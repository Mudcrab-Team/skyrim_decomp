#!/usr/bin/env python3
"""Look up how the sibling source spells a code shape.

    lookup.py index  --asm DIR --out srcmap.pkl            parse /FAs listings: symbol -> instructions with source lines
    lookup.py rva    --rva 0x1e5b30 [--top 3]              closest sibling functions to a target function, with source
    lookup.py idiom  --idiom 'xor eax, eax; ret' [--max 8] sibling functions whose instruction stream contains the idiom

Each idiom item is a regular expression matched at the start of one listing instruction ("mov eax, DWORD PTR [rcx+48]"),
consecutive items must be consecutive instructions; an item `..` allows up to 8 other instructions. Output names the sibling unit, line numbers and the source text
(sibling source is CC0); it never prints target bytes. Private: .local/ only.
"""
import argparse, collections, pickle, re, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
PROC = re.compile(r'^(\S+) PROC\b')
SRC = re.compile(r'^; (\d+)\s+:(.*)$')
FILE = re.compile(r'^; File (.+)$')
INSN = re.compile(r'^\t([a-z][a-z0-9]*)\t?(.*?)(?:\s*;.*)?$')


def build_index(asmdir):
    idx = {}
    for asm in sorted(Path(asmdir).glob('*.asm')):
        cur, line, src, lines, file = None, 0, None, {}, None
        for raw in asm.read_text(errors='replace').splitlines():
            m = FILE.match(raw)
            if m:
                file = m.group(1).split('shadow\\', 1)[-1].replace('\\', '/')
            m = PROC.match(raw)
            if m and 'COMDAT' in raw:
                cur = {'unit': asm.stem, 'file': file, 'ins': [], 'lines': {}}
                idx[(asm.stem, m.group(1))] = cur
                line = 0
                continue
            if cur is None:
                continue
            if ' ENDP' in raw:
                cur = None
                continue
            m = SRC.match(raw)
            if m:
                line = int(m.group(1))
                cur['lines'][line] = m.group(2).strip()
                continue
            m = INSN.match(raw)
            if m and not raw.startswith('\t;'):
                cur['ins'].append((f'{m.group(1)} {m.group(2)}'.strip(), line))
    return idx


def show(key, f, hit=None, width=6):
    # hit is a list of matched instruction indexes, or None for the head of the function
    lines = sorted(f['lines'])
    head = f'{key[1][:70]}  unit={f["unit"]}  file={f["file"]}  lines {lines[0] if lines else "?"}-{lines[-1] if lines else "?"}'
    out = [head]
    if hit is not None:
        sel = sorted({f['ins'][j][1] for j in hit if f['ins'][j][1]})
    else:
        sel = lines[:14]
    for ln in sel:
        out.append(f'    {ln}: {f["lines"].get(ln, "")}')
    return '\n'.join(out)


GAP = 8


def match_at(ins, pats, i, k, picked):
    """Match pats[k:] with pats[k] at ins[i]; an item '..' lets up to GAP other instructions pass."""
    if k == len(pats):
        return picked
    if pats[k] is None:
        for skip in range(0, GAP + 1):
            r = match_at(ins, pats, i + skip, k + 1, picked)
            if r:
                return r
        return None
    if i < len(ins) and pats[k].match(ins[i][0]):
        return match_at(ins, pats, i + 1, k + 1, picked + [i])
    return None


def idiom(idx, items, limit):
    pats = [None if i.strip() in ('..', '...') else re.compile(i.strip()) for i in items]
    seen, res = set(), []
    for key, f in idx.items():
        ins = f['ins']
        for i in range(len(ins)):
            hit = match_at(ins, pats, i, 0, [])
            if hit:
                text = tuple(f['lines'].get(ins[j][1], '') for j in hit)
                if text not in seen:
                    seen.add(text)
                    res.append((key, f, hit))
                break
    return res[:limit], len(res)


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest='cmd', required=True)
    p = sp.add_parser('index'); p.add_argument('--asm', required=True); p.add_argument('--out', required=True)
    for n in ('rva', 'idiom'):
        p = sp.add_parser(n)
        p.add_argument('--srcmap')
        p.add_argument('--root', required=True, help='directory holding srcmap.pkl and hits_full.pkl')
    sp.choices['rva'].add_argument('--rva', required=True, type=lambda v: int(v, 0))
    sp.choices['rva'].add_argument('--top', type=int, default=3)
    sp.choices['idiom'].add_argument('--idiom', required=True)
    sp.choices['idiom'].add_argument('--max', type=int, default=8)
    a = ap.parse_args()
    if a.cmd == 'index':
        idx = build_index(a.asm)
        pickle.dump(idx, open(a.out, 'wb'))
        print(len(idx), 'functions indexed')
        return
    idx = pickle.load(open(a.srcmap or f'{a.root}/srcmap.pkl', 'rb'))
    if a.cmd == 'idiom':
        res, total = idiom(idx, a.idiom.split(';'), a.max)
        print(f'{total} distinct spellings; showing {len(res)}')
        for key, f, hit in res:
            print(show(key, f, hit))
        return
    H = pickle.load(open(f'{a.root}/hits_full.pkl', 'rb'))
    if a.rva not in H:
        print('no lead above the match floor for this function')
        return
    cands, close = H[a.rva]
    print(f'{close} candidates within 0.02 of the best')
    for sc, j, key in cands[:a.top]:
        f = idx.get((key[0].replace('_', '_'), key[1])) or next((v for k, v in idx.items() if k[1] == key[1]), None)
        print(f'shape score {sc} (shingles {j})')
        print(show(key, f) if f else f'{key[1]} (no listing)')


if __name__ == '__main__':
    main()
