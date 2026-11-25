"""The accept_also registry, its alternative recipe files, the exception-frame condition and the retries."""
import importlib.util
from importlib.machinery import SourceFileLoader
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import recipe_alternatives as alts  # noqa: E402
from source_digest import recipe_flag_problem  # noqa: E402


def load_attempt():
    loader = SourceFileLoader('attempt_script', str(ROOT / 'tools' / 'verifier' / 'attempt'))
    spec = importlib.util.spec_from_loader('attempt_script', loader)
    module = importlib.util.module_from_spec(spec)
    loader.exec_module(module)
    return module


class FakeImage:
    """runtime_functions() and read() for an image whose unwind infos are given as {rva: flags}."""

    def __init__(self, entries, unwind_flags):
        self._entries, self._flags = entries, unwind_flags

    def runtime_functions(self):
        return list(self._entries)

    def read(self, rva, size, what):
        return None, bytes([(self._flags[rva] << 3) | 1])


class Registry(unittest.TestCase):
    def test_registry_matches_the_recipe_files(self):
        self.assertEqual(alts.problems(ROOT), [])

    def test_every_alternative_is_the_base_without_the_declared_flag(self):
        registry = alts.load(ROOT)['alternatives']
        self.assertTrue(registry)
        for base_path, entry in registry.items():
            base = json.loads((ROOT / base_path).read_text())
            for alt in entry['accept_also']:
                with self.subTest(alt=alt['recipe']):
                    recipe = json.loads((ROOT / alt['recipe']).read_text())
                    self.assertIn('/EHsc', base['flags'])
                    self.assertNotIn('/EHsc', recipe['flags'])
                    self.assertEqual([f for f in base['flags'] if f != '/EHsc'], recipe['flags'])
                    self.assertEqual(recipe_flag_problem(recipe['flags']), None)
                    self.assertEqual((recipe['compiler'], recipe['sdk']), (base['compiler'], base['sdk']))

    def test_alternatives_are_approved_for_the_ci_hash_job(self):
        manifest = json.loads((ROOT / 'data/target-hashes/sse-steam-1-7-104.json').read_text())
        for entry in alts.load(ROOT)['alternatives'].values():
            for alt in entry['accept_also']:
                self.assertIn(alt['recipe'], manifest['recipe_sha256'])

    def test_a_unit_naming_an_alternative_is_compiled_with_it_by_the_hash_job_and_the_local_compare(self):
        import ci_target_hash_check as ci
        import contrib
        line = '// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json\n'
        self.assertEqual(ci.unit_recipe(line), 'reconstruction/recipes/msvc-19.16.27054-o2-noeh.json')
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction/recipes').mkdir(parents=True)
            (root / 'reconstruction/recipes/msvc-19.16.27054-o2-noeh.json').write_text('{}')
            (root / 'u.cpp').write_text(line)
            self.assertEqual(contrib.unit_recipe(root, 'u.cpp', 'reconstruction/recipes/msvc-19.16.27054-o2.json'),
                             'reconstruction/recipes/msvc-19.16.27054-o2-noeh.json')

    def test_alternatives_lookup_is_per_base_recipe_and_ordered(self):
        got = alts.alternatives(ROOT, 'reconstruction/recipes/msvc-19.16.27054-o2.json')
        self.assertEqual([a['id'] for a in got], ['noeh'])
        self.assertEqual(got[0]['recipe'], 'reconstruction/recipes/msvc-19.16.27054-o2-noeh.json')
        self.assertEqual(alts.alternatives(ROOT, 'reconstruction/recipes/msvc-19.15.26731-o2.json'), [])

    def test_a_registry_that_drifts_from_its_recipe_file_is_reported(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction/recipes').mkdir(parents=True)
            (root / 'data').mkdir()
            base = dict(compiler={'a': 1}, sdk='x', flags=['/c', '/EHsc', '/O2'])
            (root / 'reconstruction/recipes/b.json').write_text(json.dumps(base))
            (root / 'reconstruction/recipes/b-noeh.json').write_text(json.dumps(dict(base, flags=['/c', '/O2', '/GR'])))
            row = dict(id='noeh', recipe='reconstruction/recipes/b-noeh.json', remove=['/EHsc'], add=[],
                       requires='target-no-eh-frame')
            (root / alts.REGISTRY).write_text(json.dumps(
                dict(schema=1, alternatives={'reconstruction/recipes/b.json': dict(accept_also=[row])})))
            found = alts.problems(root)
            self.assertEqual(len(found), 1)
            self.assertIn('exactly the declared flag change', found[0])

    def test_match_line_names_the_flags_and_the_recipe_line_to_add(self):
        alt = alts.alternatives(ROOT, 'reconstruction/recipes/msvc-19.16.27054-o2.json')[0]
        line = alts.match_line(ROOT, alt)
        self.assertTrue(line.startswith('MATCH (under /nologo /c /O2 /MD /GS- /GR /fp:precise /Gy;'))
        self.assertIn('without /EHsc', line)
        self.assertIn('Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json', line)
        self.assertIn('Advisory', line)


class EhFrames(unittest.TestCase):
    def frames(self):
        entries = [(0x1000, 0x1100, 0x9000), (0x1100, 0x1200, 0x9010), (0x1200, 0x1300, 0x9020), (0x2000, 0x2100, 0x9030)]
        flags = {0x9000: 0, 0x9010: 1, 0x9020: 4, 0x9030: 2}  # none, EHANDLER, CHAININFO, UHANDLER
        return alts.EhFrames(FakeImage(entries, flags))

    def test_a_function_with_a_handler_has_a_frame(self):
        self.assertTrue(self.frames().has_handler(0x1100, 0x100))
        self.assertTrue(self.frames().has_handler(0x2000, 0x100))

    def test_a_function_without_a_handler_has_none(self):
        self.assertFalse(self.frames().has_handler(0x1000, 0x100))
        self.assertFalse(self.frames().has_handler(0x1200, 0x100))

    def test_a_funclet_inside_the_function_counts(self):
        self.assertTrue(self.frames().has_handler(0x1000, 0x200))

    def test_applies_follows_the_condition_and_runs_when_it_cannot_be_judged(self):
        alt = alts.alternatives(ROOT, 'reconstruction/recipes/msvc-19.16.27054-o2.json')[0]
        frames = self.frames()
        self.assertTrue(alts.applies(alt, frames, 0x1000, 0x100))
        self.assertFalse(alts.applies(alt, frames, 0x1100, 0x100))
        self.assertTrue(alts.applies(alt, None, 0x1100, 0x100))
        self.assertTrue(alts.applies(alt, frames, 0x1100, 0x100, force=True))


class ContribRetry(unittest.TestCase):
    def run_retry(self, results, passing, frames_by_rva):
        import contrib
        task = dict(compiled='u.cpp', functions=[dict(rva=r['rva'], size=r['target_size'], symbol='s' + r['rva'])
                                                 for r in results])
        compiled = []

        def compile_unit(ctx, root, compiled_name, recipe, out, tool):
            compiled.append(recipe)
            return dict(recipe_sha256='h' * 64)

        def compare(ctx, root, tdir, t, fn, built, recipe, exe, target, fdir):
            return dict(result='pass' if passing.get(fn['rva']) else 'fail')

        class Frames:
            def has_handler(self, rva, size):
                return frames_by_rva[f'0x{rva:x}']

        with tempfile.TemporaryDirectory() as tmp, \
                mock.patch.object(contrib, 'compile_unit', compile_unit), \
                mock.patch.object(contrib, 'compare_function', compare), \
                mock.patch.object(alts.EhFrames, 'from_bytes', classmethod(lambda cls, blob: Frames())), \
                mock.patch.object(Path, 'read_bytes', lambda self: b''):
            notes = contrib.retry_under_alternatives(
                None, ROOT, Path(tmp), task, 'reconstruction/recipes/msvc-19.16.27054-o2.json', results,
                '/image', {}, {}, Path(tmp))
        return notes, compiled

    def result(self, rva, reason='code-byte-mismatch', result='fail'):
        return dict(rva=rva, result=result, reason=reason, target_size=100)

    def test_a_failed_function_without_a_frame_is_retried_and_reported_as_a_match_under_the_flags(self):
        results = [self.result('0x1000')]
        notes, compiled = self.run_retry(results, {'0x1000': True}, {'0x1000': False})
        self.assertEqual(compiled, ['reconstruction/recipes/msvc-19.16.27054-o2-noeh.json'])
        self.assertEqual(results[0]['result'], 'fail')  # the verdict under the unit's own recipe stays
        self.assertEqual(results[0]['also_matches']['recipe'], 'reconstruction/recipes/msvc-19.16.27054-o2-noeh.json')
        self.assertEqual(results[0]['also_matches']['change'], 'without /EHsc')
        self.assertIn('0x1000: MATCH (under /nologo', notes[0])

    def test_a_function_with_a_frame_costs_no_compile(self):
        results = [self.result('0x1000')]
        notes, compiled = self.run_retry(results, {'0x1000': True}, {'0x1000': True})
        self.assertEqual((notes, compiled), ([], []))
        self.assertNotIn('also_matches', results[0])

    def test_unbound_and_passing_functions_are_not_retried(self):
        results = [self.result('0x1000', reason='function-symbol-missing'), self.result('0x2000', result='pass')]
        notes, compiled = self.run_retry(results, {}, {'0x1000': False, '0x2000': False})
        self.assertEqual((notes, compiled), ([], []))

    def test_no_match_under_the_alternative_changes_nothing(self):
        results = [self.result('0x1000')]
        notes, compiled = self.run_retry(results, {'0x1000': False}, {'0x1000': False})
        self.assertEqual((notes, len(compiled)), ([], 1))
        self.assertNotIn('also_matches', results[0])

    def test_a_unit_that_would_lose_a_passing_function_says_so(self):
        results = [self.result('0x1000'), self.result('0x2000', result='pass', reason='all-checks-passed')]
        notes, _ = self.run_retry(results, {'0x1000': True, '0x2000': False}, {'0x1000': False, '0x2000': False})
        self.assertIn('0x2000 would not pass', notes[0])
        self.assertFalse(results[0]['also_matches']['unit_passes_all'])


class AttemptRetry(unittest.TestCase):
    def test_the_attempt_tool_retries_only_failed_functions_without_a_frame(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as tmp:
            dest = Path(tmp) / 'attempt'
            task = dict(recipe='reconstruction/recipes/msvc-19.16.27054-o2.json', task_id='t', compiled='u.cpp',
                        symbols_local=Path(tmp) / 'symbols.json',
                        functions=[dict(rva=0x1000, size=100, symbol='a'), dict(rva=0x2000, size=100, symbol='b'),
                                   dict(rva=0x3000, size=100, symbol='c')])
            for fn, result, reason in ((0x1000, 'fail', 'code-byte-mismatch'), (0x2000, 'fail', 'code-byte-mismatch'),
                                       (0x3000, 'pass', 'all-checks-passed')):
                (dest / f'0x{fn:x}').mkdir(parents=True)
                (dest / f'0x{fn:x}' / 'report.json').write_text(json.dumps(dict(result=result, reason=reason)))

            class Frames:
                def has_handler(self, rva, size):
                    return rva == 0x2000

            runs = []

            def run_once(alt_task, host, files, task_dir, adest):
                runs.append(alt_task['recipe'])
                for fn, ok in ((0x1000, True), (0x2000, False), (0x3000, True)):
                    (adest / f'0x{fn:x}').mkdir(parents=True)
                    (adest / f'0x{fn:x}' / 'report.json').write_text(json.dumps(dict(result='pass' if ok else 'fail')))
                return 1

            class Host:
                task = None

            image = Path(tmp) / 'image.exe'
            image.write_bytes(b'')
            with mock.patch.object(attempt, 'run_once', run_once), \
                    mock.patch.object(attempt.pipeline, 'unit_manifest', lambda t: ({}, [])), \
                    mock.patch.object(alts.EhFrames, 'from_bytes', classmethod(lambda cls, blob: Frames())):
                lines = attempt.retry_alternatives(task, Host(), Path(tmp), dest, image)
        self.assertEqual(runs, ['reconstruction/recipes/msvc-19.16.27054-o2-noeh.json'])
        self.assertTrue(any('0x1000: MATCH (under /nologo' in line for line in lines), lines)
        self.assertFalse(any('0x2000: MATCH' in line for line in lines))
        self.assertTrue(any('on 1 function(s): 1 match' in line for line in lines))

    def test_nothing_is_retried_when_every_function_passes(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as tmp:
            dest = Path(tmp)
            (dest / '0x1000').mkdir()
            (dest / '0x1000' / 'report.json').write_text(json.dumps(dict(result='pass')))
            task = dict(recipe='reconstruction/recipes/msvc-19.16.27054-o2.json', functions=[dict(rva=0x1000, size=1)])
            self.assertEqual(attempt.retry_alternatives(task, object(), dest, dest, None), [])


if __name__ == '__main__':
    unittest.main()
