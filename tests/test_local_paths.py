"""Shared contributor storage resolves configs, source clones and caches consistently."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import check_labels
import check_origin
from local_paths import local_dir, local_path, main_worktree_local


class LocalPathsTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name).resolve()
        self.repo = self.root / 'checkout'
        self.repo.mkdir()
        self.shared = self.root / 'shared'
        self.shared.mkdir()
        self.env = {'SR_LOCAL_DIR': str(self.shared)}

    def tearDown(self):
        self.tmp.cleanup()

    def test_relative_override_is_relative_to_checkout(self):
        self.assertEqual(local_dir(self.repo, {'SR_LOCAL_DIR': '../shared'}), self.shared)
        self.assertEqual(local_dir(self.repo, {}), self.repo / '.local')
        self.assertEqual(local_path(self.repo, 'reconstruction/Unit.cpp', self.env),
                         self.repo / 'reconstruction/Unit.cpp')
        self.assertEqual(local_path(self.repo, self.root / 'external', self.env), self.root / 'external')

    def test_label_and_origin_tools_use_shared_config_clones_and_cache(self):
        community = 'CharmedBaryon/CommonLibSSE-NG'
        sibling = 'momusdigital/fnv_decomp'
        (self.shared / 'verifier').mkdir()
        (self.shared / 'verifier/config.json').write_text(json.dumps({
            'community_checkouts': {community: '.local/sources/headers'},
            'sibling_checkouts': {sibling: '.local/sources/sibling'},
        }))
        for rel in ('sources/headers', 'sources/sibling'):
            (self.shared / rel).mkdir(parents=True)
        checkouts = check_labels.configured_checkouts(self.repo, self.env)
        siblings = check_labels.configured_siblings(self.repo, self.env)
        checker = check_labels.Checker(checkouts, self.repo, siblings, env=self.env)
        self.assertEqual(checker.checkouts[community], self.shared / 'sources/headers')
        self.assertEqual(checker.siblings[sibling], self.shared / 'sources/sibling')
        with patch.object(check_origin, 'Clone') as clone:
            check_origin.open_clones(self.repo, env=self.env)
        opened = {c.args[0]: c.args for c in clone.call_args_list}
        self.assertEqual(opened[community][1], self.shared / 'sources/headers')
        self.assertEqual(opened[sibling][1], self.shared / 'sources/sibling')
        self.assertTrue(all(args[-1] == self.shared / 'analysis/origin-index' for args in opened.values()))
        self.assertFalse((self.repo / '.local').exists())


class WorktreeFallbackTests(unittest.TestCase):
    def test_linked_worktree_uses_the_main_worktrees_local(self):
        import subprocess
        with tempfile.TemporaryDirectory() as tmp:
            main = Path(tmp).resolve() / 'main'
            main.mkdir()

            def git(*args, cwd=main):
                subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', *args], cwd=cwd, check=True,
                               capture_output=True)
            git('init', '-q', '-b', 'main')
            (main / 'f').write_text('x')
            git('add', 'f')
            git('commit', '-q', '-m', 'c')
            linked = Path(tmp).resolve() / 'linked'
            git('worktree', 'add', '-q', '-b', 'w', str(linked))
            self.assertIsNone(main_worktree_local(main))
            self.assertIsNone(main_worktree_local(linked))  # no .local in the main worktree yet
            (main / '.local').mkdir()
            self.assertEqual(main_worktree_local(linked), (main / '.local').resolve())
            self.assertIsNone(main_worktree_local(main))
            (linked / '.local').mkdir()
            self.assertIsNone(main_worktree_local(linked))  # its own .local wins

    def test_not_a_git_checkout(self):
        with tempfile.TemporaryDirectory() as tmp:
            self.assertIsNone(main_worktree_local(tmp))


if __name__ == '__main__':
    unittest.main()
