#!/usr/bin/env python3
"""Deterministic gate for a mapping-only PR: new `mapped` entries in data/progress.json, nothing else.

    python3 tools/mapping_check.py --shape --base SHA --head SHA     print mapping=true|false
    python3 tools/mapping_check.py --base SHA --head SHA [--main REF]  exit 0 ok, 1 refused

A mapping PR may change `data/progress.json` and add `findings/*.md`. It may only append entries
with status `mapped`; it can never move a match count. Output is fixed reason codes and counts:
a PR's content is attacker-controlled, so none of it is echoed.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
PROGRESS = 'data/progress.json'
FINDING = re.compile(r'findings/[^/]+\.md')
ENTRY_KEYS = frozenset(('build_id', 'evidence', 'id', 'name', 'name_origin', 'name_source', 'owner', 'rva',
                        'size', 'status'))
NAME_ORIGINS = frozenset(('EXE_RTTI', 'COMMUNITY', 'CRASHLOGGER_PDB', 'SYMBOLS', 'OBSERVED', 'GUESS'))
CODES = {
    'shape': 'the PR must change data/progress.json and may only add new findings/*.md besides',
    'json': 'data/progress.json is not valid JSON in the canonical layout',
    'top-level': 'something other than the `functions` list changed',
    'removed': 'an existing entry was removed',
    'modified': 'an existing entry was modified or moved',
    'duplicate-rva': 'an added entry repeats an RVA that is already present',
    'overlap': 'an added entry overlaps another function range',
    'status': 'added entries must have status `mapped`',
    'forbidden-field': 'added entries must not carry `report` or `matched` fields',
    'schema': 'an added entry does not follow the entry schema',
    'guess-label': 'a GUESS name needs a `GUESS(` label in name_source',
    'evidence': 'an evidence file is missing or is not a findings/*.md file',
    'leak': 'the publication scan flagged the diff',
    'empty': 'the PR adds no entries',
}


def shape(changes):
    """True if [(status, path)] is progress.json modified, plus only added findings/*.md files."""
    paths = {path: status for status, path in changes}
    if len(paths) != len(changes) or paths.get(PROGRESS) != 'M':
        return False
    return all(path == PROGRESS or (status == 'A' and FINDING.fullmatch(path)) for path, status in paths.items())


def _int(value):
    return isinstance(value, int) and not isinstance(value, bool)


def _text(value):
    return isinstance(value, str) and bool(value.strip())


def problems(base, head, target_build, evidence_exists, main=None):
    """Sorted reason codes for the change from `base` to `head` (parsed progress.json documents).

    `main` is the current tip's document when it differs from `base`; an RVA added there since the
    PR was cut would otherwise merge cleanly into a duplicate.
    """
    found = set()
    if {k: v for k, v in base.items() if k != 'functions'} != {k: v for k, v in head.items() if k != 'functions'}:
        found.add('top-level')
    old, new = base['functions'], head['functions']
    by_rva = {fn['rva']: fn for fn in old}
    head_by_rva = {}
    for fn in new:
        head_by_rva.setdefault(fn['rva'], fn)
    if any(rva not in head_by_rva for rva in by_rva):
        found.add('removed')
    if any(head_by_rva.get(rva) != fn for rva, fn in by_rva.items() if rva in head_by_rva):
        found.add('modified')
    kept = [fn for fn in new if fn['rva'] in by_rva]
    if len(kept) > len(old):
        found.add('duplicate-rva')
    elif not found and kept != old:
        found.add('modified')  # same entries in a different order
    added = [fn for fn in new if fn['rva'] not in by_rva]
    if not added:
        found.add('empty')
    sizes = {fn['rva']: fn.get('size') for fn in old}
    sizes.update({fn['rva']: fn.get('size') for fn in (main or base)['functions']})
    known = set(sizes)
    ranges = [(rva, rva + size) for rva, size in sizes.items() if _int(size)]
    seen = set()
    for fn in added:
        if not isinstance(fn, dict):
            found.add('schema')
            continue
        if fn.get('status') != 'mapped':
            found.add('status')
        if {'report', 'matched'} & set(fn):
            found.add('forbidden-field')
        rva, size = fn.get('rva'), fn.get('size')
        text_ok = all(_text(fn.get(k)) for k in ('id', 'name', 'owner', 'name_source', 'evidence', 'build_id'))
        if (set(fn) - {'report', 'matched'} != ENTRY_KEYS or not text_ok or not _int(rva) or not _int(size)
                or rva < 0 or size <= 0 or fn.get('name_origin') not in NAME_ORIGINS
                or fn.get('build_id') != target_build or fn.get('id') != f'{target_build}-0x{rva:x}'):
            found.add('schema')
            continue
        if rva in known or rva in seen:
            found.add('duplicate-rva')
            continue
        seen.add(rva)
        if fn['name_origin'] == 'GUESS' and 'GUESS(' not in fn['name_source']:
            found.add('guess-label')
        elif fn['name_origin'] != 'GUESS' and re.search(r'\bGUESS\b', fn['name_source']) and 'GUESS(' not in fn['name_source']:
            found.add('guess-label')
        if not FINDING.fullmatch(fn['evidence']) or not evidence_exists(fn['evidence']):
            found.add('evidence')
        ranges.append((rva, rva + size))
    ordered = sorted(ranges)
    if any(a[1] > b[0] for a, b in zip(ordered, ordered[1:])):
        found.add('overlap')
    return sorted(found)


def git(repo, *args, check=True):
    return subprocess.run(['git', '-C', str(repo), *args], capture_output=True, check=check)


def changes(repo, base, head):
    out = git(repo, 'diff', '--no-renames', '--name-status', '-z', f'{base}...{head}').stdout.decode(errors='replace')
    parts = out.split('\0')
    return [(parts[i][:1], parts[i + 1]) for i in range(0, len(parts) - 1, 2)]


def load(repo, ref):
    """(document, canonical?) of data/progress.json at ref; (None, False) when it does not parse."""
    text = git(repo, 'show', f'{ref}:{PROGRESS}').stdout.decode()
    try:
        doc = json.loads(text)
        ok = isinstance(doc, dict) and isinstance(doc.get('functions'), list) and all(
            isinstance(f, dict) and isinstance(f.get('rva'), int) for f in doc['functions'])
    except ValueError:
        return None, False
    return (doc if ok else None), ok and text == json.dumps(doc, indent=2, ensure_ascii=False) + '\n'


def run_leakgrep(repo, base, head):
    script = Path(__file__).resolve().parent / 'leakgrep.py'
    private = Path(repo) / '.local/leakgrep-private.txt'
    argv = [sys.executable, str(script), '--base', base, '--head', head, '--repo', str(repo)]
    if private.is_file():
        argv += ['--private-list', str(private)]
    result = subprocess.run(argv, capture_output=True, timeout=300)
    if result.returncode not in (0, 1) or b'leakgrep: ' not in result.stdout:
        raise RuntimeError('leakgrep did not complete')
    return result.returncode == 0


def check(repo, base, head, main=None, scan=True):
    """Reason codes (empty list: valid)."""
    if not shape(changes(repo, base, head)):
        return ['shape']
    old, _ = load(repo, base)
    new, canonical = load(repo, head)
    if old is None or new is None or not canonical:
        return ['json']
    current = load(repo, main)[0] if main else None
    if main and current is None:
        return ['json']
    target = json.loads(git(repo, 'show', f'{base}:builds/target.json').stdout)['build_id']

    def exists(path):
        return git(repo, 'cat-file', '-e', f'{head}:{path}', check=False).returncode == 0

    found = problems(old, new, target, exists, current)
    if scan and not run_leakgrep(repo, base, head):
        found.append('leak')
    return found


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--base', required=True)
    p.add_argument('--head', required=True)
    p.add_argument('--main', help='current tip to check for RVAs added since the PR was cut')
    p.add_argument('--repo', type=Path, default=ROOT)
    p.add_argument('--shape', action='store_true')
    a = p.parse_args(argv)
    if a.shape:
        print('mapping=' + ('true' if shape(changes(a.repo, a.base, a.head)) else 'false'))
        return 0
    found = check(a.repo, a.base, a.head, a.main)
    if found:
        print('mapping: refused: ' + ', '.join(found))
        for code in found:
            print(f'  {code}: {CODES[code]}')
        return 1
    print('mapping: ok')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
