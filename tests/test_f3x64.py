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


if __name__ == '__main__':
    unittest.main()
