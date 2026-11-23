"""The Windows hash job loads tools/check.py, which loads verifier.pipeline; neither may need fcntl at import."""
from pathlib import Path
import subprocess
import sys
import unittest

TOOLS = Path(__file__).resolve().parents[1] / 'tools'


class NoFcntlImport(unittest.TestCase):
    def test_check_and_pipeline_import_where_fcntl_is_missing(self):
        code = "import sys; sys.modules['fcntl'] = None; sys.path[:0] = [sys.argv[1]]; import check, verifier.pipeline"
        result = subprocess.run([sys.executable, '-c', code, str(TOOLS)], capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr[-400:])


if __name__ == '__main__':
    unittest.main()
