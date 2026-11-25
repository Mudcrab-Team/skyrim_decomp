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

from claimable import sharded_json, write_sharded

SCHEMA = 1
QUEUE_PATH = 'data/ready-queue.json'
ROWS_PER_PART = 4000
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


def build(rows, progress, limit=None):
    matched = {f['rva'] for f in progress['functions'] if f['status'] == 'matched'}
    entries, counts = rank(rows, matched)
    listed = entries[:limit]
    return {'schema_version': SCHEMA, 'build_id': progress['target_build_id'],
            'progress_updated_at': progress.get('updated_at'),
            'derivation': 'local function table call graph against matched functions in data/progress.json; '
                          'advisory ordering only, not evidence of a match',
            'order': 'unlock_rank first (unlock per size + 32 bytes, best first), then size bucket '
                     '(<16, <64, <256, <1024, larger), blocks descending, size, rva',
            'counts': dict(counts, listed=len(listed)),
            'entries': [{'rva': f'0x{e["rva"]:x}', **{k: v for k, v in e.items() if k != 'rva'}}
                        for e in listed]}


def load_rows(path):
    with open(path) as fh:
        return [json.loads(line) for line in fh if line.strip()]


def read_queue(repo, build_id):
    """Read the published queue for this build, including all its parts."""
    try:
        queue = sharded_json(repo, QUEUE_PATH, 'entries')
        listed = queue.get('counts', {}).get('listed', len(queue['entries']))
        if queue.get('build_id') == build_id and listed == len(queue['entries']):
            return queue
    except (OSError, ValueError, KeyError, TypeError, AttributeError):
        pass
    return {}


def load_queue(repo):
    """The published queue as {rva int: entry}, or {} when unavailable."""
    try:
        progress = json.loads((Path(repo) / 'data/progress.json').read_text())
        queue = read_queue(repo, progress.get('target_build_id'))
        return {int(e['rva'], 16): e for e in queue.get('entries', [])}
    except (OSError, ValueError, KeyError, TypeError, AttributeError):
        return {}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument('--function-table', required=True, help='private functions.jsonl from your own pinned image')
    ap.add_argument('--repo', default=str(Path(__file__).resolve().parent.parent))
    ap.add_argument('--limit', type=int, help='truncate an export made with --out')
    ap.add_argument('--out', type=Path, help=f'output path (default <repo>/{QUEUE_PATH})')
    args = ap.parse_args(argv)
    published = Path(args.repo) / QUEUE_PATH
    publishing = args.out is None or args.out.resolve() == published.resolve()
    if args.limit is not None and (publishing or args.limit < 0):
        ap.error('--limit requires a separate --out path and a nonnegative count')
    progress = json.loads((Path(args.repo) / 'data/progress.json').read_text())
    doc = build(load_rows(args.function_table), progress, args.limit)
    if publishing:
        write_sharded(args.repo, QUEUE_PATH, doc, 'entries', ROWS_PER_PART)
    else:
        args.out.write_text(json.dumps(doc, separators=(',', ':')) + '\n')
    print(json.dumps(doc['counts']))
    return 0


if __name__ == '__main__':
    sys.exit(main())
