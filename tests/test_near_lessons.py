"""Tests for tools/near_lessons.py and the committed docs/near-tier-lessons.md. Samples are synthetic."""
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import near_lessons as nl  # noqa: E402

RULES = {5, 34, 48}

GOOD = '''## Lessons

<a id="lesson-1"></a>
**L1. Bind first.** (repeated)
Status: mapped. Found by: Sonnet, Opus. Rules: 5 agrees, 48 extends.
Symptom: a callee is missing.
Fix: bind it.
Evidence: 0x1000 +1.5 (Sonnet); 0x2000 callees (Opus).

<a id="lesson-2"></a>
**L2. A residue.** (single)
Status: open. Found by: Sol. Rules: none.
Symptom: a block is placed elsewhere.
Tried: three spellings.
Evidence: 0x3000 flat (Sol).
Still failing: 0x3000.
'''


def codes(text, rules=RULES):
    return [code for _line, code in nl.check(text, rules)]


class CheckTest(unittest.TestCase):
    def test_a_well_formed_file_passes(self):
        self.assertEqual(codes(GOOD), [])

    def test_each_defect_has_its_own_code(self):
        cases = {
            'missing-evidence': GOOD.replace('Evidence: 0x3000 flat (Sol).\n', ''),
            'evidence-entry': GOOD.replace('0x2000 callees (Opus)', '0x2000 better (Opus)'),
            'evidence-model': GOOD.replace('0x2000 callees (Opus)', '0x2000 callees (Sol)'),
            'unknown-rule': GOOD.replace('5 agrees', '99 agrees'),
            'rule-verb': GOOD.replace('5 agrees', '5 likes'),
            'status': GOOD.replace('Status: open.', 'Status: maybe.'),
            'found-by': GOOD.replace('Found by: Sol.', 'Found by: Gemini.'),
            'confidence': GOOD.replace('(single)', '(sure)'),
            'id-order': GOOD.replace('lesson-2', 'lesson-3').replace('**L2.', '**L3.'),
            'repeated-needs-two-functions': GOOD.replace('0x2000 callees (Opus)', '0x1000 callees (Opus)'),
            'mapped-needs-rule': GOOD.replace('Rules: 5 agrees, 48 extends.', 'Rules: none.'),
            'contradicted-needs-verb': GOOD.replace('Status: mapped.', 'Status: contradicted.'),
            'verb-needs-status': GOOD.replace('48 extends', '48 contradicts'),
            'candidate-has-rule': GOOD.replace('Status: mapped.', 'Status: candidate.'),
            'missing-symptom': GOOD.replace('Symptom: a callee is missing.\n', ''),
            'missing-fix': GOOD.replace('Fix: bind it.\n', ''),
            'still-failing': GOOD.replace('Still failing: 0x3000.', 'Still failing: the loader.'),
            'rules-line': GOOD.replace(' Rules: none.', ''),
        }
        for code, text in cases.items():
            self.assertIn(code, codes(text), code)

    def test_a_contradicted_lesson_needs_the_verb_and_passes_with_it(self):
        text = GOOD.replace('Status: mapped.', 'Status: contradicted.').replace('48 extends', '48 contradicts')
        self.assertEqual(codes(text), [])

    def test_an_open_or_contested_lesson_may_cite_rules(self):
        text = GOOD.replace('Status: open. Found by: Sol. Rules: none.', 'Status: contested. Found by: Sol. Rules: 34 qualifies.')
        self.assertEqual(codes(text), [])

    def test_leak_patterns_are_refused_with_codes_only(self):
        findings = nl.check(GOOD + 'mov rax, qword ptr [rbx + 0x8]\n', RULES)
        self.assertIn('leak-asm-mnemonic', [code for _l, code in findings])
        for line, code in findings:
            self.assertIsInstance(line, int)
            self.assertNotIn('rax', code)

    def test_a_file_with_no_lessons_is_refused(self):
        self.assertEqual(codes('# nothing\n'), ['no-lessons'])


class SummaryTest(unittest.TestCase):
    def test_counts(self):
        text = nl.summary(nl.parse(GOOD))
        self.assertIn('2 lessons', text)
        self.assertIn('status: mapped 1, candidate 0, contradicted 0, contested 0, open 1', text)
        self.assertIn('confidence: repeated 1, single 1, reported 0', text)
        self.assertIn('found by: Sonnet 1, Sol 1, Opus 1', text)
        self.assertIn('5: L1 agrees', text)


class CommittedFileTest(unittest.TestCase):
    def test_the_committed_lessons_pass_the_check(self):
        done = subprocess.run([sys.executable, str(ROOT / 'tools/near_lessons.py')], capture_output=True, text=True, cwd=ROOT)
        self.assertEqual(done.returncode, 0, done.stdout + done.stderr)

    def test_the_committed_lessons_cite_only_cookbook_rules(self):
        rules = nl.cookbook_rules((ROOT / nl.COOKBOOK).read_text(encoding='utf-8'))
        self.assertGreaterEqual(len(rules), 60)
        self.assertEqual([c for _l, c in nl.check((ROOT / nl.LESSONS).read_text(encoding='utf-8'), rules) if c == 'unknown-rule'], [])

    def test_every_lesson_has_a_distinct_title_and_every_status_is_used_correctly(self):
        lessons = nl.parse((ROOT / nl.LESSONS).read_text(encoding='utf-8'))
        titles = [lesson['title'] for lesson in lessons]
        self.assertEqual(len(titles), len(set(titles)))
        statuses = {nl.status_line(lesson['fields']['Status'])[0] for lesson in lessons}
        self.assertTrue(statuses <= set(nl.STATUS))
        self.assertIn('contradicted', statuses)

    def test_drafters_are_pointed_at_the_lessons(self):
        for doc in ('docs/matching-cookbook.md', 'docs/drafter-toolkit.md', 'docs/drafter-card.md', 'docs/contributor-card.md'):
            self.assertIn('near-tier-lessons.md', (ROOT / doc).read_text(encoding='utf-8'), doc)

    def test_the_toolkit_describes_the_reflection_and_fold_loop(self):
        text = (ROOT / 'docs/drafter-toolkit.md').read_text(encoding='utf-8')
        for needle in ('Reflections and lessons', 'tools/near_lessons.py', 'integration step folds'):
            self.assertIn(needle, text)


if __name__ == '__main__':
    unittest.main()
