"""Contributor CLI behaviour in a linked git worktree and with several tasks, on synthetic inputs."""
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
import unittest.mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import contrib  # noqa: E402
from local_paths import main_checkout_local  # noqa: E402


def git(cwd, *args):
    subprocess.run(['git', '-c', 'user.name=t', '-c', 'user.email=t@t', *args], cwd=cwd, check=True,
                   capture_output=True)


class WorktreeToolchainTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.main = self.tmp / 'main'
        self.main.mkdir()
        git(self.main, 'init', '-q', '-b', 'main')
        (self.main / 'f').write_text('x')
        git(self.main, 'add', 'f')
        git(self.main, 'commit', '-q', '-m', 'c')
        self.linked = self.tmp / 'linked'
        git(self.main, 'worktree', 'add', '-q', '-b', 'w', str(self.linked))
        tail = Path(contrib.MAC_WINE['app']) / 'Contents/Resources/wine/bin'
        self.msvc = self.main / '.local/toolchains/msvc-1'
        (self.msvc / 'VC/Tools/MSVC/14.16/bin/Hostx64/x64').mkdir(parents=True)
        self.wine = self.main / '.local/toolchains/wine-1' / tail
        self.wine.mkdir(parents=True)
        (self.wine / 'wine').write_text('')
        # The worktree has a private store of its own, so the whole-.local fallback does not apply.
        (self.linked / '.local/contrib').mkdir(parents=True)

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def ctx(self):
        return contrib.Ctx(repo=self.linked, env={'PATH': ''}, platform='darwin', interactive=False)

    def test_common_dir_finds_the_main_checkout(self):
        self.assertEqual(main_checkout_local(self.linked), (self.main / '.local').resolve())
        self.assertIsNone(main_checkout_local(self.main))

    def test_toolchains_fall_back_to_the_main_checkout(self):
        ctx = self.ctx()
        self.assertEqual(ctx.local, self.linked / '.local')
        self.assertEqual(contrib.toolchain_root(ctx), self.msvc)
        self.assertEqual(contrib.private_wine_bin(ctx), self.wine)
        self.assertTrue(contrib.mac_wine_ready(ctx))

    def test_own_toolchain_wins_and_overrides_win(self):
        own = self.linked / '.local/contrib/msvc'
        (own / 'VC/Tools/MSVC/14.16/bin/Hostx64/x64').mkdir(parents=True)
        self.assertEqual(contrib.toolchain_root(self.ctx()), own)
        ctx = self.ctx()
        ctx.env['SR_MSVC'] = str(self.tmp / 'elsewhere')
        self.assertEqual(contrib.toolchain_root(ctx), self.tmp / 'elsewhere')

    def test_nothing_anywhere_keeps_the_own_default(self):
        shutil.rmtree(self.main / '.local/toolchains')
        ctx = self.ctx()
        self.assertEqual(contrib.toolchain_root(ctx), ctx.private / 'msvc')
        self.assertFalse(contrib.mac_wine_ready(ctx))


class CurrentTaskTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.repo = self.tmp / 'repo'
        self.repo.mkdir()
        git(self.repo, 'init', '-q', '-b', 'main')
        for name in ('A', 'B', 'C'):
            unit = self.repo / f'reconstruction/forms/{name}.cpp'
            unit.parent.mkdir(parents=True, exist_ok=True)
            unit.write_text('//\n')
        git(self.repo, 'add', '.')
        git(self.repo, 'commit', '-q', '-m', 'c')
        self.ctx = contrib.Ctx(repo=self.repo, env={}, private=self.tmp / 'private', interactive=False)
        for i, name in enumerate(('A', 'B', 'C')):
            tdir = self.tmp / 'private/tasks' / f'contrib-{name.lower()}'
            tdir.mkdir(parents=True)
            path = f'reconstruction/forms/{name}.cpp'
            (tdir / 'task.json').write_text(json.dumps({
                'task_id': tdir.name, 'compiled': path, 'functions': [],
                'contrib': {'practice': False, 'unit': [path.replace('.cpp', '.h'), path]}}))
            os.utime(tdir / 'task.json', (1000 + i, 1000 + i))

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def test_several_tasks_still_need_a_name_by_default(self):
        with self.assertRaises(contrib.Stop):
            contrib.load_task(self.ctx)

    def test_ambiguous_tasks_are_listed_without_using_recency(self):
        with self.assertRaises(contrib.Stop) as stopped:
            contrib.load_task(self.ctx, pick_current=True)
        for name in ('contrib-a', 'contrib-b', 'contrib-c'):
            self.assertIn(name, stopped.exception.message)

    def test_task_started_in_this_worktree_is_preferred(self):
        path = self.ctx.private / 'tasks/contrib-a/task.json'
        task = json.loads(path.read_text())
        task['contrib']['worktree'] = str(self.repo)
        path.write_text(json.dumps(task))
        tdir, _task = contrib.load_task(self.ctx, pick_current=True)
        self.assertEqual(tdir.name, 'contrib-a')

    def test_unit_with_uncommitted_changes_beats_recency(self):
        (self.repo / 'reconstruction/forms/A.cpp').write_text('// changed\n')
        tdir, _task = contrib.load_task(self.ctx, pick_current=True)
        self.assertEqual(tdir.name, 'contrib-a')

    def test_two_changed_units_limit_the_choices(self):
        (self.repo / 'reconstruction/forms/A.cpp').write_text('// changed\n')
        (self.repo / 'reconstruction/forms/B.cpp').write_text('// changed\n')
        with self.assertRaises(contrib.Stop) as stopped:
            contrib.load_task(self.ctx, pick_current=True)
        self.assertIn('contrib-a', stopped.exception.message)
        self.assertIn('contrib-b', stopped.exception.message)
        self.assertNotIn('contrib-c', stopped.exception.message)

    def test_an_explicit_name_is_untouched(self):
        tdir, _task = contrib.load_task(self.ctx, 'contrib-a', pick_current=True)
        self.assertEqual(tdir.name, 'contrib-a')


class StartExistingUnitTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.repo = self.tmp / 'repo'
        self.private = self.tmp / 'private'
        self.unit = 'reconstruction/custom/Widget.cpp'
        self.header_text = '// existing header\n#pragma once\n'
        # The claim sits after a non-comment line, where the leading-comment parser does not look.
        self.cpp_text = '#pragma once\n// 0x1000 Widget::Spin\n#include "Widget.h"\n'
        for rel, text in {'reconstruction/custom/Widget.cpp': self.cpp_text,
                          'reconstruction/custom/Widget.h': self.header_text}.items():
            (self.repo / rel).parent.mkdir(parents=True, exist_ok=True)
            (self.repo / rel).write_text(text)
        self.ctx = contrib.Ctx(repo=self.repo, env={}, private=self.private, interactive=False, as_json=True)
        tdir = self.private / 'tasks/contrib-widget'
        tdir.mkdir(parents=True)
        (tdir / 'task.json').write_text(json.dumps({
            'task_id': 'contrib-widget', 'build_id': 'b', 'compiled': self.unit, 'recipe': 'r.json',
            'functions': [], 'contrib': {'practice': False,
                                        'unit': ['reconstruction/custom/Widget.h', self.unit]}}))
        self.tdir = tdir

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def run_start(self, rva=0x1000):
        fn = {'rva': rva, 'size': 16, 'id': 'f', 'name': 'Widget::Spin', 'status': 'mapped', 'build_id': 'b'}
        args = contrib.parser().parse_args(['start', hex(rva), '--no-branch', '--drafted-by', 'tester'])
        pack = self.tmp / 'pack'
        pack.mkdir(exist_ok=True)
        patches = [
            unittest.mock.patch.object(contrib, 'inventory', return_value={'functions': [fn]}),
            unittest.mock.patch.object(contrib, 'target_manifest', return_value={'build_id': 'b'}),
            unittest.mock.patch.object(contrib, 'require_exe', return_value={'path': 'x'}),
            unittest.mock.patch.object(contrib, 'public_names', return_value={}),
            unittest.mock.patch.object(contrib, 'symbol_map_path', return_value=self.tmp / 'map.json'),
            unittest.mock.patch.object(contrib, 'write_pack', return_value=(pack, None)),
            unittest.mock.patch.object(contrib, 'refresh_symbols'),
            unittest.mock.patch.object(contrib, 'sibling_section', return_value=[]),
            unittest.mock.patch.object(contrib, 'resolve_function', return_value=fn),
        ]
        (self.tmp / 'map.json').write_text(json.dumps({'symbols': {}}))
        for p in patches:
            p.start()
            self.addCleanup(p.stop)
        return contrib.start(self.ctx, args, quiet=True)

    def test_existing_unit_is_left_alone_and_the_task_keeps_pointing_at_it(self):
        code, data, _ = self.run_start()
        self.assertEqual(code, contrib.OK)
        self.assertEqual((self.repo / self.unit).read_text(), self.cpp_text)
        self.assertNotIn('SKELETON_TODO', (self.repo / self.unit).read_text())
        task = json.loads((self.tdir / 'task.json').read_text())
        self.assertEqual(task['compiled'], self.unit)
        self.assertEqual(task['contrib']['unit'], ['reconstruction/custom/Widget.h', self.unit])
        self.assertEqual(data['unit'], ['reconstruction/custom/Widget.h', self.unit])
        self.assertEqual(data['created'], [])

    def test_a_function_the_unit_does_not_name_still_gets_its_own_header(self):
        self.run_start(rva=0x2000)
        text = (self.repo / self.unit).read_text()
        self.assertTrue(text.endswith(self.cpp_text))
        self.assertIn('// 0x2000 ', text)


class UnitIndexTests(unittest.TestCase):
    def test_index_matches_a_per_class_search(self):
        with tempfile.TemporaryDirectory() as tmp:
            for rel in ('forms/B/Dup.cpp', 'forms/A/Dup.cpp', 'ai/Solo.cpp'):
                path = Path(tmp) / 'reconstruction' / rel
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text('')
            index = contrib.unit_index(tmp)
            for cls in ('Dup', 'Solo'):
                self.assertEqual(contrib.unit_files(tmp, cls, index=index), contrib.unit_files(tmp, cls))
            self.assertEqual(contrib.unit_files(tmp, 'Dup')[0], 'forms/A')


if __name__ == '__main__':
    unittest.main()
