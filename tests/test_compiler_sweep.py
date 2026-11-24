"""Tests for tools/verifier/compiler_sweep.py and the per-toolset recipe and pin files it relies on."""
import hashlib
import json
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
sys.path.insert(0, str(ROOT / 'tools'))
import compiler_sweep as cs  # noqa: E402
import unit_build as ub  # noqa: E402
import pipeline  # noqa: E402


def row(result, reason='all-checks-passed'):
    return {'result': result, 'reason': reason, 'unwind': [], 'unwind_equal': True, 'code': None}


class SweepTests(unittest.TestCase):
    def test_recipe_sibling(self):
        got = cs.toolset_recipe('reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json', '19.15.26731')
        self.assertEqual(got, 'reconstruction/recipes/msvc-19.15.26731-o2-root-includes.json')
        with self.assertRaises(pipeline.PipelineError):
            cs.toolset_recipe('reconstruction/recipes/o2-os.json', '19.15.26731')

    def test_every_toolset_has_recipes_and_pins(self):
        for version in cs.TOOLSETS:
            if version == cs.BASELINE:
                continue
            pins = (ROOT / cs.PIN_NAME.format(version)).read_text().split('\n')
            names = [line.split()[1] for line in pins if line.strip()]
            self.assertEqual(names, ['cl.exe', 'c1xx.dll', 'c2.dll', 'link.exe'])
            cl_hash = pins[0].split()[0]
            self.assertRegex(cl_hash, '^[0-9a-f]{64}$')
            for suffix in ('o2', 'o2-root-includes', 'o2-reconstruction'):
                base = json.loads((ROOT / f'reconstruction/recipes/msvc-{cs.BASELINE}-{suffix}.json').read_text())
                got = json.loads((ROOT / f'reconstruction/recipes/msvc-{version}-{suffix}.json').read_text())
                self.assertEqual(got['compiler']['binary_sha256'], cl_hash)
                self.assertTrue(got['compiler']['version'].startswith(version))
                # Only the compiler identity may differ from the pinned recipe.
                self.assertEqual({k: v for k, v in got.items() if k != 'compiler'},
                                 {k: v for k, v in base.items() if k != 'compiler'})

    def test_summary_pins_only_when_mates_hold(self):
        task = {'task_id': 't', 'functions': [{'rva': 0x10}, {'rva': 0x20}]}
        by_version = {'19.15.26731': {'t': {'functions': {'0x10': row('pass'), '0x20': row('pass')}}},
                      cs.BASELINE: {'t': {'functions': {'0x10': row('fail', 'code-byte-mismatch'),
                                                        '0x20': row('pass')}}}}
        out = cs.summarise([task], by_version)['t']
        self.assertEqual((out['status'], out['pin']), ('pin', '19.15.26731'))
        by_version['19.15.26731']['t']['functions']['0x20'] = row('fail', 'eh-data-mismatch')
        out = cs.summarise([task], by_version)['t']
        self.assertEqual((out['status'], out['pin']), ('needs_split', None))
        by_version['19.15.26731']['t']['functions']['0x10'] = row('fail', 'code-byte-mismatch')
        self.assertEqual(cs.summarise([task], by_version)['t']['status'], 'none')

    def test_unwind_fields_without_diagnostics(self):
        tmp = ROOT / '.local' / 'test-sweep-empty'
        self.assertIsNone(cs.unwind_fields(tmp, 'unwind-info-mismatch'))
        self.assertEqual(cs.unwind_fields(tmp, 'code-byte-mismatch'), [])
        self.assertEqual(cs.unwind_fields(tmp, 'all-checks-passed'), [])
        self.assertIsNone(cs.unwind_fields(tmp, 'function-symbol-missing'))

    def test_spec_pins_are_limited_to_the_pinned_directory(self):
        task = {'task_id': 'x', 'build_id': 'b', 'compiled': 'reconstruction/a/B.cpp', 'recipe': 'r',
                'symbols_repo': None, 'functions': [{'rva': 1, 'size': 1, 'symbol': 's'}]}
        self.assertNotIn('pins', pipeline.unit_spec(task, {}, 'h'))
        self.assertEqual(pipeline.unit_spec(dict(task, pins='tools/verifier/pinned/19.15.26731.sha256'), {}, 'h')['pins'],
                         'tools/verifier/pinned/19.15.26731.sha256')
        self.assertEqual(ub.PINS_FILE, 'tools/verifier/pinned.sha256')


if __name__ == '__main__':
    unittest.main()
