"""Offline feedback tests. Every gh invocation is mocked; all comments and identities are synthetic."""
import contextlib
import copy
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import contrib
import contrib_feedback as feedback

HEAD = 'a' * 40
OLD = 'b' * 40
BEFORE = '2026-01-01T00:00:00Z'
COMMIT = '2026-01-02T00:00:00Z'
NEW = '2026-01-03T00:00:00Z'
REPLY = '2026-01-04T00:00:00Z'
URL = 'https://github.com/example/project/pull/1'


def comment(who='maintainer', when=NEW, body='Please fix this.', association='OWNER', **extra):
    return dict(id=1, user=dict(login=who), body=body, updated_at=when, html_url=URL + '#issuecomment-1',
                author_association=association, **extra)


def sticky(short, text, batch=False):
    """Synthetic body in the intake bot's sticky-comment layout."""
    lines = ['<!-- pr-bot -->', f'Bot status for head {short} (this comment is updated in place on each push).', '', text]
    if batch:
        lines += ['', 'Small request: please batch 50 to 200 functions in one PR next time.']
    return '\n'.join(lines)


def review(state='CHANGES_REQUESTED', who='maintainer', when=NEW):
    return dict(id=2, user=dict(login=who), body='Please revise.', state=state, submitted_at=when,
                commit_id=HEAD, html_url=URL + '#pullrequestreview-2')


def thread(resolved=False, when=NEW):
    return dict(id='thread-1', path='synthetic/example.cpp', line=12, originalLine=10,
                isResolved=resolved, isOutdated=False, comments=[
                    dict(id='comment-3', body='Fix the wording.', author=dict(login='reviewer'),
                         createdAt=when, updatedAt=when, url=URL + '#discussion_r3')])


def pr(number=1, who='contributor'):
    return dict(number=number, title='Synthetic PR', html_url=URL, user=dict(login=who), head=dict(sha=HEAD))


def summary(threads=(), reviews=(), comments=(), checks=(), statuses=()):
    return feedback.summarize(pr(), 'contributor', HEAD, COMMIT, list(threads), list(reviews),
                              list(comments), list(checks), list(statuses))


class SummaryTests(unittest.TestCase):
    def test_unresolved_threads_include_location_author_body_and_outdated_lines(self):
        outdated = thread()
        outdated.update(line=None, isOutdated=True)
        row = summary(threads=[outdated, thread(resolved=True)])
        self.assertEqual(row['action_count'], 1)
        got = row['review_threads'][0]
        self.assertEqual((got['file'], got['line'], got['outdated']), ('synthetic/example.cpp', 10, True))
        self.assertEqual((got['comments'][0]['author'], got['comments'][0]['body']), ('reviewer', 'Fix the wording.'))
        self.assertTrue(got['is_new'])

    def test_push_and_reply_do_not_clear_unresolved_threads_or_active_change_requests(self):
        row = summary(threads=[thread(when=BEFORE)], reviews=[review(when=BEFORE)],
                      comments=[comment('contributor', REPLY)])
        self.assertTrue(row['needs_action'])
        self.assertFalse(row['review_threads'][0]['is_new'])
        self.assertFalse(row['changes_requested'][0]['is_new'])

    def test_latest_decisive_review_per_author_and_dismissals(self):
        for state in ('APPROVED', 'DISMISSED'):
            with self.subTest(state=state):
                self.assertFalse(summary(reviews=[review(when=BEFORE), review(state)])['needs_action'])
        row = summary(reviews=[review(), review('COMMENTED', when=REPLY), review(who='another')])
        self.assertEqual(len(row['changes_requested']), 2)

    def test_maintainer_comments_and_authenticated_identity(self):
        row = summary(comments=[comment(), comment('outsider', association='NONE'),
                                comment('contributor', BEFORE), comment('collaborator', association='COLLABORATOR')])
        self.assertEqual([c['author'] for c in row['issue_comments']], ['maintainer', 'collaborator'])
        self.assertEqual(row['last_reply_at'], BEFORE)
        self.assertEqual(row['action_count'], 2)

    def test_reply_timestamps_include_resolved_threads_and_comment_edits(self):
        replied = thread(resolved=True)
        replied['comments'].append(dict(id='reply', author=dict(login='CONTRIBUTOR'), body='Fixed',
                                        createdAt=REPLY, updatedAt=REPLY, url=URL))
        row = summary(threads=[replied], comments=[comment()])
        self.assertFalse(row['needs_action'])
        self.assertTrue(row['issue_comments'][0]['new_since_commit'])
        self.assertFalse(row['issue_comments'][0]['new_since_reply'])
        edited = summary(threads=[replied], comments=[comment(when='2026-01-05T00:00:00Z')])
        self.assertTrue(edited['needs_action'])

    def test_bot_sticky_only_current_head_failure_is_actionable(self):
        failing = ('Not accepted yet (they stay drafted; push a fix and the bot re-checks the new head):\n'
                   '- 0x1000: the review did not approve it\n  - Synthetic reviewer note.')
        bodies = [sticky(HEAD[:8], failing), sticky(OLD[:8], failing),
                  sticky(HEAD[:8], 'Everything in this PR is already on main, but its commit history cannot be '
                                   'merged as it is, so the PR stays open for the maintainer.'),
                  f'<!-- pr-bot sha={HEAD} -->\nThis PR conflicts with main; merge main into your branch and push.',
                  f'<!-- pr-bot sha={OLD} -->\nThis PR conflicts with main; merge main into your branch and push.']
        row = summary(comments=[comment(body=b) for b in bodies])
        self.assertEqual([c['needs_action'] for c in row['issue_comments']], [True, False, False, True, False])
        self.assertTrue(all(c['intake_bot'] for c in row['issue_comments']))
        self.assertEqual(row['action_count'], 2)

    def test_bot_sticky_after_contributor_reply_is_history(self):
        row = summary(comments=[comment(body=sticky(HEAD[:8], '- 0x1000: x')), comment('contributor', REPLY)])
        self.assertFalse(row['issue_comments'][0]['needs_action'])

    def test_bot_markers_do_not_turn_arbitrary_outsiders_into_intake(self):
        row = comment('outsider', body=sticky(HEAD[:8], '- 0x1000: x'), association='NONE')
        self.assertEqual(summary(comments=[row])['issue_comments'], [])
        row['user']['type'] = 'Bot'
        self.assertTrue(summary(comments=[row])['issue_comments'][0]['intake_bot'])

    def test_marker_must_open_the_comment(self):
        quoted = comment(body='> ' + sticky(HEAD[:8], '- 0x1000: x'))
        self.assertFalse(summary(comments=[quoted])['issue_comments'][0]['intake_bot'])

    def test_parse_sticky_fields(self):
        body = sticky(HEAD[:8], 'Not accepted yet:\n- 0x1000: the review did not approve it\n  - Note A.\n'
                                '- 0x2000: did not byte-match', batch=True)
        got = feedback.parse_sticky(body)
        self.assertEqual(got['head'], HEAD[:8])
        self.assertTrue(got['batch'])
        self.assertEqual(got['what_needs_changing'], ['0x1000: the review did not approve it (Note A.)',
                                                      '0x2000: did not byte-match'])
        self.assertNotIn('please batch', got['text'])
        held = feedback.parse_sticky(sticky(HEAD[:8], 'This PR was held before any compile.'))
        self.assertEqual(held['what_needs_changing'], ['This PR was held before any compile.'])
        for text in ('Nothing to report.', 'Merged and recorded: 0x1000.'):
            self.assertEqual(feedback.parse_sticky(sticky(HEAD[:8], text))['what_needs_changing'], [])
        self.assertIsNone(feedback.parse_sticky('Please fix this.'))
        self.assertIsNone(feedback.parse_sticky('<!-- contrib-autopilot:1:' + HEAD + ':feedback -->'))

    def test_checks_and_legacy_status_failures_are_both_reported(self):
        checks = [dict(name=c, conclusion=c, completed_at=NEW, html_url=URL)
                  for c in ('failure', 'timed_out', 'cancelled', 'action_required', 'success', 'neutral', 'skipped', None)]
        statuses = [dict(context=s, state=s, updated_at=NEW, target_url=URL)
                    for s in ('failure', 'error', 'pending', 'success')]
        row = summary(checks=checks, statuses=statuses)
        self.assertEqual(len(row['failing_checks']), 6)
        self.assertTrue(all(c['new_since_commit'] and c['new_since_reply'] for c in row['failing_checks']))

    def test_dates_are_compared_as_instants(self):
        row = summary(comments=[comment(when='2026-01-02T01:00:00+02:00')])
        self.assertFalse(row['issue_comments'][0]['new_since_commit'])
        self.assertTrue(row['issue_comments'][0]['new_since_reply'])


class GhTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.calls = []
        self.env = {'PATH': '', 'SR_UPSTREAM': 'example/project', 'SR_GITHUB_USER': 'not-the-authenticated-user'}
        self.ctx = contrib.Ctx(repo=Path(self.tmp.name), private=Path(self.tmp.name) / 'private',
                               env=self.env, interactive=False, runner=self.run_gh)
        self.ctx.which = lambda name: 'gh'
        self.prs = [pr(), pr(2, 'someone-else')]
        self.connection = dict(nodes=[thread()], pageInfo=dict(hasNextPage=False, endCursor=None))
        self.connection['nodes'][0]['comments'] = dict(nodes=self.connection['nodes'][0]['comments'],
                                                       pageInfo=dict(hasNextPage=False, endCursor=None))
        self.reviews, self.comments, self.checks = [review()], [comment()], []
        self.failure = None

    def run_gh(self, argv, **kw):
        self.calls.append(argv)
        if self.failure:
            if isinstance(self.failure, Exception):
                raise self.failure
            return subprocess.CompletedProcess(argv, 1, '', 'synthetic transport failure')
        if argv[1:] == ['auth', 'status']:
            value = None
        else:
            self.assertEqual(argv[1], 'api', 'feedback must be read-only')
            self.assertEqual(kw['timeout'], 20)
            path = argv[2]
            if path == 'user':
                value = dict(login='contributor')
            elif path == 'graphql':
                if feedback.COMMENT_QUERY in argv[4]:
                    value = dict(data=dict(node=dict(comments=self.extra_comments)))
                else:
                    value = dict(data=dict(repository=dict(pullRequest=dict(
                        headRefOid=HEAD, commits=dict(nodes=[dict(commit=dict(committedDate=COMMIT))]),
                        reviewThreads=self.connection))))
            elif '/pulls?state=open' in path:
                value = self.prs if path.endswith('page=1') else []
            elif path == 'repos/example/project/pulls/1':
                value = pr()
            elif '/pulls/1/reviews?' in path:
                value = self.reviews if path.endswith('page=1') else []
            elif '/issues/1/comments?' in path:
                value = self.comments if path.endswith('page=1') else []
            elif f'/commits/{HEAD}/check-runs?' in path:
                value = dict(check_runs=self.checks if path.endswith('page=1') else [])
            elif f'/commits/{HEAD}/status?' in path:
                value = dict(statuses=[])
            else:
                self.fail('unexpected gh request: ' + repr(argv))
        return subprocess.CompletedProcess(argv, 0, json.dumps(copy.deepcopy(value)), '')

    def invoke(self, argv=('feedback', '--json')):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            code = contrib.main(list(argv), ctx=self.ctx)
        return code, json.loads(output.getvalue())

    def test_json_and_own_pr_filter_on_each_platform(self):
        for platform in ('darwin', 'linux', 'win32'):
            with self.subTest(platform=platform):
                self.ctx.platform = platform
                code, data = self.invoke()
                self.assertEqual(code, contrib.FAILED)
                self.assertTrue(data['feedback_available'])
                self.assertEqual(data['needs_action_prs'], 1)
                self.assertEqual(data['contributor'], 'contributor')
                self.assertEqual([p['number'] for p in data['pull_requests']], [1])
                self.assertEqual(data['pull_requests'][0]['changes_requested'][0]['author'], 'maintainer')
        self.assertFalse(any('/pulls/2/' in ' '.join(c) for c in self.calls))

    def test_empty_list_is_zero_with_json_before_command(self):
        self.prs = []
        code, data = self.invoke(('--json', 'feedback'))
        self.assertEqual(code, contrib.OK)
        self.assertEqual(data['pull_requests'], [])
        self.assertIsNone(data['error'])

    def test_text_prints_location_body_review_and_check(self):
        self.checks = [dict(name='synthetic check', conclusion='failure', completed_at=NEW, html_url=URL)]
        self.ctx.as_json = False
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            self.assertEqual(contrib.main(['feedback'], ctx=self.ctx), contrib.FAILED)
        for expected in ('synthetic/example.cpp:12', 'reviewer', 'Fix the wording.', 'Please revise.', 'synthetic check', 'NEW'):
            self.assertIn(expected, output.getvalue())

    def test_no_network_no_auth_missing_gh_and_timeout_degrade_clearly(self):
        for failure in ('network', subprocess.TimeoutExpired('gh', 20), FileNotFoundError('gh')):
            with self.subTest(failure=failure):
                self.failure = failure
                code, data = self.invoke()
                self.assertEqual(code, contrib.NETWORK)
                self.assertFalse(data['feedback_available'])
                self.assertIn('Feedback unavailable', data['error'])
                self.assertIn('gh auth', data['next'])
        self.failure = None
        self.ctx.which = lambda name: None
        code, data = self.invoke()
        self.assertEqual(code, contrib.NETWORK)
        self.assertIn('install GitHub CLI', data['error'])

    def test_explicit_offline_does_not_call_gh(self):
        self.ctx.env['SR_CONTRIB_OFFLINE'] = '1'
        code, data = self.invoke()
        self.assertEqual(code, contrib.NETWORK)
        self.assertIn('offline', data['error'])
        self.assertEqual(self.calls, [])

    def test_rest_pagination_including_checks_comments_reviews_and_prs(self):
        self.prs = [pr(n, 'other') for n in range(100)]
        self.reviews = [review()] * 100
        self.comments = [comment()] * 100
        self.checks = [dict(name='check', conclusion='failure')] * 100
        # First page includes only other authors; make the second page contain our PR.
        runner = self.run_gh

        def paged(argv, **kw):
            if argv[1] == 'api' and '/pulls?state=open' in argv[2] and argv[2].endswith('page=2'):
                self.calls.append(argv)
                return subprocess.CompletedProcess(argv, 0, json.dumps([pr()]), '')
            return runner(argv, **kw)

        self.ctx.runner = paged
        code, data = self.invoke()
        self.assertEqual(code, contrib.FAILED)
        self.assertEqual(len(data['pull_requests'][0]['issue_comments']), 100)
        for endpoint in ('pulls?state=open', 'reviews?', 'comments?', 'check-runs?'):
            self.assertTrue(any(endpoint in ' '.join(c) and 'page=2' in ' '.join(c) for c in self.calls))

    def test_nested_thread_comments_are_paginated(self):
        self.connection['nodes'][0]['comments']['pageInfo'] = dict(hasNextPage=True, endCursor='next-comments')
        self.extra_comments = dict(nodes=[dict(id='late', author=dict(login='contributor'), body='fixed',
                                               createdAt=REPLY, updatedAt=REPLY, url=URL)],
                                   pageInfo=dict(hasNextPage=False, endCursor=None))
        code, data = self.invoke()
        self.assertEqual(code, contrib.FAILED)
        self.assertEqual(data['pull_requests'][0]['last_reply_at'], REPLY)
        self.assertEqual(len(data['pull_requests'][0]['review_threads'][0]['comments']), 2)

    def test_incomplete_or_graphql_error_never_reports_clean(self):
        runner = self.run_gh
        for value in ({'errors': [{'message': 'synthetic error'}]}, 'not-json', {'data': {}}):
            def broken(argv, **kw):
                if argv[1] == 'api' and argv[2] == 'graphql':
                    return subprocess.CompletedProcess(argv, 0, json.dumps(value) if isinstance(value, dict) else value, '')
                return runner(argv, **kw)
            self.ctx.runner = broken
            code, data = self.invoke()
            self.assertEqual(code, contrib.NETWORK)
            self.assertFalse(data['feedback_available'])

    def test_moved_head_does_not_report_feedback_for_a_stale_commit(self):
        runner = self.run_gh

        def moved(argv, **kw):
            if argv[1:] == ['api', 'repos/example/project/pulls/1']:
                value = pr()
                value['head']['sha'] = OLD
                return subprocess.CompletedProcess(argv, 0, json.dumps(value), '')
            return runner(argv, **kw)

        self.ctx.runner = moved
        code, data = self.invoke()
        self.assertEqual(code, contrib.NETWORK)
        self.assertIn('new commit', data['error'])

    def test_review_thread_pagination_collects_later_threads(self):
        self.connection['pageInfo'] = dict(hasNextPage=True, endCursor='next-threads')
        runner = self.run_gh

        def paged(argv, **kw):
            if 'after=next-threads' in argv:
                first = copy.deepcopy(self.connection)
                self.connection['pageInfo']['hasNextPage'] = False
                self.connection['nodes'][0]['id'] = 'thread-2'
                try:
                    return runner(argv, **kw)
                finally:
                    self.connection = first
            return runner(argv, **kw)

        self.ctx.runner = paged
        code, data = self.invoke()
        self.assertEqual(code, contrib.FAILED)
        self.assertEqual([t['id'] for t in data['pull_requests'][0]['review_threads']], ['thread-1', 'thread-2'])

    def outcome(self):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            code = contrib.main(['--json', 'feedback', '1'], ctx=self.ctx)
        return code, json.loads(output.getvalue())

    def test_outcome_reads_the_owner_sticky_for_the_current_head(self):
        self.comments = [comment('example', body=sticky(OLD[:8], '- 0x1000: old')),
                         comment('outsider', body=sticky(HEAD[:8], '- 0x1000: spoofed'), association='NONE'),
                         comment('example', body=sticky(HEAD[:8], '- 0x1000: the review did not approve it'))]
        code, data = self.outcome()
        self.assertEqual(code, contrib.OK)
        self.assertEqual(data['what_needs_changing'], ['0x1000: the review did not approve it'])
        self.assertTrue(data['needs_action'])
        self.assertEqual(data['head'], HEAD)

    def test_outcome_accepts_the_legacy_sha_marker(self):
        self.comments = [comment('example', body=f'<!-- pr-bot sha={HEAD} -->\nThis PR conflicts with main.')]
        code, data = self.outcome()
        self.assertEqual(code, contrib.OK)
        self.assertEqual(data['what_needs_changing'], ['This PR conflicts with main.'])

    def test_outcome_for_a_stale_head_or_no_sticky_is_unavailable(self):
        for comments, words in (([comment('example', body=sticky(OLD[:8], '- 0x1000: x'))], 'current head'),
                                ([comment('example')], 'not commented')):
            with self.subTest(words=words):
                self.comments = comments
                code, data = self.outcome()
                self.assertEqual(code, contrib.NETWORK)
                self.assertIn(words, data['error'])

    def test_go_and_submit_print_advisory_without_changing_their_result(self):
        for command in ('go', 'submit'):
            for platform in ('darwin', 'win32'):
                with self.subTest(command=command, platform=platform):
                    self.ctx.platform = platform
                    with patch.dict(contrib.COMMANDS, {command: lambda ctx, args: (0, {}, None)}):
                        code, data = self.invoke(('--json', command))
                    self.assertEqual(code, contrib.OK)
                    self.assertIn(f'1 PRs have unaddressed feedback, run {self.ctx.cli} feedback', data['messages'])
        self.failure = 'offline'
        with patch.dict(contrib.COMMANDS, go=lambda ctx, args: (0, {}, None)):
            self.assertEqual(self.invoke(('--json', 'go'))[0], contrib.OK)


if __name__ == '__main__':
    unittest.main()
