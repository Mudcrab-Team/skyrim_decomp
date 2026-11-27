#!/usr/bin/env python3
"""Offline lookup of a target function in the downloaded sibling x64 shape index.

`./sr start` calls this for every function of a task. The index (tools/x64_index.py) holds one
code-shape signature per compiled sibling function; the target's signature is built the same way
from the local image with llvm-objdump (tools/f3x64/shape.py), so the two are comparable. Output is
RVAs, sibling names, paths and scores only; no bytes and no disassembly are printed or stored.
A hit is a lead for where to read, never evidence about the Skyrim binary.
"""
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE / 'f3x64'))
import x64_index  # noqa: E402

FLOOR = 0.5
TOP = 3
MIN_INSNS = 8  # shorter functions have too few shingles to rank
CAND_POOL = 200
SIBLING_DIRS = {'fnv': 'fnv_decomp', 'f3': 'f3_decomp'}
SIBLING_LICENCE = 'CC0-1.0'
ADDR_LINE = re.compile(r'^\s*([0-9a-f]+):\s?(.*)$')
_loaded = {}


def short_source(source):
    repo, _, rev = source.partition('@')
    return f'{repo}@{rev[:8]}' if rev else repo


def readable(symbol):
    """Class::Method of an MSVC-decorated sibling symbol, best effort; the raw symbol otherwise."""
    m = re.match(r'\?\?([01])(\w+)@', symbol)
    if m:
        return f'{m.group(2)}::{"~" if m.group(1) == "1" else ""}{m.group(2)}'
    m = re.match(r'\?(\w+)@(\w+)?@', symbol)
    if m:
        return f'{m.group(2)}::{m.group(1)}' if m.group(2) else m.group(1)
    return symbol


class Matcher:
    """Shingle index over the signatures of one or more games, built once per process.

    Scoring follows tools/f3x64/shape.py match(): a blend of mnemonic-shingle, constant and string
    similarity with a penalty for a different call count. Inline functions compiled into many units
    count once, and identical shapes collapse into one candidate that remembers its other names.
    """

    def __init__(self, games):
        from shape import shingles
        self._shingles = shingles
        self.entries, self.post = [], collections.defaultdict(list)
        self.by_shape = collections.defaultdict(list)
        self.games = [g[0] for g in games]
        for game, source, sigs in games:
            seen_symbol, groups = set(), {}
            for key, sig in sigs.items():
                if key[1] in seen_symbol:
                    continue
                seen_symbol.add(key[1])
                shape = (tuple(sig['mn']), tuple(sig['imms']), tuple(sig['strs']))
                if shape in groups:
                    groups[shape]['same'] += 1
                    continue
                entry = {'game': game, 'source': source, 'key': key, 'sig': sig, 'same': 0,
                         'sh': shingles(sig['mn']), 'shape': shape}
                groups[shape] = entry
                self.entries.append(entry)
                self.by_shape[(game, shape)].append(entry)
                for g in entry['sh']:
                    self.post[g].append(len(self.entries) - 1)

    def query(self, sig, topn=TOP):
        from shape import POSTING_CAP, jaccard
        n = len(sig['mn'])
        if n < MIN_INSNS:
            return []
        s = self._shingles(sig['mn'])
        cnt = collections.Counter()
        for g in s:
            lst = self.post.get(g)
            if lst and len(lst) < POSTING_CAP:
                cnt.update(lst)
        shape = (tuple(sig['mn']), tuple(sig['imms']), tuple(sig['strs']))
        out, taken = [], set()
        # An identical shape is found by lookup: short functions share their common shingles with
        # thousands of siblings, so the shingle ranking alone can miss it.
        for game in self.games:
            for e in self.by_shape.get((game, shape), []):
                if e['sig']['calls'] == sig['calls']:
                    out.append((1.0, e, True))
                    taken.add(id(e))
        for i, c in cnt.most_common(CAND_POOL):
            e = self.entries[i]
            if id(e) in taken:
                continue
            a = e['sig']
            if not (0.6 <= len(a['mn']) / n <= 1.7):
                continue
            j = c / (len(s) + len(e['sh']) - c)
            ia, ib, sa, sb = set(a['imms']), set(sig['imms']), set(a['strs']), set(sig['strs'])
            parts = [(j, 4)]
            if ia or ib:
                parts.append((jaccard(ia, ib), 1))
            if sa or sb:
                parts.append((jaccard(sa, sb), 2))
            score = sum(v * w for v, w in parts) / sum(w for _, w in parts)
            if abs(a['calls'] - sig['calls']) > max(1, n // 6):
                score *= 0.85
            out.append((round(score, 4), e, e['shape'] == shape and a['calls'] == sig['calls']))
        out.sort(key=lambda x: (x[0], x[2]), reverse=True)
        return [x for x in out if x[0] >= FLOOR][:topn]


def load_matcher(index_dir, pins_path):
    """(Matcher, pins) from the downloaded files, or (None, reason) when the index is unusable."""
    try:
        pins = x64_index.load_pins(pins_path)
    except (OSError, ValueError, x64_index.IndexError_) as exc:
        return None, f'pin file unreadable ({exc})'
    games = []
    for game in sorted(pins['assets']):
        path = Path(index_dir) / pins['assets'][game]['name']
        if not path.is_file():
            continue
        try:
            x64_index.verify(path, game, pins)
            games.append((game, short_source(pins['assets'][game]['source']), x64_index.unpack(path, game)))
        except (OSError, ValueError, x64_index.IndexError_) as exc:
            return None, f'{path.name} is unusable ({exc})'
    if not games:
        return None, 'missing'
    key = (str(index_dir), tuple(g[0] for g in games))
    if key not in _loaded:
        _loaded[key] = Matcher(games)
    return _loaded[key], pins


def target_signature(objdump, exe, data, rva, size):
    """Shape signature of one image function, built like shape.imgsigs but for a single range."""
    import shape
    base, secs = shape.pe_sections(data)

    def read_cstr(va):
        r = va - base
        for sva, sz, ptr in secs:
            if sva <= r < sva + sz:
                return shape.printable(data[ptr + r - sva:ptr + r - sva + 300])
        return None

    out = subprocess.run([objdump, '-d', '--no-show-raw-insn', '--x86-asm-syntax=intel',
                          f'--start-address=0x{base + rva:x}', f'--stop-address=0x{base + rva + size:x}', str(exe)],
                         capture_output=True, text=True, timeout=120).stdout
    sig = shape.new_sig()
    for line in out.splitlines():
        m = ADDR_LINE.match(line)
        if not m:
            continue
        parts = m.group(2).strip().split('\t', 1)
        mn = ' '.join(parts[0].split())
        ops = parts[1] if len(parts) > 1 else ''
        tok = None
        t = re.search(r'#\s*0x([0-9a-f]+)', ops)
        if t and mn == 'lea':
            tok = read_cstr(int(t.group(1), 16))
        shape.feed(sig, mn, shape.split_ops(ops), tok)
    return shape.done(sig)


_files = {}


def source_files(root):
    """{flattened lower-case name: clone-relative path} of the .cpp files, since an object stem is the
    unit's path with separators turned into underscores."""
    if root not in _files:
        found = {}
        for p in sorted(Path(root).rglob('*.cpp')):
            rel = p.relative_to(root).as_posix()
            found.setdefault(re.sub(r'[/\\.]', '_', rel[:-4]).lower(), rel)
            found.setdefault(p.stem.lower(), rel)
        _files[root] = found
    return _files[root]


def unit_file(root, unit):
    """Clone-relative source file of an object stem such as src_foo_bar_o2_variant, or None."""
    files = source_files(root)
    name = unit.lower()
    while name:
        if name in files:
            return files[name]
        name = name.rpartition('_')[0]  # drop build-variant suffixes one piece at a time
    return None


def source_location(sibling_root, game, unit, symbol):
    """(clone-relative file, 1-based line) of the sibling definition, from a local clone when one exists."""
    root = Path(sibling_root) / SIBLING_DIRS[game] if sibling_root else None
    if root is None or not root.is_dir():
        return None, None
    rel = unit_file(root, unit)
    if rel is None:
        return None, None
    try:
        import sibling_transplant
        line = sibling_transplant.definition_line((root / rel).read_text(errors='replace').splitlines(), symbol)
    except Exception:  # noqa: BLE001 - a line number is a convenience
        line = None
    return rel, line


def candidate_record(score, entry, exact, sibling_root):
    game, (unit, symbol) = entry['game'], entry['key']
    file, line = source_location(sibling_root, game, unit, symbol)
    return {'game': game, 'source': entry['source'], 'unit': unit, 'symbol': symbol, 'name': readable(symbol),
            'file': file, 'line': line, 'score': score, 'exact_shape': exact, 'same_shape_elsewhere': entry['same']}


def describe(rva, cand):
    where = f'{cand["file"]}:{cand["line"]}' if cand['file'] and cand['line'] else \
        f'{cand["file"] or "unit " + cand["unit"]} (line unknown; clone {"has no definition match" if cand["file"] else "not present"})'
    return (f'  0x{rva:x}: {cand["source"]} {where} {cand["name"]} score {cand["score"]:.2f}'
            + (' EXACT SHAPE' if cand['exact_shape'] else ''))


def hints(index_dir, pins_path, sibling_root, objdump, exe, fns):
    """(record, lines) for the functions `fns` (dicts with rva and size). Never raises."""
    record = {'schema': 1, 'status': 'ok', 'note': 'shape leads from compiled sibling code; never evidence', 'functions': {}}
    try:
        matcher, pins = load_matcher(index_dir, pins_path)
        if matcher is None:
            record['status'] = 'index-missing' if pins == 'missing' else 'index-unusable'
            record['detail'] = pins
            if pins == 'missing':
                return record, ['x64 sibling index not downloaded: run ./sr setup --yes to fetch it (docs/sibling-x64.md)']
            return record, [f'x64 sibling index not used: {pins}; run ./sr setup --yes to fetch it again']
        if not objdump:
            record['status'] = 'no-objdump'
            return record, ['x64 sibling lookup needs llvm-objdump; ./sr doctor shows how to install it']
        record['index'] = {'tag': pins['tag'], 'games': sorted({e['game'] for e in matcher.entries})}
        data = Path(exe).read_bytes()
        lines, exact_any = [], []
        for fn in fns:
            sig = target_signature(objdump, exe, data, fn['rva'], fn['size'])
            found = matcher.query(sig)
            cands = [candidate_record(s, e, x, sibling_root) for s, e, x in found]
            rva = f'0x{fn["rva"]:x}'
            record['functions'][rva] = {'candidates': cands, 'exact_shape': any(c['exact_shape'] for c in cands),
                                        **({} if cands else {'note': 'no candidate above the floor'
                                           if len(sig['mn']) >= MIN_INSNS else f'under {MIN_INSNS} instructions'})}
            for c in cands:
                lines.append(describe(fn['rva'], c))
            if not cands:
                lines.append(f'  {rva}: no sibling shape above the floor')
            exact_any += [(fn['rva'], c) for c in cands if c['exact_shape']]
        lines.insert(0, 'sibling x64 hint (shape lead from compiled CC0 sibling code, never evidence):')
        if exact_any:
            labels = sorted({f'SIBLING({c["source"]}, {SIBLING_LICENCE})' for _r, c in exact_any})
            lines.append('exact shape found: the body can be transplanted directly with tools/sibling_transplant.py, '
                         f'which writes the labels ({", ".join(labels)}); the comparator still decides')
        return record, lines
    except Exception as exc:  # noqa: BLE001 - a hint must never stop `start`
        record['status'] = 'error'
        record['detail'] = type(exc).__name__
        return record, [f'x64 sibling lookup skipped ({type(exc).__name__})']


def write_record(tdir, record):
    (Path(tdir) / 'sibling_x64.json').write_text(json.dumps(record, indent=1) + '\n')


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--index-dir', required=True)
    ap.add_argument('--exe', required=True)
    ap.add_argument('--objdump', required=True)
    ap.add_argument('--sibling-root')
    ap.add_argument('rva', nargs='+', help='rva:size')
    a = ap.parse_args(argv)
    fns = [{'rva': int(x.split(':')[0], 0), 'size': int(x.split(':')[1], 0)} for x in a.rva]
    _rec, lines = hints(a.index_dir, x64_index.PINS, a.sibling_root, a.objdump, a.exe, fns)
    print('\n'.join(lines))


if __name__ == '__main__':
    main()
