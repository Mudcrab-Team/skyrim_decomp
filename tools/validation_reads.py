"""Read-once bytes during one read-only metadata load; never retained across loads.

Stat identity is checked on each use so edits, replacements, modes and symlinks invalidate
the entry even inside that scope. No pathlib methods or process-global I/O are patched.
"""
from contextlib import contextmanager
from contextvars import ContextVar
import io
from pathlib import Path
import stat

import record_store

_READS = ContextVar('validation_reads', default=None)


@contextmanager
def read_once():
    token = _READS.set({})
    try:
        yield
    finally:
        _READS.reset(token)


def identity(path):
    link = path.lstat()
    st = path.stat() if stat.S_ISLNK(link.st_mode) else link
    return (st.st_dev, st.st_ino, st.st_mode, st.st_size, st.st_mtime_ns, st.st_ctime_ns,
            link.st_dev, link.st_ino, link.st_mode, link.st_mtime_ns, link.st_ctime_ns)


def read_bytes(path):
    path = Path(path).absolute()
    if not path.is_file() and record_store.split(path) is not None:
        # Packed records are immutable inside a shard, so no stat identity is needed.
        return record_store.read_bytes(path)
    cache = _READS.get()
    if cache is None:
        return path.read_bytes()
    stamp = identity(path)
    saved = cache.get(path)
    if saved is not None and saved[0] == stamp:
        return saved[1]
    blob = path.read_bytes()
    if identity(path) == stamp:
        cache[path] = stamp, blob
    return blob


def read_text(path):
    # Match Path.read_text's default locale encoding and universal newline handling exactly.
    with io.TextIOWrapper(io.BytesIO(read_bytes(path)), encoding=io.text_encoding(None)) as stream:
        return stream.read()
