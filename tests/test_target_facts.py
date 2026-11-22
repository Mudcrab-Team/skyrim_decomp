"""Target facts sidecar: derived from committed data only, one entry per target that has facts."""
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import target_facts  # noqa: E402


class TargetFacts(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.tmp, ignore_errors=True)
        (self.tmp / 'data/target-hashes').mkdir(parents=True)
        (self.tmp / 'data/symbol-alignment.json').write_text(json.dumps({'functions': {'0x2000': {
            'confidence': 'high', 'name': 'Foo::Bar', 'prototype': 'public: void __thiscall Foo::Bar(void)',
            'object': 'x.obj', 'source': 'tesv-2013-map'}}}))
        (self.tmp / target_facts.OFFERED).write_text(json.dumps({'build_id': 'b', 'functions': [
            {'rva': 0x2000, 'size': 20}, {'rva': 0x3000, 'size': 30}]}))

    def test_only_targets_with_facts_appear(self):
        data = target_facts.build(self.tmp)
        self.assertEqual(data['targets'], 2)
        self.assertEqual(list(data['facts']), ['0x2000'])
        al = data['facts']['0x2000']['alignment']
        self.assertEqual(al['name'], 'Foo::Bar')
        self.assertEqual(al['label'], 'SYMBOLS(tesv-2013-map)')
        self.assertNotIn('object', al)

    def test_committed_file_matches_derivation_shape(self):
        data = json.loads((ROOT / target_facts.OUT).read_text())
        self.assertEqual(data['schema'], target_facts.SCHEMA)
        self.assertLessEqual(data['with_facts'], data['targets'])
        self.assertEqual(len(data['facts']), data['with_facts'])


if __name__ == '__main__':
    unittest.main()
