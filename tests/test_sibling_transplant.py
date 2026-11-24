import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import sibling_transplant as st  # noqa: E402

SOURCE = """\
struct Base { virtual ~Base(); };
struct Holder : Base
{
    Holder(int a);
    int value;
};
extern int g_counter;
// helper
int Holder::Read(const int* p) const
{
    return *p + g_counter;
}
"""


class Excerpt(unittest.TestCase):
    def setUp(self):
        self.lines = SOURCE.splitlines()

    def test_function_and_preceding_declarations_are_cut_out(self):
        pre, fn, sig = st.excerpt(self.lines, 10)
        self.assertEqual(fn[0], 'int Holder::Read(const int* p) const')
        self.assertEqual(fn[-1], '}')
        self.assertNotIn('// helper', pre)

    def test_signature_gives_owner_and_name(self):
        self.assertEqual(st.parse_signature(['int Holder::Read(const int* p) const']), ('Holder', 'Read'))
        self.assertEqual(st.parse_signature(['void Free(int a)']), (None, 'Free'))

    def test_class_text_stops_at_the_closing_brace(self):
        self.assertEqual(st.class_text(self.lines, 'Base'), ['struct Base { virtual ~Base(); };'])
        self.assertEqual(st.class_text(self.lines, 'Holder')[-1], '};')

    def test_dependencies_come_before_their_users(self):
        deps = st.dependency_classes(self.lines, st.class_text(self.lines, 'Holder'), 'Holder')
        self.assertEqual([n for n, _ in deps], ['Base'])


class Rewrites(unittest.TestCase):
    def test_decompiler_names_are_renamed(self):
        self.assertEqual(st.sanitize('FUN_00a5c570(DAT_01234567)'), 'Func00a5c570(Data01234567)')

    def test_calling_conventions_and_32_bit_allocation_signatures_are_adapted(self):
        text = st.sanitize('void __thiscall f(); static void* operator new(unsigned int n);')
        self.assertNotIn('__thiscall', text)
        self.assertIn('operator new(size_t n)', text)

    def test_other_allocation_spellings_and_sized_delete_are_adapted(self):
        text = st.sanitize('void* operator new(unsigned long n); void* operator new[](UInt32 n);\n'
                           'void operator delete(void* p, unsigned int n); void g() { operator delete(this, 0x10); }')
        self.assertIn('operator new(size_t n)', text)
        self.assertIn('operator new[](size_t n)', text)
        self.assertIn('operator delete(void* p, size_t n)', text)
        self.assertIn('operator delete(this)', text)

    def test_crt_redeclarations_and_size_asserts_are_removed(self):
        text = st.sanitize('extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);\n'
                           'STATIC_ASSERT(sizeof(Thing) == 0x20);\nstatic_assert(offsetof(Thing, x) == 4, "x");\n'
                           'typedef char check_1[(sizeof(Thing) == 8) ? 1 : -1];\nint keep;\n')
        self.assertNotIn('memcpy', text)
        self.assertNotIn('sizeof', text)
        self.assertNotIn('offsetof', text)
        self.assertIn('int keep;', text)

    def test_stub_class_keeps_one_default_constructor(self):
        lines = ['class Thing', '{', '  public:', '    Thing(int a, int b)', '    {', '        x = a;', '    }', '    virtual ~Thing();', '    int x;', '};']
        stub = st.stub_class(lines, 'Thing', 'Thing')
        self.assertEqual(stub.count('    Thing();'), 1)
        self.assertNotIn('x = a;', '\n'.join(stub))

    def test_namespaces_are_found_and_rewrapped(self):
        lines = ['namespace a {', 'namespace b {', 'int x;', '}', '}', 'int y;']
        self.assertEqual(st.enclosing_namespaces(lines, 3), ['a', 'b'])
        self.assertEqual(st.enclosing_namespaces(lines, 5), [])
        self.assertEqual(st.wrap_namespaces('int z;', ['a', 'b']), 'namespace a {\nnamespace b {\nint z;\n}\n}')

    def test_names_come_from_a_plain_class_method_only(self):
        self.assertEqual(st.skyrim_name({'name': 'Actor::Update'}), ('Actor', 'Update'))
        self.assertEqual(st.skyrim_name({'name': 'a::b::c'}), (None, None))
        self.assertEqual(st.skyrim_name({}), (None, None))

    def test_sized_thunk_unit_is_a_class_padded_to_the_target_size(self):
        unit = st.sized_thunk_unit({'rva': 0x1000}, {'name': 'Thing::dtor_deleting'}, 0x20)
        self.assertIn('char padding_[24];', unit['header_decl'])
        self.assertEqual(unit['compared'], 'Thing::~Thing')


class Provenance(unittest.TestCase):
    def test_original_unit_header_does_not_claim_sibling_adaptation(self):
        unit = st.sized_thunk_unit({'rva': 0x1000}, {'name': 'Thing::dtor_deleting'}, 0x20)
        header, cpp = st.render(unit, 0x1000, None, 'Thing_1000')
        self.assertIn('Code origin: original', header)
        self.assertNotIn('adapted from the sibling', header)
        self.assertNotIn('Sibling source', cpp)

    def test_ci_hash_line_comes_from_the_task_symbol(self):
        import json
        import tempfile
        with tempfile.TemporaryDirectory() as tmp:
            Path(tmp, 'task.json').write_text(json.dumps({'functions': [{'rva': '0x1000', 'symbol': '??_GThing@@UEAAPEAXI@Z'},
                                                                       {'rva': '0x2000', 'symbol': 'unbound:Thing::f'}]}))
            self.assertEqual(st.ci_hash_line(tmp, 0x1000), '// CI hash: 0x1000 ??_GThing@@UEAAPEAXI@Z')
            self.assertIsNone(st.ci_hash_line(tmp, 0x2000))
            self.assertIsNone(st.ci_hash_line(tmp, 0x3000))


if __name__ == '__main__':
    unittest.main()


class HeaderRepairText(unittest.TestCase):
    """The repair writes sibling declarations into the unit's own header, labelled, without a compiler."""

    def setUp(self):
        import tempfile
        import sibling_decls
        self.tmp = tempfile.TemporaryDirectory()
        root = Path(self.tmp.name)
        (root / 'clone/include').mkdir(parents=True)
        (root / 'clone/include/Mid.h').write_text('class Base\n{\n  public:\n    int a;\n};\nclass Mid : public Base\n{\n  public:\n    int b;\n};\n')
        (root / 'u').mkdir()
        (root / 'u/U.h').write_text('// leading\n#pragma once\n\nclass User\n{\n  public:\n    Mid* m;\n};\n')
        (root / 'u/U.cpp').write_text('#include "U.h"\n')
        self.old = (st.ROOT, dict(st._INDEXES))
        st.ROOT = root
        st._INDEXES.clear()
        st._INDEXES['f3'] = sibling_decls.DeclIndex(root / 'clone', st.SIBLING_LABEL)

    def tearDown(self):
        st.ROOT = self.old[0]
        st._INDEXES.clear()
        st._INDEXES.update(self.old[1])
        self.tmp.cleanup()

    def test_missing_class_comes_with_its_base_and_is_labelled(self):
        rep = st.HeaderRepair('u/U.h', 'u/U.cpp')
        self.assertTrue(rep.fix('', 0, "unknown type name 'Mid'"))
        self.assertLess(rep.text.index('class Base'), rep.text.index('class Mid'))
        self.assertLess(rep.text.index('class Mid'), rep.text.index('class User'))
        self.assertTrue('Base' in rep.label_lines()[0] and 'Mid' in rep.label_lines()[0])
        self.assertIn(st.SIBLING_LABEL, rep.label_lines()[0])

    def test_name_no_clone_declares_becomes_a_labelled_stand_in(self):
        rep = st.HeaderRepair('u/U.h', 'u/U.cpp')
        self.assertTrue(rep.fix('', 0, "unknown type name 'Ghost'"))
        self.assertIn('struct Ghost;', rep.text)
        self.assertIn('GUESS(low) STANDIN', rep.label_lines()[-1])

    def test_conflicting_typedef_is_dropped_for_a_class_of_the_same_name(self):
        rep = st.HeaderRepair('u/U.h', 'u/U.cpp')
        rep.text = rep.text.replace('class User', 'typedef int Mid;\nclass Mid\n{\n};\nclass User')
        rep.fix('', 0, "definition of type 'Mid' conflicts with typedef of the same name")
        self.assertNotIn('typedef int Mid', rep.text)
