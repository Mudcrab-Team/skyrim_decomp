"""pr_bot pre-review gate, failure backoff, gh backoff and the two-slot pool, with every host and GitHub call stubbed."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tests'))
import pr_bot  # noqa: E402
import prereview  # noqa: E402
from test_pr_bot import FakeBot, HEAD, PR, ReviewContextTests  # noqa: E402


class WorkDir(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)


class PrecheckGateTests(WorkDir):
    def test_a_refused_function_is_never_matched_and_never_reviewed_and_the_comment_says_what_to_fix(self):
        bot = FakeBot(self.work)
        bot.pre = {0x10: ['reconstruction/a/B.cpp: names recipe reconstruction/recipes/x.json, which does not exist']}
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'fail:precheck', '0x20': 'matched'})
        self.assertEqual(bot.seen('review'), [['review', [0x20]]])
        body = bot.comments[0]['body']
        self.assertIn('0x10: a mechanical check refused it before any review', body)
        self.assertIn('names recipe reconstruction/recipes/x.json', body)
        self.assertIn('no review was spent', body)
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)

    def test_when_every_function_is_refused_no_review_is_started_and_nothing_merges(self):
        bot = FakeBot(self.work)
        bot.pre = {0x10: ['a finding'], 0x20: ['a finding']}
        out = bot.process(PR)
        self.assertEqual(set(out['verdicts'].values()), {'fail:precheck'})
        self.assertEqual(bot.seen('review'), [])
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        self.assertEqual(bot.comments[0]['body'].count('- a finding'), 1)

    def test_functions_that_failed_a_host_are_not_prechecked_and_a_clean_pr_is_unchanged(self):
        bot = FakeBot(self.work, h2={0x10: 'fail', 0x20: 'pass'})
        bot.process(PR)
        self.assertEqual(bot.seen('precheck'), [['precheck', [0x10, 0x20]]])
        self.assertEqual(bot.seen('review'), [['review', [0x20]]])
        clean = FakeBot(self.work / 'clean')
        self.assertEqual(clean.process(PR)['verdicts'], {'0x10': 'matched', '0x20': 'matched'})

    def test_a_cached_precheck_is_not_recomputed_after_a_crash(self):
        bot = FakeBot(self.work)
        bot.pre = {0x10: ['a finding']}
        original = bot.review

        def boom(*a):
            raise pr_bot.Stop('model unavailable')
        bot.review = boom
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        bot.review = original
        bot.process(PR)
        self.assertEqual(len(bot.seen('precheck')), 1)


class PrecheckTests(WorkDir):
    """The real precheck on a small tree: lint, origin and binding facts, each as a computed finding."""

    setUp = ReviewContextTests.setUp
    evidence = ReviewContextTests.evidence
    fake_run = ReviewContextTests.fake_run

    def run_precheck(self, evidence, findings=(), origin=(), host=('pass', 'pass')):
        state = pr_bot.State(self.tree / '.w' / 'state', 7, HEAD)
        row = evidence[0x10]['row']
        state.set('ci', dict(run={'run_id': 555, 'head_sha': HEAD}, rows={'16': row}))
        self.bot.origin_hits = lambda units: (list(origin), {}, False)
        files = [{'filename': 'reconstruction/a/B.cpp', 'status': 'modified'}]
        units = {'reconstruction/a/B.cpp': [0x10]}
        with mock.patch.object(prereview, 'unit_findings', return_value=list(findings)):
            return self.bot.precheck('7-aaaaaaaa', files, units, [0x10], {0x10: host[0]}, {0x10: host[1]}, state)

    def test_a_bound_clean_unit_has_no_findings(self):
        self.assertEqual(self.run_precheck(self.evidence()), {})

    def test_a_lint_finding_in_the_units_closure_refuses_its_functions(self):
        found = self.run_precheck(self.evidence(), findings=[('reconstruction/a/B.h', 'reconstruction/a/B.h: missing origin statement')])
        self.assertEqual(found, {0x10: ['reconstruction/a/B.h: missing origin statement']})

    def test_an_undeclared_adapted_body_refuses_its_functions(self):
        hit = {'function': 'B::f', 'file': 'reconstruction/a/B.cpp', 'repo': 'x/ng', 'path': 'src/B.cpp',
               'trivial': False, 'declared': False, 'fork_of': None}
        found = self.run_precheck(self.evidence(), origin=[hit])
        self.assertIn('does not name it with that file', found[0x10][0])

    def test_a_report_for_other_source_is_the_contributors_to_fix(self):
        bad = self.evidence(source={'source_revision': '0' * 64, 'path': 'reconstruction/a/B.cpp'})
        found = self.run_precheck(bad)
        self.assertTrue(all('merge current main into your branch' in line for line in found[0x10]))
        self.assertEqual(len(found[0x10]), 2)  # the unit digest and the hosts disagreeing

    def test_both_hosts_agreeing_against_the_bots_own_digest_is_a_bot_fault(self):
        bad = self.evidence(source={'source_revision': '0' * 64, 'path': 'reconstruction/a/B.cpp'})
        bad[0x10]['row']['source_sha256'] = '0' * 64
        with self.assertRaisesRegex(pr_bot.Stop, 'pins'):
            self.run_precheck(bad)

    def test_a_second_host_digest_that_differs_is_reported(self):
        evidence = self.evidence()
        evidence[0x10]['row']['source_sha256'] = '1' * 64
        found = self.run_precheck(evidence)
        self.assertIn('CI hash run compiled different source', found[0x10][0])

    def test_a_fact_only_the_bots_own_pins_can_break_stops_instead_of_blaming_the_author(self):
        bad = self.evidence(recipe={'recipe_sha256': prereview.hashlib.sha256(b'{}').hexdigest(),
                                    'compiler_binary_sha256': 'c' * 64})
        with self.assertRaisesRegex(pr_bot.Stop, 'pins'):
            self.run_precheck(bad)

    def test_a_missing_report_is_left_to_the_reviewer_not_refused(self):
        evidence = self.evidence()
        evidence[0x10]['report'].unlink()
        self.assertEqual(self.run_precheck(evidence), {})

    def test_text_the_publication_filter_refuses_is_counted_not_shown(self):
        found = self.run_precheck(self.evidence(), findings=[('reconstruction/a/B.cpp', 'reconstruction/a/B.cpp: ' + 'é' * 5)])
        self.assertEqual(found, {0x10: ['1 more finding(s) not shown; run `python3 tools/prereview.py` locally']})


class PrereviewUnitTests(unittest.TestCase):
    def test_origin_problems_skip_trivial_fork_and_declared_bodies(self):
        base = {'function': 'A::f', 'file': 'reconstruction/a/A.cpp', 'repo': 'x/ng', 'path': 'p.cpp'}
        hits = [dict(base, trivial=True, declared=None, fork_of=None),
                dict(base, trivial=False, declared=None, fork_of='x/ng'),
                dict(base, trivial=False, declared=True, fork_of=None),
                dict(base, trivial=False, declared=False, fork_of=None)]
        self.assertEqual(len(prereview.origin_problems(hits, {})), 1)

    def test_binding_split_separates_the_authors_facts_from_the_hosts(self):
        facts = {'result pass': True, 'source revision equals the tu digest and unit path': False,
                 'compiler hash equals the pinned cl.exe': False}
        self.assertEqual(prereview.binding_split(facts), (['source revision equals the tu digest and unit path'],
                                                          ['compiler hash equals the pinned cl.exe']))

    def test_recipe_problem_names_a_missing_or_changed_recipe(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction/recipes').mkdir(parents=True)
            (root / prereview.DEFAULT_RECIPE).write_text('{}')
            good = {'recipe_sha256': prereview.hashlib.sha256(b'{}').hexdigest()}
            self.assertIsNone(prereview.recipe_problem(root, '// none\n', good))
            self.assertIn('changed since the last compare', prereview.recipe_problem(root, '// none\n', {'recipe_sha256': 'x'}))
            self.assertIn('does not exist', prereview.recipe_problem(
                root, '// Recipe: reconstruction/recipes/nope.json\n', good))


class PrereviewCliTests(unittest.TestCase):
    def test_a_unit_naming_a_missing_recipe_fails_and_nothing_is_written_into_the_checkout(self):
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            (repo / 'builds').mkdir()
            (repo / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))

            def git(*args):
                subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', *args], cwd=repo, check=True,
                               capture_output=True)
            git('init', '-q')
            git('add', '.')
            git('commit', '-q', '-m', 'base')
            unit = repo / 'reconstruction/a'
            unit.mkdir(parents=True)
            (unit / 'B.h').write_text('// RVA 0x10, 4 bytes, B::f\n')
            (unit / 'B.cpp').write_text('// Recipe: reconstruction/recipes/nope.json\n#include "B.h"\n')
            git('add', '.')
            git('commit', '-q', '-m', 'head')
            before = sorted(p.relative_to(repo).as_posix() for p in repo.rglob('*') if '.git' not in p.parts)
            out = subprocess.run([sys.executable, str(ROOT / 'tools/prereview.py'), '--repo', str(repo),
                                  '--base', 'HEAD~1', '--head', 'HEAD'], capture_output=True, text=True)
            self.assertEqual(out.returncode, 1)
            self.assertIn('names recipe reconstruction/recipes/nope.json, which does not exist', out.stdout)
            self.assertIn('prereview: FAIL', out.stdout)
            self.assertEqual(before, sorted(p.relative_to(repo).as_posix() for p in repo.rglob('*')
                                            if '.git' not in p.parts))


class FailureLedgerTests(unittest.TestCase):
    def test_identical_failures_count_and_back_off_only_from_the_threshold(self):
        record = None
        waits = []
        for _ in range(6):
            record = pr_bot.failure_record(record, 'HostFailure: x', 1000)
            waits.append(record['next'] - 1000)
        self.assertEqual(record['count'], 6)
        self.assertEqual(waits[:2], [0, 0])
        self.assertEqual(waits[2:], [300, 600, 1200, 2400])

    def test_the_delay_is_capped_and_a_different_failure_starts_again(self):
        record = {'signature': 's', 'count': 40, 'next': 0, 'posted': True}
        again = pr_bot.failure_record(record, 's', 0)
        self.assertEqual(again['next'], pr_bot.FAILURE_BACKOFF_CAP)
        self.assertTrue(again['posted'])
        other = pr_bot.failure_record(record, 'different', 0)
        self.assertEqual((other['count'], other['next'], other['posted']), (1, 0, False))


class AttemptTests(WorkDir):
    def bot_failing_with(self, exc):
        bot = FakeBot(self.work)
        bot.runs = 0

        def process(pr, base=None):
            bot.runs += 1
            raise exc
        bot.process = process
        return bot

    def test_identical_verifier_failures_back_off_and_are_said_once(self):
        bot = self.bot_failing_with(pr_bot.HostFailure('verifier host did not complete (exit 5, t-0): no error text'))
        now = 10_000.0
        for _ in range(2):
            with self.assertRaises(pr_bot.HostFailure):
                bot.attempt(PR, now=now)
        self.assertEqual(bot.comments, [])
        with self.assertRaises(pr_bot.HostFailure):
            bot.attempt(PR, now=now)
        self.assertEqual(len(bot.comments), 1)
        self.assertIn('verifier host did not complete', bot.comments[0]['body'])
        self.assertNotIn('exit 5', bot.comments[0]['body'])
        self.assertEqual(bot.runs, 3)
        # Backing off: the head is not due, so the failing stage is not run again.
        self.assertIsNone(bot.attempt(PR, now=now + 299))
        self.assertEqual(bot.runs, 3)
        with self.assertRaises(pr_bot.HostFailure):
            bot.attempt(PR, now=now + 301)
        self.assertEqual(bot.runs, 4)
        self.assertIsNone(bot.attempt(PR, now=now + 301 + 599))
        self.assertEqual(len(bot.comments), 1)

    def test_other_infrastructure_failures_back_off_without_a_comment(self):
        bot = self.bot_failing_with(pr_bot.Stop('hash check has not finished'))
        for _ in range(3):
            with self.assertRaises(pr_bot.Stop):
                bot.attempt(PR, now=5.0)
        self.assertIsNone(bot.attempt(PR, now=5.0))
        self.assertEqual((bot.runs, bot.comments), (3, []))

    def test_a_new_head_has_its_own_ledger_and_success_clears_it(self):
        bot = self.bot_failing_with(pr_bot.HostFailure('x'))
        for _ in range(3):
            with self.assertRaises(pr_bot.HostFailure):
                bot.attempt(PR, now=1.0)
        other = dict(PR, headRefOid='b' * 40)
        with self.assertRaises(pr_bot.HostFailure):
            bot.attempt(other, now=1.0)
        self.assertEqual(bot.runs, 4)
        bot.process = lambda pr, base=None: {'pr': 7}
        self.assertEqual(bot.attempt(PR, now=1e9), {'pr': 7})
        self.assertIsNone(pr_bot.State(self.work / 'state', 7, HEAD).get('failure'))

    def test_a_gh_failure_is_raised_but_never_counted_against_the_head(self):
        bot = self.bot_failing_with(pr_bot.GhFailure('gh failed'))
        for _ in range(5):
            with self.assertRaises(pr_bot.GhFailure):
                bot.attempt(PR, now=1.0)
        self.assertEqual(bot.runs, 5)
        self.assertIsNone(pr_bot.State(self.work / 'state', 7, HEAD).get('failure'))

    def test_a_pr_held_by_another_run_is_skipped(self):
        bot = FakeBot(self.work)
        with bot.pr_lock(7) as first:
            self.assertTrue(first)
            with bot.pr_lock(7) as second:
                self.assertFalse(second)
            self.assertIsNone(bot.attempt(PR))
        self.assertTrue(bot.attempt(PR))


class GhFailureTests(WorkDir):
    def test_a_failed_gh_call_is_a_gh_failure_and_other_tools_stay_plain_stops(self):
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        with mock.patch.object(subprocess, 'run', return_value=subprocess.CompletedProcess(['gh'], 1, b'', b'')):
            with self.assertRaises(pr_bot.GhFailure):
                bot.run(['gh', 'pr', 'list'])
            with self.assertRaises(pr_bot.Stop) as raised:
                bot.run(['git', 'fetch'])
            self.assertNotIsInstance(raised.exception, pr_bot.GhFailure)
            self.assertEqual(bot.run(['gh', 'x'], check=False).returncode, 1)

    def test_a_gh_timeout_is_a_gh_failure(self):
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        with mock.patch.object(subprocess, 'run', side_effect=subprocess.TimeoutExpired(['gh'], 1)):
            with self.assertRaises(pr_bot.GhFailure):
                bot.run(['gh', 'pr', 'list'], timeout=1)
            with self.assertRaises(subprocess.TimeoutExpired):
                bot.run(['codex'], timeout=1)

    def test_backoff_doubles_to_a_cap_and_resets_on_success(self):
        now = [100.0]
        gh = pr_bot.GhBackoff(clock=lambda: now[0])
        self.assertEqual([gh.failed() for _ in range(6)], [60, 120, 240, 480, 900, 900])
        self.assertEqual(gh.remaining(), 900)
        now[0] += 901
        self.assertEqual(gh.remaining(), 0)
        gh.succeeded()
        self.assertEqual(gh.failed(), 60)


class VerifierHostTests(WorkDir):
    def bot(self):
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        (bot.tree / 'builds').mkdir(parents=True)
        (bot.tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
        (bot.tree / 'reconstruction/a').mkdir(parents=True)
        (bot.tree / 'reconstruction/a/B.cpp').write_text('int f() { return 1; }\n')
        return bot

    def test_exit_5_is_a_host_failure_and_a_stale_task_directory_is_cleared_first(self):
        bot = self.bot()
        stale = bot.tree / '.local/tasks/prbot-7-aaaaaaaa-0'
        (stale / 'attempts/001').mkdir(parents=True)
        seen = []

        def run(argv, **kw):
            argv = [str(a) for a in argv]
            seen.append((argv[1:3], stale.exists()))
            code, err = (5, b'attempt budget exhausted') if 'attempt' in argv[1] else (0, b'')
            return subprocess.CompletedProcess(argv, code, b'', err)
        bot.run = run
        with self.assertRaisesRegex(pr_bot.HostFailure, r'exit 5, prbot-7-aaaaaaaa-0\): attempt budget exhausted'):
            bot.mac_compare({'reconstruction/a/B.cpp': [0x10]}, '7-aaaaaaaa')
        self.assertFalse(seen[0][1])  # gone before the export that recreates it

    def test_a_verifier_timeout_is_a_host_failure(self):
        bot = self.bot()

        def run(argv, **kw):
            if 'attempt' in str(argv[1]):
                raise subprocess.TimeoutExpired(argv, 1)
            return subprocess.CompletedProcess(argv, 0, b'', b'')
        bot.run = run
        with self.assertRaises(pr_bot.HostFailure):
            bot.mac_compare({'reconstruction/a/B.cpp': [0x10]}, '7-aaaaaaaa')

    def test_the_base_compare_has_its_own_task_name_per_pr_and_head(self):
        bot = self.bot()
        (bot.tree / 'data').mkdir()
        (bot.tree / 'data/progress.json').write_text(json.dumps({'functions': [{'rva': 0x10, 'status': 'matched'}]}))
        tags = []
        bot.mac_compare = lambda units, tag: tags.append(tag) or {0x10: 'pass'}
        bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, 0, b'', b'')
        state = pr_bot.State(self.work / 'state', 7, HEAD)
        got = bot.classify_debt({0x10: 'fail'}, {0x10: 'pass'}, 'base', {'reconstruction/a/B.cpp': [0x10]}, state)
        self.assertEqual(got, {0x10: 'regressed'})
        self.assertEqual(tags, ['base-pr7-' + HEAD[:12]])
        # Not matched by the glob that collects a PR's own tasks for the record.
        self.assertFalse(('prbot-' + tags[0] + '-0').startswith('prbot-7-' + HEAD[:8]))


class PoolTests(WorkDir):
    class PoolBot(FakeBot):
        def attempt(self, pr, now=None):
            self.arrived(pr, self.tree)
            return {'pr': pr['number'], 'head': pr['headRefOid'], 'blocked': None, 'merge': False}

    def prs(self, *numbers):
        return [{'number': n, 'headRefOid': chr(96 + n) * 40, 'author': {'login': 'alice'}, 'baseRefName': 'main',
                 'isDraft': False} for n in numbers]

    def pool_bot(self, listing, arrived):
        bot = self.PoolBot(self.work)
        bot.arrived = arrived
        bot.gh_json = listing
        bot.warm = lambda pr: None
        return bot

    def test_two_prs_run_at_once_each_on_its_own_tree(self):
        both = threading.Barrier(2, timeout=5)
        trees = []

        def arrived(pr, tree):
            trees.append(tree)
            both.wait()  # only passes if the other PR is running at the same time
        bot = self.pool_bot(lambda *a: self.prs(1, 2), arrived)
        self.assertEqual(pr_bot.poll(bot, 0, workers=2, sleep=lambda s: None, rounds=1), 0)
        self.assertEqual(len(set(trees)), 2)
        self.assertEqual({t.name for t in trees}, {'tree', 'tree-1'})

    def test_a_third_pr_waits_for_a_free_slot_and_a_running_pr_is_not_queued_twice(self):
        release, started, calls = threading.Event(), threading.Event(), []

        def arrived(pr, tree):
            calls.append(pr['number'])
            if pr['number'] in (1, 2):
                started.set()
                release.wait(5)
        bot = self.pool_bot(lambda *a: self.prs(1, 2, 3), arrived)
        rounds = []

        def sleep(seconds):
            rounds.append(1)
            started.wait(5)
            if len(rounds) == 3:
                release.set()
        pr_bot.poll(bot, 0, workers=2, sleep=sleep, rounds=3)
        self.assertEqual(sorted(calls)[:2], [1, 2])
        self.assertEqual(calls.count(1), 1)
        self.assertEqual(calls.count(2), 1)

    def test_a_gh_outage_lists_nothing_and_waits_out_the_shared_backoff(self):
        now, naps, listed = [0.0], [], []

        def listing(*a):
            listed.append(now[0])
            raise pr_bot.GhFailure('gh failed')
        bot = self.pool_bot(listing, lambda pr, tree: None)
        gh = pr_bot.GhBackoff(clock=lambda: now[0])

        def sleep(seconds):
            naps.append(seconds)
            now[0] += seconds
        pr_bot.poll(bot, 60, gh=gh, sleep=sleep, rounds=6)
        # First try fails at once; the next tries come only after 60 s, then 120 s, never at full speed.
        self.assertEqual(listed, [0.0, 60.0, 180.0])
        self.assertTrue(all(n > 0 for n in naps))

    def test_a_finished_head_and_a_head_backing_off_cost_no_worker(self):
        bot = self.pool_bot(lambda *a: self.prs(1, 2), lambda pr, tree: self.fail('should not run'))
        pr_bot.State(self.work / 'state', 1, 'a' * 40).set('done', True)
        pr_bot.State(self.work / 'state', 2, 'b' * 40).set('failure', {'signature': 's', 'count': 5,
                                                                          'next': 9e12, 'posted': True})
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=2)

    def test_pushes_to_main_take_turns(self):
        bot = FakeBot(self.work)
        held = []
        bot.record = lambda pr, state, rvas: (held.append(bot.land_lock.locked()), state.set('recorded', True))
        bot.process(PR)
        self.assertEqual(held, [True])
        self.assertFalse(bot.land_lock.locked())

    def test_slots_share_the_locks_but_not_the_tree(self):
        bot = FakeBot(self.work)
        first, second = bot.for_slot(0), bot.for_slot(1)
        self.assertEqual((first.tree, second.tree), (self.work / 'tree', self.work / 'tree-1'))
        self.assertIs(first.land_lock, second.land_lock)
        self.assertIs(first.ghidra_lock, second.ghidra_lock)
        self.assertIs(first.root_lock, second.root_lock)

    def test_refill_regenerates_only_below_the_threshold_and_holds_the_push_turn(self):
        bot = FakeBot(self.work)
        regenerated = []
        bot.regenerate = lambda number: regenerated.append((number, bot.land_lock.locked()))
        for left, expected in ((1500, []), (1499, [(None, True)])):
            regenerated.clear()
            bot.offered_open = lambda left=left: left
            self.assertEqual(bot.refill_offers(), left)
            self.assertEqual(regenerated, expected)
        self.assertFalse(bot.land_lock.locked())

    def test_idle_poll_checks_the_window_at_start_and_then_once_per_period(self):
        calls = []

        class Refilling(PoolTests.PoolBot):
            def refill_offers(self):
                calls.append(1)
                return 2000
        bot = Refilling(self.work)
        bot.gh_json = lambda *a: []
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3, refill_every=3600)
        self.assertEqual(len(calls), 1)
        calls.clear()
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3)
        self.assertEqual(calls, [])

    def test_a_failed_refill_does_not_stop_the_poll(self):
        class Broken(PoolTests.PoolBot):
            def refill_offers(self):
                raise pr_bot.Stop('SR_TARGET_IMAGE is not set')
        bot = Broken(self.work)
        listed = []
        bot.gh_json = lambda *a: listed.append(1) or []
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=2, refill_every=3600)
        self.assertEqual(len(listed), 2)


if __name__ == '__main__':
    unittest.main()


class GitFailureTextTests(unittest.TestCase):
    def test_a_failed_git_command_names_its_subcommand_and_last_stderr_line(self):
        with tempfile.TemporaryDirectory() as d:
            bot = pr_bot.Bot(root=Path(d), work=Path(d) / 'w')
            with self.assertRaises(pr_bot.Stop) as caught:
                bot.run(['git', 'rev-parse', '--verify', 'nonexistent-ref'])
        text = str(caught.exception)
        self.assertIn('git failed (rev-parse --verify:', text)
