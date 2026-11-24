#!/usr/bin/env python3
"""Prebuilt shape index of the x64 sibling builds: pack, verify, fetch and load.

The index holds one signature per function of the CC0 Fallout 3 / Fallout: New Vegas sources compiled
as x64 (docs/sibling-x64.md): the mnemonic stream, call count, large immediates and string literals.
It is built from compiled sibling code only. It carries no Skyrim bytes, results or addresses, so it is
published as a release asset of the two forks and downloaded by `setup`, which checks the SHA-256 pinned
in data/x64-index.json before anything reads it.

    x64_index.py pack  --sigs F.pkl --game fnv --fork-commit SHA --out OUT.json.gz   (maintainer side)
    x64_index.py verify FILE --game fnv                                              (checks the pin)
    x64_index.py fetch  [--game fnv|f3] [--dest DIR]                                 (download and verify)

`--sigs` is the pickle written by the maintainer's own `shape.py objsigs` run on the compiled objects;
it is read only by `pack`, never from a download.
"""
import argparse
import gzip
import hashlib
import io
import json
import re
import shutil
import sys
import urllib.error
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PINS = ROOT / 'data/x64-index.json'
FORMAT = 'sr-x64-shape-index'
VERSION = 1
GAMES = {
    'fnv': {'fork': 'awarebayes/fnv_decomp', 'source': 'momusdigital/fnv_decomp'},
    'f3': {'fork': 'awarebayes/f3_decomp', 'source': 'momusdigital/f3_decomp'},
}
COMPILER = 'MSVC 19.16.27054 x64 /O2 /MD /GS- /EHsc /GR /fp:precise /Gy'
MAX_BYTES = 200 * 1024 * 1024  # a download or an unpacked index larger than this is refused
MNEMONIC = re.compile(r'[A-Za-z0-9_.<> ]*')
SHA256 = re.compile(r'[0-9a-f]{64}')
SHORT_REV = re.compile(r'[0-9a-f]{8}')


class IndexError_(Exception):
    """The index file or its pin is unusable; the message says why."""


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def load_pins(path=PINS):
    data = json.loads(Path(path).read_text())
    if data.get('version') != VERSION or not isinstance(data.get('assets'), dict):
        raise IndexError_(f'{path} is not a version {VERSION} pin file')
    for game, pin in data['assets'].items():
        info = GAMES.get(game)
        if info is None:
            raise IndexError_(f'{path}: unknown game {game!r}')
        if pin.get('repo') != info['fork'] or not SHA256.fullmatch(pin.get('sha256', '')):
            raise IndexError_(f'{path}: the {game} pin names another repository or a bad SHA-256')
        if not re.fullmatch(r'[A-Za-z0-9._-]+', data.get('tag', '')) or not re.fullmatch(r'[A-Za-z0-9._-]+', pin.get('name', '')):
            raise IndexError_(f'{path}: tag or asset name has unexpected characters')
    return data


def asset_url(pins, game):
    pin = pins['assets'][game]
    return f'https://github.com/{pin["repo"]}/releases/download/{pins["tag"]}/{pin["name"]}'


def pack(sigs, game, fork_commit, source_rev):
    """Deterministic gzip of the signatures. `sigs` maps (object stem, symbol) to {mn, calls, imms, strs}."""
    if game not in GAMES:
        raise IndexError_(f'unknown game {game!r}')
    if not re.fullmatch(r'[0-9a-f]{40}', fork_commit) or not re.fullmatch(r'[0-9a-f]{40}', source_rev):
        raise IndexError_('fork and source revisions must be full 40-digit commit ids')
    functions = []
    for (unit, symbol), sig in sorted(sigs.items()):
        mn = ' '.join(sig['mn'])
        if not MNEMONIC.fullmatch(mn):
            raise IndexError_(f'unexpected characters in the mnemonics of {symbol}')
        functions.append({'u': unit, 's': symbol, 'mn': mn, 'c': int(sig['calls']),
                          'i': [int(v) for v in sig['imms']], 't': list(sig['strs'])})
    doc = {'format': FORMAT, 'version': VERSION, 'game': game,
           'source': f'{GAMES[game]["source"]}@{source_rev}', 'fork': f'{GAMES[game]["fork"]}@{fork_commit}',
           'compiler': COMPILER, 'functions': functions}
    raw = json.dumps(doc, sort_keys=True, separators=(',', ':')).encode()
    buf = io.BytesIO()
    with gzip.GzipFile(fileobj=buf, mode='wb', mtime=0, compresslevel=9) as gz:
        gz.write(raw)
    return buf.getvalue()


def unpack(path, game=None):
    """Signatures of an index file as {(unit, symbol): {mn, calls, imms, strs}}; refuses anything off-format."""
    with gzip.open(path, 'rb') as gz:
        raw = gz.read(MAX_BYTES + 1)
    if len(raw) > MAX_BYTES:
        raise IndexError_('the unpacked index is too large')
    doc = json.loads(raw)
    if doc.get('format') != FORMAT or doc.get('version') != VERSION:
        raise IndexError_('not a version 1 x64 shape index')
    if doc.get('game') not in GAMES or (game and doc['game'] != game):
        raise IndexError_('the index is for another game')
    out = {}
    for fn in doc['functions']:
        if set(fn) != {'u', 's', 'mn', 'c', 'i', 't'} or not isinstance(fn['mn'], str) or not MNEMONIC.fullmatch(fn['mn']):
            raise IndexError_('malformed function record')
        if not (isinstance(fn['c'], int) and all(isinstance(v, int) for v in fn['i'])
                and all(isinstance(v, str) for v in fn['t'])):
            raise IndexError_('malformed function record')
        out[(fn['u'], fn['s'])] = {'mn': fn['mn'].split(), 'calls': fn['c'], 'imms': fn['i'], 'strs': fn['t']}
    return out


def verify(path, game, pins=None):
    pins = pins or load_pins()
    pin = pins['assets'].get(game)
    if pin is None:
        raise IndexError_(f'no pinned index for {game}')
    digest = sha256_file(path)
    if digest != pin['sha256']:
        raise IndexError_(f'{Path(path).name} has SHA-256 {digest}, the pin is {pin["sha256"]}')
    return digest


def fetch(game, dest, pins=None, opener=None):
    """Download the pinned index of `game` into `dest`, verify it, and return its path.
    A file already there with the pinned hash is kept; one with another hash is replaced."""
    pins = pins or load_pins()
    opener = opener or urllib.request.urlopen
    pin = pins['assets'][game]
    dest = Path(dest)
    dest.mkdir(parents=True, exist_ok=True)
    target = dest / pin['name']
    if target.is_file() and sha256_file(target) == pin['sha256']:
        return target, False
    part = target.with_name(target.name + '.part')
    try:
        with opener(asset_url(pins, game), timeout=300) as resp, open(part, 'wb') as out:
            size = 0
            for chunk in iter(lambda: resp.read(1 << 20), b''):
                size += len(chunk)
                if size > MAX_BYTES:
                    raise IndexError_('the download is larger than any published index')
                out.write(chunk)
        verify(part, game, pins)
    except (urllib.error.URLError, OSError) as exc:
        part.unlink(missing_ok=True)
        raise IndexError_(f'cannot download the {game} index: {exc}') from exc
    except IndexError_:
        part.unlink(missing_ok=True)
        raise
    shutil.move(str(part), target)
    return target, True


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('pack')
    p.add_argument('--sigs', required=True, type=Path)
    p.add_argument('--game', required=True, choices=sorted(GAMES))
    p.add_argument('--fork-commit', required=True)
    p.add_argument('--source-rev', required=True)
    p.add_argument('--out', required=True, type=Path)
    p = sub.add_parser('verify')
    p.add_argument('file', type=Path)
    p.add_argument('--game', required=True, choices=sorted(GAMES))
    p = sub.add_parser('fetch')
    p.add_argument('--game', choices=sorted(GAMES))
    p.add_argument('--dest', type=Path, default=ROOT / '.local/x64-index')
    a = ap.parse_args(argv)
    try:
        if a.cmd == 'pack':
            import pickle  # maintainer-side input only: the pickle comes from the maintainer's own run
            data = pack(pickle.load(open(a.sigs, 'rb')), a.game, a.fork_commit, a.source_rev)
            a.out.write_bytes(data)
            print(f'{a.out.name}: {len(data)} bytes, sha256 {hashlib.sha256(data).hexdigest()}')
        elif a.cmd == 'verify':
            print(verify(a.file, a.game))
        else:
            pins = load_pins()
            for game in ([a.game] if a.game else sorted(pins['assets'])):
                path, fresh = fetch(game, a.dest, pins)
                print(f'{game}: {"downloaded" if fresh else "present"} {path}')
    except (IndexError_, OSError, ValueError) as exc:
        print(f'error: {exc}', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
