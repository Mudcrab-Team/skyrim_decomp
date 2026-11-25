"""Shared-source preflight regression checks with toy source and COFF."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import compare
import contrib
import contrib_dependents as dependents
from pecoff import CoffObject
import synthetic_pecoff as fx
import target_hashes as hashes


class DependentChecks(unittest.TestCase):
    def setUp(self):
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        self.repo = Path(directory.name)
        self.ctx = contrib.Ctx(repo=self.repo, private=self.repo / '.local', as_json=True)
        self.unit = 'reconstruction/toy/Widget.cpp'
        self.header = 'reconstruction/toy/Widget.h'
        self.shared = 'reconstruction/toy/Shared.cpp'
        self.other = 'reconstruction/toy/Other.cpp'
        self.recipe = contrib.DEFAULT_RECIPE
        self.write(self.unit, '#include "Widget.h"\n')
        self.write(self.header, '#include "Shared.cpp"\n')
        self.write(self.shared, 'int Value = 1;\n')
        self.write(self.other, 'int Unrelated = 1;\n')
        self.write(self.recipe, '{}')
        self.records = [
            self.record(0x1000, self.unit, [self.unit, self.header, self.shared]),
            self.record(0x1001, self.unit, [self.unit, self.header, self.shared]),
            self.record(0x1002, self.other, [self.other]),
        ]
        self.good = fx.coff_object()
        _, section = compare.find_function(CoffObject(self.good), fx.FUNCTION)
        self.manifest = dict(build_id='toy', recipe_sha256={self.recipe: hashes.digest(b'{}')},
                             functions=[dict(rva=fn['rva'], size=len(section.data),
                                             extraction='linked-reference-inference',
                                             **hashes.section_hash(section)) for fn, _ in self.records])

    def write(self, path, text):
        path = self.repo / path
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def git(self, *args):
        return subprocess.check_output(['git', *args], cwd=self.repo, text=True).strip()

    def record(self, rva, unit, closure):
        return (dict(rva=rva, name='Widget::Work', status='matched'),
                dict(source=dict(compiled=unit, translation_unit=closure),
                     runs=[{'report': dict(contract_version=2, function={'symbol': fx.FUNCTION})}]))

    def test_staged_preflight_rechecks_transitive_includes_and_deduplicates_the_compile(self):
        self.git('init', '-q')
        self.git('add', '--', 'reconstruction')
        self.git('-c', 'user.name=Fixture', '-c', 'user.email=fixture@example.org', 'commit', '-qm', 'toy')
        self.write(self.shared, 'int Value = 2;\n')
        self.write(self.header, '#include "Shared.cpp"\n// shared header edit\n')
        self.git('add', '--', self.shared, self.header)
        self.write(self.shared, 'int Value = 1;\n')
        self.assertEqual(self.git('status', '--porcelain').splitlines()[0][:2], 'MM')

        def compile_unit(_ctx, root, unit, _recipe, out, _tool):
            self.assertEqual(unit, self.unit)
            obj = out.with_suffix('.obj')
            changed = (root / self.shared).read_text() == 'int Value = 2;\n'
            obj.write_bytes(fx.coff_object(code=fx.CODE[:-1] + b'\x90') if changed else self.good)
            return {'object': obj}

        args = contrib.parser().parse_args(['preflight', '--staged', '--base', 'HEAD'])
        with patch('contrib.intake_problems', side_effect=lambda *_a, **_kw: []), \
                patch('contrib_dependents.accepted_records', return_value=self.records), \
                patch('target_hashes.load_manifest', return_value=self.manifest), \
                patch('contrib_dependents.prefetch_objects', return_value={}), \
                patch('contrib.check_toolchain', return_value={}), \
                patch('contrib.compile_unit', side_effect=compile_unit) as compiled:
            code, result, _ = contrib.cmd_preflight(self.ctx, args)
            self.assertEqual(code, contrib.FAILED)
            self.assertEqual(result['dependent_recheck']['units'], 1)
            self.assertEqual([row['rva'] for row in result['dependent_recheck']['functions']], ['0x1000', '0x1001'])
            self.assertTrue(all(self.shared in line and self.header in line for line in result['blockers']))
            compiled.assert_called_once()
            compiled.reset_mock()
            args.staged = False
            code, result, _ = contrib.cmd_preflight(self.ctx, args)
            self.assertEqual(code, contrib.OK, result)
            self.assertEqual([row['result'] for row in result['dependent_recheck']['functions']], ['hash-match'] * 2)
            compiled.assert_called_once()

    def test_identifies_broken_closure_and_newly_resolved_angle_include(self):
        (self.repo / self.shared).unlink()
        affected = list(dependents.affected_units(self.repo, self.records, {self.shared: 'D'}))
        self.assertEqual([(unit, causes, closure) for unit, _refs, causes, closure in affected],
                         [(self.unit, [self.shared], None)])
        self.write(self.other, '#include <toy/Shared.cpp>\n')
        self.write(self.shared, 'int Value = 1;\n')
        affected = list(dependents.affected_units(self.repo, self.records, {self.shared: 'A'}))
        self.assertEqual({unit for unit, *_ in affected}, {self.unit, self.other})

    def test_compare_opt_in_reports_a_regression_after_a_passing_task(self):
        changes = [('M', self.header)]
        dependent = dict(functions=[dict(rva='0x1000', name='Widget::Work', unit=self.unit,
                                         result='mismatch', reason='published hash mismatch',
                                         includes=[self.header])])
        with patch('contrib.run_compare', side_effect=lambda *_a, **_kw: (contrib.OK, {}, None)), \
                patch('contrib.preflight_base', return_value='HEAD'), patch('contrib.git', return_value='HEAD'), \
                patch('contrib.working_source_changes', return_value=changes), \
                patch('contrib.intake_problems', return_value=[]), \
                patch('contrib_dependents.recheck', return_value=dependent) as recheck:
            self.assertEqual(contrib.cmd_compare(self.ctx, contrib.parser().parse_args(['compare']))[0], contrib.OK)
            recheck.assert_not_called()
            args = contrib.parser().parse_args(['compare', '--dependents'])
            code, result, _ = contrib.cmd_compare(self.ctx, args)
        recheck.assert_called_once_with(self.ctx, changes, None)
        self.assertEqual(code, contrib.FAILED)
        self.assertIn(f'after editing {self.header}', result['dependent_blockers'][0])

    def test_prefetched_object_uses_the_same_published_hash_comparison(self):
        units = list(dependents.affected_units(self.repo, self.records, {self.header: 'M'}))
        host = dict(backend='ssh', loader='native', batch=2)

        def batch_run(batch, _stage, outputs):
            [(task, files)] = batch
            self.assertEqual(task['functions'], [])
            self.assertEqual(task['compiled'], self.unit)
            self.assertEqual(files[self.shared], self.repo / self.shared)
            dest = outputs[task['task_id']]
            dest.mkdir(parents=True)
            (dest / 'candidate.obj').write_bytes(self.good)
            return {task['task_id']: (0, dest, None)}

        with patch('runners.load', return_value={'hosts': {'pc': host}, 'compare_prefer': []}), \
                patch('runners.reachable', return_value=True), patch('runners.with_image', return_value=host), \
                patch('runners.BatchHost') as batch, \
                patch('contrib.compile_unit') as compiled:
            batch.return_value.run.side_effect = batch_run
            rows = dependents.compare_units(self.ctx, self.repo, self.repo, units, self.manifest)
        batch.return_value.run.assert_called_once()
        self.assertEqual([row['result'] for row in rows], ['hash-match'] * 2)
        compiled.assert_not_called()


if __name__ == '__main__':
    unittest.main()
