"""The per-function verdict names in the PR bot's sticky comment: classification, strikes, table and docs."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import types
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import pr_bot  # noqa: E402
import verdicts  # noqa: E402

HEAD = 'a' * 40


def decision(verdicts_, **extra):
    return dict(dict(blocked=None, merge=True), verdicts=verdicts_, **extra)


class Classification(unittest.TestCase):
    def kind(self, verdict, **extra):
        return verdicts.classify(decision({0x10: verdict}, **extra), 0x10)

    def test_every_internal_verdict_has_a_kind_with_a_strike_and_a_next_step(self):
        for verdict in ('matched', 'debt', 'blocked', 'fail:host1', 'fail:host2', 'fail:review', 'fail:precheck',
                        'fail:missing', 'fail:record'):
            kind = self.kind(verdict)
            self.assertIn(kind, verdicts.KINDS)
            meaning, strike, nxt = verdicts.KINDS[kind]
            self.assertTrue(meaning and strike and nxt)

    def test_a_byte_difference_on_a_host_is_a_mismatch(self):
        for category in ('bytes differ', 'reference'):
            for host in ('host1', 'host2'):
                why = {0x10: {host: category}}
                self.assertEqual(self.kind('fail:' + host, host_why=why), 'mismatch')

    def test_a_host_that_compared_nothing_is_a_compile_error(self):
        for category in ('compile', 'include', 'unbound'):
            self.assertEqual(self.kind('fail:host2', host_why={0x10: {'host2': category}}), 'compile_error')
            self.assertEqual(self.kind('fail:host1', host_why={'16': {'host1': category}}), 'compile_error')

    def test_a_missing_host_result_is_ours_and_needs_review(self):
        self.assertEqual(self.kind('fail:host1', host_why={0x10: {'host1': 'missing'}}), 'needs_review')
        self.assertEqual(self.kind('fail:missing'), 'needs_review')
        self.assertEqual(self.kind('fail:record'), 'needs_review')

    def test_a_mechanical_finding_on_a_function_both_hosts_passed_is_unfit_unless_it_names_a_rule(self):
        self.assertEqual(self.kind('fail:precheck', pre={0x10: ['reconstruction/a/B.cpp: the unit is not the pushed one']}),
                         'unfit')
        self.assertEqual(self.kind('fail:precheck', pre={0x10: ['reconstruction/a/B.cpp:3: R38 pragma: remove it']}),
                         'refused_rules')

    def test_a_rejected_review_is_its_own_kind_and_debt_and_holds_are_kept_apart(self):
        self.assertEqual(self.kind('fail:review'), 'review_rejected')
        self.assertEqual(self.kind('debt'), 'debt')
        self.assertEqual(self.kind('blocked', blocked='leak'), 'held')
        self.assertEqual(self.kind('matched'), 'matched')


class Strikes(unittest.TestCase):
    def test_only_a_byte_difference_counts_toward_strikes_and_a_compile_error_is_recorded_as_none_today(self):
        self.assertTrue(verdicts.KINDS['mismatch'][1].startswith('counts'))
        self.assertIn('no ledger entry', verdicts.KINDS['compile_error'][1])
        for kind in ('unfit', 'needs_review', 'review_rejected', 'debt', 'held', 'matched'):
            self.assertEqual(verdicts.KINDS[kind][1], 'none')

    def test_a_rule_refusal_counts_only_when_the_rule_existed_at_the_base(self):
        d = decision({0x10: 'fail:precheck'}, pre={0x10: ['f.cpp:3: R39 decompiler-type: undefined']},
                     base_rules=['R1', 'R39'])
        self.assertTrue(verdicts.strike_text('refused_rules', d, 0x10).startswith('counts: R39'))
        d['base_rules'] = ['R1', 'R38']
        self.assertTrue(verdicts.strike_text('refused_rules', d, 0x10).startswith('none: R39 is newer'))
        del d['base_rules']
        self.assertTrue(verdicts.strike_text('refused_rules', d, 0x10).startswith('none:'))

    def test_the_rules_in_force_are_read_from_the_rule_rows_of_the_document(self):
        text = '| R1 | match | a |\n| R38 | match | b |\nR40 in prose is not a row\n| R39 | match | c |\n'
        self.assertEqual(verdicts.rules_in_force(text), ['R1', 'R38', 'R39'])
        self.assertEqual(verdicts.rules_in_force(None), [])
        self.assertEqual(verdicts.rules_in(['x.cpp:1: R38 pragma: y', 'x.cpp:2: R40 comment: z', 'R3 is not one']),
                         ['R38', 'R40'])


class Comment(unittest.TestCase):
    def test_the_sticky_comment_ends_with_a_row_for_each_function_that_was_not_accepted(self):
        d = decision({0x10: 'matched', 0x20: 'fail:host1', 0x30: 'fail:host2', 0x40: 'fail:missing', 0x50: 'debt'},
                     host_why={0x20: {'host1': 'bytes differ'}, 0x30: {'host2': 'compile'}})
        body = pr_bot.comment_body(HEAD, d)
        self.assertIn('Merged and recorded: 0x10.', body)
        rows = [line for line in body.splitlines() if line.startswith('| 0x')]
        self.assertEqual([r.split('|')[1].strip() for r in rows], ['0x20', '0x30', '0x40'])
        self.assertEqual([r.split('|')[2].strip() for r in rows], ['`mismatch`', '`compile_error`', '`needs_review`'])
        self.assertNotIn('0x50', body)
        self.assertNotIn('0x10 |', body)

    def test_the_existing_lines_a_contributor_agent_reads_are_unchanged(self):
        d = decision({0x20: 'fail:host1'}, host_why={0x20: {'host1': 'bytes differ'}})
        body = pr_bot.comment_body(HEAD, d)
        self.assertIn('Not accepted yet (they stay drafted; push a fix and the bot re-checks the new head):', body)
        self.assertIn('- 0x20: did not byte-match on the CI hash check (bytes differ)', body)

    def test_a_pr_that_merged_everything_gets_no_table(self):
        self.assertNotIn('| Function |', pr_bot.comment_body(HEAD, decision({0x10: 'matched'})))

    def test_a_long_list_is_cut_and_counted_by_kind(self):
        d = decision({r: 'fail:missing' for r in range(1, 31)})
        table = verdicts.table_lines(d)
        self.assertEqual(sum(line.startswith('| 0x') for line in table), verdicts.SHOWN)
        self.assertIn('and 10 more', table[-1])
        self.assertIn('`needs_review` 10', table[-1])

    def test_a_pr_wide_hold_for_a_leak_gets_no_table(self):
        d = dict(blocked='leak', leak_source='leakgrep', merge=False, verdicts={0x10: 'blocked'})
        self.assertNotIn('| Function |', pr_bot.comment_body(HEAD, d, ['R1']))

    def test_the_lint_hold_says_whether_a_rule_refusal_is_a_strike(self):
        found = ['reconstruction/a/B.cpp:3: R38 pragma: `#pragma optimize` steers code generation; remove it']
        counted = pr_bot.lint_rejection(found, base_rules=['R38'])
        self.assertIn('Verdict `refused_rules`', counted)
        self.assertIn('this counts toward your strikes', counted)
        free = pr_bot.lint_rejection(found, base_rules=['R1'])
        self.assertIn('no strike: the rule is newer than your PR\'s base', free)
        self.assertNotIn('Verdict', pr_bot.lint_rejection(['reconstruction/a/B.cpp: header is missing a line']))


class BotMethods(unittest.TestCase):
    def test_the_hold_before_any_compile_includes_the_r38_to_r40_refusals_the_hash_job_makes(self):
        with tempfile.TemporaryDirectory() as tmp:
            tree = Path(tmp)
            (tree / 'builds').mkdir()
            (tree / 'builds/target.json').write_text(json.dumps(dict(build_id='sse-steam-1-7-104')))
            unit = tree / 'reconstruction/area'
            unit.mkdir(parents=True)
            (unit / 'W.cpp').write_text('// 0x1000 W::f\n#pragma optimize("", off)\nint f() { return 0; }\n')
            bot = types.SimpleNamespace(tree=tree)
            found = pr_bot.Bot.lint_problems(bot, [dict(filename='reconstruction/area/W.cpp', status='added')])
        self.assertTrue(any('R38' in line and 'W.cpp' in line for line in found), found)

    def test_the_rules_at_the_base_come_from_the_document_at_that_revision(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            subprocess.run(['git', 'init', '-q'], cwd=root, check=True)
            (root / 'docs').mkdir()
            (root / 'docs/code-rules.md').write_text('| R1 | match | a |\n| R38 | match | b |\n')
            subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', 'add', '.'], cwd=root, check=True)
            subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-qm', 'rules'], cwd=root, check=True)
            rev = subprocess.run(['git', 'rev-parse', 'HEAD'], cwd=root, capture_output=True, text=True, check=True).stdout.strip()

            def run(argv, check=True, cwd=None):
                return subprocess.run(argv, cwd=cwd or root, capture_output=True, check=check)
            bot = types.SimpleNamespace(root=root, run=run)
            self.assertEqual(pr_bot.Bot.base_rules(bot, rev), ['R1', 'R38'])
            self.assertEqual(pr_bot.Bot.base_rules(bot, 'f' * 40), [])
            self.assertEqual(pr_bot.Bot.base_rules(bot, None), [])


class Documentation(unittest.TestCase):
    def test_the_contributor_card_carries_the_generated_table(self):
        text = (ROOT / 'docs/contributor-card.md').read_text()
        start, end = (text.index(m) for m in verdicts.MARKERS)
        self.assertEqual(text[start + len(verdicts.MARKERS[0]):end].strip(), verdicts.doc_table())


if __name__ == '__main__':
    unittest.main()
