"""Mechanical repairs the PR bot makes on a contributor's unit files instead of rejecting the PR.

Every function here is pure text in, text out, so the bot can test it without a checkout. A repair
returns None when it cannot be done safely; the PR then gets the normal rejection. Nothing here
edits a label, a provenance line or the code of a function that is not already accepted on main.
"""
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import compact_headers  # noqa: E402
import digest_v2  # noqa: E402
import lint_reconstruction as lint  # noqa: E402
import rva_headers  # noqa: E402

# Header fields that restate what the records, git and the docs already say; dropped before any other prose.
BOILERPLATE = re.compile(r'//\s*(?:Task|Build|Labels?|Evidence|Drafted by|Recipe|Status|Disclaimer|Note)\s*:', re.I)


def _lead_numbers(text):
    """[(0-based line index, line)] of the file's counted header lines."""
    header = lint.leading_comment(text)
    return [(n - 1, ln) for n, ln in lint.numbered_header_lines(header)]


def _groups(counted, lines):
    """Counted lines grouped into statements: a line that carries on the one above stays with it."""
    groups = []
    for index, _ in counted:
        if groups and groups[-1][-1] == index - 1 and compact_headers.wraps_into(lines[index - 1], lines[index]):
            groups[-1].append(index)
        else:
            groups.append([index])
    return groups


def trim_header(text, name):
    """The text with free-text header lines removed until the counted lines fit the budget, else None.

    Labels, provenance, origin and licence lines are never removed, and the result must hash to the
    same tu-sha256-v2 text, so no record or review bound to the unit changes. None when the header
    is already within budget or cannot be brought there without touching protected lines.
    """
    if '\r' in text:
        return None
    lines = text.split('\n')
    counted = _lead_numbers(text)
    if len(counted) <= lint.HEADER_LIMIT or any(not ln.lstrip().startswith('//') for _, ln in counted):
        return None
    groups = _groups(counted, lines)
    removable = [g for g in groups if not any(compact_headers.keep_line(lines[i]) for i in g)]
    boiler = [g for g in removable if BOILERPLATE.match(lines[g[0]].strip())]
    # Boilerplate in file order first, then the other free text from the bottom up.
    order = boiler + [g for g in reversed(removable) if g not in boiler]
    excess, drop = len(counted) - lint.HEADER_LIMIT, set()
    for group in order:
        if excess <= 0:
            break
        drop.update(group)
        excess -= len(group)
    if excess > 0:
        return None
    new = '\n'.join(ln for i, ln in enumerate(lines) if i not in drop)
    try:
        if digest_v2.strip_comments(text.encode(), name) != digest_v2.strip_comments(new.encode(), name):
            return None
    except ValueError:
        return None
    return new


def add_spdx(text):
    """The text with the one-line NG notice inserted after the header's first statement, else None.

    Only for a header that names CommonLibSSE-NG declarations and has no SPDX MIT line and no licence
    text; a unit carrying the full licence is rewritten by tools/compact_headers.py, not here.
    """
    if '\r' in text:
        return None
    header = lint.leading_comment(text)
    if ('CharmedBaryon/CommonLibSSE-NG@' not in header or 'SPDX-License-Identifier: MIT' in header
            or lint.FULL_LICENCE.search(header)):
        return None
    lines = text.split('\n')
    if not lines or not lines[0].startswith('//'):
        return None
    at = 1
    # After the whole first statement, never between the lines of a wrapped one.
    while at < len(lines) and lines[at].startswith('//') and compact_headers.wraps_into(lines[at - 1], lines[at]):
        at += 1
    lines.insert(at, '// ' + lint.SPDX_MIT)
    return '\n'.join(lines)


def _mask(text):
    """`text` with comments blanked and literal contents replaced, same length, so braces can be matched.

    ValueError for a raw string literal, which this scan does not model.
    """
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith('//', i):
            end = text.find('\n', i)
            end = n if end < 0 else end
            out.append(' ' * (end - i))
            i = end
        elif text.startswith('/*', i):
            end = text.find('*/', i + 2)
            end = n if end < 0 else end + 2
            out.append(''.join('\n' if ch == '\n' else ' ' for ch in text[i:end]))
            i = end
        elif c in '"\'':
            if c == '"' and i and text[i - 1] == 'R':
                raise ValueError('raw string literal')
            j = i + 1
            while j < n and text[j] != c and text[j] != '\n':
                j += 2 if text[j] == '\\' else 1
            j = min(j, n - 1)
            out.append(c + 'x' * (j - i - 1) + (text[j] if j > i else ''))
            i = j + 1
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def function_span(text, name):
    """(start, end) of the one definition of the qualified `name` in `text`, else None.

    The span runs from the first code line of the definition (comments, blank lines and preprocessor
    lines before it are left out) to its closing brace. None when there is no definition or several.
    """
    try:
        masked = _mask(text)
    except ValueError:
        return None
    pattern = re.compile(r'(?<![A-Za-z0-9_:~])' + r'\s*::\s*'.join(map(re.escape, name.split('::'))) + r'\s*\(')
    spans = []
    for m in pattern.finditer(masked):
        depth, i = 1, m.end()
        while i < len(masked) and depth:
            depth += (masked[i] == '(') - (masked[i] == ')')
            i += 1
        while i < len(masked) and masked[i] not in '{;':
            i += 1
        if i >= len(masked) or masked[i] == ';':
            continue
        start = max(masked.rfind(c, 0, m.start()) for c in ';{}') + 1
        # Skip what precedes the definition's first code line.
        while start < m.start():
            end = masked.find('\n', start)
            end = len(masked) if end < 0 else end
            line = masked[start:end].strip()
            if line and not line.startswith('#'):
                break
            start = end + 1
        depth = 0
        for j in range(i, len(masked)):
            depth += (masked[j] == '{') - (masked[j] == '}')
            if depth == 0:
                spans.append((start, j + 1))
                break
        else:
            return None
    return spans[0] if len(spans) == 1 else None


def restore_functions(text, main_text, names):
    """(new text, [names restored]): each named definition replaced by the one in main's copy of the file.

    A name that is not defined exactly once in both copies is left as the contributor wrote it.
    """
    done = []
    for name in names:
        mine, theirs = function_span(text, name), function_span(main_text, name)
        if mine is None or theirs is None:
            continue
        old, new = text[mine[0]:mine[1]], main_text[theirs[0]:theirs[1]]
        if old != new:
            text = text[:mine[0]] + new + text[mine[1]:]
            done.append(name)
    return text, done


def restoration_keeps_context(name, text, main_text, restored):
    """Require the base code outside restored definitions to survive in order."""
    def context(source):
        spans = [function_span(source, function) for function in restored]
        if None in spans:
            raise ValueError('restored definition not found')
        for start, end in sorted(spans, reverse=True):
            source = source[:start] + '\n' + source[end:]
        code = digest_v2.strip_comments(source.encode(), name, keep_provenance=False)
        return [line.strip() for line in code.splitlines() if line.strip()]

    # A replaced definition may still depend on an include, helper or declaration the PR removed.
    try:
        current = iter(context(text))
        return all(line in current for line in context(main_text))
    except ValueError:
        return False


CI_HINT = re.compile(r'//[ \t]*CI hash:[ \t]*(0x[0-9a-fA-F]+)[ \t]+\S+')
SIMPLE_NAME = re.compile(r'(?:[A-Za-z_]\w*::)*~?[A-Za-z_]\w*')
MARKED_NAME = re.compile(r'^// (0x[0-9a-fA-F]+) (\S+)', re.M)


def all_claims(text):
    return rva_headers.claimed_rvas([text]) | {int(m[1], 16) for m in MARKED_NAME.finditer(text)}


def drop_claim_comments(text, rvas):
    """Remove standalone claim lines for the dropped RVAs, keeping shared metadata intact."""
    kept = []
    for line in text.splitlines(keepends=True):
        comment = line.strip()
        content = comment.removeprefix('//').lstrip()
        standalone = comment.startswith('//') and (
            rva_headers.COMPARED.match(comment) or rva_headers.SIZE_RECORD.match(content)
            or rva_headers.COMPARED_AT.match(content))
        claims = rva_headers.claimed_rvas([comment]) if standalone else set()
        hint = CI_HINT.fullmatch(comment)
        if hint:
            claims.add(int(hint[1], 16))
        if not claims or not claims <= rvas:
            kept.append(line)
    return ''.join(kept)


def drop_duplicate_functions(text, rvas):
    """Remove unambiguous marked definitions from a unit, or leave the whole repair for manual cleanup."""
    markers = {}
    for marker in MARKED_NAME.finditer(text):
        if (rva := int(marker[1], 16)) in rvas:
            if rva in markers or not SIMPLE_NAME.fullmatch(marker[2]):
                return None
            markers[rva] = marker[2]
    if markers.keys() != rvas:
        return None
    remaining = all_claims(text) - rvas
    for name in markers.values():
        span = function_span(text, name)
        if span is None:
            return None
        start, end = span
        tail = _mask(text[end:]).lstrip()
        if tail.startswith(('{', ',', 'catch')) or re.search(r'^\s*#', _mask(text[start:end]), re.M):
            return None
        if text[end:end + 1] == '\n':
            end += 1
        text = text[:start] + text[end:]
    text = drop_claim_comments(text, rvas)
    if all_claims(text) != remaining:
        return None
    code = _mask(text)
    if any(re.search(r'\b' + re.escape(name.rsplit('::', 1)[-1].lstrip('~')) + r'\b', code)
           for name in markers.values()):
        return None
    return text


def fix_unit(name, text, main_text=None, accepted=None):
    """(new text, [kinds]) for one unit file; the text is unchanged and kinds empty when nothing applies.

    `accepted` is {rva: qualified name} of the functions already accepted on main and `main_text` is
    main's copy of this file (None for a new file). Kinds are 'accepted', 'header' and 'spdx'.
    """
    kinds, current = [], text
    if main_text is not None and accepted:
        named = rva_headers.claimed_rvas([current]) & rva_headers.claimed_rvas([main_text]) & set(accepted)
        repaired, restored = restore_functions(current, main_text, [accepted[r] for r in sorted(named)])
        if restored and restoration_keeps_context(name, current, main_text, restored):
            current = repaired
            kinds.append('accepted')
    header_fixed = current
    for kind, fix in (('header', lambda t: trim_header(t, name)), ('spdx', add_spdx)):
        changed = fix(header_fixed)
        if changed is not None:
            header_fixed = changed
            kinds.append(kind)
    if header_fixed != current:
        # A header repair that leaves a header problem behind helps nobody: the PR is rejected for it anyway.
        if lint.header_budget_problems(name, lint.leading_comment(header_fixed)):
            kinds = [k for k in kinds if k == 'accepted']
        else:
            current = header_fixed
    return current, kinds
