"""Target rows for the RVAs an open PR claims, the dropped-claim note, and the header-budget message.

Synthetic tables and trees only: no image, no game bytes.
"""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import lint_reconstruction  # noqa: E402
import pr_bot  # noqa: E402
import target_hash_offers as offers  # noqa: E402

HEAD = 'a' * 40


def row(kind='ordinary', size=40, verdict='supported'):
    return dict(kind=kind, size=size, v2=dict(verdict=verdict))


class OnDemandSelectionTests(unittest.TestCase):
    TABLE = {0x2000: row(), 0x2100: row(kind='thunk'), 0x2200: row(size=0), 0x2300: row(verdict='unsupported'),
             0x2400: row(verdict='caution')}

    def test_only_real_ordinary_supported_function_starts_are_accepted(self):
        got, refused = offers.select_on_demand(self.TABLE, {0x2500}, [0x2000, 0x2004, 0x2100, 0x2200, 0x2300,
                                                                       0x2400, 0x2500, 0x10])
        self.assertEqual(got, [0x2000, 0x2400])
        self.assertEqual(refused, {0x2004: 'not-a-function-start', 0x2100: 'not-an-ordinary-function',
                                   0x2200: 'not-an-ordinary-function', 0x2300: 'locally-unsupported',
                                   0x2500: 'already-recorded', 0x10: 'not-a-function-start'})

    def test_earlier_rows_stay_until_recorded_or_no_longer_valid(self):
        got, refused = offers.select_on_demand(self.TABLE, {0x2400}, [], retained=[0x2000, 0x2400, 0x2300, 0x9999])
        self.assertEqual((got, refused), ([0x2000], {}))

    def test_a_run_publishes_a_bounded_number(self):
        table = {0x2000 + 0x10 * i: row() for i in range(offers.ON_DEMAND_MAX + 30)}
        got, _ = offers.select_on_demand(table, set(), list(table))
        self.assertEqual(len(got), offers.ON_DEMAND_MAX)

    def test_the_cap_never_cuts_rows_already_published(self):
        table = {0x2000 + 0x10 * i: row() for i in range(offers.ON_DEMAND_MAX + 30)}
        retained = sorted(table)[-40:]  # the highest RVAs are what an RVA-ordered cut drops first
        got, _ = offers.select_on_demand(table, set(), sorted(table)[:10], retained=retained)
        self.assertTrue(set(retained) <= set(got))
        self.assertEqual(len(got), 50)

    def test_retained_rows_come_from_the_published_list(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / offers.hashes.OFFERED
            path.parent.mkdir(parents=True)
            path.write_text(json.dumps({'functions': [{'rva': 1, 'size': 4}, {'rva': 2, 'size': 4, 'on_demand': True}]}))
            self.assertEqual(offers.retained_on_demand(tmp), {2})
            self.assertEqual(offers.retained_on_demand(Path(tmp) / 'missing'), set())


class BotRowsTests(unittest.TestCase):
    UNIT = 'reconstruction/a/U'

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)
        self.bot = pr_bot.Bot(root=ROOT, work=self.work)
        tree = self.bot.tree
        (tree / 'reconstruction/a').mkdir(parents=True)
        (tree / 'data/target-hashes').mkdir(parents=True)
        self.shard = tree / 'data/target-hashes/sse-steam-1-7-104-part-000.json'
        self.shard.write_text(json.dumps({'functions': [{'rva': 0x1000}]}))
        (tree / 'data/progress.json').write_text(json.dumps({'functions': [{'rva': 0x5000}]}))
        (tree / f'{self.UNIT}.cpp').write_text('#include "U.h"\n')
        (tree / f'{self.UNIT}.h').write_text(
            '// 0x1000 U::f\n// 0x1100 U::g\n'
            '// U::h: GUESS; callees at RVAs 0x1ca490, 0x1cf2e0 and a global at 0x2078a30\n#pragma once\n')
        self.files = [{'filename': f'{self.UNIT}.h', 'status': 'modified'}]
        self.state = pr_bot.State(self.work / 's', 7, HEAD)
        self.calls = []
        self.bot.regenerate = self.regenerate
        self.bot.prepare_tree = lambda tip: self.calls.append(('prepare', tip))
        self.bot.overlay = lambda head, files: self.calls.append(('overlay', head))
        self.bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, 0, b'c' * 40 + b'\n', b'')
        self.table = {0x1100: row()}

    def regenerate(self, number, extra=()):
        self.calls.append(('regenerate', list(extra)))
        self.shard.write_text(json.dumps({'functions': [{'rva': 0x1000}, *({'rva': r} for r in extra)]}))

    def ensure(self):
        with mock.patch('claimable.load_table', lambda path: self.table):
            self.bot.ensure_rows(7, HEAD, self.files, self.state)

    def test_only_compact_lines_are_claims_and_the_unrowed_one_is_dropped(self):
        self.assertEqual(self.bot.unit_claims(self.files), {f'{self.UNIT}.cpp': {0x1000, 0x1100}})
        self.assertEqual(self.bot.dropped_claims(self.files), [0x1100])

    def test_a_claim_without_a_row_gets_its_row_published_and_the_head_a_fresh_run(self):
        self.ensure()
        self.assertEqual(self.calls, [('regenerate', [0x1100]), ('prepare', 'c' * 40), ('overlay', HEAD)])
        self.assertIsNotNone(self.state.get('rows_at'))
        self.assertEqual(self.bot.dropped_claims(self.files), [])
        self.assertEqual(self.bot.units(self.files), {f'{self.UNIT}.cpp': [0x1000, 0x1100]})

    def test_publication_happens_once_per_head(self):
        self.ensure()
        self.ensure()
        self.assertEqual([c for c in self.calls if c[0] == 'regenerate'], [('regenerate', [0x1100])])

    def test_a_claim_that_is_not_a_function_start_is_left_out_and_nothing_is_regenerated(self):
        self.table = {}
        self.ensure()
        self.assertEqual(self.calls, [])
        self.assertIsNone(self.state.get('rows_at'))
        self.assertEqual(self.bot.dropped_claims(self.files), [0x1100])

    def test_a_missing_function_table_publishes_nothing(self):
        self.table = None
        with mock.patch('sys.stderr'):
            self.ensure()
        self.assertEqual(self.calls, [])

    def test_a_dry_run_publishes_nothing(self):
        self.bot.dry_run = True
        self.ensure()
        self.assertEqual(self.calls, [])

    def test_a_unit_whose_claims_all_lack_rows_is_rejected_with_the_addresses(self):
        (self.bot.tree / f'{self.UNIT}.h').write_text('// 0x1100 U::g\n#pragma once\n')
        with self.assertRaises(pr_bot.Rejected) as caught:
            self.bot.units(self.files)
        self.assertIn('0x1100', caught.exception.text)
        self.assertIn('Not compared', caught.exception.text)

    def test_the_sticky_comment_names_dropped_claims_even_when_nothing_else_is_said(self):
        text = pr_bot.dropped_claims_text([0x1100, 0x1200])
        self.assertIn('0x1100, 0x1200', text)
        self.assertIn('no target row', text)
        many = pr_bot.dropped_claims_text(list(range(0x1000, 0x1000 + 30)))
        self.assertIn('and 10 more', many)


class Host1FreshRunTests(unittest.TestCase):
    """After rows are published, the head's earlier hash run (against the old base) is not used."""

    def test_an_older_run_is_set_aside_and_a_new_probe_is_requested(self):
        with tempfile.TemporaryDirectory() as tmp:
            bot = pr_bot.Bot(root=ROOT, work=Path(tmp))
            bot.config['hash_wait'] = 0
            old = {'name': 'hash', 'head_sha': HEAD, 'status': 'completed', 'conclusion': 'success', 'id': 1,
                   'started_at': '2026-01-01T00:00:00Z', 'details_url': 'https://github.com/o/r/actions/runs/1/job/9'}
            calls = []
            bot.run = lambda argv, **kw: calls.append([str(a) for a in argv]) or subprocess.CompletedProcess(argv, 0, b'', b'')
            bot.gh_json = lambda *a: {'check_runs': [old]} if '/check-runs' in a[1] else ([] if a[0] == 'pr' else {'workflow_runs': []})
            state = pr_bot.State(Path(tmp) / 's', 7, HEAD)
            state.set('rows_at', '2026-01-02T00:00:00Z')
            with self.assertRaises(pr_bot.Stop):
                bot.host1(7, HEAD, [0x10], state, {})
            self.assertTrue(any(c[:5] == ['gh', 'api', '-X', 'DELETE', f'repos/{pr_bot.REPOSITORY}/git/refs/heads/probe/pr-7']
                                for c in calls))
            self.assertTrue(any(c[:4] == ['gh', 'api', '-X', 'POST'] and f'sha={HEAD}' in c for c in calls))
            self.assertFalse(any(c[:3] == ['gh', 'run', 'download'] for c in calls))


class Host1LateRowTests(unittest.TestCase):
    """A finished run whose rows say `no-target` for a function main now has a row for was run against an old base."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)
        self.bot = pr_bot.Bot(root=ROOT, work=self.work)
        self.bot.config['hash_wait'] = 0
        self.bot.config['download_retry_wait'] = 0
        shards = self.bot.tree / 'data/target-hashes'
        shards.mkdir(parents=True)
        (shards / 'sse-steam-1-7-104-part-000.json').write_text(json.dumps({'functions': [{'rva': 0x10}, {'rva': 0x20}]}))
        self.job = {'name': 'hash', 'head_sha': HEAD, 'status': 'completed', 'conclusion': 'success', 'id': 1,
                    'started_at': '2026-01-01T00:00:00Z', 'details_url': 'https://github.com/o/r/actions/runs/555/job/9'}
        self.rows = [{'rva': '0x10', 'unit': 'reconstruction/a/B.cpp', 'result': 'hash-match'},
                     {'rva': '0x20', 'unit': 'reconstruction/a/B.cpp', 'result': 'no-target', 'base': 'no-target'},
                     {'rva': '0x30', 'unit': 'reconstruction/a/B.cpp', 'result': 'no-target', 'base': 'no-target'}]
        self.calls = []
        self.bot.run = self.fake_run
        self.bot.gh_json = self.gh
        self.state = pr_bot.State(self.work / 's', 7, HEAD)

    def gh(self, *args):
        if '/check-runs' in args[1]:
            return {'check_runs': [self.job]}
        if '/artifacts' in args[1]:
            return {'artifacts': [{'name': 'hash-result'}]}
        if args[0] == 'pr':
            return []
        return {'id': 555, 'head_sha': HEAD}

    def fake_run(self, argv, **kw):
        argv = [str(a) for a in argv]
        self.calls.append(argv)
        if argv[:3] == ['gh', 'run', 'download']:
            target = Path(argv[argv.index('-D') + 1])
            (target / 'hash-result.json').write_text(json.dumps({'0x10': 'pass', '0x20': 'fail'}))
            (target / 'target-result.json').write_text(json.dumps({'head_sha': HEAD, 'functions': self.rows}))
        return subprocess.CompletedProcess(argv, 0, b'', b'')

    def test_a_function_with_a_row_on_main_but_no_target_in_the_run_asks_for_a_fresh_run(self):
        self.bot.config['hash_wait'] = 600

        waits = []

        def stop_waiting(_seconds):
            waits.append(1)
            if len(waits) > 1:
                raise pr_bot.Stop('waiting for the fresh run')
        with mock.patch.object(pr_bot.time, 'sleep', stop_waiting), self.assertRaises(pr_bot.Stop):
            self.bot.host1(7, HEAD, [0x10, 0x20], self.state, {})
        self.assertEqual(self.state.get('rows_rerun'), [0x20])
        self.assertIsNotNone(self.state.get('rows_at'))
        self.assertTrue(any(c[:4] == ['gh', 'api', '-X', 'POST'] and f'sha={HEAD}' in c for c in self.calls))

    def test_a_no_target_without_a_published_row_is_taken_as_it_is(self):
        got = self.bot.host1(7, HEAD, [0x10, 0x30], self.state, {})
        self.assertEqual(got[0x10], 'pass')
        self.assertIsNone(self.state.get('rows_rerun'))

    def test_the_rerun_is_asked_for_once(self):
        self.state.set('rows_rerun', [0x20])
        got = self.bot.host1(7, HEAD, [0x10, 0x20], self.state, {})
        self.assertEqual(got[0x20], 'fail')


class HeaderBudgetMessageTests(unittest.TestCase):
    HEADER = '\n'.join(['// Source exposure: mixed', '// 0x1000 A::f', *(f'// extra line {i}' for i in range(9)),
                        '// Task: `x` @someone'])

    def problems(self):
        return lint_reconstruction.header_budget_problems('reconstruction/a/A.h', self.HEADER)

    def test_names_the_file_the_overage_and_the_counted_lines(self):
        (text,) = self.problems()
        self.assertIn('reconstruction/a/A.h: header is 5 lines over the budget: 11 lines count', text)
        self.assertIn('keep at most 6', text)
        self.assertIn('  - line 1: `// Source exposure: mixed`', text)
        self.assertIn('  - line 3: `// extra line 0`', text)
        self.assertNotIn('line 2:', text)  # the compared-function line is free
        self.assertIn('Delete or merge at least 5', text)

    def test_echoed_lines_carry_no_backticks_or_live_mentions(self):
        (text,) = self.problems()
        self.assertNotIn('@someone', text)
        self.assertIn("'x'", text)

    def test_a_long_list_is_cut_and_counted(self):
        header = '\n'.join(f'// line {i}' for i in range(30))
        (text,) = lint_reconstruction.header_budget_problems('reconstruction/a/B.h', header)
        self.assertIn('24 lines over', text)
        self.assertIn('and 15 more', text)

    def test_the_bot_comment_carries_the_message(self):
        text = pr_bot.header_rejection(self.problems())
        self.assertIn('held before any compile', text)
        self.assertIn('reconstruction/a/A.h: header is 5 lines over', text)
        self.assertIn('line 3', text)


if __name__ == '__main__':
    unittest.main()


class BlockCommentFindingsTests(unittest.TestCase):
    """A comment that sends the contributor to "the findings below" must list them, whatever the block."""

    def decision(self, blocked, key):
        return {'blocked': blocked, 'merge': False, key: [0x10], 'companions': [0x10] if key == 'companions' else [],
                'verdicts': {0x10: 'fail:precheck', 0x20: 'fail:precheck', 0x30: 'matched'},
                'pre': {0x10: ['reconstruction/a/B.cpp: finding one'], 0x20: ['reconstruction/a/B.cpp: finding one',
                                                                         '0x20: finding two']}}

    def test_stale_and_companion_comments_list_the_precheck_findings_once(self):
        for blocked, key in (('stale', 'stale'), ('companion', 'companions')):
            with self.subTest(blocked=blocked):
                text = pr_bot.outcome_body(HEAD, self.decision(blocked, key))
                self.assertIn('Findings from the mechanical checks', text)
                self.assertEqual(text.count('finding one'), 1)
                self.assertIn('- 0x20: finding two', text)
                self.assertLess(text.index('Findings from'), text.index('Please keep'))

    def test_the_findings_block_is_absent_when_no_function_failed_the_precheck(self):
        decision = self.decision('stale', 'stale')
        decision['verdicts'] = {0x10: 'fail:host1'}
        self.assertNotIn('Findings from', pr_bot.outcome_body(HEAD, decision))


class OutsideFirstTests(unittest.TestCase):
    def test_outside_prs_are_submitted_before_the_owners_in_listing_order(self):
        def pr(number, login):
            return {'number': number, 'author': {'login': login}}
        listed = [pr(582, pr_bot.OWNER), pr(579, pr_bot.OWNER.upper()), pr(574, 'aivv73'), pr(570, pr_bot.OWNER),
                  pr(550, 'eclepso')]
        self.assertEqual([p['number'] for p in pr_bot.outside_first(listed)], [574, 550, 582, 579, 570])


class RepublishRowsTests(unittest.TestCase):
    """A merged PR whose rows main lost gets them published again before its record step."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        work = Path(self.tmp.name)
        self.bot = pr_bot.Bot(root=ROOT, work=work)
        shards = self.bot.tree / 'data/target-hashes'
        shards.mkdir(parents=True)
        (shards / 'sse-steam-1-7-104-part-000.json').write_text(json.dumps({'functions': [{'rva': 0x2010}]}))
        (self.bot.tree / 'data/progress.json').write_text(json.dumps({'functions': [{'rva': 0x2040}]}))
        table = work / 'functions.jsonl'
        table.write_text('\n'.join(json.dumps(dict(rva=r, **row())) for r in (0x2010, 0x2020, 0x2030, 0x2040)) + '\n')
        patch = mock.patch.dict('os.environ', {'SR_FUNCTION_TABLE': str(table)})
        patch.start()
        self.addCleanup(patch.stop)
        self.bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, 0, b'', b'')
        self.asked = []

    def regenerate(self, number, extra=()):
        self.asked.append(sorted(extra))
        self.bot.tree.joinpath('data/target-hashes/sse-steam-1-7-104-part-001.json').write_text(
            json.dumps({'functions': [{'rva': r} for r in extra]}))

    def test_only_the_rows_main_lacks_are_published_again(self):
        self.bot.regenerate = self.regenerate
        got = self.bot.republish_rows([0x2010, 0x2020, 0x2030, 0x2040])
        self.assertEqual(self.asked, [[0x2020, 0x2030]])
        self.assertEqual(got, [0x2020, 0x2030])

    def test_nothing_is_published_when_every_row_is_there(self):
        self.bot.regenerate = self.regenerate
        self.assertEqual(self.bot.republish_rows([0x2010, 0x2040]), [])
        self.assertEqual(self.asked, [])
