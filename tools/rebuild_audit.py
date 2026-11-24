#!/usr/bin/env python3
"""Rebuild all matched units from a clean pinned checkout; never change acceptance records.

prepare exports the current include closures and recorded recipes/maps from --repo (a clean
checkout at --revision, default origin/main). Copy that private export to each runner once.
run executes locally ON the runner, with a bounded pool and an append-only resumable journal.
The original unit_build.py and comparator are copied verbatim from the audited revision.
No old object or comparator pass is reused. Digest drift alone is an observation, not a failure.
This audits all accepted translation units, not a linked game executable or ODR correctness.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
from collections import Counter
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess
import sys
import time

TOOL_FILES = ('tools/compare_runtime.py', 'tools/compare_internal.py', 'tools/compare.py',
              'tools/pecoff.py', 'tools/source_digest.py', 'tools/digest_v2.py', 'tools/verifier/verify_function.py',
              'tools/verifier/unit_build.py', 'tools/verifier/pinned.sha256', 'builds/target.json')
CAUSES = ('header-drift', 'recipe-or-compiler-mismatch', 'missing-file', 'other')


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def json_write(path, value):
    path = Path(path)
    tmp = path.with_suffix(path.suffix + '.tmp')
    tmp.write_text(json.dumps(value, sort_keys=True) + '\n', encoding='utf-8')
    # Windows readers (including SFTP) may briefly deny deletion of the old summary.
    for attempt in range(50):
        try:
            os.replace(tmp, path)
            return
        except PermissionError:
            if attempt == 49:
                raise
            time.sleep(min(.02 * (attempt + 1), .2))


def private(path):
    path = Path(path).resolve()
    if '.local' not in path.parts:
        raise ValueError('audit outputs must be under .local')
    return path


def relative(name):
    p = PurePosixPath(name)
    if p.is_absolute() or '..' in p.parts or '\\' in name or ':' in name or not p.parts:
        raise ValueError('unsafe repository path')
    if p.parts[0] in ('.git', '.local'):
        raise ValueError('private input in export')
    return name


def git(repo, *args):
    return subprocess.check_output(['git', '-C', str(repo), *args], text=True).strip()


def prepare(repo, out, revision):
    repo, out = Path(repo).resolve(), private(out)
    commit = git(repo, 'rev-parse', 'HEAD')
    if commit != git(repo, 'rev-parse', revision) or git(repo, 'status', '--porcelain', '--untracked-files=all'):
        raise ValueError('prepare requires a clean checkout at the requested revision')
    if out.exists():
        raise ValueError('export already exists; resume run or use a new export directory')
    # Import only the source-closure scanner from the audited tree, not the working tree.
    sys.path.insert(0, str(repo / 'tools'))
    from digest_v2 import tu_digest
    from check_source_digest import include_closure, source_digest_cache
    target = json.loads((repo / 'builds/target.json').read_text())
    progress = json.loads((repo / 'data/progress.json').read_text())
    matched = [f for f in progress['functions'] if f['status'] == 'matched']
    groups, seen = {}, set()
    file_hashes, generated = {}, {}

    def snapshot_hash(name):
        if name not in file_hashes:
            file_hashes[name] = digest(repo / relative(name))
        return file_hashes[name]
    with source_digest_cache():
        for fn in matched:
            identity = (fn['build_id'], fn['rva'])
            if identity in seen:
                raise ValueError('duplicate matched function')
            seen.add(identity)
            if fn['build_id'] != target['build_id']:
                raise ValueError('matched function belongs to a different target')
            try:
                import record_store
                rec = json.loads(record_store.read_text(repo / relative(fn['report'])))
            except FileNotFoundError:
                key = ('missing-record', fn['rva'])
                groups[key] = {'compiled': None, 'functions': [{'rva': fn['rva'], 'size': fn['size']}],
                               'preflight': 'missing-file', 'files': {}, 'drift': False}
                continue
            if rec['function_id'] != fn['id']:
                raise ValueError('record identity differs from matched inventory')
            key = tuple(rec[k]['path'] for k in ('recipe', 'symbol_map', 'toolchain_pin'))
            key = (rec['source']['compiled'], *key,
                   *(rec[k]['sha256'] for k in ('recipe', 'symbol_map', 'toolchain_pin')))
            if key not in groups:
                compiled = relative(rec['source']['compiled'])
                group = dict(compiled=compiled, recipe=relative(rec['recipe']['path']),
                             symbols=relative(rec['symbol_map']['path']), functions=[], files={},
                             preflight=None, drift=False)
                groups[key] = group
                try:
                    closure = include_closure(repo, compiled)
                    group['digest'] = tu_digest(repo, closure, rec['source'].get('digest_method'))
                    if snapshot_hash(group['symbols']) != rec['symbol_map']['sha256']:
                        # Rebuild the exact historical map using the gate's existing content proof.
                        # Compiler source/headers still come only from the current clean checkout.
                        import symbol_map
                        state = symbol_map.load_state(repo, group['symbols'])
                        names = state.names_for(rec['symbol_map']['sha256'])
                        blob = symbol_map.serialize(symbol_map.subset(state.current, names))
                        if hashlib.sha256(blob).hexdigest() != rec['symbol_map']['sha256']:
                            raise ValueError('recorded symbol map cannot be reproduced')
                        group['symbols'] = 'task/maps/' + rec['symbol_map']['sha256'] + '.json'
                        generated[group['symbols']] = blob
                        file_hashes[group['symbols']] = rec['symbol_map']['sha256']
                    files = set(TOOL_FILES) | set(closure) | {group['recipe'], group['symbols']}
                    group['files'] = {name: snapshot_hash(name) for name in sorted(files)}
                    if any(snapshot_hash(rec[k]['path']) != rec[k]['sha256']
                           for k in ('recipe', 'toolchain_pin')):
                        group['preflight'] = 'recipe-or-compiler-mismatch'
                except FileNotFoundError:
                    group['preflight'] = 'missing-file'
                except (OSError, ValueError):
                    group['preflight'] = 'other'
            group = groups[key]
            report = rec['runs'][0]['report']
            actual = report['function']
            if any(actual[k] != fn[k] for k in ('build_id', 'rva', 'size')):
                raise ValueError('record function differs from matched inventory')
            function = {k: actual[k] for k in ('rva', 'size', 'symbol')}
            if 'internal_identity' in actual:
                ident = actual['internal_identity']
                function['internal_selector'] = {k: ident[k] for k in
                    ('section_number', 'section_name', 'entry_offset', 'storage_class', 'symbol_type')}
            hashes = {r['report']['candidate']['code_section_sha256'] for r in rec['runs']}
            function['expected_hashes'] = sorted(hashes)
            function['digest_drift'] = group.get('digest') != rec['source']['digest']
            group['drift'] |= function['digest_drift']
            group['functions'].append(function)
    units = []
    for index, group in enumerate(groups.values()):
        group.update(id=f'u{index:06d}', build_id=target['build_id'])
        group['functions'].sort(key=lambda f: f['rva'])
        units.append(group)
    out.mkdir(parents=True)
    all_files = {name: sha for u in units for name, sha in u['files'].items()}
    for name, sha in sorted(all_files.items()):
        dest = out / 'tree' / name
        dest.parent.mkdir(parents=True, exist_ok=True)
        if name in generated:
            dest.write_bytes(generated[name])
        else:
            shutil.copyfile(repo / name, dest)
        if digest(dest) != sha:
            raise ValueError('snapshot changed during export')
    plan = dict(schema=1, commit=commit, build_id=target['build_id'], total=len(matched),
                image_sha256=target['image_sha256'], files=all_files, units=units)
    json_write(out / 'plan.json', plan)
    shutil.copyfile(Path(__file__), out / 'rebuild_audit.py')
    # Ensure no tracked input changed while records and include closures were being read.
    if git(repo, 'status', '--porcelain', '--untracked-files=all') or git(repo, 'rev-parse', 'HEAD') != commit:
        raise ValueError('audited checkout changed during export')
    print(json.dumps(dict(commit=commit, total=len(matched), units=len(units),
                          digest_drift=sum(f['digest_drift'] for u in units for f in u['functions'] if 'digest_drift' in f))))
    return plan


def read_journal(path):
    """Recover a torn final append, but refuse corruption in any completed line."""
    if not Path(path).exists():
        return {}
    data = Path(path).read_bytes()
    end = data.rfind(b'\n') + 1
    rows = {}
    for line in data[:end].splitlines():
        row = json.loads(line)
        if row['unit'] in rows:
            raise ValueError('duplicate journal result')
        rows[row['unit']] = row
    if end != len(data):
        with open(path, 'r+b') as stream:
            stream.truncate(end)
    return rows


def classify(code, error, drift):
    if code == 44 or error.startswith(('toolchain-', 'recipe-')):
        return 'recipe-or-compiler-mismatch'
    if error in ('image-missing', 'missing-file'):
        return 'missing-file'
    if drift and (code in (1, 3) or error.startswith(('include-', 'unit-invalid'))):
        return 'header-drift'  # candidate cause; confirm with history before attributing a commit
    return 'other'


def execute_unit(export, unit, args):
    start = time.monotonic()
    folder = args.out / 'scratch' / unit['id']
    if folder.exists():
        shutil.rmtree(folder)
    folder.mkdir(parents=True)
    repo, work = folder / 'repo', folder / 'work'
    code, error, facts = 4, unit.get('preflight'), None
    reports = {}
    if not error:
        try:
            for name in unit['files']:
                dest = repo / name
                dest.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(export / 'tree' / name, dest)
            spec = dict(unit_spec_schema=2 if any('internal_selector' in f for f in unit['functions']) else 1,
                        task_id=unit['id'], host=args.host, compiled=unit['compiled'],
                        build_id=unit['build_id'], recipe=unit['recipe'], symbols=unit['symbols'],
                        functions=[{k: f[k] for k in ('rva', 'size', 'symbol', 'internal_selector') if k in f}
                                   for f in unit['functions']], files=unit['files'])
            json_write(folder / 'spec.json', spec)
            command = [sys.executable, '-I', str(repo / 'tools/verifier/unit_build.py'), '--repo', str(repo),
                       '--spec', str(folder / 'spec.json'), '--work', str(work), '--msvc', str(args.msvc),
                       '--image', str(args.image), '--loader', args.loader]
            with open(folder / 'unit.log', 'w', encoding='utf-8') as log:
                code = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT, timeout=600).returncode
            if (work / 'error.json').exists():
                error = json.loads((work / 'error.json').read_text()).get('status')
            if (work / 'result.json').exists():
                facts = json.loads((work / 'result.json').read_text()).get('host_facts')
            for f in unit['functions']:
                path = work / f'0x{f["rva"]:x}' / 'report.json'
                if path.exists():
                    reports[f['rva']] = json.loads(path.read_text())
        except FileNotFoundError:
            error = 'missing-file'
        except subprocess.TimeoutExpired:
            error = 'unit-timeout'
        except (OSError, ValueError):
            error = 'unit-error'
    rows = []
    for f in unit['functions']:
        report = reports.get(f['rva']) or {}
        passed = (not error and report.get('result') == 'pass'
                  and report.get('function', {}).get('rva') == f['rva'])
        reason = 'all-checks-passed' if passed else error or report.get('reason') or f'unit-exit-{code}'
        # Only closed reason tokens enter summaries; raw exceptions/diagnostics stay private.
        if not re.fullmatch(r'[a-z0-9-]{1,100}', reason):
            reason = 'unclassified-error'
        rows.append(dict(rva=f['rva'], result='pass' if passed else 'fail', reason=reason,
                         cause=None if passed else unit.get('preflight') or classify(code, reason, f.get('digest_drift')),
                         digest_drift=f.get('digest_drift', False),
                         code_hash_drift=bool(report.get('candidate')) and
                         report['candidate'].get('code_section_sha256') not in f.get('expected_hashes', [])))
    result = dict(unit=unit['id'], seconds=round(time.monotonic()-start, 3), exit=code,
                  facts=facts, functions=rows)
    if all(r['result'] == 'pass' for r in rows):
        shutil.rmtree(folder)
    return result


def summarize(plan, rows, identity, seconds):
    functions = [f for row in rows.values() for f in row['functions']]
    passed = sum(f['result'] == 'pass' for f in functions)
    failed = len(functions) - passed
    return dict(**identity, total=plan['total'], passed=passed, failed=failed,
                pending=plan['total']-len(functions), units_done=len(rows), units_total=len(plan['units']),
                seconds=round(seconds, 2), functions_per_second=round(len(functions)/seconds, 3) if seconds else 0,
                failure_causes=dict(Counter(f['cause'] for f in functions if f['result'] != 'pass')),
                digest_drift=sum(f['digest_drift'] for f in functions),
                code_hash_drift=sum(f['code_hash_drift'] for f in functions),
                failures=[f for f in functions if f['result'] != 'pass'])


def run(args):
    export, args.out = private(args.export), private(args.out)
    args.msvc, args.image = args.msvc.resolve(), args.image.resolve()
    plan = json.loads((export / 'plan.json').read_text())
    args.out.mkdir(parents=True, exist_ok=True)
    # Refuse concurrent writers, with an OS-held lock that is released on crash.
    lock = open(args.out / 'lock', 'a+b')
    if sys.platform == 'win32':
        import msvcrt
        lock.seek(0); lock.write(b'0'); lock.flush(); lock.seek(0)
        msvcrt.locking(lock.fileno(), msvcrt.LK_NBLCK, 1)
    else:
        import fcntl
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    try:
        identity = dict(schema=1, commit=plan['commit'], plan_sha256=digest(export / 'plan.json'),
                        audit_tool_sha256=digest(__file__), host=args.host, loader=args.loader,
                        image_sha256=digest(args.image),
                        toolchain_pin_sha256=digest(export / 'tree/tools/verifier/pinned.sha256'))
        if identity['image_sha256'] != plan['image_sha256']:
            raise ValueError('runner target image mismatch')
        # Every resume rechecks the export, target and actual compiler, never trusts a stale marker.
        for name, sha in plan['files'].items():
            if digest(export / 'tree' / relative(name)) != sha:
                raise ValueError('export hash mismatch')
        sys.path.insert(0, str(export / 'tree/tools/verifier'))
        import unit_build
        env = unit_build.clean_env(os.environ)
        wrapper = (unit_build.native_settings(args.msvc) if args.loader == 'native'
                   else unit_build.wrapper_settings(args.msvc, env))
        _, hashes = unit_build.prepare_host(export / 'tree', args.msvc, args.image, wrapper,
                                            plan['image_sha256'], use_cache=False)
        identity['compiler_sha256'] = hashes
        identity['host_facts'] = unit_build.host_facts(args.loader, hashes, 'checked')
        # Private locations bind resume without putting locations in the sanitized result.
        binding = dict(identity=identity, msvc=str(args.msvc), image=str(args.image))
        saved = args.out / 'identity.json'
        if saved.exists():
            if json.loads(saved.read_text()) != binding:
                raise ValueError('resume identity differs; use a new output directory')
        elif (args.out / 'results.jsonl').exists() and (args.out / 'results.jsonl').stat().st_size:
            raise ValueError('journal has no bound identity; use a new output directory')
        json_write(saved, binding)
        rows = read_journal(args.out / 'results.jsonl')
        unit_ids = {u['id'] for u in plan['units']}
        if set(rows) - unit_ids:
            raise ValueError('journal contains an unknown unit')
        previous = json.loads((args.out / 'summary.json').read_text()) if (args.out / 'summary.json').exists() else {}
        base_seconds = previous.get('seconds', 0)
        start = time.monotonic()
        pending = [u for u in plan['units'] if u['id'] not in rows]
        if args.limit:
            pending = pending[:args.limit]
        with open(args.out / 'results.jsonl', 'a', encoding='utf-8') as journal, ThreadPoolExecutor(args.jobs) as pool:
            futures = [pool.submit(execute_unit, export, unit, args) for unit in pending]
            last = 0
            try:
                for future in as_completed(futures):
                    row = future.result()
                    journal.write(json.dumps(row, sort_keys=True)+'\n'); journal.flush(); os.fsync(journal.fileno())
                    rows[row['unit']] = row
                    now = time.monotonic()
                    if now-last > 15 or len(rows) == len(plan['units']):
                        summary = summarize(plan, rows, identity, base_seconds+now-start)
                        json_write(args.out / 'summary.json', summary)
                        print(json.dumps({k: summary[k] for k in ('host', 'passed', 'failed', 'pending', 'functions_per_second')}), flush=True)
                        last = now
            except BaseException:
                # Do not drain an entire uncheckpointed queue after a state-write failure.
                for future in futures:
                    future.cancel()
                raise
        summary = summarize(plan, rows, identity, base_seconds+time.monotonic()-start)
        json_write(args.out / 'summary.json', summary)
        return 1 if summary['failed'] else 2 if summary['pending'] else 0
    finally:
        lock.close()


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='command', required=True)
    prep = sub.add_parser('prepare')
    prep.add_argument('--repo', type=Path, required=True)
    prep.add_argument('--revision', default='origin/main')
    prep.add_argument('--out', type=Path, required=True)
    worker = sub.add_parser('run')
    for name in ('export', 'out', 'msvc', 'image'):
        worker.add_argument('--'+name, type=Path, required=True)
    worker.add_argument('--host', required=True)
    worker.add_argument('--loader', choices=('wine', 'native'), required=True)
    worker.add_argument('--jobs', type=int, default=8)
    worker.add_argument('--limit', type=int, help='pilot at most this many additional units; still reports pending')
    a = p.parse_args()
    if a.command == 'prepare':
        prepare(a.repo, a.out, a.revision)
        return 0
    if not 1 <= a.jobs <= 64 or not re.fullmatch(r'[a-z0-9-]{2,40}', a.host) or (a.limit is not None and a.limit < 1):
        p.error('invalid jobs, host or limit')
    return run(a)


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (ValueError, OSError) as exc:
        # No private path or raw compiler diagnostics in terminal output.
        print(f'audit-error {type(exc).__name__}', file=sys.stderr)
        raise SystemExit(2)
