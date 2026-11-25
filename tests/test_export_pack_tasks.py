"""Regression reference-map preparation on original synthetic metadata."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/ghidra'))
import export_pack as ep
import record_store


class ComparePackExport(unittest.TestCase):
    def test_compare_export_ignores_an_unrelated_empty_confirmation_task(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            evidence = root / 'findings/example.md'
            evidence.parent.mkdir()
            evidence.write_text('# Original finding\n')
            (root / 'data').mkdir()
            (root / 'data/progress.json').write_text(json.dumps({'functions': [
                {'id': 'synthetic-0x1000', 'rva': 4096, 'evidence': 'findings/example.md'}]}))
            tasks = root / '.local/tasks'
            unrelated = tasks / 'older/confirm-0x2000/task.json'
            unrelated.parent.mkdir(parents=True)
            unrelated.touch()
            listing = root / 'list.txt'
            listing.write_text('synthetic 0x1000 compare reconstruction/fx/Example.cpp\n')

            def write_task(task_id, unit, _recipe, _packs, _target, task_root, *_args, **_kwargs):
                task = task_root / task_id
                task.mkdir(exist_ok=True)
                (task / 'task.json').write_text(json.dumps(dict(
                    task_id=task_id, compiled=unit, build_id='synthetic', functions=[{'rva': '0x1000'}])))
                return task

            argv = ['export_pack.py', '--repo', str(root), 'packs', str(listing)]
            target = {'build_id': 'synthetic'}
            pack = dict(size=1, verdict='ready', reasons=[], identity={'owning_class': 'Example', 'community_name': None})
            with (patch.object(ep, 'REPO'), patch.object(ep, 'ANALYSIS'), patch.object(ep, 'load_config'),
                  patch.object(ep, 'setup', return_value=(target, None, None, [])),
                  patch.object(ep, 'run_ghidra', return_value=0), patch.object(ep, 'load_ghidra', return_value=({}, {})),
                  patch.object(ep, 'classify'), patch.object(ep, 'write_pack', return_value=pack),
                  patch.object(ep, 'shared_unit_functions', return_value={}),
                  patch.object(ep, 'write_task', side_effect=write_task)):
                with patch.object(sys, 'argv', argv), self.assertRaises(json.JSONDecodeError):
                    ep.main()
                with patch.object(sys, 'argv', argv + ['--no-evidence-tables']):
                    ep.main()
            self.assertTrue((tasks / 'compare/task.json').is_file())
            self.assertEqual(evidence.read_text(), '# Original finding\n')


class RegressionSymbols(unittest.TestCase):
    def test_packed_records_supply_the_accepted_symbols_and_reference_maps(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            build = root / 'reports/synthetic'
            record = build / '0x1000.json'
            mapping = build / 'unit-symbols' / ('a' * 64 + '.json')
            cpp = 'reconstruction/example/Example.cpp'
            progress = root / 'data/progress.json'
            progress.parent.mkdir()
            progress.write_text(json.dumps({'functions': [
                dict(id='synthetic-0x1000', name='Example', status='matched', rva=0x1000,
                     size=8, report=record.relative_to(root).as_posix())]}))
            mapping.parent.mkdir(parents=True)
            symbols = {'Reference': {'rva': 8192}}
            mapping.write_text(json.dumps({'symbols': symbols}))
            record.write_text(json.dumps({
                'source': {'compiled': cpp},
                'runs': [{'report': {'function': {'symbol': 'Example'}}}],
                'symbol_map': {'path': mapping.relative_to(root).as_posix()},
            }))
            record_store.pack_build(build)
            self.assertFalse(record.exists())
            self.assertFalse(mapping.exists())
            shared = ep.shared_unit_functions(root)[cpp]
            self.assertEqual(shared[0]['symbol'], 'Example')
            self.assertEqual(ep.regression_symbols(shared, 'synthetic', root)[0], symbols)

    def test_unit_maps_keep_references_and_declared_aliases(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'record.json').write_text(json.dumps({'symbol_map': {'path': 'unit.json'}}))
            symbols = {'AliasA': {'rva': 4096, 'size': 8}, 'AliasB': {'rva': 4096, 'size': 8},
                       'LocalReference': {'rva': 8192, 'size': None}}
            folds = [['AliasA', 'AliasB']]
            (root / 'unit.json').write_text(json.dumps({'symbols': symbols, 'folds': folds}))
            result, actual_folds, origins = ep.regression_symbols(
                [{'record': 'record.json'}, {'record': 'record.json'}], 'synthetic', root)
            self.assertEqual(result, symbols)
            self.assertEqual(actual_folds, folds)
            self.assertEqual(len(origins), len(symbols))
            self.assertTrue(all(x['from'] == 'unit.json' for x in origins))

    def test_conflicting_regression_names_refuse_preparation(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for i, address in enumerate((4096, 8192)):
                (root / f'record{i}.json').write_text(json.dumps({'symbol_map': {'path': f'map{i}.json'}}))
                (root / f'map{i}.json').write_text(json.dumps({'symbols': {'Reference': {'rva': address}}}))
            with self.assertRaisesRegex(ValueError, 'conflicting bindings'):
                ep.regression_symbols([{'record': f'record{i}.json'} for i in range(2)], 'synthetic', root)

    def test_distinct_vftable_addresses_leave_the_shared_binding_open(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            vftable = '??_7Synthetic@@6B@'
            for i, address in enumerate((4096, 8192)):
                (root / f'record{i}.json').write_text(json.dumps({'symbol_map': {'path': f'map{i}.json'}}))
                symbols = {vftable: {'rva': address}, f'Alias{i}': {'rva': address}}
                (root / f'map{i}.json').write_text(json.dumps({'symbols': symbols, 'folds': [[vftable, f'Alias{i}']]}))
            symbols, folds, origins = ep.regression_symbols(
                [{'record': f'record{i}.json'} for i in range(2)], 'synthetic', root)
            self.assertEqual(symbols, {'Alias0': {'rva': 4096}, 'Alias1': {'rva': 8192}})
            self.assertEqual(folds, [])
            self.assertEqual([entry['name'] for entry in origins], ['Alias0', 'Alias1'])

    def test_empty_regressions_need_no_map(self):
        self.assertEqual(ep.regression_symbols([], 'synthetic'), ({}, [], []))


if __name__ == '__main__':
    unittest.main()
