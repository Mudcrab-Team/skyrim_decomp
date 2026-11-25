#!/usr/bin/env python3
"""Local target-hash generation; never emits image bytes, masks or diagnostics.

CI imports only the stdlib/COFF helpers. iced-x86==1.21.0 is needed ONLY for local
linked-image reference-field extraction. This advisory format is not a comparator report.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path
import struct
import sys

import claimable
import compare
import target_hash_store as store
from pecoff import CoffObject, PeImage, Reject, Reloc, Section

ROOT = Path(__file__).resolve().parents[1]
VERSION = 'relocation-masked-sha256-v1'
MANIFEST = 'data/target-hashes/sse-steam-1-7-104.json'
OFFERED = 'data/target-hashes/contributor-targets.json'


def digest(blob):
    return hashlib.sha256(blob).hexdigest()


def layout(section):
    # Use exactly the comparator's supported types, field width, bounds and overlap checks.
    return [(start, end, rel.kind) for start, end, rel in
            compare.check_relocation_layout(section, len(section.data), 'target-hash')]


def normalized(data, spans):
    out = bytearray(data)
    for start, end, _kind in spans:
        out[start:end] = bytes(end - start)
    return bytes(out)


def layout_hash(size, spans):
    # A commitment, NOT the mask contents. Candidate-chosen additional masks cannot match it.
    blob = b'relocation-layout-sha256-v1\0' + struct.pack('<II', size, len(spans))
    for start, end, kind in spans:
        blob += struct.pack('<IIH', start, end - start, kind)
    return digest(blob)


def section_hash(section):
    spans = layout(section)
    return dict(normalized_sha256=digest(normalized(section.data, spans)),
                layout_sha256=layout_hash(len(section.data), spans))


def target_section(data, rva, tls_index=None, tls_size=None):
    """Infer link-dependent REL32 and TLS SECREL fields from the linked image.

    A linked PE has no original COFF relocation table. These inferred fields are advisory;
    other relocation shapes and linker transformations can use a private, checked override.
    No other immediates, register operands, internal branches or padding are erased.
    """
    from iced_x86 import (Decoder, FlowControl, InstructionInfoFactory, Mnemonic, OpAccess,
                          OpKind, Register, RegisterExt)
    decoder = Decoder(64, data, ip=rva)
    relocs = []
    secrel_fields = set()
    info = None
    tls_regs = {}
    offset_loads = {}
    guard_loads = {}
    guard_start = None
    writes = {OpAccess.WRITE, OpAccess.COND_WRITE, OpAccess.READ_WRITE, OpAccess.READ_COND_WRITE}
    full = RegisterExt.full_register

    def in_template(value):
        return 0 <= value < (tls_size if tls_size is not None else 1 << 31)

    for number, ins in enumerate(decoder):
        if ins.is_invalid:
            raise ValueError('unsupported target instruction')
        fields = decoder.get_constant_offsets(ins)
        offset = ins.ip - rva
        memory = any(ins.op_kind(k) == OpKind.MEMORY for k in range(ins.op_count))
        tls_array = (memory and ins.memory_segment == Register.GS and ins.memory_base == Register.NONE
                     and ins.memory_index == Register.NONE and ins.memory_displacement == 0x58)
        imm32_load = (ins.mnemonic == Mnemonic.MOV and ins.op0_kind == OpKind.REGISTER
                      and ins.op1_kind == OpKind.IMMEDIATE32 and fields.immediate_size == 4)
        # Keep the local-static guard's existing immediate mask.
        if imm32_load:
            guard_loads[full(ins.op0_register)] = (number, offset + fields.immediate_offset)
        elif tls_array and ins.mnemonic == Mnemonic.MOV and ins.op1_kind == OpKind.MEMORY:
            guard_start = number
        elif (guard_start is not None and number - guard_start <= 8 and ins.memory_base != Register.NONE
              and ins.memory_index != Register.NONE and ins.memory_index_scale == 1
              and ins.memory_displacement == 0 and not ins.is_ip_rel_memory_operand):
            for reg in (ins.memory_base, ins.memory_index):
                loaded = guard_loads.pop(full(reg), None)
                if loaded and number - loaded[0] <= 8:
                    secrel_fields.add(loaded[1])

        index_load = (tls_index is not None and ins.is_ip_rel_memory_operand
                      and ins.ip_rel_memory_address == tls_index)
        if tls_array or index_load or tls_regs:
            base, index = ins.memory_base, ins.memory_index
            dest, rhs = full(ins.op0_register), full(ins.op1_register)
            block = tls_regs.get(base) == 'block'
            field = None
            # The section offset can be a disp32, or an imm32 added to the block.
            if (memory and ins.segment_prefix == Register.NONE and block and index == Register.NONE
                    and fields.displacement_size == 4 and in_template(ins.memory_displacement)):
                field = offset + fields.displacement_offset
            if ins.mnemonic == Mnemonic.ADD and ins.op0_kind == OpKind.REGISTER and tls_regs.get(dest) == 'block':
                if fields.immediate_size == 4 and in_template(ins.immediate(1)):
                    field = offset + fields.immediate_offset
                elif ins.op1_kind == OpKind.REGISTER:
                    loaded = offset_loads.pop(rhs, None)
                    if loaded and number - loaded[0] <= 8:
                        field = loaded[1]
            if field is not None:
                secrel_fields.add(field)

            state = None
            if ins.mnemonic == Mnemonic.MOV and ins.op0_kind == OpKind.REGISTER:
                if tls_array and RegisterExt.size(ins.op0_register) == 8:
                    state = 'array'
                elif index_load and RegisterExt.size(ins.op0_register) == 4:
                    state = 'index'
                elif (memory and ins.segment_prefix == Register.NONE and tls_regs.get(base) == 'array'
                      and ins.memory_displacement == 0 and ins.memory_index_scale == 8
                      and index != Register.NONE and (tls_index is None or tls_regs.get(index) == 'index')
                      and RegisterExt.size(ins.op0_register) == 8):
                    state = 'block'
                elif ins.op1_kind == OpKind.REGISTER and RegisterExt.size(ins.op0_register) == 8:
                    state = tls_regs.get(rhs)
            if info is None:
                info = InstructionInfoFactory()
            for used in info.info(ins).used_registers():
                if used.access in writes:
                    reg = full(used.register)
                    tls_regs.pop(reg, None)
                    offset_loads.pop(reg, None)
            if state:
                tls_regs[dest] = state
            if imm32_load and in_template(ins.immediate32):
                offset_loads[dest] = (number, offset + fields.immediate_offset)
            if ins.flow_control != FlowControl.NEXT:
                tls_regs.clear()
                offset_loads.clear()
        if ins.is_ip_rel_memory_operand:
            if ins.memory_base != Register.RIP or fields.displacement_size != 4:
                raise ValueError('unsupported IP-relative field')
            tail = ins.len - fields.displacement_offset - 4
            kind = next((k for k, v in compare.REL32_TAIL.items() if v == tail), None)
            if kind is None:
                raise ValueError('unsupported REL32 tail')
            relocs.append(Reloc(offset + fields.displacement_offset, 0, kind))
        if ins.op_count and ins.op0_kind == OpKind.NEAR_BRANCH64:
            if (ins.flow_control == FlowControl.CALL
                    or not rva <= ins.near_branch_target < rva + len(data)):
                if fields.immediate_size != 4:
                    raise ValueError('unsupported external branch')
                relocs.append(Reloc(offset + fields.immediate_offset, 0, 0x04))
    sec = Section(1, '.text', 0, 0, 0, 0, 0, 0, 0)
    relocs.extend(Reloc(field, 0, compare.SECREL) for field in secrel_fields)
    sec.data, sec.relocs = data, sorted(relocs, key=lambda r: r.offset)
    layout(sec)
    return sec


def load_manifest(root):
    manifest = json.loads((root / MANIFEST).read_text())
    target = json.loads((root / 'builds/target.json').read_text())
    if (manifest['schema'] != 1 or manifest['normalization_version'] != VERSION
            or manifest['build_id'] != target['build_id']
            or manifest['image_sha256'] != target['image_sha256']
            or manifest['comparator_sha256'] != compare.comparator_source_sha256()
            or manifest['normalizer_sha256'] != digest((root / 'tools/target_hashes.py').read_bytes())
            or manifest['offered_inventory_sha256'] != digest((root / OFFERED).read_bytes())
            or manifest['compiler_pins_sha256'] != digest((root / 'tools/verifier/pinned.sha256').read_bytes())
            or any(digest((root / name).read_bytes()) != value
                   for name, value in manifest['recipe_sha256'].items())):
        raise ValueError('stale target-hash manifest')
    rows = []
    for shard in manifest['shards']:
        if not store.SHARD.fullmatch(shard['path']) or not compare.is_hash(shard['sha256']):
            raise ValueError('invalid target-hash shard')
        blob = (root / shard['path']).read_bytes()
        if digest(blob) != shard['sha256']:
            raise ValueError('target-hash shard digest differs')
        if store.is_binary(blob) != shard['path'].endswith('.thb'):
            raise ValueError('invalid target-hash shard contents')
        if not store.is_binary(blob) and set(json.loads(blob)) != {'functions'}:
            raise ValueError('invalid target-hash shard contents')
        part = store.rows(blob)
        if len(part) != shard['count']:
            raise ValueError('invalid target-hash shard contents')
        rows.extend(part)
    if len(rows) != manifest['function_count']:
        raise ValueError('target-hash count differs')
    manifest['functions'] = rows
    seen = set()
    for row in rows:
        if set(row) != {'rva', 'size', 'normalized_sha256', 'layout_sha256', 'extraction'}:
            raise ValueError('unexpected target-hash fields')
        if row['rva'] in seen or type(row['rva']) is not int or row['rva'] < 0:
            raise ValueError('duplicate or invalid target identity')
        seen.add(row['rva'])
        if type(row['size']) is not int or row['size'] <= 0:
            raise ValueError('invalid target size')
        for key in ('normalized_sha256', 'layout_sha256'):
            if not compare.is_hash(row[key]):
                raise ValueError('invalid target hash')
    return manifest


def candidate(blob, symbol, target):
    if target.get('extraction') == 'unmasked-unsupported':
        return 'no-target'
    _sym, section = compare.find_function(CoffObject(blob), symbol)
    if len(section.data) != target['size']:
        return 'mismatch'
    got = section_hash(section)
    # A different relocation layout is not comparable with this target extraction.
    if got['layout_sha256'] != target['layout_sha256']:
        return 'no-target'
    return 'hash-match' if got['normalized_sha256'] == target['normalized_sha256'] else 'mismatch'


def generate(root, image_path, overrides=None):
    target = json.loads((root / 'builds/target.json').read_text())
    image_bytes = image_path.read_bytes()
    if target['status'] != 'pinned' or digest(image_bytes) != target['image_sha256']:
        raise ValueError('image is not the pinned target')
    image = PeImage(image_bytes)
    tls_start, tls_end, tls_index = image.tls_template() if image.tls_dir[0] else (0, 0, None)
    inventory_bytes = (root / 'data/progress.json').read_bytes()
    inventory = json.loads(inventory_bytes)
    offered_bytes = (root / OFFERED).read_bytes()  # binds the parts by their digests
    offered = claimable.sharded_json(root, OFFERED, 'functions')
    if offered['build_id'] != target['build_id'] or offered['unresolved_rvas']:
        raise ValueError('offered target identity or boundary unresolved')
    functions = {f['rva']: f for f in inventory['functions']}
    for entry in offered['functions']:
        if entry['rva'] not in functions:
            functions[entry['rva']] = dict(entry, build_id=target['build_id'])
    rows, unsupported = [], []
    overrides = overrides or {}
    for fn in sorted(functions.values(), key=lambda f: f['rva']):
        if fn['build_id'] != target['build_id'] or fn['size'] <= 0:
            raise ValueError('inventory identity invalid')
        data = image.read(fn['rva'], fn['size'], 'target hash')[1]
        try:
            sec = target_section(data, fn['rva'], tls_index, tls_end - tls_start)
            extraction = 'linked-reference-inference'
        except ValueError:
            # Preserve exact bytes for unsupported instruction streams. Such rows are available
            # only to zero-relocation candidates; this is not a claim that a mask is known.
            sec = Section(1, '.text', 0, 0, 0, 0, 0, 0, 0)
            sec.data = data
            extraction = 'unmasked-unsupported'
            unsupported.append(fn['rva'])
        if str(fn['rva']) in overrides:
            sec.relocs = [Reloc(offset, 0, kind) for offset, kind in overrides[str(fn['rva'])]]
            extraction = 'local-comparator-layout'
        rows.append(dict(rva=fn['rva'], size=fn['size'], **section_hash(sec), extraction=extraction))
    return dict(schema=1, build_id=target['build_id'], image_sha256=target['image_sha256'],
                normalization_version=VERSION, hash_algorithm='SHA-256',
                comparator_sha256=compare.comparator_source_sha256(),
                normalizer_sha256=digest((root / 'tools/target_hashes.py').read_bytes()),
                inventory_sha256=digest(inventory_bytes),
                offered_inventory_sha256=digest(offered_bytes),
                compiler_pins_sha256=digest((root / 'tools/verifier/pinned.sha256').read_bytes()),
                recipe_sha256={p.relative_to(root).as_posix(): digest(p.read_bytes())
                               for p in sorted((root / 'reconstruction/recipes').glob('*.json'))},
                functions=rows,
                acceptance='not-evaluated'), unsupported


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--image', type=Path, required=True)
    p.add_argument('--out', type=Path, default=ROOT / MANIFEST)
    p.add_argument('--private-layouts', type=Path, help='local comparator-checked relocation offsets/types')
    a = p.parse_args(argv)
    a.out = a.out.resolve()
    try:
        overrides = json.loads(a.private_layouts.read_text()) if a.private_layouts else None
        report, unsupported = generate(ROOT, a.image, overrides)
        a.out.parent.mkdir(parents=True, exist_ok=True)
        rows = report.pop('functions')
        shards = []
        groups = {}
        for row in rows:
            groups.setdefault(store.shard_index(row['rva']), []).append(row)
        for index in sorted(groups):
            path = a.out.with_name(store.shard_name(a.out.stem, index))
            blob = store.encode(groups[index])
            path.write_bytes(blob)
            shards.append(dict(path=path.relative_to(ROOT).as_posix(), sha256=digest(blob), count=len(groups[index])))
        # A shard of an earlier layout that no longer belongs to the manifest would be published as a stray file.
        kept = {(ROOT / s['path']).resolve() for s in shards}
        for stale in a.out.parent.glob(a.out.stem + '-part-*'):
            if stale.resolve() not in kept:
                stale.unlink()
        report.update(shards=shards, function_count=len(rows))
        a.out.write_text(json.dumps(report, indent=2) + '\n')
        print(json.dumps(dict(hashes=len(rows), unsupported=len(unsupported),
                              normalization_version=VERSION, acceptance='not-evaluated')))
    except (ValueError, OSError, KeyError, Reject, ImportError) as exc:
        print(json.dumps(dict(error=type(exc).__name__, acceptance='not-evaluated')))
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
