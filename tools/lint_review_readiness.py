#!/usr/bin/env python3
"""Mechanical pre-review checks; never a substitute for the Reviewer's four blocking grounds.

Runs existing reconstruction lint plus explicit origin, complete notices, recognizable decompiler
identifiers and overbroad match claims. Semantic plausibility and provenance still need review.
This tool does not change any validator or acceptance predicate.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

import lint_reconstruction as existing


def origin_statement_problems(name, text):
    header = existing.leading_comment(text)
    statement = re.search(r'\b(?:original implementation|original reconstruction|original declarations|'
                          r'original code|original work|adapted from|derived from|reconstructed from|generated from)\b', header, re.I)
    # A name-origin label or "Source exposure" alone says nothing about the code's origin.
    explicit = re.search(r'^\s*(?://+|/\*+|\*+)?\s*(?:body origin|implementation origin|code origin|provenance|origin)\s*:\s*\S',
                         header, re.I | re.M)
    if not explicit and not statement:
        return [f'{name}: missing reconstruction origin statement in leading header']
    return []


def truncated_mit_problems(name, text):
    problems = []
    for run in existing.comment_runs(text):
        joined = existing.normalised(' '.join(run))
        if not re.search(r'\b(?:MIT licen[cs]e|permission is hereby|the software is provided|in no event shall)\b', joined, re.I):
            continue
        start = joined.find(existing.MIT_BODY_START)
        end = joined.find(existing.MIT_BODY_END, max(start, 0))
        complete = start >= 0 and end >= 0 and 'Copyright' in joined[:start]
        if complete:
            body = joined[start:end + len(existing.MIT_BODY_END)]
            complete = hashlib.sha256(body.encode()).hexdigest() == existing.MIT_BODY_SHA256
        if not complete:
            problems.append(f'{name}: truncated or altered MIT notice; retain the complete copyright, permission and disclaimer')
    return problems


def plausible_source_problems(name, text):
    markers = re.findall(r'\b(?:undefined(?:1|2|4|8)|param_\d+|local_[0-9a-f]+|(?:FUN|DAT)_[0-9a-fA-F]+)\b', text)
    return [f'{name}: check plausible_source: decompiler identifier {marker}' for marker in sorted(set(markers))]


def claim_scope_problems(name, text):
    # Only explicit claims, not ordinary descriptions of the reconstructed operation.
    claims = re.findall(r'\b(?:(?:proves|guarantees|establishes)\s+(?:(?:full|complete)\s+)?'
                        r'(?:semantic equivalence|behavio(?:u)?ral equivalence|gameplay parity|name correctness)'
                        r'|semantically equivalent to (?:Skyrim|the target|the game))\b', text, re.I)
    return [f'{name}: check claim_scope: claim exceeds the checked byte match: {claim}' for claim in claims]


def lint_files(root, names, included_only=None):
    """included_only: headers pulled in by a compiled unit but never compiled as one. They are shared
    declarations, so only the unit's own leading header must state a code origin. When not given, a
    header without a same-named .cpp is treated that way."""
    root = Path(root).resolve()
    problems = []
    for name in sorted(set(names)):
        path = root / name
        if path.suffix not in ('.h', '.cpp'):
            continue
        if not path.resolve().is_relative_to(root) or not path.is_file():
            problems.append(f'{name}: source path missing or outside repository')
            continue
        text = path.read_text()
        if path.suffix != '.h':
            shared = False
        elif included_only is None:
            shared = not path.with_suffix('.cpp').is_file()
        else:
            shared = name in included_only
        if not shared:
            problems += [f'check provenance: {p}' for p in origin_statement_problems(name, text)]
        problems += [f'check publication_hygiene: {p}' for p in truncated_mit_problems(name, text)]
        problems += plausible_source_problems(name, text)
        problems += claim_scope_problems(name, text)
    return problems


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=existing.ROOT)
    parser.add_argument('--functions', nargs='+')
    parser.add_argument('files', nargs='*')
    args = parser.parse_args(argv)
    names = list(args.files)
    try:
        if args.functions:
            data = json.loads((args.root / 'data/progress.json').read_text())
            wanted = set(args.functions)
            selected = []
            by_name = {}
            for fn in data['functions']:
                for name in {fn['id'], hex(fn['rva'])}:
                    by_name.setdefault(name, []).append(fn)
            for value in sorted(wanted):
                matches = by_name.get(value, [])
                if len(matches) != 1:
                    raise ValueError(f'{value}: expected exactly one function identity; found {len(matches)}')
                selected += matches
            for fn in selected:
                record = json.loads((args.root / fn['report']).read_text())
                names += record['source']['translation_unit']
        if not names:
            parser.error('supply files or --functions')
        problems = existing.lint_tree(args.root, sorted(set(names))) + lint_files(args.root, names)
    except (ValueError, OSError, KeyError) as error:
        problems = [str(error)]
    for problem in problems:
        print(problem)
    return 1 if problems else 0


if __name__ == '__main__':
    raise SystemExit(main())
