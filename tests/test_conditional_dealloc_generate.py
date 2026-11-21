"""Conditional sized deallocators in an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_code_rules
import conditional_dealloc_generate as generator
import contrib_screen
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


def direct_dealloc(rva, object_size, dealloc, *, prolog=bytes.fromhex('40 53')):
    body = (prolog
            + bytes.fromhex('48 83 ec 20 48 8b d9 f6 c2 01 74 0a ba')
            + struct.pack('<I', object_size)
            + bytes([0xe8]))
    call_at = rva + len(body) - 1
    return body + struct.pack('<i', dealloc - (call_at + 5)) + bytes.fromhex('48 8b c3 48 83 c4 20 5b c3')


def cleanup_dealloc(rva, cleanup, object_size, dealloc, *, epilog=bytes.fromhex('48 8b 5c 24 30 48 8b c7 48 83 c4 20 5f c3')):
    head = bytes.fromhex('48 89 5c 24 08 57 48 83 ec 20 8b da 48 8b f9')
    call1 = bytes([0xe8]) + struct.pack('<i', cleanup - (rva + len(head) + 5))
    mid = bytes.fromhex('f6 c3 01 74 0d ba') + struct.pack('<I', object_size) + bytes.fromhex('48 8b cf')
    call2_at = rva + len(head) + len(call1) + len(mid)
    call2 = bytes([0xe8]) + struct.pack('<i', dealloc - (call2_at + 5))
    return head + call1 + mid + call2 + epilog


class ConditionalDeallocTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_validates_both_shapes_and_callees(self):
        text = bytearray(1024)
        extents = {}

        def place(rva, code):
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code

        place(0x1000, bytes([0xc3]))  # dealloc
        place(0x1010, bytes([0xc3]))  # cleanup
        place(0x1040, direct_dealloc(0x1040, 88, 0x1000))
        place(0x1080, cleanup_dealloc(0x1080, 0x1010, 248, 0x1000))
        place(0x10c0, direct_dealloc(0x10c0, 0, 0x1000))                 # zero size rejected
        place(0x1100, direct_dealloc(0x1100, 24, 0x1001))                # unindexed dealloc
        place(0x1140, direct_dealloc(0x1140, 24, 0x2000))                # non-code dealloc
        place(0x1180, direct_dealloc(0x1180, 24, 0x1040))                # member-to-member dealloc
        place(0x11c0, direct_dealloc(0x11c0, 24, 0x1000, prolog=bytes.fromhex('53')))  # 1-byte push
        place(0x1200, cleanup_dealloc(0x1200, 0x1000, 16, 0x1000))       # cleanup == dealloc
        place(0x1240, cleanup_dealloc(0x1240, 0x1011, 16, 0x1000))       # unindexed cleanup
        place(0x1280, cleanup_dealloc(0x1280, 0x1010, 16, 0x1000,
                                      epilog=bytes.fromhex('48 8b c7 48 8b 5c 24 30 48 83 c4 20 5f c3')))  # swapped epilog
        place(0x12c0, direct_dealloc(0x12c0, 32, 0x1000))                # overlaps matched entry
        extents[0x2000] = 1

        image = PeImage(assemble_pe([('.text', 0x1000, text, 0x60000020),
                                     ('.data', 0x2000, bytes(16), 0xc0000040)], (0, 0)))
        inventory = {0x12bf: dict(size=2, status='matched')}
        self.assertEqual(
            generator.discover(image, extents, inventory),
            [
                generator.Member(0x1040, 33, generator.DIRECT, 88, 0x1000),
                generator.Member(0x1080, 52, generator.CLEANUP, 248, 0x1000, 0x1010),
            ],
        )

    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_shards_large_families(self):
        count = generator.SHARD_SIZE + 2
        text = bytearray(0x40 * (count + 2))
        extents = {0x1000: 1}
        text[0] = 0xc3
        for idx in range(count):
            rva = 0x1040 + idx * 0x40
            code = direct_dealloc(rva, 24, 0x1000)
            extents[rva] = len(code)
            text[rva - 0x1000:rva - 0x1000 + len(code)] = code
        image = PeImage(assemble_pe([('.text', 0x1000, text, 0x60000020)], (0, 0)))
        members = generator.discover(image, extents, {})
        self.assertEqual(len(members), count)
        self.assertEqual([m.family for m in members[:generator.SHARD_SIZE]], [f'{generator.DIRECT}1'] * generator.SHARD_SIZE)
        self.assertEqual([m.family for m in members[generator.SHARD_SIZE:]], [f'{generator.DIRECT}2'] * 2)

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Member(0x1040, 33, generator.DIRECT, 88, 0x1000),
            generator.Member(0x1080, 52, generator.CLEANUP, 248, 0x1000, 0x1010),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                self.assertIn(f'DeallocatorTarget1000(object, {m.object_size}ull);', text)
                if m.cleanup is not None:
                    self.assertIn('CleanupTarget1010(object);', text)
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
