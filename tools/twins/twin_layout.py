"""Move a stand-in's own fields using layouts derived from its include closure."""
import re

import sibling_layout as sibling
import twin_source as S
from twin_unit import Unsupported

IDENT = r'[A-Za-z_]\w*'
CLASS = re.compile(rf'^(class|struct)\s+({IDENT})(?:\s+final)?\s*(?::\s*([^{{]+))?\s*\{{')
ENUM = re.compile(rf'^enum\s+(?:(class|struct)\s+)?({IDENT})\s*(?::\s*([^{{;]+))?')
PAD_NAME = re.compile(r'^(?:pad|padding|unk|unknown|unused|gap|reserved)\w*$', re.I)
PACKING = re.compile(r'(?m)^\s*#\s*pragma\s+pack\b')
CONDITIONAL = re.compile(r'(?m)^\s*#\s*(?:if|ifdef|ifndef|elif|else)\b')
ACCESS = re.compile(r'^\s*(?:public|private|protected)\s*:')


def enum_type(text):
    match = ENUM.match(text)
    if match:
        scoped, name, underlying = match.groups()
        if underlying or scoped:
            return name, (underlying or 'int').strip()
        # Default MSVC enum width is usable when its enumerators fit signed int.
        body = text.partition('{')[2].rpartition('}')[0]
        items = [item.strip() for item in body.split(',') if item.strip()]
        if all(re.fullmatch(rf'{IDENT}(?:\s*=\s*-?(?:0[xX][0-9a-fA-F]{{1,7}}|\d{{1,9}}))?', item)
               for item in items):
            return name, 'int'
    return None


def class_record(text, enums, scope=''):
    match = CLASS.match(text)
    if not match:
        return None
    body = text[match.end():text.rfind('}')]
    parts = S.segments(body)
    for part in reversed(parts):
        start = part.start
        access = ACCESS.match(part.text)
        if access:
            start += access.end()
        snippet = body[start:part.end].lstrip()
        # Leave any declaration after an enum's closing brace for the layout parser to reject.
        if snippet.startswith('enum ') and re.search(r'}\s*;\s*$', snippet):
            enum = enum_type(snippet)
            if enum:
                name, typ = enum
                enums[scope + match[2] + '::' + name] = typ
                body = body[:start] + ' ' + body[part.end:]
    return sibling.Cls(match[1], scope + match[2], match[3], body, 0, len(text))


def declarations(text, scope=''):
    for part in S.segments(text):
        code = S.mask_text(part.text)
        if part.kind == 'namespace':
            m = re.match(rf'namespace\s+({IDENT}(?:::{IDENT})*)\s*{{', code)
            if m:
                yield from declarations(code[m.end():code.rfind('}')], scope + m[1] + '::')
        else:
            yield scope, part, code


def qualify(typ, scopes, known):
    """Resolve local and absolute references in the textual declaration's C++ scope."""
    if typ.startswith('::'):
        return typ[2:]
    return next((scope + typ for scope in scopes if scope + typ in known), typ)


def compute(cls_text, headers):
    masked = S.mask_text(cls_text)
    types, enums, aliases = {}, {}, []
    for text in headers:
        if PACKING.search(text):
            raise Unsupported('layout-packed')
        if CONDITIONAL.search(text):
            continue
        for scope, part, code in declarations(text):
            if code.startswith('enum '):
                enum = enum_type(code)
                if enum:
                    name, typ = enum
                    name = scope + name
                    enums[name] = typ if name not in enums or enums[name] == typ else None
            elif part.kind == 'class':
                rec = class_record(code, enums, scope)
                if rec:
                    # Duplicate simple names cannot establish a unique layout.
                    types[rec.name] = rec if rec.name not in types else None
            elif not scope and code.startswith('typedef '):
                aliases.append(code)
    rec = class_record(masked, enums)
    if rec is None or rec.bad:
        raise Unsupported('layout-not-computable')
    types[rec.name] = rec
    enum_types = {name: typ for name, typ in enums.items() if typ}
    known = types.keys() | enum_types.keys()
    for cls in types.values():
        if cls is None:
            continue
        prefix = cls.name.split('::')
        scopes = ['::'.join(prefix[:i]) + '::' for i in range(len(prefix), 0, -1)]
        cls.bases = [qualify(base, scopes, known) for base in cls.bases]
        cls.members = [(qualify(typ, scopes, known), decl, name, raw) for typ, decl, name, raw in cls.members]
    eng = sibling.Engine(types, '\n'.join(aliases), enum_types=enum_types, use_community_sizes=False, multiple_bases=True)
    lay = eng.layout(rec.name)
    if lay is None or lay.size is None:
        raise Unsupported('layout-has-bases' if lay is None and rec.bases else 'layout-not-computable')
    return rec, lay


def member_at(text, decl, name):
    """Find one editable declaration, refusing multi-declarators or ambiguous text matches."""
    masked = S.mask_text(text)
    tokens = re.findall(r'\w+|[^\w\s]', decl)
    pattern = r'\s*'.join(map(re.escape, tokens))
    matches = list(re.finditer(r'(?<!\w)' + pattern + r'\s*;', masked))
    if len(matches) != 1:
        raise Unsupported('layout-ambiguous-member')
    match = matches[0]
    start = match.start()
    # The layout parser removes pointer qualifiers from the base type but keeps them in the
    # declarator. Locate the type prefix so new padding precedes the complete declaration.
    prefix = re.search(r'[^;{}\n]*$', masked[:start]).group()
    access = ACCESS.match(prefix)
    if access:
        prefix = prefix[access.end():]
    start -= len(prefix.lstrip())
    return start, match


def is_pad(decl, name, lay):
    count = re.fullmatch(rf'{re.escape(name)}\s*\[\s*(0[xX][0-9a-fA-F]+|[1-9][0-9]*)\s*\]', decl)
    return (count and PAD_NAME.fullmatch(name) and int(count[1], 0) == lay.sizes[name]
            and int(count[1], 0))


def fix_checks(checks, name, size, offsets):
    number = r'(0[xX][0-9a-fA-F]+|\d+)'

    def value(old, new):
        return hex(new) if old.lower().startswith('0x') else str(new)

    def offset(m):
        if m[2] not in offsets:
            # Inherited offsets remain fixed when only the derived fields move.
            return m[0]
        return m[1] + value(m[3], offsets[m[2]])

    return [re.sub(rf'(offsetof\(\s*{name}\s*,\s*({IDENT})\s*\)\s*==\s*)' + number, offset,
                   re.sub(rf'(sizeof\(\s*{name}\s*\)\s*==\s*)' + number,
                          lambda m: m[1] + value(m[2], size), check)) for check in checks]


def relocate(cls_text, moves, check_texts=(), *, headers=()):
    """Apply (exemplar offset, twin offset) pairs; keep existing bases and check the final layout."""
    rec, original = compute(cls_text, headers)
    by_name = {member[2]: member for member in rec.members}
    pads = {name for _, decl, name, _ in rec.members if is_pad(decl, name, original)}
    requested = {}
    for old, new in sorted(set(moves)):
        name = next((name for name, offset in original.offsets.items()
                     if offset <= old < offset + original.sizes[name]), None)
        if name is None or name in pads:
            raise Unsupported('no-member-at-offset')
        new -= old - original.offsets[name]
        if (name in requested and requested[name] != new) or new < 0:
            raise Unsupported('layout-contradictory-offsets')
        requested[name] = new

    # An assertion in the exemplar is an independent check on the reader's ABI assumptions.
    baseline = fix_checks(check_texts, rec.name, original.size, original.offsets)
    if list(check_texts) != baseline:
        # Ignore numeric spelling differences, but refuse a disagreement in the value.
        numbers = lambda texts: [int(n, 0) for t in texts for n in re.findall(r'==\s*(0[xX][0-9a-fA-F]+|\d+)', t)]
        if numbers(check_texts) != numbers(baseline):
            raise Unsupported('layout-exemplar-assertion')
    text, lay = cls_text, original
    names = list(by_name)
    for index, name in enumerate(names):
        if name not in requested or lay.offsets[name] == requested[name]:
            continue
        delta = requested[name] - lay.offsets[name]
        prev = names[index - 1] if index else None
        if prev in pads and prev in lay.offsets and lay.sizes[prev] + delta >= 0:
            _, decl, _, _ = by_name[prev]
            start, match = member_at(text, decl, prev)
            count = lay.sizes[prev] + delta
            if count:
                old = text[match.start():match.end()]
                new = re.sub(r'\[\s*([^\]]+)\s*\]',
                             lambda m: '[' + (hex(count) if m[1].strip().lower().startswith('0x') else str(count)) + ']', old)
                text = text[:match.start()] + new + text[match.end():]
            else:
                text = text[:start] + text[match.end():]
        elif delta > 0:
            start, _ = member_at(text, by_name[name][1], name)
            padding = f'unsigned char padTwin{original.offsets[name]:X}[{delta}];'
            line_start = text.rfind('\n', 0, start) + 1
            indent = text[line_start:start]
            separator = '\n' + indent if not indent.strip() else ' '
            text = text[:start] + padding + separator + text[start:]
        else:
            raise Unsupported('layout-cannot-shrink')
        _, lay = compute(text, headers)
    if any(lay.offsets.get(name) != target for name, target in requested.items()):
        raise Unsupported('layout-offset-alignment')
    return text, lay.size - original.size, fix_checks(check_texts, rec.name, lay.size, lay.offsets)
