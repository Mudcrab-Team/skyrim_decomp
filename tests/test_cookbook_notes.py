"""Lesson notes: scope, template checks, the leak scan over notes, `note` and the reminders; synthetic text only."""
import contextlib
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import contrib
import cookbook_notes
import leakgrep
import pr_bot
import test_contrib as fixtures

NOTE = 'docs/cookbook-notes/1de5e0-test-note.md'


def good(**swap):
    text = cookbook_notes.render(0x1de5e0, 'A::B', 'none', 'fixed', '10/12 (aligned_matching_bytes)', 5)
    text = text.replace('TODO (the label the unit declares, or none)', 'none')
    text = text.replace('TODO (one of: ' + ', '.join(cookbook_notes.CAUSES) + ')', 'inlining')
    for heading, body in (('What differed', 'The callee was expanded in place instead of called.'),
                          ('Spellings tried that did not help', 'A local copy of the argument.'),
                          ('Spelling that fixed it', '```cpp\nreturn Helper(x);\n```')):
        start = text.index('## ' + heading)
        end = text.find('\n## ', start + 1)
        end = len(text) if end < 0 else end
        text = text[:start] + f'## {heading}\n\n{body}\n' + text[end:]
    for old, new in swap.items():
        text = text.replace(old, new)
    return text


class Scope(unittest.TestCase):
    def test_note_paths_are_in_scope_and_nothing_else_under_docs(self):
        self.assertTrue(pr_bot.in_scope(NOTE))
        for bad in ('docs/cookbook-notes/README.md', 'docs/cookbook-notes/sub/1de5e0-x.md', 'docs/matching-cookbook.md',
                    'docs/cookbook-notes/1DE5E0-x.md', 'docs/cookbook-notes/1de5e0-x.txt'):
            self.assertFalse(pr_bot.in_scope(bad), bad)

    def test_scope_problem_allows_notes_with_units_and_refuses_other_docs(self):
        unit = {'filename': 'reconstruction/a/B.cpp', 'status': 'added'}
        note = {'filename': NOTE, 'status': 'added'}
        self.assertIsNone(pr_bot.scope_problem([unit, note]))
        self.assertIsNone(pr_bot.scope_problem([note]))
        self.assertEqual(pr_bot.scope_problem([note, {'filename': 'docs/x.md'}]), 'scope')
        self.assertEqual(pr_bot.scope_problem([{'filename': NOTE, 'previous_filename': 'docs/x.md'}]), 'scope')

    def test_a_notes_only_pr_is_its_own_lane_not_tooling(self):
        note = {'filename': NOTE, 'status': 'added'}
        self.assertTrue(pr_bot.notes_lane([note]))
        self.assertFalse(pr_bot.tooling_lane([note]))
        self.assertFalse(pr_bot.notes_lane([note, {'filename': 'reconstruction/a/B.cpp', 'status': 'added'}]))
        self.assertFalse(pr_bot.notes_lane([dict(note, status='removed')]))
        self.assertFalse(pr_bot.notes_lane([dict(note, status='renamed', previous_filename='docs/x.md')]))
        self.assertTrue(pr_bot.tooling_lane([{'filename': 'docs/cookbook-notes/README.md', 'status': 'modified'}]))

    def test_workflow_scope_pattern_matches_the_bot_pattern(self):
        text = (ROOT / '.github/workflows/pr-check.yml').read_text()
        self.assertIn('docs/cookbook-notes/[0-9a-f]{3,8}-[a-z0-9][a-z0-9-]*\\.md', text)
        self.assertIn('cookbook_notes.py --base', text)


class Validate(unittest.TestCase):
    def test_a_finished_note_is_accepted(self):
        self.assertEqual(cookbook_notes.validate(NOTE, good()), [])

    def test_template_placeholders_and_missing_parts_are_refused(self):
        raw = cookbook_notes.render(0x1de5e0, 'A::B', None, 'unsolved', None, 4)
        self.assertIn('unfinished', cookbook_notes.validate(NOTE, raw))
        self.assertIn('template', cookbook_notes.validate(NOTE, '# x\n\nsome prose\n'))
        self.assertIn('outcome', cookbook_notes.validate(NOTE, good(**{'Outcome: fixed': 'Outcome: maybe'})))
        self.assertIn('cause', cookbook_notes.validate(NOTE, good(**{'Cause: inlining': 'Cause: bad luck'})))
        self.assertIn('fix-missing', cookbook_notes.validate(NOTE, good(**{'```cpp\nreturn Helper(x);\n```': 'none'})))
        self.assertIn('bad-name', cookbook_notes.validate('docs/cookbook-notes/x.md', good()))

    def test_unsolved_note_needs_no_fix(self):
        text = good(**{'Outcome: fixed': 'Outcome: unsolved', '```cpp\nreturn Helper(x);\n```': 'none'})
        self.assertEqual(cookbook_notes.validate(NOTE, text), [])

    def test_size_and_long_code_are_refused(self):
        self.assertIn('too-long', cookbook_notes.validate(NOTE, good() + 'word ' * 2000))
        code = '```cpp\n' + 'int a;\n' * 20 + '```'
        self.assertIn('long-code', cookbook_notes.validate(NOTE, good(**{'```cpp\nreturn Helper(x);\n```': code})))

    def test_leak_patterns_in_a_note_are_refused(self):
        run = ' '.join(['0f'] * 16)
        for payload in (run, 'mov eax, [esp+4]', 'FUN_00401000 does this', '/Users/someone/x'):
            codes = cookbook_notes.validate(NOTE, good() + payload + '\n')
            self.assertIn('leak-pattern', codes, payload)

    def test_the_cli_checks_a_git_range(self):
        import tempfile
        with tempfile.TemporaryDirectory() as tmp:
            def git(*a):
                return subprocess.run(['git', '-C', tmp, '-c', 'user.name=t', '-c', 'user.email=t@t.invalid', *a],
                                      check=True, capture_output=True, text=True).stdout.strip()
            git('init', '-q')
            Path(tmp, 'x').write_text('x')
            git('add', '.')
            git('commit', '-q', '-m', 'base')
            base = git('rev-parse', 'HEAD')
            note = Path(tmp, NOTE)
            note.parent.mkdir(parents=True)
            note.write_text(good() + 'mov eax, [esp+4]\n')
            git('add', '.')
            git('commit', '-q', '-m', 'bad')
            out = io.StringIO()
            with contextlib.redirect_stdout(out):
                self.assertEqual(cookbook_notes.main(['--base', base, '--head', 'HEAD', '--repo', tmp]), 1)
            self.assertNotIn('mov', out.getvalue())
            note.write_text(good())
            git('commit', '-qam', 'fixed')
            with contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(cookbook_notes.main(['--base', base, '--head', 'HEAD', '--repo', tmp]), 0)

    def test_the_bot_leak_scan_reads_a_notes_diff(self):
        diff = f'+++ b/{NOTE}\n@@ -0,0 +1 @@\n+' + ' '.join(['0f'] * 16) + '\n'
        self.assertEqual([c for _f, _n, c in leakgrep.scan_diff(diff)], ['hex-run'])

    def test_the_documented_example_note_passes_the_check(self):
        text = (ROOT / 'docs/cookbook-notes/README.md').read_text()
        block = text[text.index('<!-- example-note -->'):text.index('<!-- /example-note -->')]
        example = block.split('```markdown\n', 1)[1].rsplit('```', 1)[0]
        self.assertEqual(cookbook_notes.validate('docs/cookbook-notes/123abc-example-helper.md', example), [])

    def test_the_card_and_guide_have_a_lessons_section(self):
        for name in ('docs/contributor-card.md', 'docs/contributing-agent.md'):
            text = (ROOT / name).read_text()
            self.assertIn('Send your lessons', text, name)
            self.assertIn('./sr lesson', text, name)

    def test_readme_lists_every_cause(self):
        readme = (ROOT / 'docs/cookbook-notes/README.md').read_text()
        for cause in cookbook_notes.CAUSES:
            self.assertIn(cause, readme)


class Credits(unittest.TestCase):
    def test_credit_comes_from_the_co_author_trailer_of_the_commit_that_added_the_note(self):
        import lesson_credits
        with tempfile.TemporaryDirectory() as tmp:
            def git(*args):
                return subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@example.invalid', *args], cwd=tmp,
                                      check=True, capture_output=True, text=True).stdout
            git('init', '-q')
            notes = Path(tmp, 'docs/cookbook-notes')
            notes.mkdir(parents=True)
            (notes / '1de5e0-first.md').write_text(good())
            (notes / 'README.md').write_text('x')
            git('add', '.')
            git('commit', '-q', '-m', 'merge', '-m', 'Co-authored-by: Alice <12+Alice@users.noreply.github.com>')
            (notes / '2de5e0-second.md').write_text(good())
            git('add', '.')
            git('commit', '-q', '-m', 'merge', '-m', 'no trailer here')
            (notes / '1de5e0-first.md').unlink()
            git('add', '-A')
            git('commit', '-q', '-m', 'fold')
            self.assertEqual(lesson_credits.credits(tmp), {'alice': ['docs/cookbook-notes/1de5e0-first.md']})
            with contextlib.redirect_stdout(io.StringIO()) as out:
                self.assertEqual(lesson_credits.main(['--repo', tmp]), 0)
            self.assertEqual(out.getvalue().strip(), '@alice: 1 lesson note')


class StickyLine(unittest.TestCase):
    """The one sticky comment asks for a note when functions mismatched and none came along, and thanks for one."""
    HEAD = 'a' * 40

    def body(self, **extra):
        decision = dict(blocked=None, merge=True, verdicts={0x10: 'matched', 0x20: 'fail:host2'}, **extra)
        return pr_bot.comment_body(self.HEAD, decision)

    def test_a_mismatch_without_a_note_gets_one_ask_line(self):
        text = self.body(lesson_note=False)
        self.assertEqual(text.count('Lesson note:'), 1)
        self.assertIn('./sr lesson <rva>', text)
        self.assertIn('never blocks', text)

    def test_a_mismatch_with_a_note_gets_no_ask(self):
        text = self.body(lesson_note=True)
        self.assertNotIn('Lesson note:', text)
        self.assertIn('Lesson note merged', text)

    def test_no_mismatch_no_ask_and_no_thanks_without_a_note(self):
        decision = dict(blocked=None, merge=True, verdicts={0x10: 'matched'}, lesson_note=False)
        text = pr_bot.comment_body(self.HEAD, decision)
        self.assertNotIn('esson note', text)

    def test_a_review_rejection_is_not_a_near_miss(self):
        decision = dict(blocked=None, merge=True, verdicts={0x10: 'matched', 0x20: 'fail:review'}, lesson_note=False)
        self.assertNotIn('Lesson note:', pr_bot.comment_body(self.HEAD, decision))

    def test_a_blocked_pr_gets_no_thanks_and_no_ask(self):
        decision = dict(blocked='regression', merge=False, verdicts={0x20: 'fail:host2'}, lesson_note=True,
                        regressed=[0x20], regressed_hosts={})
        self.assertNotIn('esson note', pr_bot.comment_body(self.HEAD, decision))

    def test_the_ask_names_a_real_command_and_a_real_readme(self):
        self.assertTrue((ROOT / 'docs/cookbook-notes/README.md').is_file())
        self.assertIn('lesson', contrib.parser().format_help())
        self.assertIn('docs/cookbook-notes/README.md', pr_bot.LESSON_ASK)


class NoteCommand(fixtures.SubmitTests):
    def run_cli(self, *argv):
        ctx = self.ctx(repo=self.repo, github=fixtures.FakeGitHub(), runner=self.runner)
        with contextlib.redirect_stdout(io.StringIO()) as output:
            code = contrib.main(['--json', *argv], ctx=ctx)
        return code, json.loads(output.getvalue())

    def fail_the_function(self):
        self.summary['functions'][0]['result'] = 'fail'
        self.summary['progress'] = {f'0x{self.RVA:x}': {'metric': 'aligned_matching_bytes', 'best': 7, 'total': 9}}
        (self.tdir / 'runs' / '001').mkdir(parents=True)
        self.write()

    def test_note_prefills_the_template_from_the_task(self):
        self.fail_the_function()
        code, result = self.run_cli('note', self.tdir.name)
        self.assertEqual(code, contrib.OK)
        path = self.repo / result['data']['notes'][0] if 'data' in result else self.repo / result['notes'][0]
        text = path.read_text()
        self.assertRegex(path.name, r'^1de5e0-[a-z0-9-]+\.md$')
        self.assertIn('- Outcome: unsolved', text)
        self.assertIn('- Best score: 7/9 (aligned_matching_bytes)', text)
        self.assertIn('- Attempts: 1', text)
        self.assertIn('unfinished', cookbook_notes.validate(path.relative_to(self.repo).as_posix(), text))
        again = self.run_cli('note', self.tdir.name)[0]
        self.assertEqual(again, contrib.OK)

    def test_lesson_writes_the_template_for_a_task_function(self):
        self.fail_the_function()
        code, result = self.run_cli('lesson', f'0x{self.RVA:x}')
        self.assertEqual(code, contrib.OK)
        rel = (result.get('data') or result)['notes'][0]
        text = (self.repo / rel).read_text()
        self.assertIn('- Outcome: unsolved', text)
        self.assertIn('7/9 (aligned_matching_bytes)', text)
        self.assertTrue(cookbook_notes.NOTE_FILE.fullmatch(rel), rel)
        self.assertIn('unfinished', cookbook_notes.validate(rel, text))

    def test_lesson_for_a_function_with_no_task_writes_a_bare_template_and_keeps_an_existing_one(self):
        code, result = self.run_cli('lesson', '0xabc123', '--name', 'Syn::Fn', '--outcome', 'fixed', '--attempts', '5')
        self.assertEqual(code, contrib.OK)
        rel = (result.get('data') or result)['notes'][0]
        self.assertEqual(rel, 'docs/cookbook-notes/abc123-syn-fn.md')
        text = (self.repo / rel).read_text()
        self.assertIn('- Outcome: fixed', text)
        self.assertIn('- Attempts: 5', text)
        (self.repo / rel).write_text('kept\n')
        self.run_cli('lesson', '0xabc123', '--name', 'Syn::Fn')
        self.assertEqual((self.repo / rel).read_text(), 'kept\n')

    def test_the_reminders_name_the_lesson_command(self):
        for n in range(1, contrib.NOTE_ATTEMPTS + 1):
            (self.tdir / 'runs' / f'{n:03d}').mkdir(parents=True)
        hard = contrib.note_reminders(self.ctx(repo=self.repo), self.tdir, self.task,
                                      self.summary['functions'], contrib.task_attempts(self.tdir))
        self.assertIn(f'lesson 0x{self.RVA:x}', hard[0])
        self.summary['functions'][0]['result'] = 'fail'
        near = contrib.note_reminders(self.ctx(repo=self.repo), self.tdir, self.task,
                                      self.summary['functions'], contrib.task_attempts(self.tdir))
        self.assertEqual(len(near), 1)
        self.assertIn('lesson <rva>', near[0])

    def test_a_clean_first_pass_needs_no_note_but_a_hard_won_one_does(self):
        code, _ = self.run_cli('note', self.tdir.name)
        self.assertEqual(code, contrib.USAGE)
        for n in range(1, contrib.NOTE_ATTEMPTS + 1):
            (self.tdir / 'runs' / f'{n:03d}').mkdir(parents=True)
        lines = contrib.note_reminders(self.ctx(repo=self.repo), self.tdir, self.task,
                                       self.summary['functions'], contrib.task_attempts(self.tdir))
        self.assertEqual(len(lines), 1)
        self.assertIn('pass after', lines[0])
        self.assertIn('matching-cookbook.md', lines[0])

    def test_preflight_reminds_and_accepts_a_finished_note_in_the_submission(self):
        self.fail_the_function()
        _code, result = self.run_cli('note', self.tdir.name)
        rel = result.get('notes') or result['data']['notes']
        path = self.repo / rel[0]
        path.write_text(good())
        self.assertEqual(contrib.pending_notes(self.ctx(repo=self.repo)), [rel[0]])
        code, result = self.run_cli('preflight', '--base', 'HEAD')
        blockers = result.get('blockers') or result.get('data', {}).get('blockers', [])
        self.assertFalse([b for b in blockers if 'lesson note' in b], blockers)
        path.write_text(good() + 'mov eax, [esp+4]\n')
        _code, result = self.run_cli('preflight', '--base', 'HEAD')
        blockers = result.get('blockers') or result.get('data', {}).get('blockers', [])
        self.assertTrue([b for b in blockers if 'lesson note refused' in b and 'leak-pattern' in b], blockers)


if __name__ == '__main__':
    unittest.main()
