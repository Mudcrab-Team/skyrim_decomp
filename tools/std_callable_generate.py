"""Draft std::function implementation slots over small callables from one template.

    python tools/std_callable_generate.py --exe /path/to/SkyrimSE.exe
    python tools/std_callable_generate.py --exe /path/to/SkyrimSE.exe --out .local/std-callable --compare
    python tools/std_callable_generate.py --exe /path/to/SkyrimSE.exe --only rvas.txt --out .local/std-callable-test --compare

Copy and move slots of empty, pointer-sized and two-word callables, plus sized-delete slots of
trivially destructible callables, are emitted from `std::_Func_impl_no_alloc<Callable, void>`. Every member is one explicit instantiation over a stand-in callable derived from the single template
in the unit header.
Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and checks the full code,
unwind information, the table reference and the delete call target for every member. `--only` takes a
file of whitespace-separated hexadecimal RVAs and keeps only those members (a private selection, never
committed).
"""
from dataclasses import dataclass, replace
import struct

import leaf_family_batch
from form_factory_generate import data, type_name
from pecoff import Reject, SCN_MEM_EXECUTE

COPY = 'StdCallableCopyMove'
EMPTY_COPY = 'StdEmptyCallableCopyMove'
SCALAR_COPY = 'StdScalarCallableCopyMove'
DELETE = 'StdCallableDeleteThis'
SHARD_SIZE = 100
OPERATOR_DELETE = '??3@YAXPEAX_K@Z'
COPY_SIZE = 22
EMPTY_COPY_SIZE = 14
SCALAR_COPY_SIZE = 30
DELETE_SIZE = 15

TEMPLATE = [
    '// Stand-in callable: Bytes of stored state and a call operator that is never reached.',
    'template <unsigned long long Bytes>',
    'struct StdCallableState',
    '{',
    '    alignas(8) unsigned char state[Bytes];',
    '    void operator()() const {}',
    '};',
]


SCALAR_TEMPLATE = [
    'struct SplitCallableState',
    '{',
    '    void* first;',
    '    unsigned long long second;',
    '',
    '    SplitCallableState() = default;',
    '    SplitCallableState(const SplitCallableState& other) noexcept : first(other.first), second(other.second) {}',
    '    SplitCallableState(SplitCallableState&& other) noexcept : first(other.first), second(other.second) {}',
    '    void operator()() const {}',
    '};',
]


@dataclass(frozen=True)
class Slot:
    rva: int
    size: int
    family: str
    kind: str          # 'copy', 'move' or 'delete'
    table: int = 0     # read-only table address of the owner, copy and move only
    object_size: int = 0
    callee: int = 0
    state: int = 8     # callable storage copied or moved: none, one pointer, or sixteen bytes

    @property
    def callable(self):
        if self.kind == 'delete':
            return f'CallableObject{self.rva:x}'
        return f'CallableTable{self.table:x}'

    @property
    def bytes(self):
        return self.object_size - 8 if self.kind == 'delete' else self.state

    @property
    def table_symbol(self):
        return f'??_7?$_Func_impl_no_alloc@U{self.callable}@@X$$V@std@@6B@'

    @property
    def symbol(self):
        owner = f'?$_Func_impl_no_alloc@U{self.callable}@@X$$V@std@@'
        if self.kind == 'copy':
            return f'?_Copy@{owner}EEBAPEAV?$_Func_base@X$$V@2@PEAX@Z'
        if self.kind == 'move':
            return f'?_Move@{owner}EEAAPEAV?$_Func_base@X$$V@2@PEAX@Z'
        return f'?_Delete_this@{owner}EEAAX_N@Z'

    @property
    def method(self):
        return {'copy': '_Copy', 'move': '_Move', 'delete': '_Delete_this'}[self.kind]


def _table_store(lea, store):
    """`lea rax, [rip + table]` then `mov [rdx], rax`."""
    from iced_x86 import Code, Register

    return (lea.code == Code.LEA_R64_M and lea.op0_register == Register.RAX and lea.memory_base == Register.RIP
            and lea.len == 7
            and store.code == Code.MOV_RM64_R64 and store.memory_base == Register.RDX
            and store.memory_displacement == 0 and store.memory_index == Register.NONE
            and store.op1_register == Register.RAX and store.len == 3)


def _return_destination(insn):
    from iced_x86 import Code, Register

    return (insn.code == Code.MOV_R64_RM64 and insn.op0_register == Register.RAX
            and insn.op1_register == Register.RDX and insn.len == 3)


def _copy_word(load, store, offset):
    from iced_x86 import Code, Register

    return (load.code == Code.MOV_R64_RM64 and store.code == Code.MOV_RM64_R64
            and load.memory_base == Register.RCX and store.memory_base == Register.RDX
            and load.memory_index == store.memory_index == Register.NONE
            and load.memory_displacement == store.memory_displacement == offset
            and load.op0_register == store.op1_register
            and load.op0_register not in (Register.RCX, Register.RDX)
            and load.len == store.len == 4)


def classify(code, rva):
    from iced_x86 import Code, Decoder, Register

    insns = list(Decoder(64, code, ip=rva))
    if any(i.is_invalid for i in insns):
        return None
    if (len(insns) == 4 and len(code) == EMPTY_COPY_SIZE and _table_store(insns[0], insns[1])
            and _return_destination(insns[2]) and insns[3].code == Code.RETNQ):
        return Slot(rva, len(code), EMPTY_COPY, 'copy', table=insns[0].ip_rel_memory_address, state=0)
    if (len(insns) == 8 and len(code) == SCALAR_COPY_SIZE and _table_store(insns[0], insns[1])
            and _copy_word(insns[2], insns[3], 8) and _copy_word(insns[4], insns[5], 16)
            and _return_destination(insns[6]) and insns[7].code == Code.RETNQ):
        return Slot(rva, len(code), SCALAR_COPY, 'copy', table=insns[0].ip_rel_memory_address, state=16)
    if len(insns) == 6 and len(code) == COPY_SIZE and _table_store(insns[0], insns[1]):
        lea, _store_table, third, fourth, fifth, ret = insns
        if (third.code == Code.MOV_R64_RM64 and third.op0_register == Register.RAX
                and third.memory_base == Register.RCX and third.memory_displacement == 8
                and third.memory_index == Register.NONE and third.len == 4
                and fourth.code == Code.MOV_RM64_R64 and fourth.memory_base == Register.RDX
                and fourth.memory_displacement == 8 and fourth.memory_index == Register.NONE
                and fourth.op1_register == Register.RAX and fourth.len == 4
                and _return_destination(fifth) and ret.code == Code.RETNQ and ret.len == 1):
            return Slot(rva, len(code), COPY, 'copy', table=lea.ip_rel_memory_address, state=8)
        if (_return_destination(third)
                and fourth.code == Code.MOVUPS_XMM_XMMM128 and fourth.op0_register == Register.XMM0
                and fourth.memory_base == Register.RCX and fourth.memory_displacement == 8
                and fourth.memory_index == Register.NONE and fourth.len == 4
                and fifth.code == Code.MOVUPS_XMMM128_XMM and fifth.memory_base == Register.RDX
                and fifth.memory_displacement == 8 and fifth.memory_index == Register.NONE
                and fifth.op1_register == Register.XMM0 and fifth.len == 4
                and ret.code == Code.RETNQ and ret.len == 1):
            return Slot(rva, len(code), COPY, 'copy', table=lea.ip_rel_memory_address, state=16)
        return None
    if len(insns) == 5 and len(code) == DELETE_SIZE:
        test, skip, size, jump, ret = insns
        if (test.code == Code.TEST_RM8_R8 and test.op0_register == Register.DL and test.op1_register == Register.DL
                and test.len == 2
                and skip.code == Code.JE_REL8_64 and skip.len == 2 and skip.near_branch_target == ret.ip
                and size.code == Code.MOV_R32_IMM32 and size.op0_register == Register.EDX and size.len == 5
                and size.immediate32 > 8 and size.immediate32 % 8 == 0
                and jump.code == Code.JMP_REL32_64 and jump.len == 5
                and ret.code == Code.RETNQ and ret.len == 1):
            return Slot(rva, len(code), DELETE, 'delete', object_size=size.immediate32,
                        callee=jump.near_branch_target)
    return None


def _owner_slot(image, member):
    """0 for the first and 1 for the second table entry that names this member, else None."""
    try:
        section, blob = image.read(member.table, 16, 'owner table')
    except Reject:
        return None
    if section.flags & SCN_MEM_EXECUTE:
        return None
    for index in (0, 1):
        pointer = int.from_bytes(blob[8 * index:8 * index + 8], 'little')
        if pointer == image.image_base + member.rva:
            return index
    return None


def _standard_callable_owner(image, member):
    """Require the standard implementation's primary vftable for additional copy shapes."""
    try:
        locator = int.from_bytes(data(image, member.table - 8, 8), 'little') - image.image_base
        signature, offset, construction_offset, descriptor, _, self_rva = struct.unpack(
            '<6I', data(image, locator, 24))
        if (signature, offset, construction_offset, self_rva) != (1, 0, 0, locator):
            return False
        name = type_name(image, descriptor)
        return name.startswith('?$_Func_impl_no_alloc@') and name.endswith('@std@@')
    except (Reject, ValueError):
        return False


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    raw = list(leaf_family_batch.candidates(image, extents, inventory, (COPY_SIZE, EMPTY_COPY_SIZE, SCALAR_COPY_SIZE, DELETE_SIZE), classify))
    members = []
    for m in raw:
        if m.kind == 'delete':
            if leaf_family_batch.indexed_callee(image, m, starts):
                members.append(m)
            continue
        index = _owner_slot(image, m)
        if index is not None and (m.family == COPY or _standard_callable_owner(image, m)):
            members.append(replace(m, kind=('copy', 'move')[index]))
    result = []
    for base in (COPY, EMPTY_COPY, SCALAR_COPY, DELETE):
        rows = sorted((m for m in members if m.family == base), key=lambda m: (m.table, m.rva))
        if base != DELETE:
            groups = {}
            for m in rows:
                groups.setdefault(m.table, []).append(m)
            batches, current = [], []
            for table_rows in groups.values():
                if current and len(current) + len(table_rows) > SHARD_SIZE:
                    batches.append(current)
                    current = []
                current.extend(table_rows)
            if current:
                batches.append(current)
        else:
            batches = [rows[i:i + SHARD_SIZE] for i in range(0, len(rows), SHARD_SIZE)]
        if len(batches) == 1:
            result.extend(batches[0])
        else:
            for number, batch in enumerate(batches, 1):
                result.extend(replace(m, family=f'{base}{number}') for m in batch)
    return result


def emit(root, family, members, build_id, label):
    prefix = ['// Source exposure: mixed (pinned image and published community function boundaries).',
              f'// Boundary source: {label}',
              '// Template from the compiler\'s standard headers; the source is our own instantiation.',
              '// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.',
              '// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED',
              f'// {family}, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.',
              '// Adapted bodies: none']
    storage = SCALAR_TEMPLATE if family.startswith(SCALAR_COPY) else TEMPLATE
    if family.startswith(EMPTY_COPY):
        storage = ()
    header = prefix + ['#pragma once', '#include <functional>', '', *storage, '', f'struct {family}', '{', '};']
    source = list(prefix)
    for m in members:
        source.append(f'// 0x{m.rva:x} std::_Func_impl_no_alloc<{m.callable}, void>::{m.method}')
    for m in members:
        source.append(f'// CI hash: 0x{m.rva:x} {m.symbol}')
    source += [f'#include "{family}.h"', '']
    symbols, functions, seen = {}, [], set()
    for m in members:
        if m.kind == 'delete':
            symbols[OPERATOR_DELETE] = dict(rva=m.callee, size=None)
        else:
            symbols[m.table_symbol] = dict(rva=m.table, size=None)
        if m.callable not in seen:
            seen.add(m.callable)
            if family.startswith(SCALAR_COPY):
                source.append(f'struct {m.callable} : SplitCallableState {{}};')
            elif m.bytes:
                source.append(f'struct {m.callable} : StdCallableState<{m.bytes}> {{}};')
            else:
                source.extend([f'struct {m.callable}', '{', '    void operator()() const {}', '};'])
            source.append(f'template class std::_Func_impl_no_alloc<{m.callable}, void>;')
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions, area='std')


if __name__ == '__main__':
    raise SystemExit(leaf_family_batch.run(__doc__, discover, emit))
