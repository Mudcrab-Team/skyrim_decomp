"""Draft wrappers that call another entry and return a preserved pointer argument.

    python tools/return_argument_generate.py --exe /path/to/SkyrimSE.exe
    python tools/return_argument_generate.py --exe /path/to/SkyrimSE.exe --out .local/return-argument --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information and direct call target for every
generated member.
"""
from dataclasses import dataclass

import leaf_family_batch


RETURN_FIRST = 'ReturnFirstWrappers'
RETURN_SECOND = 'ReturnSecondWrappers'
RETURN_FIRST_CONSTANT = 'ReturnFirstConstantWrappers'


@dataclass(frozen=True)
class Wrapper:
    rva: int
    size: int
    family: str
    callee: int
    value: int | None = None

    @property
    def name(self):
        return f'Invoke{self.rva:x}'

    @property
    def symbol(self):
        params = 'PEAX' if self.family == RETURN_FIRST else 'PEAX0'
        return f'?{self.name}@{self.family}@@SAPEAX{params}@Z'


def classify(code, rva):
    from iced_x86 import Code, Decoder, Register

    insns = list(Decoder(64, code, ip=rva))
    if len(insns) not in (8, 10) or any(i.is_invalid for i in insns):
        return None
    if (insns[0].code != Code.PUSH_R64 or insns[0].op0_register != Register.RBX or insns[0].len != 2
            or insns[1].code != Code.SUB_RM64_IMM8 or insns[1].op0_register != Register.RSP
            or insns[1].immediate8 != 0x20 or insns[1].len != 4
            or insns[-5].code != Code.CALL_REL32_64 or insns[-5].len != 5
            or insns[-4].code != Code.MOV_R64_RM64 or insns[-4].op0_register != Register.RAX
            or insns[-4].op1_register != Register.RBX or insns[-4].len != 3
            or insns[-3].code != Code.ADD_RM64_IMM8 or insns[-3].op0_register != Register.RSP
            or insns[-3].immediate8 != 0x20 or insns[-3].len != 4
            or insns[-2].code != Code.POP_R64 or insns[-2].op0_register != Register.RBX or insns[-2].len != 1
            or insns[-1].code != Code.RETNQ or insns[-1].len != 1):
        return None
    callee = insns[-5].near_branch_target
    mid = insns[2:-5]
    if len(mid) == 1:
        save = mid[0]
        if save.code == Code.MOV_R64_RM64 and save.op0_register == Register.RBX and save.len == 3:
            if save.op1_register == Register.RCX:
                return Wrapper(rva, len(code), RETURN_FIRST, callee)
            if save.op1_register == Register.RDX:
                return Wrapper(rva, len(code), RETURN_SECOND, callee)
        return None
    move_r8, save, load_imm = mid
    if (move_r8.code == Code.MOV_R64_RM64 and move_r8.op0_register == Register.R8
            and move_r8.op1_register == Register.RDX and move_r8.len == 3
            and save.code == Code.MOV_R64_RM64 and save.op0_register == Register.RBX
            and save.op1_register == Register.RCX and save.len == 3
            and load_imm.code == Code.MOV_R64_IMM64 and load_imm.op0_register == Register.RDX
            and load_imm.len == 10 and 0x100000000 <= load_imm.immediate64 <= 0xffffffff7fffffff):
        return Wrapper(rva, len(code), RETURN_FIRST_CONSTANT, callee, load_imm.immediate64)
    return None


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    members = [m for m in leaf_family_batch.candidates(image, extents, inventory, (23, 36), classify)
               if leaf_family_batch.indexed_callee(image, m, starts)]
    # A member's RVA cannot also be declared as an external callee inside the same unit.
    by_family = {family: {m.rva for m in members if m.family == family}
                 for family in {m.family for m in members}}
    return [m for m in members if m.callee not in by_family[m.family]]


def emit(root, family, members, build_id, label):
    prefix = ['// Source exposure: mixed (pinned image and community function boundaries).',
              f'// Boundary source: {label}',
              '// Code origin: original argument-returning wrapper template.',
              f'// {family}, methods and callees: GUESS(low) STANDIN; original signatures unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    callee_prefix = {
        RETURN_FIRST: ('ReturnFirstTarget', 'void* first'),
        RETURN_SECOND: ('ReturnSecondTarget', 'void* first, void* second'),
        RETURN_FIRST_CONSTANT: ('ReturnFirstConstantTarget', 'void* first, unsigned long long value, void* second'),
    }[family]
    target_prefix, target_params = callee_prefix
    for callee in sorted({m.callee for m in members}):
        name = f'{target_prefix}{callee:x}'
        header.append(f'extern "C" void {name}({target_params});')
        symbols[name] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    for m in members:
        if family == RETURN_FIRST:
            decl = f'static void* {m.name}(void* first);'
            sig = f'void* {family}::{m.name}(void* first)'
            call = f'{target_prefix}{m.callee:x}(first);'
            ret = 'return first;'
        elif family == RETURN_SECOND:
            decl = f'static void* {m.name}(void* first, void* second);'
            sig = f'void* {family}::{m.name}(void* first, void* second)'
            call = f'{target_prefix}{m.callee:x}(first, second);'
            ret = 'return second;'
        else:
            decl = f'static void* {m.name}(void* first, void* second);'
            sig = f'void* {family}::{m.name}(void* first, void* second)'
            call = f'{target_prefix}{m.callee:x}(first, 0x{m.value:x}ull, second);'
            ret = 'return first;'
        header.append(f'    {decl}')
        source.extend(['', sig, '{', f'    {call}', f'    {ret}', '}'])
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
