"""Give a direct call a new binding when a strict twin targets a different callee."""
import re

import twin_source as S
from twin_unit import Unsupported

# Public nonstatic MSVC x64 member with void return and no explicit parameters.
VOID_MEMBER = re.compile(r'^\?([A-Za-z_]\w*)@([A-Za-z_]\w*)@@([QU])EAAXXZ$')


def changed_members(exemplar, target, symbols):
    if exemplar['masked'] != target['masked'] or exemplar['pattern'] != target['pattern']:
        return []
    refs = {old[2] for old, new in zip(exemplar['targets'], target['targets']) if old[2] != new[2]}
    return [match.groups() for symbol, row in symbols.items()
            if row.get('rva') in refs and (match := VOID_MEMBER.fullmatch(symbol))]


def retarget(twin, members):
    path = twin.stem + '.cpp'
    head, body = S.split_header(twin.files[path])
    header = S.mask_text(twin.files.get(twin.stem + '.h', ''))
    edits, declarations = [], []
    for method, owner, access in members:
        pattern = (rf'(?<![\w.:>])(?:(?P<member>[A-Za-z_]\w*)\s*\.\s*|'
                   rf'(?P<scope>{owner})::)?{method}\s*\(\s*\)')
        hits = [(segment, match) for segment in S.segments(body) if segment.kind == 'function'
                for match in re.finditer(pattern, S.mask_text(segment.text))]
        if len(hits) != 1:
            continue
        segment, hit = hits[0]
        # Calls in a constructor/dtor dispatch to their own class's hierarchy. Outside those,
        # only explicitly qualified virtual calls can be replaced with a direct call.
        if hit['member'] and access == 'Q' and re.search(
                rf'\b{owner}\s+{hit["member"]}\s*;', header):
            arg = '&' + hit['member']
        elif hit['scope'] or (not hit['member'] and S.simple_name(segment.name).startswith('~')):
            arg = 'this'
        else:
            continue
        name = f'Call{method}{twin.rva:x}'
        declarations.append(f'// {name}: GUESS(low) STANDIN\nvoid {name}({owner}* object);')
        edits.append((segment.start + hit.start(), segment.start + hit.end(), f'{name}({arg})'))
    if not edits:
        raise Unsupported('no-direct-callee-to-rebind')
    start = S.segments(body)[0].start
    for left, right, text in sorted(edits, reverse=True):
        body = body[:left] + text + body[right:]
    twin.files[path] = '\n'.join(head) + '\n' + body[:start] + '\n\n'.join(declarations) + '\n\n' + body[start:]
    return twin
