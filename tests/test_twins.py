"""tools/twins on synthetic sources and operands (no game data)."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'twins'))
sys.path.insert(0, str(ROOT / 'tools'))
import twin_layout as layout  # noqa: E402
import twin_shapes as shapes  # noqa: E402
import twin_source as S  # noqa: E402
import twin_subst as subst  # noqa: E402
import twin_unit as U  # noqa: E402

STAMPED_H = """// Source exposure: binary-analysis (synthetic).
// Code origin: original stand-in.
// Leaf111111, FreeLeaf111111, data: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct Leaf111111
{
    ~Leaf111111();
    void* data;
};

struct Other222222
{
    int x;
};

void FreeLeaf111111(Leaf111111* leaf);
"""
STAMPED_CPP = """// Source exposure: binary-analysis (synthetic).
// Code origin: original stand-in.
// 0x111111 Leaf111111::~Leaf111111
// 0x222222 Other222222::Get
// CI hash: 0x111111 ??1Leaf111111@@QEAA@XZ
#include "Leaf111111.h"

Leaf111111::~Leaf111111()
{
    if (data) {
        FreeLeaf111111(this);
    }
}

int Other222222::Get() { return x; }
"""
REAL_H = """// Source exposure: mixed (synthetic).
// Code origin: original stand-in.
// Widget: GUESS(low) STANDIN
#pragma once
#include <cstdint>

class Widget
{
public:
    std::uint32_t GetMode() const;
    virtual ~Widget();
    std::uint8_t unknown08[0x8];
    std::uint32_t mode;
};
static_assert(sizeof(Widget) == 0x18, "size");
"""
REAL_CPP = """// Source exposure: mixed (synthetic).
// Code origin: original stand-in.
// 0x333333 Widget::GetMode
#include "Widget.h"

// helper_hash: GUESS(low)
extern std::uint32_t helper_hash;

std::uint32_t Widget::GetMode() const
{
    return mode + 5 + helper_hash;
}
"""


class SourceTests(unittest.TestCase):
    def test_segments_and_names(self):
        segs = S.segments(STAMPED_CPP.split('#include "Leaf111111.h"')[1])
        self.assertEqual([(s.kind, s.name) for s in segs],
                         [('function', 'Leaf111111::~Leaf111111'), ('function', 'Other222222::Get')])

    def test_braces_in_strings_do_not_split(self):
        segs = S.segments('int f() { const char* s = "}"; return 1; }\nint g;')
        self.assertEqual([s.name for s in segs], ['f', 'g'])

    def test_compared_lines(self):
        self.assertEqual(S.compared(STAMPED_CPP), [(0x111111, 'Leaf111111::~Leaf111111'), (0x222222, 'Other222222::Get')])

    def test_rename_identifiers_whole_words(self):
        self.assertEqual(S.rename_identifiers('Widget WidgetX Widget::f', {'Widget': 'Owner1'}), 'Owner1 WidgetX Owner1::f')


class UnitTests(unittest.TestCase):
    def fixture(self, files):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        for rel, text in files.items():
            path = Path(tmp.name) / 'reconstruction' / rel
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
        return tmp

    def test_stamped_slices_other_functions_and_renames_hex(self):
        tmp = self.fixture({'unmapped/Leaf111111.h': STAMPED_H, 'unmapped/Leaf111111.cpp': STAMPED_CPP})
        ex = U.load_exemplar(tmp.name, 0x111111, 'unmapped/Leaf111111')
        twin = U.build(tmp.name, ex, 0x444444)
        cpp, header = twin.files['unmapped/Leaf444444.cpp'], twin.files['unmapped/Leaf444444.h']
        self.assertIn('// 0x444444 Leaf444444::~Leaf444444', cpp)
        self.assertIn('// CI hash: 0x444444 ??1Leaf444444@@QEAA@XZ', cpp)
        self.assertNotIn('Other222222', cpp + header)
        self.assertNotIn('111111', cpp.replace('0x111111 (', '') .split('Stamped as a twin of')[0] + header.split('Stamped as a twin of')[0])
        self.assertIn('FreeLeaf444444(this)', cpp)
        self.assertIn('#include "Leaf444444.h"', cpp)

    def test_standin_clones_the_owner(self):
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': REAL_CPP})
        ex = U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget')
        twin = U.build(tmp.name, ex, 0x555555)
        cpp, header = twin.files['unmapped/Owner555555.cpp'], twin.files['unmapped/Owner555555.h']
        self.assertIn('class Owner555555', header)
        self.assertIn('#include "Widget.h"', header)
        self.assertIn('Owner555555::Function555555', cpp)
        self.assertIn('helper_hash_555555', cpp)
        self.assertIn('GUESS(low) STANDIN', header)
        self.assertNotIn('Widget::', cpp)

    def test_constants_substitute_in_the_function_only(self):
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': REAL_CPP})
        ex = U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget')
        twin = U.build(tmp.name, ex, 0x555555)
        U.apply_constants(twin, {5: (9, 4)})
        self.assertIn('mode + 9 +', twin.files['unmapped/Owner555555.cpp'])
        with self.assertRaises(U.Unsupported):
            U.apply_constants(twin, {77: (1, 4)})

    def test_layout_moves_the_member(self):
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': REAL_CPP})
        ex = U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget')
        twin = U.build(tmp.name, ex, 0x555555)
        U.apply_layout(twin, [(0x10, 0x20)])
        header = twin.files['unmapped/Owner555555.h']
        self.assertIn('unknown08[0x18]', header)
        self.assertIn('== 0x28', header)


class LayoutTests(unittest.TestCase):
    CLS = 'class A {\npublic:\n    virtual void F();\n    std::uint8_t pad08[0x8];\n    std::uint32_t value;\n};'

    def test_offsets_with_vptr(self):
        _head, members, virtual, bases = layout.parse(self.CLS)
        layout.assign_offsets(members, virtual)
        self.assertEqual([(m.name, m.offset) for m in members], [('pad08', 8), ('value', 16)])
        self.assertFalse(bases)

    def test_unknown_member_type_is_refused(self):
        with self.assertRaises(U.Unsupported):
            layout.relocate('class A { Other x; };', [(0, 8)])

    def test_missing_member_is_refused(self):
        with self.assertRaises(U.Unsupported):
            layout.relocate(self.CLS, [(0x40, 0x48)])

    def test_cannot_shrink_without_padding(self):
        with self.assertRaises(U.Unsupported):
            layout.relocate('class B { public: std::uint32_t a; std::uint32_t b; };', [(4, 0)])


class SubstTests(unittest.TestCase):
    def test_uniform_immediate(self):
        ops = [(1, 4, 5, 'imm'), (6, 4, 5, 'imm'), (9, 4, 1, 'imm')]
        diffs = [(0, 5, 7, 'imm', 4), (1, 5, 7, 'imm', 4)]
        self.assertEqual(subst.immediate_map(ops, diffs), ({5: (7, 4)}, None))

    def test_ambiguous_immediate(self):
        ops = [(1, 4, 5, 'imm'), (6, 4, 5, 'imm')]
        mapping, why = subst.immediate_map(ops, [(0, 5, 7, 'imm', 4)])
        self.assertEqual((mapping, why), ({}, 'ambiguous-constant'))

    def test_negative_and_hex_literals(self):
        text, count, missing = subst.substitute_literals('x = 0xFF; y = -1;', {0xFF: (0x10, 4)})
        self.assertEqual((text, count, missing), ('x = 0x10; y = -1;', 1, set()))


class ShapeTests(unittest.TestCase):
    def test_pattern_follows_target_sharing(self):
        a = shapes.pattern_of([(1, 'REL32', 100), (5, 'REL32', 200), (9, 'REL32', 100)])
        b = shapes.pattern_of([(1, 'REL32', 7), (5, 'REL32', 8), (9, 'REL32', 7)])
        c = shapes.pattern_of([(1, 'REL32', 7), (5, 'REL32', 8), (9, 'REL32', 9)])
        self.assertEqual(a, b)
        self.assertNotEqual(a, c)

    def test_diff_requires_equal_operand_layout(self):
        a = [(1, 4, 5, 'disp'), (5, 4, 1, 'imm')]
        self.assertEqual(shapes.diff(a, [(1, 4, 9, 'disp'), (5, 4, 1, 'imm')]), [(0, 5, 9, 'disp', 4)])
        self.assertIsNone(shapes.diff(a, a[:1]))
        self.assertIsNone(shapes.diff(a, [(1, 4, 5, 'imm'), (5, 4, 1, 'imm')]))


if __name__ == '__main__':
    unittest.main()
