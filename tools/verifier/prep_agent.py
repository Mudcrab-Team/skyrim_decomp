"""Host side of tools/verifier/remote_prep.py. Standard library only; uploaded with every command.

    python prep_agent.py status  --root R [--digest]
    python prep_agent.py apply   --root R --bundle B.tar.xz        # tracked files and private inputs
    python prep_agent.py run     --root R --job job.json --image EXE

`status` prints the JSON manifest of what R/repo holds (tracked path -> content id, private path ->
size and mtime). `apply` unpacks a bundle into R/repo and deletes the paths its `.prep-delete`
member lists. `run` executes the job's script inside R/repo with the host's python, then packs
every file the run created or changed under the job's `collect` directories into R/out.tar.xz and
removes them, so the next run starts from the same tree. Nothing is read from outside R except
the image and the python that runs this file.
"""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import time

MANIFEST = '.prep-manifest.json'
DELETE_LIST = '.prep-delete'


def repo_of(root):
    return Path(root) / 'repo'


def safe_member(name):
    p = Path(name)
    return not p.is_absolute() and '..' not in p.parts


def digest_of(manifest):
    """Digest of a manifest, the same function remote_prep.py applies to what it wants the host to hold."""
    import hashlib
    return hashlib.sha256(json.dumps(sorted(manifest.items())).encode()).hexdigest()


def cmd_status(a):
    path = repo_of(a.root) / MANIFEST
    text = path.read_text() if path.is_file() else '{}'
    print(json.dumps({'digest': digest_of(json.loads(text))}) if a.digest else text)
    return 0


def cmd_apply(a):
    repo = repo_of(a.root)
    repo.mkdir(parents=True, exist_ok=True)
    with tarfile.open(a.bundle) as tar:
        members = [m for m in tar.getmembers() if safe_member(m.name) and (m.isfile() or m.isdir())]
        deleted = []
        for m in members:
            if m.name == DELETE_LIST:
                deleted = tar.extractfile(m).read().decode().splitlines()
        for m in members:
            if m.name == DELETE_LIST:
                continue
            tar.extract(m, repo)
    for rel in deleted:
        if safe_member(rel):
            (repo / rel).unlink(missing_ok=True)
    manifest = {}
    try:
        manifest = json.loads((repo / MANIFEST).read_text())
    except (OSError, ValueError):
        pass
    with tarfile.open(a.bundle) as tar:
        for m in tar.getmembers():
            if m.name == '.prep-ids':
                manifest.update(json.loads(tar.extractfile(m).read().decode()))
    for rel in deleted:
        manifest.pop(rel, None)
    (repo / MANIFEST).write_text(json.dumps(manifest))
    Path(a.bundle).unlink(missing_ok=True)
    return 0


def snapshot(repo, roots):
    out = {}
    for root in roots:
        base = repo / root
        if base.is_file():
            files = [base]
        else:
            files = [p for p in base.rglob('*') if p.is_file()] if base.is_dir() else []
        for p in files:
            st = p.stat()
            out[p.relative_to(repo).as_posix()] = (st.st_size, st.st_mtime_ns)
    return out


def cmd_run(a):
    repo = repo_of(a.root)
    job = json.loads(Path(a.job).read_text())
    script = repo / job['script']
    if not safe_member(job['script']) or not script.is_file():
        print('prep-agent: the job names no script in the repository copy')
        return 45
    roots = [r for r in job.get('collect', []) if safe_member(r)]
    before = snapshot(repo, roots)
    env = dict(os.environ, SR_SKYRIM_EXE=a.image, PYTHONUTF8='1', **{k: str(v) for k, v in job.get('env', {}).items()})
    started = time.monotonic()
    # `runs` lists the argument lists to run (up to `jobs` at once); without it the job is one run of `args`.
    runs = job.get('runs') or [job.get('args', [])]
    from concurrent.futures import ThreadPoolExecutor

    def one(args):
        return subprocess.run([sys.executable, str(script), *args], cwd=repo, env=env,
                              capture_output=True, text=True, errors='replace')

    with ThreadPoolExecutor(max(1, min(int(job.get('jobs', 1)), len(runs)))) as pool:
        procs = list(pool.map(one, runs))
    proc = procs[0] if len(procs) == 1 else None
    code = max(p.returncode for p in procs)
    after = snapshot(repo, roots)
    changed = sorted(p for p, v in after.items() if before.get(p) != v)
    out = Path(a.root) / 'out.tar.xz'
    with tarfile.open(out, 'w:xz') as tar:
        for rel in changed:
            tar.add(str(repo / rel), arcname=rel, recursive=False)
        info = tarfile.TarInfo('.prep-run.json')
        data = json.dumps({'exit': code, 'seconds': round(time.monotonic() - started, 1),
                           'stdout': (proc.stdout if proc else '')[-6000:], 'stderr': (proc.stderr if proc else '')[-3000:],
                           'runs': [{'args': r, 'exit': p.returncode, 'tail': (p.stdout + p.stderr)[-300:]}
                                    for r, p in zip(runs, procs)]}).encode()
        info.size = len(data)
        import io
        tar.addfile(info, io.BytesIO(data))
    if not job.get('keep'):
        stale = []
        for rel in changed:
            if rel not in before:
                (repo / rel).unlink(missing_ok=True)
            else:
                stale.append(rel)
        if stale:
            # A file the run rewrote no longer matches what the last sync recorded: forget it, so the next sync sends it again.
            try:
                manifest = json.loads((repo / MANIFEST).read_text())
                for rel in stale:
                    manifest.pop(rel, None)
                (repo / MANIFEST).write_text(json.dumps(manifest))
            except (OSError, ValueError):
                pass
        for root in roots:
            for d in sorted((p for p in (repo / root).rglob('*') if p.is_dir()), reverse=True):
                try:
                    d.rmdir()
                except OSError:
                    pass
    print(f'prep-agent: exit {code}, {len(runs)} run(s), {len(changed)} file(s) collected')
    return 0


def main():
    p = argparse.ArgumentParser(description=__doc__)
    sub = p.add_subparsers(dest='command', required=True)
    for name in ('status', 'apply', 'run'):
        s = sub.add_parser(name)
        s.add_argument('--root', required=True)
        if name == 'status':
            s.add_argument('--digest', action='store_true', help='print only the digest of the manifest')
        if name == 'apply':
            s.add_argument('--bundle', required=True)
        if name == 'run':
            s.add_argument('--job', required=True)
            s.add_argument('--image', required=True)
    a = p.parse_args()
    return {'status': cmd_status, 'apply': cmd_apply, 'run': cmd_run}[a.command](a)


if __name__ == '__main__':
    raise SystemExit(main())
