import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import drafter_sheet


class SheetTests(unittest.TestCase):
    def test_sheet_reads_selected_facts_without_listing(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            task = root / 'tasks' / 'one'
            task.mkdir(parents=True)
            pack = root / 'pack'
            pack.mkdir()
            (pack / 'README.md').write_text('## References leaving the function\n| callee | example |\n')
            (pack / 'listing.txt').write_text('SECRET LISTING')
            (task / 'task.json').write_text(json.dumps({'build_id': 'build', 'compiled': 'unit.cpp', 'functions': [
                {'rva': '0x1234', 'size': 8, 'pack': str(pack), 'community_name': 'A::B'}]}))
            self.assertEqual(drafter_sheet.task_for([root / 'tasks'], 0x1234), [task])
            out = drafter_sheet.render(root, task, 0x1234)
            self.assertIn('A::B', out)
            self.assertIn('callee', out)
            self.assertIn('tools/verifier/attempt', out)
            self.assertNotIn('SECRET LISTING', out)


if __name__ == '__main__':
    unittest.main()
