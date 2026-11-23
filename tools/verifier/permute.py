#!/usr/bin/env python3
"""Source permuter for one near-miss function: seeded rewrites, batch compiles, no model in the loop.

    tools/verifier/permute.py run <task-dir> --rva 0x... [--function Class::Name] [--also Class::Helper]
        [--source-root DIR] [--budget 600] [--batch 16] [--patience 8] [--seed 1] [--out DIR]
        [--jobs N] [--dry-run]
    tools/verifier/permute.py mutate <file.cpp> --function Class::Name [--steps 3] [--seed 1]

`run` reads the unit of a task directory (task.json as for `attempt`), finds the definition of the
target function in the compiled file, and searches for a variant of that one body whose object
code is closer to the target:

1. Mutations are deterministic, seeded rewrites at token and statement level (no C++ parser):
   the mechanisable rules of docs/matching-cookbook.md and docs/ideas-next.md P3 (R1 to R7), listed
   in MUTATIONS. Each one keeps ordinary C++; a few (temporaries, widths, signedness) can change
   meaning, which is harmless for the search because only a byte-identical object counts, and the
   Reviewer still reads the winner against the target.
2. Every candidate must pass tools/lint_reconstruction.py before it is compiled.
3. Candidates go to the runner host that `attempt` uses (.local/verifier/runners.json, so the same
   recipe, toolchain pins and image checks) in batches: one upload of the candidate sources, one
   agent command that compiles them `--jobs` at a time (default: the host's max_parallel, taking
   free slots only) in per-worker copies of the unit, and one download of the objects. The host
   needs no objdump; the objects are disassembled and scored here (align.py: distance and
   components, instruction counts, a hash of the function's code and relocations).
4. Search: greedy hill-climb over batches with sideways moves, random restarts from the best,
   and a seen-set keyed by the function's object-code hash. Stops at distance 0, at the wall-time
   budget, or after --patience batches without a new best.
5. At distance 0 the winning unit is compiled and compared once more by unit_build.py (the real
   comparator, all of the task's functions). Only that report says pass; run `attempt` on the
   winning source before anything is reviewed.

Outputs (private, under the task's .local tree unless --out): `best.cpp` (the unit with the best
body), `history.jsonl` (one row per scored candidate: id, parent, mutations, score), `result.json`
(start and best distance, candidates, timings, comparator result) and the comparator's
files under `final/`. Nothing game-derived is printed. Wall time of the run is queued to the cost
ledger as stage `draft`, as `attempt` does. `mutate` prints a mutated copy of a local file; it
is for tests and for perturbing a matched unit in a recovery self-test.
"""
import argparse
import copy
import hashlib
import json
import os
from pathlib import Path
import random
import re
import shutil
import sys
import time

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
REMOTE_TOOLS = ('tools/verifier/permute.py', 'tools/verifier/align.py', 'tools/verifier/disasm.py')

# --------------------------------------------------------------------------------------------
# Tokens: every token keeps the whitespace and comments before it, so emit(parse(x)) == x.

TOKEN = re.compile(r'''
   (?P<str>(?:u8|[uUL])?"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*')
  |(?P<num>\.?[0-9](?:[A-Za-z0-9_.]|[eEpP][+-])*)
  |(?P<id>[A-Za-z_][A-Za-z0-9_]*)
  |(?P<pp>\#[^\n]*)
  |(?P<op>::|->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|\.\.\.|[{}()\[\];,<>=+\-*/%&|^!~?:.])
''', re.X)
TRIVIA = re.compile(r'(?:\s+|//[^\n]*|/\*.*?\*/)*', re.S)


class Tok:
    __slots__ = ('kind', 'text', 'pre')

    def __init__(self, kind, text, pre=' '):
        self.kind, self.text, self.pre = kind, text, pre

    def __repr__(self):
        return f'Tok({self.text!r})'


def lex(text):
    toks, i = [], 0
    while True:
        m = TRIVIA.match(text, i)
        pre, i = m.group(0), m.end()
        if i >= len(text):
            return toks, pre
        m = TOKEN.match(text, i)
        if not m:
            raise ValueError(f'cannot tokenise at offset {i}')
        toks.append(Tok(m.lastgroup, m.group(0), pre))
        i = m.end()


def emit_toks(toks):
    return ''.join(t.pre + t.text for t in toks)


def new(text, pre=' '):
    kind = 'id' if re.fullmatch(r'[A-Za-z_]\w*', text) else 'num' if text[:1].isdigit() else 'op'
    return Tok(kind, text, pre)


def toks_of(text, pre=' '):
    out, _ = lex(text)
    if out:
        out[0].pre = pre
    return out


# --------------------------------------------------------------------------------------------
# Statements. A body is a Block; nodes hold token lists, so emitting them reproduces the source.

class Node:
    kind = 'node'

    def toks(self):
        raise NotImplementedError


class Simple(Node):
    """Declaration, expression, return, break, continue: tokens up to and including `;`."""
    kind = 'simple'

    def __init__(self, toks):
        self.t = toks

    def toks(self):
        return list(self.t)


class Label(Node):
    kind = 'label'

    def __init__(self, toks):
        self.t = toks

    def toks(self):
        return list(self.t)


class Block(Node):
    kind = 'block'

    def __init__(self, lb, stmts, rb):
        self.lb, self.stmts, self.rb = lb, stmts, rb

    def toks(self):
        out = [self.lb]
        for s in self.stmts:
            out += s.toks()
        return out + [self.rb]


class If(Node):
    kind = 'if'

    def __init__(self, head, cond, rp, then, else_kw=None, els=None):
        self.head, self.cond, self.rp, self.then, self.else_kw, self.els = head, cond, rp, then, else_kw, els

    def toks(self):
        out = list(self.head) + list(self.cond) + [self.rp] + self.then.toks()
        if self.els is not None:
            out += [self.else_kw] + self.els.toks()
        return out


class Loop(Node):
    """for, while and switch: keyword, `(`, header tokens, `)`, body."""

    def __init__(self, kw, lp, inner, rp, body):
        self.kind = kw.text
        self.kw, self.lp, self.inner, self.rp, self.body = kw, lp, inner, rp, body

    def toks(self):
        return [self.kw, self.lp] + list(self.inner) + [self.rp] + self.body.toks()


class Opaque(Node):
    """do-while and try/catch: token runs and nested statements in order."""
    kind = 'opaque'

    def __init__(self, parts):
        self.parts = parts

    def toks(self):
        out = []
        for p in self.parts:
            out += p.toks() if isinstance(p, Node) else list(p)
        return out


def _balanced(toks, i):
    """Index just past the group opened at toks[i] (one of ( [ {)."""
    pairs = {'(': ')', '[': ']', '{': '}'}
    stack = []
    while i < len(toks):
        t = toks[i].text
        if t in pairs:
            stack.append(pairs[t])
        elif t in (')', ']', '}'):
            if not stack or stack.pop() != t:
                raise ValueError('unbalanced brackets')
            if not stack:
                return i + 1
        i += 1
    raise ValueError('unbalanced brackets')


def parse_block(toks, i):
    if toks[i].text != '{':
        raise ValueError('block expected')
    lb, i, stmts = toks[i], i + 1, []
    while i < len(toks) and toks[i].text != '}':
        st, i = parse_stmt(toks, i)
        stmts.append(st)
    if i >= len(toks):
        raise ValueError('unterminated block')
    return Block(lb, stmts, toks[i]), i + 1


def _paren(toks, i):
    if toks[i].text != '(':
        raise ValueError('( expected')
    end = _balanced(toks, i)
    return toks[i], toks[i + 1:end - 1], toks[end - 1], end


def parse_stmt(toks, i):
    t = toks[i].text
    if t == '{':
        return parse_block(toks, i)
    if t == 'if':
        head = [toks[i]]
        i += 1
        if toks[i].text == 'constexpr':
            head.append(toks[i])
            i += 1
        lp, cond, rp, i = _paren(toks, i)
        then, i = parse_stmt(toks, i)
        if i < len(toks) and toks[i].text == 'else':
            kw = toks[i]
            els, i = parse_stmt(toks, i + 1)
            return If(head + [lp], cond, rp, then, kw, els), i
        return If(head + [lp], cond, rp, then), i
    if t in ('for', 'while', 'switch'):
        kw = toks[i]
        lp, inner, rp, i = _paren(toks, i + 1)
        body, i = parse_stmt(toks, i)
        return Loop(kw, lp, inner, rp, body), i
    if t == 'do':
        body, j = parse_stmt(toks, i + 1)
        end = j
        while toks[end].text != ';':
            end = _balanced(toks, end) if toks[end].text in '([{' else end + 1
        return Opaque([[toks[i]], body, toks[j:end + 1]]), end + 1
    if t == 'try':
        block, j = parse_block(toks, i + 1)
        parts = [[toks[i]], block]
        while j < len(toks) and toks[j].text == 'catch':
            end = _balanced(toks, j + 1)
            handler, k = parse_block(toks, end)
            parts += [toks[j:end], handler]
            j = k
        return Opaque(parts), j
    if t in ('case', 'default') or (toks[i].kind == 'id' and i + 1 < len(toks) and toks[i + 1].text == ':'
                                    and t not in KEYWORDS):
        j = i
        while toks[j].text != ':':
            j += 1
        return Label(toks[i:j + 1]), j + 1
    j = i
    while j < len(toks) and toks[j].text != ';':
        if toks[j].text in ('(', '[', '{'):
            j = _balanced(toks, j)
        elif toks[j].text == '}':
            raise ValueError('statement without ;')
        else:
            j += 1
    if j >= len(toks):
        raise ValueError('statement without ;')
    return Simple(toks[i:j + 1]), j + 1


def parse_body(text):
    """(Block, trailing trivia) of a `{ ... }` body text."""
    toks, tail = lex(text)
    block, i = parse_block(toks, 0)
    if i != len(toks):
        raise ValueError('text after the body')
    return block, tail


def emit(block, tail=''):
    return emit_toks(block.toks()) + tail


# --------------------------------------------------------------------------------------------
# Locating the function definition in the compiled file.

def find_body(text, qualified):
    """(start, end) of the `{ ... }` body of the definition of `qualified` (e.g. "TESFile::Seek")."""
    parts = qualified.split('::')
    toks, _ = lex(text)
    offsets, pos = [], 0
    for t in toks:
        pos += len(t.pre)
        offsets.append(pos)
        pos += len(t.text)
    names = [t.text for t in toks]
    want = []
    for p in parts:
        want += [p, '::']
    want = want[:-1]
    hits = []
    for i in range(len(toks) - len(want)):
        if names[i:i + len(want)] != want or (i and names[i - 1] == '::'):
            continue
        j = i + len(want)
        if j >= len(toks) or names[j] != '(':
            continue
        j = _balanced(toks, j)
        # qualifiers between ) and { : const, noexcept, override, -> type; a `;` means a declaration
        while j < len(toks) and names[j] not in ('{', ';', ':'):
            j = _balanced(toks, j) if names[j] in ('(', '[') else j + 1
        if j < len(toks) and names[j] == '{':
            end = _balanced(toks, j)
            hits.append((offsets[j], offsets[end - 1] + 1))
    if len(hits) != 1:
        raise ValueError(f'{qualified}: {len(hits)} definitions found in the compiled file (need exactly 1)')
    return hits[0]


# --------------------------------------------------------------------------------------------
# Tree helpers.

KEYWORDS = {'return', 'if', 'else', 'for', 'while', 'do', 'switch', 'case', 'default', 'break', 'continue',
            'goto', 'new', 'delete', 'sizeof', 'static_cast', 'reinterpret_cast', 'const_cast',
            'dynamic_cast', 'throw', 'try', 'catch', 'typedef', 'using', 'operator', 'alignof', 'decltype',
            'noexcept', 'static_assert', 'this', 'nullptr', 'true', 'false'}
TYPE_WORDS = {'unsigned', 'signed', 'short', 'long', 'int', 'char', 'bool', 'float', 'double', 'void',
              'auto', 'const', 'volatile', 'static', 'wchar_t', '__int64', 'std', 'struct', 'class'}
ASSIGN_OPS = {'=', '+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<<=', '>>='}


def walk_blocks(node):
    """Every Block in the tree, outermost first."""
    if isinstance(node, Block):
        yield node
        for s in node.stmts:
            yield from walk_blocks(s)
    elif isinstance(node, If):
        yield from walk_blocks(node.then)
        if node.els is not None:
            yield from walk_blocks(node.els)
    elif isinstance(node, Loop):
        yield from walk_blocks(node.body)
    elif isinstance(node, Opaque):
        for p in node.parts:
            if isinstance(p, Node):
                yield from walk_blocks(p)


def walk_nodes(node):
    yield node
    if isinstance(node, Block):
        for s in node.stmts:
            yield from walk_nodes(s)
    elif isinstance(node, If):
        yield from walk_nodes(node.then)
        if node.els is not None:
            yield from walk_nodes(node.els)
    elif isinstance(node, Loop):
        yield from walk_nodes(node.body)
    elif isinstance(node, Opaque):
        for p in node.parts:
            if isinstance(p, Node):
                yield from walk_nodes(p)


def expr_lists(root):
    """Mutable token lists that hold expressions: simple statements, conditions, loop headers."""
    out = []
    for n in walk_nodes(root):
        if isinstance(n, Simple):
            out.append(n.t)
        elif isinstance(n, If):
            out.append(n.cond)
        elif isinstance(n, Loop):
            out.append(n.inner)
    return out


def uses(toks, name):
    """Positions where identifier `name` is used as a variable (not as a member or qualified name)."""
    return [i for i, t in enumerate(toks) if t.text == name and t.kind == 'id'
            and not (i and toks[i - 1].text in ('.', '->', '::'))
            and not (i + 1 < len(toks) and toks[i + 1].text == '::')]


def node_mentions(node, name):
    return bool(uses(node.toks(), name))


def has_call(toks):
    return any(t.text == '(' and i and (toks[i - 1].kind == 'id' or toks[i - 1].text in (')', ']', '>'))
               and toks[i - 1].text not in KEYWORDS - {'this'}
               for i, t in enumerate(toks))


def written(toks, name):
    """True when `name` is assigned, incremented or has its address taken in `toks`."""
    for i in uses(toks, name):
        nxt = toks[i + 1].text if i + 1 < len(toks) else ''
        prv = toks[i - 1].text if i else ''
        if nxt in ASSIGN_OPS or nxt in ('++', '--') or prv in ('++', '--'):
            return True
        if prv == '&' and (i < 2 or toks[i - 2].kind != 'id' and toks[i - 2].text not in (')', ']')):
            return True
    return False


def decl_info(st):
    """(type tokens, name, index of `=` or None) when a simple statement declares one local."""
    if not isinstance(st, Simple):
        return None
    t = st.t
    if not t or t[0].kind != 'id' or t[0].text in KEYWORDS:
        return None
    i, words = 0, 0
    while i < len(t) and t[i].text in ('const', 'volatile', 'static', 'struct', 'class'):
        i += 1
    while i < len(t) and t[i].kind == 'id' and t[i].text in TYPE_WORDS - {'std', 'const', 'volatile'}:
        i += 1
        words += 1
    if not words:
        if i >= len(t) or t[i].kind != 'id':
            return None
        i += 1
        while i + 1 < len(t) and t[i].text == '::' and t[i + 1].kind == 'id':
            i += 2
        if i < len(t) and t[i].text == '<':
            depth = 0
            while i < len(t):
                depth += {'<': 1, '>': -1, '>>': -2}.get(t[i].text, 0)
                i += 1
                if depth <= 0:
                    break
    while i < len(t) and t[i].text in ('*', '&', 'const', 'volatile'):
        i += 1
    if i >= len(t) or t[i].kind != 'id' or t[i].text in KEYWORDS:
        return None
    name = i
    nxt = t[name + 1].text if name + 1 < len(t) else ''
    if nxt == ';':
        return t[:name], t[name].text, None
    if nxt == '=' and _top_level_comma(t[name + 2:-1]) is None:
        return t[:name], t[name].text, name + 1
    return None


def _top_level_comma(toks):
    depth = 0
    for i, t in enumerate(toks):
        if t.text in '([{':
            depth += 1
        elif t.text in ')]}':
            depth -= 1
        elif t.text == ',' and depth == 0:
            return i
    return None


def ends_in_return(node):
    if isinstance(node, Simple):
        return bool(node.t) and node.t[0].text in ('return', 'break', 'continue', 'throw', 'goto')
    if isinstance(node, Block):
        return bool(node.stmts) and ends_in_return(node.stmts[-1])
    if isinstance(node, If):
        return node.els is not None and ends_in_return(node.then) and ends_in_return(node.els)
    return False


def as_block(node, indent=None):
    if isinstance(node, Block):
        return node
    return Block(new('{'), [node], new('}', ' '))


def declared_names(stmts):
    return {d[1] for d in (decl_info(s) for s in stmts) if d}


# --------------------------------------------------------------------------------------------
# Atoms: operands simple enough to move without a parser: names, members, empty calls, literals.

def atom_end(toks, i):
    if i >= len(toks):
        return None
    t = toks[i]
    if t.kind in ('num', 'str'):
        return i + 1
    if t.kind != 'id' or (t.text in KEYWORDS and t.text not in ('this', 'nullptr', 'true', 'false')):
        return None
    j = i + 1
    while j < len(toks):
        if toks[j].text in ('.', '->', '::') and j + 1 < len(toks) and toks[j + 1].kind == 'id':
            j += 2
        elif toks[j].text == '(' and j + 1 < len(toks) and toks[j + 1].text == ')':
            j += 2
        elif toks[j].text == '[':
            k = atom_end(toks, j + 1)
            if k is None or k >= len(toks) or toks[k].text != ']':
                break
            j = k + 1
        else:
            break
    return j


def atom_spans(toks):
    """{end: start} of the longest atom ending at each position."""
    by_end = {}
    for i in range(len(toks)):
        if i and toks[i - 1].text in ('.', '->', '::'):
            continue
        e = atom_end(toks, i)
        if e is not None and (e not in by_end or by_end[e] > i):
            by_end[e] = i
    return by_end


# No statement start: `T * name;` and `T & name = x;` are declarations, not products.
LEFT_OK = {'(', ',', '=', 'return', '&&', '||', '?', ':', '['} | ASSIGN_OPS
RIGHT_OK = {')', ',', ';', '&&', '||', '?', ':', ']', '}'}
FLIP = {'<': '>', '>': '<', '<=': '>=', '>=': '<=', '==': '==', '!=': '!='}
NEGATE = {'<': '>=', '>=': '<', '>': '<=', '<=': '>', '==': '!=', '!=': '=='}
COMMUTE = {'+', '*', '&', '|', '^', '==', '!='}


def expr_sites(root, ops, pure=False):
    """[(token list, site)] over the body; a simple statement's list starts a statement."""
    out = []
    for n in walk_nodes(root):
        if isinstance(n, Simple):
            out += [(n.t, s) for s in binary_sites(n.t, ops, pure, start=';')]
        elif isinstance(n, If):
            out += [(n.cond, s) for s in binary_sites(n.cond, ops, pure)]
        elif isinstance(n, Loop):
            out += [(n.inner, s) for s in binary_sites(n.inner, ops, pure)]
    return out


def binary_sites(toks, ops, pure=False, start='('):
    """(left start, op index, right end) for `atom op atom` with low-precedence neighbours."""
    by_end = atom_spans(toks)
    out = []
    for k, t in enumerate(toks):
        if t.text not in ops or k not in by_end:
            continue
        s = by_end[k]
        e = atom_end(toks, k + 1)
        if e is None:
            continue
        left = toks[s - 1].text if s else start
        right = toks[e].text if e < len(toks) else ')'
        if left not in LEFT_OK or right not in RIGHT_OK:
            continue
        if pure and (has_call(toks[s:k]) or has_call(toks[k + 1:e])):
            continue
        out.append((s, k, e))
    return out


def swap_operands(toks, s, k, e, op_text):
    left, right = toks[s:k], toks[k + 1:e]
    pre_l, pre_op, pre_r = left[0].pre, toks[k].pre, right[0].pre
    left, right = [copy.copy(x) for x in left], [copy.copy(x) for x in right]
    right[0].pre, left[0].pre = pre_l, pre_r
    toks[s:e] = right + [Tok('op', op_text, pre_op)] + left


def top_level(toks, op):
    """Index of the first `op` outside brackets, or None."""
    depth = 0
    for i, t in enumerate(toks):
        if t.text in '([{':
            depth += 1
        elif t.text in ')]}':
            depth -= 1
        elif t.text == op and depth == 0:
            return i
    return None


def top_level_all(toks, op):
    depth, out = 0, []
    for i, t in enumerate(toks):
        if t.text in '([{':
            depth += 1
        elif t.text in ')]}':
            depth -= 1
        elif t.text == op and depth == 0:
            out.append(i)
    return out


def negate(cond):
    """Token list of the negated condition."""
    if not cond:
        return toks_of('false')
    if cond[0].text == '!' and len(cond) > 1:
        rest = cond[1:]
        if atom_end(rest, 0) == len(rest):
            out = [copy.copy(x) for x in rest]
            out[0].pre = cond[0].pre
            return out
        if rest[0].text == '(' and _balanced(rest, 0) == len(rest):
            out = [copy.copy(x) for x in rest[1:-1]]
            out[0].pre = cond[0].pre
            return out
    if top_level(cond, '&&') is None and top_level(cond, '||') is None and top_level(cond, '?') is None:
        hits = [i for i, t in enumerate(cond) if t.text in NEGATE and top_level(cond, t.text) == i]
        if len(hits) == 1 and not any(t.text in ('<', '>') for t in cond if t is not cond[hits[0]]):
            out = [copy.copy(x) for x in cond]
            out[hits[0]] = Tok('op', NEGATE[cond[hits[0]].text], cond[hits[0]].pre)
            return out
    if atom_end(cond, 0) == len(cond):
        return [Tok('op', '!', cond[0].pre)] + _with_pre(cond, '')
    return [Tok('op', '!', cond[0].pre), Tok('op', '(', '')] + _with_pre(cond, '') + [Tok('op', ')', '')]


def _with_pre(toks, pre):
    out = [copy.copy(x) for x in toks]
    if out:
        out[0].pre = pre
    return out


# --------------------------------------------------------------------------------------------
# Mutations. Each takes (body Block, rng) and returns True when it changed the tree. Tags name the
# cookbook rule or P3 rule (docs/ideas-next.md) it mechanises.

def m_decl_swap(root, rng):
    """R1: swap two adjacent local declarations whose initialisers do not depend on each other."""
    sites = []
    for b in walk_blocks(root):
        for i in range(len(b.stmts) - 1):
            a, c = decl_info(b.stmts[i]), decl_info(b.stmts[i + 1])
            if not a or not c:
                continue
            ta, tc = b.stmts[i].t, b.stmts[i + 1].t
            if uses(tc, a[1]) or uses(ta, c[1]):
                continue
            if a[2] is not None and c[2] is not None and has_call(ta) and has_call(tc):
                continue
            sites.append((b, i))
    if not sites:
        return False
    b, i = rng.choice(sites)
    x, y = b.stmts[i], b.stmts[i + 1]
    x.t[0].pre, y.t[0].pre = y.t[0].pre, x.t[0].pre
    b.stmts[i], b.stmts[i + 1] = y, x
    return True


def m_decl_move(root, rng):
    """R1: move an uninitialised or call-free declaration to its block's start or to its first use."""
    sites = []
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            d = decl_info(st)
            if not d or (d[2] is not None and has_call(st.t)):
                continue
            init_names = {t.text for t in st.t[d[2] + 1:]} if d[2] is not None else set()
            first = next((j for j in range(i + 1, len(b.stmts)) if node_mentions(b.stmts[j], d[1])), None)
            if first is not None and first > i + 1:
                between = b.stmts[i + 1:first]
                if not any(node_mentions(s, n) for s in between for n in init_names):
                    sites.append((b, i, first - 1))
            top = 0
            while top < i and isinstance(b.stmts[top], Label):
                top += 1
            if i > top:
                before = b.stmts[top:i]
                if not any(node_mentions(s, n) for s in before for n in init_names | {d[1]}) \
                        and not any(isinstance(s, Label) for s in before):
                    sites.append((b, i, top))
    if not sites:
        return False
    b, i, j = rng.choice(sites)
    st = b.stmts.pop(i)
    b.stmts.insert(j, st)
    return True


def m_decl_split(root, rng):
    """R2: `T x = e;` becomes `T x; x = e;`, or the reverse."""
    sites = []
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            d = decl_info(st)
            if not d:
                continue
            words = {t.text for t in d[0]}
            if d[2] is not None and not words & {'const', 'auto', 'static'} and '&' not in words \
                    and not (st.t[d[2] + 1].text == '{'):
                sites.append(('split', b, i, d))
            if d[2] is None and i + 1 < len(b.stmts) and isinstance(b.stmts[i + 1], Simple):
                nt = b.stmts[i + 1].t
                if len(nt) > 2 and nt[0].text == d[1] and nt[1].text == '=' and not uses(nt[2:], d[1]):
                    sites.append(('join', b, i, d))
    if not sites:
        return False
    how, b, i, d = rng.choice(sites)
    st = b.stmts[i]
    if how == 'split':
        decl = Simple(st.t[:d[2]] + [Tok('op', ';', '')])
        assign = Simple([Tok('id', d[1], st.t[0].pre)] + st.t[d[2]:])
        b.stmts[i:i + 1] = [decl, assign]
    else:
        nt = b.stmts[i + 1].t
        b.stmts[i:i + 2] = [Simple(st.t[:-1] + [Tok('op', '=', ' ')] + nt[2:])]
    return True


def m_temp_inline(root, rng):
    """R3: inline a temporary into its single use in the next statement (or a pure one everywhere)."""
    sites = []
    body_toks = root.toks()
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            d = decl_info(st)
            if not d or d[2] is None or i + 1 >= len(b.stmts):
                continue
            init = st.t[d[2] + 1:-1]
            if not init or top_level(init, ',') is not None:
                continue
            rest = [t for s in b.stmts[i + 1:] for t in s.toks()]
            if written(rest, d[1]) or len(uses(body_toks, d[1])) != 1 + len(uses(rest, d[1])):
                continue
            n_next = len(uses(b.stmts[i + 1].toks(), d[1]))
            if n_next == 1 and len(uses(rest, d[1])) == 1:
                sites.append((b, i, d, init))
            elif not has_call(init) and uses(rest, d[1]) and atom_end(init, 0) == len(init):
                sites.append((b, i, d, init))  # a re-read of a member at every use (cookbook 1)
    if not sites:
        return False
    b, i, d, init = rng.choice(sites)
    words = [t.text for t in d[0]]
    plain = atom_end(init, 0) == len(init)
    if 'auto' in words or (words and words[-1] in ('*', '&')) or 'bool' in words:
        repl = init if plain else [Tok('op', '(', '')] + _with_pre(init, '') + [Tok('op', ')', '')]
    else:
        tname = ' '.join(t.text for t in d[0] if t.text not in ('const', 'volatile', 'static'))
        repl = toks_of(f'static_cast<{tname}>(', '') + _with_pre(init, '') + [Tok('op', ')', '')]
    del b.stmts[i]
    for st in b.stmts[i:]:
        for n in walk_nodes(st):
            for lst in ([n.t] if isinstance(n, Simple) else [n.cond] if isinstance(n, If)
                        else [n.inner] if isinstance(n, Loop) else []):
                for pos in reversed(uses(lst, d[1])):
                    r = _with_pre(repl, lst[pos].pre)
                    lst[pos:pos + 1] = r
    return True


def m_temp_introduce(root, rng):
    """R3: name a member read (or empty call) that a block's statements repeat, from its first use on."""
    sites = []
    for b in walk_blocks(root):
        counts = {}
        for idx, st in enumerate(b.stmts):
            if not isinstance(st, (Simple, If, Loop)):
                continue
            lst = st.t if isinstance(st, Simple) else st.cond if isinstance(st, If) else st.inner
            by_end = atom_spans(lst)
            for e, s in by_end.items():
                text = tuple(t.text for t in lst[s:e])
                if len(text) >= 3 and ('->' in text or '.' in text):
                    counts.setdefault(text, []).append(idx)
        for text, idxs in counts.items():
            if len(idxs) < 2:
                continue
            first = idxs[0]
            region = [t for s in b.stmts[first:] for t in s.toks()]
            joined = [t.text for t in region]
            n = len(text)
            writes = any(joined[j:j + n] == list(text) and j + n < len(joined) and joined[j + n] in ASSIGN_OPS | {'++', '--'}
                         for j in range(len(joined) - n))
            if writes or isinstance(b.stmts[first], Loop) and b.stmts[first].kind != 'switch':
                continue
            sites.append((b, first, text))
    if not sites:
        return False
    b, first, text = rng.choice(sites)
    taken = {t.text for t in root.toks() if t.kind == 'id'}
    k = 0
    while f'v{k}' in taken:
        k += 1
    name = f'v{k}'
    pre = b.stmts[first].toks()[0].pre
    # An atom never holds two adjacent names, so its tokens can be joined without spaces.
    decl = Simple(toks_of(f'auto {name} =', pre) + toks_of(''.join(text), ' ') + [Tok('op', ';', '')])
    n = len(text)
    for st in b.stmts[first:]:
        for node in walk_nodes(st):
            for lst in ([node.t] if isinstance(node, Simple) else [node.cond] if isinstance(node, If)
                        else [node.inner] if isinstance(node, Loop) else []):
                j = 0
                while j <= len(lst) - n:
                    if tuple(t.text for t in lst[j:j + n]) == text and not (j and lst[j - 1].text in ('.', '->', '::')) \
                            and not (j + n < len(lst) and lst[j + n].text == '('):
                        lst[j:j + n] = [Tok('id', name, lst[j].pre)]
                    j += 1
    b.stmts.insert(first, decl)
    return True


def m_if_invert(root, rng):
    """R5: `if (c) A else B` becomes `if (!c) B else A`."""
    sites = [n for n in walk_nodes(root) if isinstance(n, If) and n.els is not None and not isinstance(n.els, If)]
    if not sites:
        return False
    n = rng.choice(sites)
    n.cond[:] = negate(n.cond)
    n.then, n.els = as_block(n.els), as_block(n.then)
    return True


def m_early_return(root, rng):
    """R5: early return versus nested: `if (c) {..return;} rest` <-> `if (c) {..return;} else {rest}`."""
    sites = []
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            if not isinstance(st, If):
                continue
            if st.els is None and ends_in_return(st.then) and i + 1 < len(b.stmts) \
                    and not any(isinstance(s, Label) for s in b.stmts[i + 1:]):
                sites.append(('nest', b, i))
            if st.els is not None and isinstance(st.els, Block) and ends_in_return(st.then):
                outer = declared_names(b.stmts[:i] + b.stmts[i + 1:])
                if not declared_names(st.els.stmts) & outer:
                    sites.append(('flat', b, i))
    if not sites:
        return False
    how, b, i = rng.choice(sites)
    st = b.stmts[i]
    if how == 'nest':
        rest = b.stmts[i + 1:]
        del b.stmts[i + 1:]
        st.then = as_block(st.then)
        st.else_kw, st.els = new('else'), Block(new('{'), rest, new('}', b.rb.pre))
    else:
        inner = st.els.stmts
        st.else_kw, st.els = None, None
        b.stmts[i + 1:i + 1] = inner
    return True


def m_and_split(root, rng):
    """R5: `if (a && b) S` <-> `if (a) { if (b) S }` (no else on either)."""
    sites = []
    for n in walk_nodes(root):
        if not isinstance(n, If) or n.els is not None:
            continue
        k = top_level(n.cond, '&&')
        if k is not None and top_level(n.cond, '||') is None and top_level(n.cond, '?') is None:
            sites.append(('split', n, k))
        inner = n.then.stmts[0] if isinstance(n.then, Block) and len(n.then.stmts) == 1 else n.then
        if isinstance(inner, If) and inner.els is not None:
            continue
        if isinstance(inner, If):
            sites.append(('join', n, inner))
    if not sites:
        return False
    how, n, x = rng.choice(sites)
    if how == 'split':
        a, c = n.cond[:x], n.cond[x + 1:]
        c = _with_pre(c, '')
        n.cond[:] = a
        n.then = Block(new('{'), [If([new('if'), Tok('op', '(', ' ')], c, Tok('op', ')', ''), n.then)], new('}'))
    else:
        def wrap(c):
            if top_level(c, '||') is not None or top_level(c, '?') is not None or top_level(c, '=') is not None:
                return [Tok('op', '(', c[0].pre)] + _with_pre(c, '') + [Tok('op', ')', '')]
            return [copy.copy(t) for t in c]
        n.cond[:] = wrap(n.cond) + [Tok('op', '&&', ' ')] + _with_pre(wrap(x.cond), ' ')
        n.then = x.then
    return True


def m_loop_form(root, rng):
    """R6: `for (i; c; s) B` <-> `{ i; while (c) { B s; } }`; `while (c)` <-> `for (; c;)`."""
    sites = []
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            if not isinstance(st, Loop) or st.kind not in ('for', 'while'):
                continue
            if st.kind == 'while':
                sites.append(('while-for', b, i))
                continue
            if len(top_level_all(st.inner, ';')) != 2 or any(t.text == 'continue' for t in st.body.toks()):
                continue
            sites.append(('for-while', b, i))
    if not sites:
        return False
    how, b, i = rng.choice(sites)
    st = b.stmts[i]
    if how == 'while-for':
        st.kw = Tok('id', 'for', st.kw.pre)
        st.kind = 'for'
        st.inner[:] = [Tok('op', ';', '')] + _with_pre(st.inner, ' ') + [Tok('op', ';', '')]
        return True
    semis = top_level_all(st.inner, ';')
    init, cond, step = st.inner[:semis[0]], st.inner[semis[0] + 1:semis[1]], st.inner[semis[1] + 1:]
    body = as_block(st.body)
    if step:
        body.stmts.append(Simple(_with_pre(step, ' ') + [Tok('op', ';', '')]))
    loop = Loop(Tok('id', 'while', ' ' if init else st.kw.pre), Tok('op', '(', ' '),
                _with_pre(cond, '') if cond else toks_of('true', ''), Tok('op', ')', ''), body)
    if init:
        b.stmts[i] = Block(Tok('op', '{', st.kw.pre), [Simple(_with_pre(init, ' ') + [Tok('op', ';', '')]), loop],
                           new('}'))
    else:
        b.stmts[i] = loop
    return True


INT_TYPES = ['std::int8_t', 'std::uint8_t', 'std::int16_t', 'std::uint16_t', 'std::int32_t', 'std::uint32_t',
             'std::int64_t', 'std::uint64_t']
SIGN_FLIP = {'int': 'unsigned int', 'unsigned int': 'int', 'unsigned': 'int', 'char': 'unsigned char',
             'unsigned char': 'char', 'short': 'unsigned short', 'unsigned short': 'short',
             'long': 'unsigned long', 'unsigned long': 'long', 'bool': 'std::uint8_t'}


def m_int_type(root, rng):
    """R4: signedness or width of a local's integral type; width of a switch operand (cookbook 6)."""
    sites = []
    for n in walk_nodes(root):
        d = decl_info(n) if isinstance(n, Simple) else None
        if d:
            tt = [t.text for t in d[0] if t.text not in ('const', 'volatile', 'static')]
            text = ''.join(tt) if '::' in tt else ' '.join(tt)
            if text in INT_TYPES or text in SIGN_FLIP:
                sites.append(('decl', n, d, text))
        if isinstance(n, Loop) and n.kind == 'switch':
            sites.append(('switch', n, None, None))
    if not sites:
        return False
    how, n, d, text = rng.choice(sites)
    if how == 'switch':
        inner = n.inner
        if inner and inner[0].text == 'static_cast':
            close = top_level(inner, '>')
            lp = close + 1 if close is not None else None
            if lp is not None and lp < len(inner) and inner[lp].text == '(' and _balanced(inner, lp) == len(inner):
                n.inner[:] = _with_pre(inner[lp + 1:-1], '')
                return True
            return False
        t = rng.choice(['std::uint32_t', 'std::int32_t', 'std::uint8_t'])
        n.inner[:] = toks_of(f'static_cast<{t}>(', '') + _with_pre(inner, '') + [Tok('op', ')', '')]
        return True
    if text in INT_TYPES and rng.random() < 0.5:
        k = INT_TYPES.index(text)
        repl = INT_TYPES[k ^ 1]
    elif text in INT_TYPES:
        repl = rng.choice([t for t in INT_TYPES if t != text])
    else:
        repl = SIGN_FLIP[text]
    start = next(i for i, t in enumerate(n.t) if t.text not in ('const', 'volatile', 'static'))
    end = len(d[0])
    while end > start and n.t[end - 1].text in ('const', 'volatile'):
        end -= 1
    n.t[start:end] = toks_of(repl, n.t[start].pre)
    return True


def m_compare(root, rng):
    """R7: `a < b` -> `b > a`, `a == b` -> `b == a` (compare direction and operand order)."""
    sites = expr_sites(root, set(FLIP))
    if not sites:
        return False
    lst, (s, k, e) = rng.choice(sites)
    swap_operands(lst, s, k, e, FLIP[lst[k].text])
    return True


def m_commute(root, rng):
    """R7: operand order of a commutative arithmetic or bitwise operator; of `&&`/`||` when pure."""
    sites = expr_sites(root, COMMUTE - {'==', '!='}) + expr_sites(root, {'&&', '||'}, pure=True)
    if not sites:
        return False
    lst, (s, k, e) = rng.choice(sites)
    swap_operands(lst, s, k, e, lst[k].text)
    return True


def m_test_form(root, rng):
    """R5/R7: `!x` <-> `x == 0`, `x` <-> `x != 0` as a whole condition; `nullptr` <-> `0` in tests."""
    sites = []
    for n in walk_nodes(root):
        if isinstance(n, If) or isinstance(n, Loop) and n.kind == 'while':
            c = n.cond if isinstance(n, If) else n.inner
            if c and c[0].text == '!' and atom_end(c, 1) == len(c):
                sites.append(('not-eq', c))
            elif c and atom_end(c, 0) == len(c):
                sites.append(('ne', c))
            elif len(c) >= 3 and c[-2].text in ('==', '!=') and c[-1].text in ('0', 'nullptr') \
                    and atom_end(c, 0) == len(c) - 2:
                sites.append(('drop', c))
    for lst in expr_lists(root):
        for i, t in enumerate(lst):
            if t.text in ('nullptr', '0') and i and lst[i - 1].text in ('==', '!='):
                sites.append(('null', lst, i))
    if not sites:
        return False
    site = rng.choice(sites)
    how, c = site[0], site[1]
    if how == 'not-eq':
        c[:] = _with_pre(c[1:], c[0].pre) + [Tok('op', '==', ' '), Tok('num', '0', ' ')]
    elif how == 'ne':
        c[:] = c + [Tok('op', '!=', ' '), Tok('num', '0', ' ')]
    elif how == 'drop':
        body = c[:-2]
        c[:] = ([Tok('op', '!', c[0].pre)] + _with_pre(body, '')) if c[-2].text == '==' else body
    else:
        i = site[2]
        c[i] = Tok('num' if c[i].text == 'nullptr' else 'id', '0' if c[i].text == 'nullptr' else 'nullptr', c[i].pre)
    return True


def m_increment(root, rng):
    """Increment forms as a statement or loop step: `++i`, `i++`, `i += 1`, `i = i + 1`."""
    sites = []
    for n in walk_nodes(root):
        if isinstance(n, Simple) and len(n.t) in (3, 4, 6):
            sites.append(n.t)
        if isinstance(n, Loop) and n.kind == 'for':
            semi = [j for j, t in enumerate(n.inner) if t.text == ';']
            if len(semi) == 2:
                sites.append(('step', n, semi[1]))
    cands = []
    for s in sites:
        if isinstance(s, tuple):
            _, n, j = s
            step = n.inner[j + 1:]
            name = _incr_name(step)
            if name:
                cands.append((n.inner, j + 1, len(n.inner), name, False))
        else:
            name = _incr_name(s[:-1])
            if name:
                cands.append((s, 0, len(s) - 1, name, True))
    if not cands:
        return False
    lst, a, b, (name, op), stmt = rng.choice(cands)
    forms = [f'++{name}', f'{name}++', f'{name} {op}= 1', f'{name} = {name} {op} 1']
    if op == '-':
        forms[0], forms[1] = f'--{name}', f'{name}--'
    current = ''.join(t.text for t in lst[a:b])
    choices = [f for f in forms if f.replace(' ', '') != current]
    lst[a:b] = toks_of(rng.choice(choices), lst[a].pre)
    return True


def _incr_name(toks):
    txt = [t.text for t in toks]
    if len(txt) == 2 and txt[0] in ('++', '--') and toks[1].kind == 'id':
        return txt[1], txt[0][0]
    if len(txt) == 2 and txt[1] in ('++', '--') and toks[0].kind == 'id':
        return txt[0], txt[1][0]
    if len(txt) == 3 and txt[1] in ('+=', '-=') and txt[2] == '1' and toks[0].kind == 'id':
        return txt[0], txt[1][0]
    if len(txt) == 5 and txt[1] == '=' and txt[2] == txt[0] and txt[3] in ('+', '-') and txt[4] == '1' \
            and toks[0].kind == 'id':
        return txt[0], txt[3]
    return None


def m_out_init(root, rng):
    """Cookbook 9: a local whose address is passed out keeps or drops its zero initialiser."""
    sites = []
    body = root.toks()
    for b in walk_blocks(root):
        for i, st in enumerate(b.stmts):
            d = decl_info(st)
            if not d:
                continue
            taken = any(body[j - 1].text == '&' and (j < 2 or body[j - 2].text in ('(', ',', '='))
                        for j in uses(body, d[1]))
            if not taken:
                continue
            init = [t.text for t in st.t[d[2] + 1:-1]] if d[2] is not None else None
            if init in (['nullptr'], ['0'], ['{', '}']):
                sites.append(('drop', st, d))
            elif init is None:
                sites.append(('add', st, d))
    if not sites:
        return False
    how, st, d = rng.choice(sites)
    if how == 'drop':
        st.t[d[2]:-1] = []
    else:
        pointer = any(t.text == '*' for t in d[0])
        st.t[-1:-1] = [Tok('op', '=', ' '), new('nullptr' if pointer else '0')]
    return True


ZERO_LITERAL = re.compile(r'0+(?:\.0*)?[fF]?|\.0+[fF]?|0[uUlL]*')


def _zero_vars(root):
    """{name: literal token} of locals declared as `T x = <zero literal>;` and never written."""
    out, own = {}, {}
    for n in walk_nodes(root):
        d = decl_info(n)
        if d and d[2] is not None and len(n.t) - d[2] == 3 and ZERO_LITERAL.fullmatch(n.t[d[2] + 1].text) \
                and n.t[d[2] + 1].kind == 'num':
            out[d[1]] = n.t[d[2] + 1]
            own[d[1]] = n.t
    return {k: v for k, v in out.items()
            if not any(written(lst, k) for lst in expr_lists(root) if lst is not own[k])}


def m_zero_form(root, rng):
    """How a zero is materialised: a named zero local read at the use, the literal at the use, or a
    new zero local standing for one literal."""
    sites = []
    zeros = _zero_vars(root)
    lists = expr_lists(root)
    for name, lit in zeros.items():
        for lst in lists:
            for i in uses(lst, name):
                if not (i and lst[i - 1].text in ('.', '->')):
                    sites.append(('inline', lst, i, lit))
    for lst in lists:
        decl_of = decl_info(Simple(lst)) if lst and lst[-1].text == ';' else None
        for i, tok in enumerate(lst):
            if tok.kind != 'num' or not ZERO_LITERAL.fullmatch(tok.text):
                continue
            if decl_of and decl_of[1] in zeros and decl_of[2] is not None and i == decl_of[2] + 1:
                continue  # the zero local's own initialiser
            for name in zeros:
                sites.append(('name', lst, i, name))
            if not zeros:
                sites.append(('intro', lst, i, None))
    if not sites:
        return False
    how, lst, i, what = rng.choice(sites)
    if how == 'inline':
        lst[i] = Tok('num', what.text, lst[i].pre)
    elif how == 'name':
        lst[i] = Tok('id', what, lst[i].pre)
    else:
        taken = {x.text for x in root.toks() if x.kind == 'id'}
        name = 'zero_'
        while name in taken:
            name += '_'
        text = lst[i].text
        ctype = 'float' if text[-1] in 'fF' else 'double' if '.' in text else 'int'
        lst[i] = Tok('id', name, lst[i].pre)
        first = root.stmts[0]
        pre = first.toks()[0].pre if first.toks() else '\n    '
        root.stmts.insert(0, Simple(toks_of(f'const {ctype} {name} = {text};', pre)))
    return True


def m_return_through(root, rng):
    """cookbook 2: a switch arm `x = e; break;` returns `e` at once instead of going through the code after the switch."""
    sites = []
    for n in walk_nodes(root):
        if not (isinstance(n, Loop) and n.kind == 'switch'):
            continue
        stmts = n.body.stmts
        for i in range(len(stmts) - 1):
            a, b = stmts[i], stmts[i + 1]
            if isinstance(a, Simple) and isinstance(b, Simple) and len(a.t) > 3 and a.t[0].kind == 'id' \
                    and a.t[0].text not in KEYWORDS and a.t[1].text == '=' and [x.text for x in b.t] == ['break', ';']:
                sites.append((stmts, i))
    if not sites:
        return False
    stmts, i = rng.choice(sites)
    a = stmts[i]
    expr = [copy.copy(x) for x in a.t[2:-1]]
    stmts[i:i + 2] = [Simple([Tok('id', 'return', a.t[0].pre)] + expr + [a.t[-1]])]
    return True


MUTATIONS = {
    'out-init': (m_out_init, 'cookbook 9', 1),
    'decl-swap': (m_decl_swap, 'R1', 3),
    'decl-move': (m_decl_move, 'R1', 2),
    'decl-split': (m_decl_split, 'R2, cookbook 9', 2),
    'temp-inline': (m_temp_inline, 'R3, cookbook 1', 3),
    'temp-introduce': (m_temp_introduce, 'R3, cookbook 1', 2),
    'if-invert': (m_if_invert, 'R5, cookbook 2', 3),
    'early-return': (m_early_return, 'R5, cookbook 2', 3),
    'and-split': (m_and_split, 'R5', 2),
    'loop-form': (m_loop_form, 'R6', 2),
    'int-type': (m_int_type, 'R4, cookbook 6', 2),
    'compare': (m_compare, 'R7', 3),
    'commute': (m_commute, 'R7', 2),
    'test-form': (m_test_form, 'R5/R7', 2),
    'increment': (m_increment, 'increment forms', 1),
    'zero-form': (m_zero_form, 'zero materialisation', 2),
    'return-through': (m_return_through, 'cookbook 2', 2),
}


def mutate(root, rng, steps=1, names=None):
    """Apply `steps` random applicable mutations in place; returns the names applied."""
    pool = [n for n in (names or MUTATIONS)]
    weights = [MUTATIONS[n][2] for n in pool]
    applied = []
    tries = 0
    while len(applied) < steps and tries < steps * 12:
        tries += 1
        name = rng.choices(pool, weights)[0]
        if MUTATIONS[name][0](root, rng):
            applied.append(name)
    return applied


# --------------------------------------------------------------------------------------------
# Unit text, lint gate and seen sets.

class Unit:
    """The compiled file split around the mutated bodies: the target's first, then `also` helpers.

    Candidates differ only in those bodies. A Block or a str stands for the target body alone;
    a list holds one entry per body.
    """

    def __init__(self, text, qualified, also=()):
        self.text = text
        self.spans, self.blocks, self.tails = [], [], []
        for name in (qualified, *also):
            start, end = find_body(text, name)
            if any(start < e and s < end for s, e in self.spans):
                raise ValueError(f'{name}: body overlaps another mutated body')
            block, tail = parse_body(text[start:end])
            if emit(block, tail) != text[start:end]:
                raise ValueError(f'{name}: body does not round-trip through the tokenizer')
            self.spans.append((start, end))
            self.blocks.append(block)
            self.tails.append(tail)
        self.start, self.end = self.spans[0]
        self.block, self.tail = self.blocks[0], self.tails[0]

    def forest(self):
        return list(self.blocks)

    def body_of(self, tree):
        if isinstance(tree, Block):
            return emit(tree, self.tail)
        return [emit(b, t) for b, t in zip(tree, self.tails)]

    def with_body(self, body):
        bodies = [body] if isinstance(body, str) else body
        return splice(self.text, self.spans[:len(bodies)], bodies)


def splice(text, spans, bodies):
    """`text` with each span replaced by its body (spans do not overlap)."""
    for (s, e), body in sorted(zip(spans, bodies), key=lambda x: -x[0][0]):
        text = text[:s] + body + text[e:]
    return text


def mutate_forest(forest, rng, steps):
    """Like mutate, over several bodies; a helper's mutation is named `<rule>@<body index>`."""
    applied, tries = [], 0
    while len(applied) < steps and tries < steps * 12:
        tries += 1
        i = rng.randrange(len(forest))
        done = mutate(forest[i], rng, 1)
        applied += [f'{n}@{i}' if i else n for n in done]
    return applied


def lint_gate(lint_root, compiled, build_id):
    """A function text -> [problems] running tools/lint_reconstruction.py on the candidate file."""
    sys.path.insert(0, str(REPO / 'tools'))
    import lint_reconstruction

    def check(text):
        path = Path(lint_root) / compiled
        path.write_text(text)
        return lint_reconstruction.lint_file(lint_root, compiled, build_id)
    return check


def make_lint_root(dest, source_root, closure):
    """A private tree the lint can read: the unit's files plus links to builds/, findings/, reports/."""
    dest = Path(dest)
    shutil.rmtree(dest, ignore_errors=True)
    dest.mkdir(parents=True)
    for name in ('builds', 'findings', 'reports'):
        (dest / name).symlink_to(REPO / name)
    (dest / 'reconstruction').mkdir()
    (dest / 'reconstruction' / 'recipes').symlink_to(REPO / 'reconstruction' / 'recipes')
    for name in closure:
        if name.startswith('reconstruction/recipes/'):
            continue
        p = dest / name
        p.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(Path(source_root) / name, p)
    return dest


def score_key(row):
    """Order of candidates: distance first, then exact edits, then instruction-count difference."""
    if row.get('st') != 'ok':
        return (float('inf'),)
    return (row['d'], row.get('ex', 0), abs(row.get('n', 0) - row.get('nt', 0)))


# --------------------------------------------------------------------------------------------
# Search, independent of how candidates are scored (so tests can use a local scorer).

class Search:
    def __init__(self, unit, scorer, lint, rng, batch=16, patience=8, restart_after=3, budget=600.0,
                 log=print, clock=time.monotonic, max_steps=3, max_steps_cap=8, dry_limit=4, on_round=None):
        self.unit, self.scorer, self.lint, self.rng = unit, scorer, lint, rng
        # A round with few new sources or no new object code widens the search (`widen` extra stacked
        # mutations per candidate, up to max_steps_cap); `dry_limit` such rounds in a row at the cap
        # end the run as pool-exhausted instead of spending host time on near-empty batches.
        self.max_steps_cap, self.dry_limit, self.on_round = max_steps_cap, dry_limit, on_round
        self.widen = 0
        self.start = self.best = None
        self.rounds = 0
        self.batch, self.patience, self.restart_after, self.budget = batch, patience, restart_after, budget
        self.log, self.clock, self.max_steps = log, clock, max_steps
        self.seen_src, self.seen_obj, self.history = set(), {}, []
        self.lint_rejected = 0
        self.next_id = 0

    def _candidates(self, parents):
        out, guard = [], 0
        while len(out) < self.batch and guard < self.batch * 20:
            guard += 1
            parent = self.rng.choice(parents)
            tree = copy.deepcopy(parent['tree'])
            top = min(self.max_steps + self.widen, self.max_steps_cap)
            steps = 1 + min(top - 1, int(self.rng.expovariate(1.2 / (1 + self.widen / 2))))
            applied = mutate_forest(tree, self.rng, steps)
            if not applied:
                continue
            body = self.unit.body_of(tree)
            digest = hashlib.sha256(json.dumps(body).encode()).hexdigest()
            if digest in self.seen_src:
                continue
            self.seen_src.add(digest)
            problems = self.lint(self.unit.with_body(body))
            if problems:
                self.lint_rejected += 1
                continue
            self.next_id += 1
            out.append({'id': f'v{self.next_id:05d}', 'parent': parent['id'], 'muts': parent['muts'] + applied,
                        'tree': tree, 'body': body})
        return out

    def run(self):
        started = self.clock()
        base_tree = self.unit.forest()
        base_body = self.unit.body_of(base_tree)
        problems = self.lint(self.unit.with_body(base_body))
        if problems:
            return {'status': 'base-lint-failed', 'problems': problems}
        self.seen_src.add(hashlib.sha256(json.dumps(base_body).encode()).hexdigest())
        base = {'id': 'v00000', 'parent': None, 'muts': [], 'tree': base_tree, 'body': base_body}
        rows = self.scorer([base])
        base.update(rows[0])
        self._record(base)
        if base.get('st') != 'ok':
            return {'status': 'base-not-scored', 'base': _public(base)}
        start = best = current = base
        self.start = self.best = base
        self.seen_obj[base.get('h')] = score_key(base)
        stale_best = stale_current = rounds = dry = 0
        stop = 'patience'
        if self.on_round:
            self.on_round(self)
        while True:
            if score_key(best)[0] == 0:
                stop = 'distance-0'
                break
            if self.clock() - started >= self.budget:
                stop = 'budget'
                break
            if stale_best >= self.patience:
                stop = 'patience'
                break
            if stale_current >= self.restart_after:
                # Random restart: a few random steps away from the best, so the climb leaves a plateau.
                tree = copy.deepcopy(best['tree'])
                applied = mutate_forest(tree, self.rng, self.rng.randint(2, 5))
                # Unscored on purpose: the first new object of the next batch becomes the current point.
                current = {'id': best['id'] + '+r', 'muts': best['muts'] + applied, 'tree': tree, 'st': 'restart'}
                stale_current = 0
            cands = self._candidates([current] * 3 + [best])
            if not cands:
                stale_best += 1
                stale_current += 1
                rounds += 1
                self.rounds = rounds
                dry, stop_now = self._dry(dry, True)
                if stop_now:
                    stop = 'pool-exhausted'
                    break
                continue
            rows = self.scorer(cands)
            rounds += 1
            self.rounds = rounds
            new_best = new_current = None
            fresh_count = 0
            for c, r in zip(cands, rows):
                c.update(r)
                fresh = c.get('h') not in self.seen_obj
                c['new_object'] = fresh
                fresh_count += fresh and c.get('st') == 'ok'
                self._record(c)
                if c.get('st') != 'ok' or not fresh:
                    continue
                self.seen_obj[c['h']] = score_key(c)
                if new_current is None or score_key(c) < score_key(new_current):
                    new_current = c
            if new_current is not None and score_key(new_current) < score_key(best):
                new_best = new_current
            if new_best is not None:
                best = current = new_best
                stale_best = stale_current = 0
            elif new_current is not None and score_key(new_current) < score_key(current):
                current = new_current
                stale_best += 1
                stale_current = 0
            elif new_current is not None and score_key(new_current) == score_key(current) and self.rng.random() < 0.3:
                current = new_current  # sideways move on a plateau: same score, different object code
                stale_best += 1
                stale_current += 1
            else:
                stale_best += 1
                stale_current += 1
            self.best = best
            dry, stop_now = self._dry(dry, len(cands) < max(2, self.batch // 4) or fresh_count == 0)
            self.log(f'round {rounds}: {len(cands)} candidates, {fresh_count} new objects, best {_fmt(best)}, '
                     f'current {_fmt(current)}' + (f', widened +{self.widen}' if self.widen else ''))
            if self.on_round:
                self.on_round(self)
            if stop_now:
                stop = 'pool-exhausted'
                break
        return {'status': stop, 'start': start, 'best': best, 'rounds': rounds,
                'candidates': len(self.history), 'lint_rejected': self.lint_rejected,
                'unique_objects': len(self.seen_obj), 'seconds': round(self.clock() - started, 1)}

    def _dry(self, dry, thin):
        """(dry-round count, whether the pool is exhausted) after a round that was `thin` or not."""
        if not thin:
            return 0, False
        cap = self.max_steps_cap - self.max_steps
        if self.widen < cap:
            self.widen += 1
            return 0, False
        return dry + 1, dry + 1 >= self.dry_limit

    def _record(self, c):
        self.history.append(_public(c))


def _public(c):
    return {k: v for k, v in c.items() if k not in ('tree', 'body')}


def _fmt(c):
    return f'd={c.get("d")}' if c.get('st') == 'ok' else str(c.get('st'))


# --------------------------------------------------------------------------------------------
# Host side: compile only. The verifier hosts have no llvm-objdump (the Windows one has no
# Python packages either), so the host returns the objects and the caller disassembles and scores.

def write_cands(path, sources):
    """An xz tar of {candidate id: full unit source}; near-identical sources compress to almost nothing."""
    import io
    import tarfile
    with tarfile.open(path, 'w:xz') as tar:
        for cid, text in sorted(sources.items()):
            data = text.encode()
            info = tarfile.TarInfo(f'{cid}.cpp')
            info.size, info.mode, info.mtime = len(data), 0o644, int(time.time())
            tar.addfile(info, io.BytesIO(data))


def read_cands(path):
    import tarfile
    out = {}
    with tarfile.open(path) as tar:
        for member in tar.getmembers():
            m = re.fullmatch(r'(v\d{5})\.cpp', member.name)
            if not m or not member.isfile():
                raise ValueError(f'unexpected member {member.name!r} in the candidate archive')
            out[m.group(1)] = tar.extractfile(member).read().decode()
    return out


def compile_batch(run, sources, jobs, compile_one):
    """Compile each source in a worker's own copy of the run's repository; (rows, {id: object bytes}).

    `compile_one(workdir, compiled, cid)` returns (returncode, combined output, object path or None).
    A worker copy is made once per call and only the compiled file is rewritten, so the headers
    stay shared in content and the run's own copy is never touched.
    """
    import concurrent.futures
    import threading
    run = Path(run).resolve()
    repo = run / 'repo'
    compiled = json.loads((repo / '.unit' / 'spec.json').read_text())['compiled']
    perm = run / 'perm'
    perm.mkdir(exist_ok=True)
    free = list(range(jobs))
    lock = threading.Lock()
    objects = {}

    def worker_dir(k):
        w = perm / f'w{k}'
        if not (w / 'repo').is_dir():
            shutil.copytree(repo, w / 'repo', ignore=shutil.ignore_patterns('.unit', '.local'))
        return w

    def one(item):
        cid, text = item
        with lock:
            k = free.pop()
        t0 = time.monotonic()
        try:
            w = worker_dir(k)
            src = w / 'repo' / compiled
            src.write_text(text)
            rc, output, obj = compile_one(w, compiled, cid)
            if rc != 0 or obj is None or not Path(obj).is_file():
                # Error codes only in the row: compiler messages quote source text.
                codes = sorted(set(re.findall(r'\b(?:error|fatal error) ([A-Z]+\d+)', output)))
                return {'id': cid, 'st': 'compile-failed', 'codes': codes[:5], 'rc': rc,
                        't': round(time.monotonic() - t0, 2)}
            objects[cid] = Path(obj).read_bytes()
            Path(obj).unlink()
            return {'id': cid, 'st': 'compiled', 't': round(time.monotonic() - t0, 2)}
        except Exception as exc:  # noqa: BLE001 - one broken candidate must not lose the batch
            return {'id': cid, 'st': 'error', 'why': type(exc).__name__, 't': round(time.monotonic() - t0, 2)}
        finally:
            with lock:
                free.append(k)

    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        rows = list(pool.map(one, sorted(sources.items())))
    return rows, objects


def host_compiler(msvc, loader, flags):
    """compile_one for this host: the recipe's flags and the environment unit_build.py compiles with."""
    import subprocess
    sys.path.insert(0, str(HERE))
    import unit_build
    env = unit_build.clean_env(os.environ)
    env['VSLANG'] = '1033'
    msvc = Path(msvc).resolve()
    if loader == 'native':
        settings = unit_build.native_settings(msvc)
        env['INCLUDE'] = settings['INCLUDE']
        cl = str(Path(settings['BINDIR']) / 'cl.exe')
    else:
        cl = str(msvc / 'bin/x64/cl')

    def compile_one(worker, compiled, cid):
        obj = worker / f'{cid}.obj'
        proc = subprocess.run([cl] + flags + [f'/Fo{obj}', compiled], cwd=worker / 'repo', env=env,
                              capture_output=True, text=True, errors='replace', timeout=unit_build.COMPILE_TIMEOUT)
        return proc.returncode, proc.stdout + proc.stderr, obj
    return compile_one


def pc_batch(a):
    """`pc-batch`: compile an uploaded candidate archive and pack the objects and rows into one archive."""
    import io
    import tarfile
    run = Path(a.run).resolve()
    names = [a.cands, a.out]
    if not all(re.fullmatch(r'(cands|out)-\d{4}\.tar', n) for n in names):
        raise SystemExit('bad archive name')
    sources = read_cands(run / a.cands)
    (run / a.cands).unlink()
    spec = json.loads((run / 'repo' / '.unit' / 'spec.json').read_text())
    flags = json.loads((run / 'repo' / spec['recipe']).read_text())['flags']
    t0 = time.monotonic()
    rows, objects = compile_batch(run, sources, a.jobs, host_compiler(a.msvc, a.loader, flags))
    with tarfile.open(run / a.out, 'w:xz') as tar:
        blobs = {'rows.json': json.dumps({'rows': rows, 'wall': round(time.monotonic() - t0, 2)}).encode()}
        blobs.update({f'{cid}.obj': data for cid, data in objects.items()})
        for name, data in sorted(blobs.items()):
            info = tarfile.TarInfo(name)
            info.size, info.mode, info.mtime = len(data), 0o644, int(time.time())
            tar.addfile(info, io.BytesIO(data))
    return 0


def function_hash(listing):
    """Hash of the function's object code: instruction bytes and relocation symbols, in order."""
    import align
    h = hashlib.sha256()
    for addr, data, _text, relocs in align.parse_listing(listing):
        h.update(f'{addr:x}:{"".join(data)}:{";".join(f"{r[1]}={r[2]}" for r in relocs)}\n'.encode())
    return h.hexdigest()[:16]


# --------------------------------------------------------------------------------------------
# Caller side: score returned objects, and the scorer that drives a runner host.

_SCORING = {}


def scoring_init(ctx):
    import align
    _SCORING.update(ctx, symbols=align.load_symbols(ctx['symbols']))


def score_object(item):
    """The scoring row for one compiled object, using the context set by scoring_init."""
    import align
    cid, obj = item
    c = _SCORING
    t0 = time.monotonic()
    try:
        cand = align.objdump_candidate(c['objdump'], obj, c['symbol'])
        if not align.parse_listing(cand):
            return {'id': cid, 'st': 'no-symbol'}
        _text, data = align.summarise(c['listing'], cand, symbols=c['symbols'], image_base=c['base'],
                                      target_size=c['size'])
        comps = data['components']
        return {'id': cid, 'st': 'ok', 'd': data['distance'], 'p': comps['prologue'], 'b': comps['body'],
                'r': comps['refs'], 'es': data['edits']['shape'], 'ex': data['edits']['exact'],
                'n': data['candidate_instructions'], 'nt': c['nt'], 'h': function_hash(cand),
                't': round(time.monotonic() - t0, 2)}
    except Exception as exc:  # noqa: BLE001 - one broken candidate must not lose the batch
        return {'id': cid, 'st': 'error', 'why': type(exc).__name__}


def scoring_context(objdump, image, task, fn):
    import align
    listing, base = align.objdump_target(objdump, image, fn['rva'], fn['size'])
    n_target = len(align.build(align._as_rows(listing), size=fn['size'], base=base))
    return {'objdump': objdump, 'listing': listing, 'base': base, 'size': fn['size'], 'symbol': fn['symbol'],
            'symbols': str(task['symbols_local']), 'nt': n_target}


def retrying(call, timings, log, limit, recover=None, sleep=time.sleep, clock=time.monotonic):
    """call() again after a transport failure, backing off 5 s doubling to 120 s, for up to `limit` seconds.

    Before each retry `recover()` (if given) runs, since a host that went away may have lost the run
    directory; a failure in it counts as another failed attempt. The time spent failing is added to
    timings['outage_seconds'], which the search's clock leaves out of the budget.
    """
    import runners
    import subprocess
    errors = (runners.RunnerError, OSError, subprocess.SubprocessError)
    began, delay, down = clock(), 5, False
    while True:
        try:
            if down and recover:
                recover()
            result = call()
            if down:
                timings['outage_seconds'] = timings.get('outage_seconds', 0) + clock() - began
                log(f'host back after {clock() - began:.0f} s')
            return result
        except errors as exc:
            down = True
            waited = clock() - began
            if waited + delay > limit:
                timings['outage_seconds'] = timings.get('outage_seconds', 0) + waited
                raise
            log(f'host unreachable ({type(exc).__name__}); retrying in {delay} s (down {waited:.0f} s)')
            sleep(delay)
            delay = min(delay * 2, 120)


def runner_scorer(host, unit, jobs, score_all, timings, log, stage, outage=1800.0, recover=None):
    """Score a batch on a runner host (runners.AgentHost with a finished baseline run).

    One upload of the candidate sources, one agent command that compiles them `jobs` at a time
    and one download of the objects: three ssh operations per batch however many candidates.
    A dropped connection is retried with backoff (`retrying`), repeating the whole batch.
    """
    import runners
    import tarfile
    counter = [0]
    empty = [0]

    def exchange(tag, local):
        """Upload, compile and download one batch; (exit code, output, objects dir or None, timings)."""
        tr, remote = host.transport, host._remote(host._run)
        t0 = time.monotonic()
        tr.put([local], remote)
        t1 = time.monotonic()
        with runners.slots(host.host['host_id'], host.host['max_parallel'], jobs, log=log) as granted:
            t2 = time.monotonic()
            code, out, err = tr.run(
                host._python() + ['-I', tr.join(remote, 'repo/tools/verifier/permute.py'), 'pc-batch', '--run', remote,
                                  '--cands', f'cands-{tag}.tar', '--out', f'out-{tag}.tar', '--msvc',
                                  host.host['msvc'], '--loader', host.host['loader'], '--jobs', str(granted)], 600)
        t3 = time.monotonic()
        if code in (124, 255):
            raise runners.TransportError(f'batch {tag}: exit {code}')
        dest = None
        if code == 0:
            archive = Path(stage) / f'out-{tag}.tar'
            dest = Path(stage) / f'out-{tag}'
            try:
                tr.get(tr.join(remote, f'out-{tag}.tar'), archive)
                shutil.rmtree(dest, ignore_errors=True)
                runners.unpack(archive, dest)
            finally:
                archive.unlink(missing_ok=True)
        return code, out or err or '', dest, (t1 - t0, t2 - t1, t3 - t2)

    def score(cands):
        counter[0] += 1
        tag = f'{counter[0]:04d}'
        t0 = time.monotonic()
        local = Path(stage) / f'cands-{tag}.tar'
        write_cands(local, {c['id']: unit.with_body(c['body']) for c in cands})
        try:
            code, text, dest, (up, wait, comp) = retrying(lambda: exchange(tag, local), timings, log, outage, recover)
        finally:
            local.unlink(missing_ok=True)
        t3 = time.monotonic()
        by_id, scored = {}, {}
        if code == 0:
            try:
                objects = {}
                for row in json.loads((dest / 'rows.json').read_text())['rows']:
                    by_id[row['id']] = row
                    if row['st'] == 'compiled':
                        objects[row['id']] = dest / f'{row["id"]}.obj'
                scored = {r['id']: r for r in score_all(sorted(objects.items()))}
            except (OSError, ValueError, KeyError, tarfile.TarError) as exc:
                log(f'batch {tag}: results unreadable ({type(exc).__name__})')
            finally:
                shutil.rmtree(dest, ignore_errors=True)
        else:
            log(f'batch {tag}: agent exit {code} {text.strip()[-120:]}')
        empty[0] = 0 if scored or by_id else empty[0] + 1
        if empty[0] >= 3:
            raise runners.RunnerError(f'the host returned no results for {empty[0]} batches in a row')
        for key, value in (('upload_seconds', up), ('slot_wait_seconds', wait), ('compile_seconds', comp),
                           ('fetch_score_seconds', time.monotonic() - t3), ('execs', 1)):
            timings[key] = timings.get(key, 0) + value
        return [scored.get(c['id'], by_id.get(c['id'], {'id': c['id'], 'st': 'lost'})) for c in cands]
    return score


def run(args):
    sys.path.insert(0, str(HERE))
    import disasm
    import pipeline
    started = time.monotonic()
    task = pipeline.load_task(args.task_dir)
    rva = int(args.rva, 0)
    fn = next((f for f in task['functions'] if f['rva'] == rva), None)
    if fn is None:
        raise SystemExit(f'0x{rva:x} is not a function of the task')
    raw = json.loads((task['dir'] / 'task.json').read_text())
    entry = next(f for f in raw['functions'] if int(str(f['rva']), 0) == rva)
    qualified = args.function or entry.get('community_name')
    if not qualified:
        raise SystemExit('give --function Class::Name')
    source_root = Path(args.source_root).resolve() if args.source_root else REPO
    out = Path(args.out).resolve() if args.out else task['dir'] / 'permute' / f'0x{rva:x}'
    pipeline.private_root(out)
    out.mkdir(parents=True, exist_ok=True)
    compiled = task['compiled']
    unit = Unit((source_root / compiled).read_text(), qualified, args.also or ())
    from source_digest import include_closure
    closure = include_closure(source_root, compiled)
    files = {name: REPO / name for name in pipeline.TOOL_FILES + REMOTE_TOOLS}
    files.update({name: source_root / name for name in closure})
    files[task['recipe']] = REPO / task['recipe']
    files[task['symbols_repo'] or pipeline.PRIVATE_SYMBOLS] = task['symbols_local']
    lint = lint_gate(make_lint_root(out / 'lintroot', source_root, closure), compiled, task['build_id'])
    if args.dry_run:
        return dry_run(unit, lint, random.Random(args.seed), args.batch)
    import runners
    config = pipeline.load_config(task['dir'])
    runner = runners.for_attempt()
    if runner is None:
        raise SystemExit('no runner host: set "attempt" to a local or ssh host in .local/verifier/runners.json '
                         '(or SR_RUNNERS_CONFIG)')
    objdump = disasm.find_objdump(config.get('objdump'))
    image = config.get('image')
    if objdump is None or not image or not Path(image).is_file():
        raise SystemExit('scoring runs here and needs llvm-objdump and the local image (.local/verifier/config.json)')
    log = print
    # The baseline is a real unit_build run of the unchanged unit on the host: it checks the
    # toolchain and image hashes and leaves the run directory the candidate batches compile in.
    host = runners.AgentHost(runner, task, label='permute', log=lambda m: print(m, file=sys.stderr))
    jobs = args.jobs or runner['max_parallel']
    log(f'permute {task["task_id"]} 0x{rva:x} {qualified}: {runners.describe(runner)}, {jobs} jobs')
    stage = out / '.stage'
    stage.mkdir(exist_ok=True)
    t0 = time.monotonic()
    code, text = host.run(files, stage)
    timings = {'baseline_seconds': round(time.monotonic() - t0, 1)}
    if code not in (0, 1):
        log(f'baseline unit_build exit {code}: ' + ' | '.join(text.splitlines()[-3:]))
        host.clean()
        return 2
    import concurrent.futures
    ctx = scoring_context(objdump, image, task, fn)
    pool = concurrent.futures.ProcessPoolExecutor(min(os.cpu_count() or 2, 8), initializer=scoring_init,
                                                  initargs=(ctx,))

    def score_all(items):
        return list(pool.map(score_object, items)) if items else []

    def recover():
        """After an outage the host may have lost its run directory: start it again from the unit."""
        host.clean()
        code, _text = host.run(files, stage)
        if code not in (0, 1):
            raise runners.RunnerError(f'baseline after the outage: unit_build exit {code}')
    scorer = runner_scorer(host, unit, jobs, score_all, timings, log, stage, outage=args.outage, recover=recover)
    summary = {'task': task['task_id'], 'rva': f'0x{rva:x}', 'function': qualified, 'status': 'running',
               'seed': args.seed, 'batch': args.batch, 'jobs': jobs, 'host': runner['host_id']}
    written = [0]
    history = out / 'history.jsonl'
    history.write_text('')

    def flush(s):
        """After every round: new history rows, the best body so far and a partial result.json, so a
        run that dies still leaves what it found."""
        with open(history, 'a') as f:
            for row in s.history[written[0]:]:
                f.write(json.dumps(row) + '\n')
        written[0] = len(s.history)
        part = dict(summary, rounds=s.rounds, candidates=len(s.history), widen=s.widen,
                    unique_objects=len(s.seen_obj), timings={k: round(v, 1) for k, v in timings.items()})
        if s.best is not None:
            (out / 'best.cpp').write_text(unit.with_body(s.best['body']))
            part.update(start_distance=s.start.get('d'), best_distance=s.best.get('d'),
                        best_id=s.best['id'], best_mutations=s.best['muts'])
        (out / 'result.json').write_text(json.dumps(part, indent=1) + '\n')
    search = Search(unit, scorer, lint, random.Random(args.seed), batch=args.batch, patience=args.patience,
                    restart_after=args.restart_after, budget=args.budget, log=log, max_steps=args.max_steps,
                    on_round=flush,
                    clock=lambda: time.monotonic() - timings.get('outage_seconds', 0))
    try:
        result = search.run()
    except BaseException as exc:
        # Keep what was found, leave no listings or objects on the host and keep the cost record.
        summary['status'] = f'aborted: {type(exc).__name__}'
        flush(search)
        try:
            host.clean()
        except Exception:  # noqa: BLE001 - the host may be the thing that failed
            pass
        pool.shutdown(cancel_futures=True)
        pipeline.record_cost(task, 'draft', time.monotonic() - started, time.monotonic() - started)
        raise
    pool.shutdown()
    host.clean()
    summary['status'] = result['status']
    flush(search)
    final = None
    if 'best' in result:
        best = result['best']
        (out / 'best.cpp').write_text(unit.with_body(best['body']))
        summary.update({'start_distance': result['start'].get('d'), 'best_distance': best.get('d'),
                        'best_id': best['id'], 'best_mutations': best['muts'], 'rounds': result['rounds'],
                        'candidates': result['candidates'], 'lint_rejected': result['lint_rejected'],
                        'unique_objects': result['unique_objects'],
                        'compile_failed': sum(1 for r in search.history if r.get('st') != 'ok')})
        if best.get('d') == 0 and best['id'] != 'v00000':
            final = verify_final(host, files, compiled, out, unit.with_body(best['body']), rva, stage)
            summary['comparator'] = final
    else:
        summary.update({k: v for k, v in result.items() if k != 'status'})
    wall = time.monotonic() - started
    timings['wall_seconds'] = round(wall, 1)
    n = summary.get('candidates') or 0
    summary['timings'] = {k: round(v, 1) if isinstance(v, float) else v for k, v in timings.items()}
    summary['candidates_per_minute'] = round(n / (wall / 60), 1) if wall else None
    (out / 'result.json').write_text(json.dumps(summary, indent=1) + '\n')
    pipeline.record_cost(task, 'draft', wall, wall)
    log(f'result: {summary["status"]}; start d={summary.get("start_distance")} best d={summary.get("best_distance")} '
        f'({summary.get("best_mutations")}); {n} candidates in {wall:.0f} s '
        f'({summary["candidates_per_minute"]}/min); comparator {final}')
    log(f'private: {out}/ (best.cpp, history.jsonl, result.json)')
    return 0 if final == 'pass' else 1


def dry_run(unit, lint, rng, batch):
    """Local check before any host time: the base lints and the mutations find sites in this body."""
    problems = lint(unit.with_body(unit.body_of(unit.forest())))
    print(f'base lint: {"PASS" if not problems else "FAIL"}' + ''.join(f'\n  {p}' for p in problems))
    sites = {}
    for name, (fn, _tag, _w) in MUTATIONS.items():
        hits = sum(fn(copy.deepcopy(b), random.Random(i)) for i in range(5) for b in unit.blocks)
        sites[name] = hits
    print('mutations with a site: ' + ', '.join(n for n, h in sites.items() if h) or 'none')
    search = Search(unit, lambda cands: [], lint, rng, batch=batch, log=lambda m: None)
    cands = search._candidates([{'id': 'v00000', 'muts': [], 'tree': unit.forest()}])
    print(f'one batch: {len(cands)} candidates, {search.lint_rejected} refused by lint')
    return 0 if not problems else 1


def verify_final(host, files, compiled, out, text, rva, stage):
    """Compile the winning unit with unit_build.py and return the comparator's result for the target."""
    path = out / 'final-src' / compiled
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    files = dict(files, **{compiled: path})
    code, _ = host.run(files, stage)
    dest = host.fetch(out / 'final')
    try:
        rep = json.loads((dest / f'0x{rva:x}' / 'report.json').read_text())
    except (OSError, ValueError):
        rep = {}
    # Other functions of the unit may be near-misses of their own; the verdict here is the target's.
    return 'pass' if code in (0, 1) and rep.get('result') == 'pass' else \
        f'{rep.get("result", "error")} {rep.get("reason")} (unit_build exit {code})'


def mutate_cmd(args):
    text = Path(args.file).read_text()
    unit = Unit(text, args.function)
    rng = random.Random(args.seed)
    tree = copy.deepcopy(unit.block)
    applied = mutate(tree, rng, args.steps)
    sys.stdout.write(unit.with_body(unit.body_of(tree)))
    print(f'mutations: {", ".join(applied)}', file=sys.stderr)
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)
    r = sub.add_parser('run', help='search for one function of a task')
    r.add_argument('task_dir')
    r.add_argument('--rva', required=True)
    r.add_argument('--function', help='qualified name of the definition to mutate (default: community name)')
    r.add_argument('--also', action='append', metavar='Class::Helper',
                   help='also mutate this definition in the same file (repeatable), e.g. an inline helper')
    r.add_argument('--source-root', help='checkout-shaped tree holding reconstruction/ (default: this checkout)')
    r.add_argument('--out', help='private output directory (default: <task-dir>/permute/0x<rva>)')
    r.add_argument('--budget', type=float, default=600.0, help='seconds of wall time (default 600 = 10 min)')
    r.add_argument('--batch', type=int, default=16)
    r.add_argument('--jobs', type=int, help='compiles at once on the host (default: its max_parallel)')
    r.add_argument('--patience', type=int, default=8, help='batches without a new best before stopping')
    r.add_argument('--restart-after', type=int, default=3, help='batches without progress before a restart')
    r.add_argument('--max-steps', type=int, default=3, help='most mutations stacked in one candidate')
    r.add_argument('--seed', type=int, default=1)
    r.add_argument('--outage', type=float, default=1800.0,
                   help='seconds to keep retrying an unreachable host (backoff 5 to 120 s) before giving up; '
                        'not counted against --budget')
    r.add_argument('--dry-run', action='store_true', help='lint the base and one batch locally; no host time')
    m = sub.add_parser('mutate', help='print a mutated copy of a file (tests, recovery self-tests)')
    m.add_argument('file')
    m.add_argument('--function', required=True)
    m.add_argument('--steps', type=int, default=3)
    m.add_argument('--seed', type=int, default=1)
    pb = sub.add_parser('pc-batch', help=argparse.SUPPRESS)
    pb.add_argument('--run', required=True)
    pb.add_argument('--cands', required=True)
    pb.add_argument('--out', required=True)
    pb.add_argument('--msvc', required=True)
    pb.add_argument('--loader', choices=('wine', 'native'), required=True)
    pb.add_argument('--jobs', type=int, required=True)
    a = p.parse_args(argv)
    if a.cmd == 'pc-batch':
        return pc_batch(a)
    if a.cmd == 'mutate':
        return mutate_cmd(a)
    return run(a)


if __name__ == '__main__':
    raise SystemExit(main())
