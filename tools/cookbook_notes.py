"""Cookbook lesson notes (docs/cookbook-notes/): the file shape, the template and the deterministic checks.

A note is words and short plain C++. The check is deliberately blunt: it refuses anything leakgrep
refuses, anything that is not the fixed template, and fenced code that is long enough to be a listing.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

import leakgrep
import lesson_tags

NOTES_DIR = 'docs/cookbook-notes/'
NOTE_FILE = re.compile(r'docs/cookbook-notes/[0-9a-f]{3,8}-[a-z0-9][a-z0-9-]{0,60}\.md\Z')
MAX_BYTES = 6000
MAX_CODE_LINES = 12
OUTCOMES = ('fixed', 'unsolved')
CAUSES = ('register-allocation', 'instruction-order', 'operand-order', 'inlining', 'loop-shape', 'branch-layout',
          'constant-folding', 'integer-width-or-cast', 'calling-convention', 'struct-layout', 'vtable-or-virtual',
          'float-codegen', 'prologue-epilogue', 'switch-lowering', 'other')
FIELDS = ('Function', 'Label', 'Outcome', 'Cause', 'Best score', 'Attempts')
SECTIONS = ('What differed', 'Spellings tried that did not help', 'Spelling that fixed it')
PLACEHOLDER = 'TODO'
FIELD_LINE = re.compile(r'- ([A-Za-z ]+): (.*)\Z')


def slug(text):
    return re.sub(r'[^a-z0-9]+', '-', text.lower()).strip('-')[:40] or 'note'


def note_path(rva, name):
    return f'{NOTES_DIR}{rva:x}-{slug(name)}.md'


def render(rva, name, label, outcome, score, attempts):
    """The template, pre-filled with what the task knows; every TODO is the drafter's to finish."""
    return '\n'.join([
        f'# 0x{rva:x} {name}',
        '',
        '<!-- tags: ' + ', '.join(sorted(lesson_tags.infer(name) or {'method/diagnostic'})) + ' -->',
        '',
        f'- Function: 0x{rva:x} {name}',
        f'- Label: {label or PLACEHOLDER + " (the label the unit declares, or none)"}',
        f'- Outcome: {outcome}',
        f'- Cause: {PLACEHOLDER} (one of: {", ".join(CAUSES)})',
        f'- Best score: {score or "not measured"}',
        f'- Attempts: {attempts}',
        '',
        '## What differed',
        '',
        f'{PLACEHOLDER}: say in words where the output departed from the target and what that suggests.',
        '',
        '## Spellings tried that did not help',
        '',
        f'{PLACEHOLDER}: one line per spelling, plain C++ or words.',
        '',
        '## Spelling that fixed it',
        '',
        f'{PLACEHOLDER}: the plain C++ that fixed it, a few lines; write "none" when the outcome is unsolved.',
        '',
    ])


def sections(text):
    """{heading: body} for the `## ` sections, and the field lines, as (fields, sections)."""
    fields, found, current = {}, {}, None
    for line in text.splitlines():
        if line.startswith('## '):
            current = line[3:].strip()
            found[current] = []
        elif current is not None:
            found[current].append(line)
        else:
            match = FIELD_LINE.fullmatch(line)
            if match:
                fields[match.group(1)] = match.group(2).strip()
    return fields, {k: '\n'.join(v).strip() for k, v in found.items()}


def validate(name, text):
    """Fixed reason codes for a note, never the text: [] when it is acceptable."""
    codes = []
    if name is not None and not NOTE_FILE.fullmatch(name):
        codes.append('bad-name')
    if len(text.encode('utf-8', 'replace')) > MAX_BYTES:
        codes.append('too-long')
    if any(code for _n, _l, code in leakgrep.scan_diff(
            '+++ b/note.md\n@@ -0,0 +1 @@\n' + ''.join('+' + line + '\n' for line in text.splitlines()))):
        codes.append('leak-pattern')
    if lesson_tags.parse(text, lesson_tags.vocabulary()) is None:
        codes.append('tags')
    fields, body = sections(text)
    if any(f not in fields for f in FIELDS) or any(s not in body for s in SECTIONS):
        codes.append('template')
    else:
        if fields['Outcome'] not in OUTCOMES:
            codes.append('outcome')
        cause = fields['Cause'].split(' ')[0]
        if cause not in CAUSES:
            codes.append('cause')
        if fields['Outcome'] == 'fixed' and body['Spelling that fixed it'].lower() in ('', 'none'):
            codes.append('fix-missing')
        if any(not value for value in body.values()):
            codes.append('empty-section')
    if PLACEHOLDER in text:
        codes.append('unfinished')
    fence = 0
    for line in text.splitlines():
        if line.startswith('```'):
            fence = -1 if fence >= 0 else 0
        elif fence < 0:
            fence -= 1
            if -fence - 1 > MAX_CODE_LINES:
                codes.append('long-code')
                break
    return sorted(set(codes))


def git_text(repo, *args):
    return subprocess.run(['git', *args], cwd=repo, check=True, capture_output=True).stdout


def write_template(a):
    """`--new`: write the pre-filled template under the checkout and print its path."""
    rva = int(a.new, 16)
    path = a.repo / (a.path or note_path(rva, a.slug or a.name or f'sub-{rva:x}'))
    if path.exists():
        print(f'{path.relative_to(a.repo)} exists; kept')
        return 1
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(render(rva, a.name or f'sub_{rva:x}', a.label, a.outcome, a.score, a.attempts))
    print(f'wrote {path.relative_to(a.repo)}; finish every TODO')
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(description='Check the cookbook notes a change adds or edits, or write a template.')
    p.add_argument('--base')
    p.add_argument('--head')
    p.add_argument('--repo', type=Path, default=Path(__file__).resolve().parents[1])
    p.add_argument('--new', metavar='RVA', help='write the template for this function instead of checking')
    p.add_argument('--name')
    p.add_argument('--slug')
    p.add_argument('--path', help=argparse.SUPPRESS)
    p.add_argument('--label')
    p.add_argument('--outcome', choices=OUTCOMES, default='unsolved')
    p.add_argument('--score')
    p.add_argument('--attempts', type=int, default=0)
    a = p.parse_args(argv)
    if a.new:
        return write_template(a)
    if not (a.base and a.head):
        p.error('give --base and --head, or --new RVA')
    rows = git_text(a.repo, 'diff', '--no-renames', '--name-only', '-z', f'{a.base}...{a.head}', '--', NOTES_DIR)
    bad = 0
    for name in filter(None, rows.decode('utf-8', 'replace').split('\0')):
        try:
            text = git_text(a.repo, 'show', f'{a.head}:{name}').decode('utf-8')
        except (subprocess.CalledProcessError, UnicodeDecodeError):
            continue
        codes = validate(name, text)
        if codes:
            bad += 1
            print(f'note {len(name)}-char path: ' + ', '.join(codes))
    print(f'cookbook_notes: {bad} refused')
    return int(bool(bad))


if __name__ == '__main__':
    sys.exit(main())
