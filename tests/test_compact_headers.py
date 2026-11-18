"""tools/compact_headers.py changes comments only, keeps provenance, and refuses what it cannot prove safe."""
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import compact_headers as c  # noqa: E402
import digest_v2  # noqa: E402
import lint_reconstruction as lint  # noqa: E402

LICENCE = '\n'.join('// ' + line if line else '//' for line in (ROOT / 'licenses/CommonLibSSE-NG.txt').read_text().splitlines())
NG = 'COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)'
OLD = f"""// Build: sse-steam-1-7-104; RVA 0x1000; 8 bytes
// Evidence: findings/x.md
// Recipe: {lint.DEFAULT_RECIPE}
// Source exposure: mixed (names from community headers; the listing of the pinned
// image).
// Drafted by someone.
// Labels: v2
// Widget, Get: {NG}
// Some prose that says nothing.
{LICENCE}
// Origin: {{"family": "f", "template_digest": "{'0' * 64}", "version": "2"}}
#include "Widget.h"
int Widget::Get() const {{ return 1; }}
"""


class RewriteTests(unittest.TestCase):
    def rewrite(self, text, ext='cpp', names=None):
        return c.rewrite(text, ext, names or {0x1000: 'Widget::Get'}, c.canonical_notice())

    def test_header_becomes_compact_and_digest_text_is_unchanged(self):
        new, why = self.rewrite(OLD)
        self.assertIsNone(why)
        self.assertEqual(digest_v2.strip_comments(OLD.encode(), 'x.cpp'), digest_v2.strip_comments(new.encode(), 'x.cpp'))
        head = new.split('#include')[0].splitlines()
        self.assertIn('// 0x1000 Widget::Get', head)
        self.assertIn('// ' + lint.SPDX_MIT, head)
        self.assertIn('// Origin: f v2', head)
        for gone in ('Build:', 'Evidence:', 'Recipe:', 'Drafted by', 'Labels: v2', 'prose', 'Permission'):
            self.assertFalse(any(gone in line for line in head), gone)
        self.assertTrue(any(NG in line for line in head))
        self.assertTrue(any('wrapped' not in line and line.endswith('image).') for line in head))

    def test_running_it_again_changes_nothing(self):
        once, _ = self.rewrite(OLD)
        again, why = self.rewrite(once)
        self.assertIsNone(why)
        self.assertEqual(once, again)
        header, _ = self.rewrite(OLD.replace('COMMUNITY(', 'COMMUNITY('), 'h')
        self.assertEqual(header, self.rewrite(header, 'h')[0])

    def test_a_non_default_recipe_is_kept_and_a_header_gets_no_function_list(self):
        new, _ = self.rewrite(OLD.replace(lint.DEFAULT_RECIPE, 'reconstruction/recipes/other.json'), 'h')
        self.assertIn('// Recipe: reconstruction/recipes/other.json', new)
        self.assertNotIn('// 0x1000', new)

    def test_a_garbled_licence_or_crlf_is_left_alone(self):
        self.assertEqual(self.rewrite(OLD.replace('Permission is hereby granted', 'Permission is granted'))[1],
                         'unrecognised-licence-text')
        self.assertEqual(self.rewrite(OLD.replace('\n', '\r\n'))[1], 'crlf')


WRAPPED = f"""// Build: sse-steam-1-7-104; RVA 0x1000; 8 bytes
// Code origin: body written from the compared function's behaviour; names and
// declarations come from the header (CharmedBaryon/CommonLibSSE-NG, MIT),
// with no body copied.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Widget, Get: GUESS(low) STANDIN
// Nothing else is claimed.
// Names follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT)
// and powerof3/CommonLibSSE 654e55f (GPL-3.0), and callee
// names from a list used with permission.
// Labels: v2
// object: GUESS(low)
// Widget: {NG}
#include "Widget.h"
int Widget::Get() const {{ return 1; }}
"""


class WrapTests(unittest.TestCase):
    """A field wrapped over several lines keeps all of its text, digest-neutrally and idempotently."""

    def rewrite(self, text):
        return c.rewrite(text, 'cpp', {0x1000: 'Widget::Get'}, c.canonical_notice())

    def test_a_wrapped_field_keeps_its_continuation(self):
        new, why = self.rewrite(WRAPPED)
        self.assertIsNone(why)
        head = new.split('#include')[0].splitlines()
        code = head.index("// Code origin: body written from the compared function's behaviour; names and")
        # The provenance line is hashed as written; the rest of its sentence follows as one line.
        self.assertEqual(head[code + 1], '// declarations come from the header (CharmedBaryon/CommonLibSSE-NG, MIT), '
                                         'with no body copied.')
        exposure = next(i for i, line in enumerate(head) if 'Source exposure:' in line)
        self.assertEqual(head[exposure + 1], '// the compared functions from the pinned image).')
        self.assertEqual(digest_v2.strip_comments(WRAPPED.encode(), 'x.cpp'),
                         digest_v2.strip_comments(new.encode(), 'x.cpp'))

    def test_a_kept_line_that_starts_mid_sentence_gets_its_start_back(self):
        new, _ = self.rewrite(WRAPPED)
        self.assertIn('// Names follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT) and powerof3/CommonLibSSE 654e55f '
                      '(GPL-3.0), and callee names from a list used with permission.', new.splitlines())

    def test_a_new_statement_is_not_a_wrap(self):
        new, _ = self.rewrite(WRAPPED)
        for gone in ('Nothing else is claimed', 'Labels: v2', 'Build:'):
            self.assertNotIn(gone, new)
        self.assertIn('// object: GUESS(low)', new.splitlines())
        self.assertFalse(c.wraps_into('// Widget, Get: GUESS(low) STANDIN', '// The target calls it.'))
        self.assertFalse(c.wraps_into('// Labels: v2', '// object: GUESS(low)'))
        self.assertTrue(c.wraps_into('// a, b, c,', '// d: GUESS(low)'))

    def test_the_spdx_line_does_not_split_a_wrapped_field(self):
        text = ('// Source exposure: mixed (names from community headers; sizes and\n'
                '// the compared functions from the pinned image).\n'
                f'// Widget: {NG}\n#include "Widget.h"\n')
        new, _ = c.rewrite(text, 'h', {}, c.canonical_notice())
        head = new.split('#include')[0].splitlines()
        self.assertEqual(head[1], '// the compared functions from the pinned image).')
        self.assertIn('// ' + lint.SPDX_MIT, head[2:])

    def test_running_it_again_changes_nothing(self):
        once, _ = self.rewrite(WRAPPED)
        self.assertEqual(self.rewrite(once)[0], once)


if __name__ == '__main__':
    unittest.main()
