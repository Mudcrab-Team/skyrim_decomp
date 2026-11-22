"""Deleting a reconstruction unit: allowed unless it would orphan an accepted function's record."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tests'))
import ci_target_hash_check as ci
import pr_bot
import unit_deletion

DIR = 'reconstruction/skyrim_shared/forms'
OLD, NEW = f'{DIR}/Old_1.cpp', f'{DIR}/New_1.cpp'
# Header line form the rva_headers claim parser reads.
HEADER = '// RVA 0x{rva:x}, 7 bytes\n'


def functions(accepted):
    return [dict(rva=r, status='matched', report=f'reports/{r:x}.json', name='A::f') for r in accepted]


def make_tree(root, bound):
    """{rva: compiled unit} records, one OLD unit declaring 0x100 and 0x200, plus a NEW unit."""
    for sub in ('data', 'reports', DIR):
        (root / sub).mkdir(parents=True, exist_ok=True)
    for r, compiled in bound.items():
        (root / f'reports/{r:x}.json').write_text(json.dumps({'source': {'compiled': compiled}}))
    (root / 'data/progress.json').write_text(json.dumps({'functions': functions(bound)}))
    (root / OLD).write_text(HEADER.format(rva=0x100) + 'void f();\n' + HEADER.format(rva=0x200) + 'void g();\n')
    (root / OLD.replace('.cpp', '.h')).write_text(HEADER.format(rva=0x100))
    (root / NEW).write_text(HEADER.format(rva=0x100) + 'void f();\n')


class ProblemsTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)

    def check(self, bound, deleted=(OLD, OLD.replace('.cpp', '.h')), keep_new=True):
        shutil.rmtree(self.root)
        self.root.mkdir()
        make_tree(self.root, bound)
        base = {n: (self.root / n).read_text() for n in (OLD, OLD.replace('.cpp', '.h'))}
        for n in deleted:
            (self.root / n).unlink()
        if not keep_new:
            (self.root / NEW).unlink()
        return unit_deletion.problems(self.root, deleted, base.get, lambda n: (self.root / n).is_file())

    def test_functions_bound_to_another_existing_unit_or_unaccepted_may_go(self):
        self.assertEqual(self.check({0x100: NEW}), [])  # 0x200 is not accepted at all
        self.assertEqual(self.check({}), [])

    def test_a_record_binding_the_deleted_unit_is_refused_with_the_function_named(self):
        found = self.check({0x100: NEW, 0x200: OLD})
        self.assertEqual(len(found), 1)
        self.assertIn('0x200', found[0])
        self.assertIn('orphan', found[0])

    def test_a_function_bound_to_a_unit_that_is_gone_is_refused(self):
        found = self.check({0x100: NEW}, keep_new=False)
        self.assertEqual(len(found), 1)
        self.assertIn('does not exist', found[0])

    def test_no_deletion_is_no_problem(self):
        make_tree(self.root, {0x100: OLD})
        self.assertEqual(unit_deletion.problems(self.root, [], lambda n: None, lambda n: True), [])


class PrepareTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name) / 'repo'
        self.root.mkdir()
        (self.root / 'builds').mkdir()
        (self.root / 'builds/target.json').write_text(json.dumps({'build_id': 'x'}))

    def git(self, *args):
        return subprocess.run(['git', '-C', str(self.root), '-c', 'user.name=t', '-c', 'user.email=t@t', *args],
                              check=True, capture_output=True).stdout.decode().strip()

    def prepare(self, bound):
        make_tree(self.root, bound)
        self.git('init', '-q', '-b', 'main')
        self.git('add', '-A')
        self.git('commit', '-qm', 'base')
        base = self.git('rev-parse', 'HEAD')
        self.git('checkout', '-q', '-b', 'pr')
        self.git('rm', '-q', OLD, OLD.replace('.cpp', '.h'))
        self.git('commit', '-qm', 'delete')
        head = self.git('rev-parse', 'HEAD')
        self.git('checkout', '-q', base)
        return ci.prepare(self.root, base, head, Path(self.tmp.name) / 'work')

    def test_a_safe_deletion_prepares_nothing_to_compile(self):
        tree, changed = self.prepare({0x100: NEW})
        self.assertEqual(changed, [])

    def test_a_deletion_that_orphans_a_record_is_refused_with_a_clear_message(self):
        with self.assertRaises(ValueError) as caught:
            self.prepare({0x100: NEW, 0x200: OLD})
        self.assertIn('would orphan an accepted function', str(caught.exception))
        self.assertIn('0x200', str(caught.exception))


class DeletionLaneTests(unittest.TestCase):
    def test_lane_is_only_removed_unit_files(self):
        gone = [{'filename': OLD, 'status': 'removed'}, {'filename': OLD.replace('.cpp', '.h'), 'status': 'removed'}]
        self.assertTrue(pr_bot.deletion_lane(gone))
        self.assertFalse(pr_bot.deletion_lane([]))
        self.assertFalse(pr_bot.deletion_lane(gone + [{'filename': NEW, 'status': 'modified'}]))
        self.assertFalse(pr_bot.deletion_lane(gone + [{'filename': 'reconstruction/INDEX.md', 'status': 'removed'}]))
        self.assertFalse(pr_bot.deletion_lane([{'filename': OLD, 'status': 'renamed', 'previous_filename': NEW}]))


if __name__ == '__main__':
    unittest.main()
