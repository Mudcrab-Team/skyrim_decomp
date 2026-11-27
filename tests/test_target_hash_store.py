import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import target_hash_store as store  # noqa: E402


def row(rva, size=16, extraction='linked-reference-inference', n='a', l='b'):
    return dict(rva=rva, size=size, normalized_sha256=n * 64, layout_sha256=l * 64, extraction=extraction)


class TargetHashStoreTests(unittest.TestCase):
    def test_rows_round_trip_sorted_with_hex_digests(self):
        rows = [row(0x2000, extraction='unmasked-unsupported'), row(0x1000, n='c', l='d')]
        blob = store.encode(rows)
        self.assertEqual(len(blob), store.HEADER.size + 2 * store.ROW.size)
        self.assertEqual(store.rows(blob), sorted(rows, key=lambda r: r['rva']))
        self.assertEqual(store.facts(blob), [(0x1000, 16, 0), (0x2000, 16, 1)])

    def test_a_json_shard_still_loads(self):
        blob = json.dumps({'functions': [row(7)]}).encode()
        self.assertEqual(store.rows(blob), [row(7)])
        self.assertEqual(store.facts(blob), [(7, 16, 0)])

    def test_malformed_input_is_refused(self):
        good = store.encode([row(1)])
        for bad in (good[:-1], good + b'\0', b'SRTH', b'SRTH\x02' + good[5:], good[:5] + b'\x09\0\0\0' + good[9:]):
            with self.assertRaises(ValueError):
                store.rows(bad)
        for bad in (dict(row(1), extraction='made-up'), dict(row(1), size=0), dict(row(1), normalized_sha256='zz'),
                    dict(row(1), extra=1), dict(row(-1))):
            with self.assertRaises(ValueError):
                store.encode([bad])

    def test_shards_split_by_range_and_names_match_the_scan_pattern(self):
        self.assertEqual(store.shard_index(0xFFFFF), 0)
        self.assertEqual(store.shard_index(0x100000), 1)
        name = 'data/target-hashes/' + store.shard_name('sse-steam-1-7-104', 3)
        self.assertTrue(store.BINARY.fullmatch(name))
        self.assertTrue(store.SHARD.fullmatch(name))

    def test_dump_prints_the_rows(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'x.thb'
            path.write_bytes(store.encode([row(5)]))
            import contextlib
            import io
            out = io.StringIO()
            with contextlib.redirect_stdout(out):
                self.assertEqual(store.main(['dump', str(path)]), 0)
            self.assertEqual(json.loads(out.getvalue())['functions'], [row(5)])


if __name__ == '__main__':
    unittest.main()
