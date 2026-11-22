import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import duplicate_rva  # noqa: E402

# The count may only go down. Lower it when a cleanup lands; raising it means a new unit repeats
# an RVA that another unit already carries (keep the unit its accepted record binds).
CEILING = 115


def write(root, name, text):
    path = Path(root) / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding='utf-8', newline='\n')


class DuplicateRva(unittest.TestCase):
    def test_same_rva_in_two_units_is_reported(self):
        with tempfile.TemporaryDirectory() as tmp:
            write(tmp, 'reconstruction/a/A.cpp', '// 0x1000 A::F\n#include "A.h"\n')
            write(tmp, 'reconstruction/b/B.cpp', '// 0x1000 B::G\n// 0x2000 B::H\n')
            write(tmp, 'reconstruction/generated/G.cpp', '// 0x2000 G::H\n')
            found = duplicate_rva.duplicates(tmp)
        self.assertEqual({0x1000: ['reconstruction/a/A.cpp', 'reconstruction/b/B.cpp']}, found)

    def test_one_unit_naming_an_rva_twice_is_not_a_cross_unit_duplicate(self):
        with tempfile.TemporaryDirectory() as tmp:
            write(tmp, 'reconstruction/a/A.cpp', '// 0x1000 A::F\n// 0x1000 A::F\n')
            self.assertEqual({}, duplicate_rva.duplicates(tmp))

    def test_tree_duplicates_do_not_grow(self):
        found = duplicate_rva.duplicates()
        self.assertLessEqual(len(found), CEILING, 'new duplicated RVAs: ' + ', '.join(
            f'0x{rva:x}' for rva in list(found)[:10]))


if __name__ == '__main__':
    unittest.main()
