"""What do symbol files of sibling builds say about the names in the inventory? Local input.

Reads symbol files you hold (a linker map, or a program database's public symbols) and
`data/progress.json`, and writes two files:

- `data/name-corroboration.json`: one verdict per already-published `Class::Method` name: is
  that method name a member of that class in each symbol file? It holds function ids that
  `data/progress.json` already lists and source labels, and no symbol-file content;
- `data/symbol-names.json`: for each class the inventory already names, the object files that
  hold its member functions in a linker map (evidence of original translation units), and, where
  the class still has functions with a placeholder or uncorroborated name, the member names the
  symbol files give that no inventory function of the class uses yet. These are candidates for a
  namer to check against the code, each with the sources that give it. They are not assignments:
  nothing here says which function a name belongs to.

No address, type, decorated name or symbol of a class the inventory does not have is printed or
written, and each source is described by its size and SHA-256 (in groups, see grouped_digest) so someone holding the same file
can reproduce the run. A symbol file stays where you keep it, outside the repository;
`tools/check.py` refuses its extension anyway.

Neither file is evidence about the pinned image. A sibling build is another program: an address
transfers nowhere, `absent` is a candidate to look at and not an error (methods are renamed,
inlined away and added between builds), and overloads are not told apart. A name taken from
`symbol-names.json` into a unit is labelled `SYMBOLS(<source-id>)`, with `<source-id>` one of `tesv-2013-map`,
`fo4-pdb`, `fnv-x360-pdb` (`docs/authorizations.md`, Notes; `findings/sibling-symbol-files.md`).

    python3 tools/symbol_corroboration.py --source LABEL=PATH [--source LABEL=PATH ...]
    python3 tools/symbol_corroboration.py --source LABEL=PATH --write    # also rewrite the data files
"""
import argparse
import collections
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from check_code_rules import PLACEHOLDERS  # noqa: E402

OUTPUT = 'data/name-corroboration.json'
NAMES_OUTPUT = 'data/symbol-names.json'
LABEL = re.compile(r'[a-z0-9][a-z0-9.-]{2,48}')
MSF_MAGIC = b'Microsoft C/C++ MSF 7.00\r\n\x1aDS\x00\x00\x00'
DBI_STREAM = 3
S_PUB32, S_PUB32_ST = 0x110e, 0x1009
# address, decorated name, rva+base, `f` for a function, `i` for an inline one, then lib:object.
MAP_PUBLIC = re.compile(r'^ [0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+[0-9a-fA-F]{8,16}( f)?( i)?\s+(\S+)\s*$')
# ?member@Class@Namespace@@...: the innermost scope comes first. Template scopes are left out.
MEMBER = re.compile(r'^\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@')
SPECIAL = re.compile(r'^\?\?(0|1|_G|_E|_7)((?:[A-Za-z_]\w*@)+)@')
CONSTRUCTOR, DESTRUCTOR = '<constructor>', '<destructor>'
SPECIAL_MEMBER = {'0': CONSTRUCTOR, '1': DESTRUCTOR, '_G': DESTRUCTOR, '_E': DESTRUCTOR, '_7': None}
PLAIN_NAME = re.compile(r'[A-Za-z_]\w*')
OBJECT_NAME = re.compile(r'[A-Za-z0-9_.:+-]+')
MAX_OBJECTS = 4


def map_publics(path):
    """(decorated name, home object or None) for a linker map's public and static symbol tables.

    The object is given only for a function that is not inline: an inline function is emitted
    by every object that uses it, so its object says nothing about where the class lives."""
    with open(path, encoding='latin-1') as handle:
        for line in handle:
            m = MAP_PUBLIC.match(line)
            if m:
                yield m.group(1), (m.group(4) if m.group(2) and not m.group(3) else None)


def pdb_publics(path):
    """(decorated name, None) for a program database's public symbols (MSF 7.00)."""
    data = memoryview(Path(path).read_bytes())
    if bytes(data[:len(MSF_MAGIC)]) != MSF_MAGIC:
        raise ValueError(f'{path}: not an MSF 7.00 program database')
    block_size, _free, _blocks, directory_bytes, _unknown, block_map = struct.unpack_from('<6I', data, len(MSF_MAGIC))

    def blocks_of(size):
        return (size + block_size - 1) // block_size

    def read(blocks, size):
        return b''.join(bytes(data[b * block_size:(b + 1) * block_size]) for b in blocks)[:size]

    directory_blocks = struct.unpack_from(f'<{blocks_of(directory_bytes)}I', data, block_map * block_size)
    directory = read(directory_blocks, directory_bytes)
    count, = struct.unpack_from('<I', directory, 0)
    sizes = [0 if size == 0xffffffff else size for size in struct.unpack_from(f'<{count}I', directory, 4)]
    offset = 4 + 4 * count
    streams = []
    for size in sizes:
        streams.append((struct.unpack_from(f'<{blocks_of(size)}I', directory, offset), size))
        offset += 4 * blocks_of(size)
    if count <= DBI_STREAM or streams[DBI_STREAM][1] < 22:
        raise ValueError(f'{path}: no debug information stream')
    # The symbol record stream's index is the seventh 16-bit field of the DBI header.
    symbol_stream, = struct.unpack_from('<H', read(*streams[DBI_STREAM]), 20)
    if symbol_stream >= count:
        raise ValueError(f'{path}: no symbol record stream')
    records = read(*streams[symbol_stream])
    position, end = 0, len(records)
    while position + 4 <= end:
        length, kind = struct.unpack_from('<HH', records, position)
        if length < 2:
            break
        if kind == S_PUB32:
            name_end = records.find(b'\x00', position + 14, position + 2 + length)
            yield records[position + 14:name_end if name_end >= 0 else position + 2 + length].decode('latin-1'), None
        elif kind == S_PUB32_ST:
            yield records[position + 15:position + 15 + records[position + 14]].decode('latin-1'), None
        position += 2 + length


def class_members(publics):
    """({class: set of member names}, {class: Counter of home objects}, symbol count).

    A class with only a vftable maps to an empty set."""
    members = collections.defaultdict(set)
    objects = collections.defaultdict(collections.Counter)
    total = 0
    for name, home in publics:
        total += 1
        m = MEMBER.match(name)
        if m:
            cls = m.group(2).split('@', 1)[0]
            members[cls].add(m.group(1))
        else:
            m = SPECIAL.match(name)
            if not m:
                continue
            member = SPECIAL_MEMBER[m.group(1)]
            cls = m.group(2).split('@', 1)[0]
            members[cls].update((member,) if member else ())
        if home:
            objects[cls][home] += 1
    return dict(members), dict(objects), total


def grouped_digest(hexdigest):
    """Four 16-digit groups joined by '-': tools/leakgrep.py refuses an unbroken run of 32 or more hex digits."""
    return '-'.join(hexdigest[i:i + 16] for i in range(0, len(hexdigest), 16))


def read_source(path):
    path = Path(path)
    with open(path, 'rb') as handle:
        head = handle.read(len(MSF_MAGIC))
        handle.seek(0)
        digest = hashlib.sha256()
        for chunk in iter(lambda: handle.read(1 << 20), b''):
            digest.update(chunk)
    kind = 'program-database' if head == MSF_MAGIC else 'linker-map'
    members, objects, total = class_members(pdb_publics(path) if kind == 'program-database' else map_publics(path))
    if not total:
        raise ValueError(f'{path}: no public symbol found')
    return members, objects, {'kind': kind, 'bytes': path.stat().st_size, 'sha256': grouped_digest(digest.hexdigest()),
                              'public_symbols': total, 'classes': len(members)}


def placeholder(word):
    return any(rx.search(word) for rx in PLACEHOLDERS)


def inventory_class(entry):
    """(class, method text) of an inventory entry whose class is a real name, else None."""
    name = (entry.get('name') or '').split('(')[0]
    if '::' not in name:
        return None
    scope, _, method = name.rpartition('::')
    cls = scope.rsplit('::', 1)[-1]
    if not cls or not method or placeholder(cls):
        return None
    return cls, method


def published_name(entry):
    """(class, member) of an inventory entry whose class and method are both real names, else None."""
    found = inventory_class(entry)
    if found is None:
        return None
    cls, method = found
    if method.startswith('~') or method in ('dtor', 'Dtor'):
        return cls, DESTRUCTOR
    if method == cls or method in ('ctor', 'Ctor'):
        return cls, CONSTRUCTOR
    if placeholder(method) or not PLAIN_NAME.fullmatch(method):
        return None
    return cls, method


def corroborate(progress, sources):
    """{function id: {'confirmed': [labels], 'absent': [labels]}} for every assessable name.

    A source that does not have the class says nothing about the function and is left out."""
    functions = {}
    for entry in progress.get('functions', ()):
        name = published_name(entry)
        if name is None:
            continue
        cls, member = name
        verdict = {'confirmed': [], 'absent': []}
        for label, members in sources.items():
            if cls in members:
                verdict['confirmed' if member in members[cls] else 'absent'].append(label)
        if verdict['confirmed'] or verdict['absent']:
            functions[entry['id']] = verdict
    return functions


def class_names(progress, sources, objects, functions):
    """{class: {'open': n, 'objects': {label: [names]}, 'candidates': {member: [labels]}}}.

    `open` counts the class's inventory functions whose method name is a placeholder or that no
    source confirms. Candidates are listed only for a class with open functions, and never
    include a member name an inventory function of the class already uses."""
    used = collections.defaultdict(set)
    open_count = collections.Counter()
    for entry in progress.get('functions', ()):
        found = inventory_class(entry)
        if found is None:
            continue
        cls = found[0]
        used[cls]
        name = published_name(entry)
        if name is not None:
            used[cls].add(name[1])
        if name is None or not functions.get(entry['id'], {}).get('confirmed'):
            open_count[cls] += 1
    classes = {}
    for cls in sorted(used):
        homes = {}
        for label, by_class in objects.items():
            ranked = sorted(by_class.get(cls, {}).items(), key=lambda item: (-item[1], item[0]))
            names = [name for name, _count in ranked[:MAX_OBJECTS] if OBJECT_NAME.fullmatch(name)]
            if names:
                homes[label] = names
        candidates = collections.defaultdict(list)
        if open_count[cls]:
            for label, members in sources.items():
                for member in members.get(cls, ()):
                    if member not in used[cls] and PLAIN_NAME.fullmatch(member):
                        candidates[member].append(label)
        if homes or candidates:
            classes[cls] = {'open': open_count[cls], 'objects': homes,
                            'candidates': {member: candidates[member] for member in sorted(candidates)}}
    return classes


def summary(progress, functions, sources):
    assessable = sum(1 for entry in progress.get('functions', ()) if published_name(entry))
    counts = {'inventory_functions': len(progress.get('functions', ())), 'assessable_names': assessable,
              'class_known_to_a_source': len(functions),
              'confirmed_by_a_source': sum(1 for v in functions.values() if v['confirmed']),
              'confirmed_by_every_source_with_the_class': sum(1 for v in functions.values() if not v['absent']),
              'absent_from_every_source_with_the_class': sum(1 for v in functions.values() if not v['confirmed'])}
    per_source = {label: {'confirmed': sum(1 for v in functions.values() if label in v['confirmed']),
                          'absent': sum(1 for v in functions.values() if label in v['absent'])} for label in sources}
    return counts, per_source


def dump(payload, rows_key):
    """JSON with one line per entry of `payload[rows_key]`, so a diff shows one function or class."""
    head = {key: value for key, value in payload.items() if key != rows_key}
    text = json.dumps(head, indent=1, sort_keys=True)[:-2]
    rows = [f'  {json.dumps(key)}: {json.dumps(value, sort_keys=True, separators=(",", ":"))}'
            for key, value in sorted(payload[rows_key].items())]
    return text + f',\n {json.dumps(rows_key)}: {{\n' + ',\n'.join(rows) + '\n }\n}\n'


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    parser.add_argument('--source', action='append', default=[], metavar='LABEL=PATH', required=True,
                        help='a linker map or program database you hold; the label names it in the output')
    parser.add_argument('--write', action='store_true', help=f'rewrite {OUTPUT} and {NAMES_OUTPUT}')
    parser.add_argument('--root', default=str(ROOT), help=argparse.SUPPRESS)
    args = parser.parse_args(argv)
    root = Path(args.root)
    sources, objects, described = {}, {}, {}
    for item in args.source:
        label, _, path = item.partition('=')
        if not LABEL.fullmatch(label) or not path or label in sources:
            parser.error(f'--source {item!r}: want a unique lower-case LABEL=PATH')
        if root.resolve() in Path(path).resolve().parents:
            parser.error(f'{label}: keep symbol files outside the repository')
        sources[label], objects[label], described[label] = read_source(path)
    progress = json.loads((root / 'data/progress.json').read_text(encoding='utf-8'))
    functions = corroborate(progress, sources)
    classes = class_names(progress, sources, objects, functions)
    counts, per_source = summary(progress, functions, sources)
    for label in sources:
        described[label].update(per_source[label])
    counts['classes_with_an_object_file'] = sum(1 for c in classes.values() if c['objects'])
    counts['classes_with_candidates'] = sum(1 for c in classes.values() if c['candidates'])
    counts['candidate_names'] = sum(len(c['candidates']) for c in classes.values())
    for key, value in counts.items():
        print(f'{key.replace("_", " ")}: {value}')
    for label, facts in described.items():
        print(f"{label}: {facts['kind']}, {facts['public_symbols']} public symbols, {facts['classes']} classes; "
              f"confirms {facts['confirmed']}, absent {facts['absent']}")
    if args.write:
        # Each source gets a one-letter key; a verdict or a candidate lists its sources as a string of keys.
        if len(sources) > 26:
            parser.error('at most 26 sources')
        keys = {label: chr(ord('a') + i) for i, label in enumerate(sources)}
        for label in sources:
            described[label]['key'] = keys[label]

        def keyed(labels):
            return ''.join(keys[label] for label in labels)

        common = {'schema_version': 1, 'target_build_id': progress.get('target_build_id'), 'sources': described,
                  'totals': counts}
        verdicts = dict(common, functions={key: {'confirmed': keyed(v['confirmed']), 'absent': keyed(v['absent'])}
                                           for key, v in functions.items()},
                        note='Verdicts on names already in data/progress.json; no symbol-file content. Sources are '
                             'listed by their one-letter key. See tools/symbol_corroboration.py and '
                             'findings/sibling-symbol-files.md.')
        names = dict(common, classes={cls: {'open': c['open'],
                                            'objects': {keys[label]: homes for label, homes in c['objects'].items()},
                                            'candidates': {member: keyed(labels)
                                                           for member, labels in c['candidates'].items()}}
                                      for cls, c in classes.items()},
                     note='Object files and unused member names that sibling-build symbol files give for classes '
                          'the inventory names, each with the one-letter keys of the sources that give it. '
                          'Candidates, not assignments, and not evidence about the pinned image. See '
                          'tools/symbol_corroboration.py and findings/sibling-symbol-files.md.')
        (root / OUTPUT).write_text(dump(verdicts, 'functions'), encoding='utf-8', newline='\n')
        (root / NAMES_OUTPUT).write_text(dump(names, 'classes'), encoding='utf-8', newline='\n')
    return 0


if __name__ == '__main__':
    sys.exit(main())
