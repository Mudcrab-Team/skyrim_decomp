"""Tests for tools/verifier/auto_hints.py and the alignment evidence it reads (synthetic listings, no game data)."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
sys.path.insert(0, str(ROOT / 'tests'))
import align  # noqa: E402
import auto_hints  # noqa: E402
import test_align as ta  # noqa: E402

TARGET_SYMBOLS = ta.SYMBOLS
# The candidate's names are the drafter's own, absent from the map.
OPEN = {k: v for k, v in ta.SYMBOLS.items() if k not in ('g_limit', '?Small@@YAXH@Z', '?Big@@YAXH@Z')}


def derive_pairs(target_rows, cand_rows, symbols=None):
    _, data = ta.run(target_rows, cand_rows, symbols=OPEN if symbols is None else symbols)
    return data['reference_pairs']


class Pairs(unittest.TestCase):
    def test_unresolved_names_vote_for_the_target_rva(self):
        pairs = derive_pairs(ta.BASE_ROWS, ta.BASE_ROWS)
        self.assertEqual(pairs['references']['g_limit'], {hex(0x5000): 1})
        self.assertEqual(pairs['references']['?Small@@YAXH@Z'], {hex(0x3000): 1})
        self.assertEqual(pairs['references']['?Big@@YAXH@Z'], {hex(0x3100): 1})
        self.assertEqual(pairs['thread_locals'], {})

    def test_resolved_names_vote_too_so_a_wrong_binding_shows(self):
        pairs = derive_pairs(ta.BASE_ROWS, ta.BASE_ROWS, symbols=ta.SYMBOLS)
        self.assertEqual(pairs['references']['g_limit'], {hex(0x5000): 1})
        wrong = dict(ta.SYMBOLS, g_limit=0x5008)
        pairs = derive_pairs(ta.BASE_ROWS, ta.BASE_ROWS, symbols=wrong)
        self.assertEqual(pairs['references']['g_limit'], {hex(0x5000): 1})

    def test_alignment_pairs_where_position_would_not(self):
        # An extra instruction in front moves every candidate offset, so the target's field at the same
        # offset is another instruction's; the aligned pair still names the right callee.
        extra = [(None, '90', 'nop', None)]
        shifted = ta.BASE_ROWS[:3] + extra + ta.BASE_ROWS[3:]
        pairs = derive_pairs(ta.BASE_ROWS, shifted)
        self.assertEqual(pairs['references']['?Small@@YAXH@Z'], {hex(0x3000): 1})
        self.assertEqual(pairs['references']['g_limit'], {hex(0x5000): 1})

    def test_same_symbol_used_twice_counts_each_pair(self):
        twice = ta.BASE_ROWS[:10] + [ta.BASE_ROWS[4]] + ta.BASE_ROWS[10:]
        pairs = derive_pairs(twice, twice)
        self.assertEqual(pairs['references']['g_limit'], {hex(0x5000): 2})

    def test_a_different_mnemonic_is_no_vote(self):
        other = ta.replace(ta.BASE_ROWS, 4, (None, '8d 1d ?? ?? ?? ??', 'lea ebx, [{T}]', ('rip', 'g_limit')))
        pairs = derive_pairs(other, ta.BASE_ROWS)
        self.assertNotIn('g_limit', pairs['references'])

    def test_thread_local_offset_is_the_difference_of_the_operand(self):
        target = ('  0: 8b 82 68 07 00 00\tmov\teax, dword ptr [rdx + 0x768]\n'
                  '  6: c3\tret\n')
        candidate = ('  0: 8b 82 00 00 00 00\tmov\teax, dword ptr [rdx]\n'
                     '\t\t0000000000000002:  IMAGE_REL_AMD64_SECREL\ttlsvar\n'
                     '  6: c3\tret\n')
        t = align.build(align.parse_listing(target), size=7)
        c = align.build(align.parse_listing(candidate), symbols={}, candidate=True)
        result = align.analyse(t, c)
        pairs = align.reference_pairs(t, c, result['ops'])
        self.assertEqual(pairs['thread_locals'], {'tlsvar': {'0x768': 1}})
        self.assertEqual(pairs['references'], {})


class Choose(unittest.TestCase):
    def test_single_value_wins(self):
        self.assertEqual(auto_hints.choose({0x10: 3}), (0x10, None))

    def test_majority_wins_and_a_tie_does_not(self):
        self.assertEqual(auto_hints.choose({0x10: 3, 0x20: 1})[0], 0x10)
        value, why = auto_hints.choose({0x10: 2, 0x20: 2})
        self.assertIsNone(value)
        self.assertIn('disagree', why)
        self.assertIsNone(auto_hints.choose({0x10: 2, 0x20: 1, 0x30: 1})[0])

    def test_unlisted_targets_are_dropped_before_counting(self):
        value, why = auto_hints.choose({0x10: 5, 0x20: 1}, lambda v: v == 0x20)
        self.assertEqual(value, 0x20)
        value, why = auto_hints.choose({0x10: 5}, lambda v: False)
        self.assertIsNone(value)
        self.assertIn('lists', why)

    def test_no_votes(self):
        self.assertEqual(auto_hints.choose({}), (None, 'no aligned instruction'))


def make_task(tmp, references, hints=None, with_pairs=None):
    """A task directory with one function, its pack, and an attempt directory holding align.json."""
    repo = Path(tmp) / 'repo'
    pack = repo / 'packs' / '0x1000'
    pack.mkdir(parents=True)
    (pack / 'pack.json').write_text(json.dumps({'references': [{'target_rva': r, 'community_names': []} for r in references]}))
    tdir = Path(tmp) / 'task'
    dest = tdir / 'attempts' / '001'
    (dest / '0x1000').mkdir(parents=True)
    (dest / 'candidate.obj').write_bytes(b'')
    (tdir / 'task.json').write_text(json.dumps({
        'task_id': 'toy', 'build_id': 'b', 'symbols': 'symbols.json',
        'functions': [{'rva': '0x1000', 'size': 20, 'symbol': '?F@@YAXXZ', 'pack': 'packs/0x1000'}]}))
    (tdir / 'symbols.json').write_text('{"symbols": {}}')
    if hints is not None:
        (tdir / 'bind-hints.json').write_text(json.dumps(hints))
    (dest / '0x1000' / 'align.json').write_text(json.dumps({'reference_pairs': with_pairs}))
    return repo, tdir, dest


class Derive(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)

    def derive(self, repo, tdir, dest, unbound, tls=()):
        report = {'unbound_references': list(unbound), 'unbound_thread_locals': list(tls)}
        return auto_hints.derive(tdir, dest, report, {}, repo=repo)

    def test_listed_target_is_written(self):
        pairs = {'references': {'g_a': {'0x5000': 2}, 'g_b': {'0x6000': 1}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000], with_pairs=pairs)
        added, skipped, _ = self.derive(repo, tdir, dest, ['g_a', 'g_b'])
        self.assertEqual(added, {'g_a': '0x5000'})
        self.assertIn('g_b', skipped)
        written = json.loads((tdir / 'bind-hints.json').read_text())
        self.assertEqual(written['g_a'], '0x5000')
        self.assertEqual(written[auto_hints.DERIVED_NOTE], 'g_a')
        import bind
        self.assertEqual(bind.load_hints(tdir), {'g_a': 0x5000})

    def test_a_hint_a_person_wrote_is_kept(self):
        pairs = {'references': {'g_a': {'0x5000': 2}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000, 0x7000], hints={'g_a': '0x7000', 'other': '0x1'},
                                     with_pairs=pairs)
        self.derive(repo, tdir, dest, ['g_a'])
        written = json.loads((tdir / 'bind-hints.json').read_text())
        self.assertEqual(written, {'g_a': '0x7000', 'other': '0x1'})

    def test_derived_note_accumulates_without_touching_entries(self):
        repo, tdir, dest = make_task(self.tmp.name, [0x5000, 0x6000], hints={'old': '0x1', auto_hints.DERIVED_NOTE: 'old'},
                                     with_pairs={'references': {'g_b': {'0x6000': 1}}, 'thread_locals': {}})
        self.derive(repo, tdir, dest, ['g_b'])
        written = json.loads((tdir / 'bind-hints.json').read_text())
        self.assertEqual(written[auto_hints.DERIVED_NOTE], 'g_b, old')
        self.assertEqual(written['old'], '0x1')

    def test_disagreeing_votes_write_nothing(self):
        pairs = {'references': {'g_a': {'0x5000': 1, '0x6000': 1}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000, 0x6000], with_pairs=pairs)
        added, skipped, _ = self.derive(repo, tdir, dest, ['g_a'])
        self.assertEqual(added, {})
        self.assertIn('disagree', skipped['g_a'])
        self.assertFalse((tdir / 'bind-hints.json').exists())

    def test_thread_local_hint_has_the_tls_form(self):
        pairs = {'references': {}, 'thread_locals': {'tlsvar': {'0x768': 3}}}
        repo, tdir, dest = make_task(self.tmp.name, [], with_pairs=pairs)
        added, _, _ = self.derive(repo, tdir, dest, [], ['tlsvar'])
        self.assertEqual(added, {'tlsvar': 'tls:0x768'})
        import bind
        self.assertEqual(bind.load_tls_hints(tdir), {'tlsvar': 0x768})

    def test_a_position_binding_the_alignment_contradicts_is_corrected_only_on_request(self):
        pairs = {'references': {'g_a': {'0x5000': 3}, 'g_lit': {'0x5000': 3}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000, 0x6000], with_pairs=pairs)
        (tdir / 'symbols.json').write_text(json.dumps({'symbols': {'g_a': {'rva': 0x6000}, '__real@3f800000': {'rva': 0x6000}}}))
        report = {'unbound_references': [], 'unbound_thread_locals': []}
        self.assertEqual(auto_hints.derive(tdir, dest, report, {}, repo=repo), ({}, {}, []))
        added, skipped, _ = auto_hints.derive(tdir, dest, report, {}, repo=repo, correct=True)
        self.assertEqual(added, {'g_a': '0x5000'})
        self.assertEqual(skipped, {})

    def test_a_binding_the_alignment_agrees_with_is_left_alone(self):
        pairs = {'references': {'g_a': {'0x5000': 3}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000], with_pairs=pairs)
        (tdir / 'symbols.json').write_text(json.dumps({'symbols': {'g_a': {'rva': 0x5000}}}))
        added, _, _ = auto_hints.derive(tdir, dest, {'unbound_references': []}, {}, repo=repo, correct=True)
        self.assertEqual(added, {})

    def test_a_public_map_is_never_corrected(self):
        pairs = {'references': {'g_a': {'0x5000': 3}}, 'thread_locals': {}}
        repo, tdir, dest = make_task(self.tmp.name, [0x5000], with_pairs=pairs)
        task = json.loads((tdir / 'task.json').read_text())
        task['symbols'] = 'reports/b/symbol-map.json'
        (tdir / 'task.json').write_text(json.dumps(task))
        added, _, _ = auto_hints.derive(tdir, dest, {'unbound_references': []}, {}, repo=repo, correct=True)
        self.assertEqual(added, {})

    def test_nothing_unbound_reads_nothing(self):
        repo, tdir, dest = make_task(self.tmp.name, [0x5000], with_pairs=None)
        self.assertEqual(self.derive(repo, tdir, dest, []), ({}, {}, []))

    def test_describe_lists_derived_and_skipped(self):
        lines = auto_hints.describe({'g_a': '0x5000'}, {'g_b': 'the aligned instructions disagree'})
        self.assertIn('derived 1 bind hint', lines[0])
        self.assertIn('g_b', lines[1])

    def test_merge_keeps_first_bindings_and_second_flags(self):
        first = {'functions': [{'rva': '0x1'}], 'references': [{'symbol': 'a'}], 'renamed': [], 'destructor_choices': [],
                 'warnings': [], 'changed': True, 'unbound_references': ['x']}
        second = {'functions': [], 'references': [{'symbol': 'x'}], 'renamed': [], 'destructor_choices': [],
                  'warnings': [], 'changed': False, 'unbound_references': []}
        merged = auto_hints.merge_reports(first, second)
        self.assertEqual([r['symbol'] for r in merged['references']], ['a', 'x'])
        self.assertTrue(merged['changed'])
        self.assertEqual(merged['unbound_references'], [])


class SummaryCache(unittest.TestCase):
    def test_summary_written_by_a_host_is_reused(self):
        with tempfile.TemporaryDirectory() as tmp:
            fdir = Path(tmp)
            self.assertIsNone(align.cached_summary(fdir))
            (fdir / 'align.json').write_text('{}')
            (fdir / 'align.txt').write_text('listing')
            (fdir / align.SUMMARY_FILE).write_text('aligned: distance 1\nclasses: x 1 (1)\n')
            lines = align.cached_summary(fdir)
            self.assertEqual(lines[:2], ['aligned: distance 1', 'classes: x 1 (1)'])
            self.assertIn('align.txt', lines[-1])
            self.assertEqual(align.attempt_summary(fdir, None, None, fdir / 'none.obj', {'symbol': 's'}), lines)


class AliasMessage(unittest.TestCase):
    """What attempt says for `undeclared-alias` (a second name at the function's RVA in the symbol map)."""

    def setUp(self):
        import importlib.util
        from importlib.machinery import SourceFileLoader
        loader = SourceFileLoader('attempt_alias_test', str(ROOT / 'tools' / 'verifier' / 'attempt'))
        spec = importlib.util.spec_from_loader('attempt_alias_test', loader)
        self.attempt = importlib.util.module_from_spec(spec)
        loader.exec_module(self.attempt)
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dest = Path(self.tmp.name)
        (self.dest / 'candidate.obj').write_bytes(b'')
        (self.dest / 'symbols.json').write_text(json.dumps({'symbols': {
            '?Own@@YAXXZ': {'rva': 0x2000}, '?Held@@YAXXZ': {'rva': 0x2000}, '?Other@@YAXXZ': {'rva': 0x3000}}}))
        self.task = {'symbols_local': self.dest / 'symbols.json',
                     'functions': [{'rva': 0x2000, 'size': 8, 'symbol': '?Own@@YAXXZ'},
                                   {'rva': 0x3000, 'size': 8, 'symbol': '?Other@@YAXXZ'}]}

    def test_silent_without_the_reason(self):
        self.assertEqual(self.attempt.alias_lines(self.task, self.dest, {0x2000: 'all-checks-passed'}), [])

    def test_names_the_ci_hash_line_when_the_object_defines_the_mapped_name(self):
        from unittest import mock
        with mock.patch('pecoff.CoffObject', lambda blob: object()), \
                mock.patch.object(self.attempt.bind, 'defined_functions', lambda obj: {'?Own@@YAXXZ': 1, '?Held@@YAXXZ': 2}):
            lines = self.attempt.alias_lines(self.task, self.dest, {0x2000: 'undeclared-alias', 0x3000: 'all-checks-passed'})
        self.assertEqual(len(lines), 1)
        self.assertIn('// CI hash: 0x2000 ?Held@@YAXXZ', lines[0])
        self.assertIn('?Own@@YAXXZ', lines[0])

    def test_explains_a_mapped_name_the_unit_does_not_define(self):
        lines = self.attempt.alias_lines(self.task, self.dest, {0x2000: 'undeclared-alias'})
        self.assertEqual(len(lines), 1)
        self.assertIn('does not define it', lines[0])
        self.assertIn('?Held@@YAXXZ', lines[0])
        self.assertNotIn('CI hash', lines[0])


if __name__ == '__main__':
    unittest.main()
