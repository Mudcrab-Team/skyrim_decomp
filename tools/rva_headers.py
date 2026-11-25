"""RVAs a unit's header comments claim, one parser for the bot and the CI hash job.

A claim only selects which published target row to test; it never supplies a hash, a size or a
mask, so a wrong or hostile claim can at worst fail its own function.

Three spellings are read, each one naming a compared function and nothing else:

- the compact `// 0x<rva> <Name>` line of the leading comment block (one per compared function);
- a size record, `RVA 0x<rva>, <n> bytes` (also `; <n> bytes` or ` <n> bytes`), anywhere in the text;
- the label `compared at RVA 0x<rva>[, 0x<rva>...]` (or `compared RVA ...`).

An address mentioned in prose ("callees at RVAs 0x1ca490, 0x1cf0f0", "a global at RVA 0x2078a30",
"bound by hint to RVA 0x...") is a reference to another function or to data, never a claim: it would
select a target row the unit does not define and fail the PR for it.
"""
import re

ADDR = r'0x[0-9a-fA-F]+'
SIZE_RECORD = re.compile(rf'\bRVA\s+({ADDR})\s*[,;]?\s*\d+\s+bytes?\b')
COMPARED_AT = re.compile(rf'\b[Cc]ompared(?:\s+at)?\s+RVAs?\s+({ADDR}(?:(?:\s*,\s*(?:and\s+)?|\s+and\s+){ADDR})*)')
COMPARED = re.compile(r'//[ \t]*(0x[0-9a-fA-F]+)[ \t]+\S')


def leading_lines(text):
    """The `//` lines at the top of a file, allowing blank lines before and between them."""
    out = []
    for line in text.splitlines():
        line = line.lstrip()
        if not line:
            continue
        if not line.startswith('//'):
            break
        out.append(line)
    return out


def claimed_rvas(texts):
    rvas = set()
    for text in texts:
        rvas.update(int(m[1], 16) for m in SIZE_RECORD.finditer(text))
        for match in COMPARED_AT.finditer(text):
            rvas.update(int(v, 16) for v in re.findall(ADDR, match[1]))
        for line in leading_lines(text):
            match = COMPARED.match(line)
            if match:
                rvas.add(int(match[1], 16))
    return rvas
