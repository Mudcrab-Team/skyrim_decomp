#!/usr/bin/env python3
"""Give a git worktree the ignored private inputs a drafter needs, without touching its sources.

    python3 tools/worktree_kit.py <worktree> [--main DIR] [--check] [--json]

A worktree has no `.local/` of its own. Several tools fall back to the main checkout's one
(`tools/local_paths.py`), but a raw `grep .local/sources/...`, a script with a hard-coded
`.local/...` path or a worktree that already has some `.local` files does not. This command adds
the missing links, so the toolkit in docs/drafter-toolkit.md works from any worktree:

- whole directories (community and sibling sources, the sibling x64 indexes, the library-shape
  and sibling-build data, toolchains, symbol inputs) become symlinks to the main checkout's copy;
- entries that a worktree may already hold a private version of (`analysis/`, `contrib/`,
  `verifier/`) are merged: only what is missing is added, and nothing existing is replaced;
- `verifier/config.json` (image and objdump paths) and `verifier/runners.json` are copied, and
  the executable path is written to `contrib/config.json` when the worktree has none (an existing
  file is never edited; the output then says to export SR_SKYRIM_EXE).

It is idempotent and only updates entries under `<worktree>/.local/`. Legacy verifier config links
become private copies. Existing regular files are kept, and writes through linked directories are refused.
`--check` prints the same table without changing anything. Output names resources only; nothing
game-derived is read or printed.
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

# name -> why a drafter wants it (shown by --check)
WHOLE_DIRS = {
    'sources': 'community headers, FNV/F3/FO4-private sibling sources and their indexes',
    'f3x64': 'sibling x64 builds, listings, shape signatures and the lab results',
    'fnvx64': 'FNV x64 build listings',
    'msvclib': 'library-shape (STL instance) index data',
    'toolchains': 'pinned MSVC and Wine toolchains',
    'inputs': 'symbol inputs and the address library',
    'config': 'export pack configuration',
}

# parent -> entries merged one by one when the worktree lacks them
MERGED = {
    'analysis': ('functions.jsonl', 'classes.jsonl', 'fnv_index.jsonl', 'fnv_index.meta.json', 'callsites.json',
                 'table-meta.json', 'parked-census.json', 'origin-index'),
    'contrib': ('x64-index', 'decompiler'),  # x64-index: sibling shape index fetched by ./sr setup
}
# (worktree entry, entry of the main private directory): `./sr start` reads the sibling source
# lookup from contrib/analysis, which the internal tables keep one level up
ALIASES = (
    ('contrib/analysis/fnv_index.jsonl', 'analysis/fnv_index.jsonl'),
    ('contrib/analysis/fnv_index.meta.json', 'analysis/fnv_index.meta.json'),
)
VERIFIER_CONFIGS = {'config.json': 'image and objdump paths', 'runners.json': 'runner hosts for attempt and confirm'}


def main_local(worktree, main=None):
    if main:
        return Path(main).resolve()
    proc = subprocess.run(['git', 'rev-parse', '--path-format=absolute', '--git-common-dir'],
                          cwd=worktree, capture_output=True, text=True)
    if proc.returncode or not proc.stdout.strip():
        raise ValueError(f'{worktree} is not inside a git checkout')
    return (Path(proc.stdout.strip()).parent / '.local').resolve()


def exists(path):
    return path.exists() or path.is_symlink()


def through_link(local, rel):
    """True when a parent directory of `local/rel` is a symlink, so creating it would write elsewhere."""
    path = Path(local)
    if path.is_symlink():
        return True
    for part in Path(rel).parts[:-1]:
        path = path / part
        if path.is_symlink():
            return True
    return False


def link_target(source, dest, local):
    target = source.resolve()
    if target.is_relative_to(local.parent.resolve()) or dest.resolve().is_relative_to(target):
        raise ValueError(f'cannot link .local/{dest.relative_to(local)} to a target within the worktree or an ancestor')
    return target


def link_input(source, dest, local):
    if exists(dest):
        return
    if through_link(local, dest.relative_to(local)):
        raise ValueError(f'cannot link .local/{dest.relative_to(local)} through a symlinked directory')
    target = link_target(source, dest, local)
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.symlink_to(target, target_is_directory=target.is_dir())


def copy_config(source, dest):
    """Keep a regular config or replace an old link with a private copy of its contents."""
    if exists(dest) and not dest.is_symlink():
        return
    with tempfile.TemporaryDirectory(dir=dest.parent) as tmp:
        copy = Path(tmp) / dest.name
        shutil.copy2(dest if dest.is_file() else source, copy)
        if dest.is_symlink():
            copy.replace(dest)
        else:
            try:
                os.link(copy, dest)
            except FileExistsError:
                pass


def plan(worktree, source):
    """[(kind, relative name, detail)] of what would be added; kind is link, copy, config or missing."""
    worktree, source = Path(worktree).resolve(), Path(source).resolve()
    local = worktree / '.local'
    if source == local.resolve():
        return []
    if local.is_symlink():
        raise ValueError('worktree .local must be its own directory')
    todo = []

    def add_link(rel, why=''):
        src, dest = source / rel, local / rel
        if not exists(src):
            todo.append(('missing', rel, why))
        elif not exists(dest):
            todo.append(('link', rel, why))

    for name, why in WHOLE_DIRS.items():
        add_link(name, why)
    for parent, entries in MERGED.items():
        if (local / parent).is_symlink():
            continue
        for name in entries:
            if not exists(local / parent / name):
                add_link(f'{parent}/{name}')
    for rel, origin in ALIASES:
        if through_link(local, rel) or exists(local / rel):
            continue
        if exists(source / origin):
            todo.append(('link', rel, origin))
        else:
            todo.append(('missing', rel, f'built from {origin}'))
    verifier = local / 'verifier'
    if not verifier.is_symlink():
        for name, detail in VERIFIER_CONFIGS.items():
            src, dest = source / 'verifier' / name, verifier / name
            if (src.is_file() or dest.is_file()) and (dest.is_symlink() or not exists(dest)):
                todo.append(('copy', f'verifier/{name}', detail))
    exe = exe_path(source)
    contrib = local / 'contrib'
    if exe and not contrib.is_symlink() and 'exe' not in read_json(contrib / 'config.json'):
        if exists(contrib / 'config.json'):
            todo.append(('note', 'contrib/config.json', f'names no exe; export SR_SKYRIM_EXE="{exe}" in the shell'))
        else:
            todo.append(('config', 'contrib/config.json', 'game executable path'))
    for kind, rel, _detail in todo:
        if kind == 'link':
            link_target(source / dict(ALIASES).get(rel, rel), local / rel, local)
    return todo


def read_json(path):
    try:
        data = json.loads(Path(path).read_text())
    except (OSError, ValueError):
        return {}
    return data if isinstance(data, dict) else {}


def exe_path(source):
    """The game image path: SR_SKYRIM_EXE, else the main checkout's verifier or contrib config."""
    value = os.environ.get('SR_SKYRIM_EXE') or read_json(source / 'verifier/config.json').get('image') \
        or read_json(source / 'contrib/config.json').get('exe')
    return str(value) if value else None


def apply(worktree, source, todo=None):
    worktree, source = Path(worktree).resolve(), Path(source).resolve()
    local = worktree / '.local'
    todo = plan(worktree, source) if todo is None else todo
    done = []
    for kind, rel, detail in todo:
        if kind in ('missing', 'note'):
            continue
        dest = local / rel
        if through_link(local, rel) or (exists(dest) and not (kind == 'copy' and dest.is_symlink())):
            continue
        if kind == 'link':
            link_input(source / dict(ALIASES).get(rel, rel), dest, local)
        else:
            dest.parent.mkdir(parents=True, exist_ok=True)
            if kind == 'copy':
                copy_config(source / rel, dest)
            elif kind == 'config':
                with dest.open('x') as handle:
                    handle.write(json.dumps({'exe': exe_path(source)}, indent=2, sort_keys=True) + '\n')
        done.append((kind, rel, detail))
    return done


def kit(worktree, main=None):
    """Add the missing private inputs to `worktree`; returns what was added. Never raises on a
    missing main checkout `.local`, so worktree creation hooks can call it unconditionally."""
    try:
        source = main_local(worktree, main)
    except ValueError:
        return []
    if not source.is_dir() or not Path(worktree).is_dir():
        return []
    return apply(worktree, source)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    ap.add_argument('worktree', type=Path)
    ap.add_argument('--main', type=Path, help="the main checkout's .local (default: found through git)")
    ap.add_argument('--check', action='store_true', help='print what would be added, change nothing')
    ap.add_argument('--json', action='store_true')
    args = ap.parse_args(argv)
    if not args.worktree.is_dir():
        print(f'error: {args.worktree} is not a directory', file=sys.stderr)
        return 2
    try:
        source = main_local(args.worktree, args.main)
    except ValueError as exc:
        print(f'error: {exc}', file=sys.stderr)
        return 2
    if not source.is_dir():
        print(f'error: no private directory at {source}', file=sys.stderr)
        return 2
    try:
        todo = plan(args.worktree, source)
        done = [] if args.check else apply(args.worktree, source, todo)
    except (OSError, ValueError) as exc:
        print(f'error: {exc}', file=sys.stderr)
        return 2
    missing = [t for t in todo if t[0] == 'missing']
    if args.json:
        print(json.dumps({'main_local': str(source), 'added': [list(d) for d in done],
                          'would_add': [list(t) for t in todo if args.check and t[0] not in ('missing', 'note')],
                          'notes': [t[2] for t in todo if t[0] == 'note'],
                          'missing_in_main': [t[1] for t in missing]}, indent=2))
        return 0
    for kind, rel, detail in (todo if args.check else [t for t in todo if t[0] == 'note'] + done):
        if kind != 'missing':
            print(f'{"would " if args.check else ""}{kind:6} .local/{rel}' + (f'  ({detail})' if detail else ''))
    for _kind, rel, detail in missing:
        print(f'absent in main checkout: .local/{rel}' + (f'  ({detail})' if detail else ''))
    if not [t for t in (todo if args.check else done) if t[0] != 'note']:
        print('nothing to add')
    return 0


if __name__ == '__main__':
    sys.exit(main())
