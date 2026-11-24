"""Plan and apply bulk renames of matched functions whose name is a guess. Local input for the map.

For every `matched` inventory entry with `name_origin` GUESS the planner joins three public or
authorized sources on the function's RVA and its `Class::member` name:

- the CrashLogger community names, prototypes and boundaries under
  `reconstruction/generated/crashlogger_pdb/` (label `CRASHLOGGER_PDB(59818@<version>)`);
- the class/member membership of the 2013 linker map, read locally and never by CI (label
  `SYMBOLS(tesv-2013-map)`); only booleans and counts leave the reader, never an address or excerpt;
- the unit's own text: the compact `// 0x<rva> Name` line is the unit's statement of the function's
  current name, and the inventory name may lag it.

Each row gets one verdict:

- `sync-inventory`: the unit already carries the CrashLogger name with its label; only the inventory
  name, origin and source change;
- `label-source`: the unit already uses the CrashLogger name but with a guess label or none; the label
  line changes;
- `rename`: the unit names the function `Class::Function<hex>` in the CrashLogger class; the
  identifier, its declaration, its header line and its label change, in the unit's own files only;
- `ambiguous`: anything else, with a reason code. Ambiguous rows are reported and never renamed.

The conflict checks, each a reason code when it fails: `no-source-name`, `duplicate-claim` (another unit claims an RVA of the unit; the CI hash run and the bot cannot
tell the units apart), `no-class-claim`, `namespace-differs`,
`generated-family`, `source-name-differs`, `ownership-conflict`, `placeholder-name`,
`not-corroborated`, `size-differs`, `alias-or-overload` (the name sits on several CrashLogger RVAs, on
another inventory entry, or in a map fold group), `this-differs` (the prototype's `this` is another
class, the signature of a folded body), `prototype-arity`, `referenced-elsewhere` (the old identifier
occurs outside the unit's own files), `name-collision` and `label-format`.

A rename changes unit text, so every function of the unit must be re-confirmed; `verify` recompiles the
units on a runner host and requires the comparator to pass with the code-section hash of the old record.
The map names no address in anything this tool writes. A name taken from the CrashLogger PDB or the map is
a community hypothesis and never evidence of identity (docs/authorizations.md, Notes); a byte match is the
only acceptance.

    python3 tools/rename_planner.py plan --map PATH [--write]       # data/rename-plan.json + findings report
    python3 tools/rename_planner.py apply-source [--limit N]        # edit unit files for rename / label-source rows
    python3 tools/rename_planner.py apply-inventory                 # name, origin, source in data/progress.json
    python3 tools/rename_planner.py verify --host NAME [--jobs N]   # recompile edited units, compare hashes
"""
import argparse
import collections
import glob
import json
import os
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from check_code_rules import PLACEHOLDERS  # noqa: E402
from rva_headers import leading_lines  # noqa: E402
from symbol_corroboration import MAP_PUBLIC, grouped_digest  # noqa: E402
import symbol_align  # noqa: E402

PLAN = 'data/rename-plan.json'
REPORT = 'findings/rename-plan.md'
CRASHLOGGER = 'reconstruction/generated/crashlogger_pdb'
CRASHLOGGER_LABEL = 'CRASHLOGGER_PDB(59818@2026.10.24)'
SYMBOLS_LABEL = 'SYMBOLS(tesv-2013-map)'
SCHEMA_VERSION = 1
MAP_ADDRESS = re.compile(r'^ ([0-9a-fA-F]{4}:[0-9a-fA-F]{8})\s+(\S+)\s+[0-9a-fA-F]{8,16}( f)?( i)?\s+(\S+)\s*$')
PLAIN_NAME = re.compile(r'[A-Za-z_]\w*')
HEX_PLACEHOLDER = re.compile(r'Function[0-9a-f]+')
HEADER_LINE = re.compile(r'//[ \t]*0x([0-9a-fA-F]+)[ \t]+([A-Za-z_~][\w:~<>,]*)(\([^)]*\))?[ \t]*((?:const)?)[ \t]*$')
INDEX_ROW = re.compile(r'^\| `([^`]+)` \| `(.*?)` \((\w+)\) \| `[^`]+` / `0x([0-9a-f]+)` / (\d+)')
LABEL_LINE = re.compile(r'^//[ \t]*(.+?):[ \t]+((?:GUESS|COMMUNITY|CRASHLOGGER_PDB|SYMBOLS|SIBLING|EXE_RTTI|STANDIN|OBSERVED)\b.*)$')
GENERATED = re.compile(r'^(?:Static|StringStatic|DeletingLeaf|Leaf|ReturnLeaf|LeafAddress|LeafForward|FieldLeaf|Census|Thunk)\w*$')
CLNAME_BAD = re.compile(r'(?:^|::)(?:sub_|thunk_|loc_|dtor|ctor|vftable|vtable|lambda|`|<)|Func\d|_dtor$|__dtor|unk\d', re.I)
LABELLED = re.compile(r'COMMUNITY\(|CRASHLOGGER_PDB\(|SYMBOLS\(|SIBLING\(|EXE_RTTI|STANDIN|OBSERVED')
FLATTENED = re.compile(r'_[0-9a-f]{8}\b')


def load_json(path):
    return json.loads((ROOT / path).read_text(encoding='utf-8'))


def tsv_rows(kind, root=ROOT):
    for path in sorted(glob.glob(str(Path(root) / CRASHLOGGER / kind / '*.tsv'))):
        with open(path, encoding='utf-8') as handle:
            for line in handle:
                if line.startswith('#') or not line.strip():
                    continue
                yield line.rstrip('\n').split('\t')


def load_crashlogger(root=ROOT):
    names, protos, bounds = {}, {}, {}
    for row in tsv_rows('names', root):
        names[int(row[0], 16)] = row[1]
    for row in tsv_rows('prototypes', root):
        protos[int(row[0], 16)] = (row[1], row[2])
    for row in tsv_rows('boundaries', root):
        bounds[int(row[0], 16)] = int(row[1], 16)
    return names, protos, bounds


def read_map(path):
    """({(final class, member): fold-group size}, sha group digest). Addresses stay inside this function."""
    import hashlib
    digest = hashlib.sha256()
    at_address = collections.defaultdict(set)
    with open(path, 'rb') as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b''):
            digest.update(chunk)
    with open(path, encoding='latin-1') as handle:
        for line in handle:
            m = MAP_ADDRESS.match(line)
            if not m:
                continue
            found = symbol_align.member_of(m.group(2))
            at_address[m.group(1)].add((found[0].split('::')[-1], found[1]) if found else m.group(2))
    members = {}
    for group in at_address.values():
        pairs = [g for g in group if isinstance(g, tuple)]
        for pair in pairs:
            members[pair] = max(members.get(pair, 0), len(group) - 1)
    return members, grouped_digest(digest.hexdigest())


def index_units(root=ROOT):
    """{rva: (unit, name, origin)} from the generated index."""
    out = {}
    for line in (Path(root) / 'reconstruction/INDEX.md').read_text(encoding='utf-8').splitlines():
        m = INDEX_ROW.match(line)
        if m:
            out[int(m.group(4), 16)] = (m.group(1), m.group(2), m.group(3))
    return out


def unit_texts(unit, root=ROOT):
    """{'.cpp': text or None, '.h': text or None} of a unit stem."""
    out = {}
    for suffix in ('.cpp', '.h'):
        path = Path(root) / 'reconstruction' / (unit + suffix)
        out[suffix] = path.read_text(encoding='utf-8-sig') if path.is_file() else None
    return out


def header_names(texts):
    """{rva: (qualified name, params text or None)} from the compact header lines of a unit's files."""
    out = {}
    for suffix in ('.cpp', '.h'):
        for line in leading_lines(texts.get(suffix) or ''):
            m = HEADER_LINE.match(line.rstrip())
            if m:
                out.setdefault(int(m.group(1), 16), (m.group(2), m.group(3)))
    return out


def placeholder(word):
    return any(rx.search(word) for rx in PLACEHOLDERS)


def split_params(text):
    parts, depth, current = [], 0, ''
    for ch in text:
        if ch in '(<[':
            depth += 1
        elif ch in ')>]':
            depth -= 1
        if ch == ',' and depth == 0:
            parts.append(current)
            current = ''
        else:
            current += ch
    if current.strip():
        parts.append(current)
    return [p.strip() for p in parts]


def prototype_arity(cc, proto):
    """Argument count after `this` for a CrashLogger prototype `ret (a, b)`, or None."""
    m = re.match(r'^.*?\((.*)\)\s*$', proto or '')
    if not m:
        return None
    params = split_params(m.group(1))
    if params == ['void']:
        params = []
    return max(len(params) - 1, 0) if cc in ('thiscall', 'fastcall') else len(params)


def this_class(cc, proto):
    """The class a thiscall/fastcall prototype names as `this`, without the flattening hash suffix."""
    if cc not in ('thiscall', 'fastcall'):
        return None
    m = re.match(r'^.*?\(\s*([A-Za-z_]\w*?)(?:_[0-9a-f]{8})?\s*\*', proto or '')
    return m.group(1) if m else None


def source_arity(texts, qualified):
    """Parameter count of the definition or declaration of `Class::member` in the unit's files, or None."""
    cls, _, member = qualified.rpartition('::')
    for text in (texts.get('.cpp'), texts.get('.h')):
        if not text:
            continue
        for rx in (re.compile(r'\b' + re.escape(qualified) + r'\s*\('), re.compile(r'\b' + re.escape(member) + r'\s*\(')):
            for m in rx.finditer(text):
                depth, i = 1, m.end()
                while i < len(text) and depth:
                    depth += {'(': 1, ')': -1}.get(text[i], 0)
                    i += 1
                params = split_params(text[m.end():i - 1])
                if params == ['void']:
                    params = []
                return len(params)
    return None


def final_scope(name):
    parts = name.split('::')
    return (parts[-2] if len(parts) > 1 else None), parts[-1]


def reference_files(token, root=ROOT):
    """Files under reconstruction/ that mention an identifier as a whole word."""
    rx = re.compile(r'\b' + re.escape(token) + r'\b')
    out = []
    for path in glob.glob(str(Path(root) / 'reconstruction' / '**' / '*'), recursive=True):
        if os.path.isfile(path) and path.endswith(('.h', '.cpp')):
            if rx.search(Path(path).read_text(encoding='utf-8-sig', errors='replace')):
                out.append(str(Path(path).relative_to(root)))
    return out


def covers(names_text, qualified, member):
    names = [n.strip() for n in names_text.split(',')]
    return qualified in names or member in names


def leading_count(lines):
    count = 0
    while count < len(lines) and lines[count].startswith('//'):
        count += 1
    return count


def label_state(texts, qualified, member):
    """'labelled', 'guess' or 'none' for the label lines of the unit's files that cover the name."""
    found = []
    for suffix in ('.cpp', '.h'):
        for line in (texts.get(suffix) or '').split('\n'):
            m = LABEL_LINE.match(line.rstrip())
            if m and covers(m.group(1), qualified, member):
                found.append('guess' if 'GUESS' in m.group(2) and not LABELLED.search(m.group(2)) else 'labelled')
    return 'labelled' if 'labelled' in found else ('guess' if found else 'none')


def classify(entry, ctx):
    """One plan row for a matched GUESS inventory entry that has a CrashLogger name."""
    rva = entry['rva']
    cl = ctx['names'][rva]
    row = {'rva': f'0x{rva:x}', 'size': entry['size'], 'inventory': entry['name'], 'crashlogger': cl,
           'has_prototype': rva in ctx['protos'] and ctx['protos'][rva][1] not in ('void ()', 'void (void)')}
    unit = ctx['units'].get(rva)
    row['unit'] = unit[0] if unit else None
    cl_class, cl_member = final_scope(cl)
    pair = (cl_class, cl_member) if cl_class else None
    row['corroborated'] = bool(pair and pair in ctx['map_members'])
    # Reasons are checked in order; the first that applies decides the verdict.

    def ambiguous(reason):
        row.update(verdict='ambiguous', reason=reason)
        return row
    if not unit:
        return ambiguous('no-source-name')
    texts = unit_texts(unit[0], ctx['root'])
    row['texts'] = texts
    declared = header_names(texts).get(rva)
    if not declared:
        return ambiguous('no-source-name')
    source_name, source_params = declared
    row['source'] = source_name
    if any(len(ctx['claims'].get(r, ())) > 1 for r in header_names(texts)):
        return ambiguous('duplicate-claim')
    src_class, src_member = final_scope(source_name)
    if src_class is None and not HEX_PLACEHOLDER.fullmatch(src_member):
        pass
    if GENERATED.match(src_class or src_member) or not PLAIN_NAME.fullmatch(src_member):
        return ambiguous('generated-family')
    if not cl_class or CLNAME_BAD.search(cl) or FLATTENED.search(cl) or placeholder(cl_member) or not PLAIN_NAME.fullmatch(cl_member):
        return ambiguous('placeholder-name')
    if not row['corroborated']:
        return ambiguous('not-corroborated')
    if ctx['bounds'].get(rva) != entry['size']:
        return ambiguous('size-differs')
    if len(ctx['by_name'][cl]) > 1 or ctx['inventory_names'][cl] > 0 and source_name != cl:
        return ambiguous('alias-or-overload')
    if ctx['map_members'].get(pair, 0) > 0:
        return ambiguous('alias-or-overload')
    if source_name != cl and source_name.rpartition('::')[0] != cl.rpartition('::')[0] \
            and src_class == cl_class and (src_member == cl_member or HEX_PLACEHOLDER.fullmatch(src_member)):
        return ambiguous('namespace-differs')
    if source_name == cl:
        state = label_state(texts, source_name, src_member)
        row.update(verdict='sync-inventory' if state == 'labelled' else 'label-source', reason=None)
        return row
    cc, proto = ctx['protos'].get(rva, (None, None))
    if proto:
        this = this_class(cc, proto)
        if this and this != cl_class:
            return ambiguous('this-differs')
        want, have = prototype_arity(cc, proto), source_arity(texts, source_name)
        if want is not None and have is not None and want != have:
            return ambiguous('prototype-arity')
    if src_class is None:
        return ambiguous('no-class-claim')
    if src_class != cl_class:
        return ambiguous('ownership-conflict')
    if not HEX_PLACEHOLDER.fullmatch(src_member):
        return ambiguous('source-name-differs')
    own = {f'reconstruction/{unit[0]}{s}' for s in ('.cpp', '.h')}
    elsewhere = set(reference_files(src_member, ctx['root'])) - own
    if elsewhere:
        return ambiguous('referenced-elsewhere')
    if any(re.search(r'\b' + re.escape(cl_member) + r'\b', t or '') for t in texts.values()):
        return ambiguous('name-collision')
    if not texts.get('.cpp'):
        return ambiguous('label-format')
    row.update(verdict='rename', reason=None, old_member=src_member, new_member=cl_member)
    return row


def unit_claims(root=ROOT):
    """{rva: {unit stems}} from the compact header lines of every unit file outside the generated folder."""
    claims = collections.defaultdict(set)
    base = Path(root) / 'reconstruction'
    for path in list(base.rglob('*.cpp')) + list(base.rglob('*.h')):
        if 'generated' in path.relative_to(base).parts:
            continue
        with open(path, encoding='utf-8-sig', errors='replace') as handle:
            head = handle.read(6000)
        for line in leading_lines(head):
            m = HEADER_LINE.match(line.rstrip())
            if m:
                claims[int(m.group(1), 16)].add(str(path.relative_to(base).with_suffix('')))
    return claims


def build_context(root=ROOT, map_path=None, progress_path=None):
    names, protos, bounds = load_crashlogger(root)
    progress = json.loads(Path(progress_path or Path(root) / 'data/progress.json').read_text(encoding='utf-8'))
    by_name = collections.defaultdict(list)
    for rva, name in names.items():
        by_name[name].append(rva)
    inventory_names = collections.Counter(f['name'] for f in progress['functions'] if f['name_origin'] != 'GUESS')
    members, source = read_map(map_path) if map_path else ({}, None)
    return {'root': Path(root), 'names': names, 'protos': protos, 'bounds': bounds, 'by_name': by_name,
            'inventory_names': inventory_names, 'map_members': members, 'map_source': source,
            'units': index_units(root), 'progress': progress, 'claims': unit_claims(root)}


def plan(ctx):
    rows = []
    for entry in ctx['progress']['functions']:
        if entry['status'] == 'matched' and entry['name_origin'] == 'GUESS' and entry['rva'] in ctx['names']:
            rows.append(classify(entry, ctx))
    for row in rows:
        row.pop('texts', None)
    # Prototype evidence first, then address order: the order in which the rows are applied.
    rows.sort(key=lambda r: (not r['has_prototype'], int(r['rva'], 16)))
    return rows


def summarize(rows):
    pool = [r for r in rows if r['corroborated']]
    verdicts = collections.Counter(r['verdict'] for r in pool)
    reasons = collections.Counter(r['reason'] for r in pool if r['verdict'] == 'ambiguous')
    return {'guess_with_crashlogger_name': len(rows), 'corroborated': len(pool),
            'corroborated_with_prototype': sum(1 for r in pool if r['has_prototype']),
            'verdicts': dict(sorted(verdicts.items())), 'ambiguous_reasons': dict(sorted(reasons.items()))}


def plan_document(rows, ctx):
    pool = [r for r in rows if r['corroborated']]
    return {'schema_version': SCHEMA_VERSION,
            'note': 'Verdicts of tools/rename_planner.py on matched GUESS entries that have a CrashLogger name and a '
                    'member of that class and name in the 2013 map. Hypotheses, not evidence of identity. No map address.',
            'labels': [CRASHLOGGER_LABEL, SYMBOLS_LABEL],
            'sources': {'tesv-2013-map': ctx['map_source']},
            'summary': summarize(rows),
            'rows': [{k: r.get(k) for k in ('rva', 'unit', 'inventory', 'source', 'crashlogger', 'verdict', 'reason',
                                            'has_prototype', 'old_member', 'new_member') if r.get(k) is not None}
                     for r in pool]}


def report_text(doc, date=None):
    import datetime
    s = doc['summary']
    date = date or datetime.datetime.now(datetime.timezone.utc).strftime('%Y-%m-%d')
    lines = [
        '# Finding: CrashLogger and 2013-map names for matched functions that carry a guess', '',
        'Status: HYPOTHESIS',
        'Author / human operator: awarebayes',
        'AI assistance / model: Claude Code (claude-sonnet-5-5), run locally on the operator\'s machine',
        f'Date (UTC): {date}',
        'Target build id / image SHA-256: `sse-steam-1-7-104` /',
        '`846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`',
        'Function RVA / size (if applicable): not applicable (per-row table below)',
        'Source exposure: mixed (this repository\'s tracked CrashLogger tables and unit sources; the 2013 linker map',
        'held by the operator, read locally; the model saw class and member names, no code, no bytes and no address)',
        'Sources and immutable revisions / licenses: `reconstruction/generated/crashlogger_pdb` (59818@2026.10.24);',
        f"the linker map identified by SHA-256 `{doc['sources']['tesv-2013-map']}` (grouped); no licence grant",
        'Name provenance: CRASHLOGGER_PDB, SYMBOLS(tesv-2013-map)',
        'Confidence: high for the counts; low to medium for any single name as a name in the pinned image', '',
        '## Question and method', '',
        'Which matched functions that still carry a guessed name can take the CrashLogger community name at their RVA,',
        'with that name\'s class and member also present in the 2013 map? `tools/rename_planner.py plan` joined the',
        'inventory, the CrashLogger names, boundaries and prototypes, the unit\'s own header lines and the map\'s',
        'class and member membership (a static, local analysis; the map reader returns booleans and fold-group sizes,',
        'never an address). Each row got one verdict, and the first failing conflict check decides an ambiguous row.', '',
        '## Result', '',
        f"- matched GUESS entries with a CrashLogger name: {s['guess_with_crashlogger_name']}",
        f"- class and member present in the map: {s['corroborated']} ({s['corroborated_with_prototype']} with a prototype)",
        '- verdicts: ' + ', '.join(f'{k} {v}' for k, v in s['verdicts'].items()),
        '- `rename` rows change a placeholder method name in the unit\'s own files; `label-source` rows add the labels to a',
        '  name the unit already uses; `sync-inventory` rows only update the inventory name, origin and source.', '',
        '## Ambiguous rows by reason', '']
    for reason, count in s['ambiguous_reasons'].items():
        lines.append(f'- `{reason}`: {count}')
    lines += ['', '## Limitations', '',
              '- Class and member membership is not overload or signature identity, and the map is another build; a name',
              '  from either table is a community hypothesis, never evidence of identity. A byte match is the only acceptance.',
              '- Folded bodies carry the name of one of their original owners; `generated-family`, `this-differs` and',
              '  `alias-or-overload` rows are the visible cases and every one is left unnamed here.',
              '- The prototype checks use the CrashLogger signature only to refuse a rename; no signature is adopted.',
              '- A negative result here (ambiguous) says the name was not adopted, not that it is wrong.', '',
              '## Ambiguous rows', '',
              '| RVA | unit | name in unit | CrashLogger name | reason |', '|---|---|---|---|---|']
    for row in doc['rows']:
        if row['verdict'] == 'ambiguous':
            lines.append(f"| `{row['rva']}` | `{row.get('unit', '')}` | `{row.get('source', row['inventory'])}` | "
                         f"`{row['crashlogger']}` | `{row['reason']}` |")
    return '\n'.join(lines) + '\n'


# ---- apply ----

def rename_text(text, old_member, new_member, qualified_old, qualified_new, rva):
    """Rename the identifier in one file and move its label to CrashLogger."""
    text = re.sub(r'\b' + re.escape(old_member) + r'\b', new_member, text)
    return text


def set_label(texts, qualified, member):
    """Give the name the CrashLogger and map labels in the unit's leading comment; returns the texts."""
    new_line = f'// {qualified}: {CRASHLOGGER_LABEL} {SYMBOLS_LABEL}'
    for suffix in ('.cpp', '.h'):
        if not texts.get(suffix):
            continue
        lines = texts[suffix].split('\n')
        for i in range(len(lines)):
            m = LABEL_LINE.match(lines[i].rstrip())
            if not (m and covers(m.group(1), qualified, member)):
                continue
            if 'GUESS' not in m.group(2) or LABELLED.search(m.group(2)):
                return texts
            rest = [n.strip() for n in m.group(1).split(',') if n.strip() not in (qualified, member)]
            lines[i:i + 1] = ([f"// {', '.join(rest)}: {m.group(2)}"] if rest else []) + [new_line]
            texts[suffix] = '\n'.join(lines)
            return texts
    lines = texts['.cpp'].split('\n')
    lines.insert(leading_count(lines), new_line)
    texts['.cpp'] = '\n'.join(lines)
    return texts


def apply_source(rows, ctx, limit=None):
    """Write unit files for `rename` and `label-source` rows; returns [(unit, [rva])]."""
    by_unit = collections.OrderedDict()
    for row in rows:
        if row.get('verdict') in ('rename', 'label-source'):
            by_unit.setdefault(row['unit'], []).append(row)
    changed = []
    for unit, group in list(by_unit.items())[:limit]:
        texts = unit_texts(unit, ctx['root'])
        for row in group:
            qualified = row['source']
            cls = final_scope(qualified)[0]
            if row['verdict'] == 'rename':
                new_qualified = f"{qualified.rsplit('::', 1)[0]}::{row['new_member']}"
                for suffix, text in texts.items():
                    if text:
                        texts[suffix] = rename_text(text, row['old_member'], row['new_member'], qualified, new_qualified, row['rva'])
                qualified = new_qualified
            texts = set_label(texts, qualified, qualified.rsplit('::', 1)[-1])
        for suffix, text in texts.items():
            if text:
                path = Path(ctx['root']) / 'reconstruction' / (unit + suffix)
                if path.read_text(encoding='utf-8-sig') != text:
                    path.write_text(text, encoding='utf-8')
        changed.append((unit, [r['rva'] for r in group]))
    return changed


def name_source(rva, corroborated):
    text = (f'{CRASHLOGGER_LABEL}: public name at RVA {rva} in the CrashLogger community PDB '
            '(reconstruction/generated/crashlogger_pdb/names); a community guess, not evidence.')
    if corroborated:
        text += (f' {SYMBOLS_LABEL}: the class has a member of this name in the 2013 linker map '
                 '(class and member only; no address, signature or overload identity).')
    return text


def apply_inventory(doc, root=ROOT):
    path = Path(root) / 'data/progress.json'
    text = path.read_text(encoding='utf-8')
    progress = json.loads(text)
    verdicts = {r['rva']: r for r in doc['rows'] if r['verdict'] in ('rename', 'label-source', 'sync-inventory')}
    count = 0
    for entry in progress['functions']:
        row = verdicts.get(f"0x{entry['rva']:x}")
        if row and entry['status'] == 'matched' and entry['name_origin'] == 'GUESS':
            entry['name'] = row['crashlogger']
            entry['name_origin'] = 'CRASHLOGGER_PDB'
            entry['name_source'] = name_source(row['rva'], True)
            count += 1
    path.write_text(json.dumps(progress, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
    return count


def verify(host_name, jobs, rows, since='HEAD', out=None):
    """Recompile every unit whose closure the edits touched on a runner host and compare with the old records.

    A function is `equal` when the comparator passes and its code-section hash is one the record's runs
    reported; the tree digest differs by construction. A renamed function is looked up under its renamed
    symbol. Returns the per-function rows; private run files stay under .local/."""
    from concurrent.futures import ThreadPoolExecutor
    sys.path.insert(0, str(ROOT / 'tools' / 'verifier'))
    import pipeline  # noqa: E402
    import reproduce_records as rr  # noqa: E402
    import runners  # noqa: E402
    import unit_selection  # noqa: E402
    config = runners.load()
    if config is None or host_name not in config['hosts'] or config['hosts'][host_name]['backend'] == 'boat':
        raise runners.RunnerError(f'{host_name} is not a local or ssh host in {runners.config_path()}')
    host = runners.with_image(config['hosts'][host_name])
    target, recs = rr.records()
    progress = json.loads((ROOT / 'data/progress.json').read_text(encoding='utf-8'))
    matched = {f['id'] for f in progress['functions'] if f.get('status') == 'matched'}
    out_root = Path(out) if out else runners.main_root() / '.local' / 'rename-verify' / host['host_id']
    pipeline.private_root(out_root)
    todo = rr.units(recs, target, matched, out_root)
    deps = {}
    for task, by_rva in todo:
        extra = deps.setdefault(task['compiled'], {task['recipe'], task['symbols_repo']})
        for rec in by_rva.values():
            extra.update(rec['source'].get('translation_unit') or ())
    changed = {p for p in unit_selection.changed_paths(rr.REPO, since) if p.startswith('reconstruction/')}
    keep = set()
    with unit_selection.source_digest_cache():
        for compiled, extra in deps.items():
            if (extra | {compiled} | set(unit_selection.include_closure(rr.REPO, compiled))) & changed:
                keep.add(compiled)
    why = f'{len(keep)} of {len(deps)} units include a changed reconstruction file'
    todo = [t for t in todo if t[0]['compiled'] in keep]
    renamed = {int(r['rva'], 16): r for r in rows if r.get('verdict') == 'rename'}
    for task, _by_rva in todo:
        swaps = {}
        for fn in task['functions']:
            r = renamed.get(fn['rva'])
            if r:
                old = fn['symbol']
                fn['symbol'] = old.replace(f"?{r['old_member']}@", f"?{r['new_member']}@", 1)
                swaps[old] = fn['symbol']
        if swaps:
            # The unit's symbol map names each definition by its decorated name; bind the renamed ones again.
            data = json.loads(Path(task['symbols_local']).read_text(encoding='utf-8'))
            data['symbols'] = {swaps.get(k, k): v for k, v in data['symbols'].items()}
            for item in data.get('_provenance', {}).get('entries', ()):
                item['name'] = swaps.get(item['name'], item['name'])
            patched = Path(out_root) / f"{task['task_id']}-renamed-symbols.json"
            patched.write_text(json.dumps(data, indent=1), encoding='utf-8')
            task['symbols_local'] = patched
    results = []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        results = list(pool.map(lambda t: (t, rr.reproduce_unit(host, t[0], t[1], out_root, lambda m: None)), todo))
    verdicts = []
    for (task, by_rva), unit in results:
        for fn in unit['functions']:
            expected = rr.expected(by_rva[fn['rva']])[1]
            ok = fn['code_section_sha256'] in expected
            verdicts.append({'unit': unit['unit'], 'rva': f"0x{fn['rva']:x}", 'verdict': 'equal' if ok else 'different',
                             'why': None if ok else (fn['why'] if fn['code_section_sha256'] is None else 'code-section-hash-differs')})
    return verdicts, why


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)
    plan_p = sub.add_parser('plan')
    plan_p.add_argument('--map', required=True)
    plan_p.add_argument('--write', action='store_true')
    plan_p.add_argument('--progress', help='inventory file to plan from instead of data/progress.json')
    src = sub.add_parser('apply-source')
    src.add_argument('--map', required=True)
    src.add_argument('--limit', type=int)
    sub.add_parser('apply-inventory')
    ver = sub.add_parser('verify')
    ver.add_argument('--host', required=True)
    ver.add_argument('--jobs', type=int, default=2)
    ver.add_argument('--since', default='HEAD')
    args = p.parse_args(argv)
    if os.environ.get('CI'):
        print('refusing to read the map in CI', file=sys.stderr)
        return 2
    if args.cmd == 'apply-inventory':
        doc = load_json(PLAN)
        print(f'{apply_inventory(doc)} inventory entries renamed')
        return 0
    if args.cmd == 'verify':
        doc = load_json(PLAN)
        verdicts, why = verify(args.host, args.jobs, doc['rows'], args.since)
        print(why)
        bad = [v for v in verdicts if v['verdict'] != 'equal']
        print(f'{len(verdicts) - len(bad)}/{len(verdicts)} equal')
        for v in bad:
            print('DIFFERENT', v['unit'], v['rva'], v['why'])
        return 1 if bad else 0
    ctx = build_context(ROOT, args.map, getattr(args, 'progress', None))
    rows = plan(ctx)
    if args.cmd == 'plan':
        doc = plan_document(rows, ctx)
        print(json.dumps(doc['summary'], indent=1))
        if args.write:
            (ROOT / PLAN).write_text(json.dumps(doc, indent=1, ensure_ascii=False) + '\n', encoding='utf-8')
            (ROOT / REPORT).write_text(report_text(doc), encoding='utf-8')
        return 0
    if args.cmd == 'apply-source':
        # classify() stripped the texts; apply re-reads the files.
        for unit, rvas in apply_source(rows, ctx, args.limit):
            print(unit, ' '.join(rvas))
        return 0
    return 2


if __name__ == '__main__':
    sys.exit(main())
