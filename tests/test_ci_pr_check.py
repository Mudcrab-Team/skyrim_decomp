"""The pr-check.yml `hash` job as the CI host of the match gate, on original synthetic fixtures."""
import copy
from pathlib import Path
import subprocess
import sys
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import check  # noqa: E402
import record as record_tool  # noqa: E402
import ci_confirmation as c  # noqa: E402
from test_match_gate import GateFixture, MAP, PIN  # noqa: E402

HEAD = 'b' * 40


class PrCheckEvidence(GateFixture, unittest.TestCase):
    def setUp(self):
        super().setUp()
        self.record['runs'] = self.record['runs'][:1]
        self.record['runs'][0].update(compiled_on='mac-wine', compared_on='mac-wine')
        self.record['build']['hosts'] = {'mac-wine': next(iter(self.record['build']['hosts'].values()))}
        self.row = dict(rva=self.fn['rva'], size=self.fn['size'], extraction='linked-reference-inference',
                        normalized_sha256='1' * 64, layout_sha256='2' * 64)
        self.manifest = dict(build_id=self.target['build_id'], functions=[self.row])
        patcher = patch.object(c.target_hashes, 'load_manifest', return_value=self.manifest)
        patcher.start()
        self.addCleanup(patcher.stop)
        # The fixture's reports embed a v1 revision, so the record assembled from them is v1 too.
        extra = patch.object(record_tool, 'DIGEST_METHOD', 'tu-sha256-v1')
        extra.start()
        self.addCleanup(extra.stop)

        def git(*args):
            return subprocess.run(['git', *args], cwd=self.root, check=True, capture_output=True).stdout.decode().strip()
        git('init', '-q')
        git('config', 'user.email', 'test@example.invalid')
        git('config', 'user.name', 'Test')
        git('add', '.')
        git('commit', '-qm', 'fixture')
        self.base = git('rev-parse', 'HEAD')
        self.run_info = dict(run_id=4242, run_attempt=1, head_sha=HEAD, event='pull_request', conclusion='success')
        self.report = dict(head_sha=HEAD, base_sha=self.base, toolset='MATCH',
                           compiler_pins_sha256=c.sha((self.root / PIN).read_bytes()))
        self.ci_row = dict(rva=hex(self.fn['rva']), unit=self.record['source']['compiled'], result='hash-match',
                           status='pass', symbols=[self.record['runs'][0]['report']['function']['symbol']],
                           source_sha256=self.record['source']['digest'],
                           recipe_sha256=self.record['recipe']['sha256'])
        self.first = dict(host_id='mac-wine', machine='maintainer-mac', loader='wine', os='macos')
        self.install()

    def evidence(self, **changes):
        args = dict(run=self.run_info, report=self.report, row=self.ci_row, map_status='pass', first_host=self.first)
        args.update(changes)
        return c.pr_check_evidence(self.root, **args)

    def install(self):
        self.record['ci_confirmation'] = self.evidence()
        self.save_record()

    def test_status_map_pass_bound_to_run_head_and_source_is_the_second_host(self):
        check.validate_match(self.fn, self.target, root=self.root)
        ci = self.record['ci_confirmation']
        self.assertEqual((ci['run_id'], ci['head_sha'], ci['schema']), (4242, HEAD, 2))

    def test_every_field_fails_closed_when_blanked(self):
        original = copy.deepcopy(self.record)
        for key in original['ci_confirmation']:
            with self.subTest(key=key):
                self.record = copy.deepcopy(original)
                self.record['ci_confirmation'][key] = None
                self.save_record()
                with self.assertRaises((ValueError, TypeError, KeyError)):
                    check.validate_match(self.fn, self.target, root=self.root)

    def test_evidence_for_other_source_or_recipe_is_refused(self):
        for key in ('source_sha256', 'recipe_sha256'):
            with self.subTest(key=key):
                self.record['ci_confirmation'][key] = '9' * 64
                self.save_record()
                with self.assertRaisesRegex(ValueError, 'source or recipe differs'):
                    check.validate_match(self.fn, self.target, root=self.root)
                self.install()

    def test_builder_refuses_anything_but_a_pass_on_the_reviewed_head(self):
        for status in ('fail', 'regressed', 'preexisting-fail', 'unverified', None):
            with self.subTest(status=status):
                with self.assertRaisesRegex(ValueError, 'did not pass'):
                    self.evidence(map_status=status)
        with self.assertRaisesRegex(ValueError, 'did not pass'):
            self.evidence(row=dict(self.ci_row, status='fail'))
        with self.assertRaisesRegex(ValueError, 'another revision'):
            self.evidence(report=dict(self.report, head_sha='c' * 40))
        with self.assertRaisesRegex(ValueError, 'verified toolset'):
            self.evidence(report=dict(self.report, error='ValueError'))
        with self.assertRaisesRegex(ValueError, 'verified toolset'):
            self.evidence(report=dict(self.report, toolset='MISMATCH'))

    def test_ci_must_have_matched_the_function_the_first_host_compared(self):
        self.record['ci_confirmation']['symbols'] = ['?OtherFunction@@YAXXZ']
        self.save_record()
        with self.assertRaisesRegex(ValueError, 'another function'):
            check.validate_match(self.fn, self.target, root=self.root)
        symbol = self.record['runs'][0]['report']['function']['symbol']
        self.record['ci_confirmation']['symbols'] = ['?OtherFunction@@YAXXZ', symbol]
        self.save_record()
        check.validate_match(self.fn, self.target, root=self.root)
        with self.assertRaisesRegex(ValueError, 'names no matching function'):
            self.evidence(row=dict(self.ci_row, symbols=[]))

    def test_failed_job_and_other_workflow_are_refused(self):
        for key, value in (('conclusion', 'failure'), ('workflow', c.WORKFLOW), ('event', 'workflow_dispatch'),
                           ('job', 'scope'), ('run_id', 0), ('run_attempt', 0), ('head_sha', self.base)):
            with self.subTest(key=key):
                self.record['ci_confirmation'][key] = value
                self.save_record()
                with self.assertRaises(ValueError):
                    check.validate_match(self.fn, self.target, root=self.root)
                self.install()

    def test_ci_host_cannot_also_be_the_first_host(self):
        self.record['ci_confirmation']['first_host'] = dict(c.CI_HOST)
        self.record['runs'][0].update(compiled_on=c.CI_HOST['host_id'], compared_on=c.CI_HOST['host_id'])
        self.record['build']['hosts'] = {c.CI_HOST['host_id']: next(iter(self.record['build']['hosts'].values()))}
        self.save_record()
        with self.assertRaises(ValueError):
            check.validate_match(self.fn, self.target, root=self.root)

    def test_a_record_with_only_the_first_host_is_still_refused(self):
        del self.record['ci_confirmation']
        self.save_record()
        with self.assertRaisesRegex(ValueError, 'at least'):
            check.validate_match(self.fn, self.target, root=self.root)

    def test_target_and_toolchain_must_match_the_published_commitment(self):
        self.manifest['functions'] = [dict(self.row, normalized_sha256='3' * 64)]
        with self.assertRaisesRegex(ValueError, 'target binding differs'):
            check.validate_match(self.fn, self.target, root=self.root)
        self.manifest['functions'] = [self.row]
        self.write(PIN, (self.root / PIN).read_text() + '0' * 64 + ' extra.exe\n')
        with self.assertRaisesRegex(ValueError, 'compiler pins differ|pin'):
            check.validate_match(self.fn, self.target, root=self.root)

    def test_tools_revision_must_be_an_ancestor(self):
        self.record['ci_confirmation']['base_sha'] = 'f' * 40
        self.save_record()
        with self.assertRaisesRegex(ValueError, 'not an ancestor'):
            check.validate_match(self.fn, self.target, root=self.root)

    def test_assembled_record_from_both_hosts_validates_and_carries_no_object_or_diagnostics(self):
        rec = self.record
        task = dict(build_id=self.target['build_id'], recipe=rec['recipe']['path'], symbols_repo=MAP,
                    symbols_local=self.root / MAP, record_notes=['a public note'])
        unit = dict(closure=rec['source']['translation_unit'], unit=rec['source']['compiled'],
                    source_sha256=rec['source']['digest'], recipe_sha256=rec['recipe']['sha256'],
                    first_host=self.first)
        built = record_tool.assemble_record(self.root, task, unit, dict(rva=self.fn['rva']),
                                            rec['runs'][0]['report'], rec['build'], self.evidence())
        self.record = built
        self.save_record(keep_build=True)
        check.validate_match(self.fn, self.target, root=self.root)
        self.assertEqual(len(built['runs']), 1)
        self.assertEqual(built['ci_confirmation']['run_id'], 4242)
        self.assertIn('a public note', built['notes'])


if __name__ == '__main__':
    unittest.main()
