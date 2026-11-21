"""Draft wrappers that forward the first argument and fix the second unsigned integer.

    python tools/fixed_argument_generate.py --exe /path/to/SkyrimSE.exe
    python tools/fixed_argument_generate.py --exe /path/to/SkyrimSE.exe --out .local/fixed-argument --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, including the direct jump target, for every generated member.
"""
from dataclasses import dataclass

import leaf_family_batch


@dataclass(frozen=True)
class Wrapper:
    rva: int
    size: int
    value: int
    callee: int
    family = 'FixedArgumentWrappers'

    @property
    def name(self):
        return f'Invoke{self.rva:x}'

    @property
    def symbol(self):
        return f'?{self.name}@{self.family}@@SAXPEAX@Z'


def classify(code, rva):
    from iced_x86 import Code, Decoder, Mnemonic, Register

    instructions = list(Decoder(64, code, ip=rva))
    if len(instructions) != 2:
        return None
    setup, jump = instructions
    if jump.code != Code.JMP_REL32_64 or jump.len != 5 or setup.op0_register != Register.EDX:
        return None
    if setup.code == Code.MOV_R32_IMM32 and setup.len == 5:
        value = setup.immediate32
    elif setup.mnemonic == Mnemonic.XOR and setup.op1_register == Register.EDX and setup.len == 2:
        value = 0
    else:
        return None
    return Wrapper(rva, len(code), value, jump.near_branch_target)


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    members = [m for m in leaf_family_batch.candidates(image, extents, inventory, (7, 10), classify)
               if leaf_family_batch.indexed_callee(image, m, starts)]
    # An emitted wrapper has one declared parameter. Its RVA cannot also be
    # declared as an external two-parameter callee in this translation unit.
    wrapper_starts = {m.rva for m in members}
    return [m for m in members if m.callee not in wrapper_starts]


def emit(root, family, members, build_id, label):
    prefix = ['// Source exposure: mixed (pinned image and community function boundaries).',
              f'// Boundary source: {label}',
              '// Code origin: original fixed-argument wrapper template.',
              f'// {family}, methods and callees: GUESS(low) STANDIN; original signatures unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    for callee in sorted({m.callee for m in members}):
        name = f'FixedArgumentTarget{callee:x}'
        header.append(f'extern "C" void {name}(void* context, unsigned int value);')
        symbols[name] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    for m in members:
        header.append(f'    static void {m.name}(void* context);')
        source.extend(['', f'void {family}::{m.name}(void* context)', '{',
                       f'    FixedArgumentTarget{m.callee:x}(context, {m.value}u);', '}'])
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
