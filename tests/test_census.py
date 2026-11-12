"""tools/census.py on original synthetic encodings and tables (no game data)."""
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools' / 'analysis'))
import census  # noqa: E402
import x64  # noqa: E402

BASE = 0x140000000
VT = 0x5000


def fam(hexcode, kind='ordinary', vt=False, rva=0x1000):
    code = bytes.fromhex(hexcode.replace(' ', ''))
    insns = x64.decode_range(code, 0, len(code), BASE + rva)
    return census.family(insns, code, kind, len(code), (lambda t: vt) if vt else (lambda t: False), BASE)


class Buckets(unittest.TestCase):
    def test_edges(self):
        self.assertEqual(census.bucket(8), '<=8')
        self.assertEqual(census.bucket(9), '9-16')
        self.assertEqual(census.bucket(512), '257-512')
        self.assertEqual(census.bucket(1024), '513-1k')
        self.assertEqual(census.bucket(4096), '1k-4k')
        self.assertEqual(census.bucket(4097), '>4k')


class Families(unittest.TestCase):
    def test_trivial_shapes(self):
        self.assertEqual(fam('c3'), 'empty')
        self.assertEqual(fam('31c0 c3'), 'return-constant')
        self.assertEqual(fam('b801000000 c3'), 'return-constant')
        self.assertEqual(fam('8b4108 c3'), 'return-member')
        self.assertEqual(fam('0fb64110 c3'), 'return-member')
        self.assertEqual(fam('488d4110 c3'), 'return-member-address')
        self.assertEqual(fam('488d0500000000 c3'), 'return-global-address')
        self.assertEqual(fam('8b0500000000 c3'), 'return-global')
        self.assertEqual(fam('89510c c3'), 'set-member')

    def test_thunks(self):
        self.assertEqual(fam('e900000000'), 'tail-call-thunk')
        self.assertEqual(fam('4883e908 e900000000'), 'adjustor-thunk')
        self.assertEqual(fam('488b4910 e900000000'), 'member-forwarder')
        self.assertEqual(fam('488b01 ff6008'), 'vcall-thunk')
        self.assertEqual(fam('ff2500000000', kind='import-thunk'), 'import-thunk')

    def test_member_shapes(self):
        self.assertEqual(fam('f6411001 0f95c0 c3'), 'flag-test')
        self.assertEqual(fam('c7410800000000 c7410c00000000 c3'), 'member-reset')
        self.assertEqual(fam('488d0500000000 488901 488bc1 c3', vt=True), 'trivial-ctor-vftable')
        self.assertEqual(fam('488d0500000000 488901 c3', vt=True), 'vftable-store-only')
        # A global address store that is not a vftable is a plain small leaf.
        self.assertEqual(fam('488d0500000000 488901 c3'), 'small-leaf')

    def test_deleting_destructor(self):
        code = ('4053 4883ec20 488bd9 f6c201 e800000000 7408 488bcb e800000000'
                ' 488bc3 4883c420 5b c3')
        self.assertEqual(fam(code), 'scalar-deleting-dtor')

    def test_static_and_size(self):
        self.assertEqual(fam('488d0d00000000 e900000000', kind='static-initializer'), 'static-init-atexit')
        self.assertEqual(fam('c3', kind='teardown'), 'teardown-stub')
        self.assertEqual(fam('90' * 100 + 'c3'), 'large')

    def test_padding_is_ignored(self):
        self.assertEqual(fam('8b4108 c3 cccccccc'), 'return-member')


class Shape(unittest.TestCase):
    def key(self, hexcode, eh=False):
        code = bytes.fromhex(hexcode.replace(' ', ''))
        return census.shape_key(x64.decode_range(code, 0, len(code), BASE), eh)

    def test_registers_and_values_dropped(self):
        self.assertEqual(self.key('8b4108 c3'), self.key('8b5120 c3'))
        self.assertEqual(self.key('b801000000 c3'), self.key('b902000000 c3'))

    def test_form_and_handler_kept(self):
        self.assertNotEqual(self.key('8b4108 c3'), self.key('8b0500000000 c3'))
        self.assertNotEqual(self.key('8b4108 c3'), self.key('8b410800 c3'[:-2] + 'c3', eh=True))
        self.assertNotEqual(self.key('8b4108 c3'), self.key('8b8100010000 c3'))


class Funclets(unittest.TestCase):
    def verdict(self, funclets, starts, entries, pad=(), leaf_end=None):
        return census.funclet_verdicts(0x1000, funclets, sorted(starts), sorted(entries),
                                       lambda e: e in pad, lambda f: leaf_end.get(f) if leaf_end else None)

    def test_none(self):
        self.assertEqual(self.verdict({}, [], [])[0], 'none')

    def test_old_rules_suffice(self):
        self.assertEqual(self.verdict({0x2000: 0x10}, [0x1000, 0x2000, 0x2010], [0x2000])[0], 'v0.5')
        self.assertEqual(self.verdict({0x2000: 0x10}, [0x1000, 0x2000], [0x2000], pad={0x2010})[0], 'v0.5')

    def test_own_pdata_end_needs_new_rules(self):
        self.assertEqual(self.verdict({0x2000: 0x10}, [0x1000, 0x2000], [0x2000]), ('v0.6', 'pdata-end'))

    def test_leaf_end_at_foreign_entry(self):
        v = self.verdict({0x2000: None}, [0x1000], [0x2000, 0x2008], leaf_end={0x2000: 0x2008})
        self.assertEqual(v, ('v0.6', 'funclet-entry'))

    def test_leaf_end_unshown(self):
        v = self.verdict({0x2000: None}, [0x1000], [0x2000], leaf_end={0x2000: 0x2008})
        self.assertEqual(v, ('refused', 'leaf-end-unshown'))

    def test_foreign_entry_inside(self):
        v = self.verdict({0x2000: 0x10}, [0x1000, 0x2000, 0x2010], [0x2000, 0x2008])
        self.assertEqual(v, ('refused', 'foreign-entry-inside'))

    def test_leaf_unknown(self):
        self.assertEqual(self.verdict({0x2000: None}, [0x1000], [0x2000])[0], 'refused')


def row(**kw):
    r = {'blocked': None, 'l1_members': 1, 'l1_rep': True, 'family': 'large', 'size': 300, 'cxx_eh': False}
    r.update(kw)
    return r


class Tiers(unittest.TestCase):
    def test_order(self):
        self.assertEqual(census.tier(row(blocked='skip-first-home-slot', l1_members=5, l1_rep=False))[0], 'T4')
        self.assertEqual(census.tier(row(l1_members=3, l1_rep=False))[0], 'T0')
        self.assertEqual(census.tier(row(l1_members=3, l1_rep=True, family='empty'))[0], 'T1')
        self.assertEqual(census.tier(row(family='flag-test', size=12))[0], 'T1p')
        self.assertEqual(census.tier(row(family='small-calls', size=100))[0], 'T2')
        self.assertEqual(census.tier(row(family='small-calls', size=100, cxx_eh=True))[0], 'T3')
        self.assertEqual(census.tier(row())[0], 'T3')

    def test_blocked_reasons(self):
        self.assertEqual(census.blocked_reason({'rva': 5}, {5}, set(), 'none', None), 'skip-first-home-slot')
        self.assertEqual(census.blocked_reason({'rva': 5}, set(), {5}, 'none', None),
                         'eh-state-store-without-handler')
        v2 = {'verdict': 'unsupported', 'reasons': ['thunk']}
        self.assertIsNone(census.blocked_reason({'rva': 5}, set(), set(), 'v0.6', v2))
        v2 = {'verdict': 'unsupported', 'reasons': ['jump-table']}
        self.assertEqual(census.blocked_reason({'rva': 5}, set(), set(), 'none', v2), 'v2-unsupported:jump-table')
        self.assertEqual(census.blocked_reason({'rva': 5}, set(), set(), 'refused', None),
                         'funclet-extent-unprovable')


class Clusters(unittest.TestCase):
    def test_stats(self):
        rows = [{'rva': i, 'size': 10, 'family': 'empty', 'masked': 'a' if i < 3 else 'b%d' % i} for i in range(5)]
        s = census.cluster_stats(rows, 'masked')
        self.assertEqual((s['clusters'], s['functions'], s['bytes']), (1, 3, 30))
        self.assertEqual((s['stampable_functions'], s['stampable_bytes']), (2, 20))
        self.assertEqual(s['clusters_by_members'], {'3-4': 1})
        self.assertEqual(s['top20'], [{'members': 3, 'size': 10, 'family': 'empty'}])


class Projection(unittest.TestCase):
    def test_plans(self):
        summary = {'tier_size_buckets': {'T0': {'<=8': 10}, 'T2': {'33-64': 4}, 'T3': {'129-256': 2},
                                         'T4': {'>4k': 7}},
                   'tiers': {'T0': {'functions': 10}, 'T2': {'functions': 4}, 'T3': {'functions': 2}},
                   'clusters': {'masked': {'clusters': 2}}}
        roles = {'by_stage': {'draft': {'usd': 10.0}, 'function-review': {'usd': 10.0}, 'tooling': {'usd': 100.0}}}
        res = census.project(summary, roles, 10)
        self.assertAlmostEqual(res['marginal_per_function'], 2.0)
        self.assertEqual(res['reachable_functions'], 16)
        a_low = 10 * 2.0 + 4 * 2.0 + 2 * 2 * 2.0
        self.assertEqual(res['plans']['A'][0], round(a_low))
        for plan in ('A', 'B', 'C'):
            self.assertLessEqual(res['plans'][plan][0], res['plans'][plan][1])
        c = res['plans']
        self.assertLessEqual(abs(c['C'][0] - sum(c['C:' + t][0] for t in ('T0', 'T1', 'T2', 'T3'))), 2)
        # Per-function work (everything but the one-time generators) costs less than today's process.
        self.assertLess(c['C:T2'][0] + c['C:T3'][0] + c['C:T0'][0], c['A'][0])


if __name__ == '__main__':
    unittest.main()
