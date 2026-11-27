"""Find RVAs that more than one reconstruction unit names in its `// 0x<rva> <Name>` marker block.

A function's accepted record binds exactly one unit. A second unit that carries the same marker is
either a stale label or a second definition of the same function, and both mislead the unit index
and the review packets. Tooling only: it reads the tree and never compares game bytes.

    python3 tools/duplicate_rva.py            # print each duplicated RVA and its units
    python3 tools/duplicate_rva.py --count    # print only the number of duplicated RVAs
    python3 tools/duplicate_rva.py --base <sha> --head <sha>   # pr-check: RVAs a PR newly repeats
    python3 tools/duplicate_rva.py --against-main <rev> --head <sha>   # merge time: RVAs main gained meanwhile

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


def marked(root=ROOT):
    """{rva: [unit path, ...]} for every RVA that any reconstruction unit marks, duplicated or not."""
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
    return {rva: sorted(units) for rva, units in sorted(seen.items())}


def duplicates(root=ROOT):
    """{rva: [unit path, ...]} for every RVA marked in more than one distinct .cpp file."""
    return {rva: units for rva, units in marked(root).items() if len(units) > 1}


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


def git_lines(root, *args):
    out = subprocess.run(['git', *args], cwd=root, capture_output=True, check=False)
    if out.returncode:
        raise SystemExit(f'duplicate_rva: git {args[0]} failed')
    return out.stdout.decode('utf-8', 'replace').splitlines()


def against_main(root, main, head, *, incoming_only=False):
    """{rva: units} for RVAs a PR head marks in a unit while a different unit on `main` marks it too.

    A PR is checked against the base it was opened on. When another PR lands on main afterwards, the
    two can repeat an RVA although neither check saw the other, so the bot asks this at merge time.
    Units the PR deletes no longer count on main's side. With incoming_only, return only the paths
    that the PR introduces for each colliding RVA, leaving main's copies out of the result.
    """
    base = git_lines(root, 'merge-base', main, head)[0]
    paths = ('--', 'reconstruction/*.cpp')
    added = set(git_lines(root, 'diff', '--no-renames', '--name-only', '--diff-filter=AM', base, head, *paths))
    gone = set(git_lines(root, 'diff', '--no-renames', '--name-only', '--diff-filter=D', base, head, *paths))
    on_main = revision_markers(root, main)
    found = {}
    for rva, units in revision_markers(root, head).items():
        mine = {u for u in units if u in added and u not in on_main.get(rva, ())}
        others = set(on_main.get(rva, ())) - gone - mine
        if mine and others:
            found[rva] = sorted(mine if incoming_only else mine | others)
    return dict(sorted(found.items()))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--repo', type=Path, default=ROOT)
    parser.add_argument('--count', action='store_true')
    parser.add_argument('--base')
    parser.add_argument('--head')
    parser.add_argument('--against-main', metavar='MAIN', help='with --head: RVAs the head repeats from main')
    args = parser.parse_args(argv)
    if args.against_main:
        if not args.head:
            parser.error('--against-main needs --head')
        clash = against_main(args.repo, args.against_main, args.head)
        for rva, units in list(clash.items())[:20]:
            print(f'0x{rva:x} is also marked in {len(units) - 1} unit(s) on main')
        print(f'duplicate_rva: {"FAIL" if clash else "PASS"} ({len(clash)} RVA(s) repeated from main)')
        return 1 if clash else 0
    if args.base or args.head:
        if not (args.base and args.head):
            parser.error('--base and --head go together')
        added = new_duplicates(args.repo, args.base, args.head)
        for rva, units in list(added.items())[:20]:
            print(f'0x{rva:x} is now marked in {len(units)} units')
        print(f'duplicate_rva: {"FAIL" if added else "PASS"} ({len(added)} newly duplicated RVA(s))')
        return 1 if added else 0
    found = duplicates(args.repo)
    if args.count:
        print(len(found))
        return 0
    for rva, units in found.items():
        print(f'0x{rva:x}: ' + ', '.join(units))
    print(f'{len(found)} duplicated RVAs', file=sys.stderr)
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main())
