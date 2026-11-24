"""Tests for tools/rename_planner.py on an invented repository, CrashLogger table and linker map."""
import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import rename_planner as rp  # noqa: E402

CL = rp.CRASHLOGGER_LABEL
MAP_LINES = [
    ' 0001:00000000       ?Spin@Widget@@QAEXH@Z   00401000 f    lib:widget.obj',
    ' 0001:00000010       ?Count@Widget@@QBEHXZ   00401010 f    lib:widget.obj',
    ' 0001:00000020       ?Alpha@Gadget@@QAEXXZ   00401020 f    lib:gadget.obj',
    ' 0001:00000020       ?Beta@Gadget@@QAEXXZ   00401020 f    lib:gadget.obj',
    ' 0001:00000030       ?Peek@Widget@@QBEHXZ   00401030 f    lib:widget.obj',
]


def entry(rva, name, size=16, origin='GUESS'):
    return {'id': f'b-0x{rva:x}', 'build_id': 'b', 'rva': rva, 'size': size, 'status': 'matched', 'named': False,
            'name': name, 'name_origin': origin, 'name_source': 'GUESS(low): placeholder', 'owner': 'o'}


class Pure(unittest.TestCase):
    def test_arity_counts_after_this(self):
        self.assertEqual(rp.prototype_arity('thiscall', 'void (Widget*, int, Gadget*)'), 2)
        self.assertEqual(rp.prototype_arity('thiscall', 'void (Widget*)'), 0)
        self.assertEqual(rp.prototype_arity('cdecl', 'int (int, int)'), 2)
        self.assertIsNone(rp.prototype_arity('thiscall', 'not a prototype'))

    def test_this_class_drops_flattening_suffix(self):
        self.assertEqual(rp.this_class('thiscall', 'void (Widget_0a1b2c3d*, int)'), 'Widget')
        self.assertIsNone(rp.this_class('cdecl', 'void (Widget*)'))

    def test_split_params_keeps_nested_commas(self):
        self.assertEqual(rp.split_params('int a, Map<int, int> b'), ['int a', 'Map<int, int> b'])

    def test_final_scope(self):
        self.assertEqual(rp.final_scope('Ns::Widget::Spin'), ('Widget', 'Spin'))
        self.assertEqual(rp.final_scope('Spin'), (None, 'Spin'))

    def test_label_state(self):
        texts = {'.cpp': '// 0x10 Widget::Spin\n// Widget::Spin: GUESS(low)\n', '.h': None}
        self.assertEqual(rp.label_state(texts, 'Widget::Spin', 'Spin'), 'guess')
        texts['.cpp'] += f'// Spin: {CL}\n'
        self.assertEqual(rp.label_state(texts, 'Widget::Spin', 'Spin'), 'labelled')
        self.assertEqual(rp.label_state({'.cpp': '// 0x10 Widget::Spin\n', '.h': ''}, 'Widget::Spin', 'Spin'), 'none')

    def test_set_label_moves_name_out_of_guess_list(self):
        texts = {'.cpp': '// 0x10 Widget::Spin\n#include "W.h"\n', '.h': '// Widget, Widget::Spin, pad: GUESS(low); note\n#pragma once\n'}
        out = rp.set_label(dict(texts), 'Widget::Spin', 'Spin')
        self.assertIn('// Widget, pad: GUESS(low); note', out['.h'])
        self.assertIn(f'// Widget::Spin: {CL} {rp.SYMBOLS_LABEL}', out['.h'])
        self.assertEqual(out['.cpp'], texts['.cpp'])

    def test_set_label_adds_a_line_when_no_label_covers_the_name(self):
        out = rp.set_label({'.cpp': '// 0x10 Widget::Spin\n#include "W.h"\n', '.h': '#pragma once\n'}, 'Widget::Spin', 'Spin')
        self.assertEqual(out['.cpp'].split('\n')[1], f'// Widget::Spin: {CL} {rp.SYMBOLS_LABEL}')

    def test_labelled_name_is_left_alone(self):
        texts = {'.cpp': f'// 0x10 Widget::Spin\n// Widget::Spin: {CL}\n', '.h': None}
        self.assertEqual(rp.set_label(dict(texts), 'Widget::Spin', 'Spin'), texts)

    def test_header_names(self):
        texts = {'.cpp': '// 0x1f0 Widget::Spin(int a) const\n// 0x200 Free\n#include "x"\n// 0x300 Late\n', '.h': None}
        self.assertEqual(rp.header_names(texts), {0x1f0: ('Widget::Spin', '(int a)'), 0x200: ('Free', None)})


class Fixture(unittest.TestCase):
    """A one-unit repository: Widget::Function1000 may become Widget::Spin."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.addCleanup(self.tmp.cleanup)
        (self.root / 'data').mkdir()
        (self.root / 'reconstruction' / 'area').mkdir(parents=True)
        for kind in ('names', 'prototypes', 'boundaries'):
            (self.root / rp.CRASHLOGGER / kind).mkdir(parents=True)
        self.map = self.root / 'fake.map'
        self.map.write_text('\n'.join(MAP_LINES) + '\n', encoding='latin-1')
        self.functions = []

    def add(self, rva, name, cl_name, proto=None, size=16, cl_size=None, unit='area/Widget', cpp=None, header=None):
        self.functions.append(entry(rva, name, size))
        with open(self.root / rp.CRASHLOGGER / 'names' / '00.tsv', 'a') as f:
            f.write(f'0x{rva:x}\t{cl_name}\n')
        with open(self.root / rp.CRASHLOGGER / 'boundaries' / '00.tsv', 'a') as f:
            f.write(f'{rva:x}\t{(cl_size or size):x}\n')
        if proto:
            with open(self.root / rp.CRASHLOGGER / 'prototypes' / '00.tsv', 'a') as f:
                f.write(f'0x{rva:x}\tthiscall\t{proto}\n')
        with open(self.root / 'reconstruction' / 'INDEX.md', 'a') as f:
            f.write(f'| `{unit}` | `{name}` (GUESS) | `b` / `0x{rva:x}` / {size} | `r` | `x` | matched | full | - |\n')
        if cpp is not None:
            (self.root / 'reconstruction' / f'{unit}.cpp').write_text(cpp)
            (self.root / 'reconstruction' / f'{unit}.h').write_text(header or '#pragma once\n')

    def plan(self):
        (self.root / 'data' / 'progress.json').write_text(json.dumps({'functions': self.functions}))
        ctx = rp.build_context(self.root, self.map)
        return {r['rva']: r for r in rp.plan(ctx)}, ctx

    def widget_unit(self, member='Function1000'):
        return dict(cpp=f'// 0x1000 Widget::{member}\n#include "Widget.h"\nvoid Widget::{member}(int a) {{}}\n',
                    header=f'// Widget::{member}: GUESS(low)\n#pragma once\nstruct Widget {{ void {member}(int a); }};\n')

    def test_placeholder_member_is_renamed(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', proto='void (Widget*, int)', **self.widget_unit())
        rows, ctx = self.plan()
        self.assertEqual(rows['0x1000']['verdict'], 'rename')
        self.assertEqual(rows['0x1000']['new_member'], 'Spin')
        self.assertTrue(rows['0x1000']['has_prototype'])
        changed = rp.apply_source(list(rows.values()), ctx)
        self.assertEqual(changed, [('area/Widget', ['0x1000'])])
        cpp = (self.root / 'reconstruction/area/Widget.cpp').read_text()
        header = (self.root / 'reconstruction/area/Widget.h').read_text()
        self.assertIn('// 0x1000 Widget::Spin', cpp)
        self.assertIn('void Widget::Spin(int a)', cpp)
        self.assertNotIn('Function1000', cpp + header)
        self.assertIn(f'// Widget::Spin: {CL} {rp.SYMBOLS_LABEL}', header)

    def test_not_in_map_is_not_corroborated(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Missing', **self.widget_unit())
        rows, _ = self.plan()
        self.assertFalse(rows['0x1000']['corroborated'])
        self.assertEqual(rows['0x1000']['reason'], 'not-corroborated')

    def test_other_class_is_an_ownership_conflict(self):
        self.add(0x1000, 'Child::Function1000', 'Widget::Spin', **dict(
            cpp='// 0x1000 Child::Function1000\n#include "Child.h"\n', header='#pragma once\n', unit='area/Child'))
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'ownership-conflict')

    def test_size_difference_is_reported(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', size=16, cl_size=32, **self.widget_unit())
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'size-differs')

    def test_folded_map_names_are_ambiguous(self):
        self.add(0x2000, 'Gadget::Function2000', 'Gadget::Alpha', unit='area/Gadget',
                 cpp='// 0x2000 Gadget::Function2000\n#include "Gadget.h"\n', header='#pragma once\n')
        rows, _ = self.plan()
        self.assertEqual(rows['0x2000']['reason'], 'alias-or-overload')

    def test_this_differs_blocks_a_rename(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', proto='void (Gadget*, int)', **self.widget_unit())
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'this-differs')

    def test_arity_mismatch_blocks_a_rename(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', proto='void (Widget*, int, int)', **self.widget_unit())
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'prototype-arity')

    def test_reference_outside_the_unit_blocks_a_rename(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', **self.widget_unit())
        (self.root / 'reconstruction/area/Other.cpp').write_text('void f(Widget* w) { w->Function1000(1); }\n')
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'referenced-elsewhere')

    def test_collision_with_an_existing_member_blocks_a_rename(self):
        unit = self.widget_unit()
        unit['header'] += 'struct Other { int Spin; };\n'
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', **unit)
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'name-collision')

    def test_generated_family_is_never_renamed(self):
        self.add(0x1000, 'Static1000::initializer', 'Widget::Spin', unit='area/Static1000',
                 cpp='// 0x1000 Static1000::initializer\n#include "Static1000.h"\n', header='#pragma once\n')
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['reason'], 'generated-family')

    def test_existing_name_with_a_label_only_syncs_the_inventory(self):
        unit = self.widget_unit('Spin')
        unit['header'] = f'// Widget::Spin: {CL}\n' + unit['header']
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', **unit)
        rows, _ = self.plan()
        self.assertEqual(rows['0x1000']['verdict'], 'sync-inventory')

    def test_existing_name_with_a_guess_label_gets_the_labels(self):
        self.add(0x1000, 'Widget::Spin', 'Widget::Spin', **self.widget_unit('Spin'))
        rows, ctx = self.plan()
        self.assertEqual(rows['0x1000']['verdict'], 'label-source')
        rp.apply_source(list(rows.values()), ctx)
        header = (self.root / 'reconstruction/area/Widget.h').read_text()
        self.assertIn(f'// Widget::Spin: {CL} {rp.SYMBOLS_LABEL}', header)
        self.assertNotIn('GUESS', header)

    def test_inventory_update_names_origin_and_source(self):
        self.add(0x1000, 'Widget::Function1000', 'Widget::Spin', **self.widget_unit())
        rows, ctx = self.plan()
        doc = rp.plan_document(list(rows.values()), ctx)
        self.assertEqual(doc['summary']['verdicts'], {'rename': 1})
        self.assertNotIn('00401000', json.dumps(doc))
        self.assertEqual(rp.apply_inventory(doc, self.root), 1)
        entry = json.loads((self.root / 'data/progress.json').read_text())['functions'][0]
        self.assertEqual((entry['name'], entry['name_origin']), ('Widget::Spin', 'CRASHLOGGER_PDB'))
        self.assertIn(rp.SYMBOLS_LABEL, entry['name_source'])

    def test_map_reader_reports_no_addresses(self):
        members, source = rp.read_map(self.map)
        self.assertEqual(members[('Gadget', 'Alpha')], 1)
        self.assertEqual(members[('Widget', 'Spin')], 0)
        self.assertNotIn('0040', json.dumps([list(map(str, members)), source]))


if __name__ == '__main__':
    unittest.main()
