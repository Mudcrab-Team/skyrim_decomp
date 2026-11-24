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
                    source_line='Node* n = first;')]
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIn('not matched', sl.apply_layout(u, bad, 'Walk'))

    def test_stack_frame_difference_is_not_a_layout_fact(self):
        stack = [dict(kind='member-offset', sibling_x64='0x28', skyrim='0x2c', instruction_pattern='mov eax, dword ptr [rsp + #]',
                      source_line='x')]
        u = dict(header_decl=HEADER, cpp_body=BODY, labels=[])
        self.assertIn('stack frame', sl.apply_layout(u, stack, 'Walk'))


if __name__ == '__main__':
    unittest.main()
