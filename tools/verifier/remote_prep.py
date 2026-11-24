#!/usr/bin/env python3
"""Prepare tasks and packs on a runner host instead of this machine (local study tool, nothing published).

    tools/verifier/remote_prep.py sync                      # tracked files and the private inputs it needs, once
    tools/verifier/remote_prep.py start 0x<rva>... [--script PATH] [--into DIR] [-- <start arguments>]
    tools/verifier/remote_prep.py status

`tools/contrib.py start` (a task, the function's pack from the image, a unit skeleton) costs about
10 s of CPU per function; a few dozen at once overloads a laptop. With `"prep": "<host>"` in
.local/verifier/runners.json the same command runs on that host, which holds a copy of this
checkout's tracked files and the private inputs the start reads, uploaded once and refreshed by
content:

- tracked files: every file `git ls-files` lists (working-tree content, so uncommitted tool edits
  count) except site/, tests/, findings/ and docs/; only the ones whose content differs from the
  host's manifest are sent, and files git no longer lists are deleted there;
- private inputs (never committed): the function table, the FNV lookup index and the x64 shape
  indexes from this checkout's .local (a subset of .local/analysis; the Ghidra project and the
  symbol files stay here), sent when their size or mtime differs.

`start` runs `tools/contrib.py start <rvas> --no-branch ...` on the host, or `--script PATH`, a local
file uploaded with the job (a local wrapper around the start, say). What the run created under
.local/contrib/tasks, .local/contrib/packs and reconstruction/ comes back under --into (default:
.local/prep/<host>/) with the same relative paths; the host's copy is left as it was. Each returned
task.json has its `pack` path rewritten to the returned pack, so the task works from --into.
Without a prep host, or when it cannot be reached, `start` says so and exits 3: the caller decides
whether to run the start here.
"""
import argparse
import hashlib
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile
import time
import uuid

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
sys.path.insert(0, str(HERE))
import runners  # noqa: E402

AGENT = HERE / 'prep_agent.py'
SKIP_TOP = ('site/', 'tests/', 'findings/', 'docs/')
# Private inputs the start reads, relative to a checkout's .local: copied to the same place on the host.
PRIVATE_INPUTS = ('analysis/functions.jsonl', 'analysis/fnv_index.jsonl', 'analysis/fnv_index.meta.json',
                  'contrib/x64-index/x64-index-v1-f3.json.gz', 'contrib/x64-index/x64-index-v1-fnv.json.gz',
                  'contrib/config.json')
COLLECT = ('.local/contrib/tasks', '.local/contrib/packs', 'reconstruction')
EXIT_NO_HOST = 3


class PrepError(Exception):
    pass


def git(repo, *args):
    proc = subprocess.run(['git', '-C', str(repo), *args], capture_output=True, text=True, check=True)
    return proc.stdout


def tracked_ids(repo):
    """{path: content id} of the tracked files that exist in the working tree, minus the skipped trees.

    The id is git's blob hash for a file that matches the index and a sha1 of the bytes for one that
    does not, so an uncommitted edit changes it.
    """
    repo = Path(repo)
    staged = {}
    for line in git(repo, 'ls-files', '-s', '-z').split('\0'):
        if not line:
            continue
        meta, path = line.split('\t', 1)
        staged[path] = meta.split()[1]
    dirty = {p for p in git(repo, 'diff', '--name-only', '-z', 'HEAD').split('\0') if p}
    dirty |= {p for p in git(repo, 'diff', '--name-only', '-z').split('\0') if p}
    out = {}
    for path, blob in staged.items():
        if path.startswith(SKIP_TOP) or not (repo / path).is_file():
            continue
        out[path] = hashlib.sha1((repo / path).read_bytes()).hexdigest() if path in dirty else blob
    return out


def private_sources(*locals_):
    """{'.local/<rel>': local file}: the first of `locals_` (this checkout's .local, then the main one) that has it."""
    out = {}
    for rel in PRIVATE_INPUTS:
        for base in locals_:
            p = Path(base) / rel
            if p.is_file():
                out[f'.local/{rel}'] = p
                break
    return out


def private_ids(sources):
    out = {}
    for rel, p in sources.items():
        st = Path(p).stat()
        out[rel] = f'{st.st_size}:{st.st_mtime_ns // 1_000_000_000}'
    return out


def agent_digest(manifest):
    """The digest prep_agent.py computes of a manifest."""
    return hashlib.sha256(json.dumps(sorted(manifest.items())).encode()).hexdigest()


def prep_host(config=None, name=None):
    """The configured prep host dict, or raises PrepError when there is none."""
    config = config if config is not None else runners.load()
    chosen = name or (config or {}).get('prep')
    if not config or not chosen or chosen not in config['hosts']:
        raise PrepError('no prep host: set "prep": "<host>" in .local/verifier/runners.json')
    return runners.with_image(config['hosts'][chosen])


class Prep:
    """One prep host: files in <work>/prep/repo, the agent next to them."""

    def __init__(self, host, local=None, repo=REPO, log=None):
        self.host, self.repo = host, Path(repo)
        self.local = Path(local) if local else self.find_local()
        # This checkout's own private files win over the main checkout's (its contrib config, say).
        self.locals = [self.local] if local else [self.repo / '.local', runners.main_root() / '.local']
        self.log = log or (lambda m: None)
        self.transport = runners.transport_for(host, log=self.log)
        self.root = self.transport.join(host['work'], 'prep')
        self.python = list(host['python']) if host['backend'] == 'ssh' else [sys.executable]

    def find_local(self):
        mine = self.repo / '.local'
        if (mine / 'analysis' / 'functions.jsonl').exists():
            return mine
        return runners.main_root() / '.local'

    def private_sources(self):
        return private_sources(*self.locals)

    def agent(self, *args, timeout=900):
        return self.transport.run(self.python + ['-I', self.transport.join(self.root, 'prep_agent.py'), *args], timeout)

    def put(self, files):
        self.transport.prepare()
        self.transport.mkdir(self.root)
        self.transport.put(files, self.root)

    def upload_agent(self):
        with tempfile.TemporaryDirectory() as tmp:
            agent = Path(tmp) / 'prep_agent.py'
            agent.write_bytes(AGENT.read_bytes())
            self.put([agent])

    def digest(self):
        """The digest of the host's manifest, a few bytes instead of the whole listing."""
        self.upload_agent()
        code, out, err = self.agent('status', '--root', self.root, '--digest')
        if code != 0:
            raise PrepError(f'{self.host["host_id"]}: status failed (exit {code}) {(err or out).strip()[-200:]}')
        try:
            return json.loads(out)['digest']
        except (ValueError, KeyError):
            raise PrepError(f'{self.host["host_id"]}: status gave no digest') from None

    def manifest(self):
        code, out, err = self.agent('status', '--root', self.root)
        if code != 0:
            raise PrepError(f'{self.host["host_id"]}: status failed (exit {code}) {(err or out).strip()[-200:]}')
        try:
            return json.loads(out)
        except ValueError:
            raise PrepError(f'{self.host["host_id"]}: status gave no manifest') from None

    def sync(self):
        """Send what differs; returns (files sent, files deleted, bytes uploaded)."""
        want = tracked_ids(self.repo)
        sources = private_sources(*self.locals)
        private = private_ids(sources)
        want.update(private)
        if self.digest() == agent_digest(want):
            return 0, 0, 0
        have = self.manifest()
        send = sorted(p for p, i in want.items() if have.get(p) != i)
        gone = sorted(p for p in have if p not in want)
        if not send and not gone:
            return 0, 0, 0
        with tempfile.TemporaryDirectory() as tmp:
            bundle = Path(tmp) / f'sync-{uuid.uuid4().hex[:8]}.tar.xz'
            with tarfile.open(bundle, 'w:xz') as tar:
                for rel in send:
                    src = sources[rel] if rel in private else self.repo / rel
                    tar.add(str(src), arcname=rel, recursive=False)
                for name, data in (('.prep-delete', '\n'.join(gone).encode()),
                                   ('.prep-ids', json.dumps({p: want[p] for p in send}).encode())):
                    info = tarfile.TarInfo(name)
                    info.size = len(data)
                    tar.addfile(info, io.BytesIO(data))
            size = bundle.stat().st_size
            self.put([bundle])
            code, out, err = self.agent('apply', '--root', self.root, '--bundle', self.transport.join(self.root, bundle.name))
        if code != 0:
            raise PrepError(f'{self.host["host_id"]}: apply failed (exit {code}) {(err or out).strip()[-200:]}')
        return len(send), len(gone), size

    def start(self, rvas, extra=(), script=None, into=None, timeout=1800, jobs=1):
        """Run the start on the host; returns (exit code of the start, files collected, stdout tail).

        With a script, each RVA is its own run of it (up to `jobs` at once on the host, whose CPUs these are);
        without one, `tools/contrib.py start` gets all the RVAs in one run, as it requires one class.
        """
        into = Path(into) if into else self.local / 'prep' / self.host['host_id']
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            job = {'script': 'tools/contrib.py', 'args': ['start', *rvas, '--no-branch', *extra], 'collect': list(COLLECT)}
            files = [AGENT]
            if script:
                job['script'] = f'.prep-scripts/{Path(script).name}'
                job['runs'] = [[rva, *extra] for rva in rvas]
                job['jobs'] = jobs
                bundle = tmp / f'script-{uuid.uuid4().hex[:8]}.tar.xz'
                with tarfile.open(bundle, 'w:xz') as tar:
                    tar.add(str(script), arcname=job['script'], recursive=False)
                self.put([bundle])
                code, out, err = self.agent('apply', '--root', self.root, '--bundle', self.transport.join(self.root, bundle.name))
                if code != 0:
                    raise PrepError(f'{self.host["host_id"]}: could not upload {script} (exit {code})')
            (tmp / 'job.json').write_text(json.dumps(job))
            self.put([tmp / 'job.json'])
            code, out, err = self.agent('run', '--root', self.root, '--job', self.transport.join(self.root, 'job.json'),
                                        '--image', self.host['image'], timeout=timeout)
            if code != 0:
                raise PrepError(f'{self.host["host_id"]}: run failed (exit {code}) {(err or out).strip()[-300:]}')
            result = tmp / 'out.tar.xz'
            self.transport.get(self.transport.join(self.root, 'out.tar.xz'), result)
            return collect(result, into, rvas)


def collect(archive, into, rvas):
    """Unpack the run's files under `into`; (start exit code, number of files, stdout tail)."""
    into = Path(into)
    into.mkdir(parents=True, exist_ok=True)
    meta, count = {}, 0
    with tarfile.open(archive) as tar:
        for m in tar.getmembers():
            if m.name == '.prep-run.json':
                meta = json.loads(tar.extractfile(m).read().decode())
            elif m.isfile() and not Path(m.name).is_absolute() and '..' not in Path(m.name).parts:
                tar.extract(m, into, filter='data')
                count += 1
    for task in (into / '.local/contrib/tasks').glob('*/task.json'):
        data = json.loads(task.read_text())
        changed = False
        for fn in data.get('functions', []):
            pack = fn.get('pack')
            if pack:
                tail = Path(str(pack).replace('\\', '/')).parts[-3:]
                local = into / '.local/contrib/packs' / Path(*tail[-2:])
                if local.is_dir():
                    fn['pack'] = str(local)
                    changed = True
        if changed:
            task.write_text(json.dumps(data, indent=2) + '\n')
    tail = (meta.get('stdout') or '') + (meta.get('stderr') or '')
    if meta.get('runs') and len(meta['runs']) > 1:
        tail = '\n'.join(f'{" ".join(r["args"])}: exit {r["exit"]}' for r in meta['runs'])
    return meta.get('exit', 2), count, tail


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)
    sub.add_parser('sync', help='send tracked files and private inputs that differ')
    sub.add_parser('status', help='what the host holds, by count')
    s = sub.add_parser('start', help='run tools/contrib.py start (or --script) on the host')
    s.add_argument('rva', nargs='+')
    s.add_argument('--script', help='local script run instead of tools/contrib.py start; it gets the RVAs and the extra arguments')
    s.add_argument('--into', help='where the returned files go (default .local/prep/<host>/)')
    s.add_argument('--host', help='prep host name (default: "prep" of runners.json)')
    s.add_argument('--timeout', type=int, default=1800)
    s.add_argument('--jobs', type=int, default=1, help='with --script: runs at once on the host')
    s.epilog = 'arguments after a bare -- are passed to the start command'
    argv = list(sys.argv[1:] if argv is None else argv)
    # Everything after a bare -- goes to the start command untouched.
    extra = []
    if '--' in argv:
        cut = argv.index('--')
        argv, extra = argv[:cut], argv[cut + 1:]
    a = p.parse_args(argv)
    a.extra = extra
    try:
        prep = Prep(prep_host(name=getattr(a, 'host', None)), log=lambda m: print(m, file=sys.stderr))
    except (PrepError, runners.RunnerError) as exc:
        print(f'remote_prep: {exc}', file=sys.stderr)
        return EXIT_NO_HOST
    started = time.monotonic()
    try:
        if a.cmd == 'status':
            prep.upload_agent()
            have = prep.manifest()
            print(f'{prep.host["host_id"]}: {len(have)} files in the copy')
            return 0
        sent, gone, size = prep.sync()
        print(f'remote_prep: {prep.host["host_id"]} synced ({sent} sent, {gone} deleted, {size / 1e6:.1f} MB, '
              f'{time.monotonic() - started:.0f} s)', file=sys.stderr)
        if a.cmd == 'sync':
            return 0
        code, count, tail = prep.start(a.rva, a.extra, a.script, a.into, a.timeout, a.jobs)
    except (PrepError, runners.RunnerError, OSError, subprocess.CalledProcessError) as exc:
        print(f'remote_prep: {exc}', file=sys.stderr)
        return EXIT_NO_HOST
    print(tail.strip()[-1500:])
    print(f'remote_prep: start exit {code}, {count} file(s) returned, {time.monotonic() - started:.0f} s',
          file=sys.stderr)
    return code


if __name__ == '__main__':
    raise SystemExit(main())
