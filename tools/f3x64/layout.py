#!/usr/bin/env python3
"""Propose Skyrim layout facts from sibling functions that match the target except for numbers.

For a pair with the same instruction count and the same opcodes, every numeric operand that differs is
a fact the target states about the Skyrim layout: a member offset, a vtable slot, or a size/constant.
Each fact is tied to the sibling's source line (from the /FAs listing) so a header author can see which
field or call it concerns. Facts that repeat across functions for the same sibling class and source text are
counted. Output is advisory JSON for a layout author; nothing here edits a header. Private, .local/ only.
"""
import argparse, collections, json, pickle, re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from score import cand_rows, target_rows, NUM
from shape import pe_sections

OP = re.compile(r'^(\S+)')


def f3class(sym):
    m = re.match(r'^\?\?_[GE]([^@]+)@@', sym)
    if m:
        return m.group(1)
    m = re.match(r'^\?+(?:[0-9A-Z])?([^@]*)@([^@]+)@@', sym)
    return m.group(2) if m else None


def classify(mn, text, idx):
    br = list(re.finditer(r'\[[^\]]*\]', text))
    for b in br:
        if b.start() <= idx < b.end():
            if mn in ('call', 'jmp'):
                return 'vtable-slot'
            return 'member-offset'
    if mn in ('call', 'jmp'):
        return 'branch-target'
    return 'immediate'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--scores', required=True)
    ap.add_argument('--objdir', required=True)
    ap.add_argument('--image', required=True)
    ap.add_argument('--srcmap', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--table', required=True, help='function table (functions.jsonl) for Skyrim names and owners')
    ap.add_argument('--matched', help='JSON list of matched rvas to exclude')
    a = ap.parse_args()
    S = json.load(open(a.scores))
    skip = set(json.load(open(a.matched))) if a.matched else set()
    idx = pickle.load(open(a.srcmap, 'rb'))
    tab = {}
    for line in open(a.table):
        f = json.loads(line)
        if f['kind'] == 'ordinary':
            tab[f['rva']] = ([n['name'] for n in f['names']], (f.get('owner') or {}).get('class'))
    base, _ = pe_sections(Path(a.image).read_bytes()[:16384])
    S = [s for s in S if s['rva'] not in skip and not s['identical'] and s['n_cand'] == s['n_tgt'] and s['struct'] == 0]
    S.sort(key=lambda s: s['key'][0])
    funcs, agg = [], collections.defaultdict(lambda: {'functions': set(), 'values': collections.Counter()})
    for s in S:
        stem, sym = s['key']
        c = cand_rows(Path(a.objdir) / (stem + '.obj'), sym)
        t = target_rows(a.image, base, s['rva'], s['size'])
        if len(c) != len(t):
            continue
        listing = idx.get((stem, sym))
        aligned = listing and len(listing['ins']) == len(c)
        facts = []
        for i, (r, q) in enumerate(zip(c, t)):
            nc, nt = NUM.findall(r['t']), NUM.findall(q['t'])
            if r['t'] == q['t'] or len(nc) != len(nt):
                continue
            for k, (x, y) in enumerate(zip(nc, nt)):
                if x == y:
                    continue
                pos = [m.start() for m in NUM.finditer(r['t'])][k]
                kind = classify(OP.match(r['t']).group(1), r['t'], pos)
                if kind == 'branch-target':
                    continue
                if kind == 'immediate' and sym.startswith(('??_G', '??_E')) and OP.match(r['t']).group(1) == 'mov':
                    kind = 'class-size'  # the size handed to operator delete by a deleting destructor
                src = listing['lines'].get(listing['ins'][i][1], '') if aligned else ''
                facts.append({'kind': kind, 'sibling_x64': x, 'skyrim': y, 'instruction_pattern': NUM.sub('#', r['t']),
                              'source_line': src})
                key = (f3class(sym) or '?', kind, src, x, y)
                agg[key]['functions'].add(s['rva'])
        if facts:
            funcs.append({'rva': s['rva'], 'skyrim_names': tab.get(s['rva'], ([], None))[0][:3], 'skyrim_owner': tab.get(s['rva'], ([], None))[1], 'sibling_symbol': sym, 'sibling_unit': stem,
                          'sibling_file': listing['file'] if listing else None, 'facts': facts})
    consistent = [{'sibling_class': k[0], 'kind': k[1], 'source_line': k[2], 'sibling_x64': k[3], 'skyrim': k[4],
                   'functions': len(v['functions'])} for k, v in agg.items() if len(v['functions']) >= 2]
    consistent.sort(key=lambda x: -x['functions'])
    out = {'schema': 1, 'note': 'advisory layout facts; values are as printed by the disassembler (hex or decimal)',
           'functions': funcs, 'repeated_facts': consistent,
           'caveat': 'sibling_class is the sibling function that matched by shape; a shared template shape can match many unrelated Skyrim classes, so key class-size and member facts by skyrim_owner / skyrim_names, not by sibling_class'}
    json.dump(out, open(a.out, 'w'), indent=1)
    print(len(funcs), 'functions with facts;', len(consistent), 'facts seen in 2+ functions')


if __name__ == '__main__':
    main()
