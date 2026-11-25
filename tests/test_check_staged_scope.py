"""`check.py --staged` judges new unit sources on their own, with the same verdicts as the full lint."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check  # noqa: E402
from lint_reconstruction import lint_tree  # noqa: E402

UNIT = 'reconstruction/misc/Widget'
HEADER = '''// Source exposure: black-box
// Widget, Read: GUESS(low)
#pragma once
class Widget {
public:
    int Read(int value) const;
};
'''
SOURCE = '''// Source exposure: black-box
// Code origin: original toy implementation
// 0x1234 Widget::Read
#include "Widget.h"

int Widget::Read(int value) const { return value + 1; }
'''


def git(root, *args):
    return subprocess.run(['git', *args], cwd=root, check=True, capture_output=True, text=True).stdout


class ScopedStagedTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        git(self.root, 'init', '-q')
        git(self.root, 'config', 'user.email', 'a@example.invalid')
        git(self.root, 'config', 'user.name', 'a')
        self.put('builds/target.json', '{"build_id": "toy"}\n')
        git(self.root, 'add', '--all')
        git(self.root, 'commit', '-qm', 'base')
        self.cpp = SOURCE
        self.h = HEADER

    def tearDown(self):
        self.tmp.cleanup()

    def put(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def stage(self, cpp=None, h=None):
        self.put(UNIT + '.cpp', self.cpp if cpp is None else cpp)
        self.put(UNIT + '.h', self.h if h is None else h)
        git(self.root, 'add', UNIT + '.cpp', UNIT + '.h')

    def scoped(self):
        names = check.scoped_staged_paths(self.root)
        self.assertEqual(names, [UNIT + '.cpp', UNIT + '.h'])
        return check.check_staged_scoped(self.root, names)

    def full_lint(self):
        problems = lint_tree(self.root, [UNIT + '.cpp', UNIT + '.h'])
        return problems

    def test_clean_unit_passes_both_ways(self):
        self.stage()
        self.assertEqual(self.full_lint(), [])
        self.assertEqual(self.scoped(), (2, None))

    def test_lint_failure_has_the_full_lint_verdict(self):
        broken = '\n'.join(l for l in self.cpp.splitlines() if 'Source exposure' not in l) + '\n'
        self.stage(cpp=broken)
        expected = self.full_lint()
        self.assertTrue(expected)
        with self.assertRaises(ValueError) as caught:
            self.scoped()
        self.assertIn(expected[0], str(caught.exception))

    def test_blob_scan_failure_is_reported(self):
        self.stage(cpp=self.cpp + '// PRIVATE DECOMPILER HINT: x\n')
        with self.assertRaisesRegex(ValueError, 'private decompiler'):
            self.scoped()

    def test_scan_reads_the_index_not_the_working_file(self):
        self.stage(cpp=self.cpp + '// PRIVATE DECOMPILER HINT: x\n')
        self.put(UNIT + '.cpp', self.cpp)
        with self.assertRaisesRegex(ValueError, 'private decompiler'):
            self.scoped()

    def test_prereview_reads_origin_from_the_index(self):
        broken = self.cpp.replace('// Code origin: original toy implementation\n', '')
        self.stage(cpp=broken)
        self.put(UNIT + '.cpp', self.cpp)
        self.assertEqual(lint_tree(self.root, [UNIT + '.cpp']), [])
        with self.assertRaisesRegex(ValueError, 'missing reconstruction origin statement'):
            self.scoped()

    def test_prereview_also_checks_edits_to_existing_units(self):
        self.stage()
        git(self.root, 'commit', '-qm', 'unit')
        self.stage(cpp=self.cpp.replace('// Code origin: original toy implementation\n', ''))
        with mock.patch.object(check, 'ROOT', self.root), \
                mock.patch.object(check, 'load', side_effect=AssertionError('metadata validation')):
            with self.assertRaisesRegex(ValueError, 'missing reconstruction origin statement'):
                check.run(staged=True)

    def test_a_named_evidence_file_is_found_from_the_index(self):
        evidence = 'findings/example-evidence.md'
        self.put(evidence, 'note\n')
        git(self.root, 'add', evidence)
        git(self.root, 'commit', '-qm', 'evidence')
        self.stage(cpp=f'// Evidence: {evidence}\n' + self.cpp)
        self.assertEqual(self.full_lint(), [])
        self.assertEqual(self.scoped(), (2, None))

    def test_missing_evidence_file_fails_like_the_full_lint(self):
        self.stage(cpp='// Evidence: findings/absent.md\n' + self.cpp)
        expected = self.full_lint()
        self.assertTrue(expected)
        with self.assertRaises(ValueError) as caught:
            self.scoped()
        self.assertIn(expected[0], str(caught.exception))

    def test_existing_unit_edits_and_metadata_keep_full_validation(self):
        self.stage()
        git(self.root, 'commit', '-qm', 'unit')
        self.put(UNIT + '.h', self.h + '\n')
        git(self.root, 'add', UNIT + '.h')
        self.assertIsNone(check.scoped_staged_paths(self.root))
        git(self.root, 'reset', '-q', '--hard')
        self.put('data/progress.json', '{}\n')
        git(self.root, 'add', 'data/progress.json')
        self.assertIsNone(check.scoped_staged_paths(self.root))

    def test_prose_and_findings_need_no_export_or_heavy_checks(self):
        self.put('docs/draft.md', 'Initial text.\n')
        git(self.root, 'add', 'docs/draft.md')
        git(self.root, 'commit', '-qm', 'prose')
        self.put('docs/draft.md', 'Revised text.\n')
        self.put('findings/synthetic.md', 'Synthetic finding.\n')
        git(self.root, 'add', 'docs/draft.md', 'findings/synthetic.md')
        with mock.patch.object(check, 'ROOT', self.root), \
                mock.patch.object(check.sparse, 'full', side_effect=AssertionError('whole tree')), \
                mock.patch.object(check.local_load, 'heavy', side_effect=AssertionError('heavy slot')):
            self.assertEqual(check.run(staged=True), (2, None))
        self.assertFalse((self.root / '.local/check-exports').exists())
        git(self.root, 'rm', '-f', 'docs/draft.md')
        self.assertIsNone(check.scoped_staged_paths(self.root))

    def test_tooling_scan_checks_staged_blobs_without_a_full_check(self):
        name = 'tools/other.py'
        self.put(name, 'x = 1\n')
        git(self.root, 'add', name)
        with mock.patch.object(check, 'ROOT', self.root), \
                mock.patch.object(check.sparse, 'full', side_effect=AssertionError('whole tree')):
            self.assertEqual(check.run(staged=True), (1, None))
            self.put(name, 'x\0y')
            git(self.root, 'add', name)
            self.put(name, 'x = 1\n')
            with self.assertRaisesRegex(ValueError, 'binary content'):
                check.run(staged=True)

    def test_nothing_staged_is_not_scoped(self):
        self.assertIsNone(check.scoped_staged_paths(self.root))

    def test_a_scoped_check_scans_only_the_staged_blobs(self):
        self.put('docs/big.txt', 'x\0y')
        git(self.root, 'add', 'docs/big.txt')
        git(self.root, 'commit', '-qm', 'bad blob already committed')
        self.stage()
        self.assertEqual(check.check_git(self.root, staged=True, only=[UNIT + '.cpp', UNIT + '.h']), 2)

    @unittest.skipIf(sys.platform == 'win32', 'Windows file names cannot hold the special characters this test creates')
    def test_special_characters_in_a_path_are_literal(self):
        self.put('docs/a*b.txt', 'text\n')
        self.put('docs/axb.txt', 'bin\0\n')
        git(self.root, 'add', 'docs/a*b.txt', 'docs/axb.txt')
        self.assertEqual(check.check_git(self.root, staged=True, only=['docs/a*b.txt']), 1)


if __name__ == '__main__':
    unittest.main()
