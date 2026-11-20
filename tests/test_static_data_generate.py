"""Static-data discovery on original synthetic PE functions."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import static_data_generate as generator
import contrib_screen
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


def relative(opcode, start, target):
    return opcode + struct.pack('<i', target - start - len(opcode) - 4)


@unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
class DiscoveryTests(unittest.TestCase):
    def test_scalar_width_and_destination_register(self):
        for opcode, storage, result in [
            ('0f b6 05', 'unsigned char', 'unsigned int'), ('0f b7 05', 'unsigned short', 'unsigned int'),
            ('8b 05', 'unsigned int', 'unsigned int'), ('48 8b 05', 'unsigned long long', 'unsigned long long'),
            ('f3 0f 10 05', 'float', 'float'), ('f2 0f 10 05', 'double', 'double'),
        ]:
            with self.subTest(opcode=opcode):
                body = relative(bytes.fromhex(opcode), 0x3000, 0x1000) + bytes([0xc3])
                m = generator.classify(body, 0x3000)
                self.assertEqual((m.data, m.storage_type, m.result_type), (0x1000, storage, result))
                for bad in (body[:-1], body + bytes([0x90]), bytes([0x65]) + body):
                    self.assertIsNone(generator.classify(bad, 0x3000))
        for opcode in ('8b 0d', '8b 01', '48 8d 05'):
            code = relative(bytes.fromhex(opcode), 0x3000, 0x1000) + bytes([0xc3])
            self.assertIsNone(generator.classify(code, 0x3000))

    def test_enrollment(self):
        extent = {}
        text = bytearray(256)

        def place(rva, body):
            extent[rva] = len(body)
            text[rva - 0x1000:rva - 0x1000 + len(body)] = body

        def reader(rva, target, opcode='8b 05'):
            place(rva, relative(bytes.fromhex(opcode), rva, target) + bytes([0xc3]))

        def wrapper(rva, data, callee):
            address = relative(bytes.fromhex('48 8d 0d'), rva, data)
            place(rva, address + relative(bytes([0xe9]), rva + len(address), callee))

        place(0x1000, bytes([0xc3]))
        reader(0x1010, 0x2000)
        wrapper(0x1020, 0x2010, 0x1000)
        wrapper(0x1030, 0x2010, 0x1001)  # jump into an unindexed address
        reader(0x1040, 0x1000)           # executable storage
        reader(0x1050, 0x2004)           # two inconsistent views of overlapping storage
        reader(0x1060, 0x2005, '0f b6 05')
        reader(0x1070, 0x2000)           # extent overlaps an accepted interval
        reader(0x1080, 0x2020)           # outside the data section
        wrapper(0x1090, 0x2010, 0x1090)  # self-reference
        reader(0x10a0, 0x2000)           # inventory disagrees with the size
        image = PeImage(assemble_pe([('.text', 0x1000, text, 0x60000020),
                                     ('.data', 0x2000, bytes(32), 0xc0000040)], (0, 0)))
        inventory = {0x106f: dict(size=2, status='matched'), 0x10a0: dict(size=6, status='mapped')}
        members = generator.discover(image, extent, inventory)
        self.assertEqual([(m.rva, m.data, m.callee) for m in members],
                         [(0x1010, 0x2000, None), (0x1020, 0x2010, 0x1000)])


class GeneratorTests(unittest.TestCase):
    def test_conflicting_extents_are_dropped(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            bounds = root / generator.pdb_types.GENERATED / 'boundaries'
            bounds.mkdir(parents=True)
            (bounds / '00.tsv').write_text('# synthetic\n1010\t7\n1020\t8\n1030\tc\n')
            public = {'functions': [dict(rva=0x1010, size=7), dict(rva=0x1020, size=7)]}
            with patch.object(generator.target_hashes, 'load_manifest', return_value=public):
                self.assertEqual(generator.boundaries(root), {0x1010: 7, 0x1030: 12})

    def test_units_and_reference_bindings(self):
        members = [generator.Member(0x1010, 7, 0x2000, 4, 'unsigned int', 'unsigned int'),
                   generator.Member(0x1020, 12, 0x2010, 1, 'StaticStorage', 'void', 0x1000)]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic boundaries')
                self.assertEqual(task['functions'], [dict(rva=m.rva, size=m.size, symbol=m.symbol)])
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[f'StaticData{m.data:x}']['rva'], m.data)
                if m.callee:
                    self.assertEqual(symbols[f'CallStatic{m.callee:x}']['rva'], m.callee)
                source = root / task['compiled']
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', source.read_text())
                self.assertEqual(contrib_screen.screen_tree(root, task['compiled']), [])
                for path in (source, source.with_suffix('.h')):
                    self.assertEqual(lint_reconstruction.lint_file(
                        root, path.relative_to(root).as_posix(), 'synthetic', compact=True), [])
