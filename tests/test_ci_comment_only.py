"""The hash job asks for no compile of a unit file whose change is only in prose comments."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import ci_target_hash_check as ci  # noqa: E402
from test_lint_reconstruction import HEADER, SOURCE, BUILD  # noqa: E402

CPP = 'reconstruction/misc/Widget.cpp'
HDR = 'reconstruction/misc/Widget.h'


def run(root, *args):
    return subprocess.run(['git', '-C', str(root), '-c', 'user.name=t', '-c', 'user.email=t@example.invalid',
                           '-c', 'commit.gpgsign=false', *args], capture_output=True, text=True, check=True).stdout.strip()


class CommentOnlyTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name) / 'repo'
        self.root.mkdir()
        run(self.root, 'init', '-q', '-b', 'main')
        files = {'builds/target.json': json.dumps(dict(build_id=BUILD)), 'findings/x.md': 'x\n', 'reports/x.md': 'x\n',
                 CPP: SOURCE, HDR: HEADER}
        for name, text in files.items():
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text, newline='\n')
        run(self.root, 'add', '.')
        run(self.root, 'commit', '-q', '-m', 'base')
        self.base = run(self.root, 'rev-parse', 'HEAD')

    def tearDown(self):
        self.tmp.cleanup()

    def prepare(self, **edits):
        for name, text in edits.items():
            (self.root / name.replace('__', '/').replace('_cpp', '.cpp').replace('_h', '.h')).write_text(text, newline='\n')
        run(self.root, 'add', '.')
        run(self.root, 'commit', '-q', '-m', 'head')
        head = run(self.root, 'rev-parse', 'HEAD')
        run(self.root, 'checkout', '-q', self.base)
        work = Path(self.tmp.name) / f'work-{head[:8]}'
        return ci.prepare(self.root, self.base, head, work)[1]

    def test_prose_only_change_asks_for_nothing(self):
        changed = self.prepare(reconstruction__misc__Widget_cpp=SOURCE.replace('#include', '// more prose\n#include'))
        self.assertEqual(changed, [])

    def test_code_change_still_asks(self):
        changed = self.prepare(reconstruction__misc__Widget_cpp=SOURCE.replace('return value', 'return value + 1'))
        self.assertEqual(changed, [CPP])

    def test_provenance_comment_change_still_asks(self):
        changed = self.prepare(reconstruction__misc__Widget_h=HEADER.replace('GUESS(low)', 'GUESS(high)'))
        self.assertEqual(changed, [HDR])

    def test_adding_a_hash_request_still_asks(self):
        request = '// CI hash: 0x10 ?Value@Widget@@QEAAHXZ\n'
        changed = self.prepare(reconstruction__misc__Widget_cpp=SOURCE.replace('#include', request + '#include', 1))
        self.assertEqual(changed, [CPP])

    def commit_files(self, **files):
        for name, text in files.items():
            path = self.root / name.replace('__', '/').replace('_cpp', '.cpp').replace('_py', '.py').replace('_h', '.h')
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text, newline='\n')
        run(self.root, 'add', '.')
        run(self.root, 'commit', '-q', '-m', 'head')
        head = run(self.root, 'rev-parse', 'HEAD')
        run(self.root, 'checkout', '-q', self.base)
        return head

    def test_a_tooling_only_pr_reads_nothing_and_skips_cleanly(self):
        head = self.commit_files(tools__x_py='print(1)\n', tests__test_x_py='pass\n')
        tree, changed = ci.prepare(self.root, self.base, head, Path(self.tmp.name) / 'work-tool')
        self.assertEqual((tree, changed), (self.root, []))

    def test_a_pr_mixing_units_and_tooling_is_still_refused(self):
        head = self.commit_files(tools__x_py='print(1)\n', reconstruction__misc__Widget_cpp=SOURCE + '\n')
        with self.assertRaises(ValueError):
            ci.prepare(self.root, self.base, head, Path(self.tmp.name) / 'work-mixed')

    def test_a_lint_failure_carries_the_file_line_and_message(self):
        bare = HEADER.replace('// Widget, Get, value: GUESS(low)', '// GUESS(low): no names before the label')
        head = self.commit_files(reconstruction__misc__Widget_h=bare)
        with self.assertRaises(ci.LintFailure) as caught:
            ci.prepare(self.root, self.base, head, Path(self.tmp.name) / 'work-lint')
        self.assertTrue(any(f.startswith(f'{HDR}:2: ') and 'label outside the v2 grammar' in f
                            for f in caught.exception.findings))
        self.assertIsInstance(caught.exception, ValueError)

    def test_the_summary_names_the_findings(self):
        text = ci.summary_text(dict(error='LintFailure', findings=[f'{HDR}:2: label outside the v2 grammar']))
        self.assertIn(f'- {HDR}:2: label outside the v2 grammar', text)


if __name__ == '__main__':
    unittest.main()
