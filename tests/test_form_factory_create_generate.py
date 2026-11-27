"""Synthetic factory vtables and a new-expression using independent fixture addresses."""
import importlib.util
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import form_factory_create_generate as gen
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import SCN_CODE, SCN_DATA, assemble_pe
from test_memory_factory_generate import _call, _emit_alloc_const_args, _emit_ensure, _lea_rip


def fixture(*, allocation=0x70, bad_branch=False, folded=False, wrong_ctor=False, base_offset=0):
    base = 0x140000000
    entry, ctor, ensure, allocate, dtor = 0x1110, 0x1290, 0x1340, 0x1350, 0x1360
    rdata = bytearray()

    def put(blob):
        rdata.extend(bytes(-len(rdata) % 8))
        rva = 0x2000 + len(rdata)
        rdata.extend(blob)
        return rva

    def table(hierarchy, first, second):
        descriptors = []
        for name, offset in hierarchy:
            td = put(bytes(16) + ('.?AV' + name).encode() + bytes(1))
            descriptors.append((td, offset))
        bases = [put(struct.pack('<IIiiiI', td, len(hierarchy)-i-1, offset, -1, 0, 0))
                 for i, (td, offset) in enumerate(descriptors)]
        array = put(struct.pack('<' + 'I' * len(bases), *bases))
        chd = put(struct.pack('<4I', 0, 0, len(bases), array))
        col = put(bytes(24))
        struct.pack_into('<6I', rdata, col - 0x2000, 1, 0, 0, descriptors[0][0], chd, col)
        return put(struct.pack('<8Q', base+col, base+first, base+second, *([base+dtor]*5))) + 8

    table([('?$ConcreteFormFactory@VExample@@$04@@', 0), ('IFormFactory@@', 0)], dtor, entry)
    product = table([('Example@@', 0), ('TESForm@@', base_offset)], dtor, ensure)
    if folded:
        table([('Unrelated@@', 0)], dtor, entry)
    b = bytearray(b'\x48\x83\xec\x38')
    b += bytes.fromhex('48 c7 44 24 20 fe ff ff ff')
    _emit_ensure(b, entry, 0x4080, 0x4100, ensure)
    _emit_alloc_const_args(b, entry, 0x4100, allocation)
    b += _call(entry + len(b), allocate)
    b += bytes.fromhex('48 89 44 24 30 48 85 c0')
    branch = len(b)
    b += bytes.fromhex('74 00 48 8b c8')
    b += _call(entry + len(b), ctor)
    b += bytes.fromhex('90 48 83 c4 38 c3')
    b[branch+1] = len(b)-branch-2 + int(bad_branch)
    b += bytes.fromhex('33 c0 48 83 c4 38 c3')
    body = _lea_rip(0x48, 0x05, ctor, product + 8 * wrong_ctor) + bytes.fromhex('48 89 01 c3')
    text = bytearray(0x400)
    text[entry-0x1000:entry-0x1000+len(b)] = b
    text[ctor-0x1000:ctor-0x1000+len(body)] = body
    extents = {entry: len(b), ctor: len(body), dtor: 1, ensure: 1, allocate: 1}
    pdata = b''.join(struct.pack('<III', r, r+extents[r], 0x5000) for r in (entry, ctor))
    pe = assemble_pe([('.text', 0x1000, bytes(text), SCN_CODE), ('.rdata', 0x2000, bytes(rdata), SCN_DATA),
                      ('.pdata', 0x3000, pdata, SCN_DATA), ('.data', 0x4000, bytes(512), SCN_DATA | 0x80000000),
                      ('.xdata', 0x5000, bytes([1,0,0,0]), SCN_DATA)], (0x3000, len(pdata)))
    return PeImage(pe), extents, entry


@unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'iced-x86 is required')
class CreateTests(unittest.TestCase):
    def rows(self, blocked=False, overlap=False, **options):
        image, extents, rva = fixture(**options)
        if overlap:
            extents[rva-2] = 4
        return gen.select(image, extents, {rva}, lambda r, n: blocked)

    def test_small_and_large_products(self):
        for size in (0x70, 0x128):
            with self.subTest(size=size):
                row, = self.rows(allocation=size)
                self.assertEqual((row.owner.cpp, row.allocation, row.constructor),
                                 ('ConcreteFormFactory<Example, 5>', size, 0x1290))
                self.assertEqual(row.heap, (0x4080, 0x4100, 0x1340, 0x1350))

    def test_emitted_unit_passes_contributor_lint(self):
        build = gen.contrib.target_manifest(gen.batch.ROOT)['build_id']
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            row, = self.rows()
            task, _ = gen.emit(root, gen.UNIT, [row], build, 'OBSERVED')
            source = Path(task['compiled'])
            for file in [source, source.with_suffix('.h')]:
                self.assertEqual(lint_reconstruction.lint_file(root, file.as_posix(), build, compact=True), [])
            request = f'// CI hash: 0x{row.rva:x} {row.symbol}'
            self.assertIn(request, (root / source).read_text()[:8192])

    def test_ownership_control_flow_and_boundaries(self):
        for opt in ('blocked', 'overlap', 'bad_branch', 'folded', 'wrong_ctor', 'base_offset'):
            with self.subTest(option=opt):
                self.assertEqual(self.rows(**{opt: True}), [])
