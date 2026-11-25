"""Reconstruct form-factory CreateImpl methods that call an out-of-line form constructor.

    python tools/form_factory_create_generate.py --exe /path/to/SkyrimSE.exe --out .local/form-create --compare

The comparator checks the constructor, heap references and exception cleanup for each product.
"""
from collections import Counter, defaultdict
from dataclasses import dataclass
import json
from pathlib import Path
import shutil
import struct

import contrib
import form_factory_generate as factory
import leaf_family_batch as batch
import memory_factory_generate as memory
from pecoff import Reject, SCN_MEM_EXECUTE

AREA = 'skyrim_shared/forms'
UNIT = 'FormFactoryProductStorage'
HEAP = 'FormFactoryAllocation'
ENSURE = '?EnsureInitialized@MemoryManager@' + HEAP + '@@QEAAXPEAI@Z'
ALLOC = '?Allocate@MemoryManager@' + HEAP + '@@QEAAPEAX_KH_N@Z'
INSTANCE = '?instance@MemoryManager@' + HEAP + '@@2V12@A'
GUARD = '?initState@MemoryManager@' + HEAP + '@@2IA'
SCN_MEM_WRITE = 0x80000000


@dataclass(frozen=True)
class Creator:
    owner: factory.Factory
    rva: int
    size: int
    allocation: int
    constructor: int
    heap: tuple
    family = UNIT

    @property
    def symbol(self):
        return '?CreateImpl@' + self.owner.decorated + 'UEAAPEAVTESForm@@XZ'


def classify(image, rva, size, extents):
    """Recognize guarded new T with a null path and a separate, direct default constructor."""
    from iced_x86 import Code, Decoder, FlowControl, Mnemonic, Register
    section, body = image.read(rva, size, 'creator')
    if not section.flags & SCN_MEM_EXECUTE:
        return None
    ins = list(Decoder(64, body, ip=rva))
    if len(ins) < 15 or any(i.is_invalid for i in ins):
        return None
    frame, state_slot = ins[:2]
    if (frame.code != Code.SUB_RM64_IMM8 or frame.op0_register != Register.RSP
            or state_slot.code != Code.MOV_RM64_IMM32 or state_slot.memory_base != Register.RSP
            or state_slot.memory_index != Register.NONE or state_slot.immediate32to64 != -2):
        return None
    guard = memory._match_ensure_init(ins, 2)
    if not guard:
        return None
    pos, state, instance, ensure, saved = guard
    args = memory._parse_alloc_const_args(ins, pos, instance)
    if not args or saved:
        return None
    pos, allocation = args
    calls = [i for i in ins if i.flow_control == FlowControl.CALL]
    if len(calls) != 3 or pos >= len(ins) or calls[1].ip != ins[pos].ip:
        return None
    if any(i.code != Code.CALL_REL32_64 or i.near_branch_target not in extents
           or rva <= i.near_branch_target < rva + size
           or not image.section_for(i.near_branch_target).flags & SCN_MEM_EXECUTE for i in calls):
        return None
    alloc, ctor = [i.near_branch_target for i in calls[1:]]
    if len({ensure, alloc, ctor}) != 3 or allocation <= 0x20 or allocation % 8:
        return None
    if state == instance or any(not image.section_for(a).flags & SCN_MEM_WRITE or
                                image.section_for(a).flags & SCN_MEM_EXECUTE for a in (state, instance)):
        return None
    flow = [i for i in ins if i.flow_control != FlowControl.NEXT]
    if [i.flow_control for i in flow] != [FlowControl.CONDITIONAL_BRANCH, FlowControl.CALL, FlowControl.CALL,
                                          FlowControl.CONDITIONAL_BRANCH, FlowControl.CALL,
                                          FlowControl.RETURN, FlowControl.RETURN]:
        return None
    tail = ins[pos + 1:]
    if (len(tail) != 11 or tail[0].code != Code.MOV_RM64_R64 or tail[0].memory_base != Register.RSP
            or tail[0].op1_register != Register.RAX or tail[1].code != Code.TEST_RM64_R64
            or (tail[1].op0_register, tail[1].op1_register) != (Register.RAX, Register.RAX)
            or tail[2].code != Code.JE_REL8_64 or tail[2].near_branch_target != tail[8].ip
            or tail[3].code != Code.MOV_R64_RM64 or (tail[3].op0_register, tail[3].op1_register)
            != (Register.RCX, Register.RAX) or tail[4].ip != calls[2].ip
            or not memory._is_zero_reg(tail[8], Register.EAX)):
        return None
    if (tail[5].mnemonic != Mnemonic.NOP or tail[7].code != Code.RETNQ or tail[10].code != Code.RETNQ
            or tail[0].memory_index != Register.NONE):
        return None
    for restore in (tail[6], tail[9]):
        if (restore.code != Code.ADD_RM64_IMM8 or restore.op0_register != Register.RSP
                or restore.immediate8to64 != frame.immediate8to64):
            return None
    return allocation, ctor, (state, instance, ensure, alloc)


def primary_form_base(image, table):
    """Require the product RTTI to place a nonvirtual TESForm subobject at offset zero."""
    (va,) = struct.unpack('<Q', factory.data(image, table.address - 8, 8))
    locator = va - image.image_base
    (_, _, _, _, chd, _) = struct.unpack('<6I', factory.data(image, locator, 24))
    _, _, count, array = struct.unpack('<4I', factory.data(image, chd, 16))
    if not 1 <= count <= 256:
        return False
    for bcd, in struct.iter_unpack('<I', factory.data(image, array, count * 4)):
        td, _, offset, parent, virtual = struct.unpack('<IIiii', factory.data(image, bcd, 20))
        if (offset, parent, virtual) == (0, -1, 0) and factory.type_name(image, td) == 'TESForm@@':
            return True
    return False


def select(image, extents, allowed, blocked):
    from iced_x86 import Decoder
    pdata, starts, isolated = factory.isolated_extents(image, extents)
    by_slot = defaultdict(list)
    primary = defaultdict(list)
    counts = Counter()
    for t in factory.tables(image, set(starts)):
        counts[t.name] += 1
        if not t.offset:
            primary[t.name].append(t)
        try:
            (va,) = struct.unpack('<Q', factory.data(image, t.address + 8, 8))
        except (Reject, ValueError):
            continue
        by_slot[va - image.image_base].append(t)
    result = []
    for rva in sorted(set(allowed) & isolated & by_slot.keys()):
        size = extents.get(rva)
        if not size or pdata.get(rva) != [rva + size]:
            continue
        owners = by_slot[rva]
        bases = [t for t in owners if t.hierarchy == (t.name, factory.INTERFACE)]
        if len(bases) != 1:
            continue
        base, = bases
        owner = factory.parse_factory(base.name)
        if not owner or owner.kind != factory.BASE:
            continue
        if any(t.offset or counts[t.name] != 1 or
               (t != base and t.hierarchy != (t.name, base.name, factory.INTERFACE)) for t in owners):
            continue
        try:
            shape = classify(image, rva, size, extents)
            if not shape or blocked(rva, size):
                continue
            product_name = ('.?AU' if owner.tag == 'struct' else '') + owner.form + '@@'
            products = primary[product_name]
            if len(products) != 1 or not primary_form_base(image, products[0]):
                continue
            ctor = shape[1]
            if pdata.get(ctor) != [ctor + extents[ctor]]:
                continue
            code = image.read(ctor, extents[ctor], 'product constructor')[1]
            if not any(i.is_ip_rel_memory_operand and i.ip_rel_memory_address == products[0].address
                       for i in Decoder(64, code, ip=ctor)):
                continue
        except (Reject, ValueError):
            continue
        result.append(Creator(owner, rva, size, *shape))
    if len({m.heap for m in result}) > 1:
        raise ValueError('inconsistent form factory heap bindings')
    return result


def discover(image, extents, inventory):
    import target_hashes
    ctx = contrib.Ctx()
    manifest = target_hashes.load_manifest(ctx.repo)
    allowed = {row['rva'] for row in manifest['functions'] if row['size'] == extents.get(row['rva'])}
    blocked = factory.occupied_ranges(ctx, manifest['build_id'], extents, inventory)
    return select(image, extents, allowed, blocked)


HEADER = """#pragma once
#include "ConcreteFormFactory.h"
#include "TESForm.h"

namespace FormFactoryAllocation
{
class MemoryManager
{
public:
    static MemoryManager instance;
    static unsigned initState;
    void EnsureInitialized(unsigned* state);
    void* Allocate(size_t bytes, int alignment, bool alignmentRequired);
};

// Represents only the TESForm base and the storage needed by the external constructor.
template<class T> struct ProductSize;

template<class T>
class FormFactoryProductStorage : public TESForm
{
public:
    FormFactoryProductStorage();

    static void* operator new(size_t bytes)
    {
        if (MemoryManager::initState != 2) {
            MemoryManager::instance.EnsureInitialized(&MemoryManager::initState);
        }
        return MemoryManager::instance.Allocate(bytes, 0, false);
    }

private:
    unsigned char unknown[ProductSize<T>::value - sizeof(TESForm)];
};
}
"""


def emit(root, family, members, build_id, label):
    from lint_reconstruction import SPDX_MIT
    prefix = [f'// {SPDX_MIT}', '// Source exposure: mixed (pinned image and community declarations).',
              '// Code origin: original factory method and partial product declarations. Adapted bodies: none.',
              '// Factory and product identities: EXE_RTTI',
              '// Allocation sizes and constructor calls: OBSERVED',
              '// CreateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)',
              '// Heap helpers, product storage and its constructor symbol: GUESS(low) STANDIN',
              f'// Boundary source: {label}']
    header = prefix + HEADER.splitlines()
    source = list(prefix)
    state, instance, ensure, alloc = members[0].heap
    public = json.loads((batch.ROOT / 'reports' / build_id / 'symbol-map.json').read_text())['symbols']
    symbols = {k: public[k] for k in (factory.DELETE, factory.HANDLER)}
    symbols.update({k: dict(rva=r, size=None) for k, r in
                    [(GUARD, state), (INSTANCE, instance), (ENSURE, ensure), (ALLOC, alloc)]})
    functions = []
    for m in members:
        o = m.owner
        name = o.cpp + '::CreateImpl'
        header += ['', f'{o.tag} {o.form};', 'namespace FormFactoryAllocation', '{',
                   f'template<> struct ProductSize<{o.form}>',
                   '{', f'    static constexpr size_t value = 0x{m.allocation:x};', '};',
                   f'static_assert(sizeof(FormFactoryProductStorage<{o.form}>) == 0x{m.allocation:x},',
                   '              "form allocation size");', '}']
        source.extend([f'// 0x{m.rva:x} {name}', f'// CI hash: 0x{m.rva:x} {m.symbol}'])
        tag = 'V' if o.tag == 'class' else 'U'
        ctor = f'??0?$FormFactoryProductStorage@{tag}{o.form}@@@{HEAP}@@QEAA@XZ'
        symbols[ctor] = dict(rva=m.constructor, size=None)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol, name=name))
    if len(('\n'.join(source) + '\n').encode()) > 8192:
        raise ValueError('explicit bindings exceed the CI header window')
    source += [f'#include "{family}.h"', '',
               '// A throwing product constructor releases its allocation through global sized delete.',
               'template<class T, unsigned char FormType>',
               'TESForm* ConcreteFormFactory<T, FormType>::CreateImpl()', '{', '    return new FormFactoryAllocation::FormFactoryProductStorage<T>;', '}', '']
    source += [f'template TESForm* {m.owner.cpp}::CreateImpl();' for m in members]
    task = batch.write_unit(root, family, build_id, header, source, symbols, functions, area=AREA)
    for file in ('TESForm.h', 'ConcreteFormFactory.h', 'IFormFactory.h'):
        rel = Path('reconstruction') / AREA / file
        shutil.copyfile(batch.ROOT / rel, root / rel)
    return task


if __name__ == '__main__':
    raise SystemExit(batch.run(__doc__, discover, emit, split=lambda m: m.owner.split))
