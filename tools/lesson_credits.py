#!/usr/bin/env python3
"""List who wrote the lesson notes that landed, from the repository's own history.

    python3 tools/lesson_credits.py            one line per contributor: notes landed, most first
    python3 tools/lesson_credits.py --json     the same as JSON

A note is a file added under docs/cookbook-notes/ in a commit on the current branch. The author credited is the
`Co-authored-by` trailer's GitHub login (the bot's squash message names the PR author there); a commit without one
is credited to nobody, so nothing here is invented. Notes are deleted once folded into the cookbook, so history
is the only complete record. It prints counts and logins, never note text.
"""
import argparse
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

import cookbook_notes

ROOT = Path(__file__).resolve().parents[1]
RECORD = '\x1e'
FIELD = '\x1f'
TRAILER = re.compile(r'^Co-authored-by: .*<(?:\d+\+)?([A-Za-z0-9](?:[A-Za-z0-9-]{0,37}[A-Za-z0-9])?)@users\.noreply\.github\.com>\s*$',
                     re.MULTILINE | re.IGNORECASE)


def parse(log):
    """{login: [note paths]} from `git log --name-only` text in the format `credits` asks for."""
    found = collections.defaultdict(list)
    for record in log.split(RECORD):
        if FIELD not in record:
            continue
        body, _sep, names = record.partition(FIELD)[2].partition(FIELD)
        notes = [n.strip() for n in names.splitlines() if cookbook_notes.NOTE_FILE.fullmatch(n.strip())]
        logins = list(dict.fromkeys(m.group(1).lower() for m in TRAILER.finditer(body)))
        for login in logins:
            found[login] += notes
    return {login: list(dict.fromkeys(paths)) for login, paths in found.items() if paths}


def credits(repo):
    log = subprocess.run(['git', 'log', '--diff-filter=A', '--name-only', f'--format={RECORD}%H{FIELD}%b{FIELD}',
                          '--', cookbook_notes.NOTES_DIR], cwd=repo, check=True, capture_output=True,
                         text=True).stdout
    return parse(log)


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    p.add_argument('--repo', type=Path, default=ROOT)
    p.add_argument('--json', action='store_true')
    a = p.parse_args(argv)
    rows = sorted(((login, len(paths)) for login, paths in credits(a.repo).items()), key=lambda r: (-r[1], r[0]))
    if a.json:
        print(json.dumps([dict(contributor='@' + login, notes=count) for login, count in rows], indent=2))
    else:
        for login, count in rows:
            print(f'@{login}: {count} lesson note{"s" if count != 1 else ""}')
        if not rows:
            print('no lesson note with a credited author has landed yet')
    return 0


if __name__ == '__main__':
    sys.exit(main())
