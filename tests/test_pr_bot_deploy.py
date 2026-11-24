"""tools/pr_bot_deploy.sh: the revision is checked out and the service restarted only when the dry run exits 0."""
import os
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / 'tools/pr_bot_deploy.sh'
ENV = {**os.environ, 'GIT_AUTHOR_NAME': 'f', 'GIT_AUTHOR_EMAIL': 'f@example.invalid',
       'GIT_COMMITTER_NAME': 'f', 'GIT_COMMITTER_EMAIL': 'f@example.invalid'}


def git(cwd, *args):
    return subprocess.run(['git', *args], cwd=cwd, capture_output=True, text=True, check=True, env=ENV).stdout.strip()


class DeployTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.dir = Path(tmp.name)
        self.src = self.dir / 'src'
        self.src.mkdir()
        git(self.src, 'init', '-q', '-b', 'main')
        (self.src / 'tools').mkdir()
        self.commit('first')
        self.old = git(self.src, 'rev-parse', 'HEAD')
        self.new = self.commit('second')
        git(self.src, 'checkout', '-q', '--detach', self.old)
        (self.dir / 'bin').mkdir()
        self.kicked = self.dir / 'kicked'
        launchctl = self.dir / 'bin/launchctl'
        launchctl.write_text(f'#!/bin/sh\necho "$@" >> {self.kicked}\n')
        launchctl.chmod(0o755)

    def commit(self, name):
        # The "bot" is a stub whose exit status the revision decides.
        (self.src / 'tools/pr_bot.py').write_text(
            'import sys\nsys.exit(1 if "--dry-run" in sys.argv and %r == "bad" else 0)\n' % name)
        git(self.src, 'add', '-A')
        git(self.src, 'commit', '-q', '-m', name)
        return git(self.src, 'rev-parse', 'HEAD')

    def with_origin(self):
        """Give the source checkout an origin whose main is the newer revision."""
        origin = self.dir / 'origin.git'
        git(self.dir, 'init', '-q', '--bare', '-b', 'main', str(origin))
        git(self.src, 'remote', 'add', 'origin', str(origin))
        git(self.src, 'push', '-q', 'origin', f'{self.new}:refs/heads/main')

    def deploy(self, sha, *extra):
        env = {**ENV, 'PATH': f'{self.dir / "bin"}:{os.environ["PATH"]}', 'SR_BOT_ROOT': str(self.dir),
               'SR_BOT_SRC': str(self.src), 'SR_BOT_PYTHON': 'python3', 'SR_BOT_LABEL': 'x.bot',
               'SR_BOT_PIN': str(self.dir / 'pin')}
        return subprocess.run(['sh', str(SCRIPT), sha, *extra], capture_output=True, text=True, env=env)

    def test_a_passing_dry_run_checks_the_revision_out_pins_it_and_restarts(self):
        done = self.deploy(self.new)
        self.assertEqual(done.returncode, 0, done.stderr)
        self.assertEqual(git(self.src, 'rev-parse', 'HEAD'), self.new)
        self.assertEqual((self.dir / 'pin').read_text().strip(), self.new)
        self.assertIn('kickstart -k', self.kicked.read_text())

    def test_a_failing_dry_run_changes_nothing(self):
        bad = self.commit('bad')
        git(self.src, 'checkout', '-q', '--detach', self.old)
        done = self.deploy(bad)
        self.assertNotEqual(done.returncode, 0)
        self.assertEqual(git(self.src, 'rev-parse', 'HEAD'), self.old)
        self.assertFalse(self.kicked.exists())
        self.assertFalse((self.dir / 'pin').exists())

    def test_a_revision_behind_origin_main_is_refused(self):
        self.with_origin()
        done = self.deploy(self.old)
        self.assertNotEqual(done.returncode, 0)
        self.assertIn('origin/main', done.stderr)
        self.assertEqual(git(self.src, 'rev-parse', 'HEAD'), self.old)
        self.assertFalse(self.kicked.exists())
        self.assertFalse((self.dir / 'pin').exists())

    def test_allow_stale_deploys_a_revision_behind_origin_main(self):
        self.with_origin()
        git(self.src, 'checkout', '-q', '--detach', self.new)
        done = self.deploy(self.old, '--allow-stale')
        self.assertEqual(done.returncode, 0, done.stderr)
        self.assertEqual(git(self.src, 'rev-parse', 'HEAD'), self.old)
        self.assertIn('kickstart -k', self.kicked.read_text())

    def test_origin_main_head_deploys_without_the_flag(self):
        self.with_origin()
        done = self.deploy(self.new)
        self.assertEqual(done.returncode, 0, done.stderr)
        self.assertEqual((self.dir / 'pin').read_text().strip(), self.new)

    def test_an_unknown_argument_is_refused(self):
        done = self.deploy(self.new, '--force')
        self.assertEqual(done.returncode, 2)
        self.assertFalse(self.kicked.exists())


if __name__ == '__main__':
    unittest.main()
