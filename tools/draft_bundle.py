"""Relocate the declaration headers of a draft alongside its public source."""
import os
from pathlib import Path, PurePosixPath
import posixpath
import re
import tempfile

from source_digest import INCLUDE_ROOTS, STRICT_INCLUDE, include_closure, quoted_includes

DRAFT_DIR = 'drafts'
BUILD = r'[a-z0-9][a-z0-9-]{0,63}'
RVA = r'[0-9a-f]{3,8}'
DRAFT_FILE = re.compile(rf'{DRAFT_DIR}/({BUILD})/({RVA})\.cpp\Z')
HEADER_FILE = re.compile(rf'{DRAFT_DIR}/({BUILD})/include/({RVA})/[A-Za-z0-9_][A-Za-z0-9_.+-]*\.h\Z')


def owner(name):
    match = DRAFT_FILE.fullmatch(name) or HEADER_FILE.fullmatch(name)
    return match.groups() if match else None


def header_dir(name):
    build, rva = owner(name)
    return PurePosixPath(DRAFT_DIR, build, 'include', rva)


def allowed_header(draft, name):
    return ((bool(HEADER_FILE.fullmatch(name)) and owner(name) == owner(draft))
            or (name.startswith('reconstruction/') and name.endswith('.h')))


def relative_include(name, target):
    if not re.fullmatch(r'[A-Za-z0-9_./+-]+\.h', target) or target.startswith('/'):
        return False
    return allowed_header(name, posixpath.normpath(posixpath.join(posixpath.dirname(name), target)))


def relocate(blob, name, rewrite):
    includes = quoted_includes(blob, name)
    text = blob.decode('utf-8')
    lines = text.split('\n')
    matches = [(i, m) for i, line in enumerate(lines) if (m := STRICT_INCLUDE.fullmatch(line.rstrip('\r')))]
    if len(matches) != len(includes):
        raise ValueError('draft includes must each fit on one line')
    for (index, match), (kind, target) in zip(matches, includes):
        new = rewrite(kind, target)
        if new != target:
            start, end = match.span(1 if kind == '"' else 2)
            lines[index] = lines[index][:start] + new + lines[index][end:]
    return '\n'.join(lines).encode()


def gather(root, name, source, declarations=None):
    """Return the relocated source and its own headers, leaving shared repository headers in place."""
    root = Path(root).resolve()
    source = Path(source).absolute()
    declarations = Path(declarations).absolute() if declarations else source.parent
    files, origins = {}, {}

    def visit(old, new, parents):
        if new in origins:
            if origins[new] != old:
                raise ValueError('draft headers have conflicting filenames')
            return
        origins[new] = old

        def rewrite(kind, target):
            inc = PurePosixPath(target)
            if inc.is_absolute() or '\\' in target or ':' in target:
                raise ValueError('draft include uses a host path')
            bases = ([old.parent, *parents, declarations] if kind == '"' else [])
            bases += [root / base for base in INCLUDE_ROOTS]
            for base in dict.fromkeys(bases):
                hit = Path(os.path.abspath(base / target))
                if hit.is_symlink() or not hit.is_file():
                    continue
                if not hit.resolve().is_relative_to(base.resolve()) and '..' not in inc.parts:
                    raise ValueError('draft include crosses a symlink')
                if hit.is_relative_to(root / 'reconstruction'):
                    shared = hit.relative_to(root).as_posix()
                    if kind == '<':
                        return target
                    return posixpath.relpath(shared, posixpath.dirname(new))
                if kind != '"' or not hit.resolve().is_relative_to(declarations.resolve()):
                    raise ValueError('draft declaration header is outside its source directory')
                dest = (header_dir(name) / hit.name).as_posix()
                if not HEADER_FILE.fullmatch(dest):
                    raise ValueError('draft declaration header has an unsupported filename')
                visit(hit, dest, (old.parent, *parents))
                return posixpath.relpath(dest, posixpath.dirname(new))
            if kind == '<':
                return target
            raise ValueError(f'missing draft declaration header {inc.name}')

        files[new] = relocate(old.read_bytes(), new, rewrite)

    if source.is_symlink():
        raise ValueError('draft source must be a regular file')
    visit(source, name, ())
    return files


def materialize(root, name, read):
    """Export the source and candidate include paths from a tree of regular files."""
    pending = [(name, ())]
    visited = set()
    while pending:
        member, parents = pending.pop()
        if (member, parents) in visited:
            continue
        visited.add((member, parents))
        blob = read(member)
        if blob is None:
            continue
        path = root / member
        if not path.is_file():
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(blob)
        chain = (member, *parents)
        includers = tuple(posixpath.dirname(path) for path in chain)
        for kind, target in quoted_includes(blob, member):
            if '\\' in target or ':' in target or target.startswith('/'):
                raise ValueError('draft include uses a host path')
            bases = dict.fromkeys((includers if kind == '"' else ()) + INCLUDE_ROOTS)
            for base in bases:
                candidate = posixpath.normpath(posixpath.join(base, target))
                if allowed_header(name, candidate) and candidate not in chain:
                    pending.append((candidate, chain))


def closure(root, name, *, read=None):
    if read is not None:
        with tempfile.TemporaryDirectory(prefix='draft-closure-') as directory:
            snapshot = Path(directory)
            materialize(snapshot, name, read)
            return closure(snapshot, name)
    members = include_closure(root, name)
    if any(p != name and not allowed_header(name, p) for p in members):
        raise ValueError('draft includes a file outside its header bundle and shared headers')
    return members


def restore(root, name, dest, compiled):
    """Copy the public closure to a prepared task's reconstruction layout."""
    files = closure(root, name)
    source_dir = PurePosixPath(compiled).parent
    mapping = {member: (source_dir / PurePosixPath(member).name).as_posix()
               for member in files if HEADER_FILE.fullmatch(member)}
    own = {posixpath.normpath(posixpath.join(posixpath.dirname(name), target))
           for kind, target in quoted_includes((root / name).read_bytes(), name) if kind == '"'} & mapping.keys()
    own_name = PurePosixPath(compiled).with_suffix('.h').as_posix()
    if len(own) == 1 and own_name not in mapping.values():
        mapping[next(iter(own))] = own_name
    mapping[name] = compiled
    if len({mapping.get(member, member).casefold() for member in files}) != len(files):
        raise ValueError('draft header collides with a shared header in the task')
    for member in files:
        path = dest / mapping.get(member, member)
        path.parent.mkdir(parents=True, exist_ok=True)
        blob = (root / member).read_bytes()
        if member == name:
            blob = blob.partition(b'\n')[2]
        if member in mapping:
            def rewrite(kind, target):
                resolved = posixpath.normpath(posixpath.join(posixpath.dirname(member), target))
                if kind == '"' and resolved in files:
                    return posixpath.relpath(mapping.get(resolved, resolved),
                                             posixpath.dirname(mapping[member]))
                return target

            blob = relocate(blob, member, rewrite)
        path.write_bytes(blob)
    include_closure(dest, compiled)
