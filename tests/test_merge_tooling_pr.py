"""Tests for the tooling-merge guard: job gating and the stale-base clobber check."""
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import merge_tooling_pr as m  # noqa: E402


def job(name, conclusion='SUCCESS'):
    return dict(name=name, workflowName='Infrastructure checks', conclusion=conclusion, status='COMPLETED')


class JobTests(unittest.TestCase):
    def test_green_shards_and_check_pass(self):
        self.assertEqual(m.job_problems([job('check'), job('tests (0)'), job('tests (1)'),
                                         dict(name='scope', workflowName='PR check', conclusion='FAILURE')]), [])

    def test_red_tests_or_check_refuses(self):
        self.assertTrue(m.job_problems([job('check'), job('tests (0)', 'FAILURE')]))
        self.assertTrue(m.job_problems([job('check', 'FAILURE'), job('tests (0)')]))

    def test_missing_or_pending_refuses(self):
        self.assertTrue(m.job_problems([job('check')]))
        self.assertTrue(m.job_problems([job('check'), dict(job('tests (0)'), conclusion=None, status='IN_PROGRESS')]))


class ClobberTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.cwd = os.getcwd()
        os.chdir(self.tmp.name)
        self.addCleanup(os.chdir, self.cwd)
        self.git('init', '-q', '-b', 'main')
        self.git('config', 'user.email', 'a@b')
        self.git('config', 'user.name', 'n')
        self.write('f.txt', ''.join(f'line {i}\n' for i in range(1, 21)))
        self.commit('base')
        self.base = self.rev()

    def git(self, *a):
        return subprocess.run(['git', *a], check=True, capture_output=True, text=True).stdout

    def rev(self):
        return self.git('rev-parse', 'HEAD').strip()

    def write(self, name, text):
        Path(name).write_text(text)

    def commit(self, msg):
        self.git('add', '-A')
        self.git('commit', '-q', '-m', msg)

    def edit(self, old, new):
        self.write('f.txt', Path('f.txt').read_text().replace(old, new))

    def test_disjoint_edits_in_the_same_file_are_fine(self):
        self.edit('line 3\n', 'line three\n')
        self.commit('main change')
        main = self.rev()
        self.git('checkout', '-q', '-b', 'pr', self.base)
        self.edit('line 18\n', 'line eighteen\n')
        self.commit('pr change')
        self.assertEqual(m.clobbers(self.base, main, self.rev()), [])

    def test_conflicting_edit_is_refused(self):
        self.edit('line 5\n', 'line five from main\n')
        self.commit('main change')
        main = self.rev()
        self.git('checkout', '-q', '-b', 'pr', self.base)
        self.edit('line 5\n', 'line 5 pr\n')
        self.commit('pr change')
        with self.assertRaises(SystemExit):
            m.clobbers(self.base, main, self.rev())

    def test_undone_hunk_detection_on_a_merged_file(self):
        hunk = m.hunks('@@ -5 +5 @@\n-line 5\n+line five from main\n')
        self.assertEqual(len(hunk), 1)
        kept = ['line five from main', 'x']
        lost = ['line 5', 'x']
        self.assertEqual(m.undone_hunks(hunk, kept), [])
        self.assertEqual(len(m.undone_hunks(hunk, lost)), 1)

    def test_resurrected_deletion_is_reported(self):
        hunk = m.hunks('@@ -5,2 +4,0 @@\n-line 5\n-line 6\n')
        self.assertEqual(len(m.undone_hunks(hunk, ['line 4', 'line 5', 'line 6'])), 1)
        self.assertEqual(m.undone_hunks(hunk, ['line 4', 'line 7']), [])

    def test_file_deleted_by_the_pr_but_edited_by_main_is_reported(self):
        self.edit('line 5\n', 'line five from main\n')
        self.commit('main change')
        main = self.rev()
        self.git('checkout', '-q', '-b', 'pr', self.base)
        self.git('rm', '-q', 'f.txt')
        self.commit('pr deletes')
        with self.assertRaises(SystemExit):
            m.clobbers(self.base, main, self.rev())  # modify/delete conflict is refused too


if __name__ == '__main__':
    unittest.main()
