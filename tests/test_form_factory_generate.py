"""Original synthetic RTTI, vtables and destructor bodies. No retail fixture."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import form_factory_generate as gen
from pecoff import PeImage
from synthetic_pecoff import assemble_pe, SCN_CODE, SCN_DATA

IMAGE_BASE = 0x140000000
BASE_NAME = '?$ConcreteFormFactory@VExample@@$04@@'
OBJECT_NAME = '?$ConcreteObjectFormFactory@VExample@@$04$00$0CA@@@'
SYMBOLS = {gen.DELETE: {'rva': 0x1330}, gen.HANDLER: {'rva': 0x1340}}


def fixture(*, immediate=5, owner=OBJECT_NAME, skip=14, cleanup=0x1320,
            duplicate=False, main_size=None, vptr=None, extra_extent=False, bad_locator=False,
            no_base=False, runtime_overlap=False):
    rdata = bytearray()
    def allocate(blob):
        rdata.extend(bytes(-len(rdata) % 8))
        address = 0x2000 + len(rdata)
        rdata.extend(blob)
        return address

    def packed(fmt, *values):
        return allocate(struct.pack(fmt, *values))

    def descriptor(name):
        return allocate(bytes(16) + ('.?AV' + name).encode('ascii') + bytes(1))

    def vtable(types, slot, invalid=False):
        bases = [packed('<IIiiiI', td, len(types)-n-1, 0, -1, 0, 0) for n, td in enumerate(types)]
        array = packed('<' + 'I'*len(types), *bases)
        hierarchy = packed('<4I', 0, 0, len(types), array)
        col = allocate(bytes(24))
        struct.pack_into('<6I', rdata, col - 0x2000, 1, 0, 0, types[0], hierarchy, col + int(invalid))
        return packed('<8Q', IMAGE_BASE + col, IMAGE_BASE + slot, *([IMAGE_BASE + 0x1300] * 6)) + 8

    interface, base, derived = map(descriptor, (gen.INTERFACE, BASE_NAME, owner))
    ib = vtable([interface], 0x1300)
    cb = vtable([base, interface], 0x1100, no_base)
    vtable([derived, base, interface], 0x1200, bad_locator)
    if duplicate:
        vtable([descriptor('Another@@')], 0x1200)

    text = bytearray(0x400)
    def body(rva):
        code = bytearray()
        def relative(prefix, target):
            code.extend(prefix)
            code.extend(struct.pack('<i', target - (rva + len(code) + 4)))
        code.extend(bytes.fromhex('57 53 48 83 ec 28 8b da 48 8b f9'))
        relative(bytes.fromhex('48 8d 05'), cb if vptr is None else vptr)
        code.extend(bytes.fromhex('48 89 01 b1') + bytes([immediate]))
        relative(bytes([0xe8]), cleanup)
        relative(bytes.fromhex('48 8d 05'), ib)
        code.extend(bytes.fromhex('48 89 07 f6 c3 01 74') + bytes([skip]))
        code.extend(bytes.fromhex('ba 10 00 00 00 48 8b cf'))
        relative(bytes([0xe8]), SYMBOLS[gen.DELETE]['rva'])
        code.extend(bytes.fromhex('90 48 8b c7 48 83 c4 28 5b 5f c3'))
        text[rva-0x1000:rva-0x1000+len(code)] = code
        return len(code)

    sizes = {rva: body(rva) for rva in (0x1100, 0x1200)}
    pdata = b''.join(struct.pack('<3I', r, r+n, 0x4000) for r, n in sizes.items())
    if runtime_overlap:
        pdata += struct.pack('<3I', 0x1204, 0x1208, 0x4000)
    image = assemble_pe([('.text', 0x1000, bytes(text), SCN_CODE),
                         ('.rdata', 0x2000, bytes(rdata), SCN_DATA),
                         ('.pdata', 0x3000, pdata, SCN_DATA),
                         ('.xdata', 0x4000, bytes([1, 0, 0, 0]), SCN_DATA)], (0x3000, len(pdata)))
    sizes.update({r: 1 for r in (0x1300, 0x1320, 0x1330, 0x1340)})
    if main_size:
        sizes[0x1200] = main_size
    if extra_extent:
        sizes[0x1202] = 1
    return PeImage(image), sizes


@unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'iced-x86 is required for decoding')
class FormFactoryTests(unittest.TestCase):
    def rows(self, blocked=lambda r, size: False, **kwargs):
        image, extents = fixture(**kwargs)
        return gen.select(image, extents, {}, blocked, SYMBOLS, 0x1350)

    def test_complete_primary_tables_and_bound_instantiations(self):
        rows = self.rows()
        self.assertEqual([r.rva for r in rows], [0x1100, 0x1200])
        self.assertEqual(rows[1].owner.cpp, 'ConcreteObjectFormFactory<Example, 5, 1, 32>')
        self.assertEqual(rows[0].owner.split, rows[1].owner.split)
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            task, directory = gen.emit(root, rows[1].family, rows[1:], 'synthetic', 'synthetic-bounds')
            self.assertEqual([fn['symbol'] for fn in task['functions']],
                             ['??_G' + OBJECT_NAME + 'UEAAPEAXI@Z'])
            symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
            self.assertEqual(symbols[gen.UNREGISTER]['rva'], 0x1320)
            self.assertEqual(symbols['__std_terminate'], {'rva': 0x1350, 'size': 6})
            self.assertIn('template class ' + rows[1].owner.cpp + ';', (root / task['compiled']).read_text())

    def test_ambiguous_or_inconsistent_derived_entry(self):
        for change in [dict(duplicate=True), dict(main_size=12), dict(extra_extent=True), dict(runtime_overlap=True),
                       dict(bad_locator=True), dict(owner=OBJECT_NAME.replace('$04', '$06'))]:
            with self.subTest(change=change):
                self.assertEqual([r.rva for r in self.rows(**change)], [0x1100])

    def test_missing_parent_table(self):
        self.assertEqual(self.rows(no_base=True), [])

    def test_references_and_branch_targets(self):
        for change in [dict(immediate=6), dict(cleanup=0x1321), dict(vptr=0x2050), dict(skip=1), dict(skip=23)]:
            with self.subTest(change=change):
                self.assertEqual(self.rows(**change), [])

    def test_excluded_interval(self):
        self.assertEqual([r.rva for r in self.rows(blocked=lambda r, n: r <= 0x1202 < r+n)], [0x1100])


class RTTINumberTests(unittest.TestCase):
    def test_decoration_is_canonical_and_bounded(self):
        for invalid in ['$0F@@@', '$0AA@@@', '$0BAA@@@', '$0?1@@', '$00$00$00@@']:
            self.assertIsNone(gen.parse_factory(BASE_NAME.replace('$04@@', invalid)))
        self.assertEqual(gen.parse_factory(BASE_NAME.replace('$04@@', '$09@@')).args, (10,))
        self.assertEqual(gen.parse_factory(BASE_NAME.replace('$04@@', '$0A@@@')).args, (0,))
