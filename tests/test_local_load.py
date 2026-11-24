"""Tests for tools/local_load.py and its use by runners and check: toy workloads only, no compiler or game input."""
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import time
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
sys.path.insert(0, str(ROOT / 'tools'))
import local_load  # noqa: E402
import runners  # noqa: E402
import check  # noqa: E402

# A toy heavy job: hold a slot, record when it ran, sleep. Run as a separate process so the slots
# are contended the way separate workers contend for them.
JOB = '''
import sys, time
sys.path.insert(0, sys.argv[1])
import local_load
with local_load.heavy('toy job') as granted:
    start = time.time()
    time.sleep(float(sys.argv[3]))
    with open(sys.argv[2], 'a') as out:
        out.write(f"{start} {time.time()}\\n")
'''


def runner_config(**extra):
    host = {'backend': 'local', 'host_id': 'mac-wine', 'machine': 'one', 'loader': 'native',
            'msvc': '/m', 'work': '/w', 'max_parallel': 4}
    ssh = {'backend': 'ssh', 'host_id': 'pc-native', 'machine': 'two', 'loader': 'native', 'msvc': 'C:/m',
           'work': 'C:/w', 'image': 'C:/i.exe', 'ssh_host': 'pc', 'ssh_config': '/c'}
    return dict({'runners_schema': 1, 'attempt': 'mac', 'confirm': [], 'hosts': {'mac': host, 'pc': ssh}}, **extra)


class Limit(unittest.TestCase):
    def test_parse(self):
        self.assertIsNone(local_load.parse(None))
        self.assertEqual(local_load.parse(2), 2)
        for bad in (0, -1, 65, True, 1.5, '2'):
            with self.subTest(bad=bad), self.assertRaises(ValueError):
                local_load.parse(bad)

    def test_environment_beats_the_file_and_can_lift_the_cap(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'runners.json'
            path.write_text(json.dumps({local_load.KEY: 3}))
            env = {'SR_RUNNERS_CONFIG': str(path)}
            self.assertEqual(local_load.limit(env), 3)
            self.assertEqual(local_load.limit(dict(env, SR_LOCAL_MAX_HEAVY='1')), 1)
            for off in ('0', 'off', 'unlimited', ''):
                self.assertIsNone(local_load.limit(dict(env, SR_LOCAL_MAX_HEAVY=off)))

    def test_no_file_or_no_key_means_no_cap(self):
        with tempfile.TemporaryDirectory() as tmp:
            self.assertIsNone(local_load.limit({'SR_RUNNERS_CONFIG': str(Path(tmp) / 'absent.json')}))
            path = Path(tmp) / 'runners.json'
            path.write_text(json.dumps({'runners_schema': 1}))
            self.assertIsNone(local_load.limit({'SR_RUNNERS_CONFIG': str(path)}))

    def test_a_malformed_setting_warns_and_applies_no_cap(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'runners.json'
            path.write_text(json.dumps({local_load.KEY: 'two'}))
            with mock.patch('sys.stderr', new=io.StringIO()) as err:
                self.assertIsNone(local_load.limit({'SR_RUNNERS_CONFIG': str(path)}))
                self.assertIsNone(local_load.limit({'SR_LOCAL_MAX_HEAVY': 'many'}))
            self.assertEqual(err.getvalue().count('no cap applied'), 2)


class Heavy(unittest.TestCase):
    def test_without_a_cap_nothing_is_locked(self):
        with tempfile.TemporaryDirectory() as tmp:
            with local_load.heavy('x', want=5, cap=None, directory=Path(tmp) / 'slots') as granted:
                self.assertEqual(granted, 5)
            self.assertFalse((Path(tmp) / 'slots').exists())

    def test_threads_never_exceed_the_cap_and_one_line_per_wait(self):
        with tempfile.TemporaryDirectory() as tmp:
            running, peak, lines, lock = [0], [0], [], threading.Lock()

            def job(i):
                with local_load.heavy(f'job {i}', cap=2, directory=tmp, poll=0.01, log=lines.append):
                    with lock:
                        running[0] += 1
                        peak[0] = max(peak[0], running[0])
                    time.sleep(0.1)
                    with lock:
                        running[0] -= 1
            threads = [threading.Thread(target=job, args=(i,)) for i in range(6)]
            for t in threads:
                t.start()
            for t in threads:
                t.join(30)
            self.assertEqual(peak[0], 2)
            self.assertEqual(local_load.busy(2, tmp), 0)
            self.assertEqual(len(lines), 4)
            self.assertTrue(all(line.startswith('local load guard: job ') and 'waits for a free slot' in line
                                for line in lines))

    def test_separate_processes_share_the_pool(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / 'spans.txt'
            env = dict(os.environ, SR_LOCAL_MAX_HEAVY='2', SR_VERIFIER_STATE=tmp)
            env.pop(local_load.ENV_HELD, None)
            procs = [subprocess.Popen([sys.executable, '-c', JOB, str(ROOT / 'tools'), str(out), '0.4'], env=env,
                                      stderr=subprocess.PIPE, text=True) for _ in range(5)]
            waits = ''.join(p.communicate(timeout=60)[1] for p in procs)
            self.assertEqual([p.returncode for p in procs], [0] * 5)
            spans = sorted(tuple(map(float, line.split())) for line in out.read_text().splitlines())
            self.assertEqual(len(spans), 5)
            for start, _ in spans:
                self.assertLessEqual(sum(1 for s, e in spans if s <= start < e), 2)
            self.assertEqual(waits.count('waits for a free slot'), 3)

    def test_a_holder_that_dies_frees_its_slot(self):
        with tempfile.TemporaryDirectory() as tmp:
            code = ('import os, sys; sys.path.insert(0, sys.argv[1]); import local_load\n'
                    'with local_load.heavy("doomed", cap=1, directory=sys.argv[2]):\n'
                    '    os._exit(0)\n')
            subprocess.run([sys.executable, '-c', code, str(ROOT / 'tools'), tmp], check=True, timeout=30)
            with local_load.heavy('after', cap=1, directory=tmp, wait=2, poll=0.01):
                pass

    def test_extra_slots_are_taken_only_when_free_and_never_waited_for(self):
        with tempfile.TemporaryDirectory() as tmp:
            with local_load.heavy('a', cap=4, directory=tmp, want=8) as granted:
                self.assertEqual(granted, 4)
            with local_load.heavy('a', cap=4, directory=tmp) as one:
                self.assertEqual(one, 1)
                # A second thread asks for three while one is held: it gets all three, not a share of four.
                got = []

                def other():
                    with local_load.heavy('b', cap=4, directory=tmp, want=4) as granted:
                        got.append(granted)
                t = threading.Thread(target=other)
                t.start()
                t.join(5)
                self.assertEqual(got, [3])

    def test_staged_check_does_not_overtake_a_waiting_binding(self):
        with tempfile.TemporaryDirectory() as tmp:
            order, queued_check, queued_bind = [], threading.Event(), threading.Event()

            def run(label, foreground, queued, poll):
                with local_load.heavy(label, cap=1, directory=tmp, foreground=foreground,
                                      log=lambda _: queued.set(), wait=3, poll=poll):
                    order.append(label)

            with local_load.heavy('active compile', cap=1, directory=tmp):
                check_thread = threading.Thread(target=run, args=('staged check', False, queued_check, 0.001))
                check_thread.start()
                self.assertTrue(queued_check.wait(3))
                bind_thread = threading.Thread(target=run, args=('binding', True, queued_bind, 0.1))
                bind_thread.start()
                self.assertTrue(queued_bind.wait(3))
            bind_thread.join(5)
            check_thread.join(5)
            self.assertEqual(order, ['binding', 'staged check'])
            self.assertEqual(local_load.busy(1, tmp), 0)

    def test_the_wait_ends_with_an_error(self):
        with tempfile.TemporaryDirectory() as tmp:
            with local_load.heavy('a', cap=1, directory=tmp):
                err = []

                def late():
                    try:
                        with local_load.heavy('b', cap=1, directory=tmp, wait=0.05, poll=0.01, log=lambda m: None):
                            pass
                    except local_load.LoadGuardError as exc:
                        err.append(str(exc))
                t = threading.Thread(target=late)
                t.start()
                t.join(5)
            self.assertEqual(len(err), 1)
            self.assertIn('b: all 1 heavy local slots stayed busy', err[0])

    def test_nesting_takes_no_second_slot_so_a_heavy_tool_can_call_another(self):
        with tempfile.TemporaryDirectory() as tmp:
            with local_load.heavy('outer', cap=1, directory=tmp, want=3) as outer:
                self.assertEqual(outer, 1)
                with local_load.heavy('inner', cap=1, directory=tmp, wait=0.05, want=2) as inner:
                    self.assertEqual(inner, 1)
                self.assertEqual(local_load.busy(1, tmp), 1)
            self.assertEqual(local_load.busy(1, tmp), 0)

    def test_a_child_process_inherits_the_hold(self):
        with tempfile.TemporaryDirectory() as tmp:
            code = ('import sys; sys.path.insert(0, sys.argv[1]); import local_load\n'
                    'with local_load.heavy("child", want=5, wait=0.05) as granted: print(granted)\n')
            env = dict(os.environ, SR_LOCAL_MAX_HEAVY='2', SR_VERIFIER_STATE=tmp)
            env.pop(local_load.ENV_HELD, None)
            with mock.patch.dict(os.environ, env):
                with local_load.heavy('parent', want=2) as held:
                    self.assertEqual(held, 2)
                    out = subprocess.run([sys.executable, '-c', code, str(ROOT / 'tools')], capture_output=True,
                                         text=True, timeout=30, env=dict(os.environ))
                self.assertEqual((out.returncode, out.stdout.strip()), (0, '2'), out.stderr)
                self.assertNotIn(local_load.ENV_HELD, os.environ)

    def test_reserved_slots_are_not_offered_to_nested_blocks(self):
        with tempfile.TemporaryDirectory() as tmp:
            with local_load.heavy('outer', cap=4, directory=tmp, want=3) as outer:
                self.assertEqual(outer, 3)
                with local_load.reserved(2):
                    with local_load.heavy('inner', cap=4, directory=tmp, want=3) as inner:
                        self.assertEqual(inner, 1)
                with local_load.heavy('inner', cap=4, directory=tmp, want=3) as inner:
                    self.assertEqual(inner, 3)


class RunnersUse(unittest.TestCase):
    def test_config_accepts_a_cap_and_defaults_to_none(self):
        self.assertIsNone(runners.validate(runner_config(), root='/repo')['local_max_heavy'])
        self.assertEqual(runners.validate(runner_config(local_max_heavy=2), root='/repo')['local_max_heavy'], 2)
        for bad in (0, 'two', True):
            with self.subTest(bad=bad), self.assertRaisesRegex(runners.RunnerError, 'local_max_heavy'):
                runners.validate(runner_config(local_max_heavy=bad), root='/repo')

    def test_a_capped_machine_sends_the_attempt_to_a_reachable_runner_first(self):
        up = lambda h: True  # noqa: E731
        plain = runners.validate(runner_config(), root='/repo')
        self.assertEqual(runners.choose_attempt(plain, {}, up), ('mac', []))
        capped = runners.validate(runner_config(local_max_heavy=2), root='/repo')
        name, warns = runners.choose_attempt(capped, {}, up)
        self.assertEqual(name, 'pc')
        self.assertIn('goes to pc instead of mac', warns[0])

    def test_a_forced_host_or_no_answering_runner_stays_local(self):
        capped = runners.validate(runner_config(local_max_heavy=2), root='/repo')
        self.assertEqual(runners.choose_attempt(capped, {'SR_ATTEMPT_HOST': 'mac'}, None), ('mac', []))
        name, warns = runners.choose_attempt(capped, {}, lambda h: False)
        self.assertEqual(name, 'mac')
        self.assertIn('one of 2 heavy local slots', warns[0])

    def test_the_environment_lifts_or_sets_the_cap(self):
        capped = runners.validate(runner_config(local_max_heavy=2), root='/repo')
        self.assertEqual(runners.choose_attempt(capped, {'SR_LOCAL_MAX_HEAVY': '0'}, lambda h: True), ('mac', []))
        plain = runners.validate(runner_config(), root='/repo')
        self.assertEqual(runners.choose_attempt(plain, {'SR_LOCAL_MAX_HEAVY': '1'}, lambda h: True)[0], 'pc')

    def test_a_local_hosts_compile_slots_hold_heavy_slots_and_other_pools_do_not(self):
        runners.validate(runner_config(), root='/repo')
        with tempfile.TemporaryDirectory() as tmp:
            guard = Path(tmp) / 'local-heavy'
            with mock.patch.dict(os.environ, {'SR_VERIFIER_STATE': tmp, 'SR_LOCAL_MAX_HEAVY': '1'}):
                with runners.slot('mac-wine', 4):
                    self.assertEqual(local_load.busy(1, guard), 1)
                with runners.slot('pc-native', 4):
                    self.assertEqual(local_load.busy(1, guard), 0)
                with runners.slot('mac-wine', 4, directory=Path(tmp) / 'private'):
                    self.assertEqual(local_load.busy(1, guard), 0)
                with runners.slots('mac-wine', 4, 3) as held:
                    self.assertEqual(held, 1)
                    self.assertEqual(local_load.busy(1, guard), 1)
                self.assertEqual(local_load.busy(1, guard), 0)

    def test_a_second_compile_waits_for_the_machine_wide_slot(self):
        runners.validate(runner_config(), root='/repo')
        with tempfile.TemporaryDirectory() as tmp:
            lines, entered = [], threading.Event()
            with mock.patch.dict(os.environ, {'SR_VERIFIER_STATE': tmp, 'SR_LOCAL_MAX_HEAVY': '1'}):
                with runners.slot('mac-wine', 4):
                    def second():
                        with runners.slot('mac-wine', 4, log=lines.append):
                            entered.set()
                    t = threading.Thread(target=second)
                    t.start()
                    self.assertFalse(entered.wait(0.5))
                t.join(10)
            self.assertTrue(entered.is_set())
            self.assertEqual(len(lines), 1)
            self.assertIn('compile on mac-wine waits for a free slot', lines[0])

    def test_without_a_cap_slots_behave_as_before(self):
        runners.validate(runner_config(), root='/repo')
        with tempfile.TemporaryDirectory() as tmp:
            with mock.patch.dict(os.environ, {'SR_VERIFIER_STATE': tmp, 'SR_LOCAL_MAX_HEAVY': ''}):
                with runners.slots('mac-wine', 4, 8) as held:
                    self.assertEqual(held, 4)
                self.assertFalse((Path(tmp) / 'local-heavy').exists())


def record(into, tag):
    into.append(tag)


class CheckFanOut(unittest.TestCase):
    def test_a_capped_machine_runs_the_background_checks_in_order_in_this_process(self):
        with tempfile.TemporaryDirectory() as tmp:
            env = {'SR_LOCAL_MAX_HEAVY': '1', 'SR_VERIFIER_STATE': tmp, 'SR_CHECK_JOBS': '4'}
            with mock.patch.dict(os.environ, env):
                seen = []
                with check.background([(record, (seen, 'a')), (record, (seen, 'b'))]):
                    seen.append('body')
                self.assertEqual(seen, ['body', 'a', 'b'])

    def test_a_capped_machine_checks_entries_without_a_pool(self):
        with tempfile.TemporaryDirectory() as tmp:
            env = {'SR_LOCAL_MAX_HEAVY': '1', 'SR_VERIFIER_STATE': tmp, 'SR_CHECK_JOBS': '4'}
            with mock.patch.dict(os.environ, env), mock.patch.object(check, '_PARALLEL_MIN', 1):
                with mock.patch.object(check, '_check_function', lambda fn, target, root: fn['id']):
                    with mock.patch.object(check.multiprocessing, 'get_context', side_effect=AssertionError('pool')):
                        entries = [{'id': f'f{i}'} for i in range(5)]
                        self.assertEqual(list(check._check_functions(entries, {}, None)), [f'f{i}' for i in range(5)])
                self.assertEqual(local_load.busy(1, Path(tmp) / 'local-heavy'), 0)

    def test_full_staged_validation_releases_its_single_slot_between_groups(self):
        with tempfile.TemporaryDirectory() as tmp:
            env = {'SR_LOCAL_MAX_HEAVY': '2', 'SR_VERIFIER_STATE': tmp, 'SR_CHECK_JOBS': '4'}
            slot_dir = Path(tmp) / 'local-heavy'

            def validate_one(fn, target, root):
                self.assertEqual(local_load.busy(2, slot_dir), 1)
                return fn

            entries = list(range(5))
            with mock.patch.dict(os.environ, env), mock.patch.object(check, '_CHUNK', 2), \
                    mock.patch.object(check, '_check_function', validate_one), \
                    mock.patch.object(local_load, 'heavy', wraps=local_load.heavy) as hold:
                self.assertEqual(list(check._check_functions(entries, {}, None, staged=True)), entries)
            self.assertEqual(hold.call_args_list, [mock.call('staged check', foreground=False)] * 3)
            self.assertEqual(local_load.busy(2, slot_dir), 0)


if __name__ == '__main__':
    unittest.main()
