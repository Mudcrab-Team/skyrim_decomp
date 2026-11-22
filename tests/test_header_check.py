"""tools/header_check.py holds only the headers a pull request adds or changes to the compact-header rule."""
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import header_check  # noqa: E402

OLD = ''.join(f'// line {i}\n' for i in range(20)) + '// Widget: GUESS(low)\n#pragma once\nclass Widget {};\n'
NEW = '// Source exposure: binary-analysis\n// Widget: GUESS(low)\n#pragma once\nclass Widget {};\n'


def run(root, *args):
    return subprocess.run(['git', '-C', str(root), '-c', 'user.name=t', '-c', 'user.email=t@example.invalid',
                           '-c', 'commit.gpgsign=false', *args], capture_output=True, text=True, check=True).stdout.strip()


class HeaderCheckTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        run(self.root, 'init', '-q', '-b', 'main')
        self.write('reconstruction/a/Widget.h', OLD)
        self.write('reconstruction/a/Other.h', OLD)
        run(self.root, 'add', '.')
        run(self.root, 'commit', '-q', '-m', 'base')
        self.base = run(self.root, 'rev-parse', 'HEAD')

    def tearDown(self):
        self.tmp.cleanup()

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def head(self):
        run(self.root, 'add', '.')
        run(self.root, 'commit', '-q', '-m', 'change')
        return header_check.check(self.root, self.base, run(self.root, 'rev-parse', 'HEAD'))

    def test_unchanged_long_header_is_not_blocked_when_only_the_body_changes(self):
        self.write('reconstruction/a/Widget.h', OLD + 'int x;\n')
        self.assertEqual(self.head(), [])

    def test_changed_long_header_is_refused_with_the_fix(self):
        self.write('reconstruction/a/Widget.h', OLD.replace('line 3', 'line three'))
        problems = self.head()
        self.assertEqual(len(problems), 1)
        self.assertIn('keep at most', problems[0])

    def test_new_long_unit_is_refused_and_a_short_one_passes(self):
        self.write('reconstruction/a/New.h', OLD)
        self.write('reconstruction/a/Short.h', NEW)
        problems = self.head()
        self.assertEqual(len(problems), 1)
        self.assertIn('New.h', problems[0])

    def test_a_change_that_only_shortens_a_long_header_passes(self):
        self.write('reconstruction/a/Widget.h', OLD.replace('// line 3\n', ''))
        self.assertEqual(self.head(), [])

    def test_ci_hash_binding_lines_do_not_count_but_other_lines_still_do(self):
        five = ''.join(f'// note {i}\n' for i in range(6))
        binding = '// CI hash: 0x32dde4 ??_ETESModel@@WCA@EAAPEAXI@Z\n'
        tail = '// Widget: GUESS(low)\n#pragma once\nclass Widget {};\n'
        self.write('reconstruction/a/Bound.h', five + binding + '// CI hash: 0x32dde8 ??_ETESModel@@WCA@EAAPEAXI@Z\n' + tail)
        self.write('reconstruction/a/Spaced.h', five + '// CI hash:0x32dde4 Sym\n' + tail)
        self.write('reconstruction/a/Prose.h', five + '// CI hash: 0x32dde4 two words\n' + tail)
        self.write('reconstruction/a/NoRva.h', five + '// CI hash: Sym\n' + tail)
        self.write('reconstruction/a/Trailing.h', five + '// CI hash: 0x32dde4 Sym extra\n' + tail)
        problems = self.head()
        self.assertEqual(sorted(p.split(':')[0].rsplit('/', 1)[1] for p in problems),
                         ['NoRva.h', 'Prose.h', 'Trailing.h'])

    def test_unprintable_path_is_not_echoed(self):
        self.write('reconstruction/a/we ird;$(x).h', OLD)
        problems = self.head()
        self.assertEqual(len(problems), 1)
        self.assertNotIn('ird', problems[0])


if __name__ == '__main__':
    unittest.main()
