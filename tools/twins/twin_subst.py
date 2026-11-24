"""Constrained substitutions for loose twins: constants that differ between exemplar and twin.

A loose twin has the exemplar's code shape with other displacements or immediates. Only a change
the source can state plainly is made here: an integer literal of the exemplar's function becomes
the twin's value when every immediate operand of that value changes the same way. A value that is
not spelled as a literal (a named constant, a sizeof, a member offset) is reported, never guessed.
"""
import re

import twin_source as S

INT = re.compile(r'(?<![\w.])(0[xX][0-9A-Fa-f]+|\d+)([uUlL]*)(?![\w.])')


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
