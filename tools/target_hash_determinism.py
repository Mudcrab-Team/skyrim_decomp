#!/usr/bin/env python3
"""Local-only 50-reference determinism/comparator audit. Keep all outputs under .local/."""
import argparse
import json
import os
from pathlib import Path
import sys

import record_store
import ci_hash_check as public
import compare
import compare_runtime
import contrib
from pecoff import CoffObject, PeImage, Reject
import target_hashes as hashes

ROOT = Path(__file__).resolve().parents[1]


def audit(root, image_path, msvc, work):
    manifest = hashes.load_manifest(root)
    image_bytes = image_path.read_bytes()
    if hashes.digest(image_bytes) != manifest['image_sha256']:
        raise ValueError('image pin differs')
    image = PeImage(image_bytes)
    ctx = contrib.Ctx(repo=root, env=dict(os.environ, SR_MSVC=str(msvc)), interactive=False)
    tool = contrib.check_toolchain(ctx)
    if tool['status'] != 'ok':
        raise ValueError('toolchain pin differs')
    inventory = {f['rva']: f for f in json.loads((root / 'data/progress.json').read_text())['functions']}
    targets = {f['rva']: f for f in manifest['functions']}
    rvas = json.loads((root / 'data/target-hashes/determinism-sample.json').read_text())['rvas']
    if len(rvas) != 50 or len(set(rvas)) != 50:
        raise ValueError('sample must contain 50 distinct references')
    results = []
    for rva in rvas:
        ref = public.reference(root, rva)
        record = json.loads(record_store.read_text(root / inventory[rva]['report']))
        version = record['runs'][0]['report']['comparator']['version']
        engine = {compare.COMPARATOR_VERSION: compare,
                  compare_runtime.COMPARATOR_VERSION: compare_runtime}[version]
        target_data = image.read(rva, ref['size'], 'target sample')[1]
        inferred = hashes.layout(hashes.target_section(target_data, rva))
        values, passes, layout_equal = [], [], []
        for attempt in range(2):
            built = contrib.compile_unit(ctx, root, ref['unit'], ref['recipe'],
                                         work / f'{rva:x}' / str(attempt), tool)
            obj = built['object'].read_bytes()
            _sym, sec = compare.find_function(CoffObject(obj), ref['symbol'])
            values.append(hashes.section_hash(sec))
            layout_equal.append(hashes.layout(sec) == inferred)
            task = dict(task_id=inventory[rva]['id'], build_id=manifest['build_id'], rva=rva,
                        size=ref['size'], symbol=ref['symbol'], source_path=ref['unit'],
                        source_revision=built['digest'], recipe_sha256=built['recipe_sha256'],
                        target_image_sha256=manifest['image_sha256'])
            report = engine.compare(task, json.loads((root / 'builds/target.json').read_text()),
                                    (root / ref['recipe']).read_bytes(),
                                    json.loads(built['build_record'].read_text()), obj, image_bytes,
                                    (root / record['symbol_map']['path']).read_bytes())
            (work / f'{rva:x}' / str(attempt) / 'comparator.json').write_text(json.dumps(report, indent=2) + '\n')
            passes.append(report['result'] == 'pass')
        row = dict(rva=rva, size=ref['size'], deterministic=values[0] == values[1],
                   hash_equal=all(v['normalized_sha256'] == targets[rva]['normalized_sha256']
                                  and v['layout_sha256'] == targets[rva]['layout_sha256'] for v in values),
                   comparator_pass=all(passes), layout_equal=all(layout_equal))
        results.append(row)
        # Only metadata and booleans are public-facing; bytes and diagnostics never printed.
        print(json.dumps(row), flush=True)
    return results


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--image', type=Path, required=True)
    p.add_argument('--msvc', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    a = p.parse_args(argv)
    if '.local' not in a.work.resolve().parts:
        p.error('audit output must stay under .local/')
    a.work.mkdir(parents=True, exist_ok=True)
    try:
        rows = audit(ROOT, a.image, a.msvc, a.work)
    except (ValueError, KeyError, OSError, Reject, contrib.Stop) as exc:
        print(json.dumps(dict(error=type(exc).__name__, acceptance='not-evaluated')))
        return 1
    (a.work / 'determinism.json').write_text(json.dumps(rows, indent=2) + '\n')
    return int(any(not all(r[k] for k in ('deterministic', 'hash_equal', 'comparator_pass', 'layout_equal'))
                   for r in rows))


if __name__ == '__main__':
    sys.exit(main())
