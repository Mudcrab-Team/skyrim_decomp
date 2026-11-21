"""`start` prints sibling-symbol member-name candidates for the class, capped and source-labelled."""
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest
import unittest.mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import contrib  # noqa: E402

BUILD = 'sse-steam-1-7-104'


class SymbolNameHintTests(unittest.TestCase):
    def setUp(self):
        self.repo = Path(tempfile.mkdtemp())
        (self.repo / 'data').mkdir()
        (self.repo / 'builds').mkdir()
        (self.repo / 'builds/target.json').write_text(json.dumps({'build_id': BUILD}))
        self.addCleanup(shutil.rmtree, self.repo, ignore_errors=True)

    def write(self, cands, confirmed=None):
        (self.repo / 'data/symbol-names.json').write_text(json.dumps({'classes': {'Foo': {'candidates': cands}}}))
        (self.repo / 'data/name-corroboration.json').write_text(json.dumps(
            {'functions': {f'{BUILD}-0x1000': {'confirmed': confirmed or '', 'absent': ''}}}))

    def hints(self, cls='Foo'):
        with unittest.mock.patch.object(contrib, 'target_manifest', return_value={'build_id': BUILD}):
            return contrib.symbol_name_hints(self.repo, cls, [{'rva': 0x1000}])

    def test_names_carry_source_ids_and_the_candidate_warning(self):
        self.write({'Alpha': 'a', 'Beta': 'bcd'}, 'ab')
        lines = self.hints()
        self.assertIn('Alpha [tesv-2013-map]', lines[-1])
        self.assertIn('Beta [fnv-x360-pdb/fo4-pdb]', lines[-1])
        self.assertIn('never evidence of which function is which', lines[-1])
        self.assertIn('fo4-pdb, tesv-2013-map', lines[0])

    def test_list_is_capped_with_a_count_of_the_rest(self):
        self.write({f'M{i:02d}': 'a' for i in range(15)})
        self.assertIn('and 3 more', self.hints()[-1])
        self.assertNotIn('M12', self.hints()[-1])

    def test_unknown_class_or_missing_data_prints_nothing(self):
        self.write({'Alpha': 'a'})
        self.assertEqual(self.hints('Bar'), [])
        (self.repo / 'data/symbol-names.json').unlink()
        self.assertEqual(self.hints(), [])


if __name__ == '__main__':
    unittest.main()
