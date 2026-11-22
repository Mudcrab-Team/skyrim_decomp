"""Draft polymorphic table-reset wrappers (initializers, tail cleanups and deallocators).

    python tools/vftable_reset_generate.py --exe /path/to/SkyrimSE.exe
    python tools/vftable_reset_generate.py --exe /path/to/SkyrimSE.exe --out .local/vftable-reset --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information, read-only table address and direct
call targets for every generated member.
"""
from dataclasses import dataclass, replace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE


INIT = 'TableInitializers'
TAIL = 'TableTailCleanups'
DEALLOC = 'TableDeallocators'
CLEANUP_DEALLOC = 'TableCleanupDeallocators'
SHARD_SIZE = 100


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    family: str
    table: int
    object_size: int | None = None
    callee: int | None = None
    cleanup: int | None = None

    @property
    def name(self):
        if self.family.startswith(INIT):
            return f'Init{self.rva:x}'
        if self.family.startswith(TAIL):
            return f'Cleanup{self.rva:x}'
        return f'Delete{self.rva:x}'

    @property
    def symbol(self):
        if self.family.startswith(INIT):
            return f'?{self.name}@{self.family}@@SAPEAXPEAUPolymorphicObject@@@Z'
        if self.family.startswith(TAIL):
            return f'?{self.name}@{self.family}@@SAXPEAUPolymorphicObject@@@Z'
        return f'?{self.name}@{self.family}@@SAPEAXPEAUPolymorphicObject@@I@Z'


def _is_table_store(load, store):
    from iced_x86 import Code, Register

    return (load.code == Code.LEA_R64_M and load.op0_register == Register.RAX
            and load.memory_base == Register.RIP and load.is_ip_rel_memory_operand
            and not load.has_segment_prefix and load.len == 7
            and store.code == Code.MOV_RM64_R64 and store.memory_base == Register.RCX
            and store.memory_displacement == 0 and store.op1_register == Register.RAX
            and not store.has_segment_prefix and store.len == 3)


def _classify_init(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 4
            or not _is_table_store(insns[0], insns[1])
            or insns[2].code != Code.MOV_R64_RM64 or insns[2].op0_register != Register.RAX
            or insns[2].op1_register != Register.RCX or insns[2].len != 3
            or insns[3].code != Code.RETNQ or insns[3].len != 1):
        return None
    return Member(rva, size, INIT, insns[0].ip_rel_memory_address)


def _classify_tail(insns, rva, size):
    from iced_x86 import Code

    if (len(insns) != 3
            or not _is_table_store(insns[0], insns[1])
            or insns[2].code != Code.JMP_REL32_64 or insns[2].len != 5):
        return None
    return Member(rva, size, TAIL, insns[0].ip_rel_memory_address, cleanup=insns[2].near_branch_target)


def _classify_dealloc(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 13
            or insns[0].code != Code.PUSH_R64 or insns[0].op0_register != Register.RBX or insns[0].len != 2
            or insns[1].code != Code.SUB_RM64_IMM8 or insns[1].op0_register != Register.RSP
            or insns[1].immediate8 != 0x20 or insns[1].len != 4
            or insns[3].code != Code.MOV_R64_RM64 or insns[3].op0_register != Register.RBX
            or insns[3].op1_register != Register.RCX or insns[3].len != 3
            or not _is_table_store(insns[2], insns[4])
            or insns[5].code != Code.TEST_RM8_IMM8 or insns[5].op0_register != Register.DL
            or insns[5].immediate8 != 1 or insns[5].len != 3
            or insns[6].code != Code.JE_REL8_64 or insns[6].len != 2
            or insns[6].near_branch_target != insns[9].ip
            or insns[7].code != Code.MOV_R32_IMM32 or insns[7].op0_register != Register.EDX
            or insns[7].len != 5 or insns[7].immediate32 == 0
            or insns[8].code != Code.CALL_REL32_64 or insns[8].len != 5
            or insns[9].code != Code.MOV_R64_RM64 or insns[9].op0_register != Register.RAX
            or insns[9].op1_register != Register.RBX or insns[9].len != 3
            or insns[10].code != Code.ADD_RM64_IMM8 or insns[10].op0_register != Register.RSP
            or insns[10].immediate8 != 0x20 or insns[10].len != 4
            or insns[11].code != Code.POP_R64 or insns[11].op0_register != Register.RBX or insns[11].len != 1
            or insns[12].code != Code.RETNQ or insns[12].len != 1):
        return None
    return Member(rva, size, DEALLOC, insns[2].ip_rel_memory_address,
                  object_size=insns[7].immediate32, callee=insns[8].near_branch_target)


def _classify_cleanup_dealloc(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 18
            or insns[0].code != Code.MOV_RM64_R64 or insns[0].memory_base != Register.RSP
            or insns[0].memory_displacement != 8 or insns[0].op1_register != Register.RBX or insns[0].len != 5
            or insns[1].code != Code.PUSH_R64 or insns[1].op0_register != Register.RDI or insns[1].len != 1
            or insns[2].code != Code.SUB_RM64_IMM8 or insns[2].op0_register != Register.RSP
            or insns[2].immediate8 != 0x20 or insns[2].len != 4
            or insns[4].code != Code.MOV_R32_RM32 or insns[4].op0_register != Register.EBX
            or insns[4].op1_register != Register.EDX or insns[4].len != 2
            or not _is_table_store(insns[3], insns[5])
            or insns[6].code != Code.MOV_R64_RM64 or insns[6].op0_register != Register.RDI
            or insns[6].op1_register != Register.RCX or insns[6].len != 3
            or insns[7].code != Code.CALL_REL32_64 or insns[7].len != 5
            or insns[8].code != Code.TEST_RM8_IMM8 or insns[8].op0_register != Register.BL
            or insns[8].immediate8 != 1 or insns[8].len != 3
            or insns[9].code != Code.JE_REL8_64 or insns[9].len != 2
            or insns[9].near_branch_target != insns[13].ip
            or insns[10].code != Code.MOV_R32_IMM32 or insns[10].op0_register != Register.EDX
            or insns[10].len != 5 or insns[10].immediate32 == 0
            or insns[11].code != Code.MOV_R64_RM64 or insns[11].op0_register != Register.RCX
            or insns[11].op1_register != Register.RDI or insns[11].len != 3
            or insns[12].code != Code.CALL_REL32_64 or insns[12].len != 5
            or insns[13].code != Code.MOV_R64_RM64 or insns[13].op0_register != Register.RBX
            or insns[13].memory_base != Register.RSP or insns[13].memory_displacement != 0x30 or insns[13].len != 5
            or insns[14].code != Code.MOV_R64_RM64 or insns[14].op0_register != Register.RAX
            or insns[14].op1_register != Register.RDI or insns[14].len != 3
            or insns[15].code != Code.ADD_RM64_IMM8 or insns[15].op0_register != Register.RSP
            or insns[15].immediate8 != 0x20 or insns[15].len != 4
            or insns[16].code != Code.POP_R64 or insns[16].op0_register != Register.RDI or insns[16].len != 1
            or insns[17].code != Code.RETNQ or insns[17].len != 1):
        return None
    cleanup = insns[7].near_branch_target
    dealloc = insns[12].near_branch_target
    if cleanup == dealloc:
        return None
    return Member(rva, size, CLEANUP_DEALLOC, insns[3].ip_rel_memory_address,
                  object_size=insns[10].immediate32, callee=dealloc, cleanup=cleanup)


def classify(code, rva):
    from iced_x86 import Decoder

    insns = list(Decoder(64, code, ip=rva))
    if any(i.is_invalid for i in insns):
        return None
    handlers = {
        14: _classify_init,
        15: _classify_tail,
        43: _classify_dealloc,
        62: _classify_cleanup_dealloc,
    }
    handler = handlers.get(len(code))
    return handler(insns, rva, len(code)) if handler else None


def _eligible_table(image, address):
    try:
        section = image.section_for(address)
        return (section.name == '.rdata'
                and not (section.flags & SCN_MEM_EXECUTE)
                and not (section.flags & 0x80000000)
                and address < section.vaddr + section.vsize)
    except Reject:
        return False


def _indexed_target(image, member, target, starts):
    return leaf_family_batch.indexed_callee(image, replace(member, callee=target), starts)


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    raw = []
    for m in leaf_family_batch.candidates(image, extents, inventory, (14, 15, 43, 62), classify):
        if not _eligible_table(image, m.table):
            continue
        if m.callee is not None and not _indexed_target(image, m, m.callee, starts):
            continue
        if m.cleanup is not None and not _indexed_target(image, m, m.cleanup, starts):
            continue
        raw.append(m)
    result = []
    for base in (INIT, TAIL, DEALLOC, CLEANUP_DEALLOC):
        rows = [m for m in raw if m.family == base]
        member_rvas = {m.rva for m in rows}
        deallocs = {m.callee for m in rows if m.callee is not None}
        clean = [m for m in rows
                 if (m.callee is None or m.callee not in member_rvas)
                 and (m.cleanup is None or (m.cleanup not in member_rvas and m.cleanup not in deallocs))]
        if len(clean) <= SHARD_SIZE:
            result.extend(clean)
        else:
            for index in range(0, len(clean), SHARD_SIZE):
                shard = f'{base}{index // SHARD_SIZE + 1}'
                result.extend(replace(m, family=shard) for m in clean[index:index + SHARD_SIZE])
    return result


def emit(root, family, members, build_id, label):
    prefix = ['// Source exposure: mixed (pinned image and community function boundaries).',
              f'// Boundary source: {label}',
              '// Code origin: original polymorphic table-reset wrapper template.',
              f'// {family}, PolymorphicObject, methods and targets: GUESS(low) STANDIN; original ownership and layouts unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '', 'struct PolymorphicObject', '{', '    const void* table;', '};', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    for table in sorted({m.table for m in members}):
        name = f'TableTarget{table:x}'
        header.append(f'extern "C" const unsigned char {name};')
        symbols[name] = dict(rva=table, size=None)
    for cleanup in sorted({m.cleanup for m in members if m.cleanup is not None}):
        name = f'CleanupTarget{cleanup:x}'
        header.append(f'extern "C" void {name}(PolymorphicObject* object);')
        symbols[name] = dict(rva=cleanup, size=None)
    for dealloc in sorted({m.callee for m in members if m.callee is not None}):
        name = f'DeallocatorTarget{dealloc:x}'
        header.append(f'extern "C" void {name}(void* object, unsigned long long size);')
        symbols[name] = dict(rva=dealloc, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    for m in members:
        if family.startswith(INIT):
            header.append(f'    static void* {m.name}(PolymorphicObject* object);')
            body = [
                '',
                f'void* {family}::{m.name}(PolymorphicObject* object)',
                '{',
                f'    object->table = &TableTarget{m.table:x};',
                '    return object;',
                '}',
            ]
        elif family.startswith(TAIL):
            header.append(f'    static void {m.name}(PolymorphicObject* object);')
            body = [
                '',
                f'void {family}::{m.name}(PolymorphicObject* object)',
                '{',
                f'    object->table = &TableTarget{m.table:x};',
                f'    CleanupTarget{m.cleanup:x}(object);',
                '}',
            ]
        else:
            header.append(f'    static void* {m.name}(PolymorphicObject* object, unsigned int flags);')
            body = [
                '',
                f'void* {family}::{m.name}(PolymorphicObject* object, unsigned int flags)',
                '{',
                f'    object->table = &TableTarget{m.table:x};',
            ]
            if m.cleanup is not None:
                body.append(f'    CleanupTarget{m.cleanup:x}(object);')
            body.extend([
                '    if ((flags & 1u) != 0u)',
                '    {',
                f'        DeallocatorTarget{m.callee:x}(object, {m.object_size}ull);',
                '    }',
                '    return object;',
                '}',
            ])
        source.extend(body)
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
