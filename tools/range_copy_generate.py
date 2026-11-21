"""Draft range-copy wrappers that copy [first, last) to dest and return dest + count.

    python tools/range_copy_generate.py --exe /path/to/SkyrimSE.exe
    python tools/range_copy_generate.py --exe /path/to/SkyrimSE.exe --out .local/range-copy --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information and direct call target for every
generated member.
"""
from dataclasses import dataclass, replace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE


THREE_ARG = 'RangeCopyWrappers'
FOUR_ARG = 'AllocatorRangeCopyWrappers'
SHARD_SIZE = 100


@dataclass(frozen=True)
class Wrapper:
    rva: int
    size: int
    family: str
    callee: int

    @property
    def name(self):
        return f'Copy{self.rva:x}'

    @property
    def symbol(self):
        if self.family.startswith(THREE_ARG):
            return f'?{self.name}@{self.family}@@SAPEAEPEBE0PEAE@Z'
        return f'?{self.name}@{self.family}@@SAPEAEPEAXPEBE1PEAE@Z'


def _has_common_frame(insns):
    from iced_x86 import Code, Register

    return (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP
            and insns[0].memory_displacement == 8 and insns[0].op1_register == Register.RBX and insns[0].len == 5
            and insns[1].code == Code.PUSH_R64 and insns[1].op0_register == Register.RDI and insns[1].len == 1
            and insns[2].code == Code.SUB_RM64_IMM8 and insns[2].op0_register == Register.RSP
            and insns[2].immediate8 == 0x20 and insns[2].len == 4
            and insns[-6].code == Code.CALL_REL32_64 and insns[-6].len == 5
            and insns[-5].code == Code.LEA_R64_M and insns[-5].op0_register == Register.RAX
            and insns[-5].memory_base == Register.RBX and insns[-5].memory_index == Register.RDI
            and insns[-5].memory_index_scale == 1 and insns[-5].memory_displacement == 0 and insns[-5].len == 4
            and insns[-4].code == Code.MOV_R64_RM64 and insns[-4].op0_register == Register.RBX
            and insns[-4].memory_base == Register.RSP and insns[-4].memory_displacement == 0x30 and insns[-4].len == 5
            and insns[-3].code == Code.ADD_RM64_IMM8 and insns[-3].op0_register == Register.RSP
            and insns[-3].immediate8 == 0x20 and insns[-3].len == 4
            and insns[-2].code == Code.POP_R64 and insns[-2].op0_register == Register.RDI and insns[-2].len == 1
            and insns[-1].code == Code.RETNQ and insns[-1].len == 1)


def classify(code, rva):
    from iced_x86 import Code, Decoder, Register

    insns = list(Decoder(64, code, ip=rva))
    if len(insns) not in (14, 15) or any(i.is_invalid for i in insns) or not _has_common_frame(insns):
        return None
    callee = insns[-6].near_branch_target
    if len(insns) == 15:
        if (insns[3].code == Code.MOV_R64_RM64 and insns[3].op0_register == Register.RBX
                and insns[3].op1_register == Register.RDX and insns[3].len == 3
                and insns[4].code == Code.MOV_R64_RM64 and insns[4].op0_register == Register.RDI
                and insns[4].op1_register == Register.R8 and insns[4].len == 3
                and insns[5].code == Code.SUB_R64_RM64 and insns[5].op0_register == Register.RBX
                and insns[5].op1_register == Register.RCX and insns[5].len == 3
                and insns[6].code == Code.MOV_R64_RM64 and insns[6].op0_register == Register.RDX
                and insns[6].op1_register == Register.RCX and insns[6].len == 3
                and insns[7].code == Code.MOV_R64_RM64 and insns[7].op0_register == Register.R8
                and insns[7].op1_register == Register.RBX and insns[7].len == 3
                and insns[8].code == Code.MOV_R64_RM64 and insns[8].op0_register == Register.RCX
                and insns[8].op1_register == Register.RDI and insns[8].len == 3):
            return Wrapper(rva, len(code), THREE_ARG, callee)
        return None
    if (insns[3].code == Code.MOV_R64_RM64 and insns[3].op0_register == Register.RBX
            and insns[3].op1_register == Register.R8 and insns[3].len == 3
            and insns[4].code == Code.MOV_R64_RM64 and insns[4].op0_register == Register.RCX
            and insns[4].op1_register == Register.R9 and insns[4].len == 3
            and insns[5].code == Code.SUB_R64_RM64 and insns[5].op0_register == Register.RBX
            and insns[5].op1_register == Register.RDX and insns[5].len == 3
            and insns[6].code == Code.MOV_R64_RM64 and insns[6].op0_register == Register.RDI
            and insns[6].op1_register == Register.R9 and insns[6].len == 3
            and insns[7].code == Code.MOV_R64_RM64 and insns[7].op0_register == Register.R8
            and insns[7].op1_register == Register.RBX and insns[7].len == 3):
        return Wrapper(rva, len(code), FOUR_ARG, callee)
    return None


def _is_import_thunk(image, address):
    from iced_x86 import Code, Decoder, Register

    try:
        section, code = image.read(address, 6, 'callee thunk')
        if not (section.flags & SCN_MEM_EXECUTE):
            return False
        insns = list(Decoder(64, code, ip=address))
        if len(insns) != 1:
            return False
        jmp = insns[0]
        if (jmp.code != Code.JMP_RM64 or jmp.len != 6 or jmp.memory_base != Register.RIP
                or not jmp.is_ip_rel_memory_operand or jmp.has_segment_prefix):
            return False
        slot = image.section_for(jmp.ip_rel_memory_address)
        return (slot.name == '.rdata' and not (slot.flags & SCN_MEM_EXECUTE)
                and jmp.ip_rel_memory_address + 8 <= slot.vaddr + slot.vsize)
    except Reject:
        return False


def _eligible_callee(image, member, starts):
    if member.rva <= member.callee < member.rva + member.size:
        return False
    return leaf_family_batch.indexed_callee(image, member, starts) or _is_import_thunk(image, member.callee)


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    raw = [m for m in leaf_family_batch.candidates(image, extents, inventory, (45, 48), classify)
           if _eligible_callee(image, m, starts)]
    result = []
    for base in (THREE_ARG, FOUR_ARG):
        rows = [m for m in raw if m.family == base]
        member_rvas = {m.rva for m in rows}
        clean = [m for m in rows if m.callee not in member_rvas]
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
              '// Code origin: original range-copy wrapper template.',
              f'// {family}, methods and callees: GUESS(low) STANDIN; original element types and owners unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    for callee in sorted({m.callee for m in members}):
        name = f'RangeCopyTarget{callee:x}'
        header.append(f'extern "C" void {name}(void* dst, const void* src, unsigned long long count);')
        symbols[name] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    three_arg = family.startswith(THREE_ARG)
    for m in members:
        if three_arg:
            decl = f'static unsigned char* {m.name}(const unsigned char* first, const unsigned char* last, unsigned char* dest);'
            sig = f'unsigned char* {family}::{m.name}(const unsigned char* first, const unsigned char* last, unsigned char* dest)'
            unused = []
        else:
            decl = f'static unsigned char* {m.name}(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest);'
            sig = f'unsigned char* {family}::{m.name}(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)'
            unused = ['    (void)unused;']
        header.append(f'    {decl}')
        source.extend([
            '',
            sig,
            '{',
            *unused,
            '    unsigned long long count = static_cast<unsigned long long>(last - first);',
            f'    RangeCopyTarget{m.callee:x}(dest, first, count);',
            '    return dest + count;',
            '}',
        ])
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
