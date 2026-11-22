"""Discover and draft two static-data leaf families on the pinned local image.

    python tools/static_data_generate.py --exe /path/to/SkyrimSE.exe
    python tools/static_data_generate.py --exe /path/to/SkyrimSE.exe --out .local/static-data

Requires iced-x86==1.21.0. Without --out only counts are printed. The private
snapshot contains C++ units, verifier tasks and per-reference address bindings.
Add --compare to compile each unit with the contributor toolchain and compare
every member locally. Community boundaries and guessed signatures are hypotheses.
"""
from collections import defaultdict
from dataclasses import dataclass

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE


READERS = 'StaticDataReaders'
WRAPPERS = 'StaticObjectWrappers'


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    data: int
    width: int
    storage_type: str
    result_type: str
    callee: int | None = None

    @property
    def family(self):
        return READERS if self.callee is None else WRAPPERS

    @property
    def name(self):
        verb = 'Read' if self.callee is None else 'Invoke'
        return f'{verb}Static{self.rva:x}'

    @property
    def symbol(self):
        result = {'unsigned int': 'I', 'unsigned long long': '_K', 'float': 'M', 'double': 'N', 'void': 'X'}
        return f'?{self.name}@{self.family}@@SA{result[self.result_type]}XZ'


def classify(code, rva):
    from iced_x86 import Code, Decoder, Register

    instructions = list(Decoder(64, code, ip=rva))
    if len(instructions) != 2:
        return None
    load, end = instructions
    if load.memory_base != Register.RIP or not load.is_ip_rel_memory_operand or load.has_segment_prefix:
        return None
    if (load.code == Code.LEA_R64_M and load.op0_register == Register.RCX and load.len == 7
            and end.code == Code.JMP_REL32_64 and end.len == 5):
        return Member(rva, len(code), load.ip_rel_memory_address, 1, 'StaticStorage', 'void',
                      end.near_branch_target)
    if end.code != Code.RETNQ or end.len != 1:
        return None
    # The memory type describes the load. A zero-extending load returns an unsigned int.
    forms = {
        (Code.MOVZX_R32_RM8, Register.EAX, 7): (1, 'unsigned char', 'unsigned int'),
        (Code.MOVZX_R32_RM16, Register.EAX, 7): (2, 'unsigned short', 'unsigned int'),
        (Code.MOV_R32_RM32, Register.EAX, 6): (4, 'unsigned int', 'unsigned int'),
        (Code.MOV_R64_RM64, Register.RAX, 7): (8, 'unsigned long long', 'unsigned long long'),
        (Code.MOVSS_XMM_XMMM32, Register.XMM0, 8): (4, 'float', 'float'),
        (Code.MOVSD_XMM_XMMM64, Register.XMM0, 8): (8, 'double', 'double'),
    }
    form = forms.get((load.code, load.op0_register, load.len))
    if form:
        return Member(rva, len(code), load.ip_rel_memory_address, *form)
    return None


def eligible_target(image, member, starts):
    try:
        data = image.section_for(member.data)
        if (data.name != '.data' or data.flags & SCN_MEM_EXECUTE or not data.flags & 0x80000000
                or member.data + member.width > data.vaddr + data.vsize or member.data % member.width):
            return False
        if member.callee is not None:
            return leaf_family_batch.indexed_callee(image, member, starts)
        return True
    except Reject:
        return False


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    candidates = [m for m in leaf_family_batch.candidates(image, extents, inventory, (7, 8, 9, 12), classify)
                  if eligible_target(image, m, starts)]
    # Avoid declaring the same storage as incompatible objects, including partial overlaps.
    views = defaultdict(set)
    for m in candidates:
        for addr in range(m.data, m.data + m.width):
            views[addr].add((m.data, m.storage_type))
    return [m for m in candidates if all(len(views[addr]) == 1 for addr in range(m.data, m.data + m.width))]


def emit(root, family, members, build_id, label):
    """Write one translation unit and a standard local task for this family."""
    prefix = ['// Source exposure: mixed (pinned image and community function boundaries).',
              f'// Boundary source: {label}',
              '// Code origin: original static-data template.',
              f'// {family}, methods and referenced symbols: GUESS(low) STANDIN; ownership and signatures unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    if family == WRAPPERS:
        header.append('struct StaticStorage;')
    symbols = {}
    for addr, typ in sorted({(m.data, m.storage_type) for m in members}):
        header.append(f'extern "C" {typ} StaticData{addr:x};')
        symbols[f'StaticData{addr:x}'] = dict(rva=addr, size=None)
    for callee in sorted({m.callee for m in members if m.callee is not None}):
        header.append(f'extern "C" void CallStatic{callee:x}(StaticStorage*);')
        symbols[f'CallStatic{callee:x}'] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    functions = []
    for m in members:
        header.append(f'    static {m.result_type} {m.name}();')
        signature = f'{m.result_type} {family}::{m.name}()'
        body = (f'return StaticData{m.data:x};' if m.callee is None
                else f'CallStatic{m.callee:x}(&StaticData{m.data:x});')
        source.extend(['', signature, '{', f'    {body}', '}'])
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


def main():
    return leaf_family_batch.run(__doc__, discover, emit)


if __name__ == '__main__':
    raise SystemExit(main())
