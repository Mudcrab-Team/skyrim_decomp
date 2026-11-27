"""tools/msvclib on toy data: unit generation, the compile driver with a stand-in compiler, lead selection."""
import json
import os
import stat
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'msvclib'))
import build  # noqa: E402
import catalog  # noqa: E402
import index  # noqa: E402


class CatalogTests(unittest.TestCase):
    def test_unit_names_are_unique_and_pointer_types_stay_distinct(self):
        names = [n for n, _ in catalog.units()]
        self.assertEqual(len(names), len(set(names)))
        self.assertIn('vector_char', names)
        self.assertIn('vector_charptr', names)

    def test_every_unit_is_an_explicit_instantiation_or_small_wrapper(self):
        for name, body in catalog.units():
            self.assertTrue(body.strip(), name)
            for line in body.splitlines():
                self.assertTrue(line.startswith(('template', 'using', 'void ', 'bool ')), (name, line))

    def test_gen_writes_prelude_units_and_listing(self):
        with tempfile.TemporaryDirectory() as d:
            sys.argv = ['catalog.py', 'gen', '--out', d, '--only', 'string_char']
            catalog.main()
            listing = json.loads((Path(d) / 'units.json').read_text())['units']
            self.assertTrue(listing)
            self.assertTrue((Path(d) / 'prelude.h').exists())
            for u in listing:
                self.assertTrue((Path(d) / u['source']).read_text().startswith('#include "prelude.h"'))

    def test_prelude_orders_every_struct(self):
        for t in catalog.STRUCTS:
            self.assertIn(f'MSVCLIB_ORDER({t})', catalog.PRELUDE)


@unittest.skipIf(os.name == 'nt', 'the stand-in compiler is a shell script')
class BuildTests(unittest.TestCase):
    def fake_cl(self, d, body):
        cl = Path(d) / 'cl'
        cl.write_text('#!/bin/sh\n' + body)
        cl.chmod(cl.stat().st_mode | stat.S_IEXEC)
        return cl

    def test_success_and_failure_are_recorded(self):
        with tempfile.TemporaryDirectory() as d:
            d = Path(d)
            out = d / 'out'
            (out / 'obj').mkdir(parents=True)
            (out / 'logs').mkdir()
            ok = self.fake_cl(d, 'for a in "$@"; do case $a in /Fo*) : > "${a#/Fo}";; esac; done\n')
            r = build.compile_unit(ok, d, [], out, 'a', 10)
            self.assertTrue(r['ok'])
            bad = self.fake_cl(d, 'echo "a.cpp(3): error C2664: no"\nexit 2\n')
            r = build.compile_unit(bad, d, [], out, 'b', 10)
            self.assertFalse(r['ok'])
            self.assertIn('C2664', r['errors'][0])

    def test_recipe_flags_are_present(self):
        for flag in ('/O2', '/MD', '/GS-', '/EHsc', '/GR', '/fp:precise', '/Gy'):
            self.assertIn(flag, build.FLAGS)


class IndexTests(unittest.TestCase):
    def test_leads_skip_matched_small_weak_and_ambiguous(self):
        hits = {1: ([(0.95, 0.9, ('u', 'f'))], 1), 2: ([(0.95, 0.9, ('u', 'f'))], 1), 3: ([(0.5, 0.5, ('u', 'f'))], 1),
                4: ([(0.95, 0.9, ('u', 'f'))], 9), 5: ([(0.95, 0.9, ('u', 'f'))], 1), 6: ([(0.95, 0.9, ('u', 'f'))], 1)}
        table = {r: {'size': 100} for r in hits}
        table[5]['size'] = 20
        del table[6]
        self.assertEqual(index.select_leads(hits, table, matched={2}), [1])

    def test_leads_skip_rvas_a_unit_already_marks(self):
        hits = {1: ([(0.95, 0.9, ('u', 'f'))], 1), 2: ([(0.95, 0.9, ('u', 'f'))], 1)}
        table = {r: {'size': 100} for r in hits}
        self.assertEqual(index.select_leads(hits, table, matched=set(), marked={2}), [1])

    def test_matched_rvas_reads_status(self):
        prog = {'functions': [{'rva': 1, 'status': 'matched'}, {'rva': 2, 'status': 'draft'}]}
        self.assertEqual(index.matched_rvas(prog), {1})

    def test_family_names_decorated_symbols(self):
        self.assertEqual(index.family('??$_Copy_memmove@PEAH@std@@YAPEAHPEAH@Z'), '_Copy_memmove')
        self.assertEqual(index.family('?deallocate@?$allocator@H@std@@QEAAXPEAH_K@Z'), 'deallocate')
        self.assertEqual(index.family('??_G?$pair@HH@std@@QEAAPEAXI@Z'), 'scalar-deleting-dtor')

    def test_families_count_passes_only(self):
        scores = [{'rva': 1, 'key': ['u', '?erase@?$list@H@std@@QEAA@XZ']}, {'rva': 2, 'key': ['u', '?erase@?$list@H@std@@QEAA@XZ']}]
        results = [{'rva': 1, 'result': 'pass'}, {'rva': 2, 'result': 'fail'}]
        self.assertEqual(index.families(scores, results), {'erase': 1})


if __name__ == '__main__':
    unittest.main()
