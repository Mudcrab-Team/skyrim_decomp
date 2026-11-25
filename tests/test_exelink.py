"""exelink: relinking compiled functions into a synthetic image and classifying the differences.

Every image and object here comes from tests/synthetic_pecoff.py: hand-chosen bytes, no compiler,
no game input.
"""
import argparse
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / 'exelink'))
import exelink  # noqa: E402
import relink  # noqa: E402
import units  # noqa: E402
import synthetic_pecoff as fx  # noqa: E402

BUILD = 'synthetic-fixture'


def spec_for(args, **extra):
    task = args['task']
    return dict({'id': 'f1', 'rva': task['rva'], 'size': task['size'], 'symbol': task['symbol']}, **extra)


def run(args, patches=(), mutate=None):
    """Place the function of `args` and return (linker, result, sections)."""
    linker = relink.Linker(args['image_bytes'], patches)
    smap = relink.parse_map(json.dumps(args['symbol_map']).encode(), BUILD)
    spec = spec_for(args)
    if mutate:
        mutate(spec)
    res = linker.place(spec, args['object_bytes'], smap)
    return linker, res, linker.finish()


class PlacementTests(unittest.TestCase):
    def test_correct_function_relinks_identical_with_its_exception_data(self):
        linker, res, sections = run(fx.inputs())
        self.assertEqual(res.status, relink.IDENTICAL)
        self.assertEqual(sorted(k for k, _r, _n in res.ranges), ['code', 'eh-data', 'pdata'])
        self.assertEqual(res.relocs['REL32'] + res.relocs['REL32_1'], 3)
        self.assertEqual(res.relocs['ADDR32NB'], 3)
        self.assertEqual(linker.work, bytearray(linker.orig))
        self.assertEqual(relink.summarize(linker, sections)['output_identical_to_retail'], True)

    def test_funclets_and_handler_data_are_placed_and_identical(self):
        unit = fx.catch_unit()
        args = fx.catch_inputs(unit)
        linker, res, _ = run(args)
        self.assertEqual(res.status, relink.IDENTICAL, res.row())
        kinds = [k for k, _r, _n in res.ranges]
        self.assertIn('funclet', kinds)
        self.assertGreaterEqual(kinds.count('eh-data'), 4)
        self.assertEqual(kinds.count('pdata'), 2)
        self.assertEqual(res.notes, set())

    def test_runtime_engine_functions_place_like_ordinary_ones(self):
        linker, res, _ = run(fx.inputs(), mutate=lambda s: s.update(engine='runtime'))
        self.assertEqual(res.status, relink.IDENTICAL)
        self.assertEqual(sorted(k for k, _r, _n in res.ranges), ['code', 'eh-data', 'pdata'])

    def test_the_patched_image_really_holds_our_bytes(self):
        # Blank the function in the image copy's source: only placement can restore it.
        args = fx.inputs()
        image = bytearray(args['image_bytes'])
        at = 0x400 + (fx.LAYOUT[fx.FUNCTION] - 0x1000)
        image[at:at + len(fx.CODE)] = b'\x90' * len(fx.CODE)
        linker = relink.Linker(bytes(image))
        res = linker.place(spec_for(args), args['object_bytes'],
                           relink.parse_map(json.dumps(args['symbol_map']).encode(), BUILD))
        linker.finish()
        self.assertEqual(res.status, relink.RESIDUAL)
        self.assertEqual(linker.work[at:at + len(fx.CODE)], bytearray(args['image_bytes'][at:at + len(fx.CODE)]))


class DifferenceClassTests(unittest.TestCase):
    def test_size_that_does_not_fit_is_its_own_class_and_places_nothing(self):
        linker, res, _ = run(fx.inputs(), mutate=lambda s: s.update(size=s['size'] + 4))
        self.assertEqual(res.status, relink.SIZE_MISMATCH)
        self.assertEqual(res.ranges, [])
        self.assertEqual(linker.work, bytearray(linker.orig))

    def test_unresolved_relocation_is_named_and_not_counted_as_a_plain_difference(self):
        args = fx.inputs()
        del args['symbol_map']['symbols'][fx.COUNTER]
        linker, res, sections = run(args)
        self.assertEqual(res.status, relink.UNRESOLVED)
        self.assertEqual(res.unresolved, [(fx.COUNTER, 'REL32_1', 'unresolved-symbol')])
        summary = relink.summarize(linker, sections)
        self.assertEqual(summary['classes'][relink.UNRESOLVED], 1)
        self.assertEqual(summary['relocations']['unresolved'], 1)
        self.assertEqual(summary['classes'][relink.RESIDUAL], 0)

    def test_wrong_target_address_is_a_residual_difference_with_first_offset(self):
        args = fx.inputs(image=fx.pe_image(link_addresses={fx.CALLEE: fx.LAYOUT[fx.CALLEE] + 4}))
        _, res, sections = run(args)
        self.assertEqual(res.status, relink.RESIDUAL)
        self.assertEqual(res.first_diff, (fx.LAYOUT[fx.FUNCTION] + 7, 'code'))
        row = sections['.text']
        self.assertEqual(row['first_diff'], (fx.LAYOUT[fx.FUNCTION] + 7, fx.FUNCTION))

    def test_bytes_changed_after_linking_are_a_post_link_patch_only_when_declared(self):
        args = fx.inputs(image=fx.pe_image(patch={0x02: 0x90}))
        at = fx.LAYOUT[fx.FUNCTION] + 2
        _, undeclared, _ = run(args)
        self.assertEqual(undeclared.status, relink.RESIDUAL)
        self.assertEqual(undeclared.first_diff[0], at)
        _, declared, _ = run(args, patches=[{'rva': at - 1, 'length': 4, 'label': 'toy'}])
        self.assertEqual(declared.status, relink.POST_LINK)
        _, partly, _ = run(args, patches=[{'rva': at + 1, 'length': 4, 'label': 'toy'}])
        self.assertEqual(partly.status, relink.RESIDUAL)

    def test_difference_with_an_unresolved_relocation_is_filed_under_unresolved(self):
        args = fx.inputs(image=fx.pe_image(patch={0x02: 0x90}))
        del args['symbol_map']['symbols'][fx.BASE]
        _, res, _ = run(args, patches=[{'rva': fx.LAYOUT[fx.FUNCTION], 'length': 0x20, 'label': 'toy'}])
        self.assertEqual(res.status, relink.UNRESOLVED)

    def test_missing_function_symbol_is_not_linked(self):
        _, res, _ = run(fx.inputs(), mutate=lambda s: s.update(symbol='NoSuchFunction'))
        self.assertEqual(res.status, relink.NOT_LINKED)
        self.assertTrue(res.reason.startswith('symbol-not-found'))

    def test_object_that_is_not_coff_is_not_linked(self):
        args = fx.inputs()
        linker = relink.Linker(args['image_bytes'])
        res = linker.place(spec_for(args), b'not an object', relink.parse_map(b'{"schema":1,"build_id":"x","symbols":{}}', 'x'))
        self.assertEqual((res.status, res.reason.split(':')[0]), (relink.NOT_LINKED, 'object-unreadable'))

    def test_two_functions_at_one_address_with_equal_bytes_are_a_fold_not_a_conflict(self):
        args = fx.inputs()
        linker = relink.Linker(args['image_bytes'])
        smap = relink.parse_map(json.dumps(args['symbol_map']).encode(), BUILD)
        first = linker.place(spec_for(args), args['object_bytes'], smap)
        second = linker.place(dict(spec_for(args), id='f2'), args['object_bytes'], smap)
        linker.finish()
        self.assertEqual((first.status, second.status), (relink.IDENTICAL, relink.IDENTICAL))
        self.assertNotIn('placement-conflict', second.notes)

    def test_record_hash_mismatch_is_noted_not_failed(self):
        _, res, _ = run(fx.inputs(), mutate=lambda s: s.update(record_code_section_sha256='0' * 64))
        self.assertEqual(res.status, relink.IDENTICAL)
        self.assertIn('object-differs-from-record', res.notes)

    def test_matching_record_hash_adds_no_note(self):
        args = fx.inputs()
        from compare import compare
        digest = compare(**args)['candidate']['code_section_sha256']
        _, res, _ = run(args, mutate=lambda s: s.update(record_code_section_sha256=digest))
        self.assertEqual(res.notes, set())


class ReportTests(unittest.TestCase):
    def test_summary_and_rows_hold_counts_names_and_rvas_only(self):
        args = fx.inputs(image=fx.pe_image(patch={0x02: 0x90}))
        linker, res, sections = run(args)
        summary = relink.summarize(linker, sections, None, BUILD)
        self.assertNotRegex(json.dumps([summary, res.row()]), r'[0-9a-fA-F]{16,}')
        self.assertEqual(set(res.row()), {'id', 'rva', 'size', 'name', 'class', 'first_diff_rva',
                                          'first_diff_kind', 'diff_bytes'})

    def test_merge_adds_counts_and_keeps_the_lowest_difference(self):
        good = run(fx.inputs())
        bad = run(fx.inputs(image=fx.pe_image(patch={0x02: 0x90})))
        parts = [relink.summarize(l, s, 'a' * 64, BUILD) for l, _r, s in (good, bad)]
        merged = relink.merge_summaries(parts)
        self.assertEqual(merged['functions'], 2)
        self.assertEqual(merged['classes'][relink.IDENTICAL], 1)
        self.assertEqual(merged['classes'][relink.RESIDUAL], 1)
        self.assertFalse(merged['output_identical_to_retail'])
        text = exelink.format_summary(merged)
        self.assertIn('first difference at RVA 0x1012', text)
        parts[1]['image_sha256'] = 'b' * 64
        with self.assertRaises(ValueError):
            relink.merge_summaries(parts)

    def test_output_derived_from_the_image_must_be_under_a_local_directory(self):
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaises(SystemExit):
                exelink.private_path(Path(tmp) / 'report')
            ok = exelink.private_path(Path(tmp) / '.local' / 'report')
            self.assertEqual(ok.name, 'report')

    def test_finish_writes_rows_and_summary_under_local_only(self):
        args = fx.inputs()
        with tempfile.TemporaryDirectory() as tmp:
            linker, _res, _ = run(args)
            ns = argparse.Namespace(summary=None, report=str(Path(tmp) / '.local' / 'r'),
                                    out_image=str(Path(tmp) / '.local' / 'out.exe'))
            with contextlib.redirect_stdout(io.StringIO()):
                code = exelink.finish(ns, linker, {'build_id': BUILD}, 'a' * 64, 0)
            self.assertEqual(code, 0)
            rows = [json.loads(x) for x in (Path(tmp) / '.local' / 'r' / 'functions.jsonl').read_text().splitlines()]
            self.assertEqual([r['class'] for r in rows], [relink.IDENTICAL])
            self.assertEqual((Path(tmp) / '.local' / 'out.exe').read_bytes(), args['image_bytes'])
            ns.report = str(Path(tmp) / 'public')
            with self.assertRaises(SystemExit), contextlib.redirect_stdout(io.StringIO()):
                exelink.finish(ns, linker, {'build_id': BUILD}, 'a' * 64, 0)


class UnitTests(unittest.TestCase):
    def test_unit_ids_are_file_safe_and_distinct(self):
        a = units.unit_id('reconstruction/skyrim/ai/Foo.cpp')
        b = units.unit_id('reconstruction/skyrim/ui/Foo.cpp')
        self.assertNotEqual(a, b)
        for name in (a, b, units.unit_id('reconstruction/' + 'x' * 300 + '.cpp')):
            self.assertRegex(name, r'^[a-z0-9-]{1,70}$')

    def test_batches_split_by_recipe_size_and_repeated_file_names(self):
        rows = [{'compiled': f'reconstruction/{d}/Foo.cpp', 'recipe': 'r1', 'unit': d} for d in 'abc']
        rows += [{'compiled': f'reconstruction/x/Bar{i}.cpp', 'recipe': 'r2', 'unit': f'bar{i}'} for i in range(5)]
        out = list(units.batches(rows, {'r1': ['/O2'], 'r2': ['/O1']}, 2))
        self.assertEqual(sorted(len(b) for _f, b in out), [1, 1, 1, 1, 2, 2])
        self.assertEqual({tuple(f) for f, _b in out}, {('/O2',), ('/O1',)})
        for _flags, batch in out:
            names = [Path(u['compiled']).stem for u in batch]
            self.assertEqual(len(names), len(set(names)))

    def test_link_unit_names_each_missing_input(self):
        args = fx.inputs()
        with tempfile.TemporaryDirectory() as tmp:
            repo, objects = Path(tmp) / 'repo', Path(tmp) / 'objs'
            (repo / 'maps').mkdir(parents=True)
            objects.mkdir()
            unit = {'unit': 'toy', 'compiled': 'reconstruction/toy.cpp', 'recipe': 'r', 'symbols': 'maps/m.json',
                    'functions': [spec_for(args)]}
            linker = relink.Linker(args['image_bytes'])
            exelink.link_unit(repo, linker, unit, objects, BUILD)
            self.assertEqual(linker.results[-1].reason, 'no-object')
            (objects / 'toy.obj').write_bytes(args['object_bytes'])
            exelink.link_unit(repo, linker, unit, objects, BUILD)
            self.assertEqual(linker.results[-1].reason, 'symbol-map-unusable')
            (repo / 'maps' / 'm.json').write_text(json.dumps(args['symbol_map']))
            exelink.link_unit(repo, linker, unit, objects, BUILD)
            self.assertIsNone(linker.results[-1].status)
            linker.finish()
            self.assertEqual(linker.results[-1].status, relink.IDENTICAL)

    def test_function_spec_reads_identity_and_record_hash_from_a_match_record(self):
        report = {'comparator': {'version': '0.6.0'}, 'function': {'rva': 16, 'size': 4, 'symbol': 'S'},
                  'source': {'source_revision': 'r' * 64, 'path': 'reconstruction/a.cpp'},
                  'candidate': {'code_section_sha256': 'c' * 64}}
        rec = {'function_id': 'b-0x10', 'runs': [{'report': report}, {'report': dict(report)}]}
        spec = units.function_spec(rec)
        self.assertEqual((spec['rva'], spec['symbol'], spec['record_code_section_sha256']), (16, 'S', 'c' * 64))
        self.assertNotIn('engine', spec)
        report['comparator'] = {'version': '0.6.1-runtime'}
        self.assertEqual(units.function_spec(rec)['engine'], 'runtime')
        rec['runs'][1]['report'] = dict(report, candidate={'code_section_sha256': 'd' * 64})
        self.assertNotIn('record_code_section_sha256', units.function_spec(rec))
        report['function']['internal_identity'] = {'entry_offset': 0}
        self.assertEqual(units.function_spec({'function_id': 'x', 'runs': [{'report': report}]})['internal_identity'],
                         {'entry_offset': 0})


if __name__ == '__main__':
    unittest.main()
