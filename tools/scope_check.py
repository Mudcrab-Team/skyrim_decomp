#!/usr/bin/env python3
"""Run the function PR scope job against a Git base and candidate commit."""
import argparse
import os
from pathlib import Path
import re
import subprocess
import sys

import giveup

TOOLS = Path(__file__).resolve().parent
OUTSIDE_RECONSTRUCTION = re.compile(
    r'docs/cookbook-notes/[0-9a-f]{3,8}-[a-z0-9][a-z0-9-]*\.md|'
    r'data/giveups/[a-z0-9][a-z0-9-]*/[0-9a-f]{3,8}\.json')
CHECKS = ('leakgrep', 'cookbook_notes', 'header_check', 'duplicate_rva', 'prereview')


def results(repo, base, head):
    """Yield the checks in CI order, stopping at the first failure."""
    raw = subprocess.run(['git', 'diff', '--no-renames', '--name-only', '-z', f'{base}...{head}', '--'],
                         cwd=repo, check=True, capture_output=True).stdout
    paths = os.fsdecode(raw).split('\0')
    outside = sum(not (name.startswith('reconstruction/') or OUTSIDE_RECONSTRUCTION.fullmatch(name)
                      or giveup.DRAFT_FILE.fullmatch(name))
                  for name in paths if name)
    if outside:
        # Paths are supplied by the PR. Only publish the count.
        yield 1, (f'scope: {outside} changed path(s) are outside reconstruction/, '
                  'docs/cookbook-notes/, data/giveups/ and drafts/\n')
        return
    for check in CHECKS:
        result = subprocess.run([sys.executable, str(TOOLS / f'{check}.py'), '--repo', str(repo),
                                 '--base', base, '--head', head], cwd=repo, capture_output=True,
                                encoding='utf-8', errors='replace')
        yield result.returncode, result.stdout + result.stderr or f'{check}: exit {result.returncode}\n'
        if result.returncode:
            return
    problems = giveup.git_pair_problems(repo, paths, head, base)
    for name, codes in problems:
        yield 1, f'{name}: {", ".join(codes)}\n'


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--repo', type=Path, default=TOOLS.parent)
    parser.add_argument('--base', required=True)
    parser.add_argument('--head', required=True)
    args = parser.parse_args(argv)
    for code, output in results(args.repo.resolve(), args.base, args.head):
        print(output, end='')
        if code:
            return code
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
