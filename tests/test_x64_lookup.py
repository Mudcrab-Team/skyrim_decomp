import hashlib
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import x64_index  # noqa: E402
import x64_lookup  # noqa: E402

REV = 'b' * 40
MN = ['push', 'sub', 'lea', 'mov', 'mov', 'test', 'je', 'mov', 'call', 'add', 'pop', 'ret']
SIGS = {('src_toy_thing', '?Run@Thing@@QEAAXXZ'): {'mn': MN, 'calls': 1, 'imms': [24, 32], 'strs': ['hello']},
        ('src_toy_other', '?Walk@Other@@QEAAXXZ'): {'mn': ['xor', 'ret'] * 6, 'calls': 0, 'imms': [], 'strs': []}}
FN = {'rva': 0x1000, 'size': 64}


def make_index(dest):
    blob = x64_index.pack(SIGS, 'fnv', REV, REV)
    name = 'idx.json.gz'
    (dest / name).write_bytes(blob)
    pins = {'version': 1, 'tag': 'x64-index-v1', 'assets': {'fnv': {
        'repo': x64_index.GAMES['fnv']['fork'], 'name': name, 'sha256': hashlib.sha256(blob).hexdigest(),
        'source': f'momusdigital/fnv_decomp@{REV}'}}}
    (dest / 'pins.json').write_text(json.dumps(pins))
    return dest / 'pins.json'


class LookupTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = Path(self.tmp.name)
        x64_lookup._loaded.clear()
        x64_lookup._files.clear()
        self.exe = self.dir / 'exe'
        self.exe.write_bytes(b'MZ')

    def tearDown(self):
        self.tmp.cleanup()

    def run_hints(self, sig, objdump='objdump', index=None):
        pins = make_index(self.dir)
        with mock.patch.object(x64_lookup, 'target_signature', return_value=sig):
            return x64_lookup.hints(index or self.dir, pins, self.dir / 'sources', objdump, self.exe, [FN])

    def test_exact_shape_hit_points_at_the_transplant_tool(self):
        src = self.dir / 'sources/fnv_decomp/src'
        src.mkdir(parents=True)
        (src / 'toy_thing.cpp').write_text('void Thing::Run()\n{\n}\n')
        sig = dict(SIGS[('src_toy_thing', '?Run@Thing@@QEAAXXZ')])
        record, lines = self.run_hints(sig)
        cand = record['functions']['0x1000']['candidates'][0]
        self.assertTrue(cand['exact_shape'])
        self.assertEqual((cand['name'], cand['file'], cand['line']), ('Thing::Run', 'src/toy_thing.cpp', 2))
        self.assertEqual(cand['source'], f'momusdigital/fnv_decomp@{REV[:8]}')
        text = '\n'.join(lines)
        self.assertIn('EXACT SHAPE', text)
        self.assertIn('tools/sibling_transplant.py', text)
        self.assertIn(f'SIBLING(momusdigital/fnv_decomp@{REV[:8]}, CC0-1.0)', text)
        x64_lookup.write_record(self.dir, record)
        self.assertEqual(json.loads((self.dir / 'sibling_x64.json').read_text())['status'], 'ok')

    def test_near_shape_is_listed_without_the_transplant_claim(self):
        sig = dict(SIGS[('src_toy_thing', '?Run@Thing@@QEAAXXZ')], strs=[])
        record, lines = self.run_hints(sig)
        cand = record['functions']['0x1000']['candidates'][0]
        self.assertFalse(cand['exact_shape'])
        self.assertLess(cand['score'], 1.0)
        self.assertNotIn('sibling_transplant', '\n'.join(lines))

    def test_unrelated_function_reports_no_candidate(self):
        record, lines = self.run_hints({'mn': ['nop2'] * 20, 'calls': 0, 'imms': [], 'strs': []})
        self.assertEqual(record['functions']['0x1000']['candidates'], [])
        self.assertIn('no sibling shape', '\n'.join(lines))

    def test_missing_index_gives_one_line_and_does_not_fail(self):
        empty = self.dir / 'none'
        empty.mkdir()
        record, lines = self.run_hints(dict(SIGS[('src_toy_thing', '?Run@Thing@@QEAAXXZ')]), index=empty)
        self.assertEqual(record['status'], 'index-missing')
        self.assertEqual(len(lines), 1)
        self.assertIn('./sr setup', lines[0])

    def test_tampered_index_is_not_used(self):
        pins = make_index(self.dir)
        (self.dir / 'idx.json.gz').write_bytes(b'junk')
        record, lines = x64_lookup.hints(self.dir, pins, None, 'objdump', self.exe, [FN])
        self.assertEqual(record['status'], 'index-unusable')
        self.assertEqual(len(lines), 1)

    def test_missing_objdump_and_lookup_errors_are_one_line(self):
        record, lines = self.run_hints({}, objdump=None)
        self.assertEqual((record['status'], len(lines)), ('no-objdump', 1))
        x64_lookup._loaded.clear()
        with mock.patch.object(x64_lookup, 'target_signature', side_effect=RuntimeError('boom')):
            record, lines = x64_lookup.hints(self.dir, self.dir / 'pins.json', None, 'objdump', self.exe, [FN])
        self.assertEqual(record['status'], 'error')
        self.assertEqual(len(lines), 1)

    def test_record_holds_no_listing_text(self):
        record, _ = self.run_hints(dict(SIGS[('src_toy_thing', '?Run@Thing@@QEAAXXZ')]))
        self.assertNotIn('push', json.dumps(record))


if __name__ == '__main__':
    unittest.main()
