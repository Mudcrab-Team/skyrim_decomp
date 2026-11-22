"""Fixed-argument wrappers in an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import contrib_screen
import fixed_argument_generate as generator
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


def tail_wrapper(rva, setup, callee):
    return setup + bytes([0xe9]) + struct.pack('<i', callee - (rva + len(setup) + 5))


class FixedArgumentTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_uses_the_whole_extent_and_the_members_own_target(self):
        text = bytearray(256)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        imm = bytes([0xba]) + struct.pack('<I', 0x80000001)
        zero = bytes([0x33, 0xd2])
        place(0x1000, bytes([0xc3]))
        place(0x1010, tail_wrapper(0x1010, imm, 0x1000))
        place(0x1020, tail_wrapper(0x1020, zero, 0x10f0))
        place(0x1030, tail_wrapper(0x1030, zero, 0x1001))  # unindexed callee
        place(0x1040, tail_wrapper(0x1040, zero, 0x1040))  # local branch
        place(0x1050, tail_wrapper(0x1050, bytes([0x33, 0xd1]), 0x1000))  # reads ECX
        place(0x1060, tail_wrapper(0x1060, bytes([0xb9]) + imm[1:], 0x1000))  # overwrites RCX
        place(0x1070, tail_wrapper(0x1070, zero, 0x1000) + bytes([0x90]))
        place(0x1080, tail_wrapper(0x1080, imm, 0x1000))  # overlaps an accepted entry
        place(0x1090, tail_wrapper(0x1090, zero, 0x1010))  # jumps to another candidate
        place(0x10a0, tail_wrapper(0x10a0, zero, 0x2000))  # indexed non-code address
        place(0x10f0, bytes([0xc3]))
        extents[0x2000] = 1
        image = PeImage(assemble_pe([('.text', 0x1000, text, 0x60000020),
                                     ('.data', 0x2000, bytes(16), 0xc0000040)], (0, 0)))
        inventory = {0x107f: dict(size=2, status='matched')}
        self.assertEqual(generator.discover(image, extents, inventory),
                         [generator.Wrapper(0x1010, 10, 0x80000001, 0x1000),
                          generator.Wrapper(0x1020, 7, 0, 0x10f0)])

    def test_members_share_a_callee_declaration_and_keep_their_values(self):
        members = [generator.Wrapper(0x1010, 10, 4294967294, 0x1000),
                   generator.Wrapper(0x1020, 7, 0, 0x1000)]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            task, directory = generator.emit(root, generator.Wrapper.family, members, 'synthetic', 'synthetic')
            src = root / task['compiled']
            self.assertEqual(src.with_suffix('.h').read_text().count('FixedArgumentTarget1000('), 1)
            for m in members:
                self.assertIn(f'FixedArgumentTarget1000(context, {m.value}u);', src.read_text())
            symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
            self.assertEqual(symbols['FixedArgumentTarget1000']['rva'], 0x1000)
            self.assertEqual([symbols[f['symbol']]['rva'] for f in task['functions']], [m.rva for m in members])
            self.assertEqual(contrib_screen.screen_tree(root, task['compiled']), [])
            for path in (src, src.with_suffix('.h')):
                self.assertEqual(lint_reconstruction.lint_file(
                    root, path.relative_to(root).as_posix(), 'synthetic', compact=True), [])
