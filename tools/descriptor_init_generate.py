"""Draft static reflection descriptor initializers (class descriptor calls and 6-field type-info records).

    python tools/descriptor_init_generate.py --exe /path/to/SkyrimSE.exe
    python tools/descriptor_init_generate.py --exe /path/to/SkyrimSE.exe --out .local/descriptor-inits --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information, static storage references and direct
call targets for every generated member.
"""
import bisect
from dataclasses import dataclass, replace
from types import SimpleNamespace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE

SCN_MEM_WRITE = 0x80000000

CLASS_DESC_INIT = 'ClassDescriptorInitializers'
TYPEINFO_DESC_INIT = 'TypeInfoDescriptorInitializers'

BASE_FAMILIES = (
    CLASS_DESC_INIT,
    TYPEINFO_DESC_INIT,
)

SHARD_SIZE = 50
CANDIDATE_SIZES = range(72, 160)

# Slot widths for the 10 stack arguments at [rsp+0x20] .. [rsp+0x68] of a 14-arg descriptor init call.
# True = 64-bit pointer (RIP target or nullptr), False = 32-bit integer immediate.
_STACK_SLOT_IS_PTR = {
    0x20: True,   # interfaces
    0x28: False,  # numInterfaces
    0x30: True,   # enums
    0x38: False,  # numEnums
    0x40: True,   # members
    0x48: False,  # numMembers
    0x50: True,   # defaults
    0x58: True,   # attributes
    0x60: False,  # flags
    0x68: False,  # describedVersion
}


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    family: str
    callee: int
    target_global: int
    # TypeInfo 6-field descriptor parameters
    field00: int | None = None
    field08: int | None = None
    field10: int | None = None
    field18: int | None = None
    object_size: int = 0
    # Class 14-argument descriptor parameters (None => nullptr)
    name_ptr: int | None = None
    parent_ptr: int | None = None
    interfaces_ptr: int | None = None
    num_interfaces: int = 0
    enums_ptr: int | None = None
    num_enums: int = 0
    members_ptr: int | None = None
    num_members: int = 0
    defaults_ptr: int | None = None
    attributes_ptr: int | None = None
    flags: int = 0
    described_version: int = 0

    @property
    def name(self):
        return f'Init{self.rva:x}'

    @property
    def base_family(self):
        return self.family.rstrip('0123456789')


def _reg_group(reg):
    """Map x86-64 GPR subregisters to their canonical 64-bit register name."""
    from iced_x86 import Register
    return {
        Register.RAX: 'RAX', Register.EAX: 'RAX',
        Register.RCX: 'RCX', Register.ECX: 'RCX',
        Register.RDX: 'RDX', Register.EDX: 'RDX',
        Register.R8: 'R8', Register.R8D: 'R8',
        Register.R9: 'R9', Register.R9D: 'R9',
        Register.R10: 'R10', Register.R10D: 'R10',
        Register.R11: 'R11', Register.R11D: 'R11',
    }.get(reg)


def _classify_typeinfo_init(insns, rva, size):
    """88B straight-line 6-field static descriptor initializer with one vtable-getter call."""
    from iced_x86 import Code, OpKind, Register
    if size != 88 or len(insns) != 14:
        return None
    if not (insns[0].code == Code.SUB_RM64_IMM8 and insns[0].op0_register == Register.RSP
            and insns[0].immediate8to64 == 0x28):
        return None
    if insns[1].code != Code.CALL_REL32_64:
        return None
    getter = insns[1].near_branch_target

    def lea_rcx_rip(ins):
        if ins.code == Code.LEA_R64_M and ins.op0_register == Register.RCX and ins.memory_base == Register.RIP:
            return ins.ip_rel_memory_address
        return None

    def mov_rip_reg(ins, reg):
        if (ins.code == Code.MOV_RM64_R64 and ins.op0_kind == OpKind.MEMORY
                and ins.memory_base == Register.RIP and ins.op1_register == reg):
            return ins.ip_rel_memory_address
        return None

    f00 = lea_rcx_rip(insns[2])
    dst20 = mov_rip_reg(insns[3], Register.RAX)
    dst00 = mov_rip_reg(insns[4], Register.RCX)
    f08 = lea_rcx_rip(insns[5])
    dst08 = mov_rip_reg(insns[6], Register.RCX)
    f10 = lea_rcx_rip(insns[7])
    dst10 = mov_rip_reg(insns[8], Register.RCX)
    f18 = lea_rcx_rip(insns[9])
    dst18 = mov_rip_reg(insns[10], Register.RCX)
    if None in (f00, dst20, dst00, f08, dst08, f10, dst10, f18, dst18):
        return None
    i11 = insns[11]
    if not (i11.code == Code.MOV_RM64_IMM32 and i11.op0_kind == OpKind.MEMORY and i11.memory_base == Register.RIP):
        return None
    dst28 = i11.ip_rel_memory_address
    obj_size = i11.immediate32to64
    if obj_size <= 0:
        return None
    if (dst08 != dst00 + 0x08 or dst10 != dst00 + 0x10 or dst18 != dst00 + 0x18
            or dst20 != dst00 + 0x20 or dst28 != dst00 + 0x28):
        return None
    if not (insns[12].code == Code.ADD_RM64_IMM8 and insns[12].op0_register == Register.RSP
            and insns[12].immediate8to64 == 0x28 and insns[13].code == Code.RETNQ):
        return None
    return Member(
        rva=rva, size=size, family=TYPEINFO_DESC_INIT,
        callee=getter, target_global=dst00,
        field00=f00, field08=f08, field10=f10, field18=f18, object_size=obj_size,
    )


def _classify_class_init(insns, rva, size):
    """Straight-line 14-argument class descriptor constructor call (frame 0x78)."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) < 16 or len(insns) > 30:
        return None
    # Epilogue must be: call rel32; add rsp, 0x78; ret
    if not (insns[-3].code == Code.CALL_REL32_64
            and insns[-2].code == Code.ADD_RM64_IMM8 and insns[-2].op0_register == Register.RSP
            and insns[-2].immediate8to64 == 0x78
            and insns[-1].code == Code.RETNQ):
        return None
    callee = insns[-3].near_branch_target

    # Prologue: either `sub rsp, 0x78` or `mov rax, rsp; sub rsp, 0x78`
    regs = {}
    idx = 0
    if (insns[0].code == Code.MOV_R64_RM64 and insns[0].op0_register == Register.RAX
            and insns[0].op1_register == Register.RSP):
        regs['RAX'] = ('sp', 0x78)
        idx = 1
    if not (insns[idx].code == Code.SUB_RM64_IMM8 and insns[idx].op0_register == Register.RSP
            and insns[idx].immediate8to64 == 0x78):
        return None
    idx += 1

    stack = {}

    def resolve_sp_offset(ins):
        if ins.memory_index != Register.NONE:
            return None
        if ins.memory_base == Register.RSP:
            disp = ins.memory_displacement
            return disp if disp in _STACK_SLOT_IS_PTR else None
        base_g = _reg_group(ins.memory_base)
        if base_g and regs.get(base_g) == ('sp', 0x78):
            # Signed 64-bit displacement relative to original RSP (= current RSP + 0x78)
            disp = ins.memory_displacement
            if disp >= (1 << 63):
                disp -= (1 << 64)
            off = 0x78 + disp
            return off if off in _STACK_SLOT_IS_PTR else None
        return None

    for ins in insns[idx:-3]:
        c = ins.code
        if c == Code.XOR_R32_RM32 and ins.op0_register == ins.op1_register:
            g = _reg_group(ins.op0_register)
            if not g:
                return None
            regs[g] = ('imm', 0)
        elif c == Code.MOV_R32_IMM32:
            g = _reg_group(ins.op0_register)
            if not g:
                return None
            regs[g] = ('imm', ins.immediate32)
        elif c == Code.LEA_R64_M and ins.memory_base == Register.RIP:
            g = _reg_group(ins.op0_register)
            if not g:
                return None
            regs[g] = ('rip', ins.ip_rel_memory_address)
        elif c == Code.LEA_R32_M and ins.memory_index == Register.NONE:
            dst = _reg_group(ins.op0_register)
            src = _reg_group(ins.memory_base)
            if not dst or not src or src not in regs or regs[src][0] != 'imm':
                return None
            disp = ins.memory_displacement
            if disp >= (1 << 63):
                disp -= (1 << 64)
            regs[dst] = ('imm', (regs[src][1] + disp) & 0xFFFFFFFF)
        elif c == Code.MOV_RM64_R64 and ins.op0_kind == OpKind.MEMORY:
            off = resolve_sp_offset(ins)
            src = _reg_group(ins.op1_register)
            if off is None or not _STACK_SLOT_IS_PTR[off] or src not in regs:
                return None
            val = regs[src]
            if val[0] == 'imm' and val[1] != 0:
                return None
            if val[0] not in ('rip', 'imm'):
                return None
            stack[off] = val
        elif c == Code.MOV_RM32_R32 and ins.op0_kind == OpKind.MEMORY:
            off = resolve_sp_offset(ins)
            src = _reg_group(ins.op1_register)
            if off is None or _STACK_SLOT_IS_PTR[off] or src not in regs or regs[src][0] != 'imm':
                return None
            stack[off] = regs[src]
        elif c == Code.MOV_RM32_IMM32 and ins.op0_kind == OpKind.MEMORY:
            off = resolve_sp_offset(ins)
            if off is None or _STACK_SLOT_IS_PTR[off]:
                return None
            stack[off] = ('imm', ins.immediate32)
        else:
            return None

    # Every one of the 4 register args and 10 stack slots must be resolved cleanly.
    if set(stack) != set(_STACK_SLOT_IS_PTR):
        return None
    for rg in ('RCX', 'RDX', 'R8', 'R9'):
        if rg not in regs:
            return None
    if regs['RCX'][0] != 'rip' or regs['RDX'][0] != 'rip' or regs['R9'][0] != 'imm':
        return None
    if regs['R8'][0] == 'imm' and regs['R8'][1] != 0:
        return None
    if regs['R8'][0] not in ('rip', 'imm'):
        return None

    def opt_ptr(val):
        return val[1] if val[0] == 'rip' else None

    def u32_to_i32(v):
        return v - (1 << 32) if v >= (1 << 31) else v

    return Member(
        rva=rva, size=size, family=CLASS_DESC_INIT,
        callee=callee, target_global=regs['RCX'][1],
        name_ptr=regs['RDX'][1],
        parent_ptr=opt_ptr(regs['R8']),
        object_size=u32_to_i32(regs['R9'][1]),
        interfaces_ptr=opt_ptr(stack[0x20]),
        num_interfaces=u32_to_i32(stack[0x28][1]),
        enums_ptr=opt_ptr(stack[0x30]),
        num_enums=u32_to_i32(stack[0x38][1]),
        members_ptr=opt_ptr(stack[0x40]),
        num_members=u32_to_i32(stack[0x48][1]),
        defaults_ptr=opt_ptr(stack[0x50]),
        attributes_ptr=opt_ptr(stack[0x58]),
        flags=stack[0x60][1],
        described_version=u32_to_i32(stack[0x68][1]),
    )


def classify(code, rva):
    """Classify one non-EH candidate function into a descriptor initializer template."""
    from iced_x86 import Decoder
    size = len(code)
    if size not in CANDIDATE_SIZES:
        return None
    insns = list(Decoder(64, code, ip=rva))
    if any(ins.is_invalid for ins in insns):
        return None
    if size == 88:
        member = _classify_typeinfo_init(insns, rva, size)
        if member is not None:
            return member
    return _classify_class_init(insns, rva, size)


def _has_exception_handler(image, pdata_entries, rva, size):
    end = rva + size
    for begin, p_end, uw_rva in pdata_entries:
        if begin < end and rva < p_end:
            try:
                _, hdr = image.read(uw_rva, 4, 'unwind header')
            except Reject:
                return True
            if (hdr[0] >> 3) & 3:
                return True
    return False


def _is_rdata(image, target):
    try:
        flags = image.section_for(target).flags
    except Reject:
        return False
    return not (flags & (SCN_MEM_EXECUTE | SCN_MEM_WRITE))


def _is_writable_data(image, target):
    try:
        flags = image.section_for(target).flags
    except Reject:
        return False
    return bool(flags & SCN_MEM_WRITE) and not (flags & SCN_MEM_EXECUTE)


def _is_nonexec_data(image, target):
    try:
        flags = image.section_for(target).flags
    except Reject:
        return False
    return not (flags & SCN_MEM_EXECUTE)


def _is_code_target(image, member, target, starts):
    if member.rva <= target < member.rva + member.size:
        return False
    if target not in starts and (target & 0xF) != 0:
        return False
    try:
        return bool(image.section_for(target).flags & SCN_MEM_EXECUTE)
    except Reject:
        return False


def _valid_member(image, member, starts):
    if not leaf_family_batch.indexed_callee(
            image, SimpleNamespace(rva=member.rva, size=member.size, callee=member.callee), starts):
        return False
    if not _is_writable_data(image, member.target_global):
        return False
    if member.base_family == TYPEINFO_DESC_INIT:
        if not (_is_rdata(image, member.field00) and _is_rdata(image, member.field08)):
            return False
        if not (_is_code_target(image, member, member.field10, starts)
                and _is_code_target(image, member, member.field18, starts)):
            return False
        return True
    if member.base_family == CLASS_DESC_INIT:
        if not _is_rdata(image, member.name_ptr):
            return False
        if member.parent_ptr is not None and not _is_writable_data(image, member.parent_ptr):
            return False
        for ptr in (member.interfaces_ptr, member.enums_ptr, member.members_ptr,
                    member.defaults_ptr, member.attributes_ptr):
            if ptr is not None and not _is_nonexec_data(image, ptr):
                return False
        return True
    return False


def _shard(members):
    out = []
    by_family = {}
    for m in members:
        by_family.setdefault(m.family, []).append(m)
    for base in BASE_FAMILIES:
        rows = by_family.get(base, [])
        if len(rows) <= SHARD_SIZE:
            out.extend(rows)
        else:
            for idx in range(0, len(rows), SHARD_SIZE):
                shard_name = f'{base}{idx // SHARD_SIZE + 1}'
                out.extend(replace(m, family=shard_name) for m in rows[idx:idx + SHARD_SIZE])
    return sorted(out, key=lambda m: m.rva)


def discover(image, extents, inventory):
    """Discover all validated non-EH static descriptor initializers."""
    pdata_sorted = sorted(image.runtime_functions())
    pdata_begins = [b for b, _, _ in pdata_sorted]
    starts = set(extents) | set(pdata_begins)

    def has_eh(rva, size):
        end = rva + size
        hi = bisect.bisect_left(pdata_begins, end)
        lo = max(0, bisect.bisect_left(pdata_begins, rva) - 8)
        return _has_exception_handler(image, pdata_sorted[lo:hi], rva, size)

    accepted = []
    for member in leaf_family_batch.candidates(image, extents, inventory, CANDIDATE_SIZES, classify):
        if not has_eh(member.rva, member.size) and _valid_member(image, member, starts):
            accepted.append(member)
    return _shard(accepted)


def _mangled_symbol(family, member):
    return f'?{member.name}@{family}@@SAXXZ'


def emit(root, family, members, build_id, boundary_label):
    """Emit one self-contained C++ unit (.h, .cpp, task.json, symbols.json) for a family shard."""
    bf = members[0].base_family
    preamble = [
        '// Source exposure: mixed (pinned image and community function boundaries).',
        f'// Boundary source: {boundary_label}',
        '// Code origin: generated structural reconstruction of static reflection descriptor initializers.',
        f'// {family}, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.',
        '// Adapted bodies: none',
    ]
    header = list(preamble) + ['#pragma once', '']
    if bf == TYPEINFO_DESC_INIT:
        header += [
            f'struct {family}Record',
            '{',
            '    void* field00;',
            '    void* field08;',
            '    void* field10;',
            '    void* field18;',
            '    void* field20;',
            '    unsigned long long field28;',
            '};',
            '',
        ]

    symbols = {}
    externs = []

    def add_extern(name, decl, rva):
        if name not in symbols:
            symbols[name] = dict(rva=rva, size=None)
            externs.append(decl)

    for m in members:
        if bf == TYPEINFO_DESC_INIT:
            add_extern(f'GetVtable_{m.callee:x}', f'extern "C" void* GetVtable_{m.callee:x}();', m.callee)
            add_extern(f'gRecord_{m.target_global:x}', f'extern "C" {family}Record gRecord_{m.target_global:x};', m.target_global)
            add_extern(f'Data_{m.field00:x}', f'extern "C" unsigned char Data_{m.field00:x}[];', m.field00)
            add_extern(f'Data_{m.field08:x}', f'extern "C" unsigned char Data_{m.field08:x}[];', m.field08)
            add_extern(f'Func_{m.field10:x}', f'extern "C" unsigned char Func_{m.field10:x}[];', m.field10)
            add_extern(f'Func_{m.field18:x}', f'extern "C" unsigned char Func_{m.field18:x}[];', m.field18)
        elif bf == CLASS_DESC_INIT:
            add_extern(
                f'ClassInit_{m.callee:x}',
                f'extern "C" void ClassInit_{m.callee:x}('
                'void* outClass, const char* name, void* parent, int objectSize, '
                'const void* interfaces, int numInterfaces, const void* enums, int numEnums, '
                'const void* members, int numMembers, const void* defaults, const void* attributes, '
                'unsigned int flags, int describedVersion);',
                m.callee,
            )
            add_extern(f'ClassSlot_{m.target_global:x}', f'extern "C" unsigned char ClassSlot_{m.target_global:x}[];', m.target_global)
            add_extern(f'Name_{m.name_ptr:x}', f'extern "C" const char Name_{m.name_ptr:x}[];', m.name_ptr)
            if m.parent_ptr is not None:
                add_extern(f'ClassSlot_{m.parent_ptr:x}', f'extern "C" unsigned char ClassSlot_{m.parent_ptr:x}[];', m.parent_ptr)
            for ptr in (m.interfaces_ptr, m.enums_ptr, m.members_ptr, m.defaults_ptr, m.attributes_ptr):
                if ptr is not None:
                    add_extern(f'DescData_{ptr:x}', f'extern "C" unsigned char DescData_{ptr:x}[];', ptr)

    header.extend(externs)
    header += ['', f'struct {family}', '{']

    source = list(preamble)
    functions = []
    bodies = []

    for m in members:
        sym = _mangled_symbol(family, m)
        symbols[sym] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=sym))
        source.append(f'// 0x{m.rva:x} {family}::{m.name}')
        header.append(f'    static void {m.name}();')

        if bf == TYPEINFO_DESC_INIT:
            bodies += [
                '',
                f'void {family}::{m.name}()',
                '{',
                f'    void* vtable = GetVtable_{m.callee:x}();',
                f'    gRecord_{m.target_global:x}.field00 = Data_{m.field00:x};',
                f'    gRecord_{m.target_global:x}.field08 = Data_{m.field08:x};',
                f'    gRecord_{m.target_global:x}.field10 = Func_{m.field10:x};',
                f'    gRecord_{m.target_global:x}.field18 = Func_{m.field18:x};',
                f'    gRecord_{m.target_global:x}.field20 = vtable;',
                f'    gRecord_{m.target_global:x}.field28 = {m.object_size}ull;',
                '}',
            ]
        elif bf == CLASS_DESC_INIT:
            def ptr_expr(ptr, prefix='DescData'):
                return 'nullptr' if ptr is None else f'{prefix}_{ptr:x}'

            bodies += [
                '',
                f'void {family}::{m.name}()',
                '{',
                f'    ClassInit_{m.callee:x}(',
                f'        ClassSlot_{m.target_global:x},',
                f'        Name_{m.name_ptr:x},',
                f'        {ptr_expr(m.parent_ptr, "ClassSlot")},',
                f'        {m.object_size},',
                f'        {ptr_expr(m.interfaces_ptr)},',
                f'        {m.num_interfaces},',
                f'        {ptr_expr(m.enums_ptr)},',
                f'        {m.num_enums},',
                f'        {ptr_expr(m.members_ptr)},',
                f'        {m.num_members},',
                f'        {ptr_expr(m.defaults_ptr)},',
                f'        {ptr_expr(m.attributes_ptr)},',
                f'        {m.flags}u,',
                f'        {m.described_version});',
                '}',
            ]

    header.append('};')
    source.append(f'#include "{family}.h"')
    source.extend(bodies)
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


def main():
    return leaf_family_batch.run(__doc__, discover, emit)


if __name__ == '__main__':
    raise SystemExit(main())
