#!/usr/bin/env python3
"""Trusted GitHub Windows batch compiler. Only source blobs and sanitized JSON cross hosts."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tools/verifier')]
import ci_confirmation as evidence
import ci_hash_check
import ci_toolchain
import compare
import compare_internal
import contrib
import lint_reconstruction
from pecoff import CoffObject
from source_digest import include_closure
from digest_v2 import tu_digest
import target_hashes


def git(*args):
    return subprocess.run(['git', *args], cwd=ROOT, capture_output=True, check=True).stdout


def prepare(candidate, request_path, request_sha, work):
    evidence.require(bool(re.fullmatch('[0-9a-f]{40}', candidate)), 'invalid candidate SHA')
    evidence.require(bool(re.fullmatch(r'data/ci-confirm/[a-z0-9-]+\.json', request_path)), 'invalid request path')
    def blob(name):
        meta = git('ls-tree', candidate, '--', name).decode().split()
        evidence.require(len(meta) >= 3 and meta[0:2] == ['100644', 'blob'], 'not a regular source blob')
        size = int(git('cat-file', '-s', meta[2]))
        evidence.require(size <= (4 << 20 if name == request_path else 1 << 20), 'source blob too large')
        data = git('cat-file', 'blob', meta[2])
        evidence.require(b'\0' not in data, 'non-text source')
        data.decode('utf-8-sig')
        return data
    raw = blob(request_path)
    evidence.require(evidence.sha(raw) == request_sha, 'request digest differs')
    request = json.loads(raw)
    evidence.require(request['schema'] == 1 and request['base_sha'] == git('rev-parse', 'HEAD').decode().strip(),
                     'request base is not trusted tool revision')
    evidence.require(isinstance(request.get('units'), list) and 0 < len(request['units']) <= 4096, 'invalid unit count')
    names = request['files']
    evidence.require(isinstance(names, dict) and 0 < len(names) <= 20000, 'invalid file set')
    tree = work / 'source'
    tree.mkdir(parents=True)
    target = json.loads((ROOT / 'builds/target.json').read_text())['build_id']
    for name, digest in names.items():
        evidence.require(bool(contrib.UNIT_PATH.fullmatch(name)), 'outside source intake')
        data = blob(name)
        evidence.require(evidence.sha(data) == digest, 'source blob digest differs')
        path = tree / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
    recipes = target_hashes.load_manifest(ROOT)['recipe_sha256']
    for unit in request['units']:
        evidence.require(unit['recipe'] in recipes, 'unapproved recipe')
        evidence.require(bool(re.fullmatch('[a-z0-9][a-z0-9.-]{0,55}', unit['task_id'])), 'invalid task id')
        evidence.require(isinstance(unit.get('functions'), list) and 0 < len(unit['functions']) <= 10000, 'invalid function count')
        closure = include_closure(tree, unit['unit'])
        evidence.require(closure == unit['closure'] and tu_digest(tree, closure) == unit['source_sha256'],
                         'translation unit differs')
        data = (ROOT / unit['recipe']).read_bytes()
        evidence.require(evidence.sha(data) == unit['recipe_sha256'], 'recipe differs')
        recipe_path = tree / unit['recipe']
        recipe_path.parent.mkdir(parents=True, exist_ok=True)
        recipe_path.write_bytes(data)
    for name in names:
        header = lint_reconstruction.leading_comment((tree / name).read_text(encoding='utf-8-sig'))
        for ref in re.findall(r'Evidence:\s*([^\s,;]+)', header):
            ref = ref.rstrip('.')
            evidence.require(bool(re.fullmatch(r'(?:findings|reports)/[A-Za-z0-9_./-]+', ref))
                             and '..' not in Path(ref).parts, 'invalid evidence path')
            source = ROOT / ref
            evidence.require(source.is_file() and not source.is_symlink(), 'evidence is not published at trusted base')
            dest = tree / ref
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(source, dest)
        evidence.require(not lint_reconstruction.lint_file(tree, name, target), 'source lint failed')
    return request, tree


def compile_batch(request, tree, bindir, work):
    manifest = target_hashes.load_manifest(ROOT)
    targets = {r['rva']: r for r in manifest['functions']}
    ctx = contrib.Ctx(repo=ROOT, platform='win32', interactive=False)
    tool = dict(status='ok', flavour='native', bin=str(bindir), root=str(bindir.parents[6]))
    def one(unit):
        rows = []
        objects = []
        for attempt in range(2):
            built = contrib.compile_unit(ctx, tree, unit['unit'], unit['recipe'],
                work / unit['task_id'] / str(attempt), tool)
            objects.append(built['object'].read_bytes())
        contents = [evidence.content_digest(b) for b in objects]
        evidence.require(contents[0] == contents[1] == unit.get('first_content_sha256', unit.get('mac_content_sha256')),
                         'nondeterminism or local object content mismatch')
        for fn in unit['functions']:
            target = targets.get(fn['rva'])
            evidence.require(target is not None and target['size'] == fn['size']
                             and target['extraction'] != 'unmasked-unsupported', 'no published target hash')
            measurements = []
            for blob in objects:
                obj = CoffObject(blob)
                if fn.get('internal_selector'):
                    ident = compare_internal.make_identity(blob, fn['symbol'], fn['internal_selector'],
                                                          unit['source_sha256'], unit['unit'])
                    _, section = compare_internal.find_internal_function(obj, dict(symbol=fn['symbol'], internal_identity=ident))
                else:
                    _, section = compare.find_function(obj, fn['symbol'])
                evidence.require(len(section.data) == fn['size'], 'candidate size differs')
                measurements.append(target_hashes.section_hash(section))
            evidence.require(measurements[0] == measurements[1] ==
                             {k: target[k] for k in ('normalized_sha256', 'layout_sha256')},
                             'target hash/layout mismatch or nondeterminism')
            rows.append(dict(task_id=unit['task_id'], rva=fn['rva'], target=target,
                unit=unit['unit'], source_sha256=unit['source_sha256'], recipe_sha256=unit['recipe_sha256'],
                **({k: unit[k] for k in ('first_host', 'first_content_sha256', 'first_object_sha256')}
                   if 'first_host' in unit else {k: unit[k] for k in ('mac_content_sha256', 'mac_object_sha256')}),
                content_sha256=contents[0], object_sha256=evidence.sha(objects[0]),
                result='hash-match', deterministic=True, **measurements[0]))
        return rows
    with ThreadPoolExecutor(max_workers=4) as pool:
        return [row for rows in pool.map(one, request['units']) for row in rows]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--candidate', required=True)
    p.add_argument('--request', required=True)
    p.add_argument('--request-sha', required=True)
    p.add_argument('--bin', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    a = p.parse_args()
    report = dict(schema=1, kind='ci-hash', host_id='github-windows-native', machine='github-hosted-windows',
                  os='windows', loader='native', workflow=evidence.WORKFLOW,
                  base_sha=git('rev-parse', 'HEAD').decode().strip(), candidate_sha=a.candidate,
                  run_id=int(os.environ['GITHUB_RUN_ID']), run_attempt=int(os.environ['GITHUB_RUN_ATTEMPT']),
                  request_sha256=a.request_sha, tools_sha256=evidence.tools_digest(ROOT),
                  toolchain_manifest_sha256=evidence.sha((ROOT / ci_toolchain.INDEX).read_bytes()))
    try:
        evidence.require(report['run_attempt'] == 1, 'rerun not admitted; dispatch a fresh run')
        evidence.require(ci_toolchain.verify(ROOT, a.bin.parents[6]), 'toolchain cache verification failed')
        probe = ci_hash_check.probe(ROOT, a.bin)
        evidence.require(probe['toolset'] == 'MATCH', 'compiler pin mismatch')
        report.update(cache_verified=True, toolset='MATCH', compiler_sha256={f['name']: f['sha256'] for f in probe['files']})
        request, tree = prepare(a.candidate, a.request, a.request_sha, a.work)
        report['build_id'] = request['build_id']
        report['functions'] = compile_batch(request, tree, a.bin, a.work / 'objects')
        report['conclusion'] = 'success'
    except Exception as exc:
        # Never publish compiler diagnostics, candidate bytes or runner paths.
        report.update(conclusion='failure', error=type(exc).__name__)
    a.out.parent.mkdir(parents=True, exist_ok=True)
    a.out.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(conclusion=report['conclusion'], functions=len(report.get('functions', [])))))
    return int(report['conclusion'] != 'success')


if __name__ == '__main__':
    sys.exit(main())
