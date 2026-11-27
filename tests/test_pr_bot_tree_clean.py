"""A bot scratch tree with stray untracked files still moves to a base that now tracks them."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import pr_bot  # noqa: E402


def git(cwd, *args):
    return subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', *args], cwd=cwd, check=True,
                          capture_output=True, text=True).stdout.strip()


class PrepareTreeTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)
        self.root = self.work / 'root'
        self.root.mkdir()
        git(self.root, 'init', '-q')
        git(self.root, 'remote', 'add', 'origin', 'https://example.invalid/r.git')
        (self.root / 'a.txt').write_text('a')
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-qm', 'one')
        self.first = git(self.root, 'rev-parse', 'HEAD')
        (self.root / 'findings').mkdir()
        (self.root / 'findings' / 'x.md').write_text('merged')
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-qm', 'two')
        self.second = git(self.root, 'rev-parse', 'HEAD')
        self.bot = pr_bot.Bot(root=self.root, work=self.work / 'work')

    def test_an_untracked_copy_of_a_file_the_base_now_tracks_is_removed_first(self):
        self.bot.prepare_tree(self.first)
        stray = self.bot.tree / 'findings' / 'x.md'
        stray.parent.mkdir()
        stray.write_text('stray')
        self.bot.prepare_tree(self.second)
        self.assertEqual(stray.read_text(), 'merged')

    def test_a_refused_checkout_names_the_paths_git_would_overwrite(self):
        self.bot.prepare_tree(self.first)
        stray = self.bot.tree / 'other' / 'y.md'
        stray.parent.mkdir()
        stray.write_text('stray')
        (self.root / 'other').mkdir()
        (self.root / 'other' / 'y.md').write_text('merged')
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-qm', 'three')
        with self.assertRaises(pr_bot.Stop) as caught:
            self.bot.prepare_tree(git(self.root, 'rev-parse', 'HEAD'))
        self.assertIn('other/y.md', str(caught.exception))


if __name__ == '__main__':
    unittest.main()
