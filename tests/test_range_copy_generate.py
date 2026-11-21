"""Range-copy wrappers in an original synthetic PE image."""
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
import range_copy_generate as generator
from pecoff import PeImage
from synthetic_pecoff import assemble_pe

PROLOG = bytes.fromhex('48 89 5c 24 08 57 48 83 ec 20')
EPILOG = bytes.fromhex('48 8d 04 3b 48 8b 5c 24 30 48 83 c4 20 5f c3')
MID_3 = bytes.fromhex('48 8b da 49 8b f8 48 2b d9') + bytes.fromhex('48 8b d1 4c 8b c3 48 8b cf')
MID_4 = bytes.fromhex('49 8b d8 49 8b c9 48 2b da 49 8b f9 4c 8b c3')


def copy_wrapper(rva, mid, callee, *, epilog=EPILOG):
    call_at = rva + len(PROLOG) + len(mid)
    return PROLOG + mid + bytes([0xe8]) + struct.pack('<i', callee - (call_at + 5)) + epilog


class RangeCopyTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_validates_both_shapes_and_callees(self):
        text = bytearray(1024)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        place(0x1000, bytes([0xc3]))
        # 6-byte unindexed import jump thunk at 0x1010 -> .rdata slot at 0x2000
        thunk = bytes.fromhex('ff 25') + struct.pack('<i', 0x2000 - (0x1010 + 6))
        text[0x10:0x16] = thunk
        place(0x1040, copy_wrapper(0x1040, MID_3, 0x1000))
        place(0x1080, copy_wrapper(0x1080, MID_4, 0x1010))
        place(0x10c0, copy_wrapper(0x10c0, MID_3, 0x1001))              # unindexed non-thunk callee
        place(0x1100, copy_wrapper(0x1100, MID_3, 0x2000))              # non-code callee
        place(0x1140, copy_wrapper(0x1140, MID_3, 0x1040))              # member-to-member call
        place(0x1180, copy_wrapper(0x1180, MID_3, 0x1000) + bytes([0x90]))  # trailing byte
        place(0x11c0, copy_wrapper(0x11c0, MID_3, 0x1000,
                                   epilog=bytes.fromhex('48 8d 04 7b 48 8b 5c 24 30 48 83 c4 20 5f c3')))  # scale 2
        place(0x1200, copy_wrapper(0x1200, MID_4, 0x1000))              # overlaps matched entry
        extents[0x2000] = 1

        image = PeImage(assemble_pe([
            ('.text', 0x1000, text, 0x60000020),
            ('.rdata', 0x2000, bytes(16), 0x40000040),
        ], (0, 0)))
        inventory = {0x11ff: dict(size=2, status='matched')}
        self.assertEqual(
            generator.discover(image, extents, inventory),
            [
                generator.Wrapper(0x1040, 48, generator.THREE_ARG, 0x1000),
                generator.Wrapper(0x1080, 45, generator.FOUR_ARG, 0x1010),
            ],
        )

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Wrapper(0x1040, 48, generator.THREE_ARG, 0x1000),
            generator.Wrapper(0x1080, 45, generator.FOUR_ARG, 0x1000),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                self.assertIn('RangeCopyTarget1000(dest, first, count);', text)
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[m.symbol], dict(rva=m.rva, size=m.size))
                self.assertEqual(symbols['RangeCopyTarget1000'], dict(rva=0x1000, size=None))
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
