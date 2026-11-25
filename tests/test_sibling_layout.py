import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import sibling_layout as sl  # noqa: E402

HEADER = """\
struct Node
{
    Node* next;
    int count;
};

class Holder
{
  public:
    virtual ~Holder();
    virtual int Size();
    virtual int Weight();
    int head;
    Node* first;
    void Walk();
};
"""
BODY = "void Holder::Walk()\n{\n    Node* n = first;\n    head = Weight();\n}\n"


def facts():
    return [dict(kind='member-offset', sibling_x64='0x10', skyrim='0x20', instruction_pattern='mov rax, qword ptr [rcx + #]',
                 source_line='Node* n = first;'),
            dict(kind='vtable-slot', sibling_x64='0x10', skyrim='0x28', instruction_pattern='call qword ptr [rax + #]',
                 source_line='head = Weight();')]


class Layout(unittest.TestCase):
    def test_engine_places_members_after_the_vptr(self):
        classes = sl.parse_classes(HEADER)
        lay = sl.Engine(classes, HEADER).layout('Holder')
        self.assertEqual((lay.offsets['head'], lay.offsets['first']), (8, 16))
        self.assertEqual(lay.slots['Weight'], 2)

    def test_stand_in_moves_member_and_slot_to_the_target(self):
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts(), 'Walk'))
        lay = sl.Engine(sl.parse_classes(u['header_decl']), u['header_decl']).layout('Holder')
        self.assertEqual(lay.offsets['first'], 0x20)
        self.assertEqual(lay.slots['Weight'], 5)
        self.assertIn('Stand-in layout', u['header_decl'])
        self.assertTrue(u['labels'] and u['labels'][-1][1] == 'GUESS')

    def test_a_fact_that_names_no_member_refuses_the_unit(self):
        bad = [dict(kind='member-offset', sibling_x64='0x40', skyrim='0x50', instruction_pattern='mov rax, qword ptr [rcx + #]',
                    source_line='unrelated();')]
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIn('not matched', sl.apply_layout(u, bad, 'Walk'))

    def test_community_size_fills_a_type_the_sibling_text_does_not_define(self):
        import json
        import os
        import tempfile
        text = "struct Holder\n{\n    Widget w;\n    int tail;\n};\n"
        classes = sl.parse_classes(text)
        self.assertNotIn('tail', sl.Engine(classes, text).layout('Holder').offsets)
        with tempfile.TemporaryDirectory() as d:
            path = os.path.join(d, 'sizes.json')
            with open(path, 'w', encoding='utf-8') as handle:
                json.dump({'Widget': {'LibA': 12, 'LibB': 12}, 'Clash': {'LibA': 4, 'LibB': 8}}, handle)
            os.environ['SIBLING_COMMUNITY_SIZES'] = path
            try:
                lay = sl.Engine(classes, text).layout('Holder')
                self.assertEqual(lay.offsets['tail'], 12)
                self.assertNotIn('Clash', sl.community_sizes())
            finally:
                del os.environ['SIBLING_COMMUNITY_SIZES']

    def test_one_member_named_by_the_source_line_is_taken_when_the_computed_offset_disagrees(self):
        wrong = [dict(kind='member-offset', sibling_x64='0x40', skyrim='0x50', instruction_pattern='mov rax, qword ptr [rcx + #]',
                      source_line='Node* n = first;')]
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIsNone(sl.apply_layout(u, wrong, 'Walk'))
        lay = sl.Engine(sl.parse_classes(u['header_decl']), u['header_decl']).layout('Holder')
        self.assertEqual(lay.offsets['first'], 0x50)

    def test_spelled_offset_inside_an_inline_header_function_is_patched(self):
        header = ("struct Owner\n{\n    char* base;\n    int Get() const { return *reinterpret_cast<int*>("
                  "reinterpret_cast<char*>(this) + 0x24c); }\n    void Run();\n};\n")
        facts = [dict(kind='member-offset', sibling_x64='0x24c', skyrim='0x298', instruction_pattern='mov rbx, qword ptr [rcx + #]',
                      source_line='return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x24c);')]
        u = dict(header_decl=header, cpp_body='void Owner::Run()\n{\n    Get();\n}\n', labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Run'))
        self.assertIn('+ 0x298)', u['header_decl'])

    def test_stack_frame_difference_is_not_a_layout_fact(self):
        stack = [dict(kind='member-offset', sibling_x64='0x28', skyrim='0x2c', instruction_pattern='mov eax, dword ptr [rsp + #]',
                      source_line='x')]
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIn('stack frame', sl.apply_layout(u, stack, 'Walk'))


WIDTH_HEADER = """\
struct Owner
{
    virtual ~Owner();
    unsigned int count;
    void* handle;
    void Clear();
};
"""
WIDTH_BODY = "void Owner::Clear()\n{\n    count = 0;\n    handle = 0;\n}\n"


class FactKinds(unittest.TestCase):
    def test_member_width_fact_retypes_the_member_at_its_offset(self):
        facts = [dict(kind='operand-width', sibling_x64='mov qword ptr [rbx + 0x10], 0x0',
                      skyrim='mov dword ptr [rbx + 0x10], 0x0', instruction_pattern='mov qword ptr [rbx + #], #', source_line='handle = 0;')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=WIDTH_BODY, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Clear'))
        text = u['header_decl']
        lay = sl.Engine(sl.parse_classes(text), text).layout('Owner')
        self.assertEqual((lay.offsets['handle'], lay.sizes['handle']), (16, 4))

    def test_register_width_fact_widens_the_integer_parameters(self):
        header = "struct Owner\n{\n    void Set(int a, unsigned int b, char* c);\n};\n"
        body = "void Owner::Set(int a, unsigned int b, char* c)\n{\n    c[a] = b;\n}\n"
        facts = [dict(kind='operand-width', sibling_x64='mov eax, edx', skyrim='mov rax, rdx', instruction_pattern='mov eax, edx',
                      source_line='')]
        u = dict(header_decl=header, cpp_body=body, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Set'))
        self.assertIn('Set(__int64 a, unsigned __int64 b, char* c)', u['cpp_body'])
        self.assertIn('Set(__int64 a, unsigned __int64 b, char* c);', u['header_decl'])
        self.assertEqual(u['widened_parameters'], 2)

    def test_widening_follows_the_callee_prototype(self):
        header = "void Helper(int a, int b);\nstruct Owner\n{\n    void Set(int a, int b);\n};\n"
        body = "void Owner::Set(int a, int b)\n{\n    Helper(b, a);\n}\n"
        facts = [dict(kind='operand-width', sibling_x64='mov eax, edx', skyrim='mov rax, rdx', instruction_pattern='mov eax, edx',
                      source_line='')]
        u = dict(header_decl=header, cpp_body=body, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Set'))
        self.assertIn('void Helper(__int64 a, __int64 b);', u['header_decl'])

    def test_widening_follows_a_constructed_class(self):
        header = "struct C\n{\n    int m_i;\n    C(int a) : m_i(a)\n    {}\n};\nvoid Free(int x, int w);\n"
        body = "void Free(int x, int w)\n{\n    C c(w);\n}\n"
        facts = [dict(kind='operand-width', sibling_x64='mov eax, edx', skyrim='mov rax, rdx', instruction_pattern='x', source_line='')]
        u = dict(header_decl=header, cpp_body=body, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Free'))
        self.assertIn('__int64 m_i;', u['header_decl'])
        self.assertIn('C(__int64 a) : m_i(a)', u['header_decl'])

    def test_register_width_fact_without_an_integer_parameter_is_refused(self):
        facts = [dict(kind='operand-width', sibling_x64='mov eax, edx', skyrim='mov rax, rdx', instruction_pattern='mov eax, edx',
                      source_line='')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=WIDTH_BODY, labels=[])
        self.assertIn('no integer parameter', sl.apply_layout(u, facts, 'Clear'))

    def test_narrower_target_is_not_a_parameter_widening(self):
        header = "struct Owner\n{\n    void Set(int a);\n};\n"
        facts = [dict(kind='operand-width', sibling_x64='mov rax, rdx', skyrim='mov eax, edx', instruction_pattern='mov rax, rdx',
                      source_line='')]
        u = dict(header_decl=header, cpp_body='void Owner::Set(int a)\n{\n}\n', labels=[])
        self.assertIn('narrower', sl.apply_layout(u, facts, 'Set'))

    def test_add_offset_moves_the_member_like_a_displacement(self):
        facts = [dict(kind='add-offset', sibling_x64='0x10', skyrim='0x18', instruction_pattern='add rcx, #', source_line='handle = 0;')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=WIDTH_BODY, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Clear'))
        text = u['header_decl']
        self.assertEqual(sl.Engine(sl.parse_classes(text), text).layout('Owner').offsets['handle'], 0x18)

    def test_allocation_size_pads_the_allocated_class(self):
        facts = [dict(kind='alloc-size', sibling_x64='0x18', skyrim='0x40', instruction_pattern='mov ecx, #',
                      source_line='Owner* p = new Owner;', callee='??2@YAPEAX_K@Z')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=WIDTH_BODY, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Clear'))
        text = u['header_decl']
        self.assertEqual(sl.Engine(sl.parse_classes(text), text).layout('Owner').size, 0x40)

    def test_class_size_below_the_used_members_is_refused(self):
        facts = [dict(kind='alloc-size', sibling_x64='0x18', skyrim='0x10', instruction_pattern='mov ecx, #',
                      source_line='Owner* p = new Owner;', callee='??2@YAPEAX_K@Z'),
                 dict(kind='operand-width', sibling_x64='mov qword ptr [rbx + 0x10], 0x0', skyrim='mov dword ptr [rbx + 0x10], 0x0',
                      instruction_pattern='mov qword ptr [rbx + #], #', source_line='handle = 0;')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=WIDTH_BODY, labels=[])
        self.assertIn('below the members', sl.apply_layout(u, facts, 'Clear'))

    def test_call_argument_constant_is_replaced_on_its_source_line_only(self):
        body = "void Owner::Clear()\n{\n    Register(5, 5);\n    Other(5);\n}\n"
        facts = [dict(kind='call-arg-constant', sibling_x64='0x5', skyrim='0x3', instruction_pattern='mov r8d, #',
                      source_line='Register(5, 5);', callee='?Register@@YAXHH@Z')]
        u = dict(header_decl=WIDTH_HEADER, cpp_body=body, labels=[])
        self.assertIsNone(sl.apply_layout(u, facts, 'Clear'))
        self.assertIn('Register(3, 3);', u['cpp_body'])
        self.assertIn('Other(5);', u['cpp_body'])
        self.assertEqual(u['constants'], 2)

    def test_thunk_keeps_its_inline_destructor_and_takes_the_target_size(self):
        header = "struct Base\n{\n    virtual ~Base();\n};\n\nstruct Node : Base\n{\n    void* a;\n    void* b;\n    virtual ~Node() { b = 0; }\n    Node();\n};\n"
        facts = [dict(kind='member-offset', sibling_x64='0x10', skyrim='0x20', instruction_pattern='mov qword ptr [rcx + #], #', source_line=''),
                 dict(kind='class-size', sibling_x64='0x18', skyrim='0x30', instruction_pattern='mov edx, #', source_line='')]
        u = dict(header_decl=header, cpp_body='Node::Node()\n{\n}\n', labels=[], thunk=True, cls='Node')
        self.assertIsNone(sl.apply_layout(u, facts, None))
        text = u['header_decl']
        lay = sl.Engine(sl.parse_classes(text), text).layout('Node')
        self.assertEqual((lay.offsets['b'], lay.size), (0x20, 0x30))
        self.assertIn('~Node() { b = 0; }', text)


if __name__ == '__main__':
    unittest.main()
