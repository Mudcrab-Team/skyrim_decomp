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
    fence = 0
    for line in text.splitlines():
        if line.lstrip().startswith('```'):
            fence = -1 if fence >= 0 else 0
        elif fence < 0:
            fence -= 1
            if -fence - 1 > MAX_CODE_LINES:
                codes.append('long-code')
                break
    return sorted(set(codes))


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
