"""Public/synthetic declaration kit, shared renderer, and header capability index tests."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import declaration_kit as kit
import header_index as hi
import unit_skeleton as us
from contrib_screen import screen, screen_tree
import lint_reconstruction as lint
from source_digest import include_closure

BUILD = json.loads((ROOT / 'builds/target.json').read_text())['build_id']
LABEL = 'COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)'


def fact(bases, size, virtuals):
    return dict(bases=bases, size=size, virtuals=virtuals, label=LABEL,
                source='CharmedBaryon/CommonLibSSE-NG', license='MIT')


class CommunityParser(unittest.TestCase):
    def test_strips_bodies_attributes_and_prose_retains_signatures(self):
        text = '''namespace RE {
class Example : public Parent {
public:
 virtual ~Example() = default; // 00
 [[nodiscard]] virtual const Other* Query(const Item& a_item) const { return nullptr; } // 04
 SKYRIM_REL_VR_VIRTUAL void Update(Item* a_item); // 05 - { return; }
};
static_assert(sizeof(Example) == 0x20);
static_assert(sizeof(Example) == 0x40);
}'''
        info = kit.source_class(text, 'Example')
        self.assertEqual(info['bases'], ['Parent'])
        self.assertEqual(info['size'], 0x20)
        self.assertEqual([v['slot'] for v in info['virtuals']], [0, 4, 5])
        self.assertEqual(info['virtuals'][1]['declaration'], 'virtual const Other* Query(const Item& a_item) const;')
        self.assertNotIn('return', str(info))
        self.assertEqual(kit.source_class('struct FORM; class X { };', 'X')['reference_kinds']['FORM'], 'struct')

    def test_pinned_reader_uses_git_blob_never_working_tree(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / kit.SOURCES[0][1]).mkdir(parents=True)
            result = subprocess.CompletedProcess([], 0, 'class Widget { virtual void Go(); // 01\n};', '')
            with patch.object(kit.subprocess, 'run', return_value=result) as run:
                info = kit.pinned_class(root, 'Widget')
            self.assertEqual(info['revision'], kit.NG_REV)
            self.assertIn(kit.NG_REV + ':include/RE/W/Widget.h', run.call_args.args[0])


class ContributorRenderer(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        base = self.root / 'reconstruction/declarations/BaseWidget.h'
        base.parent.mkdir(parents=True)
        base.write_text('class BaseWidget { public: virtual ~BaseWidget(); virtual bool Ready() const; '
                        'void* storage; };\nstatic_assert(sizeof(BaseWidget) == 0x10, "size");\n')
        recipes = self.root / 'reconstruction/recipes'
        recipes.mkdir()
        (recipes / 'test.json').write_text('{"flags": ["/Ireconstruction"]}')
        self.facts = {
            'BaseWidget': fact([], 0x10, [dict(slot=0, name='~BaseWidget', declaration='virtual ~BaseWidget();'),
                                        dict(slot=1, name='Ready', declaration='virtual bool Ready() const;')]),
            'Widget': fact(['BaseWidget'], 0x20, [dict(slot=0, name='~Widget', declaration='~Widget() override;'),
                                               dict(slot=2, name='Query', declaration='virtual Other* Query(const Item& a_item);'),
                                               dict(slot=3, name='Reset', declaration='virtual void Reset();')])}

    def files(self, functions=None, **options):
        functions = functions or [dict(build_id=BUILD, rva=0x1000, size=4, name='Widget::Query',
                                      name_source='CommonLibSSE-NG', evidence='findings/synthetic.md')]
        with patch.object(kit, 'pinned_class', side_effect=lambda root, cls: self.facts.get(cls)), \
                patch.object(kit, 'notice', return_value='// synthetic MIT notice'):
            return us.contributor_files(self.root, functions, 'Widget', 'misc', 'synthetic tester',
                                        'reconstruction/recipes/test.json', **options)

    def test_origin_metadata_survives_shared_renderer_and_refuses_invalid_input(self):
        _hp, h, _cp, cpp, _hints, _recipe = self.files()
        for text in (h, cpp):
            self.assertIn('SKELETON_TODO_CODE_ORIGIN', text)
        _hp, h, _cp, cpp, _hints, _recipe = self.files(code_origin='original synthetic fixture')
        for text in (h, cpp):
            self.assertIn('Code origin: original synthetic fixture', text)
            self.assertNotIn('SKELETON_TODO_CODE_ORIGIN', text)
        with self.assertRaisesRegex(us.SkeletonError, 'nonempty single-line'):
            self.files(code_origin='synthetic\ninvalid')

    def test_all_functions_typed_base_slots_reference_declarations_and_markers(self):
        fns = [dict(build_id=BUILD, rva=rva, size=4, name='Widget::' + method,
                    evidence='findings/synthetic.md') for rva, method in ((0x1000, 'Query'), (0x1100, 'Reset'))]
        hp, h, cp, cpp, _hints, recipe = self.files(fns)
        self.assertIn('class Widget : public BaseWidget', h)
        self.assertIn('#include "declarations/BaseWidget.h"', h)
        self.assertIn('class Other;', h)
        self.assertIn('class Item;', h)
        self.assertIn('virtual Other* Query(const Item& a_item);', h)
        self.assertIn('Other* Widget::Query(const Item& a_item)', cpp)
        self.assertIn('void Widget::Reset()', cpp)
        self.assertEqual(cpp.count(us.BODY_MARKER), 2)
        self.assertIn(us.ORIGIN_MARKER, cpp)
        self.assertNotIn('EXE_RTTI', h)
        self.assertNotIn('../', h + cpp)
        self.assertLess(h.index('~Widget()'), h.index('Query('))
        self.assertIn('static_assert(sizeof(Widget) == 0x20', h)
        self.assertEqual(screen(h.encode(), hp), [])
        self.assertEqual(screen(cpp.encode(), cp), [])
        for name, text in ((hp, h), (cp, cpp)):
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text)
        self.assertEqual(include_closure(self.root, cp), sorted([hp, cp, 'reconstruction/declarations/BaseWidget.h']))
        self.assertEqual(screen_tree(self.root, cp), [])
        self.assertTrue(any('skeleton not filled' in p.lower() for p in lint.lint_file(self.root, cp, BUILD)))

    def test_non_compared_virtual_is_preserved(self):
        _hp, h, _cp, cpp, _hints, recipe = self.files()
        self.assertIn('virtual void Reset();  // 03', h)
        self.assertNotIn('Widget::Reset()', cpp)

    def test_unsafe_existing_include_is_not_selected(self):
        base = self.root / 'reconstruction/declarations/BaseWidget.h'
        base.write_text(base.read_text().replace('class BaseWidget', '#include "../outside/Evil.h"\nclass BaseWidget'))
        _hp, h, _cp, cpp, _hints, recipe = self.files()
        self.assertNotIn('#include "declarations/BaseWidget.h"', h)
        self.assertIn('class BaseWidget', h)
        self.assertNotIn('../', h + cpp)

    def test_signature_conflict_is_explicit_and_unpublishable(self):
        self.facts['Widget']['virtuals'].append(dict(slot=1, name='Ready', declaration='bool Ready(int a_mode) const override;'))
        _hp, h, _cp, _cpp, hints, _recipe = self.files()
        self.assertIn('SKELETON_TODO_SIGNATURE', h)
        self.assertTrue(any('slot 1: signature differs' in hint for hint in hints))

    def test_inline_and_out_of_line_complete_cleanup_alternatives(self):
        for form in ('inline', 'out-of-line'):
            fn = dict(build_id=BUILD, rva=0x1000, size=20, name='Widget::~Widget',
                      evidence='findings/synthetic.md',
                      destructor={'kind': 'scalar deleting destructor', 'complete_form': form})
            _hp, h, _cp, cpp, _hints, recipe = self.files([fn])
            self.assertIn('virtual ~Widget();', h)
            self.assertIn('Widget::Widget()', cpp)  # emit the deleting wrapper
            self.assertEqual('Widget::~Widget()' in cpp, form == 'inline')
            self.assertNotIn(us.BODY_MARKER, cpp)
            self.assertIn(us.ORIGIN_MARKER, cpp)  # still needs truthful origin disclosure

    def test_missing_sources_preserve_unknowns(self):
        self.facts = {}
        _hp, h, _cp, cpp, _hints, recipe = self.files()
        self.assertIn('TODO signature: no community declaration', h)
        self.assertIn(us.BODY_MARKER, cpp)
        self.assertNotIn('static_assert(sizeof(Widget)', h)


class PublishedKit(unittest.TestCase):
    def test_root_include_recipes_are_additive_and_admitted(self):
        from source_digest import recipe_flag_problem
        for path in (ROOT / 'reconstruction/recipes').glob('*-root-includes.json'):
            original = path.with_name(path.name.replace('-root-includes', ''))
            before, after = json.loads(original.read_text()), json.loads(path.read_text())
            self.assertEqual(after, dict(before, flags=before['flags'] + ['/Ireconstruction']))
            self.assertIsNone(recipe_flag_problem(after['flags']))
            self.assertEqual(us.root_include_recipe(ROOT, original.relative_to(ROOT).as_posix()),
                             path.relative_to(ROOT).as_posix())

    def test_all_kit_headers_are_lint_and_screen_clean(self):
        for cls in kit.CLASSES:
            name = f'reconstruction/declarations/{cls}.h'
            blob = (ROOT / name).read_bytes()
            with self.subTest(cls=cls):
                self.assertEqual(lint.lint_file(ROOT, name, BUILD), [])
                self.assertEqual(screen(blob, name), [])
                self.assertTrue(b'MIT License' in blob or b'SPDX-License-Identifier: MIT (CommonLibSSE-NG' in blob)
                self.assertIn(b'Copyright (c) 2018 Ryan-rsm-McKenzie', blob)
                self.assertIn(b'COMMUNITY(', blob)
                self.assertNotIn(b'EXE_RTTI', blob)
                self.assertNotIn(b'../', blob)

    def test_slot4_is_a_pointer_and_reference_templates_are_opaque(self):
        ni = hi.entries((ROOT / 'reconstruction/declarations/NiObject.h').read_text())['NiObject']
        self.assertEqual(ni['slots']['4']['declaration'], 'virtual NiSwitchNode* AsSwitchNode();')
        text = (ROOT / 'reconstruction/declarations/NiNode.h').read_text()
        self.assertIn('NiPointer<NiAVObject>& a_childOut', text)
        self.assertIn('virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail = false);', text)
        sink = (ROOT / 'reconstruction/declarations/BSTEventSink.h').read_text()
        self.assertIn('ProcessEvent(const Event* a_event, BSTEventSource<Event>* a_eventSource) = 0;', sink)

    @unittest.skipUnless(shutil.which('clang++'), 'C++ syntax compiler unavailable')
    def test_kit_and_real_pointer_override_compile_as_cxx14(self):
        for cls in kit.CLASSES:
            code = f'#include "declarations/{cls}.h"\n'
            if cls == 'TESForm':
                code += 'static_assert(sizeof(FormType) == sizeof(int), "community enum type");\n'
            if cls == 'NiNode':
                code += 'class SwitchExample : public NiNode { NiSwitchNode* AsSwitchNode() override; };\n'
            result = subprocess.run(['clang++', '-std=c++14', '-fsyntax-only', '-x', 'c++', '-Ireconstruction', '-'],
                                    input=code, cwd=ROOT, capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)


class HeaderIndex(unittest.TestCase):
    def test_partial_signature_gap_and_missing_slot(self):
        text = '''class Parent { public:
// community declaration: virtual Child* AsChild();
virtual void AsChild(); // 04
virtual void Unk_05(); // 05
std::uint32_t flags;
};'''
        info = hi.entries(text)['Parent']
        self.assertEqual(info['slots']['4']['name'], 'AsChild')
        self.assertEqual(info['fields'], [dict(name='flags', declaration='std::uint32_t flags;')])
        self.assertEqual(info['gaps'][0]['reason'], 'signature differs from community declaration')
        self.assertIn(3, info['undeclared_slots'])
        self.assertEqual(info['gaps'][1]['reason'], 'unknown placeholder signature')

    def test_index_reports_existing_header_gaps_without_editing(self):
        advice = hi.advice(ROOT, 'NiNode', 'AsNode', 3)
        self.assertTrue(any('reconstruction/netimmerse/NiNode.h' in line and 'signature differs' in line for line in advice))
        self.assertTrue(any('reconstruction/declarations/NiNode.h' in line for line in advice))


if __name__ == '__main__':
    unittest.main()
