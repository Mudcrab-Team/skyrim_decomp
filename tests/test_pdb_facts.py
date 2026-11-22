"""Tests for tools/pdb_facts.py on invented data."""
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pdb_facts as pf  # noqa: E402

SOURCE = '''
bool Widget::Poke(int a, float b) const {
    return a > 0;
}
'''
CL = {'crashlogger': {'name': 'Widget::Poke', 'prototype': 'bool (Widget*, int)', 'convention': 'thiscall',
                      'size': 0x20, 'layout_header': None, 'class': None, 'label': 'CRASHLOGGER_PDB(x)'}}


class Signatures(unittest.TestCase):
    def test_split_params_respects_nesting(self):
        self.assertEqual(pf.split_params('int a, Foo<int, int> b'), ['int a', 'Foo<int, int> b'])
        self.assertEqual(pf.split_params('void'), [])

    def test_unit_and_pdb_signature(self):
        self.assertEqual(pf.unit_signature(SOURCE, 'Widget', 'Poke'), ('bool', ['int a', 'float b']))
        self.assertEqual(pf.pdb_signature('bool (Widget*, int)'), ('bool', 1))
        self.assertIsNone(pf.unit_signature(SOURCE, 'Widget', 'Missing'))


class Agreement(unittest.TestCase):
    def check(self, name, source=SOURCE, size=None):
        with mock.patch.object(pf, 'committed_facts', return_value=CL):
            return pf.agreement(Path('.'), 0x1000, name, source, size)

    def test_parameter_count_mismatch_is_reported(self):
        self.assertTrue(any('2 parameters' in f for f in self.check('Widget::Poke')))

    def test_matching_signature_is_quiet(self):
        source = 'bool Widget::Poke(int a) const { return a > 0; }'
        self.assertEqual(self.check('Widget::Poke', source), [])

    def test_name_and_size_mismatch(self):
        out = self.check('Widget::Prod', 'bool Widget::Prod(int a) { return a; }', size=0x30)
        self.assertTrue(any('differs from the CrashLogger PDB name' in f for f in out))
        self.assertTrue(any('0x30' in f for f in out))

    def test_placeholder_name_is_not_a_mismatch(self):
        out = self.check('Widget::Function001000', 'bool Widget::Function001000(int a) { return a; }')
        self.assertEqual(out, [])


class Setup(unittest.TestCase):
    def test_missing_files_say_what_to_download(self):
        with tempfile.TemporaryDirectory() as tmp:
            ok, lines = pf.setup_lines(Path(tmp), {'SR_SYMBOLS_DIR': tmp})
        self.assertFalse(ok)
        self.assertTrue(all('debugging.games' in ln for ln in lines))

    def test_wrong_size_is_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'x.map'
            path.write_text('invented')
            self.assertEqual(pf.verify('tesv-2013-map', path, full=False), 'size')

    def test_local_facts_skipped_in_ci(self):
        with mock.patch.object(pf, 'committed_facts', return_value={}), \
                mock.patch.object(pf, 'inventory_entry', return_value=None), \
                mock.patch.object(pf, 'locate') as locate:
            facts = pf.collect(Path('.'), 0x1000, env={'CI': '1'})
        locate.assert_not_called()
        self.assertNotIn('map', facts)
        self.assertEqual(pf.render(facts).split('\n')[-1], '  none known')


if __name__ == '__main__':
    unittest.main()
