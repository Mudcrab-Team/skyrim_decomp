"""Reconstruction symbol export against invented source and object records."""

import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / 'exelink'))
from compare import code_section_sha256  # noqa: E402
from compare_internal import internal_code_sha256, selector  # noqa: E402
from pecoff import CoffObject  # noqa: E402
from symbol_pdb import PROVENANCE_STREAM, write_pdb  # noqa: E402
import symbols  # noqa: E402
from synthetic_pecoff import SCN_TEXT, STORAGE_EXTERNAL, STORAGE_STATIC, Unit, dwords  # noqa: E402

SOURCE = 'reconstruction/Toy.cpp'
TOY = b"""// Toy: GUESS(low)
extern "C" int toy(int a) {
    if (a > 0)
        return a * 3;
    return -a;
}
"""
RVA = 0x2340
ORIGIN = 'GUESS(low)'


def subsection(kind, body):
    return dwords(kind, len(body)) + body + b'\0' * (-len(body) % 4)


def fixture(file=SOURCE, static=False):
    unit = Unit()
    strings = subsection(0xF3, b'\0' + file.encode() + b'\0')
    checksum = struct.pack('<IBB', 1, 16, 1) + hashlib.md5(TOY, usedforsecurity=False).digest() + b'\0\0'
    unit.section('.debug$S', dwords(4) + strings + subsection(0xF4, checksum), 0)
    text = unit.section('.text$mn', b'\x31\xc0\x90\xc3', SCN_TEXT)
    toy = unit.define('toy', text, storage=STORAGE_STATIC if static else STORAGE_EXTERNAL, function=True)
    proc = struct.pack('<H8IHB', 0x1110, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0) + b'Toy::call\0'
    records = subsection(0xF1, struct.pack('<H', len(proc)) + proc)
    line = struct.pack('<IHHI', 0, 0, 1, 4) + dwords(0, 3, 48)
    line += dwords(0, 3 | (1 << 31), 1, 0xFEEFEE, 3, 5) + b'\0' * 12
    debug = unit.section('.debug$S', dwords(4) + records + subsection(0xF2, line), 0)
    for offset in (12 + 32, 4 + len(records) + 8):
        unit.reloc(debug, offset, toy, 0x0B)
        unit.reloc(debug, offset + 4, toy, 0x0A)
    return unit.coff()


class SymbolMapTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.path = self.root / SOURCE
        self.path.parent.mkdir()
        self.path.write_bytes(TOY)
        self.objects = self.root / 'objects'
        self.objects.mkdir()

    def collect(self, blob, build_root=None, static=False, **changes):
        obj = CoffObject(blob)
        ordinary = symbols.plain_coff_view(obj) if static else obj
        target = next(sym for sym in ordinary.symbols.values() if sym.is_function)
        code = ordinary.section(target.section)
        spec = {'rva': RVA, 'size': len(code.data), 'symbol': 'toy',
                'source_path': SOURCE, 'source_revision': 'fixture', 'record_code_sections': 1}
        if static:
            spec['internal_identity'] = selector(ordinary, target)
            self.assertEqual(spec['internal_identity']['section_number'], 2)
            digest = internal_code_sha256(ordinary, [code], spec)
        else:
            digest = code_section_sha256(obj, [code])
        spec['record_code_section_sha256'] = digest
        spec.update(changes)
        (self.objects / 'toy.obj').write_bytes(blob)
        plan = {'build_id': 'toy', 'units': [{'unit': 'toy', 'compiled': SOURCE, 'functions': [spec]}]}
        return symbols.collect(plan, self.objects, symbols.SourceFiles(self.root, build_root))

    def test_rebases_procedure_and_lines_with_a_gap(self):
        result = self.collect(fixture('c:/src/reconstruction/toy.cpp'), 'C:/src')
        self.assertEqual(result['coverage'], {'planned': 1, 'symbols': 1, 'with_lines': 1,
                                              'code_hash_verified': 1, 'missing': {}})
        first = symbols.lookup(result['functions'], RVA)
        self.assertEqual((first['name'], first['unit'], first['labels']), ('Toy::call', SOURCE, [ORIGIN]))
        self.assertEqual((first['line']['line'], first['line']['statement']), (3, True))
        self.assertIsNone(symbols.lookup(result['functions'], RVA + 1)['line'])
        self.assertEqual(symbols.lookup(result['functions'], RVA + 3)['line']['line'], 5)
        self.assertIsNone(symbols.lookup(result['functions'], RVA + 4))

    def test_renumbers_static_symbols_for_the_accepted_selector(self):
        result = self.collect(fixture(static=True), static=True)
        self.assertEqual(result['coverage']['code_hash_verified'], 1)
        self.assertEqual(result['functions'][0]['name'], 'Toy::call')
        self.assertEqual(len(result['functions'][0]['lines']), 2)

    def test_excludes_foreign_and_changed_sources_from_line_ranges(self):
        foreign = self.collect(fixture('/sdk/reconstruction/Toy.cpp'))
        self.assertEqual(foreign['coverage']['with_lines'], 0)
        self.path.write_bytes(b'\n' + TOY)
        stale = self.collect(fixture())
        self.assertEqual(stale['coverage']['symbols'], 1)
        self.assertEqual(stale['coverage']['with_lines'], 0)

    def test_rejects_wrong_size_or_code_hash(self):
        for changes, reason in (({'size': 1}, 'code-size-mismatch'),
                                ({'record_code_section_sha256': 'wrong'}, 'code-hash-mismatch')):
            with self.subTest(reason=reason):
                result = self.collect(fixture(), **changes)
                self.assertEqual(result['missing'], [{'rva': RVA, 'reason': reason}])

    def test_keeps_exact_labels_from_the_units_included_header(self):
        label = 'SYMBOLS(tesv-2013-map)'
        self.path.with_suffix('.h').write_text(f'// Toy: {label}\n', encoding='utf-8')
        self.path.write_bytes(TOY + b'#include "Toy.h"\n')
        result = self.collect(fixture())
        self.assertEqual(result['functions'][0]['labels'], [ORIGIN, label])

    def test_output_path_must_resolve_under_local(self):
        with self.assertRaises(ValueError):
            symbols.local_path(self.root / 'symbols.json')
        self.assertEqual(symbols.local_path(self.root / '.local' / 'symbols.json'),
                         self.root.resolve() / '.local' / 'symbols.json')


LLVM = {name: shutil.which(name) for name in ('clang-cl', 'clang', 'lld-link', 'llvm-symbolizer', 'llvm-pdbutil')}


@unittest.skipUnless(all(LLVM.values()), 'needs Clang, LLD and LLVM symbol tools on PATH')
class PdbTest(unittest.TestCase):
    def test_compiled_cpp_resolves_at_a_different_rva(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / SOURCE).parent.mkdir()
            (root / SOURCE).write_bytes(TOY)
            output = root / '.local'
            output.mkdir()
            subprocess.run([LLVM['clang-cl'], '--target=x86_64-pc-windows-msvc', '/nologo', '/c', '/O2',
                            '/Gy', '/Z7', '/Fo.local/toy.obj', SOURCE], cwd=root, check=True, capture_output=True)
            obj = CoffObject((output / 'toy.obj').read_bytes())
            target = next(sym for sym in obj.symbols.values() if sym.name == 'toy')
            size = len(obj.section(target.section).data)
            plan = {'build_id': 'toy', 'units': [{'unit': 'toy', 'compiled': SOURCE, 'functions': [
                {'rva': RVA, 'size': size, 'symbol': 'toy', 'source_path': SOURCE}]}]}
            mapping = symbols.collect(plan, output, symbols.SourceFiles(root))
            self.assertEqual(mapping['coverage']['with_lines'], 1)
            pdb = output / 'toy.pdb'
            carrier = write_pdb(mapping, pdb, str(root), LLVM['clang'], LLVM['lld-link'])
            found = subprocess.check_output([LLVM['llvm-symbolizer'], '--functions=short', '--relative-address',
                                             f'--obj={carrier}', hex(RVA), hex(RVA + size - 1)], text=True)
            self.assertIn('toy\n', found)
            self.assertIn('Toy.cpp:3:0', found)
            self.assertIn('Toy.cpp:6:0', found)
            origins = output / 'origins.json'
            subprocess.run([LLVM['llvm-pdbutil'], 'export', f'--stream={PROVENANCE_STREAM}',
                            f'--out={origins}', str(pdb)], check=True, capture_output=True)
            self.assertEqual(json.loads(origins.read_text()), {'build_id': 'toy', 'labels': {str(RVA): [ORIGIN]}})


if __name__ == '__main__':
    unittest.main()
