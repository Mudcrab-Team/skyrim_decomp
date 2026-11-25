"""Original synthetic fixtures for the anonymous sibling policy and private hint pipeline."""
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import build_fo4_private_index as builder
import check
from repo_fixture import kept_environment
import check_labels
import check_origin
import fo4_private as sibling
import lint_reconstruction as lint
import sibling_cpp
import unit_skeleton


class AnonymousGuard(unittest.TestCase):
    def test_index_and_worktree_are_checked_without_echoing_identity(self):
        with tempfile.TemporaryDirectory() as tmp, patch.dict(os.environ, kept_environment(), clear=True):
            root = Path(tmp)
            subprocess.run(['git', 'init', '-q', str(root)], check=True)
            (root / '.local').mkdir()
            (root / '.local/anonymity.json').write_text(json.dumps({'forbidden_strings': ['SyntheticSecret']}))
            path = root / 'notes.md'
            path.write_text('syntheticSECRET')
            subprocess.run(['git', 'add', 'notes.md'], cwd=root, check=True)
            path.write_text('safe replacement')
            for staged in (False, True):
                with self.assertRaises(ValueError) as caught:
                    check.check_git(root, staged=staged)
                self.assertNotIn('syntheticsecret', str(caught.exception).lower())
            subprocess.run(['git', 'add', 'notes.md'], cwd=root, check=True)
            self.assertEqual(check.check_git(root, staged=True), 1)
            path.write_text('SyntheticSecret')
            with self.assertRaisesRegex(ValueError, 'Anonymous sibling guard'):
                check.check_git(root)
            with self.assertRaisesRegex(ValueError, 'Anonymous sibling guard'):
                check.check_anonymity('SYNTHETICSECRET/file.md', b'safe', ('syntheticsecret',))

    def test_explicit_config_is_required_and_can_follow_lane_clone(self):
        with tempfile.TemporaryDirectory() as tmp:
            config = Path(tmp) / 'private.json'
            with patch.dict(os.environ, {'SR_ANONYMITY_CONFIG': str(config)}):
                with self.assertRaisesRegex(ValueError, 'private config missing or invalid'):
                    check.anonymity_terms(Path(tmp) / 'other-clone')
                config.write_text('{broken')
                with self.assertRaises(ValueError):
                    check.anonymity_terms()
                config.write_text(json.dumps({'forbidden_strings': ['SyntheticSecret']}))
                self.assertEqual(check.anonymity_terms(Path(tmp) / 'other-clone'), ('syntheticsecret',))

    def test_short_nickname_is_a_token_and_owner_repo_remain_literal(self):
        with tempfile.TemporaryDirectory() as tmp, patch.dict(os.environ, kept_environment(), clear=True):
            root = Path(tmp)
            (root / '.local').mkdir()
            (root / '.local/anonymity.json').write_text(json.dumps(
                dict(forbidden_strings=['SyntheticOwner'], forbidden_tokens=['Nickname'])))
            terms = check.anonymity_terms(root)
            check.check_anonymity('notes.md', b'opaque-aNicknameb-key', terms)
            for payload in (b'Nickname', b'prefix-SyntheticOwner-suffix', b'aSyntheticOwnerb'):
                with self.assertRaises(ValueError):
                    check.check_anonymity('notes.md', payload, terms)


class SiblingPolicy(unittest.TestCase):
    def test_label_pin_permission_and_allowed_header(self):
        self.assertEqual(lint.sibling_label_problems('test.h', sibling.LABEL), [])
        self.assertIsNotNone(lint.LABEL_LINE.fullmatch('// Widget: ' + sibling.LABEL))
        header = '// Sibling source: fo4-private@1b765c70 src/Game/Widget.cpp:2'
        self.assertEqual(lint.sibling_header_problems('test.cpp', header), [])
        self.assertTrue(lint.sibling_label_problems('test.h', sibling.LABEL.replace('1b765c70', '12345678')))
        self.assertTrue(lint.sibling_label_problems('test.h', sibling.LABEL.replace('1b765c70', '1b765c70' + '0' * 32)))
        self.assertTrue(lint.sibling_label_problems('test.h', sibling.LABEL.replace('author-permission', 'MIT')))
        for folder in ('Havok', 'HavokLib', 'Scaleform', 'SDK', 'Gamebryo', '_gen', 'Other'):
            self.assertTrue(lint.sibling_header_problems('test.cpp', header.replace('src/Game/', f'src/{folder}/')))

    def test_excluded_citations_never_open_source(self):
        checker = check_labels.Checker({}, siblings={})
        with patch.object(Path, 'read_text', side_effect=AssertionError('excluded source opened')):
            findings = checker.check_sibling_sources('test.cpp', '// Sibling source: fo4-private@1b765c70 src/Havok/Widget.cpp:1')
        self.assertIn('outside the allowed game-code folders', findings[0])

    def test_config_override_keeps_anonymous_default_and_drifted_citation_is_not_read(self):
        with tempfile.TemporaryDirectory() as tmp, patch.dict(os.environ, kept_environment(), clear=True):
            root = Path(tmp)
            config = root / '.local/verifier/config.json'
            config.parent.mkdir(parents=True)
            config.write_text(json.dumps({'sibling_checkouts': {'momusdigital/fnv_decomp': 'custom'}}))
            siblings = check_labels.configured_siblings(root)
            self.assertIn('fo4-private', siblings)
            self.assertEqual(siblings['momusdigital/fnv_decomp'], 'custom')
            self.assertEqual(siblings['momusdigital/f3_decomp'], '.local/sources/f3_decomp')
            checker = check_labels.Checker({}, siblings={'fo4-private': str(root)})
            with patch('check_labels.checkout_head', return_value='0' * 40), patch.object(
                    Path, 'read_text', side_effect=AssertionError('unapproved source opened')):
                findings = checker.check_sibling_sources('test.cpp',
                    '// Sibling source: fo4-private@1b765c70 src/Game/Widget.cpp:1')
            self.assertIn('approved pin; not read', findings[0])

    def test_sibling_name_and_origin_indexes_only_visit_game_folders(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for folder, name in [('Game', 'Widget'), ('Havok', 'Vendor'), ('_gen', 'Aggregate')]:
                path = root / 'src' / folder / 'test.cpp'
                path.parent.mkdir(parents=True)
                path.write_text(f'class {name} {{ public: int Get() {{ return 2; }} }};')
            (root / 'src/Game/linked.cpp').symlink_to(root / 'src/Havok/test.cpp')
            checker = check_labels.Checker({}, siblings={'fo4-private': str(root)})
            with patch('check_labels.checkout_head', return_value=sibling.REVISION):
                index = checker.sibling_index('fo4-private')
            self.assertIn('Widget', index.scopes)
            self.assertNotIn('Vendor', index.scopes)
            self.assertNotIn('Aggregate', index.scopes)
            with patch('check_origin.head_of', return_value=sibling.REVISION):
                clone = check_origin.Clone('fo4-private', root, 'author-permission', sibling.GAME_DIRS, None)
            self.assertIn(('Widget', 'Get'), clone.index)
            self.assertNotIn(('Vendor', 'Get'), clone.index)
            with patch('check_origin.head_of', return_value='0' * 40):
                with self.assertRaisesRegex(ValueError, 'revision differs'):
                    check_origin.Clone('fo4-private', root, 'author-permission', sibling.GAME_DIRS, None)


class HintIndex(unittest.TestCase):
    def test_namespace_parser_and_overloads_are_preserved(self):
        text = 'namespace A { class Widget { int Get(int x) { return x; } int Get() { return 0; } }; }'
        rows = sibling_cpp.functions(text)
        self.assertEqual([r['qualified'] for r in rows], ['A::Widget::Get', 'A::Widget::Get'])
        self.assertNotEqual(rows[0]['params'], rows[1]['params'])
        self.assertEqual(sibling_cpp.functions('template<class T> class Box { int Get() { return 1; } };'), [])

    def test_exact_join_deduplicates_rvas_preserves_overloads_and_appends_anchors(self):
        bodies = {'A::Get': [{'body': 'return 1;'}, {'body': 'return 2;'}]}
        private = [{'rva': 16, 'names': [{'name': 'A::Get', 'how': 'community'}]},
                   {'rva': 32, 'names': [{'name': 'Get', 'how': 'community'}]}]
        public = [{'rva': 16, 'name': 'A::Get'}, {'rva': 48, 'name': 'A::Get'}]
        rows = builder.join(bodies, private, public, 'test')
        self.assertEqual([r['rva'] for r in rows], [16, 48])
        self.assertEqual(len(rows[0]['sources']), 2)
        anchor = dict(build_id='test', rva=32, qualified='A::Get', reason='synthetic anchor', evidence='private handoff')
        self.assertEqual(builder.join(bodies, private, public, 'test', [anchor])[-1]['match'], 'anchor')
        with self.assertRaises(ValueError):
            builder.join(bodies, private, public, 'test', [dict(anchor, rva=99)])
        with self.assertRaisesRegex(ValueError, 'different Skyrim build'):
            builder.join(bodies, [dict(private[0], build_id='other')], public, 'test')

    def test_builder_refuses_pin_drift_before_source_reads(self):
        with patch('build_fo4_private_index.subprocess.check_output', return_value='0' * 40):
            with self.assertRaisesRegex(ValueError, 'revision differs'):
                builder.source_bodies(Path('unused'))

    def test_sheets_attach_hint_only_to_sibling_variant_and_matching_build(self):
        with tempfile.TemporaryDirectory() as tmp, patch.dict(os.environ, kept_environment(), clear=True):
            root = Path(tmp)
            directory = root / '.local' / sibling.INDEX
            directory.mkdir(parents=True)
            (directory / 'meta.json').write_text(json.dumps(dict(source=sibling.SOURCE, revision=sibling.REVISION)))
            row = dict(build_id='test', rva=16, qualified='Widget::Get', match='exact-qualified-name',
                       sources=[dict(path='src/Game/Widget.cpp', line=1, head='int Widget::Get()', body=' return 3; ')])
            index = directory / 'hints.jsonl'
            index.write_text(json.dumps(row) + '\n')
            unit = dict(task={'build_id': 'test'}, compiled='reconstruction/misc/Widget.cpp', dir=root, brief='')
            fn = dict(rva=16, size=4, community_name='Widget::Get')
            self.assertNotIn('return 3', unit_skeleton.function_sheet(unit, fn, False, root))
            sheet = unit_skeleton.function_sheet(unit, fn, True, root)
            for expected in ('return 3', sibling.LABEL, 'VS2012', 'form IDs', 'overloads unresolved'):
                self.assertIn(expected, sheet)
            self.assertEqual(sibling.hint_section(root, 'other-build', 16), '')
            row['sources'][0]['path'] = 'src/Gamebryo/Widget.cpp'
            index.write_text(json.dumps(row) + '\n')
            with self.assertRaisesRegex(ValueError, 'excluded source path'):
                sibling.hint_section(root, 'test', 16)


if __name__ == '__main__':
    unittest.main()
