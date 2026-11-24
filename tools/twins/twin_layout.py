"""Move data members of a stand-in class to the offsets a loose twin's code uses.

The stand-in owner of a twin is a copy of the exemplar's class. When the twin reads a member at
another displacement, the class is re-laid out: the member that sits at the exemplar's offset is
moved by growing or shrinking the padding array in front of it (or adding one), and the size check
follows. Only layouts this module can compute are touched: members of builtin, enum-free scalar,
pointer or byte-array type in a class without base classes, optionally with virtual functions.
Anything else raises `Unsupported`; no offset is ever written without a member to carry it.
"""
import re

import twin_source as S
from twin_unit import Unsupported

BUILTIN = {'char': 1, 'signed char': 1, 'unsigned char': 1, 'bool': 1, 'short': 2, 'unsigned short': 2, 'int': 4,
           'unsigned': 4, 'unsigned int': 4, 'long': 4, 'unsigned long': 4, 'float': 4, 'long long': 8,
           'unsigned long long': 8, '__int64': 8, 'double': 8, 'size_t': 8, 'std::size_t': 8,
           'std::uint8_t': 1, 'std::int8_t': 1, 'std::uint16_t': 2, 'std::int16_t': 2, 'std::uint32_t': 4,
           'std::int32_t': 4, 'std::uint64_t': 8, 'std::int64_t': 8, 'uint8_t': 1, 'uint16_t': 2, 'uint32_t': 4,
           'uint64_t': 8, 'int8_t': 1, 'int16_t': 2, 'int32_t': 4, 'int64_t': 8}
PAD_NAME = re.compile(r'^(?:pad|padding|unk|unknown|unused|gap|reserved)\w*$', re.I)


class Member:
    def __init__(self, text, typ, name, count, size, align, start):
        self.text, self.typ, self.name, self.count, self.size, self.align, self.start = text, typ, name, count, size, align, start
        self.offset = None

    @property
    def is_pad(self):
        return self.count is not None and self.size == 1 and bool(PAD_NAME.match(self.name))


def _statements(body_masked):
    """(start, end) of top-level `;`-terminated statements of a class body (nested braces skipped)."""
    out, depth, start = [], 0, 0
    for i, ch in enumerate(body_masked):
        if ch == '{':
            depth += 1
        elif ch == '}':
            depth -= 1
            if depth == 0:
                nxt = body_masked[i + 1:].lstrip()
                if not nxt.startswith(';'):
                    out.append((start, i + 1))
                    start = i + 1
        elif ch == ';' and depth == 0:
            out.append((start, i + 1))
            start = i + 1
    return out


def parse(cls_text):
    """(head, members, has_virtual, body_start, body_end, bases) of one class definition text."""
    masked = S.mask_text(cls_text)
    open_ = masked.find('{')
    close = masked.rfind('}')
    if open_ < 0 or close < 0:
        raise Unsupported('layout-not-computable')
    head = masked[:open_]
    bases = ':' in re.sub(r'::', '', head)
    body = masked[open_ + 1:close]
    members, virtual = [], False
    for a, b in _statements(body):
        stmt = body[a:b].strip()
        stmt = re.sub(r'^(?:public|private|protected)\s*:', '', stmt).strip()
        if not stmt or stmt.startswith(('typedef', 'using', 'friend', 'static', 'enum', 'struct', 'class')):
            if stmt.startswith('static') and '(' not in stmt:
                raise Unsupported('layout-not-computable')
            continue
        if re.search(r'\bvirtual\b', stmt):
            virtual = True
        if '(' in stmt:
            continue
        m = re.match(r'^((?:const\s+)?[A-Za-z_][\w:]*(?:\s+(?:int|long|char))?(?:\s*\*)*)\s*([A-Za-z_]\w*)\s*(?:\[\s*([^\]]+?)\s*\])?\s*;$', stmt)
        if not m:
            raise Unsupported('layout-not-computable')
        typ, name, count = re.sub(r'\s+', ' ', m.group(1).replace('const ', '')).strip(), m.group(2), m.group(3)
        hexcount = bool(count and count.lower().startswith('0x'))
        if '*' in typ:
            size = align = 8
        elif typ in BUILTIN:
            size = align = BUILTIN[typ]
        else:
            raise Unsupported('layout-not-computable')
        n = None
        if count is not None:
            try:
                n = int(count, 0)
            except ValueError:
                raise Unsupported('layout-not-computable')
        members.append(Member(cls_text[open_ + 1 + a:open_ + 1 + b], typ, name, n, size, align, open_ + 1 + a))
        members[-1].hexcount = hexcount
    return head, members, virtual, bases


def assign_offsets(members, virtual):
    off = 8 if virtual else 0
    biggest = 8 if virtual else 1
    for m in members:
        off = (off + m.align - 1) // m.align * m.align
        m.offset = off
        off += m.size * (m.count if m.count is not None else 1)
        biggest = max(biggest, m.align)
    return (off + biggest - 1) // biggest * biggest


def relocate(cls_text, moves, check_texts=()):
    """Apply [(exemplar offset, twin offset)] to the class text; returns (class text, size delta, check texts)."""
    head, members, virtual, bases = parse(cls_text)
    if bases:
        raise Unsupported('layout-has-bases')
    size = assign_offsets(members, virtual)
    shift = 0
    edits = []
    for ev, tv in sorted(set(moves)):
        hit = [m for m in members if m.offset == ev and not m.is_pad]
        if not hit:
            raise Unsupported('no-member-at-offset')
        mem = hit[0]
        delta = tv - (ev + shift)
        if delta == 0:
            continue
        index = members.index(mem)
        prev = members[index - 1] if index else None
        if prev is not None and prev.is_pad and prev.count + delta > 0 and mem.align == 1 or \
                prev is not None and prev.is_pad and (prev.count + delta) >= 0 and delta % 1 == 0:
            if prev.count + delta < 0:
                raise Unsupported('layout-cannot-shrink')
            edits.append((prev, prev.count + delta))
        elif delta > 0:
            edits.append((mem, ('insert', delta, ev + shift - delta if False else ev + shift)))
        else:
            raise Unsupported('layout-cannot-shrink')
        shift += delta
    text = cls_text
    for target, how in sorted(edits, key=lambda e: -e[0].start):
        if isinstance(how, tuple):
            pad = '    std::uint8_t unknown%02X[%d];\n' % (how[2] - 0, how[1])
            text = text[:target.start] + pad.lstrip(' ') + '    ' + text[target.start:].lstrip()
        else:
            new = re.sub(r'\[\s*[^\]]+\s*\]', '[%s]' % (hex(how) if getattr(target, 'hexcount', False) else how), target.text, count=1)
            if how == 0:
                new = ''
            text = text[:target.start] + new + text[target.start + len(target.text):]
    checks = _fix_checks(text, check_texts)
    return text, shift, checks


def _fix_checks(cls_text, check_texts):
    """Size and member-offset assertions of the stand-in follow the new layout."""
    _head, members, virtual, _bases = parse(cls_text)
    size = assign_offsets(members, virtual)
    offsets = {m.name: m.offset for m in members}
    out = []
    for c in check_texts:
        c = re.sub(r'(sizeof\([^)]*\)\s*==\s*)(0[xX][0-9a-fA-F]+|\d+)',
                   lambda m: m.group(1) + (hex(size) if m.group(2).lower().startswith('0x') else str(size)), c)

        def off(m):
            if m.group(2) not in offsets:
                raise Unsupported('layout-assertion-member')
            v = offsets[m.group(2)]
            return m.group(1) + (hex(v) if m.group(3).lower().startswith('0x') else str(v))
        c = re.sub(r'(offsetof\(\s*\w+\s*,\s*(\w+)\s*\)\s*==\s*)(0[xX][0-9a-fA-F]+|\d+)', off, c)
        out.append(c)
    return out
