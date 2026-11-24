#!/usr/bin/env python3
"""Corpus checks of cookbook rules against compiled sibling listings (x64, the project recipe).

    corpus.py unwind --asm DIR [--asm DIR ...]     functions with the UnwindHelp -2 store, with and without an EH handler
    corpus.py lines  --srcmap FILE --src RX --asm RX [--ctx N] [--max K]
                                                   source lines matching RX and whether the instructions they produced
                                                   (plus N following instructions) contain ASM

Sibling source is CC0; output names units, line numbers and source text, never target bytes. Private: .local/ only.
"""
import argparse
import collections
import pickle
import re
import sys
from pathlib import Path

PROC = re.compile(r'^(\S+)\s+PROC\b')
UNWIND = re.compile(r'^\$unwind\$(\S+)\s+DD\b')
HELP = re.compile(r'^\tmov\s+QWORD PTR \S+, -2\s*(?:;.*)?$')


def unwind_census(asm_dirs):
    """Per function: (has the -2 UnwindHelp store, has a C++ EH handler in its unwind data)."""
    out = {}
    for d in asm_dirs:
        for asm in sorted(Path(d).glob('*.asm')):
            help_of, handler_of, cur = {}, {}, None
            lines = asm.read_text(errors='replace').splitlines()
            i = 0
            while i < len(lines):
                raw = lines[i]
                m = PROC.match(raw)
                if m and 'COMDAT' in raw:
                    cur = m.group(1)
                    help_of.setdefault(cur, False)
                elif cur and ' ENDP' in raw:
                    cur = None
                elif cur and HELP.match(raw):
                    help_of[cur] = True
                m = UNWIND.match(raw)
                if m:
                    j = i + 1
                    block = [raw]
                    while j < len(lines) and not lines[j].startswith('xdata'):
                        block.append(lines[j])
                        j += 1
                    handler_of[m.group(1)] = any('__CxxFrameHandler' in b for b in block)
                    i = j
                i += 1
            for sym, h in help_of.items():
                out[(asm.stem, sym)] = (h, handler_of.get(sym, False))
    return out


def classify(census):
    c = collections.Counter()
    for h, handler in census.values():
        c[('help' if h else 'nohelp', 'handler' if handler else 'nohandler')] += 1
    return c


def line_effect(idx, src_rx, asm_rx, ctx=0):
    """For every source line matching src_rx: do its instructions (+ctx following) match asm_rx?"""
    src, asm = re.compile(src_rx), re.compile(asm_rx)
    total, hit, examples = 0, 0, []
    for key, f in idx.items():
        ins = f['ins']
        for ln, text in f['lines'].items():
            if not src.search(text):
                continue
            pos = [k for k, (_, l) in enumerate(ins) if l == ln]
            if not pos:
                continue
            seg = ins[pos[0]:pos[-1] + 1 + ctx]
            total += 1
            ok = any(asm.search(t) for t, _ in seg)
            hit += ok
            if len(examples) < 400:
                examples.append((key, ln, text, ok))
    return total, hit, examples


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    u = sub.add_parser('unwind')
    u.add_argument('--asm', action='append', required=True)
    sub.add_parser('vftable').add_argument('--srcmap', required=True)
    sub.add_parser('twins').add_argument('--srcmap', required=True)
    sub.add_parser('tail').add_argument('--srcmap', required=True)
    li = sub.add_parser('lines')
    li.add_argument('--srcmap', required=True)
    li.add_argument('--src', required=True)
    li.add_argument('--asm', required=True)
    li.add_argument('--ctx', type=int, default=0)
    li.add_argument('--max', type=int, default=5)
    a = ap.parse_args()
    if a.cmd == 'unwind':
        census = unwind_census(a.asm)
        for k, v in sorted(classify(census).items()):
            print(k, v)
        return
    idx = pickle.load(open(a.srcmap, 'rb'))
    if a.cmd == 'vftable':
        print('thunks, beside a vftable store, adjustors, adjustors beside:', vftable_census(idx))
        return
    if a.cmd == 'twins':
        same, differ, _ = twins(idx)
        print(f'{same} source-identical groups compile identically, {differ} differ')
        return
    if a.cmd == 'tail':
        jmp, call, calls = tail_census(idx)
        print(f'return f(...) lines: {jmp} tail calls, {call} calls')
        for key, ln, text in calls[:25]:
            print(f'{key[0]}:{ln}: {text}')
        return
    total, hit, ex = line_effect(idx, a.src, a.asm, a.ctx)
    print(f'{total} source lines match; {hit} show the effect')
    shown = 0
    for key, ln, text, ok in ex:
        if shown < a.max:
            print(('HIT  ' if ok else 'MISS ') + f'{key[0]}:{ln}: {text}')
            shown += 1



def vftable_census(idx):
    """Rule 14 and 25 on the corpus: is every emitted ??_G / ??_E thunk beside a function that stores its vftable?"""
    by_unit = collections.defaultdict(lambda: {'thunks': [], 'vftables': set()})
    for (unit, sym), f in idx.items():
        u = by_unit[unit]
        m = re.match(r'\?\?_[GE](\w+)@@', sym)
        if m:
            u['thunks'].append((sym, m.group(1)))
        for text, _ in f['ins']:
            for v in re.findall(r'\?\?_7(\w+)@@6B', text):
                u['vftables'].add(v)
    total = beside = 0
    adjustors = adj_beside = 0
    for u in by_unit.values():
        for sym, cls in u['thunks']:
            total += 1
            beside += cls in u['vftables']
            if '@@W' in sym:
                adjustors += 1
                adj_beside += cls in u['vftables']
    return total, beside, adjustors, adj_beside


def tail_census(idx, rx=r'^\s*return\s+[\w:>\-.]+\(.*\);\s*$'):
    """Single `return f(...)` lines: how often is the call a tail call (jmp) and what do the others look like."""
    pat = re.compile(rx)
    jmp = call = 0
    calls = []
    for key, f in idx.items():
        ins = f['ins']
        for ln, text in f['lines'].items():
            if not pat.match(text):
                continue
            seg = [t for t, l in ins if l == ln]
            if any(t.startswith(('jmp ', 'rex_jmp')) for t in seg):
                jmp += 1
            elif any(t.startswith('call') for t in seg):
                call += 1
                if len(calls) < 400:
                    calls.append((key, ln, text.strip()))
    return jmp, call, calls



def twins(idx, min_lines=3):
    """Groups of functions with identical source text and symbol whose instruction streams still differ."""
    groups = collections.defaultdict(list)
    for (unit, sym), f in idx.items():
        if len(f['lines']) < min_lines:
            continue
        body = tuple(f['lines'][k] for k in sorted(f['lines']))
        norm = tuple(re.sub(r'\$\w+@?\d*|\bL\d+\b', 'L', t) for t, _ in f['ins'])
        groups[(sym, body)].append((unit, norm))
    same = differ = 0
    examples = []
    for (sym, body), members in groups.items():
        if len(members) < 2:
            continue
        variants = {m[1] for m in members}
        if len(variants) == 1:
            same += 1
        else:
            differ += 1
            if len(examples) < 200:
                examples.append((sym, body, [m for m in members]))
    return same, differ, examples


if __name__ == '__main__':
    sys.exit(main())
