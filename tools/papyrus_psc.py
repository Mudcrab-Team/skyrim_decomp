"""Papyrus script (.psc) declaration parser and archive pinning. Local input.

Reads the shipped script archive of a game installation you own and reduces every script to its
declarations: script name, parent, script flags, and for each function or event its return type,
parameters (type, array, name, whether a default exists) and flags (native, global, latent, ...).
Bodies, doc strings, comments and default values are discarded while parsing and never kept.

What the tool writes is derived metadata only: names, types and counts. The script texts and the
per-script tables stay where you run it (`.local/`); `tools/papyrus_natives.py` joins the result to
the executable's registrations and publishes counts, derived names and prototypes.

    python3 tools/papyrus_psc.py pin  <Scripts.zip>                      # SHA-256, size, member counts
    python3 tools/papyrus_psc.py scan <Scripts.zip> --out natives.json   # native declarations (local file)

Papyrus is case-insensitive; names keep the spelling the declaration uses and every lookup
folds case (`fold`).
"""
import argparse
import hashlib
import json
import re
import sys
import zipfile
from dataclasses import dataclass, field
from pathlib import Path

SCHEMA_VERSION = 1
SCRIPT_RE = re.compile(r'^scriptname\s+(?P<name>\w+)(?:\s+extends\s+(?P<parent>\w+))?(?P<flags>(?:\s+\w+)*)\s*$', re.I)
# [ReturnType[]] Function|Event Name(params) flags
CALLABLE_RE = re.compile(
    r'^(?:(?P<ret>\w+(?:\s*\[\s*\])?)\s+)?(?P<kind>function|event)\s+(?P<name>\w+)\s*\((?P<params>.*)\)\s*(?P<flags>(?:\w+\s*)*)$',
    re.I)
PARAM_RE = re.compile(r'^(?P<type>\w+)\s*(?P<array>\[\s*\])?\s+(?P<name>\w+)\s*(?:=\s*(?P<default>.+))?$', re.S)
FUNCTION_FLAGS = {'native', 'global', 'latent', 'debugonly', 'betaonly'}
SCRIPT_FLAGS = {'hidden', 'conditional', 'native', 'const', 'debugonly', 'betaonly'}
END_RE = re.compile(r'^end(?:function|event|state|property|struct|group)\s*$', re.I)


def fold(name):
    return name.lower()


@dataclass
class Param:
    type: str
    array: bool
    name: str
    has_default: bool


@dataclass
class Callable:
    kind: str
    name: str
    returns: str
    returns_array: bool
    params: list
    flags: frozenset

    @property
    def native(self):
        return 'native' in self.flags

    @property
    def is_global(self):
        return 'global' in self.flags

    def signature(self):
        """Papyrus-level signature, e.g. `Int[] Name(Form[] a, Bool b)`; defaults are not shown."""
        ret = (self.returns + ('[]' if self.returns_array else '')) if self.returns else 'None'
        args = ', '.join(f'{p.type}{"[]" if p.array else ""} {p.name}' for p in self.params)
        return f'{ret} {self.name}({args})'


@dataclass
class Script:
    name: str
    parent: str
    flags: frozenset
    callables: list = field(default_factory=list)

    @property
    def natives(self):
        return [c for c in self.callables if c.native]


def logical_lines(text):
    """Source lines with comments removed and `\\` continuations joined.

    A `;` outside a string starts a line comment; `;/ ... /;` is a block comment; a `{ ... }` doc
    string standing between declarations is dropped. Line numbers are not kept."""
    out = []
    buf = ''
    in_block = False
    in_doc = False
    for raw in text.replace('\r\n', '\n').replace('\r', '\n').split('\n'):
        line = []
        i, n = 0, len(raw)
        in_str = False
        while i < n:
            ch = raw[i]
            if in_block:
                if raw.startswith('/;', i):
                    in_block = False
                    i += 2
                else:
                    i += 1
                continue
            if in_doc:
                if ch == '}':
                    in_doc = False
                i += 1
                continue
            if in_str:
                line.append(ch)
                if ch == '\\' and i + 1 < n:
                    line.append(raw[i + 1])
                    i += 2
                    continue
                if ch == '"':
                    in_str = False
                i += 1
                continue
            if ch == '"':
                in_str = True
                line.append(ch)
            elif raw.startswith(';/', i):
                in_block = True
                i += 2
                continue
            elif ch == ';':
                break
            elif ch == '{':
                in_doc = True
            else:
                line.append(ch)
            i += 1
        piece = ''.join(line).rstrip()
        if piece.endswith('\\'):
            buf += piece[:-1] + ' '
            continue
        full = (buf + piece).strip()
        buf = ''
        if full:
            out.append(full)
    if buf.strip():
        out.append(buf.strip())
    return out


def split_params(text):
    """Split a parameter list on top-level commas (default values may hold quoted commas)."""
    parts, cur, in_str = [], [], False
    for ch in text:
        if ch == '"':
            in_str = not in_str
        if ch == ',' and not in_str:
            parts.append(''.join(cur))
            cur = []
        else:
            cur.append(ch)
    tail = ''.join(cur).strip()
    if tail or parts:
        parts.append(''.join(cur))
    return [p.strip() for p in parts if p.strip()]


def parse_params(text):
    params = []
    for piece in split_params(text):
        m = PARAM_RE.match(piece)
        if not m:
            raise ValueError(f'unreadable parameter: {piece!r}')
        params.append(Param(m.group('type'), bool(m.group('array')), m.group('name'), m.group('default') is not None))
    return params


def parse_script(text):
    """Parse one script into a `Script`, or None when it has no `ScriptName` line."""
    script = None
    for line in logical_lines(text):
        if script is None:
            m = SCRIPT_RE.match(line)
            if m:
                flags = frozenset(fold(f) for f in m.group('flags').split())
                script = Script(m.group('name'), m.group('parent') or '', flags)
            continue
        m = CALLABLE_RE.match(line)
        if m:
            flags = frozenset(fold(f) for f in m.group('flags').split())
            ret = m.group('ret') or ''
            array = ret.endswith(']')
            ret = re.sub(r'\s*\[\s*\]$', '', ret)
            script.callables.append(Callable(fold(m.group('kind')), m.group('name'), ret, array,
                                             parse_params(m.group('params')), flags))
    return script


def read_archive(path):
    """Yield (member name, text) for every `.psc` member of a zip archive."""
    with zipfile.ZipFile(path) as z:
        for info in z.infolist():
            if info.filename.lower().endswith('.psc'):
                yield info.filename, z.read(info).decode('utf-8', 'replace')


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()


def scan_archive(path):
    """Parse every member. Returns (scripts, stats); a member that fails is counted, not fatal."""
    scripts, stats = [], {'members': 0, 'parsed': 0, 'no_scriptname': 0, 'errors': 0, 'duplicate_names': 0}
    seen = set()
    for member, text in read_archive(path):
        stats['members'] += 1
        try:
            s = parse_script(text)
        except ValueError:
            stats['errors'] += 1
            continue
        if s is None:
            stats['no_scriptname'] += 1
            continue
        if fold(s.name) in seen:
            stats['duplicate_names'] += 1
        seen.add(fold(s.name))
        stats['parsed'] += 1
        scripts.append(s)
    return scripts, stats


def native_table(scripts):
    """{folded script: {'name', 'parent', 'natives': [callable dict]}} for scripts with native callables."""
    table = {}
    for s in scripts:
        nat = s.natives
        if not nat:
            continue
        table[fold(s.name)] = {
            'name': s.name, 'parent': s.parent, 'flags': sorted(s.flags),
            'natives': [{'name': c.name, 'kind': c.kind, 'returns': c.returns, 'returns_array': c.returns_array,
                         'global': c.is_global, 'latent': 'latent' in c.flags,
                         'params': [[p.type, p.array, p.name, p.has_default] for p in c.params]} for c in nat]}
    return table


def summary(scripts, stats):
    nat = [c for s in scripts for c in s.natives]
    return {
        **stats,
        'scripts_with_natives': sum(1 for s in scripts if s.natives),
        'native_callables': len(nat),
        'native_functions': sum(1 for c in nat if c.kind == 'function'),
        'native_events': sum(1 for c in nat if c.kind == 'event'),
        'global': sum(1 for c in nat if c.is_global),
        'latent': sum(1 for c in nat if 'latent' in c.flags),
        'returning': sum(1 for c in nat if c.returns),
        'array_returns': sum(1 for c in nat if c.returns_array),
        'array_params': sum(1 for c in nat for p in c.params if p.array),
        'params': sum(len(c.params) for c in nat),
    }


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    pin = sub.add_parser('pin', help='SHA-256, size and member counts of the archive')
    pin.add_argument('archive')
    scan = sub.add_parser('scan', help='parse every script and report native declaration counts')
    scan.add_argument('archive')
    scan.add_argument('--out', help='write the native table here (a local file; never commit it)')
    a = ap.parse_args(argv)
    path = Path(a.archive)
    if a.cmd == 'pin':
        scripts, stats = scan_archive(path)
        print(json.dumps({'sha256': sha256_file(path), 'bytes': path.stat().st_size, **summary(scripts, stats)},
                         indent=1, sort_keys=True))
        return 0
    scripts, stats = scan_archive(path)
    print(json.dumps({'sha256': sha256_file(path), **summary(scripts, stats)}, indent=1, sort_keys=True))
    if a.out:
        Path(a.out).write_text(json.dumps({'schema': SCHEMA_VERSION, 'archive_sha256': sha256_file(path),
                                           'scripts': native_table(scripts)}, indent=1, sort_keys=True) + '\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
