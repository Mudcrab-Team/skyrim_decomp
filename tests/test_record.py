"""tools/record.py: one function's rows written directly, validator-gated, idempotent, push retried."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tests'))
sys.path.insert(0, str(ROOT / 'tools'))
import build_index  # noqa: E402
import record  # noqa: E402
from check import validate  # noqa: E402
from check import DIGEST_METHOD  # noqa: E402
from digest_v2 import tu_digest  # noqa: E402
from test_match_gate import CPP, GateFixture, HDR, RECORD, REVIEW  # noqa: E402

OTHER = {'id': 'synthetic-fixture-0x3000', 'build_id': 'synthetic-fixture', 'rva': 0x3000, 'size': 8,
         'status': 'mapped', 'name': 'Other', 'name_origin': 'GUESS', 'owner': 'test',
         'evidence': 'findings/synthetic.md'}
BLOB = b'{"leak": "no"}'


class RecordTests(GateFixture, unittest.TestCase):
    def setUp(self):
        super().setUp()
        (self.root / REVIEW).unlink()
        self.fn['status'] = 'mapped'
        self.data['functions'].append(dict(OTHER))
        self.save()
        build_index.write_index(self.data, self.root)

    def save(self):
        self.write('data/progress.json', json.dumps(self.data, indent=2, ensure_ascii=False) + '\n')
        self.write('builds/target.json', json.dumps(self.target, indent=2) + '\n')

    def apply(self, rvas=None, **kw):
        return record.apply(self.root, 'synthetic-fixture', rvas or [self.fn['rva']], BLOB,
                            model='gpt-6.1-terra', task_id='pr-bot-1-abcd', **kw)

    def test_rows_point_at_their_own_report_and_validate(self):
        out = self.apply()
        self.assertEqual(out['recorded'], [self.fn['rva']])
        data = json.loads((self.root / 'data/progress.json').read_text())
        row = data['functions'][0]
        self.assertEqual((row['status'], row['report'], row['evidence']), ('matched', RECORD, RECORD))
        self.assertEqual(data['functions'][1], OTHER)
        validate(data, self.target, self.root)
        review = json.loads((self.root / REVIEW).read_text())
        self.assertEqual((review['verdict'], review['review_kind'], review['reviewer_model']),
                         ('approve', 'full', 'gpt-6.1-terra'))

    def test_index_patch_equals_full_render(self):
        self.apply()
        data = json.loads((self.root / 'data/progress.json').read_text())
        self.assertEqual((self.root / build_index.INDEX).read_text(), build_index.render_index(data, self.root))

    def test_validator_refusal_leaves_everything_untouched(self):
        before = (self.root / 'data/progress.json').read_bytes()
        self.write('reconstruction/synthetic/SyntheticSum.h', 'int SyntheticAddOne(int);\nint drift;\n')
        out = self.apply()
        self.assertEqual(out['recorded'], [])
        self.assertIn(self.fn['rva'], out['refused'])
        self.assertEqual((self.root / 'data/progress.json').read_bytes(), before)
        self.assertFalse((self.root / REVIEW).exists())

    def test_unknown_and_unrecorded_functions_are_refused_not_invented(self):
        out = self.apply([0x9999, 0x3000])
        self.assertEqual(out['recorded'], [])
        self.assertEqual(set(out['refused']), {0x9999, 0x3000})

    def publish(self, *rvas):
        """Publish bounds for functions the inventory does not hold, as the target-hash manifest does."""
        import claimable
        shard = 'data/target-hashes/sse-steam-1-7-104-part-000.json'
        sizes = {self.fn['rva']: self.fn['size']}
        self.write(shard, json.dumps({'functions': [{'rva': r, 'size': sizes.get(r, 4)} for r in rvas]}))
        self.write(claimable.MANIFEST, json.dumps({'shards': [{'path': shard}]}))
        self.write(claimable.EVIDENCE, 'shared evidence of claim-time entries\n')

    def test_a_published_function_without_an_entry_gets_one_when_it_is_recorded(self):
        self.data['functions'].remove(self.fn)
        self.save()
        build_index.write_index(self.data, self.root)
        self.publish(self.fn['rva'])
        before = len(self.data['functions'])
        out = self.apply()
        self.assertEqual(out['recorded'], [self.fn['rva']])
        data = json.loads((self.root / 'data/progress.json').read_text())
        self.assertEqual(len(data['functions']), before + 1)
        row = data['functions'][-1]
        self.assertEqual((row['rva'], row['status'], row['name_origin'], row['owner'], row['report']),
                         (self.fn['rva'], 'matched', 'GUESS', 'claim-time', RECORD))
        self.assertEqual(row['name'], f'Function{self.fn["rva"]:x}')
        validate(data, self.target, self.root)
        self.assertEqual((self.root / build_index.INDEX).read_text(), build_index.render_index(data, self.root))

    def test_an_unpublished_function_is_still_refused(self):
        self.data['functions'].remove(self.fn)
        self.save()
        self.publish(0x7777)
        before = (self.root / 'data/progress.json').read_bytes()
        out = self.apply()
        self.assertEqual((out['recorded'], out['refused']), ([], {self.fn['rva']: 'not in inventory'}))
        self.assertEqual((self.root / 'data/progress.json').read_bytes(), before)

    def test_a_refused_claim_time_function_adds_no_entry(self):
        self.data['functions'].remove(self.fn)
        self.save()
        self.publish(self.fn['rva'])
        self.write('reconstruction/synthetic/SyntheticSum.h', 'int SyntheticAddOne(int);\nint drift;\n')
        before = (self.root / 'data/progress.json').read_bytes()
        out = self.apply()
        self.assertEqual(out['recorded'], [])
        self.assertEqual((self.root / 'data/progress.json').read_bytes(), before)

    def test_second_run_is_a_no_op(self):
        self.apply()
        snapshot = (self.root / 'data/progress.json').read_bytes()
        again = self.apply()
        self.assertEqual(again['recorded'], [])
        self.assertEqual(again['refused'][self.fn['rva']], 'already matched')
        self.assertEqual((self.root / 'data/progress.json').read_bytes(), snapshot)


    def test_a_record_pointing_at_an_immutable_unit_map_carries_the_map_and_its_history(self):
        import symbol_map
        from test_match_gate import MAP
        smap = json.loads((self.root / MAP).read_text())
        blob = symbol_map.serialize(smap)
        name = f'reports/synthetic-fixture/unit-symbols/{record.hashlib.sha256(blob).hexdigest()}.json'
        symbol_map.create(self.root, name, smap)
        pinned = record.hashlib.sha256((self.root / name).read_bytes()).hexdigest()
        self.record['symbol_map'] = {'path': name, 'sha256': pinned}
        for run in self.record['runs']:
            run['report']['symbol_map_sha256'] = pinned
        self.save_record(keep_build=True)
        out = self.apply()
        self.assertEqual(out['recorded'], [self.fn['rva']])
        self.assertIn(name, out['files'])
        self.assertIn(symbol_map.history_name(name), out['files'])
        self.assertNotIn(MAP, out['files'])

    def test_grown_unit_rebinds_an_already_matched_function_and_a_failure_restores_it(self):
        self.apply()
        # A later stacked PR grows the unit: the digest changes, the old approval is stale.
        old_review = (self.root / REVIEW).read_bytes()
        self.write('reconstruction/synthetic/SyntheticSum.h', 'int SyntheticAddOne(int);\n')
        self.assertEqual(self.apply()['refused'][self.fn['rva']], 'already matched')
        self.assertEqual((self.root / REVIEW).read_bytes(), old_review)


class PushRetryTests(unittest.TestCase):
    def test_non_fast_forward_is_fetched_rebased_and_pushed(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            def g(cwd, *a):
                return subprocess.run(['git', '-C', str(cwd), *a], check=True, capture_output=True, text=True).stdout
            subprocess.run(['git', 'init', '-q', '--bare', '-b', 'main', str(tmp / 'o.git')], check=True)
            for name in ('a', 'b'):
                subprocess.run(['git', 'clone', '-q', str(tmp / 'o.git'), str(tmp / name)], check=True, capture_output=True)
                g(tmp / name, 'config', 'user.email', 't@example.invalid')
                g(tmp / name, 'config', 'user.name', 't')
            (tmp / 'a/f').write_text('1\n')
            g(tmp / 'a', 'add', 'f'); g(tmp / 'a', 'commit', '-qm', 'base'); g(tmp / 'a', 'push', '-q', 'origin', 'HEAD:main')
            g(tmp / 'b', 'pull', '-q', 'origin', 'main')
            (tmp / 'a/g').write_text('x\n')
            g(tmp / 'a', 'add', 'g'); g(tmp / 'a', 'commit', '-qm', 'race'); g(tmp / 'a', 'push', '-q', 'origin', 'HEAD:main')
            calls = []
            def fake(root, *a, **k):
                calls.append(1)
                (Path(root) / 'h').write_text('rec\n')
                return {'recorded': [1], 'refused': {}, 'files': ['h']}
            real = record.apply
            record.apply = fake
            try:
                out = record.record_and_push(tmp / 'b', 'x', [1], b'', 'Record', model='m', task_id='t')
            finally:
                record.apply = real
            self.assertTrue(out['pushed'])
            self.assertEqual(g(tmp / 'o.git', 'log', '--format=%s', 'main').split(), ['Record', 'race', 'base'])
            self.assertEqual(len(calls), 1)


if __name__ == '__main__':
    unittest.main()


class CarriedRecordTests(GateFixture, unittest.TestCase):
    """A record whose unit changed only in comments moves to the new text with its runs unchanged."""

    def setUp(self):
        super().setUp()
        (self.root / REVIEW).unlink()
        # The runs embed the v1 digest of the text they compared; the record's own digest is the v2 one.
        old = self.record['source']['digest']
        self.record['source'].update(digest_method=DIGEST_METHOD, digest=tu_digest(self.root, [CPP, HDR], DIGEST_METHOD),
                                     run_digest=old, run_digest_method='tu-sha256-v1')
        self.save_record()
        self.write('data/progress.json', json.dumps(self.data))
        self.write('builds/target.json', json.dumps(self.target))
        self.out = self.root / 'out'

    def carry(self):
        return record.build_carried_record(self.root, 'synthetic-fixture', self.fn['rva'], self.out, 'carried note')

    def test_a_provenance_only_edit_gives_a_record_the_validator_accepts_with_the_old_runs(self):
        old = json.loads((self.root / RECORD).read_text())
        self.write(HDR, '// SyntheticAddOne: OBSERVED; confirmed in the table\nint SyntheticAddOne(int);\n')
        made = self.carry()
        new = json.loads(made.read_text())
        self.assertEqual(new['runs'], old['runs'])
        self.assertEqual(new['source']['run_digest'], old['source']['run_digest'])
        self.assertEqual(new['source']['digest'], tu_digest(self.root, [CPP, HDR], DIGEST_METHOD))
        self.assertNotEqual(new['source']['digest'], old['source']['digest'])
        self.assertEqual(new['notes'], old['notes'] + ['carried note'])
        self.assertFalse(list((self.root / 'reports/synthetic-fixture').glob('.pr-*')))

    def test_a_record_that_binds_its_runs_to_the_current_digest_cannot_be_carried(self):
        self.record['source'].pop('run_digest')
        self.record['source'].pop('run_digest_method')
        self.save_record()
        with self.assertRaisesRegex(ValueError, 'cannot carry'):
            self.carry()

    def test_a_function_without_an_accepted_record_has_nothing_to_carry(self):
        self.fn['status'] = 'mapped'
        self.write('data/progress.json', json.dumps(self.data))
        with self.assertRaisesRegex(ValueError, 'accepted function'):
            self.carry()

    def test_a_changed_unit_closure_is_refused(self):
        self.write(CPP, '#include "SyntheticSum.h"\n#include "Extra.h"\nint SyntheticSum(int* p) { return SyntheticAddOne(*p); }\n')
        self.write('reconstruction/synthetic/Extra.h', '// extra\n')
        with self.assertRaisesRegex(ValueError, 'translation unit changed'):
            self.carry()
