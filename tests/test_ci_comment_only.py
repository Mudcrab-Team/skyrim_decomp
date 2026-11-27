"""The hash job asks for no compile of a unit file whose change is only in prose comments."""
import contextlib
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import ci_target_hash_check as ci  # noqa: E402
from test_lint_reconstruction import HEADER, SOURCE, BUILD  # noqa: E402

CPP = 'reconstruction/misc/Widget.cpp'
HDR = 'reconstruction/misc/Widget.h'
RECIPE = 'reconstruction/recipes/fixture-root-includes.json'


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
                 CPP: SOURCE, HDR: HEADER, RECIPE: '{}\n'}
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

    def test_a_recipe_only_change_still_asks(self):
        recipe = f'// Recipe: {RECIPE}\n'
        changed = self.prepare(reconstruction__misc__Widget_cpp=SOURCE.replace('#include', recipe + '#include', 1))
        self.assertEqual(changed, [CPP])

    def test_prepare_uses_the_named_base_without_switching_the_checkout(self):
        head = self.commit_files(reconstruction__misc__Widget_cpp=SOURCE.replace('return value', 'return value + 1'))
        elsewhere = self.commit_files(reconstruction__misc__Widget_h=HEADER.replace('GUESS(low)', 'GUESS(high)'))
        run(self.root, 'checkout', '-q', elsewhere)
        work = Path(self.tmp.name) / 'work-alternate'
        tree, changed = ci.prepare(self.root, self.base, head, work)
        self.assertEqual(changed, [CPP])
        self.assertEqual((tree / HDR).read_text(), HEADER)
        self.assertEqual((work / 'base' / CPP).read_text(), SOURCE)
        self.assertEqual(run(self.root, 'rev-parse', 'HEAD'), elsewhere)

    def test_repeated_prepare_reuses_checkout_and_clears_the_previous_head(self):
        added = 'reconstruction/misc/Other.h'
        head = self.commit_files(**{added: HEADER.replace('Widget', 'Other')},
                                 reconstruction__misc__Widget_h=HEADER.replace('GUESS(low)', 'GUESS(high)'))
        work = Path(self.tmp.name) / 'work-reused'
        tree, changed = ci.prepare(self.root, self.base, head, work)
        self.assertCountEqual(changed, [added, HDR])
        self.assertTrue((tree / added).exists())
        self.assertNotEqual((tree / HDR).read_text(), HEADER)

        next_base = self.commit_files(reconstruction__misc__Widget_h=HEADER + '// trusted base edit\n')
        run(self.root, 'checkout', '-q', next_base)
        next_head = self.commit_files(reconstruction__misc__Widget_cpp=SOURCE.replace('return value', 'return value + 1'))
        metadata = (tree / '.git').read_bytes()
        reused, changed = ci.prepare(self.root, next_base, next_head, work)
        self.assertEqual((reused, changed), (tree, [CPP]))
        self.assertEqual((reused / '.git').read_bytes(), metadata)
        self.assertEqual(run(reused, 'rev-parse', 'HEAD'), next_base)
        self.assertEqual((reused / HDR).read_text(), HEADER + '// trusted base edit\n')
        self.assertFalse((reused / added).exists())

    def test_reused_include_index_follows_base_and_head_changes(self):
        other = 'reconstruction/misc/Other.h'
        header = HEADER.replace('Widget', 'Other')
        head = self.commit_files(reconstruction__misc__Widget_cpp=SOURCE.replace('return value', 'return value + 1'))
        work = Path(self.tmp.name) / 'work-includes'
        tree, changed = ci.prepare(self.root, self.base, head, work)
        self.assertEqual({ref['unit'] for ref in ci.requests(tree, changed, {}, work)}, {CPP})

        next_base = self.commit_files(**{other: header}, reconstruction__misc__Widget_cpp=SOURCE.replace(
            '#include "Widget.h"', '#include "Widget.h"\n#include "Other.h"'))
        run(self.root, 'checkout', '-q', next_base)
        next_head = self.commit_files(**{other: header.replace('GUESS(low)', 'GUESS(high)')})
        tree, changed = ci.prepare(self.root, next_base, next_head, work)
        self.assertEqual(changed, [other])
        self.assertEqual({ref['unit'] for ref in ci.requests(tree, changed, {}, work)}, {CPP})

    def test_prepare_reports_an_invalid_revision(self):
        out = Path(self.tmp.name) / 'result.json'
        output = io.StringIO()
        with patch.object(ci, 'ROOT', self.root), patch.dict(ci.os.environ, GITHUB_STEP_SUMMARY=''), \
                contextlib.redirect_stdout(output):
            code = ci.main(['prepare', '--base', self.base, '--head', 'HEAD',
                            '--work', str(out.parent / 'work'), '--out', str(out)])
        self.assertEqual(code, 1)
        error = json.loads(out.read_text())['error']
        self.assertIn('full commit SHAs', error)
        self.assertIn(error, output.getvalue())

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

    def test_the_note_pattern_matches_the_notes_module(self):
        import cookbook_notes
        self.assertEqual(ci.NOTE_FILE.pattern, cookbook_notes.NOTE_FILE.pattern)

    def test_a_lesson_note_beside_a_unit_does_not_fail_intake(self):
        head = self.commit_files(**{'docs/cookbook-notes/abc123-a-note.md': 'note\n'},
                                 reconstruction__misc__Widget_cpp=SOURCE.replace('return value', 'return value + 1'))
        self.assertEqual(ci.prepare(self.root, self.base, head, Path(self.tmp.name) / 'work-note')[1], [CPP])

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
