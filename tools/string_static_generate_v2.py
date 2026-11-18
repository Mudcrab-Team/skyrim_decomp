"""Extract pinned private rows and generate candidates for static string acquisition.

The private full-instruction contract and decoded strings remain under .local.
No probe object is evidence: ordinary two-host confirmation must compile every unit.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import subprocess
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/verifier'))
import bind
import compare_internal as internal
import disasm
import runners
import symbol_map
import unit_build
from census_leaf_generate import write_new
from pecoff import CoffObject, PeImage
from source_digest import include_closure
from digest_v2 import tu_digest
from storage_row_extract import extract_eh, extract_instructions
import string_static_template_v2 as template

EXTRACTOR_SHA256 = 'bef60ec00d5199f4bc7923025c3eeed141ed45a3068856789b18d848b899afc5'
CONTRACT_SHA256 = '7920d7abb42710708a9d0c9c4e2d8616f98359915c808aa07f99bb233cb520d9'


def load_contract(path):
    blob = Path(path).read_bytes()
    if hashlib.sha256(blob).hexdigest() != CONTRACT_SHA256:
        raise ValueError('private extraction contract differs from pin')
    return json.loads(blob)


def extract_member(image, objdump, image_path, member, contract, procedures, handler):
    rva, size = member['rva'], member['size']
    rows = disasm.target_rows(objdump, str(image_path), rva, size)
    params = extract_instructions(rows, image.image_base, contract['primary'])
    eh = extract_eh(image, rva, procedures, handler)
    if any(eh[k] != v for k, v in contract['eh'].items()):
        raise ValueError('EH metadata differs from contract')
    fields = struct.unpack('<10I', image.read(eh['funcinfo-rva'], 40, 'FuncInfo audit')[1])
    if any(fields[int(index)] != value for index, value in contract['funcinfo-scalars'].items()):
        raise ValueError('FuncInfo scalar differs from private contract')
    if fields[5] > 65536:
        raise ValueError('unreasonable IP map count')
    ip_map = [dict(offset=ip - rva, state=state) for n in range(fields[5])
              for ip, state in [struct.unpack('<Ii', image.read(fields[6] + 8*n, 8, 'IP map audit')[1])]]
    if ip_map != contract['ip-map'] or len(ip_map) != 1:
        raise ValueError('IP map differs from one-state contract')
    params.update({'funcinfo-magic': fields[0], 'ip-map-count': fields[5], 'unwind-help': fields[7],
                   'es-type-list': fields[8], 'ip-offset': ip_map[0]['offset'], 'ip-state': ip_map[0]['state']})
    if len(eh['actions']) != 1 or not eh['actions'][0][1]:
        raise ValueError('expected exactly one cleanup action')
    state, action = eh.pop('actions')[0]
    if state != contract['cleanup-to-state']:
        raise ValueError('unexpected cleanup state')
    cleanup = disasm.target_rows(objdump, str(image_path), action, contract['cleanup_size'])
    params.update(extract_instructions(cleanup, image.image_base, contract['cleanup']))
    if params['object-rva'] != params['cleanup-object-rva']:
        raise ValueError('cleanup refers to a different object')
    # The literal is a referenced dependency, never emitted into reconstructed source.
    # Retain its extent/hash for private auditing without publishing its contents.
    literal = bytearray()
    for offset in range(65536):
        byte = image.read(params['string-rva'] + offset, 1, 'string dependency')[1]
        literal.extend(byte)
        if byte == b'\0':
            break
    else:
        raise ValueError('unterminated string dependency')
    params.update(eh)
    params.update({'entry-rva': rva, 'size': size, 'cleanup-action-rva': action,
                   'cleanup-to-state': state, 'string-length': len(literal) - 1,
                   'string-sha256': hashlib.sha256(literal).hexdigest()})
    return params


def prepare(config):
    out, contract_path = (Path(config[k]).resolve() for k in ('out', 'contract'))
    if any('.local' not in path.parts for path in (out, contract_path)):
        raise ValueError('output and extraction contract must remain private')
    if (out / 'all.txt').exists():
        raise ValueError('output already prepared')
    if hashlib.sha256((ROOT / 'tools/storage_row_extract.py').read_bytes()).hexdigest() != EXTRACTOR_SHA256:
        raise ValueError('generic extraction reader differs from pin')
    members = config['members']
    if not members or len({m['rva'] for m in members}) != len(members):
        raise ValueError('empty or duplicate population')
    contract = load_contract(contract_path)
    settings = json.loads((ROOT / '.local/verifier/config.json').read_text())
    image_path = Path(settings['image'])
    blob = image_path.read_bytes()
    if hashlib.sha256(blob).hexdigest() != json.loads((ROOT / 'builds/target.json').read_text())['image_sha256']:
        raise ValueError('image differs from pinned target')
    image = PeImage(blob)
    procedures = {}
    for begin, _, unwind in image.runtime_functions():
        procedures.setdefault(begin, []).append(unwind)
    objdump = disasm.find_objdump(settings.get('objdump'))
    if not objdump:
        raise ValueError('objdump unavailable')
    handler = json.loads((ROOT / f'reports/{template.BUILD}/symbol-map.json').read_text())['symbols']['__CxxFrameHandler3']
    progress_path = ROOT / 'data/progress.json'
    progress = json.loads(progress_path.read_text())
    for member in members:
        if any(member['rva'] < f['rva'] + f['size'] and f['rva'] < member['rva'] + member['size']
               for f in progress['functions']):
            raise ValueError('candidate overlaps existing inventory')
    with ThreadPoolExecutor(max_workers=6) as executor:
        extracted = list(executor.map(lambda m: extract_member(image, objdump, image_path, m, contract, procedures,
                                                              handler['rva']), members))
    out.mkdir(parents=True, exist_ok=True)
    (out / 'rows.json').write_text(json.dumps(extracted, indent=2) + '\n')
    host = next(h for h in runners.load()['hosts'].values() if h['backend'] == 'local' and h['loader'] == 'wine')
    flags = json.loads((ROOT / template.RECIPE).read_text())['flags']

    def one(params):
        rva, size = params['entry-rva'], params['size']
        cls, header, cpp, origin = template.emit(rva, size)
        source = f'reconstruction/static/{cls}.cpp'
        write_new(ROOT / source, cpp)
        write_new((ROOT / source).with_suffix('.h'), header)
        directory = out / 'tasks' / f'p140-string-{rva:x}'
        directory.mkdir(parents=True, exist_ok=True)
        objpath = directory / 'probe.obj'
        with runners.slot(host['host_id'], host['max_parallel']):
            proc = subprocess.run([str(Path(host['msvc']) / 'bin/x64/cl'), *flags, '/Fo' + str(objpath), str(ROOT / source)],
                                  env=unit_build.clean_env(runners.LocalTransport(host).env()),
                                  capture_output=True, text=True, timeout=300)
        if proc.returncode:
            (directory / 'probe.log').write_text(proc.stdout + proc.stderr)
            raise ValueError('probe compilation failed')
        obj = CoffObject(objpath.read_bytes())
        symbols = {s.name: s for s in obj.symbols.values()}
        name = '??__Eobject@@YAXXZ'
        context = dict(source_revision=tu_digest(ROOT, include_closure(ROOT, source)), source_path=source)
        refs = {name: (rva, size), '?text@@3QBDB': (params['string-rva'], None),
                f'?object@@3U{cls}@@A': (params['object-rva'], None),
                '??0StringSlot@@QEAA@PEBD@Z': (params['construct-rva'], None),
                '??1StringSlot@@QEAA@XZ': (params['release-rva'], None),
                '??__Fobject@@YAXXZ': (params['teardown-rva'], None),
                'atexit': (params['atexit-rva'], None)}
        entries = {}
        for symbol, (address, length) in refs.items():
            if symbol not in symbols:
                raise ValueError('compiled reference identity missing')
            entries[internal.symbol_key(obj, symbols[symbol], context)] = dict(rva=address, size=length)
        entries['__CxxFrameHandler3'] = handler
        smap = dict(schema=1, build_id=template.BUILD, symbols=entries, folds=[],
                    _provenance=dict(note='Per-member initializer and cleanup bindings; all names are guesses.',
                                     entries=[dict(name=n, rva=hex(e['rva']), community_name=None,
                                                   note='Extracted independently from the pinned member.') for n, e in entries.items()]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        map_path = f'reports/{template.BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(ROOT, map_path, smap)
        task = dict(task_schema=2, task_id=directory.name, build_id=template.BUILD,
                    compiled=source, recipe=template.RECIPE, symbols=map_path,
                    functions=[dict(rva=rva, size=size, symbol=name,
                                    internal_selector=internal.selector(obj, symbols[name]),
                                    family_metadata=dict(origin=origin, family_parameters=params, name_source='GUESS(low)'))])
        (directory / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
        entry = dict(id=f'{template.BUILD}-0x{rva:x}', build_id=template.BUILD, rva=rva, size=size,
                     status='mapped', name=f'{cls}::initializer', name_origin='GUESS',
                     name_source='GUESS(low): generated static string acquisition; owning system unknown.',
                     owner='awarebayes', evidence=template.EVIDENCE)
        return str(directory), entry

    with ThreadPoolExecutor(max_workers=6) as executor:
        generated = list(executor.map(one, extracted))
    tasks = [task for task, _ in generated]
    progress['functions'].extend(entry for _, entry in generated)
    progress_path.write_text(json.dumps(progress, indent=2) + '\n')
    bind.preflight(tasks, ROOT)
    (out / 'all.txt').write_text(''.join(task + '\n' for task in tasks))
    print(f'prepared {len(tasks)} members; whole-list binding preflight passed', flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--selection', type=Path, required=True)
    args = parser.parse_args()
    prepare(json.loads(args.selection.read_text()))
