"""Small worker checkouts; report reads always use this checkout's index, never moving main.

Acceptance lanes stay full. Full-tree checks can temporarily expand a worker and restore its
patterns afterwards. Missing tracked reports can be read in one cat-file batch without creating
thousands of files, or materialized with their report dependencies for ordinary path consumers.
"""
from contextlib import contextmanager
import json
import re
from pathlib import Path
import subprocess

import record_store
import tempfile

# Record shards are small and stay; every other file under reports/ is fetched on demand, so a
# worker never writes the maps and families it does not use.
PATTERNS = '/*\n!/site/\n!/reports/\n/reports/*/packs/\n'


def git(root, *args, **kwargs):
    return subprocess.run(['git', *args], cwd=root, check=True, capture_output=True, **kwargs).stdout


def active(root):
    result = subprocess.run(['git', 'config', '--bool', 'core.sparseCheckout'], cwd=root,
                            capture_output=True, text=True)
    return result.returncode == 0 and result.stdout.strip() == 'true'


def set_patterns(tree, patterns=PATTERNS):
    git(tree, 'sparse-checkout', 'set', '--no-cone', '--stdin', input=patterns.encode())


def add_worktree(root, tree, revision, branch=None, new_branch=False):
    args = ['worktree', 'add', '--quiet', '--no-checkout']
    if new_branch:
        args += ['-b', branch]
    elif branch is None:
        args += ['--detach']
    git(root, *args, str(tree), revision)
    set_patterns(tree)
    git(tree, 'read-tree', '-mu', 'HEAD')


@contextmanager
def full(tree):
    """Run the unchanged full-tree consumers, then restore sparsity even on failure."""
    patterns = None
    if active(tree):
        path = Path(git(tree, 'rev-parse', '--path-format=absolute', '--git-path',
                        'info/sparse-checkout').decode().strip())
        patterns = path.read_text()
        git(tree, 'sparse-checkout', 'disable')
    try:
        yield
    finally:
        if patterns is not None:
            set_patterns(tree, patterns)


def report_name(name):
    if not isinstance(name, str):
        raise ValueError('invalid sparse report path')
    path = Path(name)
    if (not name.startswith('reports/') or path.is_absolute()
            or '..' in path.parts or any(c in name for c in '\n\r\\')):
        raise ValueError('invalid sparse report path')
    return name


def reports(root, names):
    """Yield (path, JSON or None), preferring working edits over omitted index blobs."""
    root = Path(root)
    names = [report_name(n) for n in names]
    sparse = active(root)
    if not sparse:
        for name in names:
            path = root / name
            yield name, json.loads(record_store.read_text(path)) if record_store.is_file(path) else None
        return
    skipped = {row[2:].decode() for row in git(root, 'ls-files', '-v', '-z', '--', 'reports/').split(b'\0')
               if row[:1].upper() == b'S'}
    # A file avoids filling stdin while cat-file is blocked on its output pipe.
    with tempfile.TemporaryFile() as requests:
        requests.write(''.join(':' + n + '\n' for n in names
                               if n in skipped and not record_store.is_file(root / n)).encode())
        requests.seek(0)
        with subprocess.Popen(['git', 'cat-file', '--batch'], cwd=root, stdin=requests,
                              stdout=subprocess.PIPE) as proc:
            try:
                for name in names:
                    path = root / name
                    if record_store.is_file(path):
                        yield name, json.loads(record_store.read_text(path))
                    elif name in skipped:
                        header = proc.stdout.readline().split()
                        if header[-1:] == [b'missing']:
                            yield name, None
                            continue
                        size = int(header[-1])
                        blob = proc.stdout.read(size)
                        if proc.stdout.read(1) != b'\n' or len(blob) != size:
                            raise ValueError('incomplete sparse report blob')
                        yield name, json.loads(blob)
                    else:
                        yield name, None
                if proc.wait():
                    raise ValueError('sparse report batch failed')
            finally:
                proc.stdout.close()  # Do not wait on a blocked writer if parsing or a caller fails.


def ensure(root, names):
    """Materialize selected reports and referenced maps, histories and family manifests."""
    if not active(root):
        return
    skipped = git(root, 'ls-files', '-v', '-z', '--', 'reports/').split(b'\0')
    if not any(row[:1].upper() == b'S' for row in skipped):
        return
    seen, pending = set(), set(names)
    def references(value):
        if isinstance(value, str) and value.startswith('reports/'):
            yield report_name(value)
        elif isinstance(value, dict):
            for child in value.values():
                yield from references(child)
        elif isinstance(value, list):
            for child in value:
                yield from references(child)
    while pending:
        batch = pending - seen
        if not batch:
            break
        seen.update(batch)
        pending = set()
        for name, value in reports(root, sorted(batch)):
            if value is not None:
                pending.update(references(value))
            if name.endswith('.json') and not name.endswith('.history.json'):
                pending.add(name[:-5] + '.history.json')
    if seen:
        # Escape wildmatch metacharacters: dependencies are literal paths, not patterns.
        patterns = ['/' + ''.join('\\' + c if c in '*?[]' else c for c in n) for n in sorted(seen)]
        git(root, 'sparse-checkout', 'add', '--stdin', input=('\n'.join(patterns) + '\n').encode())


def source_evidence(root, files):
    """The existing lint still checks evidence paths in the selected include closure."""
    if not active(root):
        return
    names = set()
    for name in files:
        text = (Path(root) / name).read_text()
        for line in text.splitlines():
            if 'Evidence:' in line:
                names.update(match.rstrip('.,;') for match in
                             re.findall(r'reports/[^\s`<>]+', line))
    ensure(root, names)


def worker_default(tree, config):
    """Optional post-checkout hook for app-created workers; never alter active/dirty views."""
    tree = Path(tree).resolve()
    if not any(tree.is_relative_to(Path(base).resolve()) for base in config.get('worker_roots', [])):
        return False
    if any(tree == Path(path).resolve() or tree.is_relative_to(Path(path).resolve())
           for path in config.get('keep', [])):
        return False
    if active(tree) or git(tree, 'status', '--porcelain', '--untracked-files=all').strip():
        return False
    set_patterns(tree)
    # Existing kit links are retained. New workers share the canonical private inputs.
    for name, source in config.get('shared', {}).items():
        if name not in ('toolchains', 'wineprefix', 'sources', 'analysis'):
            raise ValueError('unsupported shared private input')
        target = tree / '.local' / name
        target.parent.mkdir(exist_ok=True)
        if not target.exists() and not target.is_symlink():
            target.symlink_to(Path(source).resolve(), target_is_directory=True)
    return True


def main():
    import argparse
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('tree', type=Path)
    parser.add_argument('revision')
    args = parser.parse_args()
    add_worktree(Path.cwd(), args.tree, args.revision)


if __name__ == '__main__':
    main()
