import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]


class ReportSchema(unittest.TestCase):
    def export(self, scope, code_section=None):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            data = root / 'data'
            data.mkdir()
            reconstruction = root / 'reconstruction'
            reconstruction.mkdir()
            rows = [
                (16, 'Example::Done', 12, 'matched', 'demo/Example', 'matched'),
                (32, 'Example::Draft', 4, 'reconstructed', 'demo/Example', 'reconstructed'),
                (48, 'Example::Old', 8, 'matched', 'demo/Example', 'matched, STALE (changed unit)'),
                (64, 'Unassigned', 20, 'mapped', None, 'mapped'),
            ]
            (data / 'progress.json').write_text(json.dumps({
                'scope': scope,
                'functions': [dict(build_id='toy', rva=rva, name=name, size=size, status=status)
                              for rva, name, size, status, _, _ in reversed(rows)],
            }))
            census = {
                'build_id': 'toy',
                'denominators': {'ordinary_game_code': {'bytes': 999, 'functions': 999, 'basis': 'estimated'}},
            }
            if code_section is not None:
                census['image'] = {'pe_code_virtual_size': code_section}
            (data / 'scope.json').write_text(json.dumps(census))
            with (reconstruction / 'INDEX.md').open('w') as index:
                for rva, name, size, _, unit, state in rows:
                    cell = f'`{unit}`' if unit else '-'
                    index.write(f'| {cell} | `{name}` | `toy` / `0x{rva:x}` / {size} | - | - | {state} | - | - |\n')
            output = root / 'artifact/report.json'
            subprocess.run([sys.executable, str(ROOT / 'tools/objdiff_report.py'), '--root', str(root),
                            '--output', str(output)], check=True)
            return json.loads(output.read_text())

    def test_version_two_protojson_with_unknown_scope(self):
        self.assertEqual(self.export({'bytes': None, 'functions': None}), {
            'version': 2,
            'measures': {'matched_code': '12', 'matched_functions': 1, 'total_units': 1},
            'units': [{
                'name': 'demo/Example',
                'measures': {'total_code': '24', 'matched_code': '12', 'matched_code_percent': 50.0,
                             'total_functions': 3, 'matched_functions': 1,
                             'matched_functions_percent': 100 / 3},
                'functions': [{'name': 'Example::Done', 'size': '12'},
                              {'name': 'Example::Draft', 'size': '4'},
                              {'name': 'Example::Old', 'size': '8'}],
                'metadata': {'source_path': 'reconstruction/demo/Example.cpp'},
            }],
        })

    def test_reviewed_scope_supplies_project_denominators(self):
        self.assertEqual(self.export({'bytes': 80, 'functions': 4})['measures'], {
            'matched_code': '12', 'matched_functions': 1, 'total_units': 1,
            'total_code': '80', 'matched_code_percent': 15.0,
            'total_functions': 4, 'matched_functions_percent': 25.0,
        })

    def test_measured_code_extent_supplies_labeled_lower_bound(self):
        report = self.export({'bytes': None, 'functions': None}, {'value': 200, 'basis': 'measured'})
        self.assertEqual(report['measures'], {
            'matched_code': '12', 'matched_functions': 1, 'total_units': 1,
            'total_code': '200', 'matched_code_percent': 6.0,
        })
        self.assertEqual(report['categories'], [{
            'id': 'text',
            'name': 'Lower bound (% of .text, includes CRT/import code)',
            'measures': report['measures'],
        }])
