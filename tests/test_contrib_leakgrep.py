"""The local intake check applies leakgrep's line rules to changed units."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import contrib_validation  # noqa: E402


class LocalLeakgrep(unittest.TestCase):
    def test_decompiler_style_parameter_name_is_reported_with_its_line(self):
        found = contrib_validation.leakgrep_diagnostics(b'int f(int ok)\n{\n    return param_1;\n}\n', 'reconstruction/x/A.cpp')
        self.assertEqual(len(found), 1)
        self.assertIn('A.cpp:3', found[0])
        self.assertIn('decompiler-ident', found[0])

    def test_plain_source_is_clean(self):
        self.assertEqual(contrib_validation.leakgrep_diagnostics(b'int f(int count)\n{\n    return count;\n}\n', 'reconstruction/x/A.cpp'), [])


if __name__ == '__main__':
    unittest.main()
