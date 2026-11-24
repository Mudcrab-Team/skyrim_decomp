#!/usr/bin/env python3
"""Twin generator: stamp unmatched functions from matched exemplars with the same code shape.

    twins.py index  [--config analysis.json] [--export export.txt] [--jobs 2] [--full]
    twins.py report                                   # coverage counts, strict and loose
    twins.py plan   [--level strict|loose] [--skip-claim N ...] [--skip-names REGEX] [--skip-file F]
    twins.py stamp  [--limit N] [--jobs 4] [--redo]   # write units, compile and compare on the runner host
    twins.py status                                   # results so far, by level and reason

Everything game-derived (the index, the plan, task directories and compare output) stays under `.local/`;
the units written under reconstruction/ are this repository's own sources with placeholder names.
Only the comparator decides a pass, and a pass here is a candidate for the normal two-host review route.
Run from a repository checkout; set SR_RUNNERS_CONFIG to pick the runner host and its slot cap.
"""
import argparse
import collections
import json
from pathlib import Path
import subprocess
import sys
import time

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / 'tools'))
import local_paths  # noqa: E402
import twin_runner as runner  # noqa: E402
import twin_select as T  # noqa: E402
import twin_shapes as shapes  # noqa: E402
import twin_unit as U  # noqa: E402


def state_dir():
    path = local_paths.local_dir(ROOT) / 'twins'
    path.mkdir(parents=True, exist_ok=True)
    return path


def private(name):
    """A file of the private store, falling back to the main checkout's copy."""
    return local_paths.local_path(ROOT, '.local/' + name)


def cmd_index(a):
    config = a.config or private('config/analysis.json')
    export = a.export or private('config/export.txt')
    shapes.build(config, export, a.table or private('analysis/functions.jsonl'), state_dir() / 'index.jsonl', jobs=a.jobs, full=a.full)


def load_index():
    index = shapes.load(state_dir() / 'index.jsonl')
    if not index:
        raise SystemExit('no index: run `twins.py index` first')
    return index


def cmd_report(a):
    index = load_index()
    progress = T.load_progress(ROOT)
    table = T.load_table(private('analysis/functions.jsonl'))
    out = {}
    for level in ('strict', 'loose'):
        out[level] = T.coverage(index, progress, table, level)
        out[level + '-contract-supported'] = T.coverage(index, progress, table, level, supported_only=True)
    print(json.dumps(out, indent=1))
    (state_dir() / 'coverage.json').write_text(json.dumps(out, indent=1))


def skips(a):
    out = set()
    if a.skip_file:
        out |= {int(x, 16) for x in Path(a.skip_file).read_text().split()}
    if a.skip_claim:
        out |= T.claim_rvas(a.skip_claim, cwd=ROOT)
    if a.skip_open_prs:
        out |= T.open_pr_rvas(cwd=ROOT)
    return out


def loose_diffs(plan):
    """Attach each loose twin's operand differences; strict twins are left to the strict plan."""
    import twin_subst as subst
    strict = state_dir() / 'plan-strict.json'
    skip = {r['rva'] for r in json.loads(strict.read_text())} if strict.exists() else set()
    rows = [r for r in plan if r['rva'] not in skip]
    config = private('config/analysis.json')
    image = shapes.open_image(config, private('config/export.txt'))
    ops = shapes.operands_of(image, sorted({r['rva'] for r in rows} | {r['exemplar'] for r in rows}))
    out = []
    for r in rows:
        diffs = shapes.diff(ops.get(r['exemplar'], []), ops.get(r['rva'], []))
        if diffs is None or not diffs:
            continue
        kinds = sorted({d[3] for d in diffs})
        row = dict(r, kinds=kinds, ndiff=len(diffs))
        if 'imm' in kinds:
            imap, why = subst.immediate_map(ops[r['exemplar']], diffs)
            if why or not imap:
                row['kinds'] = ['imm-ambiguous']
            else:
                row['imap'] = {str(k): list(v) for k, v in imap.items()}
        if 'disp' in kinds and row['kinds'] != ['imm-ambiguous']:
            row['moves'] = sorted({(d[1], d[2]) for d in diffs if d[3] == 'disp'})
        out.append(row)
    return out


def cmd_plan(a):
    index = load_index()
    table = T.load_table(private('analysis/functions.jsonl'))
    skip = skips(a)
    planner = T.Planner(ROOT, index, table, skip=skip, skip_names=a.skip_names, level=a.level)
    plan, stats = planner.run(probe=not a.no_probe)
    if a.supported_only:
        plan = [r for r in plan if table[r['rva']]['v2'] == 'supported']
    if a.level == 'loose':
        plan = loose_diffs(plan)
    (state_dir() / ('plan-%s.json' % a.level)).write_text(json.dumps(plan))
    print('skip set: %d RVAs' % len(skip))
    for k, v in sorted(stats.items()):
        print('%6d  %s' % (v, k))
    print('planned %d twins of %d exemplars' % (len(plan), len({r['exemplar'] for r in plan})))


def load_results(path):
    out = {}
    if path.exists():
        for line in path.read_text().splitlines():
            row = json.loads(line)
            out[row['rva']] = row
    return out


def cmd_stamp(a):
    import contrib
    index = load_index()
    plan = json.loads((state_dir() / ('plan-%s.json' % a.level)).read_text())
    results_path = state_dir() / ('results-%s.jsonl' % a.level)
    results = load_results(results_path)
    todo = [r for r in plan if a.redo or r['rva'] not in results]
    if a.only:
        wanted = {int(x, 16) for x in Path(a.only).read_text().split()}
        todo = [r for r in todo if r['rva'] in wanted]
    if a.limit:
        todo = todo[:a.limit]
    tracked = set(subprocess.run(['git', 'ls-files', 'reconstruction'], cwd=ROOT, capture_output=True, text=True).stdout.split('\n'))
    ctx = contrib.Ctx()
    exe = contrib.require_exe(ctx, contrib.target_manifest(ctx.repo))['path']
    tasks = ctx.local / 'tasks'
    planner = T.Planner(ROOT, index, {}, level=a.level)
    built = {}
    log = results_path.open('a')

    def record(row):
        results[row['rva']] = row
        log.write(json.dumps(row) + '\n')
        log.flush()

    pending = []
    for row in todo:
        rva = row['rva']
        ex = planner.exemplar(row['exemplar'])
        if isinstance(ex, U.Unsupported):
            record({'rva': rva, 'exemplar': row['exemplar'], 'status': 'unsupported', 'reason': ex.reason})
            continue
        try:
            twin = U.build(ROOT, ex, rva)
            if a.level == 'loose':
                if 'imap' not in row and 'moves' not in row:
                    raise U.Unsupported('loose-' + '+'.join(row.get('kinds', ['?'])))
                if 'imap' in row:
                    U.apply_constants(twin, {int(k): tuple(v) for k, v in row['imap'].items()})
                    U.mark_loose(twin, 'constants')
                if 'moves' in row:
                    U.apply_layout(twin, [tuple(m) for m in row['moves']])
                    U.mark_loose(twin, 'member offsets')
        except U.Unsupported as exc:
            record({'rva': rva, 'exemplar': row['exemplar'], 'status': 'unsupported', 'reason': exc.reason})
            continue
        except Exception as exc:  # noqa: BLE001
            record({'rva': rva, 'exemplar': row['exemplar'], 'status': 'unsupported', 'reason': 'error:' + type(exc).__name__})
            continue
        clash = [rel for rel in twin.files if 'reconstruction/' + rel in tracked]
        if clash:
            record({'rva': rva, 'exemplar': row['exemplar'], 'status': 'unsupported', 'reason': 'unit-exists'})
            continue
        runner.write_twin(ROOT, twin)
        tdir = runner.make_task(ctx, exe, ROOT, twin, row['size'], tasks)
        built[tdir.name] = (row, twin)
        pending.append(tdir)
    print('written %d units; comparing on the runner host with %d jobs' % (len(pending), a.jobs), flush=True)

    def done(name, res):
        row, twin = built[name]
        rec = {'rva': row['rva'], 'exemplar': row['exemplar'], 'level': a.level, 'mode': row['mode'], 'stem': twin.stem,
               'status': res['status'], 'reason': res['reason'], 'sizes': res['sizes']}
        record(rec)
        print('0x%x %s %s' % (row['rva'], res['status'], res['reason']), flush=True)
        if res['status'] != 'pass':
            (state_dir() / 'logs').mkdir(exist_ok=True)
            (state_dir() / 'logs' / ('%x.txt' % row['rva'])).write_text(res['output'][-6000:])

    runner.run_many(ROOT, pending, jobs=a.jobs, on_result=done)
    cmd_status(a)


def cmd_status(a):
    results = load_results(state_dir() / ('results-%s.jsonl' % a.level))
    c = collections.Counter((r['status'], r.get('reason')) for r in results.values())
    by = collections.Counter(r['status'] for r in results.values())
    print('results:', dict(by))
    for (s, why), n in c.most_common(25):
        print('%5d  %s %s' % (n, s, why))


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)
    s = sub.add_parser('index')
    s.add_argument('--config')
    s.add_argument('--export')
    s.add_argument('--table')
    s.add_argument('--jobs', type=int, default=2)
    s.add_argument('--full', action='store_true')
    s.set_defaults(f=cmd_index)
    sub.add_parser('report').set_defaults(f=cmd_report)
    s = sub.add_parser('plan')
    s.add_argument('--level', choices=('strict', 'loose'), default='strict')
    s.add_argument('--skip-claim', type=int, action='append', default=[], help='claim issue number whose RVAs are skipped')
    s.add_argument('--skip-open-prs', action='store_true')
    s.add_argument('--skip-names', help='regex over the inventory name; matching functions are skipped')
    s.add_argument('--skip-file', help='file of RVAs (hex, whitespace separated) to skip')
    s.add_argument('--supported-only', action='store_true', help='contract-v2 verdict supported only')
    s.add_argument('--no-probe', action='store_true')
    s.set_defaults(f=cmd_plan)
    s = sub.add_parser('stamp')
    s.add_argument('--level', choices=('strict', 'loose'), default='strict')
    s.add_argument('--limit', type=int)
    s.add_argument('--jobs', type=int, default=4)
    s.add_argument('--redo', action='store_true')
    s.add_argument('--only', help='file of RVAs (hex) to run')
    s.set_defaults(f=cmd_stamp)
    s = sub.add_parser('status')
    s.add_argument('--level', choices=('strict', 'loose'), default='strict')
    s.set_defaults(f=cmd_status)
    a = p.parse_args()
    a.f(a)


if __name__ == '__main__':
    main()
