#!/usr/bin/env python3
"""Declaration index of the sibling decompilation clones.

The transplant tool cuts a function out of a sibling source file together with the declarations
that precede it. Those declarations often name classes, templates, typedefs and helpers that the
sibling keeps in other headers, deeper than the include walk reaches. This module scans every
header of the clone once, splits it into top-level declarations and answers "which text declares
NAME" together with the declarations that text needs, so the transplant can write them into the
unit's own header. Nothing here touches a tracked shared header, and nothing is read from the game.
"""
import re
from pathlib import Path

IDENT = r'[A-Za-z_]\w*'
KEYWORDS = {'class', 'struct', 'union', 'enum', 'typedef', 'template', 'typename', 'const', 'volatile', 'unsigned', 'signed',
            'int', 'long', 'short', 'char', 'void', 'float', 'double', 'bool', 'public', 'private', 'protected', 'virtual',
            'static', 'inline', 'extern', 'operator', 'return', 'if', 'else', 'for', 'while', 'new', 'delete', 'this', 'sizeof',
            'namespace', 'using', 'friend', 'explicit', 'true', 'false', 'default', 'switch', 'case', 'break', 'continue', 'do',
            'goto', 'try', 'catch', 'throw', 'size_t', 'wchar_t', 'auto', 'register', 'mutable', 'typeid', 'nullptr'}
# Lines that only serve the sibling's own 32-bit build: layout checks, packing, include plumbing.
NOISE = re.compile(r'^\s*(?:FNV_STATIC_ASSERT\s*\(|static_assert\s*\(|#\s*(?:pragma|include|ifndef|ifdef|endif|else|elif|if|undef)\b|#\s*define\s+\w+\s*$)')
ALIGN_MACRO = re.compile(r'\bFNV_ALIGN\(\s*(\d+)\s*\)')


CHECK_TYPEDEF = re.compile(r'^\s*typedef\s+char\s+\w+\s*\[[^\]]*\?[^\]]*\]\s*;\s*$')


def strip_noise(text):
    """Text without layout asserts, pragmas and guards; `FNV_ALIGN(n)` becomes `__declspec(align(n))`."""
    out = [l for l in text.split('\n') if not NOISE.match(l) and not CHECK_TYPEDEF.match(l)]
    text = ALIGN_MACRO.sub(r'__declspec(align(\1))', '\n'.join(out))
    return re.sub(r'\bFNV_CDECL\b', '__cdecl', re.sub(r'\bFNV_FORCEINLINE\b', 'inline', text))


def strip_comments(text):
    return re.sub(r'//[^\n]*', '', re.sub(r'/\*.*?\*/', '', text, flags=re.S))


class Decl:
    __slots__ = ('name', 'kind', 'text', 'file', 'template')

    def __init__(self, name, kind, text, file, template):
        self.name, self.kind, self.text, self.file, self.template = name, kind, text, file, template


def _statements(lines):
    """Top-level statements of a header as (first line index, text, last line index)."""
    out, cur, depth, start = [], [], 0, 0
    for i, l in enumerate(lines):
        if NOISE.match(l) or l.lstrip().startswith('#'):
            continue
        code = strip_comments(l)
        if not cur and not code.strip():
            continue
        if not cur:
            start = i
        cur.append(l)
        depth += code.count('{') - code.count('}')
        if depth > 0:
            continue
        tail = code.rstrip()
        # a statement ends at ';' or at the brace that closes an inline function
        if tail.endswith((';', '}')):
            out.append((start, '\n'.join(cur), i))
            cur = []
            depth = 0
    return out


def _classify(text, file):
    """Decl list for one statement."""
    body = strip_comments(text).strip()
    template = ''
    m = re.match(r'template\s*<', body)
    if m:
        d, i = 1, m.end()
        while i < len(body) and d:
            d += {'<': 1, '>': -1}.get(body[i], 0)
            i += 1
        template, body = body[:i], body[i:].lstrip()
    mlink = re.match(r'extern\s+"C"\s*(?=[^{\s])', body)
    if mlink:
        body = body[mlink.end():].lstrip()
    mc = re.match(rf'(class|struct|union)\s+(?:__declspec\([^)]*\)\s*)?({IDENT})\s*(?::[^;{{]*)?\{{', body)
    if mc:
        return [Decl(mc.group(2), 'class', text, file, template)]
    if re.match(rf'(?:class|struct|union)\s+{IDENT}\s*;', body):
        return []
    me = re.match(rf'enum\s+(?:class\s+)?({IDENT})\b[^;{{]*\{{', body)
    if me:
        return [Decl(me.group(1), 'enum', text, file, template)]
    if body.startswith('typedef'):
        names = []
        flat = re.sub(r'\{.*\}', '{}', body, flags=re.S).rstrip(';').strip()
        fp = re.search(rf'\(\s*[*&]\s*({IDENT})\s*\)', flat)
        if fp:
            names.append(fp.group(1))
        else:
            for part in flat.split(','):
                mm = re.search(rf'({IDENT})\s*(?:\[[^\]]*\])?\s*$', part.strip())
                if mm:
                    names.append(mm.group(1))
        return [Decl(n, 'typedef', text, file, template) for n in names if n not in KEYWORDS]
    mu = re.match(rf'using\s+({IDENT})\s*=', body)
    if mu:
        return [Decl(mu.group(1), 'typedef', text, file, template)]
    if body.startswith('extern') and not mlink:
        mm = re.search(rf'({IDENT})\s*(?:\[[^\]]*\])?\s*(?:=[^;]*)?;\s*$', body)
        if mm:
            return [Decl(mm.group(1), 'extern', text, file, template)]
    if not body.startswith(('namespace', 'extern "C"', 'return', 'if', 'for', 'while')):
        head = body.split('{', 1)[0]
        mf = re.search(rf'(?<![\w:~>.])({IDENT})\s*\(', head)
        if mf and mf.group(1) not in KEYWORDS and '=' not in head[:mf.start()]:
            return [Decl(mf.group(1), 'function', text, file, template)]
    return []


# Macros of the sibling's own build (`FNV64_*` switches and spellings) that a pasted definition could not expand.
SIBLING_MACRO = re.compile(r'\bFNV64_\w+|\bF3_\w+_(?:SPEC|BODIES)\b')


def rank(d, name, prefer=None):
    return (bool(SIBLING_MACRO.search(d.text)), d.kind == 'class' and bool(re.search(r';\s*$', d.text.split('{')[0])), Path(d.file).stem != name,
            d.file != prefer, -len(d.text))


class DeclIndex:
    """Index of the declarations of one clone's headers: name -> [Decl]."""

    def __init__(self, root, label, lines=None, file=''):
        self.root, self.label = Path(root), label
        self.by_name = {}
        if lines is not None:
            for _, text, _ in _statements(lines):
                for d in _classify(text, file):
                    self.by_name.setdefault(d.name, []).append(d)
            return
        for sub in ('include', 'src'):
            base = self.root / sub
            if not base.is_dir():
                continue
            for path in sorted(base.rglob('*.h')):
                self._scan(path)

    def _scan(self, path):
        rel = path.relative_to(self.root).as_posix()
        lines = path.read_text(errors='replace').split('\n')
        for _, text, _ in _statements(lines):
            for d in _classify(text, rel):
                self.by_name.setdefault(d.name, []).append(d)

    def lookup(self, name, prefer=None):
        """Best definition of `name`: one that needs no sibling macro, then the header named for it, then the longest text."""
        found = self.by_name.get(name)
        if not found:
            return None
        return sorted(found, key=lambda d: rank(d, name, prefer))[0]

    def names_in(self, text):
        return [n for n in dict.fromkeys(re.findall(IDENT, strip_comments(text))) if n in self.by_name and n not in KEYWORDS]


def closure(indexes, name, have=frozenset(), limit=60):
    """[(Decl, index label, names it needs complete)] that declare `name` and everything its definition needs, dependencies first.

    `have` holds names the unit already defines. Pointer-only uses are not chased separately: a name
    reached only through a pointer is left to the compiler loop, which asks for it when it turns out
    to be incomplete."""
    out, seen = [], set(have)

    def visit(n, depth):
        if n in seen or depth > 12 or len(out) >= limit:
            return
        seen.add(n)
        best = [(rank(d, n), i, d, ix) for i, ix in enumerate(indexes) for d in ([ix.lookup(n)] if ix.lookup(n) else [])]
        if not best:
            return
        # a definition that needs no sibling macro first, then the current game's clone, so related classes agree
        _, _, d, ix = min(best, key=lambda t: (t[0][0], t[1], t[0]))
        deps = complete_dependencies(d, ix)
        for dep in deps:
            visit(dep, depth + 1)
        out.append((d, ix.label, deps))

    visit(name, 0)
    return out


def complete_dependencies(d, ix):
    """Names `d` needs complete: bases, by-value members and typedef targets (not pointer/reference uses)."""
    body = strip_comments(d.text)
    if d.kind == 'class':
        head = body.split('{', 1)[0]
        deps = [n for n in re.findall(IDENT, head.split(':', 1)[1]) if n in ix.by_name] if ':' in head.replace('::', '') else []
        inner = body.split('{', 1)[1]
        for m in re.finditer(rf'^\s*(?:(?:static|mutable|const|volatile)\s+)*({IDENT})(?:::\w+)*(?:\s*<[^;()]*>)?\s+[\w\[\]]+(?:\s*,\s*\w+)*\s*(?:\[[^\]]*\])?;', inner, re.M):
            if m.group(1) in ix.by_name and m.group(1) != d.name and m.group(1) not in KEYWORDS:
                deps.append(m.group(1))
        return list(dict.fromkeys(deps))
    if d.kind == 'typedef':
        flat = re.sub(r'\([^)]*\)', ' ', body)
        return [n for n in dict.fromkeys(re.findall(IDENT, flat)) if n in ix.by_name and n != d.name and n not in KEYWORDS and '*' not in body.split(n)[1][:2]]
    return []


# ---- editing a unit header -------------------------------------------------------------------

LIBC = {'memcpy', 'memmove', 'memset', 'memcmp', 'strlen', 'strcmp', 'strcpy', 'strncpy', 'strncmp', 'strcat', 'sqrt', 'sqrtf', 'sin',
        'cos', 'tan', 'atan2', 'fabs', 'fabsf', 'floor', 'ceil', 'pow', 'malloc', 'free', 'abs'}
SYSTEM_INCLUDES = {'sqrt': '<math.h>', 'sqrtf': '<math.h>', 'sin': '<math.h>', 'cos': '<math.h>', 'tan': '<math.h>', 'atan2': '<math.h>',
                   'fabs': '<math.h>', 'fabsf': '<math.h>', 'floor': '<math.h>', 'ceil': '<math.h>', 'pow': '<math.h>',
                   'size_t': '<stddef.h>', 'MAX_PATH': '<windows.h>', 'HKEY': '<windows.h>', 'DWORD': '<windows.h>',
                   'HKEY_LOCAL_MACHINE': '<windows.h>', '_ULARGE_INTEGER': '<windows.h>', 'ULARGE_INTEGER': '<windows.h>', 'HANDLE': '<windows.h>', 'HWND': '<windows.h>', 'HINSTANCE': '<windows.h>',
                   'LPCSTR': '<windows.h>', 'BOOL': '<windows.h>', 'GUID': '<windows.h>', 'LARGE_INTEGER': '<windows.h>',
                   '__m128': '<intrin.h>', '__m128i': '<intrin.h>', '__m128d': '<intrin.h>', 'placement new': '<new>', 'va_list': '<stdarg.h>'}


def statements(h):
    """[(start, end, Decl-list)] of the top-level statements of header text `h` (character offsets)."""
    out, pos = [], 0
    lines = h.split('\n')
    offsets = []
    for l in lines:
        offsets.append(pos)
        pos += len(l) + 1
    for i0, text, i1 in _statements(lines):
        start = offsets[i0]
        end = offsets[i1] + len(lines[i1])
        out.append((start, end, _classify(text, '')))
    return out


def defined_names(h):
    """{name: kind} of what the header defines (forward declarations excluded)."""
    return {d.name: d.kind for _, _, ds in statements(h) for d in ds}


def cut(h, spans):
    """`h` without the (start, end) spans; a following blank line goes with each."""
    for start, end in sorted(spans, reverse=True):
        stop = end + 1 if h[end:end + 1] == '\n' else end
        h = h[:start] + h[stop:]
    return h


def remove_definitions(h, name):
    """Drop every definition of class `name` (used when a system header now provides it)."""
    return cut(h, [(s, e) for s, e, ds in statements(h) if any(d.name == name and d.kind in ('class', 'typedef') for d in ds)])


def remove_forward_declarations(h, name):
    return re.sub(rf'^[ \t]*(?:class|struct)\s+{re.escape(name)}\s*;[ \t]*\n', '', h, flags=re.M)


def remove_typedefs(h, name):
    spans = [(s, e) for s, e, ds in statements(h) if any(d.name == name and d.kind == 'typedef' for d in ds)]
    return cut(h, spans)


def remove_later_definitions(h, name, kinds=('class', 'enum')):
    """Keep the first definition of `name`, drop the others (a header that pasted the same class twice)."""
    spans = [(s, e) for s, e, ds in statements(h) if any(d.name == name and d.kind in kinds for d in ds)]
    return cut(h, spans[1:]) if len(spans) > 1 else h


def keep_first_declaration(h, name):
    """Keep the first one-line declaration of function or variable `name`; later ones with other types conflict."""
    spans = [(s, e) for s, e, ds in statements(h) if any(d.name == name and d.kind in ('function', 'extern') for d in ds)
             and '{' not in h[s:e]]
    return cut(h, spans[1:]) if len(spans) > 1 else h


def remove_declarations(h, names):
    spans = [(s, e) for s, e, ds in statements(h) if any(d.name in names and d.kind in ('function', 'extern') for d in ds)
             and '{' not in h[s:e]]
    return cut(h, spans)


def add_member(h, cls, prototype):
    """Insert `prototype` before the closing brace of class `cls`; None when the class is not defined here."""
    for s, e, ds in statements(h):
        if any(d.name == cls and d.kind == 'class' for d in ds):
            body = h[s:e]
            k = body.rfind('}')
            return h[:s + k] + '    ' + prototype.strip() + '\n' + h[s + k:]
    return None


def insert_block(h, text, name, deps=()):
    """Insert declaration `text` of `name` just before the first statement that uses it, but after the
    definitions of the names it needs complete; a forward declaration at the top covers earlier
    pointer uses when the block has to sit later."""
    spans = statements(h)
    stripped = lambda s_, e_: strip_comments(h[s_:e_])
    use = [s for s, e, ds in spans if re.search(rf'(?<![\w:]){re.escape(name)}(?![\w])', stripped(s, e))
           and not re.fullmatch(rf'\s*(?:class|struct)\s+{re.escape(name)}\s*;\s*', stripped(s, e))]
    pos = min(use) if use else None
    after = max([e for s, e, ds in spans if any(d.name in deps for d in ds)], default=None)
    if pos is None:
        return insert_after_pragma(h, text)
    if after is not None and after >= pos:
        h = h[:after + 1] + '\n' + text + '\n' + h[after + 1:]
        return insert_after_pragma(h, f'struct {name};')
    return h[:pos] + text + '\n\n' + h[pos:]


def insert_after_pragma(h, text):
    lines = h.split('\n')
    k = next((i for i, l in enumerate(lines) if l.strip() == '#pragma once'), -1) + 1
    lines[k:k] = [''] + text.split('\n')
    return '\n'.join(lines)


def member_prototype(root, raw_name):
    """One-line member prototype for `raw_name` (a sibling decompiler name such as FUN_00aa3e40) from
    any file of the clone, or None. Returns (prototype, file)."""
    rx = re.compile(rf'^[ \t]+((?:(?:virtual|static|inline|__thiscall|__fastcall|__stdcall)\s+)*[\w:<>*&\s]+?\b{re.escape(raw_name)}\s*\([^;{{}}]*\)(?:\s*const)?)\s*;', re.M)
    for sub in ('include', 'src'):
        base = Path(root) / sub
        for path in sorted(base.rglob('*')):
            if path.suffix not in ('.h', '.cpp') or not path.is_file():
                continue
            text = path.read_text(errors='replace')
            if raw_name not in text:
                continue
            m = rx.search(text)
            if m:
                return m.group(1).strip() + ';', path.relative_to(root).as_posix()
    return None


def reorder_definitions(h):
    """`h` with every definition placed after the definitions it needs complete (bases, by-value
    members, typedef targets), the other statements staying in order. Directives are hoisted under
    `#pragma once`; top-level comments between statements are not kept."""
    lines = h.split('\n')
    k = next((i for i, l in enumerate(lines) if l.strip() == '#pragma once'), -1)
    head, rest = lines[:k + 1], lines[k + 1:]
    stmts = _statements(rest)
    owner = {}
    for n, (i0, text, i1) in enumerate(stmts):
        for d in _classify(text, ''):
            owner.setdefault(d.name, n)
    typedefs = {d.name for _, text, _ in stmts for d in _classify(text, '') if d.kind == 'typedef'}
    templates = {d.name for _, text, _ in stmts for d in _classify(text, '') if d.kind == 'class' and d.template}
    callables = {d.name for _, text, _ in stmts for d in _classify(text, '') if d.kind in ('function', 'extern')}
    forwards = [f'struct {name};' for name in sorted(owner) if name not in typedefs | templates
                and any(d.name == name and d.kind == 'class' for _, text, _ in [stmts[owner[name]]] for d in _classify(text, ''))]
    ix = DeclIndex.__new__(DeclIndex)
    ix.by_name = {name: [] for name in owner}
    order, done = [], set()

    def emit(n, stack=()):
        if n in done or n in stack:
            return
        i0, text, i1 = stmts[n]
        for d in _classify(text, ''):
            for dep in complete_dependencies(d, ix):
                if dep in owner and owner[dep] != n:
                    emit(owner[dep], stack + (n,))
        kinds = {d.kind for d in _classify(text, '')}
        if not kinds & {'class', 'enum', 'typedef'}:
            # variables and functions use their types by value as often as not
            for name in set(re.findall(IDENT, strip_comments(text))):
                if name in owner and owner[name] != n:
                    emit(owner[name], stack + (n,))
        # a typedef name must exist wherever it is mentioned, pointer uses included
        for name in set(re.findall(IDENT, strip_comments(text))):
            if name in typedefs | templates | callables and owner[name] != n:
                emit(owner[name], stack + (n,))
        done.add(n)
        order.append(n)

    for n in range(len(stmts)):
        emit(n)
    inside = set()
    for i0, _, i1 in stmts:
        inside.update(range(i0, i1 + 1))
    directives = [l for i, l in enumerate(rest) if i not in inside and l.lstrip().startswith(('#include', '#define'))]
    body = ['\n'.join(rest[stmts[n][0]:stmts[n][2] + 1]) for n in order]
    return '\n'.join(head + directives + [''] + forwards + [''] + ['\n\n'.join(body)] + [''])


def global_declaration(root, raw_name, source=None):
    """One-line `extern` declaration of global `raw_name` (a decompiler name such as DAT_011f6238) from
    the clone: the unit's own source file first, then any other file. Returns (line, file) or None."""
    rx = re.compile(rf'^(extern\b[^\n;{{}}()]*\b{re.escape(raw_name)}\b(?:\[[^\]]*\])?)\s*;', re.M)
    root = Path(root)
    files = ([root / source] if source else []) + sorted(p for sub in ('include', 'src') for p in (root / sub).rglob('*') if p.suffix in ('.h', '.cpp'))
    for path in files:
        if not path.is_file():
            continue
        text = path.read_text(errors='replace')
        if raw_name in text:
            m = rx.search(text)
            if m:
                return m.group(1) + ';', path.relative_to(root).as_posix()
    return None
