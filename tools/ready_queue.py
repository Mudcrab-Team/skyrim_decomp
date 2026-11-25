"""Rank unmatched functions by how ready they are to be drafted, callee-first.

A function is ready when every function it calls or tail-calls is already matched. Such a
function compiles against real declarations of its callees, so a drafter needs no stand-in
symbols for them. Calls through import thunks are left out of the callee sets, since an import
stub is never matched. The functions that unblock the most callers per byte come first
(`unlock_rank`, see `rank`); the rest are ordered by size bucket (small first) and, inside a
bucket, by how many other unmatched functions call them (more first), so each match also moves
callers toward ready. The queue is advisory: it never claims, locks or accepts anything.

Input is the private function table derived locally from the pinned image plus the public
data/progress.json. Only RVAs, sizes and counts are written. Nothing here is evidence of a match.
"""
import argparse
import json
from pathlib import Path
import sys

SCHEMA = 1
DEFAULT_LIMIT = 5000
QUEUE_PATH = 'data/ready-queue.json'
# Upper bounds (exclusive) of the size buckets; a function above the last bound is its own bucket.
BUCKETS = (16, 64, 256, 1024)
# Unlock order: callers a function unblocks (each caller's credit split across its missing callees)
# per byte of the function plus a fixed per-function cost. Measured on the ready set, this order
# makes several times more callers ready than the size-bucket order for the same bytes drafted.
UNLOCK_TOP = 500
UNLOCK_MIN = 2.0
UNLOCK_COST = 32


def bucket(size):
    for i, bound in enumerate(BUCKETS):
        if size < bound:
            return i
    return len(BUCKETS)


def callee_set(row):
    return set(row.get('callees') or []) | set(row.get('tail_callees') or [])


def rank(rows, matched):
    """Return (ready entries in order, counts) from function-table rows and the matched RVA set.

    Only ordinary functions the local classifier has not marked unsupported are queued; other
    kinds have their own generators. A callee that is not matched, whatever its kind, keeps its
    caller out of the ready set, except an import thunk, which is never matched and is left out.

    Each entry has `blocks` (unmatched callers), `unlocks` (callers whose last missing callee it
    is) and `unlock`, the sum over supported callers of 1 / (their missing callees). The
    `UNLOCK_TOP` entries with `unlock` of at least `UNLOCK_MIN`, by `unlock` per (size + UNLOCK_COST)
    descending, come first and carry `unlock_rank` (1 is best); the rest follow in size-bucket order.
    """
    kinds = {r['rva']: r.get('kind') for r in rows}
    open_rows = [r for r in rows if r.get('kind') == 'ordinary' and r['rva'] not in matched]
    open_rva = {r['rva'] for r in open_rows}
    pending = {r['rva']: {c for c in callee_set(r) - matched if c != r['rva'] and kinds.get(c) != 'import-thunk'}
               for r in open_rows}
    blocks, unlocks, share = {}, {}, {}
    for r in open_rows:
        caller, missing = r['rva'], pending[r['rva']]
        supported = (r.get('v2') or {}).get('verdict') != 'unsupported'
        for callee in missing:
            blocks[callee] = blocks.get(callee, 0) + 1
            if len(missing) == 1:
                unlocks[callee] = unlocks.get(callee, 0) + 1
            if supported:
                share[callee] = share.get(callee, 0) + 1 / len(missing)
    entries = []
    for r in open_rows:
        if pending[r['rva']] or (r.get('v2') or {}).get('verdict') == 'unsupported':
            continue
        entries.append({'rva': r['rva'], 'size': r['size'], 'blocks': blocks.get(r['rva'], 0),
                        'unlocks': unlocks.get(r['rva'], 0), 'unlock': round(share.get(r['rva'], 0), 2)})
    entries.sort(key=lambda e: (bucket(e['size']), -e['blocks'], e['size'], e['rva']))
    ranked = sorted((e for e in entries if e['unlock'] >= UNLOCK_MIN),
                    key=lambda e: (-e['unlock'] / (e['size'] + UNLOCK_COST), -e['blocks'], e['size'], e['rva']))[:UNLOCK_TOP]
    for position, e in enumerate(ranked, 1):
        e['unlock_rank'] = position
    entries = ranked + [e for e in entries if 'unlock_rank' not in e]
    counts = {'unmatched_ordinary': len(open_rows), 'ready': len(entries),
              'blocking_unmatched_ordinary': sum(1 for rva in blocks if rva in open_rva)}
    return entries, counts


def build(rows, progress, limit=DEFAULT_LIMIT):
    matched = {f['rva'] for f in progress['functions'] if f['status'] == 'matched'}
    entries, counts = rank(rows, matched)
    return {'schema_version': SCHEMA, 'build_id': progress['target_build_id'],
            'progress_updated_at': progress.get('updated_at'),
            'derivation': 'local function table call graph against matched functions in data/progress.json; '
                          'advisory ordering only, not evidence of a match',
            'order': 'unlock_rank first (unlock per size + 32 bytes, best first), then size bucket '
                     '(<16, <64, <256, <1024, larger), blocks descending, size, rva',
            'counts': dict(counts, listed=min(limit, len(entries))),
            'entries': [{'rva': f'0x{e["rva"]:x}', **{k: v for k, v in e.items() if k != 'rva'}}
                        for e in entries[:limit]]}


def load_rows(path):
    with open(path) as fh:
        return [json.loads(line) for line in fh if line.strip()]


def load_queue(repo):
    """The published queue as {rva int: entry}, or {} when absent or for another build."""
    path = Path(repo) / QUEUE_PATH
    try:
        queue = json.loads(path.read_text())
        progress = json.loads((Path(repo) / 'data/progress.json').read_text())
    except (OSError, ValueError):
        return {}
    if queue.get('build_id') != progress.get('target_build_id'):
        return {}
    return {int(e['rva'], 16): e for e in queue.get('entries', [])}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument('--function-table', required=True, help='private functions.jsonl from your own pinned image')
    ap.add_argument('--repo', default=str(Path(__file__).resolve().parent.parent))
    ap.add_argument('--limit', type=int, default=DEFAULT_LIMIT)
    ap.add_argument('--out', help=f'output path (default <repo>/{QUEUE_PATH})')
    args = ap.parse_args(argv)
    progress = json.loads((Path(args.repo) / 'data/progress.json').read_text())
    doc = build(load_rows(args.function_table), progress, args.limit)
    out = Path(args.out or Path(args.repo) / QUEUE_PATH)
    out.write_text(json.dumps(doc, separators=(',', ':')) + '\n')
    print(json.dumps(doc['counts']))
    return 0


if __name__ == '__main__':
    sys.exit(main())
