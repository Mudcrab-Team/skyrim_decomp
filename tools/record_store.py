"""Match records, Reviewer records and unit symbol maps, stored as xz shards beside loose files.

One file per record made `reports/` about 115k files. The per-function records now live in
`reports/<build>/packs/<kind>-<shard>.xz`, each shard a sorted JSON object mapping a record's
name (its path below `reports/<build>/`) to the record's exact text. The text is kept byte for
byte, so every hash that binds a record or a symbol map still holds.

A loose file with the same name overrides the packed copy. Writers keep writing loose files and
`pack` folds them into the shards, so a tree is valid before and after packing and an unpacked
fixture tree in a test needs no pack at all. Every reader goes through `read_bytes`, `read_text`,
`is_file` and `names`; nothing outside this module should open a record path directly.

    python3 tools/record_store.py pack [--root DIR]      fold loose records into shards
    python3 tools/record_store.py unpack [--root DIR]    write every record out as a loose file
    python3 tools/record_store.py verify [--root DIR]    shards are canonical, no loose duplicates
    python3 tools/record_store.py dump NAME [--root DIR] print one record
"""
import argparse
from collections import OrderedDict
import json
import lzma
import os
from pathlib import Path
import re
import sys

PACKS = 'packs'
MATCH = re.compile(r'0x([0-9a-f]+)\.json')
REVIEW = re.compile(r'0x([0-9a-f]+)\.review\.json')
SYMBOLS = re.compile(r'unit-symbols/([0-9a-f]{64})(\.history)?\.json')
# 0x10000 RVA ranges for the per-function kinds. Symbol maps are named by digest, so the first
# two hex digits spread them over 256 shards of a few hundred entries.
CACHE_SHARDS = 64
_cache = OrderedDict()


def shard_of(name):
    """(kind, shard) for a record name below `reports/<build>/`, or None for a plain file."""
    for kind, pattern in (('review', REVIEW), ('match', MATCH), ('sym', SYMBOLS)):
        m = pattern.fullmatch(name)
        if m:
            if kind == 'sym':
                return kind, m.group(1)[:2]
            return kind, f'{int(m.group(1), 16) >> 16:03x}'
    return None


def pack_path(build_dir, name):
    found = shard_of(name)
    return None if found is None else Path(build_dir) / PACKS / f'{found[0]}-{found[1]}.xz'


def split(path):
    """(build directory, record name) when `path` is a record path, else None."""
    path = Path(path)
    for parent in path.parents:
        if parent.parent.name == 'reports':
            name = path.relative_to(parent).as_posix()
            return (parent, name) if shard_of(name) else None
    return None


def is_pack_name(name):
    """True for a path like reports/<build>/packs/<kind>-<shard>.xz."""
    return re.fullmatch(r'reports/[a-z0-9][a-z0-9-]*/packs/(?:match|review)-[0-9a-f]{3}\.xz|'
                        r'reports/[a-z0-9][a-z0-9-]*/packs/sym-[0-9a-f]{2}\.xz', name) is not None


def expand_payload(name, payload):
    """(virtual path, text) for every entry of a shard blob, so scanners judge each record itself."""
    entries = json.loads(lzma.decompress(payload).decode())
    build = name.rsplit('/', 2)[0]
    out = []
    for entry, text in entries.items():
        if not isinstance(text, str) or shard_of(entry) is None or \
                f'{build}/{PACKS}/{"-".join(shard_of(entry))}.xz' != name:
            raise ValueError(f'{name}: entry {entry!r} does not belong in this shard')
        out.append((f'{build}/{entry}', text))
    return out


def encode(entries):
    text = json.dumps(dict(sorted(entries.items())), separators=(',', ':'), ensure_ascii=False)
    # Fixed preset and no check variation keep a repack of unchanged entries byte-identical.
    return lzma.compress(text.encode(), format=lzma.FORMAT_XZ, check=lzma.CHECK_CRC32, preset=6)


def load_shard(path):
    """Entries of one shard, cached while the file is unchanged."""
    path = Path(path)
    try:
        st = path.stat()
    except FileNotFoundError:
        return {}
    stamp = (st.st_mtime_ns, st.st_size, st.st_ino)
    hit = _cache.get(path)
    if hit is not None and hit[0] == stamp:
        _cache.move_to_end(path)
        return hit[1]
    entries = json.loads(lzma.decompress(path.read_bytes()).decode())
    _cache[path] = (stamp, entries)
    while len(_cache) > CACHE_SHARDS:
        _cache.popitem(last=False)
    return entries


def read_bytes(path):
    path = Path(path)
    try:
        return path.read_bytes()
    except FileNotFoundError:
        found = split(path)
        if found is not None:
            text = load_shard(pack_path(*found)).get(found[1])
            if text is not None:
                return text.encode()
        raise


def read_text(path):
    return read_bytes(path).decode()


def is_file(path):
    path = Path(path)
    if path.is_file():
        return True
    found = split(path)
    return found is not None and found[1] in load_shard(pack_path(*found))


exists = is_file


def names(build_dir, kind=None):
    """Sorted record names of a build, loose and packed, optionally one of match/review/history/sym."""
    build_dir = Path(build_dir)
    out = set()
    packs = build_dir / PACKS
    if packs.is_dir():
        for pack in packs.glob('*.xz'):
            out.update(load_shard(pack))
    if build_dir.is_dir():
        for entry in build_dir.iterdir():
            if shard_of(entry.name):
                out.add(entry.name)
        symbols = build_dir / 'unit-symbols'
        if symbols.is_dir():
            out.update(f'unit-symbols/{entry.name}' for entry in symbols.iterdir()
                       if shard_of(f'unit-symbols/{entry.name}'))
    return sorted(n for n in out if kind is None or _kind(n) == kind)


def _kind(name):
    if REVIEW.fullmatch(name):
        return 'review'
    if MATCH.fullmatch(name):
        return 'match'
    return 'history' if name.endswith('.history.json') else 'symbols'


def build_dirs(root):
    reports = Path(root) / 'reports'
    return sorted(p for p in reports.iterdir() if p.is_dir()) if reports.is_dir() else []


def remove(path):
    """Delete a record from the loose files and from its shard."""
    path = Path(path)
    path.unlink(missing_ok=True)
    found = split(path)
    if found is None:
        return
    pack = pack_path(*found)
    entries = dict(load_shard(pack))
    if entries.pop(found[1], None) is not None:
        _write_pack(pack, entries)


def _write_pack(pack, entries):
    pack = Path(pack)
    if entries:
        pack.parent.mkdir(parents=True, exist_ok=True)
        tmp = pack.with_name(pack.name + '.tmp')
        tmp.write_bytes(encode(entries))
        os.replace(tmp, pack)
    else:
        pack.unlink(missing_ok=True)
    _cache.pop(pack, None)


def pack_build(build_dir, keep_loose=False):
    """Fold the loose records of one build into its shards; returns (records, shards touched)."""
    build_dir = Path(build_dir)
    loose = {}
    for entry in build_dir.iterdir() if build_dir.is_dir() else []:
        if shard_of(entry.name) and entry.is_file():
            loose[entry.name] = entry
    symbols = build_dir / 'unit-symbols'
    for entry in symbols.iterdir() if symbols.is_dir() else []:
        name = f'unit-symbols/{entry.name}'
        if shard_of(name) and entry.is_file():
            loose[name] = entry
    groups = {}
    for name, entry in loose.items():
        groups.setdefault(pack_path(build_dir, name), {})[name] = entry
    for pack, files in groups.items():
        entries = dict(load_shard(pack))
        for name, entry in files.items():
            entries[name] = entry.read_bytes().decode()
        _write_pack(pack, entries)
    if not keep_loose:
        for entry in loose.values():
            entry.unlink()
        if symbols.is_dir() and not any(symbols.iterdir()):
            symbols.rmdir()
    return len(loose), len(groups)


def fold(root, rel_names):
    """Fold the loose files among repo-relative `rel_names` into their shards.

    Returns the repo-relative paths to commit in place of those files: the shards they went into
    plus every name that is not a record. A loose file that equals its packed copy is dropped
    without touching the shard, so re-recording identical evidence leaves the tree unchanged.
    """
    root = Path(root)
    out, groups = [], {}
    for rel in rel_names:
        found = split(root / rel)
        if found is None:
            out.append(rel)
        else:
            groups.setdefault(found[0], []).append(found[1])
    for build, names_ in groups.items():
        by_pack = {}
        for name in names_:
            by_pack.setdefault(pack_path(build, name), []).append(name)
        for pack, group in by_pack.items():
            entries = dict(load_shard(pack))
            changed = False
            for name in group:
                loose = build / name
                if loose.is_file():
                    text = loose.read_bytes().decode()
                    if entries.get(name) != text:
                        entries[name] = text
                        changed = True
                    loose.unlink()
            if changed:
                _write_pack(pack, entries)
            out.append(pack.relative_to(root).as_posix())
    return list(dict.fromkeys(out))


def unpack_build(build_dir):
    build_dir = Path(build_dir)
    count = 0
    for pack in sorted((build_dir / PACKS).glob('*.xz')):
        for name, text in load_shard(pack).items():
            out = build_dir / name
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_bytes(text.encode())
            count += 1
        pack.unlink()
    return count


def verify_build(build_dir):
    """Problems: non-canonical shards, entries in the wrong shard, loose copies that differ."""
    build_dir = Path(build_dir)
    problems = []
    for pack in sorted((build_dir / PACKS).glob('*.xz')):
        try:
            entries = load_shard(pack)
        except (OSError, ValueError, lzma.LZMAError) as exc:
            problems.append(f'{pack.name}: unreadable ({exc})')
            continue
        for name, text in entries.items():
            if pack_path(build_dir, name) != pack:
                problems.append(f'{pack.name}: {name} belongs in another shard')
            elif not isinstance(text, str):
                problems.append(f'{pack.name}: {name} is not text')
            loose = build_dir / name
            if loose.is_file() and loose.read_bytes().decode() != text:
                problems.append(f'{name}: loose file overrides a different packed copy; run pack')
    return problems


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('command', choices=['pack', 'unpack', 'verify', 'dump'])
    ap.add_argument('name', nargs='?')
    ap.add_argument('--root', type=Path, default=Path(__file__).resolve().parent.parent)
    args = ap.parse_args(argv)
    if args.command == 'dump':
        if not args.name:
            ap.error('dump needs a record name or path')
        sys.stdout.write(read_text(args.root / args.name))
        return 0
    bad = False
    for build in build_dirs(args.root):
        if args.command == 'pack':
            print(f'{build.name}: packed {pack_build(build)[0]} loose records')
        elif args.command == 'unpack':
            print(f'{build.name}: unpacked {unpack_build(build)} records')
        else:
            problems = verify_build(build)
            bad |= bool(problems)
            print('\n'.join(problems) or f'{build.name}: ok')
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
