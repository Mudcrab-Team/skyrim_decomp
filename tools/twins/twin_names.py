"""Select pinned community names and apply them to isolated twin declarations."""
from collections import Counter
import json
from pathlib import Path
import re

import rename_planner as R
import twin_source as S
from twin_unit import CI_HASH, LABEL_LINE, Unsupported


class Names:
    def __init__(self, root, table=None, metadata=None):
        root = Path(root)
        self.names, self.protos, self.bounds = R.load_crashlogger(root)
        self.counts = Counter(self.names.values())
        self.table = table or {}
        self.meta = metadata or {}
        self.census_names = {
            rva: {n['name'].removeprefix('RE::') for n in row['names']
                  if n.get('source') == 'meh321' and n.get('how') == 'name' and n.get('ae_id') is not None}
            for rva, row in self.table.items()
        }
        self.census_counts = Counter(n for names in self.census_names.values() for n in names)
        self.symbols = {}
        for file, key in (('symbol-names.json', 'classes'), ('symbol-alignment.json', 'functions')):
            path = root / 'data' / file
            if path.is_file():
                self.symbols[key] = json.loads(path.read_text(encoding='utf-8'))[key]

    def get(self, rva, size):
        binding = self.crashlogger(rva, size)
        if binding:
            return binding
        return self.corroborated(rva)

    def crashlogger(self, rva, size):
        name = self.names.get(rva, '')
        parts = name.split('::')
        if not valid_name(name) or self.counts[name] != 1 or self.bounds.get(rva) != size:
            return None
        cc, proto = self.protos.get(rva, (None, None))
        owner = parts[0] if len(parts) == 2 else None
        if owner and R.this_class(cc, proto) != owner:
            return None
        if not owner and cc in ('thiscall', 'fastcall'):
            return None
        if not proto or proto in ('void ()', 'void (void)'):
            return None
        return {'name': name, 'label': R.CRASHLOGGER_LABEL, 'arity': R.prototype_arity(cc, proto)}

    def corroborated(self, rva):
        names = self.census_names.get(rva, ())
        revision = self.meta.get('meh321_names') or ''
        if len(names) != 1 or not re.fullmatch(r'[0-9a-fA-F]{7,64}', revision):
            return None
        name, = names
        if not valid_name(name) or self.census_counts[name] != 1:
            return None
        owner, method = S.owner_of(name), S.simple_name(name)
        if not owner:
            return None
        crashlogger = self.names.get(rva, '')
        if valid_name(crashlogger) and crashlogger != name:
            return None
        aligned = self.symbols.get('functions', {}).get(f'0x{rva:x}', {})
        keys = self.symbols.get('classes', {}).get(owner, {}).get('candidates', {}).get(method, '')
        labels = [f'SYMBOLS({source})' for key, source in
                  [('a', 'tesv-2013-map'), ('b', 'fo4-pdb'), ('cde', 'fnv-x360-pdb')]
                  if set(key) & set(keys)]
        if aligned.get('confidence') == 'high' and aligned.get('name') == name and aligned.get('source') == 'tesv-2013-map':
            labels.append(R.SYMBOLS_LABEL)
        if not labels:
            return None
        labels = list(dict.fromkeys(labels))
        labels.append(f'COMMUNITY(meh321/AddressLibrary@{revision[:12]}, permission)')
        return {'name': name, 'label': ' '.join(labels), 'arity': None}


def valid_name(name):
    parts = name.split('::')
    return (len(parts) in (1, 2) and all(R.PLAIN_NAME.fullmatch(part) for part in parts)
            and not R.CLNAME_BAD.search(name) and not R.FLATTENED.search(name)
            and not R.placeholder(parts[-1]))


def apply(twin, binding, headers=()):
    name = binding['name']
    old_owner, old_method = S.owner_of(twin.name), S.simple_name(twin.name)
    owner, method = S.owner_of(name), S.simple_name(name)
    if (bool(old_owner) != bool(owner) or old_method.lstrip('~') == old_owner or method == owner
            or not R.PLAIN_NAME.fullmatch(old_method)):
        raise Unsupported('community-name-kind')
    if owner and any(re.search(rf'\b{re.escape(owner)}\b', S.mask_text(h)) for h in headers):
        raise Unsupported('community-name-owner-conflict')
    texts = {ext: twin.files.get(twin.stem + ext) for ext in ('.cpp', '.h')}
    if binding['arity'] is not None and R.source_arity(texts, twin.name) != binding['arity']:
        raise Unsupported('community-name-arity')
    identifiers = set().union(*(set(S.IDENT.findall(S.mask_text(t))) for t in texts.values() if t))
    if method != old_method and method in identifiers:
        raise Unsupported('community-name-collision')
    if owner and owner != old_owner and owner in identifiers:
        raise Unsupported('community-name-owner-conflict')
    replacements = {old_method: method}
    if owner:
        replacements[old_owner] = owner
        # A renamed virtual method could stop overriding an inherited slot.
        header = S.mask_text(texts['.h'] or '')
        if (method != old_method and re.search(
                rf'\bvirtual\b[^;{{}}]*\b{old_method}\s*\(|\b{old_method}\s*\([^;{{}}]*\)[^;{{}}]*\boverride\b', header)):
            raise Unsupported('community-name-virtual')
    for path, text in twin.files.items():
        head, body = S.split_header(text)
        lines = []
        for line in head:
            if line.startswith('// Code origin:'):
                line = line.replace('names replaced by placeholders.',
                                    "function name supplied by the labelled naming evidence.")
            if CI_HASH.fullmatch(line):
                continue
            marker = S.HEADER_LINE.fullmatch(line)
            if marker and int(marker[1], 16) == twin.rva:
                lines.append(f'// 0x{twin.rva:x} {name}')
                continue
            match = LABEL_LINE.fullmatch(line)
            if match and 'GUESS' in match['labels']:
                names = [n.strip() for n in match['names'].split(',')]
                kept = [n for n in names if not set(S.IDENT.findall(n)) & replacements.keys()]
                if kept:
                    lines.append('// ' + ', '.join(kept) + ': ' + match['labels'])
                continue
            lines.append(line)
        lines.insert(0, f'// {name}: {binding["label"]}')
        for match in reversed(list(S.IDENT.finditer(S.mask_text(body)))):
            if match[0] in replacements:
                body = body[:match.start()] + replacements[match[0]] + body[match.end():]
        twin.files[path] = '\n'.join(lines) + '\n' + body
    twin.name = name
    return twin
