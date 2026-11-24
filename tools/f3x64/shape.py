#!/usr/bin/env python3
"""Code-shape signatures for compiled functions, and a shingle index to match two corpora.

A signature keeps what survives a change of struct layout and pointer size under the same
compiler: the mnemonic stream, call count, large immediates and string literals. Registers,
displacements and branch/call targets are dropped. Inputs are private (compiled objects and the
target image); outputs go under .local/ only.

    shape.py objsigs  --objdir D --out F.pkl            signatures of every function in x64 objects
    shape.py imgsigs  --image EXE --table functions.jsonl --out F.pkl   signatures of image functions
    shape.py match    --a F3.pkl --b IMG.pkl --out hits.json            shingle-index lead search
"""
import argparse, bisect, collections, json, pickle, re, struct, subprocess, sys
from pathlib import Path

OBJDUMP = '/opt/homebrew/opt/llvm/bin/llvm-objdump'
HEXNUM = re.compile(r'(?<![\w+])-?0x[0-9a-f]+\b')
SKIP = {'int3', 'nop', 'nopw', 'nopl', 'xchg ax, ax'}
K = 3
POSTING_CAP = 20000


def split_ops(text):
    text = text.split('#', 1)[0].strip()
    out, depth, cur = [], 0, ''
    for ch in text:
        depth += ch == '['
        depth -= ch == ']'
        if ch == ',' and depth == 0:
            out.append(cur.strip()); cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def new_sig():
    return {'mn': [], 'calls': 0, 'imms': set(), 'strs': set(), 'loops': 0}


def feed(sig, mn, ops, strtok=None):
    """Add one instruction to a signature; ops are the operand strings, strtok a resolved literal."""
    if mn in SKIP or mn.startswith('nop'):
        return
    sig['mn'].append(mn)
    if mn == 'call':
        sig['calls'] += 1
    for o in ops[1:] if mn not in ('push', 'ret') else ops:
        if '[' in o:
            continue
        m = re.fullmatch(r'(-?)0x([0-9a-f]+)', o)
        if m:
            v = int(m.group(2), 16)
            if v >= 0x10 and v not in (0xffffffff,):
                sig['imms'].add(v)
    if strtok:
        sig['strs'].add(strtok)


def done(sig):
    return {'mn': sig['mn'], 'calls': sig['calls'], 'imms': sorted(sig['imms']), 'strs': sorted(sig['strs'])}


# ---------------------------------------------------------------- COFF (objects)

def coff_symbol_bytes(path):
    """{symbol name: bytes} for data symbols (string literals) in a COFF object."""
    d = Path(path).read_bytes()
    nsec, symoff, nsym = struct.unpack_from('<H', d, 2)[0], *struct.unpack_from('<II', d, 8)
    secs = []
    for i in range(nsec):
        o = 20 + 40 * i
        size, ptr = struct.unpack_from('<II', d, o + 16)
        secs.append((ptr, size))
    strtab = symoff + 18 * nsym
    out, i = {}, 0
    while i < nsym:
        o = symoff + 18 * i
        n = d[o:o + 8]
        if n[:4] == b'\0\0\0\0':
            off = struct.unpack_from('<I', n, 4)[0]
            name = d[strtab + off:d.index(b'\0', strtab + off)].decode('latin1')
        else:
            name = n.rstrip(b'\0').decode('latin1')
        value, secno = struct.unpack_from('<Ih', d, o + 8)
        naux = d[o + 17]
        if secno > 0 and name.startswith('??_C@'):
            ptr, size = secs[secno - 1]
            out[name] = d[ptr + value:ptr + size]
        i += 1 + naux
    return out


def printable(b):
    b = b.split(b'\0', 1)[0]
    if len(b) >= 4 and all(32 <= c < 127 or c in (9, 10, 13) for c in b):
        return b.decode('ascii')
    return None


def objsigs(objdir):
    res = {}
    for obj in sorted(Path(objdir).glob('*.obj')):
        syms = coff_symbol_bytes(obj)
        out = subprocess.run([OBJDUMP, '-d', '-r', '--no-show-raw-insn', '--x86-asm-syntax=intel', str(obj)],
                             capture_output=True, text=True).stdout
        cur, sig, last = None, None, None
        for line in out.splitlines():
            m = re.match(r'^[0-9a-f]{16} <(.+)>:$', line)
            if m:
                if cur and sig and sig['mn']:
                    res[(obj.stem, cur)] = done(sig)
                cur, sig, last = m.group(1), new_sig(), None
                continue
            if sig is None:
                continue
            m = re.match(r'^\s+[0-9a-f]+:\s+IMAGE_REL_AMD64_\w+\s+(\S+)', line)
            if m:
                tok = None
                if m.group(1) in syms:
                    tok = printable(syms[m.group(1)])
                if tok and last is not None:
                    sig['strs'].add(tok)
                continue
            m = re.match(r'^\s+[0-9a-f]+:\s+(\S[^\t]*)\t?(.*)$', line)
            if m:
                last = m.group(1)
                feed(sig, m.group(1).strip(), split_ops(m.group(2)))
        if cur and sig and sig['mn']:
            res[(obj.stem, cur)] = done(sig)
    return res


# ---------------------------------------------------------------- PE image

def pe_sections(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    nsec = struct.unpack_from('<H', data, pe + 6)[0]
    opt = struct.unpack_from('<H', data, pe + 20)[0]
    base = struct.unpack_from('<Q', data, pe + 24 + 24)[0]
    secs = []
    o = pe + 24 + opt
    for i in range(nsec):
        vsize, va, rsize, rptr = struct.unpack_from('<IIII', data, o + 40 * i + 8)
        secs.append((va, max(vsize, rsize), rptr))
    return base, secs


def imgsigs(image, table):
    data = Path(image).read_bytes()
    base, secs = pe_sections(data)

    def read_cstr(va):
        rva = va - base
        for sva, sz, ptr in secs:
            if sva <= rva < sva + sz:
                s = data[ptr + rva - sva:ptr + rva - sva + 300]
                return printable(s)
        return None

    fns = [json.loads(l) for l in open(table)]
    fns = [f for f in fns if f['kind'] == 'ordinary']
    fns.sort(key=lambda f: f['rva'])
    starts = [f['rva'] for f in fns]
    ends = [f['rva'] + f['size'] for f in fns]
    proc = subprocess.Popen([OBJDUMP, '-d', '--no-show-raw-insn', '--x86-asm-syntax=intel', str(image)],
                            stdout=subprocess.PIPE, text=True, bufsize=1 << 20)
    res, cur, sig = {}, None, None
    for line in proc.stdout:
        if not line or line[0] == ' ':
            continue
        c = line.find(':')
        if c < 8 or c > 17:
            continue
        try:
            rva = int(line[:c], 16) - base
        except ValueError:
            continue
        i = bisect.bisect_right(starts, rva) - 1
        f = fns[i] if i >= 0 and rva < ends[i] else None
        if f is not (cur and cur[0]):
            if cur and sig and sig['mn']:
                res[cur[1]] = done(sig)
            cur = (f, f['rva']) if f else None
            sig = new_sig() if f else None
        if sig is None:
            continue
        parts = line[c + 1:].strip().split('\t', 1)
        mn = ' '.join(parts[0].split())
        ops = parts[1] if len(parts) > 1 else ''
        tok = None
        t = re.search(r'#\s*0x([0-9a-f]+)', ops)
        if t and mn == 'lea':
            tok = read_cstr(int(t.group(1), 16))
        feed(sig, mn, split_ops(ops), tok)
    if cur and sig and sig['mn']:
        res[cur[1]] = done(sig)
    proc.wait()
    return res


# ---------------------------------------------------------------- matching

def shingles(mn):
    return {hash(tuple(mn[i:i + K])) for i in range(max(1, len(mn) - K + 1))}


def jaccard(a, b):
    return len(a & b) / len(a | b) if a or b else 0.0


def match(a, b, floor=0.5, topn=3):
    """For each signature in b, the best entries of a by blended shingle/immediate/string similarity."""
    keys = list(a)
    sh = [shingles(a[k]['mn']) for k in keys]
    post = collections.defaultdict(list)
    for i, s in enumerate(sh):
        for g in s:
            post[g].append(i)
    out = {}
    for bk, bs in b.items():
        n = len(bs['mn'])
        if n < 8:
            continue
        s = shingles(bs['mn'])
        cnt = collections.Counter()
        for g in s:
            lst = post.get(g)
            if lst and len(lst) < POSTING_CAP:
                cnt.update(lst)
        best = []
        for i, c in cnt.most_common(30):
            na = len(a[keys[i]]['mn'])
            if not (0.6 <= na / n <= 1.7):
                continue
            j = c / (len(s) + len(sh[i]) - c)
            ia, ib = set(a[keys[i]]['imms']), set(bs['imms'])
            sa, sb = set(a[keys[i]]['strs']), set(bs['strs'])
            ji = jaccard(ia, ib) if ia or ib else None
            js = jaccard(sa, sb) if sa or sb else None
            parts = [(j, 4)]
            if ji is not None: parts.append((ji, 1))
            if js is not None: parts.append((js, 2))
            score = sum(v * w for v, w in parts) / sum(w for _, w in parts)
            if abs(a[keys[i]]['calls'] - bs['calls']) > max(1, n // 6):
                score *= 0.85
            best.append((round(score, 4), round(j, 4), keys[i]))
        best.sort(reverse=True)
        if best and best[0][0] >= floor:
            close = sum(1 for x in best if x[0] >= best[0][0] - 0.02)
            out[bk] = (best[:topn], close)
    return out


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest='cmd', required=True)
    p = sp.add_parser('objsigs'); p.add_argument('--objdir', required=True); p.add_argument('--out', required=True)
    p = sp.add_parser('imgsigs'); p.add_argument('--image', required=True); p.add_argument('--table', required=True); p.add_argument('--out', required=True)
    p = sp.add_parser('match'); p.add_argument('--a', required=True); p.add_argument('--b', required=True); p.add_argument('--out', required=True); p.add_argument('--floor', type=float, default=0.5)
    a = ap.parse_args()
    if a.cmd == 'objsigs':
        r = objsigs(a.objdir); pickle.dump(r, open(a.out, 'wb')); print(len(r), 'functions')
    elif a.cmd == 'imgsigs':
        r = imgsigs(a.image, a.table); pickle.dump(r, open(a.out, 'wb')); print(len(r), 'functions')
    else:
        A, B = pickle.load(open(a.a, 'rb')), pickle.load(open(a.b, 'rb'))
        seen, A2 = set(), {}
        for k, v in A.items():  # an inline function compiled into many units is one candidate
            if k[1] not in seen:
                seen.add(k[1]); A2[k] = v
        groups, A3 = collections.defaultdict(list), {}
        for k, v in A2.items():  # identical code shape, constants and strings: one candidate, many names
            sig = (tuple(v['mn']), tuple(v['imms']), tuple(v['strs']))
            if sig not in groups:
                A3[k] = v
            groups[sig].append(k)
        A = A3
        print(len(A2), 'distinct symbols,', len(A), 'distinct shapes')
        r = match(A, B, a.floor)
        pickle.dump(r, open(a.out, 'wb')); print(len(r), 'sources with a lead')


if __name__ == '__main__':
    main()
