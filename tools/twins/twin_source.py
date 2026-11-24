"""Lexical view of a reconstruction source file: top-level segments, identifiers, slicing.

Everything here is text work on this repository's own units (no game data). A unit is cut
into leading comment lines, preprocessor lines and top-level segments: a segment is one
declaration ending in `;` or one braced definition (function, class, namespace body). Strings
and comments never take part in matching, so braces inside them do not confuse the cut.
"""
from dataclasses import dataclass, field
import re

IDENT = re.compile(r'[A-Za-z_]\w*')
HEADER_LINE = re.compile(r'^//[ \t]*0x([0-9a-fA-F]+)[ \t]+(.+?)[ \t]*$')
KEYWORDS = frozenset('''alignas alignof auto bool break case catch char class const constexpr continue default delete do
double else enum explicit extern false float for friend goto if inline int long mutable namespace new noexcept nullptr
operator private protected public register return short signed sizeof static static_assert struct switch template this
throw true try typedef typename union unsigned using virtual void volatile while'''.split())


def mask_text(text):
    """`text` with comments, string and character literals replaced by spaces (same length)."""
    out = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        two = text[i:i + 2]
        if two == '//':
            j = text.find('\n', i)
            j = n if j < 0 else j
            out.append(' ' * (j - i))
            i = j
        elif two == '/*':
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(''.join(ch if ch == '\n' else ' ' for ch in text[i:j]))
            i = j
        elif c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            j = min(j + 1, n)
            out.append(c + ' ' * (j - i - 2) + c if j - i >= 2 else c)
            i = j
        else:
            out.append(c)
            i += 1
    return ''.join(out)


@dataclass
class Segment:
    start: int
    end: int
    text: str
    kind: str = 'decl'          # decl | function | class | namespace | other
    name: str = ''              # declared or defined (qualified) name where recognised
    mentions: frozenset = field(default_factory=frozenset)
    lead: str = ''              # comment lines directly above the segment


def declared_name(masked):
    """Best-effort declared name of one masked segment (qualified for definitions)."""
    head = masked.split('{', 1)[0]
    head = re.sub(r'\s+', ' ', head).strip()
    m = re.match(r'^(?:template\s*<.*?>\s*)?(?:class|struct|union|enum(?:\s+class)?)\s+(?:alignas\([^)]*\)\s*)?([A-Za-z_]\w*)', head)
    if m:
        return m.group(1), 'class'
    if head.startswith('namespace'):
        return head.split()[-1] if len(head.split()) > 1 else '', 'namespace'
    paren = head.find('(')
    if paren >= 0:
        before = head[:paren].rstrip()
        if before.endswith('operator') or re.search(r'operator\s*\S{1,3}$', before):
            m = re.search(r'((?:[A-Za-z_]\w*::)*operator\s*[^\s(]+(?:\s*\[\])?)$', before)
        else:
            m = re.search(r'((?:~?[A-Za-z_]\w*(?:<[^<>]*>)?::)*~?[A-Za-z_]\w*)$', before)
        if m:
            return m.group(1), 'function'
    m = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*$', head.split('=', 1)[0].strip().rstrip(';').strip())
    if head.startswith(('typedef', 'using')):
        m = re.search(r'([A-Za-z_]\w*)\s*(?:;|$)', head) or re.match(r'using\s+([A-Za-z_]\w*)', head)
    return (m.group(1) if m else ''), 'decl'


def segments(text):
    """Top-level segments of `text` after its leading comments and preprocessor lines."""
    masked = mask_text(text)
    out = []
    i, n = 0, len(text)
    while i < n:
        # skip blank space, comments and preprocessor lines between segments
        while i < n:
            if masked[i].isspace():
                i += 1
            elif text.startswith('//', i) or text.startswith('/*', i) or (masked[i] == ' ' and not text[i].isspace()):
                j = text.find('\n', i) if text.startswith('//', i) else text.find('*/', i)
                i = n if j < 0 else (j + 1 if text.startswith('//', i) else j + 2)
            elif masked[i] == '#':
                j = i
                while j < n and (masked[j] != '\n' or masked[j - 1] == '\\'):
                    j += 1
                i = j
            else:
                break
        if i >= n:
            break
        start, depth, j = i, 0, i
        braced = False
        while j < n:
            ch = masked[j]
            if ch == '{':
                depth += 1
                braced = True
            elif ch == '}':
                depth -= 1
                if depth == 0:
                    j += 1
                    # a class or enum definition ends with `;`; a function body does not
                    k = j
                    while k < n and masked[k].isspace():
                        k += 1
                    head = masked[start:j].split('{', 1)[0]
                    if k < n and masked[k] == ';' and not re.search(r'\)\s*(?:const|noexcept|override|final|\s)*$', head.rstrip()):
                        j = k + 1
                    elif k < n and masked[k] == ';' and re.match(r'\s*(?:typedef|struct|class|union|enum)\b', head):
                        j = k + 1
                    break
            elif ch == ';' and depth == 0:
                j += 1
                break
            j += 1
        name, kind = declared_name(masked[start:j])
        if kind == 'decl' and braced:
            kind = 'other'
        if kind == 'function' and not braced and not re.search(r'=\s*(?:default|delete)\s*;\s*$', masked[start:j]):
            kind = 'proto'
        above = text[:start].split('\n')[:-1]
        lead = []
        while above and above[-1].lstrip().startswith('//'):
            lead.insert(0, above.pop().rstrip())
        seg = Segment(start, j, text[start:j], kind, name)
        seg.lead = '\n'.join(lead)
        seg.mentions = frozenset(IDENT.findall(masked[start:j])) - KEYWORDS
        out.append(seg)
        i = j
    return out


def split_header(text):
    """(leading comment lines, rest) of a source file."""
    lines = text.split('\n')
    n = 0
    while n < len(lines) and (lines[n].startswith('//') or not lines[n].strip()):
        n += 1
    return lines[:n], '\n'.join(lines[n:])


def compared(text):
    """[(rva, declared name)] of the `// 0x<rva> Name` lines in the leading comment."""
    head, _ = split_header(text)
    out = []
    for line in head:
        m = HEADER_LINE.match(line.strip())
        if m:
            out.append((int(m.group(1), 16), re.sub(r'\s*\(.*$', '', m.group(2)).strip()))
    return out


def simple_name(qualified):
    return qualified.rsplit('::', 1)[-1]


def owner_of(qualified):
    return qualified.rsplit('::', 1)[0] if '::' in qualified else ''


def rename_identifiers(text, mapping):
    """Whole-identifier replacement of `mapping` keys in `text` (comments and strings included)."""
    if not mapping:
        return text
    pattern = re.compile(r'(?<![A-Za-z0-9_])(' + '|'.join(re.escape(k) for k in sorted(mapping, key=len, reverse=True)) + r')(?![A-Za-z0-9_])')
    return pattern.sub(lambda m: mapping[m.group(1)], text)


def render(segs):
    """Segments with their leading comments, separated by blank lines."""
    return '\n\n'.join(((s.lead + '\n') if s.lead else '') + s.text.rstrip() for s in segs)
