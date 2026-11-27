"""Recheck accepted functions in units that include edited reconstruction source."""
from concurrent.futures import ThreadPoolExecutor
from contextlib import contextmanager
from pathlib import Path
import shutil
import subprocess
import tarfile
import tempfile
import time

from check_source_digest import include_closure, source_digest_cache
from contrib_validation import accepted_records


@contextmanager
def source_tree(ctx, head, work):
    from sparse_checkouts import active
    from contrib import git

    if head is None and not active(ctx.repo):
        yield ctx.repo
        return
    root = work / 'source'
    root.mkdir()
    # Read the immutable index tree, including files omitted by a sparse working checkout.
    revision = head or git(ctx, 'write-tree')
    with subprocess.Popen(['git', 'archive', revision, 'reconstruction'], cwd=ctx.repo,
                          stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
        with tarfile.open(fileobj=proc.stdout, mode='r|') as archive:
            archive.extractall(root, filter='data')
        if proc.wait():
            raise ValueError('could not read reconstruction from the index tree')
    if head is None:
        # The index supplies omitted sparse files. The actual working edits take precedence.
        unstaged = git(ctx, 'diff', '--name-only', '--no-renames', '-z', '--', 'reconstruction/')
        untracked = git(ctx, 'ls-files', '-z', '--others', '--exclude-standard', '--', 'reconstruction/')
        for name in (set(unstaged.split('\0')) | set(untracked.split('\0'))) - {''}:
            target = root / name
            source = ctx.repo / name
            target.unlink(missing_ok=True)
            if source.is_file():
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(source, target, follow_symlinks=False)
    yield root


def affected_units(root, records, changes):
    """The accepted closures provide candidates; resolve their edited closures with the match gate."""
    from ci_target_hash_check import include_candidates

    changed = set(changes)
    additions = {name for name, status in changes.items() if status == 'A'}
    # A new path can change include resolution even if it was absent from the accepted closure.
    new_includers = include_candidates(root, additions) if additions else set()
    units = {}
    for fn, record in records:
        source = record['source']
        unit = source['compiled']
        affected = changed.intersection(source['translation_unit']) - {unit}
        if affected or unit in new_includers or unit in changed:
            refs, old_paths = units.setdefault(unit, ([], set()))
            refs.append((fn, record))
            old_paths.update(affected)
    with source_digest_cache():
        for unit, (refs, old_paths) in units.items():
            try:
                closure = include_closure(root, unit)
            except (OSError, ValueError):
                if causes := old_paths or (additions if unit in new_includers else set()):
                    yield unit, refs, sorted(causes), None
                continue
            if causes := (changed.intersection(closure) - {unit}) | old_paths:
                yield unit, refs, sorted(causes), closure


def prefetch_objects(ctx, root, jobs, work, build_id):
    """Fetch compile results through the configured Windows PC batch transport."""
    import pipeline
    import runners

    objects = {}
    try:
        config = runners.load(ctx.env.get('SR_RUNNERS_CONFIG'))
        if not config:
            return {}
        names = [name for name, host in config['hosts'].items()
                 if host['backend'] == 'ssh' and host['loader'] == 'native']
        if not names:
            return {}
        preferred = config.get('compare_prefer') or names
        config = dict(config, compare_prefer=[n for n in preferred if n in names])
        forced = ctx.env.get('SR_COMPARE_HOST')
        if forced and forced not in names:
            return {}
        name, warnings = runners.choose_compare(config, ctx.env)
        for warning in warnings:
            ctx.say('dependent recheck: ' + warning)
        if name is None:
            return {}
        host = runners.with_image(config['hosts'][name])
        worker = runners.BatchHost(host)
        size = host['batch']
        for start in range(0, len(jobs), size):
            batch, outputs, by_id = [], {}, {}
            for index, (unit, recipe, closure) in enumerate(jobs[start:start + size], start):
                tid = f'dependent-{index}'
                files = {path: ctx.repo / path for path in pipeline.TOOL_FILES}
                files.update({path: root / path for path in (*closure, recipe)})
                # An empty function list makes the batch compile and validate includes only.
                task = dict(task_id=tid, build_id=build_id, compiled=unit, recipe=recipe,
                            symbols_repo=None, functions=[])
                batch.append((task, files))
                outputs[tid] = work / 'pc' / tid
                by_id[tid] = unit
            for tid, result in worker.run(batch, work / 'prefetch', outputs).items():
                if isinstance(result, tuple):
                    code, dest, _facts = result
                    if code in (3, 4):
                        objects[by_id[tid]] = (None, 'compile or include check failed')
                    elif code == 0 and (dest / 'candidate.obj').is_file():
                        objects[by_id[tid]] = (dest / 'candidate.obj', None)
        ctx.say(f'dependent recheck: Windows PC prefetched {len(objects)} of {len(jobs)} unit(s)')
        return objects
    except (runners.RunnerError, OSError, ValueError, subprocess.SubprocessError):
        ctx.say('dependent recheck: Windows PC prefetch unavailable; using the local compiler')
        return objects


def compare_units(ctx, root, work, units, manifest):
    from contrib import Stop, apply_wine_env, check_toolchain, compile_unit, DEFAULT_RECIPE, unit_recipe
    from pecoff import Reject
    import target_hashes as hashes

    targets = {row['rva']: row for row in manifest['functions']}
    recipes, failures = {}, {}
    jobs = []
    for unit, _refs, _causes, closure in units:
        if closure is None:
            failures[unit] = 'include closure failed'
            continue
        try:
            recipe = unit_recipe(root, unit, DEFAULT_RECIPE)
            if hashes.digest((root / recipe).read_bytes()) != manifest['recipe_sha256'].get(recipe):
                raise ValueError('recipe pin differs')
        except (OSError, Stop, ValueError):
            failures[unit] = 'published recipe unavailable'
            continue
        recipes[unit] = recipe
        jobs.append((unit, recipe, closure))
    prefetched = prefetch_objects(ctx, root, jobs, work, manifest['build_id']) if jobs else {}
    local_recipes = {recipe for unit, recipe in recipes.items() if unit not in prefetched}
    if local_recipes:
        apply_wine_env(ctx)
    tools = {recipe: check_toolchain(ctx, recipe=recipe) for recipe in sorted(local_recipes)}

    def check(job):
        index, (unit, refs, causes, _closure) = job
        failure = failures.get(unit)
        if failure is None:
            try:
                if unit in prefetched:
                    obj, failure = prefetched[unit]
                else:
                    recipe = recipes[unit]
                    obj = compile_unit(ctx, root, unit, recipe, work / str(index), tools[recipe])['object']
                blob = obj.read_bytes() if obj is not None else None
            except (OSError, Stop, ValueError):
                failure = 'compile or include check failed'
        rows = []
        for fn, record in refs:
            rva = fn['rva']
            row = dict(rva=hex(rva), name=fn.get('name'), unit=unit, includes=causes, result='mismatch')
            if failure:
                row['reason'] = failure
            else:
                target = targets.get(rva)
                runs = record.get('runs') or []
                report = runs[0]['report'] if runs else {}
                symbol = report.get('function', {}).get('symbol')
                if not target or target['extraction'] == 'unmasked-unsupported' or not symbol \
                        or report.get('contract_version') != 2:
                    row.update(result='unavailable', reason='published target or binding unavailable')
                else:
                    try:
                        verdict = hashes.candidate(blob, symbol, target)
                    except (ValueError, Reject):
                        row['reason'] = 'accepted symbol or object layout changed'
                    else:
                        if verdict == 'hash-match':
                            row['result'] = verdict
                        else:
                            row['reason'] = ('relocation layout changed' if verdict == 'no-target'
                                             else 'published hash mismatch')
            rows.append(row)
        return rows

    with ThreadPoolExecutor(max_workers=4) as pool:
        return [row for rows in pool.map(check, enumerate(units)) for row in rows]


def recheck(ctx, files, head):
    from target_hashes import load_manifest

    changes = {name: status for status, name in files if name.startswith('reconstruction/')
               and Path(name).suffix in ('.h', '.hpp', '.inl', '.inc', '.cpp')}
    started = time.monotonic()
    units, rows = [], []
    if changes:
        records = accepted_records(ctx.repo)
        if records:
            ctx.private.mkdir(parents=True, exist_ok=True)
            with tempfile.TemporaryDirectory(prefix='dependents-', dir=ctx.private) as directory:
                work = Path(directory)
                with source_tree(ctx, head, work) as root:
                    units = list(affected_units(root, records, changes))
                    if units:
                        rows = compare_units(ctx, root, work, units, load_manifest(ctx.repo))
    elapsed = round(time.monotonic() - started, 2)
    matched = sum(row['result'] == 'hash-match' for row in rows)
    ctx.say(f'dependent recheck: {len(units)} unit(s), {len(rows)} function(s), '
            f'{matched} hash match(es) in {elapsed:.2f} s')
    return dict(units=len(units), seconds=elapsed, functions=rows)
