"""Closed lesson vocabulary and conservative keyword-based starting tags."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TAG_LINE = re.compile(r'^<!-- tags: ([^\r\n]+) -->\r?$', re.M)
PATTERNS = {
    'method/binding': r'\bbind(?:ing|s|s?\b)|\bunbound\b',
    'method/sibling': r'\bsibling\b|fallout|\bfnv\b|\bfo4\b',
    'method/diagnostic': r'\bscore\b|\bsim\b|\bdiagnos|\bprogress\b',
    'wall/register-schedule': r'\bregister|\bschedul|\bpermut',
    'wall/flag-fold': r'\bflag|\bbit.?field|\bbit.?test',
    'wall/callee': r'\bcallee|\bcall target|\bcall set',
    'wall/control-flow': r'\bcontrol.flow|\bbranch|\bexit|\bearly return',
    'wall/layout': r'\blayout|\boffset|\bmember width|\bsize mismatch',
    'wall/inlining': r'\binlin|\bhelper boundary',
    'wall/constant': r'\bconstant|\bimmediate|\bliteral',
    'construct/destructor': r'\bdestructor|\brelease|\bcleanup',
    'construct/switch': r'\bswitch|\bdispatch|\bcase\b',
    'construct/loop': r'\bloop|\biterator|\biteration',
    'construct/float': r'\bfloat|\bdouble|\bfabs|\bsqrt',
    'construct/vector': r'\bsimd|\bvector|\bmatrix|\bquaternion',
    'construct/bitfield': r'\bbit.?field|\bbit.?test|\bflag',
    'construct/constructor': r'\bconstructor|\bconstruct(?:ion|or)',
    'construct/allocation': r'\ballocat|\boperator new|\bheap',
    'construct/serialization': r'\bserializ|\bloadgame|\bstream|\bsavegame',
    'abi/calling-convention': r'\bcalling convention|\bargument|\bparameter|\bthiscall',
    'abi/exception': r'\bunwind|\bexception|\bfunclet',
    'abi/virtual': r'\bvirtual|\bvtable|\bvftable|\bvirtual slot',
    'sibling/fnv': r'\bfnv\b|new vegas',
    'sibling/f3': r'\bf3\b|fallout 3',
    'sibling/fo4': r'\bfo4\b|fallout 4',
    'family/form-factory': r'form.?factory',
}


def vocabulary(repo=ROOT):
    return set(re.findall(r'`([a-z]+/[a-z0-9-]+)`', (Path(repo) / 'docs/lesson-tags.md').read_text()))


def infer(text):
    return {tag for tag, pattern in PATTERNS.items() if re.search(pattern, str(text), re.I)}


def parse(text, allowed):
    matches = TAG_LINE.findall(text)
    if len(matches) != 1:
        return None
    tags = {part.strip() for part in matches[0].split(',')}
    return tags if tags and tags <= allowed and '' not in tags else None
