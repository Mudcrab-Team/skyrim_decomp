"""Every PDB and symbol-file fact the project holds about one function, in one place.

    python3 tools/pdb_facts.py 0x1645d0 [--json] [--no-local]

Committed sources (always available): the CrashLogger PDB output under
`reconstruction/generated/crashlogger_pdb/` (name, prototype, size, class layout header) and
`data/symbol-alignment.json`, `data/symbol-names.json` and `data/name-corroboration.json` (names and
prototypes proposed from the 2013 map and the sibling program databases).

Local sources, only when you hold the files under `.local/inputs/symbols/` (or `SR_SYMBOLS_DIR`) and never
in CI: the 2013 Skyrim linker map (aligned name, prototype, object file, neighbouring members) and the Fallout 4
program database (class layout and the method's prototype where the class is shared). Map addresses are
never printed, and nothing here is evidence of identity: a byte match is the only acceptance.

Each fact is followed by the label line to paste into a unit when you take that fact from it.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import local_paths  # noqa: E402
import pdb_types  # noqa: E402
import symbol_align  # noqa: E402

# Sizes and SHA-256 values as recorded in docs/authorizations.md (four-group spelling).
SYMBOL_FILES = {
    'tesv-2013-map': ('tesv-2013-07-17/TESV.map', 41662359,
                      'fed7f0b964ea752f-e677f4c413c37c97-b5cad21541755c69-c701a66423b288b2'),
    'fo4-pdb': ('fo4-2019-10-23/Fallout4.pdb', 452201472,
                '6c5db527eaa981c1-c258b4523c21b677-4332b2fe520bb5fa-25ae96e2dde01917'),
    'fo4-beta-pdb': ('fo4-2019-10-23/Fallout4Beta.pdb', 670411776,
                     '9398b7f82aa08e0b-95cb88744af433e5-7303175f5085cf64-ec45f04e9081a099'),
}
DOWNLOADS = {
    'fo4-pdb': 'https://debugging.games/_files/Windows/[WIN]%20Fallout%204%20[2019-10-23]%20(PDB).7z',
    'tesv-2013-map': 'https://debugging.games/_files/Windows/[WIN]%20The%20Elder%20Scrolls%20V%20Skyrim%20[2013-07-17]%20(MAP).7z',
}
LAYOUT_LINES = 40
NEIGHBOURS = 2


def symbols_dir(repo=ROOT, env=None):
    env = os.environ if env is None else env
    if env.get('SR_SYMBOLS_DIR'):
        return Path(env['SR_SYMBOLS_DIR'])
    return local_paths.local_path(repo, '.local/inputs/symbols', env)


def locate(repo=ROOT, env=None):
    """{key: Path or None} for each symbol file under the symbols directory."""
    base = symbols_dir(repo, env)
    out = {}
    for key, (rel, _size, _sha) in SYMBOL_FILES.items():
        path = base / rel
        out[key] = path if path.is_file() else None
    return out


def verify(key, path, full=True):
    """'ok', 'missing', 'size' or 'sha256' for one located file."""
    if path is None:
        return 'missing'
    _rel, size, sha = SYMBOL_FILES[key]
    if path.stat().st_size != size:
        return 'size'
    if not full:
        return 'ok'
    digest = hashlib.sha256()
    with open(path, 'rb') as handle:
        for chunk in iter(lambda: handle.read(1 << 22), b''):
            digest.update(chunk)
    return 'ok' if digest.hexdigest() == sha.replace('-', '') else 'sha256'


def setup_lines(repo=ROOT, env=None, full=False):
    """(ok, lines) describing which symbol files are present and what to download for the missing ones."""
    found, lines, ok = locate(repo, env), [], True
    for key, path in found.items():
        if key == 'fo4-beta-pdb':
            continue
        state = verify(key, path, full)
        if state == 'ok':
            lines.append(f'ok   {key}: {path}')
        else:
            ok = False
            lines.append(f'MISS {key}: {state}; download {DOWNLOADS[key]} and extract only the '
                         f'{"map" if key == "tesv-2013-map" else "PDB"} to {symbols_dir(repo, env) / SYMBOL_FILES[key][0]}')
    return ok, lines


# --- inventory and committed data -----------------------------------------------------------------

def _load(path):
    try:
        return json.loads(Path(path).read_text())
    except (OSError, ValueError):
        return {}


def inventory_entry(repo, rva):
    for fn in _load(Path(repo) / 'data/progress.json').get('functions', []):
        if fn['rva'] == rva:
            return fn
    return None


def committed_facts(repo, rva, name=None, tree=None, alignment=None):
    """Facts from committed data. A caller doing many RVAs passes the loaded `tree` and `alignment`
    once, since reading them dominates the cost of one lookup."""
    out = {}
    key = f'0x{rva:x}'
    tree = tree or pdb_types.load_tree(repo)
    pdb_name = tree[0].get(rva)
    proto = pdb_types.lookup_prototype(rva, repo)
    bound = pdb_types.boundary_of(rva, repo)
    hint = pdb_types.lookup_rva(rva, repo, tree)
    version = pdb_types.tree_version(repo)
    if pdb_name or proto or bound:
        out['crashlogger'] = {
            'name': pdb_name,
            'convention': proto[0] if proto else None,
            'prototype': proto[1] if proto else None,
            'size': bound[1] if bound and bound[0] == rva else None,
            'layout_header': hint['header'] if hint else None,
            'class': hint['class'] if hint else None,
            'label': pdb_types.label(version),
        }
    if alignment is None:
        alignment = _load(Path(repo) / 'data/symbol-alignment.json')
    aligned = (alignment.get('functions') or {}).get(key)
    if aligned:
        out['alignment'] = dict(aligned, label=f'SYMBOLS({aligned["source"]})')
    cls = (name or '').rpartition('::')[0]
    if cls:
        entry = (_load(Path(repo) / 'data/symbol-names.json').get('classes') or {}).get(cls) or {}
        objects = sorted({o for names in (entry.get('objects') or {}).values() for o in names})
        if objects:
            out['objects'] = objects
    return out


# --- local facts ----------------------------------------------------------------------------------

def _undname(decorated):
    tool = shutil.which('llvm-undname') or '/opt/homebrew/opt/llvm/bin/llvm-undname'
    if not Path(tool).exists() or not decorated:
        return [''] * len(decorated)
    return symbol_align.undname_all(decorated, tool)


_MAP_CACHE = {}  # one parse of the map per process: a review asks about many functions


def map_facts(path, rva, name, inventory):
    """Aligned or anchored name, prototype, object file and neighbouring member names from the 2013 map."""
    key = (str(path), len(inventory))
    if key not in _MAP_CACHE:
        with open(path, encoding='latin-1') as handle:
            sets = symbol_align.variants(handle)
        _MAP_CACHE[key] = (sets, [symbol_align.Aligner(e, inventory) for e in sets])
    sets, aligners = _MAP_CACHE[key]
    entries = sets[0]
    hit = symbol_align.propose_any(aligners, rva)
    how = 'aligned' if hit else None
    index = None
    if hit:
        for i, (dec, obj) in enumerate(entries):
            if dec == hit[0] and obj == hit[1]:
                index = i
                break
    elif rva in aligners[0].anchor_index:
        index, how = aligners[0].anchor_index[rva], 'named'
    if index is None:
        return None
    dec, obj = entries[index]
    near = []
    for k in range(index - NEIGHBOURS, index + NEIGHBOURS + 1):
        if k != index and 0 <= k < len(entries) and entries[k][1] == obj:
            m = symbol_align.member_of(entries[k][0])
            if m:
                near.append(f'{m[0]}::{m[1]}')
    member = symbol_align.member_of(dec)
    return {'how': how, 'name': f'{member[0]}::{member[1]}', 'prototype': _undname([dec])[0],
            'object': re.split(r'[:\\/]', obj)[-1], 'neighbours': near,
            'tier': hit[2] if hit else None, 'label': 'SYMBOLS(tesv-2013-map)'}


def fo4_facts(path, name):
    """Layout and method prototypes for the Fallout 4 class of the same name, when the class is shared."""
    cls, _, method = (name or '').rpartition('::')
    if not cls:
        return None
    import symbol_corroboration
    protos = []
    for dec, _home in symbol_corroboration.pdb_publics(path):
        m = symbol_align.member_of(dec)
        if m and m[0] == cls and m[1] == method:
            protos.append(dec)
    layout = None
    msf = pdb_types.Msf(Path(path).read_bytes())
    model = pdb_types.Model(pdb_types.Tpi(msf.stream(2)))
    if cls in model.variants:
        _key, index = model.variants[cls][0]
        layout = pdb_types.Renderer(model).render(index).text.rstrip('\n').split('\n')
    if not protos and not layout:
        return None
    return {'prototypes': _undname(protos[:4]) if protos else [], 'layout': layout, 'class': cls,
            'label': 'SYMBOLS(fo4-pdb)'}


def collect(repo, rva, local=True, env=None):
    env = os.environ if env is None else env
    fn = inventory_entry(repo, rva)
    name = (fn or {}).get('name')
    facts = {'rva': f'0x{rva:x}', 'inventory_name': name, 'committed': committed_facts(repo, rva, name)}
    if local and not env.get('CI'):
        files = locate(repo, env)
        inv = [(f['rva'], f.get('name') or '') for f in _load(Path(repo) / 'data/progress.json').get('functions', [])]
        if files['tesv-2013-map'] and verify('tesv-2013-map', files['tesv-2013-map'], False) == 'ok':
            facts['map'] = map_facts(files['tesv-2013-map'], rva, name, inv)
        if files['fo4-pdb'] and verify('fo4-pdb', files['fo4-pdb'], False) == 'ok':
            facts['fo4'] = fo4_facts(files['fo4-pdb'], name or (facts['committed'].get('crashlogger') or {}).get('name'))
        facts['local_missing'] = [k for k in ('tesv-2013-map', 'fo4-pdb') if not files[k]]
    return facts


def render(facts):
    lines = [f'PDB facts for {facts["rva"]} (inventory name: {facts["inventory_name"] or "none"}); hints, never identity']
    cl = facts['committed'].get('crashlogger')
    if cl:
        if cl['name']:
            lines.append(f'  CrashLogger name: {cl["name"]}')
        if cl['prototype']:
            lines.append(f'  CrashLogger prototype: {cl["convention"]} {cl["prototype"]} (first parameter is the `this`, '
                         'often another class)')
        if cl['size'] is not None:
            lines.append(f'  CrashLogger size: 0x{cl["size"]:x} bytes')
        if cl['layout_header']:
            lines.append(f'  CrashLogger layout: {cl["layout_header"]}')
        lines.append(f'  label: {cl["label"]}')
    al = facts['committed'].get('alignment')
    if al:
        lines.append(f'  Map alignment (committed, {al["confidence"]}): {al["name"]} in {al["object"]}')
        if al['prototype']:
            lines.append(f'    prototype: {al["prototype"]}')
        lines.append(f'  label: {al["label"]}')
    if facts['committed'].get('objects'):
        lines.append('  Object files of the class (map): ' + ', '.join(facts['committed']['objects']))
    mp = facts.get('map')
    if mp:
        lines.append(f'  2013 map ({mp["how"]}{", " + mp["tier"] if mp["tier"] else ""}): {mp["name"]} in {mp["object"]}')
        if mp['prototype']:
            lines.append(f'    prototype: {mp["prototype"]}')
        if mp['neighbours']:
            lines.append('    neighbours: ' + ', '.join(mp['neighbours']))
        lines.append(f'  label: {mp["label"]}')
    fo = facts.get('fo4')
    if fo:
        for proto in fo['prototypes']:
            lines.append(f'  FO4 prototype: {proto}')
        if fo['layout']:
            lines.append(f'  FO4 layout of {fo["class"]}:')
            lines += ['    ' + ln for ln in fo['layout'][:LAYOUT_LINES]]
            if len(fo['layout']) > LAYOUT_LINES:
                lines.append(f'    ... {len(fo["layout"]) - LAYOUT_LINES} more lines')
        lines.append(f'  label: {fo["label"]}')
    missing = facts.get('local_missing')
    if missing:
        lines.append(f'  Not available locally: {", ".join(missing)}; `./sr setup` says what to download.')
    if len(lines) == 1:
        lines.append('  none known')
    return '\n'.join(lines)


def brief(repo, rva, name=None):
    """One short committed-data summary for a list row, or ''."""
    f = committed_facts(repo, rva, name)
    parts = []
    cl = f.get('crashlogger') or {}
    if cl.get('prototype'):
        parts.append(f'proto {cl["prototype"][:60]}')
    if cl.get('size') is not None:
        parts.append(f'size 0x{cl["size"]:x}')
    if f.get('alignment'):
        parts.append(f'map name {f["alignment"]["name"]} ({f["alignment"]["confidence"]})')
    return 'facts: ' + '; '.join(parts) if parts else ''


# --- agreement ------------------------------------------------------------------------------------

def split_params(text):
    out, depth, cur = [], 0, ''
    for ch in text:
        if ch in '(<[':
            depth += 1
        elif ch in ')>]':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip() and cur.strip() != 'void':
        out.append(cur.strip())
    return out


def unit_signature(source, cls, method):
    """(return type, parameter list) of the first definition of `cls::method` in `source`, or None."""
    m = re.search(r'(?m)^[ \t]*([A-Za-z_][\w:<>,\s\*&]*?)[ \t\*&]+(?:__\w+\s+)?' + re.escape(cls) + r'::' + re.escape(method)
                  + r'\s*\(([^)]*)\)', source)
    if not m:
        m = re.search(r'(?m)^[ \t]*' + re.escape(cls) + r'::' + re.escape(method) + r'\s*\(([^)]*)\)', source)
        return ('', split_params(m.group(1))) if m else None
    return m.group(1).strip(), split_params(m.group(2))


def pdb_signature(prototype):
    """(return type, parameter count without `this`) from `ret (this*, a, b)`."""
    m = re.match(r'^(.*?)\s*\((.*)\)\s*$', prototype or '')
    if not m:
        return None
    params = split_params(m.group(2))
    return m.group(1).strip(), max(len(params) - 1, 0)


def canonical(name):
    """Class::Method with constructor and destructor spellings folded (ctor, Ctor, Class, dtor, ~Class)."""
    cls, _, method = name.rpartition('::')
    last = cls.rpartition('::')[2]
    low = method.lower()
    if low in ('ctor', 'constructor') or method == last:
        method = '<ctor>'
    elif low in ('dtor', 'destructor') or method == '~' + last:
        method = '<dtor>'
    return f'{cls}::{method}'


def agreement(repo, rva, name, source=None, compiled_size=None):
    """Advisory findings where a reconstruction disagrees with a known PDB name, prototype or size. An
    empty list means no PDB fact contradicts it (or none exists)."""
    facts = committed_facts(repo, rva, name)
    cl = facts.get('crashlogger') or {}
    out = []
    if cl.get('name') and name and canonical(cl['name']) != canonical(name) and not symbol_align.is_placeholder(name):
        out.append(f'name {name} differs from the CrashLogger PDB name {cl["name"]}')
    if source and cl.get('prototype') and name and '::' in name:
        cls, _, method = name.rpartition('::')
        got, want = unit_signature(source, cls, method), pdb_signature(cl['prototype'])
        if got and want:
            ret, params = got
            if len(params) != want[1]:
                out.append(f'{name} takes {len(params)} parameters; the CrashLogger PDB prototype has {want[1]}')
            if ret and (ret == 'void') != (want[0] == 'void'):
                out.append(f'{name} returns {ret}; the CrashLogger PDB prototype returns {want[0]}')
    if cl.get('size') is not None and compiled_size is not None and cl['size'] != compiled_size:
        out.append(f'compiled size 0x{compiled_size:x} differs from the PDB size 0x{cl["size"]:x}')
    return out


COMPARED = re.compile(r'^//[ \t]*0x([0-9a-fA-F]+)[ \t]+(\S+)', re.M)


def unit_functions(source):
    """{rva: name} of the functions a unit claims with its `// 0x<rva> Class::Method` lines."""
    return {int(r, 16): n for r, n in COMPARED.findall(source)}


def advisory_for_unit(repo, rel_path):
    """Advisory lines for each function a unit claims whose name, signature or size disagrees with a known
    CrashLogger PDB fact. The header beside a .cpp is read too, where declarations live."""
    path = Path(repo) / rel_path
    try:
        source = path.read_text(encoding='utf-8', errors='replace')
    except OSError:
        return []
    header = path.with_suffix('.h')
    if header != path and header.is_file():
        source += '\n' + header.read_text(encoding='utf-8', errors='replace')
    out = []
    for rva, name in sorted(unit_functions(source).items()):
        fn = inventory_entry(repo, rva)
        for finding in agreement(repo, rva, name, source, (fn or {}).get('size')):
            out.append(f'0x{rva:x}: {finding}')
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('rva')
    ap.add_argument('--json', action='store_true')
    ap.add_argument('--no-local', action='store_true', help='committed data only')
    args = ap.parse_args(argv)
    rva = int(args.rva, 16) if args.rva.lower().startswith('0x') else int(args.rva, 0)
    facts = collect(ROOT, rva, local=not args.no_local)
    print(json.dumps(facts, indent=1, sort_keys=True) if args.json else render(facts))
    return 0


if __name__ == '__main__':
    sys.exit(main())
