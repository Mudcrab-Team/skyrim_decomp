"""The reviewer falls back from codex to the Claude CLI only for account or capacity failures."""
import subprocess
import sys
import tempfile
import threading
import unittest
from pathlib import Path
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import pr_bot  # noqa: E402

VERDICT = 'LEAK: no\nVERDICT 0x10: approve\n'


class FakeState:
    def __init__(self):
        self.data = {}

    def set(self, key, value):
        self.data[key] = value


class FallbackTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.dir = Path(tmp.name)
        self.bot = pr_bot.Bot(root=ROOT, work=self.dir / 'w')
        self.bot.tree = self.dir
        self.now = [1000.0]
        self.bot.clock = lambda: self.now[0]
        self.out = self.dir / 'review.txt'
        self.calls = []
        self.codex = (1, b'ERROR: out of credits\n', b'')
        self.claude = (0, b'', VERDICT.encode())
        self.bot.run = self.fake_run

    def fake_run(self, argv, **kw):
        name = Path(str(argv[0])).name
        self.calls.append((name, [str(a) for a in argv], kw))
        if name == 'codex':
            code, err, text = self.codex
            if isinstance(code, Exception):
                raise code
            if code == 0:
                self.out.write_text(text.decode())
            return subprocess.CompletedProcess(argv, code, b'', err)
        code, err, text = self.claude
        return subprocess.CompletedProcess(argv, code, text, err)

    def names(self):
        return [c[0] for c in self.calls]

    def test_out_of_credits_falls_back_and_records_the_reviewer(self):
        state = FakeState()
        state.once = lambda key, fn: state.data.setdefault(key, fn())
        text = self.bot.reviewed(state, 'review_text', lambda: self.bot.run_model('prompt', self.out))
        self.assertEqual(self.names(), ['codex', 'claude'])
        self.assertEqual(state.data['reviewer'], 'claude-sonnet-5-5')
        claude = self.calls[1]
        self.assertEqual(claude[2]['input'], b'prompt')
        self.assertEqual(claude[2]['cwd'], self.dir)
        self.assertEqual(claude[1][claude[1].index('--tools') + 1], 'Read,Grep,Glob')
        self.assertIn('claude-sonnet-5-5', claude[1])

    def test_a_review_cached_by_an_earlier_process_is_reused_on_a_fresh_thread(self):
        state = FakeState()
        state.data['review_text'] = VERDICT
        state.once = lambda key, fn: state.data[key] if key in state.data else state.data.setdefault(key, fn())
        got = []
        worker = threading.Thread(target=lambda: got.append(self.bot.reviewed(state, 'review_text', self.fail)))
        worker.start()
        worker.join()
        self.assertEqual(got, [VERDICT])
        self.assertNotIn('reviewer', state.data)

    def test_codex_reviews_at_high_effort_unless_configured(self):
        # Medium effort approved functions that high effort had rejected on the same text.
        self.codex = (0, b'', VERDICT.encode())
        self.bot.run_model('p', self.out)
        self.assertIn('model_reasoning_effort="high"', self.calls[0][1])
        self.bot.config['review_effort'] = 'medium'
        self.bot.run_model('p', self.out)
        self.assertIn('model_reasoning_effort="medium"', self.calls[1][1])

    def test_review_runs_six_chunks_at_once_by_default(self):
        self.assertEqual(pr_bot.REVIEW_CHUNK_WORKERS, 6)
        self.assertEqual(self.bot.config['review_workers'], 6)

    def test_a_missing_codex_binary_falls_back(self):
        self.codex = (FileNotFoundError('codex'), b'', b'')
        self.assertEqual(self.bot.run_model('p', self.out), VERDICT)
        self.assertEqual(self.names(), ['codex', 'claude'])

    def test_a_reject_verdict_is_not_a_failure(self):
        reject = 'LEAK: no\nVERDICT 0x10: reject\n'
        self.codex = (0, b'', reject.encode())
        state = FakeState()
        state.once = lambda key, fn: state.data.setdefault(key, fn())
        self.assertEqual(self.bot.reviewed(state, 'review_text', lambda: self.bot.run_model('p', self.out)), reject)
        self.assertEqual(self.names(), ['codex'])
        self.assertEqual(state.data['reviewer'], 'codex')

    def test_other_codex_failures_do_not_fall_back(self):
        self.codex = (1, b'ERROR: invalid schema\n', b'')
        with self.assertRaises(pr_bot.Stop):
            self.bot.run_model('p', self.out)
        self.assertEqual(self.names(), ['codex'])

    def test_codex_is_skipped_for_the_pause_then_probed_again(self):
        self.bot.run_model('p', self.out)
        self.calls.clear()
        self.now[0] += 60
        self.bot.run_model('p', self.out)
        self.assertEqual(self.names(), ['claude'])
        self.calls.clear()
        self.now[0] += pr_bot.CODEX_PAUSE
        self.codex = (0, b'', VERDICT.encode())
        self.bot.run_model('p', self.out)
        self.assertEqual(self.names(), ['codex'])

    def test_the_pause_is_shared_with_other_slots(self):
        self.bot.run_model('p', self.out)
        other = self.bot.for_slot(1)
        other.run = self.fake_run
        self.calls.clear()
        other.run_model('p', self.out)
        self.assertEqual(self.names(), ['claude'])

    def test_both_reviewers_parse_identically(self):
        via_claude = self.bot.run_model('p', self.out)
        self.codex = (0, b'', VERDICT.encode())
        self.now[0] += pr_bot.CODEX_PAUSE
        via_codex = self.bot.run_model('p', self.out)
        self.assertEqual(pr_bot.parse_review(via_claude, {0x10}), pr_bot.parse_review(via_codex, {0x10}))

    def test_a_claude_failure_stops(self):
        self.claude = (1, b'not logged in', b'')
        with self.assertRaises(pr_bot.Stop):
            self.bot.run_model('p', self.out)


if __name__ == '__main__':
    unittest.main()
