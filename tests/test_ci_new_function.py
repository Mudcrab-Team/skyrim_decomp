"""A function with no accepted record reaches the CI host: its symbol is found by hash, never supplied."""
from contextlib import redirect_stdout
import io
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
        self.write(HEADER, '// 0x1010 f\nint f();\n')
        self.write(RECIPE, json.dumps(dict(sdk='synthetic-sdk')))

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)


class HeaderClaims(Fixture):
    def test_a_claimed_rva_becomes_a_request_with_no_symbol_and_the_default_recipe(self):
        got = ci.requests(self.root, [HEADER], {})
        self.assertEqual(got, [dict(unit=UNIT, rva=0x1010, symbol=None, recipe=ci.DEFAULT_RECIPE)])

    def test_resolves_only_possible_transitive_includers_of_changed_paths(self):
        self.write('reconstruction/shared/Leaf.h', 'int f();\n')
        self.write(HEADER, '#include "../shared/Le\\\naf.h"\n')
        self.write('reconstruction/unrelated/Leaf.h', 'int g();\n')
        self.write('reconstruction/unrelated/Other.cpp', '#include "Leaf.h"\n')
        self.write('reconstruction/unrelated/Broken.cpp', '#include "unrelated.h"\n')
        leaf = 'reconstruction/shared/Leaf.h'
        got = ci.requests(self.root, [leaf], {})
        self.assertEqual({r['unit'] for r in got}, {UNIT})

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

    def test_explicit_request_and_other_claims_use_the_same_declared_recipe(self):
        self.write(UNIT, f'// Recipe: {RECIPE}\n// CI hash: 0x1020 ?g@@YAHXZ\n#include "Fixture.h"\n')
        by_rva = {r['rva']: r for r in ci.requests(self.root, [UNIT], {})}
        self.assertEqual({r['recipe'] for r in by_rva.values()}, {RECIPE})
        self.assertEqual(by_rva[0x1020]['symbol'], '?g@@YAHXZ')

    def test_regression_uses_the_recipe_declared_at_each_revision(self):
        head = self.root / 'head'
        refs = [dict(unit=UNIT, rva=0x1010, symbol=None, recipe=RECIPE)]
        with patch.object(ci, 'compile_requests', return_value=[]) as compile_requests:
            ci.regress(self.root, head, refs, None, self.root / 'work', {})
        head_call, base_call = compile_requests.call_args_list
        self.assertEqual(head_call.args[2], refs)
        self.assertEqual(base_call.args[2], [dict(refs[0], recipe=ci.DEFAULT_RECIPE)])

    def test_an_accepted_binding_wins_over_a_claim_and_other_claims_are_added(self):
        self.write(HEADER, '// 0x1010 f\n// 0x1020 g\nint f();\n')
        known = {UNIT: [dict(rva=0x1010, symbol='Known', recipe=RECIPE)]}
        got = {r['rva']: r for r in ci.requests(self.root, [HEADER], known)}
        self.assertEqual((got[0x1010]['symbol'], got[0x1010]['recipe']), ('Known', ci.DEFAULT_RECIPE))
        self.assertIsNone(got[0x1020]['symbol'])

    def test_an_accepted_function_follows_the_recipe_the_unit_declares_or_the_default(self):
        other = 'reconstruction/recipes/older.json'
        self.write(UNIT, f'// recipe {RECIPE}\n#include "Fixture.h"\nint f() {{ return 1; }}\n')
        known = {UNIT: [dict(rva=0x1010, symbol='Known', recipe=other)]}
        got = ci.requests(self.root, [HEADER], known)
        self.assertEqual((got[0]['symbol'], got[0]['recipe']), ('Known', RECIPE))
        self.write(UNIT, '#include "Fixture.h"\nint f() { return 1; }\n')
        self.assertEqual(ci.requests(self.root, [HEADER], known)[0]['recipe'], ci.DEFAULT_RECIPE)

    def test_claims_per_unit_are_capped(self):
        self.write(HEADER, ''.join(f'// 0x{0x2000 + i:x} F{i}\n' for i in range(ci.MAX_CLAIMS_PER_UNIT + 20)))
        self.assertEqual(len(ci.requests(self.root, [HEADER], {})), ci.MAX_CLAIMS_PER_UNIT)

    def test_the_claim_cap_covers_a_whole_pr_in_one_unit(self):
        import pr_bot
        self.assertGreaterEqual(ci.MAX_CLAIMS_PER_UNIT, pr_bot.Bot(root=ROOT, work=self.root).config['max_functions'])

    def test_a_unit_without_claims_or_bindings_is_still_one_unbound_request(self):
        self.write(HEADER, 'int f();\n')
        self.assertEqual(ci.requests(self.root, [HEADER], {}),
                         [dict(unit=UNIT, rva=None, symbol=None, recipe=ci.DEFAULT_RECIPE)])
        self.write(UNIT, f'// Recipe: {RECIPE}\n#include "Fixture.h"\n')
        self.assertEqual(ci.requests(self.root, [HEADER], {})[0]['recipe'], RECIPE)


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
        self.write(HEADER, '// 0x1010 f\n// normalized_sha256 ' + '0' * 64 + '\nint f();\n')
        (row,) = self.rows(fx.coff_object(code=fx.CODE[:-1] + bytes([0x90])), [self.ref()], [target_row()])
        self.assertEqual(row['result'], 'mismatch')

    def test_known_bindings_report_their_symbol_when_they_match(self):
        (row,) = self.rows(fx.coff_object(), [dict(unit=UNIT, rva=0x1010, symbol=fx.FUNCTION, recipe=RECIPE)],
                           [target_row()])
        self.assertEqual((row['result'], row['symbols']), ('hash-match', [fx.FUNCTION]))

    def test_identical_comdats_resolve_to_the_claimed_decorated_symbol(self):
        left, right = '?Add@Left@@YAHXZ', '?Add@Right@@YAHXZ'
        unit = fx.Unit()
        for symbol in (left, right):
            section = unit.section('.text$mn', bytes.fromhex('31c0c3'), 0x60001020)
            unit.define(symbol, section, storage=fx.STORAGE_EXTERNAL, function=True)
        blob = unit.coff()
        _, section = compare.find_function(CoffObject(blob), left)
        row = dict(rva=0x1010, size=len(section.data), extraction='linked-reference-inference',
                   **hashes.section_hash(section))
        self.write(UNIT, f'// Recipe: {RECIPE}\n// 0x1010 {right}\n#include "Fixture.h"\n')
        refs = ci.requests(self.root, [UNIT], {UNIT: [dict(rva=0x1010, symbol=left, recipe=RECIPE)]})
        (result,) = self.rows(blob, refs, [row])
        self.assertEqual((result['result'], result['symbols']), ('hash-match', [right]))
        refs[0]['claim'] = '?Add@Missing@@YAHXZ'
        (result,) = self.rows(blob, refs, [row])
        self.assertEqual(result['result'], 'mismatch')


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


class CompileFailures(Fixture):
    def test_rows_get_a_bounded_error_tail_from_the_failed_compile(self):
        diagnostics = '\n'.join([
            *(f'{UNIT}({n}): error C2065: \'dummy\': undeclared identifier' for n in range(1, 9)),
            f'{self.root.resolve() / "work/source" / HEADER}(21): fatal error C1083: Cannot open include file: \'Missing.h\': '
            'No such file or directory',
            f'{UNIT}(22): error C1189: #error synthetic-payload',
            'C:\\private\\Secret.h(23): error C2059: syntax error',
            'Note: including file: C:\\private\\Secret.h',
        ])

        def fail(_ctx, _tree, _unit, _recipe, out, _tool):
            out.mkdir(parents=True)
            (out / 'compile.log').write_text(diagnostics)
            raise ci.contrib.Stop(ci.contrib.COMPILE, 'compile failed', log=str(out / 'compile.log'))

        self.write(UNIT, f'// Recipe: {RECIPE}\n// CI hash: 0x1020 ?g@@YAHXZ\n#include "Fixture.h"\n')
        refs = ci.requests(self.root, [UNIT], {})
        manifest = dict(functions=[], recipe_sha256={RECIPE: 'a' * 64})
        self.write('work/requests.json', json.dumps(refs))
        for name in (UNIT, HEADER):
            self.write(f'work/source/{name}', (self.root / name).read_text())
        output = io.StringIO()
        report = self.root / 'result.json'
        with patch.object(ci.contrib, 'sdk_include_dirs', return_value=(None, [self.root / 'synthetic-sdk/include'])), \
                patch.object(ci.contrib, 'compile_unit', side_effect=fail) as compile_unit, \
                patch.object(ci, 'ROOT', self.root), patch.object(ci, 'trusted_inputs', return_value={}), \
                patch.object(ci.hashes, 'load_manifest', return_value=manifest), \
                patch.object(ci.public, 'probe', return_value={'toolset': 'MATCH'}), \
                patch.dict(ci.os.environ, GITHUB_STEP_SUMMARY=''), redirect_stdout(output):
            code = ci.main(['check', '--work', str(self.root / 'work'), '--out', str(report),
                            '--bin', str(self.root / 'a/b/c/d/e/f/g')])
        self.assertEqual(code, 1)
        self.assertEqual(output.getvalue(), report.read_text())
        rows = json.loads(output.getvalue())['functions']
        compile_unit.assert_called_once()
        self.assertEqual(compile_unit.call_args.args[3], RECIPE)
        self.assertEqual([r['result'] for r in rows], ['mismatch', 'mismatch'])
        self.assertEqual(rows[0]['reason'], rows[1]['reason'])
        self.assertEqual(rows[0]['reason'].splitlines(), [
            'compile-failed',
            *(f'{UNIT}:{n}: C2065: undeclared identifier' for n in (6, 7, 8)),
            f'{HEADER}:21: C1083: cannot open include file',
            f'{UNIT}:22: C1189: an #error directive stopped compilation',
        ])

    def test_the_error_reader_ignores_output_before_the_read_limit(self):
        log = self.root / 'compile.log'
        log.write_text(f'{UNIT}(1): error C2065: undeclared identifier\n' + 'x' * ci.DIAGNOSTIC_READ_LIMIT)
        self.assertEqual(ci.diagnostic_tail(log, self.root), [])


if __name__ == '__main__':
    unittest.main()
