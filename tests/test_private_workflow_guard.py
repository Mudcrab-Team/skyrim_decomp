"""Synthetic publication-policy fixtures; no operator addresses or paths belong here."""
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check


class PrivateWorkflowGuard(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        subprocess.run(['git', 'init', '-q', str(self.root)], check=True)
        (self.root / '.local').mkdir()
        self.config = self.root / '.local/publication-forbidden.json'
        self.environment = patch.dict(os.environ, {}, clear=True)
        self.environment.start()
        self.addCleanup(self.environment.stop)

    def policy(self):
        self.config.write_text(json.dumps(dict(forbidden_strings=['SyntheticPrivateValue'])))

    def stage(self):
        subprocess.run(['git', 'add', 'notes.md'], cwd=self.root, check=True)

    def test_index_and_worktree_cannot_hide_each_other(self):
        self.policy()
        path = self.root / 'notes.md'
        path.write_text('syntheticPRIVATEvalue')
        self.stage()
        path.write_text('safe replacement')
        for staged in (False, True):
            with self.assertRaisesRegex(ValueError, 'Private workflow guard') as caught:
                check.check_git(self.root, staged=staged)
            self.assertNotIn('syntheticprivatevalue', str(caught.exception).lower())
        self.stage()
        self.assertEqual(check.check_git(self.root, staged=True), 1)
        path.write_text('SyntheticPrivateValue')
        self.assertEqual(check.check_git(self.root, staged=True), 1)
        with self.assertRaisesRegex(ValueError, 'Private workflow guard'):
            check.check_git(self.root)
        with self.assertRaises(ValueError):
            check.check_private_workflow('SyntheticPrivateValue.md', b'safe', check.private_workflow_terms(self.root))

    def test_ci_without_private_policy_is_noop(self):
        self.assertEqual(check.private_workflow_terms(self.root), ())
        check.check_private_workflow('notes.md', b'SyntheticPrivateValue', ())

    def test_invalid_or_missing_explicit_policy_fails_closed_without_values(self):
        with patch.dict(os.environ, SR_PUBLICATION_FORBIDDEN_CONFIG=str(self.config)):
            for content in (None, '{broken', '{}', '[]', '{"forbidden_strings": []}',
                            '{"forbidden_strings": [12]}'):
                if content is not None:
                    self.config.write_text(content)
                with self.assertRaisesRegex(ValueError, 'private config missing or invalid'):
                    check.private_workflow_terms(self.root)
            self.policy()
            self.assertEqual(check.private_workflow_terms(self.root / 'clone'), ('syntheticprivatevalue',))

    def test_linked_worktree_discovers_shared_policy(self):
        self.policy()
        linked = self.root / 'linked'
        linked.mkdir()
        with patch.object(check.subprocess, 'run', return_value=type('Result', (), {
                'returncode': 0, 'stdout': str(self.root / '.git') + '\n'})()):
            self.assertEqual(check.private_workflow_terms(linked), ('syntheticprivatevalue',))


if __name__ == '__main__':
    unittest.main()
