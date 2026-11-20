"""The PR bot merges main into a conflicting outside PR's branch when only unit header comments conflict."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tests'))
import pr_bot  # noqa: E402
import test_pr_bot as shared  # noqa: E402

UNIT = 'reconstruction/a/B.cpp'
HEADER = ['// Build: x\n', '// Labels: v2\n', '// RVA 0x10, 8 bytes: A::F\n']
BODY = ['\n', '#include "B.h"\n', 'int f() { return 1; }\n']


def git(cwd, *args):
    done = subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@example.com', '-c',
                           'core.hooksPath=/dev/null', *args], cwd=cwd, capture_output=True, text=True)
    if done.returncode:
        raise AssertionError(f'git {args}: {done.stderr}')
    return done.stdout.strip()


def write(root, path, lines):
    target = Path(root) / path
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(''.join(lines))


class ResolverTests(unittest.TestCase):
    def conflict(self, pr, main, base=None, before='', after=''):
        base = ''.join(base or [])
        return (before + '<<<<<<< HEAD\n' + ''.join(pr) + '||||||| base\n' + base + '=======\n' + ''.join(main)
                + '>>>>>>> origin/main\n' + after)

    def test_header_lines_are_the_union_main_first_without_duplicates(self):
        text = self.conflict(['// Evidence: p\n', '// shared\n'], ['// shared\n', '// Drafted by m\n'],
                             before='// top\n', after='\n#include "B.h"\n')
        self.assertEqual(pr_bot.union_header_conflicts(text),
                         '// top\n// shared\n// Drafted by m\n// Evidence: p\n\n#include "B.h"\n')

    def test_a_repeated_comment_line_is_kept_once_per_occurrence(self):
        text = self.conflict(['//\n', '// a\n', '//\n'], ['//\n', '// b\n'])
        self.assertEqual(pr_bot.union_header_conflicts(text), '//\n// b\n// a\n//\n')

    def test_every_conflict_in_the_header_is_resolved(self):
        first = self.conflict(['// p1\n'], ['// m1\n'], before='// top\n')
        second = self.conflict(['// p2\n'], ['// m2\n'], before='// mid\n')
        self.assertEqual(pr_bot.union_header_conflicts(first + second),
                         '// top\n// m1\n// p1\n// mid\n// m2\n// p2\n')

    def test_a_conflict_in_a_function_body_is_refused(self):
        text = self.conflict(['  return 2;\n'], ['  return 3;\n'], before='// top\nint f() {\n', after='}\n')
        self.assertIsNone(pr_bot.union_header_conflicts(text))

    def test_a_conflict_after_the_header_block_ended_is_refused_even_if_it_holds_only_comments(self):
        text = self.conflict(['// p\n'], ['// m\n'], before='// top\n#include "B.h"\n')
        self.assertIsNone(pr_bot.union_header_conflicts(text))

    def test_a_mixed_hunk_or_a_side_that_removed_a_base_line_is_refused(self):
        self.assertIsNone(pr_bot.union_header_conflicts(self.conflict(['// p\n', 'int x;\n'], ['// m\n'])))
        self.assertIsNone(pr_bot.union_header_conflicts(self.conflict(['// keep\n'], ['// m\n'], base=['// gone\n'])))
        kept = self.conflict(['// keep\n', '// p\n'], ['// keep\n', '// m\n'], base=['// keep\n'])
        self.assertEqual(pr_bot.union_header_conflicts(kept), '// keep\n// m\n// p\n')

    def test_a_truncated_conflict_is_refused(self):
        self.assertIsNone(pr_bot.union_header_conflicts('// top\n<<<<<<< HEAD\n// p\n=======\n// m\n'))


class MergeMainTests(unittest.TestCase):
    """A real repository, a bare remote for main and a bare one standing in for the contributor's fork."""

    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        base = Path(tmp.name)
        self.remote, self.fork, self.root, self.work = base / 'remote.git', base / 'fork.git', base / 'root', base / 'w'
        for bare in (self.remote, self.fork):
            git(base, 'init', '--quiet', '--bare', '-b', 'main', str(bare))
        git(base, 'clone', '--quiet', str(self.remote), str(self.root))
        # The bot's merge commit runs plain `git merge`; a CI runner has no global committer identity.
        git(self.root, 'config', 'user.name', 't')
        git(self.root, 'config', 'user.email', 't@example.com')
        git(self.root, 'checkout', '--quiet', '-b', 'main')
        write(self.root, UNIT, HEADER + BODY)
        write(self.root, 'tools/x.py', ['print(1)\n'])
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '--quiet', '-m', 'base')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        git(self.root, 'checkout', '--quiet', '-b', 'contrib')

    def pr_commit(self, header=(), body=None, extra=None):
        write(self.root, UNIT, HEADER + list(header) + (body or BODY))
        for path, lines in (extra or {}).items():
            write(self.root, path, lines)
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '--quiet', '-m', 'pr')
        git(self.root, 'push', '--quiet', str(self.fork), 'contrib')
        return git(self.root, 'rev-parse', 'HEAD')

    def main_commit(self, header=(), body=None):
        git(self.root, 'checkout', '--quiet', 'main')
        write(self.root, UNIT, HEADER + list(header) + (body or BODY))
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '--quiet', '-m', 'main moves')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        git(self.root, 'checkout', '--quiet', 'contrib')

    def bot(self, can_modify=True, head=None):
        head = head or git(self.root, 'rev-parse', 'contrib')
        bot = pr_bot.Bot(root=self.root, work=self.work)
        bot.said = []
        bot.gh_json = lambda *a: dict(headRefOid=head, headRefName='contrib', state='OPEN',
                                      headRepository={'name': 'fork'}, headRepositoryOwner={'login': 'alice'},
                                      maintainerCanModify=can_modify)
        bot.say = lambda number, body, create=True: bot.said.append((body, create))
        patch = mock.patch.object(pr_bot, 'branch_url', lambda owner, name: str(self.fork))
        patch.start()
        self.addCleanup(patch.stop)
        return bot

    def fork_head(self):
        return git(self.fork, 'rev-parse', 'contrib')

    def worktrees(self):
        return [l for l in git(self.root, 'worktree', 'list', '--porcelain').splitlines() if l.startswith('worktree ')]

    def test_a_header_only_conflict_is_merged_into_the_branch_without_rewriting_it(self):
        head = self.pr_commit(header=['// Evidence: pr\n', '// RVA 0x20, 4 bytes: A::G\n'])
        self.main_commit(header=['// Sibling: main\n', '// RVA 0x30, 4 bytes: A::H\n'])
        main = git(self.root, 'rev-parse', 'main')
        bot = self.bot()
        pr = dict(shared.PR, headRefOid=head, mergeable='CONFLICTING')
        state = pr_bot.State(self.work / 'state', pr['number'], head)

        out = bot.conflicting(pr, state)

        new = self.fork_head()
        self.assertNotEqual(new, head)
        self.assertEqual(out['main_merged'], new)
        self.assertEqual(git(self.root, 'rev-list', '--parents', '-n', '1', new).split()[1:], [head, main])
        self.assertEqual(git(self.root, 'merge-base', '--is-ancestor', head, new) or 'ok', 'ok')
        merged = git(self.fork, 'show', f'{new}:{UNIT}').splitlines()
        self.assertEqual(merged[:7], ['// Build: x', '// Labels: v2', '// RVA 0x10, 8 bytes: A::F',
                                      '// Sibling: main', '// RVA 0x30, 4 bytes: A::H', '// Evidence: pr',
                                      '// RVA 0x20, 4 bytes: A::G'])
        self.assertEqual(merged[7:], [l.rstrip('\n') for l in BODY])
        self.assertEqual(git(self.root, 'log', '-1', '--format=%s', new), 'Merge main into contrib')
        # No new comment: only an existing sticky one is brought up to date.
        self.assertEqual([create for _, create in bot.said], [False])
        self.assertTrue(state.get('done'))
        self.assertEqual(self.worktrees(), [f'worktree {self.root.resolve()}'])

    def test_a_clean_merge_of_main_also_pushes_a_merge_commit(self):
        head = self.pr_commit(extra={'docs/pr.md': ['x\n']})
        self.main_commit(body=BODY + ['int g() { return 2; }\n'])
        sha = self.bot().merge_main_into_branch(dict(shared.PR, headRefOid=head))
        self.assertEqual(sha, self.fork_head())
        self.assertEqual(len(git(self.root, 'rev-list', '--parents', '-n', '1', sha).split()), 3)

    def test_a_conflict_in_a_function_body_aborts_and_falls_back_to_the_one_sticky_comment(self):
        head = self.pr_commit(header=['// Evidence: pr\n'], body=BODY[:2] + ['int f() { return 2; }\n'])
        self.main_commit(header=['// Sibling: main\n'], body=BODY[:2] + ['int f() { return 3; }\n'])
        bot = self.bot()
        pr = dict(shared.PR, headRefOid=head, mergeable='CONFLICTING')
        state = pr_bot.State(self.work / 'state', pr['number'], head)

        out = bot.conflicting(pr, state)

        self.assertEqual((out['blocked'], out['merge']), ('conflict', False))
        self.assertNotIn('main_merged', out)
        self.assertEqual(self.fork_head(), head)
        self.assertEqual(len(bot.said), 1)
        self.assertIn(pr_bot.CONFLICT_COMMENT, bot.said[0][0])
        self.assertTrue(bot.said[0][1])
        self.assertEqual(self.worktrees(), [f'worktree {self.root.resolve()}'])

    def test_a_conflict_outside_reconstruction_is_not_resolved_even_when_it_is_only_comments(self):
        head = self.pr_commit(extra={'tools/x.py': ['# pr\n']})
        git(self.root, 'checkout', '--quiet', 'main')
        write(self.root, 'tools/x.py', ['# main\n'])
        git(self.root, 'commit', '--quiet', '-am', 'main moves')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        git(self.root, 'checkout', '--quiet', 'contrib')
        self.assertIsNone(self.bot().merge_main_into_branch(dict(shared.PR, headRefOid=head)))
        self.assertEqual(self.fork_head(), head)

    def test_one_unsafe_file_aborts_the_whole_merge_even_if_another_is_header_only(self):
        head = self.pr_commit(header=['// Evidence: pr\n'], extra={'reconstruction/a/C.cpp': ['// p\n', 'int c;\n']})
        git(self.root, 'checkout', '--quiet', 'main')
        write(self.root, 'reconstruction/a/C.cpp', ['// m\n', 'int c;\n'])
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '--quiet', '-m', 'add C')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        git(self.root, 'checkout', '--quiet', 'contrib')
        self.main_commit(header=['// Sibling: main\n'])
        self.assertIsNone(self.bot().merge_main_into_branch(dict(shared.PR, headRefOid=head)))
        self.assertEqual(self.fork_head(), head)

    def test_nothing_is_touched_without_maintainer_edit_access_or_when_the_head_moved(self):
        head = self.pr_commit(header=['// Evidence: pr\n'])
        self.main_commit(header=['// Sibling: main\n'])
        self.assertIsNone(self.bot(can_modify=False).merge_main_into_branch(dict(shared.PR, headRefOid=head)))
        self.assertIsNone(self.bot(head='c' * 40).merge_main_into_branch(dict(shared.PR, headRefOid=head)))
        self.assertEqual(self.fork_head(), head)
        self.assertEqual(self.worktrees(), [f'worktree {self.root.resolve()}'])

    def test_a_push_that_loses_a_race_leaves_the_authors_new_commit_alone(self):
        head = self.pr_commit(header=['// Evidence: pr\n'])
        self.main_commit(header=['// Sibling: main\n'])
        bot = self.bot()
        write(self.root, 'docs/late.md', ['late\n'])
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '--quiet', '-m', 'late')
        git(self.root, 'push', '--quiet', str(self.fork), 'contrib')
        late = self.fork_head()
        self.assertIsNone(bot.merge_main_into_branch(dict(shared.PR, headRefOid=head)))
        self.assertEqual(self.fork_head(), late)

    def test_a_failure_of_the_merge_step_falls_back_to_the_sticky_comment(self):
        head = self.pr_commit(header=['// Evidence: pr\n'])
        bot = self.bot()
        bot.merge_main_into_branch = mock.Mock(side_effect=pr_bot.Stop('boom'))
        pr = dict(shared.PR, headRefOid=head, mergeable='CONFLICTING')
        with mock.patch('sys.stderr'):
            out = bot.conflicting(pr, pr_bot.State(self.work / 'state', pr['number'], head))
        self.assertEqual(out['blocked'], 'conflict')
        self.assertEqual(len(bot.said), 1)

    def test_dry_run_never_pushes(self):
        head = self.pr_commit(header=['// Evidence: pr\n'])
        self.main_commit(header=['// Sibling: main\n'])
        bot = self.bot()
        bot.dry_run = True
        pr = dict(shared.PR, headRefOid=head, mergeable='CONFLICTING')
        out = bot.conflicting(pr, pr_bot.State(self.work / 'dry', pr['number'], head))
        self.assertEqual(out['blocked'], 'conflict')
        self.assertEqual(self.fork_head(), head)


class AfterTheBotsMergeTests(unittest.TestCase):
    """The merge changes the head, so the next tick processes it like any push and records what its text outdated."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def test_the_new_head_is_reviewed_and_its_stale_companion_is_recorded_again(self):
        bot = shared.FakeBot(self.work, review=shared.WITH_COMPANION,
                             h1={0x10: 'pass', 0x20: 'pass', 0x30: 'pass'}, h2={0x10: 'pass', 0x20: 'pass', 0x30: 'pass'})
        bot.merge_main_into_branch = lambda pr: 'd' * 40
        out = bot.process(dict(shared.PR, mergeable='CONFLICTING'))
        self.assertEqual((out['blocked'], out['main_merged']), (None, 'd' * 40))
        self.assertEqual((bot.seen('review'), bot.seen('record'), bot.seen('gh', 'pr', 'comment')), ([], [], []))

        bot.extra = {'reconstruction/a/B.cpp': [0x30]}
        out = bot.process(dict(shared.PR, headRefOid='d' * 40, mergeable='UNKNOWN'))
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched', '0x30': 'matched'})
        self.assertEqual(bot.seen('record'), [['record', [0x10, 0x20, 0x30]]])


if __name__ == '__main__':
    unittest.main()
