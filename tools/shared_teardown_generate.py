"""Enroll complete shared-owner static teardown shapes from a pinned image.

A freshly compiled source probe supplies the enrollment shape, never match
proof. Every member still requires the unchanged two-host comparator and review.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tools/verifier'), str(ROOT/'tools/analysis')]
import bind
import compare_internal as internal
import imagemodel
from pecoff import CoffObject, PeImage
import runners
from source_digest import include_closure
from digest_v2 import tu_digest
import symbol_map
import unit_build
import shared_teardown_template_v1 as template


def write_new(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and (path.is_symlink() or path.read_text() != content):
        raise ValueError('refusing different existing source')
    path.write_text(content)


def extract(image, member, obj, emitted):
    rva, size = member['rva'], member['size']
    symbols = [s for s in obj.symbols.values() if s.name == emitted['symbol'] and s.is_function]
    if len(symbols) != 1:
        raise ValueError('ambiguous source probe')
    sym = symbols[0]
    internal.check_selector(internal.selector(obj, sym))
    section = obj.section(sym.section)
    if len(section.data) != size or len(section.relocs) != 1:
        raise ValueError('unsupported complete probe extent/reference shape')
    rel = section.relocs[0]
    if rel.kind != 4 or obj.symbols[rel.symbol].name != emitted['object_symbol']:
        raise ValueError('probe reference is not the static owner')
    addend = struct.unpack_from('<i', section.data, rel.offset)[0]
    code = image.read(rva, size, 'shared-owner teardown')[1]
    fields, _, flags, end = imagemodel.field_records(code, rva, size, image.image_base, rva+size)
    if flags or end != size or len(fields) != 1:
        raise ValueError('unsupported complete member decoding')
    off, width, kind, tail, target = fields[0]
    if (off, width, kind, tail) != (rel.offset, 4, 'REL32', 0):
        raise ValueError('reference shape differs')
    independent = rva+off+4+struct.unpack_from('<i', code, off)[0]
    if target != independent or image.section_for(target) is None:
        raise ValueError('invalid member reference binding')
    candidate, actual = bytearray(section.data), bytearray(code)
    candidate[off:off+4] = actual[off:off+4] = bytes(4)
    if candidate != actual:
        raise ValueError('complete member instruction shape differs')
    object_rva = target-addend
    if object_rva <= 0 or object_rva % 8 or image.section_for(object_rva) is None:
        raise ValueError('unsupported static owner storage binding')
    return object_rva, internal.selector(obj, sym)


def generate(selection, out):
    if not out.resolve().is_relative_to(ROOT/'.local'):
        raise ValueError('outputs must remain private')
    if selection['build_id'] != template.BUILD or not selection['members']:
        raise ValueError('empty or wrong build selection')
    members = selection['members']
    if len({m['rva'] for m in members}) != len(members) or any(m['kind'] != 'teardown' for m in members):
        raise ValueError('duplicate or non-teardown population')
    target = json.loads((ROOT/'builds/target.json').read_text())
    image_data = Path(json.loads((ROOT/'.local/verifier/config.json').read_text())['image']).read_bytes()
    if hashlib.sha256(image_data).hexdigest() != target['image_sha256']:
        raise ValueError('pinned image mismatch')
    image = PeImage(image_data)
    progress = json.loads((ROOT/'data/progress.json').read_text())
    existing = {f['rva']: f for f in progress['functions']}
    if any(m['rva'] in existing and (existing[m['rva']]['status']=='matched' or existing[m['rva']]['size']!=m['size']) for m in members):
        raise ValueError('matched or inconsistent inventory entry')
    out.mkdir(parents=True, exist_ok=True)
    seed = template.emit(members[0]['rva'], members[0]['size'])
    source = f'reconstruction/static/{seed["cls"]}.cpp'
    write_new(ROOT/source, seed['source']); write_new((ROOT/source).with_suffix('.h'), seed['header'])
    host = runners.for_attempt(); objpath = out/'probe.obj'
    with runners.slot(host['host_id'], host['max_parallel']):
        p = subprocess.run([str(Path(host['msvc'])/'bin/x64/cl'), *json.loads((ROOT/template.RECIPE).read_text())['flags'],
                            '/Fo'+str(objpath.resolve()), str(ROOT/source)],
                           env=unit_build.clean_env(runners.LocalTransport(host).env()), capture_output=True, text=True, timeout=180)
    (out/'probe.log').write_text(p.stdout+p.stderr)
    if p.returncode:
        raise ValueError('source probe did not compile')
    obj = CoffObject(objpath.read_bytes())
    # Full extraction of all selected members precedes population enrollment.
    rows = [(m, *extract(image, m, obj, seed)) for m in members]
    tasks, parameters = [], []
    for m, object_rva, selector in rows:
        rva, size = m['rva'], m['size']; emitted = template.emit(rva, size)
        source = f'reconstruction/static/{emitted["cls"]}.cpp'
        write_new(ROOT/source, emitted['source']); write_new((ROOT/source).with_suffix('.h'), emitted['header'])
        context = dict(source_revision=tu_digest(ROOT, include_closure(ROOT, source)), source_path=source)
        # Source probes have identical section ordering. The comparator independently
        # refuses any selector that fails to resolve in each newly compiled object.
        symbols = {}
        for name, address, extent in [(seed['symbol'], rva, size), (seed['object_symbol'], object_rva, None)]:
            sym = next(s for s in obj.symbols.values() if s.name==name)
            actual_name = emitted['object_symbol'] if name==seed['object_symbol'] else name
            key = internal.local_key(context['source_revision'], source, actual_name, internal.selector(obj, sym)) if sym.storage==3 and sym.section>0 else actual_name
            symbols[key] = dict(rva=address, size=extent)
        smap = dict(schema=1, build_id=template.BUILD, symbols=symbols, folds=[], _provenance=dict(entries=[dict(name=n,rva=hex(v['rva']),community_name=None,note='Per-member pinned-image static owner binding; source names are guesses.') for n,v in symbols.items()]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest(); map_path=f'reports/{template.BUILD}/unit-symbols/{digest}.json';symbol_map.create(ROOT,map_path,smap)
        params = dict(rva=rva,size=size,**{'object-rva':object_rva})
        td=out/'tasks'/f'p156-shared-{rva:x}';td.mkdir(parents=True,exist_ok=True)
        task=dict(task_schema=2,task_id=td.name,build_id=template.BUILD,compiled=source,recipe=template.RECIPE,symbols=map_path,functions=[dict(rva=rva,size=size,symbol=emitted['symbol'],internal_selector=selector,family_metadata=dict(origin=template.origin(),family_parameters=params,name_source='GUESS(low)'))])
        (td/'task.json').write_text(json.dumps(task,indent=2)+'\n');tasks.append(str(td.resolve()));parameters.append(params)
        if rva not in existing:progress['functions'].append(dict(id=f'{template.BUILD}-0x{rva:x}',build_id=template.BUILD,rva=rva,size=size,status='mapped',name=f'{emitted["cls"]}::teardown',name_origin='GUESS',name_source='GUESS(low): generated shared-owner teardown; owning system and pointee unknown.',owner='awarebayes',evidence=template.EVIDENCE))
    (ROOT/'data/progress.json').write_text(json.dumps(progress,indent=2)+'\n');bind.preflight(tasks,ROOT)
    (out/'all.txt').write_text(''.join(t+'\n' for t in tasks));(out/'parameter-rows.json').write_text(json.dumps(parameters,indent=2)+'\n')
    print(f'extracted {len(tasks)} complete members; binding preflight passed',flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--selection',type=Path,required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args();generate(json.loads(a.selection.read_text()),a.out)
