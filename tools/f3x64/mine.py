#!/usr/bin/env python3
"""Bucket the instruction-level differences of near-miss pairs into recurring categories.

Input is the score file of score.py. Each difference is reduced to a pattern (numbers and
register names abstracted); patterns that recur across several distinct functions are the
candidates for a cookbook rule. Output is a private JSON summary plus counts on stdout.
"""
import collections, json, re, sys

REG = re.compile(r'\b(r(?:[abcd]x|[sd]i|[sb]p|\d+)[dwb]?|e[abcd]x|e[sd]i|e[sb]p|[abcd][lx]|xmm\d+)\b')
NUM = re.compile(r'-?0x[0-9a-f]+|\b\d+\b')


def pat(t):
    return NUM.sub('#', REG.sub('R', t))


def mem_disp(t):
    m = re.search(r'\[[^\]]*?([+-]) (0x[0-9a-f]+|\d+)\]', t)
    return (int(m.group(2), 0) * (1 if m.group(1) == '+' else -1)) if m else None


def classify(kind, c, t):
    if kind == 'numeric':
        dc, dt = mem_disp(c), mem_disp(t)
        if dc is not None and dt is not None and dc != dt:
            if dt == 2 * dc:
                return 'layout: member offset doubled (pointer width)'
            return 'layout: member offset differs'
        return 'immediate differs (size or constant)'
    if kind == 'operands':
        if REG.sub('R', c) == REG.sub('R', t):
            return 'register choice differs'
        return 'operand form differs'
    cm = [x.split()[0] for x in c.split(' ; ') if x]
    tm = [x.split()[0] for x in t.split(' ; ') if x]
    if kind == 'delete':
        return 'extra instructions in sibling build'
    if kind == 'insert':
        return 'instructions only in target'
    return 'different sequence'


def main():
    S = json.load(open(sys.argv[1]))
    near = [s for s in S if not s['identical'] and s['n_cand'] and abs(s['n_cand'] - s['n_tgt']) <= max(3, s['n_tgt'] // 5)]
    cat = collections.Counter()
    catf = collections.defaultdict(set)
    pats = collections.defaultdict(lambda: collections.Counter())
    pf = collections.defaultdict(set)
    for s in near:
        for kind, c, t in s['diffs']:
            k = classify(kind, c, t)
            cat[k] += 1
            catf[k].add(s['rva'])
            if k not in ('layout: member offset differs', 'layout: member offset doubled (pointer width)'):
                key = f'{pat(c)}  =>  {pat(t)}'
                pats[k][key] += 1
                pf[key].add(s['rva'])
    recurring = sorted(((len(v), k) for k, v in pf.items() if len(v) >= 3), reverse=True)
    out = {'near_pairs': len(near), 'categories': {k: {'diffs': cat[k], 'functions': len(catf[k])} for k in cat},
           'recurring_patterns': [{'functions': n, 'pattern': k} for n, k in recurring[:60]]}
    json.dump(out, open(sys.argv[2], 'w'), indent=1)
    print(len(near), 'near pairs')
    for k, v in cat.most_common():
        print(f'{v:6d} diffs {len(catf[k]):5d} fns  {k}')
    print(len(recurring), 'patterns recurring in >=3 functions')


main()
