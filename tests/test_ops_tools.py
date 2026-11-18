"""Tests for the queue's release, profile stamping and near-miss set-aside, the profile data
and the disk admission floor. All inputs are synthetic."""
import contextlib
import io
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest
from types import SimpleNamespace
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tests'))
import profiles  # noqa: E402
import resource_admission as disk  # noqa: E402
import work_queue as wq  # noqa: E402


def write_queue(qdir, n):
    qdir.mkdir(parents=True, exist_ok=True)
    lines = [f'.local/tasks/g/g-u{i}\treconstruction/misc/U{i}.h,reconstruction/misc/U{i}.cpp\t0x{i + 1:x}000\t3' for i in range(n)]
    (qdir / 'queue.tsv').write_text('\n'.join(lines) + '\n')


class QueueAdditions(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.q = self.tmp / '.local/queue/small'
        write_queue(self.q, 2)

    def tearDown(self):
        shutil.rmtree(self.tmp)

    def test_release_frees_the_unit_for_another_session(self):
        u = wq.claim(self.q, 'haiku-2', t=100.0)
        with self.assertRaises(wq.QueueError):
            wq.release(self.q, u['dir'], worker='haiku-1')
        self.assertEqual(wq.release(self.q, u['dir'], worker='haiku-2', t=200.0), 'haiku-2')
        self.assertEqual(wq.claim(self.q, 'haiku-1', t=300.0)['key'], 'g-u0')
        rel = [json.loads(l) for l in (self.q / 'releases.jsonl').read_text().splitlines()]
        self.assertEqual(rel[0]['worker'], 'haiku-2')
        with self.assertRaises(wq.QueueError):
            wq.release(self.q, '.local/tasks/g/g-u1')  # not claimed

    def test_release_refuses_a_done_unit(self):
        u = wq.claim(self.q, 'haiku-2')
        wq.finish(self.q, u['dir'], [json.dumps({'unit': 'x.cpp'})])
        with self.assertRaisesRegex(wq.QueueError, 'already done'):
            wq.release(self.q, u['dir'])

    def test_results_carry_profile_and_claim_time(self):
        u = wq.claim(self.q, 'haiku-1', t=1_000_000.0, profile='cheap')
        recs = wq.finish(self.q, u['dir'], [json.dumps({'rva': '0x1000', 'result': 'pass', 'attempts': 2})], t=1_000_600.0)
        self.assertEqual(recs[0]['profile'], 'cheap')
        self.assertEqual(recs[0]['claimed'], wq.iso(1_000_000.0))
        self.assertIn('cheap', wq.stats(self.q)['profile'])

    def test_earlier_near_misses_are_set_aside_on_a_new_claim(self):
        unit = self.tmp / '.local/tasks/g/g-u0'
        (unit / 'near-miss').mkdir(parents=True)
        (unit / 'near-miss/0x1000.cpp').write_text('// old\n')
        u = wq.claim(self.q, 'haiku-1', t=1_000_000.0, repo=self.tmp)
        moved = u['earlier_near_misses']
        self.assertTrue((moved / '0x1000.cpp').is_file())
        self.assertFalse((unit / 'near-miss/0x1000.cpp').exists())
        # A session resuming its own claim keeps its files where they are.
        (unit / 'near-miss/0x1000.cpp').write_text('// mine\n')
        u = wq.claim(self.q, 'haiku-1', t=1_000_100.0, repo=self.tmp)
        self.assertTrue((unit / 'near-miss/0x1000.cpp').is_file())

    def test_near_miss_paths_derive_from_the_queue_in_use(self):
        unit = self.tmp / '.local/tasks/g/g-u0'
        (unit / 'near-miss').mkdir(parents=True)
        (unit / 'near-miss/0x1000.cpp').write_text('// old\n')
        # A scratch copy of the queue, outside any .local/queue/ layout, claims without a repo
        # argument: the unit dirs resolve against the copy, so the real unit keeps its files.
        scratch = self.tmp / 'scratch-queue'
        shutil.copytree(self.q, scratch)
        self.assertEqual(wq.queue_repo(scratch), scratch)
        with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            self.assertEqual(wq.main(['--queue-dir', str(scratch), 'next', '--worker', 'haiku-1']), 0)
        self.assertTrue((unit / 'near-miss/0x1000.cpp').is_file())
        # The queue in its own repository resolves against that repository, again with no argument.
        self.assertEqual(wq.queue_repo(self.q), self.tmp)
        with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            self.assertEqual(wq.main(['--queue-dir', str(self.q), 'next', '--worker', 'haiku-1']), 0)
        self.assertFalse((unit / 'near-miss/0x1000.cpp').exists())
        self.assertEqual(len(list((unit / 'near-miss').glob('earlier-*/0x1000.cpp'))), 1)

    def test_cli_release(self):
        wq.claim(self.q, 'haiku-2')
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            code = wq.main(['--queue-dir', str(self.q), 'release', '.local/tasks/g/g-u0', '--worker', 'haiku-2'])
        self.assertEqual(code, 0)
        self.assertIn('released', out.getvalue())


class Profiles(unittest.TestCase):
    def test_default_is_cheap_and_roles_are_complete(self):
        self.assertEqual(profiles.DEFAULT, 'cheap')
        for name in ('cheap', 'full', 'claude-low'):
            p = profiles.get(name)
            self.assertEqual(set(p['roles']) - {'drafter_fallback', 'drafter_strong'}, set(profiles.ROLES))
            for entry in p['roles'].values():
                self.assertTrue({'provider', 'model', 'harness'} <= entry.keys())
            self.assertTrue(p['cost'].startswith(name + ':'))
        self.assertIn('terra', profiles.role('claude-low', 'reviewer')['model'])
        self.assertIn('sol', profiles.role('claude-low', 'strong')['model'])
        with self.assertRaises(ValueError):
            profiles.get('nope')

    def test_cli_prints_a_cost_line_per_profile(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            profiles.main([])
        self.assertEqual(len(out.getvalue().splitlines()), len(profiles.PROFILES))
        self.assertIn('[default]', out.getvalue())


class DiskAdmission(unittest.TestCase):
    def admit(self, free_gb, **kw):
        with patch.object(disk.shutil, 'disk_usage', return_value=SimpleNamespace(free=int(free_gb * 1e9))):
            return disk.admit(Path.cwd(), 'synthetic job', **kw)

    def test_soft_floor_refuses_unless_overridden(self):
        with self.assertRaisesRegex(ValueError, 'low disk space'), contextlib.redirect_stderr(io.StringIO()):
            self.admit(5)
        with contextlib.redirect_stderr(io.StringIO()):
            self.admit(5, allow_low_disk=True)
        self.admit(5, soft_gb=4)

    def test_hard_floor_cannot_be_overridden(self):
        with self.assertRaisesRegex(ValueError, 'insufficient free disk'):
            self.admit(2.9, hard_gb=0, soft_gb=0, allow_low_disk=True)


if __name__ == '__main__':
    unittest.main()
