"""Argument-returning call wrappers in an original synthetic PE image."""
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
import return_argument_generate as generator
from pecoff import PeImage
from synthetic_pecoff import assemble_pe

PROLOG = bytes.fromhex('40 53 48 83 ec 20')
EPILOG = bytes.fromhex('48 8b c3 48 83 c4 20 5b c3')


def call_wrapper(rva, middle, callee, *, prolog=PROLOG, epilog=EPILOG):
    call_at = rva + len(prolog) + len(middle)
    return prolog + middle + bytes([0xe8]) + struct.pack('<i', callee - (call_at + 5)) + epilog


class ReturnArgumentTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_validates_shape_bounds_and_callee(self):
        text = bytearray(512)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        save_rcx = bytes.fromhex('48 8b d9')
        save_rdx = bytes.fromhex('48 8b da')
        const_mid = bytes.fromhex('4c 8b c2 48 8b d9 48 ba') + struct.pack('<Q', 0x3000000000000)
        low_const_mid = bytes.fromhex('4c 8b c2 48 8b d9 48 ba') + struct.pack('<Q', 0x1234)
        high_sign_mid = bytes.fromhex('4c 8b c2 48 8b d9 48 ba') + struct.pack('<Q', 0xffffffff80000000)

        place(0x1000, bytes([0xc3]))
        place(0x1020, call_wrapper(0x1020, save_rcx, 0x1000))
        place(0x1040, call_wrapper(0x1040, save_rdx, 0x1000))
        place(0x1060, call_wrapper(0x1060, const_mid, 0x1000))
        place(0x1090, call_wrapper(0x1090, save_rcx, 0x1001))              # unindexed callee
        place(0x10b0, call_wrapper(0x10b0, save_rcx, 0x10b0))              # self-call
        place(0x10d0, call_wrapper(0x10d0, save_rcx, 0x2000))              # non-code callee
        place(0x10f0, call_wrapper(0x10f0, save_rcx, 0x1020))              # calls another ReturnFirst member
        place(0x1110, call_wrapper(0x1110, save_rcx, 0x1000) + bytes([0x90]))  # trailing byte
        place(0x1130, call_wrapper(0x1130, save_rcx, 0x1000, prolog=bytes.fromhex('53 48 83 ec 20')))  # 1-byte push
        place(0x1150, call_wrapper(0x1150, low_const_mid, 0x1000))         # 32-bit imm fits mov edx, imm32
        place(0x1180, call_wrapper(0x1180, high_sign_mid, 0x1000))         # sign-extended imm32 form
        place(0x11b0, call_wrapper(0x11b0, save_rcx, 0x1000))              # overlaps matched entry
        extents[0x2000] = 1

        image = PeImage(assemble_pe([('.text', 0x1000, text, 0x60000020),
                                     ('.data', 0x2000, bytes(16), 0xc0000040)], (0, 0)))
        inventory = {0x11af: dict(size=2, status='matched')}
        self.assertEqual(
            generator.discover(image, extents, inventory),
            [
                generator.Wrapper(0x1020, 23, generator.RETURN_FIRST, 0x1000),
                generator.Wrapper(0x1040, 23, generator.RETURN_SECOND, 0x1000),
                generator.Wrapper(0x1060, 36, generator.RETURN_FIRST_CONSTANT, 0x1000, 0x3000000000000),
            ],
        )

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Wrapper(0x1020, 23, generator.RETURN_FIRST, 0x1000),
            generator.Wrapper(0x1040, 23, generator.RETURN_SECOND, 0x1000),
            generator.Wrapper(0x1060, 36, generator.RETURN_FIRST_CONSTANT, 0x1000, 0x3000000000000),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                if m.value is not None:
                    self.assertIn(f'0x{m.value:x}ull', text)
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[m.symbol], dict(rva=m.rva, size=m.size))
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
