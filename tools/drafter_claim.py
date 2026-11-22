"""Read what a contributor's PR says about who drafted it, and which functions it lists.

The PR template has one line, `Drafted by: <person>, assisted by <model> (<template hint>)`. The bot
copies the model part into each function's record so the attribution chart does not have to go back
to GitHub; the same reader backfills history from merged PR bodies. Only the contributor's own words
are returned: a person's name is dropped and nothing is inferred when the line is missing.
"""
import re

# The template keeps its hint in parentheses after the substituted value.
TEMPLATE_HINT = re.compile(r'\s*\(\s*a person, and the AI model if one wrote code\s*\)', re.I)
LINE = re.compile(r'(?im)^[\s>*-]*Drafted by:?\s*(.+?)\s*$')
ASSISTED = re.compile(r'(?i)\bassisted by\b\s*(.+)$')


def from_body(body):
    """The model or stated-origin part of the body's `Drafted by` line, or None."""
    found = LINE.search(body or '')
    if not found:
        return None
    text = TEMPLATE_HINT.sub('', found.group(1))
    assisted = ASSISTED.search(text)
    # Without "assisted by" the whole value is kept; a bare person name later classifies as no claim.
    text = (assisted.group(1) if assisted else text).strip()
    text = re.sub(r'\.(\s+\S.*)?$', '', text).strip()
    return text or None


def rvas_from_body(body, title=''):
    """RVAs the PR lists: the function table's first column, else the title's 0x... list."""
    rows = re.findall(r'(?m)^\|\s*`0x([0-9a-fA-F]+)`', body or '')
    if not rows:
        rows = re.findall(r'0x([0-9a-fA-F]{4,8})\b', title or '')
    return sorted({int(r, 16) for r in rows})
