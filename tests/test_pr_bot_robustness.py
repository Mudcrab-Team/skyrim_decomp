"""pr_bot pre-review gate, failure backoff, gh backoff and the two-slot pool, with every host and GitHub call stubbed."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import time
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

    def test_an_origin_finding_the_base_unit_already_had_does_not_refuse_the_prs_functions(self):
        hit = {'function': 'B::f', 'file': 'reconstruction/a/B.cpp', 'repo': 'x/ng', 'path': 'src/B.cpp',
               'trivial': False, 'declared': False, 'fork_of': None, 'similarity': 0.91}
        self.bot.base_origin_flags = lambda units, base, tag: {pr_bot.origin_key(hit)}
        self.assertEqual(self.run_precheck(self.evidence(), origin=[hit]), {})

    def test_a_rewritten_body_or_a_new_finding_still_refuses(self):
        hit = {'function': 'B::f', 'file': 'reconstruction/a/B.cpp', 'repo': 'x/ng', 'path': 'src/B.cpp',
               'trivial': False, 'declared': False, 'fork_of': None, 'similarity': 0.91}
        self.bot.base_origin_flags = lambda units, base, tag: {pr_bot.origin_key(dict(hit, similarity=0.85)),
                                                               pr_bot.origin_key(dict(hit, function='B::g'))}
        found = self.run_precheck(self.evidence(), origin=[hit])
        self.assertIn('does not name it with that file', found[0x10][0])

    def test_a_declared_non_mit_hit_at_base_is_inherited_but_a_new_one_still_blocks(self):
        gpl = {'function': 'B::f', 'file': 'reconstruction/a/B.cpp', 'repo': 'x/ng', 'path': 'src/B.cpp',
               'trivial': False, 'declared': 'yes', 'licence': 'GPL-3.0', 'fork_of': None, 'similarity': 0.91}
        flags = {pr_bot.declared_origin_key(gpl)}
        self.assertTrue(pr_bot.inherited_origin(gpl, flags))
        self.assertFalse(pr_bot.inherited_origin(dict(gpl, function='B::g'), flags))
        self.assertFalse(pr_bot.inherited_origin(dict(gpl, declared=None), flags))
        self.bot.base_origin_flags = lambda units, base, tag: flags
        self.assertEqual(self.run_precheck(self.evidence(), origin=[gpl]), {})
        added = dict(gpl, function='B::g', declared=None)
        found = self.run_precheck(self.evidence(), origin=[gpl, added])
        self.assertIn('does not name it with that file', found[0x10][0])
        problems, _ = pr_bot.origin_findings([added], {})
        self.assertEqual(problems, [('reconstruction/a/B.cpp', 'unpermitted-source')])

    def test_base_flags_come_from_the_units_text_at_base_and_skip_trivial_hits(self):
        import check_origin
        shown = {'base:reconstruction/a/B.cpp': b'int B::f() { return 1; }\n'}

        def run(argv, **kw):
            body = shown.get(argv[-1])
            return subprocess.CompletedProcess(argv, 0 if body is not None else 128, body or b'')
        self.bot.run = run
        base = {'function': 'B::f', 'file': 'reconstruction/a/B.cpp', 'repo': 'x/ng', 'path': 'src/B.cpp',
                'trivial': False, 'declared': None, 'fork_of': None, 'similarity': 0.91}
        hits = [base, dict(base, function='B::g', declared='yes'), dict(base, function='B::h', trivial=True)]
        seen = []

        def check_unit(files, clones, root):
            seen.append(sorted(Path(f).name for f in files))
            return hits
        with mock.patch.object(check_origin, 'open_clones', return_value=([], [])), \
                mock.patch.object(check_origin, 'check_unit', check_unit):
            flags = self.bot.base_origin_flags({'reconstruction/a/B.cpp': [0x10]}, 'base', '7-aaaaaaaa')
            none = self.bot.base_origin_flags({'reconstruction/a/B.cpp': [0x10]}, None, '7-aaaaaaaa')
        self.assertEqual(flags, {pr_bot.origin_key(base), pr_bot.declared_origin_key(hits[1])})
        self.assertEqual(seen, [['B.cpp']])
        self.assertEqual(none, set())

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

    def test_origin_problems_hide_the_private_sibling_path(self):
        hit = {'function': 'A::f', 'file': 'reconstruction/a/A.cpp', 'repo': 'fo4-private@1b765c70',
               'path': 'src/Secret/Path.cpp', 'trivial': False, 'declared': False, 'fork_of': None}
        [(_, line)] = prereview.origin_problems([hit], {})
        self.assertNotIn('src/Secret', line)
        self.assertNotIn('fo4-private', line)

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
        bot = self.bot_failing_with(pr_bot.Waiting('hash check has not finished'))
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
            if argv[0] == 'gh':  # the head re-read before a stage
                return subprocess.CompletedProcess(argv, 0, b'', b'')
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


class RecordRebindTests(WorkDir):
    def test_the_record_step_rebinds_the_unit_maps_before_it_runs_record_py(self):
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        (bot.tree / 'builds').mkdir(parents=True)
        (bot.tree / 'data').mkdir()
        (bot.tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
        (bot.tree / 'data/progress.json').write_text(json.dumps({'functions': []}))
        order = []
        bot.rebind_unit_maps = lambda number, head, rvas: order.append(('rebind', number, list(rvas)))

        def run(argv, **kw):
            order.append((Path(str(argv[1])).name if argv[0] == sys.executable else argv[0],))
            return subprocess.CompletedProcess(argv, 0, b'{"refused": {}}\n', b'')
        bot.run = run
        state = pr_bot.State(self.work / 'state', 7, 'a' * 40)
        state.set('records', str(self.work / 'records'))
        bot.record({'number': 7, 'headRefOid': 'a' * 40, 'author': {'login': 'alice'}}, state, [0x10])
        names = [o[0] for o in order]
        self.assertLess(names.index('rebind'), names.index('record.py'))
        self.assertEqual(order[names.index('rebind')][1:], (7, [0x10]))
        self.assertTrue(state.get('recorded'))


class PoolTests(WorkDir):
    class PoolBot(FakeBot):
        def close_done_claims(self):
            return []

        def sweep_probes(self):
            return []

        def attempt(self, pr, now=None):
            self.arrived(pr, self.tree)
            return {'pr': pr['number'], 'head': pr['headRefOid'], 'blocked': None, 'merge': False}

    def prs(self, *numbers):
        return [{'number': n, 'headRefOid': chr(96 + n) * 40, 'author': {'login': 'alice'}, 'baseRefName': 'main',
                 'isDraft': False} for n in numbers]

    def pool_bot(self, listing, arrived):
        bot = self.PoolBot(self.work)
        bot.arrived = arrived

        def gh_json(*args):
            rows = listing(*args)
            if args[:2] == ('pr', 'view'):  # the refresh a PR gets once it has a free slot
                return dict(next(r for r in rows if r['number'] == int(args[2])), state='OPEN', labels=[])
            return rows
        bot.gh_json = gh_json
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

    def test_the_owners_prs_leave_one_slot_for_an_outside_pr_that_arrives_later(self):
        release, calls, listing = threading.Event(), [], []

        def arrived(pr, tree):
            calls.append(pr['number'])
            release.wait(5)
        rows = self.prs(1, 2, 3)
        for row in rows[:2]:
            row['author'] = {'login': pr_bot.OWNER}
        rows[2]['author'] = {'login': 'carol'}
        listing.extend(rows[:2])
        bot = self.pool_bot(lambda *a: listing + ([rows[2]] if len(ticks) >= 2 else []), arrived)
        bot.demand = [0]
        ticks = []

        def sleep(seconds):
            ticks.append(1)
            time.sleep(0.2)
            if len(ticks) == 4:
                release.set()
        with mock.patch.object(pr_bot, 'mark_owner_reconstruction',
                               lambda bot, prs, known: [row.update(reconstruction_head=row['headRefOid'])
                                                        for row in prs if row['number'] in (1, 2)]):
            pr_bot.poll(bot, 0, workers=2, sleep=sleep, rounds=5)
        self.assertEqual(calls[:2], [1, 3])
        self.assertNotIn(2, calls[:2])

    def test_free_slots_go_to_outside_prs_before_the_owners_even_when_listed_last(self):
        release, calls = threading.Event(), []

        def arrived(pr, tree):
            calls.append(pr['number'])
            release.wait(5)
        rows = self.prs(1, 2, 3)
        for row in rows[:2]:
            row['author'] = {'login': pr_bot.OWNER}
        rows[2]['author'] = {'login': 'carol'}
        bot = self.pool_bot(lambda *a: rows, arrived)
        bot.demand = [0]
        ticks = []

        def sleep(seconds):
            ticks.append(1)
            time.sleep(0.2)
            if len(ticks) == 2:
                release.set()
        with mock.patch.object(pr_bot, 'mark_owner_reconstruction',
                               lambda bot, prs, known: [row.update(reconstruction_head=row['headRefOid'])
                                                        for row in prs if row['number'] in (1, 2)]):
            pr_bot.poll(bot, 0, workers=2, sleep=sleep, rounds=3)
        self.assertEqual(calls[0], 3)
        self.assertEqual(sorted(calls[:2]), [1, 3])

    def test_the_third_slot_opens_only_while_the_machine_is_not_overloaded(self):
        self.assertEqual(pr_bot.POOL_SIZE, 3)
        self.assertTrue(pr_bot.slot_free(0, 3, load=99, cores=8))
        self.assertTrue(pr_bot.slot_free(1, 3, load=99, cores=8))
        self.assertTrue(pr_bot.slot_free(2, 3, load=16, cores=8))
        self.assertFalse(pr_bot.slot_free(2, 3, load=16.5, cores=8))
        self.assertFalse(pr_bot.slot_free(3, 3, load=0, cores=8))
        self.assertFalse(pr_bot.slot_free(2, 2, load=0, cores=8))

    def test_an_owner_pr_with_a_matched_merge_decision_lands_without_a_compile_slot(self):
        release, calls = threading.Event(), []

        def arrived(pr, tree):
            calls.append((pr['number'], tree.name))
            if pr['number'] != 9:
                release.wait(5)
        rows = self.prs(1, 2, 9)
        for row in rows[:2]:
            row['author'] = {'login': 'carol'}
        rows[2].update(author={'login': pr_bot.OWNER}, mergeable='MERGEABLE')
        bot = self.pool_bot(lambda *a: rows, arrived)
        bot.demand = [0]
        pr_bot.State(self.work / 'state', 9, rows[2]['headRefOid']).set(
            'decision', dict(merge=True, blocked=None, verdicts={'16': 'matched', '32': 'matched'}))
        ticks = []

        def sleep(seconds):
            ticks.append(1)
            time.sleep(0.2)
            if len(ticks) == 2:
                release.set()
        with mock.patch.object(pr_bot, 'mark_owner_reconstruction',
                               lambda bot, prs, known: [row.update(reconstruction_head=row['headRefOid'])
                                                        for row in prs if row['number'] == 9]):
            pr_bot.poll(bot, 0, workers=2, sleep=sleep, rounds=3)
        self.assertEqual(dict(calls)[9], 'tree-merge')
        self.assertEqual(sorted(n for n, _ in calls[:3]), [1, 2, 9])

    def test_merge_ready_needs_every_function_matched_and_an_open_head(self):
        owner = {'author': {'login': pr_bot.OWNER}, 'mergeable': 'MERGEABLE'}
        state = pr_bot.State(self.work / 'state', 5, 'b' * 40)
        self.assertFalse(pr_bot.merge_ready(state, owner))
        state.set('decision', dict(merge=True, blocked=None, verdicts={'16': 'matched', '32': 'fail:host2'}))
        self.assertFalse(pr_bot.merge_ready(state, owner))
        state.set('decision', dict(merge=True, blocked=None, verdicts={'16': 'matched'}))
        self.assertTrue(pr_bot.merge_ready(state, owner))
        self.assertFalse(pr_bot.merge_ready(state, dict(owner, author={'login': 'carol'})))
        self.assertFalse(pr_bot.merge_ready(state, dict(owner, mergeable='CONFLICTING')))
        state.set('merged', True)
        self.assertFalse(pr_bot.merge_ready(state, owner))

    def test_a_pr_waiting_on_the_hash_check_gives_its_slot_up_when_another_pr_is_ready(self):
        bot = FakeBot(self.work)
        bot.demand = [1]
        bot.config['hash_wait'] = 3600
        bot.latest_hash_run = lambda head, unusable: {'status': 'in_progress', 'id': 1, 'started_at': 'z'}
        with mock.patch.object(pr_bot, 'HASH_YIELD_AFTER', 0), mock.patch.object(pr_bot.time, 'sleep'):
            with self.assertRaises(pr_bot.Waiting) as caught:
                pr_bot.Bot.host1(bot, 5, 'a' * 40, [0x10], pr_bot.State(self.work / 'state', 5, 'a' * 40))
        self.assertIn('slot released', str(caught.exception))

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

    def test_a_rejected_head_is_not_warmed_or_queued_until_it_is_pushed_again(self):
        bot = self.pool_bot(lambda *a: self.prs(1, 2), lambda pr, tree: self.fail('should not run'))
        warmed = []
        bot.warm = lambda pr: warmed.append(pr['number'])
        pr_bot.State(self.work / 'state', 1, 'a' * 40).set('rejected', 'header')
        pr_bot.State(self.work / 'state', 2, 'b' * 40).set('rejected', 'lint')
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3)
        self.assertEqual(warmed, [])

    def test_pushes_to_main_take_turns(self):
        bot = FakeBot(self.work)
        held = []
        bot.record = lambda pr, state, rvas: (held.append(bot.land_lock.locked()), state.set('recorded', True))
        bot.process(PR)
        self.assertEqual(held, [True])
        self.assertFalse(bot.land_lock.locked())

    def test_a_merged_pr_without_records_is_retried_and_a_recorded_one_is_not(self):
        state = self.work / 'state'
        head = 'c' * 40
        summary = dict(pr=7, head=head, merge=True, verdicts={'0x10': 'matched', '0x20': 'fail:x'})
        first = pr_bot.State(state, 7, head)
        first.set('merged', True)
        first.set('records', '/r')
        first.set('summary', summary)
        other = pr_bot.State(state, 8, 'd' * 40)
        other.set('merged', True)
        other.set('records', '/r')
        other.set('recorded', True)
        other.set('summary', dict(summary, pr=8, head='d' * 40))
        unmerged = pr_bot.State(state, 9, 'e' * 40)
        unmerged.set('summary', dict(summary, pr=9, head='e' * 40))
        self.assertEqual(pr_bot.merged_unrecorded(state, time.time()), [(7, head, [0x10])])
        self.assertEqual(pr_bot.merged_unrecorded(state, time.time() + 10 * 86400), [])
        bot = FakeBot(self.work)
        bot.gh_json = lambda *a: dict(number=7, headRefOid='z', author=dict(login='x'))
        bot.republish_rows = lambda rvas: []
        seen = []
        bot.record = lambda pr, st, rvas: (seen.append((pr['headRefOid'], rvas, bot.land_lock.locked())),
                                           st.set('recorded', True))
        self.assertEqual(bot.retry_records(state), [7])
        self.assertEqual(seen, [(head, [0x10], True)])
        self.assertEqual(bot.retry_records(state), [])
        failing = pr_bot.State(state, 11, 'f' * 40)
        failing.set('merged', True)
        failing.set('records', '/r')
        failing.set('summary', dict(summary, pr=11, head='f' * 40))
        bot.record = lambda pr, st, rvas: (_ for _ in ()).throw(pr_bot.Stop('again'))
        self.assertEqual(bot.retry_records(state), [])
        self.assertFalse(pr_bot.State(state, 11, 'f' * 40).get('recorded'))

    def test_a_retry_binds_a_dropped_unit_map_again_in_the_tree_that_holds_the_tasks(self):
        bot = FakeBot(self.work)
        task = self.work / 'tree-1/.local/tasks/prbot-7-cccccccc-0'
        task.mkdir(parents=True)
        info = dict(task_id='t', symbols='reports/b/unit-symbols/gone.json',
                    functions=[dict(rva='0x10'), dict(rva='0x20')])
        (task / 'task.json').write_text(json.dumps(info))
        ran = []

        def run(argv, **kw):
            ran.append((argv[1:2], kw.get('cwd')))
            written = json.loads((task / 'task.json').read_text())
            self.assertEqual([f['rva'] for f in written['functions']], ['0x10'])  # only what is recorded is bound
            (task / 'task.json').write_text(json.dumps(dict(written, symbols='reports/b/unit-symbols/new.json')))
            return subprocess.CompletedProcess(argv, 0, b'', b'')
        bot.run = run
        bot.config = dict(compare_timeout=5)
        slot = bot.task_slot(7, 'c' * 40)
        self.assertEqual(slot.tree, self.work / 'tree-1')
        self.assertIs(bot.task_slot(8, 'd' * 40), bot)
        slot.rebind_unit_maps(7, 'c' * 40, [0x10])
        self.assertEqual(ran, [(['tools/verifier/bind.py'], self.work / 'tree-1')])
        restored = json.loads((task / 'task.json').read_text())
        self.assertEqual(([f['rva'] for f in restored['functions']], restored['symbols']),
                         (['0x10', '0x20'], 'reports/b/unit-symbols/new.json'))

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
        self.assertEqual(pr_bot.WINDOW_LOW_WATER, 2000)
        for left, expected in ((2000, []), (1999, [(None, True)])):
            regenerated.clear()
            bot.offered_open = lambda left=left: left
            self.assertEqual(bot.refill_offers(), left)
            self.assertEqual(regenerated, expected)
        self.assertFalse(bot.land_lock.locked())
        regenerated.clear()
        bot.offered_open = lambda: 50
        bot.refill_offers(threshold=10)
        self.assertEqual(regenerated, [])

    def test_burn_counts_only_claim_time_reports_added_in_the_window(self):
        now = 1_000_000_000
        log = [str(now - 3600), 'reports/b/0x10.json', 'reports/b/0x99.json', '',
               str(now - 3 * 86400), 'reports/b/0x20.json', 'reports/b/0x21.json', '',
               str(now - 9 * 86400), 'reports/b/0x30.json']
        day, week = pr_bot.burn_per_day(log, {'reports/b/0x10.json', 'reports/b/0x20.json', 'reports/b/0x30.json'}, now)
        # the 9-day-old record is outside both windows
        self.assertEqual((day, week), (1, round(2 / 7, 1)))
        self.assertEqual(pr_bot.burn_per_day([], set(), now), (0, 0))

    def test_window_line_reports_left_claimed_burn_and_runway(self):
        self.assertEqual(pr_bot.window_line(3000, 90, (100, 300.0)),
                         '3000 claimable left, 90 claimed, burn 100/day (24h), 300/day (7d avg), '
                         'about 10.0 days of runway at the 7-day rate')
        self.assertNotIn('runway', pr_bot.window_line(3000, 0, (0, 0)))

    def test_offer_summary_reads_the_tool_line_and_ignores_anything_else(self):
        line = json.dumps({'extra_targets': 5, 'window': {'left_before': 1500, 'added': 2000, 'low_water': 2000,
                                                         'slice': 2000, 'reserved': 12}}).encode()
        self.assertIn('2000 added (1500 claimable before', pr_bot.offer_summary(b'noise\n' + line + b'\n'))
        for bad in (b'', b'not json', b'{"x": 1}', None):
            self.assertEqual(pr_bot.offer_summary(bad), '')

    def test_window_metrics_come_from_the_published_inventory_and_git_history(self):
        tree = self.work / 'metrics-tree'
        (tree / 'data/target-hashes').mkdir(parents=True)
        (tree / 'data/target-hashes/contributor-targets.json').write_text(json.dumps({'claim_function_count': 42}))
        (tree / 'data/progress.json').write_text(json.dumps({'functions': [
            {'owner': 'claim-time', 'report': 'reports/b/0x10.json'}, {'owner': 'x', 'report': 'reports/b/0x11.json'}]}))
        bot = FakeBot(self.work)
        bot.tree = tree
        now = 1_000_000_000
        bot.run = lambda argv, **kw: subprocess.CompletedProcess(
            argv, 0, f'{now - 60}\nreports/b/0x10.json\nreports/b/0x11.json\n'.encode(), b'')
        self.assertEqual(bot.window_metrics(2500, now), pr_bot.window_line(2500, 42, (1, round(1 / 7, 1))))
        bot.run = lambda argv, **kw: (_ for _ in ()).throw(subprocess.SubprocessError('git'))
        self.assertEqual(bot.window_metrics(2500, now), '')

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

    def test_a_hung_refill_does_not_hold_back_a_pr_that_arrives(self):
        started, seen = threading.Event(), []

        class Hanging(PoolTests.PoolBot):
            def refill_offers(self):
                started.set()
                seen.append(self.release.wait(10))  # False if no PR was worked while this was still running
                return 2000

            def attempt(self, pr, now=None):
                started.wait(10)
                self.release.set()
                return super().attempt(pr, now)
        bot = Hanging(self.work)
        bot.release = threading.Event()
        bot.arrived = lambda pr, tree: seen.append(('pr', pr['number']))
        bot.gh_json = lambda *a: self.prs(3) if a[:2] == ('pr', 'list') else dict(
            self.prs(3)[0], state='OPEN', mergeable='MERGEABLE')
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=2, refill_every=3600, await_housekeeping=False)
        self.assertIn(('pr', 3), seen)
        self.assertIn(True, seen)

    def test_housekeeping_has_its_own_tree_and_a_dry_run_keeps_slot_zero(self):
        bot = FakeBot(self.work)
        other = bot.maintenance_tree()
        self.assertEqual(other.tree, self.work / 'tree-maint')
        self.assertNotEqual(other.tree, bot.for_slot(0).tree)
        self.assertTrue(any(c[:2] == ['git', 'clone'] for c in bot.calls))
        dry = FakeBot(self.work, dry_run=True)
        self.assertEqual(dry.maintenance_tree().tree, dry.for_slot(0).tree)
        self.assertFalse(any(c[:2] == ['git', 'clone'] for c in dry.calls))

    def test_counting_the_window_does_not_hold_the_land_lock_but_regenerating_does(self):
        seen = []

        class Counting(FakeBot):
            def offered_open(self):
                seen.append(('count', self.land_lock.locked()))
                return left[0]

            def regenerate(self, number, extra=()):
                seen.append(('regenerate', self.land_lock.locked()))
        left = [2500]
        bot = Counting(self.work)
        self.assertEqual(bot.refill_offers(), 2500)
        left[0] = 10
        self.assertEqual(bot.refill_offers(), 10)
        self.assertEqual(seen, [('count', False), ('count', False), ('regenerate', True)])

    def test_idle_poll_sweeps_finished_claims_once_per_period_and_survives_a_failure(self):
        calls = []

        class Sweeping(PoolTests.PoolBot):
            def close_done_claims(self):
                calls.append(1)
                if len(calls) == 1:
                    raise RuntimeError('gh failed')
                return [5]
        bot = Sweeping(self.work)
        listed = []
        bot.gh_json = lambda *a: listed.append(1) or []
        pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3)
        self.assertEqual(len(calls), 1)
        self.assertEqual(len(listed), 3)
        calls.clear()
        with mock.patch.object(pr_bot, 'CLAIM_SWEEP_EVERY', 0):
            pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3)
        self.assertEqual(len(calls), 3)

    def test_idle_poll_sweeps_probe_prs_and_survives_a_failure(self):
        calls = []

        class Sweeping(PoolTests.PoolBot):
            def sweep_probes(self):
                calls.append(1)
                if len(calls) == 1:
                    raise pr_bot.Stop('gh failed')
                return [9]
        bot = Sweeping(self.work)
        bot.gh_json = lambda *a: []
        with mock.patch.object(pr_bot, 'PROBE_SWEEP_EVERY', 0):
            pr_bot.poll(bot, 0, sleep=lambda s: None, rounds=3)
        self.assertEqual(len(calls), 3)

    def test_close_done_claims_reads_origin_main_and_closes_through_the_claims_tool(self):
        bot = FakeBot(self.work)
        seen = {}

        def fake_close(gh, public):
            seen['public'] = public
            return [9]
        with mock.patch('claims.git_json', return_value={'functions': []}) as read, \
                mock.patch('claims.close_completed', side_effect=fake_close):
            self.assertEqual(bot.close_done_claims(), [9])
        read.assert_called_once_with(bot.tree, 'origin/main')
        self.assertEqual(seen['public'], {'functions': []})
        self.assertEqual(bot.calls[-1][:4], ['git', 'fetch', '--quiet', 'origin'])


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
