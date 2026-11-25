"""Recommended contributor Ghidra view. Downloads, projects, logs and output stay private.

Original tooling only; no internal project, private config or analysis data is reused.
"""
from contextlib import contextmanager
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import platform
import re
import shutil
import subprocess
import sys
import tarfile
import tempfile
import time
import urllib.error
import urllib.request
import zipfile

HEAP = '16G'
ANALYSIS_RAM = 18 * 1024**3  # 16 GiB heap plus 2 GiB for native memory and headroom.
ANALYSIS_DISK = 3 * 1024**3
WARNING = 'PRIVATE DECOMPILER HINT: never paste publicly; untrusted, not evidence'


def available_ram(ctx):
    """Conservative available/reclaimable RAM, not capacity; unknown means defer."""
    if ctx.windows:
        import ctypes
        class Memory(ctypes.Structure):
            _fields_ = [('length', ctypes.c_uint32), ('load', ctypes.c_uint32)] + [
                (name, ctypes.c_ulonglong) for name in
                ('total_phys', 'avail_phys', 'total_page', 'avail_page', 'total_virtual',
                 'avail_virtual', 'avail_extended')]
        memory = Memory()
        memory.length = ctypes.sizeof(memory)
        if not ctypes.windll.kernel32.GlobalMemoryStatusEx(ctypes.byref(memory)):
            return None
        return memory.avail_phys
    if ctx.platform == 'linux':
        match = re.search(r'^MemAvailable:\s+(\d+)\s+kB$', Path('/proc/meminfo').read_text(), re.M)
        return int(match[1]) * 1024 if match else None
    if ctx.platform == 'darwin':
        result = ctx.run(['/usr/bin/vm_stat'], capture_output=True, text=True, timeout=10)
        size = re.search(r'page size of (\d+) bytes', result.stdout)
        pages = [re.search(r'^' + label + r':\s+(\d+)\.', result.stdout, re.M)
                 for label in ('Pages free', 'Pages inactive')]
        if result.returncode == 0 and size and all(pages):
            return int(size[1]) * sum(int(p[1]) for p in pages)
    return None


def resource_problem(ctx):
    try:
        available = available_ram(ctx)
    except (OSError, ValueError, AttributeError, subprocess.SubprocessError):
        available = None
    if available is None:
        return 'available RAM could not be measured'
    if available < ANALYSIS_RAM:
        return f'{available / 1024**3:.1f} GiB available RAM; need 18 GiB (16 GiB heap plus 2 GiB margin)'
    path = ctx.private
    while not path.exists():
        path = path.parent
    free = shutil.disk_usage(path).free
    if free < ANALYSIS_DISK:
        return f'{free / 1024**3:.1f} GiB free disk; need about 3 GiB'
    return None


def recommended_setup(ctx, no_install=False):
    """A helpful background hint must never make ordinary setup fail."""
    try:
        _exe, project = identity(ctx)
        state = status(project)
        if state['state'] in ('ready', 'running', 'starting'):
            api().save_config(ctx, decompiler=True)
            return state
        reason = resource_problem(ctx)
        if reason:
            return dict(state='skipped', reason=reason)
        return setup(ctx, no_install)
    except (api().Stop, OSError, ValueError, KeyError, TypeError, AttributeError, subprocess.SubprocessError):
        return dict(state='skipped', reason='decompiler installation or analysis launch unavailable; '
                    'check the private decompiler logs and network')


def api():
    # Lazy import also works when contrib.py is running as __main__.
    main = sys.modules.get("__main__")
    if main and Path(getattr(main, "__file__", "")).name == "contrib.py":
        return main
    import contrib
    return contrib


def directory(ctx):
    return ctx.private / 'decompiler'


def pins(ctx):
    return json.loads((ctx.repo / 'tools/contrib-decompiler-pins.json').read_text(encoding='utf-8'))


def platform_key(ctx):
    system = {'darwin': 'mac', 'linux': 'linux', 'win32': 'windows'}.get(ctx.platform)
    machine = platform.machine().lower()
    arch = {'arm64': 'aarch64', 'aarch64': 'aarch64', 'amd64': 'x64', 'x86_64': 'x64'}.get(machine)
    key = f'{system}-{arch}'
    if key not in pins(ctx)['jdk']:
        raise api().Stop(api().MISSING, 'no pinned decompiler runtime for this platform',
                         'use macOS arm64/x64, Linux arm64/x64, or Windows x64')
    return key


def unpack(archive, dest):
    """Refuse traversal, links and devices before unpacking a hash-checked release."""
    def safe(name):
        path = PurePosixPath(name.replace('\\', '/'))
        if path.is_absolute() or '..' in path.parts or any(':' in p for p in path.parts):
            raise ValueError('unsafe archive path')
    if archive.name.endswith('.zip'):
        with zipfile.ZipFile(archive) as z:
            for item in z.infolist():
                safe(item.filename)
                if (item.external_attr >> 16) & 0o170000 == 0o120000:
                    raise ValueError('archive symlink refused')
            z.extractall(dest)
            for item in z.infolist():
                mode = (item.external_attr >> 16) & 0o777
                if mode and not item.is_dir():
                    (dest / item.filename).chmod(mode)
    else:
        with tarfile.open(archive) as tar:
            # Temurin includes relative symlinks. Validate their destinations on Python 3.11 too.
            for item in tar.getmembers():
                safe(item.name)
                if item.isdev() or item.isfifo():
                    raise ValueError('archive special file refused')
                if item.issym() or item.islnk():
                    target = PurePosixPath(item.linkname)
                    if target.is_absolute():
                        raise ValueError('archive absolute link refused')
                    parent = dest / PurePosixPath(item.name).parent if item.issym() else dest
                    if not (parent / item.linkname).resolve().is_relative_to(dest.resolve()):
                        raise ValueError('archive escaping link refused')
            if hasattr(tarfile, 'data_filter'):
                tar.extractall(dest, filter='data')
            else:
                tar.extractall(dest)


def download(ctx, pin):
    c = api()
    dest = directory(ctx) / 'downloads' / pin['url'].rsplit('/', 1)[1]
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.is_file() and c.sha256_file(dest) == pin['sha256']:
        return dest
    dest.unlink(missing_ok=True)
    partial = dest.with_name(dest.name + '.part')
    for attempt in range(3):
        try:
            with urllib.request.urlopen(pin['url'], timeout=60) as response, partial.open('wb') as out:
                shutil.copyfileobj(response, out)
            if c.sha256_file(partial) != pin['sha256']:
                raise c.Stop(c.FAILED, 'decompiler download SHA-256 mismatch; not installed',
                             f'{ctx.cli} --yes setup --decompiler')
            partial.replace(dest)
            return dest
        except (OSError, urllib.error.URLError) as exc:
            transient = not isinstance(exc, urllib.error.HTTPError) or exc.code in (408, 429, 500, 502, 503, 504)
            if not transient or attempt == 2:
                raise c.Stop(c.NETWORK, 'cannot download pinned decompiler runtime',
                             f'{ctx.cli} --yes setup --decompiler (retry online)') from exc
            time.sleep(attempt + 1)
        finally:
            partial.unlink(missing_ok=True)


def runtime(ctx):
    p = pins(ctx)
    root = directory(ctx)
    ghidra = root / 'tools' / p['ghidra']['root']
    java = root / 'tools' / p['jdk'][platform_key(ctx)]['root']
    if ctx.platform == 'darwin':
        java = java / 'Contents/Home'
    headless = ghidra / 'support' / ('analyzeHeadless.bat' if ctx.windows else 'analyzeHeadless')
    return headless, java


def native_binary(ctx):
    platform_dir = {'mac-aarch64': 'mac_arm_64', 'mac-x64': 'mac_x86_64',
                    'linux-aarch64': 'linux_arm_64', 'linux-x64': 'linux_x86_64',
                    'windows-x64': 'win_x86_64'}[platform_key(ctx)]
    return runtime(ctx)[0].parents[1] / 'Ghidra/Features/Decompiler/os' / platform_dir / (
        'decompile.exe' if ctx.windows else 'decompile')


def ensure_native(ctx):
    c = api()
    dest = native_binary(ctx)
    if dest.is_file():
        return
    if ctx.windows:
        raise c.Stop(c.MISSING, 'pinned Ghidra archive lacks its native decompiler',
                     f'{ctx.cli} --yes setup --decompiler')
    make = ctx.which('make')
    compiler = '/usr/bin/clang++' if ctx.platform == 'darwin' else ctx.which('g++')
    if not make or not compiler or (ctx.platform == 'darwin' and ctx.run(
            ['/usr/bin/xcrun', '--find', 'clang++'], capture_output=True).returncode):
        raise c.Stop(c.MISSING, 'building the decompiler needs make and a C++ compiler',
                     'macOS: install Apple Command Line Tools (xcode-select --install); '
                     'Linux: install make and g++ with your package manager')
    ctx.say('The official archive has no native decompiler for this platform; building its '
            'hash-checked source locally (four compile jobs; allow a few minutes).')
    source = runtime(ctx)[0].parents[1] / 'Ghidra/Features/Decompiler/src/decompile/cpp'
    key = platform_key(ctx)
    arch = ('-arch arm64' if key == 'mac-aarch64' else '-arch x86_64') if ctx.platform == 'darwin' else ''
    flags = '-mmacosx-version-min=11.0 -w' if ctx.platform == 'darwin' else ''
    started = time.monotonic()
    with (directory(ctx) / 'native-build.log').open('wb') as log:
        result = ctx.run([make, '-j4', 'ghidra_opt', 'ARCH_TYPE=' + arch,
                          'ADDITIONAL_FLAGS=' + flags, 'CXX=' + compiler + ' -std=c++11'],
                         cwd=source, stdout=log, stderr=log)
    built = source / 'ghidra_opt'
    if result.returncode or not built.is_file():
        raise c.Stop(c.FAILED, 'native decompiler build failed; inspect private native-build.log',
                     f'{ctx.cli} --yes setup --decompiler')
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(built, dest)
    dest.chmod(0o755)
    write_json(directory(ctx) / 'native-build.json', dict(seconds=time.monotonic()-started,
                                                       sha256=c.sha256_file(dest), platform=key))


def install(ctx, no_install=False):
    c = api()
    selected = [pins(ctx)['ghidra'], pins(ctx)['jdk'][platform_key(ctx)]]
    headless, java = runtime(ctx)
    marker = directory(ctx) / 'installed.json'
    if marker.is_file() and json.loads(marker.read_text(encoding='utf-8')) == selected and headless.is_file() \
            and (java / 'bin' / ('java.exe' if ctx.windows else 'java')).is_file():
        if no_install and not native_binary(ctx).is_file():
            raise c.Stop(c.MISSING, 'native decompiler is not built', f'{ctx.cli} --yes setup --decompiler')
        ensure_native(ctx)
        return
    total = sum(p['size'] for p in selected)
    ctx.say(f'Recommended Ghidra 12.2 + Temurin 25.0.1: {total / 1e6:.1f} MB download; '
            'allow 3 GB disk plus project space. Apache-2.0 and GPL-2.0 with Classpath exception; '
            'no licence acceptance required. https://adoptium.net/about/license/')
    if no_install:
        raise c.Stop(c.MISSING, 'recommended decompiler is not installed', f'{ctx.cli} --yes setup')
    if not ctx.ask('Download and unpack the recommended private decompiler?', '--yes'):
        raise c.Stop(c.CONSENT, 'decompiler install declined', f'{ctx.cli} --yes setup')
    dest = directory(ctx) / 'tools'
    dest.mkdir(parents=True, exist_ok=True)
    for pin in selected:
        archive = download(ctx, pin)
        staging = directory(ctx) / 'unpack'
        shutil.rmtree(staging, ignore_errors=True)
        staging.mkdir()
        unpack(archive, staging)
        source = staging / pin['root']
        if not source.is_dir():
            raise ValueError('pinned archive root missing')
        target = dest / pin['root']
        shutil.rmtree(target, ignore_errors=True)
        source.replace(target)
        shutil.rmtree(staging)
    ensure_native(ctx)
    marker.write_text(json.dumps(selected, indent=2) + '\n', encoding='utf-8')


def identity(ctx):
    c = api()
    target = c.target_manifest(ctx.repo)
    # Always recheck the owner's executable before opening a project or trusting a ready marker.
    exe = c.require_exe(ctx, target)['path']
    key = 'contrib-analysis-v1' + target['image_sha256'] + json.dumps(pins(ctx), sort_keys=True)
    digest = hashlib.sha256(key.encode()).hexdigest()[:16]
    return exe, directory(ctx) / 'projects' / digest


def write_json(path, data):
    temp = path.with_suffix('.tmp')
    temp.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8')
    temp.replace(path)


def process_alive(pid):
    if sys.platform == 'win32':
        import ctypes
        from ctypes import wintypes
        kernel = ctypes.WinDLL('kernel32', use_last_error=True)
        kernel.OpenProcess.restype = wintypes.HANDLE
        kernel.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
        kernel.GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
        kernel.CloseHandle.argtypes = [wintypes.HANDLE]
        handle = kernel.OpenProcess(0x1000, False, pid)
        if not handle:
            return False
        try:
            code = wintypes.DWORD()
            return bool(kernel.GetExitCodeProcess(handle, ctypes.byref(code))) and code.value == 259
        finally:
            kernel.CloseHandle(handle)
    try:
        os.kill(pid, 0)
        return True
    except ProcessLookupError:
        return False
    except PermissionError:
        return True


@contextmanager
def project_lock(project, blocking=False):
    with (project / 'worker.lock').open('a+b') as lock:
        lock.seek(0)
        if sys.platform == 'win32':
            import msvcrt
            if not lock.read(1):
                lock.write(b'0')
                lock.flush()
            lock.seek(0)
            try:
                msvcrt.locking(lock.fileno(), msvcrt.LK_LOCK if blocking else msvcrt.LK_NBLCK, 1)
            except OSError:
                yield False
                return
        else:
            import fcntl
            try:
                fcntl.flock(lock, fcntl.LOCK_EX | (0 if blocking else fcntl.LOCK_NB))
            except BlockingIOError:
                yield False
                return
        try:
            yield True
        finally:
            if sys.platform == 'win32':
                lock.seek(0)
                msvcrt.locking(lock.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(lock, fcntl.LOCK_UN)


def status(project):
    try:
        state = json.loads((project / 'state.json').read_text(encoding='utf-8'))
    except (OSError, ValueError):
        return {'state': 'not-started'}
    if state['state'] in ('running', 'starting'):
        if not process_alive(state['pid']):
            state['state'] = 'interrupted'
        state['elapsed_seconds'] = round(time.time() - state['started'], 1)
    return state


def windows_command(ctx, args, *, junction=False):
    # cmd.exe parses batch files even with shell=False. Quote every path, including '&'.
    # Refuse expansion/control characters rather than execute a changed owner-supplied path.
    if any(any(c in str(arg) for c in '%!"\r\n') for arg in args):
        raise api().Stop(api().USAGE, 'Windows decompiler paths cannot contain %, !, quotes or newlines',
                         'use a checkout and executable path without those characters')
    command = ' '.join('"' + str(arg) + '"' for arg in (args[2:] if junction else args))
    if junction:
        command = 'mklink /J ' + command
    return subprocess.list2cmdline([ctx.env.get('COMSPEC', 'cmd.exe')]) + ' /d /s /c "' + command + '"'


@contextmanager
def project_alias(ctx, project):
    # Ghidra 12.2 rejects ANY dot-prefixed component in a project locator, including .local.
    # This temporary alias stores no game data; the project itself remains under .local/contrib.
    with tempfile.TemporaryDirectory(prefix='sr-ghidra-') as temp:
        alias = Path(temp) / 'project'
        if ctx.windows:
            subprocess.run(windows_command(ctx, ['mklink', '/J', str(alias), str(project.resolve())], junction=True),
                           check=True, capture_output=True)
        else:
            alias.symlink_to(project.resolve(), target_is_directory=True)
        try:
            yield alias
        finally:
            if ctx.windows:
                try:
                    alias.rmdir()
                except FileNotFoundError:
                    pass
            else:
                alias.unlink()


def launch_command(ctx, project, *args):
    headless, java = runtime(ctx)
    env = dict(ctx.env, JAVA_HOME=str(java), GHIDRA_HEADLESS_MAXMEM=HEAP)
    for option in ('GHIDRA_JAVA_OPTIONS', 'GHIDRA_HEADLESS_JAVA_OPTIONS', '_JAVA_OPTIONS', 'JDK_JAVA_OPTIONS'):
        env.pop(option, None)
    env['PATH'] = str(java / 'bin') + os.pathsep + ctx.env.get('PATH', '')
    # Ghidra caches and Java preferences must also stay inside the contributor's private tree.
    home = directory(ctx) / 'home'
    home.mkdir(exist_ok=True)
    locations = {'user.home': home, 'java.io.tmpdir': directory(ctx) / 'tmp',
                 'application.tempdir': directory(ctx) / 'tmp',
                 'application.cachedir': directory(ctx) / 'cache',
                 'application.settingsdir': directory(ctx) / 'settings'}
    for path in locations.values():
        path.mkdir(exist_ok=True)
    env['JAVA_TOOL_OPTIONS'] = ' '.join(f'-D{key}="{path}"' for key, path in locations.items()) + \
        ' -XX:+ExitOnOutOfMemoryError'
    cmd = [str(headless), str(project), 'skyrim', '-scriptPath', str(ctx.repo / 'tools/ghidra'),
           '-max-cpu', '4', *map(str, args)]
    if ctx.windows:
        cmd = windows_command(ctx, cmd)
    return cmd, env


def setup(ctx, no_install=False):
    c = api()
    exe, project = identity(ctx)  # Missing/wrong executable must not start a download.
    project.mkdir(parents=True, exist_ok=True)
    with project_lock(project) as acquired:
        if not acquired:
            return status(project)
        return setup_locked(ctx, exe, project, no_install)


def setup_locked(ctx, exe, project, no_install):
    c = api()
    install(ctx, no_install)
    c.save_config(ctx, decompiler=True)
    project.mkdir(parents=True, exist_ok=True)
    state = status(project)
    if state['state'] in ('ready', 'running', 'starting'):
        ctx.say(f'decompiler: {state["state"]}; elapsed {state.get("elapsed_seconds", 0)} s')
        return state
    ctx.say(f'One-time private analysis: {HEAP} Java heap cap plus native memory; '
            'see docs/contributor-platforms.md for measured costs. '
            'Runs in background; rerun setup --no-self-test for status. '
            'Interrupted runs resume from the saved import; the current analysis pass restarts.')
    names = c.public_names(ctx.repo, c.inventory(ctx.repo))
    (project / 'names.tsv').write_text(''.join(f'0x{r:x}\t{n[0]}\n' for r, n in sorted(names.items())),
                                       encoding='utf-8')
    # Worker arguments contain paths only and are kept in private storage/logs.
    with (project / 'worker.log').open('ab') as log:
        kwargs = {'creationflags': subprocess.CREATE_NEW_PROCESS_GROUP | subprocess.DETACHED_PROCESS} \
            if ctx.windows else {'start_new_session': True}
        worker = subprocess.Popen([sys.executable, str(ctx.repo / 'tools/contrib_decompiler.py'),
                                   '--worker', str(ctx.repo), str(ctx.private), str(project)],
                                  env=ctx.env, stdin=subprocess.DEVNULL, stdout=log, stderr=log, **kwargs)
    write_json(project / 'state.json', dict(state='starting', pid=worker.pid, started=time.time(), heap=HEAP))
    ctx.say(f'decompiler started (worker {worker.pid}); progress: {project / "state.json"}; '
            f'private analysis log: {project / "analysis.log"}')
    return {'state': 'starting', 'pid': worker.pid, 'project': str(project)}


def run_worker(repo, private, project):
    c = api()
    ctx = c.Ctx(repo=repo, private=private, as_json=True)
    project = Path(project)
    with project_lock(project, blocking=True) as acquired:
        if not acquired:
            return
        run_analysis(ctx, project)


def run_analysis(ctx, project):
    started = time.time()
    state = dict(state='running', phase='import', pid=os.getpid(), started=started, heap=HEAP)
    write_json(project / 'state.json', state)
    try:
        exe, expected = identity(ctx)
        if expected != project:
            raise ValueError('project identity changed')
        with (project / 'analysis.log').open('ab') as log, project_alias(ctx, project) as alias:
            log_start = log.tell()
            if not ((project / 'imported').is_file() and (project / 'skyrim.gpr').is_file()):
                cmd, env = launch_command(ctx, alias, '-import', exe, '-overwrite', '-noanalysis')
                try:
                    subprocess.run(cmd, env=env, stdout=log, stderr=log, check=True)
                    if not (project / 'skyrim.gpr').is_file():
                        raise ValueError('private project was not saved')
                    (project / 'imported').write_text('complete\n', encoding='utf-8')
                except Exception:
                    (project / 'imported').unlink(missing_ok=True)
                    raise
            (project / 'analyzed').unlink(missing_ok=True)
            state['phase'] = 'analysis'
            write_json(project / 'state.json', state)
            cmd, env = launch_command(ctx, alias, '-process', Path(exe).name, '-preScript',
                                      'ContribConfigure.java', '-postScript', 'ContribNames.java',
                                      project / 'names.tsv', '-postScript', 'ContribCheckpoint.java', project / 'analyzed')
            # Sample child process tree RSS independently of Ghidra's heap cap.
            proc = subprocess.Popen(cmd, env=env, stdout=log, stderr=log)
            peak = None
            while proc.poll() is None:
                sample = process_tree_rss(proc.pid)
                if sample is not None:
                    peak = max(peak or 0, sample)
                state.update(elapsed_seconds=round(time.time() - started, 1), peak_rss_bytes=peak)
                write_json(project / 'state.json', state)
                time.sleep(2)
            log.flush()
            with (project / 'analysis.log').open('rb') as diagnostics:
                diagnostics.seek(log_start)
                exhausted = b'java.lang.OutOfMemoryError' in diagnostics.read()
            if proc.returncode or exhausted or not (project / 'analyzed').is_file():
                raise ValueError('headless analysis failed; inspect private analysis.log')
        state.update(state='ready', phase='complete', elapsed_seconds=round(time.time() - started, 1))
    except Exception:
        state.update(state='failed', phase='see-private-log', elapsed_seconds=round(time.time() - started, 1))
        raise
    finally:
        write_json(project / 'state.json', state)


def windows_process_rows():
    """Snapshot (pid, parent, resident bytes) using Windows APIs; unreadable RSS is unknown."""
    import ctypes
    from ctypes import wintypes as w
    class Entry(ctypes.Structure):
        _fields_ = [('size', w.DWORD), ('usage', w.DWORD), ('pid', w.DWORD),
                    ('heap', ctypes.c_size_t), ('module', w.DWORD), ('threads', w.DWORD),
                    ('parent', w.DWORD), ('priority', w.LONG), ('flags', w.DWORD),
                    ('exe', w.WCHAR * 260)]
    class Memory(ctypes.Structure):
        _fields_ = [('size', w.DWORD), ('faults', w.DWORD), ('peak_working_set', ctypes.c_size_t),
                    ('working_set', ctypes.c_size_t), ('peak_paged', ctypes.c_size_t),
                    ('paged', ctypes.c_size_t), ('peak_nonpaged', ctypes.c_size_t),
                    ('nonpaged', ctypes.c_size_t), ('pagefile', ctypes.c_size_t),
                    ('peak_pagefile', ctypes.c_size_t)]
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    psapi = ctypes.WinDLL('psapi', use_last_error=True)
    kernel.CreateToolhelp32Snapshot.argtypes = [w.DWORD, w.DWORD]
    kernel.CreateToolhelp32Snapshot.restype = w.HANDLE
    kernel.Process32FirstW.argtypes = kernel.Process32NextW.argtypes = [w.HANDLE, ctypes.POINTER(Entry)]
    kernel.OpenProcess.argtypes = [w.DWORD, w.BOOL, w.DWORD]
    kernel.OpenProcess.restype = w.HANDLE
    kernel.CloseHandle.argtypes = [w.HANDLE]
    psapi.GetProcessMemoryInfo.argtypes = [w.HANDLE, ctypes.POINTER(Memory), w.DWORD]
    snapshot = kernel.CreateToolhelp32Snapshot(2, 0)
    if snapshot == w.HANDLE(-1).value:
        raise OSError('cannot snapshot Windows process tree')
    rows = []
    try:
        entry = Entry()
        entry.size = ctypes.sizeof(entry)
        more = kernel.Process32FirstW(snapshot, ctypes.byref(entry))
        while more:
            rss = None
            handle = kernel.OpenProcess(0x1010, False, entry.pid)
            if handle:
                try:
                    memory = Memory()
                    memory.size = ctypes.sizeof(memory)
                    if psapi.GetProcessMemoryInfo(handle, ctypes.byref(memory), memory.size):
                        rss = memory.working_set
                finally:
                    kernel.CloseHandle(handle)
            rows.append((entry.pid, entry.parent, rss))
            more = kernel.Process32NextW(snapshot, ctypes.byref(entry))
    finally:
        kernel.CloseHandle(snapshot)
    return rows


def process_tree_rss(pid):
    """Sum current process-tree resident memory; sampling maxima remain an estimate."""
    if sys.platform == 'win32':
        rows = windows_process_rows()
    else:
        result = subprocess.run(['ps', '-axo', 'pid=,ppid=,rss='], capture_output=True, text=True, check=True)
        rows = []
        for row in result.stdout.splitlines():
            parts = row.split()
            if len(parts) == 3:
                process, parent, rss = map(int, parts)
                rows.append((process, parent, rss * 1024))
    descendants = {pid}
    while True:
        added = {p for p, parent, _rss in rows if parent in descendants} - descendants
        if not added:
            break
        descendants.update(added)
    selected = [rss for p, _parent, rss in rows if p in descendants]
    return None if not selected or any(rss is None for rss in selected) else sum(selected)


def decompile(ctx, rva, dest, *, required=True):
    c = api()
    exe, project = identity(ctx)
    state = status(project)
    if state['state'] != 'ready':
        if not required:
            ctx.say(f'decompiler: {state["state"]}; use {ctx.cli} decomp 0x{rva:x} after analysis completes')
            return None
        raise c.Stop(c.MISSING, f'decompiler analysis is {state["state"]}',
                     f'{ctx.cli} --yes setup --decompiler', decompiler=state)
    export = project / 'exports' / f'{rva:x}'
    export.mkdir(parents=True, exist_ok=True)
    selector = export / 'rvas.txt'
    selector.write_text(f'0x{rva:x}\n', encoding='utf-8')
    source = export / f'{rva:x}' / 'decomp.c'
    source.unlink(missing_ok=True)
    with project_alias(ctx, project) as alias, (export / 'headless.log').open('wb') as log:
        cmd, env = launch_command(ctx, alias, '-process', Path(exe).name, '-noanalysis', '-readOnly',
                                  '-preScript', 'ContribConfigure.java', '-postScript', 'ExportPack.java', selector, export, 'contrib')
        result = ctx.run(cmd, env=env, stdout=log, stderr=log, timeout=180)
    text = source.read_text(encoding='utf-8') if source.is_file() else ''
    if result.returncode or not text.startswith('// ' + WARNING) \
            or not text.rstrip().endswith('// END PRIVATE DECOMPILER HINT'):
        raise c.Stop(c.FAILED, 'local decompilation failed; inspect private headless.log',
                     f'{ctx.cli} decomp 0x{rva:x}')
    dest.mkdir(parents=True, exist_ok=True)
    output = dest / 'decomp.c'
    shutil.copyfile(source, output)
    return output


if __name__ == '__main__':
    if len(sys.argv) == 5 and sys.argv[1] == '--worker':
        run_worker(*sys.argv[2:])
    else:
        raise SystemExit('Use ./sr setup or ./sr decomp 0x<rva>')
