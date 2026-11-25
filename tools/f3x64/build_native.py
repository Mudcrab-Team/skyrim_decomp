#!/usr/bin/env python3
"""Compile listed translation units as x64 with the pinned recipe, natively on Windows.

Private inputs only: the source tree (a shadow copy under .local or a scratch directory) and the
toolchain are named on the command line; objects and listings go to --out. Failures keep their
first error lines so causes can be counted. No source text leaves the machine.

    build_native.py --root TREE --msvc TOOLCHAIN --units LIST --out DIR [--shim H] [--inc DIR ...]
"""
import argparse, hashlib, json, os, re, subprocess, sys, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

FLAGS = ['/nologo', '/c', '/O2', '/MD', '/GS-', '/EHsc', '/GR', '/fp:precise', '/Gy', '/w']
# a global operator new/delete pair that the sized-deallocation rule refuses is compiled again without it
RETRY = {'C2956': ['/Zc:sizedDealloc-']}


def find_toolchain(root):
    msvc = sorted((root / 'VC' / 'Tools' / 'MSVC').iterdir())[-1]
    kits = root / 'Windows Kits' / '10'
    sdk = sorted((kits / 'Include').iterdir())[-1].name
    inc = [msvc / 'include'] + [kits / 'Include' / sdk / d for d in ('ucrt', 'um', 'shared')]
    return msvc / 'bin' / 'Hostx64' / 'x64' / 'cl.exe', inc


def stem_of(src):
    stem = re.sub(r'[^A-Za-z0-9_]', '_', str(src.with_suffix('')))
    if len(stem) > 90:
        stem = stem[:60] + '_' + hashlib.sha1(stem.encode()).hexdigest()[:10]
    return stem + '_' + hashlib.sha1(str(src).encode()).hexdigest()[:6]


def compile_unit(cl, inc, env, root, out, rel, shim, extra_inc, listings, timeout, defines):
    src = Path(rel)
    stem = stem_of(src)
    obj = out / 'obj' / (stem + '.obj')
    start = time.time()
    extra, retried = [], []
    while True:
        cmd = [str(cl)] + FLAGS + extra + defines
        if listings:
            cmd += ['/FAs', '/Fa' + str(out / 'asm' / (stem + '.asm'))]
        if shim:
            cmd += ['/FI', str(shim)]
        for d in [*extra_inc, root / src.parent, root / 'src']:
            cmd += ['/I', str(d)]
        for d in inc:
            cmd += ['/I', str(d)]
        cmd += ['/Fo' + str(obj), str(root / src)]
        try:
            p = subprocess.run(cmd, env=env, capture_output=True, text=True, timeout=timeout, stdin=subprocess.DEVNULL,
                               errors='replace')
            text, rc = p.stdout + p.stderr, p.returncode
        except subprocess.TimeoutExpired:
            text, rc = 'TIMEOUT', 99
        more = [f for code, flags in RETRY.items() if re.search(r'error ' + code, text) for f in flags if f not in extra]
        if rc == 0 or not more:
            break
        extra += more
        retried += more
    (out / 'logs' / (stem + '.log')).write_text(text)
    errors = [l.strip() for l in text.splitlines() if re.search(r'error C\d+|fatal error', l)]
    return {'source': rel, 'stem': stem, 'ok': rc == 0 and obj.exists(), 'seconds': round(time.time() - start, 1),
            'errors': errors[:5], 'nerrors': len(errors), 'extra_flags': retried}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', required=True, type=Path)
    ap.add_argument('--msvc', required=True, type=Path)
    ap.add_argument('--units', required=True, type=Path, help='file with one source path (relative to --root) per line')
    ap.add_argument('--out', required=True, type=Path)
    ap.add_argument('--shim', type=Path, help='header force-included in every unit')
    ap.add_argument('--inc', type=Path, action='append', default=[])
    ap.add_argument('--define', action='append', default=[])
    ap.add_argument('--listings', action='store_true')
    ap.add_argument('--jobs', type=int, default=6)
    ap.add_argument('--timeout', type=int, default=600)
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--retry', type=Path, help='build_results.json whose failed units are rebuilt')
    a = ap.parse_args()
    root, out = a.root.resolve(), a.out.resolve()
    for d in ('obj', 'logs', 'asm'):
        (out / d).mkdir(parents=True, exist_ok=True)
    units = [l.strip() for l in a.units.read_text().splitlines() if l.strip()]
    if a.retry:
        again = {r['source'] for r in json.loads(a.retry.read_text()) if not r['ok']}
        units = [u for u in units if u in again]
    if a.limit:
        units = units[:a.limit]
    cl, inc = find_toolchain(a.msvc.resolve())
    env = dict(os.environ)
    res = []
    defines = ['/D' + d for d in a.define]
    with ThreadPoolExecutor(a.jobs) as ex:
        for r in ex.map(lambda u: compile_unit(cl, inc, env, root, out, u, a.shim, a.inc, a.listings, a.timeout, defines), units):
            res.append(r)
            print('OK ' if r['ok'] else 'ERR', r['source'], r['seconds'], (r['errors'] or [''])[0][:150], flush=True)
    (out / 'build_results.json').write_text(json.dumps(res, indent=1))
    print('built', sum(r['ok'] for r in res), 'of', len(res))


if __name__ == '__main__':
    main()
