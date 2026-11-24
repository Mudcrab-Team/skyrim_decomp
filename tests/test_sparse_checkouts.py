"""Synthetic Git repositories exercise sparse transport without any game or runner inputs."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import sparse_checkouts as sparse
import family_review


class SparseCheckouts(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name).resolve()
        sparse.git(self.root, 'init', '--quiet', '--initial-branch=main')
        sparse.git(self.root, 'config', 'user.name', 'Synthetic')
        sparse.git(self.root, 'config', 'user.email', 'synthetic@example.invalid')
        self.write('.gitignore', '.local/\n')
        self.write('tools/worker.py', '# original synthetic tool\n')
        self.write('site/index.html', '<p>synthetic</p>')
        self.write('reconstruction/unmapped/static/S.cpp', '// generated\n')
        self.write('reconstruction/unmapped/leaves/L.cpp', '// leaf\n')
        self.write('data/progress.json', '{}')
        self.report = 'reports/synthetic/0x10.json'
        self.map = 'reports/synthetic/unit-symbols/a[1].json'
        self.history = self.map[:-5] + '.history.json'
        self.write(self.report, json.dumps({'symbol_map': {'path': self.map},
                                         'family_path': 'reports/synthetic/families/f.json'}))
        self.write(self.map, '{"symbols": {}}')
        self.write(self.history, '{"versions": []}')
        self.write('reports/synthetic/families/f.json', '{}')
        self.write('reports/synthetic/unit-symbols/a1.json', '{"unrelated": true}')
        self.write('reports/synthetic/unrelated.json', '{"unrelated": true}')
        sparse.git(self.root, 'add', '.')
        sparse.git(self.root, 'commit', '--quiet', '-m', 'original synthetic fixtures')
        self.tree = self.root / '.local/worker'
        sparse.add_worktree(self.root, self.tree, 'HEAD')

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def test_app_worker_defaults_sparse_and_shared_without_touching_dirty_or_keep(self):
        sparse.git(self.tree, 'sparse-checkout', 'disable')
        shared = self.root / '.local/shared-kit'
        shared.mkdir()
        config = dict(worker_roots=[str(self.root / '.local')], shared=dict(toolchains=str(shared)))
        self.assertTrue(sparse.worker_default(self.tree, config))
        self.assertTrue((self.tree / '.local/toolchains').is_symlink())
        self.assertEqual((self.tree / '.local/toolchains').resolve(), shared)
        sparse.git(self.tree, 'sparse-checkout', 'disable')
        self.assertFalse(sparse.worker_default(self.tree, dict(config, keep=[str(self.tree)])))
        self.assertFalse(sparse.worker_default(self.root, config))
        (self.tree / 'tools/worker.py').write_text('dirty fixture')
        self.assertFalse(sparse.worker_default(self.tree, config))
        self.assertFalse(sparse.active(self.tree))

    def test_no_bulk_checkout_and_no_shared_config_change(self):
        self.assertTrue(sparse.active(self.tree))
        self.assertFalse(sparse.active(self.root))
        self.assertTrue((self.tree / 'reports').is_dir())
        self.assertFalse((self.tree / 'site').exists())
        self.assertFalse((self.tree / 'reconstruction/unmapped/static').exists())
        self.assertTrue((self.tree / 'reconstruction/unmapped/leaves/L.cpp').is_file())
        self.assertTrue((self.tree / 'tools/worker.py').is_file())
        self.assertTrue((self.root / self.report).is_file())
        self.assertEqual(sparse.git(self.tree, 'status', '--porcelain'), b'')

    def test_dependency_closure_and_literal_paths_are_clean_and_editable(self):
        sparse.ensure(self.tree, [self.report])
        for name in (self.report, self.map, self.history, 'reports/synthetic/families/f.json'):
            self.assertEqual((self.tree / name).read_bytes(), (self.root / name).read_bytes())
        self.assertEqual(sparse.git(self.tree, 'status', '--porcelain'), b'')
        (self.tree / self.map).write_text('{"edited": true}')
        self.assertIn(self.map.encode(), sparse.git(self.tree, 'diff', '--name-only'))
        sparse.ensure(self.tree, [self.report])
        self.assertEqual(json.loads((self.tree / self.map).read_text()), {'edited': True})

    def test_batch_reads_pinned_index_without_populating_or_following_shared_main(self):
        original = json.loads((self.root / self.report).read_text())
        self.write(self.report, '{"moving_main": true}')
        sparse.git(self.root, 'add', self.report)
        sparse.git(self.root, 'commit', '--quiet', '-m', 'advance synthetic main')
        names = [self.report, 'reports/synthetic/missing.json']
        self.assertEqual(dict(sparse.reports(self.tree, names)), {self.report: original, names[1]: None})
        self.assertEqual(json.loads((self.tree / self.report).read_text()), original)
        family_review.read(self.tree, Path(self.report))
        self.assertEqual(json.loads((self.tree / self.report).read_text()), original)

    def test_batch_reads_working_edits_and_staged_blobs(self):
        sparse.ensure(self.tree, [self.map])
        (self.tree / self.map).write_text('{"working": true}')
        self.assertEqual(dict(sparse.reports(self.tree, [self.map]))[self.map], {'working': True})
        sparse.git(self.tree, 'add', self.map)
        # Sparse reapply must preserve staged changes and cannot substitute shared checkout bytes.
        sparse.set_patterns(self.tree)
        self.assertEqual(dict(sparse.reports(self.tree, [self.map]))[self.map], {'working': True})

    def test_working_deletion_is_not_read_back_from_index(self):
        sparse.ensure(self.tree, [self.map])
        (self.tree / self.map).unlink()
        self.assertIsNone(dict(sparse.reports(self.tree, [self.map]))[self.map])
        self.assertIn(self.map.encode(), sparse.git(self.tree, 'diff', '--name-only'))

    def test_full_checks_restore_patterns_on_failure_and_preserve_new_outputs(self):
        sparse.ensure(self.tree, [self.report])
        with self.assertRaisesRegex(RuntimeError, 'synthetic failure'):
            with sparse.full(self.tree):
                self.assertTrue((self.tree / 'site/index.html').is_file())
                self.assertTrue((self.tree / 'reconstruction/unmapped/static/S.cpp').is_file())
                (self.tree / 'reports/synthetic/new.json').write_text('{}')
                raise RuntimeError('synthetic failure')
        self.assertTrue(sparse.active(self.tree))
        self.assertTrue((self.tree / self.report).is_file())
        self.assertTrue((self.tree / 'reports/synthetic/new.json').is_file())
        self.assertFalse((self.tree / 'site').exists())
        self.assertFalse((self.tree / 'reconstruction/unmapped/static').exists())
        self.assertEqual((self.root / self.map).read_text(), '{"symbols": {}}')

    def test_check_entry_point_expands_full_view_and_restores_after_refusal(self):
        import check
        def validate(**kwargs):
            self.assertTrue((self.tree / 'reconstruction/unmapped/static/S.cpp').is_file())
            self.assertTrue((self.tree / 'site/index.html').is_file())
            raise ValueError('synthetic validator refusal')
        with patch.object(check, 'ROOT', self.tree), patch.object(check, 'check_git', return_value=1), \
                patch.object(check, 'load', side_effect=validate), patch.object(sys, 'argv', ['check.py']):
            self.assertEqual(check.main(), 1)
        self.assertTrue(sparse.active(self.tree))
        self.assertTrue((self.tree / 'reports').is_dir())
        self.assertFalse((self.tree / 'site').exists())

    def test_verifier_loads_public_map_and_source_evidence_on_demand(self):
        sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/verifier'))
        import pipeline
        for name, text in {'builds/target.json': '{"build_id": "synthetic"}',
                           'reconstruction/x/A.cpp': '// Evidence: reports/synthetic/unrelated.json\nint x;\n',
                           'reconstruction/recipes/test.json': '{"flags": ["/O2"]}'}.items():
            path = self.tree / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
        directory = self.tree / '.local/tasks/test'
        directory.mkdir(parents=True)
        (directory / 'task.json').write_text(json.dumps(dict(build_id='synthetic',
            compiled='reconstruction/x/A.cpp', recipe_name='test', symbols=self.map,
            functions=[dict(rva=16, size=4, symbol='Synthetic')])))
        task = pipeline.load_task(directory, repo=self.tree)
        self.assertEqual(task['symbols_local'].read_bytes(), (self.root / self.map).read_bytes())
        pipeline.unit_manifest(task, repo=self.tree)
        self.assertTrue((self.tree / 'reports/synthetic/unrelated.json').is_file())

    def test_bad_report_paths_rejected(self):
        for name in ('reports/../private.json', '/reports/a.json', 'site/a.json', 'reports/a\nb.json'):
            with self.subTest(name=name), self.assertRaisesRegex(ValueError, 'report path'):
                sparse.ensure(self.tree, [name])

    def test_rerun_cli_creates_sparse_detached_tree(self):
        tree = self.root / '.local/rerun'
        subprocess.run([sys.executable, str(Path(sparse.__file__)), str(tree), 'HEAD'],
                       cwd=self.root, check=True, capture_output=True)
        self.assertTrue((tree / 'reports').is_dir())
        self.assertFalse((tree / 'site').exists())
        self.assertFalse((tree / 'reconstruction/unmapped/static').exists())
        self.assertEqual(sparse.git(tree, 'rev-parse', 'HEAD'), sparse.git(self.root, 'rev-parse', 'HEAD'))


if __name__ == '__main__':
    unittest.main()
