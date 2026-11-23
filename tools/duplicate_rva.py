"""Find RVAs that more than one reconstruction unit names in its `// 0x<rva> <Name>` marker block.

A function's accepted record binds exactly one unit. A second unit that carries the same marker is
either a stale label or a second definition of the same function, and both mislead the unit index
and the review packets. Tooling only: it reads the tree and never compares game bytes.

    python3 tools/duplicate_rva.py            # print each duplicated RVA and its units
    python3 tools/duplicate_rva.py --count    # print only the number of duplicated RVAs
    python3 tools/duplicate_rva.py --base <sha> --head <sha>   # pr-check: RVAs a PR newly repeats

A reconstruction-only PR skips the infrastructure tests, so the tree-wide ceiling would only trip on
main after the merge. The base/head mode reads both revisions through git and fails when the PR makes
any RVA live in more units than it did at base.
"""
import argparse
import collections
import os
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
MARKER = re.compile(r'^// 0x([0-9a-fA-F]+) ', re.M)
# Generated declarations are not reconstructed units (docs/code-rules.md).
SKIPPED = ('generated',)


def duplicates(root=ROOT):
    """{rva: [unit path, ...]} for every RVA marked in more than one distinct .cpp file."""
    root = Path(root)
    seen = collections.defaultdict(set)
    base = root / 'reconstruction'
    for folder, dirs, files in os.walk(base):
        dirs[:] = [d for d in dirs if d not in SKIPPED]
        for name in files:
            if not name.endswith('.cpp'):
                continue
            path = Path(folder) / name
            text = path.read_text(encoding='utf-8', errors='replace')
            for m in MARKER.finditer(text):
                seen[int(m.group(1), 16)].add(path.relative_to(root).as_posix())
    return {rva: sorted(units) for rva, units in sorted(seen.items()) if len(units) > 1}


def revision_markers(root, rev):
    """{rva: {unit path}} for the markers of every .cpp unit at one revision, read with git only."""
    out = subprocess.run(
        ['git', 'grep', '-I', '-E', '--no-color', '-e', r'^// 0x[0-9a-fA-F]+ ', rev, '--', 'reconstruction/*.cpp'],
        cwd=root, capture_output=True, check=False)
    if out.returncode not in (0, 1):
        raise SystemExit(f'duplicate_rva: git grep failed at {rev[:12]}')
    seen = collections.defaultdict(set)
    for line in out.stdout.decode('utf-8', 'replace').splitlines():
        path, _, text = line[len(rev) + 1:].partition(':')
        parts = path.split('/')
        if len(parts) > 1 and parts[1] in SKIPPED:
            continue
        m = MARKER.match(text)
        if m:
            seen[int(m.group(1), 16)].add(path)
    return seen


def new_duplicates(root, base, head):
    """{rva: units} for RVAs that head spreads over more units than base did, more than one in all."""
    before = revision_markers(root, base)
    after = revision_markers(root, head)
    return {rva: sorted(units) for rva, units in sorted(after.items())
            if len(units) > 1 and len(units) > len(before.get(rva, ()))}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--count', action='store_true')
    parser.add_argument('--base')
    parser.add_argument('--head')
    args = parser.parse_args(argv)
    if args.base or args.head:
        if not (args.base and args.head):
            parser.error('--base and --head go together')
        added = new_duplicates(ROOT, args.base, args.head)
        for rva, units in list(added.items())[:20]:
            print(f'0x{rva:x} is now marked in {len(units)} units')
        print(f'duplicate_rva: {"FAIL" if added else "PASS"} ({len(added)} newly duplicated RVA(s))')
        return 1 if added else 0
    found = duplicates()
    if args.count:
        print(len(found))
        return 0
    for rva, units in found.items():
        print(f'0x{rva:x}: ' + ', '.join(units))
    print(f'{len(found)} duplicated RVAs', file=sys.stderr)
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main())
