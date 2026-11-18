"""Contributor preflight and readiness regressions; original synthetic inputs only."""
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import contrib
import contrib_readiness
import contrib_validation
import test_contrib as fixtures
import test_match_gate as gate
from source_digest import include_closure
from digest_v2 import tu_digest


class Preflight(fixtures.SubmitTests):
    def refresh_digest(self):
        self.summary['source_revision'] = tu_digest(self.repo, include_closure(self.repo, self.unit[1]))
        self.write()

    def preflight(self, *flags):
        ctx = self.ctx(repo=self.repo, github=fixtures.FakeGitHub(), runner=self.runner)
        with contextlib.redirect_stdout(io.StringIO()) as output:
            code = contrib.main(['--json', 'preflight', '--base', 'HEAD', *flags], ctx=ctx)
        return code, json.loads(output.getvalue())

    def test_private_decompiler_marker_is_blocked_by_shared_preflight_and_submit(self):
        cpp = self.repo / self.unit[1]
        cpp.write_text(cpp.read_text() + '\n// PRIVATE DECOMPILER HINT: synthetic fixture\n')
        self.refresh_digest()
        for code, result in (self.preflight(), self.submit()):
            self.assertEqual(code, contrib.FAILED)
            self.assertTrue(any('private decompiler output/project' in p for p in result['blockers']))

    def test_missing_origin_is_found_before_submission_like_59(self):
        cpp = self.repo / self.unit[1]
        cpp.write_text('\n'.join(line for line in cpp.read_text().splitlines() if 'Code origin:' not in line) + '\n')
        self.refresh_digest()
        code, result = self.preflight()
        self.assertEqual(code, contrib.FAILED)
        finding = next(p for p in result['blockers'] if 'missing reconstruction origin' in p)
        self.assertIn(self.unit[1] + ':1:', finding)
        self.assertIn('fix: add a truthful Code origin:', finding)
        _code, submit = self.submit()
        self.assertIn(finding, submit['blockers'])

    def test_parent_include_gets_the_same_screen_as_intake_like_72(self):
        cpp = self.repo / self.unit[1]
        cpp.write_text(cpp.read_text().replace('"TESActorBaseData.h"', '"../forms/TESActorBaseData.h"'))
        self.refresh_digest()
        _code, result = self.preflight()
        finding = next(p for p in result['blockers'] if 'path-or-encoded-escape' in p)
        line = next(i for i, text in enumerate(cpp.read_text().splitlines(), 1) if '#include' in text)
        self.assertIn(f'{self.unit[1]}:{line}:', finding)
        self.assertIn('fix:', finding)
        self.git('add', *self.unit)
        tree = self.git('write-tree').strip()
        immutable = contrib.intake_problems(self.ctx(repo=self.repo), 'HEAD', tree,
                                          [('M', name) for name in self.unit])
        self.assertIn(finding, immutable)

    def test_repaired_tip_screens_as_squash_but_retained_history_still_fails(self):
        cpp = self.repo / self.unit[1]
        original = cpp.read_text()
        cpp.write_text(original + '\n#pragma comment(lib, "Synthetic")\n')
        self.git('add', *self.unit)
        self.git('commit', '-q', '-m', 'synthetic refused ancestor')
        base = self.git('rev-parse', 'HEAD~1').strip()
        cpp.write_text(original)
        self.refresh_digest()
        ctx = self.ctx(repo=self.repo)
        rows = [('M', name) for name in self.unit]
        self.assertEqual(contrib_validation.publication_problems(ctx, base, rows), [])
        retained = contrib_validation.publication_problems(ctx, base, rows, merge_method='merge')
        self.assertTrue(any('unsafe-pragma' in problem for problem in retained))

    def test_staged_preflight_checks_index_not_the_repaired_working_file(self):
        cpp = self.repo / self.unit[1]
        original = cpp.read_text()
        cpp.write_text(original + '\n#pragma comment(lib, "Synthetic")\n')
        self.git('add', *self.unit)
        cpp.write_text(original)
        code, result = self.preflight('--staged')
        self.assertEqual(code, contrib.FAILED)
        self.assertTrue(any('unsafe-pragma' in p for p in result['blockers']))
        self.assertEqual(self.preflight()[0], contrib.OK)

    def test_transitive_unchanged_header_is_screened(self):
        helper = self.repo / 'reconstruction/other/Helper.h'
        helper.parent.mkdir()
        helper.write_text('#pragma comment(lib, "Synthetic")\n')
        cpp = self.repo / self.unit[1]
        cpp.write_text(cpp.read_text() + '\n#include "other/Helper.h"\n')
        self.assertTrue(any('reconstruction/other/Helper.h:1:' in p and 'unsafe-pragma' in p
                            for p in self.preflight()[1]['blockers']))

    def test_stale_accepted_companion_is_project_work_like_72(self):
        report = 'reports/synthetic/companion.json'
        (self.repo / report).parent.mkdir(parents=True)
        (self.repo / report).write_text(json.dumps({'source': {
            'compiled': self.unit[1], 'translation_unit': self.unit, 'digest': '0' * 64}}))
        (self.repo / 'data').mkdir()
        (self.repo / 'data/progress.json').write_text(json.dumps({'functions': [{
            'rva': 0x2000, 'status': 'matched', 'report': report}]}))
        code, result = self.submit()
        self.assertEqual((code, result['blockers']), (contrib.OK, []))
        self.assertEqual(result['project_reconfirmation'][0]['rva'], '0x2000')
        self.assertEqual(result['project_reconfirmation'][0]['status'],
                         'project re-confirmation needed (no action for you)')
        self.assertEqual(self.preflight()[1]['project_reconfirmation'], result['project_reconfirmation'])
        # The record was only identified; neither it nor the inventory was repaired by submission.
        self.assertEqual(json.loads((self.repo / report).read_text())['source']['digest'], '0' * 64)

    def test_origin_placeholder_cannot_pass_readiness(self):
        cpp = self.repo / self.unit[1]
        cpp.write_text(cpp.read_text().replace('original synthetic fixture', 'SKELETON_TODO_CODE_ORIGIN'))
        self.assertTrue(any('SKELETON_TODO_CODE_ORIGIN' in p for p in self.preflight()[1]['blockers']))

    def test_readiness_lint_runs_without_requiring_a_comparison_or_fork(self):
        (self.tdir / 'last-compare.json').unlink()
        self.git('remote', 'remove', 'fork')
        self.assertEqual(self.preflight()[0], contrib.OK)

    def test_extension_headers_are_prefilled_per_function_without_inventing_origin(self):
        fn = next(f for f in contrib.inventory(ROOT)['functions'] if f['rva'] == self.RVA)
        extra = dict(fn, id='synthetic-extra', rva=self.RVA + 0x1000,
                     name='TESActorBaseData::GetSynthetic', size=4, status='mapped')
        source = self.repo / self.unit[1]
        (self.repo / 'reports' / fixtures.TARGET['build_id']).mkdir(parents=True)
        (self.repo / 'reports' / fixtures.TARGET['build_id'] / 'symbol-map.json').write_text('{"symbols": {}}')
        ctx = self.ctx(repo=self.repo)
        self.task['functions'][0]['pack'] = str(self.tmp / 'older-pack')
        self.write()
        args = contrib.parser().parse_args(['start', hex(extra['rva']), '--no-branch', '--drafted-by', 'synthetic model'])
        with patch.object(contrib, 'inventory', return_value={'functions': [extra]}), \
                patch.object(contrib, 'require_exe', return_value={'path': 'synthetic-local-input'}), \
                patch.object(contrib, 'public_names', return_value={}), \
                patch.object(contrib, 'write_pack', return_value=(self.tmp / 'pack', {})), \
                patch.object(contrib, 'refresh_symbols'), patch.object(contrib, 'sibling_section', return_value=[]):
            contrib.start(ctx, args)
        header = source.read_text().split('#include', 1)[0]
        for text in (f'// {hex(extra["rva"])} ', 'SKELETON_TODO_CODE_ORIGIN'):
            self.assertIn(text, header)
        for text in (extra['build_id'], extra['evidence'], contrib.DEFAULT_RECIPE, 'Drafted by', '4 bytes'):
            self.assertNotIn(text, header)  # the short header leaves out what the records hold
        self.assertIn('original synthetic fixture', header)  # the older declaration was preserved


class AcceptanceIsUnchanged(gate.GateFixture, unittest.TestCase):
    def test_stale_source_still_fails_the_acceptance_gate(self):
        self.write(gate.CPP, (self.root / gate.CPP).read_text() + '\n// Synthetic extension\n')
        with self.assertRaisesRegex(ValueError, 'source digest is stale'):
            gate.validate_match(self.fn, self.target, self.root)


class Ranking(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        unit = self.root / 'reconstruction/forms'
        unit.mkdir(parents=True)
        (unit / 'TESReady.cpp').write_text('#include "TESReady.h"\n')
        (unit / 'TESReady.h').write_text('class TESReady {\npublic:\n int GetValue() const;\n bool HasFlag(int mask);\n virtual ~TESReady();\n};\n')
        self.data = {'functions': [self.fn(0x1000, 'TESNew::Work', 3),
                                   self.fn(0x2000, 'TESReady::GetValue', 32),
                                   self.fn(0x3000, 'TESReady::~TESReady', 3),
                                   self.fn(0x4000, 'TESReady::HasFlag', 12)]}

    def fn(self, rva, name, size):
        return dict(rva=rva, name=name, size=size, status='mapped', name_origin='GUESS')

    def test_existing_usable_accessor_beats_smaller_new_class_and_destructor(self):
        rows = contrib.candidates(self.root, self.data)
        self.assertEqual([r['rva'] for r in rows], ['0x4000', '0x2000', '0x1000', '0x3000'])
        self.assertTrue(rows[0]['unit_exists'])
        self.assertIn('usable declaration', rows[0]['reason'])
        self.assertIn('ABI preparation', rows[-1]['reason'])

    def test_local_eh_unsupported_and_parked_facts_deprioritize(self):
        for fact, text in [({'eh': {'handler_kind': 'c++'}}, 'exception-handling'),
                           ({'v2': {'verdict': 'unsupported'}}, 'unsupported'),
                           ({'parked': True}, 'parked'), ({'kind': 'thunk'}, 'thunk')]:
            with self.subTest(fact=fact):
                rows = contrib.candidates(self.root, self.data, readiness_facts={0x4000: fact})
                risky = next(row for row in rows if row['rva'] == '0x4000')
                self.assertEqual(rows[0]['rva'], '0x2000')
                self.assertIn(text, risky['reason'])
                self.assertTrue(risky['cautions'])

    def test_claimed_rvas_never_reappear_and_size_cap_remains(self):
        rows = contrib.candidates(self.root, self.data, claimed={0x4000}, max_size=16)
        self.assertEqual({r['rva'] for r in rows}, {'0x1000', '0x3000'})

    def test_next_excludes_live_foreign_claim_before_recommending(self):
        data = dict(self.data, target_build_id='synthetic')
        data['functions'] = [dict(f, build_id='synthetic') for f in data['functions']]
        gh = fixtures.FakeGitHub({0x4000: [fixtures.item('someone', 0)]})
        ctx = contrib.Ctx(repo=self.root, private=self.root / '.local/contrib', github=gh, as_json=True)
        with patch.object(contrib, 'inventory', return_value=data):
            _code, result, _next = contrib.cmd_next(ctx, contrib.parser().parse_args(['next']))
        self.assertNotIn('0x4000', [r['rva'] for r in result['candidates']])
        self.assertTrue(result['claims_checked'])
        self.assertTrue(all(r['reason'] for r in result['candidates']))

    def test_placeholder_declarations_are_not_promoted(self):
        header = self.root / 'reconstruction/forms/TESReady.h'
        header.write_text('// Placeholder signature: replace types\n' + header.read_text())
        row = next(r for r in contrib.candidates(self.root, self.data) if r['rva'] == '0x4000')
        self.assertIn('needs preparation', row['reason'])

    def test_existing_header_that_intake_would_refuse_is_flagged(self):
        header = self.root / 'reconstruction/forms/TESReady.h'
        header.write_text('#include "../other/Base.h"\n' + header.read_text())
        row = next(r for r in contrib.candidates(self.root, self.data) if r['rva'] == '0x4000')
        self.assertIn('contributor-screen preparation', row['reason'])
        self.assertEqual(row['readiness_rank'], 4)

    def test_local_exporter_table_is_pinned_and_stays_local(self):
        directory = self.root / '.local/table'
        directory.mkdir(parents=True)
        (directory / 'table-meta.json').write_text(json.dumps({'build_id': 'synthetic',
                                                              'inputs': {'image_sha256': 'a' * 64}}))
        (directory / 'functions.jsonl').write_text(json.dumps({'rva': 0x4000, 'kind': 'ordinary'}) + '\n')
        self.assertEqual(contrib_readiness.local_facts(directory, 'synthetic', 'a' * 64)[0x4000]['kind'], 'ordinary')
        with self.assertRaisesRegex(ValueError, 'build_id'):
            contrib_readiness.local_facts(directory, 'different', 'a' * 64)
        with self.assertRaisesRegex(ValueError, 'image hash'):
            contrib_readiness.local_facts(directory, 'synthetic', 'b' * 64)


if __name__ == '__main__':
    unittest.main()
