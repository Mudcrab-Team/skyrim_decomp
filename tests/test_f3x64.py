"""tools/f3x64 on toy data: signatures, shingle matching, idiom lookup and layout classification."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'f3x64'))
import layout  # noqa: E402
import lookup  # noqa: E402
import shape  # noqa: E402


def sig(lines):
    s = shape.new_sig()
    for text in lines:
        mn, _, rest = text.partition(' ')
        shape.feed(s, mn, shape.split_ops(rest))
    return shape.done(s)


BODY = ['mov rax, qword ptr [rcx + 8]', 'test rax, rax', 'je 0x10', 'mov rcx, rax', 'call 0x40', 'add eax, 0x100',
        'cmp eax, 0x2710', 'jbe 0x20', 'mov eax, 0x2710', 'ret', 'xor eax, eax', 'ret']


class ShapeTests(unittest.TestCase):
    def test_signature_drops_registers_and_keeps_large_immediates(self):
        s = sig(BODY)
        self.assertEqual(s['calls'], 1)
        self.assertIn(0x2710, s['imms'])
        self.assertNotIn(8, s['imms'])
        self.assertEqual(s['mn'][0], 'mov')

    def test_match_finds_same_shape_with_other_registers_and_offsets(self):
        other = [t.replace('rcx', 'rdx').replace('[rdx + 8]', '[rdx + 16]') for t in BODY]
        unrelated = ['push rbx', 'sub rsp, 0x20', 'lea rcx, [rip + 4]', 'call 0x1', 'nop', 'add rsp, 0x20', 'pop rbx', 'ret'] * 3
        a = {('u', 'f'): sig(BODY), ('u', 'g'): sig(unrelated)}
        b = {1: sig(other)}
        hits = shape.match(a, b, floor=0.5)
        best = hits[1][0][0]
        self.assertEqual(best[2], ('u', 'f'))
        self.assertGreater(best[0], 0.9)

    def test_short_functions_get_no_lead(self):
        self.assertEqual(shape.match({('u', 'f'): sig(BODY)}, {1: sig(BODY[:4])}), {})


class LookupTests(unittest.TestCase):
    INDEX = {('u', 'f'): {'unit': 'u', 'file': 'src/u.cpp', 'lines': {3: 'return p ? p->Get() : 0;'},
                          'ins': [('test rcx, rcx', 3), ('je SHORT $LN3', 3), ('mov rax, QWORD PTR [rcx]', 3),
                                  ('rex_jmp QWORD PTR [rax+304]', 3), ('xor eax, eax', 3), ('ret 0', 3)]}}

    def test_consecutive_items(self):
        res, total = lookup.idiom(self.INDEX, ['test rcx, rcx', 'je'], 5)
        self.assertEqual(total, 1)

    def test_gap_item_skips_instructions(self):
        pats = ['test rcx, rcx', '..', 'xor eax, eax']
        self.assertEqual(lookup.idiom(self.INDEX, pats, 5)[1], 1)
        self.assertEqual(lookup.idiom(self.INDEX, ['test rcx, rcx', 'xor eax, eax'], 5)[1], 0)

    def test_gap_is_bounded(self):
        far = {('u', 'f'): {'unit': 'u', 'file': 'f', 'lines': {},
                            'ins': [('test rcx, rcx', 0)] + [('nop', 0)] * 12 + [('xor eax, eax', 0)]}}
        self.assertEqual(lookup.idiom(far, ['test rcx, rcx', '..', 'xor eax, eax'], 5)[1], 0)


class LayoutTests(unittest.TestCase):
    def test_classification(self):
        self.assertEqual(layout.classify('mov', 'mov rax, qword ptr [rcx + 0x48]', 27), 'member-offset')
        self.assertEqual(layout.classify('call', 'call qword ptr [rax + 0x130]', 24), 'vtable-slot')
        self.assertEqual(layout.classify('mov', 'mov edx, 0x1', 9), 'immediate')

    def test_class_name_from_decorated_symbol(self):
        self.assertEqual(layout.f3class('?Create@NiRenderedTexture@@SAPEAV1@XZ'), 'NiRenderedTexture')
        self.assertEqual(layout.f3class('??_GNiFile@@UEAAPEAXI@Z'), 'NiFile')

    def test_fact_kinds_by_context(self):
        def row(text, relsym=()):
            return {'t': text, 'rel': [1] if relsym else [], 'relsym': list(relsym), 'b': []}
        sibling = [row('mov rcx, qword ptr [rbx + 0x10]'), row('mov edx, 0x20'), row('call 0x0', relsym=['??2@YAPEAX_K@Z']),
                   row('add rcx, 0x8'), row('mov r8d, 0x5'), row('call 0x0', relsym=['?Register@@YAXXZ']),
                   row('call qword ptr [rax + 0x68]'), row('sub rsp, 0x28'), row('mov rax, qword ptr [rsp + 0x30]')]
        target = [row('mov rcx, qword ptr [rbx + 0x18]'), row('mov edx, 0x30'), row('call 0x1400'), row('add rcx, 0x10'),
                  row('mov r8d, 0x3'), row('call 0x1500'), row('call qword ptr [rax + 0x50]'), row('sub rsp, 0x38'),
                  row('mov rax, qword ptr [rsp + 0x40]')]
        facts, why = layout.pair_facts(sibling, target, '?Make@Thing@@QEAAXXZ')
        self.assertIsNone(why)
        self.assertEqual([f['kind'] for f in facts], ['member-offset', 'alloc-size', 'add-offset', 'call-arg-constant', 'vtable-slot',
                                                      'frame-size', 'stack-offset'])
        self.assertEqual(facts[1]['callee'], '??2@YAPEAX_K@Z')

    def test_deleting_thunk_size_and_width_facts(self):
        def row(text):
            return {'t': text, 'rel': [], 'relsym': [], 'b': []}
        facts, why = layout.pair_facts([row('mov edx, 0x8'), row('mov dword ptr [rcx + 0x18], 0x0')],
                                       [row('mov edx, 0x20'), row('mov qword ptr [rcx + 0x20], 0x0')], '??_GThing@@UEAAPEAXI@Z')
        self.assertIsNone(why)
        kinds = [f['kind'] for f in facts]
        self.assertEqual(kinds, ['class-size', 'operand-width', 'member-offset'])
        self.assertEqual((facts[1]['sibling_disp'], facts[1]['skyrim_disp']), ('0x18', '0x20'))

    def test_a_structural_difference_rejects_the_pair(self):
        def row(text):
            return {'t': text, 'rel': [], 'relsym': [], 'b': []}
        self.assertIsNotNone(layout.pair_facts([row('test rax, rax')], [row('xor eax, eax')], '?F@@YAXXZ')[1])


if __name__ == '__main__':
    unittest.main()
