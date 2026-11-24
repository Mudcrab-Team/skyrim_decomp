import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import sibling_decls as sd  # noqa: E402

BASE_H = """\
#ifndef BASE_H
#define BASE_H
#pragma pack(push, 4)
class Base
{
  public:
    int a;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Base) == 4);
#endif
"""
DERIVED_H = """\
#include "Base.h"
class Derived : public Base
{
  public:
    Holder h;
    Other* p;
    virtual void Run();
};
"""
LAYOUT_H = """\
template <class T> class Holder
{
  public:
    T* m_pObject;
    Holder() FNV64_SPEC;
};
typedef Base BaseAlias;
enum Mode { kA, kB };
extern Base DAT_01234567;
inline unsigned int Twice(unsigned int v)
{
    return v * 2;
}
"""


def make_clone(root):
    (root / 'include').mkdir(parents=True)
    (root / 'include/Base.h').write_text(BASE_H)
    (root / 'include/Derived.h').write_text(DERIVED_H)
    (root / 'include/layout_support.h').write_text(LAYOUT_H)
    return sd.DeclIndex(root, 'SIBLING(toy@1, CC0-1.0)')


class Index(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.ix = make_clone(Path(self.tmp.name))

    def tearDown(self):
        self.tmp.cleanup()

    def test_kinds_are_classified(self):
        kinds = {n: ds[0].kind for n, ds in self.ix.by_name.items()}
        self.assertEqual(kinds['Base'], 'class')
        self.assertEqual(kinds['Holder'], 'class')
        self.assertEqual(kinds['BaseAlias'], 'typedef')
        self.assertEqual(kinds['Mode'], 'enum')
        self.assertEqual(kinds['DAT_01234567'], 'extern')
        self.assertEqual(kinds['Twice'], 'function')

    def test_layout_checks_and_pragmas_are_not_part_of_a_definition(self):
        text = sd.strip_noise(self.ix.lookup('Base').text)
        self.assertNotIn('FNV_STATIC_ASSERT', text)
        self.assertNotIn('pragma', text)

    def test_closure_puts_bases_and_by_value_members_first(self):
        names = [d.name for d, _, _ in sd.closure([self.ix], 'Derived')]
        self.assertEqual(names[-1], 'Derived')
        self.assertLess(names.index('Base'), names.index('Derived'))
        self.assertLess(names.index('Holder'), names.index('Derived'))

    def test_closure_skips_names_the_unit_has(self):
        names = [d.name for d, _, _ in sd.closure([self.ix], 'Derived', have={'Base'})]
        self.assertNotIn('Base', names)

    def test_a_definition_that_needs_a_sibling_macro_ranks_last(self):
        other = Path(self.tmp.name) / 'other'
        (other / 'include').mkdir(parents=True)
        (other / 'include/Holder.h').write_text('template <class T> class Holder\n{\n  public:\n    T* p;\n};\n')
        ix2 = sd.DeclIndex(other, 'SIBLING(toy@2, CC0-1.0)')
        picked = sd.closure([self.ix, ix2], 'Holder')[0]
        self.assertEqual(picked[1], 'SIBLING(toy@2, CC0-1.0)')


class Editing(unittest.TestCase):
    def test_block_goes_before_its_first_user_and_after_its_needs(self):
        h = '#pragma once\n\nclass Base\n{\n};\n\nclass User\n{\n  public:\n    Mid* m;\n};\n'
        out = sd.insert_block(h, 'class Mid : public Base\n{\n};', 'Mid', ['Base'])
        self.assertLess(out.index('class Base'), out.index('class Mid'))
        self.assertLess(out.index('class Mid'), out.index('class User'))

    def test_reorder_moves_a_base_ahead_of_its_derived_class(self):
        h = '#pragma once\n\nclass Derived : public Base\n{\n};\n\nclass Base\n{\n};\n'
        out = sd.reorder_definitions(h)
        self.assertLess(out.index('class Base'), out.index('class Derived'))
        self.assertIn('struct Derived;', out)

    def test_remove_duplicate_definition_keeps_the_first(self):
        h = '#pragma once\nclass A\n{\n  int x;\n};\nclass A\n{\n  int y;\n};\n'
        out = sd.remove_later_definitions(h, 'A')
        self.assertIn('int x', out)
        self.assertNotIn('int y', out)

    def test_typedef_and_forward_declaration_are_removed(self):
        h = '#pragma once\ntypedef int Thing;\nstruct Other;\nclass Q\n{\n};\n'
        self.assertNotIn('typedef', sd.remove_typedefs(h, 'Thing'))
        self.assertNotIn('struct Other;', sd.remove_forward_declarations(h, 'Other'))

    def test_member_is_added_before_the_closing_brace(self):
        h = '#pragma once\nclass Heap\n{\n  public:\n    int a;\n};\n'
        out = sd.add_member(h, 'Heap', 'void* Func00aa3e40(unsigned int size);')
        self.assertIn('    void* Func00aa3e40(unsigned int size);\n};', out)
        self.assertIsNone(sd.add_member(h, 'Missing', 'void f();'))

    def test_first_declaration_of_a_conflicting_function_wins(self):
        h = '#pragma once\nextern "C" int __cdecl F();\nextern "C" long __cdecl F();\n'
        out = sd.keep_first_declaration(h, 'F')
        self.assertEqual(out.count('F()'), 1)
        self.assertIn('int __cdecl F', out)


class CloneSearch(unittest.TestCase):
    def test_member_prototype_and_global_are_found_by_decompiler_name(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'src').mkdir()
            (root / 'include').mkdir()
            (root / 'src/a.cpp').write_text('struct Helper\n{\n    void* __thiscall FUN_00aa3e40(unsigned int size);\n};\nextern Heap DAT_011f6238;\n')
            self.assertEqual(sd.member_prototype(root, 'FUN_00aa3e40')[0], 'void* __thiscall FUN_00aa3e40(unsigned int size);')
            self.assertEqual(sd.global_declaration(root, 'DAT_011f6238')[0], 'extern Heap DAT_011f6238;')
            self.assertIsNone(sd.global_declaration(root, 'DAT_00000001'))


if __name__ == '__main__':
    unittest.main()
