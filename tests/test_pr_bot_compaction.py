import json
from pathlib import Path
import subprocess
import sys
import tempfile
import types
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import pr_bot  # noqa: E402
import record_store  # noqa: E402


def git(cwd, *args):
    return subprocess.run(['git', '-C', str(cwd), *args], check=True, capture_output=True, text=True).stdout


class CompactionTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        tmp = Path(self.tmp.name)
        subprocess.run(['git', 'init', '-q', '--bare', '-b', 'main', str(tmp / 'o.git')], check=True)
        self.work = tmp / 'work'
        subprocess.run(['git', '-c', 'core.autocrlf=false', 'clone', '-q', str(tmp / 'o.git'), str(self.work)], check=True, capture_output=True)
        git(self.work, 'config', 'user.email', 't@example.invalid')
        git(self.work, 'config', 'user.name', 't')
        (self.work / 'tools').mkdir()
        for name in ('record_store.py',):
            (self.work / 'tools' / name).write_text((ROOT / 'tools' / name).read_text())
        build = self.work / 'reports/b1'
        build.mkdir(parents=True)
        (build / '0x10.json').write_text('{"a": 1}\n', newline='\n')
        git(self.work, 'add', '.')
        git(self.work, 'commit', '-qm', 'base')
        git(self.work, 'push', '-q', 'origin', 'HEAD:main')
        self.tree = tmp / 'tree'
        subprocess.run(['git', '-c', 'core.autocrlf=false', 'clone', '-q', str(tmp / 'o.git'), str(self.tree)], check=True, capture_output=True)
        git(self.tree, 'config', 'user.email', 't@example.invalid')
        git(self.tree, 'config', 'user.name', 't')

        def run(argv, cwd=None, check=True, timeout=None, **kwargs):
            return subprocess.run([str(a) for a in argv], cwd=cwd, capture_output=True, check=check)
        self.bot = types.SimpleNamespace(tree=self.tree, run=run)

    def test_loose_records_on_main_are_folded_and_pushed(self):
        pr_bot.Bot.compact_records(self.bot, 7)
        git(self.work, 'pull', '-q', 'origin', 'main')
        self.assertFalse((self.work / 'reports/b1/0x10.json').exists())
        self.assertEqual(record_store.read_text(self.work / 'reports/b1/0x10.json'), '{"a": 1}\n')
        self.assertIn('Compact the records carried by PR #7', git(self.work, 'log', '--format=%s', '-1'))

    def test_nothing_loose_means_no_commit(self):
        pr_bot.Bot.compact_records(self.bot, 7)
        head = git(self.tree, 'rev-parse', 'origin/main')
        pr_bot.Bot.compact_records(self.bot, 8)
        git(self.tree, 'fetch', '-q', 'origin')
        self.assertEqual(git(self.tree, 'rev-parse', 'origin/main'), head)


if __name__ == '__main__':
    unittest.main()
