"""Write twin units into a checkout and compile and compare them on the configured runner host.

Task directories (private, under `.local/tasks/`) are built directly: a task file, a local pack of
the target function (needed for position binding) and the public symbol map. `tools/verifier/attempt`
then compiles on the host `SR_RUNNERS_CONFIG` names (the Windows PC in this project), binds the
references by position and compares with the unchanged comparator. Only its verdict lines are read.
"""
import concurrent.futures as cf
import json
import os
from pathlib import Path
import re
import subprocess
import sys

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / 'verifier'))

BUILD = 'sse-steam-1-7-104'
VERDICT = re.compile(r'^\s+0x([0-9a-f]+) (PASS|FAIL) (\S+)(?:.*?size (\d+|\?)/(\d+|\?))?', re.M)
AGENT = 'Claude Sonnet 5.5 (twin propagation)'


def write_twin(root, twin):
    """Write the unit files of `twin` below reconstruction/; returns the .cpp path (repo-relative)."""
    for rel, text in twin.files.items():
        path = Path(root) / 'reconstruction' / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
    return 'reconstruction/' + twin.stem + '.cpp'


def make_task(ctx, exe, root, twin, size, tasks_dir):
    """Create `.local/tasks/twin-<rva>/` for a written twin; returns its directory."""
    import contrib
    tdir = Path(tasks_dir) / ('twin-%x' % twin.rva)
    tdir.mkdir(parents=True, exist_ok=True)
    fn = {'build_id': BUILD, 'rva': twin.rva, 'size': size, 'name': twin.name, 'name_origin': 'GUESS'}
    dest, _pack = contrib.write_pack(ctx, exe, fn, {})
    task = {'task_id': tdir.name, 'build_id': BUILD, 'compiled': 'reconstruction/' + twin.stem + '.cpp',
            'recipe': contrib.DEFAULT_RECIPE, 'symbols': 'symbols.json',
            'functions': [{'rva': '0x%x' % twin.rva, 'size': size, 'symbol': 'unbound:' + twin.name,
                           'function_id': '%s-0x%x' % (BUILD, twin.rva), 'community_name': twin.name, 'pack': str(dest)}],
            'drafter_model': AGENT}
    (tdir / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
    contrib.refresh_symbols(ctx, tdir, BUILD)
    return tdir


def attempt(root, tdir, env=None, timeout=1500):
    """Run `tools/verifier/attempt` on a task; returns {'status', 'reason', 'sizes', 'output'}."""
    e = dict(os.environ, **(env or {}))
    proc = subprocess.run([sys.executable, str(TOOLS / 'verifier/attempt'), '--agent', AGENT, '--no-advisory', '--no-retry', str(tdir)],
                          cwd=root, env=e, capture_output=True, text=True, timeout=timeout)
    out = proc.stdout + proc.stderr
    m = VERDICT.search(out)
    if m:
        return {'status': m.group(2).lower(), 'reason': m.group(3), 'sizes': [m.group(4), m.group(5)], 'exit': proc.returncode,
                'output': out}
    reason = 'compile-failed' if proc.returncode == 3 else 'unit-problem' if proc.returncode == 4 else 'no-verdict'
    return {'status': 'error', 'reason': reason, 'sizes': None, 'exit': proc.returncode, 'output': out}


def run_many(root, tdirs, jobs=4, env=None, on_result=None):
    results = {}
    with cf.ThreadPoolExecutor(jobs) as pool:
        futures = {pool.submit(attempt, root, t, env): t for t in tdirs}
        for fu in cf.as_completed(futures):
            t = futures[fu]
            try:
                results[t.name] = fu.result()
            except Exception as exc:  # noqa: BLE001
                results[t.name] = {'status': 'error', 'reason': type(exc).__name__, 'sizes': None, 'output': str(exc)}
            if on_result:
                on_result(t.name, results[t.name])
    return results


def prefetch(root, tdirs, env=None):
    """Batch-compile `tdirs` on the compare host in a few round trips; `attempt` then reuses the results."""
    e = dict(os.environ, **(env or {}))
    return subprocess.run([sys.executable, str(TOOLS / 'verifier/compare_batch.py'), *map(str, tdirs)], cwd=root, env=e,
                          capture_output=True, text=True)
