"""Findings (findings/*.md) taken by the bot without a human: the file shape and the deterministic checks.

A finding is prose about static research. The check is blunt on purpose: it refuses what leakgrep
refuses, fenced code long enough to be a listing, blob-like tokens, and a file that does not state its
method, exposure, confidence, limitations and that it is static. Whether the claims are honest is the
model review's question; this only keeps the review from being asked about a file with no claims.
"""
import re
from pathlib import Path

import leakgrep

FINDING_FILE = leakgrep.FINDING_FILE
MAX_BYTES = 150_000
MAX_CODE_LINES = 12
# A longer block is allowed only when it is a block of formulas; this caps even those.
MAX_FORMULA_LINES = 60
MIN_ASSIGNED = 0.5
# Fence labels that announce code; a long block under one is a listing whatever its lines look like.
CODE_LANGS = frozenset('c cpp c++ cc cxx h hpp asm nasm x86 x64 s hlsl glsl cs java rust rs go js ts py python sh bash'.split())
SHADER_OPS = ('mov movc add mul mad dp2 dp3 dp4 min max sqrt rsq rcp exp log frc sample sample_l ld lt ge eq ne and or '
              'xor itof ftou utof ftoi round_ni round_pi round_z').split()
# Lines that read as a listing, not as a formula. Instruction text and byte runs are also refused by leakgrep at
# any length; these catch what a long block can hide between formulas: address-prefixed lines, shader assembly,
# and ended statements of verbatim code.
LISTING = (
    re.compile(r'^\s*(?:0x)?[0-9a-f]{6,16}:?\s+(?:[0-9a-f]{2}\s+){2,}', re.I),
    re.compile(r'^\s*(?:0x)?[0-9a-f]{6,16}:\s+\S', re.I),
    re.compile(r'(?:^|[\s,])(?:[0-9a-f]{2}[ ,:-]){7}[0-9a-f]{2}\b', re.I),
    re.compile(r'^\s*(?:%s)\s+[rvotc]\d+[.\[]?|^\s*dcl_\w+|^\s*(?:ps|vs)_\d_\d\b' % '|'.join(SHADER_OPS)),
    re.compile(r'[;{}]\s*(?://.*)?$'),
    re.compile(r'^\s*(?:#\s*(?:include|define|pragma)|(?:if|for|while|switch|return|else)\b\s*[({]?|\w+\s*\*+\s*\w+\s*=)'),
)
MAX_TOKEN = 200
# Each required statement and a pattern for the word that carries it.
REQUIRED = (('static', re.compile(r'\bstatic(?:ally)?\b', re.I)),
            ('method', re.compile(r'\bmethod', re.I)),
            ('exposure', re.compile(r'\bsource exposure\b|\bexposure\b', re.I)),
            ('confidence', re.compile(r'\bconfidence\b', re.I)),
            ('limitations', re.compile(r'\blimitation|\bnegative results\b|\bunverified\b', re.I)))


def validate(name, text):
    """Fixed reason codes for a finding, never the text: [] when it is acceptable."""
    codes = []
    if name is not None and not FINDING_FILE.fullmatch(name):
        codes.append('bad-name')
    if len(text.encode('utf-8', 'replace')) > MAX_BYTES:
        codes.append('too-long')
    if '\0' in text:
        codes.append('binary')
    diff = '+++ b/' + (name or 'findings/x.md') + '\n@@ -0,0 +1 @@\n' + ''.join(
        '+' + line + '\n' for line in text.splitlines())
    if leakgrep.scan_diff(diff):
        codes.append('leak-pattern')
    for code, rx in REQUIRED:
        if not rx.search(text):
            codes.append(f'missing-{code}')
    if re.search(r'[^\s|`]{%d,}' % MAX_TOKEN, text):
        codes.append('blob')
    if any(len(block) > MAX_CODE_LINES and not formulas(label, block) for label, block in fenced_blocks(text)):
        codes.append('long-code')
    return sorted(set(codes))


def fenced_blocks(text):
    """(label, lines) of every fenced block; an unclosed block runs to the end."""
    blocks, label, block = [], None, None
    for line in text.splitlines():
        if line.lstrip().startswith('```'):
            if block is None:
                label, block = line.lstrip()[3:].strip().split(' ')[0].lower(), []
            else:
                blocks.append((label, block))
                block = None
        elif block is not None:
            block.append(line)
    if block is not None:
        blocks.append((label, block))
    return blocks


def formulas(label, lines):
    """Whether a long fenced block is derived equations: mostly assignments, nothing that reads as a listing.

    Continuation lines (indented under an assignment) belong to it. The size is still capped, so a long
    verbatim passage cannot pass by being sprinkled with equals signs.
    """
    body = [line for line in lines if line.strip()]
    if label in CODE_LANGS or len(body) > MAX_FORMULA_LINES:
        return False
    if any(rx.search(line) for line in body for rx in LISTING):
        return False
    starts = [line for line in body if not line[:1].isspace()] or body
    assigned = [line for line in starts if re.search(r'(?<![=<>!])=(?!=)', line)]
    return len(assigned) >= MIN_ASSIGNED * len(starts)


CODES = {
    'bad-name': 'the file name must be findings/<lowercase-words>.md',
    'too-long': 'the file is too large for a single finding',
    'binary': 'the file is not plain text',
    'leak-pattern': 'a line matches the leak scan (bytes, disassembly, decompiler names or a host path)',
    'blob': 'a token is long enough to be encoded data',
    'long-code': 'a fenced block is long enough to be a listing',
    'missing-static': 'the finding does not say that its evidence is static',
    'missing-method': 'the finding does not describe its method',
    'missing-exposure': 'the finding does not declare its source exposure',
    'missing-confidence': 'the finding states no confidence',
    'missing-limitations': 'the finding states no limitations or unverified claims',
}


def read(path):
    return Path(path).read_text(encoding='utf-8')
