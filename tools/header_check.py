#!/usr/bin/env python3
"""Compact-header rule for the units a pull request adds or changes (pr-check `scope` job).

    python3 tools/header_check.py --base <sha> --head <sha>

A unit file whose leading comment is the same at head as at base is skipped, so a PR that does not
touch a header is never held to the rule, however old that header is. Every other .h/.cpp under
reconstruction/ must pass `lint_reconstruction.header_budget_problems`: no licence text, the one
SPDX line for CommonLibSSE-NG declarations, and a short header. Paths come from the PR, so only
names made of safe characters are printed.
"""
import argparse
from pathlib import Path
import re
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from lint_reconstruction import header_budget_problems, leading_comment  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
SAFE = re.compile(r'reconstruction/[A-Za-z0-9_./+-]+')


def git(root, *args):
    return subprocess.run(['git', *args], cwd=root, capture_output=True, check=True).stdout


def changed_units(root, base, head):
    out = git(root, 'diff', '--no-renames', '--name-only', '--diff-filter=AM', '-z', f'{base}...{head}', '--')
    return [n for n in out.decode('utf-8', 'replace').split('\0') if n.endswith(('.h', '.cpp')) and n.startswith('reconstruction/')]


def blob(root, rev, name):
    try:
        return git(root, 'show', f'{rev}:{name}').decode('utf-8', 'replace')
    except subprocess.CalledProcessError:
        return None


def file_problems(name, new, old):
    if new is None:
        return []
    header = leading_comment(new)
    old_header = leading_comment(old) if old is not None else None
    if header == old_header:
        return []
    shown = name if SAFE.fullmatch(name) else 'reconstruction/<unprintable path>'
    return header_budget_problems(shown, header, old_header)


def check(root, base, head):
    return [problem for name in changed_units(root, base, head)
            for problem in file_problems(name, blob(root, head, name), blob(root, base, name))]


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--base', required=True)
    p.add_argument('--head', required=True)
    p.add_argument('--repo', type=Path, default=ROOT)
    a = p.parse_args(argv)
    problems = check(a.repo, a.base, a.head)
    for line in problems[:20]:
        print(line)
    if len(problems) > 20:
        print(f'... and {len(problems) - 20} more')
    print(f'header_check: {"FAIL" if problems else "PASS"} ({len(problems)} problem(s))')
    return int(bool(problems))


if __name__ == '__main__':
    raise SystemExit(main())
