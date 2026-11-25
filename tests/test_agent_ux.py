"""Agent-facing recovery, attribution and progress, using synthetic inputs only."""
import contextlib
import importlib.machinery
import importlib.util
import io
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import Mock, patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools/verifier'))
import agent_advice
import agent_identity
import attempt_progress as progress
import align
import contrib
import profiles
import work_queue as queue


def load_attempt():
    loader = importlib.machinery.SourceFileLoader('ux_attempt', str(ROOT / 'tools/verifier/attempt'))
    spec = importlib.util.spec_from_loader(loader.name, loader)
    module = importlib.util.module_from_spec(spec)
    loader.exec_module(module)
    return module


class Recovery(unittest.TestCase):
    def test_specific_next_actions_are_short_and_actionable(self):
        cases = [
            ('stale header', ('re-confirm', 'confirmation-pinned maps', 'symbol_map.path')),
            ('missing symbol map or report inputs', ('confirmation-pinned map', 'record_refresh', 'source.translation_unit')),
            ('insufficient free disk space', ('Free disk space', 'retry', 'private configuration')),
        ]
        for message, expected in cases:
            with self.subTest(message=message):
                output = agent_advice.explain(message)
                for text in expected:
                    self.assertIn(text, output)
                self.assertEqual(output.count('\n'), 1)
                self.assertEqual(agent_advice.explain(output), output)

    def test_argument_errors_and_unclassified_contributor_errors_have_next_steps(self):
        output = io.StringIO()
        with contextlib.redirect_stderr(output), self.assertRaises(SystemExit):
            contrib.parser().parse_args(['claim', '--bad-flag'])
        self.assertIn('Next:', output.getvalue())
        self.assertIn('--help', output.getvalue())
        self.assertTrue(contrib.Stop(contrib.USAGE, 'unrecognised task input').next_action)
        self.assertIsNone(contrib.Stop(contrib.OK, 'no startable function found').next_action)


class Attribution(unittest.TestCase):
    def test_explicit_agent_and_profile_defaults(self):
        with self.assertRaisesRegex(ValueError, 'required before work starts'):
            agent_identity.resolve()
        self.assertEqual(agent_identity.resolve(agent='synthetic-tool'), 'synthetic-tool')
        self.assertEqual(agent_identity.resolve(profile='full'), profiles.role('full', 'drafter')['model'])
        self.assertEqual(agent_identity.resolve('actual-model', agent='worker-1', profile='cheap'), 'actual-model')

    def test_queue_records_model_at_claim_and_inherits_it_at_done(self):
        with tempfile.TemporaryDirectory() as tmp:
            qdir = Path(tmp)
            (qdir / 'queue.tsv').write_text('unit\treconstruction/misc/X.cpp\t0x1000\t4\n')
            with patch.object(queue.github_claims, 'project_claims', return_value=({}, None)):
                queue.claim(qdir, 'session-1', model='actual-model')
            claim = json.loads((qdir / 'claims/unit.lock').read_text())
            self.assertEqual(claim['model'], 'actual-model')
            with patch.object(queue.github_claims, 'project_claims', return_value=({}, None)):
                self.assertTrue(queue.claim(qdir, 'session-1')['resumed'])
            with self.assertRaisesRegex(queue.QueueError, 'differs from claim'):
                queue.finish(qdir, 'unit', ['{"rva":"0x1000","result":"fail"}'], model='another-model')
            records = queue.finish(qdir, 'unit', ['{"rva":"0x1000","result":"fail"}'])
            self.assertEqual(records[0]['model'], 'actual-model')
            self.assertEqual(queue.stats(qdir)['model']['actual-model']['functions'], 1)

    def test_contributor_claim_requires_identity_before_github_access(self):
        with tempfile.TemporaryDirectory() as tmp:
            ctx = contrib.Ctx(repo=Path(tmp), env={}, interactive=False, as_json=True)
            output = io.StringIO()
            with contextlib.redirect_stdout(output), patch.object(ctx, 'github') as github:
                code = contrib.main(['--json', 'claim', '0x1000'], ctx)
            self.assertEqual(code, contrib.USAGE)
            github.assert_not_called()
            self.assertIn('--model', json.loads(output.getvalue())['next'])
            self.assertFalse(ctx.private.exists())


class Progress(unittest.TestCase):
    @staticmethod
    def metric(n):
        return dict(metric='aligned_matching_bytes', value=n, total=20, regions=2)

    def test_new_best_resets_patience_and_oscillation_does_not(self):
        history = []
        for value, expected in [(4, 0), (4, 1), (3, 2), (4, 3), (8, 0)]:
            result = progress.update({'0x1000': self.metric(value)}, history)
            self.assertEqual(result['0x1000']['no_improvement'], expected)
            history.append(dict(progress=result))
        self.assertEqual(result['0x1000']['delta'], 4)
        self.assertIn('+4 vs previous', progress.describe('0x1000', result['0x1000'], 3))

    def test_missing_diagnostics_are_unknown_and_uncounted_runs_do_not_use_patience(self):
        first = progress.update({'0x1000': self.metric(4)}, [])
        result = progress.update({'0x1000': self.metric(4), '0x2000': None}, [dict(progress=first)], counted=False)
        self.assertEqual(result['0x1000']['no_improvement'], 0)
        self.assertIsNone(result['0x2000'])
        self.assertIn('unavailable', progress.describe('0x2000', None, 3))
        self.assertIsNone(progress.measure({}))

    def test_diagnostic_methods_do_not_compare_unlike_numbers(self):
        first = progress.update({'0x1000': self.metric(4)}, [])
        other = dict(metric='compared_code_bytes', value=2, total=20)
        result = progress.update({'0x1000': other}, [dict(progress=first)])
        self.assertIsNone(result['0x1000']['previous'])
        self.assertEqual(result['0x1000']['no_improvement'], 0)

    def test_stuck_attempt_threshold_uses_best_score_for_routing(self):
        history = []
        for value in (18, 17, 17, 17):
            result = progress.update({'0x1000': self.metric(value)}, history, now=100)
            history.append(dict(progress=result))
        metric = result['0x1000']
        self.assertIn('3 counted attempts → permute', progress.stuck_advice('0x1000', metric, 3, 100))
        self.assertIsNone(progress.stuck_advice('0x1000', metric, 4, 100))

    def test_stuck_timer_resets_on_a_new_best(self):
        rva = '0x1000'
        first = progress.update({rva: self.metric(16)}, [], now=100)
        best = progress.update({rva: self.metric(17)}, [dict(progress=first)], now=350)
        later = progress.update({rva: self.metric(17)}, [dict(progress=best)], now=500)[rva]
        self.assertIsNone(progress.stuck_advice(rva, later, 3, 649))
        self.assertIn('5 minutes → park', progress.stuck_advice(rva, later, 3, 650))
        self.assertIsNone(progress.stuck_advice(rva, None, 3, 650))

    def test_later_matching_region_rises_with_unchanged_first_mismatch(self):
        target = '1000: b8 01 00 00 00  mov eax, 1\n1005: 83 c0 02  add eax, 2\n1008: c3  ret\n'
        before = '0: b8 03 00 00 00  mov eax, 3\n5: 83 c0 04  add eax, 4\n8: c3  ret\n'
        after = '0: b8 03 00 00 00  mov eax, 3\n5: 83 c0 02  add eax, 2\n8: c3  ret\n'
        _, old = align.summarise(target, before)
        _, new = align.summarise(target, after)
        self.assertGreater(new['matching_bytes'], old['matching_bytes'])
        self.assertEqual(new['matching_bytes'], 4)
        self.assertEqual(new['matching_regions'], 1)
        self.assertFalse(new['exact'])

    def test_attempt_persists_model_progress_and_keeps_hard_cap(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as tmp:
            directory = Path(tmp).resolve() / '.local' / 'test'
            directory.mkdir(parents=True)
            (directory / 'task.json').write_text(json.dumps(dict(drafter_model='synthetic-model')))
            other = directory.with_name('other') / 'attempts/001'
            other.mkdir(parents=True)
            (other / 'attempt.txt').write_text('other task')
            (other.parents[1] / 'attempts.jsonl').write_text('{"attempt":1}\n')
            task = dict(dir=directory, task_id='synthetic', compiled='reconstruction/misc/X.cpp',
                        max_attempts=3, symbols_local=directory / 'symbols.json',
                        functions=[dict(rva=0x1000, size=20, symbol='synthetic')])
            values = iter([4, 8, 12])
            def run_once(task, host, files, tdir, dest):
                fdir = dest / '0x1000'
                fdir.mkdir(parents=True)
                (fdir / 'report.json').write_text(json.dumps(dict(result='fail', reason='code-byte-mismatch',
                                                               detail='differs at +0x0')))
                (fdir / 'align.json').write_text(json.dumps(dict(matching_bytes=next(values), matching_regions=2,
                                                               target_bytes=20, diff_signature={'encoding': {'pair': 1}})))
                return 1
            with patch.object(attempt.pipeline, 'load_task', return_value=task), \
                 patch.object(attempt.pipeline, 'lock'), patch.object(attempt.pipeline, 'unit_manifest', return_value=({}, [])), \
                 patch.object(attempt.pipeline, 'compiler_include_problem', return_value=None), \
                 patch.object(attempt.pipeline, 'load_config', return_value={}), \
                 patch('draft_worktrees.route_attempt'), patch.object(attempt, 'missing_source_message', return_value=None), \
                 patch.object(attempt.runners, 'for_attempt', return_value=dict(host_id='synthetic-host')), \
                 patch.object(attempt.runners, 'AgentHost') as host, patch.object(attempt.runners, 'describe', return_value='synthetic-host'), \
                 patch.object(attempt.disasm, 'find_objdump', return_value=None), \
                 patch.object(attempt.disasm, 'write_side_by_side', return_value=(None, None)), \
                 patch.object(attempt, 'run_once', side_effect=run_once), \
                 patch.object(attempt, 'label_warnings', return_value=[]), patch.object(attempt, 'origin_lines', return_value=[]):
                host.return_value.waited = 0
                output = io.StringIO()
                with contextlib.redirect_stdout(output):
                    self.assertEqual(attempt.attempt(directory), 1)
                    first = directory / 'attempts/001'
                    self.assertTrue((first / 'attempt.txt').read_text().startswith('attempt 1 '))
                    self.assertEqual(json.loads((first / 'diff-signature.json').read_text()),
                                     {'0x1000': {'encoding': {'pair': 1}}})
                    self.assertEqual(attempt.prune_attempts(directory, 0), (1, 0))
                    self.assertEqual(attempt.attempt(directory), 1)
                    self.assertEqual(attempt.attempt(directory, max_attempt_bytes=0), 1)
                    self.assertEqual(attempt.attempt(directory), 5)
                self.assertIn('+4 vs previous', output.getvalue())
                self.assertIn('Next: revise the source', output.getvalue())
                self.assertIn('stop after 3 counted attempts or 5 minutes without a new best', output.getvalue())
                self.assertIn('attempt budget exhausted: 3 of 3', output.getvalue())
            rows = [json.loads(line) for line in (directory / 'attempts.jsonl').read_text().splitlines()]
            self.assertEqual(rows[-1]['model'], 'synthetic-model')
            self.assertEqual(rows[-1]['progress']['0x1000']['best'], 12)
            self.assertEqual([row['attempt'] for row in rows], [1, 2, 3])
            self.assertFalse(first.exists())
            self.assertFalse((directory / 'attempts/002').exists())
            self.assertTrue((directory / 'attempts/003/attempt.txt').is_file())
            self.assertTrue(other.is_dir())
            self.assertEqual(json.loads((directory / 'task.json').read_text()), dict(drafter_model='synthetic-model'))

    def test_runner_compiles_the_sources_saved_with_its_result(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as raw:
            repo = Path(raw).resolve()
            unit = repo / 'reconstruction/area'
            unit.mkdir(parents=True)
            cpp = unit / 'Thing_1.cpp'
            cpp.write_bytes(b'cpp v1\r\n')
            (unit / 'Thing_1.h').write_text('paired header')
            (unit / 'Local.h').write_text('local')
            shared = repo / 'reconstruction/Shared.h'
            shared.write_text('shared')
            files = {p.relative_to(repo).as_posix(): p for p in (cpp, unit / 'Local.h', shared)}
            task = dict(compiled='reconstruction/area/Thing_1.cpp', functions=[dict(rva=1), dict(rva=2)])
            directory = repo / '.local/test'
            (directory / '.attempt').mkdir(parents=True)
            dest = directory / 'attempts/001'

            def run(staged, _stage):
                cpp.write_text('cpp v2')
                self.assertEqual(staged[task['compiled']].read_bytes(), b'cpp v1\r\n')
                self.assertEqual(staged['reconstruction/Shared.h'], shared)
                return 0, ''

            def fetch(out):
                (out / '0x1').mkdir(parents=True)
                (out / '0x1/report.json').write_text('{"result": "pass"}')

            host = Mock()
            host.run.side_effect = run
            host.fetch.side_effect = fetch
            self.assertEqual(attempt.run_once(task, host, files, directory, dest), 0)
            self.assertEqual(sorted(p.name for p in (dest / 'src').iterdir()), ['Local.h', 'Thing_1.cpp', 'Thing_1.h'])
            self.assertEqual((dest / 'src/Thing_1.cpp').read_bytes(), b'cpp v1\r\n')
            self.assertEqual(list((directory / '.attempt').iterdir()), [])
            attempt.write_diff_signature(task, dest)
            self.assertEqual(json.loads((dest / 'diff-signature.json').read_text()), {'0x1': {}, '0x2': None})

    def test_prune_oldest_completed_results_across_tasks(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw).resolve() / '.local'
            oldest, newest, active = [root / task / 'attempts/001' for task in ('group/a', 'b', 'c')]
            for timestamp, run in enumerate((oldest, newest, active), 1):
                run.mkdir(parents=True)
                summary = run / 'attempt.txt'
                summary.write_text('x')
                os.utime(summary, (timestamp, timestamp))
                (run.parents[1] / 'attempts.jsonl').write_text('{"attempt":1}\n')
            incomplete = newest.parent / '002'
            incomplete.mkdir()
            (incomplete / 'candidate.obj').write_text('output')
            with attempt.pipeline.lock(active.parents[1]):
                self.assertEqual(attempt.prune_attempts(root, 2), (1, 2))
                self.assertEqual(attempt.prune_attempts(root, 0), (1, 1))
                self.assertTrue(active.is_dir())
            self.assertEqual(attempt.prune_attempts(root, 0), (1, 0))
            self.assertTrue(incomplete.is_dir())
            self.assertTrue((oldest.parents[1] / 'attempts.jsonl').is_file())

    def test_attempt_refuses_missing_identity_before_using_a_runner(self):
        attempt = load_attempt()
        with tempfile.TemporaryDirectory() as tmp:
            directory = Path(tmp)
            (directory / 'task.json').write_text('{}')
            with patch.object(attempt.pipeline, 'load_task', return_value=dict(dir=directory, max_attempts=3)), \
                 patch.object(attempt, 'missing_source_message', return_value=None), \
                 patch('draft_worktrees.route_attempt'), patch.object(attempt.pipeline, 'lock'), \
                 patch.object(attempt.runners, 'for_attempt') as runner:
                with self.assertRaisesRegex(ValueError, 'required before work starts'):
                    attempt.attempt(directory)
                runner.assert_not_called()


if __name__ == '__main__':
    unittest.main()
