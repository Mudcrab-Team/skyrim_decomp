"""Place compiled functions into a copy of the owner's executable at their original RVAs and compare.

For each function the compiled object supplies its code section, the funclets and exception data
its unwind info reaches, and its `.pdata` entries. Each such section is written into the image copy
at the RVA the exception data of the image binds it to, with every relocation resolved the way the
comparator resolves it (the unit's symbol map, `__ImageBase`, the TLS directory). Everything else in
the copy stays the owner's own bytes, so a correct set of functions leaves the copy identical to the
original. This is a diagnostic over private inputs: it never decides a match.

Differences are kept in named classes (see CLASSES). Results hold names, RVAs and counts only; no
byte value from the image or from an object leaves this module.
"""
from bisect import bisect_right
from collections import Counter
import hashlib
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from compare import (ADDR32NB, REL32_TAIL, SECREL, Function, code_section_sha256, expected_field,  # noqa: E402
                     find_function, load_symbol_map)
from compare_internal import InternalFunction, find_internal_function, internal_code_sha256  # noqa: E402
from compare_runtime import RuntimeFunction  # noqa: E402
from pecoff import (RUNTIME_FUNCTION_SIZE, SCN_CNT_CODE, CoffObject, PeImage, Reject, rel_name)  # noqa: E402

ADDR64 = 0x01

IDENTICAL = 'identical'
SIZE_MISMATCH = 'size-mismatch'
UNRESOLVED = 'unresolved-relocation'
POST_LINK = 'post-link-patch'
RESIDUAL = 'residual-difference'
# Not linked at all: the function never reached the comparison. Each reason is its own count.
NOT_LINKED = 'not-linked'
CLASSES = (IDENTICAL, SIZE_MISMATCH, UNRESOLVED, POST_LINK, RESIDUAL, NOT_LINKED)
CLASS_TEXT = {
    IDENTICAL: 'compiled bytes equal the retail bytes in place',
    SIZE_MISMATCH: 'compiled size differs from the size of the retail slot, so nothing was placed',
    UNRESOLVED: 'a relocation target has no address, so its field could not be filled in',
    POST_LINK: 'bytes differ, and every differing byte lies in a declared post-link patch range',
    RESIDUAL: 'size fits and all relocations resolved, but bytes still differ outside declared patches',
    NOT_LINKED: 'no usable object or function symbol, so nothing was placed',
}
# How many differing byte addresses are kept per function to test them against declared patches.
MAX_DIFF_ADDRESSES = 64


class ImageView(PeImage):
    """A PE image with the exception directory parsed once and, optionally, windowed.

    The comparator's unwind binding scans `runtime_functions()` for entries overlapping one range;
    for an image with a few hundred thousand entries that scan dominates a run. While `window` is
    set, only the entries overlapping it are returned. With no window the full table comes back,
    which is what the funclet-entry census needs.
    """

    def __init__(self, blob):
        super().__init__(blob)
        self.window = None
        self._table = None
        self._begins = None
        self._slots = None

    def table(self):
        if self._table is None:
            original = super().runtime_functions()
            self._slots = {e[0]: i for i, e in reversed(list(enumerate(original)))}
            self._table = sorted(original)
            self._begins = [e[0] for e in self._table]
        return self._table

    def runtime_functions(self):
        table = self.table()
        if self.window is None:
            return table
        lo, hi = self.window
        first = max(bisect_right(self._begins, lo) - 1, 0)
        last = bisect_right(self._begins, hi)
        return [e for e in table[first:last] if e[0] < hi and e[1] > lo]

    def pdata_slot(self, begin):
        """RVA of the exception-directory entry that starts at `begin`, or None."""
        self.table()
        i = self._slots.get(begin)
        return None if i is None else self.exception_dir[0] + RUNTIME_FUNCTION_SIZE * i


def new_coverage():
    """The counters Function writes while it binds exception data; their values are not used."""
    return {'code_bytes_total': None, 'code_bytes_exact': 0, 'code_bytes_by_reference': 0,
            'relocations_by_type': {}, 'self_rva_fields': 0, 'unwind_entries': 0, 'unwind_chained_entries': 0,
            'unwind_bytes_exact': 0, 'unwind': 'not-checked', 'aliases_declared': [],
            'funclet_sections': 0, 'funclet_bytes_total': 0, 'funclet_bytes_exact': 0,
            'funclet_bytes_by_reference': 0, 'funclet_ranges': [], 'funclet_end_evidence': {},
            'eh': {'handlers': {}, 'structures': {}, 'ref_fields': 0, 'int_fields': 0, 'bytes': 0,
                   'type_names_compared': 0}}


class FunctionResult:
    """What happened to one function. `ranges` are the placed byte ranges (kind, rva, length)."""

    def __init__(self, spec):
        self.id = spec.get('id')
        self.rva, self.size, self.name = spec['rva'], spec['size'], spec['symbol']
        self.status = None          # one of CLASSES once finished
        self.reason = None          # why a function is not linked, or what the size was
        self.ranges = []
        self.unresolved = []        # (symbol name, relocation kind, reason code)
        self.relocs = Counter()     # resolved relocations by kind name
        self.notes = set()
        self.first_diff = None      # (rva, kind) of the lowest differing byte
        self.diff_addresses = []
        self.diff_bytes = 0

    def row(self):
        out = {'id': self.id, 'rva': self.rva, 'size': self.size, 'name': self.name, 'class': self.status}
        if self.reason:
            out['reason'] = self.reason
        if self.first_diff:
            out['first_diff_rva'], out['first_diff_kind'] = self.first_diff
            out['diff_bytes'] = self.diff_bytes
        if self.unresolved:
            out['unresolved'] = [{'symbol': s, 'kind': k, 'reason': r} for s, k, r in self.unresolved]
        if self.notes:
            out['notes'] = sorted(self.notes)
        return out


class Linker:
    def __init__(self, image_bytes, patches=()):
        self.orig = bytes(image_bytes)
        self.work = bytearray(self.orig)
        self.written = bytearray(len(self.orig))
        self.image = ImageView(self.orig)
        self.patches = sorted((p['rva'], p['rva'] + p['length']) for p in patches)
        self.results = []
        self._primed = False

    # -- placement ----------------------------------------------------------------------------

    def locate(self, rva, length):
        """File offset of an RVA range that lies wholly in raw section data, else a Reject."""
        sec, _ = self.image.read(rva, length, 'placement range')
        return sec.raw_ptr + (rva - sec.vaddr)

    def write(self, res, kind, rva, data):
        offset = self.locate(rva, len(data))
        if any(self.written[offset:offset + len(data)]):
            # Two functions share bytes (folded copies). Equal content is the folded case; anything
            # else means two compiled functions disagree about one address.
            if bytes(self.work[offset:offset + len(data)]) != bytes(data):
                res.notes.add('placement-conflict')
            res.ranges.append((kind, rva, len(data)))
            return
        self.work[offset:offset + len(data)] = data
        self.written[offset:offset + len(data)] = b'\1' * len(data)
        res.ranges.append((kind, rva, len(data)))

    def field(self, fn, rel, sym, addend_bytes, place_rva):
        """The bytes a linker writes for one relocation; Reject when the target has no address."""
        kind = rel.kind
        if kind == SECREL:
            return fn.secrel_field(rel, sym, addend_bytes)
        if kind == ADDR64:
            target = fn.resolve(sym)
            return struct.pack('<Q', self.image.image_base + target + struct.unpack('<Q', addend_bytes)[0])
        if kind == ADDR32NB or kind in REL32_TAIL:
            return expected_field(rel, addend_bytes, fn.resolve(sym), place_rva)
        raise Reject('unsupported-relocation', f'relocation {rel_name(kind)} is not linked')

    def resolved(self, fn, res, sec, base, lo=0, hi=None):
        """Section bytes [lo, hi) with every relocation in that range filled in."""
        data = bytearray(sec.data[lo:hi])
        hi = len(sec.data) if hi is None else hi
        for rel in sorted(sec.relocs, key=lambda r: r.offset):
            if not lo <= rel.offset < hi:
                continue
            sym = fn.obj.symbols[rel.symbol]
            width = 8 if rel.kind == ADDR64 else 4
            at = rel.offset - lo
            try:
                if at + width > len(data):
                    raise Reject('malformed-relocation', 'relocation runs past its section')
                value = self.field(fn, rel, sym, bytes(sec.data[rel.offset:rel.offset + width]), base + rel.offset - lo)
            except Reject as exc:
                res.unresolved.append((sym.name, rel_name(rel.kind), exc.reason))
                continue
            data[at:at + width] = value
            res.relocs[rel_name(rel.kind)] += 1
        return data

    def bind_exception_data(self, fn, sec):
        """Bind the funclets and exception data of `sec`, as the comparator does, without comparing code."""
        done = set()
        queue = [sec]
        while queue:
            current = queue.pop(0)
            start = fn.bound[current.index]
            self.image.window = (start, start + len(current.data))
            fn.compare_unwind(current)
            for index in fn.code_queue:
                if index not in done:
                    done.add(index)
                    queue.append(fn.obj.section(index))
            fn.code_queue.clear()

    def prime(self):
        if not self._primed:
            self.image.window = None
            self.image.table()
            self.image.funclet_entries(None)
            self._primed = True

    def pdata_entries(self, fn, res):
        """Place the object's `.pdata` entries that describe bound code, at the image's own slots."""
        for pdata in (s for s in fn.obj.sections if s.name == '.pdata'):
            if pdata.data is None or len(pdata.data) % RUNTIME_FUNCTION_SIZE:
                res.notes.add('pdata-unreadable')
                continue
            by_offset = fn.relocs[pdata.index]
            for base in range(0, len(pdata.data), RUNTIME_FUNCTION_SIZE):
                first = by_offset.get(base)
                if first is None:
                    res.notes.add('pdata-unreadable')
                    continue
                owner = fn.obj.symbols[first.symbol]
                if owner.section not in fn.bound:
                    continue
                begin = fn.bound[owner.section] + owner.value + struct.unpack_from('<I', pdata.data, base)[0]
                slot = self.image.pdata_slot(begin)
                if slot is None:
                    res.notes.add('pdata-slot-missing')
                    continue
                data = self.resolved(fn, res, pdata, slot, base, base + RUNTIME_FUNCTION_SIZE)
                try:
                    self.write(res, 'pdata', slot, bytes(data))
                except Reject:
                    res.notes.add('pdata-outside-image')

    def place(self, spec, object_bytes, symbol_map):
        """Place one function. `symbol_map` is the parsed map (entries, folds, tls entries) of its unit."""
        res = FunctionResult(spec)
        self.results.append(res)
        internal = 'internal_identity' in spec
        task = {'rva': spec['rva'], 'size': spec['size'], 'symbol': spec['symbol'],
                'source_revision': spec.get('source_revision'), 'source_path': spec.get('source_path')}
        if internal:
            task['internal_identity'] = spec['internal_identity']
        try:
            obj = CoffObject(object_bytes)
        except Reject as exc:
            return self.not_linked(res, f'object-unreadable:{exc.reason}')
        try:
            sym, sec = find_internal_function(obj, task) if internal else find_function(obj, spec['symbol'])
        except Reject as exc:
            return self.not_linked(res, f'symbol-not-found:{exc.reason}')
        if len(sec.data) != spec['size']:
            res.status, res.reason = SIZE_MISMATCH, f'compiled {len(sec.data)} bytes, slot {spec["size"]} bytes'
            return res
        entries, _folds, tls_entries = symbol_map
        if internal:
            self.prime()
        engine = InternalFunction if internal else RuntimeFunction if spec.get('engine') == 'runtime' else Function
        fn = engine(obj, sec, task, entries, self.image, new_coverage(), tls_entries)
        try:
            self.bind_exception_data(fn, sec)
        except Reject as exc:
            res.notes.add(f'exception-data-unbound:{exc.reason}')
        finally:
            self.image.window = None
        for index, rva in sorted(fn.bound.items(), key=lambda kv: kv[1]):
            part = obj.section(index)
            kind = 'code' if index == sec.index else ('funclet' if part.flags & SCN_CNT_CODE else 'eh-data')
            data = self.resolved(fn, res, part, rva)
            try:
                self.write(res, kind, rva, bytes(data))
            except Reject as exc:
                if kind == 'code':
                    return self.not_linked(res, f'outside-image:{exc.reason}')
                res.notes.add(f'{kind}-outside-image')
        self.pdata_entries(fn, res)
        spec_hash = spec.get('record_code_section_sha256')
        if spec_hash:
            parts = [sec] + [obj.section(i) for i in fn.funclet_order]
            got = internal_code_sha256(obj, parts, task) if internal else code_section_sha256(obj, parts)
            if got != spec_hash:
                res.notes.add('object-differs-from-record')
        return res

    def skip(self, spec, reason):
        """Record a function that never reached placement (no object, unusable symbol map)."""
        res = FunctionResult(spec)
        self.results.append(res)
        return self.not_linked(res, reason)

    @staticmethod
    def not_linked(res, reason):
        res.status, res.reason = NOT_LINKED, reason
        return res

    # -- comparison ---------------------------------------------------------------------------

    def in_patch(self, rva):
        i = bisect_right(self.patches, (rva, float('inf'))) - 1
        return i >= 0 and self.patches[i][0] <= rva < self.patches[i][1]

    def finish(self):
        """Compare every placed range with the original image and classify every function."""
        sections = {}
        for res in self.results:
            for kind, rva, length in res.ranges:
                sec = self.image.section_for(rva)
                row = sections.setdefault(sec.name, {'placed_bytes': 0, 'differing_bytes': 0, 'functions': set(),
                                                     'first_diff': None})
                offset = self.locate(rva, length)
                row['placed_bytes'] += length
                row['functions'].add(id(res))
                ours, theirs = self.work[offset:offset + length], self.orig[offset:offset + length]
                if ours == theirs:
                    continue
                for i in range(length):
                    if ours[i] != theirs[i]:
                        res.diff_bytes += 1
                        row['differing_bytes'] += 1
                        if len(res.diff_addresses) < MAX_DIFF_ADDRESSES:
                            res.diff_addresses.append(rva + i)
                        if res.first_diff is None or rva + i < res.first_diff[0]:
                            res.first_diff = (rva + i, kind)
                        if row['first_diff'] is None or rva + i < row['first_diff'][0]:
                            row['first_diff'] = (rva + i, res.name)
            if res.status is None:
                res.status = self.classify(res)
        return sections

    def classify(self, res):
        if not res.first_diff:
            if res.unresolved:
                res.notes.add('identical-with-unresolved')
            return IDENTICAL
        if res.unresolved:
            return UNRESOLVED
        if res.diff_bytes <= MAX_DIFF_ADDRESSES and all(self.in_patch(a) for a in res.diff_addresses):
            return POST_LINK
        return RESIDUAL


def sha256_hex(blob):
    return hashlib.sha256(blob).hexdigest()


def parse_map(map_bytes, build_id):
    """(entries, folds, tls entries) of a unit symbol map; Reject if the map is unusable."""
    import json
    try:
        parsed = json.loads(map_bytes)
    except (UnicodeDecodeError, ValueError):
        raise Reject('invalid-symbol-map', 'symbol map is not JSON') from None
    return load_symbol_map({'build_id': build_id}, parsed)


def summarize(linker, sections, image_sha256=None, build_id=None):
    """Counts only: classes, not-linked reasons, relocations, placement and per-section results."""
    results = linker.results
    classes = Counter(r.status for r in results)
    reasons = Counter(r.reason.split(':')[0] for r in results if r.status == NOT_LINKED)
    relocs, unresolved_kinds = Counter(), Counter()
    placed = Counter()
    notes = Counter()
    for r in results:
        relocs.update(r.relocs)
        unresolved_kinds.update(k for _s, k, _why in r.unresolved)
        for kind, _rva, length in r.ranges:
            placed[kind + '-ranges'] += 1
            placed[kind + '-bytes'] += length
        notes.update(n.split(':')[0] for n in r.notes)
    unresolved_total = sum(unresolved_kinds.values())
    differing = sum(row['differing_bytes'] for row in sections.values())
    return {
        'exelink_summary_schema': 1,
        'build_id': build_id,
        'image_sha256': image_sha256,
        'functions': len(results),
        'classes': {c: classes.get(c, 0) for c in CLASSES},
        'not_linked_reasons': dict(sorted(reasons.items())),
        'relocations': {'resolved': sum(relocs.values()), 'unresolved': unresolved_total,
                        'resolved_by_kind': dict(sorted(relocs.items())),
                        'unresolved_by_kind': dict(sorted(unresolved_kinds.items())),
                        'functions_with_unresolved': sum(1 for r in results if r.unresolved)},
        'placement': dict(sorted(placed.items())),
        'notes': dict(sorted(notes.items())),
        'sections': [{'name': name, 'functions': len(row['functions']), 'placed_bytes': row['placed_bytes'],
                      'differing_bytes': row['differing_bytes'],
                      'result': IDENTICAL if not row['differing_bytes'] else
                      {'first_diff_rva': row['first_diff'][0], 'function': row['first_diff'][1]}}
                     for name, row in sorted(sections.items(), key=lambda kv: kv[0])],
        'output_identical_to_retail': differing == 0,
    }


def merge_summaries(parts):
    """Add shard summaries. Section results keep the lowest first difference."""
    out = None
    for part in parts:
        if out is None:
            out = {k: (dict(v) if isinstance(v, dict) else v) for k, v in part.items()}
            out['classes'] = dict(part['classes'])
            out['not_linked_reasons'] = dict(part['not_linked_reasons'])
            out['relocations'] = {k: (dict(v) if isinstance(v, dict) else v) for k, v in part['relocations'].items()}
            out['placement'] = dict(part['placement'])
            out['notes'] = dict(part['notes'])
            out['sections'] = [dict(s) for s in part['sections']]
            continue
        if part.get('image_sha256') != out.get('image_sha256') or part.get('build_id') != out.get('build_id'):
            raise ValueError('summaries come from different images or builds')
        out['functions'] += part['functions']
        for key in ('classes', 'not_linked_reasons', 'placement', 'notes'):
            for k, v in part[key].items():
                out[key][k] = out[key].get(k, 0) + v
        for key, value in part['relocations'].items():
            if isinstance(value, dict):
                for k, v in value.items():
                    out['relocations'][key][k] = out['relocations'][key].get(k, 0) + v
            else:
                out['relocations'][key] += value
        by_name = {s['name']: s for s in out['sections']}
        for s in part['sections']:
            mine = by_name.get(s['name'])
            if mine is None:
                out['sections'].append(dict(s))
                continue
            mine['functions'] += s['functions']
            mine['placed_bytes'] += s['placed_bytes']
            mine['differing_bytes'] += s['differing_bytes']
            if isinstance(s['result'], dict) and (not isinstance(mine['result'], dict)
                                                  or s['result']['first_diff_rva'] < mine['result']['first_diff_rva']):
                mine['result'] = s['result']
        out['output_identical_to_retail'] = out['output_identical_to_retail'] and part['output_identical_to_retail']
    if out is None:
        raise ValueError('no summaries to merge')
    out['sections'].sort(key=lambda s: s['name'])
    return out
