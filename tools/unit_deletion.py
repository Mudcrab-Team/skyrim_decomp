"""When may a PR delete a reconstruction unit file without orphaning an accepted function?

Shared by the bot and the CI hash job so both give the same answer. A unit is deleted by removing its
`.h` and/or `.cpp`; its declared functions must each be unaccepted, or accepted with a record that
binds a different unit which still exists. Any accepted record that binds the deleted unit itself is
refused even if no header names it, because the record would point at a file that is gone.
"""
import json
from pathlib import Path

from rva_headers import claimed_rvas


def stem_of(name):
    return name.rsplit('.', 1)[0]


def problems(root, deleted, read_base, exists, read_file=None):
    """[message] for deleted unit files (repo paths) that would orphan an accepted function; [] when safe.

    `root` holds data/progress.json and the records as on the trusted base. `read_base(path)` returns the
    base text of a unit file or None; `exists(path)` says whether a path is still present after the PR.
    `read_file(path)` returns the text of the inventory or a record, or None to read it from `root`; a PR that
    carries its own records passes its head's, so records rebound to a unit that stays are not orphans.
    """
    root = Path(root)
    stems = sorted({stem_of(n) for n in deleted})
    if not stems:
        return []
    def load(path):
        text = read_file(path) if read_file else None
        return text if text is not None else (root / path).read_text()
    inventory = json.loads(load('data/progress.json'))['functions']
    accepted = {}
    for fn in inventory:
        if fn.get('status') != 'matched' or not fn.get('report'):
            continue
        try:
            source = json.loads(load(fn['report'])).get('source') or {}
        except (OSError, ValueError):
            continue
        accepted[fn['rva']] = source.get('compiled')
    out = []
    for stem in stems:
        cpp = stem + '.cpp'
        texts = [t for t in (read_base(stem + e) for e in ('.h', '.cpp')) if t is not None]
        declared = claimed_rvas(texts)
        for rva, compiled in sorted(accepted.items()):
            if compiled == cpp:
                out.append(f'{stem}: accepted function 0x{rva:x} is bound by its record to this unit, so '
                           'deleting it would orphan the record; re-bind or re-accept it in another unit first')
            elif rva in declared and compiled and not exists(compiled):
                out.append(f'{stem}: accepted function 0x{rva:x} is bound to {compiled}, which does not '
                           'exist after this PR')
    return out
