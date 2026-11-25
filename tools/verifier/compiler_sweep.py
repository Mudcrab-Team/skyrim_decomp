#!/usr/bin/env python3
"""Compiler-build sweep: recompile a unit with every installed MSVC build and score each function.

    tools/verifier/compiler_sweep.py <task-dir>... [--repo CHECKOUT] [--toolsets 19.15.26731,...]
                                     [--out DIR] [--no-baseline]
    tools/verifier/compiler_sweep.py --list

The Rich header of the target lists objects built by compilers other than the pinned 19.16.27054, so
a register, EH or unwind difference that no source spelling moves may belong to such an object. This
tool compiles the same unit with each toolset that is installed under `.local/toolchains/` (see
setup_sweep_toolchains.sh), through the same runner path as `attempt` (runners.BatchHost: one upload,
one unit_build.py run per unit and toolset), and writes per function, privately under
`<out>/` (default `<task-dir>/sweep/`):

    * the comparator's verdict and reason (the only evidence of a byte match),
    * code: the aligned distance of the instructions alone (align.py, unwind left out), and
    * unwind: the UNWIND_INFO fields that differ (align.compare_unwind), or none when the comparator
      got past the unwind check. EH data and funclet findings stay in the reason code.

A toolset can be pinned for a unit only when every function of the unit that passed with the
pinned compiler also passes with it; otherwise the unit is reported `needs_split`. Nothing here
decides a match: a pass is review evidence on a stand-in compiler build, and acceptance still goes
through tools/accept_function.py.

Standard output carries counts, reason codes and distances only. Listings and objects stay in the
private output directory.
"""
import argparse
import json
from pathlib import Path
import sys
import time

HERE = Path(__file__).resolve().parent
TOOL_REPO = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parent))
import align  # noqa: E402
import pipeline  # noqa: E402
from pipeline import PipelineError  # noqa: E402
import runners  # noqa: E402

BASELINE = '19.16.27054'
# toolset id -> (what the Rich header calls the nearest build, or the family it stands in for)
TOOLSETS = {
    '19.00.24247': 'VS2015 Update 3 (Rich 24215 U3.1 and 23918 U2 are the targets; stand-in)',
    '19.11.25548': 'VS2017 15.4 (Rich 25547)',
    '19.12.25835': 'VS2017 15.5',
    '19.13.26132': 'VS2017 15.6',
    '19.14.26433': 'VS2017 15.7',
    '19.15.26731': 'VS2017 15.8 (Rich 26706 stand-in)',
    BASELINE: 'VS2017 15.9, the pinned build',
}
TOOLCHAIN_ROOT = Path('.local/toolchains')
UNWIND_REASONS = ('unwind-', 'unsupported-unwind')
PIN_NAME = 'tools/verifier/pinned/{}.sha256'
PIN_BASELINE = 'tools/verifier/pinned.sha256'


def toolchain_dir(root, version):
    return Path(root) / f'msvc-{version}'


def installed(root, wanted=None):
    ids = [v for v in TOOLSETS if (wanted is None or v in wanted) and toolchain_dir(root, v).is_dir()]
    return sorted(ids, key=lambda v: (v == BASELINE, v))


def toolset_recipe(recipe, version):
    """The recipe path of `recipe` (named for the pinned compiler) for another toolset."""
    stem = f'msvc-{BASELINE}'
    name = Path(recipe).name
    if not name.startswith(stem):
        raise PipelineError(f'recipe {recipe} is not named for {BASELINE}; the sweep cannot derive its sibling')
    return Path(recipe).with_name(name.replace(stem, f'msvc-{version}', 1)).as_posix()


def overlay_attempt(files, task_dir, number=None):
    """Replace unit files by the sources of the task's newest stored attempt (matched by file name).

    A near-miss draft is usually not in the checkout: its last attempt keeps the sources it compiled.
    """
    attempts = sorted(p for p in (Path(task_dir) / 'attempts').glob(number or '[0-9]*') if (p / 'src').is_dir())
    if not attempts:
        return 0
    by_name = {Path(rel).name: rel for rel in files if rel.startswith('reconstruction/')}
    n = 0
    for src in sorted((attempts[-1] / 'src').iterdir()):
        rel = by_name.get(src.name)
        if rel and src.is_file():
            files[rel] = src
            n += 1
    return n


def unit_files(task, src_repo, version, overlay=False, number=None):
    """({copy path: local path}, closure) for one unit under one toolset.

    Sources come from the checkout the unit was drafted in. The tools, the toolset's recipe and its
    pin file come from this checkout, so a draft made before the recipes existed can still be swept.
    """
    files, closure = pipeline.unit_manifest(task, src_repo)
    if overlay:
        overlay_attempt(files, task['dir'], number)
    for name in pipeline.TOOL_FILES:
        files[name] = TOOL_REPO / name
    del files[task['recipe']]
    recipe = toolset_recipe(task['recipe'], version)
    files[recipe] = TOOL_REPO / recipe
    pins = PIN_BASELINE if version == BASELINE else PIN_NAME.format(version)
    files[pins] = TOOL_REPO / pins
    if version != BASELINE:
        files[PIN_BASELINE] = TOOL_REPO / PIN_BASELINE
    return files, closure


def unwind_fields(fdir, reason):
    """Differing UNWIND_INFO fields: [] when the comparator got past the unwind check, None when unknown."""
    if reason == 'unwind-info-mismatch':
        pair = align.unwind_from_diagnostics(fdir)
        if pair is None:
            return None
        fields, _ = align.compare_unwind(pair[0], pair[1], {})
        return fields or ['unwind info (not decoded)']
    if reason and reason.startswith(UNWIND_REASONS):
        return [reason]
    if reason in (None, 'no-report', 'function-symbol-missing'):
        return None
    return []


def score_function(fdir, obj, fn, symbols, objdump, image):
    try:
        report = json.loads((fdir / 'report.json').read_text())
    except (OSError, ValueError):
        report = {}
    reason = report.get('reason')
    row = {'result': report.get('result', 'error'), 'reason': reason,
           'unwind': unwind_fields(fdir, reason)}
    row['unwind_equal'] = row['unwind'] == []
    row['code'] = None
    if obj.is_file() and objdump and image:
        try:
            _, data = align.align_function(fdir, objdump, image, obj, fn['symbol'], fn['rva'], fn['size'],
                                           symbols=symbols, unwind=False, out_dir=fdir / 'code')
            row['code'] = {'distance': data['distance'], 'exact': bool(data['exact']),
                           'components': data['components'],
                           'classes': {k: v for k, v in (data.get('classes') or {}).items()}}
        except (OSError, ValueError, KeyError) as exc:
            row['code_error'] = type(exc).__name__
    return row


def sweep_toolset(base_host, tasks, files_by_task, version, out, root, log):
    """{task id: unit record} for every task under one toolset."""
    if base_host['backend'] == 'ssh':
        # The remote toolsets sit next to the host's pinned toolchain under sweep/msvc-<version>; the
        # pinned build is the host's own.
        remote = base_host['msvc'].rsplit('/', 1)[0] + f'/sweep/msvc-{version}'
        host = dict(base_host, msvc=base_host['msvc'] if version == BASELINE else remote)
    else:
        host = dict(base_host, msvc=str(toolchain_dir(root, version).resolve()))
    units, dests, variants = [], {}, {}
    for task in tasks:
        sweep_id = f'{task["task_id"][:38]}-s{version.replace(".", "")[-5:]}'
        variant = dict(task, task_id=sweep_id, recipe=toolset_recipe(task['recipe'], version))
        if version != BASELINE:
            variant['pins'] = PIN_NAME.format(version)
        units.append((variant, files_by_task[task['task_id']][version]))
        dests[sweep_id] = Path(out) / task['task_id'] / version
        variants[sweep_id] = task
    batch = runners.BatchHost(host, log=log, fresh_prep=True)
    stage = Path(out) / '.stage' / version
    results = batch.run(units, stage, dests)
    records = {}
    for sweep_id, task in variants.items():
        res = results.get(sweep_id)
        if isinstance(res, Exception) or res is None:
            records[task['task_id']] = {'status': 'runner-error', 'detail': type(res).__name__, 'functions': {}}
            continue
        code, dest, facts = res
        records[task['task_id']] = {'status': {0: 'ok', 1: 'ok', 3: 'compile-failed', 4: 'unit-error'}.get(code, f'exit-{code}'),
                                    'exit': code, 'dir': str(dest), 'facts': facts, 'functions': {}}
    return records


def score_records(records, tasks, objdump, image):
    for task in tasks:
        rec = records[task['task_id']]
        if rec['status'] != 'ok':
            continue
        dest = Path(rec['dir'])
        symbols = align.load_symbols(task['symbols_local'])
        for fn in task['functions']:
            fdir = dest / f'0x{fn["rva"]:x}'
            rec['functions'][f'0x{fn["rva"]:x}'] = score_function(fdir, dest / 'candidate.obj', fn, symbols,
                                                                 objdump, image)


def summarise(tasks, by_version):
    """Per task: which toolsets pass which functions, and whether one toolset can be pinned."""
    out = {}
    for task in tasks:
        tid = task['task_id']
        rvas = [f'0x{fn["rva"]:x}' for fn in task['functions']]
        per_fn = {}
        for rva in rvas:
            per_fn[rva] = {v: by_version[v][tid]['functions'].get(rva) for v in by_version}
        passing = {rva: sorted(v for v, row in rows.items() if row and row['result'] == 'pass')
                   for rva, rows in per_fn.items()}
        # A function the pinned compiler already passes is a unit mate that a pin must not regress.
        mates = sorted(rva for rva in rvas if BASELINE in passing[rva])
        rescued = {rva: [v for v in passing[rva] if v != BASELINE] for rva in rvas if BASELINE not in passing[rva]}
        rescued = {rva: vs for rva, vs in rescued.items() if vs}
        pin, split = None, bool(rescued)
        for v in by_version:
            if v != BASELINE and all(v in passing[rva] for rva in mates) \
                    and all(v in vs for vs in rescued.values()) and rescued:
                pin = v
                break
        regress = mates
        out[tid] = {'functions': rvas, 'passing': passing, 'pin': pin,
                    'rescued': rescued, 'status': 'pin' if pin else ('needs_split' if split else 'none'),
                    'baseline_passing_mates': regress}
    return out


def table(tasks, by_version, summary):
    lines = []
    for task in tasks:
        tid = task['task_id']
        lines.append(f'unit {tid}: {summary[tid]["status"]}' + (f' ({summary[tid]["pin"]})' if summary[tid]['pin'] else ''))
        for fn in task['functions']:
            rva = f'0x{fn["rva"]:x}'
            for v, recs in by_version.items():
                rec = recs[tid]
                row = rec['functions'].get(rva)
                if row is None:
                    lines.append(f'  {rva} {v:12} {rec["status"]}')
                    continue
                code = row['code']
                cd = f'{code["distance"]:g}' if code else '-'
                uw = 'equal' if row['unwind_equal'] else ('?' if row['unwind'] is None else '+'.join(row['unwind']))
                lines.append(f'  {rva} {v:12} {row["result"]:5} {row["reason"] or "-":28} code {cd:>5} unwind {uw}')
    return lines


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('task_dirs', nargs='*', help='task directories (task.json); units are swept as the task names them')
    p.add_argument('--repo', default=str(TOOL_REPO), help='checkout holding the units\' sources (default: this one)')
    p.add_argument('--toolsets', help='comma-separated toolset ids (default: every installed one)')
    p.add_argument('--toolchains', default=None, help='directory holding msvc-<version> (default: .local/toolchains)')
    p.add_argument('--out', help='private output directory (default: <first task dir>/sweep)')
    p.add_argument('--host', help='runner host name in .local/verifier/runners.json (default: its attempt host)')
    p.add_argument('--attempt-sources', action='store_true',
                   help='compile the sources of each task\'s newest stored attempt instead of the checkout\'s')
    p.add_argument('--attempt-number', help='with --attempt-sources: the attempt directory name (default: the newest)')
    p.add_argument('--no-baseline', action='store_true', help='skip the pinned compiler')
    p.add_argument('--list', action='store_true', help='list the toolsets and whether each is installed')
    args = p.parse_args(argv)
    root = Path(args.toolchains) if args.toolchains else TOOL_REPO / TOOLCHAIN_ROOT
    if args.list:
        for v, label in TOOLSETS.items():
            print(f'{v:12} {"installed" if toolchain_dir(root, v).is_dir() else "missing":10} {label}')
        return 0
    if not args.task_dirs:
        p.error('give at least one task directory')
    wanted = set(args.toolsets.split(',')) if args.toolsets else None
    versions = installed(root, wanted)
    if args.no_baseline:
        versions = [v for v in versions if v != BASELINE]
    if wanted and set(wanted) - set(versions):
        print('not installed: ' + ', '.join(sorted(set(wanted) - set(versions))))
        return 2
    if not versions:
        print('no toolsets installed')
        return 2
    repo = Path(args.repo).resolve()
    try:
        tasks, files_by_task = [], {}
        config = runners.load()
        base_host = runners.with_image(config['hosts'][args.host]) if args.host and config else runners.for_attempt()
        if base_host is None:
            raise PipelineError('the sweep needs a local or ssh attempt host in .local/verifier/runners.json')
        for d in args.task_dirs:
            # One unit that cannot be prepared (a source the checkout lacks) must not stop the others.
            try:
                task = pipeline.load_task(d, repo)
                files_by_task[task['task_id']] = {v: unit_files(task, repo, v, args.attempt_sources,
                                                                args.attempt_number)[0] for v in versions}
                tasks.append(task)
            except (PipelineError, OSError, ValueError, KeyError) as exc:
                print(f'skipped {d}: {str(exc)[:120]}')
        if not tasks:
            raise PipelineError('no unit could be prepared')
    except (PipelineError, runners.RunnerError) as exc:
        print(f'error: {exc}')
        return 2
    out = Path(args.out) if args.out else tasks[0]['dir'] / 'sweep'
    out.mkdir(parents=True, exist_ok=True)
    image, objdump = align._config_image()
    image = image or base_host.get('image')
    started = time.monotonic()
    by_version = {}
    for v in versions:
        by_version[v] = sweep_toolset(base_host, tasks, files_by_task, v, out, root, print)
        score_records(by_version[v], tasks, objdump, image)
        print(f'toolset {v}: ' + ', '.join(f'{tid} {rec["status"]}' for tid, rec in by_version[v].items()))
    summary = summarise(tasks, by_version)
    (out / 'sweep.json').write_text(json.dumps({'sweep_schema': 1, 'toolsets': versions, 'units': summary,
                                                'records': by_version}, indent=1, default=str) + '\n')
    for line in table(tasks, by_version, summary):
        print(line)
    print(f'sweep {len(versions)} toolset(s) x {len(tasks)} unit(s) in {time.monotonic() - started:.0f} s; private output {out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
