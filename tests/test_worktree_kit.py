"""tools/worktree_kit.py adds missing private inputs to a worktree and never replaces anything."""
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import worktree_kit as kit


class WorktreeKit(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        base = Path(self.tmp.name).resolve()
        self.main = base / 'main/.local'
        self.tree = base / 'tree'
        for rel in ('sources/clone', 'x64', 'analysis/origin-index', 'contrib/x64-index', 'f3x64'):
            (self.main / rel).mkdir(parents=True)
        for rel in ('analysis/functions.jsonl', 'analysis/fnv_index.jsonl', 'analysis/fnv_index.meta.json',
                    'verifier/runners.json'):
            (self.main / rel).parent.mkdir(parents=True, exist_ok=True)
            (self.main / rel).write_text('{}')
        (self.main / 'verifier/config.json').write_text(json.dumps({'image': '/games/target.exe'}))
        (self.tree / 'reconstruction').mkdir(parents=True)
        (self.tree / 'reconstruction/Unit.cpp').write_text('// unit\n')
        self.env = patch_env({'SR_SKYRIM_EXE': None})
        self.env.__enter__()

    def tearDown(self):
        self.env.__exit__(None, None, None)
        self.tmp.cleanup()

    def names(self, done):
        return {rel for _kind, rel, _detail in done}

    def test_fresh_worktree_gets_links_and_is_idempotent(self):
        done = kit.apply(self.tree, self.main)
        added = self.names(done)
        self.assertIn('sources', added)
        self.assertIn('analysis/functions.jsonl', added)
        self.assertIn('contrib/x64-index', added)
        self.assertIn('contrib/analysis/fnv_index.jsonl', added)
        self.assertTrue((self.tree / '.local/sources').is_symlink())
        self.assertEqual((self.tree / '.local/sources/clone').is_dir(), True)
        self.assertEqual((self.tree / '.local/contrib/analysis/fnv_index.jsonl').resolve(),
                         (self.main / 'analysis/fnv_index.jsonl').resolve())
        cfg = json.loads((self.tree / '.local/contrib/config.json').read_text())
        self.assertEqual(cfg, {'exe': '/games/target.exe'})
        self.assertEqual(json.loads((self.tree / '.local/verifier/config.json').read_text())['image'],
                         '/games/target.exe')
        self.assertEqual(kit.apply(self.tree, self.main), [])

    def test_only_local_is_written_and_missing_inputs_are_reported(self):
        before = sorted(p.relative_to(self.tree).as_posix() for p in self.tree.rglob('*'))
        kit.apply(self.tree, self.main)
        after = sorted(p.relative_to(self.tree).as_posix() for p in self.tree.rglob('*')
                       if not p.relative_to(self.tree).as_posix().startswith('.local'))
        self.assertEqual(before, after)
        self.assertEqual((self.tree / 'reconstruction/Unit.cpp').read_text(), '// unit\n')
        self.assertFalse((self.tree / '.local/msvclib').exists())
        self.assertIn(('missing', 'msvclib'), {(k, r) for k, r, _d in kit.plan(self.tree, self.main)})

    def test_existing_entries_are_kept(self):
        local = self.tree / '.local'
        (local / 'analysis/origin-index').mkdir(parents=True)
        (local / 'analysis/origin-index/own.json').write_text('own')
        (local / 'analysis/functions.jsonl').write_text('own table')
        (local / 'contrib').mkdir(exist_ok=True)
        (local / 'contrib/config.json').write_text(json.dumps({'model': 'm'}))
        (local / 'verifier').mkdir()
        (local / 'verifier/runners.json').write_text('own runners')
        done = kit.apply(self.tree, self.main)
        self.assertNotIn('analysis/functions.jsonl', self.names(done))
        self.assertEqual((local / 'analysis/origin-index/own.json').read_text(), 'own')
        self.assertEqual((local / 'analysis/functions.jsonl').read_text(), 'own table')
        self.assertEqual((local / 'verifier/runners.json').read_text(), 'own runners')
        self.assertEqual(json.loads((local / 'contrib/config.json').read_text()), {'model': 'm'})
        notes = [d for k, _r, d in kit.plan(self.tree, self.main) if k == 'note']
        self.assertEqual(len(notes), 1)
        self.assertIn('SR_SKYRIM_EXE', notes[0])

    def test_symlinked_directory_is_never_written_through(self):
        local = self.tree / '.local'
        local.mkdir()
        (local / 'contrib').symlink_to(self.main / 'contrib', target_is_directory=True)
        before = sorted(p.name for p in (self.main / 'contrib').iterdir())
        kit.apply(self.tree, self.main)
        self.assertEqual(sorted(p.name for p in (self.main / 'contrib').iterdir()), before)

    def test_check_mode_changes_nothing(self):
        with contextlib.redirect_stdout(io.StringIO()) as out:
            rc = kit.main([str(self.tree), '--main', str(self.main), '--check'])
        self.assertIn('would link', out.getvalue())
        self.assertEqual(rc, 0)
        self.assertFalse((self.tree / '.local').exists())

    def test_main_checkout_itself_gets_nothing(self):
        self.assertEqual(kit.plan(self.main.parent, self.main), [])


class patch_env:
    def __init__(self, values):
        self.values, self.saved = values, {}

    def __enter__(self):
        import os
        for key, value in self.values.items():
            self.saved[key] = os.environ.get(key)
            if value is None:
                os.environ.pop(key, None)
            else:
                os.environ[key] = value

    def __exit__(self, *exc):
        import os
        for key, value in self.saved.items():
            if value is None:
                os.environ.pop(key, None)
            else:
                os.environ[key] = value


if __name__ == '__main__':
    unittest.main()
