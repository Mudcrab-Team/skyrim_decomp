#!/usr/bin/env python3
"""Score a compiled sibling function against the target function it was matched to.

Both sides are disassembled with raw bytes. Candidate relocation fields (calls, data references)
are masked, since a lone object cannot know where the callee lands. Instructions are then
classed as exact, numeric-only (displacement or immediate differs, the text is otherwise equal)
or structural. This is a lead score, not comparator evidence: only tools/compare.py decides a
match. Output stays under .local/.
"""
import argparse, collections, difflib, json, pickle, re, struct, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from shape import OBJDUMP, pe_sections

INS = re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*(.*)$')
REL = re.compile(r'^\s*([0-9a-f]+):\s+IMAGE_REL_AMD64_(\w+)\s+(\S+)')
NUM = re.compile(r'-?0x[0-9a-f]+|\b\d+\b')


def parse(text, with_relocs):
    rows, cur, blocks = [], None, {}
    for line in text.splitlines():
        m = re.match(r'^[0-9a-f]{16} <(.+)>:$', line)
        if m:
            cur = blocks.setdefault(m.group(1), [])
            continue
        m = INS.match(line)
        if m:
            row = {'off': int(m.group(1), 16), 'b': m.group(2).split(), 't': ' '.join(m.group(3).split()), 'rel': []}
            (cur if cur is not None else rows).append(row)
            continue
        m = REL.match(line)
        if m and with_relocs:
            tgt = cur if cur else rows
            if tgt:
                tgt[-1]['rel'].append(int(m.group(1), 16) - tgt[-1]['off'])
    return blocks if cur is not None or blocks else rows


_objcache = {}


def cand_rows(obj, sym):
    if obj not in _objcache:
        out = subprocess.run([OBJDUMP, '-d', '-r', '--x86-asm-syntax=intel', str(obj)], capture_output=True, text=True).stdout
        _objcache[obj] = parse(out, True)
    rows = _objcache[obj].get(sym, [])
    base = rows[0]['off'] if rows else 0
    for r in rows:
        r['off'] -= base
    return rows


def target_rows(image, base, rva, size):
    out = subprocess.run([OBJDUMP, '-d', '--x86-asm-syntax=intel', f'--start-address=0x{base + rva:x}',
                          f'--stop-address=0x{base + rva + size:x}', str(image)], capture_output=True, text=True).stdout
    rows = parse(out, False)
    if isinstance(rows, dict):
        rows = [r for v in rows.values() for r in v]
    return rows


def mask(row):
    b = list(row['b'])
    for off in row['rel']:
        for i in range(off, off + 4):
            if i < len(b):
                b[i] = '..'
    return b


def score(c, t):
    res = {'n_cand': len(c), 'n_tgt': len(t), 'bytes_cand': sum(len(r['b']) for r in c),
           'bytes_tgt': sum(len(r['b']) for r in t)}
    sm = difflib.SequenceMatcher(None, [re.sub(r'\s.*', '', r['t']) for r in c], [re.sub(r'\s.*', '', r['t']) for r in t], autojunk=False)
    exact = numeric = struct_ = 0
    diffs = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for r, q in zip(c[i1:i2], t[j1:j2]):
                mb, tb = mask(r), q['b']
                same = len(mb) == len(tb) and all(x == '..' or x == y for x, y in zip(mb, tb))
                if same:
                    exact += 1
                elif NUM.sub('#', r['t']) == NUM.sub('#', q['t']) or r['rel']:
                    numeric += 1
                    diffs.append(('numeric', r['t'], q['t']))
                else:
                    struct_ += 1
                    diffs.append(('operands', r['t'], q['t']))
        else:
            struct_ += max(i2 - i1, j2 - j1)
            diffs.append((tag, ' ; '.join(r['t'] for r in c[i1:i2]), ' ; '.join(r['t'] for r in t[j1:j2])))
    res.update(exact=exact, numeric=numeric, struct=struct_, diffs=diffs)
    flat_c = [x for r in c for x in mask(r)]
    flat_t = [x for r in t for x in r['b']]
    res['byte_diff'] = (sum(1 for x, y in zip(flat_c, flat_t) if x != '..' and x != y) + abs(len(flat_c) - len(flat_t))
                        if flat_c and flat_t else None)
    res['identical'] = res['n_cand'] == res['n_tgt'] and res['byte_diff'] == 0
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--hits', required=True)
    ap.add_argument('--objdir', required=True)
    ap.add_argument('--image', required=True)
    ap.add_argument('--table', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--min-score', type=float, default=0.9)
    ap.add_argument('--min-instr', type=int, default=20)
    ap.add_argument('--max-amb', type=int, default=3)
    ap.add_argument('--rvas', help='JSON list of rvas to score instead of filtering')
    a = ap.parse_args()
    H = pickle.load(open(a.hits, 'rb'))
    tab = {}
    for l in open(a.table):
        f = json.loads(l)
        if f['kind'] == 'ordinary':
            tab[f['rva']] = f
    base, _ = pe_sections(Path(a.image).read_bytes()[:4096 * 4])
    if a.rvas:
        sel = json.loads(open(a.rvas).read())
    else:
        sel = [r for r, (h, c) in H.items() if h[0][0] >= a.min_score and c <= a.max_amb and tab[r]['size'] >= 4 * a.min_instr]
    out = []
    for r in sel:
        (sc, j, key) = H[r][0][0]
        c = cand_rows(Path(a.objdir) / (key[0] + '.obj'), key[1])
        t = target_rows(a.image, base, r, tab[r]['size'])
        s = score(c, t)
        s.update(rva=r, key=list(key), shape=sc, size=tab[r]['size'], named=bool(tab[r]['names']))
        out.append(s)
    json.dump(out, open(a.out, 'w'))
    print(len(out), 'scored;', sum(1 for s in out if s['identical']), 'identical after reloc masking')


if __name__ == '__main__':
    main()
