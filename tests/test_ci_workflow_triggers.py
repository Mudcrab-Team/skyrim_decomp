import unittest
from pathlib import Path

WORKFLOWS = Path(__file__).resolve().parents[1] / '.github/workflows'


class PrCheckWorkflow(unittest.TestCase):
    text = (WORKFLOWS / 'pr-check.yml').read_text()

    def test_untrusted_compile_runs_under_pull_request_with_a_read_only_token(self):
        self.assertIn('\n  pull_request:', self.text)
        self.assertNotIn('pull_request_target', self.text)
        self.assertIn('permissions:\n  contents: read', self.text)
        self.assertNotIn('secrets.', self.text)

    def test_trusted_tools_come_from_the_base_revision(self):
        self.assertEqual(self.text.count('ref: ${{ github.event.pull_request.base.sha }}'), 4)

    def test_both_jobs_exist_and_hash_blocks_only_through_regress(self):
        self.assertIn('\n  scope:', self.text)
        self.assertIn('\n  hash:', self.text)
        self.assertIn('ci_target_hash_check.py regress', self.text)
        self.assertIn('python tools/scope_check.py --base "$BASE_SHA" --head "$PR_HEAD"', self.text)

    def test_the_mapping_lane_replaces_scope_and_hash_for_a_mapping_only_pr(self):
        self.assertIn('\n  mapping:', self.text)
        self.assertIn('python tools/mapping_check.py --base', self.text)
        self.assertEqual(self.text.count("if: needs.shape.outputs.mapping != 'true'"), 2)
        self.assertEqual(self.text.count("if: needs.shape.outputs.mapping == 'true'"), 1)
        self.assertNotIn('secrets.', self.text)


if __name__ == '__main__':
    unittest.main()
