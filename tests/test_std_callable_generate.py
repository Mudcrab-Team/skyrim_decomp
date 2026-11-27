"""Standard function implementation slots in an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_code_rules
import contrib_screen
import lint_reconstruction
import std_callable_generate as generator
from pecoff import PeImage
from synthetic_pecoff import assemble_pe

BASE = 0x140000000
LEA = bytes.fromhex('48 8d 05')
COPY_TAIL = bytes.fromhex('48 89 02 48 8b 41 08 48 89 42 08 48 8b c2 c3')
VECTOR_TAIL = bytes.fromhex('48 89 02 48 8b c2 0f 10 41 08 0f 11 42 08 c3')
DELETE_HEAD = bytes.fromhex('84 d2 74 0a ba')
RDATA = 0x2000


def copy_slot(rva, table):
    disp = table - (rva + 7)
    code = LEA + struct.pack('<i', disp) + COPY_TAIL
    assert len(code) == 22
    return code


def vector_slot(rva, table):
    code = LEA + struct.pack('<i', table - (rva + 7)) + VECTOR_TAIL
    assert len(code) == 22
    return code


def empty_slot(rva, table):
    return LEA + struct.pack('<i', table - (rva + 7)) + bytes.fromhex('48 89 02 48 8b c2 c3')


def scalar_slot(rva, table):
    tail = COPY_TAIL[:11] + bytes.fromhex('48 8b 41 10 48 89 42 10') + COPY_TAIL[11:]
    return LEA + struct.pack('<i', table - (rva + 7)) + tail


def delete_slot(rva, size, callee):
    code = DELETE_HEAD + struct.pack('<I', size) + bytes([0xe9]) + struct.pack('<i', callee - (rva + 14)) + bytes([0xc3])
    assert len(code) == 15
    return code


class StdCallableTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_reads_slots_and_validates_callee(self):
        text = bytearray(0x400)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        place(0x1000, bytes([0xc3]))
        place(0x1040, copy_slot(0x1040, RDATA))
        place(0x1080, copy_slot(0x1080, RDATA))
        place(0x10c0, copy_slot(0x10c0, RDATA + 0x20))        # table does not name this entry
        place(0x1240, vector_slot(0x1240, RDATA + 0x40))
        place(0x1280, vector_slot(0x1280, RDATA + 0x40))
        place(0x12a0, empty_slot(0x12a0, RDATA + 0x60))
        place(0x12c0, empty_slot(0x12c0, RDATA + 0x70))
        place(0x12e0, scalar_slot(0x12e0, RDATA + 0xf0))
        place(0x1100, delete_slot(0x1100, 0x10, 0x1000))
        place(0x1140, delete_slot(0x1140, 0x20, 0x1000))
        place(0x1180, delete_slot(0x1180, 0x14, 0x1000))      # size is not a whole number of words
        place(0x11c0, delete_slot(0x11c0, 0x10, 0x1001))      # callee is not an indexed function
        place(0x1200, delete_slot(0x1200, 0x10, 0x1000))      # overlaps a matched entry

        rdata = bytearray(0x120)
        struct.pack_into('<QQ', rdata, 0, BASE + 0x1040, BASE + 0x1080)
        struct.pack_into('<QQ', rdata, 0x20, BASE + 0x1f00, BASE + 0x1f10)
        struct.pack_into('<QQ', rdata, 0x40, BASE + 0x1240, BASE + 0x1280)
        struct.pack_into('<QQQ', rdata, 0x58, BASE + 0x2080, BASE + 0x12a0, 0)
        struct.pack_into('<Q', rdata, 0x70, BASE + 0x12c0)  # no complete object locator
        struct.pack_into('<QQQ', rdata, 0xe8, BASE + 0x2080, 0, BASE + 0x12e0)
        struct.pack_into('<6I', rdata, 0x80, 1, 0, 0, 0x20a0, 0, 0x2080)
        owner = b'.?AV?$_Func_impl_no_alloc@UToy@@X$$V@std@@\0'
        rdata[0xb0:0xb0 + len(owner)] = owner
        image = PeImage(assemble_pe([
            ('.text', 0x1000, bytes(text), 0x60000020),
            ('.rdata', RDATA, bytes(rdata), 0x40000040),
        ], (0, 0)))
        inventory = {0x11ff: dict(size=2, status='matched')}
        found = generator.discover(image, extents, inventory)
        self.assertEqual(
            found,
            [
                generator.Slot(0x1040, 22, generator.COPY, 'copy', table=RDATA),
                generator.Slot(0x1080, 22, generator.COPY, 'move', table=RDATA),
                generator.Slot(0x1240, 22, generator.COPY, 'copy', table=RDATA + 0x40, state=16),
                generator.Slot(0x1280, 22, generator.COPY, 'move', table=RDATA + 0x40, state=16),
                generator.Slot(0x12a0, 14, generator.EMPTY_COPY, 'copy', table=RDATA + 0x60, state=0),
                generator.Slot(0x12e0, 30, generator.SCALAR_COPY, 'move', table=RDATA + 0xf0, state=16),
                generator.Slot(0x1100, 15, generator.DELETE, 'delete', object_size=0x10, callee=0x1000),
                generator.Slot(0x1140, 15, generator.DELETE, 'delete', object_size=0x20, callee=0x1000),
            ],
        )

    def test_symbols_follow_the_standard_template_mangling(self):
        copy = generator.Slot(0x1040, 22, generator.COPY, 'copy', table=RDATA)
        move = generator.Slot(0x1080, 22, generator.COPY, 'move', table=RDATA)
        delete = generator.Slot(0x1100, 15, generator.DELETE, 'delete', object_size=0x18, callee=0x1000)
        self.assertEqual(copy.callable, move.callable)
        self.assertEqual(copy.symbol, '?_Copy@?$_Func_impl_no_alloc@UCallableTable2000@@X$$V@std@@EEBAPEAV?$_Func_base@X$$V@2@PEAX@Z')
        self.assertEqual(move.symbol, '?_Move@?$_Func_impl_no_alloc@UCallableTable2000@@X$$V@std@@EEAAPEAV?$_Func_base@X$$V@2@PEAX@Z')
        self.assertEqual(delete.symbol, '?_Delete_this@?$_Func_impl_no_alloc@UCallableObject1100@@X$$V@std@@EEAAX_N@Z')
        self.assertEqual(delete.bytes, 0x10)
        self.assertEqual(copy.bytes, 8)
        self.assertEqual(generator.Slot(0x1240, 22, generator.COPY, 'copy', table=RDATA, state=16).bytes, 16)

    def test_emit_produces_clean_units_and_bindings(self):
        copy = generator.Slot(0x1040, 22, generator.COPY, 'copy', table=RDATA)
        move = generator.Slot(0x1080, 22, generator.COPY, 'move', table=RDATA)
        delete = generator.Slot(0x1100, 15, generator.DELETE, 'delete', object_size=0x18, callee=0x1000)
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for family, members in ((generator.COPY, [copy, move]), (generator.DELETE, [delete])):
                task, directory = generator.emit(root, family, members, 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                for m in members:
                    self.assertIn(f'// 0x{m.rva:x} std::_Func_impl_no_alloc<{m.callable}, void>::{m.method}', text)
                    self.assertIn(f'// CI hash: 0x{m.rva:x} {m.symbol}', text)
                    self.assertEqual(symbols[m.symbol], dict(rva=m.rva, size=m.size))
                self.assertEqual(text.count(f'struct {members[0].callable} : StdCallableState<{members[0].bytes}> {{}};'), 1)
                self.assertEqual(text.count('template class std::_Func_impl_no_alloc<'), 1)
                self.assertEqual(contrib_screen.screen_tree(root, task['compiled']), [])
                for path in (src, hdr):
                    self.assertEqual(lint_reconstruction.lint_file(
                        root, path.relative_to(root).as_posix(), 'synthetic', compact=True), [])
            self.assertEqual(symbols[generator.OPERATOR_DELETE], dict(rva=0x1000, size=None))
            units = check_code_rules.analyse(root)
            match_findings = [(name, f) for name, unit in units.items()
                              for f in unit.findings if f[1] in check_code_rules.MATCH_RULES]
            self.assertEqual(match_findings, [])


if __name__ == '__main__':
    unittest.main()
