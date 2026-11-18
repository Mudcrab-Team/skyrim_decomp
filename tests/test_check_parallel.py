import os
import sys
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check  # noqa: E402


def ok():
    return None


def refuse(message):
    raise ValueError(message)


def die():
    os._exit(3)


class BackgroundChecks(unittest.TestCase):
    def run_with(self, jobs, calls):
        with mock.patch.dict(os.environ, {'SR_CHECK_JOBS': jobs}):
            with check.background(calls):
                pass

    def test_a_failing_child_fails_the_load_in_call_order(self):
        for jobs in ('1', '2'):
            with self.subTest(jobs=jobs):
                with self.assertRaisesRegex(ValueError, 'first'):
                    self.run_with(jobs, [(ok, ()), (refuse, ('first',)), (refuse, ('second',))])

    def test_a_child_that_dies_without_reporting_fails_the_load(self):
        with self.assertRaises(ValueError):
            self.run_with('2', [(die, ())])

    def test_passing_children_pass(self):
        self.run_with('2', [(ok, ()), (ok, ())])


class InventoryPool(unittest.TestCase):
    def entries(self, count):
        return [{'id': f'f{i}', 'status': 'mapped'} for i in range(count)]

    def test_pool_and_serial_runs_agree_and_keep_inventory_order(self):
        def fake(fn, target, root):
            if fn['id'] in ('f7', 'f9'):
                raise ValueError(fn['id'])
            return (fn['id'], 'stale') if fn['id'] == 'f3' else None
        with mock.patch.object(check, '_check_function', fake):
            with mock.patch.object(check, '_PARALLEL_MIN', 1), mock.patch.object(check, '_CHUNK', 1):
                for jobs in ('1', '4'):
                    with mock.patch.dict(os.environ, {'SR_CHECK_JOBS': jobs}):
                        seen = []
                        with self.assertRaisesRegex(ValueError, 'f7'):
                            for outcome in check._check_functions(self.entries(20), {}, None):
                                seen.append(outcome)
                        self.assertEqual(seen, [None, None, None, ('f3', 'stale'), None, None, None])


if __name__ == '__main__':
    unittest.main()
