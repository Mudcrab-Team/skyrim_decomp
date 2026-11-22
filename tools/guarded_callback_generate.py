"""Draft guarded static-callback dispatch and destroy-then-callback wrappers.

    python tools/guarded_callback_generate.py --exe /path/to/SkyrimSE.exe
    python tools/guarded_callback_generate.py --exe /path/to/SkyrimSE.exe --out .local/guarded-callback --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information, static guard/callback addresses and
direct call targets for every generated member.
"""
from dataclasses import dataclass, replace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE


DIRECT = 'GuardedCallbacks'
DESTROY = 'GuardedDestroyCallbacks'
SHARD_SIZE = 100


@dataclass(frozen=True)
class Wrapper:
    rva: int
    size: int
    family: str
    guard: int
    callback: int
    callee: int | None = None

    @property
    def name(self):
        return f'Dispatch{self.rva:x}' if self.callee is None else f'Destroy{self.rva:x}'

    @property
    def symbol(self):
        params = 'PEAX0' if self.callee is None else 'PEAX'
        return f'?{self.name}@{self.family}@@SAX{params}@Z'


def _classify_direct(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 8
            or insns[0].code != Code.CMP_RM64_IMM8 or insns[0].memory_base != Register.RIP
            or not insns[0].is_ip_rel_memory_operand or insns[0].has_segment_prefix
            or insns[0].immediate8 != 0 or insns[0].len != 8
            or insns[1].code != Code.JE_REL8_64 or insns[1].len != 2
            or insns[1].near_branch_target != insns[7].ip
            or insns[2].code != Code.MOV_R64_RM64 or insns[2].op0_register != Register.RAX
            or insns[2].memory_base != Register.RIP or not insns[2].is_ip_rel_memory_operand
            or insns[2].has_segment_prefix or insns[2].len != 7
            or insns[3].code != Code.TEST_RM64_R64 or insns[3].op0_register != Register.RAX
            or insns[3].op1_register != Register.RAX or insns[3].len != 3
            or insns[4].code != Code.JE_REL8_64 or insns[4].len != 2
            or insns[4].near_branch_target != insns[7].ip
            or insns[5].code != Code.MOV_R64_RM64 or insns[5].op0_register != Register.RCX
            or insns[5].op1_register != Register.RDX or insns[5].len != 3
            or insns[6].code != Code.JMP_RM64 or insns[6].op0_register != Register.RAX or insns[6].len != 3
            or insns[7].code != Code.RETNQ or insns[7].len != 1):
        return None
    guard = insns[0].ip_rel_memory_address
    callback = insns[2].ip_rel_memory_address
    if abs(guard - callback) < 8:
        return None
    return Wrapper(rva, size, DIRECT, guard, callback)


def _classify_destroy(insns, rva, size):
    from iced_x86 import Code, Register

    if (len(insns) != 16
            or insns[0].code != Code.TEST_RM64_R64 or insns[0].op0_register != Register.RCX
            or insns[0].op1_register != Register.RCX or insns[0].len != 3
            or insns[1].code != Code.JE_REL8_64 or insns[1].len != 2
            or insns[1].near_branch_target != insns[15].ip
            or insns[2].code != Code.PUSH_R64 or insns[2].op0_register != Register.RBX or insns[2].len != 1
            or insns[3].code != Code.SUB_RM64_IMM8 or insns[3].op0_register != Register.RSP
            or insns[3].immediate8 != 0x20 or insns[3].len != 4
            or insns[4].code != Code.MOV_R64_RM64 or insns[4].op0_register != Register.RBX
            or insns[4].op1_register != Register.RCX or insns[4].len != 3
            or insns[5].code != Code.CALL_REL32_64 or insns[5].len != 5
            or insns[6].code != Code.CMP_RM64_IMM8 or insns[6].memory_base != Register.RIP
            or not insns[6].is_ip_rel_memory_operand or insns[6].has_segment_prefix
            or insns[6].immediate8 != 0 or insns[6].len != 8
            or insns[7].code != Code.JE_REL8_64 or insns[7].len != 2
            or insns[7].near_branch_target != insns[13].ip
            or insns[8].code != Code.MOV_R64_RM64 or insns[8].op0_register != Register.RAX
            or insns[8].memory_base != Register.RIP or not insns[8].is_ip_rel_memory_operand
            or insns[8].has_segment_prefix or insns[8].len != 7
            or insns[9].code != Code.TEST_RM64_R64 or insns[9].op0_register != Register.RAX
            or insns[9].op1_register != Register.RAX or insns[9].len != 3
            or insns[10].code != Code.JE_REL8_64 or insns[10].len != 2
            or insns[10].near_branch_target != insns[13].ip
            or insns[11].code != Code.MOV_R64_RM64 or insns[11].op0_register != Register.RCX
            or insns[11].op1_register != Register.RBX or insns[11].len != 3
            or insns[12].code != Code.CALL_RM64 or insns[12].op0_register != Register.RAX or insns[12].len != 2
            or insns[13].code != Code.ADD_RM64_IMM8 or insns[13].op0_register != Register.RSP
            or insns[13].immediate8 != 0x20 or insns[13].len != 4
            or insns[14].code != Code.POP_R64 or insns[14].op0_register != Register.RBX or insns[14].len != 1
            or insns[15].code != Code.RETNQ or insns[15].len != 1):
        return None
    guard = insns[6].ip_rel_memory_address
    callback = insns[8].ip_rel_memory_address
    if abs(guard - callback) < 8:
        return None
    return Wrapper(rva, size, DESTROY, guard, callback, insns[5].near_branch_target)


def classify(code, rva):
    from iced_x86 import Decoder

    insns = list(Decoder(64, code, ip=rva))
    if any(i.is_invalid for i in insns):
        return None
    if len(code) == 29:
        return _classify_direct(insns, rva, len(code))
    if len(code) == 51:
        return _classify_destroy(insns, rva, len(code))
    return None


def _eligible_data_qword(image, address):
    try:
        section = image.section_for(address)
        return (section.name == '.data'
                and not (section.flags & SCN_MEM_EXECUTE)
                and bool(section.flags & 0x80000000)
                and address % 8 == 0
                and address + 8 <= section.vaddr + section.vsize)
    except Reject:
        return False


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    raw = []
    for m in leaf_family_batch.candidates(image, extents, inventory, (29, 51), classify):
        if not (_eligible_data_qword(image, m.guard) and _eligible_data_qword(image, m.callback)):
            continue
        if m.callee is not None and not leaf_family_batch.indexed_callee(image, m, starts):
            continue
        raw.append(m)
    result = []
    for base in (DIRECT, DESTROY):
        rows = [m for m in raw if m.family == base]
        member_rvas = {m.rva for m in rows}
        guards = {m.guard for m in rows}
        callbacks = {m.callback for m in rows}
        clean = [m for m in rows
                 if m.guard not in callbacks and m.callback not in guards
                 and (m.callee is None or m.callee not in member_rvas)]
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
              '// Code origin: original guarded static-callback wrapper template.',
              f'// {family}, methods and referenced symbols: GUESS(low) STANDIN; original owners and signatures unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '', 'typedef void (*GuardedCallbackFn)(void*);', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    symbols = {}
    for guard in sorted({m.guard for m in members}):
        name = f'CallbackGuard{guard:x}'
        header.append(f'extern "C" unsigned long long {name};')
        symbols[name] = dict(rva=guard, size=None)
    for callback in sorted({m.callback for m in members}):
        name = f'CallbackSlot{callback:x}'
        header.append(f'extern "C" GuardedCallbackFn {name};')
        symbols[name] = dict(rva=callback, size=None)
    for callee in sorted({m.callee for m in members if m.callee is not None}):
        name = f'CleanupTarget{callee:x}'
        header.append(f'extern "C" void {name}(void* object);')
        symbols[name] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    functions = []
    for m in members:
        if m.callee is None:
            header.append(f'    static void {m.name}(void* unused, void* argument);')
            body = [
                '',
                f'void {family}::{m.name}(void* unused, void* argument)',
                '{',
                '    (void)unused;',
                f'    if (CallbackGuard{m.guard:x} != 0 && CallbackSlot{m.callback:x} != nullptr)',
                '    {',
                f'        CallbackSlot{m.callback:x}(argument);',
                '    }',
                '}',
            ]
        else:
            header.append(f'    static void {m.name}(void* object);')
            body = [
                '',
                f'void {family}::{m.name}(void* object)',
                '{',
                '    if (object != nullptr)',
                '    {',
                f'        CleanupTarget{m.callee:x}(object);',
                f'        if (CallbackGuard{m.guard:x} != 0 && CallbackSlot{m.callback:x} != nullptr)',
                '        {',
                f'            CallbackSlot{m.callback:x}(object);',
                '        }',
                '    }',
                '}',
            ]
        source.extend(body)
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
