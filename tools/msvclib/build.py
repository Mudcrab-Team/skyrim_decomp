#!/usr/bin/env python3
"""Compile generated library-shape units with the pinned recipe flags, natively on Windows.

    build.py --src DIR --out DIR --cl cl.exe --include DIR [--include DIR ...] [--jobs 4] [--only SUBSTR]

Objects, per-unit logs and results.json land under --out. A unit that fails to compile is recorded with its
first error lines and does not stop the run.
"""
import argparse
import json
import os
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

FLAGS = ['/nologo', '/c', '/O2', '/MD', '/GS-', '/EHsc', '/GR', '/fp:precise', '/Gy', '/w', '/std:c++14']


def compile_unit(cl, src, includes, out, name, timeout):
    obj, log = out / 'obj' / f'{name}.obj', out / 'logs' / f'{name}.log'
    cmd = [str(cl)] + FLAGS + [f'/I{src}'] + [f'/I{i}' for i in includes] + [f'/Fo{obj}', str(src / f'{name}.cpp')]
    t = time.time()
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout, stdin=subprocess.DEVNULL,
                           env=dict(os.environ, INCLUDE=os.pathsep.join(str(i) for i in includes)))
        text, rc = p.stdout + p.stderr, p.returncode
    except subprocess.TimeoutExpired:
        text, rc = 'TIMEOUT', 99
    log.write_text(text)
    errs = [x for x in text.splitlines() if 'error C' in x or 'fatal error' in x]
    return {'unit': name, 'ok': rc == 0 and obj.exists(), 'seconds': round(time.time() - t, 1), 'errors': errs[:4]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--src', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--cl', required=True)
    ap.add_argument('--include', action='append', default=[])
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--timeout', type=int, default=600)
    ap.add_argument('--only', default='')
    a = ap.parse_args()
    src, out = Path(a.src).resolve(), Path(a.out).resolve()
    (out / 'obj').mkdir(parents=True, exist_ok=True)
    (out / 'logs').mkdir(exist_ok=True)
    names = [u['source'][:-4] for u in json.load(open(src / 'units.json'))['units'] if a.only in u['source']]
    results = []
    with ThreadPoolExecutor(min(a.jobs, 4)) as ex:  # the shared PC allows four compiles at most
        for r in ex.map(lambda n: compile_unit(a.cl, src, a.include, out, n, a.timeout), names):
            results.append(r)
            print('OK ' if r['ok'] else 'ERR', r['unit'], r['seconds'], (r['errors'] or [''])[0][:140], flush=True)
    (out / 'results.json').write_text(json.dumps(results, indent=1))
    print('built', sum(r['ok'] for r in results), 'of', len(results))


if __name__ == '__main__':
    main()
