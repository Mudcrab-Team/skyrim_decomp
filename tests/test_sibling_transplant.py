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
