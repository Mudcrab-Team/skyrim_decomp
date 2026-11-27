"""Exercise the private pool with original toy tasks and translation units."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from collect_near_misses import collect


class NearMissPoolTests(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.repo = Path(temp.name) / 'repo'
        self.tree = Path(temp.name) / 'worktree'
        self.task = self.tree / '.local/contrib/tasks/toy'
        self.task.mkdir(parents=True)
        (self.tree / '.git').touch()
        self.compiled = Path('reconstruction/toy/Toy.cpp')
        raw = dict(task_id='toy', build_id='toy-build', compiled=self.compiled.as_posix(),
                   symbols='symbols.json', functions=[
                       {'rva': '0x100', 'symbol': 'ToyF', 'size': 5},
                       {'rva': '0x200', 'symbol': 'ToyG', 'size': 5}])
        (self.task / 'task.json').write_text(json.dumps(raw))
        (self.task / 'symbols.json').write_text('{"symbols": {}}')
        header = self.tree / 'reconstruction/support.h'
        header.parent.mkdir()
        header.write_text('int Value();\n')
        self.snapshot = self.task / 'near-miss'
        self.snapshot.mkdir()
        for name in ('100', '200'):
            (self.snapshot / f'{name}.cpp').write_text('#include "Toy.h"\nvoid F() { Value(); }\n')
            (self.snapshot / f'{name}.h').write_text('#include "support.h"\n')
        self.pool = self.repo / '.local/near-miss'

    def test_collects_only_active_rvas_and_copies_the_source_closure(self):
        active, skipped, errors = collect(self.repo, [self.tree], {('toy-build', 0x200), ('other-build', 0x100)})
        self.assertEqual((active, skipped, errors), (['toy-build/0x100'], {('toy-build', 0x200)}, []))
        self.assertFalse((self.pool / 'toy-build/0x200').exists())
        task = self.pool / active[0]
        self.assertEqual((task / 'source-root' / self.compiled).read_bytes(), (self.snapshot / '100.cpp').read_bytes())
        self.assertEqual((task / 'source-root/reconstruction/support.h').read_text(), 'int Value();\n')
        self.assertEqual([f['rva'] for f in json.loads((task / 'task.json').read_text())['functions']], ['0x100'])
        self.assertEqual(collect(self.repo, [self.tree], {('toy-build', 0x100), ('toy-build', 0x200)})[0], [])
        self.assertEqual(json.loads((self.pool / 'pool.json').read_text()), [])
        self.assertTrue((self.snapshot / '100.cpp').is_file())

    def test_handoff_finds_an_explicitly_listed_thinned_draft(self):
        (self.snapshot / '100.cpp').unlink()
        (self.snapshot / '200.cpp').unlink()
        attempt = self.task / 'attempts/002/src'
        attempt.mkdir(parents=True)
        (attempt / 'Toy.cpp').write_text('void F() {}\n')
        handoff = self.tree / '.local/handoffs/toy.md'
        handoff.parent.mkdir()
        handoff.write_text('## Near misses\n\n- 0x100 near-miss. Private task `.local/contrib/tasks/toy/`.\n')
        active, skipped, errors = collect(self.repo, [handoff], set())
        self.assertEqual((active, skipped, errors), (['toy-build/0x100'], set(), []))
        self.assertEqual((self.pool / active[0] / 'source-root' / self.compiled).read_text(), 'void F() {}\n')

    def test_public_source_uses_the_matching_local_task(self):
        public = self.repo / 'drafts/toy-build/100.cpp'
        public.parent.mkdir(parents=True)
        source = '#include "Toy.h"\nint ToyF() { return Value; }\n'
        public.write_text('// Near miss: 97% | register-schedule\n'
                          + source.replace('"Toy.h"', '"include/100/Original.h"'))
        header = public.parent / 'include/100/Original.h'
        header.parent.mkdir(parents=True)
        header.write_text('constexpr int Value = 5;\n')
        match = ('toy-build', 0x200)
        active, skipped, errors = collect(self.repo, [public, self.tree], {match})
        self.assertEqual((active, skipped, errors), (['toy-build/0x100'], {match}, []))
        self.assertEqual((self.pool / active[0] / 'source-root' / self.compiled).read_text(), source)
        self.assertEqual((self.pool / active[0] / 'source-root' / self.compiled.with_suffix('.h')).read_bytes(),
                         header.read_bytes())

    def test_handoff_finds_a_staged_pool_with_no_original_snapshots(self):
        (self.snapshot / '100.cpp').unlink()
        (self.snapshot / '200.cpp').unlink()
        staged = self.tree / '.local/staged'
        source = staged / 'root' / self.compiled
        source.parent.mkdir(parents=True)
        source.write_text('void F() {}\n')
        rows = [{'stage': str(self.task), 'compiled_rel': self.compiled.as_posix(), 'rva': '0x100'}]
        (staged / 'staged.json').write_text(json.dumps(rows))
        handoff = self.tree / '.local/handoff.md'
        handoff.write_text(f'Private staged drafts are in `{staged}/`.\n')
        active, skipped, errors = collect(self.repo, [handoff], set())
        self.assertEqual((active, skipped, errors), (['toy-build/0x100'], set(), []))
        self.assertEqual((self.pool / active[0] / 'source-root' / self.compiled).read_text(), 'void F() {}\n')
