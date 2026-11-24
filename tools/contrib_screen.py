"""Conservative resource/path screen for contributed C++; not a C++ security sandbox."""
import posixpath
import re
import unicodedata
from pathlib import PurePosixPath

from source_digest import logical_lines, quoted_includes

MAX_BYTES = 65536
MAX_LINES = 2000
MAX_LINE = 4096
MAX_DEPTH = 32
MAX_MACROS = 128
MAX_EXPANSION = 100000
# These are pinned compiler headers, never searched on the maintainer's ordinary include path.
STANDARD_HEADERS = frozenset(('cstddef', 'cstdint', 'cstring', 'climits', 'cfloat', 'cmath',
                              'type_traits', 'utility', 'new', 'limits', 'stddef.h', 'stdint.h', 'intrin.h', 'math.h',
                              'algorithm', 'memory', 'vector', 'deque', 'list', 'forward_list', 'set', 'map', 'unordered_map', 'unordered_set',
                              'array', 'queue', 'functional', 'bitset', 'string', 'string.h'))
PRAGMAS = re.compile(r'(?:once|pack\s*\([^\n]*\)|warning\s*\([^\n]*\))\s*\Z')
TOKEN = re.compile(r'[A-Za-z_]\w*|[^\s]')
MAX_MESSAGE_BYTES = 4096
MAX_HISTORY_BYTES = 65536
MAX_IDENTITY_BYTES = 256
EMAIL = re.compile(r'[^\s<>@,;"\\]+@[^\s<>@,;"\\]+\Z')


def stays_in_tree(name, target):
    """Whether `target`, written in `name`, climbs only to another header under `reconstruction/`.

    Accepted units were written with `"../area/X.h"` and a recipe without an include root finds a
    repository header no other way, so the spelling has to stay allowed; what a parent step must never do
    is leave the tree or take a host path.
    """
    if (not name.startswith('reconstruction/') or '\\' in target or ':' in target or target.startswith('/')
            or not re.fullmatch(r'[A-Za-z0-9_./-]+', target) or not target.endswith('.h')):
        return False
    joined = posixpath.normpath(posixpath.join(posixpath.dirname(name), target))
    return joined.startswith('reconstruction/') and '..' not in joined.split('/')


def screen(blob, name, *, headers=STANDARD_HEADERS):
    """Return fixed reason codes only; never echo attacker-controlled text into public comments.

    Over-refusal is deliberate: scan both raw and spliced text, including inactive branches,
    comments and literals. Existing intake/lint/closure checks remain mandatory afterwards.
    """
    from decompiler_privacy import private_decompiler_path, private_decompiler_text
    problems = set()
    if private_decompiler_path(name):
        problems.add('private-decompiler-output')
    if len(blob) > MAX_BYTES:
        return ['file-size-cap']
    try:
        text = blob.decode('utf-8')
    except UnicodeDecodeError:
        return ['non-utf8']
    if any(unicodedata.category(c).startswith('C') and c not in '\t\r\n' for c in text):
        problems.add('control-character')
    if private_decompiler_text(text):
        problems.add('private-decompiler-output')
    lines = text.splitlines()
    if len(lines) > MAX_LINES:
        problems.add('line-count-cap')
    if any(len(line) > MAX_LINE for line in lines):
        problems.add('line-length-cap')
    try:
        includes = quoted_includes(blob, name)
        spliced = '\n'.join(logical_lines(blob, name))
    except ValueError:
        return sorted(problems | {'preprocessor-spelling'})
    # Comments cannot hide keywords or arguments from this additional screen.
    normalized = re.sub(r'/\*.*?\*/', ' ', spliced, flags=re.S)
    hops = {target for kind, target in includes if kind == '"' and '..' in target.split('/')
            and stays_in_tree(name, target)}
    for text_variant in (text, spliced, normalized):
        if re.search(r'\b(?:__asm__|__asm|_asm|asm|__emit|__pragma|_Pragma)\b', text_variant):
            problems.add('assembly-or-pragma-operator')
        if re.search(r'\b(?:allocate|code_seg|naked|safebuffers)\b', text_variant):
            problems.add('unsafe-declspec')
        if re.search(r'#[ \t]*(?:import|include_next|line)\b', text_variant):
            problems.add('unsafe-directive')
        if '##' in text_variant:
            problems.add('token-pasting')
        for match in re.finditer(r'#[ \t]*pragma\b([^\n]*)', text_variant):
            if not PRAGMAS.fullmatch(match.group(1).strip()):
                problems.add('unsafe-pragma')
        # A path or escape in any literal/macro/comment must not name a host location.
        pathed = text_variant
        for hop in hops:
            pathed = pathed.replace(f'"{hop}"', '"x.h"')
        if (re.search(r'(?:(?<![A-Za-z0-9_])[A-Za-z]:[\\/]|["\'][A-Za-z]:|\\\\|(?:^|[\s"\'(<>=])/[^/*=\s])', text_variant)
                or re.search(r'\.\.[\\/]|[\\/]\.\.(?:[\\/"\']|$)', pathed)
                or re.search(r'~[\\/]|\.(?:local|git)(?:[\\/"\']|$)', text_variant)
                or re.search(r'\\(?:x[0-9a-fA-F]|[uU][0-9a-fA-F]|[0-7])', text_variant)):
            problems.add('path-or-encoded-escape')
    for kind, target in includes:
        parts = PurePosixPath(target).parts
        if target in hops:
            continue
        if (not parts or any(p in ('.', '..') for p in parts) or '\\' in target or ':' in target
                or target.startswith('/') or not re.fullmatch(r'[A-Za-z0-9_./-]+', target)):
            problems.add('include-outside-roots')
        elif kind == '<' and target not in headers:
            # Repository angle includes still have to be reconstruction headers.
            if not target.endswith('.h'):
                problems.add('include-outside-roots')
        elif kind == '"' and not target.endswith('.h'):
            problems.add('include-outside-roots')
    # Bound preprocessor condition nesting and punctuation/template nesting without expanding C++.
    level = 0
    for line in spliced.splitlines():
        if re.match(r'\s*#\s*(?:if|ifdef|ifndef)\b', line):
            level += 1
            if level > MAX_DEPTH:
                problems.add('preprocessor-depth')
        elif re.match(r'\s*#\s*endif\b', line):
            level -= 1
    # Remove literals and comments only for resource accounting; dangerous spelling above sees all.
    code = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*', '', spliced, flags=re.S)
    for left, right in (('(', ')'), ('{', '}'), ('[', ']'), ('<', '>')):
        depth = 0
        for ch in code:
            if ch == left:
                depth += 1
                if depth > MAX_DEPTH:
                    problems.add('template-or-expression-depth')
            elif ch == right:
                depth = max(0, depth - 1)
    definitions = {}
    for line in spliced.splitlines():
        m = re.match(r'\s*#\s*define\s+([A-Za-z_]\w*)(\([^)]*\))?\s*(.*)', line)
        if m:
            if m.group(1) in definitions:
                problems.add('macro-redefinition')
            definitions[m.group(1)] = TOKEN.findall(m.group(3))
            if m.group(2) and len(m.group(2)) > 256:
                problems.add('macro-size-cap')
    if len(definitions) > MAX_MACROS:
        problems.add('macro-count-cap')
    memo = {}
    def weight(key, stack):
        if key in stack or len(stack) >= MAX_DEPTH:
            problems.add('macro-depth-or-cycle')
            return MAX_EXPANSION + 1
        if key in memo:
            return memo[key]
        total = 0
        for token in definitions[key]:
            total += weight(token, stack + (key,)) if token in definitions else 1
            if total > MAX_EXPANSION:
                problems.add('macro-expansion-cap')
                break
        memo[key] = total
        return total
    for key in definitions:
        weight(key, ())
    return sorted(problems)


def screen_text(text, *, limit=MAX_MESSAGE_BYTES):
    """Return fixed reason codes for free text that becomes permanent public history.

    Commit messages and identities carry no code, so the source-only rules (macros, includes)
    do not apply; the rules for what must never be published (private decompiler output, host
    paths, control characters, pasted byte dumps) do.
    """
    from decompiler_privacy import private_decompiler_text
    raw = text.encode('utf-8', 'surrogateescape')
    if len(raw) > limit:
        return ['text-size-cap']
    try:
        raw.decode('utf-8')
    except UnicodeDecodeError:
        return ['non-utf8']
    problems = set()
    if any(unicodedata.category(c).startswith('C') and c not in '\t\r\n' for c in text):
        problems.add('control-character')
    if private_decompiler_text(text):
        problems.add('private-decompiler-output')
    if (re.search(r'(?:(?<![A-Za-z0-9_])[A-Za-z]:[\\/]|\\\\|\.\.[\\/]|~[\\/]|\.(?:local|git)(?:[\\/]|\b))', text)
            or re.search(r'(?:^|[\s"\'(<>=])/(?:Users|home|root|etc|var|tmp|opt|mnt|private|proc)/', text)):
        problems.add('host-path')
    if (re.search(r'(?:\b[0-9A-Fa-f]{2}(?:[ ,]+(?:0x)?[0-9A-Fa-f]{2}){15,}\b)', text)
            or re.search(r'(?:0x[0-9A-Fa-f]{2},\s*){16,}', text)
            or re.search(r'[A-Za-z0-9+/=]{200,}', text)):
        problems.add('pasted-bytes')
    return sorted(problems)


def screen_tree(root, compiled, *, headers=STANDARD_HEADERS):
    """Screen the whole compiler input closure, not just files changed by the PR."""
    from source_digest import include_closure
    closure = include_closure(root, compiled)
    problems = []
    for name in closure:
        if not name.startswith('reconstruction/') or not name.endswith(('.h', '.cpp')):
            problems.append('include-outside-roots')
            continue
        problems.extend(screen((root / name).read_bytes(), name, headers=headers))
    # Unknown angle headers must resolve to a member of this exact repository closure.
    for name in closure:
        for kind, target in quoted_includes((root / name).read_bytes(), name):
            if kind == '<' and target not in headers and 'reconstruction/' + target not in closure:
                problems.append('include-outside-roots')
    return sorted(set(problems))
