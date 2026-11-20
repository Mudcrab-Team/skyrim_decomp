"""Mechanical readiness findings for the four review grounds; synthetic only."""
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import lint_review_readiness as lint


class ReadinessDispatch(unittest.TestCase):
    def test_four_grounds_have_mechanical_findings(self):
        cases = (
            ('plausible_source', lint.plausible_source_problems('Synthetic.cpp', 'int param_1;')),
            ('provenance', lint.origin_statement_problems('Synthetic.cpp', '// Source exposure: binary-analysis\n')),
            ('publication_hygiene', lint.truncated_mit_problems('Synthetic.h', '// MIT License\n')),
            ('claim_scope', lint.claim_scope_problems('Synthetic.cpp', '// This proves semantic equivalence.\n')),
        )
        for ground, findings in cases:
            with self.subTest(ground=ground):
                self.assertTrue(findings)
        self.assertEqual(lint.plausible_source_problems('Synthetic.cpp', 'int count;'), [])
        self.assertEqual(lint.claim_scope_problems('Synthetic.cpp', '// Byte match only; names remain guesses.'), [])

    def test_prose_naming_the_mit_licence_is_not_a_notice(self):
        prose = ('// Adapted code: bodies are taken from NG under its MIT licence; see the SPDX line below.\n'
                 '// Names follow the same licence.\n')
        self.assertEqual(lint.truncated_mit_problems('Synthetic.h', prose), [])
        self.assertTrue(lint.truncated_mit_problems('Synthetic.h', '// MIT License\n// Permission is hereby granted\n'))
        nested = ROOT / 'reconstruction/gamebryo/nimain/NiObject.h'
        if nested.is_file():
            self.assertEqual(lint.truncated_mit_problems(str(nested), nested.read_text()), [])

    def test_cli_runs_existing_lint_without_weakening_it(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / 'Synthetic.cpp'
            path.write_text('// Origin: original work.\nint local_28;\n')
            with patch.object(lint.existing, 'lint_tree', return_value=['existing lint failure']) as existing, \
                    contextlib.redirect_stdout(io.StringIO()) as out:
                self.assertEqual(lint.main(['--root', str(root), 'Synthetic.cpp']), 1)
            existing.assert_called_once_with(root, ['Synthetic.cpp'])
            self.assertIn('existing lint failure', out.getvalue())
            self.assertIn('plausible_source', out.getvalue())


if __name__ == '__main__':
    unittest.main()
