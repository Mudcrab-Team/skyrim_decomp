"""Guarded static-callback wrappers in an original synthetic PE image."""
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
import guarded_callback_generate as generator
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


def rel32(opcode, at, target, tail=b''):
    return opcode + struct.pack('<i', target - (at + len(opcode) + 4 + len(tail))) + tail


def direct_cb(rva, guard, callback):
    a = rel32(bytes.fromhex('48 83 3d'), rva, guard, b'\x00')
    b = bytes.fromhex('74 12')
    c = rel32(bytes.fromhex('48 8b 05'), rva + len(a) + len(b), callback)
    return a + b + c + bytes.fromhex('48 85 c0 74 06 48 8b ca 48 ff e0 c3')


def destroy_cb(rva, cleanup, guard, callback):
    head = bytes.fromhex('48 85 c9 74 2d 53 48 83 ec 20 48 8b d9')
    call = rel32(bytes([0xe8]), rva + len(head), cleanup)
    a = rel32(bytes.fromhex('48 83 3d'), rva + len(head) + len(call), guard, b'\x00')
    b = bytes.fromhex('74 11')
    c = rel32(bytes.fromhex('48 8b 05'), rva + len(head) + len(call) + len(a) + len(b), callback)
    tail = bytes.fromhex('48 85 c0 74 05 48 8b cb') + bytes.fromhex('ff d0 48 83 c4 20 5b c3')
    return head + call + a + b + c + tail


class GuardedCallbackTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_validates_both_shapes_storage_and_callees(self):
        text = bytearray(1024)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        place(0x1000, bytes([0xc3]))
        place(0x1040, direct_cb(0x1040, 0x2000, 0x2008))
        place(0x1080, destroy_cb(0x1080, 0x1000, 0x2000, 0x2008))
        place(0x10d0, direct_cb(0x10d0, 0x2000, 0x2000))                 # same address for guard & callback
        place(0x1100, direct_cb(0x1100, 0x2004, 0x200c))                 # unaligned 8-byte storage
        place(0x1130, direct_cb(0x1130, 0x3000, 0x3008))                 # read-only .rdata rejected
        place(0x1160, destroy_cb(0x1160, 0x1001, 0x2000, 0x2008))        # unindexed cleanup
        place(0x11b0, destroy_cb(0x11b0, 0x1080, 0x2000, 0x2008))        # member-to-member cleanup
        place(0x1200, direct_cb(0x1200, 0x2000, 0x2008))                 # overlaps matched entry

        image = PeImage(assemble_pe([
            ('.text', 0x1000, text, 0x60000020),
            ('.data', 0x2000, bytes(64), 0xc0000040),
            ('.rdata', 0x3000, bytes(64), 0x40000040),
        ], (0, 0)))
        inventory = {0x11ff: dict(size=2, status='matched')}
        self.assertEqual(
            generator.discover(image, extents, inventory),
            [
                generator.Wrapper(0x1040, 29, generator.DIRECT, 0x2000, 0x2008),
                generator.Wrapper(0x1080, 51, generator.DESTROY, 0x2000, 0x2008, 0x1000),
            ],
        )

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Wrapper(0x1040, 29, generator.DIRECT, 0x2000, 0x2008),
            generator.Wrapper(0x1080, 51, generator.DESTROY, 0x2000, 0x2008, 0x1000),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                self.assertIn('CallbackGuard2000 != 0 && CallbackSlot2008 != nullptr', text)
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[m.symbol], dict(rva=m.rva, size=m.size))
                self.assertEqual(symbols['CallbackGuard2000'], dict(rva=0x2000, size=None))
                self.assertEqual(symbols['CallbackSlot2008'], dict(rva=0x2008, size=None))
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
