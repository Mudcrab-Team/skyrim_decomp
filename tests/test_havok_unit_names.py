"""Unit-path patterns accept Havok's lowercase class prefixes and still refuse arbitrary lowercase names."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import contrib  # noqa: E402
import contrib_publication  # noqa: E402
import contrib_validation  # noqa: E402
import lint_reconstruction as lint  # noqa: E402

PATTERNS = [contrib.UNIT_PATH, contrib_publication.UNIT, contrib_validation.UNIT, lint.SOURCE]
GOOD = ['hkReferencedObject', 'hkpWorld', 'hkbBehaviorGraph', 'hkaSkeleton', 'hkxScene', 'Widget']
BAD = ['foo', 'hkfoo', 'hkabcDef', 'hk', 'widget', 'xhkWorld']


class HavokUnitNames(unittest.TestCase):
    def test_havok_prefixes_pass(self):
        for pat in PATTERNS:
            for cls in GOOD:
                for ext in ('h', 'cpp'):
                    m = pat.fullmatch(f'reconstruction/bshavok/{cls}.{ext}')
                    self.assertIsNotNone(m, (pat.pattern, cls))
                    self.assertEqual(m.group(2), cls)

    def test_arbitrary_lowercase_refused(self):
        for pat in PATTERNS:
            for cls in BAD:
                self.assertIsNone(pat.fullmatch(f'reconstruction/bshavok/{cls}.cpp'), (pat.pattern, cls))

    def test_shared_header_include(self):
        self.assertIsNotNone(lint.SHARED_HEADER.fullmatch('../bshavok/hkpWorld.h'))
        self.assertIsNone(lint.SHARED_HEADER.fullmatch('../bshavok/foo.h'))


if __name__ == '__main__':
    unittest.main()
