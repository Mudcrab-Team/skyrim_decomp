"""Functions that can be claimed and recorded without a `data/progress.json` entry.

The published target-hash manifest is the public list of function bounds. A function in it that
the inventory does not hold is claimable: the entry is made when the function is recorded, so the
inventory grows only with accepted work. Counts and RVAs only; nothing here reads game bytes.
"""
import json
from pathlib import Path

MANIFEST = 'data/target-hashes/sse-steam-1-7-104.json'
OFFERED = 'data/target-hashes/contributor-targets.json'
EVIDENCE = 'findings/claim-time-mapping.md'
BANDS = ((64, 0), (256, 1))


def band(size):
    """0 for under 64 bytes, 1 for 64-255, 2 above: the sizes the match rate is highest at."""
    return next((rank for limit, rank in BANDS if size < limit), 2)


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
        rows = json.loads((Path(root) / OFFERED).read_text())['functions']
    except (OSError, ValueError, KeyError):
        return {}
    return {row['rva']: row['class'] for row in rows if row.get('class')}


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
