"""Original synthetic primary-host identity fixtures; no executable inputs or network."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import Mock, patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tools/verifier')]
import ci_confirmation as evidence
import ci_confirm
from source_digest import include_closure
from digest_v2 import tu_digest


class PrimaryHost(unittest.TestCase):
    def test_registered_native_output_is_retained_verbatim_and_unregistered_output_is_refused(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            compiled = 'reconstruction/synthetic/Original.cpp'
            path = root / compiled; path.parent.mkdir(parents=True); path.write_bytes(b'// Original fixture\n')
            recipe = root / 'recipe.json'; recipe.write_bytes(b'{}')
            task = dict(dir=root / '.local/task', task_id='original', compiled=compiled,
                        recipe='recipe.json', functions=[dict(rva=4096, size=4, symbol='original')])
            dest = task['dir'] / 'confirm/native-primary'; (dest / '0x1000').mkdir(parents=True)
            import synthetic_pecoff as fx
            blob = fx.coff_object(); (dest / 'candidate.obj').write_bytes(blob)
            report = dict(result='pass', candidate=dict(object_sha256=evidence.sha(blob)),
                          source=dict(source_revision=tu_digest(root, include_closure(root, compiled)), path=compiled),
                          recipe=dict(recipe_sha256=evidence.sha(b'{}')))
            report_path = dest / '0x1000/report.json'; report_path.write_text(json.dumps(report))
            pins = {name: digest for digest, name in (s.split() for s in
                    (ROOT / 'tools/verifier/pinned.sha256').read_text().splitlines() if s.strip())}
            result = dict(host='native-primary', host_facts=dict(loader='native', os='windows',
                          toolchain_check='checked', compiler_sha256=pins))
            (dest / 'result.json').write_text(json.dumps(result))
            host = dict(host_id='native-primary', machine='synthetic-pc', backend='ssh', loader='native')
            base = Mock(); base.build_block.return_value = {'hosts': {'native-primary': {}}}
            with patch.object(ci_confirm.runners, 'load', return_value={}), \
                 patch.object(ci_confirm.runners, 'for_confirm', return_value=[host]):
                unit, reports, build = ci_confirm.local_inputs(root, task, base)
                self.assertEqual(unit['first_host'], dict(host_id='native-primary', machine='synthetic-pc',
                                                        loader='native', os='windows'))
                self.assertEqual(unit['first_object_sha256'], evidence.sha(blob))
                self.assertEqual(reports[4096].read_text(), report_path.read_text())
                base.build_block.assert_called_once_with(task, {'native-primary': dest})
                result['host'] = 'unregistered'
                (dest / 'result.json').write_text(json.dumps(result))
                with self.assertRaisesRegex(ValueError, 'no current all-pass first-host output'):
                    ci_confirm.local_inputs(root, task, base)
