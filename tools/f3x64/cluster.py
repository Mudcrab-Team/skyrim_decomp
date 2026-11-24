#!/usr/bin/env python3
"""Cluster the hunks of near-miss pairs (sibling body vs target) into recurring kinds.

    cluster.py --scores scores_full.json [--out clusters.json] [--min-near 0.8]

Input is the score file of score.py (private). A hunk is one entry `[kind, candidate, target]`. Each hunk is
reduced to a kind that names a source-level cause: a 32-bit versus 64-bit operand width, a register choice, a
member offset, an immediate, a branch or call whose target text only differs by relocation noise (ignored), or
instructions present on one side only. A function is described by the set of kinds of its hunks; the counts of
those sets say which cause a source rewrite should target first. Output is counts and rvas, no instruction text.
"""
import argparse
import collections
import json
import re

REG = re.compile(r'\b(r(?:[abcd]x|[sd]i|[sb]p|\d+)[dwb]?|e[abcd]x|e[sd]i|e[sb]p|[abcd][lx]|xmm\d+)\b')
NUM = re.compile(r'-?0x[0-9a-f]+|\b\d+\b')
WIDE = {'e': 'r'}


def widen_reg(match):
    r = match.group(1)
    if re.fullmatch(r'e[abcd]x|e[sd]i|e[sb]p', r):
        return 'r' + r[1:]
    if re.fullmatch(r'r\d+[dwb]', r):
        return r[:-1]
    return r


def widen(text):
    text = REG.sub(widen_reg, text)
    return re.sub(r'\b(?:dword|qword) ptr\b', 'MEM', text)


def disp(text):
    m = re.search(r'\[[^\]]*?([+-]) (0x[0-9a-f]+|\d+)\]', text)
    return None if not m else int(m.group(2), 0) * (1 if m.group(1) == '+' else -1)


def hunk_kind(kind, cand, tgt):
    """One of: noise, width, regswap, offset, immediate, operand-form, only-target, only-sibling, replaced."""
    if kind == 'delete':
        return 'only-sibling'
    if kind == 'insert':
        return 'only-target'
    if kind == 'replace':
        return 'replaced'
    mnemonic = cand.split(' ', 1)[0]
    if mnemonic.startswith('j') or mnemonic == 'call':
        if '<' in cand and '<' in tgt and (re.sub(r'<[^>]*>', '', cand) == re.sub(r'<[^>]*>', '', tgt) or NUM.sub('#', cand.split('<')[0]) == NUM.sub('#', tgt.split('<')[0])):
            return 'noise'
    if kind == 'numeric':
        dc, dt = disp(cand), disp(tgt)
        if dc is not None and dt is not None and dc != dt:
            return 'offset'
        return 'immediate'
    if widen(cand) == widen(tgt):
        return 'width'
    if REG.sub('R', cand) == REG.sub('R', tgt):
        return 'regswap'
    if NUM.sub('#', REG.sub('R', cand)) == NUM.sub('#', REG.sub('R', tgt)):
        return 'immediate'
    return 'operand-form'


def describe(score):
    kinds = [hunk_kind(*h) for h in score['diffs']]
    return tuple(sorted({k for k in kinds if k != 'noise'}))


def cluster(scores, near_only=True):
    groups = collections.defaultdict(list)
    for s in scores:
        if s.get('identical') or not s.get('n_cand'):
            continue
        if near_only and abs(s['n_cand'] - s['n_tgt']) > max(3, s['n_tgt'] // 5):
            continue
        groups[describe(s)].append(s['rva'])
    return groups


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--scores', required=True)
    ap.add_argument('--out')
    a = ap.parse_args()
    groups = cluster(json.load(open(a.scores)))
    rows = sorted(groups.items(), key=lambda kv: -len(kv[1]))
    for kinds, rvas in rows[:25]:
        print(f'{len(rvas):5d}  {"+".join(kinds) or "(noise only)"}')
    if a.out:
        json.dump({'+'.join(k) or 'noise-only': v for k, v in rows}, open(a.out, 'w'))


if __name__ == '__main__':
    main()
