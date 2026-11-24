"""Generate RTTI-owned scalar deleting destructors of Bethesda form factories.

    python tools/form_factory_generate.py --exe /path/to/SkyrimSE.exe --out .local/form-factories --compare

Requires iced-x86 and a contributor claims lookup. Only the comparator establishes a pass.
"""
from collections import Counter, defaultdict
from dataclasses import dataclass
import hashlib
import json
import re
import struct

import compare_runtime
import contrib
import duplicate_rva
import leaf_family_batch as batch
from lint_reconstruction import SPDX_MIT
from pecoff import Reject, SCN_MEM_EXECUTE

SCN_MEM_READ = 0x40000000
BASE = 'ConcreteFormFactory'
DERIVED = 'ConcreteObjectFormFactory'
INTERFACE = 'IFormFactory@@'
DELETE = '??3@YAXPEAX_K@Z'
HANDLER = '__CxxFrameHandler3'
UNREGISTER = '?UnregisterFormFactory@IFormFactory@@SAXE@Z'
NUMBER = r'\$0([0-9]|[A-P]{1,8}@)'
NAME = re.compile(r'\?\$(Concrete(?:Object)?FormFactory)@([VU])([A-Za-z_][A-Za-z0-9_]*)@@'
                  + NUMBER + '(?:' + NUMBER + NUMBER + ')?@@')


@dataclass(frozen=True)
class Factory:
    decorated: str
    kind: str
    tag: str
    form: str
    args: tuple

    @property
    def cpp(self):
        return f'{self.kind}<{self.form}, ' + ', '.join(map(str, self.args)) + '>'

    @property
    def split(self):
        # Keep base and derived instantiations of a form together.
        return 'development' if hashlib.sha256(self.form.encode()).digest()[0] % 2 == 0 else 'held-out'


def parse_factory(name):
    m = NAME.fullmatch(name)
    if not m:
        return None
    kind, tag, form, *numbers = m.groups()
    args = []
    for number in filter(None, numbers):
        if number.isdigit():
            args.append(1 + int(number))
        else:
            value = 0
            for digit in number[:-1]:
                value = 16 * value + ord(digit) - ord('A')
            if 1 <= value <= 10 or (len(number) > 2 and number.startswith('A')):
                return None
            args.append(value)
    if args[0] > 255 or len(args) != (1 if kind == BASE else 3):
        return None
    return Factory(name, kind, 'class' if tag == 'V' else 'struct', form, tuple(args))


@dataclass(frozen=True)
class Table:
    address: int
    slot: int
    name: str
    offset: int
    hierarchy: tuple


def data(image, rva, size):
    section, value = image.read(rva, size, 'RTTI')
    if section.flags & SCN_MEM_EXECUTE or not section.flags & SCN_MEM_READ:
        raise ValueError('RTTI outside readable data')
    return value


def type_name(image, td):
    section = image.section_for(td)
    at = td + 16
    room = min(section.vsize or section.raw_size, section.raw_size) - (at - section.vaddr)
    raw = data(image, at, min(512, max(room, 0))).split(b'\0', 1)
    if len(raw) != 2 or not raw[0].startswith((b'.?AV', b'.?AU')):
        raise ValueError('unsupported RTTI type descriptor')
    # Preserve a struct owner for fold detection without emitting it as a class.
    if raw[0].startswith(b'.?AU'):
        return raw[0].decode('ascii')
    return raw[0][4:].decode('ascii')


def table_at(image, address, locator, slot):
    signature, offset, cd, td, chd, check = struct.unpack('<6I', data(image, locator, 24))
    if signature != 1 or cd or check != locator:
        return None
    name = type_name(image, td)
    hierarchy = []
    if parse_factory(name) or name == INTERFACE:
        _, attributes, count, array = struct.unpack('<4I', data(image, chd, 16))
        if attributes or not 1 <= count <= 3:
            raise ValueError('expected a linear hierarchy')
        for bcd, in struct.iter_unpack('<I', data(image, array, 4 * count)):
            base, _, mdisp, pdisp, vdisp = struct.unpack('<IIiii', data(image, bcd, 20))
            if (mdisp, pdisp, vdisp) != (0, -1, 0):
                raise ValueError('expected a primary nonvirtual base')
            hierarchy.append(type_name(image, base))
    return Table(address, slot, name, offset, tuple(hierarchy))


def tables(image, starts):
    """Enumerate locator/first-slot pairs, including other owners of folded destructors."""
    for section in image.sections:
        if section.flags & SCN_MEM_EXECUTE or not section.flags & SCN_MEM_READ:
            continue
        size = min(section.vsize or section.raw_size, section.raw_size) // 8 * 8
        if size < 16:
            continue
        words = struct.iter_unpack('<Q', image.read(section.vaddr, size, 'vtable search')[1])
        previous, = next(words)
        for index, (word,) in enumerate(words, 1):
            slot = word - image.image_base
            locator = previous - image.image_base
            previous = word
            if slot not in starts or not 0 < locator <= 0xffffffff:
                continue
            try:
                table = table_at(image, section.vaddr + 8 * index, locator, slot)
            except (Reject, ValueError):
                continue
            if table:
                yield table


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    owner: Factory
    base: Table
    interface: Table
    unregister: int
    delete: int
    handler: int
    terminate: int

    @property
    def symbol(self):
        return '??_G' + self.owner.decorated + 'UEAAPEAXI@Z'

    @property
    def family(self):
        return self.owner.kind


def cleanup_target(image, rva, size, form_type, base, interface, delete, extents):
    """Cross-check the ownership hypothesis against both vptr transitions and call arguments."""
    from iced_x86 import Code, Decoder, FlowControl, Mnemonic, Register

    section, code = image.read(rva, size, 'destructor')
    if not section.flags & SCN_MEM_EXECUTE:
        return None
    insns = list(Decoder(64, code, ip=rva))
    if not insns or insns[-1].code != Code.RETNQ or any(i.is_invalid for i in insns):
        return None
    refs = [(k, i) for k, i in enumerate(insns) if i.is_ip_rel_memory_operand]
    if len(refs) != 2 or [i.ip_rel_memory_address for _, i in refs] != [base, interface]:
        return None
    for (k, i), reg in zip(refs, (Register.RCX, Register.RDI)):
        if i.code != Code.LEA_R64_M or i.op0_register != Register.RAX or k + 1 >= len(insns):
            return None
        store = insns[k + 1]
        if (store.code != Code.MOV_RM64_R64 or store.op1_register != Register.RAX
                or store.memory_base != reg or store.memory_index != Register.NONE or store.memory_displacement):
            return None
    flow = [(k, i) for k, i in enumerate(insns) if i.flow_control != FlowControl.NEXT]
    if [i.flow_control for _, i in flow] != [FlowControl.CALL, FlowControl.CONDITIONAL_BRANCH,
                                             FlowControl.CALL, FlowControl.RETURN]:
        return None
    (first, call), (branch, skip), (last, release), _ = flow
    if not refs[0][0] + 2 < first < refs[1][0] < branch < last:
        return None
    arg = insns[first - 1]
    if (arg.code != Code.MOV_R8_IMM8 or arg.op0_register != Register.CL or arg.immediate8 != form_type
            or call.code != Code.CALL_REL32_64 or call.near_branch_target not in extents
            or rva <= call.near_branch_target < rva + size or call.near_branch_target == delete
            or not image.section_for(call.near_branch_target).flags & SCN_MEM_EXECUTE):
        return None
    join = last + 1
    if insns[join].mnemonic == Mnemonic.NOP:
        join += 1
    returned_this = insns[join]
    if (returned_this.code != Code.MOV_R64_RM64
            or (returned_this.op0_register, returned_this.op1_register) != (Register.RAX, Register.RDI)):
        return None
    flags = insns[branch - 1]
    if (flags.code != Code.TEST_RM8_IMM8 or flags.op0_register != Register.BL or flags.immediate8 != 1
            or skip.code != Code.JE_REL8_64 or skip.near_branch_target != returned_this.ip
            or release.code != Code.CALL_REL32_64 or release.near_branch_target != delete):
        return None
    args = insns[branch + 1:last]
    if (len(args) != 2 or args[0].code != Code.MOV_R32_IMM32 or args[0].op0_register != Register.EDX
            or args[0].immediate32 != 16 or args[1].code != Code.MOV_R64_RM64
            or (args[1].op0_register, args[1].op1_register) != (Register.RCX, Register.RDI)):
        return None
    return call.near_branch_target


def select(image, extents, inventory, blocked, symbols, terminate):
    pdata = defaultdict(list)
    for begin, end, _ in image.runtime_functions():
        pdata[begin].append(end)
    ends = {rva: rva + size for rva, size in extents.items()}
    for rva, runtime_ends in pdata.items():
        ends[rva] = max(ends.get(rva, 0), max(runtime_ends))
    starts = sorted(ends)
    isolated = set()
    previous_end = 0
    for i, rva in enumerate(starts):
        if previous_end <= rva and (i + 1 == len(starts) or ends[rva] <= starts[i + 1]):
            isolated.add(rva)
        previous_end = max(previous_end, ends[rva])
    by_name = defaultdict(list)
    owners = Counter()
    for table in tables(image, ends):
        owners[table.slot] += 1
        by_name[table.name].append(table)

    result = []
    for name, group in by_name.items():
        owner = parse_factory(name)
        if not owner or len(group) != 1:
            continue
        table, = group
        rva = table.slot
        size = extents.get(rva, 0)
        if (not size or rva not in isolated or table.offset or owners[rva] != 1 or pdata[rva] != [rva + size]
                or blocked(rva, size) or inventory.get(rva, {}).get('size', size) != size):
            continue
        hierarchy = table.hierarchy
        if (len(hierarchy) != (2 if owner.kind == BASE else 3)
                or hierarchy[0] != name or hierarchy[-1] != INTERFACE):
            continue
        if len(by_name.get(hierarchy[-2], ())) != 1 or len(by_name.get(INTERFACE, ())) != 1:
            continue
        base, = by_name[hierarchy[-2]]
        interface, = by_name[INTERFACE]
        parent = parse_factory(base.name)
        if (not parent or parent.kind != BASE or base.offset or interface.offset
                or base.hierarchy != (base.name, INTERFACE) or interface.hierarchy != (INTERFACE,)
                or (parent.tag, parent.form, parent.args[0]) != (owner.tag, owner.form, owner.args[0])):
            continue
        try:
            for address in (table.address, base.address, interface.address):
                slots = struct.iter_unpack('<Q', data(image, address, 7 * 8))
                if not all(image.section_for(va - image.image_base).flags & SCN_MEM_EXECUTE for va, in slots):
                    raise ValueError('non-executable virtual slot')
            cleanup = cleanup_target(image, rva, size, owner.args[0], base.address, interface.address,
                                     symbols[DELETE]['rva'], extents)
        except (Reject, ValueError):
            continue
        if cleanup is not None:
            result.append(Member(rva, size, owner, base, interface, cleanup, symbols[DELETE]['rva'],
                                 symbols[HANDLER]['rva'], terminate))
    if len({m.unregister for m in result}) > 1:
        raise ValueError('inconsistent form-factory unregistration targets')
    return sorted(result, key=lambda m: m.rva)


def discover(image, extents, inventory):
    ctx = contrib.Ctx()
    build = contrib.target_manifest(ctx.repo)['build_id']
    symbols = json.loads((ctx.repo / 'reports' / build / 'symbol-map.json').read_text())['symbols']
    claims = ctx.github().open_items()
    claimed = contrib.batch_claims.ClaimIndex(claims.records, build)
    marked = set(duplicate_rva.marked(ctx.repo))
    local = {contrib.parse_rva(k) for k in contrib.local_claims(ctx)}
    occupied = sorted((r, r + max(extents.get(r, 1), inventory.get(r, {}).get('size', 1))) for r in
                      marked | local | {r for r, row in inventory.items() if row['status'] == 'matched'})

    def blocked(rva, size):
        return (any(a < rva + size and rva < b for a, b in occupied)
                or claimed.overlaps([(rva, rva + size)]))

    thunk = compare_runtime.termination_thunk(image)
    return select(image, extents, inventory, blocked, symbols, thunk['rva'])


INTERFACE_HEADER = """#pragma once

class TESForm;

class IFormFactory
{
public:
    virtual ~IFormFactory() {}
    virtual TESForm* CreateImpl() = 0;
    virtual const char* GetFormName() const = 0;
    virtual unsigned char GetFormType() const = 0;
    virtual const char* GetObjectName() const;
    virtual unsigned int GetObjectType() const;
    virtual unsigned int GetObjectCategory() const;

    static void UnregisterFormFactory(unsigned char formType);
};

"""

BASE_HEADER = """#pragma once
#include "IFormFactory.h"

template<class T, unsigned char FormType>
class ConcreteFormFactory : public IFormFactory
{
public:
    ~ConcreteFormFactory() override { UnregisterFormFactory(FormType); }
    TESForm* CreateImpl() override;
    const char* GetFormName() const override;
    unsigned char GetFormType() const override;

protected:
    const char* _name;
};

"""

DERIVED_HEADER = """#pragma once
#include "ConcreteFormFactory.h"

template<class T, unsigned char FormType, unsigned int ObjectType, unsigned int Category>
class ConcreteObjectFormFactory : public ConcreteFormFactory<T, FormType>
{
public:
    ConcreteObjectFormFactory() {}
    const char* GetObjectName() const override;
    unsigned int GetObjectType() const override;
    unsigned int GetObjectCategory() const override;
};
"""


def emit(root, family, members, build_id, label):
    prefix = [f'// {SPDX_MIT}', '// Source exposure: mixed (pinned image and published community declarations).',
              '// Factory types and template arguments: EXE_RTTI',
              '// Destructor slot and size: OBSERVED',
              '// Virtual declarations and _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)',
              '// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN',
              '// Code origin: original form-factory destructor template. Adapted bodies: none.',
              f'// Boundary source: {label}']
    names = [f'{m.owner.cpp}::~{m.owner.kind}' for m in members]
    markers = [f'// 0x{m.rva:x} {name}' for m, name in zip(members, names)]
    bindings = [f'// CI hash: 0x{m.rva:x} {m.symbol}' for m in members]
    source = prefix + markers + bindings + [f'#include "{family}.h"', '']
    first = members[0]
    symbols = {DELETE: dict(rva=first.delete, size=None), HANDLER: dict(rva=first.handler, size=None),
               '__std_terminate': dict(rva=first.terminate, size=6),
               UNREGISTER: dict(rva=first.unregister, size=None)}
    functions = []
    for tag, form in sorted({(m.owner.tag, m.owner.form) for m in members}):
        source.append(f'{tag} {form};')
    source.append('')
    for m, name in zip(members, names):
        for table in (m.base, m.interface):
            symbols['??_7' + table.name + '6B@'] = dict(rva=table.address, size=None)
        source.append(f'template class {m.owner.cpp};')
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol, name=name))
    headers = {'IFormFactory': INTERFACE_HEADER, BASE: BASE_HEADER, DERIVED: DERIVED_HEADER}
    task = batch.write_unit(root, family, build_id, prefix + headers[family].splitlines(),
                            source, symbols, functions)
    directory = root / 'reconstruction/leaves'
    for dep in (['IFormFactory', BASE] if family == DERIVED else ['IFormFactory']):
        (directory / f'{dep}.h').write_text('\n'.join(prefix + headers[dep].splitlines()) + '\n')
    return task


if __name__ == '__main__':
    raise SystemExit(batch.run(__doc__, discover, emit, split=lambda member: member.owner.split))
