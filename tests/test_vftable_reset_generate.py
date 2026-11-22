"""Polymorphic table-reset wrappers in an original synthetic PE image."""
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
import vftable_reset_generate as generator
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


def rel32(opcode, at, target):
    return opcode + struct.pack('<i', target - (at + len(opcode) + 4))


def table_init(rva, table):
    return rel32(bytes.fromhex('48 8d 05'), rva, table) + bytes.fromhex('48 89 01 48 8b c1 c3')


def table_tail(rva, table, cleanup):
    head = rel32(bytes.fromhex('48 8d 05'), rva, table) + bytes.fromhex('48 89 01')
    return head + rel32(bytes([0xe9]), rva + len(head), cleanup)


def table_dealloc(rva, table, object_size, dealloc, *, prolog=bytes.fromhex('40 53')):
    head = prolog + bytes.fromhex('48 83 ec 20')
    lea = rel32(bytes.fromhex('48 8d 05'), rva + len(head), table)
    mid = (bytes.fromhex('48 8b d9 48 89 01 f6 c2 01 74 0a ba')
           + struct.pack('<I', object_size))
    call_at = rva + len(head) + len(lea) + len(mid)
    call = rel32(bytes([0xe8]), call_at, dealloc)
    return head + lea + mid + call + bytes.fromhex('48 8b c3 48 83 c4 20 5b c3')


def table_cleanup_dealloc(rva, table, cleanup, object_size, dealloc):
    head = bytes.fromhex('48 89 5c 24 08 57 48 83 ec 20')
    lea = rel32(bytes.fromhex('48 8d 05'), rva + len(head), table)
    mid1 = bytes.fromhex('8b da 48 89 01 48 8b f9')
    call1_at = rva + len(head) + len(lea) + len(mid1)
    call1 = rel32(bytes([0xe8]), call1_at, cleanup)
    mid2 = bytes.fromhex('f6 c3 01 74 0d ba') + struct.pack('<I', object_size) + bytes.fromhex('48 8b cf')
    call2_at = call1_at + len(call1) + len(mid2)
    call2 = rel32(bytes([0xe8]), call2_at, dealloc)
    return head + lea + mid1 + call1 + mid2 + call2 + bytes.fromhex('48 8b 5c 24 30 48 8b c7 48 83 c4 20 5f c3')


class VftableResetTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_validates_all_four_shapes_and_sections(self):
        text = bytearray(1024)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        place(0x1000, bytes([0xc3]))  # dealloc
        place(0x1010, bytes([0xc3]))  # cleanup
        place(0x1040, table_init(0x1040, 0x2000))
        place(0x1060, table_tail(0x1060, 0x2008, 0x1010))
        place(0x1080, table_dealloc(0x1080, 0x2010, 32, 0x1000))
        place(0x10c0, table_cleanup_dealloc(0x10c0, 0x2018, 0x1010, 136, 0x1000))
        place(0x1110, table_init(0x1110, 0x3000))                                   # writable .data table rejected
        place(0x1130, table_init(0x1130, 0x1000))                                   # executable .text table rejected
        place(0x1150, table_tail(0x1150, 0x2008, 0x1011))                           # unindexed cleanup
        place(0x1170, table_tail(0x1170, 0x2008, 0x1060))                           # member-to-member tail call
        place(0x1190, table_dealloc(0x1190, 0x2010, 0, 0x1000))                     # zero size
        place(0x11d0, table_dealloc(0x11d0, 0x2010, 32, 0x1000, prolog=bytes([0x53])))  # 1-byte push
        place(0x1210, table_cleanup_dealloc(0x1210, 0x2018, 0x1000, 16, 0x1000))    # cleanup == dealloc
        place(0x1260, table_init(0x1260, 0x2000))                                   # overlaps matched entry

        image = PeImage(assemble_pe([
            ('.text', 0x1000, text, 0x60000020),
            ('.rdata', 0x2000, bytes(64), 0x40000040),
            ('.data', 0x3000, bytes(64), 0xc0000040),
        ], (0, 0)))
        inventory = {0x125f: dict(size=2, status='matched')}
        self.assertEqual(
            generator.discover(image, extents, inventory),
            [
                generator.Member(0x1040, 14, generator.INIT, 0x2000),
                generator.Member(0x1060, 15, generator.TAIL, 0x2008, cleanup=0x1010),
                generator.Member(0x1080, 43, generator.DEALLOC, 0x2010, object_size=32, callee=0x1000),
                generator.Member(0x10c0, 62, generator.CLEANUP_DEALLOC, 0x2018,
                                 object_size=136, callee=0x1000, cleanup=0x1010),
            ],
        )

    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_shards_large_families(self):
        count = generator.SHARD_SIZE + 2
        text = bytearray(0x10 * (count + 2))
        extents = {}
        for idx in range(count):
            rva = 0x1020 + idx * 0x10
            code = table_init(rva, 0x2000)
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code
        image = PeImage(assemble_pe([
            ('.text', 0x1000, text, 0x60000020),
            ('.rdata', 0x2000, bytes(32), 0x40000040),
        ], (0, 0)))
        members = generator.discover(image, extents, {})
        self.assertEqual(len(members), count)
        self.assertEqual([m.family for m in members[:generator.SHARD_SIZE]],
                         [f'{generator.INIT}1'] * generator.SHARD_SIZE)
        self.assertEqual([m.family for m in members[generator.SHARD_SIZE:]],
                         [f'{generator.INIT}2'] * 2)

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Member(0x1040, 14, generator.INIT, 0x2000),
            generator.Member(0x1060, 15, generator.TAIL, 0x2008, cleanup=0x1010),
            generator.Member(0x1080, 43, generator.DEALLOC, 0x2010, object_size=32, callee=0x1000),
            generator.Member(0x10c0, 62, generator.CLEANUP_DEALLOC, 0x2018,
                             object_size=136, callee=0x1000, cleanup=0x1010),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                self.assertIn(f'object->table = &TableTarget{m.table:x};', text)
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[m.symbol], dict(rva=m.rva, size=m.size))
                self.assertEqual(symbols[f'TableTarget{m.table:x}'], dict(rva=m.table, size=None))
                self.assertEqual(contrib_screen.screen_tree(root, task['compiled']), [])
                for path in (src, hdr):
                    self.assertEqual(lint_reconstruction.lint_file(
                        root, path.relative_to(root).as_posix(), 'synthetic', compact=True), [])
            units = check_code_rules.analyse(root)
            match_findings = [(name, f) for name, unit in units.items()
                              for f in unit.findings if f[1] in check_code_rules.MATCH_RULES]
            self.assertEqual(match_findings, [])


if __name__ == '__main__':
    unittest.main()
