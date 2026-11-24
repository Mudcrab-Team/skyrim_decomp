#!/usr/bin/env python3
"""Scripted transplant of a sibling-decompilation function into a Skyrim unit.

A sibling function that compiles as x64 to the same code as an unmatched Skyrim function is
cut out of the sibling clone together with the declarations that precede it, renamed to the
Skyrim owner where a name is known, written as a unit with the labels the drafter card asks
for, and handed to the normal attempt loop. Nothing is matched here: only the comparator
report from `tools/verifier/attempt` counts.

All inputs are private and stay under `.local/`: the sibling clone, the x64 build listings of
the sibling units (used only to find the source line of a function) and the Skyrim target
facts. The tool never reads image bytes.

    sibling_transplant.py plan  --scores S.json --listings DIR [DIR..] --build-results B.json --out PLAN.json
    sibling_transplant.py write PLAN.json 0x<rva> [--task-only]
    sibling_transplant.py plan ... --rvas NEAR.json     (plan near pairs that are not identical after masking)
    sibling_transplant.py run PLAN.json 0x<rva>.. --layouts FACTS.json   (stand-in layout for member-offset / vtable-slot pairs)
"""
import argparse
import json
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GAMES = {'f3': ('momusdigital/f3_decomp@f5bac1b5', 'CC0-1.0', '.local/sources/f3_decomp'),
         'fnv': ('momusdigital/fnv_decomp@2b07cb3e', 'CC0-1.0', '.local/sources/fnv_decomp')}
SIBLING_REV, _LICENCE, _DIR = GAMES[__import__('os').environ.get('SIBLING_GAME', 'f3')]
SIBLING_LABEL = f'SIBLING({SIBLING_REV}, {_LICENCE})'
SIBLING_DIR = ROOT / _DIR
# Private build data lives in the main checkout's .local, which a worktree does not carry.
MAIN = Path(__import__('subprocess').run(['git', 'rev-parse', '--path-format=absolute', '--git-common-dir'], cwd=ROOT,
                                         capture_output=True, text=True).stdout.strip()).parent
CRASHLOGGER = 'CRASHLOGGER_PDB(59818@2026.10.24)'
IDENT = r'[A-Za-z_]\w*'
# Names that the intake lint refuses outright; the sibling's decompiler-style names are renamed.
RENAMES = [(re.compile(r'\bFUN_([0-9a-fA-F]{6,8})'), r'Func\1'), (re.compile(r'\bDAT_([0-9a-fA-F]{6,8})'), r'Data\1'),
           (re.compile(r'\bsub_([0-9a-fA-F]{6,8})'), r'Routine\1'), (re.compile(r'\bparam_(\d+)\b'), r'arg\1'),
           (re.compile(r'\blocal_([0-9a-fA-F]+)\b'), r'temp\1'),
           (re.compile(r'\b([iupcbl])Var(\d+)\b'), r'\1Value\2')]
CALLCONV = re.compile(r'\b__(?:fastcall|stdcall|cdecl|thiscall)\b\s*')
DELETING = {'dtor_deleting', 'scalar_deleting_destructor', '`scalar_deleting_destructor\''}


# The siblings are 32-bit builds: allocation operators take an unsigned int size there.
OPERATOR_SIZE = re.compile(r'operator\s+(new|new\[\])\s*\(\s*unsigned(?:\s+int)?\b')
LIBC_NAMES = re.compile(r'\b(?:memcpy|memmove|memset|memcmp|strlen|strcmp|strcpy|strncpy|strncmp|strcat)\b')


def sanitize(text):
    for rx, rep in RENAMES:
        text = rx.sub(rep, text)
    text = OPERATOR_SIZE.sub(r'operator \1(size_t', text)
    text = re.sub(r'\b__forceinline\b', 'inline', text)
    text = re.sub(r'__declspec\(\s*noinline\s*\)\s*', '', text)
    return CALLCONV.sub('', text)


def decorated_parts(sym):
    """Class name from an MSVC-decorated sibling symbol, best effort."""
    m = re.match(r'\?\??(?:_G|_E|1|0)?([A-Za-z_]\w*)@', sym)
    return m.group(1) if m else None


def locate(listings, stem, sym):
    """(first source line number, [first listed source lines], source file) of `sym` in the
    sibling unit's x64 listing, or (None, [], None)."""
    for d in listings:
        p = Path(d) / f'{stem}.asm'
        if not p.exists():
            continue
        lines = p.read_text(errors='replace').splitlines()
        want = sym + ' PROC'
        for i, l in enumerate(lines):
            if l.startswith(want):
                first, texts, fname = None, [], None
                for back in range(i, max(i - 80, 0), -1):
                    if lines[back].startswith('; File '):
                        fname = lines[back][7:].strip()
                        break
                    if lines[back].endswith(' ENDP') and back != i:
                        break
                for l2 in lines[i + 1:i + 60]:
                    m = re.match(r'; (\d+)\s+:(.*)$', l2)
                    if m:
                        first = first or int(m.group(1))
                        s = m.group(2).strip()
                        if s and (not texts or texts[-1] != s):
                            texts.append(s)
                        if len(texts) == 3:
                            break
                return first, texts, fname
        return None, [], None
    return None, [], None


def clone_path(entry):
    """Clone-relative path of the file the function was compiled from (the unit, or a header it includes)."""
    f = (entry.get('file') or '').replace('\\', '/')
    m = re.search(r'/shadow/((?:src|include)/.+)$', f)
    if m:
        return m.group(1)
    return entry['source'] if not f else None


def resolve_line(lines, hint, texts):
    """1-based line in `lines` where the listed source text starts; the listing was made from a
    shadow copy whose line numbers may differ from the clone's, so the text decides."""
    norm = [' '.join(l.split()) for l in lines]
    want = [' '.join(x.split()) for x in texts[:2]]
    if not want:
        return hint
    hits = []
    for n in range(len(want), 0, -1):
        hits = [i + 1 for i in range(len(norm) - n + 1) if norm[i:i + n] == want[:n]]
        if hits:
            break
    if not hits:
        return None
    return min(hits, key=lambda h: abs(h - (hint or h)))


def match_brace(lines, start):
    depth, seen = 0, False
    for i in range(start, len(lines)):
        for ch in re.sub(r'//.*|"(?:\\.|[^"\\])*"', '', lines[i]):
            if ch == '{':
                depth += 1
                seen = True
            elif ch == '}':
                depth -= 1
        if seen and depth == 0:
            return i
    return None


def enclosing_namespaces(lines, upto):
    """Names of the namespaces that are open at line index `upto`."""
    stack, depth = [], 0
    for line in lines[:upto]:
        s = re.sub(r'//.*|"(?:\\.|[^"\\])*"', '', line)
        head = re.match(r'\s*namespace\s+([\w:]+)\s*\{', s)
        for k, ch in enumerate(s):
            if ch == '{':
                depth += 1
                if head and k == s.index('{'):
                    stack.append((head.group(1), depth))
            elif ch == '}':
                if stack and stack[-1][1] == depth:
                    stack.pop()
                depth -= 1
    return [n for n, _ in stack]


NAMESPACE_LINE = re.compile(r'\s*namespace\s+[\w:]*\s*\{.*$|\}\s*//\s*(?:end\s+)?namespace.*$')


def wrap_namespaces(text, names):
    for n in reversed(names):
        text = f'namespace {n} {{\n{text}\n}}'
    return text


def excerpt(lines, brace_line):
    """(preamble lines, function lines, first function line index) around the 1-based brace line."""
    b = brace_line - 1
    sig = b
    while sig > 0:
        prev = lines[sig - 1].strip()
        if not prev or prev.startswith('//') or prev.endswith((';', '}', '{', ':')) or prev.startswith('#'):
            break
        sig -= 1
    end = match_brace(lines, b)
    if end is None:
        return None
    pre_start = 0
    for i in range(sig - 1, -1, -1):
        if re.fullmatch(r'\}\s*(?://.*)?', lines[i]):
            pre_start = i + 1
            break
    pre = [l for l in lines[pre_start:sig] if not l.lstrip().startswith(('//', '#include'))]
    return pre, lines[sig:end + 1], sig


def include_files(rel, depth=3, seen=None):
    """[(path, lines)] of a sibling file and the quoted headers it includes, so class definitions
    that live in the unit's own declaration headers can be found."""
    seen = seen if seen is not None else set()
    path = SIBLING_DIR / rel
    if rel in seen or not path.exists():
        return []
    seen.add(rel)
    lines = path.read_text(errors='replace').splitlines()
    out = [(rel, lines)]
    if depth:
        for l in lines:
            m = re.match(r'\s*#\s*include\s+"([^"]+)"', l)
            if not m:
                continue
            for base in (str(Path(rel).parent), 'include', 'src'):
                cand = (Path(base) / m.group(1)).as_posix()
                if (SIBLING_DIR / cand).exists():
                    out += include_files(cand, depth - 1, seen)
                    break
    return out


def include_context(rel):
    return [l for _, lines in include_files(rel) for l in lines]


def class_origin(rel, name):
    """(file, 1-based line) of the first definition of class `name` in the file or its headers."""
    for f, lines in include_files(rel):
        for i, l in enumerate(lines):
            if re.match(rf'(?:class|struct)\s+{re.escape(name)}\b(?!\s*;)', l):
                return f, i + 1
    return rel, 1


def class_text(lines, name):
    for i, l in enumerate(lines):
        if re.match(rf'(?:class|struct)\s+{re.escape(name)}\b(?!\s*;)', l):
            end = match_brace(lines, i)
            if end is not None:
                closed = re.search(r'\}\s*[\w\s,*]*;\s*$', lines[end])
                return lines[i:end + 1] if closed else lines[i:end + 2]
    return None


def source_line_of(sig_text, original_lines):
    first = sig_text.strip()
    for i, l in enumerate(original_lines):
        if l.strip() == first:
            return i + 1
    return None


def skyrim_name(fact):
    """(class, method) when the committed name is a plain Class::Method, else (None, None)."""
    n = (fact or {}).get('name') or ''
    m = re.fullmatch(rf'({IDENT})::(~?{IDENT}|`scalar_deleting_destructor\')', n)
    if m and not m.group(1).startswith('FID'):
        return m.group(1), m.group(2)
    return None, None


def definition_line(lines, sym):
    """1-based line of the opening brace of the definition of an MSVC-decorated sibling symbol, found
    by name when no listing with source lines exists."""
    m = re.match(r'\?\?([01])(\w+)@', sym)
    if m:
        owner, name = m.group(2), ('~' if m.group(1) == '1' else '') + m.group(2)
    else:
        m = re.match(r'\?(\w+)@(\w+)?@', sym)
        if not m:
            return None
        name, owner = m.group(1), m.group(2)
    pat = re.compile(rf'(?<![\w:]){re.escape((owner + "::") if owner else "")}{re.escape(name)}\s*\(' if owner else
                     rf'^[\w:<>\*&\s]*\b{re.escape(name)}\s*\(')
    for i, l in enumerate(lines):
        if l[:1].isspace() or not pat.search(l) or l.rstrip().endswith(';'):
            continue
        for k in range(i, min(i + 8, len(lines))):
            if '{' in lines[k]:
                return k + 1
            if lines[k].rstrip().endswith(';'):
                break
    return None


def build_plan_fnv(args):
    import hashlib
    import os
    results = json.load(open(args.build_results))

    def stem_of(src):
        s = re.sub(r'[^A-Za-z0-9_]', '_', str(os.path.splitext(src)[0]))
        return s[:60] + '_' + hashlib.sha1(s.encode()).hexdigest()[:10] if len(s) > 90 else s
    stem_src = {stem_of(r['source']): r['source'] for r in results}
    wanted = {int(x) for x in json.load(open(args.pass_list))}
    skip = {int(x) for x in json.load(open(args.skip))} if args.skip else set()
    out, cache = [], {}
    for x in json.load(open(args.scores)):
        if not x.get('identical') or x['rva'] not in wanted or x['rva'] in skip:
            continue
        stem, sym = x['key']
        src = stem_src.get(stem)
        if not src or src.startswith(('src/havok', 'src/gamebryo')):
            continue  # Havok and Gamebryo material of the FNV clone is excluded
        if src not in cache:
            cache[src] = (SIBLING_DIR / src).read_text(errors='replace').splitlines()
        line = None if sym.startswith(('??_G', '??_E')) else definition_line(cache[src], sym)
        out.append({'rva': x['rva'], 'stem': stem, 'sym': sym, 'size': x['size'], 'source': src, 'line': line,
                    'texts': [], 'file': None})
    Path(args.out).write_text(json.dumps(out, indent=1))
    print(len(out), 'entries;', sum(1 for o in out if not o['line']), 'without a located definition (thunks need none)')


def build_plan(args):
    scores = json.load(open(args.scores))
    results = [r for b in args.build_results for r in json.load(open(b))]
    stem_src = {Path(r['obj']).stem: r['source'] for r in results}
    wanted = {int(x) for x in json.load(open(args.rvas))} if args.rvas else None
    out = []
    for x in scores:
        # a near pair is not identical after masking; the caller names the pairs it wants
        if wanted is not None:
            if x['rva'] not in wanted:
                continue
        elif not x.get('identical'):
            continue
        stem, sym = x['key']
        line, texts, fname = locate(args.listings, stem, sym)
        out.append({'rva': x['rva'], 'stem': stem, 'sym': sym, 'size': x['size'], 'source': stem_src.get(stem),
                    'line': line, 'texts': texts, 'file': fname})
    Path(args.out).write_text(json.dumps(out, indent=1))
    print(len(out), {'listed': sum(1 for o in out if o['line']), 'no_line': sum(1 for o in out if not o['line'])})


def parse_signature(sig_lines):
    """(owner, name) from the first line of a function definition, owner None for a free function."""
    head = ' '.join(l.strip() for l in sig_lines).split('(')[0]
    m = re.search(rf'((?:{IDENT}(?:<[^<>]*>)?::)*)(~?{IDENT}|operator\s*\S+)\s*$', head)
    if not m:
        return None, None
    owner = m.group(1)[:-2] if m.group(1) else None
    return owner, m.group(2)


def whole_word(text, old, new):
    return re.sub(rf'(?<![\w]){re.escape(old)}(?![\w])', new, text)


def forward_declarations(class_lines):
    """Names used as pointer or reference types; a forward declaration is harmless when the class
    is defined later in the same text, and a base or member may need it earlier."""
    body = '\n'.join(class_lines)
    blocked = set(re.findall(rf'\benum\s+(?:class\s+)?({IDENT})', body)) | set(re.findall(rf'\btypedef\b[^;{{}}]*\b({IDENT})\s*;', body))
    used = set(re.findall(r'\b([A-Z]\w*[a-z]\w*)\s*[*&]', body)) - blocked
    return sorted(u for u in used if not re.fullmatch(r'(?:Func|Data|Routine)[0-9a-f]{6,8}', u))


def dependency_classes(lines, class_lines, own, seen=None):
    """Definitions of the sibling classes `class_lines` use (bases and members), dependencies first."""
    seen = seen if seen is not None else {own}
    out = []
    joined = '\n'.join(lines)
    for name in sorted(set(re.findall(r'\b([A-Za-z_]\w*)\b', '\n'.join(class_lines)))):
        if name in seen or not re.search(rf'^(?:class|struct)\s+{re.escape(name)}\b(?!\s*;)', joined, re.M):
            continue
        seen.add(name)
        body = class_text(lines, name)
        if body is None:
            continue
        out += dependency_classes(lines, body, own, seen)
        out.append((name, body))
    return out


CALL_KEYWORDS = {'if', 'for', 'while', 'switch', 'return', 'sizeof', 'catch', 'defined', 'template', 'operator', 'new', 'delete',
                 'static_cast', 'reinterpret_cast', 'const_cast', 'dynamic_cast', 'typeid', 'throw', 'alignof', 'decltype'}


def helper_functions(lines, upto, text, ns, seen=None, depth=3):
    """Definitions of free helper functions (often inline templates) that sit earlier in the same
    sibling file and that `text` calls; the target inlines them, so a bare declaration would
    emit a call the target does not make. Dependencies come first."""
    seen = seen if seen is not None else set()
    out = []
    head = lines[:upto]
    for name in sorted(set(re.findall(rf'(?<![\w:.>])({IDENT})\s*(?:<[^<>;()]*>\s*)?\(', text)) - CALL_KEYWORDS - seen):
        seen.add(name)
        brace = definition_line(head, f'?{name}@@')
        if not brace or depth <= 0:
            continue
        got = excerpt(lines, brace)
        if got is None or not got[1] or got[1][0][:1].isspace() or enclosing_namespaces(lines, got[2]) != ns:
            continue
        body = '\n'.join(got[1])
        out += helper_functions(lines, got[2], body, ns, seen, depth - 1)
        out.append(body)
    return out


def harvest_declarations(ctx, text, limit=40):
    """One-line top-level extern, typedef and imported-function declarations of the sibling files
    that the excerpt names but does not declare itself."""
    used = set(re.findall(r'\b[A-Za-z_]\w+\b', text))
    out = []
    for l in ctx:
        if not l.startswith(('extern', 'typedef', '__declspec')) or not l.rstrip().endswith(';') or 'struct {' in l:
            continue
        s = l.rstrip().rstrip(';').strip()
        m = re.search(r'(\w+)\s*\([^()]*\)\s*(?:const)?$', s) or re.search(r'(\w+)\s*(?:\[[^\]]*\])?\s*(?:=.*)?$', s)
        name = m.group(1) if m else None
        if not name or name not in used or LIBC_NAMES.fullmatch(name):
            continue
        if re.search(rf'^(?:extern|typedef|__declspec)[^\n]*\b{re.escape(name)}\b', text, re.M):
            continue
        if l not in out:
            out.append(l)
        if len(out) >= limit:
            break
    return out


def with_support_lines(decl, body, ctx):
    """Prepend the system includes and the one-line sibling declarations the excerpt needs."""
    extra = harvest_declarations(ctx, decl + '\n' + body)
    if extra:
        decl = '\n'.join(extra) + '\n\n' + decl
    libs = ['#include <string.h>'] if LIBC_NAMES.search(decl + body) else []
    if 'size_t' in sanitize(decl + body):
        libs.append('#include <stddef.h>')
    return ('\n'.join(libs) + '\n\n' + decl) if libs else decl


def stub_class(lines, cname, new_name):
    """Class definition with every constructor replaced by one default constructor (the compiler
    emits the vftable and the compared deleting destructor next to a defined constructor)."""
    cls = class_text(lines, cname)
    if cls is None:
        return None
    out, added = [], False
    k = 0
    while k < len(cls):
        l = cls[k]
        if re.match(rf'\s*(?:explicit\s+)?{re.escape(cname)}\s*\(', l):
            # drop the whole constructor: a declaration ends at ';', a definition at its closing brace
            depth, seen = 0, False
            while k < len(cls):
                s = re.sub(r'//.*', '', cls[k])
                depth += s.count('{') - s.count('}')
                seen = seen or '{' in s
                k += 1
                if (seen and depth <= 0) or (not seen and s.rstrip().endswith(';')):
                    break
            if not added:
                out.append(f'    {cname}();')
                added = True
            continue
        out.append(l)
        k += 1
    if not added:
        i = next((k for k, l in enumerate(out) if '{' in l), 0)
        out[i + 1:i + 1] = ['  public:', f'    {cname}();']
    return out


def sized_thunk_unit(entry, fact, size):
    """Unit for a deleting-destructor thunk whose class is only known by its size: a class with a
    virtual destructor and opaque padding. Nothing is taken from the sibling's text."""
    sk_cls, _ = skyrim_name(fact)
    cls = sk_cls or f'Owner{entry["rva"]:x}'
    pad = size - 8
    members = f'    char padding_[{pad}];\n' if pad else ''
    decl = f'class {cls}\n{{\n  public:\n    {cls}();\n    virtual ~{cls}();\n{members}}};'
    kind = 'CRASHLOGGER' if sk_cls else 'GUESS'
    return dict(cls=cls, header_decl=decl, cpp_body=f'{cls}::{cls}()\n{{\n}}\n', compared=f'{cls}::~{cls}', src_line=None,
                adapted='none', labels=[([cls, f'{cls}::~{cls}'], kind)], thunk=True, source=None, original=True)


STATEMENT_START = re.compile(r'\s*(?:for|if|while|switch|return|do|else|case|\{|\*|\w+(?:\.|->)|\w+\s*=[^=])')


def cut_inline_member(lines, got):
    """(class lines with a prototype in place of the member, out-of-line definition lines) for a
    non-template member function defined inside a class body, or None. The same code is compiled
    either way; only the comparison needs the function to be emitted on its own."""
    pre, fn, sig = got
    end = sig + len(fn) - 1
    if STATEMENT_START.match(fn[0]) or 'template' in ' '.join(l.strip() for l in lines[max(sig - 1, 0):sig + 1]).split('(')[0]:
        return None
    start = next((i for i in range(sig - 1, -1, -1) if re.match(rf'(?:class|struct)\s+{IDENT}\b[^;]*$', lines[i])), None)
    if start is None or match_brace(lines, start) is None or match_brace(lines, start) < end:
        return None
    if start > 0 and lines[start - 1].lstrip().startswith('template'):
        return None
    cls = re.match(rf'(?:class|struct)\s+({IDENT})', lines[start]).group(1)
    brace = next((i for i in range(sig, end + 1) if '{' in lines[i]), None)
    if brace is None:
        return None
    head = ' '.join(l.strip() for l in lines[sig:brace]) + ' ' + lines[brace].split('{')[0].strip()
    if ':' in re.sub(r'::', '', head.split(')')[-1]):
        # a constructor initializer list sits between the signature and the body
        head = head.split(')')[0] + ')'
    m = re.search(rf'(?<![\w.>])(~?{IDENT}|operator\s*[^\s(]+)\s*\(', head)
    if not m or m.group(1) in CALL_KEYWORDS:
        return None
    proto = '    ' + re.sub(r'\s+', ' ', head).strip() + ';'
    out_head = re.sub(r'^\s*(?:(?:virtual|static|inline|explicit|__forceinline)\s+)*', '', fn[0])
    out_head = re.sub(rf'(?<![\w.>])({re.escape(m.group(1))})\s*\(', rf'{cls}::\1(', out_head, 1)
    if f'{cls}::' not in out_head:
        return None
    # default arguments belong to the declaration only
    open_ = out_head.index('(')
    close = out_head.rfind(')') if ')' in out_head else len(out_head)
    out_head = out_head[:open_] + re.sub(r'\s*=\s*[^,)]+', '', out_head[open_:close]) + out_head[close:]
    new_class = lines[start:sig] + [proto] + lines[end + 1:match_brace(lines, start) + 1]
    closed = re.search(r'\}\s*[\w\s,*]*;\s*$', lines[match_brace(lines, start)])
    if not closed:
        new_class.append(lines[match_brace(lines, start) + 1])
    return new_class, [out_head] + [l[4:] if l.startswith('    ') else l for l in fn[1:]]


def build_unit(entry, fact, shadow_lines, original_lines, mode=None):
    """Return dict(cls, header, cpp, name, labels...) or a string explaining why not."""
    sym, rva = entry['sym'], entry['rva']
    is_thunk_sym = sym.startswith(('??_G', '??_E'))
    if mode == 'sized':
        return sized_thunk_unit(entry, fact, entry['size_hint'])
    got = excerpt(shadow_lines, entry['line']) if entry.get('line') else None
    inline_member = bool(got) and got[1][0][:1].isspace()
    thunk = is_thunk_sym and (got is None or inline_member or mode != 'excerpt')
    cut = None
    if inline_member and not thunk:
        cut = cut_inline_member(shadow_lines, got)
        if cut is None:
            return 'function defined inside a class body'
    sk_cls, sk_method = skyrim_name(fact)
    if thunk:
        cname = decorated_parts(sym)
        if not cname or '@' in cname:
            return 'thunk class not parseable'
        ctx = include_context(entry['source'])
        pre_lines = stub_class(ctx, cname, cname)
        if pre_lines is None:
            return 'sibling class definition not found'
        deps = dependency_classes(ctx, pre_lines, cname)
        known = {d for d, _ in deps}
        all_lines = [l for _, b in deps for l in b] + pre_lines
        fwd = forward_declarations(all_lines)
        cls = sk_cls or sanitize(cname)
        decl = [f'struct {f};' for f in fwd if f != cname]
        for _, lines_ in deps:
            decl += [''] + lines_
        decl += [''] + pre_lines
        header_decl = with_support_lines(sanitize(whole_word('\n'.join(decl), cname, cls)), '', ctx)
        body = f'{cls}::{cls}()\n{{\n}}\n'
        compared = f'{cls}::~{cls}'
        origin_file, src_line = class_origin(entry['source'], cname)
        adapted = f'{cls} (class layout and virtual destructor; the constructor is an empty stand-in that makes the compiler emit the vftable)'
        labels = [([cls, compared], 'CRASHLOGGER' if sk_cls else ('SIBLING' if cls == cname else 'GUESS'))]
        return dict(cls=cls, header_decl=header_decl, cpp_body=body, compared=compared, src_line=src_line, adapted=adapted,
                    labels=labels, thunk=True, source=origin_file)
    if got is None:
        return 'function extent not found'
    pre, fn, sig = got
    if cut:
        pre, fn = cut
    owner, name = parse_signature(fn[:3])
    if name is None:
        return 'signature not parseable'
    cls = sk_cls or (sanitize(owner) if owner and '::' not in owner and '<' not in owner else None)
    method = name
    if sk_cls and owner and '::' not in owner and '<' not in owner and sk_method and sk_method not in DELETING and not sk_method.startswith('~'):
        method = sk_method
    free = owner is None
    ns = enclosing_namespaces(shadow_lines, sig)
    pre = [l for l in pre if not NAMESPACE_LINE.fullmatch(l)]
    in_pre = set(re.findall(rf'^(?:class|struct)\s+({IDENT})', '\n'.join(pre), re.M))
    helpers = helper_functions(shadow_lines, sig, '\n'.join(fn), ns) if entry.get('source') and not name.startswith('~') else []
    deps = [(n, b) for n, b in dependency_classes(include_context(entry['source']), pre + fn + '\n'.join(helpers).split('\n'), None)
            if n not in in_pre]
    text_pre = '\n\n'.join('\n'.join(b) for _, b in deps + [('', pre)] if b)
    if helpers:
        text_pre += '\n\n' + '\n\n'.join(helpers)
    used = '\n'.join(fn) + '\n' + text_pre
    fwd = [m for m in forward_declarations(used.split('\n')) if m != owner]
    if fwd:
        text_pre = '\n'.join(f'struct {f};' for f in fwd) + '\n\n' + text_pre
    text_pre = with_support_lines(wrap_namespaces(text_pre, ns) if ns else text_pre, '\n'.join(fn), include_context(entry['source']))
    text_fn = '\n'.join(fn)
    if name.startswith('~'):
        method = name = '~' + (sk_cls or sanitize(owner or ''))
    raw_name = parse_signature(fn[:3])[1]
    if sk_cls and owner and '::' not in owner and '<' not in owner:
        text_pre, text_fn = whole_word(text_pre, owner, sk_cls), whole_word(text_fn, owner, sk_cls)
        if raw_name.startswith('~'):
            text_fn = whole_word(text_fn, raw_name, method)
        elif method != name:
            text_fn = whole_word(text_fn, name, method)
    text_pre, text_fn = sanitize(text_pre), sanitize(text_fn)
    src_line = source_line_of(fn[0], original_lines) or source_line_of(fn[1], original_lines) or entry['line']
    if free:
        cls = 'Globals'
    if cls is None:
        return 'nested or templated owner'
    if ns:
        text_fn = wrap_namespaces(text_fn, ns)
    method_out = sanitize(method)
    kept = method_out == raw_name
    qual = '::'.join(ns) + '::' if ns else ''
    plain = method_out if free else f'{cls}::{method_out}'
    compared = qual + plain
    labels = []
    if not free:
        cls_kind = 'CRASHLOGGER' if sk_cls else ('SIBLING' if cls == owner else 'GUESS')
        if method_out.startswith('~'):
            labels.append(([cls, plain], cls_kind))
        else:
            labels.append(([cls], cls_kind))
            labels.append(([plain], 'SIBLING' if kept and cls_kind != 'GUESS' else ('CRASHLOGGER' if sk_cls and not kept and sk_method == method else 'GUESS')))
    else:
        labels.append(([method_out], 'SIBLING' if kept else 'GUESS'))
    return dict(cls=cls, header_decl=text_pre.strip('\n'), cpp_body=text_fn + '\n', compared=compared, src_line=src_line,
                adapted=compared, labels=labels, thunk=False, free=free, method=method, source=entry['source'],
                raw_name=sanitize(raw_name))


def render(u, rva, rel_source, cls_file):
    note = {'SIBLING': SIBLING_LABEL, 'CRASHLOGGER': CRASHLOGGER, 'GUESS': 'GUESS(low)'}
    h = ['// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).',
         '// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.',
         '// SPDX-License-Identifier: CC0-1.0']
    for names, kind in u['labels']:
        extra = '; sibling name, identity with this function unproven' if kind == 'SIBLING' else ''
        extra = '; placeholder name' if kind == 'GUESS' else extra
        h.append(f'// {", ".join(dict.fromkeys(names))}: {note[kind]}{extra}')
    if u.get('original'):
        h[0] = '// Source exposure: mixed (names from the community PDB table where labelled; sizes from the pinned image listing).'
        h[1] = '// Code origin: original; a class with a virtual destructor, sized from the target; the sibling decompilation only pointed at the shape.'
        c = ['// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).',
             '// Code origin: original; the compiler-generated deleting destructor of a class declaration.',
             '// Adapted bodies: none',
             f'// 0x{rva:x} {u["compared"]}']
    else:
        c = ['// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).',
             f'// Code origin: adapted from the sibling decompilation; adapted bodies: {u["adapted"]}.',
             f'// Sibling source: {SIBLING_REV} {rel_source}:{u["src_line"]}',
             f'// 0x{rva:x} {u["compared"]}']
    # Built after the original-unit wording is chosen: a header that claims sibling adaptation next to a
    # source that names none is rejected as a provenance gap.
    header = '\n'.join(h) + '\n#pragma once\n\n' + u['header_decl'] + '\n'
    cpp = '\n'.join(c) + f'\n#include "{cls_file}.h"\n\n' + u['cpp_body']
    return header, cpp


def ci_hash_line(task_dir, rva):
    """`// CI hash:` line naming the task's decorated symbol, or None.

    The standing compare host rebuilds the task from the community name, which a stand-in class does not
    carry, so only this line tells it which symbol of the object is the function.
    """
    task = json.loads((Path(task_dir) / 'task.json').read_text())
    for fn in task.get('functions', []):
        if int(str(fn['rva']), 0) == rva and str(fn.get('symbol', '')).startswith('?'):
            return f'// CI hash: 0x{rva:x} {fn["symbol"]}'
    return None


def load_facts():
    facts = {}
    for fn in sorted((ROOT / 'data/target-hashes').glob('contributor-target-facts-part-*.json')):
        facts.update(json.load(open(fn))['facts'])
    return facts


AREA_BY_SOURCE = [('gamebryo2.2/corelibs/nianimation', 'gamebryo/nianimation'), ('gamebryo2.2/corelibs/niparticle', 'gamebryo/niparticle'),
                  ('gamebryo2.2/corelibs/nicollision', 'gamebryo/nimain'), ('gamebryo', 'gamebryo/nimain'), ('havok', 'bshavok'),
                  ('bsshader', 'bsshader'), ('bsaudio', 'bsaudio'), ('bscore', 'bscore'), ('bsmain', 'bsmain'), ('bsinput', 'bsinput'),
                  ('bsmenu', 'skyrim/interface'), ('fallout/ai', 'skyrim/ai'), ('fallout_shared', 'skyrim_shared/forms')]


def area_for(source):
    source = source or ''
    for prefix, area in AREA_BY_SOURCE:
        if f'src/{prefix}' in source:
            return area
    return 'unmapped/support'


_START_LOCK = __import__('threading').Lock()


def start_task(rva, cls, area=None):
    with _START_LOCK:
        return _start_task(rva, cls, area)


def _start_task(rva, cls, area=None):
    """Create the unit skeleton and task for one function with a per-RVA unit name, like the
    sibling rounds do, so no existing unit or shared header is touched."""
    import contextlib
    import io
    import os
    sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tools/verifier')]
    import contrib
    r6 = f'{rva:x}'
    orig_files, orig_tid = contrib.unit_files, contrib.task_id_for

    def unit_files(repo, c, area=None, index=None):
        a, h, cpp = orig_files(repo, c, area, index)
        if a is None:
            return a, h, cpp
        return a, f'reconstruction/{a}/{c}_{r6}.h', f'reconstruction/{a}/{c}_{r6}.cpp'

    def task_id(c, practice=False):
        base = orig_tid(c, practice)
        return base[:max(len('contrib-') + 8, 50 - len(r6) - 1)].rstrip('-') + f'-{r6}'
    contrib.unit_files, contrib.task_id_for = unit_files, task_id
    argv = sys.argv
    sys.argv = ['contrib.py', 'start', f'0x{rva:x}', '--no-branch', '--model', 'sibling-transplant', '--class', cls] + (['--area', area] if area else [])
    buf = io.StringIO()
    try:
        with contextlib.redirect_stdout(buf), contextlib.redirect_stderr(buf):
            code = contrib.main()
    finally:
        sys.argv = argv
        contrib.unit_files, contrib.task_id_for = orig_files, orig_tid
    out = buf.getvalue()
    m = re.search(r'^unit: (\S+\.h) and (\S+\.cpp)', out, re.M)
    if code or not m:
        return None, out[-300:]
    return (m.group(1), m.group(2)), out


def undeclared_origin_lines(cpp):
    """Leading-comment lines for bodies check_origin finds close to a sibling body that the header
    does not yet name: a `Sibling source:` line per upstream file (the same function often exists in
    both Fallout decompilations) and one line naming helper functions taken along with the unit."""
    import subprocess
    files = [str(cpp)] + ([str(cpp.with_suffix('.h'))] if cpp.with_suffix('.h').exists() else [])
    r = subprocess.run([sys.executable, str(ROOT / 'tools/check_origin.py'), *files], cwd=ROOT, capture_output=True, text=True)
    revs = {'momusdigital/fnv_decomp@91e1b6e': 'momusdigital/fnv_decomp@91e1b6e8', 'momusdigital/fnv_decomp@2b07cb3': 'momusdigital/fnv_decomp@2b07cb3e',
            'momusdigital/f3_decomp@f5bac1b': 'momusdigital/f3_decomp@f5bac1b5'}
    out, names = [], []
    for m in re.finditer(r'^\s+(\S+) ~ (\S+@[0-9a-f]+) (\S+:\d+) similarity [\d.]+ \(adapted; header does NOT name', r.stdout, re.M):
        rev = revs.get(m.group(2))
        if rev:
            line = f'// Sibling source: {rev} {m.group(3)}'
            if line not in out:
                out.append(line)
            short = m.group(1).split('::')[-1]
            if short not in names:
                names.append(short)
    if out and names:
        out.append('// Adapted helpers: ' + ', '.join(names))
    return out


def clang_errors(cpp, limit=3):
    """Clang errors (message only) for the unit, or [] when clang is missing or the unit parses."""
    import subprocess
    clang = Path('/opt/homebrew/opt/llvm/bin/clang++')
    if not clang.exists():
        return []
    tc = MAIN / '.local/toolchains/msvc-19.16.27054'
    cmd = [str(clang), '-fsyntax-only', '-target', 'x86_64-pc-windows-msvc', '-fms-extensions', '-fms-compatibility',
           '-std=c++14', '-w', f'-ferror-limit={limit}', '-x', 'c++', '-I', str(cpp.parent)]
    for inc in (tc / 'VC/Tools/MSVC').glob('*/include'):
        cmd += ['-isystem', str(inc)]
    for sub in ('ucrt', 'shared', 'um'):
        for inc in (tc / 'kits/10/include').glob(f'*/{sub}'):
            cmd += ['-isystem', str(inc)]
    r = subprocess.run(cmd + [str(cpp)], capture_output=True, text=True)
    # clang treats the Interlocked family as builtins; cl does not, so those are left to the verifier
    errs = [l for l in r.stderr.splitlines() if ' error: ' in l and "conflicting types for 'Interlocked" not in l
            and not re.search(r"declaration of '_?Interlocked\w+' has a different language linkage", l)]
    return [re.sub(r'^.*? error: ', '', e) for e in errs]


def syntax_precheck(cpp):
    """First clang error for the unit, or None. A cheap local gate so hopeless units do not spend
    counted compile failures on the verifier host; clang is stricter than MSVC in places, so a
    failure here is reported, not hidden."""
    errs = clang_errors(cpp)
    return errs[0][:140] if errs else None


SYSTEM_SNIPPETS = {'MAX_PATH': '#define MAX_PATH 260', '__m128': '#include <intrin.h>', '__m128i': '#include <intrin.h>',
                   '__m128d': '#include <intrin.h>'}


def missing_declaration(name, ctx):
    """Text that declares `name`, taken from the sibling files the unit came from: a (possibly
    multi-line) typedef, a class definition with its dependencies, or a one-line prototype."""
    if name in SYSTEM_SNIPPETS:
        return SYSTEM_SNIPPETS[name]
    text = '\n'.join(ctx)
    n = re.escape(name)
    m = re.search(rf'^typedef\b[^;{{}}]*?(?:\(\s*[*&]?\s*{n}\s*\)[^;{{}}]*|\b{n}\s*(?:\[[^\]]*\])?\s*);', text, re.M)
    if m:
        return m.group(0)
    deps = dependency_classes(ctx, [name], None)
    if deps:
        return '\n\n'.join('\n'.join(b) for _, b in deps)
    m = re.search(rf'^(?:extern\b|[A-Za-z_][^\n;{{}}=]*\b){re.escape(name)}\b[^\n;{{}}]*;', text, re.M)
    if m:
        return m.group(0)
    return None


def repair_header(hpath, cpath, ctx, rounds=12):
    """Add the sibling declarations the compiler reports as missing to the unit's own header (never
    a shared one), until the unit parses or nothing more can be found. Returns the last error."""
    seen = set()
    ctx = [sanitize(l) for l in ctx]
    for _ in range(rounds):
        errs = clang_errors(ROOT / cpath, 12)
        if not errs:
            return None
        add = []
        for e in errs:
            m = re.search(r"(?:unknown type name|use of undeclared identifier|incomplete type|no template named) '(?:struct |class )?([\w:]+)'", e)
            name = m.group(1).split('::')[-1] if m else None
            if not name or name in seen:
                continue
            seen.add(name)
            raw = name
            for rx, rep in RENAMES:
                raw = rx.sub(rep, raw)
            text = missing_declaration(name, ctx)
            if 'unknown type name' in e and re.fullmatch(IDENT, name) and (not text or not text.startswith(('typedef', '#'))):
                # a pointer or reference only needs the name; a complete type is requested by a later error
                text = f'struct {name};'
            if text:
                add.append(text)
                break  # later errors are often caused by this one
        if not add:
            return errs[0][:140]
        h = (ROOT / hpath).read_text()
        lines = h.split('\n')
        k = next((i for i, l in enumerate(lines) if l.strip() == '#pragma once'), 0) + 1
        add.sort(key=lambda t: not re.fullmatch(r'struct \w+;', t))
        lines[k:k] = [''] + '\n\n'.join(add).split('\n')
        (ROOT / hpath).write_text('\n'.join(lines))
    errs = clang_errors(ROOT / cpath)
    return errs[0][:140] if errs else None


def template_instantiation(sym):
    """Explicit instantiation line for a function-template instance symbol (`??$Name@...`): the sibling
    function is a template, so nothing is emitted unless the unit asks for this instance."""
    import subprocess
    tool = Path('/opt/homebrew/opt/llvm/bin/llvm-undname')
    if not sym.startswith('??$') or not tool.exists():
        return None
    out = subprocess.run([str(tool), sym], capture_output=True, text=True).stdout.strip().splitlines()
    text = out[-1].strip() if out else ''
    if not text or text.startswith('error') or ('<' not in text):
        return None
    text = CALLCONV.sub('', re.sub(r'\b__(?:cdecl|stdcall|fastcall|thiscall|vectorcall)\b\s*', '', text))
    return 'template ' + sanitize(text) + ';'


def run_one(entry, facts, log, sizes=None, layouts=None):
    import subprocess
    rva = entry['rva']
    if sizes and hex(rva) in sizes:
        if sizes[hex(rva)] < 8:
            return 'unit:size below one pointer'
        fact = (facts.get(f'0x{rva:x}') or {}).get('crashlogger')
        return run_mode(dict(entry, size_hint=sizes[hex(rva)], source=None), fact, [], [], rva, 'sized')
    rel = clone_path(entry)
    thunk_sym = entry['sym'].startswith(('??_G', '??_E'))
    if not rel or (not entry.get('line') and not thunk_sym) or not (SIBLING_DIR / rel).exists():
        return 'no-source: function not in a clone file'
    entry = dict(entry, source=rel)
    original_lines = (SIBLING_DIR / entry['source']).read_text(errors='replace').splitlines()
    shadow_lines = original_lines
    line = resolve_line(original_lines, entry['line'], entry.get('texts') or [])
    if line is None and not entry['sym'].startswith(('??_G', '??_E')):
        return 'no-source: listed text not in the clone'
    if entry['sym'].startswith('??$'):
        # a template instance: the listing's first source line can belong to another template of the file
        inst = template_instantiation(entry['sym'])
        base = re.match(rf'template\s+[^()]*?({IDENT})\s*<', inst or '')
        found = definition_line(original_lines, f'?{base.group(1)}@@') if base else None
        if found:
            line = found
    # A deleting-destructor thunk is emitted next to a constructor or inline destructor whose listed lines say nothing about the class.
    entry = dict(entry, line=line)
    fact = (facts.get(f'0x{rva:x}') or {}).get('crashlogger')
    res = run_mode(entry, fact, shadow_lines, original_lines, rva, None, (layouts or {}).get(hex(rva)))
    if res.startswith(('FAIL', 'precheck')) and entry['sym'].startswith(('??_G', '??_E')) and entry.get('line'):
        res2 = run_mode(entry, fact, shadow_lines, original_lines, rva, 'excerpt')
        if not res2.startswith('unit:'):
            res = res2
    return res


def run_mode(entry, fact, shadow_lines, original_lines, rva, mode, layout=None):
    import subprocess
    u = build_unit(entry, fact, shadow_lines, original_lines, mode)
    if isinstance(u, str):
        return 'unit:' + u
    patches = os.environ.get('SIBLING_PATCHES')
    if patches:
        # {rva: [[regex, replacement]]}: argument constants the target passes differently from the sibling
        for rx, rep in json.load(open(patches)).get(f'0x{rva:x}', []):
            u['cpp_body'] = re.sub(rx, rep, u['cpp_body'])
    inst = None if u.get('thunk') else template_instantiation(entry['sym'])
    # the listing can point at another template than the instance named by the symbol; then nothing is instantiated
    if inst and layout is not None and '<unsigned char>' in inst:
        # sizeof(T) of a one-byte instance appears as a sibling immediate of 1 against the target's real size
        sizes = {int(f['skyrim'], 16) for f in layout if f['kind'] == 'immediate' and f['sibling_x64'] == '0x1'
                 and f['skyrim'].startswith('0x')} & {2, 4, 8}
        if len(sizes) == 1:
            inst = inst.replace('unsigned char', {2: 'short', 4: 'int', 8: '__int64'}[sizes.pop()])
    if inst and re.search(rf'(?<![\w:]){re.escape(u.get("raw_name") or "?")}\s*<', inst):
        u['cpp_body'] = u['cpp_body'].rstrip('\n') + '\n\n' + inst + '\n'
    if u.get('raw_name') and u.get('method') and u['method'] != u['raw_name'] and not u['method'].startswith('~'):
        # the declaration still carries the sibling's method name; the definition was renamed to the target's
        u['header_decl'] = whole_word(u['header_decl'], u['raw_name'], sanitize(u['method']))
    if layout is not None:
        if u.get('thunk'):
            return 'unit:layout: thunk'
        import sibling_layout
        why = sibling_layout.apply_layout(u, layout, u.get('method'))
        if why:
            return 'unit:layout: ' + why
    existing = next((ROOT / '.local/contrib/tasks').glob(f'*-{rva:x}'), None)
    if existing is not None:
        files, out = tuple(json.load(open(existing / 'task.json'))['contrib']['unit']), ''
    else:
        files, out = start_task(rva, u['cls'] if re.fullmatch(r'[A-Z]\w*', u['cls']) else 'Globals')
    if files is None and 'no area rule' in out:
        files, out = start_task(rva, u['cls'] if re.fullmatch(r'[A-Z]\w*', u['cls']) else 'Globals', area_for(entry['source']))
    if files is None:
        return 'start:' + out.replace('\n', ' ')[-160:]
    hpath, cpath = files
    import subprocess as _sp
    if (not __import__('os').environ.get('SIBLING_REWRITE') and
            _sp.run(['git', 'ls-files', '--error-unmatch', cpath], cwd=ROOT, capture_output=True).returncode == 0):
        return 'skip: the unit is already tracked in this checkout'
    fc = Path(hpath).stem.rsplit('_', 1)[0]
    if not re.search(rf'\b(?:class|struct)\s+{re.escape(fc)}\b(?!\s*;)', u['header_decl']):
        # the lint wants the unit's header to declare the class its file is named for
        u['header_decl'] += f'\n\nstruct {fc}\n{{\n}};'
        u['labels'] = u['labels'] + [([fc], 'GUESS')]
    header, cpp = render(u, rva, u['source'], Path(hpath).stem)
    (ROOT / hpath).write_text(header)
    (ROOT / cpath).write_text(cpp)
    extra = undeclared_origin_lines(ROOT / cpath)
    if extra:
        cpp = cpp.replace('#include "', '\n'.join(extra) + '\n#include "', 1)
        (ROOT / cpath).write_text(cpp)
    task = next((ROOT / '.local/contrib/tasks').glob(f'*-{rva:x}'))
    hint = ci_hash_line(task, rva)
    if hint and hint not in cpp:
        cpp = cpp.replace('#include "', hint + '\n#include "', 1)
        (ROOT / cpath).write_text(cpp)
    bad = syntax_precheck(ROOT / cpath)
    if bad and u.get('source'):
        bad = repair_header(hpath, cpath, include_context(u['source']))
    if bad:
        return 'precheck:' + bad
    if u.get('free'):
        # A free function has no class to bind it by; the hint names it by its own symbol.
        (task / 'bind-hints.json').write_text(json.dumps({u['method']: f'0x{rva:x}'}))
    r = subprocess.run([str(ROOT / 'tools/verifier/attempt'), str(task), '--model', 'sibling-transplant'],
                       cwd=ROOT, capture_output=True, text=True)
    text = r.stdout + r.stderr
    (task / 'transplant-attempt.txt').write_text(text)
    ok = re.search(rf'0x{rva:x} PASS', text) and not re.search(r'^\s+0x[0-9a-f]+ (FAIL|ERROR)', text, re.M)
    if ok:
        return 'PASS'
    first = next((l.strip() for l in text.splitlines() if re.search(r'error C\d+|FAIL|ERROR|UNBOUND|refus', l)), text.strip()[-120:])
    return 'FAIL:' + first[:160]




def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('plan')
    p.add_argument('--scores', required=True)
    p.add_argument('--listings', nargs='+', required=True)
    p.add_argument('--build-results', nargs='+', required=True)
    p.add_argument('--rvas', help='JSON list of rvas to plan whether or not they are identical (near pairs)')
    p.add_argument('--out', required=True)
    q = sub.add_parser('plan-fnv')
    q.add_argument('--scores', required=True)
    q.add_argument('--build-results', required=True)
    q.add_argument('--pass-list', required=True)
    q.add_argument('--skip', help='JSON list of rvas to leave out (those the Fallout 3 sibling already covers)')
    q.add_argument('--out', required=True)
    r = sub.add_parser('run')
    r.add_argument('plan')
    r.add_argument('rvas', nargs='+')
    r.add_argument('--jobs', type=int, default=4)
    r.add_argument('--sizes', help='JSON {rva: class size} for deleting-destructor thunks known only by size')
    r.add_argument('--layouts', help='JSON {rva: [layout facts]} for near pairs that differ only in member offsets or vtable slots')
    r.add_argument('--results', default=str(ROOT / '.local/transplant/results.jsonl'))
    a = ap.parse_args()
    if a.cmd == 'plan':
        build_plan(a)
    elif a.cmd == 'plan-fnv':
        build_plan_fnv(a)
    elif a.cmd == 'run':
        from concurrent.futures import ThreadPoolExecutor
        plan = {o['rva']: o for o in json.load(open(a.plan))}
        facts = load_facts()
        sizes = json.load(open(a.sizes)) if a.sizes else None
        layouts = json.load(open(a.layouts)) if a.layouts else None
        rvas = [int(x, 16) for x in a.rvas]
        # skeleton creation is serialised inside run_one; the PC attempts overlap
        def one(rva):
            try:
                res = run_one(plan.get(rva) or {'rva': rva, 'sym': '', 'size': 0}, facts, None, sizes, layouts)
            except Exception as exc:  # a bad sibling excerpt must not stop the batch
                res = f'error:{type(exc).__name__}: {exc}'[:200]
            print(hex(rva), res, flush=True)
            with open(a.results, 'a') as f:
                f.write(json.dumps({'rva': hex(rva), 'result': res}) + '\n')
        with ThreadPoolExecutor(a.jobs) as pool:
            list(pool.map(one, rvas))


if __name__ == '__main__':
    sys.exit(main())
