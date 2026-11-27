"""Local-only guard: a unit must not repeat SDK-derived or Gamebryo text of the fo4-private clone verbatim.

The Gamebryo folder and SDK-installed material may be read as a study reference, but units are
rewritten. A unit is flagged when a run of more than RUN consecutive normalized lines (whitespace
collapsed, blank and brace-only lines dropped) equals a run in a file under src/Gamebryo or in an
allowed game-code file that includes SDK headers. The clone is read from .local/sources/fo4-private
at the approved revision. The check is skipped when the clone is absent, at another revision, or
when CI is set, and no clone text is ever written anywhere; findings carry line numbers only.
"""
import hashlib
import os
from pathlib import Path
import re
import subprocess

from fo4_private import REVISION, SOURCE, allowed_path
from local_paths import local_dir

RUN = 8
SDK_INCLUDE = re.compile(r'#\s*include\s*["<](?:Havok|Gamebryo|Scaleform|SDK)/')
SOURCE_SUFFIXES = ('.h', '.hpp', '.inl', '.cpp', '.c')


def normalized(text):
    """(original line number, normalized line) pairs, comments kept so copied comments count."""
    out = []
    for number, line in enumerate(text.splitlines(), 1):
        line = ' '.join(line.split())
        if len(line) >= 4 and line not in ('{', '}', '};', '#pragma once'):
            out.append((number, line))
    return out


def window_key(lines):
    return hashlib.sha1('\n'.join(lines).encode()).digest()[:12]


def clone_dir(root, env=None):
    env = os.environ if env is None else env
    if env.get('CI'):
        return None
    path = local_dir(root, env) / 'sources' / SOURCE
    if not path.is_dir():
        return None
    head = subprocess.run(['git', '-C', str(path), 'rev-parse', 'HEAD'], capture_output=True, text=True)
    return path if head.returncode == 0 and head.stdout.strip() == REVISION else None


def reference_files(path):
    """Gamebryo files, and allowed game-code files that pull in SDK headers."""
    listing = subprocess.run(['git', '-C', str(path), 'ls-files', '--', 'src'], capture_output=True, text=True)
    for rel in listing.stdout.splitlines():
        if not rel.endswith(SOURCE_SUFFIXES):
            continue
        if rel.startswith('src/Gamebryo/'):
            yield rel
        elif allowed_path(rel):
            try:
                head = (path / rel).read_text(errors='replace')[:20000]
            except OSError:
                continue
            if SDK_INCLUDE.search(head):
                yield rel


def reference_index(path):
    index = {}
    for rel in reference_files(path):
        try:
            rows = normalized((path / rel).read_text(errors='replace'))
        except OSError:
            continue
        lines = [text for _n, text in rows]
        for i in range(len(lines) - RUN):
            index.setdefault(window_key(lines[i:i + RUN + 1]), rel)
    return index


def check_text(text, index):
    """Line numbers where a verbatim run longer than RUN starts, merged into runs."""
    rows = normalized(text)
    lines = [t for _n, t in rows]
    hits = [i for i in range(len(lines) - RUN) if window_key(lines[i:i + RUN + 1]) in index]
    out, last_end = [], -1
    for i in hits:
        if i > last_end:
            out.append(i)
        last_end = max(last_end, i + RUN)
    return [rows[i][0] for i in out]


def check_files(files, root, env=None):
    path = clone_dir(root, env)
    if path is None:
        return []
    index = reference_index(path)
    findings = []
    for f in files:
        full = Path(f)
        try:
            text = full.read_text(errors='replace')
        except OSError:
            continue
        for line in check_text(text, index):
            try:
                shown = full.relative_to(root).as_posix()
            except ValueError:
                shown = full.name
            findings.append(f'{shown}:{line}: run of more than {RUN} lines repeats fo4-private SDK/Gamebryo '
                            'material verbatim; rewrite it (details omitted)')
    return findings
