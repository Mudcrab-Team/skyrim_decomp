#!/usr/bin/env python3
"""Contributor-visible index of published header declarations, slots and known gaps.

python3 tools/header_index.py --class NiNode
python3 tools/header_index.py --class NiObject --slot 4
python3 tools/header_index.py > .local/header-index.json

This is a declaration inventory, not a claim that every member was reviewed or matched.
Acceptance remains per function in data/progress.json and its digest-bound reports.
"""
import argparse
import json
from pathlib import Path
import re

from declaration_kit import class_body
import pdb_types

ROOT = Path(__file__).resolve().parents[1]


def entries(text):
    """Conservatively extract direct class members; leave unparsed syntax explicitly unknown."""
    names = dict.fromkeys(re.findall(r'\b(?:class|struct)\s+([A-Za-z_]\w*)\b[^;{}]*\{', text))
    out = {}
    for cls in names:
        found = class_body(text, cls)
        if not found:
            continue
        bases, body = found
        members, fields, slots, gaps, depth = [], [], {}, [], 0
        expected = None
        for line in body.splitlines():
            code, _sep, comment = line.partition('//')
            if depth == 0:
                if 'community declaration:' in comment:
                    expected = comment.split('community declaration:', 1)[1].strip()
                member = re.search(r'(~?[A-Za-z_]\w*|operator\s*\(\))\s*\(', code)
                if member and not code.lstrip().startswith(('static_assert', 'return', 'if', 'while', 'for')):
                    name = member[1]
                    decl = ' '.join(code.split('{', 1)[0].split())
                    slot = re.match(r'\s*([0-9A-Fa-f]{2})(?:\s|$)', comment)
                    entry = dict(name=name, declaration=decl)
                    if slot:
                        entry['slot'] = int(slot[1], 16)
                        slots[str(entry['slot'])] = entry
                    members.append(entry)
                    if expected:
                        from unit_skeleton import split_declaration, signature_key
                        actual, wanted = split_declaration(decl), split_declaration(expected)
                        if actual and wanted and signature_key(actual) != signature_key(wanted):
                            gaps.append(dict(member=name, slot=entry.get('slot'), reason='signature differs from community declaration'))
                    if re.fullmatch(r'(?:virtual\s+)?void\s+(?:Unk_\w+|Slot_\w+)\s*\(\s*\)\s*(?:override\s*)?;', decl):
                        gaps.append(dict(member=name, slot=entry.get('slot'), reason='unknown placeholder signature'))
                    expected = None
                elif ';' in code and '(' not in code and not code.lstrip().startswith(('using ', 'typedef ', 'enum ')):
                    declaration = code.split(';', 1)[0].split('=', 1)[0].strip()
                    field = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*$', declaration)
                    if field and declaration[:field.start()].strip():
                        fields.append(dict(name=field[1], declaration=declaration + ';'))
            # This limited inventory skips inline-body statements and nested-class members.
            clean = re.sub(r'"(?:\\.|[^"\\])*"', '""', code)
            depth += clean.count('{') - clean.count('}')
        numbered = sorted(map(int, slots))
        missing = [i for i in range(numbered[-1] + 1) if str(i) not in slots] if numbered else []
        out[cls] = dict(bases=bases, members=members, fields=fields, slots=slots, gaps=gaps,
                        undeclared_slots=missing,
                        limitations=['Slots absent here may be inherited; absence is not proof of a missing vtable entry.',
                                     'Unnumbered, macro-generated and multiline declarations may be incomplete.',
                                     'Size agreement alone proves neither fields nor ownership.'])
    return out


def header_entry(root, path):
    root, path = Path(root).resolve(), Path(path).resolve()
    if not path.is_relative_to(root / 'reconstruction') or not path.is_file():
        return None
    text = path.read_text(encoding='utf-8')
    return dict(header=path.relative_to(root).as_posix(), classes=entries(text))


def index(root=ROOT, cls=None):
    paths = sorted((Path(root) / 'reconstruction').rglob(f'{cls or "*"}.h'))
    # The generated PDB layouts declare no methods; `start` points at them in its own hint.
    paths = [p for p in paths if not pdb_types.is_generated(p.relative_to(Path(root)).as_posix())]
    return [entry for path in paths if (entry := header_entry(root, path))]


def advice(root, cls, method=None, slot=None):
    out = []
    for entry in index(root, cls):
        info = entry['classes'].get(cls)
        if info is None:
            continue
        prefix = f'use {entry["header"]}'
        if slot is not None:
            found = info['slots'].get(str(slot))
            out.append(prefix + (f', slot {slot} declared: {found["declaration"]}' if found else
                                 f', slot {slot} missing here (check inherited declarations)'))
        elif method:
            found = [m for m in info['members'] if m['name'] == method]
            out.append(prefix + (f', {method} declared' if found else f', {method} missing here'))
        else:
            out.append(prefix)
        out += [f'{entry["header"]}: {g["member"]}: {g["reason"]}' for g in info['gaps']
                if (method is None or g['member'] == method) and (slot is None or g['slot'] == slot)]
    return out


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--class', dest='cls')
    p.add_argument('--member')
    p.add_argument('--slot', type=lambda x: int(x, 0))
    a = p.parse_args()
    if a.member or a.slot is not None:
        if not a.cls:
            p.error('--member and --slot require --class')
        print('\n'.join(advice(ROOT, a.cls, a.member, a.slot)))
    else:
        print(json.dumps(dict(schema=1, headers=index(ROOT, a.cls)), indent=2))


if __name__ == '__main__':
    main()
