"""Where a compiled unit stood before it moved to the subsystem layout (data/source-moves.json).

A move rewrites a match record's `source.compiled` and `source.translation_unit`, but the paths
that comparator and CI runs embedded when they ran (`report.source.path`, the internal identity's
`source_path`, `ci_confirmation.unit`) are evidence of that run and stay as written. For an
internal identity the old path also feeds the identity's `map_key`, so it cannot be rewritten at
all. The checks therefore read those fields through `accepted_paths`: the unit's path now, or the
path it was compiled under.

The map has `dirs` (a whole old folder moved to one new folder, file names unchanged) and `files`
(one compiled file's old path to its new path).
"""
import json
import posixpath
from functools import lru_cache
from pathlib import Path

MOVES = 'data/source-moves.json'


@lru_cache(maxsize=4)
def _load(path):
    p = Path(path)
    if not p.is_file():
        return {}, {}
    doc = json.loads(p.read_text())
    files = {new: old for old, new in doc.get('files', {}).items()}
    dirs = {new: old for old, new in doc.get('dirs', {}).items()}
    return files, dirs


def old_path(new, root):
    """The path a compiled file had before it was moved, or `new` when it never moved."""
    files, dirs = _load(str(Path(root) / MOVES))
    if new in files:
        return files[new]
    where = posixpath.dirname(new)
    if where in dirs:
        return posixpath.join(dirs[where], posixpath.basename(new))
    return new


def accepted_paths(compiled, root):
    """The paths an embedded run record may name for the unit compiled at `compiled`."""
    return {compiled, old_path(compiled, root)}
