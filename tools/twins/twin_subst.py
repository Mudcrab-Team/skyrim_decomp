"""Constrained substitutions for loose twins: constants that differ between exemplar and twin.

A loose twin has the exemplar's code shape with other displacements or immediates. Only a change
the source can state plainly is made here: an integer literal or a uniquely used integral constexpr
becomes the twin's value when every immediate operand of that value changes the same way.
"""
import re

import twin_source as S

INT = re.compile(r'(?<![\w.])(0[xX][0-9A-Fa-f]+|\d+)([uUlL]*)(?![\w.])')
CONSTEXPR = re.compile(
    r'^\s*(?:static\s+)?constexpr\s+(?:auto|(?:unsigned\s+)?(?:int|long(?:\s+long)?|short)|'
    r'(?:std::)?(?:size_t|u?int(?:8|16|32|64)_t))\s+([A-Za-z_]\w*)\s*=\s*'
    r'(-?(?:0[xX][0-9a-fA-F]+|[1-9]\d*|0)[uUlL]*)\s*;\s*$')


def immediate_map(exemplar_ops, diffs):
    """{exemplar value: twin value, width} for immediates that change uniformly; (map, why) with `why` set when not."""
    changed = [d for d in diffs if d[3] == 'imm']
    out, why = {}, None
    for ev in sorted({d[1] for d in changed}):
        mine = [d for d in changed if d[1] == ev]
        every = [k for k, op in enumerate(exemplar_ops) if op[3] == 'imm' and op[2] == ev]
        targets = {d[2] for d in mine}
        if len(mine) != len(every) or len(targets) != 1:
            why = 'ambiguous-constant'
            continue
        out[ev] = (next(iter(targets)), mine[0][4])
    return out, why


def _value(text, width):
    v = int(text, 16) if text.lower().startswith('0x') else int(text)
    return v


def substitute_literals(body, mapping):
    """Replace integer literals of `body` per `mapping` {ev: (tv, width)}; returns (text, replaced, missing)."""
    masked = S.mask_text(body)
    replaced, hit = 0, set()
    out = []
    last = 0
    for m in INT.finditer(masked):
        v = _value(m.group(1), 0)
        for ev, (tv, width) in mapping.items():
            if v == ev or (ev < 0 and v == ev + (1 << (8 * width))):
                new = tv if tv >= 0 or not m.group(1).lower().startswith('0x') else tv + (1 << (8 * width))
                if ev < 0 and v != ev and tv < 0:
                    new = tv + (1 << (8 * width))
                text = ('0x%x' % new) if m.group(1).lower().startswith('0x') else str(new)
                out.append(body[last:m.start()] + text + m.group(2))
                last = m.end()
                replaced += 1
                hit.add(ev)
                break
    out.append(body[last:])
    return ''.join(out), replaced, set(mapping) - hit


def named_constants(body, seg, mapping):
    """Change a standalone constexpr only when its declaration and sole use are in this TU."""
    changes = {}
    sources = S.segments(body)
    target = S.mask_text(seg.text)
    for declaration in sources:
        if declaration.end > seg.start:
            continue
        match = CONSTEXPR.fullmatch(S.mask_text(declaration.text))
        if not match:
            continue
        name, literal = match.groups()
        word = re.compile(rf'\b{name}\b')
        uses = list(word.finditer(target))
        if len(uses) != 1 or any(word.search(S.mask_text(s.text)) for s in sources
                                   if s.start not in (seg.start, declaration.start)):
            continue
        if re.search(r'[:.>]\s*$', target[:uses[0].start()]):
            continue
        plain = literal.rstrip('uUlL')
        value = int(plain, 0)
        if value not in mapping:
            continue
        replacement, width = mapping[value]
        if plain.startswith('-') and literal != plain:
            continue
        # Preserve the literal's deduced type for constexpr auto.
        if (literal != plain and replacement < 0
                or not -(1 << 31) <= replacement < (1 << 31)
                or plain.lower().startswith('0x') and value >= (1 << 31)):
            continue
        if replacement >= 0 and plain.lower().startswith('0x'):
            replacement = hex(replacement)
        start = declaration.start + match.start(2)
        end = declaration.start + match.end(2)
        changes.setdefault(value, []).append((start, end, str(replacement) + literal[len(plain):]))
    return [items[0] for items in changes.values() if len(items) == 1] if (
        set(changes) == set(mapping) and all(len(v) == 1 for v in changes.values())) else None
