"""Claim-time mapping: functions of the published target-hash list are claimable without an inventory entry."""
import argparse
import json
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

    def test_window_takes_small_functions_of_classes_with_a_layout(self):
        def meta(rva, size, cls, verdict='supported', kind='ordinary'):
            return rva, {'rva': rva, 'size': size, 'kind': kind, 'owner': {'class': cls} if cls else None,
                         'v2': {'verdict': verdict}}
        table = dict([meta(0x10, 200, 'Foo'), meta(0x20, 8, 'Foo'), meta(0x30, 8, 'Nolayout'), meta(0x40, 8, None),
                      meta(0x50, 8, 'Foo', 'unsupported'), meta(0x60, 8, 'Foo', kind='thunk'),
                      meta(0x70, 40, 'Foo', 'caution'), meta(0x80, 8, 'Foo')])
        got = target_hash_offers.select_window(self.repo, table, known={0x80})
        self.assertEqual(list(got), [0x20, 0x70, 0x10])
        self.assertEqual(list(target_hash_offers.select_window(self.repo, table, set(), limit=1)), [0x20])
