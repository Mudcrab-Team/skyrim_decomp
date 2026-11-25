"""tools/twins on synthetic sources and operands (no game data)."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'twins'))
sys.path.insert(0, str(ROOT / 'tools'))
import twin_layout as layout  # noqa: E402
import twin_callees as callees  # noqa: E402
import twin_names as names  # noqa: E402
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

    def test_compiler_deleting_destructor_selects_the_reemitted_symbol(self):
        cpp = STAMPED_CPP.replace('??1Leaf111111@@QEAA@XZ', '??_GLeaf111111@@UEAAPEAXI@Z')
        header = STAMPED_H.replace('    ~Leaf111111();', '    virtual ~Leaf111111();')
        tmp = self.fixture({'unmapped/Leaf111111.h': header, 'unmapped/Leaf111111.cpp': cpp})
        report = Path(tmp.name) / 'reports' / 'sse-steam-1-7-104' / '0x111111.json'
        report.parent.mkdir(parents=True)
        report.write_text(json.dumps({
            'source': {'compiled': 'reconstruction/unmapped/Leaf111111.cpp'},
            'runs': [{'report': {'contract_version': 2, 'function': {'symbol': '??_GLeaf111111@@UEAAPEAXI@Z'}}}],
        }))
        ex = U.load_exemplar(tmp.name, 0x111111, 'unmapped/Leaf111111')
        self.assertEqual(ex.deleting_symbol, '??_GLeaf111111@@UEAAPEAXI@Z')
        twin = U.build(tmp.name, ex, 0x444444)
        self.assertIn('// CI hash: 0x444444 ??_GLeaf444444@@UEAAPEAXI@Z', twin.files[twin.stem + '.cpp'])
        self.assertIn('Leaf444444::~Leaf444444()', twin.files[twin.stem + '.cpp'])

    def test_constants_substitute_in_the_function_only(self):
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': REAL_CPP})
        ex = U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget')
        twin = U.build(tmp.name, ex, 0x555555)
        U.apply_constants(twin, {5: (9, 4)})
        self.assertIn('mode + 9 +', twin.files['unmapped/Owner555555.cpp'])
        with self.assertRaises(U.Unsupported):
            U.apply_constants(twin, {77: (1, 4)})

    def test_named_constant_changes_its_own_declaration(self):
        cpp = REAL_CPP.replace('std::uint32_t Widget::GetMode() const',
                               'constexpr auto defaultMode = 5u;\n\nstd::uint32_t Widget::GetMode() const')
        cpp = cpp.replace('mode + 5 +', 'mode + defaultMode +')
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': cpp})
        twin = U.build(tmp.name, U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget'), 0x555555)
        U.apply_constants(twin, {5: (9, 4)})
        self.assertIn('constexpr auto defaultMode = 9u;', twin.files[twin.stem + '.cpp'])

    def test_community_name_updates_the_definition_and_label(self):
        tmp = self.fixture({'unmapped/Widget.h': REAL_H, 'unmapped/Widget.cpp': REAL_CPP})
        ex = U.load_exemplar(tmp.name, 0x333333, 'unmapped/Widget')
        twin = U.build(tmp.name, ex, 0x555555)
        binding = {'name': 'Gadget::ReadMode', 'label': 'CRASHLOGGER_PDB(59818@2026.10.24)', 'arity': 0}
        names.apply(twin, binding, headers=[REAL_H])
        self.assertIn('Gadget::ReadMode() const', twin.files[twin.stem + '.cpp'])
        self.assertIn('// Gadget::ReadMode: CRASHLOGGER_PDB', twin.files[twin.stem + '.h'])
        self.assertEqual(twin.name, binding['name'])

    def test_direct_member_callee_gets_its_own_symbol(self):
        twin = U.Twin(0x555555, 0x333333, 'unmapped/Owner555555', 'standin')
        twin.files[twin.stem + '.h'] = 'class Owner555555 { Field member; };'
        twin.files[twin.stem + '.cpp'] = '#include "Owner555555.h"\nvoid Owner555555::Run() { member.Reset(); }'
        callees.retarget(twin, [('Reset', 'Field', 'Q')])
        self.assertIn('void CallReset555555(Field* object);', twin.files[twin.stem + '.cpp'])
        self.assertIn('CallReset555555(&member);', twin.files[twin.stem + '.cpp'])

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
        owner, computed = layout.compute(self.CLS, ())
        self.assertEqual(computed.offsets, {'pad08': 8, 'value': 16})
        self.assertFalse(owner.bases)

    def test_included_base_class_member_and_enum(self):
        types = ('struct Base { virtual ~Base(); int tag; };\n'
                 'struct Value { std::uint64_t payload[0x2]; };\n'
                 'enum class Kind : unsigned char { Ready };')
        owner = ('struct Child : Base { unsigned char pad10[8]; '
                 'Value value; Kind kind; };')
        checks = ['static_assert(sizeof(Child) == 0x30);']
        text, delta, assertions = layout.relocate(owner, [(0x18, 0x10)], checks, headers=[types])
        _, computed = layout.compute(text, [types])
        self.assertEqual(computed.offsets, {'value': 0x10, 'kind': 0x20})
        self.assertEqual(delta, -8)
        self.assertIn('== 0x28', assertions[0])

    def test_exemplar_assertions_must_agree(self):
        with self.assertRaisesRegex(U.Unsupported, 'layout-exemplar-assertion'):
            layout.relocate(self.CLS, [(16, 24)], ['static_assert(sizeof(A) == 0x28);'])

    def test_namespaced_bases_and_interior_member_offsets(self):
        header = ('namespace Types { struct Payload { int first; int second; }; '
                  'struct Primary { virtual ~Primary(); }; struct Secondary { int id; }; }')
        cls = ('struct Widget : ::Types::Primary, Types::Secondary { '
               'Types::Payload value; };')
        text, _, _ = layout.relocate(cls, [(12, 20), (16, 24)], headers=[header])
        self.assertIn('padTwinC[8]', text)

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
