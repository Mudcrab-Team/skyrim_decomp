"""Lines `attempt` prints from the compile log."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import pipeline  # noqa: E402
from importlib.machinery import SourceFileLoader
attempt = SourceFileLoader('attempt_output_test', str(ROOT / 'tools/verifier/attempt')).load_module()


class CompileWarnings(unittest.TestCase):
    def log(self, text):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        path = Path(tmp.name) / 'compile.log'
        path.write_text(text)
        return path

    def test_forced_inline_refusals_are_named_once(self):
        path = self.log("a.cpp(10): warning C4714: function 'void __cdecl Helper(int)' marked as __forceinline not inlined\n"
                        "a.cpp(20): warning C4714: function 'Other' marked as __forceinline not inlined\n"
                        "a.cpp(30): warning C4714: function 'Other' marked as __forceinline not inlined\n")
        lines = pipeline.compile_warnings(path)
        self.assertEqual(len(lines), 1)
        self.assertIn('2 function(s)', lines[0])
        self.assertIn('Other', lines[0])

    def test_verdict_repeated_after_advice(self):
        self.assertEqual(attempt.verdict_lines('attempt: 1/1 pass', ['  0x123 PASS\n      detail']),
                         ['attempt: 1/1 pass', '  0x123 PASS'])

    def test_publication_warnings_cover_unit(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction').mkdir()
            (root / 'reconstruction/Toy.cpp').write_text('void FUN_12345678();\n')
            (root / 'reconstruction/Toy.h').write_text('// Toy: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@abc, MIT)\n')
            from unittest.mock import patch
            with patch.object(attempt.pipeline, 'REPO', root):
                lines = attempt.publication_warnings({'compiled': 'reconstruction/Toy.cpp'})
            self.assertTrue(any('decompiler' in line for line in lines), lines)
            self.assertTrue(any('SPDX' in line for line in lines), lines)

    def test_no_warning_no_line(self):
        self.assertEqual(pipeline.compile_warnings(self.log('a.cpp(1): warning C4100: unused\n')), [])
        self.assertEqual(pipeline.compile_warnings('/nonexistent/compile.log'), [])


if __name__ == '__main__':
    unittest.main()
