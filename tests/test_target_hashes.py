"""Advisory target normalization/intake; fixtures are original synthetic code only."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import compare
from pecoff import CoffObject, Reject
import ci_target_hash_check as ci
import target_hashes as h
import synthetic_pecoff as fx


class TargetHashTest(unittest.TestCase):
    def test_same_fields_as_comparator_with_standard_unkeyed_sha256(self):
        inputs = fx.inputs()
        report = compare.compare(**inputs)
        self.assertEqual(report['result'], 'pass')
        _sym, sec = compare.find_function(CoffObject(inputs['object_bytes']), fx.FUNCTION)
        spans = h.layout(sec)
        self.assertEqual(sum(b - a for a, b, _ in spans), report['coverage']['code_bytes_by_reference'])
        target = fx.link(fx.CODE, fx.RELOCS, fx.LAYOUT, fx.LAYOUT[fx.FUNCTION])
        expected = hashlib.sha256(h.normalized(target, spans)).hexdigest()
        row = dict(size=len(target), **h.section_hash(sec))
        self.assertEqual(expected, row['normalized_sha256'])
        self.assertEqual(h.candidate(inputs['object_bytes'], fx.FUNCTION, row), 'hash-match')
        # The timestamp is outside the function; a real instruction change is not.
        stamped = bytearray(inputs['object_bytes'])
        struct.pack_into('<I', stamped, 4, 314159)
        self.assertEqual(h.candidate(stamped, fx.FUNCTION, row), 'hash-match')
        changed = fx.coff_object(code=fx.CODE[:-1] + bytes([0x90]))
        self.assertEqual(h.candidate(changed, fx.FUNCTION, row), 'mismatch')
        row['size'] += 1
        self.assertEqual(h.candidate(inputs['object_bytes'], fx.FUNCTION, row), 'mismatch')

    def test_candidate_cannot_expand_mask_to_hide_instruction_changes(self):
        _sym, sec = compare.find_function(CoffObject(fx.coff_object()), fx.FUNCTION)
        target = dict(size=len(sec.data), **h.section_hash(sec))
        blob = fx.coff_object(relocs=(*fx.RELOCS, (0, fx.CALLEE, fx.REL32)))
        self.assertEqual(h.candidate(blob, fx.FUNCTION, target), 'no-target')
        for relocs in (((len(sec.data) - 1, fx.CALLEE, fx.REL32),),
                       ((0, fx.CALLEE, 1),),
                       ((0, fx.CALLEE, fx.REL32), (1, fx.CALLEE, fx.REL32))):
            with self.assertRaises(Reject):
                h.candidate(fx.coff_object(relocs=relocs), fx.FUNCTION, target)

    def test_reference_targets_remain_the_local_comparators_job(self):
        # The weaker prefilter deliberately omits reference identity; acceptance still rejects it.
        inputs = fx.inputs()
        _sym, sec = compare.find_function(CoffObject(inputs['object_bytes']), fx.FUNCTION)
        row = dict(size=len(sec.data), **h.section_hash(sec))
        bad = bytearray(fx.CODE)
        struct.pack_into('<i', bad, fx.RELOCS[0][0], 123)
        blob = fx.coff_object(code=bad)
        self.assertEqual(h.candidate(blob, fx.FUNCTION, row), 'hash-match')
        inputs['object_bytes'] = blob
        inputs['build_record']['object_sha256'] = h.digest(blob)
        self.assertEqual(compare.compare(**inputs)['reason'], 'relocation-target-mismatch')

    def test_linked_field_extraction_preserves_internal_branches(self):
        try:
            import iced_x86
        except ImportError:
            self.skipTest('local generator dependency iced-x86==1.21.0 not installed')
        data = fx.link(fx.CODE, fx.RELOCS, fx.LAYOUT, fx.LAYOUT[fx.FUNCTION])
        sec = h.target_section(data, fx.LAYOUT[fx.FUNCTION])
        self.assertEqual([(a, k) for a, _, k in h.layout(sec)], [(a, k) for a, _, k in fx.RELOCS])
        # A local jump's displacement is exact code, and is never erased.
        self.assertEqual(h.layout(h.target_section(bytes.fromhex('eb00c3'), 0x1000)), [])
        recursive = h.target_section(bytes.fromhex('e8fbffffffc3'), 0x1000)
        self.assertEqual(h.layout(recursive), [(1, 5, fx.REL32)])

    def test_thread_local_epoch_offset_is_inferred_only_in_the_guard_shape(self):
        try:
            import iced_x86  # noqa: F401
        except ImportError:
            self.skipTest('local generator dependency iced-x86==1.21.0 not installed')
        tls = bytes.fromhex('65488b042558000000')  # mov rax, gs:[58h]
        index = bytes.fromhex('ba082a0000')  # mov edx, imm32
        use = bytes.fromhex('488b0cc8' '8b040a' 'c3')  # mov rcx,[rax+rcx*8]; mov eax,[rdx+rcx]; ret
        sec = h.target_section(tls + index + use, 0x1000)
        self.assertEqual(h.layout(sec), [(10, 14, compare.SECREL)])
        # The same immediate without the TLS-block lookup is ordinary code and stays exact.
        self.assertEqual(h.layout(h.target_section(index + bytes.fromhex('8b040a' 'c3'), 0x1000)), [])
        # An immediate in a register the lookup never uses is not a section offset.
        other = bytes.fromhex('be082a0000')  # mov esi, imm32
        lookup = bytes.fromhex('488b0cd0' 'c3')  # mov rcx,[rax+rdx*8]; ret
        self.assertEqual(h.layout(h.target_section(tls + other + lookup, 0x1000)), [])

    def test_thread_local_block_displacement_and_register_addend(self):
        try:
            import iced_x86
        except ImportError:
            self.skipTest('local generator dependency iced-x86==1.21.0 not installed')
        # Load the index and the TLS array, then load the indexed block into rax.
        prefix = bytes.fromhex('8b0dfa0f0000' '65488b042558000000' '488b04c8')
        disp = bytes.fromhex('8b9054020000c3')
        direct = h.target_section(prefix + disp, 0x1000, tls_index=0x2000, tls_size=0x300)
        self.assertEqual(h.layout(direct), [(2, 6, fx.REL32), (21, 25, compare.SECREL)])
        add = bytes.fromhex('ba54020000' '4801d0' '8b10c3')
        added = h.target_section(prefix + add, 0x1000, tls_index=0x2000, tls_size=0x300)
        self.assertEqual(h.layout(added), [(2, 6, fx.REL32), (20, 24, compare.SECREL)])
        for code, index, size in (
                (prefix + disp, 0x2004, 0x300),
                (prefix + disp, 0x2000, 0x200),
                (prefix + bytes.fromhex('31c0') + disp, 0x2000, 0x300),
                (prefix[:-4] + disp, 0x2000, 0x300),
                (prefix + bytes.fromhex('4883c001') + disp, 0x2000, 0x300)):
            with self.subTest(index=index, size=size, length=len(code)):
                self.assertEqual(h.layout(h.target_section(code, 0x1000, index, size)), [(2, 6, fx.REL32)])

    def test_preparation_reads_blobs_never_executes_pr_and_rejects_symlinks(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp) / 'repo'
            root.mkdir()
            def git(*args):
                return subprocess.check_output(['git', *args], cwd=root).decode().strip()
            git('init', '-q'); git('config', 'user.email', 'synthetic@example.invalid')
            git('config', 'user.name', 'Synthetic')
            for name in ('reconstruction/forms', 'builds', 'findings', 'reports'):
                (root / name).mkdir(parents=True)
            (root / 'builds/target.json').write_text(json.dumps(dict(build_id='synthetic')))
            (root / 'reconstruction/forms/X.cpp').write_text('old')
            for name in ('findings/a.md', 'reports/a.json'):
                (root / name).write_text('synthetic')
            git('add', '.'); git('commit', '-qm', 'base'); base = git('rev-parse', 'HEAD')
            (root / 'reconstruction/forms/X.cpp').write_text('new source only')
            git('add', '.'); git('commit', '-qm', 'source'); head = git('rev-parse', 'HEAD')
            git('checkout', '-q', base)
            with patch.object(ci.lint, 'lint_file', return_value=[]):
                tree, changed = ci.prepare(root, base, head, Path(tmp) / 'work')
            self.assertEqual(changed, ['reconstruction/forms/X.cpp'])
            self.assertEqual((tree / changed[0]).read_text(), 'new source only')
            self.assertEqual((root / changed[0]).read_text(), 'old')
            git('checkout', '-q', head)
            path = root / changed[0]
            path.unlink(); path.symlink_to('../../builds/target.json')
            git('add', '.'); git('commit', '-qm', 'symlink'); evil = git('rev-parse', 'HEAD')
            git('checkout', '-q', base)
            with self.assertRaisesRegex(ValueError, 'regular|scope'):
                ci.prepare(root, base, evil, Path(tmp) / 'evil')

    def test_generated_pdb_output_is_not_read_as_a_unit(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp) / 'repo'
            root.mkdir()

            def git(*args):
                return subprocess.check_output(['git', *args], cwd=root).decode().strip()
            git('init', '-q'); git('config', 'user.email', 'synthetic@example.invalid')
            git('config', 'user.name', 'Synthetic')
            for name in ('reconstruction/forms', 'builds', 'findings', 'reports'):
                (root / name).mkdir(parents=True)
            (root / 'builds/target.json').write_text(json.dumps(dict(build_id='synthetic')))
            (root / 'reconstruction/forms/X.cpp').write_text('old')
            for name in ('findings/a.md', 'reports/a.json'):
                (root / name).write_text('synthetic')
            git('add', '.'); git('commit', '-qm', 'base'); base = git('rev-parse', 'HEAD')
            gen = root / 'reconstruction/generated/crashlogger_pdb/types'
            gen.mkdir(parents=True)
            (gen / 'Thing.h').write_text('// CRASHLOGGER_PDB(59818@2000.01.01)\n')
            (gen.parent / 'README.md').write_text('<!-- CRASHLOGGER_PDB(59818@2000.01.01) -->\n')
            git('add', '.'); git('commit', '-qm', 'generated only'); only = git('rev-parse', 'HEAD')
            (root / 'reconstruction/forms/X.cpp').write_text('new source only')
            git('add', '.'); git('commit', '-qm', 'both'); both = git('rev-parse', 'HEAD')
            git('checkout', '-q', base)
            self.assertEqual(ci.prepare(root, base, only, Path(tmp) / 'a'), (root, []))
            with patch.object(ci.lint, 'lint_file', return_value=[]):
                _tree, changed = ci.prepare(root, base, both, Path(tmp) / 'b')
            self.assertEqual(changed, ['reconstruction/forms/X.cpp'])

    def test_published_manifest_is_complete_hash_metadata_without_masks_or_bytes(self):
        manifest = h.load_manifest(ROOT)
        disk = json.loads((ROOT / h.MANIFEST).read_text())
        self.assertEqual(disk['function_count'], len(manifest['functions']))
        self.assertEqual(disk['hash_algorithm'], 'SHA-256')
        self.assertNotIn('functions', disk)
        allowed = {'rva', 'size', 'normalized_sha256', 'layout_sha256', 'extraction'}
        for row in manifest['functions']:
            self.assertEqual(set(row), allowed)
        for shard in disk['shards']:
            self.assertLess((ROOT / shard['path']).stat().st_size, 1024 * 1024)
        sample = json.loads((ROOT / 'data/target-hashes/determinism-sample.json').read_text())['rvas']
        self.assertEqual(len(sample), 50)
        self.assertEqual(len(set(sample)), 50)
        self.assertTrue(set(sample) <= {row['rva'] for row in manifest['functions']})

    def test_all_offered_candidates_and_individual_claims_have_published_targets(self):
        manifest=h.load_manifest(ROOT); covered={f['rva'] for f in manifest['functions']}
        progress=ci.contrib.inventory(ROOT)
        candidates={ci.contrib.parse_rva(c['rva']) for c in ci.contrib.candidates(ROOT,progress) if c['startable']}
        import claimable
        offered=claimable.sharded_json(ROOT,h.OFFERED,'functions')
        claimed={a for claim in offered['claims'] for a,b in claim['entries'] if b==a+1}
        self.assertTrue(candidates <= covered)
        self.assertTrue(claimed <= covered)
        self.assertFalse(offered['unresolved_rvas'])
        self.assertTrue(any(f['rva'] not in {p['rva'] for p in progress['functions']} for f in offered['functions']))

    def test_windows_checkout_preserves_raw_pin_file_digest(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            def git(*args):
                return subprocess.check_output(['git', *args], cwd=root)
            git('init', '-q')
            (root / '.gitattributes').write_bytes((ROOT / '.gitattributes').read_bytes())
            pins = b'a' * 64 + b'  cl.exe\n'
            path = root / 'pinned.sha256'
            path.write_bytes(pins)
            git('add', '.gitattributes', 'pinned.sha256')
            path.unlink()
            git('-c', 'core.autocrlf=true', 'checkout-index', '--all', '--force')
            self.assertEqual(path.read_bytes(), pins)

    def test_missing_and_stale_manifest_is_no_pass(self):
        with tempfile.TemporaryDirectory() as tmp:
            with patch.object(ci, 'ROOT', Path(tmp)), patch('builtins.print'):
                out = Path(tmp) / 'report.json'
                self.assertEqual(ci.main(['sample', '--work', str(Path(tmp) / 'work'), '--out', str(out)]), 1)
                report = json.loads(out.read_text())
                self.assertNotIn(tmp, out.read_text())
                self.assertEqual(report['acceptance'], 'not-evaluated')
                self.assertIn('error', report)


if __name__ == '__main__':
    unittest.main()
