"""Target-hash rows as compact binary shards, with one loader for every reader.

A shard is `SRTH`, a version byte, a row count (u32) and fixed 73-byte rows sorted by RVA:
rva u32, size u32, normalized sha256 (32 raw bytes), layout sha256 (32 raw bytes), extraction u8.
The JSON rows these replace spent 290 bytes per row on the same facts. Rows come back as the dicts
the JSON shards held (hex digests), so callers do not change; a JSON shard still loads, which keeps
a hand-built fixture working.

    python3 tools/target_hash_store.py dump SHARD            print a shard as JSON rows
    python3 tools/target_hash_store.py convert [--root DIR]  rewrite the JSON shards of the manifest
"""
import argparse
import json
from pathlib import Path
import re
import struct
import sys

MAGIC = b'SRTH'
VERSION = 1
HEADER = struct.Struct('<4sBI')
ROW = struct.Struct('<II32s32sB')
EXTRACTIONS = ('linked-reference-inference', 'unmasked-unsupported', 'local-comparator-layout')
# 0x100000 RVA ranges: a publish touches a few shards of about 150 KB, not one 7 MB blob.
RANGE_BITS = 20
SHARD = re.compile(r'data/target-hashes/sse-steam-1-7-104-part-[0-9]{3}\.(?:thb|json)')
BINARY = re.compile(r'data/target-hashes/[a-z0-9-]+-part-[0-9]{3}\.thb')


def shard_index(rva):
    return rva >> RANGE_BITS


def shard_name(stem, index):
    return f'{stem}-part-{index:03d}.thb'


def encode(rows):
    """Bytes of one shard for rows sorted by RVA; refuses anything the format cannot hold exactly."""
    rows = sorted(rows, key=lambda r: r['rva'])
    out = [HEADER.pack(MAGIC, VERSION, len(rows))]
    for row in rows:
        if set(row) != {'rva', 'size', 'normalized_sha256', 'layout_sha256', 'extraction'}:
            raise ValueError('unexpected target-hash fields')
        if row['extraction'] not in EXTRACTIONS:
            raise ValueError('unknown extraction')
        if not (type(row['rva']) is int and 0 <= row['rva'] < 1 << 32
                and type(row['size']) is int and 0 < row['size'] < 1 << 32):
            raise ValueError('invalid target identity')
        for key in ('normalized_sha256', 'layout_sha256'):
            if not (isinstance(row[key], str) and re.fullmatch(r'[0-9a-f]{64}', row[key])):
                raise ValueError('invalid target hash')
        out.append(ROW.pack(row['rva'], row['size'], bytes.fromhex(row['normalized_sha256']),
                            bytes.fromhex(row['layout_sha256']), EXTRACTIONS.index(row['extraction'])))
    return b''.join(out)


def _check(blob):
    if len(blob) < HEADER.size:
        raise ValueError('truncated target-hash shard')
    magic, version, count = HEADER.unpack_from(blob)
    if magic != MAGIC or version != VERSION or len(blob) != HEADER.size + count * ROW.size:
        raise ValueError('invalid target-hash shard')
    return count


def is_binary(blob):
    return blob[:4] == MAGIC


def rows(blob):
    """The rows of a shard (binary or legacy JSON) as dicts with hex digests."""
    if not is_binary(blob):
        return json.loads(blob)['functions']
    _check(blob)
    return [dict(rva=rva, size=size, normalized_sha256=n.hex(), layout_sha256=l.hex(), extraction=EXTRACTIONS[x])
            for rva, size, n, l, x in ROW.iter_unpack(memoryview(blob)[HEADER.size:])]


def facts(blob):
    """[(rva, size, extraction index)] without building digests: the cheap path for callers that only
    need which functions have a row and how big they are."""
    if not is_binary(blob):
        return [(r['rva'], r.get('size', 0), EXTRACTIONS.index(r['extraction']) if r.get('extraction') in EXTRACTIONS else 0)
                for r in json.loads(blob)['functions']]
    _check(blob)
    return [(rva, size, x) for rva, size, _n, _l, x in ROW.iter_unpack(memoryview(blob)[HEADER.size:])]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    sub = ap.add_subparsers(dest='command', required=True)
    dump = sub.add_parser('dump')
    dump.add_argument('shard', type=Path)
    conv = sub.add_parser('convert')
    conv.add_argument('--root', type=Path, default=Path(__file__).resolve().parent.parent)
    args = ap.parse_args(argv)
    if args.command == 'dump':
        json.dump(dict(functions=rows(args.shard.read_bytes())), sys.stdout, indent=2)
        print()
        return 0
    import target_hashes
    return convert(args.root, target_hashes)


def convert(root, hashes):
    """Rewrite the manifest's JSON shards as binary ones and re-stamp the manifest."""
    root = Path(root)
    manifest = json.loads((root / hashes.MANIFEST).read_text())
    every = []
    for shard in manifest['shards']:
        every.extend(rows((root / shard['path']).read_bytes()))
    stem = (root / hashes.MANIFEST).with_suffix('').name
    groups = {}
    for row in every:
        groups.setdefault(shard_index(row['rva']), []).append(row)
    old = [root / s['path'] for s in manifest['shards']]
    shards = []
    for index in sorted(groups):
        blob = encode(groups[index])
        path = root / 'data/target-hashes' / shard_name(stem, index)
        path.write_bytes(blob)
        shards.append(dict(path=path.relative_to(root).as_posix(), sha256=hashes.digest(blob),
                           count=len(groups[index])))
    for path in old:
        if path.suffix == '.json':
            path.unlink()
    manifest.update(shards=shards, function_count=len(every),
                    normalizer_sha256=hashes.digest((root / 'tools/target_hashes.py').read_bytes()))
    (root / hashes.MANIFEST).write_text(json.dumps(manifest, indent=2) + '\n')
    print(f'{len(every)} rows in {len(shards)} shards')
    return 0


if __name__ == '__main__':
    sys.exit(main())
