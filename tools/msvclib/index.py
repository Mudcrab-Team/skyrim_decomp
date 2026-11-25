#!/usr/bin/env python3
"""Library-shape index: signatures of the compiled instantiations and lead selection against the target.

    index.py sigs   --objdir D --out F.pkl              signatures of every function in the compiled units
    index.py leads  --hits H.pkl --table T.jsonl --progress P.json --out rvas.json
                                                          unmatched target functions with a strong shape lead
    index.py family --scores S.json --results R.json     pass counts per library family (names and counts only)

The match, score and comparator steps are the ones of tools/f3x64 (shape.py match, score.py, cmp_run.py --tag msvclib);
this file adds only the library-specific selection. Inputs and outputs stay under .local/.
"""
import argparse
import collections
import json
import pickle
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'f3x64'))
import shape  # noqa: E402


def matched_rvas(progress):
    return {f['rva'] for f in progress['functions'] if f['status'] == 'matched'}


def marked_rvas(tree=None):
    """RVAs any unit in the tree already marks, matched or not: a second unit would repeat them."""
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
    import duplicate_rva
    return set(duplicate_rva.marked(tree or duplicate_rva.ROOT))


def select_leads(hits, table, matched, min_score=0.8, max_amb=3, min_size=48, marked=()):
    """RVAs of ordinary target functions with no match and no unit yet whose best index lead is strong and unambiguous."""
    out = []
    for rva, (best, close) in hits.items():
        f = table.get(rva)
        if f is None or rva in matched or rva in marked or f['size'] < min_size:
            continue
        if best[0][0] >= min_score and close <= max_amb:
            out.append(rva)
    return sorted(out)


def family(symbol):
    """Template or function family of an MSVC-mangled name: the first identifier after the decoration."""
    m = re.match(r'\?+\$?([A-Za-z_][A-Za-z_0-9]*|\d)', symbol)
    if not m:
        return symbol[:12]
    name = m.group(1)
    return {'0': 'ctor', '1': 'dtor', '4': 'assign', '_G': 'scalar-deleting-dtor', '_E': 'vector-deleting-dtor'}.get(name, name)


def families(scores, results):
    sym = {s['rva']: s['key'][1] for s in scores}
    return collections.Counter(family(sym[r['rva']]) for r in results if r['result'] == 'pass' and r['rva'] in sym)


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest='cmd', required=True)
    p = sp.add_parser('sigs')
    p.add_argument('--objdir', required=True)
    p.add_argument('--out', required=True)
    p = sp.add_parser('leads')
    p.add_argument('--hits', required=True)
    p.add_argument('--table', required=True)
    p.add_argument('--progress', required=True)
    p.add_argument('--out', required=True)
    p.add_argument('--min-score', type=float, default=0.8)
    p.add_argument('--tree', help='checkout whose units already mark RVAs; default is this repository')
    p = sp.add_parser('family')
    p.add_argument('--scores', required=True)
    p.add_argument('--results', required=True)
    a = ap.parse_args()
    if a.cmd == 'sigs':
        r = shape.objsigs(a.objdir)
        pickle.dump(r, open(a.out, 'wb'))
        print(len(r), 'functions')
    elif a.cmd == 'leads':
        hits = pickle.load(open(a.hits, 'rb'))
        table = {}
        for line in open(a.table):
            f = json.loads(line)
            if f['kind'] == 'ordinary':
                table[f['rva']] = f
        sel = select_leads(hits, table, matched_rvas(json.load(open(a.progress))), a.min_score,
                           marked=marked_rvas(a.tree))
        json.dump(sel, open(a.out, 'w'))
        print(len(sel), 'unmatched functions with a lead')
    else:
        for name, n in families(json.load(open(a.scores)), json.load(open(a.results))).most_common():
            print(n, name)


if __name__ == '__main__':
    main()
