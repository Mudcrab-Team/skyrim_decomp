"""Include-only headers need no Code origin line; units' own headers still do. Synthetic files only."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import lint_review_readiness  # noqa: E402

NO_ORIGIN = '// Thing, build b. Source exposure: black-box.\n#pragma once\n'


class SharedHeaderOriginTests(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        (self.root / 'shared.h').write_text(NO_ORIGIN)
        (self.root / 'unit.h').write_text(NO_ORIGIN)
        (self.root / 'unit.cpp').write_text(NO_ORIGIN)

    def origin(self, names, **kw):
        return [p for p in lint_review_readiness.lint_files(self.root, names, **kw) if 'origin statement' in p]

    def test_header_without_unit_is_exempt_by_default(self):
        self.assertEqual(self.origin(['shared.h']), [])

    def test_header_with_same_named_unit_still_requires_origin(self):
        self.assertEqual(len(self.origin(['unit.h'])), 1)

    def test_explicit_included_only_exempts_header(self):
        self.assertEqual(self.origin(['unit.h'], included_only={'unit.h'}), [])

    def test_compiled_unit_source_always_requires_origin(self):
        self.assertEqual(len(self.origin(['unit.cpp'], included_only={'unit.cpp'})), 1)


if __name__ == '__main__':
    unittest.main()
