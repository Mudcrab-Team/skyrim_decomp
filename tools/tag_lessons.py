#!/usr/bin/env python3
"""Add initial tags to untagged lesson entries. Existing tags are left for review."""
import re
from pathlib import Path
import lesson_tags

ROOT = Path(__file__).resolve().parents[1]
ENTRY = re.compile(r'(?=^<a id="(?:rule|lesson)-\d+"></a>)', re.M)


def tag(body):
    # Title and symptom carry the subject; examples and evidence otherwise produce noisy tags.
    title = body.split('Evidence:', 1)[0]
    tags = lesson_tags.infer(title) or {'method/diagnostic'}
    return '<!-- tags: ' + ', '.join(sorted(tags)) + ' -->\n'


def main():
    for rel in ('docs/matching-cookbook.md', 'docs/near-tier-lessons.md'):
        path = ROOT / rel
        parts = ENTRY.split(path.read_text())
        for i in range(1, len(parts)):
            if not lesson_tags.TAG_LINE.search(parts[i]):
                parts[i] = re.sub(r'(^<a id="[^"]+"></a>\n)', lambda m: m[1] + tag(parts[i]), parts[i], count=1)
        path.write_text(''.join(parts))
    for path in sorted((ROOT / 'docs/cookbook-notes').glob('*.md')):
        if path.name == 'README.md':
            continue
        body = path.read_text()
        if not lesson_tags.TAG_LINE.search(body):
            path.write_text(re.sub(r'^(#[^\n]*\n)', lambda m: m[1] + '\n' + tag(body), body, count=1))


if __name__ == '__main__':
    main()
