"""Functions that can be claimed and recorded without a `data/progress.json` entry.

The published target-hash manifest is the public list of function bounds. A function in it that
the inventory does not hold is claimable: the entry is made when the function is recorded, so the
inventory grows only with accepted work. Counts and RVAs only; nothing here reads game bytes.
"""
import hashlib
import json
from pathlib import Path

MANIFEST = 'data/target-hashes/sse-steam-1-7-104.json'
OFFERED = 'data/target-hashes/contributor-targets.json'
OFFERED_ROWS = 3000  # rows per offered part: the tracked-file cap is 1 MiB and a row is about 140 bytes
EVIDENCE = 'findings/claim-time-mapping.md'
BANDS = ((64, 0), (256, 1))


def band(size):
    """0 for under 64 bytes, 1 for 64-255, 2 above: the sizes the match rate is highest at."""
    return next((rank for limit, rank in BANDS if size < limit), 2)


def sharded_json(root, path, key):
    """The JSON file at `path` with its `key` collection read back from the parts it lists.

    A list too long for the tracked-file cap is stored as `parts` (path, SHA-256, count) beside the other
    fields; a part that is missing, differs from its digest or has the wrong count raises ValueError, so a
    reader never works from a partial list.
    """
    root = Path(root)
    data = json.loads((root / path).read_text())
    if 'parts' not in data:
        return data
    rows = []
    for part in data.pop('parts'):
        blob = (root / part['path']).read_bytes()
        if hashlib.sha256(blob).hexdigest() != part['sha256']:
            raise ValueError(f'{part["path"]}: differs from its recorded digest')
        piece = json.loads(blob)[key]
        if len(piece) != part['count']:
            raise ValueError(f'{part["path"]}: wrong count')
        rows += piece if key == 'functions' else list(piece.items())
    data[key] = rows if key == 'functions' else dict(rows)
    return data


def write_sharded(root, path, data, key, size):
    """Write `data` to `path`, its `key` collection split into parts of `size` entries beside it.

    Stale parts of an earlier, longer list are removed. Returns the paths written, for staging.
    """
    root = Path(root)
    target = root / path
    stem = target.name[:-len('.json')] + '-part-'
    items = data[key] if key == 'functions' else list(data[key].items())
    for old in target.parent.glob(stem + '*.json'):
        old.unlink()
    parts, written = [], [path]
    for i in range(0, len(items), size):
        chunk = items[i:i + size]
        name = f'{stem}{i // size:03d}.json'
        blob = (json.dumps({key: chunk if key == 'functions' else dict(chunk)}, indent=2 if key == 'functions' else 1,
                           sort_keys=key != 'functions') + '\n').encode()
        (target.parent / name).write_bytes(blob)
        rel = (Path(path).parent / name).as_posix()
        parts.append({'path': rel, 'sha256': hashlib.sha256(blob).hexdigest(), 'count': len(chunk)})
        written.append(rel)
    index = {k: v for k, v in data.items() if k != key}
    index['parts'] = parts
    target.write_text(json.dumps(index, indent=2 if key == 'functions' else 1, sort_keys=key != 'functions') + '\n')
    return written


def published_sizes(root):
    """{rva: size} of every function in the published target-hash shards."""
    root = Path(root)
    try:
        manifest = json.loads((root / MANIFEST).read_text())
        out = {}
        for shard in manifest['shards']:
            for row in json.loads((root / shard['path']).read_text())['functions']:
                out[row['rva']] = row['size']
        return out
    except (OSError, ValueError, KeyError):
        return {}


def offered_classes(root):
    """{rva: class} for offered rows that name the class whose layout they extend."""
    try:
        rows = sharded_json(root, OFFERED, 'functions')['functions']
    except (OSError, ValueError, KeyError):
        return {}
    return {row['rva']: row['class'] for row in rows if row.get('class')}


def offered_window(root):
    """{rva: class or None} for every offered row the refill keeps until it is recorded.

    A row is kept when it names a class (its layout is the reason it was offered) or carries `window`
    (published by a window slice that had no layout to name, so there is no class to find it by).
    """
    try:
        rows = sharded_json(root, OFFERED, 'functions')['functions']
    except (OSError, ValueError, KeyError):
        return {}
    return {row['rva']: row.get('class') for row in rows if row.get('class') or row.get('window')}


def entry(build_id, rva, size, cls=None):
    """The inventory entry a claim-time function gets: mapped, with a placeholder name labelled GUESS."""
    name = f'Function{rva:x}'
    return {'id': f'{build_id}-0x{rva:x}', 'build_id': build_id, 'rva': rva, 'size': size, 'status': 'mapped',
            'name': f'{cls}::{name}' if cls else name, 'name_origin': 'GUESS',
            'name_source': 'GUESS(low): placeholder name from the RVA' + (
                '; the class is the vtable owner in the project function table' if cls else '; no class claimed')
            + f'. RVA 0x{rva:x}; size from the published function bounds.',
            'owner': 'claim-time', 'evidence': EVIDENCE}


def resolve(root, build_id, rva, inventory_rvas, table=None):
    """An entry for a published function the inventory lacks, or None.

    `table` is the private function table's rows by RVA when the caller has it: the function must
    then be an ordinary function there with the published size.
    """
    if rva in inventory_rvas:
        return None
    size = published_sizes(root).get(rva)
    if size is None:
        return None
    if table is not None:
        row = table.get(rva)
        if not row or row.get('kind') != 'ordinary' or row.get('size') != size:
            return None
    return entry(build_id, rva, size, offered_classes(root).get(rva))


def load_table(path):
    """The private function table by RVA, or None when it is not on this machine."""
    path = Path(path)
    if not path.is_file():
        return None
    return {row['rva']: row for row in map(json.loads, path.read_text().splitlines()) if row.get('rva') is not None}
