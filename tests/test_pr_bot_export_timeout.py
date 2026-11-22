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

    def test_timeout_kills_grandchildren(self):
        code = "import subprocess,time;subprocess.Popen(['sleep','61']);time.sleep(61)"
        with self.assertRaises(subprocess.TimeoutExpired):
            pr_bot.run_in_group([sys.executable, '-c', code], None, None, 2)
        time.sleep(0.3)
        self.assertEqual(subprocess.run(['pgrep', '-f', 'sleep 61'], capture_output=True).stdout, b'')


if __name__ == '__main__':
    unittest.main()
