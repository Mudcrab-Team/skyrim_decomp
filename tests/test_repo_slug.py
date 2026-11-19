import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import repo_slug  # noqa: E402


class RepoSlugTests(unittest.TestCase):
    def test_env_overrides_and_falls_back(self):
        self.assertEqual(repo_slug.current_slug({'GITHUB_REPOSITORY': 'a/b'}), 'a/b')
        self.assertEqual(repo_slug.current_slug({}), repo_slug.DEFAULT_SLUG)
        self.assertEqual(repo_slug.current_slug({'GITHUB_REPOSITORY': 'bad slug/x'}), repo_slug.DEFAULT_SLUG)

    def test_legacy_name_is_an_alias(self):
        self.assertTrue(repo_slug.same_repo('awarebayes/skyrim_decomp', 'Mudcrab-Team/skyrim_decomp'))
        self.assertTrue(repo_slug.same_repo('AWAREBAYES/skyrim_decomp.git', 'mudcrab-team/skyrim_decomp'))
        self.assertFalse(repo_slug.same_repo('someone/skyrim_decomp', 'Mudcrab-Team/skyrim_decomp'))
        self.assertFalse(repo_slug.same_repo('', ''))

    def test_maintainer_is_a_person(self):
        self.assertNotEqual(repo_slug.MAINTAINER_LOGIN.lower(), repo_slug.DEFAULT_SLUG.split('/')[0].lower())


if __name__ == '__main__':
    unittest.main()
