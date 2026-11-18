#!/usr/bin/env python3
"""Generate additive declaration stand-ins from pinned, permitted community headers only.

No image, class-table export, internal queue or sibling source is read. Regenerate with
python3 tools/declaration_kit.py --write; the output is a hypothesis, never match evidence.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess

from lint_reconstruction import SPDX_MIT

ROOT = Path(__file__).resolve().parents[1]
NG_REV = 'b93280e832f263dbef44e44cbe2936622a02f91a'
PO3_REV = '654e55f7979c1733033d5dbef176e43827bac944'
SOURCES = (
    ('CharmedBaryon/CommonLibSSE-NG', '.local/sources/CommonLibSSE-NG', NG_REV, 'MIT'),
    ('powerof3/CommonLibSSE', '.local/sources/CommonLibSSE-po3', PO3_REV, 'GPL-3.0'),
)
CLASSES = ('NiRefObject', 'NiObject', 'NiObjectNET', 'NiAVObject', 'NiNode',
           'BaseFormComponent', 'TESForm', 'BSTEventSink')
# Names are community declarations, not target layouts. Only opaque storage is generated.
FILES = {'BSTEventSink': 'include/RE/B/BSTEvent.h'}
GPL_NOTICE = '''Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
This file is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.
This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details. A copy is provided in
licenses/CommonLibSSE-GPL-3.0.txt; see also https://www.gnu.org/licenses/.'''


def class_body(text, cls):
    # Preserve byte offsets while erasing comments, strings and character literals for balancing.
    clean = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                   lambda m: ''.join('\n' if c == '\n' else ' ' for c in m[0]), text, flags=re.S)
    match = re.search(rf'\b(?:class|struct)\s+{re.escape(cls)}(?:\s+final)?\s*(?::([^;{{}}]+))?\s*\{{', clean)
    if not match:
        return None
    depth, end = 1, match.end()
    while end < len(clean) and depth:
        depth += {'{': 1, '}': -1}.get(clean[end], 0)
        end += 1
    if depth:
        return None
    bases = re.findall(r'(?:public|protected|private)\s+(?:virtual\s+)?(?:::)?([\w:]+)', match[1] or '')
    return bases, text[match.end():end-1]


def virtuals(body):
    """Community slot comments only; no inline bodies or upstream prose are retained."""
    out, depth = [], 0
    for line in body.splitlines():
        code, sep, comment = line.partition('//')
        direct = depth == 0
        balanced = re.sub(r'\"(?:\\.|[^\"\\])*\"', '\"\"', code)
        depth += balanced.count('{') - balanced.count('}')
        if not direct:
            continue
        slot = re.match(r'\s*([0-9A-Fa-f]{2})(?:\s|$)', comment)
        if not sep or not slot or '(' not in code:
            continue
        code = re.sub(r'\[\[[^\]]*\]\]', '', code)
        code = code.split('{', 1)[0].strip().rstrip(';').strip()
        code = re.sub(r'\bSKYRIM_REL_VR_VIRTUAL\b', 'virtual', code)
        code = re.sub(r'\bRE::', '', code)
        code = re.sub(r'\s*=\s*(?:default|delete)\s*$', '', code)
        code = ' '.join(code.split()) + ';'
        name = re.search(r'(~?[A-Za-z_]\w*|operator\s*\(\))\s*\(', code)
        if name:
            out.append(dict(slot=int(slot[1], 16), name=name[1], declaration=code))
    return out


def source_class(text, cls):
    found = class_body(text, cls)
    if not found:
        return None
    bases, body = found
    sizes = re.findall(rf'static_assert\(sizeof\({re.escape(cls)}(?:<void>)?\)\s*==\s*(0x[0-9a-fA-F]+|\d+)', text)
    # NG's first assertion is the SE/AE one; later VR variants are not transferred.
    inheritance = re.search(rf'\bclass\s+{re.escape(cls)}(?:\s+final)?\s*:([^;{{}}]+)\{{', text)
    gaps = []
    if inheritance and ('<' in inheritance[1] or 'virtual ' in inheritance[1] or len(bases) > 1):
        gaps.append('template, virtual or multiple inheritance needs local type preparation')
    return dict(bases=bases, size=int(sizes[0], 0) if sizes else None, virtuals=virtuals(body), preparation_gaps=gaps,
                reference_kinds={name: kind for kind, name in
                                 re.findall(r'\b(class|struct)\s+(\w+)\s*[;{]', text)})


def pinned_class(root, cls, sources=None):
    """Read the immutable Git blob, never a modified checkout or another revision."""
    root = Path(root)
    path = FILES.get(cls, f'include/RE/{cls[0].upper()}/{cls}.h')
    for repo, clone, rev, license_ in SOURCES:
        base = Path(sources) / Path(clone).name if sources is not None else root / clone
        if not base.is_dir():
            continue
        proc = subprocess.run(['git', '-C', str(base), 'show', f'{rev}:{path}'], capture_output=True, text=True)
        info = source_class(proc.stdout, cls) if proc.returncode == 0 else None
        if info:
            return dict(info, source=repo, revision=rev, license=license_, path=path,
                        label=f'COMMUNITY({repo}@{rev[:7]}, {license_})')
    return None


def notice(root, info, sources=None):
    repo, clone, rev, _license = next(s for s in SOURCES if s[0] == info['source'])
    if info['license'] == 'MIT':
        # The full text lives once in licenses/CommonLibSSE-NG.txt (generate() writes it).
        return '// ' + SPDX_MIT
    path = 'licenses/LICENSE-MIT.txt'
    base = Path(sources) / Path(clone).name if sources is not None else Path(root) / clone
    proc = subprocess.run(['git', '-C', str(base), 'show', f'{rev}:{path}'],
                          capture_output=True, text=True, check=True)
    text = proc.stdout.rstrip()
    if info['license'] != 'MIT':
        text += '\n\n' + GPL_NOTICE
    return '\n'.join('// ' + line if line else '//' for line in text.splitlines())


def generate(root=ROOT):
    """Return files, without mutating any accepted header or reading any private image data."""
    # Local import: unit_skeleton uses this reader too.
    from unit_skeleton import type_names
    build = json.loads((Path(root) / 'builds/target.json').read_text())['build_id']
    infos = {cls: pinned_class(root, cls) for cls in CLASSES}
    if any(info is None for info in infos.values()):
        raise ValueError('declaration kit needs the pinned community clones (run contributor setup)')
    files = {}
    for cls, info in infos.items():
        base = info['bases'][0] if info['bases'] else None
        if base and base not in infos:
            raise ValueError(f'{cls}: unprepared base {base}')
        forward = set()
        for entry in info['virtuals']:
            refs, _values = type_names(entry['declaration'])
            forward.update(t for t in refs if '<' not in t and '::' not in t and t not in (cls, base))
        forward -= {'NiPointer', 'BSTEventSource'}
        prelude = []
        if cls == 'TESForm':
            prelude += ['// FormType, FormID: ' + info['label'],
                        '// Reference declarations: include/RE/F/FormTypes.h and include/RE/B/BSCoreTypes.h.',
                        'enum class FormType : int;', 'using FormID = std::uint32_t;']
        if cls == 'BSTEventSink':
            prelude += ['// BSEventNotifyControl, BSTEventSource: ' + info['label'],
                        'enum class BSEventNotifyControl : int;',
                        'template <class Event> class BSTEventSource;']
            forward -= {'Event'}
        if any('NiPointer<' in e['declaration'] for e in info['virtuals']):
            prelude += ['// NiPointer: ' + info['label'], 'template <class T> class NiPointer;']
        labels = [f'// {cls}: STANDIN {info["label"]}']
        for entry in info['virtuals']:
            labels.append(f'// {cls}::{entry["name"]}: {info["label"]}')
        if forward:
            labels.append(f'// {", ".join(sorted(forward))}: STANDIN {info["label"]}')
        lines = ['// Source exposure: community-headers; generated by tools/declaration_kit.py.',
                 notice(root, info), *labels, '#pragma once', '', '#include <cstdint>',
                 *([f'#include "declarations/{base}.h"'] if base else []), '',
                 *[f'{info.get("reference_kinds", {}).get(t, "class")} {t};' for t in sorted(forward)], *prelude, '',
                 *(['template <class Event>'] if cls == 'BSTEventSink' else []),
                 f'class {cls}' + (f' : public {base}' if base else ''), '{', 'public:']
        for entry in info['virtuals']:
            lines += [f'    {entry["declaration"]}  // {entry["slot"]:02X}']
        start = infos[base]['size'] if base else 8
        size = info['size']
        if size and size > start:
            lines += ['', '    // Unknown members: storage only; do not infer ownership from size.',
                      f'    // unknown{start:02X}: GUESS(low)', f'    std::uint8_t unknown{start:02X}[0x{size-start:X}];']
        lines += ['};']
        if size:
            name = cls + ('<void>' if cls == 'BSTEventSink' else '')
            lines += [f'static_assert(sizeof({name}) == 0x{size:X}, "{cls} community size");']
        files[f'reconstruction/declarations/{cls}.h'] = '\n'.join(lines) + '\n'
    ng = next(s for s in SOURCES if s[0] == 'CharmedBaryon/CommonLibSSE-NG')
    proc = subprocess.run(['git', '-C', str(Path(root) / ng[1]), 'show', f'{ng[2]}:LICENSE'],
                          capture_output=True, text=True, check=True)
    files['licenses/CommonLibSSE-NG.txt'] = proc.stdout.rstrip() + '\n'
    # Keep the full text for GPL fallback declarations emitted by the shared engine.
    license_path = Path(root) / SOURCES[1][1]
    proc = subprocess.run(['git', '-C', str(license_path), 'show', f'{PO3_REV}:COPYING.txt'],
                          capture_output=True, text=True, check=True)
    files['licenses/CommonLibSSE-GPL-3.0.txt'] = proc.stdout
    return files


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--write', action='store_true')
    a = p.parse_args()
    for name, text in generate().items():
        if a.write:
            dest = ROOT / name
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_text(text, encoding='utf-8', newline='\n')
        print(name)


if __name__ == '__main__':
    main()
