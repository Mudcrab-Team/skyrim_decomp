#!/usr/bin/env python3
"""Stand-in classes for sibling transplants whose only difference from the target is layout.

A sibling function that compiles to the same code as a Skyrim function except for member
offsets or virtual-call slots is transplanted with its own unit header declaring the classes
it touches as stand-ins: the members the function uses sit at the offsets the target's code
uses, the gaps are anonymous padding and the virtual functions it calls sit at the target's
slot numbers, with placeholders for the rest. The offsets come from the advisory layout facts
(sibling x64 offset -> target offset, one per differing instruction); the sibling class is
only used to name the member that a fact refers to, and its own computed layout must agree
with the fact before the member is trusted. Nothing here edits a shared header.
"""
import json
import os
import re

IDENT = r'[A-Za-z_]\w*'
BUILTIN = {'char': 1, 'signed char': 1, 'unsigned char': 1, 'bool': 1, 'short': 2, 'unsigned short': 2, 'short int': 2,
           'wchar_t': 2, 'int': 4, 'unsigned': 4, 'unsigned int': 4, 'signed': 4, 'long': 4, 'unsigned long': 4, 'float': 4,
           'long long': 8, 'unsigned long long': 8, '__int64': 8, 'unsigned __int64': 8, 'double': 8, 'size_t': 8,
           'uint8_t': 1, 'int8_t': 1, 'uint16_t': 2, 'int16_t': 2, 'uint32_t': 4, 'int32_t': 4, 'uint64_t': 8, 'int64_t': 8,
           'ptrdiff_t': 8, 'intptr_t': 8, 'uintptr_t': 8}
QUALIFIERS = re.compile(r'\b(?:const|volatile|mutable|struct|class|enum|register)\b')
NOT_MEMBER = ('typedef', 'using', 'friend', 'template', 'static', 'struct', 'class', 'union', 'enum', 'extern', 'public', 'private', 'protected')


def strip_comments(text):
    return re.sub(r'//[^\n]*|/\*.*?\*/', '', text, flags=re.S)


def match_close(text, open_at):
    depth = 0
    for i in range(open_at, len(text)):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return i
    return None


class Cls:
    def __init__(self, kw, name, head, body, start, end):
        self.kw, self.name, self.head, self.start, self.end = kw, name, head, start, end
        self.bases, self.members, self.methods, self.bad = [], [], [], None
        self._parse_head(head)
        self._parse_body(body)

    def _parse_head(self, head):
        if not head:
            return
        for b in re.split(r',(?![^<]*>)', head):
            toks = [t for t in b.split() if t not in ('public', 'private', 'protected')]
            if 'virtual' in toks:
                self.bad = 'virtual base'
            self.bases.append(' '.join(t for t in toks if t != 'virtual'))

    def _parse_body(self, body):
        body = strip_comments(body)
        decls, cur, depth, i = [], [], 0, 0
        while i < len(body):
            ch = body[i]
            if ch == '{':
                text = ''.join(cur).strip()
                if re.match(r'(?:struct|class|union|enum)\b', text) or '=' in text.split('(')[0] or '(' not in text:
                    self.bad = self.bad or 'nested type or braced initializer'
                    cur.append(ch)
                    depth += 1
                    i += 1
                    continue
                j = match_close(body, i)
                if j is None:
                    self.bad = 'unbalanced'
                    break
                decls.append((text, True))
                cur, i = [], j + 1
                if i < len(body) and body[i] == ';':
                    i += 1
                continue
            if ch == '}':
                depth -= 1
            if ch == ';' and depth <= 0:
                decls.append((''.join(cur).strip(), False))
                cur, depth = [], 0
            else:
                cur.append(ch)
            i += 1
        for text, has_body in decls:
            text = re.sub(r'^\s*(?:public|private|protected)\s*:', '', text).strip()
            text = re.sub(r'^(?:public|private|protected)\s*:', '', text).strip()
            if not text:
                continue
            self._declaration(text, has_body)

    def _declaration(self, text, has_body):
        first = text.split()[0] if text.split() else ''
        if first in ('typedef', 'using', 'friend', 'template', 'enum', 'extern', 'union'):
            return
        if first in ('struct', 'class'):
            self.bad = self.bad or 'nested type'
            return
        if first == 'static':
            return
        if ':' in re.sub(r'::', '', text.split('(')[0]) and '(' not in text:
            self.bad = self.bad or 'bit field'
            return
        fp = re.search(rf'\(\s*\*\s*({IDENT})\s*\)\s*\(', text)
        if fp:
            self.members.append(('void*', f'(*{fp.group(1)})', fp.group(1), text))
            return
        if '(' in text:
            head = text.split('(')[0]
            name = re.search(rf'(~?{IDENT}|operator\s*\S+)\s*$', head)
            if not name:
                return
            self.methods.append(dict(name=name.group(1), virtual=bool(re.search(r'\bvirtual\b', head)), text=text, has_body=has_body))
            return
        self._data_member(text)

    def _data_member(self, text):
        text = re.sub(r'\s*=\s*[^,]*', '', text) if '=' in text else text
        parts = re.split(r',(?![^<]*>)', text)
        m = re.match(rf'^(.*?)([*&\s]*)({IDENT})\s*((?:\[[^\]]*\])*)\s*$', parts[0].strip())
        if not m or not m.group(1).strip():
            self.bad = self.bad or 'unparsed member'
            return
        typ = m.group(1).strip()
        self.members.append((typ, m.group(2).replace(' ', '') + m.group(3) + m.group(4), m.group(3), parts[0]))
        for p in parts[1:]:
            m2 = re.match(rf'^\s*([*&]*)\s*({IDENT})\s*((?:\[[^\]]*\])*)\s*$', p)
            if not m2:
                self.bad = self.bad or 'unparsed member'
                return
            self.members.append((typ, m2.group(1) + m2.group(2) + m2.group(3), m2.group(2), p))


def parse_classes(text):
    out = {}
    taken = []
    for m in re.finditer(rf'(?m)^[ \t]*(class|struct)\s+({IDENT})\s*(?::\s*([^{{;]*?))?\s*\{{', text):
        if any(a <= m.start() < b for a, b in taken):
            continue
        close = match_close(text, m.end() - 1)
        if close is None:
            continue
        end = close + 1
        while end < len(text) and text[end] in ' \t':
            end += 1
        if end < len(text) and text[end] == ';':
            end += 1
        taken.append((m.start(), end))
        out[m.group(2)] = Cls(m.group(1), m.group(2), m.group(3), text[m.end():close], m.start(), end)
    return out


_COMMUNITY = {}


def community_sizes():
    """{type name: size} from SIBLING_COMMUNITY_SIZES ({name: {library: size}}), where every library that
    states a size for the name states the same one."""
    path = os.environ.get('SIBLING_COMMUNITY_SIZES')
    if not path:
        return {}
    if path not in _COMMUNITY:
        data = json.load(open(path))
        _COMMUNITY[path] = {n: next(iter(v.values())) for n, v in data.items() if len(set(v.values())) == 1 and next(iter(v.values())) > 0}
    return _COMMUNITY[path]


class Layout:
    def __init__(self):
        self.offsets, self.sizes, self.size, self.align = {}, {}, None, 1
        self.poly, self.slots, self.nslots, self.base = False, {}, 0, None


class Engine:
    """The part of the MSVC x64 layout rules these classes need; anything else is 'unknown' and
    a member after it gets no offset (the caller then refuses the unit)."""

    def __init__(self, classes, text):
        self.classes = classes
        self.memo = {}
        self.typedefs = {}
        for m in re.finditer(rf'typedef\s+([^;{{}}()]+?)\s+({IDENT})\s*;', text):
            self.typedefs[m.group(2)] = m.group(1)
        self.enums = set(re.findall(rf'\benum\s+(?:class\s+)?({IDENT})', text))
        self.community = community_sizes()

    def type_info(self, typ, decl, depth=0):
        if decl.startswith(('*', '&', '(*')):
            return 8, 8
        count = 1
        for dim in re.findall(r'\[([^\]]*)\]', decl):
            if not dim.strip().isdigit():
                return None
            count *= int(dim)
        t = ' '.join(QUALIFIERS.sub(' ', typ).split())
        if t.endswith(('*', '&')):
            info = (8, 8)
        elif t in BUILTIN:
            info = (BUILTIN[t], BUILTIN[t])
        elif t in self.enums:
            info = (4, 4)
        elif t in self.typedefs and depth < 6:
            info = self.type_info(self.typedefs[t], '', depth + 1)
        elif t in self.classes:
            lay = self.layout(t)
            info = (lay.size, lay.align) if lay and lay.size is not None else None
        elif t in self.community:
            # a type the sibling text never defines: its size from the community library's static
            # asserts. Only a guess at the sibling's own size; the offset check against the target
            # facts in resolve() decides whether it is trusted.
            size = self.community[t]
            info = (size, min(8, size & -size))
        else:
            info = None
        return (info[0] * count, info[1]) if info else None

    def layout(self, name):
        if name in self.memo:
            return self.memo[name]
        self.memo[name] = None
        c = self.classes.get(name)
        if c is None or c.bad:
            return None
        lay = Layout()
        own_virtuals = [m for m in c.methods if m['virtual']]
        base = None
        if c.bases:
            if len(c.bases) > 1:
                return None
            base = self.layout(c.bases[0])
            if base is None or base.size is None:
                return None
        lay.base = base
        cur = 0
        lay.poly = bool(own_virtuals) or bool(base and base.poly)
        if base:
            lay.slots, lay.nslots = dict(base.slots), base.nslots
            if base.poly or not lay.poly:
                cur = base.size if (base.size > 1 or base.poly or base.offsets) else 0
            else:
                cur = 8 + base.size
            lay.align = max(lay.align, base.align)
        elif lay.poly:
            cur = 8
        if lay.poly:
            lay.align = max(lay.align, 8)
        for m in own_virtuals:
            if m['name'] not in lay.slots:
                lay.slots[m['name']] = lay.nslots
                lay.nslots += 1
        complete = True
        for typ, decl, nm, _ in c.members:
            info = self.type_info(typ, decl)
            if info is None:
                complete = False
                break
            sz, al = info
            cur = (cur + al - 1) // al * al
            lay.offsets[nm], lay.sizes[nm] = cur, sz
            cur += sz
            lay.align = max(lay.align, al)
        if complete:
            lay.size = max((cur + lay.align - 1) // lay.align * lay.align, 1)
        self.memo[name] = lay
        return lay


def hexval(s):
    return int(s, 16) if s.startswith('0x') else None


def chain(classes, name):
    """name and its bases, derived first; None for an unknown or unsupported base."""
    out = []
    while name is not None:
        c = classes.get(name)
        if c is None or c.bad or len(c.bases) > 1:
            return None
        out.append(name)
        name = c.bases[0] if c.bases else None
    return out


def resolve(engine, classes, facts, body):
    """(members {(class, member): (sibling offset, target offset)}, slots {(class, method):
    (sibling slot, target slot)}) or a reason string."""
    members, slots, literals = {}, {}, {}
    for f in facts:
        if f['kind'] == 'member-offset':
            pat = re.search(r'\[\s*(\w+)\s*\+\s*#\s*\]', f['instruction_pattern'])
            if not pat:
                continue  # a scale factor or an index, not a field offset
            if pat.group(1) in ('rsp', 'rbp'):
                return 'stack frame offset differs (local variable layout)'
            sib, sky = hexval(f['sibling_x64']), hexval(f['skyrim'])
            if sib is None or sky is None or sib == sky:
                continue
            found = set()
            # the listing's source line is sometimes the neighbouring statement, so the whole body is the fallback
            for idents in (set(re.findall(IDENT, f.get('source_line') or '')), set(re.findall(IDENT, body))):
                for cname, c in classes.items():
                    lay = engine.layout(cname)
                    if lay is None:
                        continue
                    for nm, off in lay.offsets.items():
                        if nm in idents and off == sib:
                            found.add((cname, nm))
                if found:
                    break
            if not found:
                lit = literal_offset(f, sib, sky)
                if lit:
                    literals.setdefault((f['source_line'].strip(), sib), sky)
                    continue
                return 'member fact not matched to a member of the sibling classes'
            found = {(c, n) for c, n in found if not any(o != c and (o, n) in found and c in (chain(classes, o) or []) for o in classes)}
            if len(found) > 1:
                return 'member fact matches more than one member'
            key = next(iter(found))
            if members.get(key, (sib, sky)) != (sib, sky):
                return 'one member with two different target offsets'
            members[key] = (sib, sky)
        elif f['kind'] == 'vtable-slot':
            sib, sky = hexval(f['sibling_x64']), hexval(f['skyrim'])
            if sib is None or sky is None or sib == sky or sib % 8 or sky % 8:
                continue
            called = set(re.findall(rf'({IDENT})\s*\(', f.get('source_line') or ''))
            found = set()
            for cname in classes:
                lay = engine.layout(cname)
                if lay is None:
                    continue
                for nm, slot in lay.slots.items():
                    if nm in called and slot * 8 == sib:
                        found.add((cname, nm))
            if not found:
                # a call through a function-pointer member sits at a member offset, not in a vtable
                for idents in (set(re.findall(IDENT, f.get('source_line') or '')), set(re.findall(IDENT, body))):
                    for cname in classes:
                        lay = engine.layout(cname)
                        for nm, off in (lay.offsets.items() if lay else ()):
                            if nm in idents and off == sib:
                                found.add((cname, nm))
                    if found:
                        break
                if len(found) == 1:
                    key = next(iter(found))
                    members[key] = (sib, sky)
                    continue
                if found:
                    return 'slot fact matches more than one member'
                if literal_offset(f, sib, sky):
                    literals.setdefault((f['source_line'].strip(), sib), sky)
                    continue
                return 'slot fact not matched to a virtual of the sibling classes'
            owners = {c: chain(classes, c) or [c] for c, _ in found}
            # the class that declares the virtual (the one nearest the root of the matches)
            decl = {(c, n) for c, n in found if not any(o != c and (o, n) in found and o in owners[c] for o in owners)}
            if len(decl) > 1:
                return 'slot fact matches more than one virtual'
            key = next(iter(decl))
            if slots.get(key, (sib // 8, sky // 8)) != (sib // 8, sky // 8):
                return 'one virtual with two different target slots'
            slots[key] = (sib // 8, sky // 8)
    return members, slots, literals


def literal_offset(f, sib, sky):
    """True when the fact's source line spells the sibling offset as a number (pointer arithmetic)."""
    line = f.get('source_line') or ''
    return bool(re.search(rf'\+\s*(?:0x{sib:x}|{sib})\b', line, re.I))


def emit_class(c, engine, classes, members, slots, body_idents, method_name):
    """Text of the stand-in for class `c` (a Cls) or a reason string, plus its placeholder names."""
    lay = engine.layout(c.name)
    if lay is None:
        return 'class layout not computable', []
    base = lay.base
    start = 0
    if base is not None:
        start = base.size if base.size else 0
    placed = {}  # name -> (offset, typ, decl)
    original = {m[2]: m[3].strip() for m in c.members}
    for typ, decl, nm, _ in c.members:
        target = members.get((c.name, nm))
        if target is not None:
            placed[nm] = (target[1], typ, decl)
        elif nm in body_idents:
            if nm not in lay.offsets:
                return f'referenced member {nm} has no computed offset', []
            placed[nm] = (lay.offsets[nm], typ, decl)
    # virtual slots: facts first, then the virtuals the body names, then the compiled method itself
    virt = {}
    for (cn, nm), (_sib, sky) in slots.items():
        if cn == c.name:
            virt[sky] = nm
    for m in c.methods:
        if m['virtual'] and (m['name'] in body_idents or m['name'] == method_name) and (c.name, m['name']) not in slots:
            slot = lay.slots.get(m['name'])
            if slot is not None:
                if virt.get(slot, m['name']) != m['name']:
                    return 'two virtuals on one slot', []
                virt[slot] = m['name']
    base_slots = base.nslots if base else 0
    if base is None and virt:
        base_slots = 0
    if virt and min(virt) < base_slots:
        return 'target slot lies inside the base class virtuals', []
    names = []
    lines = []
    texts = {m['name']: m for m in c.methods if m['virtual']}
    top = max(virt) if virt else None
    own_poly = lay.poly and (base is None or not base.poly)
    if own_poly and top is None:
        top = 0
    if top is not None:
        for s in range(base_slots, top + 1):
            nm = virt.get(s)
            if nm is None:
                nm = f'vslot_{s}_'
                names.append(nm)
                lines.append(f'    virtual void {nm}();')
            else:
                lines.append('    ' + declaration_only(texts[nm]['text']) + ';' if nm in texts else f'    virtual void {nm}();')
    # the polymorphic stand-in reaches the vptr automatically; members follow at their offsets
    cur = 8 if (top is not None and base is None) else start
    for nm, (off, typ, decl) in sorted(placed.items(), key=lambda kv: kv[1][0]):
        info = engine.type_info(typ, decl)
        if off < cur:
            return f'member {nm} at {off:#x} overlaps the previous member or base ({cur:#x})', []
        if info is None:
            return f'member {nm} has an unknown size', []
        al = info[1]
        if off % al:
            return f'member {nm} at {off:#x} is not aligned', []
        gap = off - cur
        if gap:
            gname = f'padding_{cur:x}_'
            names.append(gname)
            lines.append(f'    char {gname}[{gap}];')
        lines.append(f'    {original[nm]};' if decl.startswith('(*') else f'    {typ} {decl};')
        cur = off + info[0]
    for m in c.methods:
        if not m['virtual']:
            lines.append('    ' + declaration_only(m['text']) + ';')
    clause = f' : {", ".join(c.bases)}' if c.bases else ''
    kw = c.kw
    out = [f'// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.',
           f'{kw} {c.name}{clause}', '{', '  public:'] + lines + ['};']
    return '\n'.join(out), names


def declaration_only(text):
    """A method declaration without its body or constructor initialisers."""
    depth, end = 0, None
    for i, ch in enumerate(text):
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
            if depth == 0 and end is None:
                end = i + 1
    if end is None:
        return text
    tail = re.findall(r'\b(?:const|volatile|noexcept|override)\b|=\s*0', text[end:].split('{')[0].split(':')[0])
    return (text[:end] + (' ' + ' '.join(tail) if tail else '')).strip()


def apply_layout(u, facts, method_name=None):
    """Replace the classes of u['header_decl'] that carry facts (and their bases) by stand-ins.
    Returns None on success or a reason string; adds the GUESS labels for the placeholders."""
    text = u['header_decl']
    classes = parse_classes(text)
    engine = Engine(classes, text)
    res = resolve(engine, classes, [f for f in facts if f['kind'] in ('member-offset', 'vtable-slot')], u['cpp_body'])
    if isinstance(res, str):
        return res
    members, slots, literals = res
    if not members and not slots and not literals:
        return 'no usable layout fact'
    if literals:
        body = u['cpp_body']
        lines = body.split('\n')
        for (src, sib), sky in literals.items():
            want = ' '.join(src.split())
            for i, l in enumerate(lines):
                if ' '.join(l.split()) == want:
                    lines[i] = re.sub(rf'(\+\s*)(?:0x{sib:x}|{sib})\b', lambda m: m.group(1) + f'{sky:#x}', l, flags=re.I)
        u['cpp_body'] = '\n'.join(lines)
        u['literal_offsets'] = len(literals)
    touched = set()
    for cn, _ in list(members) + list(slots):
        ch = chain(classes, cn)
        if ch is None:
            return 'class chain not supported'
        touched.update(ch)
    body_idents = set(re.findall(IDENT, strip_comments(u['cpp_body'])))
    pieces, placeholders = [], []
    for name in sorted(touched, key=lambda n: -classes[n].start):
        c = classes[name]
        out, names = emit_class(c, engine, classes, members, slots, body_idents, method_name)
        if not out.startswith(('//', 'class ', 'struct ')):
            return out
        pieces.append((c.start, c.end, out))
        placeholders += names
    for start, end, out in pieces:
        text = text[:start] + out + text[end:]
    # self-check: the stand-ins must put every fact member at its target offset
    classes2 = parse_classes(text)
    engine2 = Engine(classes2, text)
    for (cn, nm), (_sib, sky) in members.items():
        lay = engine2.layout(cn)
        if lay is None or lay.offsets.get(nm) != sky:
            return f'stand-in does not place {cn}::{nm} at {sky:#x}'
    for (cn, nm), (_sib, sky) in slots.items():
        lay = engine2.layout(cn)
        if lay is None or lay.slots.get(nm) != sky:
            return f'stand-in does not place {cn}::{nm} on slot {sky}'
    u['header_decl'] = text
    if placeholders:
        u['labels'] = u['labels'] + [(placeholders, 'GUESS')]
    u['layout'] = True
    return None
