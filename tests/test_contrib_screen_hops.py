"""Parent-hop includes and the changed-files-only scope of line-style findings; synthetic sources."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]
import contrib_screen
import contrib_validation

HEADER = '#pragma once\nstruct Widget\n{\n    int count;\n};\n'


def write(root, name, text):
    path = root / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def style(problems):
    return [p for p in problems if 'deterministic screen' in p]


class Hops(unittest.TestCase):
    def test_a_parent_hop_stays_refused_in_a_file_the_change_writes(self):
        blob = b'#include "../core/Base.h"\n'
        self.assertEqual(sorted(contrib_screen.screen(blob, 'reconstruction/a/W.h')),
                         ['include-outside-roots', 'path-or-encoded-escape'])

    def make(self, root, dependent_line):
        write(root, 'reconstruction/core/Base.h', '#pragma once\n// Base.\nstruct Base\n{\n    int x;\n};\n')
        write(root, 'reconstruction/a/Dep.h', '#pragma once\n' + dependent_line + 'struct Dep\n{\n    int y;\n};\n')
        write(root, 'reconstruction/a/Widget.h', HEADER)
        write(root, 'reconstruction/a/Widget.cpp', '#include "Widget.h"\n#include "Dep.h"\n')

    def test_dependent_style_lines_do_not_fail_a_change_that_did_not_write_them(self):
        hop = '#include "../../core/Base.h"\n'
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.make(root, hop)
            self.assertEqual(style(contrib_validation.source_problems(
                root, ['reconstruction/a/Widget.h'], 'build')), [])

    def test_the_same_line_fails_when_the_change_writes_it(self):
        hop = '#include "../../core/Base.h"\n'
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.make(root, hop)
            problems = contrib_validation.source_problems(root, ['reconstruction/a/Dep.h'], 'build')
            self.assertTrue(any('include-outside-roots' in p and 'Dep.h' in p for p in problems), problems)

    def test_non_style_findings_still_fail_on_dependents(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.make(root, '__asm__("nop");\n')
            problems = contrib_validation.source_problems(root, ['reconstruction/a/Widget.h'], 'build')
            self.assertTrue(any('assembly-or-pragma-operator' in p for p in problems), problems)


if __name__ == '__main__':
    unittest.main()
