#!/usr/bin/env python3
"""Rewrite the leading comment of reconstruction units to the compact header.

    python3 tools/compact_headers.py [--apply] [--skip-list FILE] [files or directories...]

The compact header keeps what a reader or a validator needs and drops what the records, git and
the docs already say: the full MIT text becomes the one SPDX line, label lines, `Source exposure`,
sibling and origin statements stay, a `.cpp` lists its compared functions as `// 0x<rva> <Name>`
lines, and Build, Task, Labels, Evidence, default Recipe, Drafted by, disclaimers and other prose go.

Only comments change, and a file is written only when all of this holds, otherwise it is left
as it is and reported:
- its tu-sha256-v2 text (digest_v2.strip_comments) is identical before and after, so no digest,
  record or review of the v2 kind changes;
- the file lints with no finding it did not already have, and passes the review-readiness checks
  (tools/lint_review_readiness.py) the same way.
Comments that carry provenance are kept by the same predicate the digest uses
(digest_v2.is_provenance), so what the label checker and the reviewers read is untouched.
Without --apply nothing is written.
"""
import argparse
import json
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import digest_v2  # noqa: E402
import lint_reconstruction as lint  # noqa: E402
import lint_review_readiness as readiness  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
FIELD = re.compile(r'//\s*[A-Z][A-Za-z ]{2,24}:')
KEEP_RECIPE = re.compile(r'//\s*Recipe:\s*(\S+)')
# One short statement that a GPL label's file is under the GPL; the notice's prose is not kept line by line.
GPL_MENTION = re.compile(r'GPL(?!\w)|GPL-\d')
# Statements the review-readiness lint accepts as the origin of the code (tools/lint_review_readiness.py).
ORIGIN_STATEMENT = re.compile(r'\b(?:original implementation|original reconstruction|original declarations|'
                              r'original code|original work|adapted from|derived from|reconstructed from|'
                              r'generated from)\b', re.I)
ORIGIN_FIELD = re.compile(r'^\s*(?://+)?\s*(?:body origin|implementation origin|code origin|provenance|origin)\s*:\s*\S',
                          re.I)
GENERATOR_ORIGIN = re.compile(r'//\s*Origin:\s*(\{.*\})\s*$')
NOT_COMPARED = re.compile(r'not compared|callee|called function', re.I)
RVA = re.compile(r'\bRVA 0x([0-9a-fA-F]+)')


def norm(line):
    return ' '.join(line.strip().lstrip('/').split())


def canonical_notice():
    path = ROOT / lint.LICENCE_TEXT
    return [norm(line) for line in path.read_text(encoding='utf-8').splitlines() if line.strip()]


def find_notice(lead, canon):
    """(start, end) line range of an exact NG MIT notice in `lead`, None if there is none, 'bad' if one is garbled."""
    for start, line in enumerate(lead):
        if norm(line) != 'MIT License':
            continue
        need, end = list(canon), start
        for end in range(start, len(lead)):
            text = norm(lead[end])
            if not text:
                continue
            if not need or text != need[0]:
                return 'bad'
            need.pop(0)
            if not need:
                return start, end + 1
        return 'bad'
    if any('Permission is hereby granted' in line or 'THE SOFTWARE IS PROVIDED' in line for line in lead):
        return 'bad'
    return None


def keep_line(line):
    text = line.strip()
    if digest_v2.is_provenance(text):
        return True
    # What an earlier pass wrote, so running the tool again changes nothing.
    if 'SPDX-License-Identifier' in text or lint.COMPARED_LINE.match(text):
        return True
    if GPL_MENTION.search(text) and 'licenses/' not in text and 'GNU General' not in text:
        return True
    if ORIGIN_STATEMENT.search(text) or ORIGIN_FIELD.match(text):
        return True
    recipe = KEEP_RECIPE.match(text)
    return bool(recipe and recipe.group(1) != lint.DEFAULT_RECIPE)


def inventory_names(root):
    data = json.loads((Path(root) / 'data/progress.json').read_text())
    return {fn['rva']: fn['name'] for fn in data['functions'] if fn.get('name')}


def rewrite(text, ext, names, canon):
    """(new text, None) or (None, reason)."""
    if '\r' in text:
        return None, 'crlf'
    lines = text.split('\n')
    end = 0
    while end < len(lines) and lines[end].startswith('//'):
        end += 1
    lead = lines[:end]
    if not lead:
        return None, 'no-leading-comment'
    if 'GNU GENERAL PUBLIC LICENSE' in text:
        return None, 'gpl-text'
    notice = find_notice(lead, canon)
    if notice == 'bad':
        return None, 'unrecognised-licence-text'
    out, previous_kept, gpl_seen = [], False, set()
    rvas = []
    for index, line in enumerate(lead):
        if notice and notice[0] <= index < notice[1]:
            if index == notice[0]:
                out.append('// ' + lint.SPDX_MIT)
            previous_kept = False
            continue
        if not NOT_COMPARED.search(line):
            for value in RVA.findall(line):
                if int(value, 16) not in rvas:
                    rvas.append(int(value, 16))
        origin = GENERATOR_ORIGIN.match(line)
        if origin:
            try:
                data = json.loads(origin.group(1))
                out.append(f'// Origin: {data["family"]} v{data["version"]}')
            except (ValueError, KeyError, TypeError):
                out.append(line)
            previous_kept = False
            continue
        # A wrapped statement: the kept line above opened a parenthesis it has not closed.
        continuation = (previous_kept and line.strip() not in ('//', '// ') and not FIELD.match(line)
                        and out[-1].count('(') > out[-1].count(')'))
        recipe = KEEP_RECIPE.match(line.strip())
        if recipe and recipe.group(1) != lint.DEFAULT_RECIPE:
            out.append(f'// Recipe: {recipe.group(1).rstrip(".,;")}')
            previous_kept = False
            continue
        if keep_line(line) and not digest_v2.is_provenance(line) and GPL_MENTION.search(line):
            if line[:40] in gpl_seen:
                previous_kept = False
                continue
            gpl_seen.add(line[:40])
        if keep_line(line) or continuation:
            out.append(line)
            previous_kept = True
        else:
            previous_kept = False
    if notice is None and any('CharmedBaryon/CommonLibSSE-NG@' in line and 'COMMUNITY(' in line for line in lead) \
            and not any('SPDX-License-Identifier' in line for line in out):
        out.insert(0 if not out else 1, '// ' + lint.SPDX_MIT)
    if ext == 'cpp':
        compared = []
        listed = {int(m.group(1), 16) for line in out for m in [re.match(r'//\s*0x([0-9a-fA-F]+)\b', line)] if m}
        for rva in rvas:
            if rva in listed:
                continue
            name = names.get(rva)
            compared.append(f'// 0x{rva:x} {name}' if name else f'// 0x{rva:x}')
        out += compared
    return '\n'.join(out + lines[end:]), None


def problems_of(root, name, text):
    return set(lint.lint_file(root, name, None)) | {
        f'{p}' for p in readiness.origin_statement_problems(name, text) + readiness.truncated_mit_problems(name, text)}


def process(root, rel, names, canon, apply):
    path = Path(root) / rel
    old = path.read_text(encoding='utf-8')
    new, why = rewrite(old, path.suffix[1:], names, canon)
    if new is None:
        return 'skipped', why
    if new == old:
        return 'unchanged', None
    try:
        same = digest_v2.strip_comments(old.encode(), rel) == digest_v2.strip_comments(new.encode(), rel)
    except ValueError:
        same = False
    if not same:
        return 'skipped', 'digest-text-differs'
    before = problems_of(root, rel, old)
    path.write_text(new, encoding='utf-8')
    try:
        after = problems_of(root, rel, new)
    finally:
        if not apply:
            path.write_text(old, encoding='utf-8')
    if not after <= before:
        path.write_text(old, encoding='utf-8')
        return 'skipped', 'new-lint-finding'
    return 'rewritten', f'{len(old.splitlines())}->{len(new.splitlines())}'


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--apply', action='store_true')
    p.add_argument('--root', type=Path, default=ROOT)
    p.add_argument('--skip-list', type=Path, help='file of repository paths to leave alone')
    p.add_argument('--report', type=Path, help='write the per-file outcomes here')
    p.add_argument('paths', nargs='*')
    a = p.parse_args(argv)
    root = a.root
    skip = set(a.skip_list.read_text().split()) if a.skip_list else set()
    targets = []
    for arg in a.paths or ['reconstruction']:
        base = root / arg
        found = sorted(q for q in base.rglob('*') if q.suffix in ('.h', '.cpp')) if base.is_dir() else [base]
        targets += [q.relative_to(root).as_posix() for q in found]
    names, canon = inventory_names(root), canonical_notice()
    counts, removed, reasons, rows = {}, 0, {}, []
    for rel in targets:
        if rel in skip:
            outcome, why = 'skipped', 'open-pr'
        else:
            outcome, why = process(root, rel, names, canon, a.apply)
        counts[outcome] = counts.get(outcome, 0) + 1
        if outcome == 'rewritten':
            before, after = (int(x) for x in why.split('->'))
            removed += before - after
        elif outcome == 'skipped':
            reasons[why] = reasons.get(why, 0) + 1
        rows.append(f'{rel} {outcome} {why or ""}')
    if a.report:
        a.report.write_text('\n'.join(rows) + '\n')
    print(json.dumps(dict(counts=counts, lines_removed=removed, skipped=reasons), sort_keys=True),
          'applied' if a.apply else 'dry run')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
