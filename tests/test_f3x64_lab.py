"""tools/f3x64 lab compile, corpus and cluster helpers on toy data (no compiler, no game files)."""
import json
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'f3x64'))
import cluster  # noqa: E402
import corpus  # noqa: E402
import lab_compile  # noqa: E402
import lab_experiments as lab  # noqa: E402

LISTING = """\
_TEXT	SEGMENT
key$ = 32
ins$ = 40
fn	PROC					; fn, COMDAT
; Line 1
	sub	rsp, 56
	lea	rdx, QWORD PTR ins$[rsp]
	test	rcx, rcx
	je	SHORT $LN3@fn
	mov	QWORD PTR key$[rsp], 1
	npad	1
$LN3@fn:
	add	rsp, 56
	rex_jmp	QWORD PTR [rax]
fn	ENDP
_TEXT	ENDS
"""


class ListingTests(unittest.TestCase):
    def test_parse_replaces_stack_equates_and_keeps_rex_jmp(self):
        ins = lab_compile.parse_listing(LISTING)['fn']
        self.assertIn('lea rdx, QWORD PTR [rsp+40]', ins)
        self.assertIn('mov QWORD PTR [rsp+32], 1', ins)
        self.assertIn('rex_jmp QWORD PTR [rax]', ins)
        self.assertFalse(any(i.startswith('npad') for i in ins))

    def test_normalize_renames_labels_in_order(self):
        out = lab_compile.normalize(lab_compile.parse_listing(LISTING)['fn'])
        self.assertIn('je SHORT L0', out)
        self.assertIn('L0:', out)

    def test_two_spellings_with_different_label_names_compare_equal(self):
        other = LISTING.replace('$LN3@fn', '$LN9@fn')
        a = lab_compile.normalize(lab_compile.parse_listing(LISTING)['fn'])
        b = lab_compile.normalize(lab_compile.parse_listing(other)['fn'])
        self.assertEqual(a, b)


class ExperimentTests(unittest.TestCase):
    def test_ids_are_unique_and_every_variant_defines_the_function_under_test(self):
        ids = [e.ident for e in lab.E]
        self.assertEqual(len(ids), len(set(ids)))
        for exp in lab.E:
            self.assertGreaterEqual(len(exp.variants), 2, exp.ident)
            for var in exp.flags:
                self.assertIn(var, exp.variants, exp.ident)

    def test_judge_reports_failed_compile_as_error_not_pass(self):
        exp = lab.Exp('x', [0], 'claim', {'a': 'int fn(){return 1;}', 'b': 'int fn(){return 2;}'}, lambda R: True)
        R = {'a': [], 'b': [], 'a_rc': 0, 'b_rc': 2}
        self.assertEqual(lab.judge(exp, R)[0], 'error')

    def test_judge_maps_predicate_to_verdict(self):
        exp = lab.Exp('x', [0], 'claim', {'a': '', 'b': ''}, lambda R: R['a'] != R['b'])
        ok = {'a': ['x'], 'b': ['y'], 'a_rc': 0, 'b_rc': 0}
        self.assertEqual(lab.judge(exp, ok)[0], 'confirmed')
        same = {'a': ['x'], 'b': ['x'], 'a_rc': 0, 'b_rc': 0}
        self.assertEqual(lab.judge(exp, same)[0], 'contradicted')

    def test_judge_reports_a_broken_predicate_as_error(self):
        exp = lab.Exp('x', [0], 'claim', {'a': '', 'b': ''}, lambda R: R['missing'])
        self.assertEqual(lab.judge(exp, {'a': [], 'b': [], 'a_rc': 0, 'b_rc': 0})[0], 'error')

    def test_this_and_minus1_reads_register_families(self):
        ins = ['mov rdi, rcx', 'mov ebx, -1']
        self.assertEqual(lab.this_and_minus1(ins), ('d', 'b'))

    def test_stage_writes_sources_and_flags(self):
        exp = lab.Exp('t', [0], 'c', {'a': 'int fn(){return 1;}', 'b': 'int fn(){return 2;}'}, lambda R: True, flags={'b': ['/fp:fast']})
        with tempfile.TemporaryDirectory() as tmp:
            lab.stage([exp], tmp)
            self.assertTrue((Path(tmp) / 't__a.cpp').exists())
            self.assertEqual((Path(tmp) / 't__b.flags').read_text(), '/fp:fast')
            self.assertFalse((Path(tmp) / 't__a.flags').exists())


class CorpusTests(unittest.TestCase):
    def test_unwind_census_pairs_the_help_store_with_the_handler(self):
        asm = """\
?f@@YAXXZ PROC\t\t\t\t\t; f, COMDAT
\tmov\tQWORD PTR $T1[rsp], -2
?f@@YAXXZ ENDP
?g@@YAXXZ PROC\t\t\t\t\t; g, COMDAT
\tret\t0
?g@@YAXXZ ENDP
xdata\tSEGMENT
$unwind$?f@@YAXXZ DD 020f11H
\tDD\timagerel __CxxFrameHandler3
xdata\tENDS
"""
        with tempfile.TemporaryDirectory() as tmp:
            Path(tmp, 'u.asm').write_text(asm)
            census = corpus.unwind_census([tmp])
        self.assertEqual(census[('u', '?f@@YAXXZ')], (True, True))
        self.assertEqual(census[('u', '?g@@YAXXZ')], (False, False))
        counts = corpus.classify(census)
        self.assertEqual(counts[('help', 'handler')], 1)

    def test_line_effect_counts_matching_source_lines(self):
        idx = {('u', 's'): {'ins': [('shr eax, 3', 10), ('test al, 1', 10), ('ret 0', 11)],
                            'lines': {10: 'if ((x >> 3) & 1)', 11: '}'}}}
        total, hit, _ = corpus.line_effect(idx, r'>> 3', r'^shr')
        self.assertEqual((total, hit), (1, 1))
        total, hit, _ = corpus.line_effect(idx, r'>> 3', r'^bt')
        self.assertEqual((total, hit), (1, 0))

    def test_vftable_census_finds_thunks_beside_a_store(self):
        idx = {('u', '??_GX@@UEAAPEAXI@Z'): {'ins': [('ret 0', 1)], 'lines': {}},
               ('u', '??0X@@QEAA@XZ'): {'ins': [('lea rax, OFFSET FLAT:??_7X@@6B@', 1)], 'lines': {}},
               ('v', '??_GY@@UEAAPEAXI@Z'): {'ins': [('ret 0', 1)], 'lines': {}}}
        self.assertEqual(corpus.vftable_census(idx), (2, 1, 0, 0))

    def test_tail_census_separates_jumps_from_calls(self):
        idx = {('u', 'a'): {'ins': [('jmp get', 5)], 'lines': {5: 'return get(x);'}},
               ('u', 'b'): {'ins': [('call get', 5), ('ret 0', 5)], 'lines': {5: 'return get(x);'}}}
        jmp, call, calls = corpus.tail_census(idx)
        self.assertEqual((jmp, call, len(calls)), (1, 1, 1))

    def test_twins_reports_identical_and_differing_groups(self):
        body = {1: 'a;', 2: 'b;', 3: 'c;'}
        idx = {('u1', 's'): {'ins': [('ret 0', 1)], 'lines': body},
               ('u2', 's'): {'ins': [('ret 0', 1)], 'lines': body},
               ('u1', 't'): {'ins': [('ret 0', 1)], 'lines': {1: 'x;', 2: 'y;', 3: 'z;'}},
               ('u2', 't'): {'ins': [('xor eax, eax', 1), ('ret 0', 1)], 'lines': {1: 'x;', 2: 'y;', 3: 'z;'}}}
        same, differ, _ = corpus.twins(idx)
        self.assertEqual((same, differ), (1, 1))


class ClusterTests(unittest.TestCase):
    def test_hunk_kinds(self):
        k = cluster.hunk_kind
        self.assertEqual(k('operands', 'test ecx, ecx', 'test rcx, rcx'), 'width')
        self.assertEqual(k('operands', 'mov dword ptr [rsp + 0x50], 0x4', 'mov qword ptr [rsp + 0x50], 0x4'), 'width')
        self.assertEqual(k('operands', 'mov rbx, rcx', 'mov rdi, rcx'), 'regswap')
        self.assertEqual(k('numeric', 'mov rax, qword ptr [rcx + 0x8]', 'mov rax, qword ptr [rcx + 0x10]'), 'offset')
        self.assertEqual(k('numeric', 'mov edx, 0x1', 'mov edx, 0x38'), 'immediate')
        self.assertEqual(k('operands', 'je 0x96 <f+0x96>', 'je 0x1402d5d95 <.text+0x2d4d95>'), 'noise')
        self.assertEqual(k('delete', 'mov rax, rax', ''), 'only-sibling')
        self.assertEqual(k('insert', '', 'mov rax, rax'), 'only-target')

    def test_cluster_groups_functions_by_kind_set_and_skips_identical(self):
        scores = [
            {'rva': 1, 'n_cand': 10, 'n_tgt': 10, 'identical': False, 'diffs': [['operands', 'test ecx, ecx', 'test rcx, rcx']]},
            {'rva': 2, 'n_cand': 10, 'n_tgt': 10, 'identical': False, 'diffs': [['operands', 'cmp eax, 1', 'cmp rax, 1']]},
            {'rva': 3, 'n_cand': 10, 'n_tgt': 10, 'identical': True, 'diffs': []},
            {'rva': 4, 'n_cand': 10, 'n_tgt': 90, 'identical': False, 'diffs': [['operands', 'cmp eax, 1', 'cmp rax, 1']]},
        ]
        groups = cluster.cluster(scores)
        self.assertEqual(groups[('width',)], [1, 2])
        self.assertEqual(len(groups), 1)
        json.dumps({'+'.join(k): v for k, v in groups.items()})


if __name__ == '__main__':
    unittest.main()
