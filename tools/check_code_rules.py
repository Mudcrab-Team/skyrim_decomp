"""Advisory code-rules checker for reconstruction/ (docs/code-rules.md). Never compares Skyrim bytes.

A byte match proves the compiled code, not the source: source that reaches the bytes through an
offset cast, a per-unit copy of a type or a statement that only steers the compiler reproduces the
binary without recovering what was written. This tool makes that part of "plausible source"
mechanical, so it is computed instead of argued, and reports a second number beside the byte
count: functions that are `matched` and whose unit also passes every [match] rule.

It changes no gate. `matched` stays the two-host comparison plus one review
(docs/verification.md); nothing here is evidence of a match, and nothing here revokes one.

[match] rows (a function with a finding is MATCH-PENDING under the rules):

- R1  one declaration per type: a type name defined in two files with different bodies; a type
      whose `class`/`struct` keyword differs between declarations (MSVC mangles the keyword);
- R2  one declaration per global: an `extern` variable declared in a .cpp; one global declared
      with different types;
- R4  typed members, not offsets: a constant added to a byte-pointer cast inside another pointer
      cast; an offset macro;
- R13 real vtables: a virtual named `pad...` or `dummy...` (slot-for-slot comparison against the
      image's vtables needs the private function table and is not done here);
- R17 no fake code: `volatile` on a local, or elsewhere without a `// volatile: <evidence>`
      comment; empty `if`/`else` bodies and bare `;` statements; `do { } while (0)` outside a
      macro; self-assignment; the literals `+ 0` and `* 1`; members named `pad...`;
- R18 no assembly bodies (tools/lint_reconstruction.py already refuses these; counted here so the
      table is complete);
- R38 no codegen steering: `#pragma optimize|intrinsic|function`, `_ReadWriteBarrier`, and
      `__declspec(noinline)` without a `// noinline: <evidence>` comment;
- R39 no decompiler leftovers: the types and helpers `undefined`, `CONCAT44`, `SUB41`, `ZEXT48`,
      `SEXT48`, `CARRY4`, `SBORROW4` (the name shapes `param_1`, `iVar2`, `local_8`, `in_RAX`,
      `extraout_`, `unaff_` are advisory);
- R40 clean comments: no model, tool or pipeline name, checkpoint id, host path or e-mail address in
      a comment (the label lines `COMMUNITY(`, `SIBLING(`, `SYMBOLS(`, `CRASHLOGGER_PDB(`, the SPDX
      line, `Sibling source:` and `CI hash:` are exempt).

R38-R40 are also refused for the files a PR changes (`refusals`, called from
tools/lint_review_readiness.py), so new code cannot add to the count while the existing units
stay as debt in the totals.

Advisory rows never make a function pending: R7 placeholder and address-derived names, R25
prototypes declared in a .cpp, R33 function definitions with no comment above them, R35 bodies
without braces, R37 `#if 0`, and `!!x` (Section F; sometimes human).

Limits, stated so nobody reads more into a clean result than it holds. There is no C++ parser:
comments and literals are blanked, braces are matched and the rows are regular expressions,
narrow by intent, so genuine code passes and a determined fake can too. Not implemented: unused
locals (R17), layout views read through a cast (R1), vtable slot evidence (R13). A finding in a
function body belongs to that function when the unit's `// 0x<rva> <Name>` line names it;
every other finding (file scope, headers of the unit's include closure) counts against every
compared function of the unit, which over-reports for functions that do not touch the flagged
declaration.

    python3 tools/check_code_rules.py                    # whole tree: counts and the three totals
    python3 tools/check_code_rules.py --list FILE...     # one line per finding in those files
    python3 tools/check_code_rules.py --strict FILE...   # exit 1 on a [match] finding in them
    python3 tools/check_code_rules.py --json OUT.json    # counts and per-unit status
"""
import argparse
import bisect
import collections
import hashlib
import json
import posixpath
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = 'reconstruction'
# Machine-generated declarations (reconstruction/generated/crashlogger_pdb/README.md) are not reconstructed units.
SKIPPED_ROOTS = ('reconstruction/generated/',)
MATCH_RULES = ('R1', 'R2', 'R4', 'R13', 'R17', 'R18', 'R38', 'R39', 'R40')
ADVISORY_RULES = ('R7', 'R25', 'R33', 'R35', 'R37', 'F')
# Finding codes of a [match] rule that are only advisory.
ADVISORY_CODES = frozenset((('R39', 'decompiler-name'),))


def is_match(rule, code):
    return rule in MATCH_RULES and (rule, code) not in ADVISORY_CODES

COMPARED_LINE = re.compile(r'^//[ \t]*0x([0-9a-fA-F]+)[ \t]+(\S+)', re.M)
INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*"([^"\n]+)"', re.M)

# Project profile (docs/code-rules.md): names that are open naming work (R7).
PLACEHOLDERS = (
    re.compile(r'\b(?:FUN|DAT|LAB|sub|loc|off|unk|field|local|param)_[0-9A-Fa-f]+\b'),
    re.compile(r'\b(?:Unk|Func|Function|Slot|Sub)_?[0-9A-Fa-f]+\b'),
    re.compile(r'\bunk(?:nown)?[0-9A-Fa-f]{2,}\b'),
    re.compile(r'\b[iupcbl]Var\d+\b|\b(?:temp|ptr|result|var|v)\d+\b'),
    # An address-derived name: an identifier that ends in six to eight hex characters, one a digit.
    re.compile(r'\b[A-Za-z_][A-Za-z_]*?_?(?=[0-9a-fA-F]*[0-9])[0-9a-fA-F]{6,8}\b'),
)
PAD_NAME = re.compile(r'^_?pad(?:ding)?[0-9A-Fa-f_]*$', re.I)

BYTE_TYPE = (r'(?:const\s+)?(?:(?:unsigned|signed)\s+)?(?:char|BYTE|byte|std::byte|(?:std::)?u?int8_t|u8|s8|UInt8|SInt8)'
             r'(?:\s+const)?\s*\*')
CONSTANT = r'(?:0[xX][0-9a-fA-F]+|\d+)[uUlL]*\b'
C_BYTE_CAST = re.compile(r'\(\s*' + BYTE_TYPE + r'\s*\)')
NAMED_BYTE_CAST = re.compile(r'\b(?:reinterpret_cast|static_cast|const_cast)\s*<\s*' + BYTE_TYPE + r'\s*>\s*\(')
OUTER_C_CAST = re.compile(r'\(\s*[A-Za-z_][\w:<>,\s]*\*+\s*(?:const\s*)?\)\s*\(*\s*$')
OUTER_NAMED_CAST = re.compile(r'_cast\s*<[^;{}]*\*\s*>\s*\(+\s*$')
# A literal, or a constant whose own name says it is an offset (kFooOffset, FOO_OFFSET).
PLUS_CONSTANT = re.compile(r'\s*\)*\s*[+-]\s*(?:' + CONSTANT + r'|[A-Za-z_]\w*(?i:offset)\w*\b(?!\s*\())')
OPERAND = re.compile(r'\s*(?:this\b|[A-Za-z_]\w*(?:\s*(?:\.|->|::)\s*[A-Za-z_]\w*)*)')

VOLATILE = re.compile(r'\bvolatile\b')
VOLATILE_NOTE = re.compile(r'//\s*volatile:\s*\S')
# The keyword spellings are assembled from pieces so that tools/leakgrep.py, which refuses them in added
# lines, does not flag this pattern.
ASSEMBLY = re.compile(r'(?<![A-Za-z0-9_])(?:__as' r'm__|__as' r'm|_as' r'm|__em' r'it)(?![A-Za-z0-9_])'
                      r'|(?<![A-Za-z0-9_])as' r'm\s*[({]')
PAD_VIRTUAL = re.compile(r'\bvirtual\b[^;{}()]*?\b(?:pad|dummy)\w*\s*\(', re.I)
EMPTY_ELSE = re.compile(r'\belse\s*\{\s*\}')
WHILE_ZERO = re.compile(r'\}\s*while\s*\(\s*(?:0|false)\s*\)\s*;')
SELF_ASSIGN = re.compile(r'(?:^|[;{}])\s*((?:this\s*->\s*)?[A-Za-z_]\w*(?:\s*(?:\.|->)\s*[A-Za-z_]\w*)*)\s*=\s*\1\s*;')
PLUS_ZERO = re.compile(r'(?<=[\w)\]])\s*(?<![0-9.][eE])\+\s*0(?![\w.])')
TIMES_ONE = re.compile(r'(?<=[\w)\]])\s*\*\s*1(?![\w.])')
DOUBLE_NOT = re.compile(r'!!\s*[\w(]')
CONTROL = re.compile(r'\b(if|for|while|switch)\s*\(')
ELSE = re.compile(r'\belse\b(?!\s*(?:if\b|\{))')
IF_ZERO = re.compile(r'^[ \t]*#[ \t]*if[ \t]+0\b', re.M)

NAMESPACE_HEAD = re.compile(r'^(?:inline\s+)?namespace\b\s*([\w:]*)\s*$|^extern\s*$')
TYPE_HEAD = re.compile(r'(?:^|[\s>])(class|struct|union)\s+(?:(?:__declspec|alignas)\s*\([^)]*\)\s*)*'
                       r'([A-Za-z_]\w*)\s*(?:final\s*)?(?::(?!:)[^{]*)?$')
ENUM_HEAD = re.compile(r'(?:^|\s)enum\b[^(){}=]*$')
ATTRIBUTE = re.compile(r'(?:__declspec|alignas|noexcept|throw|decltype)\s*\((?:[^()]|\([^()]*\))*\)|\[\[[^\]]*\]\]')
FUNCTION_NAME = re.compile(r'((?:[A-Za-z_]\w*\s*::\s*)*(?:~\s*)?(?:operator\s*(?:\(\s*\)|\[\s*\]|[^\s(]+|\s+[\w:*&\s]+?)|'
                           r'[A-Za-z_]\w*))\s*\(')
STATEMENT_KEYWORD = re.compile(r'^(?:if|for|while|switch|catch|do|else|try|return|case|default)\b')
CTOR_INITIALISERS = re.compile(r'\)\s*(?:noexcept\s*)?:(?!:)')
FORWARD = re.compile(r'(?:^|[;{}])\s*(class|struct)\s+([A-Za-z_]\w*)\s*;')
EXTERN_STATEMENT = re.compile(r'^extern\s+(?!")(.+)$', re.S)
DECLARED_NAME = re.compile(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$')
MEMBER_NAME = re.compile(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?::\s*\d+\s*)?(?:=[^;]*|\{[^;]*\})?$')


def blank_comments_and_literals(text):
    """`text` with comments and literals replaced by spaces, and the comments by line number.

    Offsets and line breaks are kept, so a position in the result is the same position in the
    file. Preprocessor directives stay; `blank_directives` removes them for statement rows.
    """
    out = []
    comments = {}
    i, n, line = 0, len(text), 1
    while i < n:
        c = text[i]
        if c == '\n':
            line += 1
            out.append(c)
            i += 1
        elif text.startswith('//', i):
            j = text.find('\n', i)
            j = n if j < 0 else j
            comments.setdefault(line, []).append(text[i:j])
            out.append(' ' * (j - i))
            i = j
        elif text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            body = text[i:j]
            for offset, part in enumerate(body.split('\n')):
                comments.setdefault(line + offset, []).append(part)
            out.append(''.join(ch if ch == '\n' else ' ' for ch in body))
            line += body.count('\n')
            i = j
        elif c == 'R' and text.startswith('R"', i) and (i == 0 or not (text[i - 1].isalnum() or text[i - 1] == '_')):
            close = text.find('(', i)
            end = text.find(')' + text[i + 2:close] + '"', close) if close > 0 else -1
            j = n if end < 0 else end + (close - i - 2) + 2
            body = text[i:j]
            out.append(''.join(ch if ch == '\n' else ' ' for ch in body))
            line += body.count('\n')
            i = j
        elif c in '"\'':
            # A digit separator (1'000) is not a character literal; the lint refuses it anyway.
            if c == "'" and i and text[i - 1].isalnum() and i + 1 < n and text[i + 1].isalnum() \
                    and not text.startswith("'", i + 2):
                out.append(' ')
                i += 1
                continue
            j = i + 1
            while j < n and text[j] != c and text[j] != '\n':
                j += 2 if text[j] == '\\' else 1
            j = min(j + 1, n)
            out.append(c + ' ' * (j - i - 2) + c if j - i >= 2 else ' ' * (j - i))
            i = j
        else:
            out.append(c)
            i += 1
    return ''.join(out), comments


def blank_directives(code):
    """`code` with every preprocessor line (and its backslash continuations) replaced by spaces."""
    out = []
    continued = False
    for line in code.split('\n'):
        directive = continued or line.lstrip().startswith('#')
        continued = directive and line.rstrip().endswith('\\')
        out.append(' ' * len(line) if directive else line)
    return '\n'.join(out)


def closing_paren(code, opened):
    """Index just past the `)` that closes the `(` at `opened`, or -1."""
    depth = 0
    for i in range(opened, len(code)):
        if code[i] == '(':
            depth += 1
        elif code[i] == ')':
            depth -= 1
            if not depth:
                return i + 1
    return -1


class Scope:
    __slots__ = ('kind', 'name', 'keyword', 'head_start', 'start', 'end', 'parent')

    def __init__(self, kind, name, keyword, head_start, start, parent):
        self.kind, self.name, self.keyword = kind, name, keyword
        self.head_start, self.start, self.end, self.parent = head_start, start, None, parent

    def ancestors(self):
        scope = self.parent
        while scope is not None:
            yield scope
            scope = scope.parent

    def qualified(self):
        parts = [s.name or '(anonymous)' for s in self.ancestors() if s.kind in ('namespace', 'type')]
        return '::'.join(reversed(parts + [self.name])) if parts else self.name


def classify(head, parent):
    """(kind, name, keyword) of the brace opened after `head` inside `parent`."""
    inside_function = parent is not None and (parent.kind in ('function', 'block', 'init')
                                              or any(a.kind == 'function' for a in parent.ancestors()))
    plain = ATTRIBUTE.sub(' ', head).strip()
    plain = re.sub(r'^(?:template\s*<[^{}]*>\s*)+', '', plain).strip()
    m = NAMESPACE_HEAD.match(plain)
    if m and not inside_function:
        return 'namespace', m.group(1) or '', None
    if plain.endswith('=') or not plain:
        return 'block', '', None
    m = TYPE_HEAD.search(plain)
    if m and '(' not in plain and '=' not in plain:
        return 'type', m.group(2), m.group(1)
    if ENUM_HEAD.search(plain):
        return 'enum', '', None
    if inside_function or ')' not in plain or STATEMENT_KEYWORD.match(plain):
        return 'block', '', None
    if (plain[-1].isalnum() or plain[-1] in '_>') and CTOR_INITIALISERS.search(plain):
        return 'init', '', None
    m = FUNCTION_NAME.search(plain)
    if not m or STATEMENT_KEYWORD.match(m.group(1)):
        return 'block', '', None
    return 'function', re.sub(r'\s+', '', m.group(1)), None


def scopes_of(code):
    """Every brace scope of `code` (comments, literals and directives already blanked)."""
    scopes = []
    stack = []
    boundary = 0
    for m in re.finditer(r'[{};]', code):
        i, c = m.start(), m.group()
        if c == ';':
            if not stack or stack[-1].kind != 'init':
                boundary = i + 1
            continue
        if c == '{':
            parent = stack[-1] if stack else None
            head = code[boundary:i]
            kind, name, keyword = classify(head, parent)
            scope = Scope(kind, name, keyword, boundary + len(head) - len(head.lstrip()), i, parent)
            scopes.append(scope)
            stack.append(scope)
            if kind != 'init':
                boundary = i + 1
            continue
        if stack:
            scope = stack.pop()
            scope.end = i + 1
            if scope.kind != 'init':
                boundary = i + 1
    for scope in stack:
        scope.end = len(code)
    return scopes


def at_file_scope(scope):
    return scope is None or (scope.kind == 'namespace' and all(a.kind == 'namespace' for a in scope.ancestors()))


class Unit:
    """One source file: its code views, scopes and line index."""

    def __init__(self, name, text):
        self.name = name
        self.text = text
        self.is_header = name.endswith('.h')
        code, self.comments = blank_comments_and_literals(text)
        self.with_directives = code
        self.code = blank_directives(code)
        self.scopes = scopes_of(self.code)
        self.scope_starts = [s.start for s in self.scopes]
        self.line_starts = [0] + [m.end() for m in re.finditer('\n', text)]
        self.functions = [s for s in self.scopes if s.kind == 'function']
        self.findings = []      # (line, rule, code, message, function scope or None)

    def line(self, pos):
        return bisect.bisect_right(self.line_starts, pos)

    def enclosing(self, pos):
        """The innermost scope containing `pos`. Scopes nest and are listed in opening order, so it
        is the last one opened before `pos`, or the nearest of its ancestors still open there."""
        i = bisect.bisect_left(self.scope_starts, pos) - 1
        scope = self.scopes[i] if i >= 0 else None
        while scope is not None and scope.end <= pos:
            scope = scope.parent
        return scope

    def function_at(self, pos):
        scope = self.enclosing(pos)
        while scope is not None and scope.kind != 'function':
            scope = scope.parent
        return scope

    def add(self, pos, rule, code, message):
        self.findings.append((self.line(pos), rule, code, message, self.function_at(pos)))

    def has_comment(self, line, pattern=None):
        return any(pattern is None or pattern.search(c) for c in self.comments.get(line, ()))


def statement_bounds(code, pos):
    start = max(code.rfind(c, 0, pos) for c in ';{}') + 1
    ends = [e for e in (code.find(c, pos) for c in ';{}') if e >= 0]
    return start, (min(ends) if ends else len(code))


def offset_cast_rows(unit):
    """R4: a constant added to a byte-pointer cast, the sum then cast to another pointer type."""
    code = unit.code
    for rx in (C_BYTE_CAST, NAMED_BYTE_CAST):
        for m in rx.finditer(code):
            if rx is NAMED_BYTE_CAST:
                operand_end = closing_paren(code, m.end() - 1)
                operand = code[m.end():operand_end - 1] if operand_end > 0 else ''
            else:
                rest = code[m.end():]
                if rest.lstrip().startswith('('):
                    opened = m.end() + len(rest) - len(rest.lstrip())
                    operand_end = closing_paren(code, opened)
                    operand = code[opened:operand_end] if operand_end > 0 else ''
                else:
                    om = OPERAND.match(rest)
                    operand_end = m.end() + om.end() if om else -1
                    operand = om.group() if om else ''
            if operand_end < 0 or not PLUS_CONSTANT.match(code, operand_end):
                continue
            start, _ = statement_bounds(code, m.start())
            before = code[start:m.start()]
            if OUTER_C_CAST.search(before) or OUTER_NAMED_CAST.search(before):
                what = 'this' if re.search(r'\bthis\b', operand) else 'a pointer'
                unit.add(m.start(), 'R4', 'offset-cast', f'constant offset from {what} through a byte-pointer cast; '
                                                         'declare the member')
    for m in re.finditer(r'^[ \t]*#[ \t]*define\b(?:[^\n\\]|\\.|\\\n)*', unit.with_directives, re.M):
        body = m.group()
        if 'offsetof' in body:
            continue
        cast = C_BYTE_CAST.search(body) or NAMED_BYTE_CAST.search(body)
        if cast and re.search(r'[+-]\s*(?:' + CONSTANT + r'|\(?\s*[A-Za-z_]\w*\s*\)?)', body[cast.end():]):
            unit.add(m.start(), 'R4', 'offset-macro', 'macro that reads through a byte-pointer offset; declare the member')


def fake_code_rows(unit):
    """R17 rows that need only the statement text."""
    code = unit.code
    for m in VOLATILE.finditer(code):
        line = unit.line(m.start())
        if unit.function_at(m.start()) is not None:
            # A cast to a volatile pointer (the interlocked intrinsics take one) declares nothing.
            start, _ = statement_bounds(code, m.start())
            before = code[start:m.start()]
            if before.count('(') > before.count(')') or before.count('<') > before.count('>'):
                continue
            unit.add(m.start(), 'R17', 'volatile-local', '`volatile` on a local; find the real type or the missing call')
        elif not (unit.has_comment(line, VOLATILE_NOTE) or unit.has_comment(line - 1, VOLATILE_NOTE)):
            unit.add(m.start(), 'R17', 'volatile', '`volatile` without a `// volatile: <evidence>` comment')
    for m in CONTROL.finditer(code):
        if m.group(1) != 'if':
            continue
        end = closing_paren(code, m.end() - 1)
        if end < 0:
            continue
        rest = code[end:end + 200]
        if re.match(r'\s*\{\s*\}', rest) or re.match(r'\s*;', rest):
            unit.add(m.start(), 'R17', 'empty-if', 'empty `if` body')
    for m in EMPTY_ELSE.finditer(code):
        unit.add(m.start(), 'R17', 'empty-else', 'empty `else` body')
    for m in WHILE_ZERO.finditer(code):
        if unit.function_at(m.start()) is not None:
            unit.add(m.start(), 'R17', 'do-while-zero', '`do { } while (0)` outside a macro; restore the macro')
    for m in SELF_ASSIGN.finditer(code):
        if unit.function_at(m.start(1)) is not None:
            unit.add(m.start(1), 'R17', 'self-assignment', 'a variable assigned to itself')
    for rx, code_name, what in ((PLUS_ZERO, 'plus-zero', '`+ 0`'), (TIMES_ONE, 'times-one', '`* 1`')):
        for m in rx.finditer(code):
            if unit.function_at(m.start()) is not None:
                unit.add(m.end() - 1, 'R17', code_name, f'{what} changes nothing but the generated code')
    for function in unit.functions:
        depth = 0
        previous = '{'
        for i in range(function.start + 1, function.end - 1):
            c = code[i]
            if c in '([':
                depth += 1
            elif c in ')]':
                depth -= 1
            elif c == ';' and not depth and previous in ';{':
                unit.add(i, 'R17', 'bare-semicolon', 'a `;` statement on its own')
            if not c.isspace():
                previous = c
    for m in ASSEMBLY.finditer(code):
        unit.add(m.start(), 'R18', 'assembly', 'assembly is not source')
    for m in PAD_VIRTUAL.finditer(code):
        unit.add(m.start(), 'R13', 'pad-virtual', 'a virtual named as padding; declare the real slot')


PRAGMA_STEERING = re.compile(r'^[ \t]*#[ \t]*pragma[ \t]+(optimize|intrinsic|function)\b', re.M)
BARRIER = re.compile(r'(?<![A-Za-z0-9_])_ReadWriteBarrier(?![A-Za-z0-9_])')
NOINLINE = re.compile(r'(?<![A-Za-z0-9_])noinline(?![A-Za-z0-9_])')
NOINLINE_NOTE = re.compile(r'//\s*noinline:\s*\S')
DECOMPILER_TYPE = re.compile(r'(?<![A-Za-z0-9_])(?:undefined[1248]?|(?:CONCAT|SUB|ZEXT|SEXT)\d\d|(?:CARRY|SBORROW)\d)(?![A-Za-z0-9_])')
DECOMPILER_NAME = re.compile(r'(?<![A-Za-z0-9_])(?:param_\d+|[uiplcb]Var\d+|local_[0-9a-f]+|in_\w+|extraout_\w+|unaff_\w+)(?![A-Za-z0-9_])')
# Label and paperwork lines of the project's own grammar (tools/lint_reconstruction.py); they are
# removed from a comment before the R40 words are looked for, so a label never trips the rule and
# a model name beside one still does.
COMMENT_EXEMPT = re.compile(r'(?:COMMUNITY|SIBLING|SYMBOLS|CRASHLOGGER_PDB)\([^)]*\)|SPDX-License-Identifier:.*'
                            r'|Sibling source:\s*\S+@\S+\s+\S+|CI hash:.*')
COMMENT_REFUSED = (
    (re.compile(r'(?<![A-Za-z0-9_])(?:Claude|GPT(?:-[\w.]+)?|Codex|Sonnet|Opus|Haiku|Gemini|ChatGPT|Copilot)(?![A-Za-z0-9_])'),
     'model or tool name', 'describe what the code does and why, not what produced it'),
    # `Drafted by <name>` and `written by <name>` are caught by the name row; the bare phrases are
    # ordinary header words, so only `generated by` is refused on its own.
    (re.compile(r'(?i)\bgenerated by\b'),
     'authorship phrase', 'delete the sentence; origin is carried by the label lines'),
    (re.compile(r'(?<![A-Za-z0-9_])chk_\w+'), 'checkpoint or pack id', 'delete the id; it means nothing outside the pipeline'),
    (re.compile(r'/Users/|[A-Za-z]:\\{1,2}Users\\|(?<![\w])\.local/'), 'internal path', 'delete the path'),
    (re.compile(r'[\w.+-]+@[\w-]+(?:\.[\w-]+)*\.[A-Za-z]{2,}\b'), 'e-mail address', 'delete the address'),
)


def refusal_rows(unit):
    """R38-R40: codegen steering, decompiler leftovers and non-clean comments."""
    code = unit.code
    for m in PRAGMA_STEERING.finditer(unit.with_directives):
        unit.add(m.start(), 'R38', 'pragma', f'`#pragma {m.group(1)}` steers code generation; remove it')
    for m in BARRIER.finditer(code):
        unit.add(m.start(), 'R38', 'barrier', '`_ReadWriteBarrier` steers code generation; remove it')
    for m in NOINLINE.finditer(code):
        line = unit.line(m.start())
        if not (unit.has_comment(line, NOINLINE_NOTE) or unit.has_comment(line - 1, NOINLINE_NOTE)):
            unit.add(m.start(), 'R38', 'noinline', '`noinline` without a `// noinline: <evidence>` comment; '
                                                   'add the evidence or remove it')
    for m in DECOMPILER_TYPE.finditer(code):
        unit.add(m.start(), 'R39', 'decompiler-type', f'`{m.group()}` is a decompiler type or helper; '
                                                      'write the real type or expression')
    for m in DECOMPILER_NAME.finditer(code):
        unit.add(m.start(), 'R39', 'decompiler-name', f'`{m.group()}` is a decompiler-style name; name what it holds')
    for line, parts in unit.comments.items():
        for part in parts:
            text = COMMENT_EXEMPT.sub(' ', part)
            for rx, what, fix in COMMENT_REFUSED:
                hit = rx.search(text)
                if hit:
                    unit.findings.append((line, 'R40', 'comment', f'{what} `{hit.group()}` in a comment; {fix}', None))


def refusals(name, text):
    """Diagnostics for the [match] rows R38-R40 in one file, for the PR gate. Each names the rule,
    file, line, offending text and the fix. Generated trees are not reconstructed units."""
    if name.startswith(SKIPPED_ROOTS) or not name.endswith(('.h', '.cpp')):
        return []
    unit = Unit(name, text)
    refusal_rows(unit)
    return [f'{name}:{line}: {rule} {code}: {message}' for line, rule, code, message, _f in sorted(
        unit.findings, key=lambda f: f[:3]) if rule in ('R38', 'R39', 'R40') and is_match(rule, code)]


def members_of(unit, scope):
    """(position, declaration text) of each data-member declaration directly inside a type."""
    code = unit.code
    start = scope.start + 1
    children = sorted((s for s in unit.scopes if s.parent is scope), key=lambda s: s.start)
    pieces = []
    for child in children:
        pieces.append((start, child.head_start if child.kind != 'init' else child.start))
        start = child.end
    pieces.append((start, scope.end - 1))
    for a, b in pieces:
        offset = a
        for statement in code[a:b].split(';')[:-1]:
            text = statement.strip()
            position = offset + len(statement) - len(statement.lstrip())
            offset += len(statement) + 1
            text = re.sub(r'^(?:(?:public|protected|private)\s*:\s*)+', '', text).strip()
            if text and '(' not in text and not re.match(r'(?:using|typedef|friend|static_assert|enum|template)\b', text):
                yield position, text


def declaration_rows(unit):
    """Per-file halves of R1, R2, R17 (padding members) and the advisory rows on declarations."""
    code = unit.code
    types = []      # (qualified name, keyword, body hash, position)
    for scope in unit.scopes:
        if scope.kind != 'type':
            continue
        for position, text in members_of(unit, scope):
            m = MEMBER_NAME.search(text)
            if m and PAD_NAME.match(m.group(1)):
                unit.add(position, 'R17', 'padding-member', f'member `{m.group(1)}`: the compiler pads by itself; '
                                                           'an unknown range is named by its offset')
        if all(a.kind == 'namespace' for a in scope.ancestors()):
            anonymous = any(not a.name for a in scope.ancestors())
            body = re.sub(r'\s+', ' ', code[scope.head_start:scope.end]).strip()
            types.append((scope.qualified(), scope.keyword, hashlib.sha256(body.encode()).hexdigest(),
                          scope.head_start, anonymous))
    forwards = [(m.group(2), m.group(1), m.start(1)) for m in FORWARD.finditer(code)
                if unit.function_at(m.start(1)) is None]
    externs = []    # (name, type text, position)
    boundary = 0
    for m in re.finditer(r'[{};]', code):
        i = m.start()
        if m.group() == ';':
            scope = unit.enclosing(i)
            text = code[boundary:i]
            statement = text.strip()
            position = boundary + len(text) - len(text.lstrip())
            em = EXTERN_STATEMENT.match(statement)
            in_function = unit.function_at(i) is not None
            if em and '(' not in ATTRIBUTE.sub(' ', em.group(1)):
                declared = ATTRIBUTE.sub(' ', em.group(1)).split('=')[0].strip()
                nm = DECLARED_NAME.search(declared)
                if nm and (at_file_scope(scope) or in_function):
                    kind = re.sub(r'\s+', ' ', declared[:nm.start(1)] + declared[nm.end(1):]).strip()
                    externs.append((nm.group(1), kind, position))
                    if not unit.is_header:
                        unit.add(position, 'R2', 'extern-outside-header',
                                 f'`extern {nm.group(1)}` declared in a .cpp; declare it once in a shared header')
            elif not unit.is_header and at_file_scope(scope) and ')' in statement and '=' not in statement \
                    and not re.match(r'(?:static|using|typedef|friend|template|return|static_assert)\b', statement):
                plain = ATTRIBUTE.sub(' ', statement).strip()
                nm = FUNCTION_NAME.search(plain)
                if nm and '::' not in nm.group(1) and not STATEMENT_KEYWORD.match(nm.group(1)) \
                        and plain.rstrip().endswith(')'):
                    declared = ''.join(nm.group(1).split())
                    unit.add(position, 'R25', 'prototype-in-cpp',
                             f'`{declared}` is declared in this .cpp; its prototype belongs in a header')
        boundary = i + 1
    return types, forwards, externs


def readability_rows(unit):
    code = unit.code
    seen = set()
    for rx in PLACEHOLDERS:
        for m in rx.finditer(code):
            if m.group() not in seen and not re.fullmatch(r'[0-9a-fA-F]+', m.group()):
                seen.add(m.group())
                unit.add(m.start(), 'R7', 'placeholder-name', f'`{m.group()}` is a placeholder or address-derived name')
    if not unit.is_header:
        for function in unit.functions:
            if not at_file_scope(function.parent):
                continue
            line = unit.line(function.head_start)
            if not unit.has_comment(line - 1):
                unit.add(function.head_start, 'R33', 'no-function-comment', f'`{function.name}` has no comment above it')
    for m in CONTROL.finditer(code):
        if m.group(1) == 'switch' or unit.function_at(m.start()) is None:
            continue
        end = closing_paren(code, m.end() - 1)
        if end < 0:
            continue
        following = code[end:end + 200].lstrip()[:1]
        if following and following not in '{;':
            unit.add(m.start(), 'R35', 'no-braces', f'`{m.group(1)}` body without braces')
    for m in ELSE.finditer(code):
        if unit.function_at(m.start()) is not None:
            unit.add(m.start(), 'R35', 'no-braces', '`else` body without braces')
    for m in IF_ZERO.finditer(unit.with_directives):
        unit.add(m.start(), 'R37', 'if-zero', '`#if 0` block: no build compiles it')
    for m in DOUBLE_NOT.finditer(code):
        if unit.function_at(m.start()) is not None:
            unit.add(m.start(), 'F', 'double-not', '`!!x`: sometimes human, often a width trick')


def source_files(root):
    base = Path(root) / SOURCE_ROOT
    names = (p.relative_to(root).as_posix() for p in base.rglob('*') if p.suffix in ('.h', '.cpp') and p.is_file())
    return sorted(name for name in names if not name.startswith(SKIPPED_ROOTS))


def analyse(root=ROOT, names=None):
    """Every unit under reconstruction/ with its findings, cross-file rows included."""
    root = Path(root)
    units = {}
    type_index = collections.defaultdict(list)      # qualified name -> (file, keyword, hash, position)
    forward_index = collections.defaultdict(list)   # name -> (file, keyword, position)
    extern_index = collections.defaultdict(list)    # name -> (file, type text, position)
    for name in (source_files(root) if names is None else names):
        unit = Unit(name, (root / name).read_text(encoding='utf-8', errors='replace'))
        units[name] = unit
        offset_cast_rows(unit)
        fake_code_rows(unit)
        refusal_rows(unit)
        types, forwards, externs = declaration_rows(unit)
        readability_rows(unit)
        for qualified, keyword, digest, position, anonymous in types:
            if not anonymous:
                type_index[qualified].append((name, keyword, digest, position))
        for short, keyword, position in forwards:
            forward_index[short].append((name, keyword, position))
        for variable, kind, position in externs:
            extern_index[variable].append((name, kind, position))
    for qualified, entries in type_index.items():
        bodies = {digest for _, _, digest, _ in entries}
        files = {name for name, _, _, _ in entries}
        if len(bodies) > 1 and len(files) > 1:
            for name, _, _, position in entries:
                units[name].add(position, 'R1', 'type-redefined', f'`{qualified}` has {len(bodies)} different '
                                                                  f'definitions in {len(files)} files')
        keywords = {keyword for _, keyword, _, _ in entries} - {'union'}
        short = qualified.rsplit('::', 1)[-1]
        declared = keywords | {keyword for _, keyword, _ in forward_index.get(short, ())}
        if len(declared) > 1:
            sites = [(name, position) for name, _, _, position in entries]
            sites += [(name, position) for name, _, position in forward_index.get(short, ())]
            for name, position in sorted(set(sites)):
                units[name].add(position, 'R1', 'keyword-mismatch', f'`{short}` is declared both `class` and `struct`; '
                                                                    'MSVC mangles the keyword')
    for variable, entries in extern_index.items():
        kinds = {kind for _, kind, _ in entries}
        if len(kinds) > 1:
            for name, _, position in entries:
                units[name].add(position, 'R2', 'extern-type-conflict', f'`{variable}` is declared with {len(kinds)} '
                                                                        'different types')
    for unit in units.values():
        unit.findings.sort(key=lambda f: (f[0], f[1], f[2]))
    return units


def include_closure(units, name, cache):
    """Repository files `name` reaches through quoted includes (itself included). Advisory resolver:
    the includer's folder, then the repository root, then reconstruction/."""
    if name in cache:
        return cache[name]
    cache[name] = closure = {name}
    for target in INCLUDE.findall(units[name].text):
        for candidate in (posixpath.normpath(posixpath.join(posixpath.dirname(name), target)),
                          posixpath.normpath(target), posixpath.normpath(posixpath.join(SOURCE_ROOT, target))):
            if candidate in units:
                closure |= include_closure(units, candidate, cache)
                break
    return closure


def compared_functions(unit):
    """{rva: name} from the unit's `// 0x<rva> <Name>` header lines."""
    return {int(rva, 16): name for rva, name in COMPARED_LINE.findall(unit.text)}


def unit_status(units):
    """{cpp: {rva: {'name', 'match': [rule codes], 'advisory': [rule codes]}}} for every compared function."""
    cache = {}
    status = {}
    for name, unit in units.items():
        if unit.is_header:
            continue
        compared = compared_functions(unit)
        if not compared:
            continue
        by_short = collections.defaultdict(list)
        for rva, full in compared.items():
            by_short[full.split('(')[0]].append(rva)
        shared = {'match': set(), 'advisory': set()}
        own = {rva: {'match': set(), 'advisory': set()} for rva in compared}
        for member in include_closure(units, name, cache):
            for _line, rule, code, _message, function in units[member].findings:
                tier = 'match' if is_match(rule, code) else 'advisory'
                targets = by_short.get(function.name, ()) if member == name and function is not None else ()
                if len(targets) == 1:
                    own[targets[0]][tier].add(f'{rule} {code}')
                else:
                    shared[tier].add(f'{rule} {code}')
        status[name] = {rva: {'name': compared[rva],
                              'match': sorted(own[rva]['match'] | shared['match']),
                              'advisory': sorted(own[rva]['advisory'] | shared['advisory'])} for rva in compared}
    return status


def totals(root, status):
    """Counts for `matched` inventory entries: bytes matched, matched under the rules, and of those
    the ones with no open naming finding (R7)."""
    progress = json.loads((Path(root) / 'data/progress.json').read_text(encoding='utf-8'))
    by_rva = {}
    for functions in status.values():
        by_rva.update(functions)
    result = collections.Counter()
    pending_by_rule = collections.Counter()
    for entry in progress.get('functions', ()):
        if entry.get('status') != 'matched':
            continue
        result['matched'] += 1
        result['matched_bytes'] += entry.get('size', 0)
        found = by_rva.get(entry.get('rva'))
        if found is None:
            result['no_unit_line'] += 1
            continue
        if found['match']:
            result['pending'] += 1
            for rule in {code.split()[0] for code in found['match']}:
                pending_by_rule[rule] += 1
            continue
        result['under_rules'] += 1
        result['under_rules_bytes'] += entry.get('size', 0)
        if not any(code.startswith('R7 ') for code in found['advisory']):
            result['under_rules_named'] += 1
            result['under_rules_named_bytes'] += entry.get('size', 0)
    return dict(result), dict(pending_by_rule)


def summary(units, status, counts, pending_by_rule):
    lines = []
    by_code = collections.Counter()
    files = collections.defaultdict(set)
    for name, unit in units.items():
        for _line, rule, code, _message, _function in unit.findings:
            by_code[(rule, code)] += 1
            files[(rule, code)].add(name)
    lines.append(f'{len(units)} files, {sum(len(f) for f in status.values())} compared functions in {len(status)} units')
    lines.append('')
    lines.append('rule  tier      finding                  count    files')
    order = {rule: i for i, rule in enumerate(MATCH_RULES + ADVISORY_RULES)}
    for (rule, code), count in sorted(by_code.items(), key=lambda item: (order.get(item[0][0], 99), item[0][1])):
        tier = 'match' if is_match(rule, code) else 'advisory'
        lines.append(f'{rule:<5} {tier:<9} {code:<24} {count:>6} {len(files[(rule, code)]):>8}')
    lines.append('')
    lines.append(f"matched (bytes, two hosts and review):       {counts.get('matched', 0):>6} functions "
                 f"{counts.get('matched_bytes', 0):>9} bytes")
    lines.append(f"matched under the rules:                     {counts.get('under_rules', 0):>6} functions "
                 f"{counts.get('under_rules_bytes', 0):>9} bytes")
    lines.append(f"  of which with no placeholder name (R7):    {counts.get('under_rules_named', 0):>6} functions "
                 f"{counts.get('under_rules_named_bytes', 0):>9} bytes")
    lines.append(f"MATCH-PENDING under the rules:               {counts.get('pending', 0):>6} functions"
                 + (' (' + ', '.join(f'{rule} {n}' for rule, n in sorted(pending_by_rule.items(),
                                                                          key=lambda i: order.get(i[0], 99))) + ')'
                    if pending_by_rule else ''))
    if counts.get('no_unit_line'):
        lines.append(f"matched with no `// 0x<rva>` line in a unit: {counts['no_unit_line']:>6} functions (not classified)")
    return '\n'.join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('files', nargs='*', help='repository-relative files to report on (default: totals only)')
    parser.add_argument('--list', action='store_true', help='print one line per finding in the named files')
    parser.add_argument('--strict', action='store_true', help='exit 1 when a named file has a [match] finding')
    parser.add_argument('--json', dest='json_path', help='write counts and per-unit status to this path')
    parser.add_argument('--root', default=str(ROOT), help=argparse.SUPPRESS)
    args = parser.parse_args(argv)
    root = Path(args.root)
    units = analyse(root)
    status = unit_status(units)
    named = [Path(f).as_posix() for f in args.files]
    unknown = [f for f in named if f not in units]
    if unknown:
        print('not a source file under reconstruction/: ' + ', '.join(unknown), file=sys.stderr)
        return 2
    failed = False
    for name in named:
        for line, rule, code, message, function in units[name].findings:
            matching = is_match(rule, code)
            failed = failed or matching
            if args.list or args.strict:
                where = f' in {function.name}' if function is not None else ''
                print(f"{name}:{line}: {rule} {code} [{'match' if matching else 'advisory'}]{where}: {message}")
    if not named or args.json_path:
        counts, pending_by_rule = totals(root, status)
        if not named:
            print(summary(units, status, counts, pending_by_rule))
        if args.json_path:
            payload = {'schema_version': 1, 'totals': counts, 'pending_by_rule': pending_by_rule,
                       'units': {name: {f'0x{rva:x}': value for rva, value in sorted(functions.items())}
                                 for name, functions in sorted(status.items())}}
            Path(args.json_path).write_text(json.dumps(payload, indent=1, sort_keys=True) + '\n', encoding='utf-8')
    return 1 if args.strict and failed else 0


if __name__ == '__main__':
    sys.exit(main())
