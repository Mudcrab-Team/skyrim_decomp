#!/usr/bin/env python3
"""List who wrote the lesson notes, family notes and generators that landed, from the repository's own history.

    python3 tools/lesson_credits.py            one line per contributor: what they landed, most first
    python3 tools/lesson_credits.py --json     the same as JSON

A lesson note is a file added under docs/cookbook-notes/ in a commit on the current branch. A family note is a
file added under findings/ the same way, or one the generator index (docs/generators.md) links from a credited row.
The author credited is the `Co-authored-by` trailer's GitHub login (the bot's squash message names the PR author
there); a commit without one is credited to nobody, so nothing here is invented. Generator authors are the logins
in the Credit column of docs/generators.md, one count per tools/*_generate*.py row. Notes are deleted once folded
into the cookbook, so history is the only complete record. It prints counts and logins, never note text.
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


ROW = re.compile(r'^\|\s*`(tools/[A-Za-z0-9_/]*_generate[A-Za-z0-9_]*\.py)`.*\|\s*@([A-Za-z0-9-]+)\s*\|(.*)\|\s*$')
FINDING_LINK = re.compile(r'\]\(\.\./(findings/[a-z0-9][a-z0-9-]*\.md)\)')
FINDINGS_DIR = 'findings/'
INDEX = 'docs/generators.md'


def parse(log, wanted=None):
    """{login: [paths]} from `git log --name-only` text in the format `credits` asks for.

    `wanted` says which added paths count; the default is a lesson note."""
    wanted = wanted or cookbook_notes.NOTE_FILE.fullmatch
    found = collections.defaultdict(list)
    for record in log.split(RECORD):
        if FIELD not in record:
            continue
        body, _sep, names = record.partition(FIELD)[2].partition(FIELD)
        notes = [n.strip() for n in names.splitlines() if wanted(n.strip())]
        logins = list(dict.fromkeys(m.group(1).lower() for m in TRAILER.finditer(body)))
        for login in logins:
            found[login] += notes
    return {login: list(dict.fromkeys(paths)) for login, paths in found.items() if paths}


def added(repo, directory):
    return subprocess.run(['git', 'log', '--diff-filter=A', '--name-only', f'--format={RECORD}%H{FIELD}%b{FIELD}',
                           '--', directory], cwd=repo, check=True, capture_output=True, text=True).stdout


def credits(repo):
    return parse(added(repo, cookbook_notes.NOTES_DIR))


def index_rows(text):
    """[(generator path, login, [findings paths])] from the rows of the generator index."""
    rows = []
    for line in text.splitlines():
        m = ROW.match(line)
        if m:
            rows.append((m.group(1), m.group(2).lower(), FINDING_LINK.findall(m.group(3))))
    return rows


def family_credits(repo):
    """({login: [family note paths]}, {login: [generator paths]}).

    Family notes are findings added in a commit with a credited co-author, plus the findings the generator
    index links from a row, credited to that row's login. Generators come from the index alone."""
    notes = parse(added(repo, FINDINGS_DIR), lambda n: n.startswith(FINDINGS_DIR) and n.endswith('.md'))
    generators = collections.defaultdict(list)
    try:
        rows = index_rows((Path(repo) / INDEX).read_text())
    except OSError:
        rows = []
    for path, login, findings in rows:
        generators[login].append(path)
        notes.setdefault(login, [])
        notes[login] += findings
    return ({login: list(dict.fromkeys(paths)) for login, paths in notes.items() if paths},
            {login: list(dict.fromkeys(paths)) for login, paths in generators.items()})


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    p.add_argument('--repo', type=Path, default=ROOT)
    p.add_argument('--json', action='store_true')
    a = p.parse_args(argv)
    notes = credits(a.repo)
    families, generators = family_credits(a.repo)
    table = {login: (len(notes.get(login, ())), len(families.get(login, ())), len(generators.get(login, ())))
             for login in {*notes, *families, *generators}}
    rows = sorted(table.items(), key=lambda r: (-sum(r[1]), r[0]))
    if a.json:
        print(json.dumps([dict(contributor='@' + login, notes=n, family_notes=f, generators=g)
                          for login, (n, f, g) in rows], indent=2))
    else:
        for login, (n, f, g) in rows:
            parts = [f'{n} lesson note{"s" if n != 1 else ""}'] if n or not (f or g) else []
            parts += [f'{f} family note{"s" if f != 1 else ""}'] if f else []
            parts += [f'{g} generator{"s" if g != 1 else ""}'] if g else []
            print(f'@{login}: ' + ', '.join(parts))
        if not rows:
            print('nothing with a credited author has landed yet')
    return 0


if __name__ == '__main__':
    sys.exit(main())
