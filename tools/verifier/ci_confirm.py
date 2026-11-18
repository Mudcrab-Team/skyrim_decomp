#!/usr/bin/env python3
"""Batch CI second-host confirmation, retaining exact existing primary-host comparator evidence.

Called by confirm when runners.json selects ci-hash, or directly with --root/--list. A submission
uses a source-only branch, never main. Artifacts contain only sanitized JSON, never objects.
"""
import argparse
import copy
import importlib.machinery
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time
import uuid

HERE = Path(__file__).resolve().parent
TOOLS_ROOT = HERE.parents[1]
sys.path[:0] = [str(HERE), str(HERE.parent)]
import check
import ci_confirmation as evidence
import lint_reconstruction
import pipeline
import runners
from source_digest import include_closure
from digest_v2 import DIGEST_METHOD, tu_digest
import target_hashes

REPOSITORY = 'awarebayes/skyrim_decomp'


def command(argv, root, data=None, env=None):
    p = subprocess.run(argv, cwd=root, input=data, env=env, capture_output=True, check=True)
    return p.stdout.decode().strip()


def gh(root, endpoint, data=None):
    argv = ['gh', 'api', 'repos/' + REPOSITORY + '/' + endpoint]
    if data is not None:
        argv += ['--method', 'POST', '--input', '-']
    text = command(argv, root, json.dumps(data).encode() if data is not None else None)
    return json.loads(text) if text else None


def base_module():
    loader = importlib.machinery.SourceFileLoader('confirm_base_ci', str(HERE / 'confirm'))
    spec = importlib.util.spec_from_loader(loader.name, loader)
    module = importlib.util.module_from_spec(spec)
    loader.exec_module(module)
    return module


def local_inputs(root, task, base):
    """Find a registered primary host's all-pass output, binding its exact object and facts."""
    config = runners.load()
    evidence.require(config is not None, "first host needs a registered runner")
    hosts = [h for h in runners.for_confirm(config) if h["backend"] != "ci-hash"]
    evidence.require(len(hosts) == 1, "CI confirmation needs exactly one registered first host")
    host = hosts[0]
    label = host["host_id"]
    closure = include_closure(root, task['compiled'])
    digest = tu_digest(root, closure)
    recipe_sha = evidence.sha((root / task['recipe']).read_bytes())
    candidates = [task['dir'] / ('confirm/' + label)] + sorted((task['dir'] / 'attempts').glob('*'), reverse=True)
    for dest in candidates:
        if not (dest / 'candidate.obj').is_file():
            continue
        reports = {f['rva']: dest / f'0x{f["rva"]:x}/report.json' for f in task['functions']}
        if not all(p.is_file() for p in reports.values()):
            continue
        object_sha = evidence.sha((dest / 'candidate.obj').read_bytes())
        rows = [json.loads(p.read_text()) for p in reports.values()]
        if not all(r.get('result') == 'pass' and r['candidate']['object_sha256'] == object_sha
                   and r['source']['source_revision'] == digest and r['source']['path'] == task['compiled']
                   and r['recipe']['recipe_sha256'] == recipe_sha for r in rows):
            continue
        result = json.loads((dest / 'result.json').read_text())
        if result.get('host') != label:
            continue
        facts = result.get('host_facts') or {}
        pins = {name: value for value, name in (s.split() for s in
            (TOOLS_ROOT / 'tools/verifier/pinned.sha256').read_text().splitlines() if s.strip())}
        evidence.require(facts.get('loader') == host['loader']
                         and (facts.get('loader'), facts.get('os')) in {('wine', 'macos'), ('wine', 'linux'), ('native', 'windows')}
                         and facts.get('toolchain_check') == 'checked'
                         and facts.get('compiler_sha256') == pins, 'first host lacks verified toolchain facts')
        build = base.build_block(task, {label: dest})
        unit = dict(task_id=task['task_id'], unit=task['compiled'], closure=closure, source_sha256=digest,
                    recipe=task['recipe'], recipe_sha256=recipe_sha, functions=[
                        {k: v for k, v in f.items() if k in ('rva', 'size', 'symbol', 'internal_selector')}
                        for f in task['functions']], first_host=dict(host_id=label, machine=host["machine"], loader=facts["loader"], os=facts["os"]),
                    first_object_sha256=object_sha,
                    first_content_sha256=evidence.content_digest((dest / 'candidate.obj').read_bytes()))
        return unit, reports, build
    raise ValueError(f'{task["task_id"]}: no current all-pass first-host output with its exact object')


def submit(root, request, directory, log):
    """A minimal source-only commit on an isolated batch branch, using a temporary git index."""
    batch = 'p148-' + uuid.uuid4().hex[:12]
    request_path = 'data/ci-confirm/' + batch + '.json'
    blob = (json.dumps(request, indent=2) + '\n').encode()
    terms = check.anonymity_terms(root)
    check.check_anonymity(request_path, blob, terms)
    check.inspect_payload(request_path, blob)
    # Guard the exact source bytes before creating or pushing any public ref.
    payloads = {}
    for name, digest in request['files'].items():
        data = (root / name).read_bytes()
        evidence.require(evidence.sha(data) == digest, 'source changed before submission')
        check.check_anonymity(name, data, terms)
        check.inspect_payload(name, data)
        payloads[name] = data
    request_sha = evidence.sha(blob)
    with tempfile.TemporaryDirectory(dir=directory) as temp:
        env = dict(os.environ, GIT_INDEX_FILE=str(Path(temp) / 'index'))
        command(['git', 'read-tree', request['base_sha']], TOOLS_ROOT, env=env)
        for name, data in payloads.items():
            oid = command(['git', 'hash-object', '-w', '--stdin'], TOOLS_ROOT, data)
            command(['git', 'update-index', '--add', '--cacheinfo', '100644,' + oid + ',' + name], TOOLS_ROOT, env=env)
        oid = command(['git', 'hash-object', '-w', '--stdin'], TOOLS_ROOT, blob)
        command(['git', 'update-index', '--add', '--cacheinfo', '100644,' + oid + ',' + request_path], TOOLS_ROOT, env=env)
        tree = command(['git', 'write-tree'], TOOLS_ROOT, env=env)
        commit = command(['git', 'commit-tree', tree, '-p', request['base_sha']], TOOLS_ROOT,
                         ('CI confirmation source batch ' + batch + '\n').encode())
    command(['git', 'push', 'origin', commit + ':refs/heads/ci-confirm/' + batch], TOOLS_ROOT)
    # The workflow is trusted main, with only the source blobs taken from the candidate commit.
    evidence.require(command(['git', 'ls-remote', 'origin', 'refs/heads/main'], TOOLS_ROOT).split()[0]
                     == request['base_sha'], 'main moved; rebuild batch against its exact trusted revision')
    gh(root, 'actions/workflows/ci-confirm.yml/dispatches', dict(ref='main', inputs=dict(
        candidate=commit, request=request_path, request_sha=request_sha)))
    submission = dict(candidate_sha=commit, base_sha=request['base_sha'], request_sha256=request_sha,
                      branch='ci-confirm/' + batch, submitted=time.time())
    (directory / 'submission.json').write_text(json.dumps(submission, indent=2) + '\n')
    log(f'ci-hash: dispatched {len(request["units"])} units on {submission["branch"]}')
    return submission


def collect(root, submission, directory, log, timeout=900):
    started = time.monotonic()
    run = None
    while time.monotonic() - started < timeout:
        runs = gh(root, 'actions/workflows/ci-confirm.yml/runs?event=workflow_dispatch&per_page=30')['workflow_runs']
        hits = [r for r in runs if r['display_title'] == 'confirm-' + submission['request_sha256']
                and r['head_sha'] == submission['base_sha'] and r['run_attempt'] == 1]
        evidence.require(len(hits) <= 1, 'ambiguous workflow run')
        if hits:
            run = hits[0]
            if run['status'] == 'completed':
                break
        time.sleep(5)
    evidence.require(run is not None and run['status'] == 'completed' and run['conclusion'] == 'success',
                     'workflow failed or stalled; no confirmation')
    command(['gh', 'run', 'download', str(run['id']), '--repo', REPOSITORY,
             '--name', 'ci-confirm-result', '--dir', str(directory / 'artifact')], root)
    report = json.loads((directory / 'artifact/result.json').read_text())
    evidence.require(report['run_id'] == run['id'] and report['candidate_sha'] == submission['candidate_sha']
                     and report['base_sha'] == submission['base_sha']
                     and report['request_sha256'] == submission['request_sha256']
                     and report['conclusion'] == 'success', 'artifact/run binding differs')
    log(f'ci-hash: run {run["id"]} succeeded')
    return report


def run(root, task_dirs, replace=False, out=None, log=print):
    root = Path(root).resolve()
    started = time.monotonic()
    base = base_module()
    base.REPO = root
    tasks = [pipeline.load_task(d, repo=root) for d in task_dirs]
    evidence.require(len({t['task_id'] for t in tasks}) == len(tasks) and tasks, 'duplicate/empty task list')
    trusted = command(['git', 'rev-parse', 'origin/main'], TOOLS_ROOT)
    evidence.require(command(['git', 'diff', trusted, '--', *evidence.TOOLS], TOOLS_ROOT) == '',
                     'publish trusted tooling before CI confirmation')
    manifest = target_hashes.load_manifest(TOOLS_ROOT)
    targets = {r['rva']: r for r in manifest['functions']}
    request = dict(schema=1, base_sha=trusted, build_id=manifest['build_id'], files={}, units=[])
    saved = {}
    inventory = {f['rva']: f for f in json.loads((root / 'data/progress.json').read_text())['functions']}
    for task in tasks:
        evidence.require(task['symbols_repo'] is not None, 'confirm requires a public unit symbol map')
        unit, reports, build = local_inputs(root, task, base)
        evidence.require(evidence.sha((TOOLS_ROOT / task['recipe']).read_bytes()) == unit['recipe_sha256'],
                         'local recipe differs from trusted CI recipe')
        for f in task['functions']:
            row = targets.get(f['rva'])
            evidence.require(row is not None and row['size'] == f['size']
                             and row['extraction'] != 'unmasked-unsupported', f'{f["rva"]:#x}: no published target hash')
            evidence.require(inventory[f['rva']]['size'] == f['size'], 'inventory size differs')
            final = (Path(out) if out else root / 'reports') / task['build_id'] / f'0x{f["rva"]:x}.json'
            evidence.require(replace or not final.exists(), 'record exists; use --replace')
        for name in unit['closure']:
            evidence.require(not lint_reconstruction.lint_file(root, name, manifest['build_id']), 'source lint failed')
            request['files'][name] = evidence.sha((root / name).read_bytes())
        request['units'].append(unit)
        saved[task['task_id']] = task, reports, build
    directory = root / '.local/verifier/ci-confirm' / uuid.uuid4().hex[:12]
    directory.mkdir(parents=True)
    (directory / 'request.json').write_text(json.dumps(request, indent=2) + '\n')
    submission = submit(root, request, directory, log)
    report = collect(root, submission, directory, log)
    rows = {(r['task_id'], r['rva']): r for r in report['functions']}
    expected = {(t['task_id'], f['rva']) for t in tasks for f in t['functions']}
    evidence.require(set(rows) == expected and len(rows) == len(report['functions']), 'missing/extra/duplicate CI function')
    count = 0
    for unit in request['units']:
        task, reports, build = saved[unit['task_id']]
        evidence.require(tu_digest(root, include_closure(root, task['compiled'])) == unit['source_sha256'],
                         'source changed during CI run')
        for fn in task['functions']:
            rva = fn['rva']
            record = dict(match_record_schema=3 if 'internal_selector' in fn else 2,
                function_id=f'{task["build_id"]}-0x{rva:x}',
                source=dict(translation_unit=unit['closure'], compiled=unit['unit'], digest_method=DIGEST_METHOD,
                            digest=unit['source_sha256']), recipe=dict(path=task['recipe'], sha256=unit['recipe_sha256']),
                toolchain_pin=dict(path=check.TOOLCHAIN_PIN, sha256=evidence.sha((root / check.TOOLCHAIN_PIN).read_bytes())),
                symbol_map=dict(path=task['symbols_repo'], sha256=evidence.sha(task['symbols_local'].read_bytes())),
                reproduction='Run tools/verifier/confirm with a registered primary runner and the ci-hash confirmation runner; '
                             'tools/ci_confirm_batch.py compiles twice with the pinned recipe and checks published hashes.',
                build=build, notes=['CI second-host exception authorized by awarebayes 2026-11-15. '
                    'Full local comparator report is verbatim; CI independently verifies published target hashes '
                    'and whole non-debug object content. No game bytes enter CI.'] + task['record_notes'],
                runs=[dict(compiled_on=unit['first_host']['host_id'], compared_on=unit['first_host']['host_id'], report=json.loads(reports[rva].read_text()))])
            if fn.get('family_metadata'):
                record.update(fn['family_metadata'])
            record['ci_confirmation'] = {k: v for k, v in report.items() if k != 'functions'}
            record['ci_confirmation'].update(rows[task['task_id'], rva])
            # Validate in the source tree; it must carry the published tooling and target commitments.
            final = root / 'reports' / task['build_id'] / f'0x{rva:x}.json'
            scratch = final.parent / ('.ci-' + uuid.uuid4().hex + '.json')
            scratch.parent.mkdir(parents=True, exist_ok=True)
            try:
                scratch.write_text(json.dumps(record, indent=2, sort_keys=True) + '\n')
                check.validate_match(dict(inventory[rva], report=scratch.relative_to(root).as_posix()),
                                     json.loads((root / 'builds/target.json').read_text()), root=root)
                dest = (Path(out) / task['build_id'] / final.name) if out else final
                dest.parent.mkdir(parents=True, exist_ok=True)
                scratch.replace(dest)
                count += 1
            finally:
                scratch.unlink(missing_ok=True)
    seconds = time.monotonic() - started
    result = dict(confirmed=count, seconds=round(seconds, 3), functions_per_minute=round(count * 60 / seconds, 3),
                  run_id=report['run_id'], candidate_sha=submission['candidate_sha'])
    (directory / 'throughput.json').write_text(json.dumps(result, indent=2) + '\n')
    log(json.dumps(result))
    return 0


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--root', type=Path, default=TOOLS_ROOT)
    p.add_argument('--list', type=Path, required=True)
    p.add_argument('--out', type=Path)
    p.add_argument('--replace', action='store_true')
    a = p.parse_args()
    return run(a.root, a.list.read_text().splitlines(), a.replace, a.out)


if __name__ == '__main__':
    sys.exit(main())
