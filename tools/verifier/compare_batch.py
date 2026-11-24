#!/usr/bin/env python3
"""Compile and compare many task directories on one ssh runner in a few round trips.

    python3 tools/verifier/compare_batch.py <task-dir>...   # prefetch; `attempt` on each task then reads the result

`attempt` costs four ssh sessions per unit, which dominates a PR with hundreds of units. This tool
uploads the units in batches (runners.BatchHost: one upload, one agent command and one fetch per
batch), leaves each unit's private result beside its task, and `attempt` then runs unchanged: it
finds the result, checks that it was made from exactly the sources and spec it would upload now, and
goes on to binding and reporting as usual. A result that does not match is ignored and the unit is
compiled the ordinary way, so nothing here can change a verdict, only where it is computed.

The host is the first reachable `compare_prefer` entry of the runners config (SR_COMPARE_HOST
overrides; `attempt` there means no prefetch). When none answers a wake-up packet is sent, if the
host configures one, and the tool exits at once without waiting: callers carry on with their own
host. A batch that fails stops the remaining batches, and those units take the ordinary path.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys
import threading
import time
import uuid

sys.path.insert(0, str(Path(__file__).resolve().parent))
import pipeline  # noqa: E402
import runners  # noqa: E402

PREFETCH = 'prefetch.json'
CONFIRM_MARK = '.confirm-done.json'
UNIT_DIR = 'prefetch-unit'
# Batches in flight on the host: one transfers while another compiles (BatchHost holds slots only then).
IN_FLIGHT = 2


def spec_key(task, files, host_id):
    """Digest of everything the host would be given for this unit, including the sources' hashes."""
    spec = pipeline.unit_spec(task, files, host_id)
    return hashlib.sha256(json.dumps(spec, sort_keys=True).encode()).hexdigest()


def entry_path(task_dir):
    return Path(task_dir) / '.attempt' / PREFETCH


def read_entry(task_dir, task, files, config):
    """(host dict, unit directory, exit code) of a prefetched result that matches the sources now, else None."""
    path = entry_path(task_dir)
    try:
        entry = json.loads(path.read_text())
        host = runners.with_image(config['hosts'][entry['host']])
        unit = path.parent / UNIT_DIR
        if (entry['key'] == spec_key(task, files, host['host_id']) and unit.is_dir()
                and isinstance(entry['exit'], int)):
            return host, unit, entry['exit']
    except (OSError, ValueError, KeyError, TypeError, runners.RunnerError):
        pass
    return None


def discard(task_dir):
    """Drop a prefetched result once it has been used or found stale."""
    entry_path(task_dir).unlink(missing_ok=True)
    shutil.rmtree(Path(task_dir) / '.attempt' / UNIT_DIR, ignore_errors=True)


class PrefetchedHost(runners.AgentHost):
    """AgentHost whose first run is the prefetched result; a later run (after binding) uses the host itself."""

    def __init__(self, host, task, found, **kw):
        super().__init__(host, task, **kw)
        self.found = found
        self.used = False

    def run(self, files, stage_root, fresh=True, timeout=None):
        if self.found is not None:
            host, unit, code = self.found
            if spec_key(self.task, files, host['host_id']) == read_key(unit.parent):
                self.used = True
                return code, ''
            self.found = None
        return super().run(files, stage_root, fresh, timeout)

    def fetch(self, dest):
        if not self.used:
            return super().fetch(dest)
        host, unit, _ = self.found
        self.found, self.used = None, False
        dest = Path(dest)
        shutil.rmtree(dest, ignore_errors=True)
        dest.parent.mkdir(parents=True, exist_ok=True)
        unit.rename(dest)
        try:
            self.facts = json.loads((dest / 'result.json').read_text()).get('host_facts')
        except (OSError, ValueError):
            self.facts = None
        discard(dest.parents[1])
        return dest


def read_key(attempt_dir):
    try:
        return json.loads((Path(attempt_dir) / PREFETCH).read_text())['key']
    except (OSError, ValueError, KeyError):
        return None


def host_for(task, files, runner, config):
    """The host `attempt` runs this unit on: the prefetched result's host when one is current, else `runner`."""
    found = read_entry(task['dir'], task, files, config) if config else None
    if found is None:
        discard(task['dir'])
        return runners.AgentHost(runner, task, log=lambda m: print(m, file=sys.stderr)), runner
    return PrefetchedHost(found[0], task, found, log=lambda m: print(m, file=sys.stderr)), found[0]


def confirm_done(task_dir, task, files):
    """The exit code of a finished confirm run in `task_dir` made from exactly these sources, else None.

    Lets a record build that restarted skip the functions it already confirmed; the run's own facts
    (fresh toolchain check included) are in the kept result, which is still there to be read.
    """
    try:
        mark = json.loads((Path(task_dir) / CONFIRM_MARK).read_text())
        done = Path(task_dir) / 'confirm' / mark['host']
        if (mark['key'] == spec_key(task, files, mark['host']) and mark['exit'] in (0, 1)
                and (done / 'result.json').is_file()):
            return mark['exit']
    except (OSError, ValueError, KeyError, TypeError):
        pass
    return None


def mark_confirm(task_dir, task, files, host_id, code):
    """Record that the confirm run of `task_dir` finished with `code` on `host_id`; only a verdict counts."""
    mark = Path(task_dir) / CONFIRM_MARK
    if code not in (0, 1):
        mark.unlink(missing_ok=True)
        return
    tmp = mark.with_name(f'{CONFIRM_MARK}.{uuid.uuid4().hex[:6]}.tmp')
    tmp.write_text(json.dumps({'key': spec_key(task, files, host_id), 'host': host_id, 'exit': code}))
    tmp.replace(mark)


def write_entry(task_dir, key, host_id, code):
    path = entry_path(task_dir)
    tmp = path.with_name(f'{PREFETCH}.{uuid.uuid4().hex[:6]}.tmp')
    tmp.write_text(json.dumps({'key': key, 'host': host_id, 'exit': code}))
    tmp.replace(path)


def prepare(task_dirs, log, confirm=False):
    """[(task, files)] for the units the host can take; a unit `attempt` would refuse locally is left to it.

    For a confirm run, units whose kept result is current are left out as well."""
    out = []
    for d in task_dirs:
        try:
            task = pipeline.load_task(d)
            if not (pipeline.REPO / task['compiled']).exists() or pipeline.compiler_include_problem(task):
                continue
            files, _ = pipeline.unit_manifest(task)
        except (pipeline.PipelineError, OSError, ValueError, KeyError) as exc:
            log(f'compare_batch: {d}: left to attempt ({type(exc).__name__})')
            continue
        if confirm:
            if confirm_done(task['dir'], task, files) is None:
                out.append((task, files))
            continue
        discard(task['dir'])
        out.append((task, files))
    return out


def run(task_dirs, config, name, deadline, batch=None, stage_root=None, log=print, confirm=False):
    """Prefetch `task_dirs` on host `name`; returns the number of units whose result was kept.

    With `confirm` each unit is a one-function confirm directory: the toolchain is hashed afresh for every
    unit (as wine_confirm.py does) and the result is kept where wine_confirm.py would have put it."""
    host = runners.with_image(config['hosts'][name])
    units = prepare(task_dirs, log, confirm)
    if not units:
        return 0
    size = batch or host['batch']
    stage_root = Path(stage_root or runners.starts.state_dir() / 'compare-stage' / uuid.uuid4().hex[:12])
    worker = runners.BatchHost(host, log=log, fresh_prep=confirm)
    down, lock, kept = threading.Event(), threading.Lock(), [0]
    chunks = [units[i:i + size] for i in range(0, len(units), size)]
    log(f'compare_batch: {len(units)} unit(s) in {len(chunks)} batch(es) of up to {size} on '
        f'{runners.describe(host)} [{host["max_parallel"]} slots]')

    def one(chunk):
        if down.is_set() or time.monotonic() > deadline:
            return
        started = time.monotonic()
        dests = {t['task_id']: t['dir'] / ('confirm' if confirm else '.attempt') / (
            host['host_id'] if confirm else UNIT_DIR) for t, _ in chunk}
        try:
            results = worker.run(chunk, stage_root / name, dests)
        except Exception as exc:  # the whole batch failed: host trouble, so the rest take the ordinary path
            log(f'compare_batch: batch of {len(chunk)} failed ({type(exc).__name__}: {str(exc)[:160]}); '
                'the remaining units run on the ordinary host')
            down.set()
            return
        good = 0
        for task, files in chunk:
            got = results.get(task['task_id'])
            if isinstance(got, tuple) and isinstance(got[0], int):
                if confirm:
                    mark_confirm(task['dir'], task, files, host['host_id'], got[0])
                else:
                    write_entry(task['dir'], spec_key(task, files, host['host_id']), name, got[0])
                good += 1
            else:
                shutil.rmtree(dests[task['task_id']], ignore_errors=True)
        with lock:
            kept[0] += good
        log(f'compare_batch: batch of {len(chunk)} done in {time.monotonic() - started:.0f} s, {good} kept')

    try:
        with ThreadPoolExecutor(max_workers=IN_FLIGHT) as pool:
            list(pool.map(one, chunks))
    finally:
        shutil.rmtree(stage_root, ignore_errors=True)
    return kept[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('tasks', nargs='+', type=Path)
    parser.add_argument('--deadline', type=float, default=1800,
                        help='seconds after which no new batch starts (default 1800)')
    parser.add_argument('--confirm', action='store_true',
                        help='the tasks are one-function confirm directories (the bot\'s record build)')
    parser.add_argument('--batch', type=int, help='units per upload (default: the host\'s `batch`)')
    args = parser.parse_args()
    started = time.monotonic()
    try:
        config = runners.load()
        if config is None:
            print('compare_batch: no runners config; nothing prefetched')
            return 0
        name, warnings = runners.choose_compare(config)
        for w in warnings:
            print(f'compare_batch: WARNING: {w}')
        if name is None:
            print('compare_batch: no compare host is reachable or preferred; units run on the ordinary host')
            return 0
        kept = run(args.tasks, config, name, started + args.deadline, args.batch, confirm=args.confirm)
    except (runners.RunnerError, pipeline.PipelineError, OSError) as exc:
        print(f'compare_batch: {type(exc).__name__}: {str(exc)[:200]}; units run on the ordinary host')
        return 0
    print(f'compare_batch: {kept} of {len(args.tasks)} unit(s) prefetched on {name} in {time.monotonic() - started:.0f} s')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
