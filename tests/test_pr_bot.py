"""tools/pr_bot.py decisions and orchestration, with every host, model and GitHub call stubbed."""
import contextlib
import hashlib
import io
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
import pr_bot  # noqa: E402

HEAD = 'a' * 40
BASE = 'b' * 40
PR = {'number': 7, 'headRefOid': HEAD, 'author': {'login': 'alice'}}
GOOD = json.dumps({'leak': 'no', 'functions': {'0x10': {'verdict': 'approve', 'ground': 'none'},
                                                '0x20': {'verdict': 'approve', 'ground': 'none'}}})


class HintTests(unittest.TestCase):
    def test_header_request_lines_become_bind_hints_for_compared_functions_only(self):
        text = ('// CI hash: 0xEEE380 ?Impl@A@@QEAAXXZ\n// CI hash: 0x99 ?Other@A@@QEAAXXZ\n'
                '// CI hash:0x10 ?Bad@A@@QEAAXXZ\nint x;\n// CI hash: 0x20 ?Late@A@@QEAAXXZ extra\n')
        self.assertEqual(pr_bot.ci_hash_hints(text, [0xeee380]), {'?Impl@A@@QEAAXXZ': '0xeee380'})
        self.assertEqual(pr_bot.ci_hash_hints(text, []), {})

    def test_recorded_symbol_hints_pick_the_overload_by_record(self):
        task = {'export': {'unit_already_records': [
            {'rva': '0x1900a0', 'symbol': '?F@A@@QEAAXXZ'}, {'rva': '0x405a50', 'symbol': '?F@A@@QEBAXXZ'},
            {'rva': '0x10', 'symbol': None}]}}
        self.assertEqual(pr_bot.recorded_symbol_hints(task, [0x1900a0, 0x405a50, 0x10]),
                         {'?F@A@@QEAAXXZ': '0x1900a0', '?F@A@@QEBAXXZ': '0x405a50'})
        self.assertEqual(pr_bot.recorded_symbol_hints(task, [0x405a50]), {'?F@A@@QEBAXXZ': '0x405a50'})
        self.assertEqual(pr_bot.recorded_symbol_hints({}, [1]), {})


class PollableTests(unittest.TestCase):
    def pr(self, login, labels=(), base='main', draft=False):
        return {'number': 1, 'author': {'login': login}, 'baseRefName': base, 'isDraft': draft,
                'labels': [{'name': n} for n in labels]}

    def test_owner_pr_is_skipped_unless_it_carries_the_opt_in_label(self):
        owner = pr_bot.OWNER
        self.assertEqual(pr_bot.pollable([self.pr(owner), self.pr(owner, ['other'])]), [])
        opted = self.pr(owner, [pr_bot.OPT_IN_LABEL])
        self.assertEqual(pr_bot.pollable([opted]), [opted])

    def test_outside_pr_needs_no_label_but_drafts_and_other_bases_stay_out(self):
        outside = self.pr('alice')
        self.assertEqual(pr_bot.pollable([outside, self.pr('alice', draft=True), self.pr('alice', base='dev'),
                                          self.pr(pr_bot.OWNER, [pr_bot.OPT_IN_LABEL], draft=True)]), [outside])
        self.assertEqual(pr_bot.pollable([{'number': 2, 'author': {'login': 'bob'}, 'baseRefName': 'main',
                                           'isDraft': False}]), [{'number': 2, 'author': {'login': 'bob'},
                                                                  'baseRefName': 'main', 'isDraft': False}])


class DecisionTests(unittest.TestCase):
    def table(self, h1, h2, rv, **kw):
        return pr_bot.decide([0x10], {0x10: h1}, {0x10: h2}, {0x10: rv}, **kw)

    def test_matched_needs_both_hosts_and_the_review(self):
        self.assertEqual(self.table('pass', 'pass', 'approve')['verdicts'][0x10], 'matched')
        self.assertEqual(self.table('fail', 'pass', 'approve')['verdicts'][0x10], 'fail:host1')
        self.assertEqual(self.table('pass', 'fail', 'approve')['verdicts'][0x10], 'fail:host2')
        self.assertEqual(self.table('pass', 'pass', 'reject')['verdicts'][0x10], 'fail:review')
        self.assertEqual(self.table('pass', None, 'approve')['verdicts'][0x10], 'fail:missing')
        self.assertTrue(self.table('pass', 'pass', 'approve')['merge'])
        self.assertFalse(self.table('pass', 'pass', 'reject')['merge'])

    def test_leak_or_grep_hit_blocks_the_whole_pr(self):
        for kw in ({'leak': 'yes'}, {'leak': 'unreadable'}, {'leak_hits': ['R1']}):
            d = pr_bot.decide([0x10, 0x20], {0x10: 'pass', 0x20: 'pass'}, {0x10: 'pass', 0x20: 'pass'},
                              {0x10: 'approve', 0x20: 'approve'}, **kw)
            self.assertEqual((d['blocked'], d['merge']), ('leak', False))
            self.assertEqual(set(d['verdicts'].values()), {'blocked'})

    def test_a_leak_claim_blocks_only_with_recognised_evidence(self):
        rows = {'0x10': {'verdict': 'approve', 'ground': 'none'}}
        bare = json.dumps({'leak': 'yes', 'why': 'x', 'functions': rows})
        self.assertEqual(pr_bot.parse_review(bare, [0x10]), ('no', {0x10: 'approve'}))
        odd = json.dumps({'leak': 'yes', 'leak_evidence': ['style'], 'functions': rows})
        self.assertEqual(pr_bot.parse_review(odd, [0x10])[0], 'no')
        backed = json.dumps({'leak': 'yes', 'leak_evidence': ['decompiler-artifact'], 'functions': rows})
        self.assertEqual(pr_bot.parse_review(backed, [0x10])[0], 'yes')
        self.assertEqual(pr_bot.review_leak_evidence(backed), ['decompiler-artifact'])

    def test_justified_cast_note_approves_and_comment_states_the_real_reason(self):
        args = ([0x10], {0x10: 'pass'}, {0x10: 'pass'}, {0x10: 'approve'})
        self.assertTrue(pr_bot.decide(*args, leak='no')['merge'])
        review = pr_bot.decide(*args, leak='yes', leak_evidence=['copied-text'])
        self.assertEqual((review['blocked'], review['leak_source']), ('leak', 'review'))
        body = pr_bot.comment_body(HEAD, review)
        self.assertIn('copied-text', body)
        self.assertNotIn('held before any compile', body)
        grep = pr_bot.decide(*args, leak_hits=['R1'])
        self.assertIn('held before any compile', pr_bot.comment_body(HEAD, grep, ['R1']))
        broken = pr_bot.decide(*args, leak='unreadable')
        self.assertIn('bot fault', pr_bot.comment_body(HEAD, broken))
        self.assertNotIn('held before any compile', pr_bot.comment_body(HEAD, broken))

    def test_regression_blocks_but_preexisting_debt_does_not(self):
        d = pr_bot.decide([0x10, 0x20], {0x10: 'pass', 0x20: 'regressed'}, {0x10: 'pass', 0x20: 'pass'},
                          {0x10: 'approve', 0x20: 'approve'})
        self.assertEqual((d['blocked'], d['merge']), ('regression', False))
        d = pr_bot.decide([0x10, 0x20], {0x10: 'pass', 0x20: 'preexisting-fail'}, {0x10: 'pass', 0x20: 'fail'},
                          {0x10: 'approve', 0x20: 'reject'})
        self.assertEqual(d['verdicts'], {0x10: 'matched', 0x20: 'debt'})
        self.assertIsNone(d['blocked'])
        self.assertTrue(d['merge'])
        self.assertNotIn('0x20', pr_bot.comment_body(HEAD, d))

    def test_rejection_comment_carries_filtered_review_reasons(self):
        text = json.dumps({'functions': {
            '0x10': {'verdict': 'reject', 'ground': 'plausibility', 'why': 'Accessed field hidden in a byte array.',
                     'naming_findings': ['Placeholder member names.', 'bytes 0x48 0x89 0x5c 0x24 0x08 leak']},
            '0x20': {'verdict': 'approve', 'why': 'fine'}}})
        notes = pr_bot.review_notes(text, [0x10, 0x20])
        self.assertEqual(notes, {0x10: ['Accessed field hidden in a byte array.', 'Placeholder member names.']})
        d = pr_bot.decide([0x10], {0x10: 'pass'}, {0x10: 'pass'}, {0x10: 'reject'})
        body = pr_bot.comment_body(HEAD, dict(d, notes=notes))
        self.assertIn('the review did not approve it', body)
        self.assertIn('  - Accessed field hidden in a byte array.', body)
        self.assertNotIn('0x48', body)
        self.assertEqual(pr_bot.review_notes('nonsense', [0x10]), {})

    def test_review_rejection_names_the_unit_and_a_category_in_every_blocking_comment(self):
        text = json.dumps({'functions': {
            '0x10': {'verdict': 'reject', 'ground': 'provenance', 'why': 'Header contradicts itself.'},
            '0x20': {'verdict': 'reject', 'ground': 'surprise', 'why': 'x'},
            '0x30': {'verdict': 'approve', 'ground': 'none', 'why': 'fine'}}})
        grounds = pr_bot.review_grounds(text, [0x10, 0x20, 0x30])
        self.assertEqual(grounds, {0x10: 'provenance', 0x20: 'other'})
        self.assertEqual(pr_bot.review_grounds('nonsense', [0x10]), {})
        units = {0x10: 'reconstruction/a/Foo.cpp', 0x20: 'reconstruction/a/Bar.cpp'}
        d = pr_bot.decide([0x10, 0x20], {0x10: 'pass', 0x20: 'pass'}, {0x10: 'pass', 0x20: 'pass'},
                          {0x10: 'reject', 0x20: 'reject'})
        body = pr_bot.comment_body(HEAD, dict(d, grounds=grounds, unit_files=units))
        self.assertIn('- 0x10: the review did not approve it (unit reconstruction/a/Foo.cpp; provenance label', body)
        self.assertIn('- 0x20: the review did not approve it (unit reconstruction/a/Bar.cpp; no category given)', body)
        self.assertNotIn('contradicts', body)
        stale = pr_bot.decide([0x10, 0x20], {0x10: 'pass', 0x20: 'pass'}, {0x10: 'pass', 0x20: 'pass'},
                              {0x10: 'reject', 0x20: 'approve'}, stale=[0x10])
        body = pr_bot.comment_body(HEAD, dict(stale, grounds=grounds, unit_files=units))
        self.assertIn('go stale', body)
        self.assertIn('0x10: the review did not approve it (unit reconstruction/a/Foo.cpp; provenance', body)
        self.assertNotIn('0x20', body)

    def test_a_bad_review_answer_never_approves(self):
        self.assertEqual(pr_bot.parse_review('nonsense', [0x10]), ('unreadable', {}))
        leak, out = pr_bot.parse_review('x ' + GOOD, [0x10, 0x30])
        self.assertEqual((leak, out), ('no', {0x10: 'approve', 0x30: 'reject'}))


class ScopeAndMergeTests(unittest.TestCase):
    def test_scope_rejects_anything_outside_reconstruction(self):
        ok = [{'filename': 'reconstruction/a/B.cpp', 'status': 'added'}]
        self.assertIsNone(pr_bot.scope_problem(ok))
        for bad in ({'filename': '.github/workflows/x.yml'}, {'filename': 'tools/x.py'},
                    {'filename': 'reconstruction/../tools/x.py'}, {'filename': 'data/progress.json'},
                    {'filename': 'reconstruction/a.cpp', 'previous_filename': 'tools/old.py'}):
            self.assertEqual(pr_bot.scope_problem(ok + [bad]), 'scope')
        self.assertEqual(pr_bot.scope_problem([]), 'empty')

    def test_merge_command_pins_the_head_and_uses_a_bot_message(self):
        subject, body = pr_bot.squash_message(7, 'alice', 99, [0x20, 0x10])
        argv = pr_bot.merge_command(7, HEAD, subject, body)
        self.assertEqual(argv[argv.index('--match-head-commit') + 1], HEAD)
        self.assertIn('--squash', argv)
        self.assertEqual(subject, 'Reconstruct 2 functions (0x10, 0x20) (#7)')
        self.assertIn('Co-authored-by: alice <99+alice@users.noreply.github.com>', body)


class DropLandedTests(unittest.TestCase):
    def test_only_files_that_differ_from_main_remain(self):
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            def git(*a):
                return subprocess.run(['git', '-C', tmp, *a], check=True, capture_output=True, text=True).stdout.strip()
            git('init', '-q', '-b', 'main')
            git('config', 'user.email', 't@example.invalid'); git('config', 'user.name', 't')
            (repo / 'reconstruction').mkdir()
            (repo / 'reconstruction/low.cpp').write_text('1\n')
            git('add', '.'); git('commit', '-qm', 'main'); git('update-ref', 'refs/remotes/origin/main', 'HEAD')
            (repo / 'reconstruction/high.cpp').write_text('2\n')
            git('add', '.'); git('commit', '-qm', 'head')
            head = git('rev-parse', 'HEAD')
            bot = pr_bot.Bot(root=repo, work=repo / 'w')
            files = [{'filename': 'reconstruction/low.cpp', 'status': 'added'},
                     {'filename': 'reconstruction/high.cpp', 'status': 'added'}]
            self.assertEqual([f['filename'] for f in bot.drop_landed(head, files)], ['reconstruction/high.cpp'])


class RemovedAcceptedTests(unittest.TestCase):
    def test_only_accepted_functions_a_changed_unit_no_longer_names_are_removed(self):
        with tempfile.TemporaryDirectory() as tmp:
            tree = Path(tmp)
            (tree / 'builds').mkdir()
            (tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
            (tree / 'data').mkdir()
            (tree / 'reconstruction/a').mkdir(parents=True)
            (tree / 'reconstruction/a/Kept.cpp').write_text('// RVA 0x10, 4 bytes\n')
            (tree / 'reconstruction/a/Edited.cpp').write_text('// RVA 0x20, 4 bytes\n')
            fns = []
            for rva, unit in ((0x10, 'Kept'), (0x20, 'Edited'), (0x30, 'Edited'), (0x40, 'Gone')):
                report = tree / f'r{rva}.json'
                report.write_text(json.dumps({'source': {'compiled': f'reconstruction/a/{unit}.cpp'}}))
                fns.append({'build_id': 'b', 'status': 'matched', 'rva': rva, 'report': report.name})
            (tree / 'data/progress.json').write_text(json.dumps({'functions': fns}))
            bot = pr_bot.Bot(root=tree, work=tree / 'w')
            bot.tree = tree
            files = [{'filename': 'reconstruction/a/Edited.cpp'}, {'filename': 'reconstruction/a/Gone.cpp'}]
            units = {'reconstruction/a/Edited.cpp': [0x20]}
            self.assertEqual(bot.removed_accepted(units, files, [0x20]), [0x30, 0x40])


class FakeBot(pr_bot.Bot):
    def __init__(self, work, files=None, h1=None, h2=None, review=GOOD, grep=(False, []), **kw):
        super().__init__(root=ROOT, work=work, **kw)
        self.calls, self.files = [], files or [{'filename': 'reconstruction/a/B.cpp', 'status': 'added'}]
        self.h1 = h1 or {0x10: 'pass', 0x20: 'pass'}
        self.h2 = h2 or {0x10: 'pass', 0x20: 'pass'}
        self.review_text, self.grep = review, grep
        self.merge_ok = True
        self.landed = None
        self.refused = set()
        self.history = None
        self.extra = {}
        self.stale = []
        self.removed = []
        self.comments = []  # the PR's issue comments as {id, login, body}
        self.sizes = {}
        self.pre = {}  # rva -> mechanical findings the pre-review gate returns

    def run(self, argv, **kw):
        argv = [str(a) for a in argv]
        self.calls.append(argv)
        out = BASE.encode() if argv[:2] == ['git', 'merge-base'] else b''
        if argv[:3] == ['gh', 'pr', 'comment']:
            self.comments.append({'id': 1000 + len(self.comments), 'login': pr_bot.OWNER, 'body': argv[-1]})
        elif argv[:3] == ['gh', 'api', '--paginate'] and argv[-1].endswith('/comments'):
            out = ''.join(json.dumps(c) + '\n' for c in self.comments).encode()
        elif argv[:4] == ['gh', 'api', '-X', 'PATCH']:
            cid = int(argv[4].rsplit('/', 1)[1])
            for c in self.comments:
                if c['id'] == cid:
                    c['body'] = argv[-1].split('=', 1)[1]
        code = 1 if argv[:3] == ['gh', 'pr', 'merge'] and not self.merge_ok else 0
        return subprocess.CompletedProcess(argv, code, out, b'')

    def gh_json(self, *a):
        return {'id': 99, 'headRefOid': HEAD, 'state': 'OPEN'}

    def changed_files(self, number):
        self.calls.append(['changed_files'])
        return self.files

    def reports_present(self, tag, verdicts):
        return not getattr(self, 'reports_gone', False)

    def prepare_tree(self, base):
        pass

    def overlay(self, head, files):
        pass

    def drop_landed(self, head, files, ref=None):
        self.calls.append(['drop_landed'])
        return self.files if self.landed is None else self.landed

    def units(self, files):
        return {'reconstruction/a/B.cpp': [0x10, 0x20]}

    def leakgrep(self, base, head):
        return self.grep

    def header_sizes(self, units):
        return dict(self.sizes)

    def companions(self, units, files, functions):
        return self.extra

    def stale_accepted(self, units, files):
        return self.stale

    def removed_accepted(self, units, files, named):
        return list(self.removed)

    def review(self, number, head, base, functions, *a):
        self.calls.append(['review', sorted(functions)])
        return self.review_text

    def mac_compare(self, units, tag):
        self.calls.append(['mac', units])
        return dict(self.h2)

    def host1(self, number, head, functions, state=None, units=None):
        self.calls.append(['host1', sorted(functions), units])
        return dict(self.h1)

    def classify_debt(self, host2, *a):
        return host2

    def precheck(self, tag, files, units, functions, host1, host2, state):
        self.calls.append(['precheck', sorted(functions)])
        return {r: list(v) for r, v in self.pre.items()}

    def settle_ci_debt(self, host1):
        return host1

    def build_records(self, *a):
        self.calls.append(['build_records', a[1], sorted(a[2])])
        return Path('/nonexistent'), set(self.refused)

    def record(self, pr, state, rvas):
        self.calls.append(['record', rvas])
        state.set('recorded', True)

    def history_problem(self, base, head):
        return self.history

    def prepare_tree(self, base):
        self.calls.append(['prepare_tree'])

    def seen(self, *prefix):
        return [c for c in self.calls if c[:len(prefix)] == list(prefix)]


ORIGIN_REVIEW = json.dumps({'leak': 'yes', 'leak_evidence': ['origin-similarity'],
                            'functions': {'0x10': {'verdict': 'approve', 'ground': 'none'},
                                          '0x20': {'verdict': 'approve', 'ground': 'none'}}})
UNIT = 'reconstruction/a/B.cpp'
FNV_HEADER = '// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/Game/Thing.cpp:12'


def origin_hit(repo='momusdigital/fnv_decomp', path='src/Game/Thing.cpp', declared=True, trivial=False, file=UNIT):
    return {'function': 'Thing::Run', 'file': file, 'line': 3, 'repo': repo, 'revision': '91e1b6e', 'licence': 'x',
            'path': path, 'upstream_line': 12, 'similarity': 0.9, 'trivial': trivial, 'declared': declared,
            'fork_of': None}


class OriginFindingTests(unittest.TestCase):
    """An origin-similarity claim is informational only for a labelled admitted sibling body."""

    def test_an_admitted_sibling_with_a_valid_label_is_a_note(self):
        self.assertEqual(pr_bot.origin_findings([origin_hit()], {UNIT: FNV_HEADER}), ([], [UNIT]))

    def test_a_fo4_private_game_folder_with_a_valid_label_is_a_note(self):
        header = '// Sibling source: fo4-private@1b765c70 src/BSMain/Thing.cpp'
        hit = origin_hit('fo4-private', 'src/BSMain/Thing.cpp')
        self.assertEqual(pr_bot.origin_findings([hit], {UNIT: header}), ([], [UNIT]))

    def test_an_unlabelled_sibling_match_blocks(self):
        self.assertEqual(pr_bot.origin_findings([origin_hit(declared=False)], {UNIT: '// nothing'})[0],
                         [(UNIT, 'unlabelled')])

    def test_a_label_citing_another_file_or_pin_blocks(self):
        for header in ('// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/Game/Other.cpp',
                       '// Sibling source: momusdigital/fnv_decomp@deadbeef src/Game/Thing.cpp'):
            self.assertEqual(pr_bot.origin_findings([origin_hit()], {UNIT: header})[0], [(UNIT, 'invalid-label')])

    def test_a_declared_mit_community_body_is_a_note(self):
        hit = dict(origin_hit('CharmedBaryon/CommonLibSSE-NG', 'src/Thing.cpp'), licence='MIT')
        self.assertEqual(pr_bot.origin_findings([hit], {UNIT: '// Adapted bodies: Thing::Run'}), ([], [UNIT]))

    def test_an_undeclared_mit_community_body_blocks(self):
        hit = dict(origin_hit('CharmedBaryon/CommonLibSSE-NG', 'src/Thing.cpp', declared=False), licence='MIT')
        self.assertEqual(pr_bot.origin_findings([hit], {UNIT: FNV_HEADER})[0], [(UNIT, 'unpermitted-source')])

    def test_an_unpermitted_origin_blocks_even_when_declared(self):
        hit = origin_hit('CharmedBaryon/CommonLibSSE-NG', 'src/Thing.cpp')
        self.assertEqual(pr_bot.origin_findings([hit], {UNIT: FNV_HEADER})[0], [(UNIT, 'unpermitted-source')])

    def test_excluded_fo4_private_folders_block(self):
        header = '// Sibling source: fo4-private@1b765c70 src/Havok/Thing.cpp'
        hit = origin_hit('fo4-private', 'src/Havok/Thing.cpp')
        self.assertEqual(pr_bot.origin_findings([hit], {UNIT: header})[0], [(UNIT, 'excluded-source')])

    def test_a_claim_the_origin_check_cannot_confirm_blocks(self):
        for hits, unverified in (([], False), ([origin_hit()], True), ([origin_hit(trivial=True)], True)):
            problems, _ = pr_bot.origin_findings(hits, {UNIT: FNV_HEADER}, unverified)
            self.assertIn(('(origin check)', 'unconfirmed'), problems)

    def test_a_claim_resting_only_on_trivial_or_fork_hits_is_not_a_finding(self):
        fork = dict(origin_hit('CharmedBaryon/CommonLibSSE-NG', 'src/Thing.cpp'), fork_of='x')
        self.assertEqual(pr_bot.origin_findings([origin_hit(trivial=True), fork], {UNIT: FNV_HEADER}), ([], []))


class OriginBot(FakeBot):
    def __init__(self, work, hits, header=FNV_HEADER, **kw):
        super().__init__(work, review=ORIGIN_REVIEW, **kw)
        self.hits, self.header = hits, header

    def origin_hits(self, units):
        return self.hits, {UNIT: self.header}, False


class OriginProcessTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def test_a_labelled_sibling_body_merges_with_a_note_and_no_leak(self):
        bot = OriginBot(self.work, [origin_hit()])
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched'})
        self.assertEqual(out['origin_note'], [UNIT])
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])
        text = pr_bot.comment_body(HEAD, dict(blocked=None, merge=True, verdicts={0x10: 'fail:host2'},
                                               origin_permitted=[UNIT]))
        self.assertIn('Note, not a block', text)

    def test_an_unlabelled_match_blocks_and_the_comment_names_the_file_and_reason(self):
        bot = OriginBot(self.work, [origin_hit(declared=False)])
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('leak', False))
        body = bot.comments[0]['body']
        self.assertIn(f'- {UNIT}: unlabelled', body)
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])

    def test_an_unpermitted_origin_blocks(self):
        bot = OriginBot(self.work, [origin_hit('powerof3/CommonLibSSE', 'src/T.cpp')])
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('leak', False))
        self.assertIn(f'- {UNIT}: unpermitted-source', bot.comments[0]['body'])

    def test_other_evidence_alongside_origin_similarity_still_blocks(self):
        review = json.dumps({'leak': 'yes', 'leak_evidence': ['origin-similarity', 'copied-text'],
                             'functions': {'0x10': {'verdict': 'approve'}, '0x20': {'verdict': 'approve'}}})
        bot = OriginBot(self.work, [origin_hit()])
        bot.review_text = review
        self.assertEqual(bot.process(PR)['blocked'], 'leak')



class ProcessTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def test_all_pass_merges_once_records_and_survives_a_rerun(self):
        bot = FakeBot(self.work)
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched'})
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)
        self.assertEqual(len(bot.seen('record')), 1)
        before = len(bot.calls)
        bot.process(PR)
        self.assertEqual(len(bot.calls), before)

    def test_rerun_after_a_crash_resumes_without_repeating_paid_work(self):
        bot = FakeBot(self.work)
        original = bot.host1
        def boom(*a):
            raise pr_bot.Stop('hash check has not finished')
        bot.host1 = boom
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        bot.host1 = original
        bot.process(PR)
        self.assertEqual((len(bot.seen('review')), len(bot.seen('mac'))), (1, 1))
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)

    def test_a_conflicting_pr_is_told_once_per_head_and_costs_no_review_or_compare(self):
        bot = FakeBot(self.work)
        pr = dict(PR, mergeable='CONFLICTING')
        out = bot.process(pr)
        self.assertEqual((out['blocked'], out['merge']), ('conflict', False))
        bot.process(pr)
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        self.assertIn('merge main into your branch', bot.seen('gh', 'pr', 'comment')[0][-1])
        for stage in ('review', 'mac', 'host1', 'changed_files'):
            self.assertEqual(bot.seen(stage), [])
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        warmed = len(bot.calls)
        bot.warm(pr)
        self.assertEqual(len(bot.calls), warmed)

    def test_a_cached_mac_verdict_whose_reports_are_not_in_this_slot_is_compared_again(self):
        bot = FakeBot(self.work)
        state = pr_bot.State(self.work / 'state', 7, HEAD)
        state.set('host2', {'16': 'pass', '32': 'pass'})
        bot.reports_gone = True
        bot.process(PR)
        self.assertEqual(len(bot.seen('mac')), 1)

    def test_reports_present_needs_a_report_for_every_cached_function(self):
        bot = pr_bot.Bot(self.work, work=self.work / 'w')
        report = bot.tree / '.local/tasks/prbot-7-aaaaaaaa-0/attempts/001/0x10/report.json'
        report.parent.mkdir(parents=True)
        report.write_text('{}')
        self.assertTrue(bot.reports_present('7-aaaaaaaa', {'16': 'pass'}))
        self.assertFalse(bot.reports_present('7-aaaaaaaa', {'16': 'pass', '32': 'pass'}))

    def test_a_new_head_after_a_conflict_is_processed_normally(self):
        bot = FakeBot(self.work)
        bot.process(dict(PR, mergeable='CONFLICTING'))
        out = bot.process(dict(PR, headRefOid='b' * 40, mergeable='MERGEABLE'))
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched'})
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)

    def test_a_merge_refusal_for_a_conflict_comments_once_and_does_not_redo_the_pipeline(self):
        bot = FakeBot(self.work)
        bot.merge_ok = False
        bot.gh_json = lambda *a: {'id': 99, 'headRefOid': HEAD, 'state': 'OPEN', 'mergeable': 'CONFLICTING'}
        bot.process(PR)
        bot.process(PR)
        self.assertEqual((len(bot.seen('review')), len(bot.seen('mac')), len(bot.seen('gh', 'pr', 'merge'))), (1, 1, 1))
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)

    def test_a_merge_refusal_with_the_head_unchanged_keeps_the_cached_results_and_retries_only_the_merge(self):
        bot = FakeBot(self.work)
        bot.merge_ok = False
        bot.gh_json = lambda *a: {'id': 99, 'headRefOid': HEAD, 'state': 'OPEN', 'mergeable': 'UNKNOWN'}
        for _ in range(2):
            with self.assertRaises(pr_bot.Stop):
                bot.process(PR)
        self.assertEqual((len(bot.seen('review')), len(bot.seen('mac')), len(bot.seen('host1'))), (1, 1, 1))
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 2)
        bot.merge_ok = True
        bot.process(PR)
        self.assertEqual((len(bot.seen('review')), len(bot.seen('mac'))), (1, 1))

    def test_a_merge_refusal_because_the_head_moved_is_not_reported_as_a_conflict(self):
        bot = FakeBot(self.work)
        bot.merge_ok = False
        bot.gh_json = lambda *a: {'id': 99, 'headRefOid': 'c' * 40, 'state': 'OPEN', 'mergeable': 'MERGEABLE'}
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])

    def test_only_what_both_hosts_passed_is_reviewed_and_nothing_else_costs_a_call(self):
        bot = FakeBot(self.work, h2={0x10: 'pass', 0x20: 'fail'})
        out = bot.process(PR)
        self.assertEqual(bot.seen('review'), [['review', [0x10]]])
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'fail:host2'})
        other = FakeBot(self.work / 'n', h1={0x10: 'fail', 0x20: 'fail'})
        other.process(PR)
        self.assertEqual((other.seen('review'), other.seen('gh', 'pr', 'merge')), ([], []))

    def test_a_regression_of_a_function_outside_the_pr_blocks_it(self):
        bot = FakeBot(self.work, h1={0x10: 'pass', 0x20: 'pass', 0x99: 'regressed'})
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'regression')
        self.assertEqual((bot.seen('review'), bot.seen('gh', 'pr', 'merge')), ([], []))

    def test_scope_rejection_never_compiles_reviews_or_merges(self):
        bot = FakeBot(self.work, files=[{'filename': 'reconstruction/a/B.cpp', 'status': 'added'},
                                        {'filename': '.github/workflows/pr-check.yml', 'status': 'modified'}])
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'scope')
        self.assertEqual((bot.seen('review'), bot.seen('mac'), bot.seen('gh', 'pr', 'merge')), ([], [], []))
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)

    def test_a_pr_with_no_reconstruction_file_is_tooling_labelled_and_never_merged(self):
        files = [{'filename': 'tools/ghidra/x.py', 'status': 'added'},
                 {'filename': 'tests/test_x.py', 'status': 'added'}]
        self.assertTrue(pr_bot.tooling_lane(files))
        self.assertFalse(pr_bot.tooling_lane([]))
        self.assertFalse(pr_bot.tooling_lane(files + [{'filename': 'reconstruction/a/B.cpp'}]))
        bot = FakeBot(self.work, files=files)
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'tooling')
        self.assertEqual((bot.seen('review'), bot.seen('mac'), bot.seen('gh', 'pr', 'merge')), ([], [], []))
        self.assertEqual(len(bot.seen('gh', 'pr', 'edit')), 1)
        self.assertIn('--add-label', bot.seen('gh', 'pr', 'edit')[0])
        comment = bot.seen('gh', 'pr', 'comment')
        self.assertEqual(len(comment), 1)
        self.assertIn('tooling PR', comment[0][-1])
        self.assertNotIn('outside reconstruction', comment[0][-1])

    def test_a_mixed_pr_keeps_the_scope_block_with_a_clear_message(self):
        bot = FakeBot(self.work, files=[{'filename': 'reconstruction/a/B.cpp', 'status': 'added'},
                                        {'filename': 'tools/x.py', 'status': 'added'}])
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'scope')
        self.assertEqual(bot.seen('gh', 'pr', 'edit'), [])
        self.assertIn('separate PR', bot.seen('gh', 'pr', 'comment')[0][-1])

    def test_a_pr_with_no_changed_files_is_marked_landed_not_called_out_of_scope(self):
        bot = FakeBot(self.work, files=[])
        bot.landed = []
        out = bot.process(PR)
        self.assertIsNone(out['blocked'])
        self.assertEqual((bot.seen('review'), bot.seen('mac'), bot.seen('gh', 'pr', 'merge')), ([], [], []))
        comment = bot.seen('gh', 'pr', 'comment')
        self.assertEqual(len(comment), 1)
        self.assertNotIn('outside reconstruction', comment[0][-1])

    def test_grep_hit_blocks_before_any_model_or_host_call(self):
        bot = FakeBot(self.work, grep=(True, ['LG01']))
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'leak')
        self.assertEqual((bot.seen('review'), bot.seen('mac'), bot.seen('gh', 'pr', 'merge')), ([], [], []))
        self.assertIn('LG01', bot.seen('gh', 'pr', 'comment')[0][-1])

    def test_debt_function_does_not_block_the_others(self):
        bot = FakeBot(self.work, h1={0x10: 'pass', 0x20: 'preexisting-fail'}, h2={0x10: 'pass', 0x20: 'fail'})
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'debt'})
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])

    def test_partial_pass_merges_and_comments_only_on_the_failure(self):
        bot = FakeBot(self.work, h2={0x10: 'pass', 0x20: 'fail'})
        bot.process(PR)
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)
        body = bot.seen('gh', 'pr', 'comment')[0][-1]
        self.assertIn('0x20', body)
        self.assertNotIn('0x10:', body)

    def test_nothing_passing_does_not_merge(self):
        bot = FakeBot(self.work, review=json.dumps({'leak': 'no', 'functions': {}}))
        bot.process(PR)
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])

    def test_dry_run_has_no_side_effects(self):
        bot = FakeBot(self.work, dry_run=True)
        out = bot.process(PR)
        self.assertTrue(out['merge'])
        self.assertEqual((bot.seen('gh', 'pr', 'merge'), bot.seen('gh', 'pr', 'comment'), bot.seen('record')), ([], [], []))

    def test_stacked_pr_whose_content_already_landed_is_marked_merged_with_a_tree_neutral_merge(self):
        bot = FakeBot(self.work)
        bot.landed = []
        out = bot.process(PR)
        self.assertFalse(out['merge'])
        self.assertEqual((bot.seen('mac'), bot.seen('review'), bot.seen('gh', 'pr', 'merge')), ([], [], []))
        merge = bot.seen('git', 'merge', '-s', 'ours', '--no-ff')
        self.assertEqual(len(merge), 1)
        self.assertEqual(merge[0][-1], HEAD)
        self.assertIn('Co-authored-by: alice <99+alice@users.noreply.github.com>', merge[0][-2])
        self.assertEqual(len(bot.seen('git', 'push', '--quiet', 'origin', 'HEAD:main')), 1)
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        self.assertEqual(bot.seen('record'), [])
        before = len(bot.calls)
        bot.process(PR)
        self.assertEqual(len(bot.calls), before)

    def test_landed_pr_with_unmergeable_history_stays_open_and_nothing_is_pushed(self):
        bot = FakeBot(self.work)
        bot.landed = []
        bot.history = 'leak'
        bot.process(PR)
        self.assertEqual((bot.seen('git', 'merge'), bot.seen('git', 'push')), ([], []))
        self.assertIn('stays open', bot.seen('gh', 'pr', 'comment')[0][-1])

    def test_landed_pr_whose_head_moved_starts_over(self):
        bot = FakeBot(self.work)
        bot.landed = []
        bot.gh_json = lambda *a: {'id': 99, 'headRefOid': 'c' * 40, 'state': 'OPEN'}
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        self.assertEqual(bot.seen('git', 'merge'), [])

    def test_the_bot_never_closes_a_contributor_pr(self):
        source = (ROOT / 'tools/pr_bot.py').read_text()
        self.assertNotRegex(source, r"""['"]close['"]|pr close""")
        scenarios = [dict(), dict(h2={0x10: 'fail', 0x20: 'fail'}), dict(grep=(True, ['asm-mnemonic'])),
                     dict(files=[{'filename': 'tools/x.py', 'status': 'modified'}]),
                     dict(review=json.dumps({'leak': 'yes', 'functions': {}})), dict(landed=[]), dict(history='leak')]
        for index, scenario in enumerate(scenarios):
            with self.subTest(index=index):
                scenario = dict(scenario)
                landed, history = scenario.pop('landed', None), scenario.pop('history', None)
                bot = FakeBot(self.work / str(index), **scenario)
                bot.landed, bot.history = landed, history
                bot.process(PR)
                self.assertFalse([c for c in bot.calls if 'close' in c], bot.calls)

    def test_a_record_the_validator_refuses_keeps_that_function_drafted(self):
        bot = FakeBot(self.work)
        bot.refused = {0x20}
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'fail:record'})
        self.assertEqual(len(bot.seen('gh', 'pr', 'merge')), 1)
        self.assertEqual(bot.seen('record')[0][1], [0x10])
        self.assertIn('0x20', bot.seen('gh', 'pr', 'comment')[0][-1])

    def test_no_function_recorded_means_no_merge(self):
        bot = FakeBot(self.work)
        bot.refused = {0x10, 0x20}
        out = bot.process(PR)
        self.assertFalse(out['merge'])
        self.assertEqual((bot.seen('gh', 'pr', 'merge'), bot.seen('record')), ([], []))

    def test_refused_merge_starts_over(self):
        bot = FakeBot(self.work)
        bot.merge_ok = False
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        self.assertEqual(bot.seen('record'), [])
        bot.merge_ok = True
        bot.process(PR)
        self.assertEqual(len(bot.seen('record')), 1)


WITH_COMPANION = json.dumps({'leak': 'no', 'functions': {
    f'0x{r:x}': {'verdict': 'approve', 'ground': 'none'} for r in (0x10, 0x20, 0x30)}})


class CompanionProcessTests(unittest.TestCase):
    """Accepted functions of a changed unit that the PR does not name are confirmed with it or block it."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def bot(self, **kw):
        kw.setdefault('review', WITH_COMPANION)
        kw.setdefault('h1', {0x10: 'pass', 0x20: 'pass', 0x30: 'pass'})
        kw.setdefault('h2', {0x10: 'pass', 0x20: 'pass', 0x30: 'pass'})
        bot = FakeBot(self.work, **kw)
        bot.extra = {'reconstruction/a/B.cpp': [0x30]}
        return bot

    def test_decide_blocks_on_a_companion_that_is_not_matched_and_ignores_it_for_the_merge_floor(self):
        ok = {0x10: 'pass', 0x30: 'pass'}
        done = pr_bot.decide([0x10, 0x30], ok, ok, {0x10: 'approve', 0x30: 'approve'}, companions=[0x30])
        self.assertEqual((done['blocked'], done['merge'], done['companions']), (None, True, [0x30]))
        only = pr_bot.decide([0x10, 0x30], {0x10: 'fail', 0x30: 'pass'}, ok, {0x10: 'approve', 0x30: 'approve'},
                             companions=[0x30])
        self.assertEqual((only['blocked'], only['merge']), (None, False))
        for review in ('reject', None):
            bad = pr_bot.decide([0x10, 0x30], ok, ok, {0x10: 'approve', 0x30: review}, companions=[0x30])
            self.assertEqual((bad['blocked'], bad['merge']), ('companion', False))
        debt = pr_bot.decide([0x10, 0x30], ok, {0x10: 'pass', 0x30: 'preexisting-fail'},
                             {0x10: 'approve', 0x30: 'approve'}, companions=[0x30])
        self.assertEqual((debt['blocked'], debt['merge']), ('companion', False))

    def test_decide_blocks_a_named_stale_function_that_is_not_matched_even_as_debt(self):
        h1 = {0x10: 'pass', 0x20: 'pass'}
        for h2_20 in ('fail', 'preexisting-fail'):
            out = pr_bot.decide([0x10, 0x20], h1, {0x10: 'pass', 0x20: h2_20},
                                {0x10: 'approve', 0x20: 'approve'}, stale=[0x20])
            self.assertEqual((out['blocked'], out['merge'], out['stale']), ('stale', False, [0x20]))
        ok = pr_bot.decide([0x10, 0x20], h1, {0x10: 'pass', 0x20: 'pass'},
                           {0x10: 'approve', 0x20: 'approve'}, stale=[0x20])
        self.assertEqual((ok['blocked'], ok['merge']), (None, True))
        unnamed = pr_bot.decide([0x10], {0x10: 'pass'}, {0x10: 'pass'}, {0x10: 'approve'}, stale=[0x20])
        self.assertEqual((unnamed['blocked'], unnamed['merge']), (None, True))

    def test_a_named_stale_function_that_fails_blocks_the_merge_with_a_comment_naming_it(self):
        bot = FakeBot(self.work, h2={0x10: 'pass', 0x20: 'preexisting-fail'})
        bot.stale = [0x20]
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('stale', False))
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        body = bot.seen('gh', 'pr', 'comment')[0][-1]
        self.assertIn('0x20', body)
        self.assertNotIn('0x10', body)
        self.assertIn('go stale', body)

    def test_a_stale_block_also_lists_host_failures_and_removed_accepted_functions(self):
        bot = FakeBot(self.work, h1={0x10: 'pass', 0x20: 'pass'}, h2={0x10: 'fail', 0x20: 'pass'})
        bot.stale = [0x20]
        bot.removed = [0x2e6a70, 0x2f6280]
        bot.review_text = json.dumps({'leak': 'no', 'functions': {'0x20': {'verdict': 'reject', 'ground': 'provenance'}}})
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'stale')
        body = bot.seen('gh', 'pr', 'comment')[0][-1]
        self.assertIn('0x20: the review did not approve it', body)
        self.assertIn('Also failing in this PR:', body)
        self.assertIn('- 0x10: host 2 (compiled and compared locally): bytes differ', body)
        self.assertIn('0x2e6a70, 0x2f6280', body)
        self.assertEqual(body.count('<!-- pr-bot'), 1)

    def test_comment_categories_are_fixed_words_never_comparator_text(self):
        self.assertEqual(pr_bot.host_category(None), 'missing')
        self.assertEqual(pr_bot.host_category('no-target'), 'unbound')
        self.assertEqual(pr_bot.host_category('symbol-unbound at /Users/x/y'), 'unbound')
        self.assertEqual(pr_bot.host_category('mismatch'), 'bytes differ')
        d = dict(pr_bot.decide([0x10], {0x10: 'fail'}, {0x10: 'fail'}, {0x10: 'approve'}),
                 host_why={'16': {'host1': 'missing', 'host2': 'unbound'}})
        self.assertIn('0x10: did not byte-match on the CI hash check (missing)', pr_bot.comment_body(HEAD, d))
        d['verdicts'] = {0x10: 'fail:host1'}
        self.assertIn('host 1 (CI hash check): missing; host 2 (compiled and compared locally): unbound',
                      '\n'.join(pr_bot.other_failure_lines(d, set())))

    def test_removed_accepted_functions_are_named_when_nothing_else_blocks(self):
        d = dict(pr_bot.decide([0x10], {0x10: 'pass'}, {0x10: 'pass'}, {0x10: 'approve'}), removed=[0x2e6a70])
        body = pr_bot.comment_body(HEAD, d)
        self.assertIn('Merged and recorded: 0x10.', body)
        self.assertIn('0x2e6a70', body)

    def test_companions_are_confirmed_on_both_hosts_reviewed_recorded_and_credited_apart(self):
        bot = self.bot()
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched', '0x30': 'matched'})
        self.assertEqual(bot.seen('mac')[0][1], {'reconstruction/a/B.cpp': [0x10, 0x20, 0x30]})
        self.assertEqual(bot.seen('host1')[0][1], [0x10, 0x20, 0x30])
        self.assertEqual(bot.seen('review'), [['review', [0x10, 0x20, 0x30]]])
        self.assertEqual(bot.seen('build_records')[0][2], [0x10, 0x20, 0x30])
        self.assertEqual(bot.seen('record'), [['record', [0x10, 0x20, 0x30]]])
        merge = bot.seen('gh', 'pr', 'merge')[0]
        subject = merge[merge.index('--subject') + 1]
        self.assertIn('Reconstruct 2 functions (0x10, 0x20)', subject)
        self.assertIn('0x30', merge[merge.index('--body') + 1])
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])

    def test_a_companion_that_stops_matching_blocks_the_merge_with_a_comment_naming_it(self):
        bot = self.bot(h2={0x10: 'pass', 0x20: 'pass', 0x30: 'fail'})
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('companion', False))
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        self.assertEqual(bot.seen('record'), [])
        body = bot.seen('gh', 'pr', 'comment')[0][-1]
        self.assertIn('0x30', body)
        self.assertNotIn('0x10', body)
        self.assertIn('did not byte-match', body)

    def test_a_companion_the_reviewer_rejects_blocks_the_merge(self):
        no = json.loads(WITH_COMPANION)
        no['functions']['0x30']['verdict'] = 'reject'
        bot = self.bot(review=json.dumps(no))
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['verdicts']['0x30']), ('companion', 'fail:review'))
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])

    def test_a_companion_without_a_ci_row_is_a_failure_not_a_pass(self):
        bot = self.bot(h1={0x10: 'pass', 0x20: 'pass'})
        out = bot.process(PR)
        self.assertEqual(out['blocked'], 'companion')
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])

    def test_a_companion_whose_record_cannot_be_built_blocks_before_the_merge(self):
        bot = self.bot()
        bot.refused = {0x30}
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('companion', False))
        self.assertEqual(bot.seen('gh', 'pr', 'merge'), [])
        self.assertEqual(bot.seen('record'), [])

    def test_a_pr_with_no_companions_is_unchanged(self):
        bot = FakeBot(self.work)
        out = bot.process(PR)
        self.assertEqual(out['verdicts'], {'0x10': 'matched', '0x20': 'matched'})
        self.assertEqual(bot.seen('record'), [['record', [0x10, 0x20]]])

    def test_results_cached_without_companions_are_not_reused_for_a_set_that_has_them(self):
        bot = self.bot()
        state = pr_bot.State(self.work / 'state', 7, HEAD)
        state.set('host2', {'16': 'pass', '32': 'pass'})
        state.set('host1', {'16': 'pass', '32': 'pass'})
        state.set('review_text', GOOD)
        out = bot.process(PR)
        self.assertEqual(out['verdicts']['0x30'], 'matched')
        self.assertEqual(len(bot.seen('mac')), 1)


class CompanionDiscoveryTests(unittest.TestCase):
    """Bot.companions reads the inventory and records to find accepted functions a PR makes stale."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.tree = Path(self.tmp.name)
        self.write('builds/target.json', json.dumps({'build_id': 'b'}))
        self.write('reconstruction/a/B.cpp', '#include "B.h"\nint f() { return 1; }\n')
        self.write('reconstruction/a/B.h', '// RVA 0x10\nint f();\n')
        self.write('reconstruction/c/D.cpp', '#include "../a/B.h"\nint g() { return 2; }\n')
        self.write('reconstruction/e/F.cpp', 'int h() { return 3; }\n')
        self.fns = []
        bot = pr_bot.Bot(root=ROOT, work=self.tree / '.w')
        bot.tree = self.tree
        self.bot = bot

    def write(self, name, text):
        (self.tree / name).parent.mkdir(parents=True, exist_ok=True)
        (self.tree / name).write_text(text)

    def accept(self, rva, unit, status='matched', digest=None):
        from source_digest import include_closure
        from digest_v2 import tu_digest
        closure = include_closure(self.tree, unit)
        report = f'reports/b/0x{rva:x}.json'
        self.write(report, json.dumps({'source': {'compiled': unit, 'translation_unit': closure,
                                                  'digest': digest or tu_digest(self.tree, closure)}}))
        self.fns.append({'build_id': 'b', 'rva': rva, 'status': status, 'report': report})
        self.write('data/progress.json', json.dumps({'functions': self.fns}))

    def find(self, changed, units, named=(0x10,)):
        files = [{'filename': n, 'status': 'modified'} for n in changed]
        return self.bot.companions(units, files, named)

    def test_an_accepted_function_of_a_changed_unit_with_a_stale_digest_is_a_companion(self):
        self.accept(0x10, 'reconstruction/a/B.cpp')
        self.accept(0x11, 'reconstruction/a/B.cpp', digest='0' * 64)
        self.assertEqual(self.find(['reconstruction/a/B.h'], {'reconstruction/a/B.cpp': [0x10]}),
                         {'reconstruction/a/B.cpp': [0x11]})

    def test_a_function_the_pr_names_or_that_is_not_matched_or_whose_digest_is_current_is_not(self):
        self.accept(0x10, 'reconstruction/a/B.cpp', digest='0' * 64)
        self.accept(0x12, 'reconstruction/a/B.cpp', status='drafted', digest='0' * 64)
        self.accept(0x13, 'reconstruction/a/B.cpp')
        self.assertEqual(self.find(['reconstruction/a/B.h'], {'reconstruction/a/B.cpp': [0x10]}), {})

    def test_a_unit_that_only_includes_the_changed_header_is_found_through_its_record(self):
        self.accept(0x20, 'reconstruction/c/D.cpp', digest='0' * 64)
        self.assertEqual(self.find(['reconstruction/a/B.h'], {'reconstruction/a/B.cpp': [0x10]}),
                         {'reconstruction/c/D.cpp': [0x20]})

    def test_an_unrelated_unit_is_left_alone(self):
        self.accept(0x30, 'reconstruction/e/F.cpp', digest='0' * 64)
        self.assertEqual(self.find(['reconstruction/a/B.h'], {'reconstruction/a/B.cpp': [0x10]}), {})


class RecordStaleTests(unittest.TestCase):
    """A function matched by an earlier PR is recorded again when this PR's unit text outdated its record."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        tree = Path(self.tmp.name) / 'tree'
        (tree / 'builds').mkdir(parents=True)
        (tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
        (tree / 'data').mkdir()
        (tree / 'data/progress.json').write_text(json.dumps({'functions': [
            {'build_id': 'b', 'rva': r, 'status': 'matched'} for r in (0x10, 0x20, 0x30)]}))
        (tree / 'reports/b').mkdir(parents=True)
        for rva, task in ((0x10, 'pr-bot-7-aaaaaaaa'), (0x20, 'pr-bot-3-bbbbbbbb')):
            (tree / f'reports/b/0x{rva:x}.review.json').write_text(json.dumps({'review_task_id': task}))
        self.argv = []
        bot = pr_bot.Bot(root=ROOT, work=Path(self.tmp.name))
        bot.tree, bot.run = tree, self.fake_run
        self.bot = bot
        self.state = pr_bot.State(Path(self.tmp.name) / 's', 7, 'a' * 40)
        self.state.set('records', {})

    def fake_run(self, argv, **kw):
        argv = [str(a) for a in argv]
        if argv[1].endswith('record.py'):
            self.argv = argv
        return subprocess.CompletedProcess(argv, 0, b'', b'')

    def test_only_this_prs_own_finished_record_is_skipped(self):
        pr = {'number': 7, 'headRefOid': 'a' * 40, 'author': {'login': 'x'}}
        self.bot.record(pr, self.state, [0x10, 0x20, 0x30, 0x40])
        offered = [self.argv[i + 1] for i, a in enumerate(self.argv) if a == '--rva']
        self.assertEqual(offered, ['0x20', '0x30', '0x40'])


class LeakgrepContractTests(unittest.TestCase):
    OUTPUT = ('reconstruction/a/B.cpp:3 asm-mnemonic\nreconstruction/a/B.h:10 include-outside-roots\n'
              'reconstruction/a/B.h:11 asm-mnemonic\nleakgrep: 3 hit(s)\n')

    def test_codes_are_the_rule_names_not_the_file_positions_or_the_summary(self):
        self.assertEqual(pr_bot.parse_leak_codes(self.OUTPUT), ['asm-mnemonic', 'include-outside-roots', 'asm-mnemonic'])
        self.assertEqual(pr_bot.parse_leak_codes('leakgrep: 0 hit(s)\n'), [])
        self.assertEqual(pr_bot.parse_leak_codes('<file 1>:4 private-path\n'), ['private-path'])

    def test_exit_code_one_is_a_hit_and_two_is_an_infrastructure_failure(self):
        bot = pr_bot.Bot(root=ROOT)
        bot.tools = Path(tempfile.mkdtemp())
        (bot.tools / 'leakgrep.py').write_text('')
        for code, out, expect in ((1, self.OUTPUT, (True, ['asm-mnemonic', 'include-outside-roots', 'asm-mnemonic'])),
                                  (0, 'leakgrep: 0 hit(s)\n', (False, []))):
            bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, code, out.encode(), b'')
            self.assertEqual(bot.leakgrep(BASE, HEAD), expect)
        bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, 2, b'', b'')
        with self.assertRaises(pr_bot.Stop):
            bot.leakgrep(BASE, HEAD)

    def test_a_crash_that_exits_one_without_the_summary_is_not_a_leak(self):
        bot = pr_bot.Bot(root=ROOT)
        bot.tools = Path(tempfile.mkdtemp())
        (bot.tools / 'leakgrep.py').write_text('')
        bot.run = lambda argv, **kw: subprocess.CompletedProcess(argv, 1, b'', b'Traceback')
        with self.assertRaises(pr_bot.Stop):
            bot.leakgrep(BASE, HEAD)

    def test_live_mode_fails_closed_without_leakgrep_and_replay_does_not(self):
        bot = pr_bot.Bot(root=Path(tempfile.mkdtemp()))
        bot.tools = Path(tempfile.mkdtemp())
        with self.assertRaises(pr_bot.Stop):
            bot.leakgrep(BASE, HEAD)
        bot.dry_run = True
        self.assertEqual(bot.leakgrep(BASE, HEAD), (False, []))

    def test_live_run_refuses_to_assume_the_ci_host(self):
        with contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit):
            pr_bot.main(['pr', '1', '--host1', 'assume-pass'])


class HashMapTests(unittest.TestCase):
    def test_unit_keys_are_not_functions(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'hash-result.json'
            path.write_text(json.dumps({'0x10': 'pass', '0X20': 'regressed', 'reconstruction/a/New.cpp': 'unverified'}))
            self.assertEqual(pr_bot.results_from_report(path), {0x10: 'pass', 0x20: 'regressed'})

    def test_rows_keep_only_the_function_in_the_unit_it_was_found_in(self):
        report = {'functions': [{'rva': '0x10', 'unit': 'reconstruction/a/B.cpp'},
                                {'rva': '0x10', 'unit': 'reconstruction/other/C.cpp'},
                                {'rva': None, 'unit': 'reconstruction/a/New.cpp'}]}
        rows = pr_bot.ci_rows(report, {0x10: 'reconstruction/a/B.cpp'})
        self.assertEqual({r: row['unit'] for r, row in rows.items()}, {0x10: 'reconstruction/a/B.cpp'})


class Host1Tests(unittest.TestCase):
    """The live host-1 path against a stubbed GitHub."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)
        self.job = {'name': 'hash', 'head_sha': HEAD, 'status': 'completed', 'conclusion': 'success',
                    'details_url': 'https://github.com/o/r/actions/runs/555/job/9'}
        self.meta = {'id': 555, 'head_sha': HEAD, 'run_attempt': 1, 'event': 'pull_request'}
        self.files = {'hash-result.json': {'0x10': 'pass', '0x20': 'fail'},
                      'target-result.json': {'head_sha': HEAD, 'base_sha': BASE, 'toolset': 'MATCH',
                                             'compiler_pins_sha256': 'e' * 64, 'functions': [
                                                 {'rva': '0x10', 'unit': 'reconstruction/a/B.cpp', 'status': 'pass'}]}}
        self.artifacts = []
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        bot.run = self.fake_run
        bot.gh_json = self.gh
        bot.config['hash_wait'] = 0
        bot.config['download_retry_wait'] = 0
        self.bot = bot

    def gh(self, *args):
        if '/check-runs' in args[1]:
            return {'check_runs': self.jobs if hasattr(self, 'jobs') else [self.job]}
        if '/artifacts' in args[1]:
            return {'artifacts': self.artifacts}
        return self.meta

    def fake_run(self, argv, **kw):
        argv = [str(a) for a in argv]
        if argv[:3] == ['gh', 'run', 'download']:
            target = Path(argv[argv.index('-D') + 1])
            for name, value in self.files.items():
                (target / name).write_text(json.dumps(value))
        return subprocess.CompletedProcess(argv, 0, b'', b'')

    def host1(self):
        state = pr_bot.State(self.work / 's', 7, HEAD)
        got = self.bot.host1(7, HEAD, [0x10, 0x20], state, {'reconstruction/a/B.cpp': [0x10, 0x20]})
        return got, state

    def test_statuses_and_the_run_facts_for_the_record(self):
        got, state = self.host1()
        self.assertEqual(got, {0x10: 'pass', 0x20: 'fail'})
        ci = state.get('ci')
        self.assertEqual((ci['run']['run_id'], ci['run']['head_sha'], ci['run']['conclusion']), (555, HEAD, 'success'))
        self.assertEqual(ci['map'], {'16': 'pass', '32': 'fail'})
        self.assertEqual(set(ci['rows']), {'16'})
        self.assertEqual(ci['report']['base_sha'], BASE)

    def test_a_run_of_another_head_is_not_this_pr(self):
        self.meta['head_sha'] = 'c' * 40
        with self.assertRaises(pr_bot.Stop):
            self.host1()

    def test_a_failed_job_confirms_nothing_unless_it_reports_a_regression(self):
        self.job['conclusion'] = 'failure'
        got, _ = self.host1()
        self.assertEqual(got, {0x10: 'fail', 0x20: 'fail'})
        self.files['hash-result.json'] = {'0x10': 'regressed', '0x20': 'pass'}
        got, _ = self.host1()
        self.assertEqual(got, {0x10: 'regressed', 0x20: 'pass'})

    def test_a_head_without_a_run_gets_a_probe_branch_and_draft_pr_once(self):
        calls = []
        self.job['name'] = 'other'
        self.bot.run = lambda argv, **kw: calls.append([str(a) for a in argv]) or subprocess.CompletedProcess(argv, 0, b'', b'')
        self.bot.gh_json = lambda *a: {'check_runs': [self.job]} if '/check-runs' in a[1] else ([] if a[0] == 'pr' else {'workflow_runs': []})
        with self.assertRaises(pr_bot.Stop):
            self.host1()
        branch = [c for c in calls if c[:4] == ['gh', 'api', '-X', 'POST'] and f'sha={HEAD}' in c]
        self.assertEqual(len(branch), 1)
        self.assertIn('ref=refs/heads/probe/pr-7', branch[0])
        self.assertEqual(len([c for c in calls if c[:3] == ['gh', 'pr', 'create']]), 1)
        self.assertIn('--draft', [c for c in calls if c[:3] == ['gh', 'pr', 'create']][0])

    def test_warm_probes_only_a_head_with_no_run_and_in_scope(self):
        probed = []
        self.bot.probe_hash_run = lambda number, head: probed.append(number)
        self.bot.changed_files = lambda number: [{'filename': 'reconstruction/a/B.cpp'}]
        pr = {'number': 7, 'headRefOid': HEAD}
        self.bot.warm(pr)
        self.assertEqual(probed, [])  # the head already has a hash run
        self.job['name'] = 'other'
        self.bot.warm(pr)
        self.assertEqual(probed, [7])
        self.bot.changed_files = lambda number: [{'filename': 'tools/x.py'}]
        self.bot.warm(pr)
        self.assertEqual(probed, [7])

    def test_a_finished_run_without_a_result_triggers_one_probe_then_stops(self):
        calls = []
        self.files.pop('hash-result.json')
        self.job['id'] = 1
        base_run = self.bot.run
        self.bot.run = lambda argv, **kw: calls.append([str(a) for a in argv]) or base_run(argv, **kw)
        orig = self.bot.gh_json
        self.bot.gh_json = lambda *a: [] if a[0] == 'pr' else orig(*a)
        with self.assertRaises(pr_bot.Stop):
            self.host1()
        self.assertEqual(len([c for c in calls if c[:3] == ['gh', 'pr', 'create']]), 1)

    def test_a_missing_artifact_is_retried_not_trusted(self):
        self.files.pop('hash-result.json')
        with self.assertRaises(pr_bot.Stop):
            self.host1()

    def wait_with(self, on_sleep):
        self.bot.config['hash_wait'] = 60
        real_sleep = pr_bot.time.sleep
        pr_bot.time.sleep = on_sleep
        self.addCleanup(setattr, pr_bot.time, 'sleep', real_sleep)

    def test_a_stale_run_ahead_of_the_probe_does_not_end_the_wait(self):
        # The fork's own run (stale base, no artifact) finishes before the probe's run has appeared.
        probed = []
        self.bot.probe_hash_run = lambda number, head: probed.append(number)
        self.bot.approve_pending = lambda head: None
        self.job.update(id=1, conclusion='failure', started_at='2000-01-01T00:00:00Z')
        self.files.pop('hash-result.json')
        later = dict(self.job, id=2, conclusion='success', started_at='2999-01-01T00:00:00Z')
        stale = self.job

        def on_sleep(seconds):
            self.jobs = [stale, later]  # the probe's run shows up while the bot waits
            self.files['hash-result.json'] = {'0x10': 'pass', '0x20': 'pass'}
        self.wait_with(on_sleep)
        got, _ = self.host1()
        self.assertEqual(got, {0x10: 'pass', 0x20: 'pass'})
        self.assertEqual(probed, [7])

    def test_a_probe_run_without_a_result_is_a_real_stop(self):
        self.bot.probe_hash_run = lambda number, head: None
        self.bot.approve_pending = lambda head: None
        self.job.update(id=1, started_at='2000-01-01T00:00:00Z')
        self.files.pop('hash-result.json')
        later = dict(self.job, id=2, started_at='2999-01-01T00:00:00Z')
        stale = self.job

        def on_sleep(seconds):
            self.jobs = [stale, later]
        self.wait_with(on_sleep)
        with self.assertRaisesRegex(pr_bot.Stop, 'left no result'):
            self.host1()

    def test_a_listed_artifact_that_will_not_download_is_not_a_run_without_a_result(self):
        self.artifacts = [{'name': 'hash-result', 'expired': False}]
        self.files.pop('hash-result.json')
        probed = []
        self.bot.probe_hash_run = lambda number, head: probed.append(number)
        with self.assertRaisesRegex(pr_bot.Stop, 'did not download'):
            self.host1()
        self.assertEqual(probed, [])

    def test_check_runs_are_read_from_every_page(self):
        pages = [{'check_runs': [dict(self.job, name='tests (0)')]}, {'check_runs': [self.job]}]
        self.bot.gh_json = lambda *a: pages
        self.assertEqual(self.bot.latest_hash_run(HEAD)['name'], 'hash')


class NewFunctionRecordTests(unittest.TestCase):
    """Records for functions that have no accepted record yet: a public unit map is frozen first."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)
        self.tree = self.work / 'tree'
        self.task = self.tree / '.local/tasks/prbot-7-aaaaaaaa-0'
        self.task.mkdir(parents=True)
        self.fns = [{'rva': '0x10', 'size': 8, 'symbol': '?F@@YAXXZ'}, {'rva': '0x20', 'size': 8, 'symbol': '?G@@YAXXZ'}]
        self.set_task('symbols.json')
        (self.tree / 'data').mkdir()
        (self.tree / 'data/progress.json').write_text(json.dumps({'functions': [
            {'rva': 0x10, 'status': 'mapped'}, {'rva': 0x20, 'status': 'matched'}]}))
        self.calls, self.bind_code, self.record_ok = [], 0, {0x10: True, 0x20: True}
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        bot.tree, bot.run = self.tree, self.fake_run
        self.bot = bot
        self.state = pr_bot.State(self.work / 's', 7, HEAD)
        row = {'status': 'pass', 'symbols': ['?F@@YAXXZ']}
        self.state.set('ci', dict(run={}, report={}, rows={'16': row, '32': row}, map={'16': 'pass', '32': 'pass'}))

    def set_task(self, symbols):
        (self.task / 'task.json').write_text(json.dumps({'task_id': 'prbot-7-aaaaaaaa-0', 'build_id': 'b',
                                                        'symbols': symbols, 'functions': self.fns}))

    def fake_run(self, argv, **kw):
        argv = [str(a) for a in argv]
        self.calls.append(argv)
        code = 0
        if argv[1].endswith('bind.py'):
            self.bound_rvas = [f['rva'] for f in json.loads((self.task / 'task.json').read_text())['functions']]
            code = self.bind_code
            if not code:
                public = 'reports/b/unit-symbols/' + 'c' * 64 + '.json'
                (self.tree / public).parent.mkdir(parents=True, exist_ok=True)
                (self.tree / public).write_text('{}')
                self.set_task(public)
        if argv[1] == '-c':
            rva = json.loads((Path(argv[4]) / 'task.json').read_text())['functions'][0]['rva']
            if self.record_ok[int(rva, 0)]:
                dest = Path(argv[5]) / 'b' / f'{rva}.json'
                dest.parent.mkdir(parents=True, exist_ok=True)
                dest.write_text('{}')
            else:
                code = 1
        return subprocess.CompletedProcess(argv, code, b'', b'')

    def build(self, rvas=(0x10, 0x20)):
        return self.bot.build_records('7-aaaaaaaa/records', {}, set(rvas), self.state)

    def seen(self, name):
        return [c for c in self.calls if any(name in a for a in c[:2])]

    def test_a_private_symbol_map_is_frozen_once_before_any_confirmation(self):
        out, failed = self.build()
        self.assertEqual(failed, set())
        self.assertEqual(len(self.seen('bind.py')), 1)
        self.assertIn('--unit-maps', self.seen('bind.py')[0])
        self.assertLess(self.calls.index(self.seen('bind.py')[0]), self.calls.index(self.seen('wine_confirm.py')[0]))
        sub = json.loads((self.task / 'confirm-0x10/task.json').read_text())
        self.assertTrue(sub['symbols'].startswith('reports/b/unit-symbols/'))
        self.assertEqual(len(self.seen('wine_confirm.py')), 2)

    def test_only_the_functions_being_recorded_are_bound_so_a_debt_function_cannot_refuse_them(self):
        out, failed = self.build({0x10})
        self.assertEqual((failed, self.bound_rvas), (set(), ['0x10']))
        self.assertEqual([f['rva'] for f in json.loads((self.task / 'task.json').read_text())['functions']],
                         ['0x10', '0x20'])

    def test_an_already_public_map_is_not_rebound(self):
        public = 'reports/b/unit-symbols/' + 'd' * 64 + '.json'
        (self.tree / public).parent.mkdir(parents=True, exist_ok=True)
        (self.tree / public).write_text('{}')
        self.set_task(public)
        self.build()
        self.assertEqual(self.seen('bind.py'), [])

    def test_a_public_map_lost_with_a_rebuilt_tree_is_bound_again(self):
        self.set_task('reports/b/unit-symbols/' + 'e' * 64 + '.json')
        out, failed = self.build()
        self.assertEqual(failed, set())
        self.assertEqual(len(self.seen('bind.py')), 1)

    def test_a_failed_bind_refuses_every_function_of_the_unit_without_confirming_any(self):
        self.bind_code = 1
        out, failed = self.build()
        self.assertEqual(failed, {0x10, 0x20})
        self.assertEqual(self.seen('wine_confirm.py'), [])

    def test_a_carried_function_is_recorded_from_its_own_record_with_no_hash_row_or_confirmation(self):
        (self.tree / 'builds').mkdir()
        (self.tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
        self.state.data['carried'] = {'16': pr_bot.CARRY_REASON}
        self.state.data['ci']['rows'].pop('16')
        asked = []
        self.bot.carried_records = lambda tag, rvas, build: (asked.append((set(rvas), build)), (self.work, set()))[1]
        out, failed = self.build()
        self.assertEqual((failed, asked), (set(), [({0x10}, 'b')]))
        self.assertEqual(len(self.seen('wine_confirm.py')), 1)

    def test_a_carried_record_that_cannot_be_built_refuses_only_that_function(self):
        (self.tree / 'builds').mkdir()
        (self.tree / 'builds/target.json').write_text(json.dumps({'build_id': 'b'}))
        self.state.data['carried'] = {'16': pr_bot.CARRY_REASON}
        self.bot.carried_records = lambda tag, rvas, build: (self.work, set(rvas))
        out, failed = self.build()
        self.assertEqual(failed, {0x10})

    def test_a_record_the_validator_refuses_fails_only_that_function(self):
        self.record_ok[0x10] = False
        out, failed = self.build()
        self.assertEqual(failed, {0x10})

    def test_a_function_without_a_ci_row_is_refused_not_waited_for(self):
        self.state.data['ci']['rows'].pop('16')
        out, failed = self.build()
        self.assertEqual(failed, {0x10})

    def test_a_matched_function_with_no_task_in_the_tree_is_refused_not_skipped(self):
        out, failed = self.build({0x10, 0x20, 0x30})
        self.assertEqual(failed, {0x30})

    def test_a_stale_record_file_never_stands_in_for_a_refused_one(self):
        out, _ = self.build()
        self.record_ok[0x10] = False
        out, failed = self.build()
        self.assertEqual(failed, {0x10})

    def test_ci_preexisting_fail_is_debt_only_for_a_function_matched_at_base(self):
        got = self.bot.settle_ci_debt({0x10: 'preexisting-fail', 0x20: 'preexisting-fail', 0x30: 'pass'})
        self.assertEqual(got, {0x10: 'fail', 0x20: 'preexisting-fail', 0x30: 'pass'})


class HistoryTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.repo = Path(self.tmp.name)

    def git(self, *args):
        return subprocess.run(['git', '-C', str(self.repo), '-c', 'user.email=t@example.invalid', '-c', 'user.name=T',
                               *args], check=True, capture_output=True).stdout.decode().strip()

    def commit(self, name, text, message='unit'):
        path = self.repo / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        self.git('add', '--', name)
        self.git('commit', '-qm', message)
        return self.git('rev-parse', 'HEAD')

    def bot(self, hits=()):
        bot = pr_bot.Bot(root=self.repo, work=self.repo / '.w')
        bot.leakgrep = lambda base, head: (self.git('show', head, '--format=%s', '-s') in hits, [])
        bot.leakgrep_text = lambda text: text.strip() in hits
        return bot

    def test_clean_reconstruction_history_passes(self):
        self.git('init', '-q')
        base = self.commit('reconstruction/a.h', 'one\n')
        head = self.commit('reconstruction/b.h', 'two\n')
        self.assertIsNone(self.bot().history_problem(base, head))

    def test_a_commit_outside_reconstruction_is_refused_even_if_later_reverted(self):
        self.git('init', '-q')
        base = self.commit('reconstruction/a.h', 'one\n')
        self.commit('tools/x.py', 'x\n')
        head = self.commit('reconstruction/b.h', 'two\n')
        self.assertEqual(self.bot().history_problem(base, head), 'scope')

    def test_a_flagged_commit_or_message_in_the_middle_is_refused(self):
        self.git('init', '-q')
        base = self.commit('reconstruction/a.h', 'one\n')
        self.commit('reconstruction/b.h', 'two\n', 'dirty-diff')
        head = self.commit('reconstruction/c.h', 'three\n')
        self.assertEqual(self.bot(hits=('dirty-diff',)).history_problem(base, head), 'leak')
        self.git('commit', '-q', '--amend', '-m', 'dirty-message')
        head = self.git('rev-parse', 'HEAD')
        self.assertEqual(self.bot(hits=('dirty-message',)).history_problem(base, head), 'leak')

    def test_a_merge_commit_in_the_history_is_refused(self):
        self.git('init', '-q', '-b', 'main')
        base = self.commit('reconstruction/a.h', 'one\n')
        self.git('checkout', '-q', '-b', 'side')
        self.commit('reconstruction/s.h', 's\n')
        self.git('checkout', '-q', 'main')
        self.commit('reconstruction/m.h', 'm\n')
        self.git('merge', '-q', '--no-ff', '-m', 'merge', 'side')
        self.assertEqual(self.bot().history_problem(base, self.git('rev-parse', 'HEAD')), 'merge-commit')


class ReviewContextTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.tree = Path(self.tmp.name)
        files = {'data/progress.json': json.dumps({'functions': [
                     {'id': 'b-0x10', 'build_id': 'b', 'rva': 0x10, 'size': 8, 'status': 'mapped', 'name': 'N', 'name_origin': 'GUESS'}]}),
                 'builds/target.json': json.dumps({'build_id': 'b', 'image_sha256': 'f' * 64}),
                 'tools/verifier/pinned.sha256': 'a' * 64 + ' cl.exe\n',
                 'reconstruction/a/B.cpp': '#include "B.h"\nint f() { return 1; }\n',
                 'reconstruction/a/B.h': '// RVA 0x10\nint f();\n',
                 '.local/packs/b/0x10/listing.txt': 'private',
                 'docs/reviewer-runbook.md': (ROOT / 'docs/reviewer-runbook.md').read_text()}
        for name, text in files.items():
            (self.tree / name).parent.mkdir(parents=True, exist_ok=True)
            (self.tree / name).write_text(text)
        self.prompts = []
        self.origin_out = b'check_origin: threshold 0.75; compared with a/b@1234567\ncheck_origin: 0 hit(s), 0 non-trivial\n'
        bot = pr_bot.Bot(root=ROOT, work=self.tree / '.w')
        bot.tree = self.tree
        bot.run = self.fake_run
        self.bot = bot

    def fake_run(self, argv, **kw):
        argv = [str(a) for a in argv]
        if argv[0] == 'codex':
            self.prompts.append(kw['input'].decode())
            Path(argv[argv.index('--output-last-message') + 1]).write_text('{}')
        out = b'reconstruction/a/B.h: check provenance: missing origin\n' if 'lint_review_readiness.py' in ' '.join(argv) else b''
        if 'check_origin.py' in ' '.join(argv):
            out = self.origin_out
        return subprocess.CompletedProcess(argv, 0, out, b'')

    def evidence(self, **report):
        from source_digest import include_closure
        from digest_v2 import tu_digest
        digest = tu_digest(self.tree, include_closure(self.tree, 'reconstruction/a/B.cpp'))
        recipe = self.tree / 'reconstruction/recipes/msvc-19.16.27054-o2.json'
        recipe.parent.mkdir(parents=True, exist_ok=True)
        recipe.write_text('{}')
        body = {'result': 'pass', 'source': {'source_revision': digest, 'path': 'reconstruction/a/B.cpp'},
                'recipe': {'recipe_sha256': hashlib.sha256(b'{}').hexdigest(), 'compiler_binary_sha256': 'a' * 64},
                'target': {'image_sha256': 'f' * 64, 'expected_image_sha256': 'f' * 64}}
        body.update(report)
        path = self.tree / '.local/tasks/prbot-7-aaaaaaaa-0/attempts/001/0x10/report.json'
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(body))
        row = {'status': 'pass', 'source_sha256': digest, 'recipe_sha256': hashlib.sha256(b'{}').hexdigest()}
        return {0x10: dict(report=path, host1='pass', host2='pass', row=row, run={'run_id': 555, 'head_sha': HEAD})}

    def test_the_reviewer_sees_both_hosts_bound_to_the_source_so_item_3_can_be_judged(self):
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, self.evidence())
        prompt = self.prompts[0]
        self.assertIn('.local/tasks/prbot-7-aaaaaaaa-0/attempts/001/0x10/report.json: result pass: agree', prompt)
        self.assertNotIn('DIFFER', prompt)
        self.assertIn('second-host run 555 (CI hash job, which compares the published target hashes) on head ' + HEAD[:12] + ': pass; its source digest agrees, its recipe hash agrees', prompt)

    def test_the_sheet_names_the_digest_method_so_the_reviewer_does_not_hash_with_v1(self):
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, self.evidence())
        prompt = self.prompts[0]
        self.assertIn('digest method: tu-sha256-v2 (python3 tools/digest_v2.py', prompt)
        self.assertIn('never equal to it', prompt)

    def test_the_prompt_lists_body_origin_hits_or_says_none_were_found(self):
        units = {'reconstruction/a/B.cpp': [0x10]}
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), units, self.evidence())
        self.assertIn('## Body origin (tools/check_origin.py)\nno same-named community/sibling body found '
                      '(clone revisions: a/b@1234567)', self.prompts[0])
        self.assertIn('"unverified" alone is not a ground to reject', self.prompts[0])
        hit = {'function': 'B::f', 'repo': 'x/ng', 'revision': 'abc', 'path': 'src/B.cpp', 'upstream_line': 3,
               'similarity': 0.9, 'trivial': False, 'declared': False, 'fork_of': None}
        self.origin_out = b'check_origin: threshold 0.75; compared with x/ng@abc\n' + json.dumps(hit).encode() + b'\n'
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), units, self.evidence())
        self.assertIn('B::f ~ x/ng@abc src/B.cpp:3 similarity 0.90 (adapted; header does NOT name it', self.prompts[1])

    def test_the_sheet_marks_which_files_the_pr_changed_and_which_are_unchanged_context(self):
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, self.evidence(),
                        {'reconstruction/a/B.cpp'})
        prompt = self.prompts[0]
        self.assertIn('reconstruction/a/B.cpp (changed by this PR), reconstruction/a/B.h (unchanged from main)', prompt)
        self.assertIn('Review the files this PR changes in full', prompt)

    def declare_other_recipe(self, hint):
        other = self.tree / 'reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json'
        other.parent.mkdir(parents=True, exist_ok=True)
        other.write_text('{"x": 1}')
        head = '// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json\n' + hint
        (self.tree / 'reconstruction/a/B.cpp').write_text(head + '#include "B.h"\nint f() { return 1; }\n')
        evidence = self.evidence()
        return evidence

    def test_a_requested_rva_is_compared_with_the_default_recipe_the_ci_job_selects(self):
        evidence = self.declare_other_recipe('// CI hash: 0x10 ?f@@YAHXZ\n')
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, evidence)
        self.assertIn('its recipe hash agrees', self.prompts[0])

    def test_an_unrequested_rva_must_match_the_recipe_the_unit_names(self):
        evidence = self.declare_other_recipe('')
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, evidence)
        self.assertIn('its recipe hash DIFFERS', self.prompts[0])

    def test_a_requested_rva_with_another_recipe_hash_still_differs(self):
        evidence = self.declare_other_recipe('// CI hash: 0x10 ?f@@YAHXZ\n')
        evidence[0x10]['row']['recipe_sha256'] = hashlib.sha256(b'other').hexdigest()
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, evidence)
        self.assertIn('its recipe hash DIFFERS', self.prompts[0])

    def test_a_report_for_other_source_or_compiler_is_shown_as_differing(self):
        bad = self.evidence(source={'source_revision': '0' * 64, 'path': 'reconstruction/a/B.cpp'})
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]}, bad)
        self.assertIn('source revision equals the tu digest and unit path: DIFFER', self.prompts[0])

    def test_without_a_report_the_sheet_says_so_instead_of_inventing_one(self):
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]},
                        {0x10: dict(report=None, host1='pass', host2='pass', row=None, run=None)})
        self.assertIn('comparator report: NOT available', self.prompts[0])
        self.assertIn('second-host run (CI hash job, which compares the published target hashes): pass', self.prompts[0])

    def test_prompt_carries_the_runbook_standard_the_pins_the_packs_and_the_lint(self):
        self.bot.review(7, HEAD, BASE, [0x10], (False, []), {'reconstruction/a/B.cpp': [0x10]},
                        self.evidence())
        prompt = self.prompts[0]
        self.assertIn('## Checklist (per function)', prompt)
        self.assertIn('Names and labels (not blocking)', prompt)
        self.assertIn('target image sha256: ' + 'f' * 64, prompt)
        self.assertIn('a' * 64 + ' cl.exe', prompt)
        self.assertIn('0x10: inventory size 8, status mapped', prompt)
        self.assertIn('.local/packs/b/0x10/', prompt)
        self.assertIn('.local/analysis/fnv_index.jsonl', prompt)
        self.assertIn('check provenance: missing origin', prompt)
        self.assertIn('reconstruction/a/B.cpp, reconstruction/a/B.h', prompt)
        self.assertLess(prompt.index('Binding sheet'), prompt.index('UNTRUSTED DIFF DATA'))

    def test_the_runbook_checklist_is_read_from_the_runbook_not_copied(self):
        text = pr_bot.runbook_checklist(ROOT)
        self.assertTrue(text.startswith('## Checklist (per function)'))
        self.assertNotIn('For a change to the comparator', text)
        self.assertIn('Plausible source', text)
        self.assertIn('do not reject because the full licence text was removed', text)

    def test_the_checklist_lets_an_opaque_sized_standin_pass_only_for_size_and_destructor_use(self):
        text = pr_bot.runbook_checklist(ROOT)
        self.assertIn('opaque, correctly sized stand-in', text)
        self.assertIn('only the class size and the destructor call', text)
        self.assertIn('must not be used to fake field access', text)

    def test_a_reply_with_reasons_still_parses_and_only_approve_approves(self):
        leak, got = pr_bot.parse_review(json.dumps({'leak': 'no', 'functions': {
            '0x10': {'verdict': 'approve', 'ground': 'none', 'why': 'fine'},
            '0x20': {'verdict': 'reject', 'ground': 'binding', 'why': 'header disagrees'}}}), [0x10, 0x20, 0x30])
        self.assertEqual((leak, got), ('no', {0x10: 'approve', 0x20: 'reject', 0x30: 'reject'}))



class MappingBot(FakeBot):
    """The mapping lane with the checker, the CI check, the model and the regenerate stubbed."""
    MAP_FILES = [{'filename': 'data/progress.json', 'status': 'modified'},
                 {'filename': 'findings/new.md', 'status': 'added'}]
    APPROVE = json.dumps({'leak': 'no', 'verdict': 'approve', 'ground': 'none', 'why': 'ok', 'notes': []})

    def __init__(self, work, codes=(), ci='success', review=APPROVE, **kw):
        super().__init__(work, files=list(self.MAP_FILES), **kw)
        self.codes, self.ci, self.text = list(codes), ci, review

    def mapping_problems(self, base, head):
        self.calls.append(['mapping_problems'])
        return list(self.codes)

    def mapping_added(self, base, head):
        return [{'rva': 0x3000, 'size': 8, 'name': 'A::f', 'name_origin': 'COMMUNITY', 'evidence': 'findings/new.md',
                 'owner': 'alice', 'name_source': 'Community name'}] * 3

    def mapping_ci(self, head):
        self.calls.append(['mapping_ci'])
        if self.ci is None:
            raise pr_bot.Stop('mapping check has no run on this head yet')
        return self.ci

    def mapping_review(self, number, head, added):
        self.calls.append(['mapping_review', len(added)])
        return self.text

    def regenerate(self, number):
        self.calls.append(['regenerate', number])


class MappingLaneTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def test_lane_is_progress_plus_new_findings_and_nothing_else(self):
        ok = MappingBot.MAP_FILES
        self.assertTrue(pr_bot.mapping_lane(ok))
        self.assertTrue(pr_bot.mapping_lane(ok[:1]))
        for bad in ({'filename': 'docs/progress.svg', 'status': 'modified'},
                    {'filename': 'reconstruction/INDEX.md', 'status': 'modified'},
                    {'filename': 'reconstruction/a/B.cpp', 'status': 'added'},
                    {'filename': 'findings/old.md', 'status': 'modified'},
                    {'filename': 'findings/n.md', 'status': 'renamed', 'previous_filename': 'findings/o.md'}):
            self.assertFalse(pr_bot.mapping_lane(ok + [bad]), bad)
        self.assertFalse(pr_bot.mapping_lane(ok[1:]))
        self.assertFalse(pr_bot.mapping_lane([]))

    def test_a_valid_mapping_pr_is_reviewed_once_merged_and_regenerated_without_hosts(self):
        bot = MappingBot(self.work)
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge'], out['mapped']), (None, True, 3))
        for stage in ('mac', 'host1', 'build_records', 'record', 'drop_landed'):
            self.assertEqual(bot.seen(stage), [], stage)
        self.assertEqual(len(bot.seen('mapping_review')), 1)
        merge = bot.seen('gh', 'pr', 'merge')
        self.assertEqual(len(merge), 1)
        self.assertEqual(merge[0][merge[0].index('--match-head-commit') + 1], HEAD)
        self.assertEqual(merge[0][merge[0].index('--subject') + 1], 'Map 3 functions (#7)')
        self.assertIn('Co-authored-by: alice <99+alice@users.noreply.github.com>', merge[0][-1])
        self.assertEqual(bot.seen('regenerate'), [['regenerate', 7]])
        self.assertLess(bot.calls.index(merge[0]), bot.calls.index(['regenerate', 7]))
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])  # a clean merge posts no new comment
        before = len(bot.calls)
        bot.process(PR)
        self.assertEqual(len(bot.calls), before)

    def test_a_rule_failure_blocks_before_the_ci_check_the_review_and_the_merge(self):
        bot = MappingBot(self.work, codes=['status', 'forbidden-field'])
        out = bot.process(PR)
        self.assertEqual((out['blocked'], out['merge']), ('mapping', False))
        for stage in ('mapping_ci', 'mapping_review'):
            self.assertEqual(bot.seen(stage), [])
        self.assertEqual((bot.seen('gh', 'pr', 'merge'), bot.seen('regenerate')), ([], []))
        comment = bot.seen('gh', 'pr', 'comment')
        self.assertEqual(len(comment), 1)
        self.assertIn('status: added entries must have status `mapped`', comment[0][-1])
        self.assertIn('forbidden-field', comment[0][-1])

    def test_a_failed_mapping_check_blocks_and_a_missing_one_retries_without_caching(self):
        bot = MappingBot(self.work, ci='failure')
        self.assertEqual(bot.process(PR)['blocked'], 'mapping-ci')
        self.assertEqual((bot.seen('mapping_review'), bot.seen('gh', 'pr', 'merge')), ([], []))
        waiting = MappingBot(self.work / 'w', ci=None)
        with self.assertRaises(pr_bot.Stop):
            waiting.process(PR)
        waiting.ci = 'success'
        self.assertTrue(waiting.process(PR)['merge'])
        self.assertEqual(len(waiting.seen('mapping_problems')), 1)

    def test_a_reject_a_leak_or_an_unreadable_review_never_merges(self):
        reject = json.dumps({'leak': 'no', 'verdict': 'reject', 'ground': 'plausibility', 'why': 'names do not fit sizes'})
        leak = json.dumps({'leak': 'yes', 'leak_evidence': ['decompiler-artifact'], 'verdict': 'approve'})
        for n, (text, blocked, shown) in enumerate(((reject, 'review', 'names do not fit sizes'),
                                                    (leak, 'leak', 'decompiler-artifact'),
                                                    ('nonsense', 'leak', 'bot fault'))):
            bot = MappingBot(self.work / str(n), review=text)
            self.assertEqual(bot.process(PR)['blocked'], blocked)
            self.assertEqual((bot.seen('gh', 'pr', 'merge'), bot.seen('regenerate')), ([], []))
            self.assertIn(shown, bot.seen('gh', 'pr', 'comment')[0][-1])

    def test_a_refused_merge_does_not_regenerate(self):
        bot = MappingBot(self.work)
        bot.merge_ok = False
        with self.assertRaises(pr_bot.Stop):
            bot.process(PR)
        self.assertEqual(bot.seen('regenerate'), [])

    def test_a_dry_run_changes_nothing(self):
        bot = MappingBot(self.work, dry_run=True)
        self.assertTrue(bot.process(PR)['merge'])
        self.assertEqual((bot.seen('gh', 'pr', 'merge'), bot.seen('regenerate'), bot.seen('gh', 'pr', 'comment')),
                         ([], [], []))

    def test_warm_never_probes_a_mapping_pr(self):
        bot = MappingBot(self.work)
        probed = []
        bot.probe_hash_run = lambda number, head: probed.append(number)
        bot.latest_hash_run = lambda head, unusable=(): None
        bot.warm({'number': 7, 'headRefOid': HEAD})
        self.assertEqual(probed, [])

    def test_the_mapping_reviewer_is_told_it_may_read_with_shell_commands(self):
        # A read-only sandbox reads only through shell commands; "run nothing" made the model report that it
        # could not inspect the findings and reject every mapping PR.
        text = pr_bot.MAPPING_PREAMBLE
        self.assertIn('read-only shell commands', text)
        self.assertNotIn('run nothing', text)

    def test_review_answers_are_parsed_strictly(self):
        self.assertEqual(pr_bot.parse_mapping_review(MappingBot.APPROVE), ('no', 'approve', ['ok']))
        self.assertEqual(pr_bot.parse_mapping_review('x')[:2], ('unreadable', 'reject'))
        bare = json.dumps({'leak': 'yes', 'verdict': 'approve'})
        self.assertEqual(pr_bot.parse_mapping_review(bare)[:2], ('no', 'approve'))
        self.assertEqual(pr_bot.parse_mapping_review(json.dumps({'leak': 'no'}))[:2], ('no', 'reject'))

    def test_the_regenerate_pushes_only_generated_files(self):
        calls, status = [], []

        class Tree(pr_bot.Bot):
            def run(self, argv, **kw):
                argv = [str(a) for a in argv]
                calls.append(argv)
                out = ''.join(f' M {n}\n' for n in status).encode() if argv[:2] == ['git', 'status'] else b''
                return subprocess.CompletedProcess(argv, 0, out, b'')
        bot = Tree(root=ROOT, work=self.work)
        env = mock.patch.dict(os.environ, {'SR_TARGET_IMAGE': '/img/game.exe', 'SR_FUNCTION_TABLE': '/t/f.jsonl'})
        env.start()
        self.addCleanup(env.stop)
        status[:] = ['reconstruction/INDEX.md', 'docs/progress.svg']
        bot.regenerate(7)
        self.assertTrue(any(c[:2] == ['git', 'push'] for c in calls))
        add = [c for c in calls if c[:2] == ['git', 'add']][0]
        self.assertEqual(add[-2:], ['docs/progress.svg', 'reconstruction/INDEX.md'])
        # The offers must be refreshed before the manifest that binds their digest, both before the commit.
        scripts = [Path(c[1]).name for c in calls if len(c) > 1 and c[1].startswith('tools/')]
        self.assertEqual(scripts[-2:], ['target_hash_offers.py', 'target_hashes.py'])
        self.assertIn('/img/game.exe', [c for c in calls if c[1:2] == ['tools/target_hashes.py']][0])
        self.assertLess(calls.index([c for c in calls if c[1:2] == ['tools/target_hashes.py']][0]),
                        calls.index(add))
        calls.clear()
        status[:] = ['data/target-hashes/contributor-targets.json', 'data/target-hashes/sse-steam-1-7-104-part-003.json',
                     'data/target-hashes/sse-steam-1-7-104.json']
        bot.regenerate(7)
        # A shard the manifest newly names is untracked; the status must report it or main loses the file.
        self.assertIn('--untracked-files=all', [c for c in calls if c[:2] == ['git', 'status']][0])
        self.assertTrue(any(c[:2] == ['git', 'push'] for c in calls))
        calls.clear()
        status[:] = ['data/target-hashes/sub/x.json']
        with self.assertRaises(pr_bot.Stop):
            bot.regenerate(7)
        self.assertFalse(any(c[:2] == ['git', 'push'] for c in calls))
        calls.clear()
        status[:] = ['reconstruction/INDEX.md', 'data/progress.json']
        with self.assertRaises(pr_bot.Stop):
            bot.regenerate(7)
        self.assertFalse(any(c[:2] == ['git', 'push'] for c in calls))
        calls.clear()
        status[:] = []
        bot.regenerate(7)
        self.assertFalse(any(c[:2] in (['git', 'push'], ['git', 'commit']) for c in calls))
        calls.clear()
        env.stop()
        with mock.patch.dict(os.environ):
            os.environ.pop('SR_TARGET_IMAGE', None)
            with self.assertRaises(pr_bot.Stop):
                bot.regenerate(7)
        self.assertEqual(calls, [])
        env.start()


class StickyCommentTests(unittest.TestCase):
    """Each PR carries at most one bot comment, edited in place on every head and verdict."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.work = Path(self.tmp.name)

    def test_new_heads_edit_the_one_comment_and_show_only_the_current_head(self):
        bot = FakeBot(self.work, h2={0x10: 'fail', 0x20: 'fail'})
        bot.process(PR)
        bot.process(dict(PR, headRefOid='c' * 40))
        bot.process(dict(PR, headRefOid='d' * 40, mergeable='CONFLICTING'))
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        self.assertEqual(len(bot.seen('gh', 'api', '-X', 'PATCH')), 2)
        self.assertEqual(len(bot.comments), 1)
        body = bot.comments[0]['body']
        self.assertTrue(body.startswith(pr_bot.STICKY))
        self.assertIn('dddddddd', body)
        self.assertNotIn('cccccccc', body)
        self.assertNotIn('did not byte-match', body)
        self.assertIn('merge main into your branch', body)

    def test_a_reset_state_for_the_same_head_does_not_post_again(self):
        bot = FakeBot(self.work, h2={0x10: 'fail', 0x20: 'fail'})
        bot.process(PR)
        for f in (self.work / 'state').iterdir():
            f.unlink()
        bot.process(PR)
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        self.assertEqual(bot.seen('gh', 'api', '-X', 'PATCH'), [])  # same body: nothing to edit

    def test_a_legacy_bot_comment_is_adopted_and_other_comments_are_left_alone(self):
        bot = FakeBot(self.work, h2={0x10: 'fail', 0x20: 'fail'})
        bot.comments = [{'id': 1, 'login': 'alice', 'body': '<!-- pr-bot --> not the bot'},
                        {'id': 2, 'login': pr_bot.OWNER, 'body': '<!-- pr-bot sha=' + 'e' * 40 + ' -->\nold'},
                        {'id': 3, 'login': pr_bot.OWNER, 'body': 'A note from the maintainer.'}]
        bot.process(PR)
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])
        patch = bot.seen('gh', 'api', '-X', 'PATCH')
        self.assertEqual([c[4].rsplit('/', 1)[1] for c in patch], ['2'])
        self.assertEqual(bot.comments[0]['body'], '<!-- pr-bot --> not the bot')
        self.assertEqual(bot.comments[2]['body'], 'A note from the maintainer.')

    def test_a_clean_merge_posts_nothing_but_clears_an_earlier_rejection(self):
        bot = FakeBot(self.work)
        bot.process(PR)
        self.assertEqual((bot.comments, bot.seen('gh', 'api', '-X', 'PATCH')), ([], []))
        other = FakeBot(self.work / 'n')
        other.comments = [{'id': 5, 'login': pr_bot.OWNER, 'body': pr_bot.STICKY + '\nNot accepted yet'}]
        other.process(PR)
        self.assertEqual(other.seen('gh', 'pr', 'comment'), [])
        self.assertIn('Merged and recorded: 0x10, 0x20.', other.comments[0]['body'])
        self.assertNotIn('Not accepted', other.comments[0]['body'])

    def test_an_over_cap_pr_gets_the_reason_in_its_sticky_comment_once(self):
        bot = FakeBot(self.work)
        bot.config['max_functions'] = 1
        for _ in range(3):
            with self.assertRaises(pr_bot.Rejected):
                bot.process(PR)
        self.assertEqual(len(bot.comments), 1)
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        self.assertEqual(bot.seen('gh', 'api', '-X', 'PATCH'), [])
        self.assertIn('2 functions, over the limit of 1', bot.comments[0]['body'])
        self.assertTrue(bot.comments[0]['body'].startswith(pr_bot.STICKY))

    def test_a_rejection_edits_the_existing_comment_in_place(self):
        bot = FakeBot(self.work)
        bot.config['max_functions'] = 1
        bot.comments = [{'id': 5, 'login': pr_bot.OWNER, 'body': pr_bot.STICKY + '\nold'}]
        with self.assertRaises(pr_bot.Rejected):
            bot.process(PR)
        self.assertEqual(bot.seen('gh', 'pr', 'comment'), [])
        self.assertEqual(len(bot.comments), 1)
        self.assertIn('limit of 1', bot.comments[0]['body'])

    def test_a_header_rejection_is_posted_and_a_bot_stop_is_not(self):
        bot = FakeBot(self.work)

        def bad(files):
            raise pr_bot.Rejected('rva-headers', 'fix the header')
        bot.units = bad
        with self.assertRaises(pr_bot.Rejected):
            bot.process(PR)
        self.assertIn('fix the header', bot.comments[0]['body'])
        other = FakeBot(self.work / 's')

        def down(units, tag):
            raise pr_bot.Stop('verifier host did not complete')
        other.mac_compare = down
        with self.assertRaises(pr_bot.Stop):
            other.process(PR)
        self.assertEqual(other.comments, [])

    def test_the_batching_request_is_a_line_in_the_sticky_comment(self):
        bot = FakeBot(self.work)
        bot.sizes = {0x10: 40, 0x20: 60}
        bot.process(PR)
        self.assertEqual(len(bot.seen('gh', 'pr', 'comment')), 1)
        body = bot.comments[0]['body']
        self.assertIn('Merged and recorded', body)
        self.assertIn(pr_bot.BATCH_LINE, body)

    def test_batching_asks_only_small_prs_of_known_size(self):
        self.assertTrue(pr_bot.wants_batching([1, 2], {1: 40, 2: 40}))
        self.assertFalse(pr_bot.wants_batching([1], {1: 50000}))
        self.assertFalse(pr_bot.wants_batching([1, 2], {1: 40}))
        many = list(range(pr_bot.BATCH_MIN))
        self.assertFalse(pr_bot.wants_batching(many, {r: 4 for r in many}))
        self.assertFalse(pr_bot.wants_batching([], {}))

    def test_the_bot_posts_comments_only_through_the_sticky_helper(self):
        source = (ROOT / 'tools/pr_bot.py').read_text()
        self.assertEqual(source.count("'gh', 'pr', 'comment'"), 1)
        self.assertNotRegex(source, r"pr', 'review'|/reviews")

    def test_header_sizes_reads_the_unit_headers_in_the_prepared_tree(self):
        bot = pr_bot.Bot(root=ROOT, work=self.work)
        unit = bot.tree / 'reconstruction/a/B.cpp'
        unit.parent.mkdir(parents=True)
        unit.write_text('// RVA 0x10, 40 bytes, A::f\n// RVA 0x20, 8 bytes, A::g\n')
        self.assertEqual(bot.header_sizes({'reconstruction/a/B.cpp': [0x10, 0x20]}), {0x10: 40, 0x20: 8})


class NewFunctionsTest(unittest.TestCase):
    def test_functions_already_on_base_do_not_count(self):
        bot = pr_bot.Bot(root=ROOT, work=Path(tempfile.mkdtemp()))
        shown = {'base:reconstruction/a/B.h': b'// RVA 0x10, 4 bytes: B::f\n', 'base:reconstruction/a/B.cpp': b''}

        def run(argv, **kw):
            out = shown.get(argv[-1])
            return subprocess.CompletedProcess(argv, 0 if out is not None else 128, out or b'')
        bot.run = run
        units = {'reconstruction/a/B.cpp': [0x10, 0x20], 'reconstruction/a/C.cpp': [0x30]}
        self.assertEqual(bot.new_functions('base', units), {0x20, 0x30})


class TargetRvasTest(unittest.TestCase):
    def test_target_rvas_read_the_shards(self):
        work = Path(tempfile.mkdtemp())
        bot = pr_bot.Bot(root=ROOT, work=work)
        shards = bot.tree / 'data/target-hashes'
        shards.mkdir(parents=True)
        (shards / 'sse-steam-1-7-104-part-000.json').write_text(json.dumps({'functions': [{'rva': 16}, {'rva': 32}]}))
        self.assertEqual(bot.target_rvas(), {16, 32})
        self.assertEqual(pr_bot.Bot(root=ROOT, work=Path(tempfile.mkdtemp())).target_rvas(), set())


class OutcomeLineTests(unittest.TestCase):
    def test_unblocked_refusal_says_why(self):
        result = dict(pr=350, head='h', blocked=None, merge=False,
                      verdicts={'0x1': 'fail:review', '0x2': 'fail:review', '0x3': 'debt'})
        self.assertEqual(pr_bot.outcome(result, dict(number=350))['why'], {'debt': 1, 'fail:review': 2})

    def test_merge_and_blocked_lines_stay_short(self):
        self.assertNotIn('why', pr_bot.outcome(dict(pr=1, head='h', blocked=None, merge=True, verdicts={'0x1': 'matched'}),
                                               dict(number=1)))
        self.assertNotIn('why', pr_bot.outcome(dict(pr=1, head='h', blocked='stale', merge=False, verdicts={'0x1': 'x'}),
                                               dict(number=1)))


if __name__ == '__main__':
    unittest.main()


class CarryHost1Tests(unittest.TestCase):
    """The comment-only exception: host 1 is carried only for a no-target function with an unchanged-code unit."""
    UNIT = 'reconstruction/a/U.cpp'
    OLD = b'// U: GUESS(low)\nint f() { return 1; }\n'

    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.repo, self.tree = Path(tmp.name) / 'repo', Path(tmp.name) / 'tree'
        for root in (self.repo, self.tree):
            (root / 'reconstruction/a').mkdir(parents=True)
            (root / 'data/target-hashes').mkdir(parents=True)
        self.write(self.repo, 'data/target-hashes/sse-steam-1-7-104.json',
                   json.dumps({'shards': [{'path': 'data/target-hashes/sse-steam-1-7-104-part-000.json'}]}))
        self.write(self.repo, 'data/target-hashes/sse-steam-1-7-104-part-000.json',
                   json.dumps({'functions': [{'rva': 0x40, 'extraction': 'masked'},
                                             {'rva': 0x50, 'extraction': 'unmasked-unsupported'}]}))
        self.write(self.repo, self.UNIT, self.OLD)
        self.git('init', '-q', '-b', 'main')
        self.git('add', '.')
        self.git('commit', '-qm', 'base')
        self.base = self.git('rev-parse', 'HEAD')
        for name in ('data/target-hashes/sse-steam-1-7-104.json', 'data/target-hashes/sse-steam-1-7-104-part-000.json'):
            self.write(self.tree, name, (self.repo / name).read_bytes())
        self.set_head(b'// U: OBSERVED; table entry\n// more prose\nint f() { return 1; }\n')
        self.accepted(0x10, 0x20, 0x40, 0x50)
        self.bot = pr_bot.Bot(root=self.repo, work=self.tree / 'w')
        self.bot.tree = self.tree
        self.state = pr_bot.State(self.tree / 'w', 7, HEAD)
        self.hash_run(16)
        self.files = [{'filename': self.UNIT}]

    def hash_run(self, *rvas, base='no-target', result='no-target', status='unverified'):
        """The `ci` state the bot keeps from a hash run whose rows are all alike, built from the artifact's rows."""
        report = {'functions': [{'rva': hex(r), 'unit': self.UNIT, 'result': result, 'base': base, 'status': status}
                                for r in rvas]}
        self.state.data['ci'] = dict(report={}, rows={}, map={str(r): status for r in rvas}, **pr_bot.row_facts(report))

    def no_run(self):
        self.state.data['ci'] = dict(report={}, rows={}, map={}, seen=[], no_target_base=[])

    def write(self, root, name, data):
        path = Path(root) / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data if isinstance(data, bytes) else data.encode())

    def git(self, *args):
        return subprocess.run(['git', '-C', str(self.repo), '-c', 'user.email=t@example.invalid', '-c',
                               'user.name=T', *args], check=True, capture_output=True).stdout.decode().strip()

    def set_head(self, text):
        self.write(self.tree, self.UNIT, text)

    def accepted(self, *rvas):
        self.write(self.tree, 'data/progress.json', json.dumps({'functions': [
            {'build_id': 'b', 'rva': r, 'status': 'matched', 'report': f'r{r}.json'} for r in rvas]}))

    def carry(self, host1=None, host2=None, rvas=(0x10,), units=None):
        return self.bot.carry_host1(self.base, self.files, list(rvas), units or {self.UNIT: list(rvas)},
                                    host1 or {r: 'unverified' for r in rvas}, host2 or {r: 'pass' for r in rvas},
                                    self.state)

    def test_a_comment_only_unit_without_a_target_carries_host_1(self):
        got = self.carry()
        self.assertEqual(got, {'16': 'host1: carried (comment-only, no-target at base)'})
        self.assertEqual(got['16'], pr_bot.CARRY_REASON)

    def test_a_unit_the_job_skipped_for_comments_carries_when_no_target_was_ever_published(self):
        self.no_run()
        self.assertEqual(list(self.carry(host1={0x10: 'fail'})), ['16'])
        self.assertEqual(list(self.carry(rvas=(0x50,), host1={0x50: 'fail'})), ['80'])  # unmasked-unsupported row
        self.assertEqual(self.carry(rvas=(0x40,), host1={0x40: 'fail'}), {})  # a target was published at base

    def test_a_target_published_after_base_blocks_the_carry_for_a_skipped_unit(self):
        self.no_run()
        self.write(self.tree, 'data/target-hashes/sse-steam-1-7-104-part-000.json',
                   json.dumps({'functions': [{'rva': 0x10, 'extraction': 'masked'}]}))
        self.assertEqual(self.carry(host1={0x10: 'fail'}), {})

    def test_the_job_must_have_found_no_target_at_base_too(self):
        for base in ('hash-match', 'mismatch', None):
            self.hash_run(16, base=base)
            self.assertEqual(self.carry(), {}, base)

    def test_a_published_target_does_not_matter_when_the_job_itself_found_no_target_at_base(self):
        self.hash_run(64)
        self.assertEqual(list(self.carry(rvas=(0x40,))), ['64'])

    def test_a_code_change_never_carries(self):
        self.set_head(b'// U: GUESS(low)\nint f() { return 2; }\n')
        self.assertEqual(self.carry(), {})

    def test_a_string_or_include_change_is_code(self):
        self.set_head(b'// U: GUESS(low)\nconst char* s = "x";\nint f() { return 1; }\n')
        self.assertEqual(self.carry(), {})

    def test_a_unit_that_is_new_in_the_pr_never_carries(self):
        self.files = [{'filename': 'reconstruction/a/N.cpp'}]
        self.write(self.tree, 'reconstruction/a/N.cpp', b'int g() { return 1; }\n')
        self.assertEqual(self.carry(units={'reconstruction/a/N.cpp': [0x10]}), {})

    def test_a_header_changed_in_code_blocks_the_carry_for_the_units_that_include_it(self):
        self.write(self.repo, 'reconstruction/a/H.h', b'// h\nint h;\n')
        self.git('add', '.')
        self.git('commit', '-qm', 'header')
        self.base = self.git('rev-parse', 'HEAD')
        self.write(self.repo, self.UNIT, b'#include "H.h"\n' + self.OLD)
        self.git('commit', '-qam', 'include')
        self.base = self.git('rev-parse', 'HEAD')
        self.write(self.tree, 'reconstruction/a/H.h', b'// h\nint h;\n')
        self.set_head(b'#include "H.h"\n// U: OBSERVED\nint f() { return 1; }\n')
        self.files = [{'filename': self.UNIT}, {'filename': 'reconstruction/a/H.h'}]
        self.assertEqual(list(self.carry()), ['16'])
        self.write(self.tree, 'reconstruction/a/H.h', b'// h\nint h2;\n')
        self.assertEqual(self.carry(), {})

    def test_host_2_must_pass_on_the_new_text(self):
        for bad in ('fail', 'preexisting-fail', None):
            self.assertEqual(self.carry(host2={0x10: bad}), {}, bad)

    def test_a_real_host_1_failure_is_not_carried(self):
        for result, status in (('mismatch', 'fail'), ('mismatch', 'regressed'), ('hash-match', 'pass')):
            self.hash_run(16, result=result, status=status)
            self.assertEqual(self.carry(host1={0x10: 'fail'}), {}, (result, status))
        self.no_run()
        self.state.data['ci']['report'] = {'error': 'ValueError'}
        self.assertEqual(self.carry(host1={0x10: 'fail'}), {})

    def test_a_function_with_no_accepted_record_has_nothing_to_carry(self):
        self.hash_run(48)
        self.assertEqual(self.carry(rvas=(0x30,)), {})

    def test_without_hash_evidence_nothing_carries(self):
        self.state.data.pop('ci')
        self.assertEqual(self.carry(), {})


class RowFactsTests(unittest.TestCase):
    def test_a_function_is_no_target_at_base_only_if_every_row_for_it_says_so(self):
        rows = [{'rva': '0x10', 'unit': 'a.cpp', 'result': 'no-target', 'base': 'no-target'},
                {'rva': '0x20', 'unit': 'a.cpp', 'result': 'no-target', 'base': 'no-target'},
                {'rva': '0x20', 'unit': 'b.cpp', 'result': 'hash-match', 'base': 'hash-match'},
                {'rva': '0x30', 'unit': 'a.cpp', 'result': 'no-target', 'base': None},
                {'rva': None, 'unit': 'c.cpp', 'result': 'no-target', 'base': 'no-target'}]
        self.assertEqual(pr_bot.row_facts({'functions': rows}), {'seen': [0x10, 0x20, 0x30], 'no_target_base': [0x10]})
        self.assertEqual(pr_bot.row_facts({}), {'seen': [], 'no_target_base': []})
