#!/usr/bin/env python3
"""Alternative compile flag sets a failed compare is retried under (`accept_also`).

    python3 tools/recipe_alternatives.py check                  # registry and recipe files agree
    python3 tools/recipe_alternatives.py generate               # write the alternative recipe files
    python3 tools/recipe_alternatives.py list [<recipe>]        # what is tried after a failed compare
    python3 tools/recipe_alternatives.py eh <image> <rva> <size> # whether the image has an exception frame there

A recipe is one flag set, and a function's record binds the recipe file by path and hash. So an
alternative flag set is a recipe file of its own (the base recipe's flags with the declared changes),
and `data/recipe-alternatives.json` lists, per base recipe, the alternatives to try in order. Nothing in
an existing recipe changes, so no accepted record goes stale.

What a retry decides: after a function fails under the unit's recipe, `./sr compare` and
`tools/verifier/attempt` compile the unit again under each listed alternative that applies to the
function and compare it. A pass prints `MATCH (under <flags>)` and the `Recipe:` line to add. It is
advisory and never a pass of its own: the unit is accepted under the flags only once it names the
alternative recipe in its own `Recipe:` line, because the CI hash job and the second host compile the
unit with the recipe it names (tools/ci_target_hash_check.py reads that line, and the target-hash
manifest approves each recipe file by hash). The recorded acceptance therefore names the flags used,
and a byte match under them is still a byte match.

`requires` limits which functions a retry is spent on. `target-no-eh-frame`: the pinned image's unwind
data gives the function no exception handler, so a unit built without `/EHsc` is a candidate for it.
The condition only saves compiles; the byte comparison alone decides.
"""
import argparse
import bisect
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pecoff import PeImage, Reject, UNW_FLAG_EHANDLER, UNW_FLAG_UHANDLER  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
REGISTRY = 'data/recipe-alternatives.json'
REQUIRES = ('target-no-eh-frame',)
# The base recipes an alternative is generated for, and each alternative's id and change.
GENERATED = {
    'noeh': dict(remove=['/EHsc'], add=[], suffix='noeh', requires='target-no-eh-frame'),
}
BASES = ('msvc-19.16.27054-o2', 'o2-fpfast', 'o2-os')
VARIANTS = ('', '-reconstruction', '-root-includes')


def recipe_path(base, alt_id, variant):
    return f'reconstruction/recipes/{base}-{GENERATED[alt_id]["suffix"]}{variant}.json'


def derived(base_recipe, remove, add):
    """The alternative recipe's content: the base's flags without `remove` and with `add` appended."""
    flags = [f for f in base_recipe['flags'] if f not in remove] + list(add)
    return dict(base_recipe, flags=flags)


def expected_registry():
    alternatives = {}
    for base in BASES:
        for variant in VARIANTS:
            rows = []
            for alt_id, spec in GENERATED.items():
                rows.append(dict(id=alt_id, recipe=recipe_path(base, alt_id, variant), remove=spec['remove'],
                                 add=spec['add'], requires=spec['requires']))
            alternatives[f'reconstruction/recipes/{base}{variant}.json'] = dict(accept_also=rows)
    return dict(schema=1, alternatives=alternatives)


def dump(value):
    return json.dumps(value, indent=2) + '\n'


def generate(root=ROOT):
    """Write the alternative recipe files and the registry; returns the paths written."""
    root = Path(root)
    written = []
    registry = expected_registry()
    for base_path, entry in registry['alternatives'].items():
        base = json.loads((root / base_path).read_text())
        for alt in entry['accept_also']:
            target = root / alt['recipe']
            text = dump(derived(base, alt['remove'], alt['add']))
            if not target.is_file() or target.read_text() != text:
                target.write_text(text)
                written.append(alt['recipe'])
    path = root / REGISTRY
    path.parent.mkdir(parents=True, exist_ok=True)
    if not path.is_file() or path.read_text() != dump(registry):
        path.write_text(dump(registry))
        written.append(REGISTRY)
    return written


def load(root=ROOT):
    path = Path(root) / REGISTRY
    if not path.is_file():
        return dict(schema=1, alternatives={})
    return json.loads(path.read_text())


def problems(root=ROOT):
    """Why the registry does not describe the recipe files exactly, as a list of words."""
    root = Path(root)
    registry = load(root)
    found = []
    if registry.get('schema') != 1 or not isinstance(registry.get('alternatives'), dict):
        return ['registry: schema must be 1 with an alternatives object']
    seen = set()
    for base_path, entry in sorted(registry['alternatives'].items()):
        base_file = root / base_path
        if not base_file.is_file():
            found.append(f'{base_path}: base recipe does not exist')
            continue
        base = json.loads(base_file.read_text())
        rows = entry.get('accept_also') if isinstance(entry, dict) else None
        if not isinstance(rows, list) or not rows:
            found.append(f'{base_path}: accept_also must be a non-empty list')
            continue
        for alt in rows:
            where = f'{base_path} -> {alt.get("id")}'
            if set(alt) != {'id', 'recipe', 'remove', 'add', 'requires'}:
                found.append(f'{where}: keys must be id, recipe, remove, add, requires')
                continue
            if alt['requires'] not in REQUIRES:
                found.append(f'{where}: unknown requires {alt["requires"]!r}')
            if alt['recipe'] == base_path or alt['recipe'] in seen:
                found.append(f'{where}: recipe {alt["recipe"]} repeats')
            seen.add(alt['recipe'])
            if not any(f in base['flags'] for f in alt['remove']) and not alt['add']:
                found.append(f'{where}: changes no flag')
            target = root / alt['recipe']
            if not target.is_file():
                found.append(f'{where}: recipe file {alt["recipe"]} does not exist')
                continue
            recipe = json.loads(target.read_text())
            if recipe != derived(base, alt['remove'], alt['add']):
                found.append(f'{where}: {alt["recipe"]} is not the base recipe with exactly the declared flag change')
            for key in ('compiler', 'sdk'):
                if recipe.get(key) != base.get(key):
                    found.append(f'{where}: {key} differs from the base recipe')
    return found


def alternatives(root, recipe_rel):
    """The ordered alternatives to try after a failed compare under `recipe_rel` (a repository-relative path)."""
    entry = load(root)['alternatives'].get(str(recipe_rel).replace('\\', '/'))
    return list(entry['accept_also']) if entry else []


def flags_of(root, recipe_rel):
    return json.loads((Path(root) / recipe_rel).read_text())['flags']


def change_text(alt):
    parts = [f'without {f}' for f in alt['remove']] + [f'with {f}' for f in alt['add']]
    return ' and '.join(parts)


def match_line(root, alt):
    """`MATCH (under <flags>)` for an alternative that byte-matched, with the line that makes it count."""
    flags = ' '.join(flags_of(root, alt['recipe']))
    return (f'MATCH (under {flags}; {change_text(alt)}). Advisory: it counts once the unit names the flags, '
            f'with `Recipe: {alt["recipe"]}` in its header, which applies to every function in the unit.')


class EhFrames:
    """Which functions of an image have an exception handler in their unwind data."""

    def __init__(self, image):
        self.image = image
        entries = sorted(image.runtime_functions())
        self.begins = [b for b, _e, _u in entries]
        self.entries = entries
        self.cache = {}

    @classmethod
    def from_bytes(cls, blob):
        return cls(PeImage(blob))

    def unwind_flags(self, unwind):
        head = self.image.read(unwind, 1, 'unwind info')[1][0]
        return head >> 3 if head & 0x7 == 1 else 0

    def has_handler(self, rva, size):
        """True when a `.pdata` entry that starts inside [rva, rva + size) names an exception or termination handler."""
        key = (rva, size)
        if key not in self.cache:
            found = False
            i = bisect.bisect_left(self.begins, rva)
            while i < len(self.entries) and self.entries[i][0] < rva + size:
                try:
                    if self.unwind_flags(self.entries[i][2]) & (UNW_FLAG_EHANDLER | UNW_FLAG_UHANDLER):
                        found = True
                        break
                except Reject:
                    found = True  # unreadable unwind data: cannot say there is no frame, so do not narrow
                    break
                i += 1
            self.cache[key] = found
        return self.cache[key]


def applies(alt, frames, rva, size, force=False):
    """Whether a retry under `alt` is worth a compile for the function at `rva`; True when it cannot be judged.

    `force` ignores `requires`, to measure how much the condition leaves out."""
    if force:
        return True
    if alt['requires'] == 'target-no-eh-frame':
        return frames is None or not frames.has_handler(rva, size)
    return True


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)
    sub.add_parser('check')
    sub.add_parser('generate')
    q = sub.add_parser('list')
    q.add_argument('recipe', nargs='?')
    e = sub.add_parser('eh')
    e.add_argument('image', type=Path)
    e.add_argument('rva')
    e.add_argument('size')
    a = p.parse_args(argv)
    if a.cmd == 'generate':
        for name in generate():
            print('wrote', name)
        return 0
    if a.cmd == 'check':
        found = problems()
        for line in found:
            print(line)
        print(f'{len(load()["alternatives"])} base recipes with alternatives; '
              + ('no problems' if not found else f'{len(found)} problem(s)'))
        return int(bool(found))
    if a.cmd == 'list':
        rows = load()['alternatives']
        for base in ([a.recipe] if a.recipe else sorted(rows)):
            for alt in alternatives(ROOT, base):
                print(f'{base} -> {alt["recipe"]} ({change_text(alt)}; requires {alt["requires"]})')
        return 0
    frames = EhFrames.from_bytes(a.image.read_bytes())
    print('exception handler in unwind data' if frames.has_handler(int(a.rva, 0), int(a.size, 0))
          else 'no exception frame')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
