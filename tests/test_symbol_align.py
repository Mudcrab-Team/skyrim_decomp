"""Tests for tools/symbol_align.py on invented map lines and an invented inventory."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import symbol_align as sa  # noqa: E402


def line(dec, obj, flags=' f', n=0):
    return f' 0001:{n:08x}       {dec}   {0x401000 + n:08x}{flags}    lib:{obj}'


MAP = [
    line('?Alpha@Widget@@QAEXXZ', 'widget.obj', n=0),
    line('?Beta@Widget@@UAEHH@Z', 'widget.obj', n=16),
    line('?Gamma@Widget@@QBE_NXZ', 'widget.obj', n=32),
    line('?Delta@Widget@@QAEXXZ', 'widget.obj', n=48),
    line('?Other@Gadget@@QAEXXZ', 'gadget.obj', n=64),
]
INVENTORY = [
    (0x1000, 'Widget::Alpha'),
    (0x1010, 'Widget::Func_1010'),
    (0x1020, 'Widget::Gamma'),
    (0x1030, 'Widget::Delta'),
]


class MemberOf(unittest.TestCase):
    def test_plain_ctor_and_dtor(self):
        self.assertEqual(sa.member_of('?Run@Ns@Widget@@QAEXXZ'), ('Widget::Ns', 'Run'))
        self.assertEqual(sa.member_of('??0Widget@@QAE@XZ'), ('Widget', 'Widget'))
        self.assertEqual(sa.member_of('??1Widget@@UAE@XZ'), ('Widget', '~Widget'))
        self.assertIsNone(sa.member_of('_main'))


class Align(unittest.TestCase):
    def test_gap_filled_between_anchors(self):
        entries = sa.parse_map(MAP)
        aligners, functions = sa.build([entries], INVENTORY)
        self.assertEqual(list(functions), ['0x1010'])
        found = functions['0x1010']
        self.assertEqual(found['name'], 'Widget::Beta')
        self.assertEqual(found['confidence'], 'high')
        self.assertEqual(found['object'], 'widget.obj')

    def test_count_mismatch_gives_nothing(self):
        inventory = INVENTORY[:1] + [(0x1008, 'Widget::Func_1008')] + INVENTORY[1:]
        _, functions = sa.build([sa.parse_map(MAP)], inventory)
        self.assertEqual(functions, {})

    def test_different_object_gives_nothing(self):
        lines = MAP[:2] + [line('?Gamma@Widget@@QBE_NXZ', 'other.obj', n=32)] + MAP[3:]
        _, functions = sa.build([sa.parse_map(lines)], INVENTORY)
        self.assertEqual(functions, {})

    def test_output_has_no_addresses(self):
        _, functions = sa.build([sa.parse_map(MAP)], INVENTORY)
        text = repr(functions)
        self.assertNotIn('401', text)
        self.assertNotIn('0001:', text)

    def test_holdout_reproduces_hidden_name(self):
        aligners = [sa.Aligner(sa.parse_map(MAP), INVENTORY + [(0x1040, 'Widget::Epsilon')])]
        stats = sa.holdout(aligners, 10)
        self.assertNotIn('wrong', str(stats))
        self.assertEqual(sum(w for _, w in stats.values()), stats.get('none', [0, 0])[1])

    def test_inline_variant_drops_duplicates(self):
        lines = MAP + [line('?Tmpl@Widget@@QAEXXZ', 'widget.obj', ' f i', 80)]
        self.assertEqual(len(sa.parse_map(lines)), 6)
        self.assertEqual(len(sa.parse_map(lines, inline=False)), 5)


if __name__ == '__main__':
    unittest.main()


class Undname(unittest.TestCase):
    def test_echoed_input_is_paired(self):
        from unittest import mock
        fake = mock.Mock(stdout='?A@B@@QAEXXZ\npublic: void B::A(void)\n\n?C@B@@QAEXXZ\npublic: void B::C(void)\n')
        with mock.patch.object(sa.subprocess, 'run', return_value=fake):
            got = sa.undname_all(['?A@B@@QAEXXZ', '?C@B@@QAEXXZ'], 'undname')
        self.assertEqual(got, ['public: void B::A(void)', 'public: void B::C(void)'])
