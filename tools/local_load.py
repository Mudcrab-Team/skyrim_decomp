#!/usr/bin/env python3
"""Machine-wide cap on heavy local processes, for a machine that only orchestrates.

    python3 tools/local_load.py status        # the cap in force and how many slots are held

A runners config (`.local/verifier/runners.json`, or SR_RUNNERS_CONFIG) may set the top-level
`local_max_heavy`: the most CPU-heavy local jobs (compiles, scoring pools, check fan-out) that may run
on this machine at once, across every checkout and worktree that shares the same `.local/verifier`.
Unset, there is no cap and nothing here does anything, which is the case for contributors and CI.
SR_LOCAL_MAX_HEAVY overrides the file for one process tree: a number, or `0`/`off`/`unlimited` to lift
the cap (for example for a service that must not queue behind workers).

The cap is a pool of flock()ed files under `<state>/local-heavy/`, released by the kernel when the
holder dies, so no daemon and no stale lock. `heavy()` holds one slot for a block (plus, on request,
more that are free right now, never waiting for them, so two callers can never hold half a set each).
A job that has to wait prints one line saying so. Holding is re-entrant: a block nested inside a held
block in the same thread, or in a child process that inherits SR_LOCAL_HEAVY_HELD, takes no further
slot, so a heavy tool calling another heavy tool cannot deadlock itself.

Callers that can run on a remote runner should prefer it (`runners.choose_attempt` does when a cap is
set); the cap only bounds what still has to run here.
"""
from contextlib import contextmanager
import json
import os
from pathlib import Path
import sys
import threading
import time


KEY = 'local_max_heavy'
ENV_LIMIT = 'SR_LOCAL_MAX_HEAVY'
ENV_HELD = 'SR_LOCAL_HEAVY_HELD'
MAX_SLOTS = 64
DEFAULT_WAIT = 4 * 3600
UNSET = object()
_OFF = ('', '0', 'off', 'none', 'unlimited')


class LoadGuardError(Exception):
    pass


def parse(value, where=KEY):
    """The cap as an int from 1 to MAX_SLOTS, or None for no cap; ValueError for anything else."""
    if value is None:
        return None
    if isinstance(value, bool) or not isinstance(value, int) or not 1 <= value <= MAX_SLOTS:
        raise ValueError(f'{where} must be an integer from 1 to {MAX_SLOTS} (or absent for no cap)')
    return value


_state = {}


def state_dir(environ=None):
    environ = os.environ if environ is None else environ
    configured = environ.get('SR_VERIFIER_STATE')
    if configured:
        return Path(configured)
    if 'default' not in _state:
        verifier = str(Path(__file__).resolve().parent / 'verifier')
        if verifier not in sys.path:
            sys.path.append(verifier)
        try:
            import starts
            _state['default'] = starts.state_dir()
        except OSError:
            _state['default'] = Path(__file__).resolve().parents[1] / '.local' / 'verifier'
    return _state['default']


def config_path(environ=None):
    environ = os.environ if environ is None else environ
    configured = environ.get('SR_RUNNERS_CONFIG')
    return Path(configured) if configured else state_dir(environ) / 'runners.json'


def _warn(message):
    print(f'local load guard: {message}; no cap applied', file=sys.stderr)


def limit(environ=None, configured=UNSET):
    """The cap in force, or None. `configured` is a validated config's value; without it the file is read."""
    environ = os.environ if environ is None else environ
    raw = environ.get(ENV_LIMIT)
    if raw is not None:
        if raw.strip().lower() in _OFF:
            return None
        try:
            return parse(int(raw), ENV_LIMIT)
        except ValueError as exc:
            _warn(str(exc))
            return None
    if configured is not UNSET:
        return configured
    try:
        data = json.loads(config_path(environ).read_text())
        return parse(data.get(KEY) if isinstance(data, dict) else None)
    except OSError:
        return None
    except ValueError as exc:
        _warn(f'{config_path(environ)}: {exc}')
        return None


def slot_dir(environ=None):
    return state_dir(environ) / 'local-heavy'


def _lock():
    """file_lock, imported when a cap is in force: without a cap this module needs nothing platform specific."""
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import file_lock
    return file_lock


def _take(directory, cap):
    file_lock = _lock()
    for i in range(cap):
        handle = open(directory / f'slot.{i}.lock', 'a')
        try:
            file_lock.flock(handle, file_lock.LOCK_EX | file_lock.LOCK_NB)
        except OSError:
            handle.close()
            continue
        return handle
    return None


def busy(cap, directory=None):
    """How many of the `cap` slots are held right now."""
    directory = Path(directory) if directory else slot_dir()
    file_lock = _lock()
    count = 0
    for i in range(cap):
        path = directory / f'slot.{i}.lock'
        if not path.exists():
            continue
        with open(path, 'a') as handle:
            try:
                file_lock.flock(handle, file_lock.LOCK_EX | file_lock.LOCK_NB)
                file_lock.flock(handle, file_lock.LOCK_UN)
            except OSError:
                count += 1
    return count


class _Held(threading.local):
    held = 0
    reserved = 0


_held = _Held()
_marker = {'lock': threading.Lock(), 'count': 0, 'previous': None}


def _mark(n):
    with _marker['lock']:
        if _marker['count'] == 0:
            _marker['previous'] = os.environ.get(ENV_HELD)
            os.environ[ENV_HELD] = str(n)
        _marker['count'] += 1


def _unmark():
    with _marker['lock']:
        _marker['count'] -= 1
        if _marker['count'] == 0:
            if _marker['previous'] is None:
                os.environ.pop(ENV_HELD, None)
            else:
                os.environ[ENV_HELD] = _marker['previous']


def _say(message):
    print(message, file=sys.stderr, flush=True)


@contextmanager
def heavy(label, want=1, log=None, wait=DEFAULT_WAIT, directory=None, cap=UNSET, poll=0.25):
    """Hold a heavy-job slot for the block; yields how many slots are held (the caller sizes its pool to it).

    The first slot is waited for, up to `wait` seconds (LoadGuardError after that); the others up to
    `want` are taken only if free now. With no cap in force this yields `want` and holds nothing.
    """
    cap = limit() if cap is UNSET else cap
    if cap is None:
        yield want
        return
    if _held.held:
        yield max(1, min(want, _held.held - _held.reserved))
        return
    # The marker is inherited only from a parent process; one set by another thread here is not ours to use.
    inherited = os.environ.get(ENV_HELD) if _marker['count'] == 0 else None
    if inherited and inherited.isdigit() and int(inherited) > 0:
        yield max(1, min(want, int(inherited)))
        return
    log = log or _say
    want = max(1, min(want, cap))
    directory = Path(directory) if directory else slot_dir()
    directory.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    handles = []
    said = False
    while True:
        handle = _take(directory, cap)
        if handle:
            handles.append(handle)
            break
        if time.monotonic() - started > wait:
            raise LoadGuardError(f'{label}: all {cap} heavy local slots stayed busy for {wait} s')
        if not said:
            log(f'local load guard: {label} waits for a free slot ({busy(cap, directory)} of {cap} heavy local '
                'slots busy)')
            said = True
        time.sleep(poll)
    while len(handles) < want:
        handle = _take(directory, cap)
        if not handle:
            break
        handles.append(handle)
    file_lock = _lock()
    _held.held, _held.reserved = len(handles), 0
    _mark(len(handles))
    try:
        yield len(handles)
    finally:
        _held.held = _held.reserved = 0
        _unmark()
        for handle in handles:
            file_lock.flock(handle, file_lock.LOCK_UN)
            handle.close()


@contextmanager
def reserved(count):
    """Inside a held block: `count` of its slots are in use by helper processes, so nested blocks get fewer."""
    _held.reserved += count
    try:
        yield
    finally:
        _held.reserved -= count


def main(argv=None):
    cap = limit()
    if cap is None:
        print('local load guard: no cap (set local_max_heavy in the runners config, or SR_LOCAL_MAX_HEAVY)')
        return 0
    print(f'local load guard: cap {cap}; {busy(cap)} slot(s) held now ({slot_dir()})')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
