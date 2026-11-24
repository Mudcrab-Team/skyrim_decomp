"""The findings lane: which PRs enter it, the digest exemption in leakgrep, the file checks and the landing.

Fixtures are invented prose; no game text, byte or value appears.
"""
import json
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import findings_check  # noqa: E402
import leakgrep  # noqa: E402
import pr_bot  # noqa: E402
import test_pr_bot_replay as replay  # noqa: E402

NAME = 'findings/widget-retail-facts.md'
DIGEST = 'ab' * 32


def finding(extra='', digest=True):
    pin = f'Image SHA-256 `{DIGEST}`.\n' if digest else ''
    return ('Transfer status: UNREVIEWED\n\n# Finding: widget defaults\n\n'
            f'{pin}Source exposure: mixed. Method: static reading of the pinned image. All claims are static.\n\n'
            'The widget scale default is 2 and the clamp is one half.\n\n'
            'Confidence: high for the values. Limitations: no runtime trace was taken.\n' + extra)


def diff_of(line, name=NAME):
    return f'--- a/{name}\n+++ b/{name}\n@@ -0,0 +1 @@\n+{line}\n'


class Lane(unittest.TestCase):
    def rows(self, *names, status='added'):
        return [{'filename': n, 'status': status} for n in names]

    def test_findings_only_prs_enter_the_lane_and_are_not_tooling_work(self):
        self.assertTrue(pr_bot.findings_lane(self.rows(NAME)))
        self.assertTrue(pr_bot.findings_lane(self.rows(NAME, status='modified')))
        self.assertTrue(pr_bot.findings_lane(self.rows(NAME, 'docs/cookbook-notes/1de5e0-x.md')))

    def test_everything_else_stays_out_of_the_lane(self):
        for files in ([], self.rows('tools/x.py'), self.rows(NAME, 'tools/x.py'), self.rows(NAME, 'tests/t.py'),
                      self.rows(NAME, 'reconstruction/a/B.cpp'), self.rows('findings/sub/x.md'),
                      self.rows('findings/TEMPLATE.txt'), self.rows('docs/cookbook-notes/1de5e0-x.md'),
                      self.rows(NAME, status='removed'),
                      [{'filename': NAME, 'status': 'renamed', 'previous_filename': 'findings/old.md'}],
                      self.rows(*[f'findings/f{i}.md' for i in range(pr_bot.MAX_FINDING_FILES + 1)])):
            self.assertFalse(pr_bot.findings_lane(files), files)
        self.assertTrue(pr_bot.tooling_lane(self.rows('tools/x.py')))


class DigestExemption(unittest.TestCase):
    def hits(self, line, name=NAME):
        return leakgrep.scan_diff(diff_of(line, name))

    def test_a_labelled_digest_in_a_finding_is_not_a_hit(self):
        self.assertEqual(self.hits(f'Image SHA-256 `{DIGEST}`.'), [])
        self.assertEqual(self.hits(f'Source revision {"c" * 40}.'), [])

    def test_the_exemption_is_narrow(self):
        self.assertEqual([c for _n, _l, c in self.hits(f'Value `{DIGEST}`.')], ['hex-run'])
        self.assertEqual([c for _n, _l, c in self.hits(f'Image SHA-256 `{DIGEST}`.', 'docs/x.md')], ['hex-run'])
        self.assertEqual([c for _n, _l, c in self.hits(f'Image SHA-256 `{DIGEST}`.', 'findings/x.txt')], ['hex-run'])
        self.assertEqual([c for _n, _l, c in self.hits('SHA-256 ' + 'ab' * 33)], ['hex-run'])
        self.assertEqual([c for _n, _l, c in self.hits('SHA-256 ' + ' '.join(['0f'] * 16))], ['hex-run'])
        self.assertEqual([c for _n, _l, c in self.hits(f'SHA-256 {DIGEST} then {"0f" * 24}')], ['hex-run'])

    def test_a_file_cannot_carry_data_out_as_many_digests(self):
        lines = ''.join(f'+SHA-256 {DIGEST}\n' for _ in range(leakgrep.MAX_FINDING_DIGESTS + 1))
        diff = f'+++ b/{NAME}\n@@ -0,0 +1,99 @@\n' + lines
        self.assertEqual([n for _f, n, _c in leakgrep.scan_diff(diff)], [leakgrep.MAX_FINDING_DIGESTS + 1])


class Validate(unittest.TestCase):
    def test_a_stated_finding_passes(self):
        self.assertEqual(findings_check.validate(NAME, finding()), [])

    def test_each_missing_statement_is_named(self):
        self.assertEqual(findings_check.validate(NAME, 'Nothing much.\n'),
                         sorted(f'missing-{c}' for c in ('static', 'method', 'exposure', 'confidence', 'limitations')))

    def test_listings_blobs_leaks_and_names_are_refused(self):
        code = '```\n' + 'int a;\n' * 20 + '```\n'
        self.assertIn('long-code', findings_check.validate(NAME, finding(code)))
        self.assertIn('blob', findings_check.validate(NAME, finding('Z' * 300 + '\n')))
        self.assertIn('leak-pattern', findings_check.validate(NAME, finding('mov eax, [ebx]\n')))
        self.assertIn('leak-pattern', findings_check.validate(NAME, finding(' '.join(['0f'] * 16) + '\n')))
        self.assertIn('too-long', findings_check.validate(NAME, finding('word ' * 40000)))
        self.assertIn('bad-name', findings_check.validate('findings/Bad Name.md', finding()))

    def test_short_fenced_formula_is_fine(self):
        self.assertEqual(findings_check.validate(NAME, finding('```\nscale = base * 2\n```\n')), [])

    def fenced(self, lines, label='text'):
        return finding(f'```{label}\n' + '\n'.join(lines) + '\n```\n')

    def test_a_long_block_of_formulas_is_not_a_listing(self):
        eqs = ['C   = scene colour (RGB) plus a clamped reflection term from the',
               '      mask and the reflection texture',
               'A   = AO factor, d = depth',
               "d'  = 1.01 x d - 0.01",
               'z   = 2 x N x F / ((N + F) - (2 x d\' - 1) x (F - N))'] + [f'v{i} = saturate(a{i} x k - b{i})' for i in range(12)]
        self.assertGreater(len(eqs), findings_check.MAX_CODE_LINES)
        self.assertEqual(findings_check.validate(NAME, self.fenced(eqs)), [])
        self.assertEqual(findings_check.validate(NAME, self.fenced(eqs, '')), [])

    def test_a_long_block_that_reads_as_a_listing_is_refused_even_with_equals_signs(self):
        eq = [f'v{i} = a{i} x k' for i in range(14)]
        for bad in ('    0x1400a1b20:  48 8b 01  1', 'mad r0.xyz, r1.xyz, cb2[1].xyz, r2.xyz', 'dcl_input v0.xyz',
                    'x = foo(a, b);', '}', '#include <vector>', '  1400a1b20 48 8b 01 48 89 5c 24 08 57'):
            self.assertIn('long-code', findings_check.validate(NAME, self.fenced(eq + [bad])), bad)

    def test_a_long_block_that_is_not_mostly_assignments_or_is_labelled_code_is_refused(self):
        self.assertIn('long-code', findings_check.validate(NAME, self.fenced(['plain words only'] * 14)))
        self.assertIn('long-code', findings_check.validate(NAME, self.fenced([f'v{i} = a{i}' for i in range(14)], 'cpp')))
        self.assertIn('long-code', findings_check.validate(
            NAME, self.fenced([f'v{i} = a{i} x k' for i in range(findings_check.MAX_FORMULA_LINES + 1)])))
        self.assertIn('long-code', findings_check.validate(NAME, finding('```text\n' + 'words\n' * 14)))


class FindingsBot(replay.ReplayBot):
    """The replay bot with the real leak scan, since the digest exemption is the point."""

    def leakgrep(self, base, head):
        diff = replay.git(self.root, 'diff', '--no-renames', '--no-color', '-U0', f'{base}...{head}')
        hits = leakgrep.scan_diff(diff)
        return bool(hits), [c for _n, _l, c in hits]


class Landing(replay.Replay):
    def setUp(self):
        super().setUp()
        self.bot = FindingsBot(self.w, config=dict(hash_wait=1, download_retry_wait=0))
        self.bot.work.mkdir(parents=True, exist_ok=True)
        self.w.bots.append(self.bot)
        self.verdict = {'leak': 'no', 'leak_evidence': [], 'verdict': 'approve', 'ground': 'none', 'why': 'ok', 'notes': []}
        self.prompts = []

        def text(prompt):
            self.prompts.append(prompt)
            return json.dumps(self.verdict)
        self.w.reviewers.text = text

    def pr(self, files=None, check='success', number=7):
        head = self.w.make_pr(number, files or {NAME: finding()})
        if check:
            self.w.ci.runs.setdefault(head, []).append(dict(
                id=900, name='check', head_sha=head, status='completed' if check != 'running' else 'in_progress',
                conclusion=None if check == 'running' else check, started_at=replay.OLD, details_url='https://ci.invalid/x'))
        return head

    def blocked(self, number=7):
        return self.w.state(self.bot, number).get('decision')['blocked']

    def test_a_clean_finding_with_a_green_check_is_squash_merged_to_the_exact_head(self):
        head = self.pr()
        log = self.w.poll(self.bot)
        self.assertTrue(self.merged(7), log)
        self.assertEqual(self.w.github.merges, [7])
        self.assertEqual(self.w.reviewers.calls and len(self.prompts), 1)
        self.assertIn('findings/*.md', self.prompts[0])
        self.assertEqual(self.w.compiled, [])
        self.assertEqual(self.w.github.prs[7]['head'], head)

    def test_the_merge_message_is_bot_written_and_credits_the_author(self):
        self.pr()
        self.w.poll(self.bot)
        call = next(a for a in self.w.github.calls if a[:2] == ['pr', 'merge'])
        self.assertEqual(call[call.index('--subject') + 1], 'Add 1 finding (#7)')
        self.assertIn('Co-authored-by: alice <4242+alice@users.noreply.github.com>', call[call.index('--body') + 1])
        self.assertIn('--squash', call)
        self.assertEqual(call[call.index('--match-head-commit') + 1], self.w.github.prs[7]['head'])

    def test_a_failed_check_job_blocks_before_any_review(self):
        self.pr(check='failure')
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.blocked(), self.prompts), (False, 'check-ci', []))

    def test_an_unfinished_check_job_waits(self):
        self.pr(check='running')
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.prompts, self.w.state(self.bot, 7).get('decision')), (False, [], None))

    def test_a_leak_hit_blocks_without_a_review(self):
        self.pr({NAME: finding('x = FUN_00401000;\n')})
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.prompts), (False, []))
        self.assertIn(self.blocked(), ('findings', 'scan'))

    def test_an_unlabelled_hex_run_is_refused_but_a_pinned_digest_is_not(self):
        self.pr({NAME: finding(f'Value `{DIGEST}`.\n')})
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.prompts), (False, []))

    def test_a_file_without_stated_evidence_is_refused_with_reasons(self):
        self.pr({NAME: 'Some facts.\n'})
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.blocked(), self.prompts), (False, 'findings', []))
        self.assertIn('missing-static', self.w.sticky(7)[0])

    def test_a_reject_verdict_blocks_with_the_notes(self):
        self.verdict.update(verdict='reject', ground='evidence', notes=['claims no method'])
        self.pr()
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.blocked()), (False, 'review'))
        self.assertIn('claims no method', self.w.sticky(7)[0])

    def test_a_review_leak_finding_with_evidence_blocks(self):
        self.verdict.update(leak='yes', leak_evidence=['copied-text'])
        self.pr()
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.blocked()), (False, 'leak'))

    def test_an_unreadable_review_never_merges(self):
        self.w.reviewers.text = lambda prompt: 'no json here'
        self.pr()
        self.w.poll(self.bot)
        self.assertFalse(self.merged(7))

    def test_a_pr_with_tools_or_tests_files_stays_tooling(self):
        self.pr({NAME: finding(), 'tools/x.py': 'print(1)\n'})
        self.w.poll(self.bot)
        self.assertEqual((self.merged(7), self.blocked(), self.prompts), (False, 'tooling', []))
        self.assertIn(pr_bot.TOOLING_LABEL, self.w.github.prs[7]['labels'])


if __name__ == '__main__':
    unittest.main()
