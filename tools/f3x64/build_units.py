#!/usr/bin/env python3
"""Compile a sample of sibling translation units as x64 with the project's pinned recipe.

Private inputs only: the sibling clone and toolchain live under .local/, objects are written
there too. A thin force-included shim absorbs 32-bit assumptions so the bodies reach the
x64 code generator; failures are recorded with their first error lines so the causes can be counted.
"""
import argparse, hashlib, json, os, random, re, subprocess, sys, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

INC = None
LISTINGS = False
FLAGS = ['/nologo', '/c', '/O2', '/MD', '/GS-', '/EHsc', '/GR', '/fp:precise', '/Gy', '/w']


def compile_unit(env, root, shim, cl, unit, out, timeout):
    src = Path(unit['source'])
    # a digest suffix keeps stems distinct on case-insensitive disks and when separators collapse to the same name
    stem = re.sub(r'[^A-Za-z0-9_]', '_', str(src.with_suffix(''))) + '_' + hashlib.sha1(str(src).encode()).hexdigest()[:6]
    obj = out / 'obj' / (stem + '.obj')
    log = out / 'logs' / (stem + '.log')
    cmd = [str(cl)] + FLAGS + ['/FI', str(shim), '/I', str(INC or root / 'include'), '/I', str(root / src.parent),
                               '/I', str(root / 'src'), '/Fo' + str(obj), str(root / src)]
    if LISTINGS:
        cmd[1:1] = ['/FAs', '/Fa' + str(out / 'asm' / (stem + '.asm'))]
    t = time.time()
    try:
        p = subprocess.run(cmd, env=env, capture_output=True, text=True, timeout=timeout)
        text, rc = p.stdout + p.stderr, p.returncode
    except subprocess.TimeoutExpired:
        text, rc = 'TIMEOUT', 99
    log.write_text(text)
    errs = [l for l in text.splitlines() if re.search(r'error C\d+|fatal error', l)]
    return {'source': unit['source'], 'obj': str(obj), 'ok': rc == 0 and obj.exists(), 'rc': rc,
            'seconds': round(time.time() - t, 1), 'errors': errs[:5], 'nerrors': len(errs),
            'nfunctions': len(unit['functions'])}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', required=True)
    ap.add_argument('--msvc', required=True)
    ap.add_argument('--wine-bin', required=True)
    ap.add_argument('--wineprefix', required=True)
    ap.add_argument('--shim', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--inc', help='shadow include dir that replaces the sibling include dir')
    ap.add_argument('--listings', action='store_true', help='also write source-annotated listings (/FAs)')
    ap.add_argument('--retry', help='build_results.json whose failed units are rebuilt')
    ap.add_argument('--n', type=int, default=200)
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('--jobs', type=int, default=6)
    ap.add_argument('--timeout', type=int, default=400)
    ap.add_argument('--skip', type=int, default=0, help='skip this many of the shuffled units (second sample)')
    ap.add_argument('--max-lines', type=int, default=0)
    a = ap.parse_args()
    global INC, LISTINGS
    LISTINGS = a.listings
    INC = Path(a.inc).resolve() if a.inc else None
    root, out = Path(a.root).resolve(), Path(a.out).resolve()
    (out / 'obj').mkdir(parents=True, exist_ok=True); (out / 'logs').mkdir(exist_ok=True); (out / 'asm').mkdir(exist_ok=True)
    units = json.load(open(root / 'build' / 'units.json'))['units']
    units = [u for u in units if (root / u['source']).exists()]
    if a.max_lines:
        units = [u for u in units if sum(1 for _ in open(root / u['source'], errors='replace')) <= a.max_lines]
    random.Random(a.seed).shuffle(units)
    if a.retry:
        again = {r['source'] for r in json.load(open(a.retry)) if not r['ok']}
        units = [u for u in units if u['source'] in again]
    else:
        units = units[a.skip:a.skip + a.n]
    env = dict(os.environ, WINEPREFIX=a.wineprefix, WINEDEBUG='-all',
               PATH=a.wine_bin + os.pathsep + os.environ['PATH'])
    cl = Path(a.msvc).resolve() / 'bin' / 'x64' / 'cl'
    res = []
    with ThreadPoolExecutor(a.jobs) as ex:
        for r in ex.map(lambda u: compile_unit(env, root, Path(a.shim).resolve(), cl, u, out, a.timeout), units):
            res.append(r)
            print('OK ' if r['ok'] else 'ERR', r['source'], r['seconds'], (r['errors'] or [''])[0][:150], flush=True)
    (out / 'build_results.json').write_text(json.dumps(res, indent=1))
    print('built', sum(r['ok'] for r in res), 'of', len(res))


if __name__ == '__main__':
    main()
