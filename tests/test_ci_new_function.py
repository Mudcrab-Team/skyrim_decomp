"""A function with no accepted record reaches the CI host: its symbol is found by hash, never supplied."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import compare  # noqa: E402
import ci_target_hash_check as ci  # noqa: E402
import synthetic_pecoff as fx  # noqa: E402
import target_hashes as hashes  # noqa: E402
from pecoff import CoffObject  # noqa: E402

UNIT = 'reconstruction/synthetic/Fixture.cpp'
HEADER = 'reconstruction/synthetic/Fixture.h'
RECIPE = 'reconstruction/recipes/synthetic.json'


def target_row(rva=0x1010, **kw):
    _sym, sec = compare.find_function(CoffObject(fx.coff_object(**kw)), fx.FUNCTION)
    return dict(rva=rva, size=len(sec.data), extraction='linked-reference-inference', **hashes.section_hash(sec))


class MatchingSymbols(unittest.TestCase):
    def test_the_function_equal_to_the_published_target_is_found_by_its_hash(self):
        self.assertEqual(ci.matching_symbols(fx.coff_object(), target_row()), [fx.FUNCTION])

    def test_changed_code_or_a_target_of_another_size_matches_nothing(self):
        self.assertEqual(ci.matching_symbols(fx.coff_object(code=fx.CODE[:-1] + bytes([0x90])), target_row()), [])
        self.assertEqual(ci.matching_symbols(fx.coff_object(), dict(target_row(), size=3)), [])

    def test_a_different_relocation_layout_is_not_a_match(self):
        extra = fx.coff_object(relocs=(*fx.RELOCS, (0, fx.CALLEE, fx.REL32)))
        self.assertEqual(ci.matching_symbols(extra, target_row()), [])


class Fixture(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.write(UNIT, '#include "Fixture.h"\nint f() { return 1; }\n')
        self.write(HEADER, '// RVA 0x1010\nint f();\n')
        self.write(RECIPE, json.dumps(dict(sdk='synthetic-sdk')))

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)


class HeaderClaims(Fixture):
    def test_a_claimed_rva_becomes_a_request_with_no_symbol_and_the_default_recipe(self):
        got = ci.requests(self.root, [HEADER], {})
        self.assertEqual(got, [dict(unit=UNIT, rva=0x1010, symbol=None, recipe=ci.DEFAULT_RECIPE)])

    def test_ci_hash_hint_accepts_optional_space_after_the_colon(self):
        for spacing in ('', ' ', '  ', '\t'):
            with self.subTest(spacing=spacing):
                self.assertEqual(ci.REQUEST.findall(f'// CI hash:{spacing}0xeee380 ?f@@YAXXZ\n'),
                                 [('0xeee380', '?f@@YAXXZ')])
        self.assertEqual(ci.REQUEST.findall('// CI hash:\n0xeee380 ?f@@YAXXZ\n'), [])
        self.assertEqual(ci.REQUEST.findall('// CI hash: 0xeee380\n'), [])

    def test_the_unit_names_its_recipe(self):
        self.write(UNIT, f'// recipe {RECIPE}\n#include "Fixture.h"\nint f() {{ return 1; }}\n')
        self.assertEqual(ci.requests(self.root, [HEADER], {})[0]['recipe'], RECIPE)

    def test_an_accepted_binding_wins_over_a_claim_and_other_claims_are_added(self):
        self.write(HEADER, '// RVA 0x1010, 0x1020\nint f();\n')
        known = {UNIT: [dict(rva=0x1010, symbol='Known', recipe=RECIPE)]}
        got = {r['rva']: r for r in ci.requests(self.root, [HEADER], known)}
        self.assertEqual((got[0x1010]['symbol'], got[0x1010]['recipe']), ('Known', RECIPE))
        self.assertIsNone(got[0x1020]['symbol'])

    def test_claims_per_unit_are_capped(self):
        self.write(HEADER, '// ' + ''.join(f'RVA 0x{0x2000 + i:x}\n// ' for i in range(ci.MAX_CLAIMS_PER_UNIT + 20)))
        self.assertEqual(len(ci.requests(self.root, [HEADER], {})), ci.MAX_CLAIMS_PER_UNIT)

    def test_the_claim_cap_covers_a_whole_pr_in_one_unit(self):
        import pr_bot
        self.assertGreaterEqual(ci.MAX_CLAIMS_PER_UNIT, pr_bot.Bot(root=ROOT, work=self.root).config['max_functions'])

    def test_a_unit_without_claims_or_bindings_is_still_one_unbound_request(self):
        self.write(HEADER, 'int f();\n')
        self.assertEqual(ci.requests(self.root, [HEADER], {}),
                         [dict(unit=UNIT, rva=None, symbol=None, recipe=ci.DEFAULT_RECIPE)])


class Discovery(Fixture):
    def rows(self, blob, refs, manifest_rows):
        obj = self.root / 'synthetic.obj'
        obj.write_bytes(blob)
        manifest = dict(functions=manifest_rows, recipe_sha256={RECIPE: 'a' * 64, ci.DEFAULT_RECIPE: 'a' * 64})
        bindir = self.root / 'a/b/c/d/e/f/g'
        with patch.object(ci.contrib, 'sdk_include_dirs', return_value=(None, [self.root / 'synthetic-sdk/include'])), \
                patch.object(ci.contrib, 'compile_unit', return_value=dict(object=obj)):
            return ci.compile_requests(self.root, self.root, refs, bindir, self.root / 'work', manifest)

    def ref(self, **kw):
        return dict(unit=UNIT, rva=0x1010, symbol=None, recipe=RECIPE, **kw)

    def test_a_new_function_passes_with_the_symbol_the_comparison_found_and_its_source_binding(self):
        (row,) = self.rows(fx.coff_object(), [self.ref()], [target_row()])
        self.assertEqual((row['result'], row['symbols'], row['rva']), ('hash-match', [fx.FUNCTION], '0x1010'))
        self.assertEqual(len(row['source_sha256']), 64)
        self.assertEqual(len(row['recipe_sha256']), 64)

    def test_a_claim_nothing_in_the_object_matches_fails_with_a_fixed_reason(self):
        (row,) = self.rows(fx.coff_object(code=fx.CODE[:-1] + bytes([0x90])), [self.ref()], [target_row()])
        self.assertEqual((row['result'], row['reason']), ('mismatch', 'no-matching-function'))
        self.assertNotIn('symbols', row)

    def test_a_claim_without_a_published_target_stays_unverified(self):
        (row,) = self.rows(fx.coff_object(), [self.ref()], [])
        self.assertEqual((row['result'], row['reason']), ('no-target', 'published-target-or-binding-unavailable'))

    def test_a_pr_cannot_supply_its_own_target_hash(self):
        # The target comes only from the manifest argument (the base checkout's published rows); a
        # row-shaped claim in the source is ignored.
        self.write(HEADER, '// RVA 0x1010\n// normalized_sha256 ' + '0' * 64 + '\nint f();\n')
        (row,) = self.rows(fx.coff_object(code=fx.CODE[:-1] + bytes([0x90])), [self.ref()], [target_row()])
        self.assertEqual(row['result'], 'mismatch')

    def test_known_bindings_report_their_symbol_when_they_match(self):
        (row,) = self.rows(fx.coff_object(), [dict(unit=UNIT, rva=0x1010, symbol=fx.FUNCTION, recipe=RECIPE)],
                           [target_row()])
        self.assertEqual((row['result'], row['symbols']), ('hash-match', [fx.FUNCTION]))


    def test_a_stale_recorded_symbol_is_found_again_by_its_hash(self):
        # A declaration change (void made bool) renames the decorated symbol a record names.
        stale = '?Setup@Shader@@UEAAXXZ'
        (row,) = self.rows(fx.coff_object(), [dict(unit=UNIT, rva=0x1010, symbol=stale, recipe=RECIPE)],
                           [target_row()])
        self.assertEqual((row['result'], row['symbols']), ('hash-match', [fx.FUNCTION]))

    def test_a_stale_recorded_symbol_with_changed_code_still_fails(self):
        (row,) = self.rows(fx.coff_object(code=fx.CODE[:-1] + bytes([0x90])),
                           [dict(unit=UNIT, rva=0x1010, symbol='?Setup@Shader@@UEAAXXZ', recipe=RECIPE)],
                           [target_row()])
        self.assertEqual((row['result'], row['reason']), ('mismatch', 'no-matching-function'))

if __name__ == '__main__':
    unittest.main()
