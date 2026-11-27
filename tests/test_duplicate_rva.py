import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import duplicate_rva  # noqa: E402

# The count may only go down. Lower it when a cleanup lands; raising it means a new unit repeats
# an RVA that another unit already carries (keep the unit its accepted record binds).
CEILING = 82


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


def git(root, *args):
    return subprocess.run(['git', '-C', str(root), '-c', 'user.name=t', '-c', 'user.email=t@example.invalid',
                           '-c', 'commit.gpgsign=false', *args], capture_output=True, text=True, check=True).stdout.strip()


class NewDuplicates(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        git(self.root, 'init', '-q', '-b', 'main')
        write(self.root, 'reconstruction/a/A.cpp', '// 0x1000 A::F\n')
        write(self.root, 'reconstruction/b/B.cpp', '// 0x2000 B::G\n')
        write(self.root, 'reconstruction/b/C.cpp', '// 0x2000 C::G\n')
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-q', '-m', 'base')
        self.base = git(self.root, 'rev-parse', 'HEAD')

    def tearDown(self):
        self.tmp.cleanup()

    def head(self):
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-q', '-m', 'head')
        return git(self.root, 'rev-parse', 'HEAD')

    def test_a_unit_repeating_an_rva_is_new(self):
        write(self.root, 'reconstruction/c/D.cpp', '// 0x1000 D::F\n')
        found = duplicate_rva.new_duplicates(self.root, self.base, self.head())
        self.assertEqual({0x1000: ['reconstruction/a/A.cpp', 'reconstruction/c/D.cpp']}, found)

    def test_a_third_unit_on_an_old_duplicate_is_new(self):
        write(self.root, 'reconstruction/c/D.cpp', '// 0x2000 D::G\n')
        self.assertEqual([0x2000], list(duplicate_rva.new_duplicates(self.root, self.base, self.head())))

    def test_an_old_duplicate_and_generated_units_are_not_new(self):
        write(self.root, 'reconstruction/generated/G.cpp', '// 0x1000 G::F\n')
        write(self.root, 'reconstruction/c/E.cpp', '// 0x3000 E::F\n')
        self.assertEqual({}, duplicate_rva.new_duplicates(self.root, self.base, self.head()))

    def test_deleting_a_duplicate_is_not_new(self):
        git(self.root, 'rm', '-q', 'reconstruction/b/C.cpp')
        self.assertEqual({}, duplicate_rva.new_duplicates(self.root, self.base, self.head()))


class AgainstMain(unittest.TestCase):
    """A PR checked on an older base can repeat an RVA that main gained afterwards."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        git(self.root, 'init', '-q', '-b', 'main')
        write(self.root, 'reconstruction/a/A.cpp', '// 0x1000 A::F\n')
        git(self.root, 'add', '.')
        git(self.root, 'commit', '-q', '-m', 'base')
        git(self.root, 'checkout', '-q', '-b', 'pr')

    def tearDown(self):
        self.tmp.cleanup()

    def commit(self, branch, message='c'):
        git(self.root, 'add', '-A')
        git(self.root, 'commit', '-q', '-m', message)
        return git(self.root, 'rev-parse', branch)

    def land_on_main(self, name, text):
        git(self.root, 'checkout', '-q', 'main')
        write(self.root, name, text)
        self.commit('main')
        git(self.root, 'checkout', '-q', 'pr')

    def test_a_unit_main_gained_for_the_same_rva_is_a_repeat(self):
        write(self.root, 'reconstruction/std/S.cpp', '// 0x2000 S::F\n')
        head = self.commit('pr')
        self.land_on_main('reconstruction/b/B.cpp', '// 0x2000 B::F\n')
        found = duplicate_rva.against_main(self.root, 'main', head)
        self.assertEqual({0x2000: ['reconstruction/b/B.cpp', 'reconstruction/std/S.cpp']}, found)

    def test_unrelated_units_and_an_unchanged_old_duplicate_are_not_repeats(self):
        write(self.root, 'reconstruction/std/S.cpp', '// 0x2000 S::F\n')
        head = self.commit('pr')
        self.land_on_main('reconstruction/b/B.cpp', '// 0x3000 B::F\n')
        self.assertEqual({}, duplicate_rva.against_main(self.root, 'main', head))

    def test_replacing_the_unit_main_holds_is_not_a_repeat(self):
        git(self.root, 'rm', '-q', 'reconstruction/a/A.cpp')
        write(self.root, 'reconstruction/c/C.cpp', '// 0x1000 C::F\n')
        head = self.commit('pr')
        self.assertEqual({}, duplicate_rva.against_main(self.root, 'main', head))

    def test_marked_lists_every_rva_with_its_units(self):
        self.assertEqual({0x1000: ['reconstruction/a/A.cpp']}, duplicate_rva.marked(self.root))


if __name__ == '__main__':
    unittest.main()
