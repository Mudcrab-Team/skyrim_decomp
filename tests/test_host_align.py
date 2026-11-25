"""The host agent aligns failing functions after a run (tools/verifier/host_agent.py), best effort."""
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import host_agent  # noqa: E402
import runners  # noqa: E402


class AlignOnHost(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.run_dir = Path(self.tmp.name) / 'run'
        tools = self.run_dir / 'repo' / 'tools' / 'verifier'
        tools.mkdir(parents=True)
        for name in ('align.py', 'disasm.py'):
            shutil.copyfile(ROOT / 'tools' / 'verifier' / name, tools / name)
        (self.run_dir / 'repo' / '.unit').mkdir()
        (self.run_dir / 'repo' / '.unit' / 'spec.json').write_text(json.dumps({'symbols': 'task/symbols.json'}))
        self.work = self.run_dir / 'work' / 'h'
        self.work.mkdir(parents=True)

    def test_a_run_without_an_object_is_left_alone(self):
        host_agent.align_on_host(self.run_dir, self.work, '/nonexistent/llvm-objdump', '/nonexistent/image.exe')
        self.assertFalse((self.work / host_agent.ALIGN_LOG).exists())

    def test_the_log_records_what_the_alignment_did(self):
        (self.work / 'candidate.obj').write_bytes(b'')
        host_agent.align_on_host(self.run_dir, self.work, '/nonexistent/llvm-objdump', '/nonexistent/image.exe')
        self.assertTrue((self.work / host_agent.ALIGN_LOG).read_text().startswith('exit'))

    def test_a_missing_spec_does_not_stop_the_run(self):
        (self.work / 'candidate.obj').write_bytes(b'')
        (self.run_dir / 'repo' / '.unit' / 'spec.json').unlink()
        host_agent.align_on_host(self.run_dir, self.work, '/nonexistent/llvm-objdump', '/nonexistent/image.exe')
        self.assertIn('not aligned', (self.work / host_agent.ALIGN_LOG).read_text())


class SideBySide(unittest.TestCase):
    def test_every_function_without_a_listing_gets_one(self):
        import align
        from unittest import mock
        with tempfile.TemporaryDirectory() as tmp:
            attempt = Path(tmp)
            for name, symbol in (('0x10', '?A@@YAXXZ'), ('0x20', '?B@@YAXXZ'), ('0x30', None)):
                (attempt / name).mkdir()
                (attempt / name / 'report.json').write_text(json.dumps({'function': {'rva': 16, 'size': 8, 'symbol': symbol}}))
            (attempt / '0x20' / 'side-by-side.txt').write_text('already there')
            calls = []

            def fake(dest, objdump, image, obj, symbol, rva, size):
                calls.append(symbol)
                Path(dest).write_text('x')
                return Path(dest), None
            with mock.patch.object(align.disasm, 'write_side_by_side', fake):
                self.assertEqual(align.write_side_by_sides(attempt, 'objdump', 'image'), 1)
            self.assertEqual(calls, ['?A@@YAXXZ'])
            self.assertEqual((attempt / '0x20' / 'side-by-side.txt').read_text(), 'already there')


class RunnerPassesTheObjdump(unittest.TestCase):
    def host(self, **extra):
        return dict({'host_id': 'toy-host', 'machine': 'toy', 'backend': 'local', 'loader': 'native', 'msvc': '/m',
                     'work': '/w', 'max_parallel': 1, 'image': '/i.exe', 'objdump': '/o/llvm-objdump'}, **extra)

    def test_align_is_off_until_asked(self):
        agent = runners.AgentHost(self.host(), {'task_id': 't'})
        self.assertFalse(agent.align)

    def test_validate_accepts_an_objdump_and_a_prep_host(self):
        raw = {'runners_schema': 1, 'attempt': 'win', 'prep': 'win', 'hosts': {'win': {
            'backend': 'ssh', 'host_id': 'toy-win', 'machine': 'toy', 'loader': 'native', 'ssh_config': 'cfg',
            'ssh_host': 'toy', 'python': ['python'], 'msvc': 'C:/m', 'image': 'C:/i.exe', 'work': 'C:/w',
            'objdump': 'C:/llvm/llvm-objdump.exe'}}}
        out = runners.validate(raw, root=Path(self.id()))
        self.assertEqual(out['prep'], 'win')
        self.assertEqual(out['hosts']['win']['objdump'], 'C:/llvm/llvm-objdump.exe')


if __name__ == '__main__':
    unittest.main()
