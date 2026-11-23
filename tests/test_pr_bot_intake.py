"""pr_bot zero-touch intake (branch repairs, one look per head) and the one-commit landing of records.

Git is real here (local bare repositories); GitHub, the hosts and the reviewer are stubbed. Source text is invented.
"""
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tests'))
import lint_reconstruction as lint  # noqa: E402
import pr_bot  # noqa: E402
from test_pr_bot import FakeBot, HEAD, PR  # noqa: E402

IDENTITY = {'GIT_AUTHOR_NAME': 'bot', 'GIT_AUTHOR_EMAIL': 'bot@example.invalid',
            'GIT_COMMITTER_NAME': 'bot', 'GIT_COMMITTER_EMAIL': 'bot@example.invalid'}
BODY = '#include "Thing.h"\n\nint Thing::Alpha(int a_x)\n{\n    return a_x + 1;\n}\n'


def git(cwd, *args):
    return subprocess.run(['git', *args], cwd=cwd, capture_output=True, text=True, check=True,
                          env={**os.environ, **IDENTITY}).stdout.strip()


class WorkDir(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)
        patcher = mock.patch.dict(os.environ, IDENTITY)
        patcher.start()
        self.addCleanup(patcher.stop)


class OneLookPerHeadTests(WorkDir):
    def rejecting_bot(self):
        bot = FakeBot(self.dir)
        bot.looks = 0

        def units(files):
            bot.looks += 1
            raise pr_bot.Rejected('rva-headers', 'fix the header')
        bot.units = units
        return bot

    def test_a_rejected_head_is_not_looked_at_again_but_a_new_head_is(self):
        bot = self.rejecting_bot()
        with self.assertRaises(pr_bot.Rejected):
            bot.attempt(PR)
        for _ in range(3):
            self.assertIsNone(bot.attempt(PR))
        self.assertEqual(bot.looks, 1)
        self.assertEqual(len(bot.comments), 1)
        with self.assertRaises(pr_bot.Rejected):
            bot.attempt(dict(PR, headRefOid='b' * 40))
        self.assertEqual(bot.looks, 2)

    def test_a_bot_stop_is_still_retried(self):
        bot = FakeBot(self.dir)
        bot.looks = 0

        def units(files):
            bot.looks += 1
            raise pr_bot.Stop('hash check has not finished')
        bot.units = units
        for _ in range(2):
            with self.assertRaises(pr_bot.Stop):
                bot.attempt(PR, now=1.0)
        self.assertEqual(bot.looks, 2)


class AutofixHookTests(WorkDir):
    def test_a_pushed_repair_ends_the_old_head_without_a_compare(self):
        bot = FakeBot(self.dir)
        bot.autofix = lambda pr, state, files: True

        def never(units, tag):
            raise AssertionError('compared a head the bot already replaced')
        bot.mac_compare = never
        out = bot.process(PR)
        self.assertIsNone(out['blocked'])
        self.assertFalse(out['merge'])

    def test_no_repair_means_the_normal_pipeline(self):
        bot = FakeBot(self.dir)
        bot.autofix = lambda pr, state, files: False
        self.assertEqual(bot.process(PR)['verdicts'], {'0x10': 'matched', '0x20': 'matched'})


class AutofixTests(WorkDir):
    """`autofix` on a prepared tree: what it edits, what it says, and who it leaves alone."""
    NAME = 'reconstruction/a/B.cpp'

    def tree_bot(self, text, main_text=None, accepted=None):
        tree = self.dir / 'tree'
        (tree / 'builds').mkdir(parents=True)
        (tree / 'data').mkdir()
        (tree / 'builds/target.json').write_text(json.dumps({'build_id': 'sse-test'}))
        functions = [dict(build_id='sse-test', rva=0x1000, name=n, status='matched') for n in (accepted or [])]
        (tree / 'data/progress.json').write_text(json.dumps({'functions': functions}))
        (tree / self.NAME).parent.mkdir(parents=True)
        (tree / self.NAME).write_text(text)
        bot = FakeBot(self.dir, files=[{'filename': self.NAME, 'status': 'modified'}])
        bot.tree = tree
        bot.pushed = []
        real_run = bot.run

        def run(argv, **kw):
            if [str(a) for a in argv[:2]] == ['git', 'show']:
                if main_text is None:
                    return subprocess.CompletedProcess(argv, 128, b'', b'')
                return subprocess.CompletedProcess(argv, 0, main_text.encode(), b'')
            return real_run(argv, **kw)
        bot.run = run
        bot.gh_json = lambda *a: {'id': 77}

        def push(pr, edits, message):
            bot.pushed.append((edits, message))
            return 'c' * 40
        bot.push_to_branch = push
        return bot

    def header(self):
        free = ''.join(f'// Free text line {i}.\n' for i in range(4))
        return '// Task: t\n// Build: b\n// Evidence: e\n' + free + '// 0x1000 Thing::Alpha\n'

    def test_an_over_budget_header_is_trimmed_pushed_and_credited(self):
        text = self.header() + BODY
        bot = self.tree_bot(text)
        state = pr_bot.State(self.dir / 'state', 5, HEAD)
        self.assertTrue(bot.autofix(PR, state, bot.files))
        (edits, message), = bot.pushed
        self.assertEqual(lint.header_budget_problems(self.NAME, lint.leading_comment(edits[self.NAME])), [])
        self.assertIn('Co-authored-by: ', message)
        self.assertIn('77+', message)
        self.assertIn('header', message)
        self.assertIn('trimmed', bot.comments[0]['body'])
        self.assertEqual((bot.tree / self.NAME).read_text(), text)  # the scratch tree is left as it was

    def test_a_function_accepted_on_main_goes_back_to_mains_copy(self):
        main = '// 0x1000 Thing::Alpha\n' + BODY
        bot = self.tree_bot(main.replace('a_x + 1', 'a_x + 2'), main, ['Thing::Alpha'])
        self.assertTrue(bot.autofix(PR, pr_bot.State(self.dir / 'state', 5, HEAD), bot.files))
        self.assertEqual(bot.pushed[0][0][self.NAME], main)

    def test_nothing_to_repair_pushes_nothing(self):
        text = '// 0x1000 Thing::Alpha\n' + BODY
        bot = self.tree_bot(text, text)
        self.assertFalse(bot.autofix(PR, pr_bot.State(self.dir / 'state', 5, HEAD), bot.files))
        self.assertEqual((bot.pushed, bot.comments), ([], []))

    def test_a_pr_listed_in_the_skip_file_is_left_to_its_human(self):
        bot = self.tree_bot(self.header() + BODY)
        (self.dir / 'no-autofix.txt').write_text(f'{PR["number"]}\n')
        self.assertFalse(bot.autofix(PR, pr_bot.State(self.dir / 'state', 5, HEAD), bot.files))
        self.assertEqual(bot.pushed, [])

    def test_a_dry_run_never_pushes(self):
        bot = self.tree_bot(self.header() + BODY)
        bot.dry_run = True
        self.assertFalse(bot.autofix(PR, pr_bot.State(self.dir / 'state', 5, HEAD), bot.files))
        self.assertEqual(bot.pushed, [])


class PushToBranchTests(WorkDir):
    def test_the_commit_lands_on_the_contributors_branch_without_force_and_not_outside_reconstruction(self):
        fork = self.dir / 'fork.git'
        git(self.dir, 'init', '-q', '--bare', '-b', 'feature', str(fork))
        clone = self.dir / 'clone'
        git(self.dir, 'clone', '-q', str(fork), str(clone))
        (clone / 'reconstruction/a').mkdir(parents=True)
        (clone / 'reconstruction/a/B.cpp').write_text('// old\n' + BODY)
        git(clone, 'add', '-A')
        git(clone, 'commit', '-q', '-m', 'work')
        git(clone, 'push', '-q', 'origin', 'HEAD:feature')
        head = git(clone, 'rev-parse', 'HEAD')
        bot = FakeBot(self.dir / 'work')
        bot.root = clone
        bot.gh_json = lambda *a: dict(headRefOid=head, headRefName='feature', state='OPEN', maintainerCanModify=True,
                                      headRepository={'name': 'r'}, headRepositoryOwner={'login': 'o'})
        bot.run = lambda argv, cwd=None, **kw: subprocess.run([str(a) for a in argv], cwd=cwd or clone,
                                                              capture_output=True, check=kw.get('check', True))
        pr = dict(PR, headRefOid=head)
        with mock.patch.object(pr_bot, 'branch_url', return_value=str(fork)):
            self.assertIsNone(bot.push_to_branch(pr, {'tools/x.py': 'x'}, 'm'))
            sha = bot.push_to_branch(pr, {'reconstruction/a/B.cpp': '// new\n' + BODY}, 'Fix\n\nCo-authored-by: a <1+a@x>\n')
        self.assertEqual(git(fork, 'rev-parse', 'feature'), sha)
        self.assertEqual(git(fork, 'rev-parse', 'feature^'), head)
        self.assertIn('// new', git(fork, 'show', 'feature:reconstruction/a/B.cpp'))
        self.assertIn('Co-authored-by: a', git(fork, 'log', '-1', '--format=%B', 'feature'))

    def test_a_branch_that_does_not_allow_maintainer_edits_is_not_touched(self):
        bot = FakeBot(self.dir / 'work')
        bot.gh_json = lambda *a: dict(headRefOid=HEAD, headRefName='f', state='OPEN', maintainerCanModify=False,
                                      headRepository={'name': 'r'}, headRepositoryOwner={'login': 'o'})
        self.assertIsNone(bot.push_to_branch(PR, {'reconstruction/a/B.cpp': 'x'}, 'm'))


RECORD_STUB = '''import json, sys
from pathlib import Path
args = sys.argv
root = Path(args[args.index('--root') + 1])
rvas = [a for i, a in enumerate(args) if args[i - 1] == '--rva']
if root.joinpath('refuse').exists():
    print(json.dumps({'recorded': [], 'refused': {r: 'no' for r in rvas}, 'files': []}))
    raise SystemExit(1)
(root / 'reports').mkdir(exist_ok=True)
if '--drafter' in args:
    (root / 'drafter').write_text(args[args.index('--drafter') + 1])
for r in rvas:
    (root / 'reports' / (r + '.json')).write_text('{}')
print(json.dumps({'recorded': rvas, 'refused': {}, 'files': ['reports/' + r + '.json' for r in rvas]}))
'''


class LandWithRecordsTests(WorkDir):
    """One commit on main holds the squash and the records; the PR head is then merged tree-neutrally."""

    def setUp(self):
        super().setUp()
        self.origin = self.dir / 'origin.git'
        git(self.dir, 'init', '-q', '--bare', '-b', 'main', str(self.origin))
        self.root = self.dir / 'root'
        git(self.dir, 'clone', '-q', str(self.origin), str(self.root))
        (self.root / 'tools').mkdir()
        (self.root / 'tools/record.py').write_text(RECORD_STUB)
        (self.root / 'builds').mkdir()
        (self.root / 'builds/target.json').write_text(json.dumps({'build_id': 'sse-test'}))
        (self.root / 'data').mkdir()
        (self.root / 'data/progress.json').write_text(json.dumps({'functions': []}))
        (self.root / 'reconstruction').mkdir()
        (self.root / 'reconstruction/U.cpp').write_text('// base\n' + BODY)
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '-q', '-m', 'base')
        git(self.root, 'push', '-q', 'origin', 'HEAD:main')
        self.base = git(self.root, 'rev-parse', 'HEAD')
        git(self.root, 'checkout', '-q', '-b', 'pr')
        (self.root / 'reconstruction/U.cpp').write_text('// changed\n' + BODY)
        git(self.root, 'commit', '-qam', 'pr work')
        self.head = git(self.root, 'rev-parse', 'HEAD')
        git(self.root, 'checkout', '-q', 'main')
        self.tree = self.dir / 'work/tree'
        git(self.dir, 'clone', '-q', '--shared', str(self.root), str(self.tree))
        git(self.tree, 'remote', 'set-url', 'origin', str(self.origin))
        self.bot = FakeBot(self.dir / 'work')
        self.bot.tree, self.bot.root = self.tree, self.root
        self.bot.run = lambda argv, cwd=None, input=None, timeout=None, check=True: self.sh(argv, cwd, check)
        self.bot.gh_json = lambda *a: {'headRefOid': self.head, 'state': 'OPEN'}
        self.bot.history_problem = lambda base, head: None
        self.pr = dict(PR, headRefOid=self.head)
        self.state = pr_bot.State(self.dir / 'work/state', PR['number'], self.head)
        records = self.dir / 'records'
        records.mkdir()
        self.state.set('records', str(records))
        self.state.set('base_sha', self.base)
        review = self.dir / 'work/reviews' / f'pr{PR["number"]}-{self.head[:12]}.txt'
        review.parent.mkdir(parents=True)
        review.write_text('{}')

    @staticmethod
    def sh(argv, cwd, check):
        done = subprocess.run([str(a) for a in argv], cwd=cwd, capture_output=True, env={**os.environ, **IDENTITY})
        if check and done.returncode:
            raise pr_bot.Stop(f'{argv[0]} failed')
        return done

    def land(self):
        return self.bot.land_with_records(self.pr, self.state, [0x1000], 'Reconstruct 1 function (#7)',
                                          'Accepted.\n\nCo-authored-by: a <1+a@x>')

    def test_main_gets_the_squash_with_its_records_in_one_commit_and_the_head_is_merged_neutrally(self):
        self.assertTrue(self.land())
        merge = git(self.origin, 'rev-parse', 'main')
        squash = git(self.origin, 'rev-parse', 'main^1')
        self.assertEqual(git(self.origin, 'rev-parse', 'main^2'), self.head)
        self.assertEqual(git(self.origin, 'rev-parse', f'{merge}^{{tree}}'), git(self.origin, 'rev-parse', f'{squash}^{{tree}}'))
        self.assertEqual(git(self.origin, 'rev-parse', f'{squash}^'), self.base)
        names = git(self.origin, 'show', '--name-only', '--format=', squash).split()
        self.assertEqual(sorted(names), ['reconstruction/U.cpp', 'reports/0x1000.json'])
        self.assertTrue(git(self.origin, 'log', '-1', '--format=%s', squash).startswith('Reconstruct 1 function'))
        self.assertIn('Co-authored-by: a', git(self.origin, 'log', '-1', '--format=%B', squash))

    def stub_cookbook(self, body):
        (self.root / 'docs').mkdir(exist_ok=True)
        (self.root / 'docs/cookbook-hits.json').write_text('{}\n')
        (self.root / 'docs/matching-cookbook.md').write_text('rank\n')
        (self.root / 'tools/cookbook_rank.py').write_text(body)
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '-q', '-m', 'cookbook')
        git(self.root, 'push', '-q', 'origin', 'HEAD:main')
        git(self.root, 'checkout', '-q', '-B', 'pr', self.head)
        git(self.root, 'rebase', '-q', 'main')
        self.head = git(self.root, 'rev-parse', 'HEAD')
        git(self.root, 'checkout', '-q', 'main')
        self.base = git(self.root, 'rev-parse', 'HEAD')
        self.pr = dict(PR, headRefOid=self.head)
        self.bot.gh_json = lambda *a: {'headRefOid': self.head, 'state': 'OPEN'}
        self.state = pr_bot.State(self.dir / 'work/state2', PR['number'], self.head)
        self.state.set('records', str(self.dir / 'records'))
        self.state.set('base_sha', self.base)
        review = self.dir / 'work/reviews' / f'pr{PR["number"]}-{self.head[:12]}.txt'
        review.write_text('{}')

    def test_the_cookbook_hits_ride_in_the_same_commit_as_the_records(self):
        self.stub_cookbook("import pathlib, sys\nroot = pathlib.Path(sys.argv[sys.argv.index('--repo') + 1])\n"
                           "(root / 'docs/cookbook-hits.json').write_text('{\"0x1000\": [3]}\\n')\n"
                           "(root / 'docs/matching-cookbook.md').write_text('ranked\\n')\n")
        self.assertTrue(self.land())
        squash = git(self.origin, 'rev-parse', 'main^1')
        names = git(self.origin, 'show', '--name-only', '--format=', squash).split()
        self.assertEqual(sorted(names), ['docs/cookbook-hits.json', 'docs/matching-cookbook.md',
                                         'reconstruction/U.cpp', 'reports/0x1000.json'])

    def test_a_failing_cookbook_step_does_not_block_the_merge_and_leaves_its_files_alone(self):
        self.stub_cookbook("import pathlib, sys\nroot = pathlib.Path(sys.argv[sys.argv.index('--repo') + 1])\n"
                           "(root / 'docs/cookbook-hits.json').write_text('half\\n')\nsys.exit(1)\n")
        self.assertTrue(self.land())
        squash = git(self.origin, 'rev-parse', 'main^1')
        names = git(self.origin, 'show', '--name-only', '--format=', squash).split()
        self.assertEqual(sorted(names), ['reconstruction/U.cpp', 'reports/0x1000.json'])
        self.assertEqual(git(self.origin, 'show', 'main:docs/cookbook-hits.json'), '{}')

    def test_the_prs_drafter_line_is_passed_to_the_record_step(self):
        body = '- Drafted by: someone, assisted by claude-sonnet-5-5 (a person, and the AI model if one wrote code)'
        self.bot.gh_json = lambda *a: {'headRefOid': self.head, 'state': 'OPEN', 'body': body}
        self.assertTrue(self.land())
        self.assertEqual((self.tree / 'drafter').read_text(), 'claude-sonnet-5-5')

    def test_a_pr_that_states_no_drafter_passes_none(self):
        self.assertTrue(self.land())
        self.assertFalse((self.tree / 'drafter').exists())

    def test_a_refused_record_leaves_main_alone_and_asks_for_the_plain_merge(self):
        (self.tree / 'refuse').write_text('')
        self.assertFalse(self.land())
        self.assertEqual(git(self.origin, 'rev-parse', 'main'), self.base)

    def test_a_head_that_moved_is_not_landed(self):
        self.bot.gh_json = lambda *a: {'headRefOid': 'd' * 40, 'state': 'OPEN'}
        self.assertFalse(self.land())
        self.assertEqual(git(self.origin, 'rev-parse', 'main'), self.base)

    def test_history_the_check_refuses_falls_back_to_the_plain_merge(self):
        self.bot.history_problem = lambda base, head: 'merge-commit'
        self.assertFalse(self.land())
        self.assertEqual(git(self.origin, 'rev-parse', 'main'), self.base)

    def test_a_pr_that_conflicts_with_main_falls_back_and_leaves_main_alone(self):
        (self.root / 'reconstruction/U.cpp').write_text('// other\n' + BODY)
        git(self.root, 'commit', '-qam', 'main moved')
        git(self.root, 'push', '-q', 'origin', 'HEAD:main')
        moved = git(self.root, 'rev-parse', 'HEAD')
        self.assertFalse(self.land())
        self.assertEqual(git(self.origin, 'rev-parse', 'main'), moved)

    def test_missing_evidence_falls_back(self):
        self.state.drop('records')
        self.assertFalse(self.land())

    def test_finish_does_not_run_the_plain_merge_or_the_later_record_step_when_it_landed(self):
        bot = FakeBot(self.dir / 'fin')
        bot.land_with_records = lambda *a: True
        out = bot.process(PR)
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        self.assertTrue(pr_bot.State(self.dir / 'fin/state', PR['number'], HEAD).get('recorded'))
        self.assertTrue(out['merge'])

    def test_finish_falls_back_to_the_plain_merge(self):
        bot = FakeBot(self.dir / 'fin2')
        bot.land_with_records = lambda *a: False
        bot.process(PR)
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)


if __name__ == '__main__':
    unittest.main()
