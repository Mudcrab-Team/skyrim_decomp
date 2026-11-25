"""Read immutable Git metadata and bounded lint context without a checkout or per-blob processes."""
import hashlib
import json
from pathlib import Path, PurePosixPath
import subprocess


def cached_tree_bytes(root, revision):
    cache = Path(root) / '.local/git-context' / (revision + '.json')
    try:
        saved = json.loads(cache.read_text())
        raw = bytes.fromhex(saved['raw'])
        # Reject damaged cache data; the cache key is the immutable tree resolved above.
        if saved['sha256'] != hashlib.sha256(raw).hexdigest():
            raise ValueError('damaged metadata cache')
    except (OSError, ValueError, KeyError, TypeError):
        raw = subprocess.check_output(['git', 'ls-tree', '-rz', revision], cwd=root)
        try:
            cache.parent.mkdir(parents=True, exist_ok=True)
            cache.write_text(json.dumps(dict(raw=raw.hex(), sha256=hashlib.sha256(raw).hexdigest())))
        except OSError:
            pass
    return raw


def tree_entries(root, ref, *, cached=True):
    revision = subprocess.check_output(['git', 'rev-parse', f'{ref}^{{tree}}'], cwd=root).decode().strip()
    raw = (cached_tree_bytes(root, revision) if cached else
           subprocess.check_output(['git', 'ls-tree', '-rz', revision], cwd=root))
    entries = {}
    for row in filter(None, raw.split(b'\0')):
        meta, name = row.split(b'\t', 1)
        mode, kind, sha = meta.decode().split()
        entries[name.decode()] = (mode, kind, sha)
    return revision, entries


def blobs(root, entries, names):
    """One streaming batch process; reject links and Git paths that could escape the scratch tree."""
    result = {}
    with subprocess.Popen(['git', 'cat-file', '--batch'], cwd=root,
                          stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
        try:
            for name in dict.fromkeys(names):
                if name not in entries:
                    continue
                path = PurePosixPath(name)
                mode, kind, sha = entries[name]
                if path.is_absolute() or '..' in path.parts or '\\' in name or kind != 'blob' or mode not in ('100644', '100755'):
                    raise ValueError('lint context must contain regular repository files')
                proc.stdin.write(sha.encode() + b'\n')
                proc.stdin.flush()
                header = proc.stdout.readline().split()
                if len(header) != 3 or header[:2] != [sha.encode(), b'blob']:
                    raise ValueError('invalid git blob response')
                payload = proc.stdout.read(int(header[2]))
                if proc.stdout.read(1) != b'\n':
                    raise ValueError('truncated git blob')
                result[name] = payload
        finally:
            proc.stdin.close()
        if proc.wait():
            raise ValueError('git blob batch failed')
    return result


def lint_dependencies(sources):
    """All paths inspected by lint_file; lint itself still decides every rule."""
    import re
    from source_digest import INCLUDE_ROOTS, quoted_includes
    names = set(sources)
    for name, blob in sources.items():
        path = PurePosixPath(name)
        if path.suffix == '.cpp':
            names.add(str(path.with_suffix('.h')))
        text = blob.decode('utf-8', errors='replace')
        for ref in re.findall(r'(?:Evidence|Recipe):\s*([^\s,;]+)', text):
            ref = ref.rstrip('.,;')
            if not PurePosixPath(ref).is_absolute() and '..' not in PurePosixPath(ref).parts:
                names.add(ref)
        try:
            for kind, target in quoted_includes(blob, name):
                if kind == '<':
                    names.update(str(PurePosixPath(base) / target) for base in INCLUDE_ROOTS)
        except ValueError:
            pass  # lint emits the original failure
    return {n for n in names if not PurePosixPath(n).is_absolute()
            and '..' not in PurePosixPath(n).parts and '\\' not in n and ':' not in n}
