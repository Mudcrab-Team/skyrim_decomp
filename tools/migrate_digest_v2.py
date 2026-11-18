#!/usr/bin/env python3
"""Move match records whose v1 digest still matches the tree to the v2 digest (tools/digest_v2.py).

    python3 tools/migrate_digest_v2.py [--apply] [reports/<build>/0x*.json ...]

For every record with `digest_method: tu-sha256-v1` whose digest equals the v1 digest of its listed
translation unit as the tree holds it now, the record's `digest` becomes the v2 digest of that same
tree and the v1 digest is kept as `run_digest` (digest_v2.run_revision): the comparator runs embed
it as their source revision. A record whose v1 digest is already stale is left as it is and listed,
so a migration can never turn an old mismatch into a pass. Review records are not rewritten: a
review of the v1 digest binds the migrated record through `run_digest` (digest_v2.review_binds).
Without --apply nothing is written.
"""
import argparse
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from digest_v2 import DIGEST_METHOD, tu_digest  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def migrate(root, path):
    """(outcome, new text or None) for one record file."""
    raw = Path(path).read_text(encoding='utf-8')
    record = json.loads(raw)
    source = record.get('source')
    if not isinstance(source, dict) or source.get('digest_method') != 'tu-sha256-v1':
        return 'not-v1', None
    unit = source.get('translation_unit')
    try:
        old = tu_digest(root, unit, 'tu-sha256-v1')
        new = tu_digest(root, unit, DIGEST_METHOD)
    except (OSError, ValueError, TypeError):
        return 'unit-unreadable', None
    if old != source.get('digest'):
        return 'v1-stale', None
    # Edited in the text so a record's own formatting and key order are untouched.
    before = ('\n    "digest": "%s",\n    "digest_method": "tu-sha256-v1",\n' % old)
    after = ('\n    "digest": "%s",\n    "digest_method": "%s",\n    "run_digest": "%s",\n'
             '    "run_digest_method": "tu-sha256-v1",\n' % (new, DIGEST_METHOD, old))
    if raw.count(before) != 1:
        return 'source-block-unrecognised', None
    text = raw.replace(before, after)
    expected = json.loads(raw)
    expected['source'].update(digest=new, digest_method=DIGEST_METHOD, run_digest=old, run_digest_method='tu-sha256-v1')
    if json.loads(text) != expected:
        return 'source-block-unrecognised', None
    return 'migrated', text


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--apply', action='store_true')
    p.add_argument('--root', type=Path, default=ROOT)
    p.add_argument('records', nargs='*')
    a = p.parse_args(argv)
    root = a.root
    names = a.records or sorted(
        str(q.relative_to(root)) for q in (root / 'reports').glob('*/0x*.json') if not q.name.endswith('.review.json'))
    counts, stale = {}, []
    for name in names:
        outcome, text = migrate(root, root / name)
        counts[outcome] = counts.get(outcome, 0) + 1
        if outcome in ('v1-stale', 'unit-unreadable', 'source-block-unrecognised'):
            stale.append(f'{name} {outcome}')
        if text is not None and a.apply:
            (root / name).write_text(text, encoding='utf-8')
    for line in stale:
        print(line)
    print(json.dumps(counts, sort_keys=True), 'applied' if a.apply else 'dry run')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
