"""Build a twin unit from a matched exemplar unit (this repository's own sources only).

A twin is a function whose code equals a matched exemplar's apart from the fields the comparator
treats as references (strict) or also apart from displacements and immediates (loose). The twin
unit is the exemplar's source cut down to the one compared function, with its helpers, and
with names replaced by stand-ins that claim nothing:

  stamped    the exemplar's own class name carries its RVA (a placeholder class): the RVA in every
             identifier, file name and header line becomes the twin's; the unit's own header is
             copied, keeping only the declarations the kept source reaches.
  stand-in   the exemplar's owner is a real class: the twin's header includes the exemplar's
             header and adds a copy of the owner declaration named `Owner<rva>` (method
             `Function<rva>`), labelled GUESS(low) STANDIN; nothing else about the owner is claimed.

Unsupported shapes raise `Unsupported` with a short reason; the planner counts them by reason.
"""
from dataclasses import dataclass, field
import json
from pathlib import Path
import re

import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import rva_headers  # noqa: E402
import record_store  # noqa: E402
from source_digest import include_closure  # noqa: E402
import twin_source as S  # noqa: E402

HEADER_LIMIT = 6
DROP_PREFIXES = ('// Drafted by', '// Task', '// Evidence', '// Labels', '// Cookbook:', '// Adapted bodies')
LABEL_WORD = re.compile(r'\b(COMMUNITY|SIBLING|GUESS|EXE_RTTI|OBSERVED|STANDIN|CRASHLOGGER_PDB|SYMBOLS)\b')
LABEL_LINE = re.compile(r'^//\s*(?P<names>\S.*?)\s*:\s*(?P<labels>(?:COMMUNITY|SIBLING|CRASHLOGGER_PDB|SYMBOLS|GUESS|EXE_RTTI|STANDIN|OBSERVED).*)$')
INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)
CI_HASH = re.compile(r'^//[ \t]*CI hash:[ \t]*0x([0-9a-fA-F]+)[ \t]+(\S+)[ \t]*$')
SPECIAL_METHOD = re.compile(r'^(?:~|operator\b)')


class Unsupported(Exception):
    def __init__(self, reason):
        super().__init__(reason)
        self.reason = reason


@dataclass
class Exemplar:
    rva: int
    stem: str                 # reconstruction-relative path without extension
    cpp: str
    cpp_name: str
    name: str                 # compared name from the `// 0x<rva> Name` line
    functions: list           # [(rva, name)] compared in the unit
    header_path: str = None   # reconstruction-relative path of the unit's own header
    header: str = None
    ci_hash: str = None       # decorated symbol of the exemplar's `// CI hash:` line, if any
    deleting_symbol: str = '' # externally emitted scalar deleting destructor

    @property
    def hex(self):
        return '%x' % self.rva

    @property
    def owner(self):
        return S.owner_of(self.name)

    @property
    def method(self):
        return S.simple_name(self.name)


@dataclass
class Twin:
    rva: int
    exemplar: int
    stem: str
    mode: str
    files: dict = field(default_factory=dict)   # reconstruction-relative path -> text
    name: str = ''
    notes: list = field(default_factory=list)


def resolve_include(root, unit_dir, name):
    for base in (Path(root) / 'reconstruction' / unit_dir, Path(root) / 'reconstruction'):
        if (base / name).is_file():
            return (base / name).relative_to(Path(root) / 'reconstruction').as_posix()
    return None


def load_exemplar(root, rva, stem):
    root = Path(root)
    cpp_path = root / 'reconstruction' / (stem + '.cpp')
    if not cpp_path.is_file():
        raise Unsupported('no-source')
    cpp = cpp_path.read_text()
    funcs = S.compared(cpp)
    mine = [n for r, n in funcs if r == rva]
    if not mine:
        raise Unsupported('exemplar-header-line-missing')
    unit_dir = Path(stem).parent.as_posix()
    header_path = header = None
    for inc in INCLUDE.findall(cpp):
        rel = resolve_include(root, unit_dir, inc)
        if rel and Path(rel).stem == Path(stem).stem or (rel and Path(rel).parent == Path(unit_dir) and header_path is None):
            header_path = rel
            header = (root / 'reconstruction' / rel).read_text()
            break
    ci = None
    for line in S.split_header(cpp)[0]:
        m = CI_HASH.match(line.strip())
        if m and int(m.group(1), 16) == rva:
            ci = m.group(2)
    deleting = deleting_symbol(root, rva, stem)
    return Exemplar(rva, stem, cpp, Path(stem).name, mine[0], funcs, header_path, header, ci, deleting)


def deleting_symbol(root, rva, stem):
    path = root / 'reports' / 'sse-steam-1-7-104' / f'0x{rva:x}.json'
    try:
        record = json.loads(record_store.read_text(path))
    except FileNotFoundError:
        return ''
    runs = record.get('runs') or []
    if not runs or record.get('source', {}).get('compiled') != 'reconstruction/' + stem + '.cpp':
        return ''
    report = runs[0]['report']
    symbol = report.get('function', {}).get('symbol', '')
    return symbol if report.get('contract_version') == 2 and re.fullmatch(r'\?\?_G[A-Za-z_]\w*@@\w+@Z', symbol) else ''


def included_headers(root, ex):
    path = 'reconstruction/' + ex.stem + '.cpp'
    try:
        return [(Path(root) / p).read_text(encoding='utf-8-sig')
                for p in include_closure(root, path) if p != path]
    except ValueError as exc:
        raise Unsupported('include-closure') from exc


# ------------------------------------------------------------------ slicing

def definition_for(ex, segs):
    """The function segment that defines the compared function, or None (compiler-made symbol).

    A unit whose header line names the function by description (generated units) is matched by the
    one definition whose qualified name carries the exemplar's RVA; the exemplar then takes that name."""
    if ex.deleting_symbol:
        return None
    want = ex.name
    hits = [s for s in segs if s.kind == 'function' and s.name == want]
    if len(hits) == 1:
        return hits[0]
    if len(hits) > 1:
        raise Unsupported('overloaded-definition')
    stamped = [s for s in segs if s.kind == 'function' and ex.hex in s.name]
    if len(stamped) == 1:
        ex.name = stamped[0].name
        return stamped[0]
    return None


def other_compared_names(ex):
    return {n for r, n in ex.functions if r != ex.rva and n != ex.name}


def keep_segments(ex, segs):
    """Segments of the exemplar .cpp the twin keeps: its definition, companions, what they reach."""
    target = definition_for(ex, segs)
    others = other_compared_names(ex)
    owner = ex.owner
    simple_owner = S.simple_name(owner)
    defs = [s for s in segs if s.kind in ('function', 'other') and (
        s.name not in others or (ex.deleting_symbol and S.owner_of(s.name) == owner
                                 and S.simple_name(s.name).lstrip('~') == simple_owner))]
    chosen = set()
    if target is not None:
        chosen.add(id(target))
    # companions of a compiler-made compared symbol: the owner's constructors and destructors
    # emit the vftable and the deleting destructor the comparison needs
    for s in defs:
        if owner and S.owner_of(s.name) == owner and S.simple_name(s.name).lstrip('~') == simple_owner:
            chosen.add(id(s))
    if not chosen:
        raise Unsupported('no-definition-for-compared-symbol')
    if ex.deleting_symbol and not any(id(s) in chosen and S.simple_name(s.name) == '~' + simple_owner for s in defs):
        raise Unsupported('no-destructor-definition')
    changed = True
    while changed:
        changed = False
        wanted = set()
        for s in defs:
            if id(s) in chosen:
                wanted |= set(s.mentions)
        for s in defs:
            if id(s) not in chosen and (S.simple_name(s.name) in wanted or s.name in wanted):
                chosen.add(id(s))
                changed = True
    wanted = set()
    for s in defs:
        if id(s) in chosen:
            wanted |= set(s.mentions)
    rest = [s for s in segs if s.kind not in ('function', 'other')]
    kept_rest = {id(s) for s in reachable([s for s in rest if s.kind != 'namespace'], wanted)}
    # a namespace (named or anonymous) holding helpers the kept code names is kept whole
    for s in rest:
        if s.kind == 'namespace' and '{' in s.text:
            inner = S.segments(s.text[s.text.index('{') + 1:s.text.rindex('}')])
            if any(i.name and (i.name in wanted or S.simple_name(i.name) in wanted) for i in inner):
                kept_rest.add(id(s))
    keep = [s for s in segs if id(s) in chosen or id(s) in kept_rest]
    return keep, wanted


def reachable(segs, roots):
    """Segments of a header reachable by name from `roots` (names), in file order."""
    needed = set(roots)
    kept = set()
    changed = True
    while changed:
        changed = False
        for i, s in enumerate(segs):
            if i in kept:
                continue
            hit = (s.name and (s.name in needed or S.simple_name(s.name) in needed))
            if not hit and s.text.lstrip().startswith('static_assert'):
                hit = any(j in kept and segs[j].name and segs[j].name in s.mentions for j in range(len(segs)))
            if hit:
                kept.add(i)
                needed |= set(s.mentions)
                changed = True
    return [segs[i] for i in sorted(kept)]


def preprocessor_lines(text):
    masked = S.mask_text(text)
    out = []
    for line, m in zip(text.split('\n'), masked.split('\n')):
        if m.lstrip().startswith('#'):
            out.append(line.strip())
    return out


def check_preprocessor(lines):
    for line in lines:
        word = re.sub(r'^#\s*', '', line).split()[0] if re.sub(r'^#\s*', '', line) else ''
        if word not in ('include', 'pragma'):
            raise Unsupported('conditional-or-macro-source')


# ------------------------------------------------------------------ labels and header comment

def label_rewrite(lines, mapping, text_after, extra=None):
    """Label lines with renamed names relabelled GUESS(low) STANDIN, vanished names dropped."""
    out, standins = [], []
    for line in lines:
        m = LABEL_LINE.match(line.strip())
        if not m:
            out.append(line)
            continue
        names = [n.strip() for n in m.group('names').split(',')]
        labels = m.group('labels')
        keep, moved = [], []
        for n in names:
            new = S.rename_identifiers(n, mapping)
            if new != n:
                moved.append(new)
            elif re.search(r'(?<![A-Za-z0-9_])' + re.escape(n.split('::')[-1]) + r'(?![A-Za-z0-9_])', text_after):
                keep.append(n)
        if keep:
            out.append('// ' + ', '.join(keep) + ': ' + labels)
        standins += moved
    return out, standins


def build_header_comment(ex, lines, mapping, twin, body_text, note):
    """Header lines of a twin file."""
    lines = [l for l in lines if l.strip() and not l.startswith(DROP_PREFIXES)]
    lines = [l for l in lines if not S.HEADER_LINE.match(l.strip()) and not CI_HASH.match(l.strip())]
    lines, standins = label_rewrite(lines, mapping, body_text)
    out, seen = [], False
    for l in lines:
        if l.startswith('// Code origin:') and not seen:
            l = l.rstrip() + note
            seen = True
        out.append(l)
    if not seen:
        pos = next((i + 1 for i, l in enumerate(out) if l.startswith('// Source exposure')), 0)
        out.insert(pos, '// Code origin:' + note)
    return out, standins


def relabel_body(text, mapping, drop_hex=None):
    """Kept source with renamed names; label lines inside it follow the renames (renamed means GUESS(low) STANDIN)."""
    out = []
    for line in text.split('\n'):
        m = LABEL_LINE.match(line.strip())
        if m:
            names = [n.strip() for n in m.group('names').split(',')]
            moved = [S.rename_identifiers(n, mapping) for n in names]
            if moved != names:
                line = '// ' + ', '.join(moved) + ': GUESS(low) STANDIN'
        else:
            line = S.rename_identifiers(line, mapping)
        out.append(line)
    return '\n'.join(out)


def counted(lines):
    return [l for l in lines if l.strip() and l.strip() != '//' and not LABEL_WORD.search(l)
            and 'Sibling source:' not in l and not S.HEADER_LINE.match(l.strip()) and not CI_HASH.match(l.strip())
            and 'SPDX-License-Identifier' not in l]


# ------------------------------------------------------------------ renaming

def standin_externs(ex, segs):
    """Names of the stand-in declarations the exemplar .cpp makes itself (externs, prototypes)."""
    names = []
    for s in segs:
        if s.kind not in ('decl', 'proto') or not s.name:
            continue
        flat = re.sub(r'\s+', ' ', S.mask_text(s.text))
        if flat.lstrip().startswith(('using', 'typedef', 'static_assert', 'static', 'constexpr', 'const ')):
            continue
        if '=' in flat.split('(')[0] and 'extern' not in flat:
            continue
        names.append(s.name)
    return names


def twin_stem(ex, rva):
    h = ex.hex
    stem = ex.stem
    if h in Path(stem).name:
        return stem.replace(h, '%x' % rva)
    return (Path(stem).parent / ('%s_%x' % (Path(stem).name, rva))).as_posix()


def is_stamped(ex):
    return bool(ex.owner) and ex.hex in ex.owner or (not ex.owner and ex.hex in ex.name)


def build(root, ex, rva, note=None):
    """The twin unit of `ex` at `rva`; raises Unsupported when the shape is not handled."""
    root = Path(root)
    cpp_head, cpp_body = S.split_header(ex.cpp)
    pre = preprocessor_lines(cpp_body)
    check_preprocessor(pre)
    segs = S.segments(cpp_body)
    keep, _needed = keep_segments(ex, segs)
    for s in keep:
        if s.kind == 'function' and s.name == ex.name and not s.lead.strip():
            s.lead = '// guess: same compiled code as matched 0x%x apart from relocated fields; its role here is not established.' % ex.rva
    new_hex = '%x' % rva
    unit_dir = Path(ex.stem).parent
    mode = 'stamped' if is_stamped(ex) else 'standin'
    stem = twin_stem(ex, rva) if mode == 'stamped' else (unit_dir / ('Owner%s' % new_hex)).as_posix()
    twin = Twin(rva, ex.rva, stem, mode)
    note = note or ' Stamped as a twin of matched 0x%x (%s): source copied, names replaced by placeholders.' % (ex.rva, ex.stem)
    kept_text = S.render(keep)
    if mode == 'stamped':
        mapping = {}
        sub = lambda t: t.replace(ex.hex, new_hex)
        files_h = None
        if ex.header_path:
            hh, hb = S.split_header(ex.header)
            hpre = preprocessor_lines(hb)
            check_preprocessor(hpre)
            hsegs = S.segments(hb)
            roots = set(S.IDENT.findall(S.mask_text(kept_text))) - S.KEYWORDS
            hkeep = reachable(hsegs, roots)
            if not hkeep:
                raise Unsupported('no-declarations-reached')
            h_text = S.render(hkeep)
            hc, hs = build_header_comment(ex, hh, {}, twin, h_text, note)
            hc = [sub(l) if 'Stamped as a twin of' not in l else sub(l.split(' Stamped as a twin of')[0]) + ' Stamped as a twin of' + l.split(' Stamped as a twin of')[1] for l in hc]
            if len(counted(hc)) > HEADER_LIMIT:
                raise Unsupported('header-budget')
            body = '\n'.join(l for l in hpre if l.startswith('#pragma') or l.startswith('#include')) + '\n\n' + sub(h_text) + '\n'
            files_h = '\n'.join(hc) + '\n' + body
            new_h_path = (Path(ex.header_path).parent / (Path(stem).name + '.h')).as_posix()
            twin.files[new_h_path] = files_h
            inc_map = {Path(ex.header_path).name: Path(new_h_path).name}
        else:
            inc_map = {}
        cpp_lines = []
        for l in pre:
            m = re.match(r'#\s*include\s+"([^"]+)"', l)
            if m and Path(m.group(1)).name in inc_map:
                l = '#include "%s"' % inc_map[Path(m.group(1)).name]
            cpp_lines.append(sub(l))
        cc, _ = build_header_comment(ex, cpp_head, {}, twin, kept_text, note)
        cc = [sub(l) if 'Stamped as a twin of' not in l else sub(l.split(' Stamped as a twin of')[0]) + ' Stamped as a twin of' + l.split(' Stamped as a twin of')[1] for l in cc]
        name = sub(ex.name)
        cc.append('// 0x%x %s' % (rva, name))
        if ex.deleting_symbol or ex.ci_hash:
            cc.append('// CI hash: 0x%x %s' % (rva, sub(ex.deleting_symbol or ex.ci_hash)))
        if len(counted(cc)) > HEADER_LIMIT:
            raise Unsupported('header-budget')
        twin.name = name
        twin.files[stem + '.cpp'] = '\n'.join(cc) + '\n' + '\n'.join(cpp_lines) + '\n\n' + sub(kept_text) + '\n'
        twin.files = strip_foreign_claims(twin.files, rva)
        return twin
    return build_standin(root, ex, twin, keep, kept_text, pre, cpp_head, note)


def owner_class_segment(root, ex):
    """(header path, [segments of the owner class and its size checks]) searched through the includes."""
    root = Path(root)
    owner = S.simple_name(ex.owner)
    seen, queue = set(), []
    unit_dir = Path(ex.stem).parent.as_posix()
    for inc in INCLUDE.findall(ex.cpp):
        rel = resolve_include(root, unit_dir, inc)
        if rel:
            queue.append(rel)
    while queue:
        rel = queue.pop(0)
        if rel in seen:
            continue
        seen.add(rel)
        text = (root / 'reconstruction' / rel).read_text()
        _, body = S.split_header(text)
        segs = S.segments(body)
        defs = [s for s in segs if s.kind == 'class' and s.name == owner and '{' in s.text]
        if defs:
            checks = [s for s in segs if s.text.lstrip().startswith('static_assert') and owner in s.mentions]
            return rel, defs[0], checks
        for inc in INCLUDE.findall(text):
            sub = resolve_include(root, Path(rel).parent.as_posix(), inc)
            if sub:
                queue.append(sub)
    return None, None, []


def build_standin(root, ex, twin, keep, kept_text, pre, cpp_head, note):
    rva, new_hex = twin.rva, '%x' % twin.rva
    owner = S.simple_name(ex.owner)
    if not ex.owner:
        raise Unsupported('free-function-exemplar-not-stamped')
    if '<' in ex.owner or '::' in ex.owner:
        raise Unsupported('nested-or-template-owner')
    hpath, cls, checks = owner_class_segment(root, ex)
    if cls is None:
        raise Unsupported('owner-declaration-not-found')
    new_owner = 'Owner' + new_hex
    mapping = {owner: new_owner}
    method = ex.method
    plain = (not ex.deleting_symbol and bool(S.IDENT.fullmatch(method)) and not SPECIAL_METHOD.match(method)
             and method != owner and method.lower() not in ('dtor', 'destructor', 'ctor', 'constructor'))
    # keep the method's name when it is virtual or overrides: renaming would make a new virtual
    if plain and re.search(r'\bvirtual\b[^;{}]*\b%s\s*\(|\b%s\s*\([^;{}]*\)[^;{}]*\boverride\b' % (re.escape(method), re.escape(method)), S.mask_text(cls.text)):
        plain = False
    segs = S.segments(S.split_header(ex.cpp)[1])
    externs = standin_externs(ex, [s for s in keep if s.kind in ('decl', 'proto')])
    for n in externs:
        if n not in mapping and n not in (owner, method):
            mapping[n] = '%s_%s' % (n, new_hex)

    def rename(text, in_class=False):
        text = S.rename_identifiers(text, mapping)
        if plain:
            if in_class:
                text = re.sub(r'(?<![\w.>:~])%s(?=\s*\()' % re.escape(method), 'Function' + new_hex, text)
            else:
                text = re.sub(r'(?<![\w])%s\s*::\s*%s(?![\w])' % (re.escape(new_owner), re.escape(method)),
                              '%s::Function%s' % (new_owner, new_hex), text)
        return text

    cls_text = rename(S.render([cls]), in_class=True)
    chk_text = [rename(S.render([c])) for c in checks]
    stem = twin.stem
    h_name = Path(stem).name + '.h'
    note_text = note
    # the twin header: labels, include of the exemplar's header, the stand-in owner
    hh, _ = S.split_header((Path(root) / 'reconstruction' / hpath).read_text())
    body_for_labels = cls_text + '\n' + '\n'.join(chk_text)
    hc, standins = build_header_comment(ex, [l for l in hh if l.strip()], mapping, twin, body_for_labels, note_text)
    names = sorted({new_owner} | ({'Function' + new_hex} if plain else set()) | {v for k, v in mapping.items() if k in externs})
    hc = [l for l in hc if not l.startswith('// Source exposure')] if False else hc
    hc.append('// %s: GUESS(low) STANDIN' % ', '.join(names[:1] + [n for n in names[1:] if n not in externs and not n.startswith('g_')]))
    if len(counted(hc)) > HEADER_LIMIT:
        raise Unsupported('header-budget')
    incs = ['#pragma once', '#include "%s"' % Path(hpath).name if Path(hpath).parent == Path(twin.stem).parent else '#include "%s"' % hpath]
    for l in pre:
        if l.startswith('#include <'):
            incs.append(l)
    h_text = '\n'.join(hc) + '\n' + '\n'.join(dict.fromkeys(incs)) + '\n\n' + cls_text + '\n' + '\n'.join(chk_text) + '\n'
    twin.files[stem + '.h'] = h_text
    cc, _ = build_header_comment(ex, cpp_head, mapping, twin, kept_text, note_text)
    if plain:
        new_method = 'Function' + new_hex
    elif method in (owner, '~' + owner):
        new_method = method.replace(owner, new_owner)
    elif method.lower() in ('dtor', 'destructor'):
        new_method = '~' + new_owner
    elif method.lower() in ('ctor', 'constructor'):
        new_method = new_owner
    else:
        new_method = method
    name = '%s::%s' % (new_owner, new_method)
    cc.append('// 0x%x %s' % (rva, name))
    if ex.deleting_symbol:
        if not ex.deleting_symbol.startswith('??_G' + owner + '@@'):
            raise Unsupported('deleting-symbol-owner')
        cc.append('// CI hash: 0x%x %s' % (rva, '??_G' + new_owner + ex.deleting_symbol[4 + len(owner):]))
    elif ex.ci_hash:
        cc.append('// CI hash: 0x%x %s' % (rva, ex.ci_hash.replace(ex.hex, new_hex)))
    cpp_lines = ['#include "%s"' % h_name]
    for l in pre:
        m = re.match(r'#\s*include\s+"([^"]+)"', l)
        if m and Path(m.group(1)).name in (Path(hpath).name, Path(ex.header_path or '').name):
            continue
        cpp_lines.append(l)
    body = relabel_body(kept_text, mapping)
    if plain:
        body = rename(body)
    twin.name = name
    twin.files[stem + '.cpp'] = '\n'.join(cc) + '\n' + '\n'.join(dict.fromkeys(cpp_lines)) + '\n\n' + body + '\n'
    twin.files = sanitize_labels(twin.files, new_owner, cls_text)
    twin.files = strip_foreign_claims(twin.files, rva)
    twin.notes.append('owner header %s' % hpath)
    return twin


def apply_constants(twin, imap):
    """Loose twin: change the integer literals of the twin's own function per `imap` {ev: (tv, width)}.

    Raises Unsupported when a changed value is not spelled as a literal of that function."""
    import twin_subst as subst
    path = twin.stem + '.cpp'
    text = twin.files[path]
    head, body = S.split_header(text)
    segs = [s for s in S.segments(body) if s.kind == 'function' and (s.name == twin.name or S.simple_name(s.name) == S.simple_name(twin.name))]
    if not segs:
        raise Unsupported('definition-not-found')
    seg = segs[-1]
    new, count, missing = subst.substitute_literals(seg.text, imap)
    edits = subst.named_constants(body, seg, {v: imap[v] for v in missing}) if missing else []
    if edits is None or not (count or edits):
        raise Unsupported('constant-not-literal')
    edits.append((seg.start, seg.end, new))
    for start, end, replacement in sorted(edits, reverse=True):
        body = body[:start] + replacement + body[end:]
    note = 'Constants differ from the exemplar: loose twin (same code shape).'
    twin.files[path] = '\n'.join(head) + '\n' + body
    twin.notes.append(note)
    return twin


def apply_layout(twin, moves, *, headers=()):
    """Loose twin: re-lay out the stand-in owner so members sit at the twin's displacements."""
    import twin_layout as layout
    if twin.mode != 'standin':
        raise Unsupported('layout-of-stamped-unit')
    path = twin.stem + '.h'
    text = twin.files[path]
    head, body = S.split_header(text)
    segs = S.segments(body)
    owner = S.simple_name(twin.name.split('::')[0])
    cls = [s for s in segs if s.kind == 'class' and s.name == owner and '{' in s.text]
    if not cls:
        raise Unsupported('owner-not-in-header')
    checks = [s for s in segs if s.text.lstrip().startswith('static_assert') and owner in s.mentions]
    new_cls, delta, new_checks = layout.relocate(cls[0].text, moves, [c.text for c in checks], headers=headers)
    pieces = [(cls[0], new_cls)] + list(zip(checks, new_checks))
    for seg, new in sorted(pieces, key=lambda p: -p[0].start):
        body = body[:seg.start] + new + body[seg.end:]
    twin.files[path] = '\n'.join(head) + '\n' + body
    twin.notes.append('layout moved: %+d bytes' % delta)
    return twin


def mark_loose(twin, what):
    """Say in the cpp's `Code origin:` line that the twin differs from its exemplar in `what`."""
    path = twin.stem + '.cpp'
    lines = twin.files[path].split('\n')
    for i, line in enumerate(lines):
        if line.startswith('// Code origin:'):
            lines[i] = line.rstrip() + ' Loose twin: %s differ from the exemplar and follow this function\'s code.' % what
            break
    twin.files[path] = '\n'.join(lines)


def declared_in(cls_text, name):
    """Whether `name` is declared (method or member) in the class text."""
    return bool(re.search(r'(?<![\w:.>])%s\s*(?:\(|;|\[|=|\{)' % re.escape(name), S.mask_text(cls_text)))


def sanitize_labels(files, new_owner, cls_text):
    """Names of the cloned owner stand-in are GUESS(low) STANDIN, not the community names they were copied from.

    A label line that names something declared in the stand-in class (or qualified by it) moves to a STANDIN
    line; one that names a name no longer in the file is dropped."""
    out = {}
    for path, text in files.items():
        lines = text.split('\n')
        body = '\n'.join(l for l in lines if not LABEL_LINE.match(l.strip()))
        moved, new = [], []
        for line in lines:
            m = LABEL_LINE.match(line.strip())
            if not m or 'STANDIN' in m.group('labels') and 'GUESS' in m.group('labels') and 'COMMUNITY' not in m.group('labels'):
                new.append(line)
                continue
            keep = []
            for n in [x.strip() for x in m.group('names').split(',')]:
                last = n.split('::')[-1]
                if n.startswith(new_owner + '::') or last == new_owner or (cls_text and declared_in(cls_text, last) and n.split('::')[0] in (new_owner, last)):
                    moved.append(n)
                elif re.search(r'(?<![A-Za-z0-9_])' + re.escape(last) + r'(?![A-Za-z0-9_])', body):
                    keep.append(n)
            if keep:
                new.append('// ' + ', '.join(keep) + ': ' + m.group('labels'))
        if moved:
            at = next((i for i, l in enumerate(new) if not l.startswith('//')), len(new))
            new.insert(at, '// %s: GUESS(low) STANDIN' % ', '.join(dict.fromkeys(moved)))
        out[path] = '\n'.join(new)
    return out


def strip_foreign_claims(files, rva):
    """Drop comments that claim another RVA (the exemplar's other compared functions) from the twin's files."""
    out = {}
    for path, text in files.items():
        lines = []
        for line in text.split('\n'):
            foreign = rva_headers.claimed_rvas([line]) - {rva}
            if foreign and '//' in line:
                code = line.split('//', 1)[0].rstrip()
                if not code:
                    continue
                line = code
            lines.append(line)
        text = '\n'.join(lines)
        text = re.sub(r'[ \t]*//[ \t]*compared:?[ \t]*0x([0-9a-fA-F]+)[^\n]*',
                      lambda m: m.group(0) if int(m.group(1), 16) == rva else '', text)
        out[path] = text
    return out
