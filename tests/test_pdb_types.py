"""tools/pdb_types.py on a tiny synthetic PDB (invented names only), and its hooks into lint and start."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
import contrib  # noqa: E402
import lint_reconstruction  # noqa: E402
import pdb_types as P  # noqa: E402

VERSION = '2000.01.01'
LABEL = f'CRASHLOGGER_PDB(59818@{VERSION})'


def pad4(data):
    """Pad with LF_PAD bytes (0xF1..0xF3), as a compiler does, so a reader can tell padding from content."""
    n = -len(data) % 4
    return data + bytes(0xF0 | k for k in range(n, 0, -1))


def number(value):
    if value < 0x8000:
        return struct.pack('<H', value)
    return struct.pack('<HI', 0x8004, value)


def record(kind, body):
    body = pad4(body)
    return struct.pack('<HH', len(body) + 2, kind) + body


def fieldlist(members=(), enumerators=()):
    out = b''
    for offset, ti, name in members:
        out += pad4(struct.pack('<HHI', P.LF_MEMBER, 3, ti) + number(offset) + name.encode() + b'\0')
    for name, value in enumerators:
        out += pad4(struct.pack('<HH', P.LF_ENUMERATE, 3) + number(value) + name.encode() + b'\0')
    return record(P.LF_FIELDLIST, out)


def struct_record(name, size, field=0, unique='', fwd=False, kind=P.LF_STRUCTURE):
    prop = (0x80 if fwd else 0) | (0x200 if unique else 0)
    body = struct.pack('<HHIII', 0, prop, field, 0, 0) + number(0 if fwd else size) + name.encode() + b'\0'
    return record(kind, body + (unique.encode() + b'\0' if unique else b''))


def build_msf(streams, block=512):
    blocks, listing, nxt = {}, [], 3
    data = bytearray(block * 3)
    for index, content in enumerate(streams):
        count = -(-len(content) // block)
        listing.append((len(content), list(range(nxt, nxt + count))))
        data += content + b'\0' * (count * block - len(content))
        nxt += count
    directory = struct.pack('<I', len(streams)) + b''.join(struct.pack('<I', n) for n, _ in listing)
    directory += b''.join(struct.pack(f'<{len(b)}I', *b) for _, b in listing)
    dir_blocks = -(-len(directory) // block)
    data += directory + b'\0' * (dir_blocks * block - len(directory))
    map_block = nxt + dir_blocks
    data += struct.pack(f'<{dir_blocks}I', *range(nxt, nxt + dir_blocks)).ljust(block, b'\0')
    header = P.MSF_MAGIC + struct.pack('<IIIIII', block, 1, len(data) // block, len(directory), 0, map_block)
    data[:len(header)] = header
    return bytes(data)


def build_pdb():
    """A PDB whose names, offsets and sizes are all made up."""
    ptr_void = record(P.LF_POINTER, struct.pack('<II', 3, 0x0C | (8 << 13)))             # 0x1000
    gizmo_fields = fieldlist([(0, 0x1000, 'vtable'), (8, 0x74, 'gizmoId')])               # 0x1001
    gizmo = struct_record('Gizmo', 16, 0x1001, 'gizmo-u')                                  # 0x1002
    gizmo_fwd = struct_record('Gizmo', 0, 0, 'gizmo-u', fwd=True)                          # 0x1003
    low = record(P.LF_BITFIELD, struct.pack('<IBB', 0x75, 3, 0))                           # 0x1004
    high = record(P.LF_BITFIELD, struct.pack('<IBB', 0x75, 5, 3))                          # 0x1005
    gizmo_ptr = record(P.LF_POINTER, struct.pack('<II', 0x1003, 0x0C | (8 << 13)))         # 0x1006
    widget_fields = fieldlist([(0, 0x1003, '_base'), (16, 0x74, 'count'), (20, 0x1004, 'lowBits'),
                               (20, 0x1005, 'highBits'), (24, 3, 'v0'), (25, 3, 'v1'), (26, 3, 'v2'),
                               (32, 0x1006, 'owner')])                                    # 0x1007
    widget = struct_record('Widget', 40, 0x1007, 'widget-u')                               # 0x1008
    mode_fields = fieldlist(enumerators=[('kNone', 0), ('kBig', 0x80000000)])              # 0x1009
    mode = record(P.LF_ENUM, struct.pack('<HHII', 2, 0x200, 0x74, 0x1009) + b'Mode\0' + b'mode-u\0')  # 0x100a
    thing_a_fields = fieldlist([(0, 0x74, 'a'), (4, 0x74, 'b')])                           # 0x100b
    thing_a = struct_record('Thing', 8, 0x100B, 'thing-a')                                 # 0x100c
    thing_b_fields = fieldlist([(0, 0x74, 'c')])                                           # 0x100d
    thing_b = struct_record('Thing', 4, 0x100D, 'thing-b')                                 # 0x100e
    packed_fields = fieldlist([(0, 0x73, 'a'), (2, 0x75, 'b')])                            # 0x100f
    packed = struct_record('Packed', 6, 0x100F, 'packed-u')                                # 0x1010
    records = [ptr_void, gizmo_fields, gizmo, gizmo_fwd, low, high, gizmo_ptr, widget_fields, widget,
               mode_fields, mode, thing_a_fields, thing_a, thing_b_fields, thing_b, packed_fields, packed]
    blob = b''.join(records)
    tpi = struct.pack('<IIIIIHHIIIIII', 20040203, 56, 0x1000, 0x1000 + len(records), len(blob),
                      0xFFFF, 0xFFFF, 4, 8, 0, 0, 0, 0)
    tpi = tpi.ljust(56, b'\0') + blob

    pub = lambda off, name, flags=2: record(0x110E, struct.pack('<IIH', flags, off, 1) + name.encode() + b'\0')  # noqa: E731
    syms = b''.join([pub(0x200, 'Widget::Reset'), pub(0x300, 'FUN_140001300'), pub(0x2000, 'Gizmo::Tick_140003000'),
                     pub(0x400, 'g_table', 0)])
    proc = record(0x1110, struct.pack('<IIIIIIIIHB', 0, 0, 0, 16, 0, 0, 0x1000, 0x100, 1, 0) + b'Widget::Update\0')
    module = struct.pack('<I', 4) + proc
    info = bytearray(64)
    struct.pack_into('<H', info, 34, 5)               # the module's symbol stream
    struct.pack_into('<I', info, 36, len(module))     # its symbol byte count
    mod_info = pad4(bytes(info) + b'm.obj\0m.obj\0')
    dbg = struct.pack('<6H', 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 6)   # section headers: stream 6
    dbi = bytearray(64)
    struct.pack_into('<H', dbi, 20, 4)                # symbol record stream
    struct.pack_into('<i', dbi, 24, len(mod_info))
    struct.pack_into('<i', dbi, 48, len(dbg))
    section = struct.pack('<8sIIIIIIHHI', b'.text', 0x4000, 0x1000, 0x4000, 0, 0, 0, 0, 0, 0x60000020)
    pdb_stream = struct.pack('<III', 20000404, 1, 1) + bytes(range(16))
    streams = [b'', pdb_stream, tpi, bytes(dbi) + mod_info + dbg, syms, module, section]
    return build_msf(streams)


class PdbTypesTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory()
        cls.pdb = Path(cls.tmp.name) / 'Fake.pdb'
        cls.pdb.write_bytes(build_pdb())
        cls.files = P.build_files(cls.pdb, VERSION)

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def test_every_file_starts_with_the_label(self):
        self.assertTrue(self.files)
        for name, text in self.files.items():
            self.assertIn(LABEL, text.split('\n', 1)[0], name)

    def test_names_map_has_chosen_names_only(self):
        rows = {}
        for name, text in self.files.items():
            if name.startswith('names/'):
                rows.update(line.split('\t') for line in text.splitlines() if not line.startswith('#'))
        self.assertEqual(rows, {'0x1100': 'Widget::Update', '0x1200': 'Widget::Reset',
                                '0x3000': 'Gizmo::Tick_140003000'})

    def test_layout_header_of_a_derived_class(self):
        text = self.files['types/Widget.h']
        for expected in ('#include "Gizmo.h"', 'Gizmo _base;', 'int count;', 'unsigned int lowBits : 3;',
                         'unsigned int highBits : 5;', 'unsigned char undefined_18[3];', 'Gizmo* owner;',
                         'unsigned char _pad_0[5];', 'static_assert(sizeof(Widget) == 40'):
            self.assertIn(expected, text)
        self.assertNotIn('#pragma pack', text)
        self.assertLess(text.index('_base'), text.index('count'))

    def test_base_pads_to_its_size(self):
        self.assertIn('unsigned char _pad_0[4];', self.files['types/Gizmo.h'])

    def test_enum_wraps_values_to_the_underlying_type(self):
        text = self.files['types/Mode.h']
        self.assertIn('enum class Mode : int {', text)
        self.assertIn('kBig = -2147483648,', text)

    def test_same_name_different_types_get_separate_headers(self):
        things = [n for n in self.files if n.startswith('types/Thing')]
        self.assertEqual(len(things), 2)
        rows = [line.split('\t') for line in self.files['types.tsv'].splitlines() if line.startswith('Thing\t')]
        self.assertEqual(sorted(r[4] == '-' for r in rows), [False, True])
        self.assertIn('static_assert(sizeof(Thing) == 8', self.files['types/Thing.h'])

    def test_misaligned_members_use_pack(self):
        text = self.files['types/Packed.h']
        self.assertIn('#pragma pack(push, 2)', text)
        self.assertIn('#pragma pack(pop)', text)

    def test_generation_is_deterministic_and_replaces_the_directory(self):
        self.assertEqual(self.files, P.build_files(self.pdb, VERSION))
        out = Path(self.tmp.name) / 'out'
        (out / 'types').mkdir(parents=True)
        (out / 'types' / 'Stale.h').write_text('stale')
        P.write_tree(self.files, out)
        self.assertFalse((out / 'types' / 'Stale.h').exists())
        self.assertEqual(sorted(p.relative_to(out).as_posix() for p in out.rglob('*') if p.is_file()),
                         sorted(self.files))

    def make_repo(self):
        root = Path(tempfile.mkdtemp(dir=self.tmp.name))
        P.write_tree(self.files, root / P.GENERATED)
        return root

    def test_hint_names_the_owning_class_header(self):
        root = self.make_repo()
        hint = P.hint_for_rva(0x1100, root)
        self.assertIn('Widget::Update', hint)
        self.assertIn('PDB layout', hint)
        self.assertIn(f'{P.GENERATED}/types/Widget.h', hint)
        self.assertIn('"generated/crashlogger_pdb/types/Widget.h"', hint)
        self.assertIn(LABEL, hint)
        self.assertEqual(P.lookup_rva(0x3000, root)['class'], 'Gizmo')
        self.assertIsNone(P.hint_for_rva(0x9999, root))

    def test_start_hint_is_silent_without_the_tree(self):
        root = self.make_repo()
        lines = contrib.pdb_hints(root, [{'rva': 0x1100}, {'rva': 0x1200}])
        self.assertEqual(len(lines), 1)  # one layout line per class, however many of its functions
        self.assertIn('PDB layout for Widget::Update', lines[0])
        self.assertEqual(contrib.pdb_hints(Path(tempfile.mkdtemp(dir=self.tmp.name)), [{'rva': 0x1100}]), [])

    def test_lint_leaves_generated_files_to_the_label_rule(self):
        root = self.make_repo()
        name = f'{P.GENERATED}/types/Widget.h'
        self.assertEqual(lint_reconstruction.lint_file(root, name, 'x'), [])
        path = root / name
        path.write_text('struct Widget {};\n')
        self.assertTrue(lint_reconstruction.lint_file(root, name, 'x'))
        self.assertTrue(P.tree_problems(root))

    def test_owner_candidates(self):
        self.assertEqual(P.owner_candidates('Foo::Bar_140001234')[0], 'Foo')
        self.assertEqual(P.owner_candidates('BSTArray<RE::Foo>::Clear')[0], 'BSTArray<RE::Foo>')
        self.assertIn('Outer___Inner', P.owner_candidates('Outer___Inner__dtor'))


if __name__ == '__main__':
    unittest.main()
