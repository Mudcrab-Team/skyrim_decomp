"""Cookbook ranking: the committed section is current, the format is stable and hits are collected."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]
import cookbook_rank

COOKBOOK = """# Cookbook

## Control flow

<a id="rule-1"></a>
**1. First | cause: fix it.** (high)
Text mentioning 0x999.

Evidence: 0x10, 0x20.
Still failing: 0x30.

<a id="rule-2"></a>
**2. Second cause that
wraps.** (low)
Body.

Still failing: 0x40, 0x50, 0x60.

<a id="rule-3"></a>
**3. Third.** (low)
Body.

## Later

**A. Not a rule.**
Evidence: 0x70.
"""


def repo(tmp, matched=(0x10, 0x40, 0x50)):
    tmp = Path(tmp)
    (tmp / 'docs').mkdir()
    (tmp / 'data').mkdir()
    (tmp / 'reconstruction' / 'a').mkdir(parents=True)
    (tmp / 'docs' / 'matching-cookbook.md').write_text(COOKBOOK)
    (tmp / 'data' / 'progress.json').write_text(json.dumps(
        {'functions': [{'rva': r, 'status': 'matched'} for r in matched] + [{'rva': 0x99, 'status': 'draft'}]}))
    return tmp


class RankTest(unittest.TestCase):
    def test_committed_section_is_current(self):
        self.assertEqual(cookbook_rank.main(['--check']), 0,
                         'run python3 tools/cookbook_rank.py and commit docs/matching-cookbook.md')

    def test_every_rule_is_ranked_and_linked(self):
        text = (ROOT / 'docs' / 'matching-cookbook.md').read_text()
        rules = cookbook_rank.parse_rules(text)
        self.assertEqual(sorted(rules), list(range(1, max(rules) + 1)))
        for n in rules:
            self.assertIn(f'<a id="rule-{n}"></a>', text)
            self.assertIn(f'](#rule-{n}) |', text)

    def test_parse_and_order(self):
        rules = cookbook_rank.parse_rules(COOKBOOK)
        self.assertEqual(sorted(rules), [1, 2, 3])
        self.assertEqual(rules[2]['title'], 'Second cause that wraps')
        self.assertEqual(rules[1]['evidence'], {'0x10', '0x20'})
        rows = cookbook_rank.ranking(rules, {'0x77': [3]})
        self.assertEqual([r[1] for r in rows], [1, 2, 3])
        self.assertEqual(rows[0][3:], (2, 1))
        self.assertEqual(rows[1][3:], (0, 3))
        self.assertEqual(rows[2][3:], (1, 0))

    def test_hit_for_a_cited_function_is_not_double_counted(self):
        rules = cookbook_rank.parse_rules(COOKBOOK)
        rows = {r[1]: r for r in cookbook_rank.ranking(rules, {'0x10': [1], '0x30': [1]})}
        self.assertEqual(rows[1][3:], (3, 0))

    def test_rewrite_is_idempotent_and_keeps_the_rest(self):
        once = cookbook_rank.rendered(COOKBOOK, {})
        self.assertEqual(cookbook_rank.rendered(once, {}), once)
        self.assertIn(cookbook_rank.BEGIN, once)
        self.assertTrue(once.replace(once[once.index(cookbook_rank.BEGIN):once.index(cookbook_rank.END)
                                          + len(cookbook_rank.END) + 2], '') == COOKBOOK)

    def test_collect_counts_only_matched_functions(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = repo(tmp)
            task = root / 'tasks' / 't1'
            task.mkdir(parents=True)
            (task / 'task.json').write_text(json.dumps({'functions': [{'rva': 0x40}, {'rva': 0x99}]}))
            (task / 'attempts.jsonl').write_text(
                json.dumps({'exit': 1, 'cookbook_rules': [3]}) + '\n'
                + json.dumps({'exit': 0, 'cookbook_rules': [2, 9]}) + '\n')
            (root / 'reconstruction' / 'a' / 'A.cpp').write_text(
                '// Source exposure: none\n// Cookbook: 0x50 1, 2\n// Cookbook: 0x99 1\n\nint x;\n')
            self.assertEqual(cookbook_rank.main(['--repo', str(root), '--collect', str(root / 'tasks')]), 0)
            hits = json.loads((root / 'docs' / 'cookbook-hits.json').read_text())
            self.assertEqual(hits, {'0x40': [2], '0x50': [1, 2]})
            self.assertEqual(cookbook_rank.main(['--repo', str(root), '--check']), 0)
            before = (root / 'docs' / 'cookbook-hits.json').read_text()
            cookbook_rank.main(['--repo', str(root), '--collect', str(root / 'tasks')])
            self.assertEqual((root / 'docs' / 'cookbook-hits.json').read_text(), before)

    def test_header_line_is_free_of_the_header_budget(self):
        from lint_reconstruction import counted_header_lines
        header = '// one\n// Cookbook: 0x50 1, 2\n// Cookbook: 0x51 48\n'
        self.assertEqual(counted_header_lines(header), ['// one'])

    def test_check_fails_when_stale(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = repo(tmp)
            self.assertEqual(cookbook_rank.main(['--repo', str(root)]), 0)
            self.assertEqual(cookbook_rank.main(['--repo', str(root), '--check']), 0)
            path = root / 'docs' / 'matching-cookbook.md'
            path.write_text(path.read_text().replace('Evidence: 0x10, 0x20.', 'Evidence: 0x10.'))
            self.assertEqual(cookbook_rank.main(['--repo', str(root), '--check']), 1)


if __name__ == '__main__':
    unittest.main()
