"""The family generator index, the bot's family-note line and the credits that read the index."""
import contextlib
import io
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import lesson_credits
import pr_bot

INDEX = ROOT / 'docs/generators.md'
HEAD = 'a' * 40


def generator_files():
    return sorted(p.relative_to(ROOT).as_posix() for p in (ROOT / 'tools').glob('*_generate*.py'))


def indexed():
    return {path: (login, findings) for path, login, findings in lesson_credits.index_rows(INDEX.read_text())}


class Index(unittest.TestCase):
    def test_every_generator_has_a_row(self):
        missing = [f for f in generator_files() if f not in indexed()]
        self.assertEqual(missing, [], 'add a row to docs/generators.md for each of these')

    def test_every_row_names_a_generator_that_exists(self):
        gone = [p for p in indexed() if not (ROOT / p).is_file()]
        self.assertEqual(gone, [])

    def test_every_row_has_a_credit_and_its_findings_exist(self):
        for path, (login, findings) in indexed().items():
            self.assertTrue(login, path)
            for finding in findings:
                self.assertTrue((ROOT / finding).is_file(), f'{path}: {finding}')

    def test_every_row_carries_a_command_and_a_verification(self):
        for line in INDEX.read_text().splitlines():
            if not re.match(r'^\| `tools/\S*_generate\S*\.py`', line):
                continue
            cells = [c.strip() for c in line.strip().strip('|').split('|')]
            self.assertEqual(len(cells), 6, line[:80])
            self.assertTrue(all(cells), line[:80])
            self.assertIn('python3 tools/', cells[3], line[:80])

    def test_the_guides_link_the_index(self):
        for name in ('docs/contributing-agent.md', 'docs/contributor-card.md', 'docs/matching-cookbook.md'):
            self.assertIn('generators.md', (ROOT / name).read_text(), name)


class FamilyLine(unittest.TestCase):
    def decision(self, **extra):
        return dict(dict(blocked=None, merge=True, verdicts={}), **extra)

    def lines(self, **extra):
        return pr_bot.family_lines(self.decision(**extra))

    def test_a_changed_generator_without_a_note_gets_one_advisory_line(self):
        found = self.lines(generator=True, family_note=False)
        self.assertEqual(len(found), 1)
        self.assertIn('family generator', found[0])
        self.assertIn('./sr lesson', found[0])
        self.assertIn('never blocks', found[0])

    def test_a_note_in_the_pr_silences_the_line(self):
        self.assertEqual(self.lines(generator=True, family_note=True), [])

    def test_fifty_functions_from_one_area_ask_and_forty_nine_do_not(self):
        def landed(count, area='reconstruction/wrappers'):
            return dict(verdicts={0x1000 + i: 'matched' for i in range(count)},
                        unit_files={0x1000 + i: f'{area}/U{i % 3}.cpp' for i in range(count)})
        self.assertEqual(len(pr_bot.family_lines(dict(landed(50), family_note=False))), 1)
        self.assertIn('lands 50 functions', pr_bot.family_lines(dict(landed(50)))[0])
        self.assertEqual(pr_bot.family_lines(dict(landed(49))), [])

    def test_the_count_is_per_area_and_only_for_matched_functions(self):
        verdicts = {i: 'matched' for i in range(30)} | {100 + i: 'matched' for i in range(30)}
        units = {i: 'reconstruction/a/X.cpp' for i in range(30)} | {100 + i: 'reconstruction/b/Y.cpp' for i in range(30)}
        self.assertEqual(pr_bot.family_size(dict(verdicts=verdicts, unit_files=units)), 30)
        failed = {i: 'fail:host2' for i in range(60)}
        self.assertEqual(pr_bot.family_size(dict(verdicts=failed, unit_files={i: 'reconstruction/a/X.cpp' for i in range(60)})), 0)

    def test_string_keys_from_a_stored_decision_count_too(self):
        verdicts = {str(i): 'matched' for i in range(50)}
        units = {str(i): 'reconstruction/a/X.cpp' for i in range(50)}
        self.assertEqual(pr_bot.family_size(dict(verdicts=verdicts, unit_files=units)), 50)

    def test_generator_paths(self):
        for name in ('tools/form_factory_generate.py', 'tools/static_resource_generate_v2.py'):
            self.assertTrue(pr_bot.generator_changed([dict(filename=name, status='modified')]), name)
        for name in ('tools/leaf_family_batch.py', 'tests/test_form_factory_generate.py', 'tools/x_generate.txt',
                     'tools/sub/x_generate.py'):
            self.assertFalse(pr_bot.generator_changed([dict(filename=name, status='added')]), name)
        self.assertFalse(pr_bot.generator_changed([dict(filename='tools/a_generate.py', status='removed')]))

    def test_notes_and_findings_count_as_a_family_note(self):
        self.assertTrue(pr_bot.family_note_present([dict(filename='findings/form-factory-destructors.md', status='added')]))
        self.assertTrue(pr_bot.family_note_present([dict(filename='docs/cookbook-notes/1de5e0-x.md', status='added')]))
        self.assertFalse(pr_bot.family_note_present([dict(filename='docs/cookbook-notes/README.md', status='added')]))
        self.assertFalse(pr_bot.family_note_present([dict(filename='findings/x.md', status='removed')]))

    def test_the_sticky_comment_carries_the_line_once_next_to_the_mismatch_ask(self):
        verdicts = {0x100 + i: 'matched' for i in range(60)} | {0x20: 'fail:host2'}
        decision = self.decision(verdicts=verdicts, lesson_note=False, family_note=False, generator=False,
                                 unit_files={r: 'reconstruction/w/A.cpp' for r in verdicts})
        text = pr_bot.comment_body(HEAD, decision)
        self.assertEqual(text.count('Family note:'), 1)
        self.assertEqual(text.count('Lesson note:'), 1)

    def test_a_lesson_note_replaces_the_ask_with_the_thanks(self):
        decision = self.decision(verdicts={0x100 + i: 'matched' for i in range(60)}, lesson_note=True, family_note=True,
                                 unit_files={0x100 + i: 'reconstruction/w/A.cpp' for i in range(60)})
        text = pr_bot.comment_body(HEAD, decision)
        self.assertNotIn('Family note:', text)
        self.assertIn('Lesson note merged', text)

    def test_a_blocked_pr_gets_no_family_line(self):
        decision = dict(blocked='regression', merge=False, verdicts={}, generator=True, family_note=False,
                        regressed=[], regressed_hosts={})
        self.assertNotIn('Family note:', pr_bot.comment_body(HEAD, decision))


class ToolingComment(unittest.TestCase):
    """The tooling lane's one comment gets the line when it changes a generator and has no note."""
    def comment(self, files):
        import test_pr_bot as fixtures
        with tempfile.TemporaryDirectory() as tmp:
            bot = fixtures.FakeBot(Path(tmp), files=files)
            bot.process(fixtures.PR)
            sent = bot.seen('gh', 'pr', 'comment')
            self.assertEqual(len(sent), 1)
            return sent[0][-1]

    def test_a_generator_pr_without_a_note_is_asked_once(self):
        text = self.comment([dict(filename='tools/a_generate.py', status='added'),
                             dict(filename='tests/test_a_generate.py', status='added')])
        self.assertIn('tooling PR', text)
        self.assertEqual(text.count('Family note:'), 1)

    def test_a_generator_pr_with_a_findings_note_is_not_asked(self):
        text = self.comment([dict(filename='tools/a_generate.py', status='added'),
                             dict(filename='findings/a-family.md', status='added')])
        self.assertNotIn('Family note:', text)

    def test_an_ordinary_tooling_pr_is_not_asked(self):
        self.assertNotIn('Family note:', self.comment([dict(filename='tools/ghidra/x.py', status='added')]))


class Credits(unittest.TestCase):
    ROWS = ('| `tools/a_generate.py` | things | checks | `python3 tools/a_generate.py` | @Alice | '
            '[a-things](../findings/a-things.md) |\n'
            '| `tools/b_generate_v2.py` | more | checks | `python3 tools/b_generate_v2.py` | @alice | - |\n'
            '| `tools/c_generate.py` | other | checks | `python3 tools/c_generate.py` | @bob | - |\n'
            '| `tools/leaf_family_batch.py` | helper | - | - | @alice |\n')

    def test_index_rows_read_path_login_and_findings(self):
        self.assertEqual(lesson_credits.index_rows(self.ROWS),
                         [('tools/a_generate.py', 'alice', ['findings/a-things.md']),
                          ('tools/b_generate_v2.py', 'alice', []), ('tools/c_generate.py', 'bob', [])])

    def test_generators_and_family_notes_are_credited_with_lesson_notes(self):
        with tempfile.TemporaryDirectory() as tmp:
            def git(*args):
                return subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@example.invalid', *args], cwd=tmp,
                                      check=True, capture_output=True, text=True).stdout
            git('init', '-q')
            Path(tmp, 'docs').mkdir()
            Path(tmp, 'docs/generators.md').write_text(self.ROWS)
            Path(tmp, 'findings').mkdir()
            Path(tmp, 'findings/a-things.md').write_text('x')
            Path(tmp, 'findings/carol-note.md').write_text('x')
            git('add', '.')
            git('commit', '-q', '-m', 'merge', '-m', 'Co-authored-by: Carol <9+carol@users.noreply.github.com>')
            Path(tmp, 'findings/anon.md').write_text('x')
            git('add', '.')
            git('commit', '-q', '-m', 'no trailer')
            families, generators = lesson_credits.family_credits(tmp)
            self.assertEqual(generators, {'alice': ['tools/a_generate.py', 'tools/b_generate_v2.py'],
                                          'bob': ['tools/c_generate.py']})
            self.assertEqual(families['alice'], ['findings/a-things.md'])
            self.assertEqual(sorted(families['carol']), ['findings/a-things.md', 'findings/carol-note.md'])
            self.assertNotIn('findings/anon.md', sum(families.values(), []))
            with contextlib.redirect_stdout(io.StringIO()) as out:
                self.assertEqual(lesson_credits.main(['--repo', tmp]), 0)
            self.assertIn('@alice: 1 family note, 2 generators', out.getvalue())
            self.assertIn('@bob: 1 generator', out.getvalue())

    def test_the_real_index_credits_its_authors(self):
        families, generators = lesson_credits.family_credits(ROOT)
        self.assertTrue(generators.get('aivv73'))
        self.assertTrue(families.get('aivv73'))


if __name__ == '__main__':
    unittest.main()
