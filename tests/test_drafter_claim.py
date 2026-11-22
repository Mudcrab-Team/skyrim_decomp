"""The PR summary's drafter line and RVA list, and the backfill that matches them to records."""
from datetime import datetime, timezone
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import backfill_drafter_claims as backfill
import drafter_claim

HINT = ' (a person, and the AI model if one wrote code)'


class FromBody(unittest.TestCase):
    def test_the_model_part_without_the_name_or_template_hint(self):
        for line, claim in [
                ('- Drafted by: aivv73, assisted by gpt-6.2-sol' + HINT, 'gpt-6.2-sol'),
                ('- Drafted by: not stated' + HINT, 'not stated'),
                ('- Drafted by: Hinkiii, assisted by claude-sonnet-5-5.', 'claude-sonnet-5-5'),
                ('- Drafted by: opencode-go/deepseek-v4.1-flash' + HINT, 'opencode-go/deepseek-v4.1-flash'),
                ('- Drafted by: a, assisted by gpt-6.2-astra. Batch claims #370.', 'gpt-6.2-astra')]:
            with self.subTest(line=line):
                self.assertEqual(drafter_claim.from_body('intro\n' + line + '\n- next'), claim)

    def test_no_line_is_no_claim(self):
        self.assertIsNone(drafter_claim.from_body('no provenance section'))
        self.assertIsNone(drafter_claim.from_body(None))

    def test_rvas_come_from_the_table_else_the_title(self):
        body = '| RVA | name |\n|---|---|\n| `0x1A00` | A |\n| `0x2b00` | B |\n'
        self.assertEqual(drafter_claim.rvas_from_body(body, 'x (0x9999)'), [0x1a00, 0x2b00])
        self.assertEqual(drafter_claim.rvas_from_body('', 'Reconstruct X (0x1a00, 0x2b00)'), [0x1a00, 0x2b00])


class Pick(unittest.TestCase):
    def prs(self):
        body = '| `0x10` | f |\n- Drafted by: a, assisted by claude-opus-5-5\n'
        return [{'number': 1, 'author': {'login': 'Alice'}, 'mergedAt': '2026-11-18T10:00:00Z', 'body': body, 'title': ''},
                {'number': 2, 'author': {'login': 'Alice'}, 'mergedAt': '2026-11-20T10:00:00Z', 'body': body.replace('opus', 'sonnet'), 'title': ''},
                {'number': 3, 'author': {'login': 'Bob'}, 'mergedAt': '2026-11-19T10:00:00Z', 'body': body, 'title': ''}]

    def at(self, day, hour=12):
        return datetime(2026, 11, day, hour, tzinfo=timezone.utc)

    def test_the_submitters_latest_pr_merged_by_the_record_time(self):
        index = backfill.index_prs(self.prs())
        self.assertEqual(backfill.pick(index, 0x10, 'alice', self.at(19))[2], 1)
        self.assertEqual(backfill.pick(index, 0x10, 'alice', self.at(21))[2], 2)

    def test_another_authors_pr_or_a_later_one_is_not_used(self):
        index = backfill.index_prs(self.prs())
        self.assertIsNone(backfill.pick(index, 0x10, 'carol', self.at(21)))
        self.assertIsNone(backfill.pick(index, 0x10, 'alice', self.at(17)))
        self.assertIsNone(backfill.pick(index, 0x10, None, self.at(21)))
        self.assertIsNone(backfill.pick(index, 0x11, 'alice', self.at(21)))


if __name__ == '__main__':
    unittest.main()
