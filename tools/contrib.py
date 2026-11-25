#!/usr/bin/env python3
"""Contributor helper: set up, claim a function, get its bytes from your own game, write C++,
compare locally and open a pull request. Python 3.11+ standard library only; Linux, macOS, Windows.

    ./sr go [--profile cheap|full]   # one command: setup, pick, claim and start a function
    ./sr doctor             # what is present, what is missing, the one next step
    ./sr setup [--yes] [--exe PATH] [--accept-microsoft-license] [--no-decompiler]
    ./sr next               # unclaimed targets ranked by advisory draft readiness
    ./sr claim 0x<rva>      # GitHub issue as a claim (or a prefilled link)
    ./sr start 0x<rva>      # branch, unit skeleton, local pack from your exe
    ./sr decomp 0x<rva>     # private Ghidra pseudo-C hint (once background analysis is ready)
    ./sr compare            # compile with the pinned MSVC and run the comparator
    ./sr bind               # resolve bindings for the most recent compiled candidate
    ./sr preflight          # shared deterministic intake checks, before or after compare
    ./sr submit [--dry-run] # checks, commit, push, pull request
    ./sr feedback          # review feedback and failing checks on your open PRs
    ./sr release 0x<rva>    # give a claim back
    ./sr intake --base REF  # contributor-scope checks of a diff (CI, maintainers)

Every command takes --json (one JSON object on stdout) and never prompts when stdin is not a
terminal or --json is given: a step that needs a person exits 7 and names the flag to pass.
Exit codes: 0 ok, 1 a check failed (compare or lint), 2 usage or internal error, 3 compile failed,
4 unit or include problem, 5 a required input is missing (game executable, toolchain), 6 the
function is claimed by someone else, 7 a person must decide (licence, path, install), 8 network
needed but unavailable.

Nothing here uploads game-derived material. The executable is read where it is installed; packs,
objects, listings and reports stay under the ignored `.local/contrib/`. A pull request carries
source files and a sanitized comparator summary only. A local pass is not acceptance: the project
re-runs the comparison on two of its own hosts and a Reviewer checks the source before anything is
recorded as `matched` (docs/verification.md).

`--profile` (on `go` and `start`; remembered in the private config) chooses what your coding agent
reads and how many compare runs it tries before stopping: `cheap` (default; small card, for
Haiku- or Luna-class models) or `full` (full card and cookbook, for Sonnet-class models). It never
changes what counts as a match. `python3 tools/profiles.py` prints a rough cost line for each.
"""
import argparse
from bisect import bisect_left
from datetime import datetime, timezone
import hashlib
import json
import ntpath
import os
import posixpath
from pathlib import Path, PurePosixPath, PureWindowsPath
import re
import shlex
import shutil
import struct
import subprocess
import sys
import tempfile
import time
import urllib.error
import urllib.parse
import urllib.request

import profiles
import rva_headers
import agent_advice
import agent_identity
import repo_slug
import attempt_progress
import ready_queue
import crashlogger_pdb
import cookbook_notes
import giveup
from local_paths import local_dir, local_path, main_checkout_local, main_worktree_local, no_sibling_names

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / 'tools'
for _p in (TOOLS, TOOLS / 'verifier', TOOLS / 'analysis', TOOLS / 'ghidra'):
    if str(_p) not in sys.path:
        sys.path.insert(0, str(_p))

OK, FAILED, USAGE, COMPILE, UNIT, MISSING, CLAIMED, CONSENT, NETWORK = 0, 1, 2, 3, 4, 5, 6, 7, 8
UPSTREAM = repo_slug.DEFAULT_SLUG
COMPILE_TIMEOUT = 180
# Below this many functions `submit` suggests a bigger batch.
SMALL_PR_FUNCTIONS = 20
# Contributor units are small; a cap keeps a pathological file away from the compiler and reviewers.
MAX_UNIT_FILE_BYTES = 64 * 1024
DEFAULT_RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
# A matched function with a two-file unit, used by `setup` to prove the whole local chain works.
SELF_TEST_RVA = 0xef8900
UNIT_PATH = re.compile(r'reconstruction/((?:[a-z][a-z0-9_]*/)*[a-z][a-z0-9_]*)/((?:hk[a-z]{0,2})?[A-Z][A-Za-z0-9_]*)\.(h|cpp)')
PLAIN_NAME = re.compile(r'((?:hk[a-z]{0,2})?[A-Z][A-Za-z0-9_]*)::(~?[A-Za-z_][A-Za-z0-9_]*)')
FREE_NAME = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
# A claim-time entry with no class: the bare RVA placeholder (tools/claimable.py).
BARE_PLACEHOLDER = re.compile(r'Function[0-9a-f]+')
RVA_TOKEN = re.compile(r'(?<![0-9A-Za-z])0x([0-9a-fA-F]{3,8})(?![0-9A-Za-z])')
# Pinned community naming sources (SOURCES.md) that tools/check_labels.py and check_origin.py read
# from .local/sources/.
COMMUNITY_SOURCES = {
    'CharmedBaryon/CommonLibSSE-NG': ('.local/sources/CommonLibSSE-NG', 'b93280e832f263dbef44e44cbe2936622a02f91a', 'MIT'),
    'powerof3/CommonLibSSE': ('.local/sources/CommonLibSSE-po3', '654e55f7979c1733033d5dbef176e43827bac944', 'GPL-3.0'),
    'meh321/AddressLibraryDatabase': ('.local/sources/AddressLibraryDatabase', '0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91',
                                      'permission'),
}
# The FNV decompilation, readable and reusable by contributors on the same terms as the project's
# Drafters (docs/authorizations.md, Notes; LEGAL.md): SIBLING(...) labels, a `Sibling source:` line
# for a reused body, never evidence about the Skyrim binary. Optional: setup skips it with
# --no-sibling, and nothing else depends on it.
SIBLING_SOURCE = ('momusdigital/fnv_decomp', '.local/sources/fnv_decomp', '2b07cb3ec4b7aa11be96c7567914e11731aebeaf')
# The Fallout 3 decompilation (CC0-1.0), fetched with the FNV one on the same terms; the origin
# check reads it, but no name index is built from it.
SIBLING_EXTRA_SOURCES = {
    'momusdigital/f3_decomp': ('.local/sources/f3_decomp', 'f5bac1b54fc8fde16294c1d6779f27407d0a117b', 'CC0-1.0'),
}
# Steam ids. The app and build ids come from findings/target-pin.md; the depot and manifest of the
# executable are recorded from the maintainer's own install (its appmanifest lists them, and its
# build id equals the pin). Steam may move the app to a newer build at any time, which is why the
# executable is always checked against the pinned SHA-256 after a download.
STEAM_APP_ID = '489830'
STEAM_BUILD_ID = '24914197'
STEAM_EXE_DEPOT = '489833'
STEAM_EXE_MANIFEST = '4886117324142477814'
# Homebrew disabled its Wine casks (they fail Gatekeeper), so on macOS this tool fetches WineHQ's
# build as packaged by Gcenx, the same archive and hash his tap's wine-stable cask names.
CONTRIB_PROFILES = ('cheap', 'full')
MAC_WINE = {'version': '11.0_1', 'app': 'Wine Stable.app',
            'url': 'https://github.com/Gcenx/macOS_Wine_builds/releases/download/11.0_1/wine-stable-11.0_1-osx64.tar.xz',
            'sha256': 'b50dc50ec7f41d58b115a6b685d4d1315ba3c797bd3aa0f49213f2703cb82388'}


class Stop(Exception):
    """End a command with an exit code, a message and the one next action."""

    def __init__(self, code, message, next_action=None, **data):
        super().__init__(message)
        self.code, self.message, self.data = code, message, data
        self.next_action = next_action or (agent_advice.next_action(message, 'contrib') if code else None)


# ------------------------------------------------------------------ context and output

class Ctx:
    """Everything a command reads from its surroundings, so tests can substitute any of it."""

    def __init__(self, repo=REPO, env=None, platform=None, interactive=None, as_json=False, assume_yes=False,
                 runner=None, github=None, private=None):
        self.repo = Path(repo)
        self.env = dict(os.environ if env is None else env)
        if not self.env.get('SR_LOCAL_DIR'):
            shared = main_worktree_local(self.repo)
            if shared:
                self.env['SR_LOCAL_DIR'] = str(shared)
        self.platform = platform or sys.platform
        if interactive is None:
            interactive = sys.stdin.isatty() and sys.stdout.isatty()
        self.interactive = bool(interactive) and not as_json
        self.as_json, self.assume_yes = as_json, assume_yes
        self._private = Path(private) if private else None
        self.runner = runner or subprocess.run
        self._github = github
        self.log = []
        self.redact = False
        self.redact_paths = {}
        self.process_logs = []

    @property
    def local(self):
        try:
            return local_dir(self.repo, self.env)
        except ValueError as exc:
            raise Stop(MISSING, str(exc), 'set SR_LOCAL_DIR to an existing private directory') from None

    @property
    def private(self):
        return self._private if self._private is not None else self.local / 'contrib'

    @property
    def windows(self):
        return self.platform == 'win32'

    @property
    def cli(self):
        # sr.cmd names itself: a newcomer it bootstrapped has no `py` launcher on PATH.
        return '.\\sr.cmd' if self.windows else './sr'

    def which(self, name):
        path = shutil.which(name, path=self.env.get('PATH'))
        paths = ntpath if self.windows else posixpath
        if path and paths.dirname(path):
            marker = '<tool>' if paths.dirname(name) else f'<{paths.splitext(name)[0]}>'
            self.remember_path(path, marker)
        return path

    def remember_path(self, path, marker):
        if self.redact and path:
            self.redact_paths[str(path)] = marker

    def run(self, cmd, **kw):
        kw.setdefault('env', self.env)
        if (self.as_json or self.redact) and not any(k in kw for k in ('capture_output', 'stdout', 'stderr')):
            import tempfile
            directory = self.private / 'logs'
            directory.mkdir(parents=True, exist_ok=True)
            with tempfile.NamedTemporaryFile(dir=directory, suffix='.log', delete=False) as log:
                kw.update(stdout=log, stderr=subprocess.STDOUT)
                proc = self.runner(cmd, **kw)
            path = Path(log.name)
            if self.redact:
                path.write_text(self.scrub(path.read_text(errors='replace')))
            self.process_logs.append(str(path))
            return proc
        return self.runner(cmd, **kw)

    def scrub(self, text):
        """Replace known private paths in output meant to be posted."""
        if not self.redact:
            return text
        home = self.env.get('USERPROFILE' if self.windows else 'HOME') or str(Path.home())
        paths = [(str(self.repo), '<repo>'), (home, '~')]
        if self._private is not None:
            paths.append((str(self._private), '<local>'))
        try:
            cfg = load_config(self)
        except Stop:
            cfg = {}
        for key in ('exe', 'msvc', 'wine'):
            if cfg.get(key):
                paths.append((str(cfg[key]), '<' + key + '>'))
        for key in ('SR_MSVC', 'SR_MSVC_ROOT', 'SR_WINE_BIN'):
            if self.env.get(key):
                paths.append((self.env[key], '<toolchain>'))
        if self.env.get('SR_SYMBOLS_DIR'):
            paths.append((self.env['SR_SYMBOLS_DIR'], '<symbols>'))
        paths.extend(self.redact_paths.items())
        try:
            for rel, _rev, _lic in COMMUNITY_SOURCES.values():
                paths.append((str(local_path(self.repo, rel, self.env)), '<source>'))
            verifier = json.loads((self.local / 'verifier/config.json').read_text())
            for field in ('community_checkouts', 'sibling_checkouts'):
                for source in (verifier.get(field) or {}).values():
                    paths.append((str(source), '<source>'))
        except (Stop, OSError, ValueError):
            pass
        if self.env.get('SR_LOCAL_DIR'):
            shared = Path(self.env['SR_LOCAL_DIR']).expanduser()
            if not shared.is_absolute():
                shared = self.repo / shared
            paths[0:0] = [(str(shared.resolve()), '<local>'), (str(shared), '<local>')]
        for path, mark in sorted(paths, key=lambda item: len(item[0]), reverse=True):
            if path and len(path) > 1:
                variants = {path}
                if self.windows:
                    variants.update((path.replace('/', '\\'), path.replace('\\', '/')))
                variants.update(json.dumps(p)[1:-1] for p in tuple(variants))
                for variant in sorted(variants, key=len, reverse=True):
                    text = re.sub(re.escape(variant), lambda _m: mark, text,
                                  flags=re.I if self.windows or self.platform == 'darwin' else 0)
        return text

    def say(self, line):
        line = self.scrub(line)
        self.log.append(line)
        if not self.as_json:
            print(line, flush=True)

    def ask(self, question, flag):
        """Yes/no from a person; never asks without a terminal (exit 7 naming the flag instead)."""
        if self.assume_yes:
            return True
        if not self.interactive:
            raise Stop(CONSENT, f'{question} (no terminal to ask on)', f'rerun with {flag} once a person has agreed')
        answer = input(self.scrub(f'{question} [y/N] ')).strip().lower()
        return answer in ('y', 'yes')

    def github(self):
        if self._github is None:
            self._github = GitHub(self)
        return self._github


def config_path(ctx):
    return ctx.private / 'config.json'


def load_config(ctx):
    try:
        return json.loads(config_path(ctx).read_text())
    except (OSError, ValueError):
        pass
    # A worktree with a .local of its own but no config reads the main checkout's.
    for base in main_local_fallback(ctx):
        try:
            return json.loads((base / 'contrib' / 'config.json').read_text())
        except (OSError, ValueError):
            continue
    return {}


def main_local_fallback(ctx):
    """[main checkout's .local] for a linked worktree without SR_LOCAL_DIR, else []."""
    if ctx.env.get('SR_LOCAL_DIR') or ctx._private is not None:
        return []
    main = main_checkout_local(ctx.repo)
    return [main] if main is not None else []


def save_config(ctx, **changes):
    cfg = load_config(ctx)
    cfg.update(changes)
    config_path(ctx).parent.mkdir(parents=True, exist_ok=True)
    config_path(ctx).write_text(json.dumps(cfg, indent=2, sort_keys=True) + '\n')
    return cfg


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def target_manifest(repo):
    return json.loads((Path(repo) / 'builds/target.json').read_text())


def parse_rva(text):
    if isinstance(text, int):
        return text
    m = re.fullmatch(r'(?:0x)?([0-9a-fA-F]+)', str(text).strip())
    if not m:
        raise Stop(USAGE, f'not an RVA: {text!r} (write it as 0x<hex>)')
    return int(m.group(1), 16)


def git(ctx, *args, check=True, cwd=None):
    proc = ctx.run(['git', *args], cwd=cwd or ctx.repo, capture_output=True, text=True)
    if check and proc.returncode != 0:
        raise Stop(USAGE, f'git {" ".join(args)} failed: {proc.stderr.strip()[:300]}')
    return proc.stdout.strip()


# ------------------------------------------------------------------ inventory

def inventory(repo):
    return json.loads((Path(repo) / 'data/progress.json').read_text())


def find_function(data, rva):
    for fn in data['functions']:
        if fn['rva'] == rva:
            return fn
    return None


def function_table_rows(ctx):
    """The private function table by RVA when this machine has one (SR_FUNCTION_TABLE or the analysis export)."""
    import claimable
    path = ctx.env.get('SR_FUNCTION_TABLE') or str(Path(ctx.repo) / '.local/analysis/functions.jsonl')
    return claimable.load_table(path)


def resolve_function(ctx, data, rva):
    """The inventory entry, else an entry for a published function the inventory does not hold, else None.

    A published function is claimable without bulk mapping: record.py adds its entry when it is accepted.
    """
    import claimable
    fn = find_function(data, rva)
    if fn is not None:
        return fn
    sizes = claimable.published_sizes(ctx.repo)
    if rva not in sizes:
        return None
    return claimable.resolve_many(ctx.repo, data['target_build_id'], [rva],
                                  function_table_rows(ctx), sizes=sizes).get(rva)


def community_label(name_source):
    """The COMMUNITY(...) label an inventory entry's name source supports, and its licence word."""
    text = name_source or ''
    for repo, (_path, rev, licence) in COMMUNITY_SOURCES.items():
        if repo in text:
            return f'COMMUNITY({repo}@{rev[:7]}, {licence})', licence
    return None, None


def pdb_names(ctx):
    """The optional CrashLogger PDB name lookup (docs/contributing-agent.md), or None when absent."""
    return crashlogger_pdb.open_names(ctx.repo, ctx.env, ctx.private / 'crashlogger_publics.json')


def area_for(cls, repo=None):
    """The area the class belongs in by tools/unit_paths.py, or None when no rule covers it."""
    import unit_paths
    return unit_paths.unit_dir(cls, repo or Path(__file__).resolve().parent.parent)


def unit_index(repo):
    """{class: area} for every existing reconstruction/<area>/<class>.cpp, one directory walk.
    The first path in sorted order wins, as a per-class search would pick it."""
    base = Path(repo) / 'reconstruction'
    found = {}
    for path in sorted(base.rglob('*.cpp')):
        found.setdefault(path.stem, path.parent.relative_to(base).as_posix())
    return found


def unit_files(repo, cls, area=None, index=None):
    """(area, .h, .cpp) repository paths of the class's unit, existing or proposed.

    `index` is a unit_index(repo) for callers resolving many classes."""
    found = unit_index(repo) if index is None else index
    if cls in found:
        a = found[cls]
        return a, f'reconstruction/{a}/{cls}.h', f'reconstruction/{a}/{cls}.cpp'
    area = area or area_for(cls, repo)
    if area is None:
        return None, None, None
    return area, f'reconstruction/{area}/{cls}.h', f'reconstruction/{area}/{cls}.cpp'


def candidates(repo, data, claimed=(), max_size=None, readiness_facts=None, published=False, class_filter=None,
               ready=None, symbol_map=None):
    """Unclaimed targets ordered by callee readiness, binding cautions, unlock rank (the ready queue's
    functions that unblock the most callers per byte first), size band, existing layout,
    advisory declaration readiness, blocked callers, size and RVA.

    With `published`, functions of the target-hash list that have no inventory entry are included when
    their offered row names a class; they are made `mapped` when recorded (tools/claimable.py).
    """
    import claimable
    from contrib_readiness import binding_caution, readiness
    out, headers, layouts = [], {}, {}
    mapped = {}
    if symbol_map:
        for name, entry in symbol_map['symbols'].items():
            if 'rva' in entry:
                mapped.setdefault(entry['rva'], set()).add(name)
    folds = [set(group) for group in (symbol_map or {}).get('folds', [])]
    ready = ready or {}
    units = unit_index(repo)
    pool = list(data['functions'])
    if published:
        held = {f['rva'] for f in pool}
        sizes = claimable.published_sizes(repo)
        pool += [claimable.entry(data['target_build_id'], rva, sizes[rva], cls)
                 for rva, cls in sorted(claimable.offered_classes(repo).items()) if rva in sizes and rva not in held]
    for fn in pool:
        if fn['status'] != 'mapped' or fn['rva'] in claimed:
            continue
        if max_size and fn['size'] > max_size:
            continue
        m = PLAIN_NAME.fullmatch(fn.get('name') or '')
        cls, method = m.groups() if m else ('', '')
        if class_filter is not None and not class_filter.search(cls):
            continue
        if cls not in layouts:
            layouts[cls] = unit_files(repo, cls, index=units) if cls else (None, None, None)
        area, header, cpp = layouts[cls]
        has_unit = bool(cpp and (Path(repo) / cpp).is_file())
        if header not in headers:
            path = Path(repo) / header if header else None
            headers[header] = path.read_text() if path and path.is_file() else ''
        bindings = mapped.get(fn['rva'])
        caution = binding_caution(fn.get('name'), bindings, folds) if bindings else None
        rank, reason, cautions = readiness(fn, cls, method, headers[header],
                                          (readiness_facts or {}).get(fn['rva']), caution)
        callee_ready = fn['rva'] in ready and not caution
        out.append({'rva': f'0x{fn["rva"]:x}', 'size': fn['size'], 'name': fn.get('name'),
                    'name_origin': fn.get('name_origin'), 'unit': cpp, 'unit_exists': has_unit,
                    'startable': bool(m and area), 'readiness_rank': rank, 'reason': reason,
                    'cautions': cautions, 'in_inventory': fn.get('owner') != 'claim-time',
                    'size_band': claimable.band(fn['size']), 'has_layout': bool(headers[header]),
                    'callee_ready': callee_ready,
                    '_key': (not m or area is None, not callee_ready, bool(caution),
                             (ready.get(fn['rva']) or {}).get('unlock_rank', float('inf')),
                             claimable.band(fn['size']), not headers[header], rank,
                             -ready.get(fn['rva'], {}).get('blocks', 0), fn['size'], fn['rva'])})
    out.sort(key=lambda c: c.pop('_key'))
    return out


# ------------------------------------------------------------------ the game executable

def pe_version(path):
    """FileVersion from the VS_FIXEDFILEINFO block of a PE file, or None."""
    try:
        blob = Path(path).read_bytes()
    except OSError:
        return None
    i = blob.find(b'\xbd\x04\xef\xfe')
    if i < 0 or i + 16 > len(blob):
        return None
    ms, ls = struct.unpack_from('<II', blob, i + 8)
    return f'{ms >> 16}.{ms & 0xffff}.{ls >> 16}.{ls & 0xffff}'


def steam_libraries(ctx, exists=os.path.isdir, read=None):
    """Steam library folders this machine has, from the usual Steam roots and libraryfolders.vdf."""
    home = ctx.env.get('USERPROFILE' if ctx.windows else 'HOME') or str(Path.home())
    if ctx.windows:
        P = PureWindowsPath
        roots = [P(ctx.env.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Steam',
                 P(ctx.env.get('ProgramFiles', r'C:\Program Files')) / 'Steam']
    else:
        P = PurePosixPath
        roots = [P(home) / '.steam/steam', P(home) / '.local/share/Steam',
                 P(home) / '.var/app/com.valvesoftware.Steam/.local/share/Steam',
                 P(home) / 'Library/Application Support/Steam', P(home) / 'Steam']
    read = read or (lambda p: Path(p).read_text(errors='replace'))
    libs = []
    for root in roots:
        if not exists(str(root)):
            continue
        libs.append(root)
        vdf = root / 'steamapps' / 'libraryfolders.vdf'
        try:
            text = read(str(vdf))
        except OSError:
            continue
        for m in re.finditer(r'"path"\s+"((?:[^"\\]|\\.)*)"', text):
            libs.append(P(m.group(1).replace('\\\\', '\\')))
    return list(dict.fromkeys(libs))


def exe_candidates(ctx, exists=os.path.isfile, dir_exists=os.path.isdir, read=None):
    found = []
    for lib in steam_libraries(ctx, dir_exists, read):
        p = lib / 'steamapps' / 'common' / 'Skyrim Special Edition' / 'SkyrimSE.exe'
        if exists(str(p)):
            found.append(str(p))
    # The SteamCMD route installs into .local/contrib/game; its depot-only variant writes under
    # SteamCMD's own steamapps/content folder.
    own = [ctx.private / 'game' / 'SkyrimSE.exe']
    own += [base / 'contrib' / 'game' / 'SkyrimSE.exe' for base in main_local_fallback(ctx)]
    own += [d / 'steamapps' / 'content' / f'app_{STEAM_APP_ID}' / f'depot_{STEAM_EXE_DEPOT}' / 'SkyrimSE.exe'
            for d in steamcmd_dirs(ctx)]
    for p in own:
        if exists(str(p)):
            found.append(str(p))
    return list(dict.fromkeys(found))


def inspect_exe(path, target):
    p = Path(path)
    if not p.is_file():
        return {'status': 'missing', 'path': str(path)}
    digest = sha256_file(p)
    return {'status': 'ok' if digest == target['image_sha256'] else 'wrong-build', 'path': str(p),
            'sha256': digest, 'version': pe_version(p)}


def wrong_build_message(info, target, redact=False):
    observed = ('does not match' if redact else
                f'is version {info.get("version") or "unknown"} (SHA-256 {info["sha256"][:16]}...), not')
    return (f'{info["path"]} {observed} '
            f'the pinned target {target["version"]} from {target["store"]} '
            f'(SHA-256 {target["image_sha256"][:16]}...). The comparator needs exactly that file; '
            'see docs/contributing-agent.md, "The game executable".')


def steamcmd_route(ctx):
    """The official SteamCMD steps for the contributor's own account; credentials are typed into
    SteamCMD by the contributor and never pass through this tool."""
    where = ctx.private / 'game'
    return ['steamcmd   (then type these at its Steam> prompt; it asks for your password itself)',
            '@sSteamCmdForcePlatformType windows',
            f'force_install_dir "{where}"',
            'login <your-steam-login>',
            f'app_update {STEAM_APP_ID} validate      (whole game, about 13 GB; the route the maintainer used)',
            f'  or: download_depot {STEAM_APP_ID} {STEAM_EXE_DEPOT} {STEAM_EXE_MANIFEST}      (only the executable, '
            'about 38 MB; not yet tried by the project; SteamCMD prints the folder it wrote)',
            'quit',
            f'then: {ctx.cli} setup      (it looks in both places; or pass --exe "<path to SkyrimSE.exe>")']


def steamcmd_dirs(ctx):
    """Where SteamCMD keeps its own files on this platform (its depot downloads land beneath)."""
    home = Path(ctx.env.get('USERPROFILE' if ctx.windows else 'HOME') or str(Path.home()))
    if ctx.windows:
        return [Path(r'C:\steamcmd')]
    return [home / 'Library/Application Support/Steam', home / '.steam/steamcmd', home / '.steam/steam',
            home / '.local/share/Steam', home / 'Steam', Path('/usr/games/steamcmd')]


def resolve_exe(ctx, target, given=None):
    """(info, how) for the configured or discovered executable; info None when nothing is found."""
    cfg = load_config(ctx)
    for how, path in (('--exe', given), ('SR_SKYRIM_EXE', ctx.env.get('SR_SKYRIM_EXE')), ('config', cfg.get('exe'))):
        if path:
            ctx.remember_path(path, '<exe>')
            return inspect_exe(path, target), how
    paths = exe_candidates(ctx)
    for path in paths:
        ctx.remember_path(path, '<exe>')
    infos = [inspect_exe(p, target) for p in paths]
    good = [i for i in infos if i['status'] == 'ok']
    if good:
        return good[0], 'found in a Steam library'
    if infos:
        return infos[0], 'found in a Steam library'
    return None, None


def require_exe(ctx, target):
    info, _how = resolve_exe(ctx, target)
    if info is None or info['status'] == 'missing':
        raise Stop(MISSING, 'SkyrimSE.exe not configured or not found', f'{ctx.cli} setup --exe "<path to SkyrimSE.exe>"')
    if info['status'] != 'ok':
        raise Stop(MISSING, wrong_build_message(info, target, ctx.redact), f'{ctx.cli} doctor')
    return info


# ------------------------------------------------------------------ toolchain

def recipe_constants(repo):
    """Pins of the verifier toolchain recipe, read through the shared accessor so the contributor
    path cannot drift from the recipe the project's verifiers use."""
    import recipe_pins
    try:
        return recipe_pins.read_pins(repo)
    except recipe_pins.MissingPin as exc:
        raise Stop(USAGE, str(exc))


def pinned_hashes(repo, recipe=None):
    folder = Path(repo) / 'tools/verifier'
    pin_file = folder / 'pinned.sha256'
    if recipe:
        try:
            compiler = json.loads((Path(repo) / recipe).read_text())['compiler']
            digest = compiler['binary_sha256']
            version = re.match(r'\d+\.\d+\.\d+\b', compiler.get('version', ''))
        except (OSError, ValueError, KeyError, TypeError) as exc:
            raise Stop(UNIT, f'invalid compiler pin in {recipe}') from exc
        if version and (alternate := folder / 'pinned' / (version[0] + '.sha256')).is_file():
            pin_file = alternate
    out = {}
    for line in pin_file.read_text().splitlines():
        parts = line.split()
        if len(parts) == 2:
            out[parts[1]] = parts[0]
    if recipe and out.get('cl.exe') != digest:
        raise Stop(UNIT, f'no matching toolchain pins for {recipe}')
    return out


def toolchain_dirs(ctx, kind):
    """Places a toolchain may live, in order: this checkout's private store (`contrib/<kind>`, then
    `toolchains/<kind>*`), then the same two under the main checkout's .local when this is a linked
    worktree, whose own ignored .local lacks what was set up once in the main one."""
    bases = []
    try:
        bases.append(ctx.local)
    except Stop:
        pass
    main = main_checkout_local(ctx.repo)
    if main is not None and main not in bases:
        bases.append(main)
    out = [ctx.private / kind]
    for base in bases:
        for cand in [base / 'contrib' / kind, *sorted((base / 'toolchains').glob(kind + '*'))]:
            if cand not in out:
                out.append(cand)
    return out


def toolchain_candidates(ctx):
    cfg = load_config(ctx)
    explicit = ctx.env.get('SR_MSVC') or cfg.get('msvc')
    return [Path(explicit)] if explicit else toolchain_dirs(ctx, 'msvc')


def toolchain_root(ctx):
    candidates = toolchain_candidates(ctx)
    for cand in candidates:
        if toolchain_bins(cand):
            return cand
    return candidates[0]


def toolchain_bins(root):
    return sorted(Path(root).glob('VC/Tools/MSVC/*/bin/Hostx64/x64'))


def sdk_include_dirs(ctx, root, sdk_version):
    """Windows SDK include directories for a native compile (the msvc-wine wrapper sets its own)."""
    bases = [Path(root) / 'Windows Kits' / '10' / 'Include',
             Path(ctx.env.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Windows Kits' / '10' / 'Include']
    for base in bases:
        versions = sorted(p for p in base.glob('10.*') if p.is_dir()) if base.is_dir() else []
        pick = [p for p in versions if p.name.startswith(sdk_version)] or versions[-1:]
        if pick:
            return base.parent.parent.parent, [pick[0] / d for d in ('ucrt', 'shared', 'um', 'winrt')]
    return None, []


def check_toolchain(ctx, repo=None, recipe=None):
    """State of the compiler: 'override' (a test stand-in), 'ok', 'missing', 'mismatch' or 'no-wrapper'."""
    override = ctx.env.get('SR_CONTRIB_COMPILER')
    if override:
        return {'status': 'override', 'command': json.loads(override) if override.startswith('[') else [override],
                'pinned': False}
    candidates = toolchain_candidates(ctx)
    fallback = {'status': 'missing', 'root': str(candidates[0]), 'pinned': False}
    pins = None
    for root in candidates:
        ctx.remember_path(root, '<msvc>')
        for bin_dir in reversed(toolchain_bins(root)):
            if pins is None:
                pins = pinned_hashes(repo or ctx.repo, recipe)
            bad = [name for name, digest in pins.items()
                   if not (bin_dir / name).is_file() or sha256_file(bin_dir / name) != digest]
            status = ('mismatch' if bad else 'no-wrapper'
                      if not ctx.windows and not (root / 'bin/x64/cl').is_file() else 'ok')
            info = dict(root=str(root), bin=str(bin_dir), pinned=not bad, status=status,
                        flavour='native' if ctx.windows else 'wine')
            if bad:
                info['differing'] = bad
            if status == 'ok':
                return info
            if fallback['status'] == 'missing' or (not bad and not fallback['pinned']):
                fallback = info
    return fallback


# ------------------------------------------------------------------ compiling a unit

def classify_windows(opened, repo, tool_roots):
    """Split /showIncludes paths of a native Windows compile into repository files (exact spelling,
    POSIX form), a toolchain count and anything else."""
    def norm(p):
        drive, tail = ntpath.splitdrive(str(p).replace('/', '\\'))
        path = drive + '\\'
        for part in tail.split('\\'):
            if part:
                path = ntpath.realpath(ntpath.join(path, part))
        return path
    repo_n = norm(repo)
    roots = [norm(r).lower().rstrip('\\') + '\\' for r in tool_roots if r]
    files, outside, tools = set(), [], 0
    for raw in opened:
        path = raw.replace('/', '\\')
        drive, tail = ntpath.splitdrive(path)
        if drive and not tail.startswith('\\'):
            outside.append(raw)
            continue
        p = norm(ntpath.join(repo_n, path))
        low = p.lower()
        if any(low.startswith(r) for r in roots):
            tools += 1
        elif low.startswith(repo_n.lower().rstrip('\\') + '\\') and '\\..' not in low:
            files.add(p[len(repo_n.rstrip('\\')) + 1:].replace('\\', '/'))
        else:
            outside.append(raw)
    return sorted(files), tools, outside


def compile_unit(ctx, root, compiled, recipe_rel, out_dir, tool):
    """Compile one unit with the recipe's flags and the build-path checks of the verifier
    (tools/verifier/unit_build.py): cleared environment, /showIncludes equal to the closure."""
    import unit_build
    from source_digest import include_closure, recipe_flag_problem
    # The compiler reports opened files from the real working directory, so compare against that.
    from digest_v2 import tu_digest
    # The compiler reports opened files from the real working directory, so compare against that.
    root, out_dir = Path(root).resolve(), Path(out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    try:
        closure = include_closure(root, compiled)
    except (ValueError, OSError) as exc:
        raise Stop(UNIT, f'translation unit: {exc}', 'fix the include named above; docs/drafter-card.md, "Source rules"')
    recipe_bytes = (root / recipe_rel).read_bytes()
    recipe = json.loads(recipe_bytes)
    problem = recipe_flag_problem(recipe.get('flags'))
    if problem:
        raise Stop(UNIT, f'recipe flags: {problem}')
    env = unit_build.clean_env(ctx.env)
    env.update(VSLANG='1033', WINEDEBUG='-all')  # English /showIncludes notes; quiet Wine
    obj = out_dir / 'candidate.obj'
    if obj.exists():
        obj.unlink()
    status = tool['status']
    if status == 'override':
        cmd, roots, flavour = list(tool['command']), [], 'override'
    elif status != 'ok':
        raise Stop(MISSING, f'compiler toolchain is {status}', f'{ctx.cli} setup')
    elif tool['flavour'] == 'wine':
        msvc = Path(tool['root'])
        wrapper = unit_build.wrapper_settings(msvc, env)
        if not same_file(wrapper['BINDIR'], tool['bin']):
            raise Stop(MISSING, 'the compiler wrapper selects a different toolset from the recipe pin',
                       f'{ctx.cli} doctor')
        problem = unit_build.include_problem(wrapper['INCLUDE'], wrapper['BASE'])
        if problem:
            raise Stop(UNIT, problem)
        cmd, roots, flavour = [str(msvc / 'bin/x64/cl')], [wrapper['BASE'][2:].replace('\\', '/')], 'wine'
    else:
        sdk_root, includes = sdk_include_dirs(ctx, tool['root'], recipe_constants(ctx.repo)['SDK_VERSION'])
        vc_include = Path(tool['bin']).parents[2] / 'include'
        env['INCLUDE'] = ';'.join(str(p) for p in [vc_include, *includes])
        sdk_version = includes[0].parent.name if includes else recipe_constants(ctx.repo)['SDK_VERSION']
        env['LIB'] = ';'.join(str(p) for p in (Path(tool['bin']).parents[2] / 'lib/x64',
            (includes[0].parents[2] if includes else Path(tool['root']) / 'Windows Kits/10') / 'Lib' / sdk_version / 'ucrt/x64',
            (includes[0].parents[2] if includes else Path(tool['root']) / 'Windows Kits/10') / 'Lib' / sdk_version / 'um/x64'))
        cmd, roots, flavour = [str(Path(tool['bin']) / 'cl.exe')], [tool['root'], sdk_root], 'native'
    cmd = cmd + recipe['flags'] + [unit_build.SHOW_INCLUDES, f'/Fo{obj}', compiled]
    try:
        proc = ctx.run(cmd, cwd=root, env=env, capture_output=True, text=True, errors='replace',
                       timeout=COMPILE_TIMEOUT)
    except subprocess.TimeoutExpired:
        raise Stop(COMPILE, f'compile took longer than {COMPILE_TIMEOUT} s and was stopped')
    except OSError as exc:
        raise Stop(MISSING, f'cannot run the compiler: {exc}', f'{ctx.cli} doctor')
    opened, rest = unit_build.parse_show_includes(proc.stdout)
    (out_dir / 'compile.log').write_text(ctx.scrub('\n'.join(rest) + '\n' + (proc.stderr or '')))
    if proc.returncode != 0 or not obj.is_file():
        errors = [line.strip() for line in rest if re.search(r'\berror [A-Z]+\d+', line)][:8]
        raise Stop(COMPILE, 'compile failed', 'fix the errors and run compare again',
                   errors=errors, log=str(out_dir / 'compile.log'))
    if flavour == 'native' or (flavour == 'override' and ctx.windows):
        repo_files, tool_count, outside = classify_windows(opened, root, roots)
    else:
        repo_files, tool_count, outside = unit_build.classify_includes(opened, root, Path(roots[0]) if roots
                                                                       else Path('/nonexistent-toolchain'))
    if outside and ctx.platform == 'darwin':
        outside = fold_case_includes(outside, root, closure, repo_files)
    if outside:
        raise Stop(UNIT, f'{len(outside)} included file(s) outside the repository and the toolchain: '
                   + ', '.join(outside[:3]), 'include only reconstruction/ headers and the toolchain\'s own',
                   outside=outside[:20])
    diff = unit_build.closure_difference(repo_files, compiled, closure)
    if diff:
        raise Stop(UNIT, diff, 'move or remove the include named above')
    digest = tu_digest(root, closure)
    recipe_sha = hashlib.sha256(recipe_bytes).hexdigest()
    record = {'build_record_schema': 1, 'source_revision': digest, 'source_path': compiled,
              'recipe_sha256': recipe_sha, 'object_sha256': sha256_file(obj),
              'environment': {'cleared': list(unit_build.CLEARED_ENV), 'added_flags': [unit_build.SHOW_INCLUDES],
                              'compiler': flavour, 'toolchain_files': tool_count}}
    (out_dir / 'build-record.json').write_text(json.dumps(record, indent=2) + '\n')
    return {'object': obj, 'closure': closure, 'digest': digest, 'recipe_sha256': recipe_sha,
            'build_record': out_dir / 'build-record.json', 'compiler': flavour}


def fold_case_includes(outside, root, closure, repo_files):
    """Entries of `outside` that are closure files spelled in another case, moved into repo_files.

    macOS volumes are usually case-insensitive and Wine there may report an opened header in lower
    case. Only an exact case-insensitive match to a file of the derived closure is accepted, and
    only when the reported path opens that very file (same device and inode), so a file outside the
    repository, or a different file whose name merely folds to a closure name, still fails."""
    base = str(root).replace('\\', '/')
    if len(base) > 2 and base[1] == ':':
        base = base[2:]
    prefix = base.rstrip('/').lower() + '/'
    by_lower = {c.lower(): c for c in closure}
    rest = []
    for raw in outside:
        path = raw.replace('\\', '/')
        if len(path) > 2 and path[1] == ':':
            path = path[2:]
        # A relative include prints as `<dir>/../<other>/X.h`; fold the dots before looking it up, then
        # let the file system confirm that the original spelling opens that very file.
        folded = posixpath.normpath(path)
        hit = by_lower.get(folded.lower()[len(prefix):]) if folded.lower().startswith(prefix) else None
        if hit and same_file(path, os.path.join(str(root), hit)):
            if hit not in repo_files:
                repo_files.append(hit)
        else:
            rest.append(raw)
    repo_files.sort()
    return rest


def same_file(a, b):
    """True when both paths open one existing file; a missing or unreadable path is not a match."""
    try:
        return os.path.samefile(a, b)
    except OSError:
        return False


# ------------------------------------------------------------------ the local pack

def public_names(repo, data):
    """{rva: [names]} from the public symbol map and the inventory, for reading a listing."""
    from bind import fallback_qualified
    names = {}
    target = target_manifest(repo)
    smap = Path(repo) / 'reports' / target['build_id'] / 'symbol-map.json'
    if smap.is_file():
        for name, entry in json.loads(smap.read_text()).get('symbols', {}).items():
            if isinstance(entry, dict) and isinstance(entry.get('rva'), int):
                names.setdefault(entry['rva'], []).append(fallback_qualified(name) or name)
    for fn in data['functions']:
        if fn.get('name'):
            names.setdefault(fn['rva'], []).insert(0, fn['name'])
    return {k: list(dict.fromkeys(v)) for k, v in names.items()}


def add_funclet_references(image_bytes, rva, refs, names, img=None):
    """Add the call/jump targets of the function's EH funclets to `refs`; a note on failure, else None.

    An unwind funclet that jumps to an out-of-line destructor (a scope guard, a local visitor) is
    outside the function's own range, so without this the reference table never lists that target
    and no bind hint can name it. Rows carry `in_funclet` and the offset from the function start.
    """
    try:
        import export_pack
        img = img or export_pack.ImageFacts(blob=image_bytes)
        entry = img.pdata_at.get(rva)
        if entry is None:
            return None
        end, parts, _split = export_pack.function_extent(img, rva, entry[0])
        own = [(rva, entry[0], entry[1])] + parts
        funclets = sorted((export_pack.eh_facts(img, {'by_rva': {}}, [], rva, own)).get('funclets', {}).items())
        for row in export_pack.funclet_branch_refs(img, rva, funclets):
            ref = refs.get(row['target'])
            if ref is None:
                ref = refs[row['target']] = {'target_rva': row['target'], 'kind': 'call-or-jump', 'at': [],
                                             'in_funclet': True,
                                             'community_names': [{'name': n, 'kind': 'name'}
                                                                 for n in names.get(row['target'], [])]}
            ref['at'].append(row['offset'] + row['operand_offset'])
    except Exception as exc:  # a reading aid: the pack is still usable without the funclet rows
        return f'funclet references not added: {type(exc).__name__}'
    return None


def build_pack(image_bytes, rva, size, identity, names):
    """Pack of one function from the image: its bytes, instruction boundaries and the targets of its
    calls, jumps and rip-relative references with any public name. Private (game-derived)."""
    from pecoff import PeImage
    import x64
    image = PeImage(image_bytes)
    _sec, code = image.read(rva, size, 'function')
    rows, refs, note = [], {}, None
    try:
        insns = x64.decode_range(code, 0, size, rva)
    except x64.DecodeError as exc:
        insns, note = [], f'instruction decoding stopped: {exc}'
    for off, ins in insns:
        field, target, kind = None, None, None
        if ins.rel is not None and not (rva <= ins.target < rva + size):
            field, target, kind = ins.rel, ins.target, 'call-or-jump'
        elif ins.rip is not None:
            field, target, kind = (ins.rip, 4), ins.rip_target, 'data-or-code'
        rows.append({'offset': off, 'length': ins.length, 'field': field, 'target': target})
        if target is not None:
            r = refs.setdefault(target, {'target_rva': target, 'kind': kind, 'at': [],
                                         'community_names': [{'name': n, 'kind': 'name'} for n in names.get(target, [])]})
            r['at'].append(off + field[0])
    note = add_funclet_references(image_bytes, rva, refs, names) or note
    pdata = [e for e in image.runtime_functions() if rva <= e[0] < rva + size]
    return {'pack_schema': 1, 'source': 'local-exe', 'identity': dict(identity, name_how=None),
            'bytes_hex': code.hex(), 'instructions': rows, 'references': list(refs.values()),
            'unwind_entries': len(pdata), 'note': note}


def pack_listing(pack):
    """A readable byte listing: offset, bytes (relocated fields as ..) and reference targets."""
    code = bytes.fromhex(pack['bytes_hex'])
    lines = [f'# {pack["identity"].get("community_name")} RVA 0x{pack["identity"]["rva"]:x} '
             f'{pack["identity"]["size"]} bytes; private, never paste or upload']
    for row in pack['instructions']:
        raw = code[row['offset']:row['offset'] + row['length']]
        cells = [f'{b:02x}' for b in raw]
        if row['field']:
            for i in range(row['field'][0], row['field'][0] + row['field'][1]):
                cells[i] = '..'
        text = f'  +0x{row["offset"]:03x}  {" ".join(cells):<45}'
        if row['target'] is not None:
            ref = next(r for r in pack['references'] if r['target_rva'] == row['target'])
            names = ', '.join(c['name'] for c in ref['community_names'][:2]) or 'no public name'
            text += f' -> 0x{row["target"]:x} {names}'
        lines.append(text.rstrip())
    for ref in pack['references']:
        if ref.get('in_funclet'):
            names = ', '.join(c['name'] for c in ref['community_names'][:2]) or 'no public name'
            where = ', '.join(f'+0x{at:x}' for at in ref['at'])
            lines.append(f'# EH funclet call/jump at {where} -> 0x{ref["target_rva"]:x} {names}')
    if pack.get('note'):
        lines.append(f'# {pack["note"]}')
    return '\n'.join(lines) + '\n'


def find_objdump(ctx):
    for name in (ctx.env.get('SR_OBJDUMP'), 'llvm-objdump', '/opt/homebrew/opt/llvm/bin/llvm-objdump',
                 '/usr/local/opt/llvm/bin/llvm-objdump', r'C:\Program Files\LLVM\bin\llvm-objdump.exe'):
        if name and (path := ctx.which(name) or (name if os.path.isfile(name) else None)):
            if path != 'llvm-objdump':
                ctx.remember_path(path, '<llvm-objdump>')
            return path
    return None


def write_pack(ctx, exe, fn, names):
    rva, size = fn['rva'], fn['size']
    dest = ctx.private / 'packs' / fn['build_id'] / f'0x{rva:x}'
    dest.mkdir(parents=True, exist_ok=True)
    identity = {'build_id': fn['build_id'], 'rva': rva, 'size': size, 'community_name': fn.get('name'),
                'name_origin': fn.get('name_origin')}
    pack = build_pack(Path(exe).read_bytes(), rva, size, identity, names)
    (dest / 'pack.json').write_text(json.dumps(pack, indent=1) + '\n')
    (dest / 'bytes.txt').write_text(pack_listing(pack))
    objdump = find_objdump(ctx)
    if objdump:
        import disasm
        try:
            rows = disasm.target_rows(objdump, exe, rva, size)
            # The `+0x.. MNEMONIC operands` form is what tools/verifier/bind.py reads for destructors.
            (dest / 'listing.txt').write_text(''.join(f'  +0x{r[0]:03x}  {r[2].upper()}\n' for r in rows))
        except (OSError, ValueError, subprocess.SubprocessError):
            pass
    if load_config(ctx).get('decompiler'):
        import contrib_decompiler
        contrib_decompiler.decompile(ctx, rva, dest, required=False)
    return dest, pack


import claims as batch_claims  # noqa: E402


# ------------------------------------------------------------------ GitHub claims

class Offline(Exception):
    pass


class GitHub:
    """Open issues and pull requests of the upstream repository, through `gh` when it is signed in,
    else the public REST API (read only); creating a claim without `gh` gives a prefilled link."""

    def __init__(self, ctx):
        self.ctx = ctx
        self.repo = ctx.env.get('SR_UPSTREAM') or UPSTREAM
        self._gh = None

    def gh(self):
        if self._gh is None:
            exe = self.ctx.which('gh')
            ok = bool(exe) and self.ctx.run([exe, 'auth', 'status'], capture_output=True, text=True, timeout=20).returncode == 0
            self._gh = exe if ok else False
            if not ok:
                self.ctx.say('GitHub: run gh auth login for automatic claims and higher API quota; browser/manual submission remains available.')
        return self._gh or None

    def api(self, path):
        if self.ctx.env.get('SR_CONTRIB_OFFLINE'):
            raise Offline('offline mode (SR_CONTRIB_OFFLINE)')
        gh = self.gh()
        if gh:
            proc = self.ctx.run([gh, 'api', path], capture_output=True, text=True)
            if proc.returncode != 0:
                detail = proc.stderr.strip()[:200]
                if 'rate limit' in detail.lower():
                    raise Offline('GitHub rate-limit exhausted; run gh auth login or retry after the quota resets')
                raise Offline(detail)
            return json.loads(proc.stdout)
        req = urllib.request.Request(f'https://api.github.com/{path}', headers={
            'Accept': 'application/vnd.github+json', 'User-Agent': 'skyrim-research-contrib'})
        try:
            with urllib.request.urlopen(req, timeout=20) as resp:
                return json.loads(resp.read())
        except urllib.error.HTTPError as exc:
            if exc.code == 429 or (exc.code == 403 and exc.headers.get('X-RateLimit-Remaining') == '0'):
                raise Offline('GitHub rate-limit exhausted; run gh auth login or retry after the quota resets') from None
            raise Offline(f'GitHub HTTP {exc.code}; check gh auth login and repository access') from None
        except (urllib.error.URLError, OSError, ValueError) as exc:
            raise Offline(f'GitHub offline or transport unavailable: {exc}') from None

    # Enough pages for any plausible number of open items; past it the list is reported incomplete
    # rather than silently treated as complete.
    MAX_PAGES = 100

    def open_items(self, refresh=False, *, build=None, entries=None):
        """Open issues and pull requests naming RVAs, optionally scoped to a pending claim."""
        wanted = batch_claims.ClaimIntervals(entries) if entries is not None else None
        cache = self.ctx.private / 'claims-cache.json'
        if wanted is None and not refresh and not self.ctx.env.get('SR_CONTRIB_OFFLINE'):
            if getattr(self, '_items', None) is not None:
                return self._items
            try:
                saved = json.loads(cache.read_text())
                if saved['repo'] == self.repo and 0 <= time.time() - saved['fetched'] < batch_claims.TTL:
                    self._items = batch_claims.ClaimIndex(saved['items'])
                    return self._items
            except (OSError, ValueError, KeyError, TypeError):
                pass
        items = []
        for page in range(1, self.MAX_PAGES + 1):
            batch = self.api(f'repos/{self.repo}/issues?state=open&per_page=100&page={page}')
            if page == self.MAX_PAGES and len(batch) == 100:
                raise Offline(f'more than {100 * self.MAX_PAGES} open items; claims cannot all be checked')
            for it in batch:
                parsed = batch_claims.parse_issue(it)
                if not parsed['entries']:
                    continue
                if wanted is not None and (parsed['build_id'] not in (None, build)
                                           or not any(wanted.overlaps(a, b) for a, b in parsed['entries'])):
                    continue
                it['updated_at'] = batch_claims.activity(self.api, self.repo, it)
                items.append(batch_claims.parse_issue(it))
            if len(batch) < 100:
                break
        out = batch_claims.ClaimIndex(items)
        if wanted is not None:
            return out
        self._items = out
        try:
            cache.parent.mkdir(parents=True, exist_ok=True)
            cache.write_text(json.dumps(dict(repo=self.repo, fetched=time.time(), items=items)))
        except OSError:
            pass
        return out

    def user(self):
        cfg = load_config(self.ctx)
        if self.ctx.env.get('SR_GITHUB_USER') or cfg.get('github_user'):
            return self.ctx.env.get('SR_GITHUB_USER') or cfg['github_user']
        gh = self.gh()
        if gh:
            proc = self.ctx.run([gh, 'api', 'user', '-q', '.login'], capture_output=True, text=True)
            if proc.returncode == 0 and proc.stdout.strip():
                return proc.stdout.strip()
        return None

    def feedback(self):
        import contrib_feedback
        return contrib_feedback.collect(self)

    def create_issue(self, title, body):
        gh = self.gh()
        if not gh:
            return None
        if len(body) >= batch_claims.BODY_LIMIT:
            raise Stop(USAGE, 'refusing issue body at or above 60,000 characters')
        proc = self.ctx.run([gh, 'issue', 'create', '--repo', self.repo, '--title', title,
                             '--body-file', '-'], input=body, capture_output=True, text=True)
        if proc.returncode == 0:
            return proc.stdout.strip().splitlines()[-1]
        raise Stop(NETWORK, 'gh issue create failed')

    def new_issue_link(self, title, body):
        q = urllib.parse.urlencode({'template': 'claim.yml', 'title': title, 'body': body})
        return f'https://github.com/{self.repo}/issues/new?{q}'

    def comment(self, number, body):
        gh = self.gh()
        if gh:
            self.ctx.run([gh, 'issue', 'comment', str(number), '--repo', self.repo, '--body', body],
                         capture_output=True, text=True)
            return True
        return False

    def close(self, number, body):
        gh = self.gh()
        if gh:
            self.ctx.run([gh, 'issue', 'close', str(number), '--repo', self.repo, '--comment', body],
                         capture_output=True, text=True)
            return True
        return False


def issue_number(url):
    m = re.search(r'/(?:issues|pull)/(\d+)', url or '')
    return int(m.group(1)) if m else 1 << 62


def claim_state(items, me, now=None):
    """Split claims on one function into mine, fresh claims by others and lapsed ones."""
    now = now or datetime.now(timezone.utc)
    mine, fresh, stale = [], [], []
    for it in items:
        if me and me in (it.get('assignees') or [it.get('author')]):
            mine.append(it)
            continue
        try:
            updated = datetime.fromisoformat(str(it.get('updated_at')).replace('Z', '+00:00'))
        except ValueError:
            updated = now
        (stale if now - updated >= batch_claims.CLAIM_LAPSE else fresh).append(it)
    return mine, fresh, stale


def local_claims(ctx):
    try:
        return json.loads((ctx.private / 'claims.json').read_text())
    except (OSError, ValueError):
        return {}


def save_local_claim(ctx, rva, record):
    save_local_claims(ctx, [rva], record)


def save_local_claims(ctx, addresses, record):
    claims = local_claims(ctx)
    claims.update((f'0x{rva:x}', record) for rva in addresses)
    (ctx.private).mkdir(parents=True, exist_ok=True)
    (ctx.private / 'claims.json').write_text(json.dumps(claims, indent=2, sort_keys=True) + '\n')


# ------------------------------------------------------------------ unit skeleton and task

def skeleton(fn, cls, method, area, drafted_by, recipe, code_origin=None):
    """Compatibility entry point for the shared declaration renderer."""
    from unit_skeleton import skeleton as render, SkeletonError
    try:
        return render(fn, cls, method, area, drafted_by, recipe, code_origin=code_origin)
    except SkeletonError as exc:
        raise Stop(USAGE, str(exc)) from None


def contrib_profile(ctx, given=None):
    """The profile for this contributor: the flag, else the remembered one, else the default."""
    name = given or load_config(ctx).get('profile') or profiles.DEFAULT
    if name not in CONTRIB_PROFILES:
        raise Stop(USAGE, f'--profile must be one of {", ".join(CONTRIB_PROFILES)}, not {name!r}')
    return profiles.get(name)


def task_id_for(cls, practice=False):
    # A practice run of an accepted unit gets its own directory, so it never mixes its runs or
    # functions into a real task on the same class and is never picked as "the" task to submit.
    return ('practice-' if practice else 'contrib-') + re.sub(r'[^a-z0-9]+', '-', cls.lower()).strip('-')


def task_dir(ctx, tid):
    return ctx.private / 'tasks' / tid


def changed_paths(ctx):
    """Repository paths with uncommitted changes (tracked or new), POSIX form; empty outside git."""
    proc = ctx.run(['git', 'status', '--porcelain', '--untracked-files=all'], cwd=ctx.repo,
                   capture_output=True, text=True)
    if proc.returncode != 0:
        return set()
    return {line[3:].split(' -> ')[-1].strip().strip('"') for line in proc.stdout.splitlines() if len(line) > 3}


def pick_current_task(ctx, pick):
    """Use unit and worktree evidence to narrow the choices in a shared task store."""
    present = [(d, t) for d, t in pick if (ctx.repo / t['compiled']).is_file()]
    pick = present or pick
    changed = changed_paths(ctx)
    branch = git(ctx, 'symbolic-ref', '--quiet', '--short', 'HEAD', check=False)
    worktree = str(ctx.repo.resolve())
    for matches in (
        lambda d, t: t['compiled'] in changed or bool(set(t.get('contrib', {}).get('unit', [])) & changed),
        lambda d, t: bool(branch) and branch in (t.get('contrib', {}).get('branch'),
                                                f'contrib/{d.name.removeprefix("contrib-")}'),
        lambda d, t: t.get('contrib', {}).get('worktree') == worktree,
    ):
        pick = [(d, t) for d, t in pick if matches(d, t)] or pick
        if len(pick) == 1:
            return pick[0]
    raise Stop(USAGE, 'several tasks fit this worktree; name one: '
               + ', '.join(f'{d.name} ({t["compiled"]})' for d, t in pick))


def task_files(ctx):
    """Every task.json: this store's, then the main checkout's for ids this one lacks."""
    bases = [ctx.private / 'tasks'] + [b / 'contrib' / 'tasks' for b in main_local_fallback(ctx)]
    seen, out = set(), []
    for base in bases:
        for path in sorted(base.glob('*/task.json')) if base.is_dir() else []:
            if path.parent.name not in seen:
                seen.add(path.parent.name)
                out.append(path)
    return out


def load_task(ctx, ident=None, pick_current=False):
    """The contributor task named by id, RVA or unit; the only one when none is named (with
    `pick_current`, the current one when several exist)."""
    tasks = task_files(ctx)
    loaded = [(p.parent, json.loads(p.read_text())) for p in tasks]
    if ident:
        try:
            rva = parse_rva(ident) if re.fullmatch(r'(0x)?[0-9a-fA-F]+', ident) else None
        except Stop:
            rva = None
        pick = [(d, t) for d, t in loaded if d.name == ident or ident in (t['compiled'],)
                or (rva is not None and any(parse_rva(f['rva']) == rva for f in t['functions']))]
    else:
        real = [(d, t) for d, t in loaded if not t.get('contrib', {}).get('practice')]
        pick = real or loaded
    if not pick:
        raise Stop(USAGE, 'no contributor task' + (f' for {ident}' if ident else ''), f'{ctx.cli} start 0x<rva>')
    if len(pick) > 1:
        if pick_current and not ident:
            return pick_current_task(ctx, pick)
        raise Stop(USAGE, 'several tasks: name one (' + ', '.join(d.name for d, _ in pick) + ')')
    return pick[0]


def symbol_map_path(repo, build_id):
    """The public symbol map, or a Stop that names the file and the sparse-checkout fix."""
    path = Path(repo) / 'reports' / build_id / 'symbol-map.json'
    if not path.is_file():
        raise Stop(MISSING, f'{path.relative_to(repo).as_posix()} is missing; a sparse checkout that excludes reports/ does not have it',
                   "git sparse-checkout set --no-cone '/*' '!/site/'   (then run the command again)")
    return path


def readiness_symbol_map(ctx, build_id):
    try:
        return json.loads(symbol_map_path(ctx.repo, build_id).read_text())
    except Stop:
        # A sparse checkout can rank targets without materializing all of reports/.
        blob = git(ctx, 'show', f'HEAD:reports/{build_id}/symbol-map.json', check=False)
        if blob:
            return json.loads(blob)
        raise


def refresh_symbols(ctx, tdir, build_id):
    """symbols.json = the public map plus the entries bind added for this task earlier."""
    public = json.loads(symbol_map_path(ctx.repo, build_id).read_text())
    path = tdir / 'symbols.json'
    try:
        private = json.loads(path.read_text())
    except (OSError, ValueError):
        private = {}
    extra = {k: v for k, v in (private.get('symbols') or {}).items() if k not in public['symbols']}
    merged = dict(public)
    merged['symbols'] = dict(public['symbols'], **extra)
    path.write_text(json.dumps(merged, indent=2) + '\n')
    return extra


# ------------------------------------------------------------------ commands

def cmd_doctor(ctx, args):
    target = target_manifest(ctx.repo)
    checks, nxt = [], None

    def add(name, ok, detail, fix=None, required=True):
        nonlocal nxt
        checks.append({'check': name, 'ok': ok, 'required': required, 'detail': detail, 'fix': fix})
        mark = 'ok  ' if ok else ('MISS' if required else 'opt ')
        ctx.say(f'{mark} {name}: {detail}')
        if not ok and required and nxt is None:
            nxt = fix
    add('python', sys.version_info >= (3, 11), sys.version.split()[0], 'use ./sr (Windows: .\\sr.cmd), which finds Python 3.11+; or install Python 3.11 or newer')
    git_path = ctx.which('git')
    add('git', bool(git_path), git_path or 'not found', 'install git')
    shared = ctx.env.get('SR_LOCAL_DIR')
    if shared:
        ctx.say(f'note: private files are under {shared} (SR_LOCAL_DIR, or the main worktree\'s .local)')
    info, how = resolve_exe(ctx, target, getattr(args, 'exe', None))
    if info is None:
        add('game executable', False, 'SkyrimSE.exe not found in a Steam library',
            f'{ctx.cli} setup --exe "<path to SkyrimSE.exe>"   (or set SR_SKYRIM_EXE to its path)')
    elif info['status'] != 'ok':
        add('game executable', False, wrong_build_message(info, target, ctx.redact) if info['status'] == 'wrong-build'
            else f'{info["path"]} does not exist', f'{ctx.cli} setup --exe "<path to SkyrimSE.exe>"   (or set SR_SKYRIM_EXE)')
    else:
        add('game executable', True, f'{info["path"]} ({how}) is {target["version"]}, hash pinned')
    tool = check_toolchain(ctx)
    if not ctx.windows:
        if ctx.platform == 'darwin':
            # Only this project's unpacked Wine counts on macOS: a cask install in /Applications
            # carries a quarantine flag and blocks on a Gatekeeper dialog when run headless.
            wine = str(Path(ctx.env.get('SR_WINE_BIN') or private_wine_bin(ctx)) / 'wine') if mac_wine_ready(ctx) else None
            ctx.remember_path(wine, '<wine>')
        else:
            wine = ctx.which('wine64') or ctx.which('wine')
        add('wine', bool(wine), wine or 'not found',
            f'{ctx.cli} setup --yes   (or set SR_WINE_BIN to the folder holding wine)', required=tool['status'] != 'override')
    detail = {'ok': f'cl 19.16.27054 at {tool.get("bin")} matches tools/verifier/pinned.sha256',
              'override': 'SR_CONTRIB_COMPILER stand-in (not the pinned compiler; results cannot be submitted)',
              'missing': f'no MSVC toolchain under {tool.get("root")}',
              'mismatch': f'toolchain at {tool.get("root")} differs from pinned.sha256 ({", ".join(tool.get("differing", []))})',
              'no-wrapper': 'toolset unpacked but the msvc-wine wrapper is missing'}[tool['status']]
    add('compiler', tool['status'] in ('ok', 'override'), detail,
        f'{ctx.cli} setup --accept-microsoft-license   (a person must accept Microsoft\'s licence first; '
        'or set SR_MSVC to an unpacked toolchain)')
    objdump = find_objdump(ctx)
    add('llvm-objdump (readable listing)', bool(objdump), objdump or 'not found; byte listing only',
        f'{ctx.cli} setup --yes', required=False)
    gh = ctx.which('gh')
    add('gh (GitHub CLI)', bool(gh), gh or 'not found; claims and PRs open as browser links', None, required=False)
    missing_src = [r for r, (p, _rev, _l) in COMMUNITY_SOURCES.items() if not local_path(ctx.repo, p, ctx.env).is_dir()]
    add('community sources (label checks)', not missing_src,
        'present' if not missing_src else 'missing: ' + ', '.join(missing_src), f'{ctx.cli} setup --yes', required=False)
    index = sibling_analysis_dir(ctx) / 'fnv_index.jsonl'
    add('sibling source (FNV decompilation, optional)', index.is_file(),
        f'index at {index}' if index.is_file() else 'not fetched; packs carry no sibling pointers',
        f'{ctx.cli} setup --yes', required=False)
    import pdb_facts
    sym_ok, sym_lines = pdb_facts.setup_lines(ctx.repo, ctx.env)
    add('symbol files (2013 map, Fallout 4 PDB)', sym_ok,
        'present, sizes match' if sym_ok else '; '.join(sym_lines),
        f'{ctx.cli} setup (it says what to download), or set SR_SYMBOLS_DIR', required=False)
    ok = all(c['ok'] for c in checks if c['required'])
    if ok and nxt is None:
        tasks = [p for p in task_files(ctx) if p.parent.name.startswith('contrib-')]
        nxt = f'{ctx.cli} compare' if tasks else f'{ctx.cli} go'
    return (OK if ok else MISSING), {'checks': checks, 'platform': ctx.platform}, nxt


def package_manager(ctx):
    if ctx.windows:
        for pm in ('winget', 'choco'):
            if ctx.which(pm):
                return pm
        return None
    for pm in ('brew', 'apt-get', 'dnf', 'pacman', 'zypper'):
        if ctx.which(pm):
            return pm
    return None


# Package names per manager. Wine is needed off Windows (the compiler is a Windows program);
# msitools unpacks the Windows SDK there. LLVM gives llvm-objdump (readable listing, side-by-side)
# and llvm-undname (binding by name). SteamCMD is Valve's own client, for the macOS and Linux route.
PACKAGES = {
    'brew': {'wine': ['--cask', 'wine-stable'], 'msitools': ['msitools'], 'llvm': ['llvm'], 'gh': ['gh'],
             'steamcmd': ['--cask', 'steamcmd']},
    'apt-get': {'wine': ['wine', 'wine64', 'winbind'], 'msitools': ['msitools'], 'llvm': ['llvm'], 'gh': ['gh'],
                'steamcmd': ['steamcmd']},
    'dnf': {'wine': ['wine'], 'msitools': ['msitools'], 'llvm': ['llvm'], 'gh': ['gh'], 'steamcmd': ['steamcmd']},
    'pacman': {'wine': ['wine'], 'msitools': ['msitools'], 'llvm': ['llvm'], 'gh': ['github-cli'],
               'steamcmd': None},
    'zypper': {'wine': ['wine'], 'msitools': ['msitools'], 'llvm': ['llvm'], 'gh': ['gh'], 'steamcmd': None},
    'winget': {'llvm': ['LLVM.LLVM'], 'gh': ['GitHub.cli'], 'git': ['Git.Git']},
    'choco': {'llvm': ['llvm'], 'gh': ['gh'], 'git': ['git']},
}


def install_command(ctx, pm, names, accept_sources=False):
    if pm == 'brew':
        casks = [n for n in names if n[:1] == ['--cask']]
        out = []
        plain = [p for n in names if n[:1] != ['--cask'] for p in n]
        if plain:
            out.append(['brew', 'install', *plain])
        out += [['brew', 'install', *n] for n in casks]
        return out
    flat = [p for n in names for p in n]
    sudo = [] if (hasattr(os, 'geteuid') and os.geteuid() == 0) else (['sudo'] if ctx.interactive else ['sudo', '-n'])
    if pm == 'apt-get':
        return [sudo + ['apt-get', 'update', '-q'], sudo + ['apt-get', 'install', '-y', '-q', *flat]]
    if pm == 'dnf':
        return [sudo + ['dnf', 'install', '-y', *flat]]
    if pm == 'pacman':
        return [sudo + ['pacman', '-S', '--needed', '--noconfirm', *flat]]
    if pm == 'zypper':
        return [sudo + ['zypper', '--non-interactive', 'install', *flat]]
    if pm == 'winget':
        # The source agreements are terms of Microsoft's package sources, so they ride on their own
        # flag, never on --yes; without it winget asks on its first run (or fails without a terminal).
        agree = ['--accept-source-agreements'] if accept_sources else []
        return [['winget', 'install', '-e', '--silent', '--source', 'winget', *agree, '--id', p] for p in flat]
    if pm == 'choco':
        return [['choco', 'install', '-y', *flat]]
    return []


def private_wine_bin(ctx):
    tail = Path(MAC_WINE['app']) / 'Contents' / 'Resources' / 'wine' / 'bin'
    for cand in toolchain_dirs(ctx, 'wine'):
        if (cand / tail / 'wine').is_file():
            return cand / tail
    return ctx.private / 'wine' / tail


def apply_wine_env(ctx):
    """Put this project's Wine first on PATH (macOS) and keep its prefix under .local/, so the
    contributor's own ~/.wine is never touched."""
    if ctx.windows:
        return
    if ctx.platform == 'darwin':
        b = Path(ctx.env.get('SR_WINE_BIN') or private_wine_bin(ctx))
        path = ctx.env.get('PATH', '')
        if (b / 'wine').is_file() and not path.startswith(str(b)):
            ctx.env['PATH'] = f'{b}{os.pathsep}{path}'
    ctx.env.setdefault('WINEPREFIX', str(ctx.private / 'wineprefix'))
    ctx.env.setdefault('WINEDEBUG', '-all')


def mac_wine_ready(ctx):
    b = Path(ctx.env.get('SR_WINE_BIN') or private_wine_bin(ctx))
    return (b / 'wine').is_file()


def install_mac_wine(ctx):
    """WineHQ's macOS build (packaged by Gcenx, the source of the former Homebrew cask), pinned by
    SHA-256 and unpacked under .local/. Downloaded by this tool rather than by a browser or a cask,
    so it carries no quarantine flag and Gatekeeper never asks; nothing goes to /Applications."""
    import tarfile
    dest = ctx.private / 'wine'
    dest.mkdir(parents=True, exist_ok=True)
    archive = dest / 'wine.tar.xz'
    if not archive.is_file() or sha256_file(archive) != MAC_WINE['sha256']:
        ctx.say(f'downloading Wine {MAC_WINE["version"]} for macOS (about 185 MB)')
        try:
            with urllib.request.urlopen(MAC_WINE['url'], timeout=900) as resp, open(archive, 'wb') as out:
                shutil.copyfileobj(resp, out)
        except (urllib.error.URLError, OSError) as exc:
            raise Stop(NETWORK, f'cannot download Wine: {exc}', f'{ctx.cli} setup --yes (when online)')
        if sha256_file(archive) != MAC_WINE['sha256']:
            archive.unlink()
            raise Stop(FAILED, 'the Wine download does not match its pinned SHA-256')
    with tarfile.open(archive) as tar:
        try:
            tar.extractall(dest, filter='data')
        except TypeError:  # Python without extraction filters
            # Unfiltered extraction trusts member paths; that is safe here only because the
            # archive was checked against its pinned SHA-256 above.
            tar.extractall(dest)
    archive.unlink()
    apply_wine_env(ctx)
    save_config(ctx, wine=str(private_wine_bin(ctx)))


def wanted_packages(ctx, tool):
    want = []
    if not ctx.windows and tool['status'] != 'override':
        if ctx.platform != 'darwin' and not (ctx.which('wine64') or ctx.which('wine')):
            want.append('wine')
        if not ctx.which('msiextract') and tool['status'] != 'ok':
            want.append('msitools')
    if not find_objdump(ctx):
        want.append('llvm')
    if ctx.windows and not ctx.which('git'):
        want.append('git')
    return want


def fetch_sources(ctx, sources=None):
    """Shallow clones of the pinned community naming sources, for the label and origin checks."""
    done = []
    for repo, (rel, rev, _lic) in (COMMUNITY_SOURCES if sources is None else sources).items():
        dest = local_path(ctx.repo, rel, ctx.env)
        if (dest / '.git').is_dir():
            head = git(ctx, 'rev-parse', 'HEAD', check=False, cwd=dest)
            if head == rev:
                continue
        dest.mkdir(parents=True, exist_ok=True)
        for args in (['init', '-q'], ['fetch', '-q', '--depth', '1', f'https://github.com/{repo}.git', rev],
                     ['-c', 'advice.detachedHead=false', 'checkout', '-q', 'FETCH_HEAD']):
            proc = ctx.run(['git', *args], cwd=dest, capture_output=True, text=True)
            if proc.returncode != 0:
                raise Stop(NETWORK, f'cannot fetch {repo}@{rev[:7]}: {proc.stderr.strip()[:200]}',
                           f'{ctx.cli} setup --yes   (retry when online)')
        done.append(repo)
    return done


def fetch_x64_index(ctx):
    """Download the prebuilt x64 shape indexes (docs/sibling-x64.md) into the private folder, each checked
    against the SHA-256 pinned in data/x64-index.json. Returns a one-line summary."""
    import x64_index
    try:
        pins = x64_index.load_pins(ctx.repo / 'data/x64-index.json')
        dest = ctx.private / 'x64-index'
        got = []
        for game in sorted(pins['assets']):
            _path, fresh = x64_index.fetch(game, dest, pins)
            got.append(f'{game} {"downloaded" if fresh else "present"}')
    except x64_index.IndexError_ as exc:
        raise Stop(NETWORK, str(exc), f'{ctx.cli} setup --yes   (retry when online)')
    return ', '.join(got) + f' ({pins["tag"]}, SHA-256 verified) in {dest}'


def sibling_analysis_dir(ctx):
    return ctx.private / 'analysis'


def build_sibling_index(ctx):
    """The private FNV lookup index (tools/build_fnv_index.py) joined by name to the public
    inventory, since a contributor has no Ghidra tables: `start` then lists the same-named FNV
    method and the class's small methods. Returns the number of our functions joined, or None."""
    repo, rel, _rev = SIBLING_SOURCE
    clone = local_path(ctx.repo, rel, ctx.env)
    if not (clone / 'build/units.json').is_file():
        return None
    out = sibling_analysis_dir(ctx)
    out.mkdir(parents=True, exist_ok=True)
    with open(out / 'functions.jsonl', 'w') as fh:
        for fn in inventory(ctx.repo)['functions']:
            if PLAIN_NAME.fullmatch(fn.get('name') or ''):
                fh.write(json.dumps({'rva': fn['rva'], 'names': [{'name': fn['name'], 'how': 'community',
                                                                    'source': 'data/progress.json'}]}) + '\n')
    proc = ctx.run([sys.executable, str(ctx.repo / 'tools/build_fnv_index.py'), '--fnv', str(clone),
                    '--analysis', str(out)], cwd=ctx.repo, capture_output=True, text=True)
    if proc.returncode != 0:
        raise Stop(FAILED, f'building the {repo} index failed: {(proc.stderr or proc.stdout).strip()[-200:]}')
    m = re.search(r'our functions joined by name: (\d+)', proc.stdout)
    return int(m.group(1)) if m else 0


def sibling_section(ctx, cls, rvas):
    """Lines of the "Sibling source" section for a task, [] without the index or a match."""
    try:
        from export_pack import sibling_lines
    except Exception:  # noqa: BLE001 - the section is optional help, never required
        return []
    lines = sibling_lines(cls, rvas, root=sibling_analysis_dir(ctx))
    if lines and no_sibling_names(ctx.env):
        return ['A sibling declaration exists for this name (details omitted).']
    return lines


def licence_url(vsman):
    """The Build Tools licence link from the pinned installer manifest, if it names one."""
    try:
        data = json.loads(Path(vsman).read_text(encoding='utf-8-sig'))
    except (OSError, ValueError):
        return None
    for pkg in data.get('packages', []):
        if pkg.get('id') == 'Microsoft.VisualStudio.Product.BuildTools':
            for res in pkg.get('localizedResources') or []:
                if str(res.get('language', '')).lower() == 'en-us' and res.get('license'):
                    return res['license']
    return None


def install_toolchain(ctx, accept):
    """The verifier recipe (see tools/verifier/recipe_pins.py) on this machine: msvc-wine at its
    pinned commit, the pinned VS 2017 15.9 manifest, toolset and SDK from Microsoft's servers, then
    the binaries checked against pinned.sha256. Resumable: finished steps are skipped."""
    pins = recipe_constants(ctx.repo)
    work = ctx.private / 'toolchain-work'
    work.mkdir(parents=True, exist_ok=True)
    src = work / 'msvc-wine'
    at_pin = (src / '.git').is_dir() and git(ctx, 'rev-parse', 'HEAD', check=False, cwd=src) == pins['MSVC_WINE_COMMIT']
    if not at_pin:
        if not (src / '.git').is_dir():
            proc = ctx.run(['git', 'clone', '-q', pins['MSVC_WINE_URL'], str(src)], capture_output=True, text=True)
            if proc.returncode != 0:
                raise Stop(NETWORK, f'cannot clone msvc-wine: {proc.stderr.strip()[:200]}', f'{ctx.cli} setup (when online)')
        git(ctx, '-c', 'advice.detachedHead=false', 'checkout', '-q', pins['MSVC_WINE_COMMIT'], cwd=src)
    vsman = work / 'VisualStudio.vsman'
    if not vsman.is_file() or sha256_file(vsman) != pins['VSMAN_SHA256']:
        ctx.say('downloading the pinned Visual Studio 2017 15.9 installer manifest from Microsoft')
        try:
            with urllib.request.urlopen(pins['VSMAN_URL'], timeout=120) as resp:
                vsman.write_bytes(resp.read())
        except (urllib.error.URLError, OSError) as exc:
            raise Stop(NETWORK, f'cannot download the installer manifest: {exc}', f'{ctx.cli} setup (when online)')
        if sha256_file(vsman) != pins['VSMAN_SHA256']:
            vsman.unlink()
            raise Stop(FAILED, 'the installer manifest does not match its pinned SHA-256; the recipe stops here '
                       '(tools/verifier/README.md, "Known limits of the recipe")')
    url = licence_url(vsman)
    if not url:
        # Acceptance needs a licence a person can read; without a concrete link nothing is accepted.
        raise Stop(FAILED, 'the pinned installer manifest names no licence link, so no licence can be shown '
                   'for acceptance; nothing was installed', 'report this in an issue (tools/verifier/README.md)')
    if accept:
        ctx.say(f'Microsoft Build Tools for Visual Studio 2017 licence, accepted by the person who passed '
                f'--accept-microsoft-license: {url}')
    else:
        ctx.say(f'Microsoft Build Tools for Visual Studio 2017 licence: {url}')
        if not ctx.interactive:
            raise Stop(CONSENT, f'installing the compiler accepts Microsoft\'s licence ({url})',
                       f'{ctx.cli} setup --accept-microsoft-license   (only after a person has read and accepted it)',
                       licence=url)
        if input('Do you accept this licence? Type "yes": ').strip().lower() != 'yes':
            raise Stop(CONSENT, 'licence not accepted; no compiler installed')
    dest = toolchain_root(ctx)
    common = [sys.executable, '-I', str(src / 'vsdownload.py'), '--manifest', str(vsman), '--major', '15',
              '--host-arch', 'x64', '--architecture', 'x64', '--with-default', 'no', '--with-msvc', 'yes',
              '--with-sdk', 'yes', '--sdk-version', pins['SDK_VERSION'], '--accept-license']
    # A persistent download cache: without one vsdownload.py discards every finished payload when
    # one fails, so an interrupted 0.75 GB download on a slow link would start over. vsdownload.py
    # checks each cached payload against the manifest's SHA-256 before reusing it.
    cache = work / 'cache'
    if not toolchain_bins(dest):
        ctx.say(f'downloading and unpacking the toolset and SDK into {dest} (about 0.75 GB from Microsoft, '
                f'about 3.5 GB of disk); an interrupted download resumes from {cache} on the next run')
        proc = ctx.run(common + ['--cache', str(cache), '--dest', str(dest)], cwd=work)
        if proc.returncode != 0:
            raise Stop(FAILED, 'vsdownload.py failed (see its output above); finished downloads are kept',
                       f'{ctx.cli} setup --accept-microsoft-license   (resumes)')
    shutil.rmtree(cache, ignore_errors=True)
    if not ctx.windows and not (dest / 'bin/x64/cl').is_file():
        proc = ctx.run(['bash', str(src / 'install.sh'), str(dest)], cwd=work)
        if proc.returncode != 0:
            raise Stop(FAILED, 'msvc-wine install.sh failed (see its output above)', f'{ctx.cli} doctor')
    save_config(ctx, msvc=str(dest), microsoft_licence_accepted=True)
    return check_toolchain(ctx)


def cmd_setup(ctx, args):
    target = target_manifest(ctx.repo)
    steps = []

    def step(name, status, detail):
        steps.append({'step': name, 'status': status, 'detail': detail})
        ctx.say(f'[{status}] {name}: {detail}')
    if sys.version_info < (3, 11):
        raise Stop(MISSING, 'Python 3.11 or newer is needed', 'install a newer Python and rerun')
    if not ctx.which('git'):
        raise Stop(MISSING, 'git is needed', 'install git and rerun')
    # 1. Packages first, so SteamCMD is available for the executable step.
    tool = check_toolchain(ctx)
    want = wanted_packages(ctx, tool)
    pm = package_manager(ctx)
    if getattr(args, 'steamcmd', False) and not ctx.which('steamcmd'):
        if pm == 'apt-get':
            # Debian's package shows Valve's Steam licence in a debconf dialog; a person answers it,
            # so this tool never installs it with -y or preseeds the answer.
            step('steamcmd', 'needs-person', 'run: sudo apt install steamcmd   (it shows the Steam licence for you '
                 'to accept; Ubuntu needs the multiverse repository and i386: sudo add-apt-repository multiverse; '
                 'sudo dpkg --add-architecture i386; sudo apt update)')
        elif ctx.windows:
            step('steamcmd', 'needs-person', 'download SteamCMD from Valve: '
                 'https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip (unzip it to C:\\steamcmd)')
        else:
            want.append('steamcmd')
    if want:
        table = PACKAGES.get(pm or '', {})
        names = [table[w] for w in want if table.get(w)]
        cmds = install_command(ctx, pm, names, getattr(args, 'accept_winget_source_agreements', False)) if pm else []
        shown = ' && '.join(' '.join(shlex.quote(c) for c in cmd) for cmd in cmds)
        if not cmds:
            step('packages', 'needs-person', f'install {", ".join(want)} with your package manager')
        elif args.no_install:
            step('packages', 'skipped', f'would run: {shown}')
        elif ctx.ask(f'Install {", ".join(want)} with: {shown}?', '--yes'):
            for cmd in cmds:
                proc = ctx.run(cmd)
                if proc.returncode != 0:
                    if pm == 'winget' and '--accept-source-agreements' not in cmd:
                        raise Stop(CONSENT, f'package install failed: {" ".join(cmd)}; winget may be waiting for '
                                   'you to accept the terms of its package source',
                                   f'run it yourself in a terminal, or after reading the terms: {ctx.cli} setup '
                                   '--yes --accept-winget-source-agreements', steps=steps)
                    raise Stop(MISSING, f'package install failed: {" ".join(cmd)}',
                               f'run it yourself (it may need your password): {shown}', steps=steps)
            step('packages', 'installed', ', '.join(want))
        else:
            step('packages', 'skipped', 'declined')
    else:
        step('packages', 'present', 'nothing to install')
    if not ctx.windows and ctx.platform == 'darwin' and not ctx.env.get('SR_CONTRIB_COMPILER'):
        rosetta = ctx.run(['arch', '-x86_64', '/usr/bin/true'], capture_output=True).returncode == 0 \
            if os.uname().machine == 'arm64' else True
        if not rosetta:
            step('rosetta', 'needs-person', 'Wine on Apple silicon needs Rosetta 2, which has its own Apple licence')
            raise Stop(CONSENT, 'Rosetta 2 is not installed; installing it accepts Apple\'s licence',
                       'a person runs: softwareupdate --install-rosetta   (then rerun setup)', steps=steps)
        if mac_wine_ready(ctx):
            step('wine', 'present', str(Path(ctx.env.get('SR_WINE_BIN') or private_wine_bin(ctx))))
        elif args.no_install:
            step('wine', 'skipped', f'would download {MAC_WINE["url"]}')
        elif ctx.ask(f'Download Wine {MAC_WINE["version"]} (WineHQ build, about 185 MB) into {ctx.private / "wine"}?',
                     '--yes'):
            install_mac_wine(ctx)
            step('wine', 'installed', str(private_wine_bin(ctx)))
        else:
            raise Stop(CONSENT, 'Wine is needed to run the compiler on macOS', f'{ctx.cli} setup --yes', steps=steps)
    # 2. The game executable.
    info, how = resolve_exe(ctx, target, args.exe)
    steamcmd = ctx.which('steamcmd')
    if (info is None or info['status'] != 'ok') and getattr(args, 'steamcmd', False) and steamcmd \
            and ctx.interactive and not args.exe and not ctx.redact:
        # SteamCMD runs in this terminal: the person types the login, password and guard code into
        # it directly. Its terminal output also bypasses this process, so redacted runs use the manual route.
        ctx.say('\n'.join(steamcmd_route(ctx)))
        if ctx.ask('Start SteamCMD now (you type the steps above at its prompt)?', '--steamcmd'):
            (ctx.private / 'game').mkdir(parents=True, exist_ok=True)
            subprocess.run([steamcmd], env=ctx.env)
            info, how = resolve_exe(ctx, target, None)
    if info is not None and info['status'] == 'ok':
        save_config(ctx, exe=info['path'])
        step('game executable', 'ok', f'{info["path"]} ({how}), {target["version"]}, SHA-256 pinned')
    else:
        detail = wrong_build_message(info, target, ctx.redact) if info and info['status'] == 'wrong-build' else \
            'SkyrimSE.exe not found' + (f' at {info["path"]}' if info else ' in a Steam library')
        step('game executable', 'needs-person', detail)
        raise Stop(MISSING, detail, f'{ctx.cli} setup --exe "<path to SkyrimSE.exe>"', steps=steps,
                   steamcmd_route=steamcmd_route(ctx), pinned={k: target[k] for k in ('version', 'store', 'image_sha256')})
    if getattr(args, 'decompiler', True):
        import contrib_decompiler
        decompiler = contrib_decompiler.recommended_setup(ctx, args.no_install)
        detail = (decompiler['reason'] + f'; run {ctx.cli} --yes setup later to retry'
                  if decompiler['state'] == 'skipped' else
                  f'private background analysis; rerun {ctx.cli} setup --no-self-test for progress')
        step('decompiler', decompiler['state'], detail)
    # 3. Community sources for the label and origin checks.
    if not args.no_sources:
        try:
            fetched = fetch_sources(ctx)
            step('community sources', 'ok', ('fetched ' + ', '.join(fetched)) if fetched else 'present at their pins')
        except Stop as exc:
            step('community sources', 'skipped', exc.message)
    # 3b. The FNV decompilation (optional): read for shape and names, never evidence.
    if not args.no_sources and not getattr(args, 'no_sibling', False):
        repo, rel, rev = SIBLING_SOURCE
        try:
            fetched = fetch_sources(ctx, {repo: (rel, rev, 'CC0-1.0'), **SIBLING_EXTRA_SOURCES})
            joined = build_sibling_index(ctx)
            step('sibling source', 'ok', f'{repo}@{rev[:8]} ' + ('fetched' if fetched else 'present')
                 + f'; index joins {joined} inventory functions by name')
        except Stop as exc:
            step('sibling source', 'skipped', exc.message)
    # 3c. The prebuilt x64 shape index of the CC0 sibling builds (compiled sibling code only; the SHA-256
    # is pinned in data/x64-index.json). Optional like the sibling clone.
    if not args.no_sources and not getattr(args, 'no_sibling', False):
        try:
            step('x64 index', 'ok', fetch_x64_index(ctx))
        except Stop as exc:
            step('x64 index', 'skipped', exc.message)
    # 4. The compiler.
    if tool['status'] in ('ok', 'override'):
        step('compiler', tool['status'], tool.get('bin') or 'SR_CONTRIB_COMPILER')
    else:
        tool = install_toolchain(ctx, args.accept_microsoft_license)
        if tool['status'] != 'ok':
            raise Stop(MISSING, f'toolchain after install: {tool["status"]} {tool.get("differing", "")}',
                       f'{ctx.cli} doctor', steps=steps)
        step('compiler', 'installed', tool['bin'])
    import pdb_facts
    sym_ok, sym_lines = pdb_facts.setup_lines(ctx.repo, ctx.env, full=True)
    step('symbol files', 'ok' if sym_ok else 'needs-person',
         'map and Fallout 4 PDB present, SHA-256 verified' if sym_ok else
         '; '.join(sym_lines) + '. Optional but strongly recommended: they give the names, prototypes and layouts '
         '`start` prints. Extract only the .map and .pdb; label names SYMBOLS(<source-id>); never commit them')
    # 5. Self-test: a function the project already matched must pass here too.
    if not args.no_self_test:
        try:
            code, data, _n = run_self_test(ctx)
        except Stop as exc:
            if ctx.redact:
                detail = 'failed; see private diagnostics from setup without --redact'
                step('self-test', 'fail', detail)
                raise Stop(exc.code, f'self-test: {detail}', f'{ctx.cli} doctor', steps=steps) from None
            step('self-test', 'fail', exc.message)
            raise Stop(exc.code, f'self-test: {exc.message}', exc.next_action or f'{ctx.cli} doctor',
                       steps=steps, **exc.data)
        if data.get('skipped'):
            step('self-test', 'skipped', data['note'])
        else:
            step('self-test', 'pass' if code == OK else 'fail',
                 f'0x{SELF_TEST_RVA:x} compiled and compared: ' + ', '.join(
                     f'{f["rva"]} {f["result"]} {f["reason"]}' for f in data.get('functions', [])))
        if code != OK:
            failure = {'steps': steps}
            if not ctx.redact:
                failure['self_test'] = data
            raise Stop(code, 'self-test failed: the local toolchain does not reproduce an accepted match',
                       f'{ctx.cli} doctor', **failure)
    result = {'steps': steps}
    if getattr(args, 'decompiler', True):
        result['decompiler'] = decompiler
    return OK, result, f'{ctx.cli} next'


def run_self_test(ctx):
    data = inventory(ctx.repo)
    fn = find_function(data, SELF_TEST_RVA)
    if fn is None or fn['status'] != 'matched':
        return OK, {'functions': [], 'skipped': True,
                    'note': f'0x{SELF_TEST_RVA:x} is not a matched function in data/progress.json; nothing proven'}, None
    args = argparse.Namespace(rva=[f'0x{SELF_TEST_RVA:x}'], practice=True, drafted_by='self-test', area=None,
                              no_branch=True, recipe=None, force=False)
    start(ctx, args, quiet=True)
    return run_compare(ctx, task_id_for(PLAIN_NAME.fullmatch(fn['name']).group(1), practice=True), quiet=ctx.redact)


def cmd_next(ctx, args):
    data = inventory(ctx.repo)
    claimed, online = set(), True
    try:
        index = ctx.github().open_items()
        me = ctx.github().user()
        import claimable
        pool = [(f['rva'], f['build_id']) for f in data['functions']]
        pool += [(rva, data['target_build_id']) for rva in claimable.offered_window(ctx.repo)]
        claimed = {rva for rva, build in pool
                   if batch_claims.claimed(index, rva, me) and
                   any(it.get('build_id') in (None, build) for it in batch_claims.claimed(index, rva, me))}
    except Offline as exc:
        online = False
        ctx.say(f'claims unavailable: {exc}')
    claimed |= {parse_rva(k) for k in local_claims(ctx)}
    facts = {}
    if getattr(args, 'function_table', None):
        from contrib_readiness import local_facts
        target = target_manifest(ctx.repo)
        try:
            facts = local_facts(args.function_table, data['target_build_id'], target['image_sha256'])
        except (OSError, ValueError, KeyError) as exc:
            raise Stop(USAGE, str(exc)) from None
    class_filter = None
    if getattr(args, 'class_regex', None):
        try:
            class_filter = re.compile(args.class_regex)
        except re.error as exc:
            raise Stop(USAGE, f'--class is not a regular expression: {exc}') from None
    symbols = readiness_symbol_map(ctx, data['target_build_id'])
    max_size = 64 if args.max_size is None and class_filter is None else args.max_size
    ready = [c for c in candidates(ctx.repo, data, claimed, max_size, facts, published=True,
                                   class_filter=class_filter, ready=ready_queue.load_queue(ctx.repo), symbol_map=symbols)
             if c['startable']]
    counts = {'claimable': len(ready), 'without_inventory_entry': sum(not c['in_inventory'] for c in ready),
              'under_64_bytes': sum(c['size_band'] == 0 for c in ready),
              '64_to_255_bytes': sum(c['size_band'] == 1 for c in ready),
              'with_existing_layout': sum(c['has_layout'] for c in ready),
              'callee_ready': sum(c['callee_ready'] for c in ready)}
    rows = ready[:args.count]
    pdb = pdb_names(ctx)
    import pdb_facts
    ctx.say('claimable now: ' + ', '.join(f'{v} {k.replace("_", " ")}' for k, v in counts.items()))
    for c in rows:
        ctx.say(f'{c["rva"]:>10}  {c["size"]:>5} B  {c["name"]}  -> {c["unit"]}' + ('' if not c['unit_exists']
                                                                                   else '  (existing unit)')
                + f'  — {c["reason"]}'
                + (f'  [pdb: {hint.name[:80]}]' if (hint := pdb and pdb.suggest(parse_rva(c['rva']))) else '')
                + (f'  [{brief}]' if (brief := pdb_facts.brief(ctx.repo, parse_rva(c['rva']), c.get('name'))) else '')
                + (f'  [{earlier}; `{ctx.cli} facts {c["rva"]}`]' if (earlier := giveup.brief(ctx.repo, c['rva'])) else ''))
    if not online:
        ctx.say('note: GitHub not reachable; claims by others are not excluded')
    if not rows:
        return OK, {'candidates': [], 'claims_checked': online, 'counts': counts}, None
    return OK, {'candidates': rows, 'claims_checked': online, 'counts': counts}, f'{ctx.cli} claim {rows[0]["rva"]}'


def claim_selection(ctx, args, data):
    import claimable

    values = getattr(args, 'rva', []) or []
    values = [values] if isinstance(values, str) else list(values)
    for file in getattr(args, 'lists', []) or []:
        for line in Path(file).read_text().splitlines():
            if line.strip() and not line.lstrip().startswith('#'):
                values.append(line.split()[0])
    addresses = {parse_rva(v) for v in values}
    classes = dict.fromkeys(getattr(args, 'classes', []) or [])
    by_class, by_name, by_rva = {}, {}, {}
    for fn in data['functions']:
        by_rva.setdefault(fn['rva'], fn)
        if classes and fn['status'] != 'matched':
            name = fn.get('name') or ''
            owner, sep, _ = name.rpartition('::')
            if sep and owner in classes:
                by_class.setdefault(owner, []).append(fn['rva'])
            if name in classes:
                by_name.setdefault(name, []).append(fn['rva'])
    for cls in classes:
        selected = by_class.get(cls) or by_name.get(cls)
        if not selected:
            raise Stop(USAGE, f'class {cls} has no unmatched functions',
                       f'{ctx.cli} claim 0x<RVA> --model <model>')
        addresses.update(selected)
    ranges = []
    for value in getattr(args, 'ranges', []) or []:
        try:
            start, end = map(parse_rva, value.split('-', 1))
        except (ValueError, Stop):
            raise Stop(USAGE, 'range must be 0x<start>-0x<end>') from None
        if end <= start:
            raise Stop(USAGE, 'range end must be greater than start')
        ranges.append((start, end))
    ranged = batch_claims.ClaimIntervals(ranges)
    if ranges:
        addresses.update(f['rva'] for f in data['functions'] if f['status'] != 'matched' and f['rva'] in ranged)
    if not addresses:
        if ranges:
            raise Stop(USAGE, 'the range has no unmatched functions, so there is nothing to claim', f'{ctx.cli} next')
        raise Stop(USAGE, 'select RVAs, --class, --list or --range')
    if missing := addresses - by_rva.keys():
        sizes = claimable.published_sizes(ctx.repo)
        if offered := missing.intersection(sizes):
            by_rva.update(claimable.resolve_many(ctx.repo, data['target_build_id'], offered,
                                                function_table_rows(ctx), sizes=sizes))
    ordered = sorted(addresses)
    functions = []
    for address in ordered:
        fn = by_rva.get(address)
        if fn is None:
            raise Stop(USAGE, f'0x{address:x} is not in data/progress.json or the published target-hash list')
        if fn['status'] == 'matched':
            raise Stop(USAGE, f'0x{address:x} is already matched', f'{ctx.cli} next')
        functions.append(fn)
    entries = ranged.entries + [(r, r + 1) for r in ordered if r not in ranged]
    return functions, entries


def claim_conflicts(index, blocked, addresses):
    """{rva: [claim items]} for each requested address a blocking claim covers."""
    addresses = sorted(addresses)
    where = {}
    for it in blocked:
        entries = it.get('entries')
        if entries:
            for start, end in batch_claims.ClaimIntervals(entries).entries:
                for address in addresses[bisect_left(addresses, start):bisect_left(addresses, end)]:
                    where.setdefault(address, []).append(it)
        else:
            for address in addresses:
                if it in index.get(address, []):
                    where.setdefault(address, []).append(it)
    return where


def describe_conflicts(where, extra=()):
    parts = [f'0x{a:x} (' + ', '.join(f'#{i["number"]} {i["url"]} by {i["author"]}' for i in its) + ')'
             for a, its in sorted(where.items())]
    if not parts:
        parts = [f'#{i["number"]} {i["url"]} by {i["author"]}' for i in extra]
    return ', '.join(parts)


def giveup_notice(ctx, rvas, cap=10):
    """Say what earlier drafters learned about these functions (tools/giveup.py); at most `cap` functions."""
    import giveup
    found = [r for r in rvas if giveup.load(ctx.repo, f'0x{r:x}')]
    lines = giveup.lines_for(ctx.repo, [f'0x{r:x}' for r in found[:cap]])
    for line in lines:
        ctx.say(line)
    if len(found) > cap:
        ctx.say(f'... and {len(found) - cap} more function(s) with earlier give-ups: python3 tools/giveup.py list')
    return lines


def cmd_claim(ctx, args):
    config = load_config(ctx)
    try:
        model = agent_identity.resolve(getattr(args, 'model', None) or config.get('model'),
                                       agent=getattr(args, 'agent', None),
                                       drafted_by=getattr(args, 'drafted_by', None) or config.get('drafted_by'))
    except ValueError as error:
        raise Stop(USAGE, str(error)) from None
    save_config(ctx, model=model)
    ctx.say(f'model/agent: {model}')
    def save_claim(addresses, record):
        save_local_claims(ctx, addresses, dict(record, model=model))
    data = inventory(ctx.repo)
    functions, entries = claim_selection(ctx, args, data)
    build = functions[0]['build_id']
    addresses = [f['rva'] for f in functions]
    first = addresses[0]
    gh = ctx.github()
    try:
        index = gh.open_items(build=build, entries=entries)
    except Offline as exc:
        if not args.offline_ok:
            raise Stop(NETWORK, f'cannot reach GitHub to check claims ({exc})',
                       f'{ctx.cli} claim 0x{first:x} when online, or --offline-ok to start unclaimed')
        save_claim(addresses, {'status': 'unpublished', 'url': None})
        ctx.say('WARNING: claim recorded locally only; others cannot see it. Run claim again when online.')
        return OK, {'rva': f'0x{first:x}', 'claim': 'unpublished'}, f'{ctx.cli} start 0x{first:x}'
    if getattr(args, 'github_user', None):
        save_config(ctx, github_user=args.github_user)
    me = gh.user()
    def overlapping(idx):
        if isinstance(idx, batch_claims.ClaimIndex):
            return [it for it in batch_claims.ClaimIndex(idx.records, build).overlaps(entries, active=False)]
        result = []
        for address in addresses:
            for it in idx.get(address, []):
                if it not in result:
                    result.append(it)
        return result
    items = overlapping(index)
    if not me and items:
        raise Stop(USAGE, 'GitHub login is unknown; cannot tell whether an existing claim is yours',
                   f'{ctx.cli} claim 0x{first:x} --github-user <your-login>', claims=items)
    mine, fresh, stale = claim_state(items, me)
    blocked = fresh + ([] if args.take_over else stale)
    if blocked:
        where = claim_conflicts(index, blocked, addresses)
        if getattr(args, 'skip_conflicts', False):
            skipped = set(where)
            functions = [f for f in functions if f['rva'] not in skipped]
            if not functions:
                raise Stop(CLAIMED, 'every selected function is already claimed: ' + describe_conflicts(where),
                           f'{ctx.cli} next', claims=blocked)
            addresses = [f['rva'] for f in functions]
            first = addresses[0]
            entries = [(a, a + 1) for a in addresses]
            ctx.say('skipping claimed functions: ' + describe_conflicts(where))
            mine, fresh, stale = claim_state(overlapping(index), me)
        elif fresh:
            raise Stop(CLAIMED, 'scope is claimed: ' + describe_conflicts(where, fresh),
                       f'{ctx.cli} claim ... --skip-conflicts to claim the rest', claims=fresh)
        else:
            raise Stop(CLAIMED, 'lapsed claims: ' + describe_conflicts(where) + '; use --take-over',
                       f'{ctx.cli} claim 0x{first:x} --take-over (or --skip-conflicts)', claims=stale)
    ranges_covered = all(any(a <= start and end <= b for it in mine for a, b in it.get('entries', []))
                         for start, end in entries if end > start + 1)
    if mine and ranges_covered and all(any(it in mine for it in index.get(address, [])) for address in addresses):
        save_claim(addresses, {'status': 'published', 'url': mine[0]['url']})
        ctx.say(f'already yours: {mine[0]["url"]}')
        return OK, {'rva': f'0x{first:x}', 'claim': mine[0]['url']}, f'{ctx.cli} start 0x{first:x}'
    public = batch_claims.git_json(ctx.repo)
    # Offered functions are not in the inventory yet, so the claimed addresses count as well.
    known = sorted({f['rva'] for f in data['functions'] if f['build_id'] == build} | set(addresses))
    counts = {(a, b): bisect_left(known, b) - bisect_left(known, a) for a, b in entries}
    if not any(counts.values()):
        raise Stop(USAGE, 'the claim resolves to 0 functions; no issue was opened', f'{ctx.cli} next')
    giveup_notice(ctx, addresses)
    plans = batch_claims.parts(build, entries, public, me, counts=counts)
    urls, links = [], []
    for title, text, chunk in plans:
        url = gh.create_issue(title, text)
        if not url:
            links.append(gh.new_issue_link(title, text))
            continue
        urls.append(url)
        try:
            after = overlapping(gh.open_items(refresh=True, build=build, entries=entries))
        except Offline:
            after = []
        rivals = [i for i in claim_state(after, me)[1] if i['url'] != url and int(i['number']) < issue_number(url)]
        if rivals:
            for created in urls:
                gh.close(issue_number(created), f'Withdrawn: {rivals[0]["url"]} claimed the overlapping scope first.')
            saved = local_claims(ctx)
            saved = {key: value for key, value in saved.items() if value.get('url') not in urls}
            ctx.private.mkdir(parents=True, exist_ok=True)
            (ctx.private / 'claims.json').write_text(json.dumps(saved) + '\n')
            raise Stop(CLAIMED, f'older claim #{rivals[0]["number"]} won; your claim was withdrawn', claims=rivals)
        covered = batch_claims.ClaimIntervals(chunk)
        save_claim((a for a in addresses if a in covered), {'status': 'published', 'url': url})
        ctx.say(f'claimed: {url}')
    if links:
        ctx.say('gh is not signed in; file these issues, then run claim again:')
        for link in links:
            ctx.say(link)
        return OK, {'rva': f'0x{first:x}', 'claim': 'link-only', 'link': links[0], 'links': links}, 'file the issues and run claim again'
    for it in stale:
        for offset in range(0, len(entries), 500):
            markers = '\n'.join(f'<!-- skyrim-claim-takeover-v1 0x{a:x}-0x{b:x} -->'
                                for a, b in entries[offset:offset + 500])
            gh.comment(it['number'], f'Taking over overlapping functions after 24 hours without activity. '
                       f'New claim: #{issue_number(urls[0])}.\n' + markers)
    return OK, {'rva': f'0x{first:x}', 'claim': urls[0], 'claims': urls}, f'{ctx.cli} start 0x{first:x}'


def cmd_release(ctx, args):
    rva = parse_rva(args.rva)
    if getattr(args, 'draft_from', None) and not args.category:
        raise Stop(USAGE, '--draft-from needs --category and the give-up details')
    filed = file_giveup(ctx, rva, args) if args.category else None
    gh = ctx.github()
    reason = args.reason or 'giving the function back'
    closed = []
    try:
        me = gh.user()
        for it in gh.open_items().get(rva, []):
            if len(it.get('entries', [])) > 1 or any(b > a + 1 for a, b in it.get('entries', [])):
                ctx.say(f'batch #{it["number"]}: edit its scope on GitHub or close the whole issue to release it')
                continue
            if it['author'] == me and not it['pull_request'] and gh.close(it['number'], f'Released: {reason}'):
                closed.append(it['url'])
    except Offline:
        pass
    claims = local_claims(ctx)
    claims.pop(f'0x{rva:x}', None)
    if (ctx.private / 'claims.json').exists():
        (ctx.private / 'claims.json').write_text(json.dumps(claims, indent=2) + '\n')
    ctx.say('released' + (': ' + ', '.join(closed) if closed else ' locally (close the claim issue on GitHub if any)'))
    if not filed and args.reason and args.reason != 'giving the function back':
        ctx.say(f'to keep what you learned for the next drafter, add --category <{"|".join(giveup.CATEGORIES)}> '
                '--tried "..." --still-differs "..." --suspected-cause "..." (the record is words and numbers only)')
    return OK, {'rva': f'0x{rva:x}', 'closed': closed, 'giveup': filed}, \
        (f'{ctx.cli} submit --notes-only --dry-run' if filed else f'{ctx.cli} next')


def file_giveup(ctx, rva, args):
    """Write the give-up record for a released function from the arguments and the task's last compare."""
    similarity, model = None, None
    source = getattr(args, 'draft_from', None)
    explicit_score = getattr(args, 'best_similarity', None)
    distance = getattr(args, 'best_distance', None)
    if source and explicit_score is None and distance is None:
        raise Stop(USAGE, '--draft-from needs --best-similarity or --best-distance measured for that source')
    for task_dir in sorted((ctx.private / 'tasks').glob('*')) if (ctx.private / 'tasks').is_dir() else ():
        last = attempt_progress.read_json(task_dir / 'last-compare.json')
        for fn in last.get('functions', []):
            if fn.get('rva') == f'0x{rva:x}':
                measured = (last.get('progress') or {}).get(f'0x{rva:x}') or {}
                if measured.get('total'):
                    similarity = round(100 * measured['value'] / measured['total'], 2)
                model = last.get('model')
    config = load_config(ctx)
    model = model or config.get('model') or config.get('drafted_by') or 'unknown'
    rec = dict(category=args.category, tried=args.tried or [], still_differs=args.still_differs or '',
               suspected_cause=args.suspected_cause or '', model=str(model)[:59], harness=ctx.cli.lstrip('./'),
               lane='contributor', best_code=dict(kind='note', ref=args.note) if args.note else dict(kind='none'))
    if distance is not None:
        rec['best_distance'] = distance
    elif explicit_score is not None:
        rec['best_similarity'] = explicit_score
        if basis := getattr(args, 'similarity_basis', None):
            rec['similarity_basis'] = basis
    elif similarity is not None:
        rec['best_similarity'] = similarity
        rec['similarity_basis'] = 'aligned matching bytes of the last compare'
    try:
        path, added = giveup.add(ctx.repo, f'0x{rva:x}', {k: rec[k] for k in giveup.KEYS if k in rec},
                                 draft_from=source, draft_declarations=getattr(args, 'draft_declarations', None))
    except (ValueError, OSError) as exc:
        raise Stop(USAGE, f'give-up record not written: {exc}') from None
    ctx.say(('give-up record written: ' if added else 'give-up record already there: ') + path.relative_to(ctx.repo).as_posix())
    return path.relative_to(ctx.repo).as_posix()


def write_source(path, text):
    """A unit file with LF line ends on every platform: the source digest hashes the bytes on disk,
    and text mode on Windows would write CRLF and change the digest."""
    Path(path).write_text(text, encoding='utf-8', newline='\n')


# Header lines that appear once per unit: a second copy is boilerplate, not information.
HEADER_ONCE = re.compile(r'^//[ \t]*(?:Source exposure:|Code origin:|SPDX-License-Identifier:|Adapted bodies:)')
HEADER_COMPARED = re.compile(r'^//[ \t]*(0x[0-9a-fA-F]+)(?:[ \t]|$)')


def merge_header_additions(text, blocks):
    """`text` with the header metadata of newly added functions merged into its leading `//` block.

    Each block is the comment a skeleton renders for one function. Its compared `// 0x<rva> Name`
    line and its label lines are added to the unit's existing header (inside the unbroken run of
    `//` lines at the top, which is where the compared-function parser reads); its one-per-unit
    lines (source exposure, code origin, SPDX, adapted bodies, with their continuation lines) are
    kept only when the header has none yet, and a line the header already has is not repeated. A
    placeholder (`SKELETON_TODO_*`) of a skipped line is appended to the existing line, so the added
    functions still have to be answered for before the unit is publishable.
    """
    from digest_v2 import LABEL_WORD
    lines = text.split('\n')
    end = 0
    while end < len(lines) and lines[end].startswith('//'):
        end += 1
    head, rest = lines[:end], lines[end:]
    for block in blocks:
        entries = []  # (is one-per-unit, [lines]); continuation lines follow their one-per-unit line
        for line in block.rstrip('\n').split('\n'):
            if not line.strip():
                continue
            if HEADER_ONCE.match(line):
                entries.append((True, [line]))
            elif entries and entries[-1][0] and line.startswith('//') and not HEADER_COMPARED.match(line) \
                    and not LABEL_WORD.search(line):
                entries[-1][1].append(line)
            else:
                entries.append((False, [line]))
        for once, group in entries:
            first = group[0]
            if once:
                key = HEADER_ONCE.match(first).group(0).strip()
                at = next((i for i, ln in enumerate(head) if ln.strip().startswith(key)), None)
                if at is not None:
                    # An unfilled placeholder in the new block still has to be answered for the added
                    # functions, so it rides on the existing line instead of repeating the line.
                    todo = re.search(r'SKELETON_TODO\w*', first)
                    if todo and todo.group(0) not in head[at]:
                        head[at] += f'; {todo.group(0)} (state it for the added functions)'
                    continue
            elif first in head:
                continue
            else:
                m = HEADER_COMPARED.match(first)
                if m and any((c := HEADER_COMPARED.match(ln)) and int(c.group(1), 16) == int(m.group(1), 16)
                             for ln in head):
                    continue
            head += group
    return '\n'.join(head + rest)


def pdb_hints(repo, fns):
    """Lines naming the CrashLogger-PDB layout header (and names) of the functions, from the committed
    reconstruction/generated output; nothing, silently, when that is absent or knows none of them."""
    try:
        import pdb_types
        return pdb_types.hint_for_rvas([fn['rva'] for fn in fns], repo)
    except Exception:  # an optional hint must never stop `start`
        return []


SYMBOL_SOURCE_IDS = {'a': 'tesv-2013-map', 'b': 'fo4-pdb', 'c': 'fnv-x360-pdb', 'd': 'fnv-x360-pdb',
                     'e': 'fnv-x360-pdb'}
SYMBOL_NAME_CAP = 12


def symbol_name_hints(repo, cls, fns=(), cap=SYMBOL_NAME_CAP):
    """Lines listing member names that sibling-build symbol files give for the class, each with the
    source-id to label it with; nothing, silently, when the data is absent or the class has none."""
    try:
        entry = json.loads((repo / 'data/symbol-names.json').read_text())['classes'].get(cls) or {}
        cands = entry.get('candidates') or {}
        corr = json.loads((repo / 'data/name-corroboration.json').read_text()).get('functions') or {}
        build = target_manifest(repo)['build_id']

        def ids(keys):
            return sorted({SYMBOL_SOURCE_IDS[k] for k in keys if k in SYMBOL_SOURCE_IDS})
        lines = []
        for fn in fns:
            seen = ids((corr.get(f'{build}-0x{fn["rva"]:x}') or {}).get('confirmed') or '')
            if seen:
                lines.append(f'Symbol sources with the member name of 0x{fn["rva"]:x}: {", ".join(seen)}')
        shown = sorted(cands)[:cap]
        if shown:
            more = len(cands) - len(shown)
            lines.append(f'Symbol-name candidates for {cls} (sibling builds; candidates only, never evidence of which '
                         f'function is which; label a name you take SYMBOLS(<source-id>)): '
                         + ', '.join(f'{n} [{"/".join(ids(cands[n]))}]' for n in shown)
                         + (f' and {more} more in data/symbol-names.json' if more > 0 else ''))
        return lines if shown else []
    except Exception:  # an optional hint must never stop `start`
        return []


def pdb_fact_lines(ctx, fns):
    """The full pdb_facts text for each function, local files included; never stops the caller."""
    import pdb_facts
    lines = []
    for fn in fns:
        try:
            lines += pdb_facts.render(pdb_facts.collect(ctx.repo, fn['rva'], env=ctx.env)).split('\n')
        except Exception as exc:  # optional facts must never stop `start`
            lines.append(f'PDB facts for 0x{fn["rva"]:x} unavailable: {exc}')
    return lines


def pdb_warnings(ctx, task, root):
    """Advisory findings where the draft's name, signature or size disagrees with a known PDB fact."""
    import pdb_facts
    source = ''
    for rel in task.get('contrib', {}).get('unit', []) or [task['compiled']]:
        try:
            source += (Path(root) / rel).read_text(encoding='utf-8', errors='replace') + '\n'
        except OSError:
            pass
    out = []
    for fn in task['functions']:
        try:
            rva = parse_rva(fn['rva'])
            name = (fn.get('name') or '') or fn.get('symbol', '')
            out += [f'0x{rva:x}: {w}' for w in pdb_facts.agreement(Path(root), rva, name, source, fn.get('size'))]
        except Exception:  # an advisory check must never stop `compare`
            pass
    return out


def unit_claims(root, rvas):
    """Find source units that claim any of the requested RVAs."""
    import pdb_types
    paths = None
    if rvas and (root / '.git').exists():
        addresses = '|'.join(f'{rva:x}' for rva in sorted(rvas))
        scan = subprocess.run(['git', 'grep', '-ilz', '--untracked', '-E',
                               rf'0x0*({addresses})([^[:xdigit:]]|$)',
                               '--', ':(glob)reconstruction/**/*.cpp', ':(glob)reconstruction/**/*.h',
                               ':(exclude)reconstruction/generated/crashlogger_pdb/**'],
                              cwd=root, capture_output=True)
        if scan.returncode in (0, 1):
            paths = [root / path for path in scan.stdout.decode('utf-8').split('\0') if path]
    if paths is None:
        paths = (root / 'reconstruction').rglob('*')
    found = {}
    for path in paths:
        if path.suffix not in ('.cpp', '.h'):
            continue
        unit = path.with_suffix('.cpp').relative_to(root).as_posix()
        if pdb_types.is_generated(unit) or not UNIT_PATH.fullmatch(unit):
            continue
        if path.suffix == '.h' and not (root / unit).is_file():
            continue
        source = path.read_text(encoding='utf-8-sig', errors='replace')
        for rva in rva_headers.claimed_rvas([source]) & rvas:
            found.setdefault(rva, set()).add(unit)
    return found


def practice_unit(root, rvas):
    found = unit_claims(root, rvas)
    for rva, units in found.items():
        if len(units) > 1:
            raise Stop(USAGE, f'{rva:#x} is claimed by several units: {", ".join(sorted(units))}')
    if not found:
        return None
    units = set().union(*found.values())
    if len(units) != 1 or len(found) != len(rvas):
        raise Stop(USAGE, 'one unit per practice task: give RVAs claimed by the same unit')
    return units.pop()


def start_unit(ctx, stem, rvas, args, claimed_unit):
    import pdb_types

    requested = getattr(args, 'unit', None)
    if requested and (not UNIT_PATH.fullmatch(requested) or not requested.endswith('.cpp')
                      or pdb_types.is_generated(requested) or not (ctx.repo / requested).is_file()):
        raise Stop(USAGE, '--unit must be an existing reconstruction .cpp path')
    claims = unit_claims(ctx.repo, rvas) if not args.practice else {}
    claimants = set().union(*claims.values())
    if claims and not set.intersection(*claims.values()):
        raise Stop(USAGE, 'the requested RVAs are claimed by different units; start them separately: '
                   + ', '.join(f'{rva:#x} ({", ".join(sorted(units))})' for rva, units in sorted(claims.items())))
    if requested and (claimed_unit and requested != claimed_unit or claims and
                      any(requested not in units for units in claims.values())):
        raise Stop(USAGE, '--unit must claim the requested RVAs already assigned to a unit: '
                   + ', '.join(sorted(claimants or {claimed_unit})))
    if cpp := (requested or claimed_unit):
        return cpp

    candidates = set.intersection(*claims.values()) if claims else {
        rel for p in (ctx.repo / 'reconstruction').rglob(f'{stem}*.cpp')
        if (p.stem == stem or p.stem.startswith(stem + '_'))
        and (rel := p.relative_to(ctx.repo).as_posix()) and UNIT_PATH.fullmatch(rel)
        and not pdb_types.is_generated(rel)}
    if args.area and not claims:
        candidates = {p for p in candidates if Path(p).parent.as_posix() == f'reconstruction/{args.area}'}
    if len(candidates) > 1:
        raise Stop(USAGE, 'several units fit; rerun start with --unit and one of:\n  ' + '\n  '.join(sorted(candidates)))
    return next(iter(candidates), None)


def start_names(root, functions):
    """Replace placeholders only with a name tied to the RVA."""
    import pdb_facts
    import pdb_types
    from lint_reconstruction import LABEL_LINE

    pending = {fn['rva'] for fn in functions if BARE_PLACEHOLDER.fullmatch(fn.get('name', '').split('::')[-1])}
    if not pending:
        return functions
    claims = unit_claims(root, pending)
    pdb = pdb_types.load_tree(root)
    alignment = attempt_progress.read_json(root / 'data/symbol-alignment.json')
    name_in = re.compile(r'(?<![\w:])' + PLAIN_NAME.pattern + r'(?![\w:])')
    resolved = []
    for fn in functions:
        rva = fn['rva']
        if rva not in pending:
            resolved.append(fn)
            continue
        hints = {}
        for unit in claims.get(rva, ()):
            for path in (root / unit, (root / unit).with_suffix('.h')):
                if not path.is_file():
                    continue
                text = path.read_text(encoding='utf-8-sig')
                for claimed, declaration in rva_headers.compact_claims(text):
                    if claimed == rva and (m := name_in.search(declaration)) and not BARE_PLACEHOLDER.fullmatch(m[2]):
                        name = m[0]
                        labels = [line['labels'] for line in map(LABEL_LINE.match, text.splitlines())
                                  if line and name in re.split(r'\s*,\s*', line['names'])]
                        hints.setdefault(name, labels[0] if labels else None)
        owner = fn.get('name', '').rpartition('::')[0]
        hints = {name: label for name, label in hints.items() if not owner or name.startswith(owner + '::')}
        if len(hints) > 1:
            hints.clear()
        facts = pdb_facts.committed_facts(root, rva, tree=pdb, alignment=alignment)
        for fact in (facts.get('crashlogger'), facts.get('alignment')):
            if hints:
                break
            raw = (fact or {}).get('name') or ''
            decorated = re.fullmatch(r'\?(\w+)@(\w+)@@.*', raw)
            if decorated:
                raw = f'{decorated[2]}::{decorated[1]}'
            if m := (name_in.search(raw) or name_in.search(raw.replace('__', '::'))):
                if (not owner or owner == m[1]) and not BARE_PLACEHOLDER.fullmatch(m[2]):
                    hints.setdefault(m[0], fact['label'])
        if hints:
            name, label = next(iter(hints.items()))
            fn = dict(fn, name=name, name_origin=label or fn.get('name_origin', 'GUESS'))
        resolved.append(fn)
    return resolved


def start(ctx, args, quiet=False):
    from unit_skeleton import BODY_MARKER, SkeletonError, contributor_files, unit_stem

    data = inventory(ctx.repo)
    target = target_manifest(ctx.repo)
    fns = []
    for text in args.rva:
        fn = resolve_function(ctx, data, parse_rva(text))
        if fn is None:
            raise Stop(USAGE, f'{text} is not in data/progress.json or the published target-hash list',
                       f'{ctx.cli} next')
        if fn['status'] == 'matched' and not args.practice:
            raise Stop(USAGE, f'{text} is already matched; use --practice to try it as an exercise', f'{ctx.cli} next')
        fns.append(fn)
    fns = start_names(ctx.repo, fns)
    given = getattr(args, 'class_name', None)
    if given is not None and not PLAIN_NAME.fullmatch(f'{given}::Function'):
        raise Stop(USAGE, f'--class must be a plain class name such as TESObjectCELL, not {given!r}')
    if given:
        # Use the contributor's class spelling consistently in paths, declarations and function names.
        for i, fn in enumerate(fns):
            name = fn.get('name') or ''
            owner, qualified, method = name.rpartition('::')
            if not qualified and FREE_NAME.fullmatch(method) and not BARE_PLACEHOLDER.fullmatch(method):
                raise Stop(USAGE, f'--class does not apply to free function {name}; omit --class to start it',
                           f'{ctx.cli} start {fn["rva"]:#x}')
            if owner == given or not (qualified or BARE_PLACEHOLDER.fullmatch(method)):
                continue
            if qualified and method in (owner, f'~{owner}'):
                method = f'~{given}' if method.startswith('~') else given
            fns[i] = dict(fn, name=f'{given}::{method}', name_origin='GUESS')
    member_names = [PLAIN_NAME.fullmatch(fn.get('name') or '') for fn in fns]
    free = all(FREE_NAME.fullmatch(fn.get('name') or '') for fn in fns)
    rvas = {fn['rva'] for fn in fns}
    claimed_unit = practice_unit(ctx.repo, rvas) if args.practice else None
    if not claimed_unit:
        if free and len(fns) != 1:
            raise Stop(USAGE, 'one unit per task: start free functions one RVA at a time')
        if not free and not all(member_names):
            raise Stop(USAGE, 'start takes one plain free-function name or plain Class::Method names from one class',
                       f'{ctx.cli} next')
        if len({match[1] for match in member_names if match}) > 1:
            raise Stop(USAGE, 'one unit per task: give functions of one class')
    if claimed_unit:
        stem = Path(claimed_unit).stem
        cls = None if free else stem
    else:
        cls = None if free else member_names[0][1]
        stem = unit_stem(cls, fns[0]['rva'])
    import unit_paths
    if args.area is not None and not unit_paths.area_accepted(args.area):
        raise Stop(USAGE, f'--area must be one of the areas in tools/unit_paths.py (for example skyrim/ai), '
                   f'not {args.area!r}')
    cpp = start_unit(ctx, stem, rvas, args, claimed_unit)
    if cpp:
        header = Path(cpp).with_suffix('.h').as_posix()
        area = Path(cpp).parent.relative_to('reconstruction').as_posix()
    else:
        area, header, cpp = unit_files(ctx.repo, stem, args.area or ('unmapped/support' if free else None), index={})
    if area is None:
        raise Stop(USAGE, f'no area rule for class {cls} (reconstruction/README.md, "Layout")',
                   f'{ctx.cli} start {" ".join(args.rva)} --area <area>  (ask in your claim issue which area)')
    tid = task_id_for(Path(cpp).stem, args.practice)
    tdir = task_dir(ctx, tid)
    old = attempt_progress.read_json(tdir / 'task.json')
    if old and old.get('compiled') != cpp:
        tdir = task_dir(ctx, f'{tid}-{hashlib.sha256(cpp.encode()).hexdigest()[:12]}')
        old = attempt_progress.read_json(tdir / 'task.json')
    exe = require_exe(ctx, target)['path']
    tdir.mkdir(parents=True, exist_ok=True)
    names = public_names(ctx.repo, data)
    smap = json.loads(symbol_map_path(ctx.repo, target['build_id']).read_text())['symbols']
    by_rva = {e['rva']: n for n, e in smap.items() if isinstance(e, dict) and isinstance(e.get('rva'), int)}
    functions = {parse_rva(f['rva']): f for f in old.get('functions', [])}
    for fn in fns:
        dest, _pack = write_pack(ctx, exe, fn, names)
        entry = functions.setdefault(fn['rva'], {
            'rva': f'0x{fn["rva"]:x}', 'size': fn['size'],
            'symbol': by_rva.get(fn['rva']) or f'unbound:{fn["name"]}',
            'function_id': fn['id'], 'community_name': fn['name'], 'pack': str(dest)})
        if BARE_PLACEHOLDER.fullmatch((entry.get('community_name') or '').split('::')[-1]):
            entry['community_name'] = fn['name']
            if entry['symbol'].startswith('unbound:'):
                entry['symbol'] = by_rva.get(fn['rva']) or f'unbound:{fn["name"]}'
        if entry['community_name'] == fn['name'] and fn.get('name_origin'):
            entry['name_origin'] = fn['name_origin']
    recipe = args.recipe or old.get('recipe') or DEFAULT_RECIPE
    sibling = sibling_section(ctx, cls, sorted(functions)) if cls else []
    if sibling:
        (tdir / 'sibling.md').write_text(f'# {cls}: pointers into the FNV decompilation (private)\n'
                                         + '\n'.join(sibling) + '\n')
    from header_index import advice as header_advice
    declaration_advice = [hint for match in member_names if match for hint in header_advice(ctx.repo, *match.groups())]
    created = []
    existing = (ctx.repo / cpp).is_file()
    extending_skeleton = existing and BODY_MARKER in (ctx.repo / cpp).read_text(encoding='utf-8-sig')
    if not args.practice and (not existing or extending_skeleton) and not getattr(args, 'code_origin', None) and ctx.interactive:
        args.code_origin = input('Code origin: describe the actual sources and any adaptation '
                                 '(leave blank to fill the required header after drafting): ').strip() or None
    if not (ctx.repo / cpp).exists():
        if args.practice:
            raise Stop(USAGE, f'{cpp} does not exist; practice works on accepted units only')
        drafted = args.drafted_by or load_config(ctx).get('drafted_by')
        if not drafted:
            raise Stop(CONSENT, 'say who drafts the unit (a person, and the AI model if one writes code)',
                       f'{ctx.cli} start {" ".join(args.rva)} --drafted-by "<your name>, assisted by <model or none>"')
        inputs = [dict(fn, pack=functions[fn['rva']].get('pack')) for fn in fns]
        if cleanup := getattr(args, 'deleting_cleanup', None):
            for fn in inputs:
                if fn['name'].split('::')[-1].startswith('~'):
                    fn['destructor'] = {'kind': 'scalar deleting destructor', 'complete_form': cleanup}
        try:
            _h, h_text, _cpp, cpp_text, declaration_advice, recipe = contributor_files(
                ctx.repo, inputs, cls, area, drafted, recipe, sources=ctx.local / 'sources',
                code_origin=getattr(args, 'code_origin', None))
        except SkeletonError as exc:
            raise Stop(USAGE, str(exc)) from None
        if not (ctx.repo / header).exists():
            (ctx.repo / header).parent.mkdir(parents=True, exist_ok=True)
            write_source(ctx.repo / header, h_text)
            created.append(header)
        write_source(ctx.repo / cpp, cpp_text)
        created.append(cpp)
        save_config(ctx, drafted_by=drafted)
    if not args.practice and (created or extending_skeleton):
        drafted = args.drafted_by or load_config(ctx).get('drafted_by') or 'unknown'
        text = (ctx.repo / cpp).read_text()
        claimed = rva_headers.claimed_rvas([text, (ctx.repo / header).read_text() if (ctx.repo / header).is_file() else ''])
        # An older unit can already carry the function marker outside its leading comment block.
        claimed.update(int(marker[1], 16) for line in text.splitlines()
                       if (marker := HEADER_COMPARED.match(line.lstrip())))
        additions = []
        for fn, match in zip(fns, member_names):
            if fn['rva'] not in claimed:
                _h, metadata = skeleton(fn, cls, match[2] if match else fn['name'], area, drafted, recipe,
                                        getattr(args, 'code_origin', None))
                additions.append(metadata.split('#include', 1)[0])
        if additions:
            write_source(ctx.repo / cpp, merge_header_additions(text, additions))
        ctx.say('Function header metadata is prepared. Add the new declarations and bodies; '
                'replace each code-origin placeholder truthfully before compare. '
                'Preflight removes unused starter header lines it can identify. '
                'Accepted companions are re-confirmed by the project.')
    elif not args.practice:
        ctx.say('Existing source kept as written. Add any new function declarations, bodies, and provenance yourself.')
    if not quiet:
        for hint in declaration_advice:
            ctx.say(hint)
    prof = contrib_profile(ctx, getattr(args, 'profile', None))
    save_config(ctx, profile=prof['name'])
    task = {'task_id': tdir.name, 'build_id': target['build_id'], 'compiled': cpp, 'recipe': recipe,
            'symbols': 'symbols.json', 'functions': sorted(functions.values(), key=lambda f: parse_rva(f['rva'])),
            'drafter_model': getattr(args, 'model', None) or load_config(ctx).get('model') or load_config(ctx).get('drafted_by'),
            'contrib': {'practice': bool(args.practice), 'unit': [header, cpp], 'profile': prof['name']}}
    branch = None
    if not args.no_branch and not args.practice:
        branch = f'contrib/{tdir.name[len("contrib-"):]}'
        exists = ctx.run(['git', 'rev-parse', '--verify', '--quiet', branch], cwd=ctx.repo,
                         capture_output=True).returncode == 0
        git(ctx, 'switch', *([] if exists else ['-c']), branch)
    task['contrib'].update(worktree=str(ctx.repo.resolve()),
                           branch=branch or git(ctx, 'symbolic-ref', '--quiet', '--short', 'HEAD', check=False))
    (tdir / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
    refresh_symbols(ctx, tdir, target['build_id'])
    packs = [f['pack'] for f in task['functions']]
    pdb, suggestions = pdb_names(ctx), {}
    for fn in fns:
        found = pdb.suggest(fn['rva']) if pdb else None
        if found:
            suggestions[f'0x{fn["rva"]:x}'] = {'name': found.name, 'label': found.label, 'source': found.source}
    import x64_lookup
    x64_record, x64_lines = x64_lookup.hints(ctx.private / 'x64-index', ctx.repo / 'data/x64-index.json',
                                             ctx.local / 'sources', find_objdump(ctx), exe, fns)
    x64_lookup.write_record(tdir, x64_record)
    if not quiet:
        giveup_notice(ctx, [parse_rva(fn['rva']) for fn in fns])
        for line in x64_lines:
            ctx.say(line)
        for rva, found in suggestions.items():
            ctx.say(f'CrashLogger PDB name for {rva}: {found["name"]} (a suggestion, not evidence; '
                    f'if you use it, label it {found["label"]})')
        for p in packs:
            ctx.say(f'pack (private, read it locally, never paste it anywhere): {p}/bytes.txt'
                    + (' and listing.txt' if (Path(p) / 'listing.txt').is_file() else '')
                    + (' and decomp.c (untrusted hint)' if (Path(p) / 'decomp.c').is_file() else ''))
        if sibling:
            ctx.say(f'sibling source pointers (FNV; shape and names only, never evidence): {tdir / "sibling.md"}')
        for line in pdb_hints(ctx.repo, fns):
            ctx.say(line)
        if cls:
            for line in symbol_name_hints(ctx.repo, cls, fns):
                ctx.say(line)
        for line in pdb_fact_lines(ctx, fns):
            ctx.say(line)
        ctx.say(f'unit: {header} and {cpp}' + (' (skeleton created)' if created else ''))
        ctx.say(f'profile {prof["name"]}: read {"; ".join(prof["contrib_docs"])}; '
                + attempt_progress.guidance(prof['stuck_after'])
                + f' Hard cap: {prof["contrib_max_tries"]} compare runs. {prof["cost"]}')
    return OK, {'task': tdir.name, 'unit': [header, cpp], 'created': created, 'packs': packs, 'branch': branch,
                'practice': bool(args.practice), 'declarations': declaration_advice,
                'sibling': str(tdir / 'sibling.md') if sibling else None, 'sibling_x64': str(tdir / 'sibling_x64.json'),
                 'pdb': pdb_hints(ctx.repo, fns),
                'pdb_facts': pdb_fact_lines(ctx, fns),
                'profile': prof['name'], 'read': prof['contrib_docs'], 'max_tries': prof['contrib_max_tries'],
                'cost': prof['cost'], **({'pdb_names': suggestions} if suggestions else {})}, \
        f'edit {cpp}, then {ctx.cli} compare'


def cmd_decomp(ctx, args):
    import contrib_decompiler
    rva = parse_rva(args.rva)
    target = target_manifest(ctx.repo)
    require_exe(ctx, target)
    dest = ctx.private / 'packs' / target['build_id'] / f'0x{rva:x}'
    output = contrib_decompiler.decompile(ctx, rva, dest)
    ctx.say(f'private untrusted hint, never paste publicly: {output}')
    return OK, {'decomp': str(output)}, f'read the private hint locally; use {ctx.cli} compare for evidence'


def cmd_facts(ctx, args):
    rva = parse_rva(args.rva)
    lines = pdb_fact_lines(ctx, [{'rva': rva}])
    for line in lines:
        ctx.say(line)
    earlier = giveup_notice(ctx, [rva])
    return OK, {'rva': f'0x{rva:x}', 'pdb_facts': lines, 'giveups': earlier}, f'{ctx.cli} start 0x{rva:x}'


def cmd_start(ctx, args):
    return start(ctx, args)


def candidate_size(obj_path, symbol):
    from bind import defined_functions
    from pecoff import CoffObject
    try:
        obj = CoffObject(Path(obj_path).read_bytes())
        sec = defined_functions(obj).get(symbol)
        return obj.section(sec).raw_size if sec else None
    except Exception:  # noqa: BLE001 - a size for display only
        return None


def compare_with_local_dir(ctx, task_file, built, exe, report_path, diagnostics):
    """Use the unchanged comparator API's existing private_root argument for shared storage.

    The verifier CLI fixes that argument to its own checkout's .local. Keep its default path
    unchanged; contributors with an override use the same engine and report validator here.
    """
    import compare_runtime
    import verify_function
    from pecoff import Reject
    task, recipe, symbols, manifest = verify_function.load_task_file(task_file)
    if not verify_function.under(diagnostics, ctx.local):
        raise verify_function.TaskFileError(f'diagnostics must stay under {ctx.local}')
    if report_path.resolve() == diagnostics.resolve():
        raise verify_function.TaskFileError('report and diagnostics paths must differ')
    for stale in (report_path, diagnostics):
        if stale.exists():
            stale.unlink()
    try:
        report = compare_runtime.compare(
            task, json.loads(manifest.read_text()), recipe.read_bytes(),
            json.loads(built['build_record'].read_text()), built['object'].read_bytes(),
            Path(exe).read_bytes(), symbols.read_bytes(), diagnostics=diagnostics, private_root=ctx.local)
        report = verify_function.check_report(report)
    except (OSError, ValueError, Reject) as exc:
        report = verify_function.error_record(task, 2, str(exc))
        report_path.write_text(json.dumps(report, indent=2) + '\n')
        return 2
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    return 0 if report['result'] == 'pass' else 1


UNIT_RECIPE = re.compile(r'\breconstruction/recipes/[a-zA-Z0-9_.-]+\.json')


def unit_recipe(root, compiled, fallback):
    """The recipe the unit names, found the way CI finds it (the first recipe path in the source),
    else `fallback`."""
    try:
        found = UNIT_RECIPE.search((Path(root) / compiled).read_text(errors='replace'))
    except OSError:
        return fallback
    if not found:
        return fallback
    if not (Path(root) / found.group(0)).is_file():
        raise Stop(UNIT, f'{compiled} names recipe {found.group(0)}, which does not exist',
                   'name a recipe under reconstruction/recipes/ or drop the Recipe: line')
    return found.group(0)


def compare_function(ctx, root, tdir, task, fn, built, recipe_rel, exe, target, fdir):
    """Compare one function of a compiled unit with the comparator; the report is written to `fdir`."""
    import verify_function
    rva = parse_rva(fn['rva'])
    vtask = {'task_id': f'{task["task_id"]}-{rva:x}', 'build_id': task['build_id'],
             'target_image_sha256': target['image_sha256'], 'rva': rva, 'size': fn['size'],
             'symbol': fn['symbol'], 'source_revision': built['digest'], 'source_path': task['compiled'],
             'recipe_sha256': built['recipe_sha256']}
    (fdir / 'task-file.json').write_text(json.dumps({
        'verify_task_schema': 1, 'task': vtask, 'recipe': str(root / recipe_rel),
        'symbols': str(tdir / 'symbols.json'), 'manifest': str(root / 'builds/target.json')}, indent=2))
    diag_root = ctx.local if ctx.env.get('SR_LOCAL_DIR') else verify_function.PRIVATE_ROOT
    diag = diag_root / 'contrib' / 'diagnostics' / f'{task["task_id"]}-{rva:x}.json'
    if ctx.env.get('SR_LOCAL_DIR'):
        compare_with_local_dir(ctx, fdir / 'task-file.json', built, exe, fdir / 'report.json', diag)
    else:
        verify_function.run(fdir / 'task-file.json', built['object'], built['build_record'], exe,
                            fdir / 'report.json', diag)
    return json.loads((fdir / 'report.json').read_text())


def retry_under_alternatives(ctx, root, tdir, task, recipe, results, exe, target, tool, out):
    """Retry the failed functions of a unit under each alternative flag set of its recipe (accept_also).

    Advisory: `results` keep the verdict under the unit's own recipe; a function that byte-matches under
    an alternative gets `also_matches` naming the recipe and flags, because it is accepted under them
    only once the unit's `Recipe:` line names that recipe (the CI hash job and the second host compile
    with the recipe the unit names). One compile per alternative covers every function of the unit, so
    the answer also says whether the functions that already pass keep passing under it.
    """
    import recipe_alternatives as alts
    from pecoff import Reject
    from bind import BINDING_REASONS
    # A function nothing was compared for (an unbound symbol) says nothing about the flags.
    failed = [r for r in results if r['result'] != 'pass' and r['reason'] not in BINDING_REASONS]
    notes = []
    if not failed:
        return notes
    try:
        frames = alts.EhFrames.from_bytes(Path(exe).read_bytes()) if any(
            a['requires'] == 'target-no-eh-frame' for a in alts.alternatives(root, recipe)) else None
    except (OSError, ValueError, Reject):
        frames = None
    for alt in alts.alternatives(root, recipe):
        wanted = [r for r in failed if 'also_matches' not in r
                  and alts.applies(alt, frames, parse_rva(r['rva']), r['target_size'])]
        if not wanted:
            continue
        alt_out = out / ('alt-' + alt['id'])
        try:
            built = compile_unit(ctx, root, task['compiled'], alt['recipe'], alt_out, tool)
        except Stop as exc:
            notes.append(f'retry {alt["id"]} ({alts.change_text(alt)}): not compiled ({exc.message})')
            continue
        passing = {}
        for fn in task['functions']:
            rva = parse_rva(fn['rva'])
            fdir = alt_out / f'0x{rva:x}'
            fdir.mkdir(parents=True, exist_ok=True)
            passing[f'0x{rva:x}'] = compare_function(ctx, root, tdir, task, fn, built, alt['recipe'], exe, target,
                                                     fdir).get('result') == 'pass'
        won = [r['rva'] for r in wanted if passing.get(r['rva'])]
        for r in results:
            if r['rva'] in won:
                r['also_matches'] = dict(id=alt['id'], recipe=alt['recipe'], recipe_sha256=built['recipe_sha256'],
                                         flags=alts.flags_of(root, alt['recipe']), change=alts.change_text(alt),
                                         unit_passes_all=all(passing.values()))
        if won:
            line = alts.match_line(root, alt)
            others = [rva for rva, ok in passing.items() if not ok]
            if others:
                line += (' Under these flags ' + ', '.join(others) + ' would not pass, so a unit that holds them '
                         'too needs them in a unit of their own.')
            notes.append(f'{", ".join(won)}: {line}')
    return notes


def prepare_draft_compare(ctx, root, target, rva, ident):
    import bind
    import claimable

    build = target['build_id']
    draft = giveup.draft_path(root, build, rva)
    if not draft.is_file():
        raise Stop(USAGE, f'no public draft for {rva:#x}')
    compiled = draft.relative_to(root).as_posix()
    if ident:
        tdir, task = load_task(ctx, ident)
        functions = [fn for fn in task['functions'] if parse_rva(fn['rva']) == rva]
        if not functions or task['build_id'] != build:
            raise Stop(USAGE, f'{rva:#x} is not a function of the specified task and build')
    else:
        entry = find_function(inventory(root), rva)
        size = entry['size'] if entry else claimable.published_sizes(root).get(rva)
        name = bind.header_declarations(root, compiled).get(rva, {}).get('name')
        if size is None or not name:
            raise Stop(USAGE, f'the public draft for {rva:#x} needs a target size and function name',
                       f'{ctx.cli} compare <prepared-task> --draft {rva:#x}')
        functions = [{'rva': hex(rva), 'size': size, 'community_name': name, 'symbol': f'unbound:{name}'}]
        task = {'build_id': build, 'recipe': DEFAULT_RECIPE}
    draft_scores = ctx.private / 'draft-scores'
    draft_scores.mkdir(parents=True, exist_ok=True)
    draft_task = Path(tempfile.mkdtemp(prefix=f'{rva:x}-', dir=draft_scores))
    if ident:
        for filename in ('symbols.json', 'bind-hints.json'):
            if (tdir / filename).is_file():
                shutil.copyfile(tdir / filename, draft_task / filename)
    task = dict(task, task_id=f'public-draft-{draft_task.name.replace("_", "-")}', functions=functions,
                compiled=compiled, symbols='symbols.json', contrib=dict(task.get('contrib', {}), unit=[compiled]))
    (draft_task / 'task.json').write_text(json.dumps(task) + '\n')
    return draft_task, task


def bind_attempt(root, tdir, out, exe, objdump):
    import auto_hints
    import bind

    candidate = out / 'candidate.obj'
    report = bind.bind(tdir, candidate, exe, objdump, repo=root)
    task = json.loads((tdir / 'task.json').read_text())
    if task.get('symbols', 'symbols.json').startswith('reports/'):
        return report, bind.describe(report, tdir)
    default_rvas, default_tls = bind.split_hints(bind.crt_defaults(root, task.get('build_id')))
    definitions = {parse_rva(fn['rva']) for fn in task['functions']}
    resolved = {}
    for row in report['references']:
        name, how = row['symbol'], row['how']
        if how.endswith('replaced'):
            continue
        if 'tls_offset' in row:
            value = f'tls:{row["tls_offset"]}'
            verified_default = default_tls.get(name) == parse_rva(row['tls_offset'])
        else:
            value = row['rva']
            rva = parse_rva(value)
            if rva in definitions:
                continue
            verified_default = default_rvas.get(name) == rva
        if verified_default or how == 'thread-local name' or (row.get('from') == 'funclet' and not how.endswith('hint')):
            resolved[name] = value
    written = auto_hints.write(tdir, resolved) if resolved else {}
    lines = [f'  wrote {bind.HINTS}: {json.dumps(written)}'] if written else []
    if objdump and (report['unbound_references'] or report['unbound_thread_locals']):
        for row in report['functions']:
            (out / row['rva']).mkdir(exist_ok=True)
        config = {'objdump': objdump, 'image': exe}
        added, skipped, notes = auto_hints.derive(tdir, out, report, config, repo=root)
        if added:
            lines.append(f'  wrote {bind.HINTS}: {json.dumps(added)}')
        lines += auto_hints.describe({}, skipped, notes)
        if added:
            second = bind.bind(tdir, candidate, exe, objdump, repo=root)
            report = auto_hints.merge_reports(report, second)
    return report, lines + bind.describe(report, tdir)


def count_attempts(root, task, results, history, digest):
    from bind import fallback_qualified, header_declarations
    from pr_autofix import function_span

    unit = root / task['compiled']
    sources = [p.read_text(encoding='utf-8-sig', errors='replace') for p in (unit, unit.with_suffix('.h')) if p.is_file()]
    declarations = header_declarations(root, task['compiled'])
    previous = {row['rva']: (run.get('source_revision'), row)
                for run in history for row in run.get('functions', [])}
    counted = set()
    for fn, row in zip(task['functions'], results):
        rva = row['rva']
        name = (declarations.get(parse_rva(rva), {}).get('name') or fallback_qualified(fn['symbol'])
                or fn.get('community_name'))
        bodies = []
        for source in sources:
            if name and (span := function_span(source, name)):
                bodies.append(source[span[0]:span[1]])
        revision = hashlib.sha256(bodies[0].encode()).hexdigest() if len(bodies) == 1 else None
        prior_digest, prior = previous.get(rva, (None, {}))
        prior_revision = prior.get('body_revision')
        changed = (revision != prior_revision if revision and prior_revision else
                   digest != prior_digest and bool(row['code_section_sha256'])
                   and row['code_section_sha256'] != prior.get('code_section_sha256'))
        if not prior or (changed and 'attempts' in prior):
            counted.add(rva)
        row['body_revision'] = revision
        row['attempts'] = prior.get('attempts', int(bool(prior))) + int(rva in counted)
    return counted


def run_compare(ctx, ident=None, root=None, retry=True, quiet=False, draft_rva=None):
    """Compile the task's unit and compare each function; returns (code, data, next)."""
    import verify_function
    say = (lambda _line: None) if quiet else ctx.say
    root = Path(root or ctx.repo)
    if draft_rva is None:
        tdir, task = load_task(ctx, ident, pick_current=True)
        if ident is None:
            say(f'using task {tdir.name} ({task["compiled"]})')
        target = target_manifest(root)
        if task.get('contrib', {}).get('practice'):
            unit = practice_unit(root, {parse_rva(fn['rva']) for fn in task['functions']})
            if unit and unit != task['compiled']:
                task['compiled'] = unit
                task['contrib']['unit'] = [Path(unit).with_suffix('.h').as_posix(), unit]
                (tdir / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
    else:
        target = target_manifest(root)
        tdir, task = prepare_draft_compare(ctx, root, target, draft_rva, ident)
    config = load_config(ctx)
    model = task.get('drafter_model') or config.get('model') or config.get('drafted_by')
    # Legacy comparison-only tasks may predate claims; new claims require attribution up front.
    exe = require_exe(ctx, target)['path']
    runs = tdir / 'runs'
    number = len([p for p in runs.glob('[0-9][0-9][0-9]')]) + 1 if runs.is_dir() else 1
    out = runs / f'{number:03d}'
    refresh_symbols(ctx, tdir, task['build_id'])
    warnings = pdb_warnings(ctx, task, root)
    for w in warnings:
        say(f'PDB warning (advisory; a byte match decides): {w}')
    recipe = unit_recipe(root, task['compiled'], task['recipe'])
    if recipe != task['recipe']:
        say(f'recipe: {recipe} (named by the unit; the task had {task["recipe"]})')
    tool = check_toolchain(ctx, root, recipe)
    if tool['status'] == 'ok':
        say(f'compiler: toolset {Path(tool["bin"]).parents[2].name} at {tool["root"]} (recipe pin)')
    built = compile_unit(ctx, root, task['compiled'], recipe, out, tool)
    objdump = find_objdump(ctx)
    _, bind_lines = bind_attempt(root, tdir, out, exe, objdump)
    task = json.loads((tdir / 'task.json').read_text())
    task['recipe'] = recipe
    results, current = [], {}
    for fn in task['functions']:
        rva = parse_rva(fn['rva'])
        fdir = out / f'0x{rva:x}'
        fdir.mkdir(parents=True, exist_ok=True)
        report = compare_function(ctx, root, tdir, task, fn, built, recipe, exe, target, fdir)
        m = re.search(r'at \+0x([0-9a-f]+)', report.get('detail') or '')
        cov = report.get('coverage') or {}
        results.append({'rva': f'0x{rva:x}', 'name': fn.get('community_name'), 'result': report.get('result'),
                        'reason': report.get('reason'), 'detail': verify_function.mask(str(report.get('detail'))),
                        'hint': verify_function.HINTS.get(report.get('reason') or '', ''),
                        'first_mismatch': f'+0x{m.group(1)}' if m else None,
                        'candidate_size': candidate_size(built['object'], fn['symbol']), 'target_size': fn['size'],
                        'coverage': {k: cov.get(k) for k in ('code_bytes_total', 'code_bytes_exact',
                                                             'code_bytes_by_reference', 'unwind')},
                        'code_section_sha256': (report.get('candidate') or {}).get('code_section_sha256')})
        alignment = None
        if report.get('result') == 'pass':
            alignment = dict(matching_bytes=fn['size'], target_bytes=fn['size'], matching_regions=1)
        elif objdump:
            import align
            align.attempt_summary(fdir, objdump, exe, built['object'],
                                  dict(fn, rva=rva), tdir / 'symbols.json')
            alignment = attempt_progress.read_json(fdir / 'align.json')
        current[f'0x{rva:x}'] = attempt_progress.measure(report, alignment)
        if objdump:
            import disasm
            disasm.write_side_by_side(fdir / 'side-by-side.txt', objdump, exe, built['object'], fn['symbol'],
                                      rva, fn['size'])
    retry_notes = retry_under_alternatives(ctx, root, tdir, task, recipe, results, exe, target, tool, out) if retry else []
    first = json.loads((out / f'0x{parse_rva(task["functions"][0]["rva"]):x}' / 'report.json').read_text())
    prof = contrib_profile(ctx, task.get('contrib', {}).get('profile'))
    history = [attempt_progress.read_json(path / 'summary.json') for path in sorted(runs.glob('[0-9][0-9][0-9]')) if path != out]
    finished_at = time.time()
    counted = count_attempts(root, task, results, history, built['digest'])
    measured = [run for run in history if any('attempts' in row for row in run.get('functions', []))]
    progress = attempt_progress.update(current, measured, counted=counted, now=finished_at)
    summary = {'model': model, 'progress': progress, 'task': task['task_id'], 'run': number, 'unit': task['compiled'], 'source_revision': built['digest'],
               'recipe': task['recipe'], 'recipe_sha256': built['recipe_sha256'],
               'compiler': 'pinned' if built['compiler'] in ('wine', 'native') else 'override',
               'image_sha256_pinned': True, 'comparator': first.get('comparator'),
               'contract_version': first.get('contract_version'), 'functions': results,
               'bind': [line.strip() for line in bind_lines], 'retry': retry_notes, 'practice': task.get('contrib', {}).get('practice', False),
               'private_dir': str(out)}
    passed = sum(r['result'] == 'pass' for r in results)
    say(f'run {number}: {passed}/{len(results)} pass ({summary["compiler"]} compiler)')
    for r in results:
        size = f'{r["candidate_size"]}/{r["target_size"]} B'
        say(f'  {r["rva"]} {r["name"]}: {r["result"].upper()} {r["reason"]} {r["first_mismatch"] or ""} '
            f'{size} (attempts: {r["attempts"]})')
        if r['result'] != 'pass':
            say(f'    hint: {r["hint"]}')
    for line in retry_notes:
        say('  ' + line)
    for line in bind_lines:
        say(line)
    if objdump:
        for r in results:
            say(f'private side-by-side: {out / r["rva"] / "side-by-side.txt"} (read locally; never paste it anywhere)')
    nxt = f'{ctx.cli} submit --dry-run' if passed == len(results) else f'revise the source, then {ctx.cli} compare'
    summary['profile'], summary['max_tries'] = prof['name'], prof['contrib_max_tries']
    for rva, metric in progress.items():
        say(attempt_progress.describe(rva, metric, prof['stuck_after']))
    if draft_rva is not None:
        (out / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
        return (OK if passed == len(results) else FAILED), summary, None
    failed = [r['rva'] for r in results if r['result'] != 'pass']
    stuck = [advice for rva in failed
             if (advice := attempt_progress.stuck_advice(rva, progress[rva], prof['stuck_after'], finished_at))]
    for advice in stuck:
        say(advice)
    say(attempt_progress.guidance(prof['stuck_after']))
    for line in note_reminders(ctx, task, results):
        say(line)
    if failed and len(stuck) == len(failed) and not summary['practice']:
        nxt = ' | '.join(stuck)
    elif failed and all(r['attempts'] >= prof['contrib_max_tries'] for r in results if r['rva'] in failed) and not summary['practice']:
        first_rva = failed[0]
        nxt = (f'stop: hard cap {prof["contrib_max_tries"]} reached under profile {prof["name"]}; tell the person, then '
               f'{ctx.cli} release {first_rva} --reason "<one line>"'
               + (f', or continue with a stronger model ({ctx.cli} start {first_rva} --profile full)'
                  if prof['name'] == 'cheap' else ''))
    if summary['practice'] and passed == len(results):
        nxt = f'{ctx.cli} next'
    (out / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    (tdir / 'last-compare.json').write_text(json.dumps(summary, indent=2) + '\n')
    return (OK if passed == len(results) else FAILED), summary, nxt


NOTE_ATTEMPTS = 4  # a pass that took this many compares is a hard-won one


def note_needs(task, results):
    """[(function, kind)] worth a look for a lesson note: unmatched ones, and a pass after many attempts."""
    out = []
    for fn in task['functions']:
        row = next((r for r in results if r.get('rva') == fn['rva']), None) or {}
        if row.get('result') != 'pass':
            out.append((fn, 'near-miss'))
        elif row.get('attempts', 1) >= NOTE_ATTEMPTS:
            out.append((fn, 'hard-won pass'))
    return out


def note_exists(ctx, fn):
    rva = parse_rva(fn['rva'])
    return any((ctx.repo / cookbook_notes.NOTES_DIR).glob(f'{rva:x}-*.md'))


def note_reminders(ctx, task, results):
    """A line per hard-won pass that has no note yet, and one line for all near-misses.

    A note records what the cookbook lacks: the cause of a near-miss, or the spelling of a pass that took many
    compares. The lines name the one command that writes the template; whether the cause is already in the
    cookbook is the drafter's call.
    """
    todo = [(fn, kind) for fn, kind in note_needs(task, results) if not note_exists(ctx, fn)]
    attempts = {row['rva']: row.get('attempts', 1) for row in results}
    lines = [f'note: {fn["rva"]} {fn.get("community_name")}: pass after {attempts[fn["rva"]]} attempt(s); if the spelling that '
             f'fixed it is not in docs/matching-cookbook.md, send it as a lesson note: `{ctx.cli} lesson {fn["rva"]}` '
             '(docs/cookbook-notes/README.md)' for fn, kind in todo if kind == 'hard-won pass']
    near = [fn['rva'] for fn, kind in todo if kind == 'near-miss']
    if near:
        lines.append(f'note: {len(near)} unmatched ({", ".join(near)}); if the cause is not in docs/matching-cookbook.md, '
                     f'send it as a lesson note: `{ctx.cli} lesson <rva>` (words and short plain C++; credited in the merge)')
    return lines


def last_results(tdir):
    try:
        return json.loads((tdir / 'last-compare.json').read_text())['functions']
    except (OSError, ValueError, KeyError):
        return []


def pending_notes(ctx):
    """Uncommitted note, give-up and draft files to carry with a submission."""
    from contrib_publication import auxiliary
    return sorted(n for n in changed_paths(ctx) if auxiliary(n)
                  and (ctx.repo / n).is_file())


def cmd_note(ctx, args):
    """Write the lesson-note template for a function, pre-filled from the task, for the drafter to finish."""
    if getattr(args, 'draft_from', None):
        if not args.rva or not args.category:
            raise Stop(USAGE, '--draft-from needs --rva, --category and the give-up details')
        record = file_giveup(ctx, parse_rva(args.rva), args)
        return OK, {'giveup': record}, f'{ctx.cli} submit --notes-only --dry-run'
    tdir, task = load_task(ctx, args.task, pick_current=True)
    results = last_results(tdir)
    if args.rva:
        wanted = parse_rva(args.rva)
        picked = [(fn, 'requested') for fn in task['functions'] if parse_rva(fn['rva']) == wanted]
        if not picked:
            raise Stop(USAGE, f'{args.rva} is not a function of task {tdir.name}')
    else:
        picked = note_needs(task, results)
        if not picked:
            raise Stop(USAGE, 'no near-miss or hard-won pass in this task; name a function with --rva to write one anyway')
    progress = {}
    try:
        progress = json.loads((tdir / 'last-compare.json').read_text()).get('progress') or {}
    except (OSError, ValueError):
        pass
    written = []
    for fn, _kind in picked:
        rva = parse_rva(fn['rva'])
        row = next((r for r in results if r.get('rva') == fn['rva']), None) or {}
        metric = progress.get(fn['rva']) or {}
        score = f'{metric["best"]}/{metric["total"]} ({metric["metric"]})' if metric.get('best') is not None else None
        name = fn.get('community_name') or fn.get('symbol') or f'sub_{rva:x}'
        path = ctx.repo / (args.path or cookbook_notes.note_path(rva, args.slug or name))
        if path.exists() and not args.force:
            ctx.say(f'{path.relative_to(ctx.repo).as_posix()} exists; kept (--force replaces it)')
            written.append(path.relative_to(ctx.repo).as_posix())
            continue
        outcome = 'fixed' if row.get('result') == 'pass' else 'unsolved'
        text = cookbook_notes.render(rva, name, fn.get('label'), outcome, score, row.get('attempts', int(bool(row))))
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        written.append(path.relative_to(ctx.repo).as_posix())
        ctx.say(f'wrote {written[-1]}: finish every TODO in words and short plain C++ (never bytes, hex or listings)')
    return OK, {'notes': written}, f'finish the TODO lines, then `{ctx.cli} preflight` and submit; the note goes in the same PR'


def cmd_lesson(ctx, args):
    """`lesson <rva>`: the note template for one function, from its task when there is one, else a bare template."""
    rva = parse_rva(args.rva)
    try:
        tdir, _task = load_task(ctx, args.rva)
    except Stop as stop:
        if not stop.message.startswith('no contributor task'):
            raise
        tdir = None
    if tdir is not None:
        return cmd_note(ctx, argparse.Namespace(task=tdir.name, rva=args.rva, slug=args.slug, path=None,
                                                force=args.force))
    name = args.name or f'sub_{rva:x}'
    path = ctx.repo / cookbook_notes.note_path(rva, args.slug or name)
    rel = path.relative_to(ctx.repo).as_posix()
    if path.exists() and not args.force:
        ctx.say(f'{rel} exists; kept (--force replaces it)')
    else:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(cookbook_notes.render(rva, name, None, args.outcome, None, args.attempts))
        ctx.say(f'wrote {rel}: finish every TODO in words and short plain C++ (never bytes, hex or listings)')
    return OK, {'notes': [rel]}, f'finish the TODO lines, then `{ctx.cli} preflight` and submit; the note goes in the same PR'


def cmd_compare(ctx, args):
    draft_rva = parse_rva(args.draft) if args.draft is not None else None
    code, result, next_action = run_compare(ctx, args.task, retry=not args.no_retry, draft_rva=draft_rva)
    if args.dependents:
        from scoped_memo import memo_scope

        base = preflight_base(ctx, None)
        changes = working_source_changes(ctx, git(ctx, 'merge-base', base, 'HEAD'))
        with memo_scope():
            problems = intake_problems(ctx, base, head=None, files=changes, scope=True) if changes else []
            warnings = []
            result['dependent_recheck'] = check_dependents(ctx, changes, None, problems, warnings)
        for line in problems:
            ctx.say('BLOCKED: ' + line)
        for line in warnings:
            ctx.say('warning: ' + line)
        result['dependent_blockers'] = problems
        if problems and code == OK:
            return FAILED, result, f'fix the listed findings, then {ctx.cli} compare --dependents'
    return code, result, next_action


def cmd_bind(ctx, args):
    tdir, task = load_task(ctx, args.task, pick_current=True)
    candidates = sorted((tdir / 'runs').glob('[0-9][0-9][0-9]/candidate.obj'))
    if not candidates:
        raise Stop(USAGE, f'no compiled candidate for {tdir.name}; run {ctx.cli} compare {tdir.name} first')
    ctx.say(f'using task {tdir.name} ({task["compiled"]})')
    exe = require_exe(ctx, target_manifest(ctx.repo))['path']
    report, lines = bind_attempt(ctx.repo, tdir, candidates[-1].parent, exe, find_objdump(ctx))
    for line in lines:
        ctx.say(line)
    unbound = any(report[key] for key in ('unbound_functions', 'unbound_references', 'unbound_thread_locals',
                                         'ignored_hints'))
    return (FAILED if unbound else OK), {'task': tdir.name, 'bind': [line.strip() for line in lines]}, None


# ------------------------------------------------------------------ intake rules and submit

def changed_files(ctx, base, head='HEAD', *, index_tree=False):
    refs = [base, head] if index_tree else [f'{base}...{head}' if head else base]
    raw = git(ctx, 'diff', '--name-status', '--no-renames', '-z', *refs, '--')
    fields = raw.split('\0')
    return [(status[:1], name) for status, name in zip(fields[::2], fields[1::2])]


def git_blob(ctx, ref, name):
    proc = ctx.run(['git', 'show', f'{ref}:{name}'], cwd=ctx.repo, capture_output=True)
    return proc.stdout if proc.returncode == 0 else None


def intake_problems(ctx, base, head='HEAD', files=None, details=None, *, scope=False):
    """Shared deterministic submission checks; acceptance remains the project's separate gate."""
    from contrib_validation import intake_problems as validate, publication_problems
    rows = files if files is not None else changed_files(ctx, base, head)
    problems = validate(ctx, rows, head, details)
    if not problems:
        problems += publication_problems(ctx, base, rows, head, scope=scope)
    return problems


def cmd_intake(ctx, args):
    base = args.base
    try:
        problems = intake_problems(ctx, base, args.head)
    except (ValueError, OSError) as exc:
        problems = [f'intake context rejected: {exc}']
    for p in problems:
        ctx.say(f'problem: {p}')
    ctx.say('intake: ' + ('PASS' if not problems else f'FAIL ({len(problems)} problem(s))'))
    return (OK if not problems else FAILED), {'problems': problems}, None if not problems else 'fix the problems listed'


def submission_files(ctx, base, unit, head='HEAD'):
    branch_rows = changed_files(ctx, base, head) if base != 'HEAD' else []
    return list(dict.fromkeys([(s, n) for s, n in branch_rows if n not in unit] + [('M', n) for n in unit]))


def prune_unused_headers(ctx, tdir, task):
    """Remove untouched starter lines for plain members with no source definition."""
    from bind import load_hints, unit_hints
    from permute import find_bodies, lex
    from source_digest import include_closure

    compiled = task['compiled']
    placeholders = {}
    if not task.get('contrib', {}).get('practice'):
        for fn in task['functions']:
            name = fn.get('community_name') or ''
            match = re.fullmatch(r'([A-Za-z_]\w*)::([A-Za-z_]\w*)', name)
            if (match and match[2].lower() not in (match[1].lower(), 'ctor', 'dtor')
                    and (fn.get('symbol') or '').startswith('unbound:')):
                rva = parse_rva(fn['rva'])
                placeholders[f'// {hex(rva)} {name}'] = (rva, name, match[2])
    if not placeholders:
        return

    try:
        closure = include_closure(ctx.repo, compiled)
        sources = {name: (ctx.repo / name).read_bytes().decode('utf-8') for name in closure}
        text = sources.pop(compiled)
        head = set(rva_headers.leading_lines(text))
        hinted = set(unit_hints(ctx.repo, task).values()) | set(load_hints(tdir).values())
        cpp_names = set(re.findall(r'\b[A-Za-z_]\w*\b', ' '.join(t.text for t in lex(text)[0])))
        headers = [(src, {t.text for t in lex(src)[0]}) for src in sources.values()]
        remove = {line for line, (rva, name, member) in placeholders.items()
                  if line in head and rva not in hinted and member not in cpp_names
                  and not any(member in tokens and (tokens & {'default', 'template'}
                                                    or find_bodies(src, member) or find_bodies(src, name))
                              for src, tokens in headers)}
    except (OSError, ValueError, IndexError):
        return
    if remove:
        lines = text.splitlines(keepends=True)
        end = next((i for i, line in enumerate(lines) if line.strip() and not line.lstrip().startswith('//')),
                   len(lines))
        write_source(ctx.repo / compiled, ''.join(line for line in lines[:end]
                                                  if line.rstrip('\r\n') not in remove) + ''.join(lines[end:]))
        ctx.say(f'{compiled}: removed {len(remove)} unused starter function header line(s)')


def preflight_base(ctx, requested):
    up, _push = upstream_remote(ctx)
    base = requested or (f'{up}/main' if up else 'origin/main')
    if ctx.run(['git', 'rev-parse', '--verify', '--quiet', base], cwd=ctx.repo, capture_output=True).returncode:
        return 'HEAD'
    return base


def working_source_changes(ctx, fork):
    changes = [(s, n) for s, n in changed_files(ctx, fork, head=None) if n.startswith('reconstruction/')]
    untracked = git(ctx, 'ls-files', '-z', '--others', '--exclude-standard', '--', 'reconstruction/')
    return changes + [('A', n) for n in untracked.split('\0') if n]


def check_dependents(ctx, changes, head, problems, warnings):
    from contrib_dependents import recheck

    if problems:
        return None
    try:
        result = recheck(ctx, changes, head)
    except (OSError, ValueError, subprocess.SubprocessError):
        problems.append('dependent recheck could not read the source snapshot or published target manifest')
        return None
    for row in result['functions']:
        if row['result'] == 'hash-match':
            continue
        line = (f'dependent recheck {row["rva"]} {row["name"] or ""} in {row["unit"]}: '
                f'{row["reason"]} after editing {", ".join(row["includes"])}')
        (problems if row['result'] == 'mismatch' else warnings).append(line)
    return result


def cmd_preflight(ctx, args):
    """Check source intake and recheck accepted dependents of shared edits."""
    from contrib_validation import project_reconfirmation
    from scoped_memo import memo_scope
    picked = select_tasks(ctx, args) if (args.task or args.all_dirty
                                         or not args.staged and (not args.base or task_files(ctx))) else []
    base = preflight_base(ctx, args.base)
    head = git(ctx, 'write-tree') if args.staged else None
    fork = git(ctx, 'merge-base', base, 'HEAD')
    if head:
        changes = files = changed_files(ctx, fork, head, index_tree=True)
    else:
        for tdir, task in picked:
            prune_unused_headers(ctx, tdir, task)
        unit = list(dict.fromkeys(n for _d, t_ in picked for n in t_['contrib']['unit']))
        files = submission_files(ctx, base, unit + [n for n in pending_notes(ctx) if n not in unit])
        changes = working_source_changes(ctx, fork)
        files = list({name: (status, name) for status, name in files + changes}.values())
    reminders = [line for d_, t_ in picked
                 for line in note_reminders(ctx, t_, last_results(d_))]
    details = {}
    with memo_scope():
        problems = intake_problems(ctx, base, head=head, files=files, details=details, scope=True)
        reconfirmation = project_reconfirmation(ctx.repo, [n for _status, n in files])
        warnings = details.get('warnings', [])
        dependents = check_dependents(ctx, changes, head, problems, warnings)
    labels, origin = details.get('label_findings', []), details.get('origin_findings', [])
    details_lines = ([f'BLOCKED: {item}' for item in problems] +
                     [f'label: {item}' for item in labels] +
                     [f'{item["file"]}:1: {item["rva"]}: {item["status"]}' for item in reconfirmation] +
                     [f'warning: {item}' for item in warnings] + reminders)
    if (getattr(args, 'verbose', False) or args.staged or ctx.as_json or ctx.env.get('CI')
            or any(row['result'] != 'hash-match' for row in (dependents or {}).get('functions', ()))):
        for line in (reminders + [f'warning: {item}' for item in warnings] +
                     [f'BLOCKED: {item}' for item in problems] +
                     [f'{item["file"]}:1: {item["rva"]}: {item["status"]}' for item in reconfirmation] +
                     [f'label: {item}' for item in labels]):
            ctx.say(line)
    else:
        ctx.say(f'preflight: {"BLOCKED" if problems else "PASS"}; '
                f'{len(problems)} blocker(s), {len(labels)} label finding(s), '
                f'{len(warnings)} warning(s)')
        if details_lines:
            ctx.say(details_lines[0] + (' (use --verbose for all findings)' if len(details_lines) > 1 else ''))
    return (FAILED if problems else OK), dict(problems=problems, blockers=problems, label_findings=labels,
                                            project_reconfirmation=reconfirmation, origin_findings=origin,
                                            warnings=warnings, dependent_recheck=dependents), \
        'fix the listed findings' if problems else f'{ctx.cli} compare'


def upstream_remote(ctx):
    """(upstream remote name or None, push remote name or None)."""
    up, push = None, None
    slugs = {*repo_slug.aliases(UPSTREAM),
             (ctx.env.get('SR_UPSTREAM') or UPSTREAM).lower()}
    remotes = []
    for line in git(ctx, 'remote', '-v', check=False).splitlines():
        parts = line.split()
        if len(parts) < 3 or parts[2] != '(push)':
            continue
        name, url = parts[0], parts[1].lower().rstrip('/').removesuffix('.git')
        remotes.append((name, url.rstrip('/')))
    # A remote with multiple push URLs is unsafe if any URL targets upstream.
    upstreams = {name for name, url in remotes
                 if any(url.endswith('/' + slug) or url.endswith(':' + slug) for slug in slugs)}
    up = next((name for name, _ in remotes if name in upstreams), None)
    push = next((name for name, _ in remotes if name not in upstreams), None)
    return up, push


def submit_remote(ctx, fork):
    """Prefer origin when it is upstream and the authenticated user can write there."""
    gh = ctx.github()
    origin = git(ctx, 'remote', 'get-url', 'origin', check=False)
    origin_match = GITHUB_REMOTE.fullmatch(origin)
    if not origin_match or not repo_slug.same_repo('/'.join(origin_match.groups()), gh.repo):
        return fork, False
    authenticated = gh.gh()
    if authenticated:
        try:
            permissions = gh.api(f'repos/{gh.repo}').get('permissions') or {}
        except (Offline, OSError, ValueError, subprocess.TimeoutExpired):
            raise Stop(NETWORK, 'could not check upstream push permission; restore GitHub access and retry submit') from None
        if not permissions.get('push'):
            return fork, False
    urls = git(ctx, 'remote', 'get-url', '--push', '--all', 'origin', check=False).splitlines()
    target = GITHUB_REMOTE.fullmatch(urls[0]) if len(urls) == 1 else None
    if not target or not repo_slug.same_repo('/'.join(target.groups()), gh.repo):
        raise Stop(USAGE, 'origin must have a single push URL pointing to the upstream repository')
    if not authenticated:
        # Check write access without requiring a separate account login or updating a remote ref.
        try:
            probe = ctx.run(['git', 'push', '--dry-run', 'origin',
                             f'HEAD:refs/heads/sr-write-check-{os.getpid()}'], cwd=ctx.repo,
                            env=dict(ctx.env, GIT_TERMINAL_PROMPT='0'), capture_output=True, text=True, timeout=15)
        except (OSError, subprocess.TimeoutExpired):
            raise Stop(NETWORK, 'upstream push permission probe did not complete; retry submit') from None
        if probe.returncode:
            return fork, False
    if git(ctx, 'symbolic-ref', '--quiet', '--short', 'HEAD', check=False) in ('', 'main'):
        raise Stop(USAGE, 'switch to a contribution branch before submitting to origin/main')
    return 'origin', True


GITHUB_REMOTE = re.compile(r'(?:https://github\.com/|git@github\.com:|ssh://git@github\.com/)'
                           r'([A-Za-z0-9-]+)/([A-Za-z0-9_.-]+?)(?:\.git)?/?', re.I)


def submit_preflight(ctx, push, internal=False):
    blockers, actions = [], []
    owner = None
    if push:
        url = git(ctx, 'remote', 'get-url', '--push', push, check=False)
        match = GITHUB_REMOTE.fullmatch(url)
        if match:
            owner = match.group(1)
        else:
            blockers.append('fork push remote must name a GitHub repository')
    else:
        blockers.append('no fork remote to push to')
        actions.append(f'fork the repository on GitHub; git remote add fork https://github.com/<you>/{UPSTREAM.split("/")[-1]}.git')
    for field in ('name', 'email'):
        if not git(ctx, 'config', '--get', 'user.' + field, check=False):
            blockers.append('git author ' + field + ' is not configured')
            actions.append('git config user.' + field + ' <your-' + field + '>')
    authenticated = bool(ctx.github().gh())
    if not authenticated:
        actions.append('gh auth login (recommended for claims, API quota and automatic PR creation); '
                       'or configure Git push credentials and use the browser PR link')
    return dict(fork_remote=None if internal else push, fork_owner=None if internal else owner,
                push_remote=push, internal=internal, authenticated=authenticated, git_push_auth='not-checked',
                blockers=blockers, actions=actions)


def pr_body(ctx, task, summary, args, labels, origin):
    template = (ctx.repo / '.github/PULL_REQUEST_TEMPLATE/function.md').read_text()
    summaries = summary if isinstance(summary, list) else [summary]
    rows = '\n'.join(f'| `{r["rva"]}` | `{r["name"]}` | {r["result"]} | `{r["reason"]}` | {r["candidate_size"]}/'
                     f'{r["target_size"]} | `{(r["code_section_sha256"] or "")[:16]}` |'
                     for one in summaries for r in one['functions'])
    reports = []
    for one in summaries:
        report = {k: one[k] for k in ('unit', 'source_revision', 'recipe', 'recipe_sha256', 'compiler',
                                      'image_sha256_pinned', 'comparator', 'contract_version')}
        report['functions'] = [{k: r[k] for k in ('rva', 'result', 'reason', 'candidate_size', 'target_size',
                                                  'coverage', 'code_section_sha256')} for r in one['functions']]
        reports.append(report)
    report = reports[0] if not isinstance(summary, list) else reports
    fields = {
        'functions_table': rows,
        'report_json': json.dumps(report, indent=1),
        'drafted_by': args.drafted_by or load_config(ctx).get('drafted_by') or 'not stated',
        'label_findings': '\n'.join(f'- {x}' for x in labels) or '- none',
        'origin_findings': '\n'.join(f'- {x}' for x in origin) or '- none',
        'tool_revision': git(ctx, 'rev-parse', '--short=12', 'HEAD', check=False) or 'unknown',
    }
    for k, v in fields.items():
        template = template.replace('{{' + k + '}}', v)
    return template


def select_tasks(ctx, args):
    """[(dir, task)] for the task names given, or every unsubmitted task whose unit has uncommitted
    changes with --all-dirty; one task when nothing is named, as before."""
    names = getattr(args, 'task', None) or []
    names = [names] if isinstance(names, str) else list(names)
    if getattr(args, 'all_dirty', False):
        if names:
            raise Stop(USAGE, 'name tasks or pass --all-dirty, not both')
        changed = changed_paths(ctx)
        picked = []
        for path in task_files(ctx):
            task = json.loads(path.read_text())
            contrib = task.get('contrib', {})
            if contrib.get('practice') or contrib.get('submitted'):
                continue
            if task.get('compiled') in changed or set(contrib.get('unit', [])) & changed:
                picked.append((path.parent, task))
        if not picked:
            raise Stop(USAGE, 'no task has uncommitted changes in its unit', f'{ctx.cli} start 0x<rva>')
        return picked
    if not names:
        return [load_task(ctx, None)]
    picked = []
    for name in names:
        item = load_task(ctx, name)
        if all(item[0] != d for d, _t in picked):
            picked.append(item)
    return picked


def submit_task_blockers(ctx, tdir, task):
    """(blockers, last compare summary) of one task: compare current and passing, pinned compiler, not practice."""
    blockers = []
    try:
        summary = json.loads((tdir / 'last-compare.json').read_text())
    except (OSError, ValueError):
        raise Stop(USAGE, 'no comparison yet', f'{ctx.cli} compare {tdir.name}')
    from source_digest import include_closure
    from digest_v2 import tu_digest
    try:
        digest = tu_digest(ctx.repo, include_closure(ctx.repo, task['compiled']))
        if digest != summary['source_revision']:
            blockers.append(f'{task["compiled"]}:1: the unit changed since the last compare; fix: run compare again')
    except (OSError, ValueError):
        blockers.append(f'{task["compiled"]}:1: comparison source closure cannot be resolved; '
                        'fix: repair the include findings below, then run compare again')
    try:
        import prereview
        recipe = prereview.recipe_problem(ctx.repo, (ctx.repo / task['compiled']).read_text(), summary)
        if recipe:
            blockers.append(f'{task["compiled"]}:1: {recipe}')
    except (OSError, ValueError):
        pass  # the unreadable unit is already reported by the digest check above
    if not all(r['result'] == 'pass' for r in summary['functions']):
        blockers.append(f'{task["compiled"]}:1: not every function passed the last compare; '
                        'fix: resolve the comparison failures before submitting')
    if summary['compiler'] != 'pinned':
        blockers.append(f'{task["compiled"]}:1: the last compare used a stand-in compiler, not the pinned MSVC; '
                        'fix: install the pinned compiler with setup and compare again')
    if task.get('contrib', {}).get('practice'):
        blockers.append('practice tasks re-do accepted functions and are not submitted')
    return blockers, summary


def cmd_submit(ctx, args):
    if getattr(args, 'notes_only', False):
        return submit_notes(ctx, args)
    picked = select_tasks(ctx, args)
    tdir, task = picked[0]
    blockers, warnings = [], []
    summaries, unit = [], []
    for tdir_i, task_i in picked:
        problems_i, summary_i = submit_task_blockers(ctx, tdir_i, task_i)
        blockers += problems_i
        summaries.append(summary_i)
        unit += [n for n in task_i['contrib']['unit'] if (ctx.repo / n).is_file() and n not in unit]
    summary = summaries[0] if len(picked) == 1 else dict(summaries[0], functions=[
        r for s_ in summaries for r in s_['functions']])
    notes = [n for n in pending_notes(ctx) if n not in unit]
    for d_, t_ in picked:
        for line in note_reminders(ctx, t_, last_results(d_)):
            ctx.say(line)
    unit = unit + notes
    up, push = upstream_remote(ctx)
    push, internal = submit_remote(ctx, push)
    if internal:
        up = push
    preflight = submit_preflight(ctx, push, internal)
    blockers += preflight['blockers']
    warnings += preflight['actions']
    base = args.base or (f'{up}/main' if up else 'origin/main')
    if ctx.run(['git', 'rev-parse', '--verify', '--quiet', base], cwd=ctx.repo, capture_output=True).returncode != 0:
        base = 'HEAD'
    # Everything the branch would bring, not only the unit: committed changes since the base plus
    # the unit as it is on disk now.
    files = submission_files(ctx, base, unit)
    details = {}
    problems = intake_problems(ctx, base, head=None, files=files, details=details)
    blockers += problems
    labels, origin = details.get('label_findings', []), details.get('origin_findings', [])
    warnings += details.get('warnings', [])
    from contrib_validation import project_reconfirmation
    reconfirmation = project_reconfirmation(ctx.repo, [n for _status, n in files])
    for item in reconfirmation:
        warnings.append(f'{item["file"]}:1: {item["rva"]}: {item["status"]}')
    try:
        open_items = ctx.github().open_items(refresh=True)
        me = ctx.github().user()
        own_urls = {c.get('url') for c in local_claims(ctx).values()}
        for fn in [f for _d, t_ in picked for f in t_['functions']]:
            items = [i for i in open_items.get(parse_rva(fn['rva']), []) if i['url'] not in own_urls]
            _mine, fresh, _stale = claim_state(items, me)
            if fresh and not args.ack_collision:
                blockers.append(f'another open claim or pull request names {fn["rva"]}: '
                                + ', '.join(i['url'] for i in fresh) + ' (talk to them, or pass --ack-collision)'
                                + ('' if me else '; if it is yours, give claim --github-user <your-login>'))
    except Offline as exc:
        warnings.append(f'GitHub claims not checked: {exc}')
    body = pr_body(ctx, task, summaries if len(picked) > 1 else summary, args, labels, origin)
    names = ', '.join(r['name'] for r in summary['functions'])
    title = f'Reconstruct {names} ({", ".join(r["rva"] for r in summary["functions"])})'
    (tdir / 'pr-body.md').write_text(body)
    for w in warnings:
        ctx.say(f'warning: {w}')
    for b in blockers:
        ctx.say(f'BLOCKED: {b}')
    drafted = args.drafted_by or load_config(ctx).get('drafted_by') or 'not stated'
    if drafted == 'not stated':
        ctx.say('warning: no drafter is stated, so the project charts this as human or unstated. To credit the model, '
                f"give {ctx.cli} submit --drafted-by 'your name, assisted by <model>'.")
    data = {'title': title, 'body_file': str(tdir / 'pr-body.md'), 'files': unit, 'blockers': blockers,
            'warnings': warnings, 'project_reconfirmation': reconfirmation,
            'dry_run': bool(args.dry_run), 'base': base, 'preflight': preflight,
            'ci_hash': {'advisory': True, 'advice': 'For optional public hash CI, add // CI hash: <RVA> <COFF-symbol> in the first 8192 bytes of the .cpp header. Without a resolved binding CI reports no-target; green CI is not acceptance.'},
            'commit_message': f'{title}\n\nDrafted by {drafted}. Local comparator pass with the pinned recipe; '
                              'not yet confirmed by the project.'}
    ctx.say(data['ci_hash']['advice'])
    ctx.say('A local pass is not acceptance: the project re-runs the comparison on two of its own hosts and a '
            'Reviewer checks the source before the function is recorded as matched.')
    count = sum(len(t_['functions']) for _d, t_ in picked)
    if count < SMALL_PR_FUNCTIONS:
        ctx.say(f'Hint: this PR has {count} function(s). Bigger is welcome: 50 to 200 per PR, one PR per family. '
                "Don't do it all in one go: split a family into batches of 10-15 and give each to a subagent "
                '(recipe in docs/contributor-card.md), then submit them together with `--all-dirty`.')
    return publish_submission(ctx, data, push, files, picked)


def submit_notes(ctx, args):
    from contrib_publication import auxiliary

    if args.task or args.all_dirty:
        raise Stop(USAGE, '--notes-only takes no tasks')
    unit = pending_notes(ctx)
    up, push = upstream_remote(ctx)
    push, internal = submit_remote(ctx, push)
    if internal:
        up = push
    base = args.base or (f'{up}/main' if up else 'origin/main')
    files = submission_files(ctx, base, unit)
    if not files or any(not auxiliary(name) for _status, name in files):
        raise Stop(USAGE, '--notes-only needs a branch containing only drafts, give-ups or lessons')
    preflight = submit_preflight(ctx, push, internal)
    blockers = preflight['blockers'] + intake_problems(ctx, base, head=None, files=files)
    for finding in blockers:
        ctx.say(f'BLOCKED: {finding}')
    title = 'Share contributor near-miss drafts and notes'
    body_file = ctx.private / 'notes-pr-body.md'
    body_file.parent.mkdir(parents=True, exist_ok=True)
    body_file.write_text('Contributor drafts and notes for future attempts.\n\n## Files\n\n'
                         + ''.join(f'- `{name}`\n' for _, name in files), encoding='utf-8')
    return publish_submission(ctx, dict(title=title, body_file=str(body_file), files=unit,
                                        blockers=blockers, dry_run=args.dry_run, base=base,
                                        preflight=preflight, commit_message=title), push, files, [])


def publish_submission(ctx, data, push, files, picked):
    title, body_file = data['title'], data['body_file']
    unit, base, blockers, preflight = (data[k] for k in ('files', 'base', 'blockers', 'preflight'))
    internal = preflight['internal']
    branch = git(ctx, 'rev-parse', '--abbrev-ref', 'HEAD') if internal else None
    refspec = f'HEAD:refs/heads/{branch}' if internal else 'HEAD'
    if data['dry_run']:
        plan = [f'git push --dry-run {push or "<your fork remote>"} {refspec}']
        if unit:
            plan += [f'git add {" ".join(unit)}', f'{ctx.cli} preflight --staged --base {base}',
                     f'git commit -m "{title}" -- {" ".join(unit)}']
        plan += [f'git push {push or "<your fork remote>"} {refspec}',
                 f'gh pr create --repo {ctx.github().repo} --title "{title}" --body-file {body_file}']
        for p in plan:
            ctx.say(f'would run: {p}')
        return (OK if not blockers else FAILED), dict(data, plan=plan), \
            ('fix the blockers listed' if blockers else f'{ctx.cli} submit' + ('' if picked else ' --notes-only'))
    if blockers:
        raise Stop(FAILED, f'{len(blockers)} blocker(s); nothing committed or pushed', 'fix the blockers listed', **data)
    other = [n for n in git(ctx, 'diff', '--cached', '--name-only').splitlines() if n and n not in unit]
    if other:
        raise Stop(USAGE, 'other files are staged: ' + ', '.join(other[:5]) + '; submit commits only the unit',
                   'git restore --staged <those files>, then submit again', **data)
    # Push credentials can differ from the account used for repository permissions.
    destination = 'upstream' if internal else 'fork'
    try:
        probe = ctx.run(['git', 'push', '--dry-run', push, refspec], cwd=ctx.repo,
                        env=dict(ctx.env, GIT_TERMINAL_PROMPT='0'), capture_output=True, text=True, timeout=60)
    except (OSError, subprocess.TimeoutExpired):
        raise Stop(NETWORK, f'{destination} push preflight did not complete; nothing committed',
                   f'configure Git push credentials for the {destination}, then rerun submit', **data)
    if probe.returncode:
        raise Stop(NETWORK, f'{destination} push authentication/permission preflight failed; nothing committed',
                   f'configure Git push credentials for the {destination}, then rerun submit', **data)
    preflight['git_push_auth'] = 'passed'
    if unit:
        git(ctx, 'add', '--', *unit)
    # Validate the immutable index that will be committed, without requiring project acceptance.
    index_tree = git(ctx, 'write-tree')
    staged_problems = intake_problems(ctx, base, head=index_tree, files=files)
    if staged_problems:
        raise Stop(FAILED, 'staged submission preflight failed', 'fix the listed findings',
                   blockers=staged_problems)
    if unit:
        git(ctx, 'commit', '-m', data['commit_message'], '--', *unit)
    if not push:
        raise Stop(USAGE, 'no fork remote to push to', 'fork the repository on GitHub, then '
                   f'git remote add fork https://github.com/<you>/{UPSTREAM.split("/")[-1]}.git and run submit again', **data)
    branch = branch or git(ctx, 'rev-parse', '--abbrev-ref', 'HEAD')
    git(ctx, 'push', push, refspec if internal else branch)
    for tdir_i, task_i in picked:
        task_i['contrib']['submitted'] = branch
        (tdir_i / 'task.json').write_text(json.dumps(task_i, indent=2) + '\n')
    head = branch if internal else f"{preflight['fork_owner']}:{branch}"
    gh = ctx.github().gh()
    if gh:
        proc = ctx.run([gh, 'pr', 'create', '--repo', ctx.github().repo, '--head', head,
                        '--title', title, '--body-file', body_file], capture_output=True, text=True)
        if proc.returncode == 0:
            url = proc.stdout.strip().splitlines()[-1]
            ctx.say(f'pull request: {url}')
            return OK, dict(data, pull_request=url), 'wait for the project to confirm; watch the pull request'
    head = urllib.parse.quote(head, safe=':')
    link = f'https://github.com/{ctx.github().repo}/compare/main...{head}?expand=1'
    ctx.say(f'open this link and paste {body_file} as the description: {link}')
    return OK, dict(data, link=link), 'open the link and create the pull request'


# ------------------------------------------------------------------ go

def cmd_feedback(ctx, args):
    import contrib_feedback
    try:
        data = (contrib_feedback.collect_outcome(ctx.github(), args.pr) if args.pr is not None
                else ctx.github().feedback())
    except (contrib_feedback.Unavailable, OSError, ValueError, KeyError, TypeError, subprocess.SubprocessError) as exc:
        message = str(exc) if isinstance(exc, contrib_feedback.Unavailable) else 'Feedback unavailable: check the network and gh auth status.'
        raise Stop(NETWORK, message, f'check gh auth status, then rerun {ctx.cli} feedback',
                   feedback_available=False) from None
    if args.pr is not None:
        if not ctx.as_json:
            print(ctx.scrub(json.dumps(data, indent=2)))
        return OK, data, None
    if not ctx.as_json:
        contrib_feedback.display(ctx, data)
    count = data['needs_action_prs']
    return (FAILED if count else OK), dict(data, feedback_available=True), (
        'pull the PR branch, address feedback, push fixes to the same branch, reply and resolve fixed threads'
        if count else None)


def feedback_hint(ctx):
    """An advisory read must never prevent local work or submission while offline."""
    import contrib_feedback
    try:
        count = ctx.github().feedback()['needs_action_prs']
    except (contrib_feedback.Unavailable, OSError, ValueError, KeyError, TypeError, subprocess.SubprocessError):
        return
    if count:
        ctx.say(f'{count} PRs have unaddressed feedback, run {ctx.cli} feedback')


def cmd_go(ctx, args):
    """setup -> next -> claim -> start, stopping at the first step that needs a person."""
    setup_args = argparse.Namespace(exe=args.exe, accept_microsoft_license=args.accept_microsoft_license,
                                    no_install=False, no_sources=False, no_self_test=args.no_self_test,
                                    steamcmd=False, no_sibling=args.no_sibling, decompiler=getattr(args, 'decompiler', True),
                                    accept_winget_source_agreements=args.accept_winget_source_agreements)
    try:
        cmd_setup(ctx, setup_args)
    except Stop as exc:
        # Drafting can begin before the compiler is installed; the executable is needed for the pack.
        if exc.code == MISSING and exc.data.get('component') != 'decompiler' \
                and 'SkyrimSE.exe' not in exc.message and 'not the pinned' not in exc.message:
            ctx.say(f'continuing without a compiler for now: {exc.message}')
        else:
            raise
    if not args.rva:
        # Resume unfinished work instead of claiming a second function.
        for path in task_files(ctx):
            task = json.loads(path.read_text())
            if not task.get('contrib', {}).get('practice') and not task['contrib'].get('submitted'):
                ctx.say(f'resuming {task["task_id"]} ({task["compiled"]})')
                return OK, {'task': task['task_id'], 'unit': task['contrib']['unit'], 'resumed': True}, \
                    f'edit {task["compiled"]}, then {ctx.cli} compare {task["task_id"]}'
    if args.rva:
        rva = args.rva
    else:
        _c, data, _n = cmd_next(ctx, argparse.Namespace(count=1, max_size=args.max_size))
        if not data['candidates']:
            raise Stop(OK, 'no startable function found')
        rva = data['candidates'][0]['rva']
    code, claim, claim_next = cmd_claim(ctx, argparse.Namespace(rva=rva, take_over=False, offline_ok=args.offline_ok,
                                      model=getattr(args, 'model', None), drafted_by=args.drafted_by))
    if code != OK or claim.get('claim') == 'link-only':
        links = ' '.join(claim.get('links', []))
        return (CONSENT if claim.get('claim') == 'link-only' else code), claim, (
            f'file {links}, then run {ctx.cli} claim {rva} --github-user <your-login>'
            if claim.get('claim') == 'link-only' else claim_next)
    return start(ctx, argparse.Namespace(rva=[rva], practice=False, drafted_by=args.drafted_by, area=None,
                                         no_branch=args.no_branch, recipe=None, force=False, profile=args.profile))


# ------------------------------------------------------------------ main

def cmd_sheet(ctx, args):
    import drafter_sheet
    rva = parse_rva(args.rva)
    if args.task:
        matches = [Path(args.task)]
    else:
        matches = drafter_sheet.task_for([ctx.local / 'tasks', ctx.private / 'tasks'], rva)
    if not matches:
        raise Stop(MISSING, f'no prepared task for 0x{rva:x}', f'{ctx.cli} start 0x{rva:x} or pass --task <task-dir>')
    if len(matches) > 1:
        raise Stop(USAGE, f'multiple prepared tasks for 0x{rva:x}; pass --task', errors=[str(p) for p in matches])
    import drafter_lessons
    fn = resolve_function(ctx, inventory(ctx.repo), rva)
    tags = drafter_lessons.tags_for(ctx.repo, ctx.local, rva, fn, matches[0])
    result = drafter_sheet.render(ctx.repo, matches[0], rva) + 'Lesson tags: ' + (', '.join(sorted(tags)) or 'none known') + '\n'
    ctx.say(result.rstrip())
    return OK, {'sheet': result}, None


def cmd_lessons(ctx, args):
    import drafter_lessons
    rva = parse_rva(args.rva) if args.rva else None
    if rva is None and not args.tag:
        raise Stop(USAGE, 'give an RVA or at least one --tag')
    fn = resolve_function(ctx, inventory(ctx.repo), rva) if rva is not None else None
    if rva is not None and not fn and not args.task:
        raise Stop(USAGE, f'{args.rva} is not in the function inventory or published target hashes; use --task')
    tags = set(args.tag)
    if rva is not None:
        tags.update(drafter_lessons.tags_for(ctx.repo, ctx.local, rva, fn, args.task))
    result = drafter_lessons.select(ctx.repo, rva, tags, args.max_chars)
    ctx.say(result.rstrip())
    return OK, {'lessons': result, 'tags': sorted(tags)}, None


def parser():
    p = agent_advice.ArgumentParser(prog='contrib.py', description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--json', action='store_true', help='one JSON object on stdout; never prompts')
    p.add_argument('--yes', action='store_true', help='agree to package installs (never to a licence)')
    p.add_argument('--redact', action='store_true',
                   help='replace known private paths in output; use it for anything you post publicly')
    sub = p.add_subparsers(dest='command', required=True)
    s = sub.add_parser('sheet')
    s.add_argument('rva')
    s.add_argument('--task', help='prepared task directory, when more than one exists')
    s = sub.add_parser('lessons')
    s.add_argument('rva', nargs='?')
    s.add_argument('--task', help='prepared task directory')
    s.add_argument('--tag', action='append', default=[], help='additional tag from docs/lesson-tags.md; repeat as needed')
    s.add_argument('--max-chars', type=int, default=12000)
    s = sub.add_parser('doctor')
    s.add_argument('--exe')
    s = sub.add_parser('facts')
    s.add_argument('rva')
    s = sub.add_parser('decomp')
    s.add_argument('rva')
    s = sub.add_parser('feedback')
    s.add_argument('pr', nargs='?', type=int)
    s.add_argument('--json', action='store_true', default=argparse.SUPPRESS,
                   help='one JSON object on stdout; also accepted before feedback')
    s = sub.add_parser('setup')
    s.add_argument('--decompiler', action=argparse.BooleanOptionalAction, default=True,
                   help='recommended private Ghidra view (default on; --no-decompiler skips it)')
    s.add_argument('--exe')
    s.add_argument('--accept-microsoft-license', action='store_true',
                   help='a person has read and accepted the VS 2017 Build Tools licence')
    s.add_argument('--no-install', action='store_true', help='print package commands instead of running them')
    s.add_argument('--no-sources', action='store_true')
    s.add_argument('--no-sibling', action='store_true', help='skip the optional FNV decompilation clone (about 175 MB)')
    s.add_argument('--no-self-test', action='store_true')
    s.add_argument('--steamcmd', action='store_true', help="also install Valve's SteamCMD")
    s.add_argument('--accept-winget-source-agreements', action='store_true',
                   help="Windows: a person has accepted the terms of winget's package source")
    s = sub.add_parser('next')
    s.add_argument('--count', type=int, default=5)
    s.add_argument('--max-size', type=int, help='maximum function size (default: 64 bytes without --class)')
    s.add_argument('--function-table', help='optional private function table derived locally from your own pinned image')
    s.add_argument('--class', dest='class_regex', metavar='REGEX',
                   help='only classes whose name matches (re.search, e.g. "^Ni"); filters before readiness is computed')
    s = sub.add_parser('claim')
    s.add_argument('rva', nargs='*')
    s.add_argument('--class', dest='classes', action='append', default=[],
                   help='claim unmatched members of a class or an exact function name; repeat to batch')
    s.add_argument('--list', dest='lists', action='append', default=[])
    s.add_argument('--range', dest='ranges', action='append', default=[])
    s.add_argument('--take-over', action='store_true')
    s.add_argument('--skip-conflicts', action='store_true',
                   help='claim the functions nobody else holds and name the ones skipped')
    s.add_argument('--offline-ok', action='store_true')
    s.add_argument('--github-user', help='your GitHub login, when gh is not signed in')
    s.add_argument('--model', '--agent', help='actual model id or agent/tool name, recorded before claiming')
    s.add_argument('--drafted-by', help='human/agent attribution, including model if AI-assisted')
    s = sub.add_parser('release')
    s.add_argument('rva')
    s.add_argument('--reason')
    giveup.add_draft_arguments(s)
    s.add_argument('--note', help='lesson note holding the near-miss, docs/cookbook-notes/<rva>-<slug>.md')
    s = sub.add_parser('start')
    s.add_argument('--model', '--agent', help='actual model id or agent/tool name')
    s.add_argument('rva', nargs='+')
    s.add_argument('--drafted-by')
    s.add_argument('--area')
    s.add_argument('--unit', metavar='PATH', help='choose an existing reconstruction .cpp when several units fit')
    s.add_argument('--class', dest='class_name', metavar='CLASS',
                   help='use this owner for members or Function<rva> placeholders (label inferred names GUESS)')
    s.add_argument('--recipe')
    s.add_argument('--deleting-cleanup', choices=('inline', 'out-of-line'),
                   help='for a scalar deleting destructor identified locally: inline complete cleanup or call out')
    s.add_argument('--practice', action='store_true', help='try an already matched function as an exercise')
    s.add_argument('--code-origin', help='truthful code/declaration origin, including any adapted sources; otherwise a required placeholder')
    s.add_argument('--profile', choices=CONTRIB_PROFILES,
                   help='cheap (default: small card, Haiku/Luna-class) or full (full card, Sonnet-class); never changes the gate')
    s.add_argument('--no-branch', action='store_true')
    s.add_argument('--force', action='store_true', help=argparse.SUPPRESS)
    s = sub.add_parser('compare')
    s.add_argument('task', nargs='?')
    s.add_argument('--draft', metavar='RVA', help='score the public draft for this RVA')
    s.add_argument('--dependents', action='store_true', help='also recheck accepted units that include edited source')
    s.add_argument('--no-retry', action='store_true',
                   help='skip the advisory retry of failed functions under the recipe\'s alternative flag sets')
    s = sub.add_parser('bind', help='resolve bindings for the most recent compiled candidate of a task')
    s.add_argument('task', nargs='?')
    s = sub.add_parser('note')
    s.add_argument('task', nargs='?')
    s.add_argument('--rva', help='write a note for this function even when it is not a near-miss')
    s.add_argument('--slug', help='short file-name slug (default: the function name)')
    s.add_argument('--path', help=argparse.SUPPRESS)
    s.add_argument('--force', action='store_true', help='replace an existing note')
    giveup.add_draft_arguments(s)
    s = sub.add_parser('lesson', help='write the lesson-note template for one function (a near-miss, a hard pass, a solved shape)')
    s.add_argument('rva')
    s.add_argument('--name', help='function name for the template when there is no task')
    s.add_argument('--outcome', choices=cookbook_notes.OUTCOMES, default='unsolved', help='template outcome when there is no task')
    s.add_argument('--attempts', type=int, default=0, help='attempt count for the template when there is no task')
    s.add_argument('--slug', help='short file-name slug (default: the function name)')
    s.add_argument('--force', action='store_true', help='replace an existing note')
    s = sub.add_parser('submit')
    s.add_argument('task', nargs='*', help='one or more task names; several make one pull request')
    s.add_argument('--all-dirty', action='store_true',
                   help='every unsubmitted task whose unit has uncommitted changes, in one pull request')
    s.add_argument('--notes-only', action='store_true', help='submit drafts, give-ups or lessons without a matched unit')
    s.add_argument('--dry-run', action='store_true')
    s.add_argument('--base')
    s.add_argument('--drafted-by')
    s.add_argument('--ack-collision', action='store_true')
    s = sub.add_parser('preflight')
    s.add_argument('--verbose', action='store_true', help='show every finding')
    s.add_argument('task', nargs='*', help='one or more task names')
    s.add_argument('--all-dirty', action='store_true', help='every unsubmitted task whose unit has uncommitted changes')
    s.add_argument('--base')
    s.add_argument('--staged', action='store_true', help='check the index against the PR base, including unassigned files')
    s = sub.add_parser('intake')
    s.add_argument('--base', required=True)
    s.add_argument('--head', default='HEAD')
    s = sub.add_parser('go')
    s.add_argument('--decompiler', action=argparse.BooleanOptionalAction, default=True,
                   help='recommended private Ghidra view (default on; --no-decompiler skips it)')
    s.add_argument('--model', '--agent', help='actual model id or agent/tool name, recorded before claiming')
    s.add_argument('rva', nargs='?')
    s.add_argument('--exe')
    s.add_argument('--drafted-by')
    s.add_argument('--accept-microsoft-license', action='store_true')
    s.add_argument('--accept-winget-source-agreements', action='store_true')
    s.add_argument('--no-sibling', action='store_true')
    s.add_argument('--no-self-test', action='store_true')
    s.add_argument('--no-branch', action='store_true')
    s.add_argument('--offline-ok', action='store_true')
    s.add_argument('--max-size', type=int, default=64)
    s.add_argument('--profile', choices=CONTRIB_PROFILES,
                   help='cheap (default: small card, Haiku/Luna-class) or full (full card, Sonnet-class); never changes the gate')
    return p


COMMANDS = {'sheet': cmd_sheet, 'lessons': cmd_lessons, 'doctor': cmd_doctor, 'setup': cmd_setup, 'next': cmd_next, 'claim': cmd_claim, 'release': cmd_release,
            'start': cmd_start, 'facts': cmd_facts, 'decomp': cmd_decomp, 'compare': cmd_compare, 'bind': cmd_bind,
            'note': cmd_note, 'lesson': cmd_lesson, 'submit': cmd_submit,
            'preflight': cmd_preflight, 'intake': cmd_intake, 'go': cmd_go, 'feedback': cmd_feedback}


def main(argv=None, ctx=None):
    args = parser().parse_args(argv)
    ctx = ctx or Ctx(as_json=args.json, assume_yes=args.yes)
    ctx.as_json = ctx.as_json or args.json
    ctx.interactive = ctx.interactive and not ctx.as_json
    ctx.assume_yes = ctx.assume_yes or args.yes
    ctx.redact = ctx.redact or args.redact
    if getattr(args, 'exe', None):
        ctx.remember_path(args.exe, '<exe>')
    try:
        ctx.local  # Validate an explicit override before any command writes private files.
        apply_wine_env(ctx)
        if args.command in ('go', 'submit'):
            feedback_hint(ctx)
        code, data, nxt = COMMANDS[args.command](ctx, args)
        message = None
    except Stop as exc:
        code, data, nxt, message = exc.code, exc.data, exc.next_action, exc.message
        if not ctx.as_json:
            print(ctx.scrub(f'{"error" if code else "note"}: {message}'), file=sys.stderr)
            for line in data.get('steamcmd_route') or []:
                print(ctx.scrub(f'  {line}'), file=sys.stderr)
            for line in data.get('errors') or []:
                print(ctx.scrub(f'  {line}'), file=sys.stderr)
    except (OSError, ValueError, KeyError, TypeError) as exc:
        code, data, nxt, message = USAGE, {}, agent_advice.next_action(exc, 'contrib'), str(exc)
        if not ctx.as_json:
            print(ctx.scrub(f'error: {message}'), file=sys.stderr)
    if ctx.as_json:
        out = {'command': args.command, 'ok': code == OK, 'exit_code': code, 'error': message, 'next': nxt}
        out.update({k: v for k, v in (data or {}).items() if k not in out})
        out['messages'] = ctx.log
        if ctx.process_logs:
            out['logs'] = ctx.process_logs
        print(ctx.scrub(json.dumps(out, indent=2, default=str)))
    elif nxt:
        print(ctx.scrub(f'next: {nxt}'))
    return code


if __name__ == '__main__':
    raise SystemExit(main())
