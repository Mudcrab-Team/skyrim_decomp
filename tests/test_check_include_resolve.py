"""Accepted units must resolve their includes under their own recipe; synthetic sources only."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_include_resolve as cir  # noqa: E402

PLAIN = ['/nologo', '/c', '/O2']
ROOTED = PLAIN + ['/I', 'reconstruction']


def tree(root, include, flags):
    files = {
        'reconstruction/area/X.h': '// header\n',
        'reconstruction/other/U.cpp': f'#include "{include}"\n',
        'reconstruction/recipes/r.json': json.dumps({'flags': flags}),
    }
    for name, content in files.items():
        path = Path(root) / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content)
    return {('reconstruction/other/U.cpp', 'reconstruction/recipes/r.json'): ['fn-1']}


class IncludeResolve(unittest.TestCase):
    def problems(self, include, flags):
        with tempfile.TemporaryDirectory() as tmp:
            return cir.check_units(tmp, tree(tmp, include, flags))

    def test_root_relative_include_without_root_fails(self):
        problems = self.problems('area/X.h', PLAIN)
        self.assertEqual(len(problems), 1)
        unit, ids, reason = problems[0]
        self.assertEqual((unit, ids), ('reconstruction/other/U.cpp', ['fn-1']))
        self.assertIn('area/X.h', reason)
        self.assertIn('cannot be resolved', reason)

    def test_parent_step_spelling_passes_without_root(self):
        self.assertEqual(self.problems('../area/X.h', PLAIN), [])

    def test_root_relative_include_passes_with_root(self):
        self.assertEqual(self.problems('area/X.h', ROOTED), [])

    def test_unreadable_record_is_a_problem(self):
        with tempfile.TemporaryDirectory() as tmp:
            problems = cir.check_units(tmp, {(None, 'reports/x/0x1.json'): ['fn-2']})
        self.assertEqual(len(problems), 1)

    def test_imports_without_fcntl(self):
        # The Windows hash job loads this module chain through tools/check.py; fcntl is POSIX-only.
        import subprocess
        code = "import sys; sys.modules['fcntl'] = None; import check_include_resolve"
        tools = str(Path(__file__).resolve().parents[1] / 'tools')
        done = subprocess.run([sys.executable, '-c', code], cwd=tools, capture_output=True, text=True)
        self.assertEqual(done.returncode, 0, done.stderr[-300:])


if __name__ == '__main__':
    unittest.main()
