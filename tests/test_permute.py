"""Tests for tools/verifier/permute.py on original synthetic C++ (no game data, no Boat machine)."""
import copy
import difflib
import json
from pathlib import Path
import random
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import permute  # noqa: E402

# An original toy unit: a counter with a lookup, written for these tests.
UNIT = '''// toy unit
#include "Toy.h"

int Helper(int a_value);

bool Toy::Probe(Node* a_node, unsigned int a_limit)
{
    // leading comment kept with the first statement
    int total = 0;
    unsigned int count;
    Node* next = a_node->next;
    Fill(&count);
    if (a_node == nullptr) {
        return false;
    }
    if (a_node->flags & 4) {
        total = Helper(a_node->value);
    } else {
        total = a_node->value + 1;
    }
    for (unsigned int i = 0; i < a_limit; ++i) {
        total += Helper(i);
    }
    while (next) {
        next = next->next;
    }
    if (total > 3 && a_limit != 0) {
        count = a_limit;
        count++;
    }
    Helper(a_node->value);
    int kind = a_node->kind;
    switch (kind) {
    case 1:
        return true;
    default:
        total = 2;
        break;
    }
    return total < static_cast<int>(a_limit) + a_node->value;
}

int Toy::Other()
{
    return Value() + 1;
}
'''


def body_unit():
    return permute.Unit(UNIT, 'Toy::Probe')


class Tokens(unittest.TestCase):
    def test_round_trip(self):
        toks, tail = permute.lex(UNIT)
        self.assertEqual(permute.emit_toks(toks) + tail, UNIT)

    def test_find_body_and_parse(self):
        u = body_unit()
        self.assertTrue(UNIT[u.start:u.end].startswith('{'))
        self.assertTrue(UNIT[u.start:u.end].rstrip().endswith('}'))
        self.assertEqual(u.with_body(u.body_of(u.block)), UNIT)
        kinds = [type(s).__name__ for s in u.block.stmts]
        self.assertEqual(kinds, ['Simple', 'Simple', 'Simple', 'Simple', 'If', 'If', 'Loop', 'Loop', 'If', 'Simple',
                                 'Simple', 'Loop', 'Simple'])

    def test_several_bodies(self):
        u = permute.Unit(UNIT, 'Toy::Probe', ['Toy::Other'])
        self.assertEqual(len(u.spans), 2)
        self.assertEqual(u.with_body(u.body_of(u.forest())), UNIT)
        forest = copy.deepcopy(u.forest())
        rng = random.Random(2)
        names = []
        for _ in range(40):
            names += permute.mutate_forest(forest, rng, 1)
        text = u.with_body(u.body_of(forest))
        permute.Unit(text, 'Toy::Probe', ['Toy::Other'])
        self.assertTrue(any(n.endswith('@1') for n in names), names)
        self.assertTrue(any('@' not in n for n in names), names)
        with self.assertRaises(ValueError):
            permute.Unit(UNIT, 'Toy::Probe', ['Toy::Probe'])

    def test_out_init(self):
        src = 'void T::F()\n{\n    char* message = nullptr;\n    Format(&message);\n    Free(message);\n}\n'
        u = permute.Unit(src, 'T::F')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_out_init(tree, random.Random(0)))
        self.assertIn('char* message;', u.body_of(tree))
        self.assertTrue(permute.m_out_init(tree, random.Random(0)))
        self.assertIn('char* message = nullptr;', u.body_of(tree))

    def test_definition_must_be_unique(self):
        with self.assertRaises(ValueError):
            permute.find_body(UNIT + '\nbool Toy::Probe(Node* a, unsigned int b)\n{\n    return true;\n}\n',
                              'Toy::Probe')
        with self.assertRaises(ValueError):
            permute.find_body(UNIT, 'Toy::Missing')

    def test_decl_info(self):
        u = body_unit()
        names = [permute.decl_info(s) and permute.decl_info(s)[1] for s in u.block.stmts[:3]]
        self.assertEqual(names, ['total', 'count', 'next'])
        self.assertIsNone(permute.decl_info(u.block.stmts[-1]))


def apply_one(name, seed=0):
    u = body_unit()
    tree = copy.deepcopy(u.block)
    rng = random.Random(seed)
    for _ in range(20):
        if permute.MUTATIONS[name][0](tree, rng):
            return u.body_of(tree)
    return None


def diff(a, b):
    return [line for line in difflib.ndiff(a.splitlines(), b.splitlines()) if line[:1] in '+-']


class Mutations(unittest.TestCase):
    def test_every_mutation_applies_and_reparses(self):
        base = body_unit().body_of(body_unit().block)
        for name in permute.MUTATIONS:
            with self.subTest(name=name):
                out = apply_one(name)
                self.assertIsNotNone(out, f'{name} found no site in the toy unit')
                self.assertNotEqual(out, base)
                block, tail = permute.parse_body(out)
                self.assertEqual(permute.emit(block, tail), out)

    def test_return_through_replaces_assign_and_break(self):
        out = ' '.join(apply_one('return-through').split())
        self.assertIn('default: return 2;', out)

    def test_zero_form_names_and_inlines_a_zero(self):
        text = ('int Toy::Z(int a)\n{\n    const float lo = 0.0f;\n    float r = a;\n'
                '    if (!(r >= lo)) {\n        r = lo;\n    }\n    return r;\n}\n')
        u = permute.Unit(text, 'Toy::Z')
        seen = set()
        for seed in range(40):
            tree = copy.deepcopy(u.block)
            if permute.m_zero_form(tree, random.Random(seed)):
                seen.add(' '.join(u.body_of(tree).split()))
        self.assertTrue(any('r = 0.0f;' in s or '>= 0.0f' in s for s in seen))
        base = ' '.join(u.body_of(u.block).split())
        self.assertTrue(seen and all(s != base for s in seen))

    def test_zero_form_introduces_a_zero_local_when_none_exists(self):
        text = 'int Toy::Z(int a)\n{\n    int r = a;\n    if (r < 0) {\n        r = 0;\n    }\n    return r;\n}\n'
        u = permute.Unit(text, 'Toy::Z')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_zero_form(tree, random.Random(0)))
        self.assertIn('const int zero_ = 0;', ' '.join(u.body_of(tree).split()))

    def test_find_body_matches_a_destructor(self):
        text = 'Toy::Toy() = default;\n\nToy::~Toy()\n{\n    Clear();\n}\n'
        start, end = permute.find_body(text, 'Toy::~Toy')
        self.assertEqual(text[start:end].strip(), '{\n    Clear();\n}')

    def test_if_invert(self):
        out = apply_one('if-invert')
        self.assertIn('if (!(a_node->flags & 4))', ' '.join(out.split()))

    def test_compare_flip(self):
        u = body_unit()
        tree = copy.deepcopy(u.block)
        lst = tree.stmts[4].cond
        site = permute.binary_sites(lst, set(permute.FLIP))[0]
        permute.swap_operands(lst, *site, permute.FLIP[lst[site[1]].text])
        self.assertEqual(permute.emit_toks(lst).strip(), 'nullptr == a_node')

    def test_template_angle_is_not_a_comparison(self):
        toks, _ = permute.lex('return total < static_cast<int>(a_limit);')
        sites = permute.binary_sites(toks, set(permute.FLIP))
        self.assertEqual(sites, [])

    def test_declaration_is_not_a_product(self):
        src = 'void T::F()\n{\n    Zone* zone;\n    Zone& ref = Get();\n    int n = a * b;\n}\n'
        u = permute.Unit(src, 'T::F')
        sites = permute.expr_sites(u.block, permute.COMMUTE)
        self.assertEqual([permute.emit_toks(lst[s:e]).strip() for lst, (s, k, e) in sites], ['a * b'])

    def test_loop_form_round(self):
        u = body_unit()
        tree = copy.deepcopy(u.block)
        rng = random.Random(3)
        seen = set()
        for _ in range(40):
            t = copy.deepcopy(tree)
            if permute.m_loop_form(t, rng):
                seen.add(' '.join(u.body_of(t).split()))
        joined = '\n'.join(seen)
        self.assertIn('while ( i < a_limit) {', joined.replace('while (i', 'while ( i'))
        self.assertIn('for (; next;)', joined.replace('for (;next;)', 'for (; next;)'))

    def test_early_return_nest_and_flatten(self):
        src = 'void T::F(int a)\n{\n    if (a) {\n        return;\n    }\n    G();\n}\n'
        u = permute.Unit(src, 'T::F')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_early_return(tree, random.Random(0)))
        nested = ' '.join(u.body_of(tree).split())
        self.assertIn('else {', nested)
        self.assertTrue(permute.m_early_return(tree, random.Random(0)))
        self.assertEqual(' '.join(u.body_of(tree).split()), ' '.join(u.body_of(u.block).split()))

    def test_temp_inline_single_use(self):
        src = 'int T::F(P* p)\n{\n    int v = p->Get();\n    return v + 1;\n}\n'
        u = permute.Unit(src, 'T::F')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_temp_inline(tree, random.Random(0)))
        self.assertEqual(' '.join(u.body_of(tree).split()), '{ return static_cast<int>(p->Get()) + 1; }')

    def test_temp_inline_refuses_written_local(self):
        src = 'int T::F(P* p)\n{\n    int v = p->Get();\n    v += 2;\n    return v;\n}\n'
        u = permute.Unit(src, 'T::F')
        self.assertFalse(permute.m_temp_inline(copy.deepcopy(u.block), random.Random(0)))

    def test_temp_introduce_names_a_repeated_member(self):
        src = 'int T::F(P* p)\n{\n    G(p->m);\n    return p->m;\n}\n'
        u = permute.Unit(src, 'T::F')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_temp_introduce(tree, random.Random(0)))
        self.assertEqual(' '.join(u.body_of(tree).split()), '{ auto v0 = p->m; G(v0); return v0; }')

    def test_temp_introduce_refuses_written_member(self):
        src = 'int T::F(P* p)\n{\n    G(p->m);\n    p->m = 2;\n    return p->m;\n}\n'
        u = permute.Unit(src, 'T::F')
        self.assertFalse(permute.m_temp_introduce(copy.deepcopy(u.block), random.Random(0)))

    def test_and_split_and_join(self):
        src = 'void T::F(int a, int b)\n{\n    if (a && b) {\n        G();\n    }\n}\n'
        u = permute.Unit(src, 'T::F')
        tree = copy.deepcopy(u.block)
        self.assertTrue(permute.m_and_split(tree, random.Random(0)))
        self.assertEqual(' '.join(u.body_of(tree).split()), '{ if (a) { if (b) { G(); } } }')
        self.assertTrue(permute.m_and_split(tree, random.Random(1)))
        self.assertEqual(' '.join(u.body_of(tree).split()), '{ if (a && b) { G(); } }')

    def test_increment_forms(self):
        src = 'void T::F(int i)\n{\n    i++;\n}\n'
        u = permute.Unit(src, 'T::F')
        outs = set()
        for seed in range(12):
            tree = copy.deepcopy(u.block)
            permute.m_increment(tree, random.Random(seed))
            outs.add(' '.join(u.body_of(tree).split()))
        self.assertEqual(outs, {'{ ++i; }', '{ i += 1; }', '{ i = i + 1; }'})

    def test_int_type_and_switch_width(self):
        src = 'void T::F(int a)\n{\n    std::uint32_t n = 0;\n    switch (a) {\n    default:\n        break;\n    }\n}\n'
        u = permute.Unit(src, 'T::F')
        outs = set()
        for seed in range(30):
            tree = copy.deepcopy(u.block)
            permute.m_int_type(tree, random.Random(seed))
            outs.add(' '.join(u.body_of(tree).split()))
        self.assertTrue(any('std::int32_t n' in o for o in outs))
        self.assertTrue(any('switch (static_cast<std::uint32_t>(a))' in o for o in outs))

    def test_deterministic_for_a_seed(self):
        def run(seed):
            u = body_unit()
            tree = copy.deepcopy(u.block)
            applied = permute.mutate(tree, random.Random(seed), 4)
            return applied, u.body_of(tree)
        self.assertEqual(run(7), run(7))
        self.assertNotEqual(run(7), run(8))

    def test_random_stacks_always_reparse(self):
        u = body_unit()
        rng = random.Random(11)
        for _ in range(300):
            tree = copy.deepcopy(u.block)
            permute.mutate(tree, rng, rng.randint(1, 5))
            out = u.body_of(tree)
            block, tail = permute.parse_body(out)
            self.assertEqual(permute.emit(block, tail), out)
            permute.Unit(u.with_body(out), 'Toy::Probe')


class Batches(unittest.TestCase):
    def test_candidate_archive_round_trip(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'cands-0001.tar'
            sources = {'v00001': 'int a;\n', 'v00002': 'int b;\n'}
            permute.write_cands(path, sources)
            self.assertEqual(permute.read_cands(path), sources)

    def test_candidate_archive_refuses_other_names(self):
        import io
        import tarfile
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'cands-0001.tar'
            with tarfile.open(path, 'w:xz') as tar:
                info = tarfile.TarInfo('../x.cpp')
                info.size = 0
                tar.addfile(info, io.BytesIO(b''))
            with self.assertRaises(ValueError):
                permute.read_cands(path)

    def _run_dir(self, root):
        repo = Path(root) / 'repo'
        (repo / '.unit').mkdir(parents=True)
        (repo / 'reconstruction').mkdir()
        (repo / 'reconstruction' / 'unit.cpp').write_text('base')
        (repo / '.unit' / 'spec.json').write_text(json.dumps({'compiled': 'reconstruction/unit.cpp'}))
        return Path(root)

    def test_compile_batch_uses_worker_copies_and_reports_failures(self):
        seen = []

        def compile_one(worker, compiled, cid):
            text = (worker / 'repo' / compiled).read_text()
            seen.append((cid, text, worker.name))
            if 'bad' in text:
                return 2, 'x.cpp(3): error C2065: oops\nerror C2143: more', None
            obj = worker / f'{cid}.obj'
            obj.write_bytes(text.encode())
            return 0, '', obj

        with tempfile.TemporaryDirectory() as d:
            run = self._run_dir(d)
            rows, objects = permute.compile_batch(run, {'v00001': 'one', 'v00002': 'bad', 'v00003': 'three'}, 2,
                                                  compile_one)
            by = {r['id']: r for r in rows}
            self.assertEqual(by['v00001']['st'], 'compiled')
            self.assertEqual(by['v00002']['st'], 'compile-failed')
            self.assertEqual(by['v00002']['codes'], ['C2065', 'C2143'])
            self.assertEqual(objects, {'v00001': b'one', 'v00003': b'three'})
            self.assertLessEqual(len({w for _, _, w in seen}), 2)
            self.assertEqual((run / 'repo' / 'reconstruction' / 'unit.cpp').read_text(), 'base')

    def test_compile_batch_survives_a_crashing_worker(self):
        def compile_one(worker, compiled, cid):
            raise OSError('disk')

        with tempfile.TemporaryDirectory() as d:
            rows, objects = permute.compile_batch(self._run_dir(d), {'v00001': 'x'}, 1, compile_one)
            self.assertEqual(rows[0]['st'], 'error')
            self.assertEqual(objects, {})

    def test_pc_batch_round_trip(self):
        import tarfile
        with tempfile.TemporaryDirectory() as d:
            run = self._run_dir(d)
            (run / 'repo' / 'recipe.json').write_text(json.dumps({'flags': ['/O2']}))
            (run / 'repo' / '.unit' / 'spec.json').write_text(
                json.dumps({'compiled': 'reconstruction/unit.cpp', 'recipe': 'recipe.json'}))
            permute.write_cands(run / 'cands-0001.tar', {'v00001': 'one'})

            def fake(msvc, loader, flags):
                self.assertEqual((msvc, loader, flags), ('tc', 'native', ['/O2']))

                def compile_one(worker, compiled, cid):
                    obj = worker / f'{cid}.obj'
                    obj.write_bytes(b'OBJ')
                    return 0, '', obj
                return compile_one

            real, permute.host_compiler = permute.host_compiler, fake
            try:
                args = type('A', (), dict(run=str(run), cands='cands-0001.tar', out='out-0001.tar', msvc='tc',
                                          loader='native', jobs=1))
                self.assertEqual(permute.pc_batch(args), 0)
            finally:
                permute.host_compiler = real
            self.assertFalse((run / 'cands-0001.tar').exists())
            with tarfile.open(run / 'out-0001.tar') as tar:
                self.assertEqual(sorted(tar.getnames()), ['rows.json', 'v00001.obj'])

    def test_pc_batch_refuses_odd_archive_names(self):
        args = type('A', (), dict(run='.', cands='../x.tar', out='out-0001.tar', msvc='t', loader='native', jobs=1))
        with self.assertRaises(SystemExit):
            permute.pc_batch(args)

    def test_function_hash_ignores_nothing_but_addresses_and_text(self):
        a = '   0: 48 89 5c 24 08\tmov qword ptr [rsp + 0x8], rbx\n   5: c3\tret\n'
        b = '   0: 48 89 5c 24 08\tmov qword ptr [rsp+8], rbx\n   5: c3\tret\n'
        c = '   0: 48 89 5c 24 10\tmov qword ptr [rsp + 0x10], rbx\n   5: c3\tret\n'
        self.assertEqual(permute.function_hash(a), permute.function_hash(b))
        self.assertNotEqual(permute.function_hash(a), permute.function_hash(c))


class SearchLoop(unittest.TestCase):
    """The search against a local scorer: distance = token edits to a hidden target body."""

    def scorer_for(self, target_body):
        target = [t.text for t in permute.lex(target_body)[0]]

        def score(cands):
            rows = []
            for c in cands:
                toks = [t.text for t in permute.lex('\n'.join(c['body']))[0]]
                sm = difflib.SequenceMatcher(a=target, b=toks, autojunk=False)
                d = sum(max(i2 - i1, j2 - j1) for op, i1, i2, j1, j2 in sm.get_opcodes() if op != 'equal')
                rows.append({'id': c['id'], 'st': 'ok', 'd': d, 'ex': d, 'n': len(toks), 'nt': len(target),
                             'h': str(hash(tuple(toks)))})
            return rows
        return score

    def test_recovers_perturbed_bodies(self):
        # Two random rule steps away from the target, as in the recovery test of docs/ideas-next.md
        # P3. The scorer here compares text, so the perturbation uses only rules whose inverse
        # spelling is in the catalogue (an inlined temporary comes back as a cast, never as the
        # original declaration, although the object code may well be the same).
        invertible = ['decl-swap', 'decl-move', 'decl-split', 'if-invert', 'early-return', 'and-split',
                      'compare', 'commute', 'test-form', 'increment']
        u = body_unit()
        target_body = u.body_of(u.block)
        recovered = 0
        for seed in range(6):
            start = copy.deepcopy(u.block)
            permute.mutate(start, random.Random(seed), 2, names=invertible)
            perturbed = permute.Unit(u.with_body(u.body_of(start)), 'Toy::Probe')
            search = permute.Search(perturbed, self.scorer_for(target_body), lambda text: [], random.Random(1),
                                    batch=24, patience=20, budget=10 ** 6, log=lambda m: None)
            result = search.run()
            self.assertLessEqual(result['best']['d'], result['start']['d'])
            recovered += result['status'] == 'distance-0'
        self.assertGreaterEqual(recovered, 4)

    def test_lint_gate_drops_candidates(self):
        u = body_unit()
        calls = []

        def lint(text):
            calls.append(text)
            return [] if text == UNIT else ['refused']
        search = permute.Search(u, self.scorer_for('{ return 0; }'), lint, random.Random(1),
                                batch=4, patience=2, budget=10 ** 6, log=lambda m: None)
        result = search.run()
        self.assertEqual(result['candidates'], 1)  # only the base was scored
        self.assertGreater(result['lint_rejected'], 0)
        self.assertEqual(result['status'], 'patience')

    def test_base_must_pass_lint(self):
        u = body_unit()
        search = permute.Search(u, self.scorer_for('{}'), lambda text: ['bad'], random.Random(1), log=lambda m: None)
        self.assertEqual(search.run()['status'], 'base-lint-failed')

    def test_budget_stops(self):
        u = body_unit()
        ticks = iter([0, 0] + [10 ** 6] * 1000)
        search = permute.Search(u, self.scorer_for('{ return 0; }'), lambda text: [], random.Random(1),
                                budget=5, log=lambda m: None, clock=lambda: next(ticks))
        self.assertEqual(search.run()['status'], 'budget')

    def test_seen_set_keys_on_object_hash(self):
        u = body_unit()

        def score(cands):
            return [{'id': c['id'], 'st': 'ok', 'd': 5, 'ex': 5, 'n': 1, 'nt': 1, 'h': 'same'} for c in cands]
        search = permute.Search(u, score, lambda text: [], random.Random(1), batch=4, patience=3,
                                budget=10 ** 6, log=lambda m: None)
        result = search.run()
        self.assertEqual(result['unique_objects'], 1)
        self.assertTrue(all(not r.get('new_object', False) for r in search.history[1:]))

    def test_dry_rounds_widen_then_stop_as_pool_exhausted(self):
        u = body_unit()
        rounds = []

        def score(cands):
            return [{'id': c['id'], 'st': 'ok', 'd': 5, 'ex': 5, 'n': 1, 'nt': 1, 'h': 'same'} for c in cands]
        search = permute.Search(u, score, lambda text: [], random.Random(1), batch=4, patience=1000,
                                budget=10 ** 6, log=lambda m: None, on_round=rounds.append)
        result = search.run()
        self.assertEqual(result['status'], 'pool-exhausted')
        self.assertEqual(search.widen, search.max_steps_cap - search.max_steps)
        self.assertGreater(len(rounds), 1)  # flushed every round, and once after the base

    def test_pool_exhaustion_reseeds_before_ending(self):
        u = body_unit()
        n = [0]
        logs = []

        def score(cands):
            out = []
            for c in cands:
                n[0] += 1
                out.append({'id': c['id'], 'st': 'ok', 'd': 5, 'ex': 5, 'n': 1, 'nt': 1,
                            'h': f'h{n[0]}' if n[0] <= 5 else 'same'})
            return out
        search = permute.Search(u, score, lambda text: [], random.Random(1), batch=4, patience=0,
                                budget=10 ** 6, log=logs.append, reseeds=2)
        result = search.run()
        self.assertEqual(result['status'], 'pool-exhausted')
        self.assertEqual(search.reseeds_left, 0)
        self.assertEqual(sum('reseeding' in m for m in logs), 2)

    def test_patience_zero_means_no_patience_limit(self):
        u = body_unit()
        n = [0]

        def score(cands):
            out = []
            for c in cands:
                n[0] += 1
                out.append({'id': c['id'], 'st': 'ok', 'd': 5, 'ex': 5, 'n': 1, 'nt': 1, 'h': f'h{n[0]}'})
            return out
        search = permute.Search(u, score, lambda text: [], random.Random(1), batch=4, patience=0,
                                budget=10 ** 6, log=lambda m: None)
        calls = [0]
        inner = search.scorer

        def counted(c):
            calls[0] += 1
            if calls[0] > 40:
                raise KeyboardInterrupt
            return inner(c)
        search.scorer = counted
        with self.assertRaises(KeyboardInterrupt):
            search.run()
        self.assertGreater(calls[0], 40)

    def test_fresh_objects_reset_the_dry_count(self):
        u = body_unit()
        n = [0]

        def score(cands):
            out = []
            for c in cands:
                n[0] += 1
                out.append({'id': c['id'], 'st': 'ok', 'd': 5, 'ex': 5, 'n': 1, 'nt': 1, 'h': f'h{n[0]}'})
            return out
        search = permute.Search(u, score, lambda text: [], random.Random(1), batch=4, patience=6,
                                budget=10 ** 6, log=lambda m: None)
        self.assertEqual(search.run()['status'], 'patience')


class Retrying(unittest.TestCase):
    def test_retries_with_backoff_and_recovers_once_per_failure(self):
        import runners
        calls, sleeps, recovered, timings, now = [], [], [], {}, [0.0]

        def call():
            calls.append(1)
            if len(calls) < 3:
                raise runners.TransportError('down')
            return 'ok'

        def sleep(s):
            sleeps.append(s)
            now[0] += s
        got = permute.retrying(call, timings, lambda m: None, 600, recover=lambda: recovered.append(1),
                               sleep=sleep, clock=lambda: now[0])
        self.assertEqual(got, 'ok')
        self.assertEqual(sleeps, [5, 10])
        self.assertEqual(len(recovered), 2)
        self.assertEqual(timings['outage_seconds'], 15)

    def test_gives_up_after_the_limit(self):
        import runners
        now = [0.0]

        def sleep(s):
            now[0] += s

        def call():
            raise runners.TransportError('down')
        with self.assertRaises(runners.TransportError):
            permute.retrying(call, {}, lambda m: None, 20, sleep=sleep, clock=lambda: now[0])
        self.assertLessEqual(now[0], 20)

    def test_does_not_retry_other_errors(self):
        def call():
            raise KeyError('bug')
        with self.assertRaises(KeyError):
            permute.retrying(call, {}, lambda m: None, 600, sleep=lambda s: None)


class LintRoot(unittest.TestCase):
    def test_lint_gate_runs_the_repository_lint(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / 'src'
            (src / 'reconstruction/toys').mkdir(parents=True)
            (src / 'reconstruction/toys/Toy.cpp').write_text('#include "Toy.h"\n')
            (src / 'reconstruction/toys/Toy.h').write_text('#pragma once\n')
            root = permute.make_lint_root(Path(tmp) / 'lint', src, ['reconstruction/toys/Toy.cpp',
                                                                   'reconstruction/toys/Toy.h'])
            check = permute.lint_gate(root, 'reconstruction/toys/Toy.cpp', 'sse-steam-1-7-104')
            problems = check('#include "Toy.h"\nvoid F() { __asm { nop } }\n')
            self.assertTrue(any('inline assembly' in p for p in problems), problems)


if __name__ == '__main__':
    unittest.main()
