"""The bot's compare asks the runner for one batch first and never depends on it."""
from pathlib import Path
import subprocess
import sys
import unittest
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pr_bot  # noqa: E402


def fake(config, run):
    return SimpleNamespace(config=dict(compare_timeout=60, **config), tree=Path('/tree'), run=run)


class PrefetchCompare(unittest.TestCase):
    def test_one_batch_command_names_every_task(self):
        calls = []

        def run(argv, **kw):
            calls.append(argv)
            return subprocess.CompletedProcess(argv, 0, b'compare_batch: 2 of 2 unit(s) prefetched\n', b'')
        pr_bot.Bot.prefetch_compare(fake({}, run), [Path('/t/a'), Path('/t/b')], None)
        self.assertEqual(len(calls), 1)
        self.assertEqual(calls[0][1:2], ['tools/verifier/compare_batch.py'])
        self.assertEqual(calls[0][-2:], ['/t/a', '/t/b'])

    def test_a_failing_or_timed_out_batch_is_not_an_error(self):
        for exc in (subprocess.TimeoutExpired('x', 1), OSError('gone'), pr_bot.Stop('no')):
            def run(argv, exc=exc, **kw):
                raise exc
            pr_bot.Bot.prefetch_compare(fake({}, run), [Path('/t/a')], None)
        bad = lambda argv, **kw: subprocess.CompletedProcess(argv, 2, b'', b'boom')
        pr_bot.Bot.prefetch_compare(fake({}, bad), [Path('/t/a')], None)

    def test_it_can_be_switched_off(self):
        def run(argv, **kw):
            raise AssertionError('must not run')
        pr_bot.Bot.prefetch_compare(fake({'compare_prefetch': False}, run), [Path('/t/a')], None)


if __name__ == '__main__':
    unittest.main()
