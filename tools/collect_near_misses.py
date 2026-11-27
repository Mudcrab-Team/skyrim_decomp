#!/usr/bin/env python3
"""Collect near misses from public drafts, handoffs, worktrees or task directories.

    python3 tools/collect_near_misses.py PATH [PATH ...]

Use the resulting <build>/0x<rva> directory as the permuter task, and its
source-root directory with --source-root. pool.json lists the active copies.
Public drafts use a local task for the same build and RVA for symbols and packs.
"""
import argparse
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess
import tempfile

import draft_bundle
import giveup
import record_store
from source_digest import INCLUDE_ROOTS, include_closure, quoted_includes

REPO = Path(__file__).resolve().parents[1]
SKIP_DIRS = {'attempts', 'packs', 'out', 'reconstruction', 'sources', 'toolchains', 'wineprefix', 'worktrees'}
NEAR_MISS = re.compile(r'^- (0x[0-9a-f]+)\b', re.I)
HANDOFF_PATH = re.compile(r'`((?:/|\.local/)[^`]+)`|(?:^|\s)(/[^\s`(),;]+)')


def read_json(path):
    return json.loads(path.read_text())


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def rva(value):
    return value if isinstance(value, int) else int(value, 16)


def integrated(repo):
    subprocess.run(['git', 'fetch', '--quiet', 'origin', 'main'], cwd=repo, check=True)
    data = json.loads(subprocess.check_output(['git', 'show', 'origin/main:data/progress.json'], cwd=repo))
    return {(f['build_id'], rva(f['rva'])) for f in data['functions'] if f['status'] == 'matched'}


def handoff_inputs(path):
    """Paths and explicitly identified near misses in a Markdown handoff."""
    paths, targets = set(), set()
    local = next((p for p in path.parents if p.name == '.local'), None)
    section = False
    for line in path.read_text().splitlines():
        if line.startswith('#'):
            section = bool(re.match(r'^#+\s+near[ -]miss(?:es)?\b', line, re.I))
        row = NEAR_MISS.match(line)
        if row and (section or re.search(r'\bnear[_ -]miss\b', line, re.I)):
            targets.add(rva(row[1]))
        for match in HANDOFF_PATH.finditer(line):
            ref = Path((match[1] or match[2]).rstrip('.:/'))
            if not ref.is_absolute() and local:
                ref = local.parent / ref
            if ref.is_dir() or (ref.is_file() and ref.name == 'staged.json'):
                paths.add(ref.resolve())
    return paths, targets


def discover(paths):
    """Yield staged indexes and task directories without traversing unrelated worktrees."""
    seen = set()
    for path in sorted(paths):
        if path.is_file():
            if path.name == 'staged.json' and path not in seen and '.local' in path.parts:
                seen.add(path)
                yield path
            continue
        start = path / '.local' if (path / '.git').exists() else path
        for directory, dirs, files in os.walk(start):
            folder = Path(directory)
            dirs[:] = sorted(d for d in dirs if d not in SKIP_DIRS and not (folder / d / '.git').exists())
            if '.local' not in folder.parts:
                continue
            for name in ('staged.json', 'task.json', 'all-results.json'):
                if name in files and folder / name not in seen:
                    seen.add(folder / name)
                    yield folder / name


def saved_source(task, compiled, address, roots, listed):
    saved = task / 'near-miss'
    for name in (f'{address:x}.cpp', f'0x{address:x}.cpp', compiled.name):
        if (saved / name).is_file():
            return saved / name
    if listed:
        for root in roots:
            if (root / compiled).is_file():
                return root / compiled
        attempts = task / 'attempts'
        if attempts.is_dir():
            for entry in sorted(attempts.iterdir(), key=lambda p: int(p.name) if p.name.isdecimal() else -1,
                                reverse=True):
                source = entry / 'src' / compiled.name
                if source.is_file():
                    return source
    return None


def copy_unit(dest, compiled, source, roots):
    """Copy the saved translation unit, preferring private siblings over checkout dependencies."""
    source_root = dest / 'source-root'
    public = '/'.join(source.parts[-3:])
    if giveup.DRAFT_FILE.fullmatch(public):
        draft_bundle.restore(source.parents[2], public, source_root, compiled.as_posix())
        return
    pending = [(compiled, source, ())]
    while pending:
        name, original, parents = pending.pop()
        path = source_root / name
        if path.is_file():
            continue
        path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(original, path)
        for kind, inc in quoted_includes(path.read_bytes(), str(name)):
            bases = ([name.parent, *parents] if kind == '"' else []) + [Path(p) for p in INCLUDE_ROOTS]
            for base in bases:
                rel = Path(os.path.normpath(base / inc))
                if rel.is_absolute() or not rel.is_relative_to('reconstruction'):
                    continue
                options = []
                if rel.parent == compiled.parent:
                    if rel.name == compiled.with_suffix('.h').name:
                        options.append(source.with_suffix('.h'))
                    options.append(source.parent / rel.name)
                options.extend(root / rel for root in roots)
                found = next((p for p in options if p.is_file()), None)
                if found:
                    pending.append((rel, found, (name.parent, *parents)))
    include_closure(source_root, compiled.as_posix())


def copy_task(pool, task_path, raw, fn, source, roots):
    build, address = raw['build_id'], rva(fn['rva'])
    if not re.fullmatch(r'[a-z0-9][a-z0-9-]*', build):
        raise ValueError('invalid build ID')
    compiled = PurePosixPath(raw['compiled'])
    if not compiled.is_relative_to('reconstruction') or '..' in compiled.parts or compiled.suffix != '.cpp':
        raise ValueError('invalid compiled path')
    dest = pool / build / f'0x{address:x}'
    if not dest.resolve().is_relative_to(pool.resolve()):
        raise ValueError('task copy must stay inside the pool')
    if (dest / 'task.json').is_file():
        return dest
    task = task_path.parent
    symbols = Path(raw.get('symbols', 'symbols.json'))
    if symbols.parts[0] == 'reports':
        symbols = next((p / symbols for p in roots if record_store.is_file(p / symbols)), symbols)
    else:
        symbols = task / symbols
    pack = next((d / 'pack.json' for d in [task / 'packs' / build / f'0x{address:x}',
                *(p / fn['pack'] for p in roots if fn.get('pack'))] if (d / 'pack.json').is_file()), None)
    dest.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=dest.parent) as temp:
        draft = Path(temp) / 'draft'
        draft.mkdir()
        copy_unit(draft, Path(compiled), source, roots)
        (draft / 'symbols.json').write_bytes(record_store.read_bytes(symbols))
        if pack:
            (draft / 'pack').mkdir()
            shutil.copyfile(pack, draft / 'pack/pack.json')
        copied = dict(raw, symbols='symbols.json', functions=[dict(fn, pack=str(dest / 'pack') if pack else None)])
        copied['task_schema'] = 2 if 'internal_selector' in fn else 1
        write_json(draft / 'task.json', copied)
        draft.rename(dest)
    return dest


def collect(repo, paths, matched):
    repo = repo.resolve()
    pool = repo / '.local/near-miss'
    if not pool.resolve().is_relative_to(repo / '.local'):
        raise ValueError('pool must stay under this checkout’s .local directory')
    pool.mkdir(parents=True, exist_ok=True)
    targets, inputs, public = set(), set(), {}
    for path in paths:
        if path.name == giveup.DRAFT_DIR or giveup.DRAFT_FILE.fullmatch('/'.join(path.parts[-3:])):
            for source in path.glob('*/*.cpp') if path.is_dir() else (path,):
                if not source.is_symlink() and giveup.DRAFT_FILE.fullmatch('/'.join(source.parts[-3:])):
                    public[source.parent.name, rva(source.stem)] = source
        elif path.suffix.lower() == '.md':
            refs, marked = handoff_inputs(path)
            inputs.update(refs)
            targets.update(marked)
        else:
            inputs.add(path)
    public_only = bool(public) and not inputs
    if public:
        inputs.update((repo / '.local/tasks', repo / '.local/contrib/tasks'))
    files = list(discover(inputs))
    candidates = []
    for path in (p for p in files if p.name == 'staged.json'):
        for row in read_json(path):
            if row.get('stage') and row.get('compiled_rel'):
                candidates.append((Path(row['stage']) / 'task.json', rva(row['rva']), path.parent / 'root'))
    for path in (p for p in files if p.name == 'all-results.json'):
        rows = read_json(path)
        if isinstance(rows, list):
            targets.update(rva(row['rva']) for row in rows if row.get('outcome') == 'near-miss' and 'rva' in row)
    candidates.extend((p, None, None) for p in files if p.name == 'task.json')
    skipped, errors = set(public) & matched, {}
    for path, selected, staged in candidates:
        if '.local' not in path.resolve().parts or not path.is_file():
            continue
        raw = read_json(path)
        if not {'build_id', 'functions', 'compiled'} <= raw.keys():
            continue
        roots = ([staged] if staged else []) + [p for p in path.parents if (p / 'reconstruction').is_dir()] + [repo]
        for fn in raw['functions']:
            address = rva(fn['rva'])
            if fn.get('role') == 'regression' or (selected is not None and address != selected):
                continue
            compiled = Path(raw['compiled'])
            key = raw['build_id'], address
            if key in public:
                source = public[key]
            elif public_only:
                continue
            elif staged is None:
                source = saved_source(path.parent, compiled, address, roots[:-1], address in targets)
            else:
                source = staged / compiled
            if not source:
                continue
            if key in matched:
                skipped.add(key)
                continue
            try:
                copy_task(pool, path, raw, fn, source, roots)
            except (OSError, ValueError) as exc:
                errors[key] = f'{path.parent.name} {hex(address)}: {type(exc).__name__}'
            else:
                errors.pop(key, None)
    active = []
    for path in sorted(pool.glob('*/0x*/task.json')):
        key = path.parent.parent.name, rva(path.parent.name)
        if key in matched:
            skipped.add(key)
        else:
            active.append(path.parent.relative_to(pool).as_posix())
    with tempfile.TemporaryDirectory(dir=pool) as temp:
        index = Path(temp) / 'pool.json'
        write_json(index, active)
        index.replace(pool / 'pool.json')
    missing = set(public) - skipped - set(errors) - {
        (build, rva(address)) for build, address in (name.split('/') for name in active)}
    messages = list(errors.values())
    if missing:
        messages.append(f'{len(missing)} public draft(s) without a prepared local task')
    return active, skipped, messages


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('paths', type=Path, nargs='+', help='drafts/ or a draft .cpp, Markdown handoffs, worktrees or private tasks')
    args = parser.parse_args(argv)
    paths = [p.resolve() for p in args.paths]
    for path in paths:
        if not path.exists():
            parser.error(f'input does not exist: {path}')
    active, skipped, errors = collect(REPO, paths, integrated(REPO))
    print(f'{len(active)} active copies in .local/near-miss, {len(skipped)} already matched on origin/main')
    for message in errors:
        print(f'could not collect {message}')
    return int(bool(errors))


if __name__ == '__main__':
    raise SystemExit(main())
