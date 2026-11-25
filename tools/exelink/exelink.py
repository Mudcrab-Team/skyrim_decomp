#!/usr/bin/env python3
"""Relink matched functions into a copy of the owner's executable at their original RVAs.

    python3 tools/exelink/exelink.py plan --out .local/exelink/plan.json [--sample N --seed S] [--shard K/N]
    python3 tools/exelink/exelink.py link --plan PLAN --objects DIR [--image EXE] [--report DIR]
    python3 tools/exelink/exelink.py run  --plan PLAN --objects DIR --msvc TOOLCHAIN [--image EXE] [--report DIR]
    python3 tools/exelink/exelink.py merge SUMMARY.json... [--summary OUT.json]

`link` takes objects already built (`<unit id>.obj` in --objects, from a verifier or CI-hash build);
`run` also compiles the planned units with the pinned recipe on a Windows host as it goes and deletes
each object once placed. The image is the owner's own executable (--image, or `image` in
.local/verifier/config.json) and must hash to builds/target.json. Output on stdout is counts, RVAs
and names. Per-function rows (--report DIR) and the relinked image (--out-image) derive from the
owner's executable, so both must be written under a `.local` directory. See docs/exelink.md.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys
import time

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import relink  # noqa: E402
import units as plans  # noqa: E402
from pecoff import Reject  # noqa: E402

ROOT = plans.ROOT


def private_path(path):
    """Resolve `path`, refusing any location outside a `.local` directory."""
    path = Path(path).resolve()
    if '.local' not in path.parts:
        raise SystemExit(f'refusing {path}: output derived from the image must be under a .local directory')
    return path


def default_image(repo):
    try:
        return json.loads((Path(repo) / '.local/verifier/config.json').read_text()).get('image')
    except (OSError, ValueError):
        return None


def load_image(path, target):
    blob = Path(path).read_bytes()
    digest = hashlib.sha256(blob).hexdigest()
    if digest != target['image_sha256']:
        raise SystemExit('the image does not hash to builds/target.json; refusing to link into it')
    return blob, digest


def link_unit(repo, linker, unit, objects, build_id):
    """Place every function of one planned unit; each missing input is a named not-linked reason."""
    obj_path = plans.object_path(objects, unit)
    try:
        object_bytes = obj_path.read_bytes()
    except OSError:
        object_bytes = None
    symbols = None
    if object_bytes is not None:
        try:
            symbols = relink.parse_map(plans.read_symbol_map(repo, unit['symbols']), build_id)
        except (OSError, Reject):
            symbols = None
    for spec in unit['functions']:
        if object_bytes is None:
            linker.skip(spec, 'no-object')
        elif symbols is None:
            linker.skip(spec, 'symbol-map-unusable')
        else:
            linker.place(spec, object_bytes, symbols)


def load_patches(path):
    if not path:
        return []
    patches = json.loads(Path(path).read_text())
    if not (isinstance(patches, list) and all(isinstance(p, dict) and isinstance(p.get('rva'), int)
                                              and isinstance(p.get('length'), int) and p['length'] > 0
                                              for p in patches)):
        raise SystemExit('--post-link must be a JSON list of {"rva": int, "length": int, "label": str}')
    return patches


def format_summary(summary):
    lines = [f'functions: {summary["functions"]}']
    for name, count in summary['classes'].items():
        lines.append(f'  {name:24} {count:8}  {relink.CLASS_TEXT[name]}')
    for reason, count in summary['not_linked_reasons'].items():
        lines.append(f'    not linked, {reason}: {count}')
    rel = summary['relocations']
    lines.append(f'relocations: {rel["resolved"]} resolved, {rel["unresolved"]} unresolved '
                 f'in {rel["functions_with_unresolved"]} functions')
    for k, v in summary['notes'].items():
        lines.append(f'note {k}: {v}')
    lines.append('sections:')
    for s in summary['sections']:
        res = s['result']
        what = 'identical' if res == relink.IDENTICAL else \
            f'first difference at RVA 0x{res["first_diff_rva"]:x} in {res["function"]}'
        lines.append(f'  {s["name"]:10} {s["functions"]:7} functions {s["placed_bytes"]:10} bytes placed  {what}')
    lines.append(f'output identical to retail: {summary["output_identical_to_retail"]}')
    return '\n'.join(lines)


def finish(args, linker, plan, image_sha, started):
    sections = linker.finish()
    summary = relink.summarize(linker, sections, image_sha, plan['build_id'])
    summary['seconds'] = round(time.monotonic() - started, 1)
    print(format_summary(summary))
    if args.summary:
        Path(args.summary).write_text(json.dumps(summary, indent=1, sort_keys=True) + '\n')
    if args.report:
        report = private_path(args.report)
        report.mkdir(parents=True, exist_ok=True)
        (report / 'summary.json').write_text(json.dumps(summary, indent=1, sort_keys=True) + '\n')
        with open(report / 'functions.jsonl', 'w') as out:
            for res in sorted(linker.results, key=lambda r: r.rva):
                out.write(json.dumps(res.row(), sort_keys=True) + '\n')
        shown = [r for r in linker.results if r.status != relink.IDENTICAL]
        print(f'per-function rows: {report / "functions.jsonl"} ({len(shown)} not identical)')
    if args.out_image:
        out = private_path(args.out_image)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(linker.work)
        print(f'relinked image written to {out}')
    return 0 if summary['output_identical_to_retail'] and not summary['classes'][relink.NOT_LINKED] else 1


def start(args):
    plan = json.loads(Path(args.plan).read_text())
    target = json.loads((ROOT / 'builds/target.json').read_text())
    if plan.get('plan_schema') != plans.PLAN_SCHEMA or plan['build_id'] != target['build_id']:
        raise SystemExit('plan is not for the pinned build')
    image = args.image or default_image(ROOT)
    if not image:
        raise SystemExit('no image: pass --image or set "image" in .local/verifier/config.json')
    blob, digest = load_image(image, target)
    return plan, relink.Linker(blob, load_patches(args.post_link)), digest


def cmd_plan(args):
    shard = None
    if args.shard:
        index, count = (int(x) for x in args.shard.split('/'))
        if not 0 <= index < count:
            raise SystemExit('--shard K/N needs 0 <= K < N')
        shard = (index, count)
    plan = plans.make_plan(ROOT, units=args.unit, sample=args.sample, seed=args.seed, shard=shard)
    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(plan, indent=1) + '\n')
    print(f'plan: {plan["functions"]} functions in {len(plan["units"])} units -> {out}')
    return 0


def cmd_link(args):
    started = time.monotonic()
    plan, linker, digest = start(args)
    for unit in plan['units']:
        link_unit(ROOT, linker, unit, args.objects, plan['build_id'])
    return finish(args, linker, plan, digest, started)


def cmd_run(args):
    started = time.monotonic()
    plan, linker, digest = start(args)
    objects = Path(args.objects)
    todo = plan['units']
    done = 0

    def placed(batch, failed):
        nonlocal done
        for unit in batch:
            link_unit(ROOT, linker, unit, objects, plan['build_id'])
            if not args.keep_objects:
                plans.object_path(objects, unit).unlink(missing_ok=True)
        done += len(batch)
        print(f'  {done}/{len(todo)} units, {len(failed)} failed in this batch, '
              f'{round(time.monotonic() - started)} s', flush=True)

    plans.build_units(ROOT, todo, objects, args.msvc, jobs=args.jobs, batch_size=args.batch, on_batch=placed)
    return finish(args, linker, plan, digest, started)


def cmd_merge(args):
    summary = relink.merge_summaries([json.loads(Path(p).read_text()) for p in args.summaries])
    summary.pop('seconds', None)
    print(format_summary(summary))
    if args.summary:
        Path(args.summary).write_text(json.dumps(summary, indent=1, sort_keys=True) + '\n')
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='command', required=True)

    def common(q, objects=True):
        q.add_argument('--plan', required=True)
        q.add_argument('--objects', required=objects, help='directory of <unit id>.obj files')
        q.add_argument('--image', help='the owner\'s executable (default: .local/verifier/config.json)')
        q.add_argument('--post-link', help='JSON list of declared post-link patch ranges {rva, length, label}')
        q.add_argument('--report', help='write summary.json and functions.jsonl here (under .local)')
        q.add_argument('--summary', help='also write the counts-only summary here')
        q.add_argument('--out-image', help='write the relinked image here (under .local)')

    q = sub.add_parser('plan', help='list the matched functions to place')
    q.add_argument('--out', required=True)
    q.add_argument('--unit', action='append', help='only this compiled file (repeatable)')
    q.add_argument('--sample', type=int, help='keep this many units, chosen with --seed')
    q.add_argument('--seed', type=int, default=0)
    q.add_argument('--shard', help='K/N: every Nth unit starting at K')
    q.set_defaults(func=cmd_plan)
    q = sub.add_parser('link', help='place functions from objects that are already built')
    common(q)
    q.set_defaults(func=cmd_link)
    q = sub.add_parser('run', help='compile the planned units on this Windows host and place them')
    common(q)
    q.add_argument('--msvc', required=True, help='the unpacked pinned toolchain (see docs/windows-verifier-host.md)')
    q.add_argument('--jobs', type=int, default=1, help='compiler runs in parallel (default 1)')
    q.add_argument('--batch', type=int, default=24, help='units per compiler run')
    q.add_argument('--keep-objects', action='store_true')
    q.set_defaults(func=cmd_run)
    q = sub.add_parser('merge', help='add up the summaries of several shards')
    q.add_argument('summaries', nargs='+')
    q.add_argument('--summary')
    q.set_defaults(func=cmd_merge)
    args = p.parse_args(argv)
    return args.func(args)


if __name__ == '__main__':
    sys.exit(main())
