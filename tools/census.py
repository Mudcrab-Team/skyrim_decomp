"""Whole-image census for planning cheap reconstruction lanes: sizes, duplicates, families, blocks.

    python3 tools/census.py build --config .local/config/export_pack.json \
        --export <Ghidra F/V export> --functions .local/analysis/functions.jsonl \
        --fnv .local/analysis/fnv_index.jsonl --parked .local/analysis/parked-census.json \
        [--progress data/progress.json] [--costs data/costs.json] [--tasks .local/tasks] \
        --out .local/analysis/census

Writes, under --out (private, game-derived): `functions.tsv` (one row per function entry: rva,
kind, size, bucket, flags, cluster ids and sizes, family, tier) and `summary.json` (counts,
bytes and RVAs of already public matched functions only; this is what findings quote).

Definitions (also stated in findings/token-census.md):

- Population: every entry of the function table (`build_function_table.py`). Funclets
  (`eh-funclet`) are compiled and compared with their parent, so they are counted apart and never
  as functions to reconstruct.
- Size: the comparator v2 extent the table records (chained .pdata and switch tables included,
  funclets excluded).
- `exact`: identical bytes over that range. `masked` (L1): identical after zeroing every field the
  comparator treats as a reference (rel32 branch and call displacements that leave the function,
  RIP-relative displacements, image-base-relative switch table entries, DIR64 slots), with the same
  field offsets and kinds, the same self-relative targets, the same unwind codes, chained-entry
  layout and handler presence (`tools/analysis/imagemodel.py`). Members of an L1 cluster differ
  only in which symbols they reference. `shape` (L3): per instruction, opcode bytes, the opcode
  extension of group opcodes, the memory operand form (none, register base, base+index, RIP,
  stack) and the widths of immediate and displacement fields; register numbers, immediates,
  displacements and targets dropped; plus handler presence.
- Families: rules over the decoded instructions of functions up to 96 bytes, listed in FAMILIES.
"""
import argparse
import bisect
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import sys
import time

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE / 'analysis'))
sys.path.insert(0, str(HERE / 'ghidra'))
sys.path.insert(0, str(HERE))
import x64  # noqa: E402
import usage_census  # noqa: E402

BUCKETS = ((8, '<=8'), (16, '9-16'), (32, '17-32'), (64, '33-64'), (128, '65-128'), (256, '129-256'),
           (512, '257-512'), (1024, '513-1k'), (4096, '1k-4k'), (None, '>4k'))
TARGET_KINDS = ('ordinary', 'static-initializer', 'teardown', 'thunk', 'import-thunk')
FAMILY_MAX = 96

# family: (one-line shape, generator from metadata alone: 'yes' | 'partial' | 'no', what it needs)
FAMILIES = {
    'empty': ('returns at once', 'yes', 'symbol and signature'),
    'return-constant': ('loads a constant into the return register, returns', 'yes', 'constant, return width'),
    'return-member': ('loads a member of `this` (one load, any width or float), returns', 'yes',
                      'member offset and width (class layout)'),
    'return-member-address': ('returns the address of a member of `this`', 'yes', 'member offset'),
    'return-global': ('loads a global, returns', 'yes', 'global symbol and width'),
    'return-global-address': ('returns the address of a global (GetRTTI-style accessor)', 'yes', 'global symbol'),
    'set-member': ('stores an argument or constant into a member of `this`, returns', 'yes',
                   'member offset, width, value source'),
    'member-reset': ('stores constants into two or more members of `this` without calls, returns', 'partial',
                     'offsets, widths and values; store order and zero-register reuse follow the compiler'),
    'flag-test': ('reads a member, tests or shifts bits, returns the flag (up to 6 instructions)', 'partial',
                  'offset, mask; bitfield vs mask spelling decides test/and/shr'),
    'tail-call-thunk': ('a single jump to another function (forwarder)', 'yes', 'callee symbol and signature'),
    'adjustor-thunk': ('adjusts `this` by a constant and tail-calls', 'yes',
                       'class hierarchy offset and target; normally emitted by the compiler from the class'),
    'member-forwarder': ('loads a member or global into an argument register and tail-calls', 'partial',
                         'member offset and callee'),
    'vcall-thunk': ('loads the vftable and jumps through a slot (vcall thunk)', 'yes', 'slot index'),
    'trivial-ctor-vftable': ('stores vftable pointers (and constants) into `this`, returns `this`, no calls',
                             'partial', 'class, bases and member defaults'),
    'vftable-store-only': ('stores a vftable pointer into `this` and returns (inlined base destructor body)',
                           'partial', 'class whose destructor body is empty'),
    'scalar-deleting-dtor': ('calls the destructor, frees when bit 0 of the flags is set', 'yes',
                             'class, object size, destructor symbol'),
    'refcount-release': ('locked decrement, virtual call when it reaches zero', 'partial', 'offset, slot'),
    'static-init-atexit': ('static initializer that registers a destructor with atexit (<=64 B)', 'partial',
                           'object symbol, constructor and destructor; the order of a TU decides layout'),
    'static-init-other': ('other static initializer', 'no', ''),
    'teardown-stub': ('static teardown stub (<=32 B)', 'partial', 'object and destructor symbols'),
    'teardown-other': ('other static teardown', 'no', ''),
    'import-thunk': ('jump through an import slot', 'yes', 'import name; emitted by the linker'),
    'small-leaf': ('other function up to 96 B without calls', 'no', ''),
    'small-calls': ('other function up to 96 B with calls', 'no', ''),
    'large': ('over 96 B', 'no', ''),
    'undecoded': ('bytes the decoder refused', 'no', ''),
}
GENERATOR = {k for k, v in FAMILIES.items() if v[1] == 'yes'}
GENERATOR_PARTIAL = {k for k, v in FAMILIES.items() if v[1] == 'partial'}

ARITH_GROUP = {(0x83,), (0x81,)}
LOADS = {(0x8B,), (0x0F, 0xB6), (0x0F, 0xB7), (0x0F, 0xBE), (0x0F, 0xBF), (0x63,), (0x0F, 0x10), (0x0F, 0x28),
         (0x0F, 0x7E), (0x0F, 0x6E), (0x0F, 0x5A)}
STORES = {(0x88,), (0x89,), (0xC6,), (0xC7,), (0x0F, 0x11), (0x0F, 0x29), (0x0F, 0xD6), (0x0F, 0x7F)}
TESTS = {(0x84,), (0x85,), (0xF6,), (0xF7,), (0xA8,), (0xA9,), (0x0F, 0xBA), (0x0F, 0xA3), (0x23,), (0x21,),
         (0x80,), (0x81,), (0x83,), (0xC0,), (0xC1,), (0xD0,), (0xD1,), (0x24,), (0x25,)}
ZERO = {(0x33,), (0x31,), (0x0F, 0x57)}
RCX = 1


def bucket(size):
    for hi, label in BUCKETS:
        if hi is None or size <= hi:
            return label
    return BUCKETS[-1][1]


def body(insns):
    """Instructions without trailing padding (int3, nop)."""
    return [(o, i) for o, i in insns if i.flow not in (x64.INT3, x64.NOP)]


def is_store(i):
    return i.opcode in STORES and (i.base is not None or i.rip is not None)


def is_mem(i):
    return i.base is not None or i.rip is not None


def family(insns, code, kind, size, is_vtable=lambda t: False, image_base=0):
    """The family of one function from its decoded instructions (see FAMILIES)."""
    if kind == 'import-thunk':
        return 'import-thunk'
    ops = body(insns)
    if not ops:
        return 'undecoded'
    flows = [i.flow for _, i in ops]
    opc = [i.opcode for _, i in ops]
    calls = sum(1 for f in flows if f in (x64.CALL, x64.ICALL))
    if kind == 'static-initializer':
        if size <= 64 and flows[-1] == x64.JMP and any(i.lea and i.rip is not None for _, i in ops):
            return 'static-init-atexit'
        return 'static-init-other'
    if kind == 'teardown':
        return 'teardown-stub' if size <= 32 else 'teardown-other'
    if size > FAMILY_MAX:
        return 'large'
    n = len(ops)
    last = flows[-1]
    if n == 1:
        if last == x64.RET:
            return 'empty'
        if last == x64.JMP and ops[0][1].rel and ops[0][1].rel[1] == 4:
            return 'tail-call-thunk'
        if last == x64.IJMP and ops[0][1].rip is not None:
            return 'import-thunk'
    if n == 2 and last == x64.RET:
        o, i = ops[0]
        if opc[0] in ZERO and not is_mem(i):
            return 'return-constant'
        if opc[0][0] in range(0xB0, 0xC0) and len(opc[0]) == 1:
            return 'return-constant'
        if opc[0] in ((0xC7,), (0x83,), (0x0D,)) and not is_mem(i):
            return 'return-constant'
        if i.lea and i.rip is not None:
            return 'return-global-address'
        if i.lea and i.base == RCX:
            return 'return-member-address'
        if opc[0] in LOADS and i.rip is not None:
            return 'return-global'
        if opc[0] in LOADS and i.base == RCX:
            return 'return-member'
        if is_store(i) and i.base == RCX:
            return 'set-member'
    if n == 2 and last == x64.JMP and ops[1][1].rel and ops[1][1].rel[1] == 4:
        o, i = ops[0]
        if (opc[0] in ARITH_GROUP and not is_mem(i) and (i.reg & 7) in (0, 5)) or (i.lea and i.base == RCX):
            return 'adjustor-thunk'
        if (opc[0] in LOADS or i.lea) and is_mem(i):
            return 'member-forwarder'
    if n == 2 and last == x64.IJMP and opc[0] == (0x8B,) and i_base(ops[0][1]) == RCX:
        return 'vcall-thunk'
    if last == x64.RET and calls == 0:
        stores = [i for _, i in ops if is_store(i)]
        vt = [i for _, i in ops if i.lea and i.rip is not None and is_vtable(i.rip_target - image_base)]
        plain = all(is_store(i) or i.flow == x64.RET or (i.lea and i.rip is not None) or (opc_i in ZERO)
                    or (i.opcode == (0x8B,) and not is_mem(i)) or (i.opcode[0] in range(0xB8, 0xC0))
                    for (_, i), opc_i in zip(ops, opc))
        if vt and plain:
            returns_this = any(i.opcode == (0x8B,) and not is_mem(i) for _, i in ops)
            return 'trivial-ctor-vftable' if returns_this else 'vftable-store-only'
        if plain and stores and all(i.base == RCX for i in stores) and not any(
                i.lea and i.rip is not None for _, i in ops) and len(stores) >= 2:
            return 'member-reset'
        if n <= 6 and any(o in TESTS for o in opc) and any(i.base == RCX and i.opcode in LOADS | TESTS
                                                             for _, i in ops) and not stores:
            return 'flag-test'
    tests_bit0 = any(i.opcode == (0xF6,) and (i.reg & 7) == 0 and i.imm and code[o + i.imm[0]] == 1
                     for o, i in ops)
    if tests_bit0 and calls >= 1 and n <= 16:
        return 'scalar-deleting-dtor'
    locks = sum(1 for o, _ in ops if code[o] == 0xF0)
    if locks and n <= 20 and x64.ICALL in flows:
        return 'refcount-release'
    return 'small-calls' if calls or x64.JMP in flows else 'small-leaf'


def i_base(i):
    return i.base


def shape_key(insns, eh):
    """L3 digest: per instruction opcode, group extension, memory form and field widths only."""
    h = hashlib.blake2b(digest_size=10)
    for _, i in body(insns):
        if i.rip is not None:
            mem = 'R'
        elif i.base is None and i.index is None:
            mem = '-'
        elif i.base == 4:
            mem = 'S'
        else:
            mem = 'B' + ('I' if i.index is not None else '')
        ext = (i.reg & 7) if i.opcode and (i.opcode[0] in x64.GROUP1 if len(i.opcode) == 1 else
                                          i.opcode[1] in x64.GROUP_0F) and i.reg is not None else ''
        op = bytes(i.opcode)
        if len(op) == 1 and op[0] in x64.REG_IN_OPCODE1:
            op = bytes((op[0] & 0xF8,))
        h.update(('%s/%s/%s/%s/%s/%d;' % (op.hex(), ext, mem,
                                          i.disp[1] if i.disp else 0, i.imm[1] if i.imm else 0,
                                          i.flow)).encode())
    h.update(b'eh' if eh else b'-')
    return h.hexdigest()


# --- funclet extents ------------------------------------------------------------------------------

def funclet_end(f, size, decode_leaf):
    """End of a funclet: its own .pdata end, or for a leaf funclet the end of its first jump/return."""
    if size:
        return f + size
    return decode_leaf(f)


def funclet_verdicts(parent, funclets, pdata_starts, all_entries, int3_pad, decode_leaf):
    """(verdict, cause) for one parent: verdict 'none' | 'v0.5' | 'v0.6' | 'refused'.

    funclets: {entry: size or None}. pdata_starts: sorted list. all_entries: sorted funclet
    entries named by any C++ FuncInfo of the image. int3_pad(e): True when the bytes from e to the
    next 16-byte boundary (at least one) are int3. A target-side estimate: each funclet is assumed
    to end where the image's code for it ends (its .pdata end, or a leaf funclet's first jump or
    return), as a matching candidate's section would.
    """
    if not funclets:
        return 'none', ''
    own = set(funclets) | {parent}
    ok5 = ok6 = True
    cause = ''
    for f, n in sorted(funclets.items()):
        e = funclet_end(f, n, decode_leaf)
        if e is None:
            return 'refused', 'leaf-end-unknown'
        i = bisect.bisect_left(pdata_starts, e)
        starts_here = i < len(pdata_starts) and pdata_starts[i] == e
        if [x for x in all_entries_between(all_entries, f, e) if x not in own]:
            return 'refused', 'foreign-entry-inside'
        if not (starts_here or e in own or int3_pad(e)):
            ok5 = False
            if n:
                cause = cause or 'pdata-end'
            elif e in all_entries:
                cause = cause or 'funclet-entry'
            else:
                ok6 = False
                cause = 'leaf-end-unshown'
    if ok5:
        return 'v0.5', ''
    return ('v0.6', cause) if ok6 else ('refused', cause)


def all_entries_between(sorted_entries, lo, hi):
    i = bisect.bisect_right(sorted_entries, lo)
    j = bisect.bisect_left(sorted_entries, hi)
    return sorted_entries[i:j]


# --- tiers ----------------------------------------------------------------------------------------

def tier(row):
    """T0 stamp, T1 generator, T2 weak single shot, T3 agent, T4 parked; plus the reason.

    T0: a member of an L1 cluster that is not its representative (lowest RVA); the representative
    is solved by whatever tier its own shape gives. T1: family with a generator ('yes'), or
    'partial' ones counted in the high case only (`T1p`). T4: blocked whatever the model.
    T2 candidates: up to 128 B without C++ EH; the rest T3.
    """
    if row['blocked']:
        return 'T4', row['blocked']
    if row['l1_members'] >= 2 and not row['l1_rep']:
        return 'T0', 'L1 duplicate'
    fam = row['family']
    if fam in GENERATOR:
        return 'T1', fam
    if fam in GENERATOR_PARTIAL:
        return 'T1p', fam
    if row['size'] <= 128 and not row['cxx_eh']:
        return 'T2', 'small'
    return 'T3', 'agent'


def blocked_reason(row, parked_skip, parked_noh, funclet_class, v2):
    if row['rva'] in parked_skip:
        return 'skip-first-home-slot'
    if row['rva'] in parked_noh:
        return 'eh-state-store-without-handler'
    if v2 and v2.get('verdict') == 'unsupported':
        rs = [r for r in v2.get('reasons', []) if r not in ('thunk', 'import-thunk')]
        if rs:
            return 'v2-unsupported:' + rs[0]
    if funclet_class == 'refused':
        return 'funclet-extent-unprovable'
    return None


# --- build -----------------------------------------------------------------------------------------

def load_jsonl(path):
    with open(path) as f:
        for line in f:
            if line.strip():
                yield json.loads(line)


def named(row):
    """Public name sources of one table row: 'community' (NG/po3 id or slot), 'meh321', 'rtti'."""
    out = set()
    for n in row.get('names') or []:
        if n.get('how') == 'placeholder':
            continue
        out.add('meh321' if n['source'] == 'meh321' else 'community')
    if (row.get('owner') or {}).get('how', '').startswith('vtable'):
        out.add('rtti')
    return out


def build(args):
    import imagemodel
    import export_pack as ep
    t0 = time.time()
    cfg = json.loads(Path(args.config).read_text())
    rows = {r['rva']: r for r in load_jsonl(args.functions)}
    fnv = set()
    for r in load_jsonl(args.fnv):
        for o in r.get('ours') or []:
            fnv.add(o['rva'])
    parked = json.loads(Path(args.parked).read_text()) if args.parked else {}
    skip, noh = set(parked.get('skip', [])), set(parked.get('m2_noh', []))
    matched = {}
    if args.progress:
        for f in json.loads(Path(args.progress).read_text())['functions']:
            if f['status'] == 'matched':
                matched[f['rva']] = f
    im = imagemodel.open_image(cfg, args.export, with_names=False)
    img = im.img
    base = im.image_base
    vtables = set(im.vtables_raw)
    print('image and tables loaded %.0f s' % (time.time() - t0), file=sys.stderr)

    # Funclet census: every C++ FuncInfo's entries, then each parent's verdict.
    funclets_of = {}
    addrlib = ep.read_addrlib_v5(cfg['addrlib']) if cfg.get('addrlib') else None
    comms = []
    if addrlib and cfg.get('ng_root') and Path(cfg['ng_root']).is_dir():
        comms.append(ep.Community('CommonLibSSE-NG', cfg['ng_root'], cfg['ng_revision'], 'MIT',
                                  Path(args.out) / 'cache'))
    for rva, r in rows.items():
        if r['kind'] in TARGET_KINDS and (r.get('eh') or {}).get('handler_kind') == 'c++':
            entry = img.pdata_at.get(rva)
            if not entry:
                continue
            try:
                end, parts, _ = ep.function_extent(img, rva, entry[0])
                facts = ep.eh_facts(img, addrlib, comms, rva, [(rva, entry[0], entry[1])] + parts)
                funclets_of[rva] = facts['funclets']
            except Exception:
                funclets_of[rva] = None
    # Rule 4 counts entries any FuncInfo names. Parents this walk cannot read (other handlers,
    # unreadable data) still have their funclets in `.text$x`, where the Ghidra export places an
    # entry for each funclet it found from the same FuncInfos; both sets are taken.
    all_entries = sorted({f for fs in funclets_of.values() if fs for f in fs} |
                         {rva for rva, r in rows.items() if r.get('group') == '.text$x'})

    def int3_pad(e):
        pad = (-e) % 16
        if not pad:
            return False
        try:
            return set(img.read(e, pad)) == {0xCC}
        except Exception:
            return False

    def decode_leaf(f):
        try:
            code = img.read(f, 256)
        except Exception:
            return None
        p = 0
        while p < len(code) - 16:
            try:
                i = x64.decode(code, p, base + f + p, len(code))
            except x64.DecodeError:
                return None
            p += i.length
            if i.flow in (x64.JMP, x64.RET, x64.IJMP):
                return f + p
        return None

    # A leaf target outside `.text$x` is not this function's funclet but shared code (one CRT
    # termination stub is named by thousands of FuncInfos); a candidate references it like any other
    # symbol, so it has no extent to prove.
    text_x = {rva for rva, r in rows.items() if r.get('group') == '.text$x'}
    shared_leaf = Counter()
    for rva, fs in list(funclets_of.items()):
        if fs:
            keep = {f: n for f, n in fs.items() if n or f in text_x}
            shared_leaf.update(f for f in fs if f not in keep)
            funclets_of[rva] = keep
    fclass = {}
    for rva, fs in funclets_of.items():
        fclass[rva] = ('refused', 'eh-data-unreadable') if fs is None else funclet_verdicts(
            rva, fs, img.pdata_begins, all_entries, int3_pad, decode_leaf)
    print('funclet census %.0f s' % (time.time() - t0), file=sys.stderr)

    # Per-function facts.
    out = []
    for idx, (rva, esize, _name) in enumerate(im.funcs):
        r = rows.get(rva)
        if r is None:
            continue
        rec = {'rva': rva, 'kind': r['kind'], 'size': r.get('size') or r.get('ghidra_size') or esize,
               'pdata': bool((r.get('eh') or {}).get('has_pdata')),
               'cxx_eh': (r.get('eh') or {}).get('handler_kind') == 'c++',
               'handler': (r.get('eh') or {}).get('handler_kind') or '',
               'funclets': (r.get('v2') or {}).get('funclets', 0) or 0,
               'names': ','.join(sorted(named(r))), 'fnv': rva in fnv, 'matched': rva in matched,
               'funclet_class': fclass.get(rva, ('none', ''))[0],
               'funclet_cause': fclass.get(rva, ('none', ''))[1]}
        if r['kind'] == 'eh-funclet':
            rec.update(exact='', masked='', shape='', family='funclet')
            out.append(rec)
            continue
        a = im.analyse(idx)
        if 'error' in a:
            rec.update(exact='', masked='x%x' % rva, shape='x%x' % rva, family='undecoded')
        else:
            insns, code = a.pop('_insns'), a.pop('_code')
            rec.update(exact=a['exact'], masked=a['masked'], shape=shape_key(insns, a['eh']),
                       family=family(insns, code, r['kind'], rec['size'], lambda t: t in vtables, base))
        rec['blocked'] = blocked_reason(rec, skip, noh, rec['funclet_class'], r.get('v2'))
        out.append(rec)
    print('functions analysed %.0f s' % (time.time() - t0), file=sys.stderr)
    targets = [x for x in out if x['kind'] != 'eh-funclet']
    count = {lvl: Counter(x[lvl] for x in targets) for lvl in ('exact', 'masked', 'shape')}
    rep = {}
    for x in sorted(targets, key=lambda x: (not x['matched'], x['rva'])):
        rep.setdefault(x['masked'], x['rva'])
    for x in targets:
        x['l1_members'] = count['masked'][x['masked']]
        x['l1_rep'] = rep[x['masked']] == x['rva']
        x['exact_members'] = count['exact'][x['exact']]
        x['shape_members'] = count['shape'][x['shape']]
        x['tier'], x['tier_reason'] = tier(x)
    outdir = Path(args.out)
    outdir.mkdir(parents=True, exist_ok=True)
    cols = ('rva', 'kind', 'size', 'pdata', 'cxx_eh', 'handler', 'funclets', 'names', 'fnv', 'matched',
            'funclet_class', 'funclet_cause', 'family', 'exact', 'exact_members', 'masked', 'l1_members', 'l1_rep', 'shape',
            'shape_members', 'blocked', 'tier', 'tier_reason')
    with open(outdir / 'functions.tsv', 'w') as f:
        f.write('\t'.join(cols) + '\n')
        for x in out:
            f.write('\t'.join('0x%x' % x[c] if c == 'rva' else str(x.get(c, '') if x.get(c) is not None else '')
                              for c in cols) + '\n')
    s = summarize(out, matched, args)
    s['shared_leaf_targets'] = {'targets': len(shared_leaf), 'parents': sum(shared_leaf.values())}
    s['seconds'] = round(time.time() - t0, 1)
    (outdir / 'summary.json').write_text(json.dumps(s, indent=1) + '\n')
    print(json.dumps({k: s[k] for k in ('population', 'targets')}, indent=1))
    return 0


# --- summaries ----------------------------------------------------------------------------------

def table(rows, key=None):
    """{bucket: {'functions', 'bytes'}} in bucket order, optionally only rows where key(row)."""
    t = {label: {'functions': 0, 'bytes': 0} for _, label in BUCKETS}
    for r in rows:
        if key is None or key(r):
            b = t[bucket(r['size'])]
            b['functions'] += 1
            b['bytes'] += r['size']
    return t


def cluster_stats(targets, level):
    groups = defaultdict(list)
    for r in targets:
        groups[r[level]].append(r)
    multi = [g for g in groups.values() if len(g) >= 2]
    by_members = Counter()
    for g in multi:
        n = len(g)
        label = '2' if n == 2 else '3-4' if n <= 4 else '5-9' if n <= 9 else '10-19' if n <= 19 else \
            '20-99' if n <= 99 else '100+'
        by_members[label] += 1
    top = sorted(multi, key=lambda g: -len(g))[:20]
    return {'clusters': len(multi), 'functions': sum(len(g) for g in multi),
            'bytes': sum(r['size'] for g in multi for r in g),
            'stampable_functions': sum(len(g) - 1 for g in multi),
            'stampable_bytes': sum(r['size'] for g in multi for r in sorted(g, key=lambda r: r['rva'])[1:]),
            'clusters_by_members': dict(by_members),
            'member_size_buckets': {k: v['functions'] for k, v in table([r for g in multi for r in g]).items()},
            'top20': [{'members': len(g), 'size': g[0]['size'],
                       'family': Counter(r['family'] for r in g).most_common(1)[0][0]} for g in top]}


def summarize(out, matched, args):
    targets = [r for r in out if r['kind'] != 'eh-funclet']
    funclets = [r for r in out if r['kind'] == 'eh-funclet']
    s = {'population': {'entries': len(out), 'funclets': len(funclets),
                        'funclet_bytes': sum(r['size'] for r in funclets),
                        'kinds': dict(Counter(r['kind'] for r in out))},
         'targets': {'functions': len(targets), 'bytes': sum(r['size'] for r in targets)}}
    s['size'] = {
        'all': table(targets),
        'pdata': table(targets, lambda r: r['pdata']),
        'cxx_eh': table(targets, lambda r: r['cxx_eh']),
        'funclets': table(targets, lambda r: r['funclets']),
        'named_community': table(targets, lambda r: 'community' in r['names']),
        'named_meh321': table(targets, lambda r: 'meh321' in r['names']),
        'rtti_owner': table(targets, lambda r: 'rtti' in r['names']),
        'any_public_name': table(targets, lambda r: bool(r['names'])),
        'fnv': table(targets, lambda r: r['fnv']),
    }
    s['clusters'] = {lvl: cluster_stats(targets, lvl) for lvl in ('exact', 'masked', 'shape')}
    fam = defaultdict(lambda: {'functions': 0, 'bytes': 0, 'matched': 0, 'in_l1_dup': 0, 'blocked': 0})
    for r in targets:
        f = fam[r['family']]
        f['functions'] += 1
        f['bytes'] += r['size']
        f['matched'] += r['matched']
        f['in_l1_dup'] += r['l1_members'] >= 2
        f['blocked'] += bool(r['blocked'])
    s['families'] = {k: dict(v, shape=FAMILIES[k][0], generator=FAMILIES[k][1], needs=FAMILIES[k][2])
                     for k, v in sorted(fam.items(), key=lambda kv: -kv[1]['functions'])}
    s['blocked'] = dict(Counter(r['blocked'] for r in targets if r['blocked']))
    s['blocked_bytes'] = dict(Counter({k: 0 for k in s['blocked']}))
    for r in targets:
        if r['blocked']:
            s['blocked_bytes'][r['blocked']] += r['size']
    s['funclet_classes'] = dict(Counter(r['funclet_class'] for r in targets))
    s['funclet_causes'] = dict(Counter('%s:%s' % (r['funclet_class'], r['funclet_cause']) for r in targets
                                       if r['funclet_class'] != 'none'))
    s['blocked_by_kind'] = dict(Counter('%s:%s' % (r['kind'], r['blocked']) for r in targets if r['blocked']))
    s['funclet_class_bytes'] = {}
    for r in targets:
        s['funclet_class_bytes'][r['funclet_class']] = s['funclet_class_bytes'].get(r['funclet_class'], 0) + r['size']
    tiers = defaultdict(lambda: {'functions': 0, 'bytes': 0})
    for r in targets:
        tiers[r['tier']]['functions'] += 1
        tiers[r['tier']]['bytes'] += r['size']
    s['tiers'] = dict(sorted(tiers.items()))
    tier_size = defaultdict(lambda: defaultdict(int))
    for r in targets:
        tier_size[r['tier']][bucket(r['size'])] += 1
    s['tier_size_buckets'] = {k: dict(v) for k, v in sorted(tier_size.items())}
    # Already matched functions: their families, clusters and what stamping them would cover now.
    m = [r for r in targets if r['matched']]
    stamp_now = [r for r in targets if not r['matched'] and r['l1_members'] >= 2 and r['masked'] in
                 {x['masked'] for x in m}]
    t0 = [r for r in targets if r['tier'] == 'T0']
    s['t0_split'] = dict(Counter('%s|%s' % ('static' if r['kind'] in ('static-initializer', 'teardown') else 'code',
                                            'identity' if r['names'] else 'no-identity') for r in t0))
    s['t0_split_bytes'] = {}
    for r in t0:
        k = '%s|%s' % ('static' if r['kind'] in ('static-initializer', 'teardown') else 'code',
                       'identity' if r['names'] else 'no-identity')
        s['t0_split_bytes'][k] = s['t0_split_bytes'].get(k, 0) + r['size']
    s['stamp_now_families'] = dict(Counter(r['family'] for r in stamp_now))
    s['family_tiers'] = {}
    for r in targets:
        s['family_tiers'].setdefault(r['family'], Counter())[r['tier']] += 1
    s['family_tiers'] = {k: dict(v) for k, v in s['family_tiers'].items()}
    s['matched_cost'] = matched_cost(m, getattr(args, 'costs', None), getattr(args, 'tasks', None))
    s['matched'] = {'functions': len(m), 'bytes': sum(r['size'] for r in m),
                    'families': dict(Counter(r['family'] for r in m)),
                    'in_l1_clusters': sum(1 for r in m if r['l1_members'] >= 2),
                    'stampable_now_functions': len(stamp_now),
                    'stampable_now_bytes': sum(r['size'] for r in stamp_now),
                    'tiers': dict(Counter(r['tier'] for r in m))}
    return s


# --- projection ------------------------------------------------------------------------------------

# Every number here is an ASSUMPTION unless its comment says measured; findings/token-census.md
# states which. (low, high) pairs; money in USD at API list prices (usage_census.PRICES).
ASSUMPTIONS = {
    # Cost of one function relative to the matched sample (mean 61 B) by size bucket.
    'size_factor': {'<=8': (1, 1), '9-16': (1, 1), '17-32': (1, 1), '33-64': (1, 1.3), '65-128': (1.2, 1.8),
                    '129-256': (2, 3), '257-512': (3, 5), '513-1k': (5, 9), '1k-4k': (8, 16), '>4k': (15, 40)},
    # Weak-model harness: calls per function and USD per call (Haiku 5.5 or GPT-6 Luna, 8-20k input
    # tokens of which 50-70% a cached prefix, 1-2k output), for functions up to 512 B.
    'harness_calls': (2, 5),
    'harness_usd_per_call': (0.0009, 0.0021),
    'harness_max_bucket': '257-512',
    'escalate_share': (0.2, 0.5),           # harness failures that go to a Sonnet agent as today
    # Tiered plan.
    'cluster_review_usd': (0.3, 1.0),       # one Reviewer pass per stamped cluster (family-level review)
    'sample_share': (0.05, 0.10),           # random second check of stamped / generated functions
    'generator_families': 25,
    'generator_build_usd': (20, 80),        # Opus Engineer per family generator, one time
    'family_review_usd': (2, 5),
    'batch_review_usd': (0.05, 0.15),       # per function, Reviewer writes a file and returns a table
    'orchestration_usd': (0.01, 0.05),      # per function once integration and dispatch are scripted
    'triage_share': (0.5, 1.0),             # of today's triage cost, for T2/T3
    'review_t3_usd': (0.10, 0.274),         # per function before the size factor; high = measured today
}


def stage_costs(roles):
    """Measured USD per stage from usage_census roles output, and the matched-function count."""
    return {k: v['usd'] for k, v in roles['by_stage'].items()}


def project(summary, roles, matched_count, a=ASSUMPTIONS):
    """{plan: (low USD, high USD)} for the reachable inventory, and the per-function stage costs."""
    st = stage_costs(roles)
    per = {k: v / matched_count for k, v in st.items()}
    marginal = sum(per.get(k, 0) for k in ('draft', 'function-review', 'integration', 'triage', 'prep',
                                            'orchestration'))
    tsb = summary['tier_size_buckets']
    order = [label for _, label in BUCKETS]
    harness_max = order.index(a['harness_max_bucket'])
    reach = Counter()
    for t, b in tsb.items():
        if t != 'T4':
            for k, n in b.items():
                reach[k] += n
    out = {}
    for lo_hi in (0, 1):
        sf = {k: v[lo_hi] for k, v in a['size_factor'].items()}
        # Plan A: today's process for every reachable function.
        plan_a = sum(n * sf[k] * marginal for k, n in reach.items())
        # Plan B: weak-model harness replaces drafting up to the harness bucket.
        draft = per.get('draft', 0)
        harness = a['harness_calls'][lo_hi] * a['harness_usd_per_call'][lo_hi]
        esc = a['escalate_share'][lo_hi]
        plan_b = 0.0
        for k, n in reach.items():
            rest = (marginal - draft) * sf[k]
            if order.index(k) <= harness_max:
                plan_b += n * (rest + harness + esc * draft * sf[k])
            else:
                plan_b += n * (rest + draft * sf[k])
        # Plan C: tiers.
        t0 = summary['tiers'].get('T0', {}).get('functions', 0)
        clusters = summary['clusters']['masked']['clusters']
        c_t0 = clusters * a['cluster_review_usd'][lo_hi] + t0 * a['sample_share'][lo_hi] * a['batch_review_usd'][lo_hi]
        t1 = summary['tiers'].get('T1', {}).get('functions', 0) + summary['tiers'].get('T1p', {}).get('functions', 0)
        c_t1 = a['generator_families'] * (a['generator_build_usd'][lo_hi] + a['family_review_usd'][lo_hi]) + \
            t1 * a['sample_share'][lo_hi] * a['batch_review_usd'][lo_hi]
        c_t2 = 0.0
        for k, n in tsb.get('T2', {}).items():
            c_t2 += n * (harness + esc * draft * sf[k] + a['batch_review_usd'][lo_hi] * sf[k] +
                         a['orchestration_usd'][lo_hi] + a['triage_share'][lo_hi] * per.get('triage', 0) * esc)
        c_t3 = 0.0
        for k, n in tsb.get('T3', {}).items():
            drafting = (harness + esc * draft * sf[k]) if order.index(k) <= harness_max else draft * sf[k]
            c_t3 += n * (drafting + a['review_t3_usd'][lo_hi] * sf[k] + a['orchestration_usd'][lo_hi] +
                         a['triage_share'][lo_hi] * per.get('triage', 0) * sf[k])
        out.setdefault('A', []).append(round(plan_a))
        out.setdefault('B', []).append(round(plan_b))
        out.setdefault('C', []).append(round(c_t0 + c_t1 + c_t2 + c_t3))
        out.setdefault('C:T0', []).append(round(c_t0))
        out.setdefault('C:T1', []).append(round(c_t1))
        out.setdefault('C:T2', []).append(round(c_t2))
        out.setdefault('C:T3', []).append(round(c_t3))
    return {'plans': out, 'per_function_measured': {k: round(v, 4) for k, v in per.items()},
            'marginal_per_function': round(marginal, 4), 'reachable_functions': sum(reach.values())}


def cmd_project(args):
    summary = json.loads(Path(args.summary).read_text())
    roles = json.loads(Path(args.roles).read_text())
    res = project(summary, roles, args.matched)
    print(json.dumps(res, indent=1))
    return 0


def task_attempts(tasks_dir):
    """{rva: (unit attempts / unit functions, unit functions)} from the draft loop's task dirs."""
    out = {}
    if not tasks_dir:
        return out
    for tj in Path(tasks_dir).glob('**/task.json'):
        try:
            t = json.loads(tj.read_text())
        except ValueError:
            continue
        fs = t.get('functions') or []
        att = tj.parent / 'attempts.jsonl'
        n = 0
        if att.exists():
            for line in att.read_text().splitlines():
                try:
                    n += bool(json.loads(line).get('counted', True))
                except ValueError:
                    pass
        for f in fs:
            rva = int(f['rva'], 16)
            if rva not in out or n:
                out[rva] = (n / max(1, len(fs)), len(fs), n)
    return out


def matched_cost(matched_rows, costs_path, tasks_dir):
    """Per family of matched functions: attempts per function and allocated tokens by stage."""
    alloc = defaultdict(lambda: defaultdict(float))
    if costs_path:
        for rec in json.loads(Path(costs_path).read_text())['records']:
            if not rec.get('model'):
                continue
            tot = sum(rec['tokens'].values())
            out_tok = rec['tokens'].get('output', 0)
            t = rec['tokens']
            # The ledger keeps one cache-write count; subagent transcripts show only 5-minute writes.
            usd = usage_census.price(rec['model'], {'input': t['input'], 'cw5m': t['cache_creation'], 'cw1h': 0,
                                                    'cache_read': t['cache_read'], 'output': t['output']}) or 0.0
            for a in rec['allocations']:
                if a['target'].startswith('sse-steam-1-7-104:'):
                    rva = int(a['target'].split(':')[1], 16)
                    alloc[rva][rec['stage'] + ':all'] += tot * a['share']
                    alloc[rva][rec['stage'] + ':output'] += out_tok * a['share']
                    alloc[rva][rec['stage'] + ':usd'] += usd * a['share']
    att = task_attempts(tasks_dir)
    fam = defaultdict(lambda: {'functions': 0, 'with_attempts': 0, 'attempts': 0.0, 'with_tokens': 0,
                               'draft_tokens': 0.0, 'review_tokens': 0.0, 'other_tokens': 0.0,
                               'draft_usd': 0.0, 'review_usd': 0.0, 'other_usd': 0.0})
    dist = Counter()
    for r in matched_rows:
        f = fam[r['family']]
        f['functions'] += 1
        if r['rva'] in att and att[r['rva']][2]:
            f['with_attempts'] += 1
            f['attempts'] += att[r['rva']][0]
            a = att[r['rva']][0]
            dist['<=1' if a <= 1 else '1-2' if a <= 2 else '2-4' if a <= 4 else '4-8' if a <= 8 else '>8'] += 1
        if r['rva'] in alloc:
            f['with_tokens'] += 1
            for k, v in alloc[r['rva']].items():
                stage, what = k.split(':')
                if what in ('all', 'usd'):
                    unit = 'tokens' if what == 'all' else 'usd'
                    key = ('draft_' if stage == 'draft' else 'review_' if stage == 'review' else 'other_') + unit
                    f[key] += v
    return {'families': {k: {x: round(y, 2) if isinstance(y, float) else y for x, y in v.items()}
                         for k, v in sorted(fam.items(), key=lambda kv: -kv[1]['functions'])},
            'attempts_per_function_distribution': dict(dist)}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    b = sub.add_parser('build')
    b.add_argument('--config', required=True)
    b.add_argument('--export', required=True)
    b.add_argument('--functions', required=True)
    b.add_argument('--fnv', required=True)
    b.add_argument('--parked')
    b.add_argument('--progress')
    b.add_argument('--costs')
    b.add_argument('--tasks')
    b.add_argument('--out', required=True)
    pr = sub.add_parser('project')
    pr.add_argument('--summary', required=True)
    pr.add_argument('--roles', required=True, help='usage_census.py roles output')
    pr.add_argument('--matched', type=int, required=True, help='matched functions the roles paid for')
    args = ap.parse_args(argv)
    return {'build': build, 'project': cmd_project}[args.cmd](args)


if __name__ == '__main__':
    sys.exit(main())
