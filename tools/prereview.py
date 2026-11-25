#!/usr/bin/env python3
"""Deterministic consistency checks that run before any model review (pr-check `scope`, the bot, `contrib submit`).

    python3 tools/prereview.py --base <sha> --head <sha>

None of this replaces the Reviewer or the comparator; it refuses early what a Reviewer would reject
for a reason a program can see: a unit that fails the source lint or the readiness lint, a recipe
the unit names that does not exist, a body close to a community or sibling body that the header does
not declare, and a comparator report or CI row that does not bind the unit as it is on disk. Each
finding says what to change. The acceptance rule (byte match on two hosts plus one review) is untouched.

The CLI reads the unit files of the PR head from git as data and prints only safe path names, so a
hostile path never reaches the log.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
import header_check  # noqa: E402
import lint_reconstruction  # noqa: E402
import lint_review_readiness  # noqa: E402
from git_context import blobs, lint_dependencies, tree_entries  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
SAFE = re.compile(r'reconstruction/[A-Za-z0-9_./+-]+')
RECIPE = re.compile(r'\breconstruction/recipes/[a-zA-Z0-9_.-]+\.json')
DEFAULT_RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'

HOSTS_AGREE = 'both hosts compiled the same source'
DIGEST_FACTS = ('source revision equals the tu digest and unit path',
                'second-host source digest equals the tu digest')

# What to do about each binding fact that disagrees. The first group is the contributor's to fix; the
# second is the bot's own host configuration, which a PR cannot change, so it is never shown on a PR.
BINDING_ADVICE = {
    'source revision equals the tu digest and unit path':
        'the source the verifier compared is not the unit as pushed (a shared header usually changed on main '
        'since your branch point): merge current main into your branch, compare again, push',
    'recipe hash equals the recipe file':
        'the recipe the verifier used is not the recipe file the unit names: keep the `Recipe:` line and '
        'reconstruction/recipes/ consistent, then compare again',
    'second-host source digest equals the tu digest':
        'the CI hash run compiled different source than the unit as pushed: merge current main into your '
        'branch and push again so the run starts from the current base',
    HOSTS_AGREE:
        'the local compare and the CI hash run compiled different source (the branch is behind main or a shared '
        'header differs): merge current main into your branch and push',
    'second-host recipe hash equals the recipe the job selects':
        'the CI hash run used a different recipe than the unit names (a `// CI hash:` request line is '
        'compiled with the default recipe): align the `Recipe:` line with the recipe the request needs',
}
BOT_SIDE_FACTS = ('result pass', 'compiler hash equals the pinned cl.exe', 'target image equals builds/target.json')


def safe_name(name):
    return name if SAFE.fullmatch(name) else 'reconstruction/<unprintable path>'


def readiness_problems(root, name, text, included_only=None):
    """Readiness and recipe findings for a single source file."""
    if included_only is None:
        included_only = {name} if name.endswith('.h') else set()
    problems = lint_review_readiness.lint_files(root, [name], included_only)
    if name.endswith('.cpp'):
        for recipe in dict.fromkeys(RECIPE.findall(text)):
            if not (root / recipe).is_file():
                problems.append(f'{name}: names recipe {recipe}, which does not exist; '
                                'fix: name a recipe under reconstruction/recipes/')
    return problems


def staged_problems(repo, exported, names):
    """Check the exported index files with HEAD as the header baseline."""
    problems = []
    for name in names:
        text = (exported / name).read_text(encoding='utf-8', errors='replace')
        problems += header_check.file_problems(name, text, header_check.blob(repo, 'HEAD', name))
        problems += readiness_problems(exported, name, text)
    return problems


def unit_findings(root, names, build_id):
    """[(file, message)] from the source lint and the readiness lint on unit files.

    Both linters already run in contributor intake; running them here puts the same findings in front
    of the contributor before a review is paid for.
    """
    root = Path(root)
    names = sorted({n for n in names if n.endswith(('.h', '.cpp'))})
    found = []
    for name in names:
        try:
            lines = lint_reconstruction.lint_file(root, name, build_id)
            text = (root / name).read_text(errors='replace')
            lines += readiness_problems(root, name, text)
        except (OSError, ValueError) as exc:
            found.append((name, f'{name}: cannot be read for lint ({type(exc).__name__})'))
            continue
        found += [(name, line) for line in lines]
    return sorted(set(found))


def unit_problems(root, names, build_id):
    return sorted({line for _name, line in unit_findings(root, names, build_id)})


def binding_facts(report, row, digest, cpp, recipe_sha, ci_recipe_sha, compiler_pin, image_sha):
    """{fact: bool} for one function's comparator report and CI row against the unit and the pins.

    `report` is the first host's comparator report (or None), `row` the CI job's row for the function
    (or None). A missing report or row yields no facts for that host; the callers decide what an
    absence means.
    """
    facts = {}
    if report is not None:
        src, rec, tgt = report.get('source') or {}, report.get('recipe') or {}, report.get('target') or {}
        facts.update({
            'result pass': report.get('result') == 'pass',
            'source revision equals the tu digest and unit path': src.get('source_revision') == digest
            and src.get('path') == cpp,
            'recipe hash equals the recipe file': recipe_sha is not None and rec.get('recipe_sha256') == recipe_sha,
            'compiler hash equals the pinned cl.exe': rec.get('compiler_binary_sha256') == compiler_pin,
            'target image equals builds/target.json': tgt.get('image_sha256') == tgt.get('expected_image_sha256')
            == image_sha})
    if row:
        facts['second-host source digest equals the tu digest'] = row.get('source_sha256') == digest
        if report is not None:
            facts[HOSTS_AGREE] = (report.get('source') or {}).get('source_revision') == row.get('source_sha256')
        facts['second-host recipe hash equals the recipe the job selects'] = (
            ci_recipe_sha is not None and row.get('recipe_sha256') == ci_recipe_sha)
    return facts


def binding_split(facts):
    """([contributor-fixable fact names], [bot-side fact names]) among the facts that disagree.

    When both hosts compiled the same source and only the bot's own recomputation of the digest
    disagrees, the fault is in the bot's tree, not in the PR: the PR is not blamed.
    """
    bad = [k for k, v in facts.items() if not v]
    mine = [k for k in bad if k not in BOT_SIDE_FACTS and k != HOSTS_AGREE]
    theirs = [k for k in bad if k in BOT_SIDE_FACTS]
    if HOSTS_AGREE in bad:
        mine.append(HOSTS_AGREE)
    elif facts.get(HOSTS_AGREE) and set(mine) <= set(DIGEST_FACTS):
        theirs += mine
        mine = []
    return mine, theirs


def origin_problems(hits, headers):
    """[(file, line)] for bodies close to a community or sibling body that the unit header does not declare.

    Trivial bodies and a fork's copy of a body that the parent already reports carry no provenance
    claim. This is the intake rule (`contrib_validation.provenance_findings`) applied where the pinned
    clones exist, which a CI runner does not have.
    """
    out = []
    for hit in hits:
        if hit.get('trivial') or hit.get('fork_of') or hit.get('declared'):
            continue
        if str(hit['repo']).startswith('fo4-private'):
            # Private sibling: its file layout is not public and outside contributors cannot read it.
            out.append((hit['file'], f'{hit["function"]} is close to a body in a private sibling source '
                        'that the unit header does not declare; fix: rewrite the body in your own words '
                        '(this source is not public, so it cannot be declared from a contributor clone)'))
            continue
        out.append((hit['file'], f'{hit["function"]} is close to a body in {hit["repo"]} '
                    f'({hit["path"]}) but the unit header does not name it with that file; '
                    'fix: declare the adapted body, its upstream file, revision and licence in the leading '
                    'header (docs/drafter-card.md, "Declare adapted bodies")'))
    return sorted(set(out))


def recipe_problem(root, cpp_text, summary):
    """Why a last-compare summary's recipe hash is not the recipe file the unit names now, or None."""
    found = RECIPE.search(cpp_text)
    recipe = found.group(0) if found else DEFAULT_RECIPE
    path = Path(root) / recipe
    if not path.is_file():
        return f'the unit names recipe {recipe}, which does not exist; fix: name a recipe under reconstruction/recipes/'
    if summary.get('recipe_sha256') != hashlib.sha256(path.read_bytes()).hexdigest():
        return (f'the recipe file {recipe} changed since the last compare; '
                'fix: run compare again so the report binds the current recipe')
    return None


def git(root, *args):
    return subprocess.run(['git', *args], cwd=root, capture_output=True, check=True).stdout


def changed_units(root, base, head):
    out = git(root, 'diff', '--no-renames', '--name-only', '--diff-filter=AM', '-z', f'{base}...{head}', '--')
    return [n for n in out.decode('utf-8', 'replace').split('\0') if n.endswith(('.h', '.cpp'))
            and n.startswith('reconstruction/') and not n.startswith('reconstruction/recipes/')]


def check(root, base, head):
    """Unit problems for the changed units of `head`, read from git into a scratch copy of the tree."""
    root = Path(root)
    names = changed_units(root, base, head)
    if not names:
        return []
    # Read the unit pair from the head and its lint dependencies from the trusted base.
    # Git blobs give Windows and sparse checkouts the same inputs as CI.
    pair = {Path(n).with_suffix(ext).as_posix() for n in names for ext in ('.h', '.cpp')}
    _, head_entries = tree_entries(root, head, cached=False)
    _, base_entries = tree_entries(root, base, cached=False)
    sources = blobs(root, head_entries, pair)
    dependencies = lint_dependencies(sources) - pair
    dependencies.update(recipe for n, blob in sources.items() if n.endswith('.cpp')
                        for recipe in RECIPE.findall(blob.decode('utf-8', 'replace')))
    target = 'builds/target.json'
    deps = blobs(root, base_entries, dependencies | {target})
    build = json.loads(deps.pop(target))['build_id']
    with tempfile.TemporaryDirectory() as scratch:
        scratch = Path(scratch)
        for name, blob in (deps | sources).items():
            path = scratch / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(blob)
        return unit_problems(scratch, names, build)


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--base', required=True)
    p.add_argument('--head', required=True)
    p.add_argument('--repo', type=Path, default=ROOT)
    a = p.parse_args(argv)
    problems = check(a.repo, a.base, a.head)
    for line in problems[:30]:
        # Messages name the PR's own files; keep only lines whose leading path is a safe name.
        head, sep, rest = line.partition(': ')
        print(f'{safe_name(head)}: {rest}' if sep and head.startswith('reconstruction/') else line)
    if len(problems) > 30:
        print(f'... and {len(problems) - 30} more')
    print(f'prereview: {"FAIL" if problems else "PASS"} ({len(problems)} problem(s))')
    return int(bool(problems))


if __name__ == '__main__':
    raise SystemExit(main())
