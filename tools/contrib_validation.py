"""Shared deterministic contributor intake/preflight checks, separate from match acceptance.

Only trusted tooling runs. A submitted revision is materialized as data for closure/lint checks.
"""
import json
from pathlib import Path, PurePosixPath
import re
import tempfile

import check_code_rules
import contrib_screen
import lint_reconstruction
import lint_review_readiness
import unit_paths
from source_digest import include_closure, _repo_file
from digest_v2 import tu_digest
from local_paths import local_path, no_sibling_names

UNIT = re.compile(r'reconstruction/((?:[a-z][a-z0-9_]*/)*[a-z][a-z0-9_]*)/((?:hk[a-z]{0,2})?[A-Z][A-Za-z0-9_]*)\.(h|cpp)\Z')


def publication_problems(ctx, base, rows, head=None, merge_method='squash'):
    """Use intake's retained-publication policy on a private snapshot, without changing the index.

    The synthetic commit is unreferenced and never pushed. It lets the same Git-based screen see
    pending source edits as well as the branch tip. A dry run changes no branch or staged file.
    """
    from contrib_publication import PublicationRejected, screen_publication
    def screen(revision):
        try:
            screen_publication(ctx.repo, base, revision, merge_method=merge_method)
        except PublicationRejected as exc:
            name = rows[0][1] if rows else 'reconstruction'
            fix = ('split the contribution below the reported publication resource cap'
                   if 'cap' in str(exc) else 'resolve the intake publication finding before submitting; '
                   'do not rewrite history to hide suspect material')
            return [f'{name}:1: retained publication: {exc}; fix: {fix}']
        return []

    if head:
        resolved = ctx.run(['git', 'rev-parse', '--verify', '--quiet', str(head) + '^{commit}'],
                           cwd=ctx.repo, capture_output=True)
        if resolved.returncode == 0:
            return screen(head)
    ctx.private.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=ctx.private, prefix='preflight-') as directory:
        env = dict(ctx.env, GIT_INDEX_FILE=str(Path(directory) / 'index'),
                   GIT_AUTHOR_NAME='Private preflight', GIT_AUTHOR_EMAIL='preflight@example.invalid',
                   GIT_COMMITTER_NAME='Private preflight', GIT_COMMITTER_EMAIL='preflight@example.invalid')

        def git(*args, input=None):
            result = ctx.run(['git', *args], cwd=ctx.repo, env=env, input=input, capture_output=True)
            if result.returncode:
                raise ValueError('private submission snapshot could not be prepared; check the index and source paths')
            return result.stdout

        git('read-tree', head or 'HEAD')
        if not head:
            for status, name in rows:
                if status == 'D':
                    git('update-index', '--force-remove', '--', name)
                    continue
                path = ctx.repo / name
                blob = git('hash-object', '-w', '--stdin', input=path.read_bytes()).decode().strip()
                mode = '100755' if path.stat().st_mode & 0o111 else '100644'
                git('update-index', '--add', '--cacheinfo', f'{mode},{blob},{name}')
        tree = git('write-tree').decode().strip()
        snapshot = git('commit-tree', tree, '-p', 'HEAD', input=b'Private contributor preflight snapshot\n').decode().strip()
        return screen(snapshot)


def diagnostic(problem):
    """Keep existing check text, supplying a header location and an actionable repair."""
    problem = re.sub(r'^check (?:provenance|publication_hygiene): ', '', problem)
    match = re.match(r'([^:]+):(?!\d+:)', problem)
    if match:
        problem = problem[:match.end()] + '1:' + problem[match.end():]
    fix = 'resolve the reported source/header requirement'
    if 'origin statement' in problem:
        fix = 'add a truthful Code origin: declaration to the leading header; disclose any adaptation'
    elif 'include' in problem.lower():
        fix = 'use the own-header name or a reconstruction-root header path; never a host/private path'
    elif 'decompiler identifier' in problem:
        fix = 'write programmer-level source with meaningful names; never paste decompiler output'
    return problem + '; fix: ' + fix


def screen_diagnostics(blob, name, *, headers=contrib_screen.STANDARD_HEADERS):
    codes = contrib_screen.screen(blob, name, headers=headers)
    # Locate single-line offences; whole-file resource findings point to the file's first line.
    locations = {}
    if codes:
        for number, line in enumerate(blob.splitlines(), 1):
            for code in contrib_screen.screen(line, name, headers=headers):
                locations.setdefault(code, number)
    return [f'{name}:{locations.get(code, 1)}: deterministic screen: {code}; fix: '
            + ('use a reconstruction-root header path without parent steps or host paths'
               if code in ('path-or-encoded-escape', 'include-outside-roots') else
               'remove the refused construct or reduce the reported resource use') for code in codes]


def source_problems(root, names, target, *, headers=contrib_screen.STANDARD_HEADERS, guard=None,
                    companions=()):
    """Screen exactly the changed files and their complete compiler input closures."""
    root = Path(root)
    problems, all_names = [], set(names)
    compiled = {PurePosixPath(n).with_suffix('.cpp').as_posix() for n in names
                if (root / Path(n).with_suffix('.cpp')).is_file()} | set(companions)
    if not compiled:
        problems.append(diagnostic(f'{names[0]}: no companion translation unit identifies this contribution'))
    for cpp in sorted(compiled):
        if not (root / cpp).is_file():
            problems.append(diagnostic(f'{cpp}: companion translation unit is missing'))
            continue
        try:
            closure = include_closure(root, cpp)
            all_names.update(closure)
            # Retain the intake screen's closure/angle-header predicates unchanged.
            codes = contrib_screen.screen_tree(root, cpp, headers=headers)
            if codes and not any(contrib_screen.screen((root / n).read_bytes(), n, headers=headers)
                                 for n in closure):
                problems += [diagnostic(f'{cpp}: deterministic screen: {code}') for code in codes]
        except (OSError, ValueError) as exc:
            problems.append(diagnostic(str(exc)))
    own_headers = {PurePosixPath(c).with_suffix('.h').as_posix() for c in compiled}
    # Shared declarations are only included, never compiled as a unit; a unit's own header is not.
    included_only = {n for n in all_names if n.endswith('.h') and n not in own_headers}
    for name in sorted(all_names):
        path = root / name
        if _repo_file(root, name) != name:
            problems.append(diagnostic(f'{name}: source must be a regular repository file'))
            continue
        blob = path.read_bytes()
        if guard:
            try:
                guard(name, blob)
            except ValueError as exc:
                problems.append(diagnostic(f'{name}: publication guard: {exc}'))
                continue
        problems += screen_diagnostics(blob, name, headers=headers)
        try:
            problems += [diagnostic(p) for p in lint_reconstruction.lint_file(root, name, target)]
            problems += [diagnostic(p) for p in lint_review_readiness.lint_files(root, [name], included_only)]
        except (UnicodeError, ValueError) as exc:
            problems.append(diagnostic(f'{name}: source lint failed ({type(exc).__name__})'))
    # R38-R40 of docs/code-rules.md apply to the files this change touches, not to the include closure:
    # headers a unit merely includes may carry older debt that is not this contributor's to fix.
    for name in sorted(set(names)):
        path = root / name
        if name.startswith('reconstruction/') and path.suffix in ('.h', '.cpp') and path.is_file():
            problems += check_code_rules.refusals(name, path.read_text(encoding='utf-8', errors='replace'))
    return sorted(set(problems))


def provenance_findings(ctx, unit, root=None):
    """Identical optional clone-backed label/origin checks for intake and local snapshots."""
    import check_labels
    import check_origin
    root = Path(root or ctx.repo)
    checkouts = {repo: local_path(ctx.repo, path, ctx.env)
                 for repo, path in check_labels.configured_checkouts(ctx.repo, ctx.env).items()}
    siblings = {repo: local_path(ctx.repo, path, ctx.env)
                for repo, path in check_labels.configured_siblings(ctx.repo, ctx.env).items()}
    labels = check_labels.check([root / n for n in unit], root=root, env=ctx.env,
                                checkouts=checkouts, siblings=siblings)
    warnings = ['label: ' + finding for finding in labels]
    # A claimed RVA inside a function the CrashLogger PDB records, rather than at its start, is probably wrong.
    import pdb_types
    import rva_headers
    claimed = rva_headers.claimed_rvas(
        [(root / n).read_text(errors='replace') for n in unit if (root / n).is_file()])
    warnings += ['pdb boundary: ' + w for w in pdb_types.boundary_warnings(sorted(claimed), ctx.repo)]
    clones, missing = check_origin.open_clones(ctx.repo, env=ctx.env)
    hits = check_origin.check_unit([root / n for n in unit], clones, root=root)
    origin = [check_origin.describe(h, no_sibling_names=no_sibling_names(ctx.env)) for h in hits]
    problems = []
    for hit in hits:
        if not hit['trivial'] and not hit['fork_of'] and not hit['declared']:
            problems.append(f'{hit.get("file", unit[-1])}:{hit.get("line", 1)}: '
                            'a body close to a community body is not declared in the unit header; '
                            'fix: declare the adapted body and its source in the leading header '
                            '(docs/drafter-card.md, "Declare adapted bodies")')
    missing = [r for r in missing if r != 'fo4-private']
    if missing:
        warnings.append('origin check ran without: ' + ', '.join(
            'a sibling checkout' if no_sibling_names(ctx.env) and r in check_origin.SIBLINGS else r
            for r in missing))
    return labels, origin, problems, warnings


def intake_problems(ctx, rows, head=None, details=None):
    """Same intake scope, publication, source lint, readiness and screen for Git or local input."""
    problems = []
    names = []
    for status, name in rows:
        if not UNIT.fullmatch(name):
            problems.append(diagnostic(f'{name}: outside contributor scope (reconstruction/<area>/<Class>.h or .cpp only)'))
        elif status == 'D':
            problems.append(diagnostic(f'{name}: deleting a unit file is for maintainers'))
        elif status == 'A' and not unit_paths.area_accepted(UNIT.fullmatch(name).group(1)):
            problems.append(diagnostic(f'{name}: area is not one of the unit areas in tools/unit_paths.py'))
        else:
            names.append(name)
    if not names:
        return problems
    target = json.loads((ctx.repo / 'builds/target.json').read_text())['build_id']
    companions = {source['compiled'] for _fn, source in accepted_sources(ctx.repo)
                  if set(names).intersection(source['translation_unit'])}
    import check
    # Reuse the publication guards; no acceptance records are evaluated or edited here.
    terms, private = check.anonymity_terms(ctx.repo), check.private_workflow_terms(ctx.repo)

    def guard(name, blob):
        check.check_anonymity(name, blob, terms)
        check.check_private_workflow(name, blob, private)
        check.inspect_payload(name, blob)

    def validate(root):
        problems.extend(source_problems(root, names, target, guard=guard, companions=companions))
        # Do not let optional clone diagnostics quote material refused by publication guards.
        if not problems:
            labels, origin, origin_problems, warnings = provenance_findings(ctx, names, root)
            problems.extend(origin_problems)
            if details is not None:
                details.update(label_findings=labels, origin_findings=origin, warnings=warnings)

    if not head:
        validate(ctx.repo)
    else:
        from git_context import tree_entries, blobs, lint_dependencies
        _revision, entries = tree_entries(ctx.repo, head)
        for name in names:
            if name not in entries or entries[name][0] != '100644':
                problems.append(diagnostic(f'{name}: intake requires a regular non-executable source file'))
        # Headers are small public source. Include all repository headers so the canonical closure
        # resolver sees ambiguity, transitive and includer-chain resolution exactly as intake does.
        wanted = set(names) | {PurePosixPath(n).with_suffix('.cpp').as_posix() for n in names} | companions
        wanted.update(n for n in entries if n.startswith('reconstruction/') and n.endswith('.h'))
        sources = blobs(ctx.repo, entries, wanted)
        sources.update(blobs(ctx.repo, entries, lint_dependencies(sources)))
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name, blob in sources.items():
                path = root / name
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(blob)
            validate(root)
    return sorted(set(problems))


def accepted_sources(root):
    """Use the same accepted-unit include closures intake collects for companion regressions."""
    root = Path(root)
    path = root / 'data/progress.json'
    if not path.is_file():
        return
    functions = [fn for fn in json.loads(path.read_text())['functions']
                 if fn.get('status') == 'matched' and fn.get('report')]
    from sparse_checkouts import reports
    for fn, (_name, record) in zip(functions, reports(root, [fn['report'] for fn in functions])):
        if record is None:
            raise ValueError('accepted companion report is missing')
        yield fn, record['source']


def project_reconfirmation(root, changed):
    """Accepted companions affected by this source edit are the project's work, never acceptance."""
    root, changed = Path(root), set(changed)
    result = []
    for fn, source in accepted_sources(root):
        if not changed.intersection(source['translation_unit']):
            continue
        try:
            stale = tu_digest(root, include_closure(root, source['compiled']), source.get('digest_method')) != source['digest']
        except (OSError, ValueError):
            stale = True  # the source preflight reports the closure fault; no acceptance is renewed
        if stale:
            result.append({'rva': hex(fn['rva']), 'file': source['compiled'],
                           'status': 'project re-confirmation needed (no action for you)'})
    return result
