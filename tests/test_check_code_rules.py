import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_code_rules as rules  # noqa: E402

TOOL = Path(rules.__file__)

# Every sample is synthetic; none is taken from a game binary, a decompiler session or a unit.
HEADER = '#pragma once\nclass Widget\n{\npublic:\n    void Run();\n    int count;\n    float scale;\n};\n'


def codes(body, name='reconstruction/area/Widget.cpp', header=HEADER):
    """Finding codes of one synthetic .cpp checked beside its header."""
    with tempfile.TemporaryDirectory() as tmp:
        root = Path(tmp)
        write(root, name, '// 0x1000 Widget::Run\n#include "Widget.h"\n' + body)
        write(root, 'reconstruction/area/Widget.h', header)
        units = rules.analyse(root)
        return [f'{rule} {code}' for _line, rule, code, _message, _function in units[name].findings]


def write(root, name, text):
    path = root / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding='utf-8', newline='\n')


def in_function(statements):
    return '// Runs the widget.\nvoid Widget::Run()\n{\n' + statements + '\n}\n'


class BlankingTest(unittest.TestCase):
    def test_comments_and_literals_keep_their_positions(self):
        text = 'int a; // volatile here\nconst char* s = "x = x; {";\n/* if (a) {}\n */ char c = \'{\';\n'
        code, comments = rules.blank_comments_and_literals(text)
        self.assertEqual(len(code), len(text))
        self.assertEqual(code.count('\n'), text.count('\n'))
        self.assertNotIn('volatile', code)
        self.assertNotIn('x = x', code)
        self.assertEqual(code.count('{'), 0)
        self.assertIn(1, comments)
        self.assertIn(3, comments)

    def test_directives_are_blanked_with_their_continuations(self):
        code = rules.blank_directives('#define DO(x) do { x; } \\\n    while (0)\nint a;\n')
        self.assertNotIn('while', code)
        self.assertIn('int a;', code)


class ScopeTest(unittest.TestCase):
    def kinds(self, text):
        code, _ = rules.blank_comments_and_literals(text)
        return [(s.kind, s.name) for s in rules.scopes_of(rules.blank_directives(code))]

    def test_namespace_type_function_and_blocks(self):
        text = ('namespace game {\nstruct Point { float x; };\nenum Kind { kA };\n'
                'int Widget::Total(int a) const {\n    if (a) { return 1; }\n    return 0;\n}\n}\n')
        self.assertEqual(self.kinds(text), [('namespace', 'game'), ('type', 'Point'), ('enum', ''),
                                            ('function', 'Widget::Total'), ('block', '')])

    def test_constructor_initialiser_braces_are_not_the_body(self):
        text = 'Widget::Widget() : count{1}, scale(2.0f) {\n    Run();\n}\n'
        kinds = self.kinds(text)
        self.assertEqual(kinds, [('init', ''), ('function', 'Widget::Widget')])
        self.assertEqual(self.kinds('Widget::Widget() : scale(2.0f), count{1} {\n}\n'),
                         [('init', ''), ('function', 'Widget::Widget')])

    def test_function_returning_a_struct_pointer_is_a_function(self):
        self.assertEqual(self.kinds('struct Point* Find(int a) {\n    return 0;\n}\n'), [('function', 'Find')])

    def test_attributes_do_not_name_the_function(self):
        self.assertEqual(self.kinds('__declspec(noinline) void Stop() {\n}\n'), [('function', 'Stop')])


class MatchRowTest(unittest.TestCase):
    def assertFinds(self, code, body, **kwargs):
        self.assertIn(code, codes(body, **kwargs), body)

    def assertClean(self, code, body, **kwargs):
        self.assertNotIn(code, codes(body, **kwargs), body)

    def test_offset_casts(self):
        for statement in ('float r = *(float*)((char*)obj + 0x58);',
                          '*(int*)((unsigned char*)model + 16) |= 1;',
                          'int v = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1a);',
                          'return reinterpret_cast<Widget*>(reinterpret_cast<std::uint8_t*>(this) - 0xa0);',
                          'long* c = reinterpret_cast<long*>(reinterpret_cast<char*>(&p) + kVisitCounterOffset);'):
            self.assertFinds('R4 offset-cast', in_function('    ' + statement))

    def test_byte_arithmetic_without_a_fixed_struct_passes(self):
        for statement in ('const char* next = (const char*)cursor + length;',
                          'std::uint8_t* out = reinterpret_cast<std::uint8_t*>(buffer) + written;',
                          'float r = obj->radius;',
                          'char* end = (char*)begin + 4;'):
            self.assertClean('R4 offset-cast', in_function('    ' + statement))

    def test_offset_macro(self):
        self.assertFinds('R4 offset-macro', '#define FIELD(p, o) (*(int*)((char*)(p) + (o)))\n')
        self.assertClean('R4 offset-macro', '#define FOFS(x) offsetof(Widget, x)\n')

    def test_volatile(self):
        self.assertFinds('R17 volatile-local', in_function('    volatile int carrier = count;'))
        self.assertFinds('R17 volatile', 'volatile long gCounter;\n')
        self.assertClean('R17 volatile', '// volatile: written by the audio thread\nvolatile long gCounter;\n')
        self.assertClean('R17 volatile-local', in_function('    Add(reinterpret_cast<volatile long*>(&count));'))
        self.assertClean('R17 volatile', '// a volatile situation\nint a;\n')

    def test_empty_bodies_and_bare_semicolons(self):
        self.assertFinds('R17 empty-if', in_function('    if (count) { }'))
        self.assertFinds('R17 empty-if', in_function('    if (count);'))
        self.assertFinds('R17 empty-else', in_function('    if (count) { Run(); } else { }'))
        self.assertFinds('R17 bare-semicolon', in_function('    Run();\n    ;'))
        for statement in ('for (;;) { Run(); }', 'while (*s++) ;', 'for (i = 0; i < 3; i++) ;',
                          'if (count) { Run(); }', 'int a[] = {1, 2};', 'switch (count) { case 1: ; }'):
            found = codes(in_function('    ' + statement))
            self.assertFalse([c for c in found if c in ('R17 empty-if', 'R17 empty-else', 'R17 bare-semicolon')],
                             statement)

    def test_do_while_zero_only_outside_a_macro(self):
        self.assertFinds('R17 do-while-zero', in_function('    do { Run(); } while (0);'))
        self.assertClean('R17 do-while-zero', '#define RUN() do { Go(); } while (0)\n')
        self.assertClean('R17 do-while-zero', in_function('    do { Run(); } while (count);'))

    def test_self_assignment_and_identity_arithmetic(self):
        self.assertFinds('R17 self-assignment', in_function('    count = count;'))
        self.assertFinds('R17 self-assignment', in_function('    this->scale = this->scale;'))
        self.assertClean('R17 self-assignment', in_function('    this->count = count;\n    bool same = count == count;'))
        self.assertFinds('R17 plus-zero', in_function('    int a = count + 0;'))
        self.assertFinds('R17 times-one', in_function('    int a = count * 1;'))
        for statement in ('int a = count + 0x10;', 'float f = scale * 1.5f;', 'float g = 1e+0f;', 'int b = count * 10;',
                          'int c = count + 01;', 'int* p = &count; *p = 1;'):
            found = codes(in_function('    ' + statement))
            self.assertFalse([c for c in found if c in ('R17 plus-zero', 'R17 times-one')], statement)

    def test_padding_members_and_virtuals(self):
        header = '#pragma once\nstruct Item\n{\n    int count;\n    std::uint32_t pad0C;\n    char _pad[4];\n    int unk14;\n};\n'
        found = codes('', header=header, name='reconstruction/area/Widget.cpp')
        self.assertEqual(found, [])     # findings sit in the header, not the .cpp
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            write(root, 'reconstruction/area/Item.h', header + 'class Base\n{\n    virtual void Pad1();\n    virtual void Run();\n};\n')
            unit = rules.analyse(root)['reconstruction/area/Item.h']
            found = [(rule, code, line) for line, rule, code, _m, _f in unit.findings]
        self.assertIn(('R17', 'padding-member', 5), found)
        self.assertIn(('R17', 'padding-member', 6), found)
        self.assertIn(('R13', 'pad-virtual', 11), found)
        self.assertEqual(len([f for f in found if f[1] == 'padding-member']), 2)

    def test_assembly(self):
        self.assertFinds('R18 assembly', in_function('    __as' 'm { nop }'))
        self.assertClean('R18 assembly', in_function('    int basement = 1;'))


class CrossFileTest(unittest.TestCase):
    def tree(self, files):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        root = Path(self.tmp.name)
        for name, text in files.items():
            write(root, name, text)
        return root

    def found(self, root):
        return {(name, rule, code) for name, unit in rules.analyse(root).items()
                for _line, rule, code, _m, _f in unit.findings}

    def test_type_defined_twice_with_different_bodies(self):
        root = self.tree({
            'reconstruction/a/Foo.h': 'struct Vec\n{\n    float x;\n    float y;\n};\n',
            'reconstruction/b/Bar.h': 'struct Vec\n{\n    float x;\n};\n',
            'reconstruction/c/Baz.h': 'struct Same { int a; };\n',
            'reconstruction/d/Qux.h': 'struct Same {\n    int a;\n};\n',
            'reconstruction/e/One.cpp': 'namespace\n{\n    struct Entry { int a; };\n}\n',
            'reconstruction/e/Two.cpp': 'namespace\n{\n    struct Entry { float b; };\n}\n',
        })
        found = self.found(root)
        self.assertIn(('reconstruction/a/Foo.h', 'R1', 'type-redefined'), found)
        self.assertIn(('reconstruction/b/Bar.h', 'R1', 'type-redefined'), found)
        self.assertFalse([f for f in found if f[0].startswith(('reconstruction/c', 'reconstruction/d'))])
        self.assertFalse([f for f in found if f[0].startswith('reconstruction/e')])

    def test_class_struct_keyword_mismatch(self):
        root = self.tree({
            'reconstruction/a/Foo.h': 'class Actor\n{\npublic:\n    int a;\n};\n',
            'reconstruction/b/Bar.h': 'struct Actor;\nclass Other;\nvoid Use(Actor*, Other*);\n',
        })
        found = self.found(root)
        self.assertIn(('reconstruction/a/Foo.h', 'R1', 'keyword-mismatch'), found)
        self.assertIn(('reconstruction/b/Bar.h', 'R1', 'keyword-mismatch'), found)
        self.assertEqual(len([f for f in found if f[2] == 'keyword-mismatch']), 2)

    def test_externs(self):
        root = self.tree({
            'reconstruction/a/Foo.h': 'extern int gFrameCount;\nextern "C" void Declared();\n',
            'reconstruction/a/Foo.cpp': '#include "Foo.h"\nextern float gScale;\nextern void Helper(int);\nint gFrameCount;\n',
            'reconstruction/b/Bar.h': 'extern long gFrameCount;\n',
        })
        found = self.found(root)
        self.assertIn(('reconstruction/a/Foo.cpp', 'R2', 'extern-outside-header'), found)
        self.assertIn(('reconstruction/a/Foo.h', 'R2', 'extern-type-conflict'), found)
        self.assertIn(('reconstruction/b/Bar.h', 'R2', 'extern-type-conflict'), found)
        self.assertEqual(len([f for f in found if f[2] == 'extern-outside-header']), 1)


class AdvisoryRowTest(unittest.TestCase):
    def test_advisory_rows(self):
        body = ('void Loose(int);\nvoid Widget::Run()\n{\n    if (count) Stop();\n    bool on = !!count;\n'
                '    int unk58 = Function1581e30();\n}\n#if 0\nint old;\n#endif\n')
        found = codes(body)
        for code in ('R25 prototype-in-cpp', 'R33 no-function-comment', 'R35 no-braces', 'F double-not',
                     'R7 placeholder-name', 'R37 if-zero'):
            self.assertIn(code, found)
        self.assertFalse([c for c in found if c.split()[0] in rules.MATCH_RULES])

    def test_ordinary_names_are_not_placeholders(self):
        found = codes(in_function('    int retries = 2;\n    float scale32 = 1.0f;\n    int total = 1000000 + 0xdeadbeef;'))
        self.assertNotIn('R7 placeholder-name', found)


class SourceFilesTest(unittest.TestCase):
    def test_generated_tree_is_not_a_unit(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            write(root, 'reconstruction/area/Widget.h', HEADER)
            write(root, 'reconstruction/area/Widget.cpp', '// 0x1000 Widget::Run\n#include "Widget.h"\n')
            write(root, 'reconstruction/generated/tree/Gadget.h', '#pragma once\nstruct Gadget\n{\n    int pad04;\n};\n')
            write(root, 'reconstruction/generated/tree/Gadget.cpp', 'void Gadget::Run()\n{\n    ;\n}\n')
            self.assertEqual(rules.source_files(root), ['reconstruction/area/Widget.cpp', 'reconstruction/area/Widget.h'])
            self.assertEqual(sorted(rules.analyse(root)), ['reconstruction/area/Widget.cpp', 'reconstruction/area/Widget.h'])


class RefusalRowTest(unittest.TestCase):
    def test_codegen_steering_is_refused(self):
        self.assertIn('R38 pragma', codes('#pragma optimize("", off)\n'))
        self.assertIn('R38 pragma', codes('#pragma intrinsic(memcpy)\n'))
        self.assertIn('R38 pragma', codes('#pragma function(strlen)\n'))
        self.assertIn('R38 barrier', codes(in_function('    _ReadWriteBarrier();')))
        self.assertIn('R38 noinline', codes('__declspec(noinline) void Helper();\n'))

    def test_noinline_with_evidence_and_plain_code_pass(self):
        self.assertNotIn('R38 noinline', codes('// noinline: the image calls it out of line\n__declspec(noinline) void Helper();\n'))
        self.assertNotIn('R38 noinline', codes('__declspec(noinline) void Helper(); // noinline: separate symbol\n'))
        self.assertFalse([c for c in codes('#pragma warning(disable : 4100)\n' + in_function('    count = 1;'))
                          if c.startswith('R38')])

    def test_decompiler_types_are_refused_and_names_advisory(self):
        for word in ('undefined4', 'undefined', 'CONCAT44(a, b)', 'SUB41(a)', 'ZEXT48(a)', 'SEXT48(a)', 'CARRY4(a, b)',
                     'SBORROW4(a, b)'):
            self.assertIn('R39 decompiler-type', codes(in_function(f'    x = {word};')), word)
        found = codes(in_function('    int param_1 = 0; int iVar2 = 0; int local_8 = 0; int in_RAX = 0;'))
        self.assertIn('R39 decompiler-name', found)
        self.assertNotIn('R39 decompiler-type', found)
        self.assertFalse(rules.is_match('R39', 'decompiler-name'))
        self.assertTrue(rules.is_match('R39', 'decompiler-type'))

    def test_decompiler_words_in_comments_literals_and_longer_names_pass(self):
        found = codes(in_function('    // undefined4 once\n    const char* s = "CONCAT44";\n    int undefinedCount = 0;'))
        self.assertFalse([c for c in found if c.startswith('R39')])

    def test_comments_naming_a_model_path_or_address_are_refused(self):
        for text in ('// written with Claude', '// Drafted by GPT-6.1 Sol', '// Codex pass', '// Generated by a tool',
                     '// chk_ab12 pack', '// see /Users/someone/x', '// C:\\Users\\someone', '// notes in .local/x',
                     '// mail a.b@example.com', '/* Gemini\n */'):
            self.assertIn('R40 comment', codes(text + '\n'), text)

    def test_label_and_paperwork_lines_pass(self):
        for text in ('// Widget, Run: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)',
                     '// Run: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)',
                     '// Run: CRASHLOGGER_PDB(59818@2026.10.24)', '// Run: SYMBOLS(tesv-2013-map)',
                     '// SPDX-License-Identifier: MIT', '// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/a.cpp:12',
                     '// CI hash: 0x1000 ?Run@Widget@@QEAAXXZ', '// Source exposure: binary-analysis',
                     '// Reads the actor and sets the flag.'):
            self.assertNotIn('R40 comment', codes(text + '\n'), text)

    def test_a_model_name_beside_a_label_is_still_refused(self):
        self.assertIn('R40 comment', codes('// Run: SYMBOLS(tesv-2013-map) Claude chose it\n'))

    def test_refusals_name_rule_file_line_text_and_fix(self):
        found = rules.refusals('reconstruction/area/Widget.cpp', '// ok\nint x = undefined4;\n// Claude\n')
        self.assertEqual(len(found), 2)
        self.assertRegex(found[0], r'^reconstruction/area/Widget\.cpp:2: R39 decompiler-type: `undefined4`.*write the real')
        self.assertRegex(found[1], r'^reconstruction/area/Widget\.cpp:3: R40 comment: .*`Claude`.*describe what')

    def test_refusals_skip_advisory_names_and_generated_trees(self):
        self.assertEqual(rules.refusals('reconstruction/area/Widget.cpp', 'int param_1;\n'), [])
        self.assertEqual(rules.refusals('reconstruction/generated/crashlogger_pdb/A.h', 'int undefined4;\n'), [])

    def test_the_pr_gate_checks_changed_files_only(self):
        import contrib_validation
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            write(root, 'reconstruction/area/Widget.h', HEADER + '// Claude\n')
            write(root, 'reconstruction/area/Other.h', '#pragma once\n// Claude\n')
            write(root, 'reconstruction/area/Widget.cpp', '#include "Widget.h"\n#include "Other.h"\n')
            problems = contrib_validation.source_problems(root, ['reconstruction/area/Widget.h'], 'build')
            refused = [p for p in problems if 'R40' in p]
            self.assertEqual(len(refused), 1)
            self.assertIn('Widget.h', refused[0])


class TotalsTest(unittest.TestCase):
    def test_function_status_and_totals(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            write(root, 'reconstruction/area/Widget.h', HEADER)
            write(root, 'reconstruction/area/Widget.cpp',
                  '// 0x1000 Widget::Run\n// 0x2000 Widget::Stop\n#include "Widget.h"\n'
                  '// Runs.\nvoid Widget::Run()\n{\n    count = count;\n}\n'
                  '// Stops.\nvoid Widget::Stop()\n{\n    count = 0;\n}\n')
            write(root, 'reconstruction/area/Gadget.h', '#pragma once\nstruct Gadget\n{\n    int pad04;\n};\n')
            write(root, 'reconstruction/area/Gadget.cpp',
                  '// 0x3000 Gadget::Functionabc123\n#include "Gadget.h"\n// Unknown.\nint Gadget::Functionabc123()\n{\n    return 1;\n}\n')
            write(root, 'data/progress.json', json.dumps({'functions': [
                {'rva': 0x1000, 'size': 10, 'status': 'matched'}, {'rva': 0x2000, 'size': 20, 'status': 'matched'},
                {'rva': 0x3000, 'size': 30, 'status': 'matched'}, {'rva': 0x4000, 'size': 40, 'status': 'matched'},
                {'rva': 0x5000, 'size': 50, 'status': 'mapped'}]}))
            units = rules.analyse(root)
            status = rules.unit_status(units)
            widget = status['reconstruction/area/Widget.cpp']
            self.assertEqual(widget[0x1000]['match'], ['R17 self-assignment'])
            self.assertEqual(widget[0x2000]['match'], [])
            # A header finding counts against every compared function of the unit.
            self.assertEqual(status['reconstruction/area/Gadget.cpp'][0x3000]['match'], ['R17 padding-member'])
            counts, pending = rules.totals(root, status)
            self.assertEqual(counts['matched'], 4)
            self.assertEqual(counts['matched_bytes'], 100)
            self.assertEqual(counts['under_rules'], 1)
            self.assertEqual(counts['under_rules_bytes'], 20)
            self.assertEqual(counts['under_rules_named'], 1)
            self.assertEqual(counts['pending'], 2)
            self.assertEqual(counts['no_unit_line'], 1)
            self.assertEqual(pending, {'R17': 2})

            listed = subprocess.run([sys.executable, str(TOOL), '--root', str(root), '--list',
                                     'reconstruction/area/Widget.cpp'], capture_output=True, text=True)
            self.assertEqual(listed.returncode, 0, listed.stderr)
            self.assertIn('reconstruction/area/Widget.cpp:7: R17 self-assignment [match] in Widget::Run', listed.stdout)
            strict = subprocess.run([sys.executable, str(TOOL), '--root', str(root), '--strict',
                                     'reconstruction/area/Widget.cpp'], capture_output=True, text=True)
            self.assertEqual(strict.returncode, 1)
            whole = subprocess.run([sys.executable, str(TOOL), '--root', str(root)], capture_output=True, text=True)
            self.assertEqual(whole.returncode, 0, whole.stderr)
            self.assertIn('matched under the rules:', whole.stdout)
            unknown = subprocess.run([sys.executable, str(TOOL), '--root', str(root), 'tools/check.py'],
                                     capture_output=True, text=True)
            self.assertEqual(unknown.returncode, 2)


class PathResolutionTest(unittest.TestCase):
    """Paths on the command line may be absolute, relative to a subdirectory or live in a git worktree."""
    SOURCE = '// 0x1000 Widget::Run\n#include "Widget.h"\nvoid Widget::Run()\n{\n    count = count;\n}\n'
    NAME = 'reconstruction/area/Widget.cpp'

    def run_tool(self, root, *args, cwd=None):
        return subprocess.run([sys.executable, str(TOOL), '--root', str(root), '--list', *args],
                              capture_output=True, text=True, cwd=cwd)

    def make_checkout(self, root):
        write(root, self.NAME, self.SOURCE)
        write(root, 'reconstruction/area/Widget.h', HEADER)

    def test_absolute_and_subdirectory_paths(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            self.make_checkout(root)
            for arg, cwd in ((str(root / self.NAME), None), ('Widget.cpp', root / 'reconstruction/area'),
                             ('../area/Widget.cpp', root / 'reconstruction/area'), ('./' + self.NAME, root),
                             (self.NAME, root)):
                done = self.run_tool(root, arg, cwd=cwd)
                self.assertEqual(done.returncode, 0, (arg, done.stderr))
                self.assertIn(self.NAME + ':5: R17 self-assignment', done.stdout, arg)

    def test_symlinked_checkout_path(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve() / 'real'
            self.make_checkout(root)
            link = Path(tmp).resolve() / 'link'
            try:
                link.symlink_to(root, target_is_directory=True)
            except (OSError, NotImplementedError):
                self.skipTest('no symlinks here')
            done = self.run_tool(root, str(link / self.NAME))
            self.assertEqual(done.returncode, 0, done.stderr)
            self.assertIn(self.NAME + ':5: R17 self-assignment', done.stdout)

    def test_git_worktree_paths(self):
        git = ['git', '-c', 'user.name=t', '-c', 'user.email=t@example.invalid']
        with tempfile.TemporaryDirectory() as tmp:
            main, tree = Path(tmp).resolve() / 'main', Path(tmp).resolve() / 'tree'
            self.make_checkout(main)
            try:
                for cmd in (['init', '-q'], ['add', '-A'], ['commit', '-q', '-m', 'x'], ['worktree', 'add', '-q', str(tree), '-b', 'w']):
                    subprocess.run(git + cmd, cwd=main, check=True, capture_output=True)
            except (OSError, subprocess.CalledProcessError):
                self.skipTest('git worktree unavailable')
            # The worktree's file, named by its absolute path, with the tool run from the worktree and from the main checkout.
            for root in (tree, main):
                done = self.run_tool(root, str(tree / self.NAME), cwd=tree)
                self.assertEqual(done.returncode, 0, done.stderr)
                self.assertIn(self.NAME + ':5: R17 self-assignment', done.stdout)
            # The finding belongs to the file that was named: an edit only the worktree has is seen.
            write(tree, self.NAME, self.SOURCE.replace('count = count;', 'count = 1;'))
            self.assertNotIn('self-assignment', self.run_tool(main, str(tree / self.NAME)).stdout)
            self.assertIn('self-assignment', self.run_tool(main, str(main / self.NAME)).stdout)

    def test_missing_and_foreign_files_are_still_refused(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp).resolve()
            self.make_checkout(root)
            for arg in ('reconstruction/area/Nothing.cpp', str(root / 'tools/check.py'), '/nonexistent/x.cpp'):
                done = self.run_tool(root, arg)
                self.assertEqual(done.returncode, 2, arg)
                self.assertIn('not a source file under reconstruction/', done.stderr)


class TreeNoinlineDebt(unittest.TestCase):
    # Files that still carry an R38 finding; the list only shrinks. A file whose note is fixed
    # must leave it, so a regrown finding anywhere else fails here.
    KNOWN = {'reconstruction/bsshader/BSLightingShaderMaterialEye.h',
             'reconstruction/bsshader/BSLightingShaderMaterialLandscape.h',
             'reconstruction/gamebryo/nianimation/NiBlendTransformInterpolator_f67ed0.cpp',
             'reconstruction/gamebryo/nimain/BSLeafAnimNode.cpp',
             'reconstruction/gamebryo/nimain/NiTexture.h',
             'reconstruction/skyrim_shared/actors/TESNPC.cpp'}

    def test_no_new_noinline_without_evidence(self):
        root = Path(rules.__file__).resolve().parents[1]
        found = set()
        for path in (root / 'reconstruction').rglob('*'):
            if path.suffix not in ('.h', '.cpp') or 'generated' in path.parts:
                continue
            text = path.read_text(encoding='utf-8', errors='replace')
            if 'noinline' not in text:
                continue
            name = path.relative_to(root).as_posix()
            if any(' R38 ' in line for line in rules.refusals(name, text)):
                found.add(name)
        self.assertEqual(set(), found - self.KNOWN, 'noinline without a `// noinline:` note')


class NamedFilesOnlyTest(unittest.TestCase):
    def test_list_reads_only_the_files_given(self):
        import contextlib
        import io
        from unittest import mock
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'reconstruction' / 'a').mkdir(parents=True)
            (root / 'reconstruction' / 'a' / 'One.cpp').write_text('int One() { return 1; }\n')
            (root / 'reconstruction' / 'a' / 'Two.cpp').write_text('int Two() { return 2; }\n')
            seen = []
            real = rules.analyse

            def spy(checkout, names=None):
                seen.append(names)
                return real(checkout, names)
            out = io.StringIO()
            with mock.patch.object(rules, 'analyse', spy), contextlib.redirect_stdout(out):
                code = rules.main(['--list', 'reconstruction/a/One.cpp', '--root', str(root)])
            self.assertEqual(code, 0)
            self.assertEqual(seen, [['reconstruction/a/One.cpp']])
            err = io.StringIO()
            with contextlib.redirect_stderr(err):
                self.assertEqual(rules.main(['--list', 'reconstruction/a/Missing.cpp', '--root', str(root)]), 2)
            self.assertIn('not a source file', err.getvalue())


if __name__ == '__main__':
    unittest.main()
