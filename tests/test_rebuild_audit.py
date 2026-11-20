"""Synthetic audit tests: no game inputs, compiler, network or acceptance mutations."""
import argparse
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SPEC = importlib.util.spec_from_file_location('rebuild_audit', Path(__file__).resolve().parents[1] / 'tools/rebuild_audit.py')
audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(audit)


class AuditTests(unittest.TestCase):
    def test_recover_torn_final_append_and_refuse_inner_corruption(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'state.jsonl'
            path.write_bytes(b'{"unit":"u0"}\n{"unit":')
            self.assertEqual(audit.read_journal(path), {'u0': {'unit': 'u0'}})
            self.assertEqual(path.read_bytes(), b'{"unit":"u0"}\n')
            path.write_bytes(b'broken\n{"unit":"u1"}\n')
            with self.assertRaises(ValueError):
                audit.read_journal(path)
            path.write_bytes(b'{"unit":"u0"}\n{"unit":"u0"}\n')
            with self.assertRaises(ValueError):
                audit.read_journal(path)

    def test_atomic_write_retries_windows_reader_sharing_violation(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'summary.json'
            original = audit.os.replace
            calls = []
            def replace(source, dest):
                calls.append((source, dest))
                if len(calls) < 3:
                    raise PermissionError('synthetic Windows sharing violation')
                original(source, dest)
            with patch.object(audit.os, 'replace', side_effect=replace), patch.object(audit.time, 'sleep'):
                audit.json_write(path, {'passed': 1})
            self.assertEqual(json.loads(path.read_text()), {'passed': 1})
            self.assertEqual(len(calls), 3)
            with patch.object(audit.os, 'replace', side_effect=PermissionError), patch.object(audit.time, 'sleep'):
                with self.assertRaises(PermissionError):
                    audit.json_write(path, {'passed': 2})
            self.assertEqual(json.loads(path.read_text()), {'passed': 1})

    def test_outputs_and_export_paths_are_private_and_contained(self):
        for path in ('/tmp/public-output',):
            with self.assertRaises(ValueError):
                audit.private(path)
        for path in ('../secret', '/tmp/secret', 'C:/secret', '.local/secret', '.git/config', 'x\\secret'):
            with self.subTest(path=path), self.assertRaises(ValueError):
                audit.relative(path)
        self.assertEqual(audit.relative('reconstruction/a/A.h'), 'reconstruction/a/A.h')

    def test_summary_distinguishes_pending_drift_and_comparison_failure(self):
        row = dict(unit='u0', functions=[
            dict(rva=16, result='pass', cause=None, digest_drift=True, code_hash_drift=False),
            dict(rva=32, result='fail', cause='other', digest_drift=False, code_hash_drift=True)])
        s = audit.summarize(dict(total=3, units=[1, 2]), {'u0': row}, {'host': 'synthetic'}, 2)
        self.assertEqual((s['passed'], s['failed'], s['pending']), (1, 1, 1))
        self.assertEqual(s['digest_drift'], 1)
        self.assertEqual(s['failure_causes'], {'other': 1})
        self.assertEqual(s['failures'][0]['rva'], 32)

    def test_cause_is_an_explicit_candidate_not_all_drift(self):
        self.assertEqual(audit.classify(44, 'toolchain-mismatch', True), 'recipe-or-compiler-mismatch')
        self.assertEqual(audit.classify(3, 'compile-error', True), 'header-drift')
        self.assertEqual(audit.classify(3, 'compile-error', False), 'other')
        self.assertEqual(audit.classify(42, 'image-missing', False), 'missing-file')

    def test_worker_uses_fresh_copy_and_comparator_result_with_drift(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            export = root / 'export'
            (export / 'tree').mkdir(parents=True)
            (export / 'tree/a.cpp').write_text('// synthetic')
            unit = dict(id='u0', files={'a.cpp': audit.digest(export / 'tree/a.cpp')}, compiled='a.cpp',
                        recipe='recipe.json', symbols='symbols.json', build_id='synthetic', drift=True,
                        functions=[dict(rva=16, size=1, symbol='synthetic', digest_drift=True, expected_hashes=['abc'])])
            args = argparse.Namespace(out=root / 'out', host='synthetic', msvc=root, image=root, loader='native')
            def compile_fake(command, **kwargs):
                work = Path(command[command.index('--work')+1])
                (work / '0x10').mkdir(parents=True)
                (work / '0x10/report.json').write_text(json.dumps(dict(result='pass', function={'rva': 16}, candidate={'code_section_sha256': 'abc'})))
                return argparse.Namespace(returncode=0)
            with patch.object(audit.subprocess, 'run', compile_fake):
                row = audit.execute_unit(export, unit, args)
            self.assertEqual(row['functions'][0]['result'], 'pass')
            self.assertTrue(row['functions'][0]['digest_drift'])
            self.assertFalse((args.out / 'scratch/u0').exists())
            unit['preflight'] = 'recipe-or-compiler-mismatch'
            with patch.object(audit.subprocess, 'run', side_effect=AssertionError('must not silently use another recipe')):
                row = audit.execute_unit(export, unit, args)
            self.assertEqual(row['functions'][0]['result'], 'fail')
            self.assertEqual(row['functions'][0]['cause'], 'recipe-or-compiler-mismatch')

    def test_prepare_selects_matched_and_preserves_internal_selector(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            repo, out = root / 'repo', root / '.local/export'
            names = set(audit.TOOL_FILES) | {'a.cpp', 'a.h', 'recipe.json', 'symbols.json',
                                           'record.json', 'data/progress.json', 'tools/check_source_digest.py'}
            for name in names:
                path = repo / name
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text('{}')
            # Use the real scanner, copied only as original test infrastructure.
            scanner = Path(__file__).resolve().parents[1] / 'tools/source_digest.py'
            (repo / 'tools/source_digest.py').write_bytes(scanner.read_bytes())
            (repo / 'tools/digest_v2.py').write_bytes(scanner.with_name('digest_v2.py').read_bytes())
            (repo / 'tools/check_source_digest.py').write_bytes(scanner.with_name('check_source_digest.py').read_bytes())
            (repo / 'a.cpp').write_text('#include "a.h"\n')
            (repo / 'a.h').write_text('// original synthetic header\n')
            (repo / 'builds/target.json').write_text(json.dumps({'build_id': 'synthetic', 'image_sha256': '0'*64}))
            fn = dict(id='synthetic-0x10', build_id='synthetic', rva=16, size=1, status='matched', report='record.json')
            (repo / 'data/progress.json').write_text(json.dumps({'functions': [fn, dict(fn, status='planned')]}))
            selector = dict(section_number=1, section_name='.text', entry_offset=0, storage_class=3, symbol_type=32)
            rec = dict(function_id=fn['id'], source=dict(compiled='a.cpp', digest='old'),
                       recipe=dict(path='recipe.json', sha256=audit.digest(repo / 'recipe.json')),
                       symbol_map=dict(path='symbols.json', sha256=audit.digest(repo / 'symbols.json')),
                       toolchain_pin=dict(path='tools/verifier/pinned.sha256', sha256=audit.digest(repo / 'tools/verifier/pinned.sha256')),
                       runs=[{'report': dict(function=dict(build_id='synthetic', rva=16, size=1, symbol='synthetic',
                                                          internal_identity=dict(selector, object_sha256='old')),
                                             candidate={'code_section_sha256': 'abc'})}])
            (repo / 'record.json').write_text(json.dumps(rec))
            with patch.object(audit, 'git', side_effect=['commit', 'commit', '', '', 'commit']):
                plan = audit.prepare(repo, out, 'origin/main')
            self.assertEqual(plan['total'], 1)
            unit = plan['units'][0]
            self.assertEqual(unit['functions'][0]['internal_selector'], selector)
            self.assertTrue(unit['functions'][0]['digest_drift'])
            self.assertIsNone(unit['preflight'])
            self.assertEqual((out / 'tree/a.h').read_bytes(), (repo / 'a.h').read_bytes())
            self.assertFalse((out / 'tree/record.json').exists())
            # An older, still valid global map must not become a false compiler failure.
            import sys
            sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
            import symbol_map
            old = dict(schema=1, build_id='synthetic', symbols={'synthetic': {'rva': 16, 'size': 1}})
            current = dict(old, symbols=dict(old['symbols'], unrelated={'rva': 32, 'size': 1}))
            old_sha = symbol_map.sha256(symbol_map.serialize(old))
            current_sha = symbol_map.sha256(symbol_map.serialize(current))
            (repo / 'symbols.json').write_bytes(symbol_map.serialize(current))
            (repo / 'symbols.history.json').write_text(json.dumps(dict(schema=1, map='symbols.json', versions=[
                dict(sha256=old_sha, base=None, added=['synthetic']),
                dict(sha256=current_sha, base=0, added=['unrelated'])])))
            rec['symbol_map']['sha256'] = old_sha
            (repo / 'record.json').write_text(json.dumps(rec))
            out2 = out.with_name('historical-export')
            with patch.object(audit, 'git', side_effect=['commit', 'commit', '', '', 'commit']):
                plan2 = audit.prepare(repo, out2, 'origin/main')
            unit2 = plan2['units'][0]
            self.assertIsNone(unit2['preflight'])
            self.assertEqual(audit.digest(out2 / 'tree' / unit2['symbols']), old_sha)
            self.assertEqual(audit.digest(repo / 'symbols.json'), current_sha)

    def test_resume_runs_only_pending_and_binds_plan_and_driver(self):
        from types import SimpleNamespace
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp) / '.local'
            export = root / 'export'
            (export / 'tree/tools/verifier').mkdir(parents=True)
            (export / 'tree/tools/verifier/pinned.sha256').write_text('synthetic pins')
            image = root / 'image'
            image.write_text('original synthetic target')
            units = [dict(id='u0'), dict(id='u1')]
            plan = dict(commit='a'*40, image_sha256=audit.digest(image), files={}, total=2, units=units)
            audit.json_write(export / 'plan.json', plan)
            args = argparse.Namespace(export=export, out=root / 'out', msvc=root, image=image,
                                      host='synthetic', loader='native', jobs=1, limit=1)
            fake_builder = SimpleNamespace(clean_env=lambda env: env, native_settings=lambda p: {},
                prepare_host=lambda *a, **k: ('checked', {'cl.exe': 'pin'}),
                host_facts=lambda *a: {'loader': 'native', 'os': 'windows'})
            def execute(exp, unit, arg):
                return dict(unit=unit['id'], functions=[dict(rva=int(unit['id'][1:]), result='pass',
                            cause=None, digest_drift=False, code_hash_drift=False)])
            with patch.dict(audit.sys.modules, {'unit_build': fake_builder}), patch.object(audit, 'execute_unit', side_effect=execute) as worker:
                self.assertEqual(audit.run(args), 2)
                self.assertEqual(worker.call_count, 1)
                args.limit = None
                self.assertEqual(audit.run(args), 0)
                self.assertEqual(worker.call_count, 2)
                self.assertEqual(audit.run(args), 0)
                self.assertEqual(worker.call_count, 2)
                plan['commit'] = 'b'*40
                audit.json_write(export / 'plan.json', plan)
                with self.assertRaises(ValueError):
                    audit.run(args)
                plan['commit'] = 'a'*40
                audit.json_write(export / 'plan.json', plan)
                (args.out / 'identity.json').unlink()
                with self.assertRaises(ValueError):
                    audit.run(args)
                self.assertFalse((args.out / 'identity.json').exists())

    def test_prepare_refuses_dirty_or_wrong_revision_before_export(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / '.local/export'
            with patch.object(audit, 'git', side_effect=['a', 'b']):
                with self.assertRaises(ValueError):
                    audit.prepare(tmp, out, 'origin/main')
            with patch.object(audit, 'git', side_effect=['a', 'a', ' M file']):
                with self.assertRaises(ValueError):
                    audit.prepare(tmp, out, 'origin/main')
            self.assertFalse(out.exists())


if __name__ == '__main__':
    unittest.main()
