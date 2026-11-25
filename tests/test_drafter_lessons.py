from pathlib import Path
import json
import shutil
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import drafter_lessons
import lesson_tags

ROOT = Path(__file__).resolve().parents[1]


class LessonsTests(unittest.TestCase):
    def test_all_lessons_have_valid_tags(self):
        allowed = lesson_tags.vocabulary(ROOT)
        self.assertEqual(set(lesson_tags.PATTERNS), allowed)
        found = list(drafter_lessons.entries(ROOT))
        self.assertGreater(len(found), 100)
        self.assertTrue(all(tags and tags <= allowed for _, _, tags in found))

    def test_tag_rank_and_cap(self):
        out = drafter_lessons.select(ROOT, None, {'construct/destructor'}, 4000)
        self.assertIn('construct/destructor', out)
        self.assertLessEqual(len(out), 4000)

    def test_tag_line_accepts_windows_newlines(self):
        self.assertEqual(lesson_tags.parse('<!-- tags: wall/callee -->\r\n', {'wall/callee'}), {'wall/callee'})

    def test_invalid_tag_refused(self):
        with self.assertRaisesRegex(ValueError, 'unknown lesson tags'):
            drafter_lessons.select(ROOT, None, {'wall/not-real'})

    def test_tags_from_task_lead_alignment_and_local_hint(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'docs').mkdir()
            shutil.copy(ROOT / 'docs/lesson-tags.md', root / 'docs/lesson-tags.md')
            task = root / 'task'
            task.mkdir()
            (task / 'task.json').write_text(json.dumps({'functions': [{'rva': '0x1234', 'community_name': 'Example::Load'}]}))
            (task / 'sibling_x64.json').write_text(json.dumps({'functions': {'0x1234': {'candidates': [{'game': 'fo4', 'name': 'Example::Load'}]}}}))
            align = task / 'attempts/001/0x1234'
            align.mkdir(parents=True)
            (align / 'align.json').write_text(json.dumps({'suggestion': 'register schedule'}))
            local = root / '.local'
            (local / 'analysis').mkdir(parents=True)
            (local / 'analysis/hints.jsonl').write_text(json.dumps({'rva': '0x1234', 'family': 'form factory'}) + '\n')
            tags = drafter_lessons.tags_for(root, local, 0x1234, task_dir=task)
            self.assertTrue({'sibling/fo4', 'wall/register-schedule', 'family/form-factory'} <= tags)


if __name__ == '__main__':
    unittest.main()
