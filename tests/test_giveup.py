"""Give-up records: format, leak rules, the tool, the surfaces and the contributor scope."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import giveup  # noqa: E402
import pr_bot  # noqa: E402

BUILD = 'sse-steam-1-7-104'


def record(**extra):
    base = dict(category='register-schedule', tried=['reordered the two locals', 'moved the null test'],
                still_differs='callee-saved registers are chosen differently in the second loop',
                suspected_cause='inline expansion order in the helper', best_similarity=93.3,
                similarity_basis='aligned shape similarity', model='claude-sonnet-5-5', harness='near-pilot',
                lane='internal', best_code=dict(kind='none'))
    base.update(extra)
    return base


class Repo(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        (self.root / 'builds').mkdir()
        (self.root / 'builds/target.json').write_text(json.dumps(dict(build_id=BUILD)))

    def tearDown(self):
        self.tmp.cleanup()


class Records(unittest.TestCase):
    def test_a_good_record_has_no_problems(self):
        self.assertEqual(giveup.record_problems(record()), [])

    def test_the_category_is_from_the_fixed_list(self):
        self.assertEqual(giveup.record_problems(record(category='bad-luck')), ['category'])
        for category in giveup.CATEGORIES:
            self.assertEqual(giveup.record_problems(record(category=category)), [])

    def test_instructions_bytes_and_paths_are_refused_as_words(self):
        for text in ('mov eax, [rcx+8] replaces the load', 'the bytes 48 8b 01 48 8b 41 08 48 89 44 24 20 48 83 ec 28 differ',
                     'see /Users/someone/work for it', 'line one\nline two', 'it is `a` code span'):
            self.assertTrue(giveup.record_problems(record(still_differs=text)), text)
        self.assertTrue(giveup.record_problems(record(tried=['lea rax, [rsp+20h] was tried'])))

    def test_limits(self):
        self.assertIn('still_differs-too-long', giveup.record_problems(record(still_differs='x ' * 300)))
        self.assertIn('tried-list', giveup.record_problems(record(tried=[])))
        self.assertIn('best-similarity', giveup.record_problems(record(best_similarity=120)))
        self.assertIn('lane', giveup.record_problems(record(lane='robot')))
        self.assertIn('missing-key', giveup.record_problems({'category': 'other'}))

    def test_the_pointer_to_the_best_code_is_a_local_folder_or_a_note_never_a_path_out(self):
        ok_local = dict(kind='local', ref='.local/giveups/sse-steam-1-7-104/1004350/1')
        self.assertEqual(giveup.record_problems(record(best_code=ok_local)), [])
        self.assertEqual(giveup.record_problems(record(best_code=dict(kind='note', ref='docs/cookbook-notes/1004350-lag-bone.md'))), [])
        for bad in (dict(kind='local', ref='/Users/x/best'), dict(kind='local', ref='.local/giveups/../../x'),
                    dict(kind='note', ref='docs/other.md'), dict(kind='none', ref='x'), dict(kind='code', ref='x')):
            self.assertTrue(giveup.record_problems(record(best_code=bad)), bad)


class Tool(Repo):
    def test_add_show_list_and_repeats(self):
        path, added = giveup.add(self.root, '0x1004350', record())
        self.assertTrue(added)
        self.assertEqual(path.relative_to(self.root).as_posix(), f'data/giveups/{BUILD}/1004350.json')
        self.assertEqual(giveup.validate(path.relative_to(self.root).as_posix(), path.read_text(), BUILD), [])
        self.assertEqual(giveup.add(self.root, '0x1004350', record())[1], False)
        giveup.add(self.root, '0x1004350', record(model='claude-opus-5-5', best_similarity=96))
        shown = '\n'.join(giveup.lines_for(self.root, ['0x1004350']))
        self.assertIn('Earlier give-ups for 0x1004350', shown)
        self.assertIn('best 96%', shown)
        self.assertIn('tried: reordered the two locals; moved the null test', shown)
        self.assertEqual(giveup.brief(self.root, '0x1004350'), '2 earlier give-ups: register-schedule (best 96%)')
        self.assertEqual(giveup.brief(self.root, '0x2000'), '')
        self.assertEqual(giveup.lines_for(self.root, ['0x2000']), [])

    def test_an_invalid_record_is_not_written(self):
        with self.assertRaises(ValueError):
            giveup.add(self.root, '0x1004350', record(still_differs='mov eax, ecx'))
        self.assertFalse((self.root / 'data/giveups').exists())

    def test_a_file_edited_by_hand_is_refused_by_validate(self):
        path, _ = giveup.add(self.root, '0x1004350', record())
        name = path.relative_to(self.root).as_posix()
        doc = json.loads(path.read_text())
        self.assertIn('format', giveup.validate(name, json.dumps(doc), BUILD))
        doc['rva'] = '0x1004351'
        self.assertIn('identity', giveup.validate(name, giveup.dump(doc), BUILD))
        self.assertIn('bad-name', giveup.validate('data/giveups/x.json', giveup.dump(doc), BUILD))
        self.assertEqual(giveup.validate(name, 'not json', BUILD), ['not-json'])

    def test_keep_best_copies_the_files_and_points_at_them(self):
        src = self.root / 'U.cpp'
        src.write_text('int x;\n')
        ref = giveup.keep_best(self.root, '0x1004350', [src])
        self.assertEqual(ref, dict(kind='local', ref=f'.local/giveups/{BUILD}/1004350/1'))
        self.assertEqual(giveup.keep_best(self.root, '0x1004350', [src])['ref'], f'.local/giveups/{BUILD}/1004350/2')
        self.assertTrue((self.root / ref['ref'] / 'U.cpp').is_file())

    def test_check_command(self):
        giveup.add(self.root, '0x1004350', record())
        self.assertEqual(giveup.main(['--root', str(self.root), 'check']), 0)
        (self.root / f'data/giveups/{BUILD}/1004350.json').write_text('{}')
        self.assertEqual(giveup.main(['--root', str(self.root), 'check']), 1)

    def test_every_committed_record_is_valid(self):
        self.assertEqual(giveup.main(['check']), 0)

    def test_public_draft_and_history_share_the_giveup_identity(self):
        (self.root / 'data').mkdir()
        (self.root / 'data/progress.json').write_text('{"functions": []}')
        source = self.root / 'Toy.cpp'
        source.write_text('// Source exposure: black-box\n// 0x1000 Toy\n\nint Toy() { return 2; }\n')
        data = record(best_similarity=97)
        path, added = giveup.add(self.root, '0x1000', data, draft_from=source)
        self.assertTrue(added)
        self.assertFalse(giveup.add(self.root, '0x1000', data, draft_from=source)[1])
        draft = giveup.draft_path(self.root, BUILD, '0x1000')
        name = draft.relative_to(self.root).as_posix()
        self.assertEqual(draft.read_text(), giveup.draft_line(data) + '\n' + source.read_text())

        def read(name):
            path = self.root / name
            return path.read_bytes() if path.is_file() else None

        self.assertEqual(giveup.pair_problems(self.root, [name], read, set(), BUILD), [])
        matched = {(BUILD, '0x1000')}
        self.assertEqual(giveup.pair_problems(self.root, [name], read, matched, BUILD),
                         [(name, ['draft-target-or-status'])])
        self.assertEqual(giveup.retire(self.root, BUILD, '0x1000'), [name, path.relative_to(self.root).as_posix()])
        self.assertFalse(draft.exists())
        self.assertEqual(giveup.load(self.root, '0x1000')[0]['best_code'], dict(kind='draft-history', ref=name))
        self.assertEqual(giveup.pair_problems(self.root, [name], read, matched, BUILD), [])

    def test_invalid_public_source_leaves_existing_pair_untouched(self):
        (self.root / 'data').mkdir()
        (self.root / 'data/progress.json').write_text('{"functions": []}')
        source = self.root / 'Toy.cpp'
        source.write_text('// Source exposure: black-box\n// 0x1000 Toy\nint Toy() { return 2; }\n')
        path, _ = giveup.add(self.root, '0x1000', record(), draft_from=source)
        draft = giveup.draft_path(self.root, BUILD, '0x1000')
        before = draft.read_bytes(), path.read_bytes()
        with source.open('a') as stream:
            stream.write('// ' + 'mov' + ' eax, ecx\n')
        with self.assertRaisesRegex(ValueError, 'asm-mnemonic'):
            giveup.add(self.root, '0x1000', record(best_similarity=99), draft_from=source)
        self.assertEqual((draft.read_bytes(), path.read_bytes()), before)


class Surfaces(Repo):
    def test_the_unit_sheet_lists_earlier_give_ups_first(self):
        import unit_skeleton
        giveup.add(self.root, '0x1000', record())
        unit = dict(compiled='reconstruction/a/B.cpp', dir=self.root, brief='', task={'build_id': BUILD})
        fn = dict(rva='0x1000', size=10, community_name='B::f')
        sheet = unit_skeleton.function_sheet(unit, fn, repo=self.root)
        self.assertLess(sheet.index('Earlier give-ups for 0x1000'), sheet.index('## Signature and registers'))

    def test_contrib_next_row_and_claims_check_show_them(self):
        import claims
        giveup.add(self.root, '0x1000', record())
        self.assertIn('1 earlier give-up', giveup.brief(self.root, '0x1000'))
        self.assertTrue(hasattr(claims, 'main'))


class Release(Repo):
    def test_release_with_a_category_writes_the_record_from_the_last_compare(self):
        import contrib
        import types
        private = self.root / 'private'
        task = private / 'tasks' / 't1'
        task.mkdir(parents=True)
        (task / 'last-compare.json').write_text(json.dumps(dict(
            model='claude-sonnet-5-5', functions=[dict(rva='0x1000')],
            progress={'0x1000': dict(metric='aligned_matching_bytes', value=90, total=100)})))
        said = []
        ctx = types.SimpleNamespace(repo=self.root, private=private, cli='./sr', say=said.append)
        args = types.SimpleNamespace(category='control-flow', tried=['a short try'], still_differs='the loop exits elsewhere',
                                     suspected_cause='a different loop shape', note=None)
        from unittest import mock
        with mock.patch.object(contrib, 'load_config', lambda c: {}):
            path = contrib.file_giveup(ctx, 0x1000, args)
        rec = giveup.load(self.root, '0x1000')[0]
        self.assertEqual((rec['best_similarity'], rec['lane'], rec['harness'], rec['model']),
                         (90.0, 'contributor', 'sr', 'claude-sonnet-5-5'))
        self.assertEqual(path, f'data/giveups/{BUILD}/1000.json')
        args.still_differs = 'mov eax, ecx'
        with mock.patch.object(contrib, 'load_config', lambda c: {}), self.assertRaises(contrib.Stop):
            contrib.file_giveup(ctx, 0x2000, args)


class Scope(unittest.TestCase):
    def test_a_contributor_pr_may_carry_a_record_but_no_other_data_file(self):
        self.assertTrue(pr_bot.in_scope('data/giveups/sse-steam-1-7-104/1004350.json'))
        self.assertFalse(pr_bot.in_scope('data/giveups/sse-steam-1-7-104/../progress.json'))
        self.assertFalse(pr_bot.in_scope('data/giveups/sse-steam-1-7-104/1004350.txt'))
        self.assertFalse(pr_bot.in_scope('data/progress.json'))

    def test_records_alone_take_the_notes_lane(self):
        rows = [dict(filename='data/giveups/sse-steam-1-7-104/1004350.json', status='added')]
        self.assertTrue(pr_bot.notes_lane(rows))
        self.assertFalse(pr_bot.notes_lane(rows + [dict(filename='tools/x.py', status='added')]))
        draft = dict(filename=f'drafts/{BUILD}/1000.cpp', status='added')
        self.assertTrue(pr_bot.in_scope(draft['filename']))
        self.assertTrue(pr_bot.notes_lane(rows + [draft]))
        self.assertFalse(pr_bot.in_scope(f'drafts/{BUILD}/1000.txt'))

    def test_the_scope_job_regex_matches_the_bot_rule(self):
        import scope_check
        for name in (f'data/giveups/{BUILD}/1004350.json', f'data/giveups/{BUILD}/1004350.txt'):
            self.assertEqual(bool(scope_check.OUTSIDE_RECONSTRUCTION.fullmatch(name)), pr_bot.in_scope(name))

    def test_the_bot_validates_a_record_in_the_notes_checks(self):
        class Bot:
            def head_blob(self, head, name):
                return {'good': giveup.dump(dict(schema=1, build_id=BUILD, rva='0x1004350', records=[record()])).encode(),
                        'bad': b'{}'}[self.kind]
        for kind, expect in (('good', []), ('bad', ['shape'])):
            bot = Bot()
            bot.kind = kind
            found = pr_bot.Bot.note_problems(bot, 'head', [dict(filename=f'data/giveups/{BUILD}/1004350.json', status='added')])
            self.assertEqual([codes for _n, codes in found], [expect] if expect else [])


if __name__ == '__main__':
    unittest.main()
