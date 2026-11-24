"""Shape index of the pinned image: one record per function, keyed by RVA (private, game-derived).

A record holds the digests `tools/analysis/clusters.py` groups by, plus the pattern of which
reference fields share a target:

  masked   code with reference fields blanked (relocation level)
  shape    masked with displacements and immediates blanked too
  pattern  first-seen index of each reference target, in field order; two functions are strict
           twins only when masked and pattern both agree, because source names one symbol per
           distinct target

The cache is keyed by RVA, so a rerun analyses only functions it has not seen. Only counts
and RVAs are ever printed; the cache itself stays under `.local/`.
"""
import hashlib
import json
import multiprocessing as mp
from pathlib import Path
import sys
import time

TOOLS = Path(__file__).resolve().parents[1]
for sub in ('analysis', 'ghidra', ''):
    sys.path.insert(0, str(TOOLS / sub) if sub else str(TOOLS))
import imagemodel  # noqa: E402

KINDS = ('ordinary', 'static-initializer', 'teardown', 'thunk')
VERSION = 1
_IMAGE = None


def pattern_of(targets):
    seen, out = {}, []
    for _off, kind, target in targets:
        out.append((kind, seen.setdefault(target, len(seen))))
    return hashlib.blake2b(repr(out).encode(), digest_size=6).hexdigest()


def record(result):
    return {'rva': result['rva'], 'size': result['size'], 'masked': result['masked'],
            'pattern': pattern_of(result['targets']), 'shape': result['shape'], 'exact': result['exact'],
            'nfields': result['nfields'], 'ntargets': len({t for _, _, t in result['targets']}),
            'nops': len(result['operands']), 'eh': result['eh'], 'flags': result['flags'],
            'targets': [list(t) for t in result['targets']]}


def _init(config, export):
    global _IMAGE
    _IMAGE = open_image(config, export)


def _work(i):
    result = _IMAGE.analyse(i)
    if 'error' in result:
        return {'rva': _IMAGE.funcs[i][0], 'error': result['error'].split(':')[0]}
    return record(result)


def read_table(path):
    """({rva: kind}, {rva: v2 verdict}) from the private function table."""
    kind, verdict = {}, {}
    with open(path) as handle:
        for line in handle:
            row = json.loads(line)
            kind[row['rva']] = row['kind']
            verdict[row['rva']] = (row.get('v2') or {}).get('verdict')
    return kind, verdict


def load(path):
    """{rva: record} of an index file, {} when absent or of another version."""
    path = Path(path)
    out = {}
    if not path.exists():
        return out
    with open(path) as handle:
        if json.loads(handle.readline()).get('version') != VERSION:
            return {}
        for line in handle:
            row = json.loads(line)
            out[row['rva']] = row
    return out


def save(path, rows):
    path = Path(path)
    tmp = path.with_suffix('.tmp')
    with open(tmp, 'w') as handle:
        handle.write(json.dumps({'version': VERSION}) + '\n')
        for rva in sorted(rows):
            handle.write(json.dumps(rows[rva], separators=(',', ':')) + '\n')
    tmp.replace(path)


def open_image(config, export):
    cfg = imagemodel.load_config(config)
    return imagemodel.open_image(cfg, str(export), with_names=False)


def build(config, export, table, out, jobs=2, full=False, log=print):
    """Extend (or with `full` rebuild) the index at `out`; returns {rva: record}."""
    global _IMAGE
    kinds, _ = read_table(table)
    have = {} if full else load(out)
    _IMAGE = open_image(config, export)
    todo = [i for i, (rva, _s, _n) in enumerate(_IMAGE.funcs) if kinds.get(rva) in KINDS and rva not in have]
    log('index: %d cached, %d to analyse' % (len(have), len(todo)))
    started = time.time()
    if todo:
        # each worker opens its own image so the pool also works where processes cannot fork (Windows)
        with mp.get_context('spawn').Pool(jobs, initializer=_init, initargs=(config, export)) as pool:
            for n, row in enumerate(pool.imap_unordered(_work, todo, chunksize=200), 1):
                have[row['rva']] = row
                if n % 20000 == 0:
                    log('  %d/%d (%.0f s)' % (n, len(todo), time.time() - started))
        save(out, have)
    errors = sum(1 for row in have.values() if 'error' in row)
    log('index: %d functions, %d decode errors' % (len(have), errors))
    return have


def operands_of(image, rvas):
    """{rva: [(offset, width, value, kind)]} with kind 'disp' or 'imm', in code order, for loose diffs."""
    out = {}
    for rva in rvas:
        i = image.index.get(rva)
        if i is None:
            continue
        result = image.analyse(i)
        if 'error' in result:
            continue
        body = result['_code']
        ops = []
        for off, ins in result['_insns']:
            for kind, part in (('disp', ins.disp), ('imm', ins.imm)):
                if part is not None:
                    a, n = off + part[0], part[1]
                    ops.append((a, n, int.from_bytes(body[a:a + n], 'little', signed=True), kind))
        out[rva] = ops
    return out


def diff(exemplar_ops, twin_ops):
    """[(position, exemplar value, twin value, kind, width)] of operands that differ, or None when the
    operand layouts differ (then the pair is not a loose twin)."""
    if len(exemplar_ops) != len(twin_ops):
        return None
    out = []
    for k, (a, b) in enumerate(zip(exemplar_ops, twin_ops)):
        if a[0] != b[0] or a[1] != b[1] or a[3] != b[3]:
            return None
        if a[2] != b[2]:
            out.append((k, a[2], b[2], a[3], a[1]))
    return out
