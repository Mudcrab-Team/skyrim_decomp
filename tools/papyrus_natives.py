"""Typed prototypes for native script-engine callbacks. Local input.

Joins three things, all read locally from inputs you hold:

1. the native declarations of the shipped script archive (`tools/papyrus_psc.py scan`);
2. the executable's native registrations: each registration builds a function object from a script
   name, a function name, a virtual table and a handler address (`harvest_handlers.RegistrationSiteScanner`);
3. the run-time type information of the function object's class, `NativeFunctionN<Self, R, A1..An>`, whose
   template arguments spell the handler's real parameter types.

Per handler it writes (privately, `.local/papyrus/registrations.json`) the script and function
name, the declared Papyrus signature and a typed C++ prototype built from the class arguments, and
whether the two agree on arity and primitive types. What is printed, and what `--summary` writes, is counts
only. Published names for a handler come from the same rows under the usual rules: `OBSERVED`, never
evidence of identity, only a byte match is acceptance.

    python3 tools/papyrus_natives.py sites   --config CFG [--out .local/papyrus]
    python3 tools/papyrus_natives.py join    --config CFG --natives .local/papyrus/natives.json [--out .local/papyrus]
    python3 tools/papyrus_natives.py counts  --out .local/papyrus [--summary findings-counts.json]

The config is the private one `tools/ghidra/export_pack.py` reads. Nothing here is committed except the code.
"""
import argparse
import collections
import glob
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE / 'ghidra'))
import harvest_handlers as hh  # noqa: E402

CL_NAMES = 'reconstruction/generated/crashlogger_pdb/names'
NATIVE_CLASS_RE = re.compile(r'^NativeFunction(?P<n>\d+)<(?P<args>.*)@BSScript>$')
CL_PAPYRUS_RE = re.compile(r'^papyrus(?:::|__)(?P<script>\w+)::(?P<fn>\w+?)(?:_H?[0-9A-Fa-f]{3,}(?:_\d+)?)?$')
PRIMITIVE = {'X': 'void', '_N': 'bool', 'H': 'std::int32_t', 'I': 'std::uint32_t', 'M': 'float', 'N': 'double',
             'J': 'std::int32_t', 'K': 'std::uint32_t', 'D': 'char', 'E': 'unsigned char', 'F': 'std::int16_t',
             'G': 'std::uint16_t', '_J': 'std::int64_t', '_K': 'std::uint64_t'}
PSC_PRIMITIVE = {'int': 'std::int32_t', 'float': 'float', 'bool': 'bool', 'string': 'BSFixedString'}


def decode_template_types(args, count):
    """Read `count + 2` template arguments (Self, R, A1..An) of an MSVC-decorated class name.

    `args` is the text between `NativeFunctionN<` and `@BSScript>`. The template name is entry 0 of the
    name back-reference table, so the first class name read is entry 1. Returns readable C++ spellings,
    or None when the text uses a form this reader does not know (nothing is guessed)."""
    names = ['<template>']
    pos = 0

    def read_name():
        nonlocal pos
        if args[pos].isdigit():
            idx = int(args[pos])
            pos += 1
            return names[idx]
        end = args.index('@', pos)
        part = args[pos:end]
        if not re.fullmatch(r'[A-Za-z_]\w*', part):
            raise ValueError(part)
        pos = end + 1
        names.append(part)
        return part

    def read_type():
        nonlocal pos
        for prefix, mark in (('PEA', '*'), ('PEB', 'const*'), ('AEA', '&'), ('AEB', 'const&')):
            if args.startswith(prefix, pos):
                pos += 3
                inner = read_type()
                return f'{inner}{mark}' if mark in ('*', '&') else f'{inner} {mark}'
        if args[pos] in 'VU':
            pos += 1
            parts = []
            while args[pos] != '@':
                parts.append(read_name())
            pos += 1
            return '::'.join(reversed(parts))
        for code in ('_N', '_J', '_K'):
            if args.startswith(code, pos):
                pos += 2
                return PRIMITIVE[code]
        if args[pos] in PRIMITIVE:
            code = args[pos]
            pos += 1
            return PRIMITIVE[code]
        raise ValueError(args[pos:pos + 8])

    out = []
    try:
        for _ in range(count + 2):
            out.append(read_type())
        if pos != len(args):
            return None
    except (ValueError, IndexError):
        return None
    return out


def native_class_types(class_name):
    """{'self', 'ret', 'args'} spelled from a `NativeFunctionN<...>` class name, or None."""
    m = NATIVE_CLASS_RE.match(class_name)
    if not m:
        return None
    types = decode_template_types(m.group('args'), int(m.group('n')))
    if types is None:
        return None
    return {'self': types[0], 'ret': types[1], 'args': types[2:]}


def kind_of_cpp(spelling):
    """Coarse kind of a C++ spelling for the agreement check: primitive name, string, or 'object'."""
    s = spelling.replace('const', '').replace('&', '').replace('*', '').strip()
    if s in ('std::int32_t', 'std::uint32_t'):
        return 'int'
    if s in ('float', 'double'):
        return 'float'
    if s == 'bool':
        return 'bool'
    if s == 'void':
        return 'void'
    if s.endswith('BSFixedString'):
        return 'string'
    return 'object'


def kind_of_psc(type_name, array):
    t = type_name.lower()
    if array:
        return 'array'
    return {'int': 'int', 'float': 'float', 'bool': 'bool', 'string': 'string', '': 'void'}.get(t, 'object')


def agreement(decl, native):
    """'agree', or the first disagreement found: 'arity', 'return', 'argument N'. Arrays are not compared
    (the class spells them as an engine container type, not a primitive)."""
    if native is None:
        return 'no-class'
    if len(decl['params']) != len(native['args']):
        return 'arity'
    want, got = kind_of_psc(decl['returns'], decl['returns_array']), kind_of_cpp(native['ret'])
    if want != 'array' and want != got and not (want == 'void' and got == 'void'):
        return 'return'
    for i, (p, a) in enumerate(zip(decl['params'], native['args'])):
        k = kind_of_psc(p[0], p[1])
        if k != 'array' and k != kind_of_cpp(a):
            return f'argument {i}'
    return 'agree'


def typed_prototype(native, decl):
    """C++-style prototype from the class arguments. Hidden engine arguments are not shown: the
    ABI of the leading registry and stack-id parameters is not established by this join."""
    if native is None:
        return None
    names = [p[2] for p in decl['params']]
    args = ', '.join(f'{t} {n}' for t, n in zip(native['args'], names))
    return f"{native['ret']} ({native['self']}* self{', ' + args if args else ''})"


def load_cl_names(root=ROOT):
    names = {}
    for path in glob.glob(str(root / CL_NAMES / '*.tsv')):
        for line in open(path, encoding='utf-8'):
            if not line.startswith('#'):
                rva, name = line.rstrip('\n').split('\t', 1)
                names[int(rva, 16)] = name
    return names


def cl_script_leads(names):
    """{rva: (script, function)} for CrashLogger names of the form `papyrus::Script::Function`."""
    out = {}
    for rva, name in names.items():
        m = CL_PAPYRUS_RE.match(name)
        if m:
            out[rva] = (m.group('script'), m.group('fn'))
    return out


def run_sites(cfg, entries, base):
    cmd = [cfg.get('objdump') or 'llvm-objdump', '-d', '--no-show-raw-insn', '--x86-asm-syntax=intel', cfg['image']]
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, text=True, bufsize=1 << 20)
    scanner = hh.RegistrationSiteScanner(base, entries)
    rows = scanner.feed(proc.stdout)
    if proc.wait() != 0:
        raise SystemExit('llvm-objdump failed')
    return rows, {k: sorted(v) for k, v in scanner.ctor_vtables.items()}


def join(sites, natives, img, classes_by_vftable, matched, cl_names, ctor_vtables=None):
    """Registration rows with typed prototypes, plus counts. `classes_by_vftable` maps a vtable RVA
    to the class name read from run-time type information."""
    rows, stats = hh.harvest_native_registrations(img, sites, natives, classes_by_vftable, ctor_vtables)
    leads = cl_script_leads(cl_names)
    out = []
    for r in rows:
        native = native_class_types(r['native_class'] or '')
        verdict = agreement(r['decl'], native)
        out.append({
            'handler': r['handler'], 'script': r['script'], 'function': r['function'],
            'global': r['decl']['global'], 'site': r['site'], 'native_class': r['native_class'],
            'papyrus': f"{r['decl']['returns'] or 'None'} {r['function']}"
                       f"({', '.join(p[0] + ('[]' if p[1] else '') + ' ' + p[2] for p in r['decl']['params'])})",
            'prototype': typed_prototype(native, r['decl']), 'agreement': verdict,
            'matched': r['handler'] in matched,
            'cl_name': cl_names.get(r['handler']),
            'cl_lead': r['handler'] in leads,
            'cl_lead_agrees': leads.get(r['handler'], ('', ''))[0].lower() == r['script'].lower()
            and leads.get(r['handler'], ('', ''))[1].lower() == r['function'].lower() if r['handler'] in leads else None,
        })
    return out, stats, leads


def count(rows, leads, natives, matched):
    handlers = {r['handler'] for r in rows}
    declared = sum(len(s['natives']) for s in natives.values())
    c = collections.Counter(r['agreement'] for r in rows)
    lead_hits = [r for r in rows if r['cl_lead']]
    return {
        'declared_natives': declared,
        'resolved_registrations': len(rows),
        'distinct_handlers': len(handlers),
        'typed_prototypes': sum(1 for r in rows if r['prototype']),
        'agreement': dict(sorted(c.items())),
        'handlers_already_matched': sum(1 for r in rows if r['matched']),
        'handlers_with_crashlogger_name': sum(1 for r in rows if r['cl_name']),
        'crashlogger_script_leads': len(leads),
        'crashlogger_leads_confirmed': sum(1 for r in lead_hits if r['cl_lead_agrees']),
        'crashlogger_leads_contradicted': sum(1 for r in lead_hits if r['cl_lead_agrees'] is False),
        'new_handlers_unmatched': sum(1 for r in rows if not r['matched']),
        'new_handlers_unmatched_and_unnamed': sum(1 for r in rows if not r['matched'] and not r['cl_name']),
    }


def family_counts(classes, matched):
    """What the `NativeFunctionN<Self, R, A...>` instances own, by virtual-table slot, against the base class.

    A slot whose function differs from the base class's is that instance's own code. Counts per slot:
    instances, distinct functions, how many are already matched, and how many classes spell their types
    in a form `decode_template_types` reads."""
    base = next((c for c in classes if c['class'] == 'BSScript::NF_util::NativeFunctionBase'), None)
    inst = [c for c in classes if NATIVE_CLASS_RE.match(c['class'])]
    out = {'native_function_classes': len(inst),
           'native_function_classes_decoded': sum(1 for c in inst if native_class_types(c['class'])),
           'native_function_own_slots': {}}
    if base is None:
        return out
    own = collections.defaultdict(list)
    for c in inst:
        for k, f in enumerate(c['slots']):
            if k >= len(base['slots']) or f != base['slots'][k]:
                own[k].append(f)
    for k, fns in sorted(own.items()):
        out['native_function_own_slots'][str(k)] = {
            'instances': len(fns), 'distinct_functions': len(set(fns)),
            'matched': sum(1 for f in set(fns) if f in matched)}
    return out


def shape_groups(classes, functions_path, slot=22):
    """How the instances' own code in one slot clusters by relocation-masked shape (the L1 key of
    `tools/ghidra/build_function_table.py`): group count, functions in groups of two or more, the largest
    group, and the size range. A family a template could emit is one with few, large groups."""
    inst = [c for c in classes if NATIVE_CLASS_RE.match(c['class'])]
    wanted = {c['slots'][slot] for c in inst if len(c['slots']) > slot}
    keys, sizes = {}, {}
    with open(functions_path, encoding='utf-8') as handle:
        for line in handle:
            row = json.loads(line)
            if row['rva'] in wanted:
                keys[row['rva']] = row['l1']
                sizes[row['rva']] = row['size']
    groups = collections.Counter(keys.values())
    return {'slot': slot, 'functions': len(keys), 'shape_groups': len(groups),
            'in_groups_of_two_or_more': sum(n for n in groups.values() if n > 1),
            'largest_group': max(groups.values(), default=0),
            'size_min': min(sizes.values(), default=0), 'size_max': max(sizes.values(), default=0)}


def _setup(config):
    import export_pack as ep
    cfg = json.load(open(config))
    target, img, addrlib, comms = ep.setup(cfg)
    return ep, cfg, img


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    ap.add_argument('stage', choices=('sites', 'join', 'counts'))
    ap.add_argument('--config')
    ap.add_argument('--natives')
    ap.add_argument('--out', default=str(ROOT / '.local/papyrus'))
    ap.add_argument('--analysis', default=str(ROOT / '.local/analysis'))
    ap.add_argument('--summary', help='write the counts here as JSON')
    a = ap.parse_args(argv)
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    if a.stage == 'sites':
        ep, cfg, img = _setup(a.config)
        meta = ep.load_meta(Path(a.analysis) / 'cache' / 'ghidra-all')
        entries = {rva for rva, m in meta.items() if m['found']}
        sites, ctors = run_sites(cfg, entries, ep.image_base(img))
        (out / 'sites.json').write_text(json.dumps({'sites': sites, 'ctor_vtables': ctors}))
        print(json.dumps({'sites': len(sites), 'constructors_with_vtable': len(ctors)}))
        return 0
    if a.stage == 'join':
        ep, cfg, img = _setup(a.config)
        saved = json.loads((out / 'sites.json').read_text())
        sites = saved['sites']
        ctors = {int(k): v for k, v in saved['ctor_vtables'].items()}
        for s in sites:
            s['args'] = {int(k): v for k, v in s['args'].items()}
        natives = json.loads(Path(a.natives).read_text())['scripts']
        classes, all_classes = {}, []
        for line in open(Path(a.analysis) / 'classes.jsonl'):
            c = json.loads(line)
            classes[c['vftable']] = c['class']
            all_classes.append(c)
        progress = json.loads((ROOT / 'data/progress.json').read_text())
        matched = {f['rva'] for f in progress['functions'] if f['status'] == 'matched'}
        rows, stats, leads = join(sites, natives, img, classes, matched, load_cl_names(), ctors)
        (out / 'registrations.json').write_text(json.dumps(rows, indent=1))
        info = {**stats, **count(rows, leads, natives, matched), **family_counts(all_classes, matched)}
        functions_path = Path(a.analysis) / 'functions.jsonl'
        if functions_path.is_file():
            info['run_slot_shapes'] = shape_groups(all_classes, functions_path)
        (out / 'counts.json').write_text(json.dumps(info, indent=1, sort_keys=True) + '\n')
        print(json.dumps(info, indent=1, sort_keys=True))
        return 0
    info = json.loads((out / 'counts.json').read_text())
    print(json.dumps(info, indent=1, sort_keys=True))
    if a.summary:
        Path(a.summary).write_text(json.dumps(info, indent=1, sort_keys=True) + '\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
