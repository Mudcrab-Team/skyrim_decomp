import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import record_store as rs  # noqa: E402

DIGEST = 'ab' * 32


class RecordStoreTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.build = self.root / 'reports' / 'b1'
        self.files = {
            '0x1000.json': '{"a": 1}\n',
            '0x1000.review.json': '{"r": 1}\n',
            '0x20000.json': '{"b": 2}\n',
            f'unit-symbols/{DIGEST}.json': '{"s": 1}\n',
            f'unit-symbols/{DIGEST}.history.json': '{"h": 1}\n',
        }
        for name, text in self.files.items():
            path = self.build / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
        (self.build / 'symbol-map.json').write_text('{}\n')

    def test_names_map_to_shards_by_rva_range_and_digest_prefix(self):
        self.assertEqual(rs.shard_of('0x1000.json'), ('match', '000'))
        self.assertEqual(rs.shard_of('0x20000.json'), ('match', '002'))
        self.assertEqual(rs.shard_of('0x1000.review.json'), ('review', '000'))
        self.assertEqual(rs.shard_of(f'unit-symbols/{DIGEST}.history.json'), ('sym', 'ab'))
        self.assertIsNone(rs.shard_of('symbol-map.json'))
        self.assertIsNone(rs.shard_of('0x73ad90-recheck-cases.json'))

    def test_pack_keeps_text_byte_for_byte_and_leaves_other_files(self):
        rs.pack_build(self.build)
        self.assertFalse((self.build / '0x1000.json').exists())
        self.assertTrue((self.build / 'symbol-map.json').is_file())
        for name, text in self.files.items():
            self.assertEqual(rs.read_bytes(self.build / name), text.encode())
        self.assertEqual(rs.verify_build(self.build), [])
        self.assertEqual(len(list((self.build / 'packs').glob('*.xz'))), 4)

    def test_loose_file_overrides_its_shard_and_fold_replaces_it(self):
        rs.pack_build(self.build)
        (self.build / '0x1000.json').write_text('{"a": 2}\n')
        self.assertEqual(json.loads(rs.read_text(self.build / '0x1000.json')), {'a': 2})
        out = rs.fold(self.root, ['reports/b1/0x1000.json', 'data/progress.json'])
        self.assertEqual(sorted(out), ['data/progress.json', 'reports/b1/packs/match-000.xz'])
        self.assertFalse((self.build / '0x1000.json').exists())
        self.assertEqual(json.loads(rs.read_text(self.build / '0x1000.json')), {'a': 2})

    def test_fold_of_identical_text_leaves_the_shard_untouched(self):
        rs.pack_build(self.build)
        pack = self.build / 'packs/match-000.xz'
        before = pack.read_bytes()
        (self.build / '0x1000.json').write_text(self.files['0x1000.json'])
        rs.fold(self.root, ['reports/b1/0x1000.json'])
        self.assertEqual(pack.read_bytes(), before)

    def test_remove_drops_the_record_from_the_shard_and_empty_shards_vanish(self):
        rs.pack_build(self.build)
        rs.remove(self.build / '0x20000.json')
        self.assertFalse(rs.is_file(self.build / '0x20000.json'))
        self.assertFalse((self.build / 'packs/match-002.xz').exists())
        self.assertTrue(rs.is_file(self.build / '0x1000.json'))

    def test_names_lists_loose_and_packed_once(self):
        rs.pack_build(self.build)
        (self.build / '0x30000.json').write_text('{}\n')
        self.assertEqual(rs.names(self.build, 'match'), ['0x1000.json', '0x20000.json', '0x30000.json'])
        self.assertEqual(rs.names(self.build, 'review'), ['0x1000.review.json'])
        self.assertEqual(rs.names(self.build, 'history'), [f'unit-symbols/{DIGEST}.history.json'])

    def test_unpack_restores_the_loose_layout(self):
        rs.pack_build(self.build)
        self.assertEqual(rs.unpack_build(self.build), len(self.files))
        for name, text in self.files.items():
            self.assertEqual((self.build / name).read_text(), text)
        self.assertFalse(list((self.build / 'packs').glob('*.xz')))

    def test_missing_record_raises_file_not_found(self):
        with self.assertRaises(FileNotFoundError):
            rs.read_bytes(self.build / '0x999.json')
        self.assertFalse(rs.is_file(self.build / '0x999.json'))

    def test_a_shard_entry_in_the_wrong_shard_is_refused_by_the_scanner_hook(self):
        rs.pack_build(self.build)
        payload = (self.build / 'packs/match-000.xz').read_bytes()
        self.assertEqual([n for n, _ in rs.expand_payload('reports/b1/packs/match-000.xz', payload)],
                         ['reports/b1/0x1000.json'])
        with self.assertRaises(ValueError):
            rs.expand_payload('reports/b1/packs/match-001.xz', payload)
        self.assertTrue(rs.is_pack_name('reports/b1/packs/sym-ab.xz'))
        self.assertFalse(rs.is_pack_name('reports/b1/packs/other.xz'))


if __name__ == '__main__':
    unittest.main()
