"""Pack export allowance scales with the row count and a timed-out export leaves no child running."""
from pathlib import Path
import subprocess
import sys
import time
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pr_bot  # noqa: E402


class PackExportTimeout(unittest.TestCase):
    def test_allowance_grows_with_rows(self):
        self.assertGreaterEqual(pr_bot.pack_export_timeout(1), 1800)
        self.assertGreater(pr_bot.pack_export_timeout(300), pr_bot.pack_export_timeout(120))

    @unittest.skipIf(sys.platform == 'win32', 'process groups, pgrep and sleep are POSIX; the Windows bot has no process-group kill')
    def test_timeout_kills_grandchildren(self):
        code = "import subprocess,time;subprocess.Popen(['sleep','61']);time.sleep(61)"
        with self.assertRaises(subprocess.TimeoutExpired):
            pr_bot.run_in_group([sys.executable, '-c', code], None, None, 2)
        time.sleep(0.3)
        self.assertEqual(subprocess.run(['pgrep', '-f', 'sleep 61'], capture_output=True).stdout, b'')


class ExporterFailureText(unittest.TestCase):
    def test_tail_names_the_error_and_hides_host_paths(self):
        raw = b"Traceback\nOSError: [Errno 63] File name too long: '/Users/someone/work/packs/x'\n"
        tail = pr_bot.stderr_tail(raw)
        self.assertIn('File name too long', tail)
        self.assertNotIn('/Users', tail)
        self.assertEqual(pr_bot.stderr_tail(b''), '')

    def test_failed_helper_status_carries_the_tail(self):
        bot = pr_bot.Bot.__new__(pr_bot.Bot)
        bot.dry_run, bot.root, bot.blocked_writes = False, Path('.'), []
        code = "import sys;sys.stderr.write('OSError: boom\\n');sys.exit(2)"
        with self.assertRaises(pr_bot.Stop) as ctx:
            bot.run([sys.executable, '-c', code])
        self.assertIn('boom', str(ctx.exception))


if __name__ == '__main__':
    unittest.main()
