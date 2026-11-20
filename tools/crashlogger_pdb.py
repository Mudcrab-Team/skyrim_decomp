"""Name hints from the CrashLogger PDB (Nexus mod 59818), committed output first, local PDB second.

The maintainer authorised that community-generated PDB as a naming source (docs/authorizations.md,
Notes). Its generated output lives in reconstruction/generated/crashlogger_pdb/ (tools/pdb_types.py
writes it): `names/<NN>.tsv` maps an RVA to a public name, one file per MiB of RVA, first line
`# CRASHLOGGER_PDB(59818@<version>)`. `./sr next` and `./sr start` show the name at an RVA as a
suggestion, read from that committed map when it exists and, for an RVA it lacks, from a local
PDB under `.local/pdb/SkyrimSE.pdb` (or SR_CRASHLOGGER_PDB) for someone who has downloaded one. A
name taken from either is labelled `CRASHLOGGER_PDB(59818@<version>)`; it is a name source, not
evidence of what the function is.

The local reader is a pure-Python walk of the MSF container: DBI stream -> symbol record stream ->
S_PUB32 records, mapped to RVAs through the section headers (or, for a PDB without them, section 1
as `.text` at 0x1000). Everything is silent when a source is missing or unreadable. The parsed
local table is cached in the contributor's private directory, never in the repository.
"""
import json
import re
import struct
from pathlib import Path

from local_paths import local_path

DEFAULT_PDB = '.local/pdb/SkyrimSE.pdb'
ENV_PATH = 'SR_CRASHLOGGER_PDB'
ENV_VERSION = 'SR_CRASHLOGGER_PDB_VERSION'
VERSION_FILE = 'version.txt'
VERSION_PATTERN = re.compile(r'[0-9A-Za-z][0-9A-Za-z.+-]*')
PLACEHOLDER_VERSION = '<mod version>'
MODULE_ID = '59818'
GENERATED = 'reconstruction/generated/crashlogger_pdb'
NAMES_DIR = 'names'
SHARD_BITS = 20
COMMITTED_LABEL = re.compile(r'#\s*(CRASHLOGGER_PDB\(59818@[0-9A-Za-z][0-9A-Za-z.+-]*\))')

MSF_MAGIC = b'Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0'
DBI_STREAM = 3
DBI_HEADER = struct.Struct('<iIIHHHHHHiiiiiIiiHHI')
S_PUB32 = 0x110E
PUB_CODE_OR_FUNCTION = 0x3
SECTION_HEADER_STREAM_SLOT = 5
NO_STREAM = 0xFFFF
SECTION_HEADER_SIZE = 40
FALLBACK_SECTIONS = {1: 0x1000}


class PdbError(ValueError):
    pass


def _stream_reader(data):
    """read(index) -> bytes of one MSF stream."""
    if data[:len(MSF_MAGIC)] != MSF_MAGIC:
        raise PdbError('not an MSF 7.00 file')
    block, _free, _count, dir_bytes, _unused, map_addr = struct.unpack_from('<6I', data, 32)
    if block not in (512, 1024, 2048, 4096):
        raise PdbError('bad block size')

    def gather(indices, size):
        out = b''.join(data[i * block:(i + 1) * block] for i in indices)
        if len(out) < size:
            raise PdbError('stream runs past the file')
        return out[:size]

    dir_blocks = -(-dir_bytes // block)
    listed = struct.unpack_from(f'<{dir_blocks}I', data, map_addr * block)
    directory = gather(listed, dir_bytes)
    (count,) = struct.unpack_from('<I', directory, 0)
    sizes = struct.unpack_from(f'<{count}I', directory, 4)
    pos, streams = 4 + 4 * count, []
    for size in sizes:
        size = 0 if size == 0xFFFFFFFF else size
        n = -(-size // block)
        streams.append((size, struct.unpack_from(f'<{n}I', directory, pos)))
        pos += 4 * n

    def read(index):
        if index >= len(streams):
            raise PdbError('missing stream')
        size, indices = streams[index]
        return gather(indices, size)
    return read


def read_publics(path):
    """{rva: name} for the public symbols that are code; PdbError when the file cannot be read."""
    try:
        return _read_publics(Path(path).read_bytes())
    except (struct.error, IndexError, OverflowError, MemoryError) as exc:
        raise PdbError(str(exc)) from None


def _read_publics(data):
    read = _stream_reader(data)
    dbi = read(DBI_STREAM)
    fields = DBI_HEADER.unpack_from(dbi, 0)
    sym_stream = fields[7]
    mod, contrib, section_map, source, type_server, ec = (fields[i] for i in (9, 10, 11, 12, 13, 16))
    optional = fields[15]
    sections = dict(FALLBACK_SECTIONS)
    if optional >= 2 * (SECTION_HEADER_STREAM_SLOT + 1):
        start = DBI_HEADER.size + mod + contrib + section_map + source + type_server + ec
        slots = struct.unpack_from(f'<{optional // 2}H', dbi, start)
        if slots[SECTION_HEADER_STREAM_SLOT] != NO_STREAM:
            headers = read(slots[SECTION_HEADER_STREAM_SLOT])
            sections = {i + 1: struct.unpack_from('<I', headers, i * SECTION_HEADER_SIZE + 12)[0]
                        for i in range(len(headers) // SECTION_HEADER_SIZE)}
    if sym_stream == NO_STREAM:
        raise PdbError('no symbol record stream')
    symbols = read(sym_stream)
    names, pos = {}, 0
    while pos + 4 <= len(symbols):
        length, kind = struct.unpack_from('<HH', symbols, pos)
        end = pos + 2 + length
        if length < 2:
            break
        if kind == S_PUB32 and length >= 2 + 4 + 4 + 2 + 1:
            flags, offset, segment = struct.unpack_from('<IIH', symbols, pos + 4)
            if flags & PUB_CODE_OR_FUNCTION and segment in sections:
                name = symbols[pos + 14:end].split(b'\0', 1)[0].decode('utf-8', 'replace')
                names.setdefault(sections[segment] + offset, name)
        pos = end
    return names


def load_publics(path, cache):
    """read_publics through a cache keyed by the file's size and mtime; {} when unreadable."""
    path = Path(path)
    try:
        stat = path.stat()
    except OSError:
        return {}
    key = [stat.st_size, stat.st_mtime_ns]
    try:
        cached = json.loads(Path(cache).read_text())
        if cached.get('key') == key:
            return {int(rva, 16): name for rva, name in cached['publics'].items()}
    except (OSError, ValueError, KeyError, AttributeError):
        pass
    try:
        names = read_publics(path)
    except (OSError, PdbError):
        return {}
    try:
        Path(cache).parent.mkdir(parents=True, exist_ok=True)
        Path(cache).write_text(json.dumps({'key': key, 'publics': {f'{r:x}': n for r, n in names.items()}}))
    except OSError:
        pass
    return names


def label(env, pdb_path):
    """The provenance label for a name from this PDB; the version comes from the environment or a
    `version.txt` beside the file, else a placeholder the contributor must replace."""
    version = (env.get(ENV_VERSION) or '').strip()
    if not version:
        try:
            version = (Path(pdb_path).parent / VERSION_FILE).read_text().strip()
        except OSError:
            version = ''
    if not VERSION_PATTERN.fullmatch(version):
        version = PLACEHOLDER_VERSION
    return f'CRASHLOGGER_PDB({MODULE_ID}@{version})'


class Suggestion:
    """A name, the label to use for it and where it came from ('committed' or 'local')."""
    __slots__ = ('name', 'label', 'source')

    def __init__(self, name, label, source):
        self.name, self.label, self.source = name, label, source


class Names:
    def __init__(self, repo, publics, local_label):
        self.dir = Path(repo) / GENERATED / NAMES_DIR
        self.publics, self.local_label = publics or {}, local_label
        self.shards = {}

    def committed(self, rva):
        """(name, label) from the committed names map, or None."""
        shard = rva >> SHARD_BITS
        if shard not in self.shards:
            table, tag = {}, None
            try:
                for line in (self.dir / f'{shard:02x}.tsv').read_text(encoding='utf-8').splitlines():
                    if line.startswith('#'):
                        tag = tag or (COMMITTED_LABEL.match(line) or [None, None])[1]
                        continue
                    key, _, name = line.partition('\t')
                    if name:
                        table[int(key, 16)] = name
            except (OSError, ValueError):
                table, tag = {}, None
            self.shards[shard] = (table, tag)
        table, tag = self.shards[shard]
        return (table[rva], tag) if rva in table and tag else None

    def suggest(self, rva):
        """The committed name for an RVA, else the local PDB's; None when neither knows it."""
        found = self.committed(rva)
        if found:
            return Suggestion(found[0], found[1], 'committed')
        if rva in self.publics:
            return Suggestion(self.publics[rva], self.local_label, 'local')
        return None


def open_names(repo, env, cache):
    """Names from the committed map and/or a local PDB, or None (silently) when there is neither."""
    publics, tag = {}, None
    override = env.get(ENV_PATH)
    try:
        path = Path(override).expanduser() if override else local_path(repo, DEFAULT_PDB, env)
    except ValueError:
        path = None
    if path is not None and path.is_file():
        publics = load_publics(path, cache)
        tag = label(env, path)
    if not publics and not (Path(repo) / GENERATED / NAMES_DIR).is_dir():
        return None
    return Names(repo, publics, tag)
