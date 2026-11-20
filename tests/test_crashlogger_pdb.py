"""tools/crashlogger_pdb.py on a tiny synthetic MSF file with invented names, and its contrib hook."""
from pathlib import Path
import shutil
import struct
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import contrib  # noqa: E402
import crashlogger_pdb as cp  # noqa: E402

BLOCK = 512
NO_STREAM = 0xFFFF


def build_msf(streams):
    blocks = [b'', bytes(BLOCK), bytes(BLOCK)]

    def add(data):
        out = []
        for start in range(0, len(data), BLOCK):
            out.append(len(blocks))
            blocks.append(data[start:start + BLOCK].ljust(BLOCK, b'\0'))
        return out
    indices = [add(s) for s in streams]
    directory = (struct.pack('<I', len(streams)) + b''.join(struct.pack('<I', len(s)) for s in streams)
                 + b''.join(struct.pack(f'<{len(i)}I', *i) for i in indices))
    dir_blocks = add(directory)
    map_block = len(blocks)
    blocks.append(struct.pack(f'<{len(dir_blocks)}I', *dir_blocks).ljust(BLOCK, b'\0'))
    blocks[0] = (cp.MSF_MAGIC + struct.pack('<6I', BLOCK, 1, len(blocks), len(directory), 0, map_block)).ljust(BLOCK, b'\0')
    return b''.join(blocks)


def pub32(name, segment, offset, flags=cp.PUB_CODE_OR_FUNCTION):
    body = struct.pack('<HIIH', cp.S_PUB32, flags, offset, segment) + name.encode() + b'\0'
    body += b'\0' * (-(len(body) + 2) % 4)
    return struct.pack('<H', len(body)) + body


def section_headers(*virtual_addresses):
    return b''.join(struct.pack('<8sIIIIIIHHI', b'.sec', 0x100, va, 0x100, 0, 0, 0, 0, 0, 0)
                    for va in virtual_addresses)


def dbi(sym_stream, header_stream=None):
    slots = b'' if header_stream is None else struct.pack('<6H', NO_STREAM, NO_STREAM, NO_STREAM, NO_STREAM,
                                                          NO_STREAM, header_stream)
    return cp.DBI_HEADER.pack(-1, 19990903, 1, NO_STREAM, 0, NO_STREAM, 0, sym_stream, 0, 0, 0, 0, 0, 0, 0,
                              len(slots), 0, 0, 0x8664, 0) + slots


RECORDS = b''.join([
    pub32('Fixture::Alpha', 1, 0x10),
    pub32('Fixture::Beta', 1, 0x200),
    pub32('Fixture::Gamma', 2, 0x30),
    pub32('Fixture::DataOnly', 1, 0x400, flags=0),
    pub32('Fixture::Nowhere', 99, 0x0),
])


def pdb_bytes(with_headers=True):
    streams = [b'', b'', b'', dbi(5, 6 if with_headers else None), b'', RECORDS,
               section_headers(0x1000, 0x9000) if with_headers else b'']
    return build_msf(streams)


class Base(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.tmp, ignore_errors=True)
        self.pdb = self.tmp / 'SkyrimSE.pdb'
        self.cache = self.tmp / 'cache' / 'publics.json'


class ReaderTests(Base):
    def test_section_headers_give_the_rvas(self):
        self.pdb.write_bytes(pdb_bytes())
        self.assertEqual(cp.read_publics(self.pdb), {0x1010: 'Fixture::Alpha', 0x1200: 'Fixture::Beta',
                                                     0x9030: 'Fixture::Gamma'})

    def test_without_section_headers_only_text_is_mapped(self):
        self.pdb.write_bytes(pdb_bytes(with_headers=False))
        self.assertEqual(cp.read_publics(self.pdb), {0x1010: 'Fixture::Alpha', 0x1200: 'Fixture::Beta'})

    def test_not_a_pdb_is_an_error(self):
        self.pdb.write_bytes(b'not a pdb' * 100)
        with self.assertRaises(cp.PdbError):
            cp.read_publics(self.pdb)

    def test_truncated_file_is_an_error(self):
        self.pdb.write_bytes(pdb_bytes()[:BLOCK * 5])
        with self.assertRaises(cp.PdbError):
            cp.read_publics(self.pdb)


class CacheTests(Base):
    def test_second_load_comes_from_the_cache(self):
        self.pdb.write_bytes(pdb_bytes())
        first = cp.load_publics(self.pdb, self.cache)
        self.assertTrue(self.cache.is_file())
        with mock.patch.object(cp, 'read_publics', side_effect=AssertionError('parsed again')):
            self.assertEqual(cp.load_publics(self.pdb, self.cache), first)

    def test_changed_file_is_parsed_again(self):
        self.pdb.write_bytes(pdb_bytes(with_headers=False))
        cp.load_publics(self.pdb, self.cache)
        self.pdb.write_bytes(pdb_bytes())
        self.assertIn(0x9030, cp.load_publics(self.pdb, self.cache))

    def test_missing_or_broken_file_is_silently_empty(self):
        self.assertEqual(cp.load_publics(self.pdb, self.cache), {})
        self.pdb.write_bytes(b'junk')
        self.assertEqual(cp.load_publics(self.pdb, self.cache), {})
        self.assertFalse(self.cache.exists())


class LabelTests(Base):
    def setUp(self):
        super().setUp()
        self.pdb.write_bytes(pdb_bytes())

    def test_version_from_the_environment(self):
        self.assertEqual(cp.label({cp.ENV_VERSION: '2026.10.24'}, self.pdb), 'CRASHLOGGER_PDB(59818@2026.10.24)')

    def test_version_from_the_file_beside_the_pdb(self):
        (self.tmp / cp.VERSION_FILE).write_text('2026.10.24\n')
        self.assertEqual(cp.label({}, self.pdb), 'CRASHLOGGER_PDB(59818@2026.10.24)')

    def test_unknown_or_invalid_version_stays_a_placeholder(self):
        self.assertEqual(cp.label({}, self.pdb), 'CRASHLOGGER_PDB(59818@<mod version>)')
        self.assertEqual(cp.label({cp.ENV_VERSION: 'a b)'}, self.pdb), 'CRASHLOGGER_PDB(59818@<mod version>)')

    def test_the_label_is_in_the_lint_grammar(self):
        import lint_reconstruction as lint
        line = f'// Fixture::Alpha: {cp.label({cp.ENV_VERSION: "2026.10.24"}, self.pdb)}'
        self.assertTrue(lint.LABEL_LINE.match(line))
        self.assertFalse(lint.LABEL_LINE.match(f'// Fixture::Alpha: {cp.label({}, self.pdb)}'))


COMMITTED = '# CRASHLOGGER_PDB(59818@2026.10.24)\n# rva, public name; RVAs 0x0-0xfffff\n0x1010\tCommitted::Alpha\n0x1400\tCommitted::Delta\n'


class OpenNamesTests(Base):
    def committed_repo(self, text=COMMITTED):
        repo = self.tmp / 'repo'
        names = repo / cp.GENERATED / cp.NAMES_DIR
        names.mkdir(parents=True)
        (names / '00.tsv').write_text(text)
        return repo

    def test_absent_pdb_does_nothing(self):
        self.assertIsNone(cp.open_names(self.tmp, {cp.ENV_PATH: str(self.pdb)}, self.cache))
        self.assertIsNone(cp.open_names(self.tmp, {'SR_LOCAL_DIR': str(self.tmp)}, self.cache))

    def test_env_path_override(self):
        self.pdb.write_bytes(pdb_bytes())
        names = cp.open_names(self.tmp, {cp.ENV_PATH: str(self.pdb)}, self.cache)
        found = names.suggest(0x1010)
        self.assertEqual((found.name, found.source), ('Fixture::Alpha', 'local'))
        self.assertIsNone(names.suggest(0x1011))

    def test_default_location_under_local(self):
        (self.tmp / 'pdb').mkdir()
        (self.tmp / 'pdb' / 'SkyrimSE.pdb').write_bytes(pdb_bytes())
        names = cp.open_names(self.tmp, {'SR_LOCAL_DIR': str(self.tmp)}, self.cache)
        self.assertEqual(names.suggest(0x1200).name, 'Fixture::Beta')

    def test_committed_map_alone(self):
        names = cp.open_names(self.committed_repo(), {}, self.cache)
        found = names.suggest(0x1400)
        self.assertEqual((found.name, found.label, found.source),
                         ('Committed::Delta', 'CRASHLOGGER_PDB(59818@2026.10.24)', 'committed'))
        self.assertIsNone(names.suggest(0x1401))
        self.assertIsNone(names.suggest(0x300000))

    def test_committed_map_wins_and_local_pdb_fills_the_gaps(self):
        self.pdb.write_bytes(pdb_bytes())
        env = {cp.ENV_PATH: str(self.pdb), cp.ENV_VERSION: '1.2.3'}
        names = cp.open_names(self.committed_repo(), env, self.cache)
        self.assertEqual(names.suggest(0x1010).name, 'Committed::Alpha')
        gap = names.suggest(0x1200)
        self.assertEqual((gap.name, gap.label, gap.source), ('Fixture::Beta', 'CRASHLOGGER_PDB(59818@1.2.3)', 'local'))

    def test_committed_shard_without_a_label_line_is_ignored(self):
        names = cp.open_names(self.committed_repo('0x1010\tNoLabel::Alpha\n'), {}, self.cache)
        self.assertIsNone(names.suggest(0x1010))

    def test_contrib_hook(self):
        self.pdb.write_bytes(pdb_bytes())
        ctx = contrib.Ctx(env={cp.ENV_PATH: str(self.pdb), cp.ENV_VERSION: '1.2.3'}, private=self.tmp / 'private',
                          interactive=False)
        found = contrib.pdb_names(ctx).suggest(0x9030)
        self.assertEqual((found.name, found.label), ('Fixture::Gamma', 'CRASHLOGGER_PDB(59818@1.2.3)'))
        self.assertTrue((self.tmp / 'private' / 'crashlogger_publics.json').is_file())


if __name__ == '__main__':
    unittest.main()
