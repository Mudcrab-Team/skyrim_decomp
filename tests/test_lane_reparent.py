"""Tree-neutral origin movement keeps the checked commit; the intake merge push waits for the lane."""
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import time
import unittest
from types import SimpleNamespace
from unittest.mock import patch

sys.path[:0] = [str(Path(__file__).resolve().parents[1] / 'tools')]
import contrib_autopilot as ap
import flow
import flow_lane as lane
from test_flow import git as repo_git
from test_flow_lane import PushLane as _PushLane

lane_setup, enqueue, run_lane = _PushLane.setUp, _PushLane.enqueue, _PushLane.lane
del _PushLane


def git(cwd, *args, env=None):
    return subprocess.run(['git', *args], cwd=cwd, check=True, capture_output=True, text=True, env=env).stdout.strip()


class Reparent(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.repo = Path(self.tmp.name) / 'repo'
        self.repo.mkdir()
        git(self.repo, 'init', '-q', '-b', 'main')
        git(self.repo, 'config', 'user.name', 'Synthetic')
        git(self.repo, 'config', 'user.email', 'synthetic@example.org')
        (self.repo / 'a.txt').write_text('one\n')
        git(self.repo, 'add', '.')
        git(self.repo, 'commit', '-q', '-m', 'base')
        self.base = git(self.repo, 'rev-parse', 'HEAD')
        (self.repo / 'a.txt').write_text('two\n')
        git(self.repo, 'commit', '-q', '-am', 'candidate\n\nbody line')
        self.commit = git(self.repo, 'rev-parse', 'HEAD')
        git(self.repo, 'checkout', '-q', '--detach', self.commit)

    def receipt(self):
        integ = dict(commit=self.commit, base_revision=self.base, checks='done', pushed=None, ci=None)
        return dict(attempts=[], integrated=integ), integ

    def side_branch(self, content=None):
        git(self.repo, 'checkout', '-q', '--detach', self.base)
        if content is not None:
            (self.repo / 'b.txt').write_text(content)
            git(self.repo, 'add', 'b.txt')
            git(self.repo, 'commit', '-q', '-m', 'file change')
        else:
            git(self.repo, 'commit', '-q', '--allow-empty', '-m', 'merge keeping the tree')
        head = git(self.repo, 'rev-parse', 'HEAD')
        git(self.repo, 'checkout', '-q', '--detach', self.commit)
        return head

    def test_moved_head_with_equal_tree_keeps_tree_message_and_checks(self):
        destination = self.side_branch()
        receipt, integ = self.receipt()
        self.assertTrue(lane.reparent_tree_neutral(self.repo, receipt, integ, destination))
        new = integ['commit']
        self.assertNotEqual(new, self.commit)
        self.assertEqual(git(self.repo, 'rev-parse', new + '^'), destination)
        self.assertEqual(git(self.repo, 'rev-parse', new + '^{tree}'), git(self.repo, 'rev-parse', self.commit + '^{tree}'))
        self.assertEqual(git(self.repo, 'log', '-1', '--format=%B', new), 'candidate\n\nbody line')
        self.assertEqual(git(self.repo, 'rev-parse', 'HEAD'), new)
        self.assertEqual(integ['base_revision'], destination)
        self.assertEqual(integ['checks'], 'done')
        self.assertEqual(integ['reparented_from'], self.commit)
        self.assertEqual(receipt['attempts'][0]['commit'], self.commit)

    def test_moved_head_with_changed_tree_is_not_reparented(self):
        destination = self.side_branch('new\n')
        receipt, integ = self.receipt()
        self.assertFalse(lane.reparent_tree_neutral(self.repo, receipt, integ, destination))
        self.assertEqual(integ['commit'], self.commit)
        self.assertEqual(receipt['attempts'], [])


class RunReparents(unittest.TestCase):
    setUp, enqueue, lane = lane_setup, enqueue, run_lane

    def test_empty_origin_commit_during_checks_does_not_rebuild(self):
        self.enqueue()
        real = flow.pre_push_checks
        moved = []

        def checks_then_origin_moves(*args, **kwargs):
            real(*args, **kwargs)
            if not moved:
                repo_git(self.root, 'commit', '-q', '--allow-empty', '-m', 'tree-neutral merge')
                repo_git(self.root, 'push', '-q', 'origin', 'HEAD:main')
                moved.append(repo_git(self.root, 'rev-parse', 'HEAD'))

        with patch.object(flow, 'pre_push_checks', side_effect=checks_then_origin_moves) as checks:
            result = self.lane()
        self.assertEqual(checks.call_count, 1)
        self.assertEqual(result['state'], 'done')
        commit = result['integrated']['commit']
        self.assertEqual(repo_git(self.root, 'rev-parse', commit + '^'), moved[0])
        self.assertEqual(repo_git(self.root, 'rev-parse', 'origin/main'), commit)
        self.assertEqual(result['integrated']['ci'], 'green')
        self.assertEqual(len(result['attempts']), 1)


class MergeWaitsForLane(unittest.TestCase):
    def test_merge_push_does_not_start_while_a_lane_run_holds_the_lock(self):
        with tempfile.TemporaryDirectory() as tmp:
            fdir = Path(tmp) / 'flow'
            runtime = SimpleNamespace(fdir=fdir, config=dict(standard_headers=[], max_functions=1),
                                      private=Path(tmp), root=Path(tmp), root_lock=threading.RLock())
            pushes = []
            runtime.current_head = lambda number: 'h' * 40
            runtime.gh = lambda *a, **k: SimpleNamespace(stdout='{"state": "OPEN"}')
            runtime.git = lambda *a, **k: 'h' * 40
            runtime.command = lambda *a, **k: SimpleNamespace(stdout='')
            runtime.push_merge = lambda *a: pushes.append(time.monotonic()) or 'merged'
            revision = dict(number=7, head='h' * 40, author='login')
            outcome = []
            with patch('contrib_publication.screen_publication', return_value={}):
                with lane.lane_lock(fdir, purpose='integration'):
                    worker = threading.Thread(target=lambda: outcome.append(
                        ap.Runtime.merge_contributor(runtime, revision, {})))
                    worker.start()
                    time.sleep(0.5)
                    self.assertEqual(pushes, [])
                worker.join(10)
            self.assertEqual(outcome, ['merged'])
            self.assertEqual(len(pushes), 1)


if __name__ == '__main__':
    unittest.main()
