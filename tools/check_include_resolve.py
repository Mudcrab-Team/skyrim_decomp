#!/usr/bin/env python3
"""Fast static check that every accepted unit still resolves its includes under its own recipe.

A recipe without `/I reconstruction` finds a header outside the including file's directory only
through a relative spelling such as "../area/X.h". Rewriting such includes to the root-relative form
leaves every tu-sha256-v2 digest unchanged (an include is a fixed token there) yet makes the unit
fail to compile. This resolves each quoted include as the compiler would (includer's directory, then
the directories of the files that opened it, then the recipe's `/I` roots) with the cached closure
walk shared across units, so a scan of all accepted units takes seconds; the per-unit scan in
tools/verifier/pipeline.py (compiler_include_problem) is far too slow at that scale.
"""
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import record_store
import sparse_checkouts as sparse
from check_source_digest import include_closure, source_digest_cache
from verifier.pipeline import recipe_include_roots

ROOT = Path(__file__).resolve().parents[1]


def accepted_units(root):
    """{(compiled, recipe path): [function ids]} for every matched inventory entry with a record."""
    root = Path(root)
    data = json.loads((root / 'data/progress.json').read_text())
    units = {}
    for fn in data['functions']:
        if fn.get('status') != 'matched' or not fn.get('report'):
            continue
        try:
            record = json.loads(record_store.read_text(root / fn['report']))
            key = (record['source']['compiled'], record['recipe']['path'])
        except (OSError, ValueError, KeyError, TypeError):
            key = (None, fn['report'])
        units.setdefault(key, []).append(fn['id'])
    return units


def check_units(root, units):
    """Problems as (unit, function ids, reason), one per unit that cannot resolve an include."""
    root = Path(root)
    problems, roots_by_recipe = [], {}
    with source_digest_cache():
        for (compiled, recipe), ids in sorted(units.items(), key=lambda kv: (str(kv[0][0]), kv[0][1])):
            if compiled is None:
                problems.append((recipe, ids, 'match record is unreadable or lacks source.compiled/recipe.path'))
                continue
            if recipe not in roots_by_recipe:
                try:
                    flags = json.loads((root / recipe).read_text()).get('flags') or []
                    roots_by_recipe[recipe] = recipe_include_roots(flags)
                except (OSError, ValueError) as exc:
                    roots_by_recipe[recipe] = exc
            roots = roots_by_recipe[recipe]
            if isinstance(roots, Exception):
                problems.append((compiled, ids, f'recipe {recipe} unreadable: {roots}'))
                continue
            try:
                include_closure(root, compiled, roots)
            except (ValueError, OSError) as exc:
                problems.append((compiled, ids, f'{exc} (recipe {recipe}; /I roots: {", ".join(roots) or "none"})'))
    return problems


def run(root=ROOT):
    """Print one line per failing unit; return how many there are."""
    problems = check_units(root, accepted_units(root))
    for unit, ids, reason in problems:
        print(f'FAIL: unit {unit}: {reason} [{len(ids)} accepted function(s), e.g. {ids[0]}]', file=sys.stderr)
    return len(problems)


def main():
    with sparse.full(ROOT):
        failures = run(ROOT)
    if failures:
        print(f'FAIL: {failures} accepted unit(s) cannot resolve their includes under their own recipe', file=sys.stderr)
        return 1
    print('PASS: every accepted unit resolves its includes under its own recipe')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
