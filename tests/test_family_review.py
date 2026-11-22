"""Family acceptance on original synthetic leaf functions and a real local git history.

Comparator reports come from compare(), never a fabricated pass. No game input or runner.
"""
import copy
import hashlib
import json
import os
from pathlib import Path
import struct
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import accept_function as af
import check
import family_review as fr
import build_leaderboard
from compare import compare
from source_digest import tu_digest
from test_match_gate import GateFixture, CPP, HDR, MAP, PIN, RECORD, REVIEW
import synthetic_pecoff as fx


def plan_family(root, spec_file):
    """Freeze a family spec the way a recorded family manifest looks, without the removed planner."""
    family = fr.read(root, spec_file)
    data, target = af.load(root)
    by_id = {fn['id']: fn for fn in data['functions']}
    first = family['first_members']
    family.update(family_schema=1, review=None, paused=False, pause_reason='')
    family['first_members'] = {}
    for fid in first:
        fn = by_id[fid]
        record = af.validate_match(fn, target, root)
        fr.check_member(family, fn, record)
        family['first_members'][fid] = fr.member_digest(fn, record)
    fr.validate_family(family, approved=False)
    path = f'reports/{target["build_id"]}/families/{fr.family_key(family)}.json'
    fr.write(root, path, family)
    return path


def approve_family(root, path, review_file):
    family = fr.read(root, path)
    doc = fr.read(root, review_file)
    family['review'] = {k: doc[k] for k in ('review_task_id', 'reviewer_model', 'profile', 'spec_sha256')}
    family['review']['review_sha256'] = hashlib.sha256(Path(review_file).read_bytes()).hexdigest()
    fr.validate_family(family)
    fr.write(root, path, family)


def plan_family_batch(root, family_path, name, seed, population):
    family = fr.read(root, family_path)
    data, target = af.load(root)
    by_id = {fn['id']: fn for fn in data['functions']}
    members = {}
    for fid in population:
        fn = by_id[fid]
        record = af.validate_match(fn, target, root)
        fr.check_member(family, fn, record, ranges=False)
        members[fid] = fr.member_digest(fn, record)
    path = f'reports/{target["build_id"]}/family-batches/{name}.json'
    fr.write(root, path, dict(batch_schema=1, family_path=family_path, family_sha256=fr.digest(fr.spec(family)),
                              seed=seed, population=sorted(population), members=members,
                              commitment=None, sample=None))
    return path


def draw_family_batch(root, path):
    batch = fr.read(root, path)
    batch.update(commitment=fr.git(root, 'rev-parse', 'HEAD'), sample=fr.draw(batch['seed'], batch['population']))
    fr.validate_batch(batch, fr.read(root, batch['family_path']))
    fr.write(root, path, batch)
    return batch


class FamilyReviewTests(GateFixture, unittest.TestCase):
    def setUp(self):
        super().setUp()
        (self.root / RECORD).unlink()
        (self.root / REVIEW).unlink()
        self.fdir = self.root / '.local/flow'
        self.write('.gitignore', '.local/\n')
        self.write('tools/synthetic_template.py', 'def emit(value):\n    return value\n')
        self.template = hashlib.sha256((self.root / 'tools/synthetic_template.py').read_bytes()).hexdigest()
        self.origin = dict(family='synthetic-leaf', version='1', template_digest=self.template)
        self.write(CPP, '#include "SyntheticSum.h"\n' + '\n'.join(
            f'int SyntheticLeaf{i}(int x) {{ return x + 1; }}' for i in range(41)) + '\n')
        unit = fx.Unit()
        for i in range(41):
            sec = unit.section('.text$mn', fx.CALLEE_CODE, fx.SCN_TEXT)
            unit.define(f'SyntheticLeaf{i}', sec, storage=fx.STORAGE_EXTERNAL, function=True)
        self.image = unit.link({})
        self.target['image_sha256'] = hashlib.sha256(self.image).hexdigest()
        placement = unit.default_placement()
        symbols = {f'SyntheticLeaf{i}': {'rva': placement[i + 1], 'size': len(fx.CALLEE_CODE)} for i in range(41)}
        symbol_map = {'schema': 1, 'build_id': 'synthetic-fixture', 'folds': [], 'symbols': symbols}
        self.write(MAP, json.dumps(symbol_map))
        self.data['functions'] = []
        self.records = {}
        for i in range(41):
            rva = placement[i + 1]
            fn = dict(id=f'synthetic-fixture-0x{rva:x}', build_id='synthetic-fixture', rva=rva,
                      size=len(fx.CALLEE_CODE), status='mapped', name=f'SyntheticLeaf{i}', name_origin='GUESS',
                      owner='test', evidence='findings/synthetic.md', report=f'reports/synthetic-fixture/0x{rva:x}.json')
            self.fn = fn
            self.data['functions'].append(fn)
            reports = []
            for stamp in (1, 2):
                obj = bytearray(unit.coff())
                struct.pack_into('<I', obj, 4, stamp)
                args = fx.inputs(obj=bytes(obj), image=self.image, recipe_bytes=self.recipe_bytes)
                args['symbol_map'] = (self.root / MAP).read_bytes()
                args['task'].update(rva=rva, size=fn['size'], symbol=fn['name'], source_path=CPP,
                                    source_revision=tu_digest(self.root, [CPP, HDR]))
                args['build_record'].update(source_path=CPP, source_revision=args['task']['source_revision'])
                reports.append(compare(**args))
            self.record = self.make_record(runs=[('host-a', 'host-a', reports[0]), ('host-b', 'host-b', reports[1])])
            self.record.update(origin=copy.deepcopy(self.origin), family_parameters={'width': 4}, name_source='GUESS(low)')
            self.record['build'] = self.build_block()
            self.records[fn['id']] = self.record
            fr.write(self.root, fn['report'], self.record)
        self.write('builds/target.json', json.dumps(self.target))
        self.save_data()
        self.first = [fn['id'] for fn in self.data['functions'][:20]]
        self.later = [fn['id'] for fn in self.data['functions'][20:]]
        self.approve_members(self.first, 'initial')
        sample_fn = self.data['functions'][0]
        self.family = dict(family_schema=1, origin=self.origin, binding=fr.binding(sample_fn, self.records[self.first[0]]),
                           template_source={'path': 'tools/synthetic_template.py', 'sha256': self.template},
                           parameter_source={'path': 'tools/synthetic_template.py', 'sha256': self.template},
                           parameter_ranges={'width': {'min': 1, 'max': 8}}, first_members=self.first,
                           review=None, paused=False, pause_reason='')
        fr.write(self.root, '.local/family-spec.json', self.family)
        self.family_path = plan_family(self.root, '.local/family-spec.json')
        self.family = fr.read(self.root, self.family_path)
        self.family_review_path = '.local/reviews/synthetic-family.family.json'
        self.family_doc = dict(family_review_schema=1, review_task_id='synthetic-family', reviewer_model='opus',
                               profile='cheap', spec_sha256=fr.digest(fr.spec(self.family)), fresh_context=True,
                               drafted_or_triaged=False, verdict='approve', escalation_category='none',
                               checks=dict.fromkeys(('plausible_source', 'provenance', 'claim_scope', 'publication_hygiene',
                                                     'parameter_extraction', 'target_binding', 'name_sources', 'first_20'), 'pass'))
        fr.write(self.root, self.family_review_path, self.family_doc)
        approve_family(self.root, self.family_path, self.root / self.family_review_path)
        self.family = fr.read(self.root, self.family_path)
        self.git('init', '--quiet', '-b', 'main')
        self.git('config', 'user.name', 'Synthetic')
        self.git('config', 'user.email', 'synthetic@example.invalid')
        self.commit('base')
        self.batch_path = plan_family_batch(self.root, self.family_path, 'synthetic-batch', 'synthetic-seed', self.later)
        self.commit('record seed and population')
        self.batch = draw_family_batch(self.root, self.batch_path)
        self.commit('record sample')
        self.unsampled = sorted(set(self.later) - set(self.batch['sample']))
        self.assertEqual(len(self.unsampled), 1)

    def test_individual_and_multi_review_acceptance_are_byte_identical(self):
        from datetime import datetime, timezone
        from test_acceptance_flow import review_text
        when = datetime(2000, 1, 3, tzinfo=timezone.utc)
        requests = []
        for i, fid in enumerate(self.later):
            fn = next(fn for fn in self.data['functions'] if fn['id'] == fid)
            review = self.root / f'.local/reviews/batch-{i}.md'
            review.write_text(review_text(f'batch-{i}', [dict(rva=fn['rva'], size=fn['size'],
                                                           digest=self.records[fid]['source']['digest'])]))
            requests.append(dict(review=str(review), functions=[fid]))
        tracked = self.git('ls-files').splitlines()
        before = {name: (self.root / name).read_bytes() for name in tracked}
        # The old path invokes a complete acceptance transaction for each function, uncached.
        with patch.object(check, 'include_closure', __import__('source_digest').include_closure):
            for request in requests:
                af.accept_many(self.root, request['review'], select=set(request['functions']), when=when)
        paths = set(tracked) | {p.relative_to(self.root).as_posix()
                               for p in (self.root / 'reports').rglob('*.json')}
        expected = {name: (self.root / name).read_bytes() for name in paths}
        for name in paths:
            if name in before:
                (self.root / name).write_bytes(before[name])
            else:
                (self.root / name).unlink()
        with patch.object(af, 'write_index', wraps=af.write_index) as index, \
                patch.object(af, 'validate_review', wraps=af.validate_review) as review_check:
            changed, skipped = af.accept_reviews(self.root, requests, when=when)
        self.assertEqual(index.call_count, 1)
        self.assertEqual(review_check.call_count, len(requests))
        self.assertEqual(skipped, [])
        self.assertEqual(sum(p.endswith('.review.json') for p in changed), len(requests))
        self.assertEqual(expected, {name: (self.root / name).read_bytes() for name in paths})
        check.validate(fr.read(self.root, 'data/progress.json'), self.target, self.root)

    def test_multi_review_failure_restores_every_tracked_file(self):
        from test_acceptance_flow import review_text
        requests = []
        for i, fid in enumerate(self.later[:2]):
            fn = next(fn for fn in self.data['functions'] if fn['id'] == fid)
            review = self.root / f'.local/reviews/batch-{i}.md'
            review.write_text(review_text(f'batch-{i}', [dict(rva=fn['rva'], size=fn['size'],
                                                           digest=self.records[fid]['source']['digest'])]))
            requests.append(dict(review=str(review), functions=[fid]))
        before = {name: (self.root / name).read_bytes() for name in self.git('ls-files').splitlines()}
        with patch.object(af, 'write_index', side_effect=OSError('synthetic index failure')):
            with self.assertRaisesRegex(OSError, 'synthetic index failure'):
                af.accept_reviews(self.root, requests)
        self.assertEqual(before, {name: (self.root / name).read_bytes() for name in before})
        for fid in self.later[:2]:
            fn = next(fn for fn in self.data['functions'] if fn['id'] == fid)
            self.assertFalse((self.root / check.review_record_path(fn)).exists())

    def git(self, *args):
        return subprocess.check_output(['git', *args], cwd=self.root, stderr=subprocess.PIPE, text=True).strip()

    def commit(self, message):
        self.git('add', '--all')
        self.git('commit', '--quiet', '-m', message)

    def save_data(self):
        fr.write(self.root, 'data/progress.json', self.data)

    def reload_data(self):
        self.data = fr.read(self.root, 'data/progress.json')

    def approve_members(self, ids, name):
        fns = [fn for fn in self.data['functions'] if fn['id'] in ids]
        for second in (False, True):
            task = name + ('-s' if second else '')
            text = (f'# Review {task}\n\nreviewer_model: opus\nfresh_context: yes\n'
                    'drafted_or_triaged_any_reviewed_function: no\ngates_in_force: G2\nsource_revision: synthetic\n'
                    f'sampling_second_pass: {"yes" if second else "no"}\ndecompiler_output_read: no\n')
            for fn in fns:
                text += (f'\n## {fn["build_id"]} 0x{fn["rva"]:x} {fn["size"]}\n\nverdict: approve\n'
                         f'escalation_category: none\nsource_paths: {CPP} {HDR}\n'
                         f'source_digest: {self.records[fn["id"]]["source"]["digest"]}\nreport_path: {fn["report"]}\n'
                         'report_binding: agree\nchecks:\n  plausible_source: pass\n  provenance: pass\n'
                         '  claim_scope: pass\n  publication_hygiene: pass\nblocking_findings: none\n'
                         'naming_findings: none\nreasons: Original synthetic fixture.\n')
            self.write(f'.local/reviews/{task}.md', text)
        af.accept_many(self.root, self.root / f'.local/reviews/{name}.md')
        self.reload_data()

    def accept_batch(self):
        """Write the state a family acceptance leaves behind: unsampled members matched with a family review."""
        data, target = af.load(self.root)
        family, batch = fr.read(self.root, self.family_path), fr.read(self.root, self.batch_path)
        index = {fn['id']: i for i, fn in enumerate(data['functions'])}
        prepared, new = [], af.planned_inventory(self.root, data, [index[f] for f in self.unsampled], False)
        for fid in self.unsampled:
            fn = data['functions'][index[fid]]
            rec = af.validate_match(fn, target, self.root)
            rv = af.review_record(fn, rec, family['review'], family['review']['review_task_id'], b'',
                                  af.now_utc(), 'family', ['Family approval does not assess individual names.'])
            rv.update(review_record_schema=4, review_sha256=family['review']['review_sha256'],
                      family_evidence={'family_path': self.family_path, 'batch_path': self.batch_path,
                                       'batch_sha256': fr.digest(batch), 'member_sha256': fr.member_digest(fn, rec)})
            prepared.append((index[fid], fn, rec, rv))
            new['functions'][index[fid]]['status'] = 'matched'
            af.set_named(new['functions'], index[fid], False)
        return af.apply(self.root, data, new, target, prepared, af.stale_ids(self.root, data) - set(self.unsampled),
                        af.now_utc())

    def ready(self):
        self.approve_members(self.batch['sample'], 'sample')
        self.commit('accept independently reviewed sample')

    def public_review_inputs(self):
        self.ready()
        self.accept_batch()
        self.reload_data()
        fn = next(fn for fn in self.data['functions'] if fn['id'] == self.unsampled[0])
        return fn, self.records[fn['id']], fr.read(self.root, check.review_record_path(fn))

    def test_public_metadata_validation_reuses_only_exact_contents(self):
        fn, record, review = self.public_review_inputs()
        fr._public_family_batch.cache_clear()
        with patch.object(fr, 'validate_family', wraps=fr.validate_family) as family_check, \
                patch.object(fr, 'validate_batch', wraps=fr.validate_batch) as batch_check, \
                patch.object(fr, 'check_member', wraps=fr.check_member) as member_check:
            for _ in range(2):
                fr.validate_public_review(self.root, fn, record, review)
            self.assertEqual(family_check.call_count, 1)
            self.assertEqual(batch_check.call_count, 1)
            self.assertEqual(member_check.call_count, 2)
        self.assertEqual(fr._public_family_batch.cache_info().maxsize, 256)

    def test_public_cache_rereads_same_size_same_mtime_changed_batch(self):
        fn, record, review = self.public_review_inputs()
        fr.validate_public_review(self.root, fn, record, review)
        path = self.root / self.batch_path
        before, stat = path.read_bytes(), path.stat()
        batch = copy.deepcopy(self.batch)
        batch['members'][fn['id']] = '0' * 64
        fr.write(self.root, self.batch_path, batch)
        self.assertEqual(len(path.read_bytes()), len(before))
        os.utime(path, ns=(stat.st_atime_ns, stat.st_mtime_ns))
        with self.assertRaisesRegex(ValueError, 'member differs from committed population'):
            fr.validate_public_review(self.root, fn, record, review)

    def test_public_cache_keeps_all_member_and_review_bindings(self):
        fn, record, review = self.public_review_inputs()
        fr.validate_public_review(self.root, fn, record, review)
        changed_record = copy.deepcopy(record)
        changed_record['family_parameters']['width'] = 5
        with self.assertRaisesRegex(ValueError, 'member differs from committed population'):
            fr.validate_public_review(self.root, fn, changed_record, review)
        changed_review = copy.deepcopy(review)
        changed_review['family_evidence']['member_sha256'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'sanitized family evidence digest mismatch'):
            fr.validate_public_review(self.root, fn, record, changed_review)
        changed_review = copy.deepcopy(review)
        changed_review['review_sha256'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'sanitized record names another family review'):
            fr.validate_public_review(self.root, fn, record, changed_review)

    def test_public_cache_does_not_hide_duplicate_fields_or_changed_paths(self):
        fn, record, review = self.public_review_inputs()
        fr.validate_public_review(self.root, fn, record, review)
        other_path = str(Path(self.family_path).with_name('other.json'))
        self.write(other_path, (self.root / self.family_path).read_text())
        changed_review = copy.deepcopy(review)
        changed_review['family_evidence']['family_path'] = other_path
        with self.assertRaisesRegex(ValueError, 'batch names another family'):
            fr.validate_public_review(self.root, fn, record, changed_review)
        path = self.root / self.batch_path
        path.write_text(path.read_text().replace('{', '{"batch_schema": 1,', 1))
        with self.assertRaisesRegex(ValueError, 'duplicate JSON field'):
            fr.validate_public_review(self.root, fn, record, review)

    def exact_row_audit_family(self, rows=None):
        family = copy.deepcopy(self.family)
        family.update(parameter_ranges=fr.exact_ranges(rows or [{'width': 4}]), review=None)
        fr.write(self.root, self.family_path, family)
        return family

    def test_family_packet_audits_every_row_and_is_read_only(self):
        import review_packet
        self.exact_row_audit_family()
        paths = [self.family_path, 'data/progress.json', self.data['functions'][0]['report']]
        before = {p: (self.root / p).read_bytes() for p in paths}
        result = '\n'.join(review_packet.family_rows(self.root, self.family_path))
        self.assertIn('permitted rows checked: 1/1; current reproduced members: 41', result)
        self.assertIn('does not re-extract target references', result)
        self.assertEqual(before, {p: (self.root / p).read_bytes() for p in paths})

    def test_family_packet_refuses_unrepresented_rows_and_changed_first_members(self):
        import review_packet
        self.exact_row_audit_family([{'width': 4}, {'width': 5}])
        with self.assertRaisesRegex(ValueError, '1 permitted row.*lack'):
            review_packet.family_rows(self.root, self.family_path)
        family = self.exact_row_audit_family()
        family['first_members'][self.first[0]] = '0' * 64
        fr.write(self.root, self.family_path, family)
        with self.assertRaisesRegex(ValueError, 'frozen first-20 member binding changed'):
            review_packet.family_rows(self.root, self.family_path)

    def test_family_packet_refuses_wrong_parameter_rva_and_stale_source(self):
        import review_packet
        family = copy.deepcopy(self.family)
        for fn in self.data['functions']:
            rec = self.records[fn['id']]
            rec['family_parameters'] = {'entry-rva': fn['rva'], 'size': fn['size']}
        self.records[self.later[-1]]['family_parameters']['entry-rva'] += 1
        for fn in self.data['functions']:
            fr.write(self.root, fn['report'], self.records[fn['id']])
        family.update(review=None, parameter_ranges=fr.exact_ranges(
            [r['family_parameters'] for r in self.records.values()]))
        family['first_members'] = {fn['id']: fr.member_digest(fn, self.records[fn['id']])
                                   for fn in self.data['functions'] if fn['id'] in self.first}
        fr.write(self.root, self.family_path, family)
        with self.assertRaisesRegex(ValueError, 'parameter entry-rva disagrees with inventory'):
            review_packet.family_rows(self.root, self.family_path)
        with (self.root / CPP).open('a') as out:
            out.write('// Changed fixture source.\n')
        with self.assertRaisesRegex(ValueError, 'stale'):
            review_packet.family_rows(self.root, self.family_path)

    def test_binding_change_starts_new_family(self):
        fn = self.data['functions'][-1]
        for field in ('build_id', 'image_sha256', 'recipe_sha256', 'compiler', 'toolchain_sha256', 'comparator'):
            with self.subTest(field=field):
                family = copy.deepcopy(self.family)
                family['binding'][field] = 'different'
                with self.assertRaisesRegex(ValueError, 'binding mismatch'):
                    fr.check_member(family, fn, self.records[fn['id']])

    def test_no_range_exemption_for_wrong_parameter_type(self):
        self.assertFalse(fr.in_ranges({'width': True}, self.family['parameter_ranges']))
        self.assertFalse(fr.in_ranges({'width': '4'}, self.family['parameter_ranges']))
        self.assertFalse(fr.in_ranges({}, self.family['parameter_ranges']))
        self.assertFalse(fr.in_ranges({'width': 4, 'other': 1}, self.family['parameter_ranges']))
        self.assertTrue(fr.in_ranges({'virtual': True}, {'virtual': {'values': [True]}}))
        self.assertFalse(fr.in_ranges({'virtual': 1}, {'virtual': {'values': [True]}}))

    def combined_sample_inputs(self):
        def public():
            return {p: p.read_bytes() for p in self.root.rglob('*') if p.is_file()
                    and not {'.git', '.local'} & set(p.relative_to(self.root).parts)}
        def restore(before):
            for p in set(public()) - set(before):
                p.unlink()
            for p, blob in before.items():
                p.write_bytes(blob)
        before = public()
        self.approve_members(self.batch['sample'], 'sample')
        restore(before)
        self.reload_data()
        requests = [dict(kind='family', path=self.batch_path, functions=self.unsampled, profile='cheap'),
                    dict(kind='review', review=str(self.root / '.local/reviews/sample.md'),
                         functions=list(self.batch['sample']), profile='cheap')]
        return requests, before, public, restore

    def test_supersession_rejects_partial_source_version_or_other_family(self):
        for changes in ({'version': '2'}, {'template_digest': 'f' * 64},
                        {'family': 'another-family', 'version': '2', 'template_digest': 'f' * 64}):
            replacement = copy.deepcopy(self.family)
            replacement['origin'].update(changes)
            with self.assertRaises(ValueError):
                fr.supersession_binding(self.family, replacement)

    def test_draw_size_and_reproducibility(self):
        for n, count in ((1, 1), (19, 19), (20, 20), (21, 20), (1000, 50), (1001, 51)):
            population = [f'synthetic-{i}' for i in range(n)]
            self.assertEqual(len(fr.draw('seed', population)), count)
            self.assertEqual(fr.draw('seed', population), fr.draw('seed', list(reversed(population))))

    def test_family_record_cannot_be_relabelled_without_family_gate(self):
        self.ready()
        self.accept_batch()
        self.reload_data()
        fn = next(fn for fn in self.data['functions'] if fn['id'] == self.unsampled[0])
        rv = fr.read(self.root, check.review_record_path(fn))
        rv['family_evidence']['batch_sha256'] = 'a' * 64
        fr.write(self.root, check.review_record_path(fn), rv)
        with self.assertRaisesRegex(ValueError, 'evidence digest mismatch'):
            check.validate(self.data, self.target, self.root)


if __name__ == '__main__':
    unittest.main()


class ExactParameterRowsTests(unittest.TestCase):
    def test_preserves_correlated_rows_and_types(self):
        a = {'width': 1, 'value': 2, 'virtual': True}
        b = {'width': 4, 'value': 1000, 'virtual': True}
        ranges = fr.exact_ranges([a, b, a])
        self.assertEqual(len(ranges['rows']), 2)
        for row in (a, b):
            self.assertTrue(fr.in_ranges(row, ranges))
        for row in ({'width': 1, 'value': 1000, 'virtual': True},
                    {'width': 4, 'value': 2, 'virtual': True},
                    {'width': 1, 'value': 2, 'virtual': 1},
                    {'width': 1, 'value': 2},
                    {'width': 1, 'value': 2, 'virtual': True, 'extra': 0}):
            self.assertFalse(fr.in_ranges(row, ranges))

    def test_refuses_invalid_or_duplicate_rows(self):
        for rows in ([], [{}], [{'x': 1}, {'y': 1}], [{'x': 1}, {'x': 1}], [{'x': None}]):
            with self.subTest(rows=rows), self.assertRaises(ValueError):
                fr.validate_ranges({'rows': rows})
