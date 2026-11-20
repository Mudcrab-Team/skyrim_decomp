import json
import re
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import symbol_corroboration as symbols  # noqa: E402

TOOL = Path(symbols.__file__)

# Every name below is invented for the test; no line comes from a real symbol file.
MAP_TEXT = '''
 Sample

 Timestamp is 00000000 (Thu Jan  1 00:00:00 1970)

 Preferred load address is 00400000

 Start         Length     Name                   Class
 0001:00000000 00001000H .text                   CODE

  Address         Publics by Value              Rva+Base       Lib:Object

 0001:00000000       ?Run@Widget@@QAEXXZ        00401000 f   Widget.obj
 0001:00000010       ?Stop@Widget@@QAEXXZ       00401010 f   Widget.obj
 0001:00000020       ?Count@Widget@@QBEHXZ      00401020 f i Gadget.obj
 0001:00000030       ??0Widget@@QAE@XZ          00401030 f   Widget.obj
 0001:00000040       ??1Gadget@@UAE@XZ          00401040 f   engine:Gadget.obj
 0001:00000050       ?Spin@Gadget@game@@QAEXXZ  00401050 f   engine:Gadget.obj
 0002:00000000       ??_7Sprocket@@6B@          00402000     Sprocket.obj
 0002:00000010       ?gTotal@@3HA               00402010     Widget.obj
 0001:00000060       ?Get@?$Array@H@@QAEHXZ     00401060 f i Widget.obj
'''
PROGRESS = {'target_build_id': 'test-build', 'functions': [
    {'id': 'test-0x10', 'name': 'Widget::Run'},
    {'id': 'test-0x20', 'name': 'Widget::Halt'},
    {'id': 'test-0x30', 'name': 'Widget::Widget'},
    {'id': 'test-0x40', 'name': 'Gadget::~Gadget'},
    {'id': 'test-0x50', 'name': 'Gadget::Function1581e30'},
    {'id': 'test-0x60', 'name': 'Missing::Run'},
    {'id': 'test-0x70', 'name': 'DeletingLeaf9d4fa0::Read'},
    {'id': 'test-0x80', 'name': 'FreeFunction'},
    {'id': 'test-0x90', 'name': 'Sprocket::Turn'},
]}


def public_record(name):
    body = struct.pack('<HIIH', symbols.S_PUB32, 2, 0x1000, 1) + name.encode() + b'\x00'
    body += b'\x00' * (-(len(body) + 2) % 4)
    return struct.pack('<H', len(body)) + body


def program_database(names, block_size=0x400):
    """A minimal MSF 7.00 file: empty streams 0-2, a DBI header naming stream 4, and the public symbols."""
    records = b''.join(public_record(name) for name in names) + struct.pack('<HH', 2, 0x1234)
    dbi = struct.pack('<iIIHHHHHH', -1, 19990903, 1, 0, 0, 0, 0, 4, 0) + b'\x00' * 40
    streams = [b'', b'', b'', dbi, records]
    blocks = [b'', b'', b'']        # block 0 is the superblock; 1 and 2 stand for the free block maps
    placed = []
    for stream in streams:
        indices = []
        for offset in range(0, len(stream), block_size):
            indices.append(len(blocks))
            blocks.append(stream[offset:offset + block_size].ljust(block_size, b'\x00'))
        placed.append(indices)
    directory = struct.pack('<I', len(streams)) + b''.join(struct.pack('<I', len(s)) for s in streams)
    directory += b''.join(struct.pack('<I', index) for indices in placed for index in indices)
    directory_blocks = []
    for offset in range(0, len(directory), block_size):
        directory_blocks.append(len(blocks))
        blocks.append(directory[offset:offset + block_size].ljust(block_size, b'\x00'))
    block_map = len(blocks)
    blocks.append(b''.join(struct.pack('<I', index) for index in directory_blocks).ljust(block_size, b'\x00'))
    superblock = symbols.MSF_MAGIC + struct.pack('<6I', block_size, 1, len(blocks), len(directory), 0, block_map)
    blocks[0] = superblock
    return b''.join(block.ljust(block_size, b'\x00') for block in blocks)


class DigestTest(unittest.TestCase):
    def test_grouped_digest_has_no_long_hex_run(self):
        grouped = symbols.grouped_digest('0123456789abcdef' * 4)
        self.assertEqual(grouped, '-'.join(['0123456789abcdef'] * 4))
        self.assertIsNone(re.search(r'[0-9a-f]{32,}', grouped))
        self.assertEqual(grouped.replace('-', ''), '0123456789abcdef' * 4)


class ReaderTest(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def test_linker_map(self):
        path = self.dir / 'sample.map'
        path.write_text(MAP_TEXT, encoding='latin-1')
        members, objects, facts = symbols.read_source(path)
        self.assertEqual(facts['kind'], 'linker-map')
        self.assertEqual(facts['public_symbols'], 9)
        self.assertEqual(members['Widget'], {'Run', 'Stop', 'Count', symbols.CONSTRUCTOR})
        self.assertEqual(members['Gadget'], {'Spin', symbols.DESTRUCTOR})
        self.assertEqual(members['Sprocket'], set())
        self.assertNotIn('Array', members)
        # An inline function's object is not the class's home.
        self.assertEqual(dict(objects['Widget']), {'Widget.obj': 3})
        self.assertEqual(dict(objects['Gadget']), {'engine:Gadget.obj': 2})

    def test_program_database(self):
        names = ['?Run@Widget@@QEAAXXZ', '??1Widget@@UEAA@XZ', '?Spin@Gadget@@QEAAXXZ', '??_7Sprocket@@6B@'] * 300
        path = self.dir / 'sample.pdb'
        path.write_bytes(program_database(names))
        members, objects, facts = symbols.read_source(path)
        self.assertEqual(facts['kind'], 'program-database')
        self.assertEqual(facts['public_symbols'], 1200)
        self.assertEqual(members, {'Widget': {'Run', symbols.DESTRUCTOR}, 'Gadget': {'Spin'}, 'Sprocket': set()})
        self.assertEqual(objects, {})

    def test_other_files_are_refused(self):
        path = self.dir / 'notes.txt'
        path.write_text('nothing that looks like a symbol table\n')
        with self.assertRaises(ValueError):
            symbols.read_source(path)


class VerdictTest(unittest.TestCase):
    def setUp(self):
        self.sources = {'first': {'Widget': {'Run', 'Stop', symbols.CONSTRUCTOR}, 'Gadget': {symbols.DESTRUCTOR, 'Spin'},
                                  'Sprocket': set()},
                        'second': {'Widget': {'Halt', 'Stop', 'operator_like'}}}
        self.objects = {'first': {'Widget': {'Widget.obj': 3, 'Other.obj': 1}}, 'second': {}}

    def test_published_names(self):
        names = [symbols.published_name(entry) for entry in PROGRESS['functions']]
        self.assertEqual(names, [('Widget', 'Run'), ('Widget', 'Halt'), ('Widget', symbols.CONSTRUCTOR),
                                 ('Gadget', symbols.DESTRUCTOR), None, ('Missing', 'Run'), None, None,
                                 ('Sprocket', 'Turn')])

    def test_verdicts(self):
        functions = symbols.corroborate(PROGRESS, self.sources)
        self.assertEqual(functions, {
            'test-0x10': {'confirmed': ['first'], 'absent': ['second']},
            'test-0x20': {'confirmed': ['second'], 'absent': ['first']},
            'test-0x30': {'confirmed': ['first'], 'absent': ['second']},
            'test-0x40': {'confirmed': ['first'], 'absent': []},
            'test-0x90': {'confirmed': [], 'absent': ['first']},
        })
        counts, per_source = symbols.summary(PROGRESS, functions, self.sources)
        self.assertEqual(counts['assessable_names'], 6)
        self.assertEqual(counts['confirmed_by_a_source'], 4)
        self.assertEqual(counts['absent_from_every_source_with_the_class'], 1)
        self.assertEqual(per_source, {'first': {'confirmed': 3, 'absent': 2}, 'second': {'confirmed': 1, 'absent': 2}})

    def test_class_names(self):
        functions = symbols.corroborate(PROGRESS, self.sources)
        classes = symbols.class_names(PROGRESS, self.sources, self.objects, functions)
        # Every Widget name is confirmed by a source: no open function, so no candidate list.
        self.assertEqual(classes['Widget'], {'open': 0, 'objects': {'first': ['Widget.obj', 'Other.obj']},
                                             'candidates': {}})
        # Gadget has a placeholder-named function: the unused member is offered, the used one is not.
        self.assertEqual(classes['Gadget'], {'open': 1, 'objects': {}, 'candidates': {'Spin': ['first']}})
        self.assertNotIn('Sprocket', classes)      # known to a source, nothing to offer
        self.assertNotIn('Missing', classes)
        self.assertNotIn('DeletingLeaf9d4fa0', classes)


class CommandTest(unittest.TestCase):
    def test_writes_only_verdicts_and_names_of_inventory_classes(self):
        with tempfile.TemporaryDirectory() as tmp, tempfile.TemporaryDirectory() as outside:
            root = Path(tmp)
            (root / 'data').mkdir()
            (root / 'data/progress.json').write_text(json.dumps(PROGRESS), encoding='utf-8')
            map_path = Path(outside) / 'sample.map'
            map_path.write_text(MAP_TEXT, encoding='latin-1')
            pdb_path = Path(outside) / 'sample.pdb'
            pdb_path.write_bytes(program_database(['?Halt@Widget@@QEAAXXZ', '?Hidden@Unlisted@@QEAAXXZ']))
            run = subprocess.run([sys.executable, str(TOOL), '--root', str(root), '--write',
                                  '--source', f'sample-map={map_path}', '--source', f'sample-pdb={pdb_path}'],
                                 capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stderr)
            verdicts = json.loads((root / symbols.OUTPUT).read_text(encoding='utf-8'))
            names_text = (root / symbols.NAMES_OUTPUT).read_text(encoding='utf-8')
            names = json.loads(names_text)
            self.assertEqual(verdicts['sources']['sample-map']['key'], 'a')
            self.assertEqual(verdicts['functions']['test-0x10'], {'confirmed': 'a', 'absent': 'b'})
            self.assertEqual(verdicts['functions']['test-0x20'], {'confirmed': 'b', 'absent': 'a'})
            self.assertEqual(names['classes']['Gadget'], {'open': 1, 'objects': {'a': ['engine:Gadget.obj']},
                                                          'candidates': {'Spin': 'a'}})
            # A class the inventory does not name never reaches the output, nor does a decorated name.
            for text in (names_text, (root / symbols.OUTPUT).read_text(encoding='utf-8'), run.stdout):
                self.assertNotIn('Unlisted', text)
                self.assertNotIn('Hidden', text)
                self.assertNotIn('@@', text)
            self.assertNotIn(str(outside), names_text)

            inside = root / 'kept.map'
            inside.write_text(MAP_TEXT, encoding='latin-1')
            refused = subprocess.run([sys.executable, str(TOOL), '--root', str(root), '--source', f'kept-map={inside}'],
                                     capture_output=True, text=True)
            self.assertEqual(refused.returncode, 2)
            self.assertIn('outside the repository', refused.stderr)


if __name__ == '__main__':
    unittest.main()
