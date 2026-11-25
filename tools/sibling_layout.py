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
WIDTH_TYPES = {'byte': 'unsigned char', 'word': 'unsigned short', 'dword': 'unsigned int', 'qword': 'unsigned __int64'}
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
                decls.append((text, body[i:j + 1]))
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
            self.methods.append(dict(name=name.group(1), virtual=bool(re.search(r'\bvirtual\b', head)), text=text, has_body=bool(has_body),
                                     body=has_body or ''))
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
        with open(path, encoding='utf-8') as handle:
            data = json.load(handle)
        _COMMUNITY[path] = {n: next(iter(v.values())) for n, v in data.items() if len(set(v.values())) == 1 and next(iter(v.values())) > 0}
    return _COMMUNITY[path]


class Layout:
    def __init__(self):
        self.offsets, self.sizes, self.size, self.align = {}, {}, None, 1
        self.poly, self.slots, self.nslots, self.base = False, {}, 0, None


class Engine:
    """The part of the MSVC x64 layout rules these classes need; anything else is 'unknown' and
    a member after it gets no offset (the caller then refuses the unit)."""

    def __init__(self, classes, text, *, enum_types=None, use_community_sizes=True, multiple_bases=False):
        self.classes = classes
        self.memo = {}
        self.typedefs = {}
        for m in re.finditer(rf'typedef\s+([^;{{}}()]+?)\s+({IDENT})\s*;', text):
            self.typedefs[m.group(2)] = m.group(1)
        self.enums = ({name: 'int' for name in re.findall(rf'\benum\s+(?:class\s+)?({IDENT})', text)}
                      if enum_types is None else enum_types)
        self.community = community_sizes() if use_community_sizes else {}
        self.multiple_bases = multiple_bases

    def type_info(self, typ, decl, depth=0):
        count = 1
        for dim in re.findall(r'\[([^\]]*)\]', decl):
            dim = dim.strip().lower()
            if not re.fullmatch(r'(?:0x[0-9a-f]+|[1-9][0-9]*)', dim):
                return None
            count *= int(dim, 0)
        t = ' '.join(QUALIFIERS.sub(' ', typ).split())
        if t.startswith('std::') and t[5:] in BUILTIN:
            t = t[5:]
        if decl.startswith(('*', '&', '(*')) or t.endswith(('*', '&')):
            info = (8, 8)
        elif t in BUILTIN:
            info = (BUILTIN[t], BUILTIN[t])
        elif t in self.enums and depth < 6:
            info = self.type_info(self.enums[t], '', depth + 1)
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
        if len(c.bases) > 1 and not self.multiple_bases:
            return None
        bases = [self.layout(name) for name in c.bases]
        if any(b is None or b.size is None for b in bases):
            return None
        if len(bases) > 1:
            if any(b.size == 1 and not b.poly and not b.offsets for b in bases):
                return None  # Multiple empty bases require tracking distinct subobject addresses.
            # MSVC first lays out the primary vptr-containing base, then the others.
            primary = next((i for i, b in enumerate(bases) if b.poly), 0)
            bases.insert(0, bases.pop(primary))
        base = bases[0] if bases else None
        lay.base = base
        cur = 0
        own_virtuals += [m for m in c.methods if not m['virtual'] and m['name'].startswith('~') and base is not None and base.poly]
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
        for other in bases[1:]:
            cur = (cur + other.align - 1) // other.align * other.align + other.size
            lay.align = max(lay.align, other.align)
        for m in own_virtuals:
            if m['name'] not in lay.slots:
                inherited = next((n for n in lay.slots if n.startswith('~')), None) if m['name'].startswith('~') else None
                if inherited is not None:
                    lay.slots[m['name']] = lay.slots[inherited]
                    continue
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
    members, slots, literals, widths, sizes = {}, {}, {}, {}, []
    for f in facts:
        if f['kind'] in ('class-size', 'alloc-size'):
            sib, sky = hexval(f['sibling_x64']), hexval(f['skyrim'])
            if sib is not None and sky is not None and sib != sky:
                sizes.append((f['kind'], sib, sky, f.get('source_line') or ''))
        elif f['kind'] == 'operand-width':
            m = re.search(r'\[\s*(\w+)\s*(?:\+\s*(0x[0-9a-f]+|\d+)\s*)?\]', f['sibling_x64'])
            ptr = re.search(r'\b(byte|word|dword|qword) ptr\b', f['skyrim'])
            if not m or not ptr:
                return 'width fact is not on a member access'
            if m.group(1) in ('rsp', 'rbp'):
                return 'stack frame offset differs (local variable layout)'
            sib = int(m.group(2), 0) if m.group(2) else 0
            found = set()
            for idents in (set(re.findall(IDENT, f.get('source_line') or '')), set(re.findall(IDENT, body))):
                for cname in classes:
                    lay = engine.layout(cname)
                    for nm, off in (lay.offsets.items() if lay else ()):
                        if nm in idents and off == sib:
                            found.add((cname, nm))
                if found:
                    break
            found = {(c, n) for c, n in found if not any(o != c and (o, n) in found and c in (chain(classes, o) or []) for o in classes)}
            if len(found) != 1:
                return 'width fact not matched to one member'
            key = next(iter(found))
            new = WIDTH_TYPES[ptr.group(1)]
            if widths.get(key, new) != new:
                return 'one member with two different widths'
            widths[key] = new
        elif f['kind'] in ('member-offset', 'add-offset'):
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
            if not found and not literal_offset(f, sib, sky):
                # the computed layout can be wrong (an unknown base or member type before it), so the member the fact's own
                # source line names is taken when it is the only one; the comparator decides whether the guess was right
                named = set(re.findall(IDENT, f.get('source_line') or ''))
                loose = set()
                for cname, c in classes.items():
                    if engine.layout(cname) is None:
                        continue
                    loose.update((cname, m[2]) for m in c.members if m[2] in named)
                loose = {(c, n) for c, n in loose if not any(o != c and (o, n) in loose and c in (chain(classes, o) or []) for o in classes)}
                if len(loose) == 1:
                    found = loose
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
    return members, slots, literals, widths, sizes


def literal_offset(f, sib, sky):
    """True when the fact's source line spells the sibling offset as a number (pointer arithmetic)."""
    line = f.get('source_line') or ''
    return bool(re.search(rf'\+\s*(?:0x{sib:x}|{sib})\b', line, re.I))


def emit_class(c, engine, classes, members, slots, body_idents, method_name, widths=None, tails=None, keep_dtor=False):
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
    widths = widths or {}
    for typ, decl, nm, _ in c.members:
        target = members.get((c.name, nm))
        if (c.name, nm) in widths:
            if '[' in decl or decl.startswith('(*'):
                return f'member {nm} is not a scalar', []
            typ, decl = widths[(c.name, nm)], nm
            original[nm] = f'{typ} {nm}'
        if target is not None:
            placed[nm] = (target[1], typ, decl)
        elif nm in body_idents or (c.name, nm) in widths:
            if nm not in lay.offsets:
                return f'referenced member {nm} has no computed offset', []
            placed[nm] = (lay.offsets[nm], typ, decl)
    # virtual slots: facts first, then the virtuals the body names, then the compiled method itself
    virt = {}
    for (cn, nm), (_sib, sky) in slots.items():
        if cn == c.name:
            virt[sky] = nm
    dtors = [m for m in c.methods if keep_dtor and m['name'].startswith('~') and m['name'] in lay.slots]
    for m in c.methods:
        if m in dtors:
            continue
        if m['virtual'] and (m['name'] in body_idents or m['name'] == method_name) and (c.name, m['name']) not in slots:
            slot = lay.slots.get(m['name'])
            if slot is not None:
                if virt.get(slot, m['name']) != m['name']:
                    return 'two virtuals on one slot', []
                virt[slot] = m['name']
    base_slots = base.nslots if base else 0
    if base is None and virt:
        base_slots = 0
    for m in dtors:
        # a destructor overriding the base's takes the base slot and is only re-declared; a new one gets its own slot
        if lay.slots[m['name']] >= base_slots:
            virt.setdefault(lay.slots[m['name']], m['name'])
    if virt and min(virt) < base_slots:
        return 'target slot lies inside the base class virtuals', []
    names = []
    lines = []
    for m in dtors:
        if lay.slots[m['name']] < base_slots:
            head = m['text'] if 'virtual' in m['text'].split('(')[0] else 'virtual ' + m['text']
            lines.append('    ' + head + ' ' + (m['body'] or ';'))
    texts = {m['name']: m for m in c.methods if m['virtual'] or (keep_dtor and m['name'].startswith('~'))}
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
                if keep_dtor and nm.startswith('~') and nm in texts:
                    t = texts[nm]
                    lines.append('    ' + (t['text'] if 'virtual' in t['text'].split('(')[0] else 'virtual ' + t['text']) + ' ' + (t['body'] or ';'))
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
    if tails and c.name in tails:
        tail = tails[c.name]
        if tail < cur:
            return f'target size {tail:#x} is below the members the function uses ({cur:#x})', []
        if tail > cur:
            names.append('padding_tail_')
            lines.append(f'    char padding_tail_[{tail - cur}];')
    for m in c.methods:
        if not m['virtual'] and not (keep_dtor and m['name'].startswith('~') and m['name'] in lay.slots):
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


def literal_value(token):
    try:
        return int(token, 0)
    except ValueError:
        return None


def apply_constants(u, facts):
    """Replace the argument literals the sibling passes to a call by the target's constants. Only the fact's own
    source line is touched when the listing names it; otherwise every argument position holding the sibling's
    value. Returns the number of replaced literals."""
    done, lines = 0, u['cpp_body'].split('\n')
    seen = set()
    for f in facts:
        if f['kind'] != 'call-arg-constant':
            continue
        sib, sky = literal_value(f['sibling_x64']), literal_value(f['skyrim'])
        if sib is None or sky is None or sib == sky or (sib, sky) in seen:
            continue
        seen.add((sib, sky))
        want = ' '.join((f.get('source_line') or '').split())
        rows = [i for i, l in enumerate(lines) if want and ' '.join(l.split()) == want] or list(range(len(lines)))

        def swap(m):
            nonlocal done
            if literal_value(m.group(2).rstrip('uUlL')) != sib:
                return m.group(0)
            done += 1
            return m.group(1) + (f'{sky:#x}' if m.group(2).lower().startswith('0x') else str(sky))
        for i in rows:
            lines[i] = re.sub(r'((?<=[(,])\s*)(0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*)(?=\s*[,)])', swap, lines[i])
    u['cpp_body'] = '\n'.join(lines)
    return done


PARAM_TYPES = re.compile(r'(?<![\w:])(unsigned\s+int|unsigned\s+long|unsigned|long|int)(?![\w:])')


def register_width(f):
    """True for a width fact that concerns a register or a stack slot (a parameter or local), not a member."""
    if f['kind'] != 'operand-width':
        return False
    m = re.search(r'\[\s*(\w+)\s*[+\]]', f['sibling_x64'])
    return m is None or m.group(1) in ('rsp', 'rbp')


def widen_parameters(u, facts, method_name):
    """Rule 68: the sibling's integer parameters are 32-bit where the target's are pointer-sized. Widen every integer
    parameter of the compiled function (definition and declaration). Returns the number of parameters changed, or a
    reason string when the facts say the target is narrower or the signature is not found."""
    rows = [f for f in facts if register_width(f)]
    if not rows:
        return 0
    narrower = 0
    for f in rows:
        a, b = f['sibling_x64'], f['skyrim']
        if re.search(r'\b(?:dword|e[a-z]{2}|r\d+d)\b', a) and re.search(r'\b(?:qword|r[a-z]{2}|r\d+)\b', b):
            narrower += 1
    if narrower < len(rows) / 2:
        return 'the target is narrower than the sibling: not a parameter widening'
    name = (method_name or '').split('::')[-1] or None
    body = u['cpp_body']
    head_end = body.find('{')
    head = body[:head_end] if head_end > 0 else ''
    m = re.search(rf'(?<![\w~]){re.escape(name)}\s*\(([^)]*)\)' if name else r'\w+\s*\(([^)]*)\)', head)
    if not m:
        return 'signature not found for a parameter widening'
    changed = [0]

    def wide(match):
        changed[0] += 1
        return 'unsigned __int64' if 'unsigned' in match.group(1) else '__int64'
    params = PARAM_TYPES.sub(wide, m.group(1))
    if not changed[0]:
        return 'no integer parameter to widen'
    u['cpp_body'] = body[:m.start(1)] + params + body[m.end(1):]
    decl = u['header_decl']
    dm = re.search(rf'(?<![\w~]){re.escape(name)}\s*\(([^)]*)\)', decl) if name else None
    if dm:
        u['header_decl'] = decl[:dm.start(1)] + PARAM_TYPES.sub(lambda mm: 'unsigned __int64' if 'unsigned' in mm.group(1) else '__int64', dm.group(1)) + decl[dm.end(1):]
    u['widened_parameters'] = changed[0]
    return changed[0]


def apply_layout(u, facts, method_name=None):
    """Replace the classes of u['header_decl'] that carry facts (and their bases) by stand-ins.
    Returns None on success or a reason string; adds the GUESS labels for the placeholders."""
    text = u['header_decl']
    classes = parse_classes(text)
    engine = Engine(classes, text)
    thunk = bool(u.get('thunk'))
    consts = apply_constants(u, facts)
    widened = widen_parameters(u, facts, method_name)
    if isinstance(widened, str):
        return widened
    facts = [f for f in facts if not register_width(f)]
    if widened:
        text = u['header_decl']
        classes = parse_classes(text)
        engine = Engine(classes, text)
    # a deleting-destructor thunk keeps the class text with the inline destructor: that body names the members it releases
    body = u['cpp_body'] + ('\n' + '\n'.join(m['body'] for c in classes.values() for m in c.methods if m.get('body')) if thunk else '')
    usable = [f for f in facts if f['kind'] in ('member-offset', 'vtable-slot', 'add-offset', 'operand-width', 'class-size', 'alloc-size')]
    res = resolve(engine, classes, usable, body)
    if isinstance(res, str):
        return res
    members, slots, literals, widths, sizes = res
    tails = {}
    for kind, sib, sky, src in sizes:
        if thunk and u.get('cls') in classes:
            owner = u['cls']
        else:
            named = [n for n in re.findall(rf'\bnew\s+({IDENT})', src) if n in classes]
            sized = [n for n in classes if (engine.layout(n) is not None and engine.layout(n).size == sib)]
            owner = named[0] if len(set(named)) == 1 else (sized[0] if len(sized) == 1 else None)
        if owner is None:
            return 'size fact not matched to a class'
        if tails.get(owner, sky) != sky:
            return 'one class with two different target sizes'
        tails[owner] = sky
    u['constants'] = consts
    if not members and not slots and not literals and not widths and not tails:
        return None if (consts or widened) else 'no usable layout fact'
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
    for cn, _ in list(members) + list(slots) + list(widths):
        ch = chain(classes, cn)
        if ch is None:
            return 'class chain not supported'
        touched.update(ch)
    for cn in tails:
        ch = chain(classes, cn)
        if ch is None:
            return 'class chain not supported'
        touched.update(ch)
    body_idents = set(re.findall(IDENT, strip_comments(body)))
    pieces, placeholders = [], []
    for name in sorted(touched, key=lambda n: -classes[n].start):
        c = classes[name]
        out, names = emit_class(c, engine, classes, members, slots, body_idents, method_name, widths, tails,
                                keep_dtor=thunk and name == u.get('cls'))
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
    for cn, size in tails.items():
        lay = engine2.layout(cn)
        if lay is None or lay.size != size:
            return f'stand-in {cn} is not {size:#x} bytes'
    u['header_decl'] = text
    if placeholders:
        u['labels'] = u['labels'] + [(placeholders, 'GUESS')]
    u['layout'] = True
    return None
