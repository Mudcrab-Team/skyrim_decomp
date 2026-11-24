#!/usr/bin/env python3
"""Compile toy translation units under the project recipe on the Windows runner and read their listings.

    lab_compile.py compile --src DIR --out DIR [--jobs 4] [--runners FILE]

Every `*.cpp` in --src is compiled with the recipe flags (plus `*.flags` beside it, one line, for a
per-variant flag) and its `/FA` listing comes back under --out. Only toy sources go over: nothing here reads
the game image. `parse_listing` / `normalize` turn a listing into one comparable instruction list per
function, so variants of one spelling can be compared exactly.
"""
import argparse
import json
import re
import subprocess
import sys
import tarfile
import time
from pathlib import Path

RECIPE_FLAGS = ['/nologo', '/c', '/O2', '/MD', '/GS-', '/EHsc', '/GR', '/fp:precise', '/Gy']
MAX_JOBS = 4

REMOTE_DRIVER = r'''
import json, os, subprocess, sys, tarfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
work, msvc, jobs = Path(sys.argv[1]), Path(sys.argv[2]), int(sys.argv[3])
base = msvc / 'VC' / 'Tools' / 'MSVC'
ver = sorted(p for p in base.iterdir() if p.is_dir())[0]
binx = ver / 'bin' / 'Hostx64' / 'x64'
sdk = sorted(p for p in (msvc / 'Windows Kits' / '10' / 'Include').iterdir())[0].name
inc = [ver / 'include'] + [msvc / 'Windows Kits' / '10' / 'Include' / sdk / n for n in ('ucrt', 'um', 'shared')]
env = dict(os.environ, INCLUDE=os.pathsep.join(str(p) for p in inc), PATH=str(binx) + os.pathsep + os.environ['PATH'])
flags = json.loads(os.environ['LAB_FLAGS'])
src = work / 'src'
out = work / 'out'
out.mkdir(exist_ok=True)

def one(cpp):
    extra = []
    fl = cpp.with_suffix('.flags')
    if fl.exists():
        extra = [x.replace('@TREE@', str(work / 'tree')) for x in fl.read_text().split()]
    stem = cpp.stem
    cmd = [str(binx / 'cl.exe')] + flags + extra + ['/FA', '/Fa' + str(out / (stem + '.asm')), '/Fo' + str(out / (stem + '.obj')), str(cpp)]
    p = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=str(src))
    (out / (stem + '.log')).write_text(p.stdout + p.stderr)
    return stem, p.returncode

with ThreadPoolExecutor(jobs) as ex:
    res = list(ex.map(one, sorted(src.glob('*.cpp'))))
(out / 'rc.json').write_text(json.dumps(dict(res)))
with tarfile.open(work / 'out.tar', 'w') as t:
    for f in out.iterdir():
        if f.suffix in ('.asm', '.log', '.json'):
            t.add(f, arcname=f.name)
'''


def load_host(runners_path):
    raw = json.loads(Path(runners_path).read_text())
    host = raw['hosts']['winpc']
    root = Path(runners_path).resolve().parents[2]
    ssh_config = Path(host['ssh_config'])
    if not ssh_config.is_absolute():
        ssh_config = root / ssh_config
    return {'ssh_config': str(ssh_config), 'ssh_host': host['ssh_host'], 'msvc': host['msvc'],
            'work': host['work'], 'python': host['python'][0]}


def compile_remote(src_dir, out_dir, jobs, runners, extra_flags=(), tree=None):
    jobs = max(1, min(int(jobs), MAX_JOBS))
    host = load_host(runners)
    src_dir, out_dir = Path(src_dir), Path(out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    run = f'cookbook-x64-lab-{int(time.time())}'
    remote = f"{host['work']}/{run}"
    stage = out_dir / '_stage'
    stage.mkdir(exist_ok=True)
    tar_path = stage / 'src.tar'
    with tarfile.open(tar_path, 'w') as t:
        for f in sorted(src_dir.iterdir()):
            if f.suffix in ('.cpp', '.h', '.flags'):
                t.add(f, arcname='src/' + f.name)
        if tree:
            # a private include/source tree that variants reach through `@TREE@` in their .flags file
            t.add(tree, arcname='tree')
    (stage / 'driver.py').write_text(REMOTE_DRIVER)
    ssh = ['ssh', '-F', host['ssh_config'], host['ssh_host']]
    scp = ['scp', '-q', '-F', host['ssh_config']]
    subprocess.run(ssh + [f"New-Item -ItemType Directory -Force '{remote}' | Out-Null"], check=True, timeout=120)
    subprocess.run(scp + [str(tar_path), str(stage / 'driver.py'), f"{host['ssh_host']}:{remote}/"], check=True, timeout=300)
    flags = json.dumps(RECIPE_FLAGS + list(extra_flags))
    script = (f"cd '{remote}'; tar -xf src.tar; $env:LAB_FLAGS='{flags}'; "
              f"& '{host['python']}' driver.py '{remote}' '{host['msvc']}' {jobs}; tar -tf out.tar | Out-Null")
    p = subprocess.run(ssh + [script], capture_output=True, text=True, timeout=1800)
    if p.returncode != 0:
        sys.stderr.write(p.stdout[-800:] + p.stderr[-800:])
        raise SystemExit('remote compile failed')
    subprocess.run(scp + [f"{host['ssh_host']}:{remote}/out.tar", str(stage / 'out.tar')], check=True, timeout=300)
    with tarfile.open(stage / 'out.tar') as t:
        t.extractall(out_dir, filter='data')
    subprocess.run(ssh + [f"Remove-Item -Recurse -Force '{remote}'"], timeout=120)
    return json.loads((out_dir / 'rc.json').read_text())


PROC = re.compile(r'^(\S+)\s+PROC\b')
LABEL = re.compile(r'\$(?:LN|LL|LC|T|L|EH)\w*@?\d*@?\w*|\$[A-Za-z]+\d+')
INSN = re.compile(r'^\t([a-z][a-z0-9_]*)(?:\t(.*?))?\s*(?:;.*)?$')
EQUATE = re.compile(r'^(\S+\$)\s*=\s*(-?\d+)')


def parse_listing(text):
    """symbol -> raw instruction strings, for every PROC in a /FA listing.

    The listing names stack slots (`key$[rsp]`) and defines them as equates before the PROC; they are
    replaced by their numeric offset so two variants compare by frame layout.
    """
    funcs, cur, equates = {}, None, {}
    for raw in text.splitlines():
        m = EQUATE.match(raw)
        if m and cur is None:
            equates[m.group(1)] = int(m.group(2))
            continue
        m = PROC.match(raw)
        if m:
            cur = funcs.setdefault(m.group(1), [])
            local = dict(equates)
            equates = {}
            continue
        if cur is None:
            continue
        if re.match(r'^\S+\s+ENDP', raw):
            cur = None
            continue
        if raw.startswith('$') and raw.rstrip().endswith(':'):
            cur.append(raw.strip())
            continue
        m = INSN.match(raw)
        if m and m.group(1) not in ('npad', 'align'):
            ins = f'{m.group(1)} {m.group(2) or ""}'.strip()
            cur.append(substitute(ins, local))
    return funcs


def substitute(ins, equates):
    """`PTR key$[rsp]` -> `PTR [rsp+N]` and `x$[rbp]` -> `[rbp+N]` for the equates of this function."""
    def repl(m):
        off = equates.get(m.group(1))
        return m.group(0) if off is None else f'[{m.group(2)}+{off}]'
    return re.sub(r'(\S+\$)\[(r[sb]p)\]', repl, ins)


def normalize(instrs):
    """Rename local labels in order of first appearance so equal code has equal text."""
    names = {}

    def rename(match):
        return names.setdefault(match.group(0), f'L{len(names)}')

    out = []
    for ins in instrs:
        if ins.startswith('$') and ins.endswith(':'):
            out.append(rename(re.match(LABEL, ins)) + ':' if re.match(LABEL, ins) else ins)
            continue
        out.append(LABEL.sub(rename, ins))
    return out


def load_results(out_dir):
    """stem -> {symbol: normalized instructions} for every listing in out_dir."""
    res = {}
    for asm in sorted(Path(out_dir).glob('*.asm')):
        res[asm.stem] = {s: normalize(i) for s, i in parse_listing(asm.read_text(errors='replace')).items()}
    return res


def default_runners():
    """The private runners file of the main checkout, found from a worktree inside its .local too."""
    import os
    if os.environ.get('SR_RUNNERS_CONFIG'):
        return os.environ['SR_RUNNERS_CONFIG']
    for parent in Path(__file__).resolve().parents:
        cand = parent / '.local' / 'verifier' / 'runners.json'
        if cand.exists():
            return str(cand)
    raise SystemExit('no .local/verifier/runners.json found')


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    c = sub.add_parser('compile')
    c.add_argument('--src', required=True)
    c.add_argument('--out', required=True)
    c.add_argument('--jobs', type=int, default=MAX_JOBS)
    c.add_argument('--runners', default=None)
    a = ap.parse_args()
    runners = a.runners or default_runners()
    print(json.dumps(compile_remote(a.src, a.out, a.jobs, runners)))


if __name__ == '__main__':
    sys.exit(main())
