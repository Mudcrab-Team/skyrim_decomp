import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import contrib_publication as pub  # noqa: E402


def unit_text(rva):
    return f'// SPDX-License-Identifier: CC0-1.0\n// 0x{rva:x} Thing::Get\nint Get();\n'


class FunctionCap(unittest.TestCase):
    """The per-PR cap counts functions the way the bot does, not files."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.git('init', '-q', '-b', 'main')
        self.git('config', 'user.email', 'a@example.invalid')
        self.git('config', 'user.name', 'a')
        (self.root / 'README').write_text('x\n')
        self.git('add', '-A')
        self.git('commit', '-q', '-m', 'base')
        self.base = self.git('rev-parse', 'HEAD').strip()

    def tearDown(self):
        self.tmp.cleanup()

    def git(self, *args):
        return subprocess.run(['git', *args], cwd=self.root, check=True, capture_output=True, text=True).stdout

    def commit_units(self, count, first=0x1000):
        directory = self.root / 'reconstruction' / 'area'
        directory.mkdir(parents=True, exist_ok=True)
        for i in range(count):
            for ext in ('h', 'cpp'):
                (directory / f'U{i}x.{ext}').write_text(unit_text(first + i))
        self.git('add', '-A')
        self.git('commit', '-q', '-m', 'units')
        return self.git('rev-parse', 'HEAD').strip()

    def screened(self, head, **kw):
        return pub.screen_publication(self.root, self.base, head, **kw)

    def test_more_files_than_the_function_cap_pass_when_functions_fit(self):
        # 70 units = 140 files, over the old 120-file cap, but only 70 functions
        head = self.commit_units(70)
        self.assertEqual(len(self.screened(head)['files']), 140)

    def test_function_count_over_the_cap_is_rejected(self):
        head = self.commit_units(5)
        with self.assertRaisesRegex(pub.PublicationRejected, 'function-count resource cap'):
            self.screened(head, max_functions=4, max_files=100)

    def test_function_count_at_the_cap_passes(self):
        head = self.commit_units(5)
        self.assertEqual(len(self.screened(head, max_functions=5)['files']), 10)

    def test_a_function_in_both_header_and_source_counts_once(self):
        head = self.commit_units(3)
        self.assertEqual(pub.new_claimed_functions(
            lambda *a: subprocess.run(['git', *a], cwd=self.root, check=True, capture_output=True).stdout,
            self.base, head, [{'path': f'reconstruction/area/U{i}x.{e}'} for i in range(3) for e in ('h', 'cpp')]), 3)

    def test_functions_already_in_the_changed_files_are_not_new(self):
        head = self.commit_units(4)
        self.base = head
        (self.root / 'reconstruction/area/U0x.cpp').write_text(unit_text(0x1000) + '// edit\n')
        self.git('add', '-A')
        self.git('commit', '-q', '-m', 'edit')
        edit = self.git('rev-parse', 'HEAD').strip()
        self.assertEqual(len(self.screened(edit, max_functions=1)['files']), 1)

    def test_file_count_stays_a_resource_guard(self):
        head = self.commit_units(3)
        with self.assertRaisesRegex(pub.PublicationRejected, 'file-count resource cap'):
            self.screened(head, max_functions=100, max_files=5)


if __name__ == '__main__':
    unittest.main()
