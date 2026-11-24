import gzip
import io
import json
import sys
import tempfile
import unittest
import urllib.error
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import x64_index  # noqa: E402

SIGS = {('unit_a', '?f@@YAXXZ'): {'mn': ['mov', 'call', 'ret'], 'calls': 1, 'imms': [4096], 'strs': ['hello']},
        ('unit_a', '?g@@YAXXZ'): {'mn': ['xor', 'ret', '<unknown>'], 'calls': 0, 'imms': [], 'strs': []}}
REV = 'a' * 40


class Resp(io.BytesIO):
    def __enter__(self):
        return self

    def __exit__(self, *a):
        return False


def pins_for(blob, game='fnv'):
    import hashlib
    return {'version': 1, 'tag': 'x64-index-v1', 'assets': {game: {
        'repo': x64_index.GAMES[game]['fork'], 'name': 'idx.json.gz', 'sha256': hashlib.sha256(blob).hexdigest()}}}


class IndexTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = Path(self.tmp.name)

    def tearDown(self):
        self.tmp.cleanup()

    def test_pack_roundtrip_and_determinism(self):
        blob = x64_index.pack(SIGS, 'fnv', REV, REV)
        self.assertEqual(blob, x64_index.pack(dict(reversed(list(SIGS.items()))), 'fnv', REV, REV))
        (self.dir / 'i.gz').write_bytes(blob)
        self.assertEqual(x64_index.unpack(self.dir / 'i.gz', 'fnv'), SIGS)
        with self.assertRaises(x64_index.IndexError_):
            x64_index.unpack(self.dir / 'i.gz', 'f3')

    def test_pack_refuses_odd_mnemonics_and_short_revisions(self):
        with self.assertRaises(x64_index.IndexError_):
            x64_index.pack({('u', 's'): {'mn': ['mov;rm'], 'calls': 0, 'imms': [], 'strs': []}}, 'fnv', REV, REV)
        with self.assertRaises(x64_index.IndexError_):
            x64_index.pack(SIGS, 'fnv', 'abc', REV)

    def test_unpack_refuses_foreign_documents(self):
        for doc in ({'format': 'other', 'version': 1}, {'format': x64_index.FORMAT, 'version': 2}):
            with gzip.open(self.dir / 'bad.gz', 'wb') as fh:
                fh.write(json.dumps(doc).encode())
            with self.assertRaises(x64_index.IndexError_):
                x64_index.unpack(self.dir / 'bad.gz')

    def test_fetch_verifies_the_pinned_hash(self):
        blob = x64_index.pack(SIGS, 'fnv', REV, REV)
        pins = pins_for(blob)
        path, fresh = x64_index.fetch('fnv', self.dir, pins, opener=lambda url, timeout: Resp(blob))
        self.assertTrue(fresh)
        self.assertEqual(path.read_bytes(), blob)
        again, fresh = x64_index.fetch('fnv', self.dir, pins, opener=lambda *a, **k: self.fail('downloaded twice'))
        self.assertFalse(fresh)

    def test_fetch_refuses_a_tampered_download_and_leaves_nothing(self):
        blob = x64_index.pack(SIGS, 'fnv', REV, REV)
        with self.assertRaises(x64_index.IndexError_):
            x64_index.fetch('fnv', self.dir, pins_for(blob), opener=lambda url, timeout: Resp(blob + b'x'))
        self.assertEqual(list(self.dir.iterdir()), [])

    def test_fetch_reports_network_failure(self):
        def offline(url, timeout):
            raise urllib.error.URLError('offline')
        with self.assertRaises(x64_index.IndexError_):
            x64_index.fetch('fnv', self.dir, pins_for(b'x'), opener=offline)

    def test_tracked_pins_are_well_formed(self):
        pins = x64_index.load_pins()
        self.assertEqual(set(pins['assets']), {'fnv', 'f3'})
        for game in pins['assets']:
            self.assertTrue(x64_index.asset_url(pins, game).startswith(f'https://github.com/{x64_index.GAMES[game]["fork"]}/releases/download/'))

    def test_pin_file_with_another_repository_is_refused(self):
        bad = self.dir / 'p.json'
        pins = pins_for(b'x')
        pins['assets']['fnv']['repo'] = 'someone/else'
        bad.write_text(json.dumps(pins))
        with self.assertRaises(x64_index.IndexError_):
            x64_index.load_pins(bad)

    def test_setup_step_downloads_both_games_and_reports_network_failure(self):
        import contrib
        from types import SimpleNamespace
        from unittest import mock
        ctx = SimpleNamespace(repo=ROOT, private=self.dir, cli='./sr')
        blobs = {}

        def fake_fetch(game, dest, pins=None, opener=None):
            blobs[game] = dest
            return Path(dest) / game, True
        with mock.patch.object(x64_index, 'fetch', fake_fetch):
            detail = contrib.fetch_x64_index(ctx)
        self.assertEqual(sorted(blobs), ['f3', 'fnv'])
        self.assertIn('SHA-256 verified', detail)
        with mock.patch.object(x64_index, 'fetch', side_effect=x64_index.IndexError_('offline')):
            with self.assertRaises(contrib.Stop):
                contrib.fetch_x64_index(ctx)


if __name__ == '__main__':
    unittest.main()
