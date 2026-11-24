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


class Advisory(unittest.TestCase):
    def test_unit_advisory_reads_claimed_functions(self):
        unit = '// 0x1000 Widget::Poke\nbool Widget::Poke(int a, float b) const { return a > 0; }\n'
        with tempfile.TemporaryDirectory() as tmp:
            (Path(tmp) / 'w.cpp').write_text(unit)
            with mock.patch.object(pf, 'committed_facts', return_value=CL), \
                    mock.patch.object(pf, 'inventory_entry', return_value={'size': 0x20}):
                lines = pf.advisory_for_unit(Path(tmp), 'w.cpp')
        self.assertEqual(len(lines), 1)
        self.assertIn('0x1000', lines[0])

    def test_bot_comment_lists_advisory_without_blocking(self):
        sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
        import pr_bot
        decision = {'blocked': None, 'merge': True, 'verdicts': {}, 'pdb_advisory': ['u.cpp 0x1000: name differs']}
        text = pr_bot.comment_body('abc', decision)
        self.assertIn('Advisory (does not block the merge)', text)
        self.assertIn('0x1000', text)


class Canonical(unittest.TestCase):
    def test_constructor_spellings_agree(self):
        self.assertEqual(pf.canonical('Widget::ctor'), pf.canonical('Widget::Widget'))
        self.assertEqual(pf.canonical('Widget::Dtor'), pf.canonical('Widget::~Widget'))
        self.assertNotEqual(pf.canonical('Widget::Poke'), pf.canonical('Widget::Prod'))


class Fo4Cache(unittest.TestCase):
    def test_the_database_is_parsed_once_however_many_functions_ask(self):
        import symbol_corroboration
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'db.pdb'
            path.write_bytes(b'x')
            model = mock.Mock(variants={})
            pf._FO4_CACHE.clear()
            with (mock.patch.object(pf.pdb_types, 'Msf') as msf, mock.patch.object(pf.pdb_types, 'Tpi'),
                  mock.patch.object(pf.pdb_types, 'Model', return_value=model) as build,
                  mock.patch.object(symbol_corroboration, 'pdb_publics', return_value=[('?Poke@Widget@@QEAAXXZ', None)]) as publics,
                  mock.patch.object(pf.symbol_align, 'member_of', return_value=('Widget', 'Poke'))):
                first = pf.fo4_facts(path, 'Widget::Poke')
                second = pf.fo4_facts(path, 'Widget::Poke')
                other = pf.fo4_facts(path, 'Widget::Prod')
            self.assertEqual((msf.call_count, build.call_count, publics.call_count), (1, 1, 1))
            self.assertEqual(first, second)
            self.assertIsNotNone(first)
            self.assertIsNone(other)
