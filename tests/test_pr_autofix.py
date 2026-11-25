"""Mechanical unit repairs the PR bot pushes to a contributor's branch (tools/pr_autofix.py).

Fixtures are invented source text; none of it comes from the game image.
"""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lint_reconstruction as lint  # noqa: E402
import pr_autofix  # noqa: E402

BODY = '''#include "Thing.h"

int Thing::Alpha(int a_x)
{
    return a_x + 1;
}

int Thing::Beta(int a_x)
{
    return a_x * 2;
}
'''
NG = '// Names: Thing::Alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)\n'


def over_budget(extra=0):
    free = ''.join(f'// Free text line {i} about this unit.\n' for i in range(extra))
    return ('// Task: t1\n// Build: sse\n// Evidence: reports\n// Drafted by: someone\n' + free +
            '// Source exposure: black-box (original reconstruction)\n// 0x1000 Thing::Alpha\n')


class TrimHeaderTests(unittest.TestCase):
    def test_boilerplate_goes_first_and_provenance_stays(self):
        text = over_budget(4) + BODY
        self.assertTrue(lint.header_budget_problems('x.cpp', lint.leading_comment(text)))
        new = pr_autofix.trim_header(text, 'reconstruction/x.cpp')
        self.assertIsNotNone(new)
        self.assertEqual(lint.header_budget_problems('x.cpp', lint.leading_comment(new)), [])
        self.assertIn('// Source exposure: black-box (original reconstruction)', new)
        self.assertIn('// 0x1000 Thing::Alpha', new)
        self.assertNotIn('// Task: t1', new)
        self.assertTrue(new.endswith(BODY))

    def test_a_label_line_is_never_removed(self):
        label = '// Thing::Alpha: GUESS(low) STANDIN\n'
        text = '// a1\n// a2\n// a3\n// a4\n// a5\n// a6\n// a7\n' + label + BODY
        new = pr_autofix.trim_header(text, 'reconstruction/x.cpp')
        self.assertIn(label, new)
        self.assertEqual(lint.header_budget_problems('x.cpp', lint.leading_comment(new)), [])

    def test_a_header_made_only_of_protected_lines_is_left_alone(self):
        text = ''.join(f'// Source exposure: line {i}\n' for i in range(8)) + BODY
        self.assertIsNone(pr_autofix.trim_header(text, 'reconstruction/x.cpp'))

    def test_a_header_within_budget_is_left_alone(self):
        self.assertIsNone(pr_autofix.trim_header('// one\n// two\n' + BODY, 'reconstruction/x.cpp'))

    def test_a_wrapped_statement_is_removed_whole(self):
        text = ('// Task: t1\n// Note: this explains the unit and\n// carries on over a second line.\n'
                '// a\n// b\n// c\n// d\n// e\n' + BODY)
        new = pr_autofix.trim_header(text, 'reconstruction/x.cpp')
        self.assertNotIn('carries on', new)
        self.assertNotIn('this explains', new)


class SpdxTests(unittest.TestCase):
    def test_the_notice_is_added_after_the_first_statement(self):
        text = '// Unit for Thing.\n' + NG + BODY
        new = pr_autofix.add_spdx(text)
        self.assertEqual(new.split('\n')[1], '// ' + lint.SPDX_MIT)
        self.assertEqual(lint.header_budget_problems('x.cpp', lint.leading_comment(new)), [])

    def test_it_is_not_inserted_inside_a_wrapped_first_statement(self):
        text = '// Unit for Thing and\n// its neighbours.\n' + NG + BODY
        new = pr_autofix.add_spdx(text).split('\n')
        self.assertEqual(new[:3], ['// Unit for Thing and', '// its neighbours.', '// ' + lint.SPDX_MIT])

    def test_a_unit_that_already_has_it_or_does_not_need_it_is_untouched(self):
        self.assertIsNone(pr_autofix.add_spdx('// x\n// ' + lint.SPDX_MIT + '\n' + NG + BODY))
        self.assertIsNone(pr_autofix.add_spdx('// x\n// Names: Thing: GUESS(low) STANDIN\n' + BODY))

    def test_full_licence_text_is_not_a_mechanical_case(self):
        self.assertIsNone(pr_autofix.add_spdx('// MIT License\n// Permission is hereby granted\n' + NG + BODY))


class RestoreTests(unittest.TestCase):
    def test_an_accepted_function_takes_mains_copy_and_the_other_keeps_the_contributors(self):
        main = '// 0x1000 Thing::Alpha\n' + BODY
        mine = main.replace('a_x + 1', 'a_x + 100').replace('a_x * 2', 'a_x * 3')
        new, restored = pr_autofix.restore_functions(mine, main, ['Thing::Alpha'])
        self.assertEqual(restored, ['Thing::Alpha'])
        self.assertIn('a_x + 1;', new)
        self.assertIn('a_x * 3;', new)

    def test_braces_in_strings_and_comments_do_not_end_the_span(self):
        main = BODY.replace('return a_x + 1;', 'return a_x + 1;')
        mine = BODY.replace('return a_x + 1;', '// }\n    const char* s = "}";\n    return a_x + 7;')
        new, restored = pr_autofix.restore_functions(mine, main, ['Thing::Alpha'])
        self.assertEqual(new, main)
        self.assertEqual(restored, ['Thing::Alpha'])

    def test_a_name_defined_twice_or_missing_is_skipped(self):
        twice = BODY + BODY
        self.assertEqual(pr_autofix.restore_functions(twice, BODY, ['Thing::Alpha']), (twice, []))
        self.assertEqual(pr_autofix.restore_functions(BODY, BODY, ['Thing::Gamma']), (BODY, []))

    def test_a_declaration_is_not_a_definition(self):
        self.assertIsNone(pr_autofix.function_span('struct Thing { int Alpha(int); };\n', 'Thing::Alpha'))
        self.assertIsNone(pr_autofix.function_span('int Thing::Alpha(int a_x);\n', 'Thing::Alpha'))

    def test_includes_before_a_definition_stay_out_of_the_span(self):
        start, end = pr_autofix.function_span(BODY, 'Thing::Alpha')
        self.assertTrue(BODY[start:end].startswith('int Thing::Alpha'))


class FixUnitTests(unittest.TestCase):
    ACCEPTED = {0x1000: 'Thing::Alpha'}

    def test_all_three_repairs_apply_together(self):
        main = '// 0x1000 Thing::Alpha\n' + BODY
        mine = over_budget(3).replace('// Source exposure', NG + '// Source exposure') + \
            BODY.replace('a_x + 1', 'a_x + 9')
        new, kinds = pr_autofix.fix_unit('reconstruction/x.cpp', mine, main, self.ACCEPTED)
        self.assertEqual(kinds, ['accepted', 'header', 'spdx'])
        self.assertEqual(lint.header_budget_problems('x.cpp', lint.leading_comment(new)), [])
        self.assertIn('a_x + 1;', new)
        self.assertIn(lint.SPDX_MIT, new)

    def test_a_function_that_is_not_accepted_keeps_the_contributors_version(self):
        main = '// 0x1000 Thing::Alpha\n' + BODY
        mine = main.replace('a_x * 2', 'a_x * 5')
        new, kinds = pr_autofix.fix_unit('reconstruction/x.cpp', mine, main, {})
        self.assertEqual((new, kinds), (mine, []))

    def test_body_repair_skips_a_deleted_helper_and_its_includes(self):
        name = 'reconstruction/x.cpp'
        old_body = 'return offset(a_x);'
        helper = '#include <cstddef>\n\nstatic int offset(std::ptrdiff_t x) { return x + 1; }\n\n'
        main = ('// 0x1000 Thing::Alpha\n' + BODY.replace('int Thing::Alpha', helper + 'int Thing::Alpha')
                .replace('return a_x + 1;', old_body))
        mine = main.replace(helper, '').replace(old_body, 'return a_x + 1;')
        self.assertEqual(pr_autofix.fix_unit(name, mine, main, self.ACCEPTED), (mine, []))

    def test_body_repair_with_a_new_definition_preserves_the_addition(self):
        name = 'reconstruction/x.cpp'
        main = '// 0x1000 Thing::Alpha\n' + BODY
        added = '\nint Thing::Gamma() { return 3; }\n'
        mine = main.replace('return a_x + 1;', 'return a_x + 2;') + added
        self.assertEqual(pr_autofix.fix_unit(name, mine, main, self.ACCEPTED), (main + added, ['accepted']))

    def test_a_new_file_gets_only_header_repairs(self):
        new, kinds = pr_autofix.fix_unit('reconstruction/x.cpp', over_budget(3) + BODY, None, self.ACCEPTED)
        self.assertEqual(kinds, ['header'])

    def test_a_header_that_cannot_be_brought_into_budget_is_not_half_repaired(self):
        text = ''.join(f'// Source exposure: line {i}\n' for i in range(8)) + NG + BODY
        new, kinds = pr_autofix.fix_unit('reconstruction/x.cpp', text, None, {})
        self.assertEqual((new, kinds), (text, []))

    def test_a_clean_unit_is_unchanged(self):
        text = '// 0x1000 Thing::Alpha\n' + BODY
        self.assertEqual(pr_autofix.fix_unit('reconstruction/x.cpp', text, text, self.ACCEPTED), (text, []))


if __name__ == '__main__':
    unittest.main()
