"""A long stage leaves a progress entry a watcher can read: atomic, throttled, monotonic, ageing."""
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import pr_bot  # noqa: E402

HEAD = 'abcdef0123456789'


class Clock:
    def __init__(self):
        self.now = 1000.0

    def __call__(self):
        return self.now


class ProgressTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)
        self.clock, self.said = Clock(), []
        self.progress = pr_bot.Progress(self.dir, 7, HEAD, clock=self.clock, interval=60, every=10,
                                        say=self.said.append)

    def entry(self):
        return json.loads(self.progress.path.read_text())

    def test_file_is_a_sibling_of_the_state_file_and_has_the_fields_a_watcher_needs(self):
        self.progress.begin('compare', 5)
        self.assertEqual(self.progress.path.name, 'pr7-abcdef012345.progress.json')
        e = self.entry()
        for key in ('stage', 'done', 'total', 'passed', 'failed', 'started_at', 'updated_at'):
            self.assertIn(key, e)
        self.assertEqual((e['stage'], e['done'], e['total']), ('compare', 0, 5))
        self.assertTrue(self.said and 'compare 0/5' in self.said[-1])

    def test_writes_are_throttled_by_time_and_by_count(self):
        self.progress.begin('compare', 100)
        writes = len(self.said)
        for _ in range(9):
            self.progress.advance(True)
        self.assertEqual(len(self.said), writes)  # under the count and under a minute
        self.progress.advance(True)  # the tenth unit
        self.assertEqual(self.entry()['done'], 10)
        self.clock.now += 61
        self.progress.advance(False)
        self.assertEqual((self.entry()['done'], self.entry()['failed']), (11, 1))

    def test_last_unit_is_always_written(self):
        self.progress.begin('review', 2)
        self.progress.advance()
        self.progress.advance()
        self.assertEqual(self.entry()['done'], 2)

    def test_no_temp_file_is_left_and_the_file_is_always_whole_json(self):
        self.progress.begin('compare', 200)
        stop = threading.Event()
        ready = threading.Event()
        seen = []

        def read():
            while not stop.is_set():
                try:
                    seen.append(json.loads(self.progress.path.read_text()))
                    ready.set()
                except (FileNotFoundError, PermissionError):
                    # Windows can refuse an open briefly while the writer replaces the file.
                    pass
                stop.wait(0.001)

        with ThreadPoolExecutor(max_workers=1) as pool:
            reader = pool.submit(read)
            try:
                self.assertTrue(ready.wait(5), 'reader did not see the initial progress entry')
                for _ in range(200):
                    self.progress.advance(True)
            finally:
                stop.set()
                reader.result()
        self.assertEqual([p.name for p in self.dir.iterdir()], [self.progress.path.name])
        done = [e['done'] for e in seen]
        self.assertEqual(done, sorted(done))
        self.assertEqual(self.entry()['done'], 200)

    def test_status_line_shows_age_and_flags_a_stale_entry(self):
        self.progress.begin('compare', 40)
        for _ in range(10):
            self.progress.advance(True)
        line, = pr_bot.progress_lines(self.dir, now=self.clock.now + 30)
        self.assertIn('pr7 abcdef012345 compare 10/40 pass=10 fail=0 age=30s', line)
        self.assertNotIn('STUCK', line)
        line, = pr_bot.progress_lines(self.dir, now=self.clock.now + 601)
        self.assertIn('STUCK', line)

    def test_a_completed_stage_is_not_called_stuck(self):
        self.progress.begin('compare', 2)
        self.progress.advance(True)
        self.progress.advance(True)
        line, = pr_bot.progress_lines(self.dir, now=self.clock.now + 5000)
        self.assertNotIn('STUCK', line)
        self.assertIn('stage complete', line)

    def test_a_finished_head_is_not_listed(self):
        self.progress.begin('compare', 4)
        (self.dir / 'pr7-abcdef012345.json').write_text(json.dumps({'done': True}))
        self.assertEqual(pr_bot.progress_lines(self.dir), [])

    def test_clear_removes_the_entry(self):
        self.progress.begin('compare', 4)
        self.progress.clear()
        self.assertFalse(self.progress.path.exists())

    def test_heartbeat_touches_while_a_block_runs(self):
        self.progress.begin('pack-export', 3)
        before = len(self.said)
        with self.progress.heartbeat(period=0.05):
            threading.Event().wait(0.3)
        self.assertGreater(len(self.said), before)


class FakeAttemptTests(unittest.TestCase):
    """compare_on_host with a fake verifier: progress is visible while attempts are still running."""

    def test_counts_appear_mid_stage_and_never_go_down(self):
        import test_pr_bot_replay as replay
        case = replay.ParallelCompareTests('test_attempts_overlap_and_every_function_gets_its_own_verdict')
        case.setUp()
        self.addCleanup(case.doCleanups)  # World's subprocess patches are undone here, not in tearDown
        self.addCleanup(case.tearDown)
        directory = case.bot.work / 'state'
        progress = pr_bot.Progress(directory, 7, 'abcdef13' + '0' * 8, interval=0, every=1)
        case.bot.progress_by_tag = {'7-abcdef13': progress}
        mid, release = [], threading.Event()

        def attempt(task):
            index = int(task.name.rsplit('-', 1)[1])
            if index >= 3:
                release.wait(20)  # held back until the first three have been seen in the progress file
            report = task / 'attempts/0' / f'0x{0x1000 + 0x10 * index:x}'
            report.mkdir(parents=True)
            (report / 'report.json').write_text(json.dumps(dict(result='pass')))
            return subprocess.CompletedProcess([], 0, b'', b'')

        def watch():
            for _ in range(500):
                try:
                    entry = json.loads(progress.path.read_text())
                except (OSError, ValueError):
                    entry = None
                if entry and entry['stage'] == 'compare' and entry['done'] >= 3:
                    mid.append(entry)
                    break
                threading.Event().wait(0.02)
            release.set()
        watcher = threading.Thread(target=watch)
        watcher.start()
        try:
            result, _ = case.compare(6, attempt, workers=3)
        finally:
            release.set()
            watcher.join()
        self.assertEqual(len(result), 6)
        final = json.loads(progress.path.read_text())
        self.assertEqual((final['done'], final['total'], final['passed']), (6, 6, 6))
        self.assertTrue(mid, 'no progress was visible while the stage ran')
        self.assertEqual(mid[0]['stage'], 'compare')
        self.assertLess(mid[0]['done'], mid[0]['total'])
        self.assertGreaterEqual(mid[0]['done'], 3)
        self.assertLessEqual(mid[0]['done'], final['done'])


if __name__ == '__main__':
    unittest.main()
