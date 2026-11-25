#!/usr/bin/env python3
"""Propose Skyrim layout facts from sibling functions that match the target except for numbers or widths.

For a pair with the same instruction count and the same opcodes, every numeric operand that differs is
a fact the target states about the Skyrim layout: a member offset, a vtable slot, a class size, an
allocation size or a constant. A register that differs only in width is an operand-width fact. Each fact is
tied to the sibling's source line (from the /FAs listing) so a header author can see which field or call it
concerns. Facts that repeat across functions are counted, keyed by the Skyrim owner class rather than the
sibling class. Works for any sibling build (Fallout 3, New Vegas, the private Fallout 4 tree): the sibling
only supplies the compiled code and listing; no sibling text is read here.

Fact kinds:
  member-offset  displacement in a memory operand off a pointer register
  stack-offset   displacement off rsp/rbp (local variable layout; not a class fact)
  vtable-slot    displacement of an indirect call or jump
  add-offset     `add reg64, N` / `lea` style address arithmetic: the offset of a member or sub-object
  class-size     size handed to operator delete by a deleting destructor thunk
  alloc-size     size handed to an allocation call
  call-arg-constant  a constant loaded into an argument register just before a call (callee symbol kept)
  immediate      any other differing constant
  operand-width  the same instruction with a 32-bit register on one side and a 64-bit register on the other

Output is advisory JSON for a layout author; nothing here edits a header. Private, .local/ only.
"""
import argparse, collections, json, pickle, re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from score import cand_rows, target_rows, NUM
from shape import pe_sections

OP = re.compile(r'^(\S+)')
REG = re.compile(r'\b(r(?:[abcd]x|[sd]i|[sb]p|\d+)[dwb]?|e[abcd]x|e[sd]i|e[sb]p|[abcd][lx]|[sd]il|[sb]pl)\b')
ARGREG = {'ecx': 'rcx', 'edx': 'rdx', 'r8d': 'r8', 'r9d': 'r9', 'rcx': 'rcx', 'rdx': 'rdx', 'r8': 'r8', 'r9': 'r9',
          'cx': 'rcx', 'dx': 'rdx', 'r8w': 'r8', 'r9w': 'r9', 'cl': 'rcx', 'dl': 'rdx', 'r8b': 'r8', 'r9b': 'r9'}
ALLOC = re.compile(r'^\?\?[23_]|operator|Alloc|alloc|Malloc|malloc|@MemoryManager@@|^\?\?_U|^\?\?2')
DISPLACED = re.compile(r'\[\s*([a-z0-9]+)\s*(?:\+\s*[a-z0-9]+\s*(?:\*\s*\d)?\s*)?[+-]\s*(0x[0-9a-f]+|\d+)\s*\]')


def clean(text):
    """An instruction without objdump's symbol annotation and trailing address comment."""
    return re.sub(r'\s*<[^>]*>', '', re.sub(r'\s+#.*$', '', text))


def f3class(sym):
    m = re.match(r'^\?\?_[GE]([^@]+)@@', sym)
    if m:
        return m.group(1)
    m = re.match(r'^\?+(?:[0-9A-Z])?([^@]*)@([^@]+)@@', sym)
    return m.group(2) if m else None


def widen_reg(match):
    r = match.group(1)
    if re.fullmatch(r'e[abcd]x|e[sd]i|e[sb]p', r):
        return 'r' + r[1:]
    if re.fullmatch(r'r\d+[dwb]', r):
        return r[:-1]
    return r


def widen(text):
    return re.sub(r'\b(?:dword|qword) ptr\b', 'MEM', REG.sub(widen_reg, text))


def classify(mn, text, idx):
    """Operand-position kind of the number at text[idx]: vtable-slot, member-offset, branch-target or immediate."""
    for b in re.finditer(r'\[[^\]]*\]', text):
        if b.start() <= idx < b.end():
            return 'vtable-slot' if mn in ('call', 'jmp') else 'member-offset'
    if mn in ('call', 'jmp') or mn.startswith('j'):
        return 'branch-target'
    return 'immediate'


def base_register(text, idx):
    for b in re.finditer(r'\[[^\]]*\]', text):
        if b.start() <= idx < b.end():
            m = re.match(r'\[\s*([a-z0-9]+)', b.group(0))
            return m.group(1) if m else None
    return None


def refine(kind, mn, text, sym, rows, i, base):
    """Split the coarse kinds by context. rows[i] is the candidate instruction carrying the number."""
    if kind == 'member-offset':
        if base in ('rsp', 'rbp', 'esp', 'ebp'):
            return 'stack-offset'
        if base == 'rip':
            return None
        return kind
    if kind != 'immediate':
        return kind
    dest = re.match(r'^\S+\s+([a-z0-9]+)\s*,', text)
    dest = dest.group(1) if dest else ''
    if mn == 'mov' and dest in ARGREG and sym.startswith(('??_G', '??_E')):
        return 'class-size'
    if mn in ('add', 'sub') and dest == 'rsp':
        return 'frame-size'
    if mn == 'add' and dest in ('rax', 'rbx', 'rcx', 'rdx', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15'):
        return 'add-offset'
    if mn == 'mov' and dest in ARGREG:
        for r in rows[i + 1:i + 5]:
            if r['t'].startswith('call') or r['t'].startswith('jmp'):
                callee = r['relsym'][0] if r.get('relsym') else ''
                return 'alloc-size' if ALLOC.search(callee) else 'call-arg-constant'
            if r['t'].startswith(('mov ' + dest, 'lea ' + dest)):
                break
    return kind


def callee_after(rows, i):
    for r in rows[i + 1:i + 5]:
        if r['t'].startswith(('call', 'jmp')):
            return r['relsym'][0] if r.get('relsym') else ''
    return ''


def pair_facts(c, t, sym, listing=None):
    """(facts, reason). reason is None when every differing instruction is a number or a width."""
    aligned = bool(listing) and len(listing['ins']) == len(c)
    facts = []
    for i, (r, q) in enumerate(zip(c, t)):
        rt, qt = clean(r['t']), clean(q['t'])
        if rt == qt:
            continue
        mn = OP.match(rt).group(1)
        if (mn in ('call', 'jmp') or mn.startswith('j')) and '[' not in rt:
            continue  # a direct branch or call: its target is a relocation, resolved by the comparator's symbol map
        if r['rel'] and 'rip' in rt:
            continue  # a data reference: relocation noise
        nc, nt = NUM.findall(rt), NUM.findall(qt)
        src = listing['lines'].get(listing['ins'][i][1], '') if aligned else ''
        if len(nc) == len(nt) and NUM.sub('#', rt) == NUM.sub('#', qt):
            for k, (x, y) in enumerate(zip(nc, nt)):
                if x == y:
                    continue
                pos = [m.start() for m in NUM.finditer(rt)][k]
                kind = classify(mn, rt, pos)
                if kind == 'branch-target':
                    continue
                base = base_register(rt, pos)
                kind = refine(kind, mn, rt, sym, c, i, base)
                if kind is None:
                    continue
                fact = {'kind': kind, 'sibling_x64': x, 'skyrim': y, 'instruction_pattern': NUM.sub('#', rt), 'source_line': src}
                if base:
                    fact['base'] = base
                if kind in ('call-arg-constant', 'alloc-size'):
                    fact['callee'] = callee_after(c, i)
                facts.append(fact)
        elif widen(NUM.sub('#', rt)) == widen(NUM.sub('#', qt)):
            width = {'kind': 'operand-width', 'sibling_x64': rt, 'skyrim': qt, 'instruction_pattern': NUM.sub('#', rt), 'source_line': src}
            for key, text in (('sibling_disp', rt), ('skyrim_disp', qt)):
                m = DISPLACED.search(text)
                if m:
                    width[key] = m.group(2)
                    width['base'] = m.group(1)
            facts.append(width)
            # the same instruction can also move a member: its displacement is a separate fact
            if len(nc) == len(nt):
                for k, (x, y) in enumerate(zip(nc, nt)):
                    pos = [m.start() for m in NUM.finditer(rt)][k]
                    if x != y and classify(mn, rt, pos) == 'member-offset':
                        base = base_register(rt, pos)
                        kind = refine('member-offset', mn, rt, sym, c, i, base)
                        if kind:
                            facts.append({'kind': kind, 'sibling_x64': x, 'skyrim': y, 'instruction_pattern': NUM.sub('#', rt),
                                          'source_line': src, 'base': base})
        else:
            return facts, 'instruction differs beyond numbers and widths'
    return facts, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--scores', required=True)
    ap.add_argument('--objdir', required=True)
    ap.add_argument('--image', required=True)
    ap.add_argument('--srcmap', help='pickle of source listings (lookup.py index); without it facts carry no source line')
    ap.add_argument('--out', required=True)
    ap.add_argument('--table', required=True, help='function table (functions.jsonl) for Skyrim names and owners')
    ap.add_argument('--matched', help='JSON list of matched rvas to exclude')
    ap.add_argument('--only', help='JSON list of rvas to restrict to')
    ap.add_argument('--max-struct', type=int, default=8, help='skip pairs with more structural hunks than this in the score file')
    ap.add_argument('--emit-layouts', help='also write {hex rva: [facts]} for sibling_transplant --layouts (usable kinds only)')
    a = ap.parse_args()
    S = json.load(open(a.scores))
    skip = set(json.load(open(a.matched))) if a.matched else set()
    only = set(json.load(open(a.only))) if a.only else None
    idx = pickle.load(open(a.srcmap, 'rb')) if a.srcmap else {}
    tab = {}
    for line in open(a.table):
        f = json.loads(line)
        if f['kind'] == 'ordinary':
            tab[f['rva']] = ([n['name'] for n in f['names']], (f.get('owner') or {}).get('class'))
    base, _ = pe_sections(Path(a.image).read_bytes()[:16384])
    S = [s for s in S if s['rva'] not in skip and not s['identical'] and s['n_cand'] == s['n_tgt'] and s['struct'] <= a.max_struct
         and (only is None or s['rva'] in only)]
    S.sort(key=lambda s: s['key'][0])
    funcs, agg, skipped = [], collections.defaultdict(lambda: {'functions': set()}), collections.Counter()
    owner_sizes = collections.defaultdict(lambda: collections.defaultdict(set))
    for s in S:
        stem, sym = s['key']
        c = cand_rows(Path(a.objdir) / (stem + '.obj'), sym)
        t = target_rows(a.image, base, s['rva'], s['size'])
        if len(c) != len(t):
            skipped['length'] += 1
            continue
        facts, why = pair_facts(c, t, sym, idx.get((stem, sym)))
        if why:
            skipped['structural'] += 1
            continue
        if not facts:
            skipped['none'] += 1
            continue
        names, owner = tab.get(s['rva'], ([], None))
        listing = idx.get((stem, sym))
        for f in facts:
            key = (owner or '?', f['kind'], f['sibling_x64'], f['skyrim'])
            agg[key]['functions'].add(s['rva'])
            if owner and f['kind'] == 'class-size':
                owner_sizes[owner][f['skyrim']].add(s['rva'])
        funcs.append({'rva': s['rva'], 'skyrim_names': names[:3], 'skyrim_owner': owner, 'sibling_symbol': sym, 'sibling_unit': stem,
                      'sibling_file': listing['file'] if listing else None, 'kinds': sorted({f['kind'] for f in facts}), 'facts': facts})
    repeated = [{'skyrim_owner': k[0], 'kind': k[1], 'sibling_x64': k[2], 'skyrim': k[3], 'functions': len(v['functions'])}
                for k, v in agg.items() if len(v['functions']) >= 2]
    repeated.sort(key=lambda x: -x['functions'])
    # class sizes by the Skyrim owner (a deleting-destructor thunk names its class): one size per owner is a usable fact,
    # two sizes mean the shape matched unrelated classes and neither is trusted
    sizes = {o: {v: sorted(r) for v, r in d.items()} for o, d in owner_sizes.items()}
    out = {'schema': 2, 'owner_class_sizes': {o: d for o, d in sizes.items() if len(d) == 1},
           'owner_size_conflicts': {o: d for o, d in sizes.items() if len(d) > 1}, 'note': 'advisory layout facts; values are as printed by the disassembler (hex or decimal)',
           'functions': funcs, 'repeated_facts': repeated, 'skipped': dict(skipped),
           'caveat': 'a shared template shape can match many unrelated Skyrim classes, so key class-size and member facts by skyrim_owner, not by the sibling class'}
    json.dump(out, open(a.out, 'w'), indent=1)
    kinds = collections.Counter(f['kind'] for fn in funcs for f in fn['facts'])
    print(len(funcs), 'functions with facts;', len(repeated), 'facts seen in 2+ functions;', dict(kinds), 'skipped', dict(skipped))
    if a.emit_layouts:
        usable = {'member-offset', 'vtable-slot', 'add-offset', 'class-size', 'alloc-size', 'call-arg-constant', 'immediate', 'operand-width', 'stack-offset'}
        json.dump({hex(fn['rva']): [f for f in fn['facts'] if f['kind'] in usable] for fn in funcs}, open(a.emit_layouts, 'w'))


if __name__ == '__main__':
    main()
