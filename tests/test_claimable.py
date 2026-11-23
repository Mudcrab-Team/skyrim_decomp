"""Claim-time mapping: functions of the published target-hash list are claimable without an inventory entry."""
import argparse
import json
import os
from pathlib import Path
import shutil
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import claimable  # noqa: E402
import contrib  # noqa: E402
import target_hash_offers  # noqa: E402

BUILD = 'synthetic-fixture'


def mapped(rva, size, name):
    return {'id': f'{BUILD}-0x{rva:x}', 'build_id': BUILD, 'rva': rva, 'size': size, 'status': 'mapped',
            'name': name, 'name_origin': 'GUESS', 'owner': 'test', 'evidence': 'findings/synthetic.md'}


def row(rva, size):
    return {'rva': rva, 'size': size, 'normalized_sha256': '0' * 64, 'layout_sha256': '0' * 64,
            'extraction': 'linked-reference-inference'}


class Fixture(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.tmp, ignore_errors=True)
        self.repo = self.tmp
        (self.repo / 'data/target-hashes').mkdir(parents=True)
        (self.repo / 'reconstruction/forms').mkdir(parents=True)
        (self.repo / 'reconstruction/forms/Foo.h').write_text('struct Foo { void Bar(); };\n')
        (self.repo / 'reconstruction/forms/Foo.cpp').write_text('void Foo::Bar() {}\n')
        self.data = {'target_build_id': BUILD, 'functions': [mapped(0x100, 100, 'Foo::Bar')]}
        sizes = {0x100: 100, 0x200: 20, 0x300: 150, 0x400: 10, 0x500: 300}
        shard = 'data/target-hashes/sse-steam-1-7-104-part-000.json'
        (self.repo / shard).write_text(json.dumps({'functions': [row(r, s) for r, s in sizes.items()]}))
        (self.repo / claimable.MANIFEST).write_text(json.dumps({'shards': [{'path': shard}]}))
        offered = [dict(rva=0x200, size=20, extent_source='x', **{'class': 'Foo'}),
                   dict(rva=0x300, size=150, extent_source='x', **{'class': 'Foo'}),
                   dict(rva=0x400, size=10, extent_source='x'),
                   dict(rva=0x500, size=300, extent_source='x', **{'class': 'Foo'})]
        (self.repo / claimable.OFFERED).write_text(json.dumps({'functions': offered}))


class ClaimableTests(Fixture):
    def test_bands(self):
        self.assertEqual([claimable.band(n) for n in (1, 63, 64, 255, 256, 5000)], [0, 0, 1, 1, 2, 2])

    def test_resolve_makes_a_guess_entry_only_for_published_functions(self):
        fn = claimable.resolve(self.repo, BUILD, 0x200, {0x100})
        self.assertEqual((fn['status'], fn['name'], fn['name_origin'], fn['size']), ('mapped', 'Foo::Function200', 'GUESS', 20))
        self.assertTrue(fn['name_source'].startswith('GUESS(low)'))
        self.assertEqual(claimable.resolve(self.repo, BUILD, 0x400, set())['name'], 'Function400')
        self.assertIsNone(claimable.resolve(self.repo, BUILD, 0x999, set()))
        self.assertIsNone(claimable.resolve(self.repo, BUILD, 0x100, {0x100}))

    def test_private_table_must_agree_when_present(self):
        ok = {0x200: {'kind': 'ordinary', 'size': 20}}
        self.assertIsNotNone(claimable.resolve(self.repo, BUILD, 0x200, set(), ok))
        for bad in ({}, {0x200: {'kind': 'thunk', 'size': 20}}, {0x200: {'kind': 'ordinary', 'size': 21}}):
            self.assertIsNone(claimable.resolve(self.repo, BUILD, 0x200, set(), bad))

    def test_claim_and_start_accept_a_published_function_without_an_entry(self):
        ctx = contrib.Ctx(repo=self.repo, interactive=False, env={})
        self.assertEqual(contrib.resolve_function(ctx, self.data, 0x200)['name'], 'Foo::Function200')
        self.assertIsNone(contrib.resolve_function(ctx, self.data, 0x999))
        args = argparse.Namespace(rva=['0x200', '0x100'], lists=[], classes=[], ranges=[])
        functions, entries = contrib.claim_selection(ctx, args, self.data)
        self.assertEqual([f['rva'] for f in functions], [0x100, 0x200])
        with self.assertRaises(contrib.Stop):
            contrib.claim_selection(ctx, argparse.Namespace(rva=['0x999'], lists=[], classes=[], ranges=[]), self.data)

    def test_next_prefers_small_functions_and_never_invents_an_inventory_entry(self):
        rows = contrib.candidates(self.repo, self.data, published=True)
        order = [int(r['rva'], 16) for r in rows if r['startable']]
        self.assertEqual(order, [0x200, 0x100, 0x300, 0x500])
        self.assertEqual([r['in_inventory'] for r in rows if r['startable']], [False, True, False, False])
        # No bulk mapping: the inventory itself is untouched and the default listing ignores the published list.
        self.assertEqual([f['rva'] for f in self.data['functions']], [0x100])
        self.assertEqual([int(r['rva'], 16) for r in contrib.candidates(self.repo, self.data)], [0x100])

    def test_claimed_published_functions_are_not_offered_again(self):
        rows = contrib.candidates(self.repo, self.data, claimed={0x200}, published=True)
        self.assertNotIn(0x200, [int(r['rva'], 16) for r in rows])

    def test_window_takes_every_supported_ordinary_function_and_names_only_layout_classes(self):
        def meta(rva, size, cls, verdict='supported', kind='ordinary'):
            return rva, {'rva': rva, 'size': size, 'kind': kind, 'owner': {'class': cls} if cls else None,
                         'v2': {'verdict': verdict}}
        table = dict([meta(0x10, 200, 'Foo'), meta(0x20, 8, 'Foo'), meta(0x30, 8, 'Nolayout'), meta(0x40, 8, None),
                      meta(0x50, 8, 'Foo', 'unsupported'), meta(0x60, 8, 'Foo', kind='thunk'),
                      meta(0x70, 40, 'Foo', 'caution'), meta(0x80, 8, 'Foo')])
        got = target_hash_offers.select_window(self.repo, table, known={0x80})
        self.assertEqual(got, {0x20: 'Foo', 0x70: 'Foo', 0x10: 'Foo', 0x30: None, 0x40: None})
        self.assertEqual(list(got), [0x20, 0x70, 0x10, 0x30, 0x40])
        # A limit is an address chunk, not the best-ranked few.
        self.assertEqual(list(target_hash_offers.select_window(self.repo, table, set(), limit=1)), [0x10])
        self.assertEqual(list(target_hash_offers.select_window(self.repo, table, set(), rva_range=(0x20, 0x50))),
                         [0x20, 0x30, 0x40])


def meta(rva, size, cls='Foo', verdict='supported', reasons=(), cautions=(), names=(), how=None):
    return rva, {'rva': rva, 'size': size, 'kind': 'ordinary', 'owner': {'class': cls, 'how': how},
                 'names': [{'how': n} for n in names],
                 'v2': {'verdict': verdict, 'reasons': list(reasons), 'cautions': list(cautions)}}


class WindowPolicyTests(Fixture):
    def window(self, rows, **kw):
        return list(target_hash_offers.select_window(self.repo, dict(rows), kw.pop('known', set()), **kw))

    def test_ranking_prefers_named_and_sibling_classes_and_puts_large_and_hard_last(self):
        (self.repo / 'reconstruction/forms/Rich.cpp').write_text('')
        (self.repo / 'reconstruction/forms/Rich.h').write_text('struct Rich {};\n')
        rows = [meta(0x10, 300), meta(0x20, 300, names=['community-id']), meta(0x30, 300, cls='Rich'),
                meta(0x40, 4000), meta(0x50, 40, reasons=['jump-table']), meta(0x60, 700),
                meta(0x70, 40, cautions=['indirect jump without recovered targets']), meta(0x80, 30, names=['placeholder'])]
        got = self.window(rows, siblings={'Rich': 9, 'Foo': 1})
        # small first; then medium (named before unnamed, more siblings first); large and hard functions last
        self.assertEqual(got, [0x80, 0x20, 0x30, 0x10, 0x60, 0x50, 0x70, 0x40])
        self.assertEqual(target_hash_offers.rank_key(dict(rows)[0x30], {'Rich': 9}, 'Rich')[:4], (False, False, 2, True))

    def pdb_types(self, *rows):
        """Write a generated CrashLogger layout directory holding `rows` of (name, kind, size, variant)."""
        base = self.repo / target_hash_offers.PDB_DIR
        (base / 'types').mkdir(parents=True)
        lines = ['# CRASHLOGGER_PDB(59818@test)', '# header']
        for name, kind, size, variant in rows:
            lines.append('\t'.join((name, name, kind, str(size), variant)))
            if name != 'Nofile':
                (base / 'types' / f'{name}.h').write_text(f'struct {name} {{}};\n')
        (base / 'types.tsv').write_text('\n'.join(lines) + '\n')

    def test_a_generated_pdb_layout_counts_as_a_layout_unit(self):
        self.pdb_types(('Actor', 'struct', 40, '-'), ('Zzzq', 'struct', 8, '-'), ('Enumy', 'enum', 4, '-'),
                       ('Unioned', 'union', 4, '-'), ('Empty', 'struct', 0, '-'), ('Dup', 'struct', 8, 'abc12345'),
                       ('Nofile', 'struct', 8, '-'))
        self.assertEqual(target_hash_offers.pdb_layout_classes(self.repo), {'Actor', 'Zzzq'})
        rows = [meta(0x10, 8, cls='Actor'), meta(0x20, 8, cls='Zzzq'), meta(0x30, 8, cls='Enumy'),
                meta(0x40, 8, cls='Dup'), meta(0x50, 8, cls='Nolayout'), meta(0x60, 8, cls='Actor', verdict='unsupported')]
        # Zzzq has a header but no unit area rule, so nothing could be started there; the others have no PDB layout.
        # They are still offered, after the layout class and without a class on the row.
        self.assertEqual(self.window(rows), [0x10, 0x20, 0x30, 0x40, 0x50])
        self.assertEqual({r: c for r, c in target_hash_offers.select_window(self.repo, dict(rows), set()).items() if c},
                         {0x10: 'Actor'})

    def test_no_pdb_directory_changes_nothing(self):
        self.assertEqual(target_hash_offers.pdb_layout_classes(self.repo), set())
        self.assertEqual(target_hash_offers.select_window(self.repo, dict([meta(0x10, 8, cls='Actor')]), set()),
                         {0x10: None})

    def test_pdb_only_classes_rank_after_real_units_and_keep_size_order_within_each(self):
        self.pdb_types(('Actor', 'struct', 40, '-'), ('Foo', 'struct', 8, '-'))
        rows = [meta(0x10, 8, cls='Actor'), meta(0x20, 300, cls='Foo'), meta(0x30, 4000, cls='Foo'),
                meta(0x40, 70, cls='Actor'), meta(0x50, 40, cls='Foo', reasons=['jump-table']), meta(0x60, 20, cls='Actor')]
        got = self.window(rows)
        # Foo has a real unit (its PDB header is irrelevant): medium, then hard, then large; Actor is PDB-only: small, small-medium.
        self.assertEqual(got, [0x20, 0x50, 0x30, 0x10, 0x60, 0x40])
        self.assertTrue(target_hash_offers.rank_key(dict(rows)[0x10], {}, 'Actor', True)
                        > target_hash_offers.rank_key(dict(rows)[0x30], {}, 'Foo'))

    def test_a_class_with_a_cpp_but_no_header_falls_back_to_its_pdb_layout(self):
        self.pdb_types(('Actor', 'struct', 40, '-'))
        (self.repo / 'reconstruction/skyrim_shared/actors').mkdir(parents=True)
        (self.repo / 'reconstruction/skyrim_shared/actors/Actor.cpp').write_text('')
        self.assertEqual(self.window([meta(0x10, 8, cls='Actor')]), [0x10])

    def test_keep_reserved_and_known_are_never_selected_and_limit_bounds_the_slice(self):
        rows = [meta(r, 8 + r) for r in (0x10, 0x20, 0x30, 0x40, 0x50)]
        self.assertEqual(self.window(rows, known={0x10}, reserved={0x20}, keep={0x30}), [0x40, 0x50])
        self.assertEqual(self.window(rows, limit=2), [0x10, 0x20])

    def test_a_slice_skips_reserved_rows_and_keeps_scanning_until_it_is_full(self):
        rows = [meta(r, 8 + r) for r in range(0x10, 0x100, 0x10)]
        reserved = {0x10, 0x20, 0x30, 0x40}
        self.assertEqual(self.window(rows, limit=3, reserved=reserved), [0x50, 0x60, 0x70])
        # Fewer eligible rows than the slice: all of them, never a reserved one.
        self.assertEqual(self.window(rows, limit=50, reserved=reserved | {0x80}), [0x50, 0x60, 0x70, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0])

    def test_a_plan_directory_idle_past_the_limit_stops_reserving(self):
        live, stale = self.tmp / 'live', self.tmp / 'stale'
        for d, rva in ((live, 0x2000), (stale, 0x3000)):
            d.mkdir()
            (d / 'plan.json').write_text(json.dumps([rva]))
        now = 1_000_000.0
        os.utime(live / 'plan.json', (now - 3600, now - 3600))
        os.utime(stale / 'plan.json', (now - 13 * 3600, now - 13 * 3600))
        self.assertEqual(target_hash_offers.reserved_rvas([live, stale], 12, now), {0x2000})
        self.assertEqual(target_hash_offers.reserved_rvas([live, stale], None, now), {0x2000, 0x3000})
        # A recent log beside an old plan keeps the whole directory reserved.
        (stale / 'run.log').write_text('x')
        os.utime(stale / 'run.log', (now - 60, now - 60))
        self.assertEqual(target_hash_offers.reserved_rvas([live, stale], 12, now), {0x2000, 0x3000})
        self.assertEqual(target_hash_offers.plan_idle_hours(self.tmp / 'missing', now), float('inf'))

    def test_reserved_rvas_read_the_plan_formats_and_skip_what_is_unreadable(self):
        plans = self.tmp / 'plans'
        plans.mkdir()
        (plans / 'recon.json').write_text(json.dumps([0x2000, 0x2010]))
        (plans / 'pairs.json').write_text(json.dumps([[0x3000, 'ClassTypeLeaf3000'], [0x3010, 'ClassTypeLeaf3010']]))
        (plans / 'ranked.json').write_text(json.dumps([[310, 'm:abc', [0x4000], [0x4010, 0x4020]]]))
        (plans / 'results.json').write_text(json.dumps({'20480': {'rva': 20480, 'sizes': [33, 33]}}))
        (plans / 'broken.json').write_text('{')
        (plans / 'notes.txt').write_text('0x9000')
        got = target_hash_offers.reserved_rvas([plans, self.tmp / 'missing'])
        self.assertEqual(got, {0x2000, 0x2010, 0x3000, 0x3010, 0x4000, 0x4010, 0x4020, 20480})

    def table(self, count):
        return dict(meta(0x1000 + 0x10 * i, 20 + i) for i in range(count))

    def test_a_slice_is_added_only_below_the_low_water_mark_and_offered_rows_stay(self):
        table = self.table(6)
        # Fixture: 0x100 is inventory-mapped, 0x200/0x300/0x500 are already offered: 4 claimable.
        for low, expected_added in ((4, 0), (5, 3)):
            classes, added, left = target_hash_offers.plan_window(
                self.repo, table | {0x200: meta(0x200, 20)[1], 0x300: meta(0x300, 150)[1], 0x500: meta(0x500, 300)[1]},
                self.data, {0x100: {}}, set(), set(), low, 3)
            self.assertEqual((left, len(added)), (4, expected_added))
            self.assertTrue({0x200, 0x300, 0x500} <= set(classes))
        self.assertEqual(sorted(added), [0x1000, 0x1010, 0x1020])

    def test_a_range_chunk_is_added_whatever_is_left_and_classless_rows_stay_offered(self):
        table = self.table(6) | {0x200: meta(0x200, 20)[1]}
        table[0x1020]['owner'] = None
        classes, added, left = target_hash_offers.plan_window(
            self.repo, table, self.data, {0x100: {}}, set(), set(), 0, 1, rva_range=(0x1010, 0x1040))
        self.assertEqual((left, sorted(added)), (4, [0x1010, 0x1020, 0x1030]))
        self.assertIsNone(classes[0x1020])
        # The row written for it carries `window` and no class; the next refill reads it back as offered.
        (self.repo / 'data/target-hashes/contributor-targets.json').write_text(json.dumps({'functions': [
            {'rva': 0x1020, 'size': 40, 'window': True}, {'rva': 0x1030, 'size': 40, 'class': 'Foo', 'window': True},
            {'rva': 0x1040, 'size': 40}]}))
        self.assertEqual(claimable.offered_window(self.repo), {0x1020: None, 0x1030: 'Foo'})
        self.assertEqual(claimable.offered_classes(self.repo), {0x1030: 'Foo'})
        again, new, _left = target_hash_offers.plan_window(self.repo, table, self.data, {0x100: {}}, set(), set(), 0, 1)
        self.assertIn(0x1020, again)
        self.assertNotIn(0x1020, new)

    def test_a_long_offered_list_is_stored_in_parts_and_read_back_whole(self):
        rows = [{'rva': 0x1000 + 0x10 * i, 'size': 8, 'window': True} for i in range(7)]
        output = {'schema': 1, 'build_id': BUILD, 'claim_function_count': 0, 'functions': rows}
        written = claimable.write_sharded(self.repo, claimable.OFFERED, output, 'functions', 3)
        self.assertEqual(len(written), 4)  # the index and three parts
        index = json.loads((self.repo / claimable.OFFERED).read_text())
        self.assertNotIn('functions', index)
        self.assertEqual([p['count'] for p in index['parts']], [3, 3, 1])
        self.assertEqual(claimable.sharded_json(self.repo, claimable.OFFERED, 'functions')['functions'], rows)
        self.assertEqual(set(claimable.offered_window(self.repo)), {r['rva'] for r in rows})
        # A shorter list leaves no stale part behind.
        claimable.write_sharded(self.repo, claimable.OFFERED, dict(output, functions=rows[:3]), 'functions', 3)
        self.assertEqual(len(list((self.repo / 'data/target-hashes').glob('contributor-targets-part-*.json'))), 1)
        # A part that no longer matches its digest is refused, so no reader works from a partial list.
        part = self.repo / index['parts'][0]['path']
        part.write_text(part.read_text().replace('4096', '4097'))
        self.assertEqual(claimable.offered_window(self.repo), {})
        with self.assertRaises(ValueError):
            claimable.sharded_json(self.repo, claimable.OFFERED, 'functions')

    def test_an_unclaimed_reserved_row_is_withdrawn_but_a_claimed_one_stays(self):
        table = {0x200: meta(0x200, 20)[1], 0x300: meta(0x300, 150)[1], 0x500: meta(0x500, 300)[1]}
        classes, _added, _left = target_hash_offers.plan_window(
            self.repo, table, self.data, {0x100: {}}, {0x300}, {0x200, 0x300}, 0, 5)
        self.assertEqual(sorted(classes), [0x300, 0x500])

    def test_matched_siblings_count_matched_functions_per_class(self):
        data = {'functions': [{'name': 'A::B::f', 'status': 'matched'}, {'name': 'A::B::g', 'status': 'matched'},
                              {'name': 'A::B::h', 'status': 'mapped'}, {'name': 'plain', 'status': 'matched'}]}
        self.assertEqual(target_hash_offers.matched_siblings(data), {'A::B': 2})


if __name__ == '__main__':
    unittest.main()
