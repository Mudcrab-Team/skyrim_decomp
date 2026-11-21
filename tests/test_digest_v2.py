"""tu-sha256-v2 ignores prose comments but not provenance, strings or code; records of either method validate."""
import sys
import tempfile
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
import digest_v2 as d  # noqa: E402
import source_digest as v1  # noqa: E402

BASE = (b'// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations)\n'
        b'// Source exposure: binary-analysis\n'
        b'// Foo: GUESS(low)\n'
        b'#include "A.h"\n'
        b'const char* s = "// not a comment";\n'
        b'int f() { return 1; }\n')


def digest(blob):
    return d.strip_comments(blob, 'x.cpp')


class SameCodeTests(unittest.TestCase):
    def test_provenance_labels_are_comments_here_but_code_and_strings_are_not(self):
        relabelled = BASE.replace(b'GUESS(low)', b'OBSERVED; table entry confirmed') + b'// extra prose\n'
        self.assertTrue(d.same_code(BASE, relabelled, 'x.cpp'))
        self.assertNotEqual(digest(BASE), digest(relabelled))
        self.assertFalse(d.same_code(BASE, BASE.replace(b'return 1', b'return 2'), 'x.cpp'))
        self.assertFalse(d.same_code(BASE, BASE.replace(b'// not a comment', b'// changed'), 'x.cpp'))
        self.assertFalse(d.same_code(BASE, BASE.replace(b'"A.h"', b'"B.h"'), 'x.cpp'))

    def test_a_text_the_scan_cannot_classify_is_not_comment_only(self):
        self.assertFalse(d.same_code(BASE, BASE + b'/* open', 'x.cpp'))
        self.assertFalse(d.same_code(BASE + b'/* open', BASE + b'/* open', 'x.cpp'))


class StripTests(unittest.TestCase):
    def test_prose_comments_do_not_change_the_text(self):
        noisy = (b'// Build: x\n// Evidence: findings/x.md\n' + BASE.replace(b'int f()', b'/* why\nmore */\nint f()')
                 + b'// trailing prose\nint g() { return 2; } // note\n')
        plain = BASE + b'int g() { return 2; }\n'
        self.assertEqual(digest(noisy), digest(plain))

    def test_deleting_whole_comment_lines_is_invisible(self):
        a = b'// one\n// two\n#include "A.h"\n\n// three\nint f();\n'
        b = b'#include "A.h"\n\nint f();\n'
        self.assertEqual(digest(a), digest(b))

    def test_provenance_is_hashed(self):
        for marker in (b'GUESS(high)', b'STANDIN', b'COMMUNITY(a/b@abcdef1, MIT)', b'SIBLING(x/y@abcdef1, no-licence)',
                       b'SYMBOLS(fo4-pdb)'):
            self.assertNotEqual(digest(BASE), digest(BASE.replace(b'GUESS(low)', marker)), marker)
        for field in (b'Source exposure: mixed', b'Code origin: adapted', b'Adapted bodies: Foo::Bar'):
            self.assertNotEqual(digest(BASE), digest(BASE + b'// ' + field + b'\n'), field)

    def test_code_and_strings_are_hashed(self):
        self.assertNotEqual(digest(BASE), digest(BASE.replace(b'return 1', b'return 2')))
        self.assertNotEqual(digest(BASE), digest(BASE.replace(b'// not a comment', b'// other text')))

    def test_comment_markers_in_literals_are_not_comments(self):
        self.assertIn('"/* kept */"', digest(b'const char* s = "/* kept */";\n'))
        self.assertIn("'\"'", digest(b"char c = '\"'; // gone\n"))
        self.assertNotIn('gone', digest(b"char c = '\"'; // gone\n"))

    def test_digit_separator_is_code(self):
        self.assertIn("1'000", digest(b"int n = 1'000; // gone\n"))

    def test_refusals(self):
        for blob in (b'/* open\n', b'const char* s = "open\n', b'int x = __LINE__;\n', b"int x = a'b;\n"):
            with self.assertRaises(ValueError, msg=blob):
                digest(blob)


class UnitDigestTests(unittest.TestCase):
    def test_methods_and_binding_helpers(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction').mkdir()
            (root / 'reconstruction/A.cpp').write_bytes(BASE)
            (root / 'reconstruction/A.h').write_bytes(b'// header prose\nint f();\n')
            unit = ['reconstruction/A.cpp', 'reconstruction/A.h']
            old = d.tu_digest(root, unit, 'tu-sha256-v1')
            self.assertEqual(old, v1.tu_digest(root, unit))
            new = d.tu_digest(root, unit)
            self.assertNotEqual(old, new)
            (root / 'reconstruction/A.h').write_bytes(b'int f();\n')
            self.assertEqual(new, d.tu_digest(root, unit))
            self.assertNotEqual(old, d.tu_digest(root, unit, 'tu-sha256-v1'))
            with self.assertRaises(ValueError):
                d.tu_digest(root, unit, 'tu-sha256-v3')
            source = {'digest_method': d.DIGEST_METHOD, 'digest': new, 'run_digest': old, 'run_digest_method': 'tu-sha256-v1'}
            self.assertIsNone(d.run_digest_problem(source))
            self.assertEqual(d.run_revision(source), old)
            self.assertEqual(d.run_revision({'digest': new}), new)
            self.assertTrue(d.review_binds('tu-sha256-v1', old, source))
            self.assertTrue(d.review_binds(d.DIGEST_METHOD, new, source))
            self.assertFalse(d.review_binds('tu-sha256-v1', new, source))
            self.assertFalse(d.review_binds(d.DIGEST_METHOD, old, source))
            self.assertFalse(d.review_binds('tu-sha256-v1', old, {'digest_method': d.DIGEST_METHOD, 'digest': new}))
            self.assertIsNotNone(d.run_digest_problem(dict(source, run_digest_method='tu-sha256-v2')))
            self.assertIsNotNone(d.run_digest_problem({'digest_method': 'tu-sha256-v1', 'run_digest': old,
                                                       'run_digest_method': 'tu-sha256-v1'}))
            self.assertIsNotNone(d.run_digest_problem({'digest_method': d.DIGEST_METHOD, 'run_digest': old}))


class PathIndependenceTests(unittest.TestCase):
    FILES = {'reconstruction/a/Unit.cpp': b'#include "Unit.h"\n#include <cstdint>\n#include "shared/Base.h"\nint f() { return 1; }\n',
             'reconstruction/a/Unit.h': b'#pragma once\nint f();\n',
             'reconstruction/shared/Base.h': b'#pragma once\nstruct Base {};\n'}

    def digest(self, files, method=None):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for name, blob in files.items():
                (root / name).parent.mkdir(parents=True, exist_ok=True)
                (root / name).write_bytes(blob)
            return d.tu_digest(root, sorted(files), method), d.unit_digest(dict(files), method)

    def test_moving_a_unit_and_rewriting_includes_changes_nothing(self):
        before = self.digest(self.FILES)
        self.assertEqual(before[0], before[1])
        moved = {'reconstruction/b/c/Renamed.cpp': self.FILES['reconstruction/a/Unit.cpp'].replace(b'"Unit.h"', b'"Renamed.h"')
                 .replace(b'"shared/Base.h"', b'"common/Base.h"'),
                 'reconstruction/b/c/Renamed.h': self.FILES['reconstruction/a/Unit.h'],
                 'reconstruction/common/Base.h': self.FILES['reconstruction/shared/Base.h']}
        self.assertEqual(self.digest(moved), before)

    def test_content_include_order_and_graph_still_matter(self):
        base = self.digest(self.FILES)[0]
        changed = dict(self.FILES, **{'reconstruction/shared/Base.h': b'#pragma once\nstruct Base { int x; };\n'})
        self.assertNotEqual(base, self.digest(changed)[0])
        swapped = dict(self.FILES, **{'reconstruction/a/Unit.cpp': b'#include "shared/Base.h"\n#include <cstdint>\n#include "Unit.h"\nint f() { return 1; }\n'})
        self.assertNotEqual(base, self.digest(swapped)[0])
        toolchain = dict(self.FILES, **{'reconstruction/a/Unit.cpp': self.FILES['reconstruction/a/Unit.cpp'].replace(b'<cstdint>', b'<cstddef>')})
        self.assertNotEqual(base, self.digest(toolchain)[0])

    def test_v1_still_depends_on_paths(self):
        moved = {'reconstruction/z/Unit.cpp': self.FILES['reconstruction/a/Unit.cpp'], 'reconstruction/z/Unit.h': self.FILES['reconstruction/a/Unit.h'],
                 'reconstruction/shared/Base.h': self.FILES['reconstruction/shared/Base.h']}
        self.assertNotEqual(self.digest(self.FILES, 'tu-sha256-v1')[0], self.digest(moved, 'tu-sha256-v1')[0])

    def test_path_dependent_constructs_are_refused(self):
        for text in (b'const char* f = __FILE__;\n', b'const wchar_t* f = __FILEW__;\n', b'#line 5\nint x;\n'):
            with self.assertRaises(ValueError, msg=text):
                d.unit_digest({'reconstruction/a/U.cpp': text})

    def test_an_include_of_a_file_outside_the_unit_is_refused(self):
        with self.assertRaises(ValueError):
            d.unit_digest({'reconstruction/a/U.cpp': b'#include "Missing.h"\n'})


if __name__ == '__main__':
    unittest.main()
