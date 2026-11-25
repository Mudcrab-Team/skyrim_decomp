"""Plans and builds for exelink: which matched functions to place, and the objects to place them from.

A plan lists, per translation unit, the compiled file, recipe, unit symbol map and the matched
functions it defines, all taken from the public match records. Objects come from any build of those
units named `<unit id>.obj`: the verifier's `candidate.obj`, a CI-hash build, or `build_units` below,
which compiles with the pinned recipe on a Windows host that has the pinned toolchain unpacked.
"""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import random
import re
import shutil
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
import record_store  # noqa: E402

PLAN_SCHEMA = 1
UNIT_ID_LIMIT = 48


def unit_id(compiled, recipe='', symbols=''):
    """A file-name-safe identifier of one planned unit: the compiled path, recipe and symbol map."""
    stem = re.sub(r'[^a-z0-9]+', '-', compiled.lower().removeprefix('reconstruction/').removesuffix('.cpp')).strip('-')
    key = '\0'.join((compiled, recipe, symbols))
    return f'{stem[:UNIT_ID_LIMIT].rstrip("-")}-{hashlib.sha256(key.encode()).hexdigest()[:10]}'


def function_spec(rec):
    """One plan entry from a match record; identity and hashes only."""
    run = rec['runs'][0]['report']
    fn, src = run['function'], run['source']
    spec = {'id': rec['function_id'], 'rva': fn['rva'], 'size': fn['size'], 'symbol': fn['symbol'],
            'source_revision': src['source_revision'], 'source_path': src['path']}
    if 'internal_identity' in fn:
        spec['internal_identity'] = fn['internal_identity']
    elif run['comparator']['version'].endswith('-runtime'):
        # Ordinary functions with a verified CRT termination action bind through the runtime engine.
        spec['engine'] = 'runtime'
    hashes = {r['report'].get('candidate', {}).get('code_section_sha256') for r in rec['runs']}
    hashes.discard(None)
    if len(hashes) == 1:
        spec['record_code_section_sha256'] = next(iter(hashes))
    return spec


def make_plan(repo=ROOT, units=None, sample=None, seed=0, shard=None):
    """The matched functions of the pinned build, grouped by translation unit.

    `units` restricts to those compiled files, `sample` keeps that many units chosen with `seed`,
    `shard` is (index, count) and keeps every count-th unit starting at index.
    """
    repo = Path(repo)
    target = json.loads((repo / 'builds/target.json').read_text())
    progress = json.loads((repo / 'data/progress.json').read_text())
    matched = {f['id'] for f in progress['functions'] if f.get('status') == 'matched'}
    build = repo / 'reports' / target['build_id']
    groups = {}
    for name in record_store.names(build, 'match'):
        rec = json.loads(record_store.read_text(build / name))
        if 'match_record_schema' not in rec or rec['function_id'] not in matched:
            continue
        key = (rec['source']['compiled'], rec['recipe']['path'], rec['symbol_map']['path'])
        groups.setdefault(key, []).append(function_spec(rec))
    rows = [{'unit': unit_id(c, r, s), 'compiled': c, 'recipe': r, 'symbols': s,
             'functions': sorted(f, key=lambda x: x['rva'])} for (c, r, s), f in sorted(groups.items())]
    if units:
        rows = [r for r in rows if r['compiled'] in set(units)]
    if sample is not None and sample < len(rows):
        rows = sorted(random.Random(seed).sample(rows, sample), key=lambda r: r['compiled'])
    if shard is not None:
        index, count = shard
        rows = rows[index::count]
    return {'plan_schema': PLAN_SCHEMA, 'build_id': target['build_id'], 'image_sha256': target['image_sha256'],
            'units': rows, 'functions': sum(len(r['functions']) for r in rows)}


def read_symbol_map(repo, path):
    return record_store.read_bytes(Path(repo) / path)


def object_path(objects, unit):
    return Path(objects) / f'{unit["unit"]}.obj'


# -- building ---------------------------------------------------------------------------------


class BuildError(Exception):
    pass


def compile_environment(msvc):
    """(cl path, environment) for a native Windows compile, as the verifier's unit build sets it up."""
    import unit_build
    wrapper = unit_build.native_settings(msvc)
    env = unit_build.clean_env(os.environ)
    env['VSLANG'] = '1033'
    env['INCLUDE'] = wrapper['INCLUDE']
    return str(Path(wrapper['BINDIR']) / 'cl.exe'), env


def batches(units, recipes, size):
    """Groups of at most `size` units with one recipe and distinct source file names."""
    by_recipe = {}
    for unit in units:
        by_recipe.setdefault(unit['recipe'], []).append(unit)
    for recipe, group in sorted(by_recipe.items()):
        flags = recipes[recipe]
        batch, names = [], set()
        for unit in group:
            base = Path(unit['compiled']).stem.lower()
            if len(batch) >= size or base in names:
                yield flags, batch
                batch, names = [], set()
            batch.append(unit)
            names.add(base)
        if batch:
            yield flags, batch


def compile_batch(repo, cl, env, flags, batch, objects, scratch, timeout=600):
    """Compile `batch` in one compiler run; returns the units that produced no object.

    The compiler's own output is dropped: it can quote source text, and an object is all that is
    wanted. A unit with no object is retried alone once, so one bad source never hides others.
    """
    import unit_build
    scratch = Path(scratch)
    shutil.rmtree(scratch, ignore_errors=True)
    scratch.mkdir(parents=True)
    cmd = [cl] + list(flags) + [f'/Fo{scratch}{os.sep}'] + [u['compiled'] for u in batch]
    try:
        unit_build.compile_bounded(cmd, repo, env, timeout)
    except unit_build.UnitError:
        pass
    missing = []
    for unit in batch:
        made = scratch / f'{Path(unit["compiled"]).stem}.obj'
        if made.is_file():
            os.replace(made, object_path(objects, unit))
        else:
            missing.append(unit)
    failed = []
    for unit in missing:
        single = scratch / 'single'
        shutil.rmtree(single, ignore_errors=True)
        single.mkdir()
        try:
            unit_build.compile_bounded([cl] + list(flags) + [f'/Fo{single}{os.sep}', unit['compiled']], repo, env, timeout)
        except unit_build.UnitError:
            pass
        made = single / f'{Path(unit["compiled"]).stem}.obj'
        if made.is_file():
            os.replace(made, object_path(objects, unit))
        else:
            failed.append(unit)
    shutil.rmtree(scratch, ignore_errors=True)
    return failed


def build_units(repo, units, objects, msvc, jobs=1, batch_size=24, on_batch=None):
    """Compile every unit into `objects/<unit id>.obj`, `jobs` compiler runs at a time.

    `on_batch(batch, failed)` is called from the calling thread as each batch finishes, so the
    caller can use the objects while later batches still compile. Returns the failed units.
    """
    repo = Path(repo)
    Path(objects).mkdir(parents=True, exist_ok=True)
    cl, env = compile_environment(msvc)
    recipes = {}
    for unit in units:
        if unit['recipe'] not in recipes:
            recipes[unit['recipe']] = json.loads((repo / unit['recipe']).read_text())['flags']
    work = list(batches(units, recipes, batch_size))
    scratch = Path(objects) / '.build'
    failed_all = []
    with ThreadPoolExecutor(max_workers=max(1, jobs)) as pool:
        futures = [pool.submit(compile_batch, repo, cl, env, flags, batch, objects, scratch / str(i))
                   for i, (flags, batch) in enumerate(work)]
        for (flags, batch), future in zip(work, futures):
            failed = future.result()
            failed_all += failed
            if on_batch:
                on_batch(batch, failed)
    shutil.rmtree(scratch, ignore_errors=True)
    return failed_all
