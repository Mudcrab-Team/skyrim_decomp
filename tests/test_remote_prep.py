"""Tests for tools/verifier/remote_prep.py and prep_agent.py against a local "host" (no ssh, no game data)."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import remote_prep  # noqa: E402
import runners  # noqa: E402

SCRIPT = '''\
import json, os, sys
from pathlib import Path
rva = sys.argv[1]
tdir = Path('.local/contrib/tasks/contrib-toy-' + rva[2:])
tdir.mkdir(parents=True)
pack = Path('.local/contrib/packs/b1') / rva
pack.mkdir(parents=True)
(pack / 'pack.json').write_text('{}')
(tdir / 'task.json').write_text(json.dumps({'functions': [{'rva': rva, 'pack': str(Path.cwd() / pack)}], 'image': os.environ['SR_SKYRIM_EXE']}))
Path('reconstruction').mkdir(exist_ok=True)
Path('reconstruction/Toy_' + rva[2:] + '.cpp').write_text('// toy')
print('started', rva, Path('data/seen.txt').read_text().strip(), Path('.local/analysis/functions.jsonl').exists())
'''


def git(repo, *args):
    subprocess.run(['git', '-C', str(repo), *args], check=True, capture_output=True)


class RemotePrep(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        tmp = Path(self.tmp.name)
        self.repo = tmp / 'repo'
        (self.repo / 'data').mkdir(parents=True)
        (self.repo / 'data/seen.txt').write_text('v1\n')
        (self.repo / 'tests').mkdir()
        (self.repo / 'tests/skipped.py').write_text('x')
        (self.repo / 'reconstruction').mkdir()
        (self.repo / 'reconstruction/Old.cpp').write_text('old')
        git(self.repo, 'init', '-q')
        git(self.repo, 'add', '-A')
        git(self.repo, '-c', 'user.name=t', '-c', 'user.email=t@t', 'commit', '-q', '-m', 'init')
        self.local = tmp / 'local'
        (self.local / 'analysis').mkdir(parents=True)
        (self.local / 'analysis/functions.jsonl').write_text('{"rva": 1}\n')
        (tmp / 'work').mkdir()
        host = {'host_id': 'toy-host', 'machine': 'toy', 'backend': 'local', 'loader': 'native', 'msvc': str(tmp),
                'work': str(tmp / 'work'), 'max_parallel': 1, 'image': str(tmp / 'Toy.exe')}
        self.prep = remote_prep.Prep(host, local=self.local, repo=self.repo)
        self.remote = tmp / 'work' / 'prep' / 'repo'

    def test_first_sync_sends_tracked_files_and_private_inputs(self):
        sent, gone, size = self.prep.sync()
        self.assertEqual((sent, gone), (3, 0))
        self.assertTrue((self.remote / 'data/seen.txt').is_file())
        self.assertTrue((self.remote / 'reconstruction/Old.cpp').is_file())
        self.assertTrue((self.remote / '.local/analysis/functions.jsonl').is_file())
        self.assertFalse((self.remote / 'tests').exists())

    def test_second_sync_sends_nothing_and_a_change_sends_one_file(self):
        self.prep.sync()
        self.assertEqual(self.prep.sync(), (0, 0, 0))
        (self.repo / 'data/seen.txt').write_text('v2\n')
        sent, gone, _ = self.prep.sync()
        self.assertEqual((sent, gone), (1, 0))
        self.assertEqual((self.remote / 'data/seen.txt').read_text(), 'v2\n')

    def test_a_file_git_no_longer_lists_is_deleted(self):
        self.prep.sync()
        git(self.repo, 'rm', '-q', '-f', 'reconstruction/Old.cpp')
        sent, gone, _ = self.prep.sync()
        self.assertEqual((sent, gone), (0, 1))
        self.assertFalse((self.remote / 'reconstruction/Old.cpp').exists())

    def test_a_changed_private_input_is_sent_again(self):
        self.prep.sync()
        (self.local / 'analysis/functions.jsonl').write_text('{"rva": 1}\n{"rva": 2}\n')
        sent, _, _ = self.prep.sync()
        self.assertEqual(sent, 1)

    def test_start_returns_the_run_files_and_leaves_the_host_as_it_was(self):
        self.prep.sync()
        script = Path(self.tmp.name) / 'toy_start.py'
        script.write_text(SCRIPT)
        into = Path(self.tmp.name) / 'back'
        code, count, tail = self.prep.start(['0x1234'], script=script, into=into)
        self.assertEqual(code, 0)
        self.assertIn('started 0x1234 v1 True', tail)
        self.assertEqual(count, 3)
        task = json.loads((into / '.local/contrib/tasks/contrib-toy-1234/task.json').read_text())
        self.assertEqual(task['image'], str(Path(self.tmp.name) / 'Toy.exe'))
        self.assertEqual(task['functions'][0]['pack'], str(into / '.local/contrib/packs/b1/0x1234'))
        self.assertTrue((into / 'reconstruction/Toy_1234.cpp').is_file())
        self.assertFalse((self.remote / 'reconstruction/Toy_1234.cpp').exists())
        self.assertFalse((self.remote / '.local/contrib/packs/b1/0x1234').exists())
        self.assertEqual(self.prep.sync(), (0, 0, 0))

    def test_several_rvas_run_one_script_each_in_parallel(self):
        self.prep.sync()
        script = Path(self.tmp.name) / 'toy_start.py'
        script.write_text(SCRIPT)
        into = Path(self.tmp.name) / 'back3'
        code, count, tail = self.prep.start(['0x10', '0x20', '0x30'], script=script, into=into, jobs=3)
        self.assertEqual(code, 0)
        self.assertEqual(count, 9)
        self.assertEqual(tail.count('exit 0'), 3)
        for rva in ('10', '20', '30'):
            self.assertTrue((into / f'.local/contrib/tasks/contrib-toy-{rva}/task.json').is_file())

    def test_one_failing_run_sets_the_exit_code(self):
        self.prep.sync()
        script = Path(self.tmp.name) / 'maybe.py'
        script.write_text("import sys\nsys.exit(7 if sys.argv[1] == '0x2' else 0)\n")
        code, _count, tail = self.prep.start(['0x1', '0x2'], script=script, into=Path(self.tmp.name) / 'back4', jobs=2)
        self.assertEqual(code, 7)
        self.assertIn('0x2: exit 7', tail)

    def test_a_rewritten_tracked_file_is_sent_again(self):
        self.prep.sync()
        script = Path(self.tmp.name) / 'rewrite.py'
        script.write_text("from pathlib import Path\nPath('reconstruction/Old.cpp').write_text('changed')\n")
        self.prep.start(['0x1'], script=script, into=Path(self.tmp.name) / 'back2')
        sent, _, _ = self.prep.sync()
        self.assertEqual(sent, 1)
        self.assertEqual((self.remote / 'reconstruction/Old.cpp').read_text(), 'old')

    def test_no_prep_host_is_a_clear_error(self):
        with self.assertRaises(remote_prep.PrepError):
            remote_prep.prep_host({'hosts': {}, 'prep': None})

    def test_runners_config_checks_the_prep_host(self):
        base = {'runners_schema': 1, 'attempt': 'boat', 'hosts': {'boat': {'backend': 'boat'}}}
        with self.assertRaises(runners.RunnerError):
            runners.validate(dict(base, prep='boat'))
        with self.assertRaises(runners.RunnerError):
            runners.validate(dict(base, prep='nowhere'))
        self.assertIsNone(runners.validate(base)['prep'])


if __name__ == '__main__':
    unittest.main()
