"""Units that instantiate std:: templates include the compiler's container headers; both screens accept them."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import contrib_screen  # noqa: E402
import leakgrep  # noqa: E402

CONTAINERS = ('vector', 'deque', 'list', 'forward_list', 'set', 'map', 'unordered_map', 'unordered_set', 'array',
              'queue', 'functional', 'bitset', 'string', 'memory', 'algorithm')


class StdHeaderTests(unittest.TestCase):
    def test_leakgrep_allows_container_headers(self):
        for name in CONTAINERS:
            self.assertFalse(leakgrep.include_problem(f'#include <{name}>'), name)

    def test_contrib_screen_allows_container_headers(self):
        for name in CONTAINERS:
            self.assertIn(name, contrib_screen.STANDARD_HEADERS)

    def test_other_angle_headers_stay_refused(self):
        for line in ('#include <windows.h.cpp>', '#include <vector.cpp>', '#include <sys/../vector>', '#include <C:/x>'):
            self.assertTrue(leakgrep.include_problem(line), line)
        self.assertNotIn('windows', contrib_screen.STANDARD_HEADERS)


if __name__ == '__main__':
    unittest.main()
