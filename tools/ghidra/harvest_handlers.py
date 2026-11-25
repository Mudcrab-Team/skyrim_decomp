"""Clean-room harvesters for executable-owned handler names (OBSERVED).

Two static passes over a PE64 image and its disassembly:

1. ``harvest_script_functions`` locates dense 0x50-byte command/script tables
   (``functionName`` at +0x00, ``executeFunction`` at +0x30, ``conditionFunction``
   at +0x40), expands across sparse/null entries in the same contiguous table,
   and emits strictly 1-to-1 handler mappings once at least ``min_entries``
   (default 20, per ``docs/resource-guidelines.md``) records confirm the layout.
2. ``harvest_registrations`` aggregates direct calls where ``DisasmPass`` saw
   RIP-relative ``lea`` instructions loading Win64 argument registers with one
   identifier string and one executable function entry. A callee is accepted
   only when at least ``min_sites`` (default 20) callsites share one fixed
   ``(name_slot, handler_slot)`` pair, and only globally 1-to-1 mappings are
   emitted.

Original code; no game data.
"""
from collections import defaultdict
import re
import struct

TABLE_NAME_RE = re.compile(r'^[A-Za-z_]\w{1,63}$')
REG_IDENT_RE = re.compile(r'^[A-Za-z_][A-Za-z0-9_:.<>-]{1,95}$')

ARG_REG64 = {'rcx': 0, 'rdx': 1, 'r8': 2, 'r9': 3}
ARG_REG_ANY = {
    'rcx': 0, 'ecx': 0, 'cx': 0, 'cl': 0, 'ch': 0,
    'rdx': 1, 'edx': 1, 'dx': 1, 'dl': 1, 'dh': 1,
    'r8': 2, 'r8d': 2, 'r8w': 2, 'r8b': 2,
    'r9': 3, 'r9d': 3, 'r9w': 3, 'r9b': 3,
}
NO_DEST = {'cmp', 'test', 'push', 'call', 'jmp', 'ucomiss', 'comiss', 'ucomisd', 'comisd', 'bt', 'ret', 'nop'}
RIP_LEA_RE = re.compile(r'\[rip\s*[+-]\s*0x[0-9a-f]+\]')


def _is_exec(sec):
    return bool(getattr(sec, 'flags', getattr(sec, 'chars', 0)) & 0x20000000)


def _read_cstr(img, rva, maxlen=120):
    sec = img.section(rva)
    if sec is None or _is_exec(sec):
        return None
    rel = rva - sec.vaddr
    limit = min(sec.vsize, sec.raw_size)
    if rel < 0 or rel >= limit:
        return None
    fo = sec.raw_ptr + rel
    end = img.blob.find(b'\0', fo, min(len(img.blob), fo + maxlen, sec.raw_ptr + limit))
    if end == -1:
        return None
    raw = img.blob[fo:end]
    if any(b < 0x20 or b > 0x7E for b in raw):
        return None
    return raw.decode('ascii')


def _text_bounds(img):
    for sec in img.pe.sections:
        if sec.name == '.text' and _is_exec(sec):
            return sec.vaddr, sec.vaddr + min(sec.vsize, sec.raw_size)
    for sec in img.pe.sections:
        if _is_exec(sec):
            return sec.vaddr, sec.vaddr + min(sec.vsize, sec.raw_size)
    return 0, 0


def _in_nonexec_data(img, rva):
    sec = img.section(rva)
    if sec is None or _is_exec(sec):
        return False
    rel = rva - sec.vaddr
    return 0 <= rel < min(sec.vsize, sec.raw_size)


def harvest_script_functions(img, *, stride=0x50, exec_off=0x30, cond_off=0x40, min_entries=20):
    """Find SCRIPT_FUNCTION-style tables and return 1-to-1 ``{rva: entry}`` mappings."""
    base = img.pe.image_base
    text_lo, text_hi = _text_bounds(img)
    if text_hi <= text_lo:
        return {}, {'tables': 0, 'records': 0, 'exec': 0, 'cond': 0}
    text_va_lo, text_va_hi = base + text_lo, base + text_hi

    def va_to_fo(va):
        if va < base:
            return None
        rva = va - base
        sec = img.section(rva)
        if sec is None or _is_exec(sec):
            return None
        rel = rva - sec.vaddr
        if rel < 0 or rel + stride > min(sec.vsize, sec.raw_size):
            return None
        return sec.raw_ptr + rel

    # 1. Seed scan: 8-byte aligned slots where +0x00 -> ASCII identifier and +exec_off -> .text
    cand = set()
    for sec in img.pe.sections:
        if _is_exec(sec) or sec.name not in ('.rdata', '.data'):
            continue
        limit = min(sec.vsize, sec.raw_size) - stride
        if limit < 0:
            continue
        for rel in range(0, limit + 1, 8):
            fo = sec.raw_ptr + rel
            name_va = struct.unpack_from('<Q', img.blob, fo)[0]
            if name_va < base:
                continue
            exec_va = struct.unpack_from('<Q', img.blob, fo + exec_off)[0]
            if not (text_va_lo <= exec_va < text_va_hi):
                continue
            nm = _read_cstr(img, name_va - base, 65)
            if nm and TABLE_NAME_RE.match(nm):
                cand.add(base + sec.vaddr + rel)

    def is_record(va):
        fo = va_to_fo(va)
        if fo is None:
            return False
        np, sp, _op, hp, _ref, _params, ep_va, cp_va, cdp_va = struct.unpack_from('<QQQQQQQQQ', img.blob, fo)
        ok_np = (np == 0) or (np >= base and _read_cstr(img, np - base) is not None)
        ok_sp = (sp == 0) or (sp >= base and _read_cstr(img, sp - base) is not None)
        ok_hp = (hp == 0) or (hp >= base and _in_nonexec_data(img, hp - base))
        ok_ep = (ep_va == 0) or (text_va_lo <= ep_va < text_va_hi)
        ok_cp = (cp_va == 0) or (text_va_lo <= cp_va < text_va_hi)
        ok_cdp = (cdp_va == 0) or (text_va_lo <= cdp_va < text_va_hi)
        non_empty = (np != 0) or (ep_va != 0) or (cp_va != 0)
        return ok_np and ok_sp and ok_hp and ok_ep and ok_cp and ok_cdp and non_empty

    # 2. Find contiguous seed runs >= min_entries (longest first) and expand each to full table bounds
    runs = []
    for start in sorted(cand):
        if start - stride in cand:
            continue
        n = 0
        cur = start
        while cur in cand:
            n += 1
            cur += stride
        if n >= min_entries and is_record(start):
            runs.append((n, start))
    tables = []
    seen_ranges = []
    for n, start in sorted(runs, reverse=True):
        lo = start
        while is_record(lo - stride):
            lo -= stride
        hi = start + n * stride
        while is_record(hi):
            hi += stride
        if any(lo < b and hi > a for a, b in seen_ranges):
            continue
        seen_ranges.append((lo, hi))
        tables.append((lo, (hi - lo) // stride))

    # 3. Collect 1-to-1 executeFunction and conditionFunction mappings
    planned = defaultdict(set)
    kind_of = {}
    table_count_of = {}
    total_named = 0
    for lo, count in tables:
        named_in_table = 0
        recs = []
        for i in range(count):
            fo = va_to_fo(lo + i * stride)
            if fo is None:
                continue
            np = struct.unpack_from('<Q', img.blob, fo)[0]
            ep_va = struct.unpack_from('<Q', img.blob, fo + exec_off)[0]
            cdp_va = struct.unpack_from('<Q', img.blob, fo + cond_off)[0]
            nm = _read_cstr(img, np - base) if np >= base else None
            if not nm:
                continue
            nm_clean = nm.strip()
            if not TABLE_NAME_RE.match(nm_clean):
                continue
            named_in_table += 1
            recs.append((nm_clean, ep_va, cdp_va))
        if named_in_table < min_entries:
            continue
        total_named += named_in_table
        for nm_clean, ep_va, cdp_va in recs:
            if text_va_lo <= ep_va < text_va_hi:
                rva = ep_va - base
                planned[rva].add('Cmd_' + nm_clean)
                kind_of[rva] = 'script-exec'
                table_count_of[rva] = named_in_table
            if text_va_lo <= cdp_va < text_va_hi:
                rva = cdp_va - base
                planned[rva].add('Cond_' + nm_clean)
                kind_of[rva] = 'script-cond'
                table_count_of[rva] = named_in_table

    out = {}
    n_exec = n_cond = 0
    for rva, names in planned.items():
        if len(names) != 1:
            continue
        how = kind_of[rva]
        out[rva] = {
            'name': next(iter(names)),
            'source': 'exe-table',
            'how': how,
            'entries': table_count_of[rva],
        }
        if how == 'script-exec':
            n_exec += 1
        else:
            n_cond += 1
    return out, {'tables': len(tables), 'records': total_named, 'exec': n_exec, 'cond': n_cond}


def lea_arg_targets(window, base):
    """From a pre-call instruction window, return ``{arg_slot: target_rva}`` for RIP-relative LEAs."""
    found = {}
    clobbered = set()
    for row in reversed(window):
        mn, ops = row[0], row[1]
        comment_target = row[2] if len(row) > 2 else None
        if not ops or mn in NO_DEST:
            continue
        dest = ops[0]
        slot = ARG_REG_ANY.get(dest)
        if slot is None or slot in clobbered or slot in found:
            continue
        if mn == 'lea' and dest in ARG_REG64 and len(ops) >= 2 and comment_target is not None \
                and RIP_LEA_RE.search(ops[1]):
            rva = comment_target - base
            if rva > 0:
                found[slot] = rva
        else:
            clobbered.add(slot)
    return found


def harvest_registrations(img, reg_calls, entries, *, min_sites=20):
    """Aggregate direct registration call sites and return 1-to-1 ``{handler_rva: entry}`` mappings.

    ``reg_calls`` is an iterable of ``(callsite_rva, caller_rva, callee_rva, slot_targets)``.
    """
    entry_set = set(entries)
    observations = []
    for callsite_rva, caller_rva, callee_rva, slot_targets in reg_calls:
        names = []
        handlers = []
        for slot, target_rva in sorted(slot_targets.items()):
            sec = img.section(target_rva)
            if sec is None:
                continue
            if _is_exec(sec):
                if target_rva in entry_set and target_rva != callee_rva:
                    handlers.append((slot, target_rva))
            else:
                ident = _read_cstr(img, target_rva, 97)
                if ident and REG_IDENT_RE.match(ident):
                    names.append((slot, ident))
        if len(names) == 1 and len(handlers) == 1:
            name_slot, name = names[0]
            handler_slot, handler_rva = handlers[0]
            observations.append({
                'callsite': callsite_rva,
                'caller': caller_rva,
                'callee': callee_rva,
                'name_slot': name_slot,
                'handler_slot': handler_slot,
                'name': name,
                'handler': handler_rva,
            })

    by_callee = defaultdict(list)
    global_names_by_handler = defaultdict(set)
    global_handlers_by_name = defaultdict(set)
    for row in observations:
        by_callee[row['callee']].append(row)
        global_names_by_handler[row['handler']].add(row['name'])
        global_handlers_by_name[row['name']].add(row['handler'])

    out = {}
    accepted_callees = 0
    for callee, rows in by_callee.items():
        callsites = {r['callsite'] for r in rows}
        names = {r['name'] for r in rows}
        if len(callsites) < min_sites or len(names) < min_sites:
            continue
        slot_pairs = {(r['name_slot'], r['handler_slot']) for r in rows}
        if len(slot_pairs) != 1:
            continue
        accepted_callees += 1
        local_names_by_handler = defaultdict(set)
        local_handlers_by_name = defaultdict(set)
        for r in rows:
            local_names_by_handler[r['handler']].add(r['name'])
            local_handlers_by_name[r['name']].add(r['handler'])
        for r in rows:
            h, nm = r['handler'], r['name']
            if len(local_names_by_handler[h]) != 1 or len(local_handlers_by_name[nm]) != 1:
                continue
            if len(global_names_by_handler[h]) != 1 or len(global_handlers_by_name[nm]) != 1:
                continue
            out[h] = {
                'name': nm,
                'source': 'exe-reg',
                'how': 'registration',
                'callee': callee,
                'sites': len(callsites),
            }
    return out, {'observations': len(observations), 'callees': accepted_callees, 'accepted': len(out)}


# ---------------------------------------------------------------------------------------------
# Script-engine native registrations.
#
# A native function object is built in two steps the pass below can see: a base constructor call
# whose argument registers hold a function-name string and a script-name string, then a few stores
# into the new object (a virtual-table pointer at offset 0 and the handler address in a later
# slot). The strings are joined to the declarations read from the shipped script archive
# (`tools/papyrus_psc.py`); the join, not the string shape alone, is what makes a site count.

GPR64 = ('rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi') + tuple(f'r{i}' for i in range(8, 16))
_SUBREG = {}
for _i, _name in enumerate(GPR64):
    _SUBREG[_name] = _name
    if _i < 8:
        _SUBREG['e' + _name[1:]] = _name
        _SUBREG[_name[1:]] = _name
    else:
        for _suffix in ('d', 'w', 'b'):
            _SUBREG[_name + _suffix] = _name
VOLATILE = ('rax', 'rcx', 'rdx', 'r8', 'r9', 'r10', 'r11')
ARG_SLOT_REGS = ('rcx', 'rdx', 'r8', 'r9')
STORE_RE = re.compile(r'^(?:qword )?ptr \[(?P<base>\w+)(?: \+ 0x(?P<off>[0-9a-f]+))?\]$')
CALL_TARGET_RE = re.compile(r'^0x([0-9a-f]+)')
COMMENT_TARGET_RE = re.compile(r'#\s*0x([0-9a-f]+)')
SITE_TAIL = 14


def _split_operands(text):
    text = text.split('#', 1)[0].strip()
    out, depth, cur = [], 0, ''
    for ch in text:
        if ch == '[':
            depth += 1
        elif ch == ']':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


class RegistrationSiteScanner:
    """Stream of ``llvm-objdump -d --x86-asm-syntax=intel`` lines to registration call sites.

    A register map tracks which general register holds a RIP-relative address (set by ``lea``, cleared
    by any other write and, for the volatile registers, by every call), so a callee-saved register that
    carries a table address across a call is still known when it is stored. At every direct call, the
    argument registers that hold such an address are recorded when at least two do; the next
    ``SITE_TAIL`` instructions (up to the next control transfer) are scanned for stores of a known
    address into ``[reg]`` or ``[reg + off]``. Output rows are plain dicts:
    ``{'site', 'callee', 'args': {slot: rva}, 'stores': [(offset, rva)]}``.
    """

    def __init__(self, base, entries=None):
        self.base = base
        self.entries = set(entries or ())
        self.known = {}
        self.rows = []
        self.open = None
        self.left = 0
        self.func = None
        self.ctor_vtables = defaultdict(set)

    def _close(self):
        if self.open is not None:
            self.rows.append(self.open)
        self.open = None
        self.left = 0

    def instruction(self, addr, mn, ops, target):
        rva = addr - self.base
        if rva in self.entries:
            self._close()
            self.known.clear()
            self.func = rva
        mn = mn.split()[-1]
        if mn == 'mov' and len(ops) == 2 and self.func is not None:
            m = STORE_RE.match(ops[0])
            src = _SUBREG.get(ops[1])
            if m and src in self.known and not m.group('off') and m.group('base') in ('rcx', 'rbx', 'rdi', 'rsi'):
                self.ctor_vtables[self.func].add(self.known[src])
        if self.open is not None:
            if mn in ('call', 'jmp', 'ret') or mn.startswith('j') or self.left <= 0:
                self._close()
            else:
                self.left -= 1
                if mn == 'mov' and len(ops) == 2:
                    m = STORE_RE.match(ops[0])
                    src = _SUBREG.get(ops[1])
                    if m and src in self.known:
                        self.open['stores'].append((int(m.group('off') or '0', 16), self.known[src]))
        if mn == 'call':
            self._close()
            m = CALL_TARGET_RE.match(ops[0]) if ops else None
            if m:
                args = {i: self.known[r] for i, r in enumerate(ARG_SLOT_REGS) if r in self.known}
                if len(args) >= 2:
                    self.open = {'site': rva, 'callee': int(m.group(1), 16) - self.base, 'args': args, 'stores': []}
                    self.left = SITE_TAIL
            for r in VOLATILE:
                self.known.pop(r, None)
            return
        if not ops or mn in NO_DEST:
            return
        dest = _SUBREG.get(ops[0])
        if dest is None:
            return
        if mn == 'lea' and len(ops) == 2 and target is not None and RIP_LEA_RE.search(ops[1]):
            self.known[dest] = target - self.base
        else:
            self.known.pop(dest, None)

    def feed(self, lines):
        for text in lines:
            colon = text.find(':')
            if colon < 8 or colon > 17 or text[0] == ' ':
                continue
            try:
                addr = int(text[:colon], 16)
            except ValueError:
                continue
            rest = text[colon + 1:].strip()
            if not rest:
                continue
            parts = rest.split('\t', 1)
            mn = ' '.join(parts[0].split())
            opstext = parts[1] if len(parts) > 1 else ''
            m = COMMENT_TARGET_RE.search(opstext)
            self.instruction(addr, mn, _split_operands(opstext), int(m.group(1), 16) if m else None)
        self._close()
        return self.rows


def harvest_native_registrations(img, sites, natives, vftable_names=None, ctor_vtables=None):
    """Join registration call sites to script declarations. Returns ``(rows, stats)``.

    ``natives`` is the table of ``tools/papyrus_psc.py`` (`{folded script: {'natives': [...]}}`).
    ``vftable_names`` optionally maps a virtual-table RVA to its class name (read from RTTI).
    ``ctor_vtables`` maps a constructor to the virtual tables it stores at offset zero; it names the class when the
    registering function does not store one itself. The handler is an executable address passed as an argument or
    stored into the new object. A row is emitted only when two argument strings are a declared (script, native function) pair
    and exactly one stored address lies in executable code; a handler that more than one declared
    pair claims is dropped, as the pairing is then not one to one.
    """
    declared = {}
    for key, script in natives.items():
        for c in script['natives']:
            declared[(key, c['name'].lower())] = (script, c)
    stats = {'sites': len(sites), 'pairs': 0, 'no_handler': 0, 'several_handlers': 0}
    found = []
    for site in sites:
        strings = {}
        for slot, rva in site['args'].items():
            sec = img.section(rva)
            if sec is None or _is_exec(sec):
                continue
            text = _read_cstr(img, rva, 97)
            if text and REG_IDENT_RE.match(text):
                strings[slot] = text
        pair = None
        for a, fn in strings.items():
            for b, scr in strings.items():
                if a != b and (scr.lower(), fn.lower()) in declared:
                    pair = (scr, fn)
        if pair is None:
            continue
        stats['pairs'] += 1
        handlers, vtables = set(), set()
        for rva in site['args'].values():
            sec = img.section(rva)
            if sec is not None and _is_exec(sec) and rva != site['callee']:
                handlers.add(rva)
        for off, rva in site['stores']:
            sec = img.section(rva)
            if sec is None:
                continue
            if _is_exec(sec):
                handlers.add(rva)
            elif off == 0:
                vtables.add(rva)
        if not handlers:
            stats['no_handler'] += 1
            continue
        if len(handlers) > 1:
            stats['several_handlers'] += 1
            continue
        script, c = declared[(pair[0].lower(), pair[1].lower())]
        if not vtables:
            vtables = set((ctor_vtables or {}).get(site['callee'], ()))
        vt = next(iter(vtables)) if len(vtables) == 1 else None
        found.append({'handler': next(iter(handlers)), 'script': script['name'], 'function': c['name'],
                      'decl': c, 'site': site['site'], 'vftable': vt,
                      'native_class': (vftable_names or {}).get(vt)})
    by_handler = defaultdict(set)
    for r in found:
        by_handler[r['handler']].add((r['script'].lower(), r['function'].lower()))
    rows = [r for r in found if len(by_handler[r['handler']]) == 1]
    stats.update({'resolved': len(rows), 'shared_handlers': len(found) - len(rows),
                  'distinct_handlers': len({r['handler'] for r in rows})})
    return rows, stats
