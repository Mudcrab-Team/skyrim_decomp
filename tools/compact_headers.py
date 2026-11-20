#!/usr/bin/env python3
"""Rewrite the leading comment of reconstruction units to the compact header.

    python3 tools/compact_headers.py [--apply] [--skip-list FILE] [--base REV | --all-tree | files or directories...]

The compact header keeps what a reader or a validator needs and drops what the records, git and
the docs already say: the full MIT text becomes the one SPDX line, label lines, `Source exposure`,
sibling and origin statements stay, a `.cpp` lists its compared functions as `// 0x<rva> <Name>`
lines, and Build, Task, Labels, Evidence, default Recipe, Drafted by, disclaimers and other prose go.
A kept statement wrapped over several lines keeps all of its text (`wraps_into`): the rest of a
provenance field follows it as one line, and any other wrapped statement is joined into one line.

Only comments change, and a file is written only when all of this holds, otherwise it is left
as it is and reported:
- its tu-sha256-v2 text (digest_v2.strip_comments) is identical before and after, so no digest,
  record or review of the v2 kind changes;
- the file lints with no finding it did not already have, and passes the review-readiness checks
  (tools/lint_review_readiness.py) the same way.
Comments that carry provenance are kept by the same predicate the digest uses
(digest_v2.is_provenance), so what the label checker and the reviewers read is untouched.
Without --apply nothing is written.
With no path it takes the .h and .cpp files under reconstruction/ that this checkout changed against
origin/main (committed, modified or untracked), lists them, and touches nothing else; --base picks
another revision. Rewriting the whole tree needs the explicit --all-tree.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess
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
SENTENCE_END = ('.', ';', ':', '!', '?')
# The start of a label line, `object: GUESS(low)` or `a, b: COMMUNITY(...)`.
NAMES_THEN_COLON = re.compile(r'[A-Za-z_~:][\w:~<>]*(?:\s*,\s*[\w:~<>]+)*\s*:\s')
# Words a wrapped header line ends on when the clause goes on in the next line.
OPEN_ENDING = re.compile(r'(?:,|\b(?:a|an|and|are|as|at|be|between|but|by|for|from|in|into|is|its|nor|of|on|or|over|'
                         r'per|than|that|the|their|through|to|under|via|was|were|which|whose|with|without))$', re.I)


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


def wraps_into(previous, line):
    """True when `line` carries on the statement `previous` left unfinished: `previous` opened a
    parenthesis it has not closed, or it ends without closing punctuation and `line` starts the way
    only the middle of a sentence does (lower case, an opening bracket) or `previous` ends on a
    comma or a word that cannot end a clause. A capitalised line after a finished-looking one
    (`GUESS(low) STANDIN`, `Source exposure: binary-analysis`) is a new statement, not a wrap, and
    so is a `name, name: LABEL` line unless the line above ends its list with a comma."""
    before = norm(previous)
    if before.count('(') > before.count(')'):
        return True
    after = norm(line)
    if not before or not after or before.endswith(SENTENCE_END):
        return False
    if NAMES_THEN_COLON.match(after) and not before.endswith(','):
        return False
    return after[0].islower() or after[0] in '([{' or bool(OPEN_ENDING.search(before))


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
    # `glued`: lines that must stay right after the line above; `dropped`: the lines dropped since
    # the last kept or blank line, in case a kept line turns out to finish one of their statements.
    rvas, glued, dropped = [], set(), []
    for index, line in enumerate(lead):
        if line.strip() in ('//', '') or (notice and notice[0] <= index < notice[1]):
            dropped = []
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
            previous_kept, dropped = False, []
            continue
        # A wrapped statement: the kept line above stops mid-sentence, so this line is the rest of
        # it. Dropping it would leave a provenance field cut off in the middle of a clause.
        continuation = (previous_kept and line.strip() not in ('//', '// ') and not FIELD.match(line)
                        and 'SPDX-License-Identifier' not in out[-1] and not lint.COMPARED_LINE.match(out[-1].strip())
                        and wraps_into(out[-1], line))
        recipe = KEEP_RECIPE.match(line.strip())
        if recipe and recipe.group(1) != lint.DEFAULT_RECIPE:
            out.append(f'// Recipe: {recipe.group(1).rstrip(".,;")}')
            previous_kept, dropped = False, []
            continue
        if keep_line(line) and not digest_v2.is_provenance(line) and GPL_MENTION.search(line):
            if line[:40] in gpl_seen:
                previous_kept, dropped = False, []
                continue
            gpl_seen.add(line[:40])
        if keep_line(line) or continuation:
            # The lines of one wrapped statement become one line where the digest allows it: a
            # provenance line is hashed as written, so the rest of a wrapped provenance field
            # becomes one more line, and any other statement is joined whole.
            if continuation and not keep_line(line) and not digest_v2.is_provenance(out[-1]):
                out[-1] = out[-1].rstrip() + ' ' + norm(line)
                previous_kept = True
                continue
            if continuation and not keep_line(line):
                glued.add(len(out))
            elif (dropped and 'SPDX-License-Identifier' not in line and not lint.COMPARED_LINE.match(line.strip())
                  and wraps_into(dropped[-1], line)):
                # A kept line that starts mid-sentence: bring back the dropped start of the
                # statement so the kept part is not read out of context.
                start = len(dropped) - 1
                while start and wraps_into(dropped[start - 1], dropped[start]):
                    start -= 1
                head = ' '.join([dropped[start].rstrip()] + [norm(x) for x in dropped[start + 1:]])
                if digest_v2.is_provenance(line):
                    out.append(head)
                    glued.add(len(out))
                else:
                    line = head + ' ' + norm(line)
            dropped = []
            out.append(line)
            previous_kept = True
        else:
            if line.strip() not in ('//', ''):
                dropped.append(line)
            previous_kept = False
    if notice is None and any('CharmedBaryon/CommonLibSSE-NG@' in line and 'COMMUNITY(' in line for line in lead) \
            and not any('SPDX-License-Identifier' in line for line in out):
        # After the first statement, never between a wrapped statement's lines.
        at = 0 if not out else 1
        while at in glued:
            at += 1
        out.insert(at, '// ' + lint.SPDX_MIT)
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


def changed_units(root, base='origin/main'):
    """Reconstruction .h/.cpp files this checkout changed since it left `base`; None if git cannot say."""
    def git(*args):
        proc = subprocess.run(['git', *args], cwd=root, capture_output=True, text=True)
        return proc.stdout.splitlines() if proc.returncode == 0 else None
    fork = git('merge-base', base, 'HEAD')
    if not fork:
        return None
    committed = git('diff', '--name-only', '--diff-filter=ACMR', fork[0], '--', 'reconstruction')
    fresh = git('ls-files', '--others', '--exclude-standard', '--', 'reconstruction')
    if committed is None or fresh is None:
        return None
    return sorted(n for n in {*committed, *fresh} if n.endswith(('.h', '.cpp')) and (root / n).is_file())


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--apply', action='store_true')
    p.add_argument('--root', type=Path, default=ROOT)
    p.add_argument('--skip-list', type=Path, help='file of repository paths to leave alone')
    p.add_argument('--report', type=Path, help='write the per-file outcomes here')
    p.add_argument('--base', default='origin/main', help='default scope: files changed against this revision')
    p.add_argument('--all-tree', action='store_true', help='rewrite every unit under reconstruction/')
    p.add_argument('paths', nargs='*')
    a = p.parse_args(argv)
    root = a.root
    skip = set(a.skip_list.read_text().split()) if a.skip_list else set()
    targets = []
    paths = a.paths
    if a.all_tree and paths:
        p.error('--all-tree takes no paths')
    if a.all_tree:
        paths = ['reconstruction']
    elif not paths:
        paths = changed_units(root, a.base)
        if paths is None:
            p.error(f'cannot tell what changed against {a.base}; give file paths, or --all-tree for the whole tree')
        print(f'{len(paths)} file(s) changed against {a.base}:', *paths, sep='\n  ' if paths else '')
        if not paths:
            print('nothing to do')
            return 0
    for arg in paths:
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
