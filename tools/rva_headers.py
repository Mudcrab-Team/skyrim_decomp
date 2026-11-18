"""RVAs a unit's header comments claim, one parser for the bot and the CI hash job.

A claim only selects which published target row to test; it never supplies a hash, a size or a
mask, so a wrong or hostile claim can at worst fail its own function.

Two spellings are read: the compact `// 0x<rva> <Name>` line of the leading comment block (one
per compared function), and the older `RVA 0x<rva>` phrase anywhere in the text.
"""
import re

CLAIM = re.compile(r'\bRVAs?\s+((?:0x[0-9a-fA-F]+)(?:(?:\s*,\s*(?:and\s+)?|\s+(?:and\s+)?)(?:0x[0-9a-fA-F]+))*)')
COMPARED = re.compile(r'//[ \t]*(0x[0-9a-fA-F]+)[ \t]+\S')


def leading_lines(text):
    """The `//` lines at the top of a file, up to the first line that is not one."""
    out = []
    for line in text.splitlines():
        if not line.startswith('//'):
            break
        out.append(line)
    return out


def claimed_rvas(texts):
    rvas = set()
    for text in texts:
        for match in CLAIM.finditer(text):
            rvas.update(int(v, 16) for v in re.findall(r'0x[0-9a-fA-F]+', match[1]))
        for line in leading_lines(text):
            match = COMPARED.match(line)
            if match:
                rvas.add(int(match[1], 16))
    return rvas
