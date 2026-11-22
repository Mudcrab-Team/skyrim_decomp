"""Draft conditional sized deallocators and cleanup-then-deallocate wrappers.

    python tools/conditional_dealloc_generate.py --exe /path/to/SkyrimSE.exe
    python tools/conditional_dealloc_generate.py --exe /path/to/SkyrimSE.exe --out .local/conditional-dealloc --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information and direct call targets for every
generated member.
"""
from dataclasses import dataclass, replace

import leaf_family_batch


DIRECT = 'ConditionalDeallocators'
CLEANUP = 'CleanupDeallocators'
SHARD_SIZE = 100


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    family: str
    object_size: int
    callee: int
    cleanup: int | None = None

    @property
    def name(self):
        return f'Delete{self.rva:x}'

    @property
    def symbol(self):
        return f'?{self.name}@{self.family}@@SAPEAXPEAXI@Z'


def _classify_direct(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 11
            or insns[0].code != Code.PUSH_R64 or insns[0].op0_register != Register.RBX or insns[0].len != 2
            or insns[1].code != Code.SUB_RM64_IMM8 or insns[1].op0_register != Register.RSP
            or insns[1].immediate8 != 0x20 or insns[1].len != 4
            or insns[2].code != Code.MOV_R64_RM64 or insns[2].op0_register != Register.RBX
            or insns[2].op1_register != Register.RCX or insns[2].len != 3
            or insns[3].code != Code.TEST_RM8_IMM8 or insns[3].op0_register != Register.DL
            or insns[3].immediate8 != 1 or insns[3].len != 3
            or insns[4].code != Code.JE_REL8_64 or insns[4].len != 2
            or insns[4].near_branch_target != insns[7].ip
            or insns[5].code != Code.MOV_R32_IMM32 or insns[5].op0_register != Register.EDX
            or insns[5].len != 5 or insns[5].immediate32 == 0
            or insns[6].code != Code.CALL_REL32_64 or insns[6].len != 5
            or insns[7].code != Code.MOV_R64_RM64 or insns[7].op0_register != Register.RAX
            or insns[7].op1_register != Register.RBX or insns[7].len != 3
            or insns[8].code != Code.ADD_RM64_IMM8 or insns[8].op0_register != Register.RSP
            or insns[8].immediate8 != 0x20 or insns[8].len != 4
            or insns[9].code != Code.POP_R64 or insns[9].op0_register != Register.RBX or insns[9].len != 1
            or insns[10].code != Code.RETNQ or insns[10].len != 1):
        return None
    return Member(rva, size, DIRECT, insns[5].immediate32, insns[6].near_branch_target)


def _classify_cleanup(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 16
            or insns[0].code != Code.MOV_RM64_R64 or insns[0].memory_base != Register.RSP
            or insns[0].memory_displacement != 8 or insns[0].op1_register != Register.RBX or insns[0].len != 5
            or insns[1].code != Code.PUSH_R64 or insns[1].op0_register != Register.RDI or insns[1].len != 1
            or insns[2].code != Code.SUB_RM64_IMM8 or insns[2].op0_register != Register.RSP
            or insns[2].immediate8 != 0x20 or insns[2].len != 4
            or insns[3].code != Code.MOV_R32_RM32 or insns[3].op0_register != Register.EBX
            or insns[3].op1_register != Register.EDX or insns[3].len != 2
            or insns[4].code != Code.MOV_R64_RM64 or insns[4].op0_register != Register.RDI
            or insns[4].op1_register != Register.RCX or insns[4].len != 3
            or insns[5].code != Code.CALL_REL32_64 or insns[5].len != 5
            or insns[6].code != Code.TEST_RM8_IMM8 or insns[6].op0_register != Register.BL
            or insns[6].immediate8 != 1 or insns[6].len != 3
            or insns[7].code != Code.JE_REL8_64 or insns[7].len != 2
            or insns[7].near_branch_target != insns[11].ip
            or insns[8].code != Code.MOV_R32_IMM32 or insns[8].op0_register != Register.EDX
            or insns[8].len != 5 or insns[8].immediate32 == 0
            or insns[9].code != Code.MOV_R64_RM64 or insns[9].op0_register != Register.RCX
            or insns[9].op1_register != Register.RDI or insns[9].len != 3
            or insns[10].code != Code.CALL_REL32_64 or insns[10].len != 5
            or insns[11].code != Code.MOV_R64_RM64 or insns[11].op0_register != Register.RBX
            or insns[11].memory_base != Register.RSP or insns[11].memory_displacement != 0x30 or insns[11].len != 5
            or insns[12].code != Code.MOV_R64_RM64 or insns[12].op0_register != Register.RAX
            or insns[12].op1_register != Register.RDI or insns[12].len != 3
            or insns[13].code != Code.ADD_RM64_IMM8 or insns[13].op0_register != Register.RSP
            or insns[13].immediate8 != 0x20 or insns[13].len != 4
            or insns[14].code != Code.POP_R64 or insns[14].op0_register != Register.RDI or insns[14].len != 1
            or insns[15].code != Code.RETNQ or insns[15].len != 1):
        return None
    cleanup = insns[5].near_branch_target
    dealloc = insns[10].near_branch_target
    if cleanup == dealloc:
        return None
    return Member(rva, size, CLEANUP, insns[8].immediate32, dealloc, cleanup)


def classify(code, rva):
    from iced_x86 import Decoder

    insns = list(Decoder(64, code, ip=rva))
    if any(i.is_invalid for i in insns):
        return None
    if len(code) == 33:
        return _classify_direct(insns, rva, len(code))
    if len(code) == 52:
        return _classify_cleanup(insns, rva, len(code))
    return None


def _indexed_target(image, member, target, starts):
    return leaf_family_batch.indexed_callee(image, replace(member, callee=target), starts)


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    raw = []
    for m in leaf_family_batch.candidates(image, extents, inventory, (33, 52), classify):
        if not leaf_family_batch.indexed_callee(image, m, starts):
            continue
        if m.cleanup is not None and not _indexed_target(image, m, m.cleanup, starts):
            continue
        raw.append(m)
    # Keep each base family free of internal member-to-member references and
    # conflicting cleanup/deallocator declarations, then shard to stay under
    # contributor file-size and per-PR function caps.
    result = []
    for base in (DIRECT, CLEANUP):
        rows = [m for m in raw if m.family == base]
        member_rvas = {m.rva for m in rows}
        deallocs = {m.callee for m in rows}
        clean = [m for m in rows
                 if m.callee not in member_rvas
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
              '// Code origin: original conditional sized-deallocator template.',
              f'// {family}, methods and callees: GUESS(low) STANDIN; original ownership and layouts unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    for cleanup in sorted({m.cleanup for m in members if m.cleanup is not None}):
        name = f'CleanupTarget{cleanup:x}'
        header.append(f'extern "C" void {name}(void* object);')
        symbols[name] = dict(rva=cleanup, size=None)
    for dealloc in sorted({m.callee for m in members}):
        name = f'DeallocatorTarget{dealloc:x}'
        header.append(f'extern "C" void {name}(void* object, unsigned long long size);')
        symbols[name] = dict(rva=dealloc, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    for m in members:
        header.append(f'    static void* {m.name}(void* object, unsigned int flags);')
        body = ['', f'void* {family}::{m.name}(void* object, unsigned int flags)', '{']
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
