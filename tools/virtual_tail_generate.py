"""Enroll only complete nullable first-slot virtual call shapes.

The extractor checks the argument source, zero slot offset, flag and local branch
for every member. These checks do not replace any comparator decision.
"""
import argparse
import hashlib
import json
from pathlib import Path
import storage_free_return_generate as generator
import virtual_tail_template_v1 as template
from pecoff import CoffObject
from source_digest import include_closure
from digest_v2 import tu_digest


def probe_extractor(directory):
    """Use freshly compiled source forms, never an embedded image instruction stream.

    Probes must have passed the unchanged local comparator. Their complete code
    sections have no relocations; every selected member must equal one of them.
    This enrollment filter is additional to each member's own comparator run.
    """
    forms = {}
    for td in directory.glob('*/task.json'):
        task = json.loads(td.read_text())
        member = task['functions'][0]
        params = member['family_metadata']['family_parameters']
        key = params['result'], params['value']
        if key in forms:
            continue
        dest = td.parent/'confirm/mac-wine'
        if not (dest/'result.json').exists():
            continue
        result = json.loads((dest/'result.json').read_text())
        report = json.loads((dest/f'0x{member["rva"]:x}'/'report.json').read_text())
        emitted = template.emit(member['rva'], member['size'], *key)
        source = generator.ROOT/task['compiled']
        if (source.read_text() != emitted['source']
                or source.with_suffix('.h').read_text() != emitted['header']
                or task['recipe'] != template.RECIPE
                or result['source_revision'] != tu_digest(generator.ROOT, include_closure(generator.ROOT, task['compiled']))
                or report.get('result') != 'pass'):
            raise ValueError('probe source or comparison binding differs')
        data = (dest/'candidate.obj').read_bytes()
        if hashlib.sha256(data).hexdigest() != result['object_sha256']:
            raise ValueError('probe object binding differs')
        obj = CoffObject(data)
        symbols = [s for s in obj.symbols.values() if s.name == emitted['symbol']
                   and s.is_function and s.storage == 2 and s.value == 0]
        if len(symbols) != 1:
            raise ValueError('ambiguous probe symbol')
        section = obj.section(symbols[0].section)
        if section.relocs or len(section.data) != member['size']:
            raise ValueError('probe has references or wrong extent')
        forms[key] = section.data
    if set(forms) != {('argument-dispatch', 1), ('object-dispatch', 0)}:
        raise ValueError('both independently compared source probes are required')

    def extract(code):
        matches = [key for key, body in forms.items() if code == body]
        if len(matches) != 1:
            raise ValueError('unsupported complete virtual dispatch shape')
        return matches[0]
    return extract


def bootstrap(code):
    """Only choose a source hypothesis for two seeds; comparator decides its result."""
    if len(code) == 23:
        return 'argument-dispatch', 1
    if len(code) == 14:
        return 'object-dispatch', 0
    raise ValueError('unsupported probe extent')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--selection', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    p.add_argument('--probes', type=Path)
    p.add_argument('--bootstrap', action='store_true')
    a = p.parse_args()
    selection = json.loads(a.selection.read_text())
    if a.bootstrap:
        if a.probes or sorted(m['size'] for m in selection['members']) != [14, 23]:
            p.error('--bootstrap enrolls exactly one seed of each extent, without --probes')
        extract = bootstrap
    elif a.probes:
        extract = probe_extractor(a.probes)
    else:
        p.error('--probes is required for population extraction')
    generator.generate(selection, a.out, template, extract, 'p139-virtual', 'Dispatch')
