"""std:: instances are game code for ranking; Concurrency, Havok and the other middleware stay out."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools/analysis'))
import clusters  # noqa: E402


def row(*names):
    return {'member_list': [{'owner': n, 'name': ''} for n in names]}


class ClusterScopeTests(unittest.TestCase):
    def test_std_instances_are_ranked(self):
        self.assertFalse(clusters.is_middleware(row('std::vector<int>', 'std::_Tree<int>')))

    def test_other_middleware_is_excluded(self):
        for name in ('Concurrency::details::x', 'hkpWorld', 'Scaleform::GFx::Value', 'bnetSession', 'type_info'):
            self.assertTrue(clusters.is_middleware(row(name)), name)


if __name__ == '__main__':
    unittest.main()
