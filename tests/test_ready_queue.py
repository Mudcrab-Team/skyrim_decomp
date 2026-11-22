"""Callee-first ready queue: synthetic function tables only."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]
import contrib
import ready_queue


def row(rva, size, callees=(), tail=(), kind='ordinary', verdict='supported'):
    return {'rva': rva, 'size': size, 'callees': list(callees), 'tail_callees': list(tail),
            'kind': kind, 'v2': {'verdict': verdict}}


class Ranking(unittest.TestCase):
    def test_ready_needs_every_callee_and_tail_callee_matched(self):
        rows = [row(1, 8), row(2, 8, callees=[100]), row(3, 8, tail=[101]), row(4, 8, callees=[100], tail=[101]),
                row(5, 8, callees=[2])]
        entries, counts = ready_queue.rank(rows, matched={100})
        self.assertEqual({e['rva'] for e in entries}, {1, 2})
        self.assertEqual(counts['ready'], 2)

    def test_unmatched_callee_of_any_kind_blocks_its_caller(self):
        rows = [row(1, 8, callees=[50]), row(50, 8, kind='thunk')]
        entries, _ = ready_queue.rank(rows, matched=set())
        self.assertEqual(entries, [])

    def test_small_first_then_most_blocking_then_size(self):
        rows = [row(1, 300), row(2, 10), row(3, 12), row(4, 12), row(5, 100),
                row(10, 8, callees=[3, 5]), row(11, 8, callees=[3]), row(12, 8, callees=[1])]
        entries, _ = ready_queue.rank(rows, matched=set())
        order = [e['rva'] for e in entries]
        # 3 blocks two callers; 4 and 2 block none; the bucket under 16 comes before 100 and 300 bytes
        self.assertEqual(order, [3, 2, 4, 5, 1])
        self.assertEqual(next(e for e in entries if e['rva'] == 3)['blocks'], 2)

    def test_unlocks_counts_callers_whose_only_missing_callee_it_is(self):
        rows = [row(1, 8), row(2, 8), row(10, 8, callees=[1]), row(11, 8, callees=[1, 2])]
        entries, _ = ready_queue.rank(rows, matched=set())
        by = {e['rva']: e for e in entries}
        self.assertEqual((by[1]['blocks'], by[1]['unlocks']), (2, 1))
        self.assertEqual((by[2]['blocks'], by[2]['unlocks']), (1, 0))

    def test_unsupported_matched_and_other_kinds_are_not_queued(self):
        rows = [row(1, 8, verdict='unsupported'), row(2, 8), row(3, 8, kind='static-initializer'), row(4, 8)]
        entries, counts = ready_queue.rank(rows, matched={2})
        self.assertEqual([e['rva'] for e in entries], [4])
        self.assertEqual(counts['unmatched_ordinary'], 2)

    def test_build_limits_listing_but_keeps_total(self):
        progress = {'target_build_id': 'b', 'updated_at': 'x',
                    'functions': [{'rva': 1, 'status': 'matched'}, {'rva': 2, 'status': 'mapped'}]}
        doc = ready_queue.build([row(2, 8), row(3, 8), row(4, 8, callees=[1])], progress, limit=2)
        self.assertEqual(doc['counts'], {'unmatched_ordinary': 3, 'ready': 3, 'blocking_unmatched_ordinary': 0,
                                         'listed': 2})
        self.assertEqual([e['rva'] for e in doc['entries']], ['0x2', '0x3'])


class Feeding(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.root = Path(temp.name)
        (self.root / 'data').mkdir()
        (self.root / 'reconstruction/forms').mkdir(parents=True)
        (self.root / 'data/progress.json').write_text(json.dumps({'target_build_id': 'b', 'functions': []}))
        self.data = {'target_build_id': 'b', 'functions': [
            dict(rva=0x1000, name='TESNew::Work', size=12, status='mapped', name_origin='GUESS'),
            dict(rva=0x2000, name='TESNew::Other', size=12, status='mapped', name_origin='GUESS')]}

    def queue(self, build='b'):
        (self.root / ready_queue.QUEUE_PATH).write_text(json.dumps(
            {'build_id': build, 'entries': [{'rva': '0x2000', 'size': 12, 'blocks': 5, 'unlocks': 1}]}))

    def test_load_queue_keys_by_rva_and_ignores_another_build(self):
        self.assertEqual(ready_queue.load_queue(self.root), {})
        self.queue()
        self.assertEqual(set(ready_queue.load_queue(self.root)), {0x2000})
        self.queue(build='other')
        self.assertEqual(ready_queue.load_queue(self.root), {})

    def test_ready_function_is_offered_before_an_equal_unready_one(self):
        unready = [c['rva'] for c in contrib.candidates(self.root, self.data)]
        self.assertEqual(unready, ['0x1000', '0x2000'])
        self.queue()
        rows = contrib.candidates(self.root, self.data, ready=ready_queue.load_queue(self.root))
        self.assertEqual([c['rva'] for c in rows], ['0x2000', '0x1000'])
        self.assertEqual([c['callee_ready'] for c in rows], [True, False])


if __name__ == '__main__':
    unittest.main()
