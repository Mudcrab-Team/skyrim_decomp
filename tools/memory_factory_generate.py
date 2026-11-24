"""Draft non-EH Bethesda MemoryManager::Allocate factory and creator methods.

    python tools/memory_factory_generate.py --exe /path/to/SkyrimSE.exe
    python tools/memory_factory_generate.py --exe /path/to/SkyrimSE.exe --out .local/memory-factory --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information, static storage references and direct
call targets for every generated member.
"""
import bisect
from dataclasses import dataclass, replace
from types import SimpleNamespace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE

SCN_MEM_READ = 0x40000000

ALLOC_FIXED = 'MemoryAllocFixed'
ALLOC_DYNAMIC = 'MemoryAllocDynamic'
CREATE_OBJECT = 'MemoryCreateObject'
CREATE_NIREF = 'MemoryCreateNiRefObject'
CREATE_SMARTPTR = 'BSTSmartPointerCreate'

BASE_FAMILIES = (
    ALLOC_FIXED,
    ALLOC_DYNAMIC,
    CREATE_OBJECT,
    CREATE_NIREF,
    CREATE_SMARTPTR,
)

SHARD_SIZE = 30
CANDIDATE_SIZES = frozenset(range(54, 340))


@dataclass(frozen=True)
class StoreOp:
    kind: str  # 'addr', 'zero', 'imm', 'flt'
    offset: int
    width: int  # 1, 2, 4, or 8
    value: int  # RVA for 'addr'/'flt', constant for 'imm', 0 for 'zero'


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    family: str
    guard_rva: int
    mgr_rva: int
    ensure_rva: int
    alloc_rva: int
    alloc_size: int = 0
    align: int = 0
    align_req: bool = False
    has_spill: bool = True
    niref_vft: int = 0
    niref_cnt: int = 0
    ref_width: int = 4
    stores: tuple = ()

    @property
    def name(self):
        return f'Op{self.rva:x}'

    @property
    def base_family(self):
        return self.family.rstrip('0123456789')

    def all_callees(self):
        return (self.ensure_rva, self.alloc_rva)

    def all_data_refs(self):
        refs = [self.guard_rva, self.mgr_rva]
        if self.niref_vft:
            refs.append(self.niref_vft)
        if self.niref_cnt:
            refs.append(self.niref_cnt)
        for st in self.stores:
            if st.kind in ('addr', 'flt'):
                refs.append(st.value)
        return tuple(refs)


def _signed_disp(insn):
    d = insn.memory_displacement
    return d - (1 << 64) if d >= (1 << 63) else d


def _is_zero_reg(insn, reg):
    from iced_x86 import Code
    return insn.code == Code.XOR_R32_RM32 and insn.op0_register == reg and insn.op1_register == reg


def _match_ensure_init(insns, idx):
    """Match MemoryManager::GetSingleton() once-init guard starting at idx.

    Returns (next_idx, guard_rva, mgr_rva, ensure_rva, extra_saved_reg_mov) or None.
    Supports either:
      cmp dword [guard], 2 ; je skip ; lea rdx, [guard] ; lea rcx, [mgr] ; call ensure
    or with a single reg-move interleaved between cmp and je (e.g. mov rbx, rcx or mov rsi, rdx).
    """
    from iced_x86 import Code, OpKind, Register
    if idx + 5 > len(insns):
        return None
    i0 = insns[idx]
    if not (i0.code == Code.CMP_RM32_IMM8 and i0.is_ip_rel_memory_operand and i0.immediate8 == 2):
        return None
    guard_rva = i0.ip_rel_memory_address
    saved_mov = None
    cur = idx + 1
    if insns[cur].code == Code.MOV_R64_RM64 and insns[cur].op1_kind == OpKind.REGISTER:
        saved_mov = (insns[cur].op0_register, insns[cur].op1_register)
        cur += 1
    if cur + 4 > len(insns):
        return None
    i_je, i_rdx, i_rcx, i_call = insns[cur:cur + 4]
    if not (i_je.code == Code.JE_REL8_64
            and i_rdx.code == Code.LEA_R64_M and i_rdx.op0_register == Register.RDX
            and i_rdx.is_ip_rel_memory_operand and i_rdx.ip_rel_memory_address == guard_rva
            and i_rcx.code == Code.LEA_R64_M and i_rcx.op0_register == Register.RCX
            and i_rcx.is_ip_rel_memory_operand
            and i_call.code == Code.CALL_REL32_64):
        return None
    next_idx = cur + 4
    if next_idx >= len(insns) or i_je.near_branch64 != insns[next_idx].ip:
        return None
    mgr_rva = i_rcx.ip_rel_memory_address
    ensure_rva = i_call.near_branch64
    return next_idx, guard_rva, mgr_rva, ensure_rva, saved_mov


def _parse_alloc_const_args(insns, idx, mgr_rva):
    """Parse setup of Allocate(const_size, 0, false) at idx (4 insns before call/jmp).

    Returns (next_idx, alloc_size) or None.
    """
    from iced_x86 import Code, OpKind, Register
    if idx + 4 > len(insns):
        return None
    seen_rcx = False
    seen_r8 = False
    seen_r9 = False
    alloc_size = None
    for i in insns[idx:idx + 4]:
        if i.code == Code.LEA_R64_M and i.op0_register == Register.RCX and i.is_ip_rel_memory_operand:
            if i.ip_rel_memory_address != mgr_rva or seen_rcx:
                return None
            seen_rcx = True
        elif _is_zero_reg(i, Register.R8D):
            if seen_r8:
                return None
            seen_r8 = True
        elif _is_zero_reg(i, Register.R9D):
            if seen_r9:
                return None
            seen_r9 = True
        elif i.code == Code.LEA_R32_M and i.op0_register == Register.EDX and i.memory_index == Register.NONE:
            if i.memory_base != Register.R9 or not seen_r9 or alloc_size is not None:
                return None
            disp = _signed_disp(i)
            if not (1 <= disp <= 0x400):
                return None
            alloc_size = disp
        elif i.code == Code.MOV_R32_IMM32 and i.op0_register == Register.EDX:
            if alloc_size is not None:
                return None
            val = i.immediate32
            if not (1 <= val <= 0x4000):
                return None
            alloc_size = val
        else:
            return None
    if not (seen_rcx and seen_r8 and seen_r9 and alloc_size is not None):
        return None
    return idx + 4, alloc_size


def _classify_alloc_fixed(insns, rva, size):
    """58B (12 insns): return MemoryManager::GetSingleton()->Allocate(N, 0, false);"""
    from iced_x86 import Code, Register
    if len(insns) != 12:
        return None
    if not (insns[0].code == Code.SUB_RM64_IMM8 and insns[0].op0_register == Register.RSP and insns[0].immediate8 == 0x28):
        return None
    ens = _match_ensure_init(insns, 1)
    if ens is None:
        return None
    nxt, guard_rva, mgr_rva, ensure_rva, saved_mov = ens
    if saved_mov is not None:
        return None
    arg = _parse_alloc_const_args(insns, nxt, mgr_rva)
    if arg is None:
        return None
    nxt, alloc_size = arg
    if nxt + 2 != len(insns):
        return None
    i_add, i_jmp = insns[nxt], insns[nxt + 1]
    if not (i_add.code == Code.ADD_RM64_IMM8 and i_add.op0_register == Register.RSP and i_add.immediate8 == 0x28
            and i_jmp.code == Code.JMP_REL32_64):
        return None
    return Member(
        rva=rva, size=size, family=ALLOC_FIXED,
        guard_rva=guard_rva, mgr_rva=mgr_rva, ensure_rva=ensure_rva,
        alloc_rva=i_jmp.near_branch64, alloc_size=alloc_size,
    )


def _classify_alloc_dynamic(insns, rva, size):
    """63B/66B (15 insns): return MemoryManager::GetSingleton()->Allocate(size, align, alignReq);"""
    from iced_x86 import Code, Register
    if len(insns) != 15:
        return None
    if not (insns[0].code == Code.PUSH_R64 and insns[0].op0_register == Register.RBX
            and insns[1].code == Code.SUB_RM64_IMM8 and insns[1].op0_register == Register.RSP and insns[1].immediate8 == 0x20):
        return None
    ens = _match_ensure_init(insns, 2)
    if ens is None:
        return None
    nxt, guard_rva, mgr_rva, ensure_rva, saved_mov = ens
    if saved_mov != (Register.RBX, Register.RCX):
        return None
    if nxt + 7 != len(insns):
        return None
    seen_rcx = False
    seen_rdx = False
    align = None
    align_req = None
    for i in insns[nxt:nxt + 4]:
        if i.code == Code.LEA_R64_M and i.op0_register == Register.RCX and i.is_ip_rel_memory_operand:
            if i.ip_rel_memory_address != mgr_rva or seen_rcx:
                return None
            seen_rcx = True
        elif i.code == Code.MOV_R64_RM64 and i.op0_register == Register.RDX and i.op1_register == Register.RBX:
            if seen_rdx:
                return None
            seen_rdx = True
        elif _is_zero_reg(i, Register.R8D):
            if align is not None:
                return None
            align = 0
        elif i.code == Code.MOV_R32_IMM32 and i.op0_register == Register.R8D:
            if align is not None or i.immediate32 == 0 or i.immediate32 > 0x1000:
                return None
            align = i.immediate32
        elif _is_zero_reg(i, Register.R9D):
            if align_req is not None:
                return None
            align_req = False
        elif i.code == Code.MOV_R8_IMM8 and i.op0_register == Register.R9L and i.immediate8 == 1:
            if align_req is not None:
                return None
            align_req = True
        else:
            return None
    if not (seen_rcx and seen_rdx and align is not None and align_req is not None):
        return None
    i_add, i_pop, i_jmp = insns[nxt + 4:nxt + 7]
    if not (i_add.code == Code.ADD_RM64_IMM8 and i_add.op0_register == Register.RSP and i_add.immediate8 == 0x20
            and i_pop.code == Code.POP_R64 and i_pop.op0_register == Register.RBX
            and i_jmp.code == Code.JMP_REL32_64):
        return None
    return Member(
        rva=rva, size=size, family=ALLOC_DYNAMIC,
        guard_rva=guard_rva, mgr_rva=mgr_rva, ensure_rva=ensure_rva,
        alloc_rva=i_jmp.near_branch64, align=align, align_req=align_req,
    )


def _parse_store_block(insns, base_reg, alloc_size, *, zero_regs_init=(), allow_flt=True):
    """Parse a straight-line constructor store sequence into [base_reg + off].

    Tracks register values (zero registers, RIP-relative data addresses, and loaded xmm floats).
    Returns tuple of StoreOp or None if any unrecognized instruction or out-of-bounds store appears.
    """
    from iced_x86 import Code, OpKind, Register

    # Map sub-registers of RCX / RDX / RAX to their 64-bit canonical reg
    REG_FAMILY = {
        Register.RAX: (Register.RAX, 8), Register.EAX: (Register.RAX, 4),
        Register.AX: (Register.RAX, 2), Register.AL: (Register.RAX, 1),
        Register.RCX: (Register.RCX, 8), Register.ECX: (Register.RCX, 4),
        Register.CX: (Register.RCX, 2), Register.CL: (Register.RCX, 1),
        Register.RDX: (Register.RDX, 8), Register.EDX: (Register.RDX, 4),
        Register.DX: (Register.RDX, 2), Register.DL: (Register.RDX, 1),
        Register.R8: (Register.R8, 8), Register.R8D: (Register.R8, 4),
        Register.R8W: (Register.R8, 2), Register.R8L: (Register.R8, 1),
    }

    reg_val = {r: ('zero', 0) for r in zero_regs_init}
    xmm_val = {}
    stores = []
    written = set()

    def _valid_base(i):
        if i.op0_kind != OpKind.MEMORY or i.memory_index != Register.NONE:
            return None
        if i.memory_base != base_reg and not (base_reg == Register.RBX and i.memory_base == Register.RAX and Register.RAX not in reg_val):
            return None
        off = _signed_disp(i)
        if off < 0:
            return None
        return off

    for i in insns:
        c = i.code
        # Self-xor produces a zero register
        if c == Code.XOR_R32_RM32 and i.op0_register == i.op1_register and i.op0_register in REG_FAMILY:
            canon, _ = REG_FAMILY[i.op0_register]
            if canon == base_reg:
                return None
            reg_val[canon] = ('zero', 0)
            continue
        # RIP-relative effective address load for a static data symbol
        if c == Code.LEA_R64_M and i.is_ip_rel_memory_operand and i.op0_register in REG_FAMILY:
            canon, _ = REG_FAMILY[i.op0_register]
            if canon == base_reg:
                return None
            reg_val[canon] = ('addr', i.ip_rel_memory_address)
            continue
        # Scalar single-precision float load from static storage
        if allow_flt and c == Code.MOVSS_XMM_XMMM32 and i.is_ip_rel_memory_operand:
            xmm_val[i.op0_register] = i.ip_rel_memory_address
            continue
        # Scalar single-precision float store into the allocated object
        if allow_flt and c == Code.MOVSS_XMMM32_XMM and i.op1_register in xmm_val:
            off = _valid_base(i)
            if off is None or off + 4 > alloc_size:
                return None
            stores.append(StoreOp('flt', off, 4, xmm_val[i.op1_register]))
            written.update(range(off, off + 4))
            continue
        # Register-to-memory store of width 1, 2, 4 or 8 bytes
        if c in (Code.MOV_RM64_R64, Code.MOV_RM32_R32, Code.MOV_RM16_R16, Code.MOV_RM8_R8):
            off = _valid_base(i)
            if off is None or i.op1_register not in REG_FAMILY:
                return None
            canon, width = REG_FAMILY[i.op1_register]
            if canon not in reg_val or off + width > alloc_size:
                return None
            kind, val = reg_val[canon]
            if kind == 'addr' and width != 8:
                return None
            stores.append(StoreOp(kind, off, width, val))
            written.update(range(off, off + width))
            continue
        # Immediate-to-memory store of width 1, 2, 4 or 8 bytes
        if c == Code.MOV_RM64_IMM32:
            off = _valid_base(i)
            if off is None or off + 8 > alloc_size or i.immediate32to64 != 0:
                return None
            stores.append(StoreOp('zero', off, 8, 0))
            written.update(range(off, off + 8))
            continue
        if c == Code.MOV_RM32_IMM32:
            off = _valid_base(i)
            if off is None or off + 4 > alloc_size:
                return None
            val = i.immediate32
            stores.append(StoreOp('zero' if val == 0 else 'imm', off, 4, val))
            written.update(range(off, off + 4))
            continue
        if c == Code.MOV_RM16_IMM16:
            off = _valid_base(i)
            if off is None or off + 2 > alloc_size:
                return None
            val = i.immediate16
            stores.append(StoreOp('zero_b2' if val == 0 else 'imm_b2', off, 2, val))
            written.update(range(off, off + 2))
            continue
        if c == Code.MOV_RM8_IMM8:
            off = _valid_base(i)
            if off is None or off + 1 > alloc_size:
                return None
            val = i.immediate8
            stores.append(StoreOp('zero' if val == 0 else 'imm', off, 1, val))
            written.update(range(off, off + 1))
            continue
        return None
    if not stores:
        return None
    # Reject overlapping non-vftable stores (vftable at offset 0 may be overwritten once by derived ctor)
    seen_ranges = []
    for st in stores:
        if st.offset == 0 and st.kind == 'addr':
            continue
        for a, b in seen_ranges:
            if st.offset < b and a < st.offset + st.width:
                return None
        seen_ranges.append((st.offset, st.offset + st.width))
    return tuple(stores)


def _match_sub28_null_epilogue(insns, idx):
    """Match the null-return epilogue at idx after the non-null add rsp, 28h; ret."""
    from iced_x86 import Code, Register
    tail = insns[idx:]
    if len(tail) == 2:
        # Direct frame teardown and return
        return (tail[0].code == Code.ADD_RM64_IMM8 and tail[0].op0_register == Register.RSP and tail[0].immediate8 == 0x28
                and tail[1].code == Code.RETNQ)
    if len(tail) == 3:
        # Copy pre-zeroed register to return register, then return
        return (tail[0].code == Code.MOV_R64_RM64 and tail[0].op0_register == Register.RAX and tail[0].op1_register == Register.RCX
                and tail[1].code == Code.ADD_RM64_IMM8 and tail[1].op0_register == Register.RSP and tail[1].immediate8 == 0x28
                and tail[2].code == Code.RETNQ)
    if len(tail) == 4:
        # Zero return register via scratch register, then return
        return (_is_zero_reg(tail[0], Register.ECX)
                and tail[1].code == Code.MOV_R32_RM32 and tail[1].op0_register == Register.EAX and tail[1].op1_register == Register.ECX
                and tail[2].code == Code.ADD_RM64_IMM8 and tail[2].op0_register == Register.RSP and tail[2].immediate8 == 0x28
                and tail[3].code == Code.RETNQ)
    return False


def _classify_create_object(insns, rva, size):
    """MemoryCreateObject: sub rsp, 28h -> EnsureInit -> Allocate(N,0,false) -> inline init."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) < 18:
        return None
    if not (insns[0].code == Code.SUB_RM64_IMM8 and insns[0].op0_register == Register.RSP and insns[0].immediate8 == 0x28):
        return None
    ens = _match_ensure_init(insns, 1)
    if ens is None:
        return None
    nxt, guard_rva, mgr_rva, ensure_rva, saved_mov = ens
    if saved_mov is not None:
        return None
    arg = _parse_alloc_const_args(insns, nxt, mgr_rva)
    if arg is None:
        return None
    nxt, alloc_size = arg
    if nxt >= len(insns) or insns[nxt].code != Code.CALL_REL32_64:
        return None
    alloc_rva = insns[nxt].near_branch64
    nxt += 1

    # Optional hoisted xor ecx, ecx
    zero_regs = ()
    if nxt < len(insns) and _is_zero_reg(insns[nxt], Register.ECX):
        zero_regs = (Register.RCX,)
        nxt += 1

    # Optional mov [rsp+38h], rax (present for member `new Obj()`, absent for static `if (p)`)
    has_spill = False
    if (nxt < len(insns) and insns[nxt].code == Code.MOV_RM64_R64
            and insns[nxt].op0_kind == OpKind.MEMORY and insns[nxt].memory_base == Register.RSP
            and insns[nxt].memory_index == Register.NONE and _signed_disp(insns[nxt]) == 0x38
            and insns[nxt].op1_register == Register.RAX):
        has_spill = True
        nxt += 1

    if nxt + 2 >= len(insns):
        return None
    i_test, i_je = insns[nxt], insns[nxt + 1]
    if not (i_test.code == Code.TEST_RM64_R64 and i_test.op0_register == Register.RAX and i_test.op1_register == Register.RAX
            and i_je.code in (Code.JE_REL8_64, Code.JE_REL32_64)):
        return None
    null_ip = i_je.near_branch64
    body_start = nxt + 2

    null_idx = next((k for k in range(body_start, len(insns)) if insns[k].ip == null_ip), None)
    if null_idx is None or null_idx < body_start + 3:
        return None
    if not _match_sub28_null_epilogue(insns, null_idx):
        return None
    # Non-null epilogue immediately precedes null_idx
    ep0, ep1 = insns[null_idx - 2], insns[null_idx - 1]
    if not (ep0.code == Code.ADD_RM64_IMM8 and ep0.op0_register == Register.RSP and ep0.immediate8 == 0x28
            and ep1.code == Code.RETNQ):
        return None

    body = insns[body_start:null_idx - 2]
    if any(i.has_lock_prefix for i in body):
        return None
    stores = _parse_store_block(body, Register.RAX, alloc_size, zero_regs_init=zero_regs, allow_flt=False)
    if stores is None:
        return None
    addr_stores = [st for st in stores if st.kind == 'addr']
    if len(addr_stores) > 1:
        return None
    if addr_stores and (addr_stores[0].offset != 0 or body[0].code != Code.LEA_R64_M):
        return None
    return Member(
        rva=rva, size=size, family=CREATE_OBJECT,
        guard_rva=guard_rva, mgr_rva=mgr_rva, ensure_rva=ensure_rva,
        alloc_rva=alloc_rva, alloc_size=alloc_size, has_spill=has_spill,
        stores=stores,
    )


def _classify_create_niref(insns, rva, size):
    """MemoryCreateNiRefObject: sub rsp, 28h -> EnsureInit -> Allocate -> NiRefBase -> derived init."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) < 24:
        return None
    if not (insns[0].code == Code.SUB_RM64_IMM8 and insns[0].op0_register == Register.RSP and insns[0].immediate8 == 0x28):
        return None
    ens = _match_ensure_init(insns, 1)
    if ens is None:
        return None
    nxt, guard_rva, mgr_rva, ensure_rva, saved_mov = ens
    if saved_mov is not None:
        return None
    arg = _parse_alloc_const_args(insns, nxt, mgr_rva)
    if arg is None:
        return None
    nxt, alloc_size = arg
    if alloc_size < 0x10 or nxt + 4 >= len(insns) or insns[nxt].code != Code.CALL_REL32_64:
        return None
    alloc_rva = insns[nxt].near_branch64
    nxt += 1

    # Home-slot spill of allocated pointer followed by null check and branch
    i_sp, i_test, i_je = insns[nxt:nxt + 3]
    if not (i_sp.code == Code.MOV_RM64_R64 and i_sp.op0_kind == OpKind.MEMORY
            and i_sp.memory_base == Register.RSP and i_sp.memory_index == Register.NONE
            and _signed_disp(i_sp) == 0x38 and i_sp.op1_register == Register.RAX
            and i_test.code == Code.TEST_RM64_R64 and i_test.op0_register == Register.RAX and i_test.op1_register == Register.RAX
            and i_je.code in (Code.JE_REL8_64, Code.JE_REL32_64)):
        return None
    null_ip = i_je.near_branch64
    body_start = nxt + 3

    null_idx = next((k for k in range(body_start, len(insns)) if insns[k].ip == null_ip), None)
    if null_idx is None or null_idx < body_start + 6:
        return None
    if not _match_sub28_null_epilogue(insns, null_idx):
        return None
    ep0, ep1 = insns[null_idx - 2], insns[null_idx - 1]
    if not (ep0.code == Code.ADD_RM64_IMM8 and ep0.op0_register == Register.RSP and ep0.immediate8 == 0x28
            and ep1.code == Code.RETNQ):
        return None

    # Match NiRefBase ctor prefix inside body_start:
    # Form A (4 insns + lock inc): lea rcx, [niref_vft] ; mov [rax], rcx ; xor ecx, ecx ; mov [rax+8], ecx ; lock inc dword [niref_cnt]
    # Form B (3 insns + lock inc): lea rcx, [niref_vft] ; mov dword [rax+8], 0 ; mov [rax], rcx ; lock inc dword [niref_cnt]
    b = insns[body_start:null_idx - 2]
    if len(b) < 6:
        return None
    if not (b[0].code == Code.LEA_R64_M and b[0].op0_register == Register.RCX and b[0].is_ip_rel_memory_operand):
        return None
    niref_vft = b[0].ip_rel_memory_address
    zero_regs = ()
    if (b[1].code == Code.MOV_RM64_R64 and b[1].memory_base == Register.RAX and _signed_disp(b[1]) == 0 and b[1].op1_register == Register.RCX
            and _is_zero_reg(b[2], Register.ECX)
            and b[3].code == Code.MOV_RM32_R32 and b[3].memory_base == Register.RAX and _signed_disp(b[3]) == 8 and b[3].op1_register == Register.ECX
            and b[4].has_lock_prefix and b[4].code == Code.INC_RM32 and b[4].is_ip_rel_memory_operand):
        niref_cnt = b[4].ip_rel_memory_address
        zero_regs = (Register.RCX,)
        rest = b[5:]
    elif (b[1].code == Code.MOV_RM32_IMM32 and b[1].memory_base == Register.RAX and _signed_disp(b[1]) == 8 and b[1].immediate32 == 0
            and b[2].code == Code.MOV_RM64_R64 and b[2].memory_base == Register.RAX and _signed_disp(b[2]) == 0 and b[2].op1_register == Register.RCX
            and b[3].has_lock_prefix and b[3].code == Code.INC_RM32 and b[3].is_ip_rel_memory_operand):
        niref_cnt = b[3].ip_rel_memory_address
        rest = b[4:]
    else:
        return None
    if any(i.has_lock_prefix for i in rest):
        return None
    stores = _parse_store_block(rest, Register.RAX, alloc_size, zero_regs_init=zero_regs, allow_flt=False)
    if stores is None:
        return None
    # Require a single addr store (the derived vftable at offset 0) as the final store
    addr_stores = [st for st in stores if st.kind == 'addr']
    if len(addr_stores) != 1 or addr_stores[0].offset != 0:
        return None
    if not (stores[-1].offset == 0 and stores[-1].kind == 'addr'):
        return None
    # Ensure no derived store touches NiRefBase fields [0x08..0x0F]
    if any(8 <= st.offset < 0x10 for st in stores):
        return None
    return Member(
        rva=rva, size=size, family=CREATE_NIREF,
        guard_rva=guard_rva, mgr_rva=mgr_rva, ensure_rva=ensure_rva,
        alloc_rva=alloc_rva, alloc_size=alloc_size, has_spill=True,
        niref_vft=niref_vft, niref_cnt=niref_cnt, stores=stores,
    )


def _classify_create_smartptr(insns, rva, size):
    """BSTSmartPointerCreate: out = BSTSmartPointer<Obj>(new Obj());"""
    from iced_x86 import Code, OpKind, Register
    if len(insns) < 52:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.MOV_RM64_R64 and insns[1].memory_base == Register.RSP and _signed_disp(insns[1]) == 0x18 and insns[1].op1_register == Register.RSI
            and insns[2].code == Code.PUSH_R64 and insns[2].op0_register == Register.RDI
            and insns[3].code == Code.SUB_RM64_IMM8 and insns[3].op0_register == Register.RSP and insns[3].immediate8 == 0x20):
        return None
    ens = _match_ensure_init(insns, 4)
    if ens is None:
        return None
    nxt, guard_rva, mgr_rva, ensure_rva, saved_mov = ens
    if saved_mov != (Register.RSI, Register.RDX):
        return None
    arg = _parse_alloc_const_args(insns, nxt, mgr_rva)
    if arg is None:
        return None
    nxt, alloc_size = arg
    if alloc_size < 0x10 or nxt + 5 >= len(insns) or insns[nxt].code != Code.CALL_REL32_64:
        return None
    alloc_rva = insns[nxt].near_branch64
    nxt += 1

    i_sp, i_mv, i_test, i_je = insns[nxt:nxt + 4]
    if not (i_sp.code == Code.MOV_RM64_R64 and i_sp.memory_base == Register.RSP and _signed_disp(i_sp) == 0x38 and i_sp.op1_register == Register.RAX
            and i_mv.code == Code.MOV_R64_RM64 and i_mv.op0_register == Register.RBX and i_mv.op1_register == Register.RAX
            and i_test.code == Code.TEST_RM64_R64 and i_test.op0_register == Register.RAX and i_test.op1_register == Register.RAX
            and i_je.code == Code.JE_REL8_64):
        return None
    null_ip = i_je.near_branch64
    body_start = nxt + 4
    null_idx = next((k for k in range(body_start, len(insns)) if insns[k].ip == null_ip), None)
    if null_idx is None or null_idx < body_start + 4:
        return None

    i_inc, i_jmp = insns[null_idx - 2], insns[null_idx - 1]
    if not (i_inc.has_lock_prefix and i_inc.code == Code.INC_RM32 and i_inc.memory_base == Register.RBX
            and i_inc.memory_index == Register.NONE and _signed_disp(i_inc) == 8
            and i_jmp.code == Code.JMP_REL8_64):
        return None
    assign_idx = null_idx + 1
    if assign_idx >= len(insns) or i_jmp.near_branch64 != insns[assign_idx].ip:
        return None

    i_null = insns[null_idx]
    if not ((i_null.code == Code.MOV_R64_RM64 and i_null.op0_register == Register.RBX and i_null.op1_register == Register.RAX)
            or _is_zero_reg(i_null, Register.EBX)):
        return None

    tail = insns[assign_idx:]
    if len(tail) != 31:
        return None
    if not (tail[0].code == Code.MOV_R64_RM64 and tail[0].op0_register == Register.RCX and tail[0].memory_base == Register.RSI and _signed_disp(tail[0]) == 0
            and tail[1].code == Code.MOV_R32_IMM32 and tail[1].op0_register == Register.EDI and tail[1].immediate32 == 0xFFFFFFFF
            and tail[2].code in (Code.CMP_R64_RM64, Code.CMP_RM64_R64) and tail[2].op0_register == Register.RBX and tail[2].op1_register == Register.RCX
            and tail[3].code == Code.JE_REL8_64 and tail[3].near_branch64 == tail[17].ip
            and tail[4].code == Code.TEST_RM64_R64 and tail[4].op0_register == Register.RBX and tail[4].op1_register == Register.RBX
            and tail[5].code == Code.JE_REL8_64 and tail[5].near_branch64 == tail[7].ip
            and tail[6].has_lock_prefix and tail[6].code == Code.INC_RM32 and tail[6].memory_base == Register.RBX and _signed_disp(tail[6]) == 8
            and tail[7].code == Code.MOV_RM64_R64 and tail[7].memory_base == Register.RSI and _signed_disp(tail[7]) == 0 and tail[7].op1_register == Register.RBX
            and tail[8].code == Code.TEST_RM64_R64 and tail[8].op0_register == Register.RCX and tail[8].op1_register == Register.RCX
            and tail[9].code == Code.JE_REL8_64 and tail[9].near_branch64 == tail[17].ip
            and tail[10].code == Code.MOV_R32_RM32 and tail[10].op0_register == Register.EAX and tail[10].op1_register == Register.EDI
            and tail[11].has_lock_prefix and tail[11].code == Code.XADD_RM32_R32 and tail[11].memory_base == Register.RCX and _signed_disp(tail[11]) == 8 and tail[11].op1_register == Register.EAX
            and tail[12].code == Code.CMP_RM32_IMM8 and tail[12].op0_register == Register.EAX and tail[12].immediate8 == 1
            and tail[13].code == Code.JNE_REL8_64 and tail[13].near_branch64 == tail[17].ip
            and tail[14].code == Code.MOV_R64_RM64 and tail[14].op0_register == Register.RAX and tail[14].memory_base == Register.RCX and _signed_disp(tail[14]) == 0
            and tail[15].code == Code.MOV_R32_IMM32 and tail[15].op0_register == Register.EDX and tail[15].immediate32 == 1
            and tail[16].code == Code.CALL_RM64 and tail[16].memory_base == Register.RAX and _signed_disp(tail[16]) == 0
            and tail[17].code == Code.TEST_RM64_R64 and tail[17].op0_register == Register.RBX and tail[17].op1_register == Register.RBX
            and tail[18].code == Code.JE_REL8_64 and tail[18].near_branch64 == tail[26].ip
            and tail[19].has_lock_prefix and tail[19].code == Code.XADD_RM32_R32 and tail[19].memory_base == Register.RBX and _signed_disp(tail[19]) == 8 and tail[19].op1_register == Register.EDI
            and tail[20].code == Code.CMP_RM32_IMM8 and tail[20].op0_register == Register.EDI and tail[20].immediate8 == 1
            and tail[21].code == Code.JNE_REL8_64 and tail[21].near_branch64 == tail[26].ip
            and tail[22].code == Code.MOV_R64_RM64 and tail[22].op0_register == Register.RAX and tail[22].memory_base == Register.RBX and _signed_disp(tail[22]) == 0
            and tail[23].code == Code.MOV_R32_RM32 and tail[23].op0_register == Register.EDX and tail[23].op1_register == Register.EDI
            and tail[24].code == Code.MOV_R64_RM64 and tail[24].op0_register == Register.RCX and tail[24].op1_register == Register.RBX
            and tail[25].code == Code.CALL_RM64 and tail[25].memory_base == Register.RAX and _signed_disp(tail[25]) == 0
            and tail[26].code == Code.MOV_R64_RM64 and tail[26].op0_register == Register.RBX and tail[26].memory_base == Register.RSP and _signed_disp(tail[26]) == 0x30
            and tail[27].code == Code.MOV_R64_RM64 and tail[27].op0_register == Register.RSI and tail[27].memory_base == Register.RSP and _signed_disp(tail[27]) == 0x40
            and tail[28].code == Code.ADD_RM64_IMM8 and tail[28].op0_register == Register.RSP and tail[28].immediate8 == 0x20
            and tail[29].code == Code.POP_R64 and tail[29].op0_register == Register.RDI
            and tail[30].code == Code.RETNQ):
        return None

    body = insns[body_start:null_idx - 2]
    if any(i.has_lock_prefix for i in body):
        return None
    stores = _parse_store_block(body, Register.RBX, alloc_size, allow_flt=False)
    if stores is None:
        return None
    if sum(1 for st in stores if st.kind == 'addr') != 1:
        return None
    if not any(st.offset == 0 and st.kind == 'addr' for st in stores):
        return None
    ref_st = [st for st in stores if st.offset == 8 and st.kind == 'zero' and st.width in (4, 8)]
    if len(ref_st) != 1:
        return None
    if ref_st[0].width == 4 and len(stores) != 2:
        return None
    if any(st.kind != 'zero' for st in stores if st.offset != 0):
        return None
    return Member(
        rva=rva, size=size, family=CREATE_SMARTPTR,
        guard_rva=guard_rva, mgr_rva=mgr_rva, ensure_rva=ensure_rva,
        alloc_rva=alloc_rva, alloc_size=alloc_size, has_spill=True,
        ref_width=ref_st[0].width, stores=stores,
    )


def classify(code, rva):
    from iced_x86 import Decoder
    size = len(code)
    if size not in CANDIDATE_SIZES:
        return None
    insns = list(Decoder(64, code, ip=rva))
    if not insns or sum(i.len for i in insns) != size:
        return None
    for fn in (
        _classify_alloc_fixed,
        _classify_alloc_dynamic,
        _classify_create_object,
        _classify_create_niref,
        _classify_create_smartptr,
    ):
        res = fn(insns, rva, size)
        if res is not None:
            return res
    return None


def _has_unwind_handler(image, rva, size, rf_starts, rf_entries):
    i = bisect.bisect_left(rf_starts, rva)
    while i < len(rf_entries) and rf_entries[i][0] < rva + size:
        _, _, uw = rf_entries[i]
        if uw:
            try:
                _, ub = image.read(uw, 1, 'unwind header')
                if (ub[0] >> 3) & 0x3:
                    return True
            except Reject:
                return True
        i += 1
    return False


def _is_data_target(image, rva):
    try:
        sec = image.section_for(rva)
    except Reject:
        return False
    return bool(sec.flags & SCN_MEM_READ) and not bool(sec.flags & SCN_MEM_EXECUTE)


def _validate_member(image, m, starts):
    if m.ensure_rva == m.alloc_rva:
        return False
    for c in m.all_callees():
        if not leaf_family_batch.indexed_callee(image, SimpleNamespace(rva=m.rva, size=m.size, callee=c), starts):
            return False
    for d in m.all_data_refs():
        if not _is_data_target(image, d):
            return False
    return True


def _shard(members):
    by_base = {}
    for m in members:
        by_base.setdefault(m.base_family, []).append(m)
    out = []
    for base in BASE_FAMILIES:
        group = sorted(by_base.get(base, ()), key=lambda m: m.rva)
        if len(group) <= SHARD_SIZE:
            out.extend(group)
        else:
            for idx in range(0, len(group), SHARD_SIZE):
                shard_name = f'{base}{idx // SHARD_SIZE + 1}'
                out.extend(replace(m, family=shard_name) for m in group[idx:idx + SHARD_SIZE])
    return sorted(out, key=lambda m: m.rva)


def discover(image, extents, inventory):
    rfs = sorted(image.runtime_functions())
    rf_starts = [b for b, _, _ in rfs]
    starts = set(extents) | set(rf_starts)
    raw = [
        m for m in leaf_family_batch.candidates(image, extents, inventory, CANDIDATE_SIZES, classify)
        if not _has_unwind_handler(image, m.rva, m.size, rf_starts, rfs)
        and _validate_member(image, m, starts)
    ]
    sharded = _shard(raw)
    by_fam = {}
    for m in sharded:
        by_fam.setdefault(m.family, set()).add(m.rva)
    return [m for m in sharded if not any(c in by_fam[m.family] for c in m.all_callees())]


def _mangled(family, m):
    bf = m.base_family
    if bf == ALLOC_FIXED:
        return f'?{m.name}@{family}@@SAPEAXXZ'
    if bf == ALLOC_DYNAMIC:
        return f'?{m.name}@{family}@@SAPEAX_K@Z'
    if bf == CREATE_OBJECT:
        if m.has_spill:
            return f'?{m.name}@{family}@@QEAAPEAXXZ'
        return f'?{m.name}@{family}@@SAPEAXXZ'
    if bf == CREATE_NIREF:
        return f'?{m.name}@{family}@@QEAAPEAXXZ'
    if bf == CREATE_SMARTPTR:
        return f'?{m.name}@{family}@@QEAAXAEAU?$BSTSmartPointer@UObj_{m.rva:x}@@@@@Z'
    raise ValueError(bf)


def _cpp_type_for_store(st):
    if st.kind == 'addr':
        return 'void*'
    if st.kind == 'flt':
        return 'float'
    return {1: 'std::uint8_t', 2: 'std::uint16_t', 4: 'std::uint32_t', 8: 'std::uint64_t'}[st.width]


def _layout_fields(start_off, alloc_size, stores):
    """Build deterministic C++ struct fields and init statements for a store sequence.

    Splits any unaligned 8-byte zero store (off % 8 == 4) into two adjacent 32-bit zero
    fields so natural struct alignment holds without pack pragmas or casts.
    Returns (field_lines, init_lines).
    """
    # Expand any 8-byte zero at off % 8 != 0 or 2-byte immediate store (merged byte pair) into aligned chunks
    expanded = []
    for st in stores:
        if st.kind == 'zero_b2':
            expanded.append(StoreOp('zero', st.offset, 1, 0))
            expanded.append(StoreOp('zero', st.offset + 1, 1, 0))
        elif st.kind == 'imm_b2':
            lo = st.value & 0xff
            hi = (st.value >> 8) & 0xff
            expanded.append(StoreOp('zero' if lo == 0 else 'imm', st.offset, 1, lo))
            expanded.append(StoreOp('zero' if hi == 0 else 'imm', st.offset + 1, 1, hi))
        elif st.kind == 'zero' and st.width == 8 and (st.offset % 8) != 0:
            if (st.offset % 4) == 0:
                expanded.append(StoreOp('zero', st.offset, 4, 0))
                expanded.append(StoreOp('zero', st.offset + 4, 4, 0))
            else:
                for b in range(8):
                    expanded.append(StoreOp('zero', st.offset + b, 1, 0))
        elif st.kind == 'zero' and st.width == 4 and (st.offset % 4) != 0:
            for b in range(4):
                expanded.append(StoreOp('zero', st.offset + b, 1, 0))
        elif st.kind == 'zero' and st.width == 2 and (st.offset % 2) != 0:
            expanded.append(StoreOp('zero', st.offset, 1, 0))
            expanded.append(StoreOp('zero', st.offset + 1, 1, 0))
        else:
            expanded.append(st)

    # Deduplicate field declarations by offset (keep first; offset 0 may be inherited)
    by_off = {}
    for st in expanded:
        if st.offset >= start_off and st.offset not in by_off:
            by_off[st.offset] = st

    field_lines = []
    cur = start_off
    for off in sorted(by_off):
        st = by_off[off]
        if off > cur:
            field_lines.append(f'    std::uint8_t unk_{cur:x}[0x{off - cur:x}];')
            cur = off
        ty = _cpp_type_for_store(st)
        field_lines.append(f'    {ty} f_{off:x};')
        cur = off + st.width
    if cur < alloc_size:
        field_lines.append(f'    std::uint8_t unk_{cur:x}[0x{alloc_size - cur:x}];')

    init_lines = []
    for st in expanded:
        lhs = 'vftable' if (st.offset == 0 and start_off > 0) else f'f_{st.offset:x}'
        if st.kind == 'addr':
            init_lines.append(f'        {lhs} = Data_{st.value:x};')
        elif st.kind == 'flt':
            init_lines.append(f'        {lhs} = Flt_{st.value:x};')
        elif st.kind == 'zero':
            init_lines.append(f'        {lhs} = 0u;')
        else:
            init_lines.append(f'        {lhs} = 0x{st.value:x}u;')
    return field_lines, init_lines


def emit(root, family, members, build_id, label):
    bf = members[0].base_family
    prefix = [
        '// Source exposure: mixed (pinned image and community function boundaries).',
        f'// Boundary source: {label}',
        '// Code origin: original structural reconstruction of Bethesda MemoryManager::Allocate factory helpers.',
        f'// {family}, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.',
        '// Adapted bodies: none',
    ]
    header = prefix + ['#pragma once', '#include <cstddef>', '#include <cstdint>']
    if bf in (CREATE_NIREF, CREATE_SMARTPTR):
        header.append('#include <intrin.h>')
    header.append('')
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"', '']
    symbols = {}

    # Collect unique external symbols across members in this shard
    header.append('extern "C" {')
    for g in sorted({m.guard_rva for m in members}):
        nm = f'MemMgrGuard_{g:x}'
        header.append(f'    extern std::uint32_t {nm};')
        symbols[nm] = dict(rva=g, size=None)
    for mg in sorted({m.mgr_rva for m in members}):
        nm = f'MemMgrInst_{mg:x}'
        header.append(f'    extern std::uint8_t {nm}[1];')
        symbols[nm] = dict(rva=mg, size=None)
    for e in sorted({m.ensure_rva for m in members}):
        nm = f'MemMgrEnsure_{e:x}'
        header.append(f'    void __cdecl {nm}(void* self, std::uint32_t* state);')
        symbols[nm] = dict(rva=e, size=None)
    for a in sorted({m.alloc_rva for m in members}):
        nm = f'MemMgrAlloc_{a:x}'
        header.append(f'    void* __cdecl {nm}(void* self, std::size_t size, std::uint32_t align, bool alignReq);')
        symbols[nm] = dict(rva=a, size=None)
    for nv in sorted({m.niref_vft for m in members if m.niref_vft}):
        nm = f'Data_{nv:x}'
        if nm not in symbols:
            header.append(f'    extern std::uint8_t {nm}[1];')
            symbols[nm] = dict(rva=nv, size=None)
    for nc in sorted({m.niref_cnt for m in members if m.niref_cnt}):
        nm = f'NiRefCount_{nc:x}'
        if nm not in symbols:
            header.append(f'    extern long {nm};')
            symbols[nm] = dict(rva=nc, size=None)
    data_addrs = sorted({st.value for m in members for st in m.stores if st.kind == 'addr'})
    for da in data_addrs:
        nm = f'Data_{da:x}'
        if nm not in symbols:
            header.append(f'    extern std::uint8_t {nm}[1];')
            symbols[nm] = dict(rva=da, size=None)
    flt_addrs = sorted({st.value for m in members for st in m.stores if st.kind == 'flt'})
    for fa in flt_addrs:
        nm = f'Flt_{fa:x}'
        if nm not in symbols:
            header.append(f'    extern float {nm};')
            symbols[nm] = dict(rva=fa, size=None)
    header.extend(['}', ''])

    # Emit MemoryManager helper (parameterized per unique (guard, mgr, ensure, alloc) tuple)
    mm_tuples = sorted({(m.guard_rva, m.mgr_rva, m.ensure_rva, m.alloc_rva) for m in members})
    mm_names = {}
    for idx, (g, mg, e, a) in enumerate(mm_tuples):
        mm_nm = 'MemoryManager' if len(mm_tuples) == 1 else f'MemoryManager_{idx}'
        mm_names[(g, mg, e, a)] = mm_nm
        header.extend([
            f'struct {mm_nm} {{',
            '    static void* GetSingleton() {',
            f'        if (MemMgrGuard_{g:x} != 2u) {{',
            f'            MemMgrEnsure_{e:x}(MemMgrInst_{mg:x}, &MemMgrGuard_{g:x});',
            '        }',
            f'        return MemMgrInst_{mg:x};',
            '    }',
            '    static void* Alloc(std::size_t size, std::uint32_t align = 0u, bool alignReq = false) {',
            f'        return MemMgrAlloc_{a:x}(GetSingleton(), size, align, alignReq);',
            '    }',
            '};',
            '',
        ])

    if bf in (CREATE_OBJECT, CREATE_NIREF, CREATE_SMARTPTR):
        for mm_key, mm_nm in mm_names.items():
            hb_nm = 'HeapAllocBase' if len(mm_names) == 1 else f'HeapAllocBase_{mm_nm}'
            header.extend([
                f'struct {hb_nm} {{',
                '    static void* operator new(std::size_t size) throw() {',
                f'        return {mm_nm}::Alloc(size);',
                '    }',
                '};',
                '',
            ])

    if bf == CREATE_NIREF:
        niref_tuples = sorted({(m.niref_vft, m.niref_cnt, mm_names[(m.guard_rva, m.mgr_rva, m.ensure_rva, m.alloc_rva)]) for m in members})
        nr_names = {}
        for idx, (nv, nc, mm_nm) in enumerate(niref_tuples):
            hb_nm = 'HeapAllocBase' if len(mm_names) == 1 else f'HeapAllocBase_{mm_nm}'
            nr_nm = 'NiRefBase' if len(niref_tuples) == 1 else f'NiRefBase_{idx}'
            nr_names[(nv, nc, mm_nm)] = nr_nm
            header.extend([
                f'struct {nr_nm} : {hb_nm} {{',
                '    void* vftable;',
                '    std::uint32_t refCount;',
                '    std::uint32_t unk_c;',
                f'    {nr_nm}() {{',
                f'        vftable = Data_{nv:x};',
                '        refCount = 0u;',
                f'        _InterlockedIncrement(reinterpret_cast<volatile long*>(&NiRefCount_{nc:x}));  // atomic object counter increment',
                '    }',
                '};',
                '',
            ])

    if bf == CREATE_SMARTPTR:
        header.extend([
            'template <class T>',
            'struct BSTSmartPointer {',
            '    T* ptr;',
            '    explicit BSTSmartPointer(T* p) throw() : ptr(p) {',
            '        if (ptr) {',
            '            ptr->IncRef();',
            '        }',
            '    }',
            '    ~BSTSmartPointer() throw() {',
            '        if (ptr && ptr->DecRef() == 0u) {',
            '            ptr->Destroy();',
            '        }',
            '    }',
            '    BSTSmartPointer& operator=(const BSTSmartPointer& rhs) throw() {',
            '        T* old = ptr;',
            '        if (rhs.ptr != old) {',
            '            if (rhs.ptr) {',
            '                rhs.ptr->IncRef();',
            '            }',
            '            ptr = rhs.ptr;',
            '            if (old && old->DecRef() == 0u) {',
            '                old->Destroy();',
            '            }',
            '        }',
            '        return *this;',
            '    }',
            '};',
            '',
        ])

    # Emit per-member object structs in header when needed
    if bf in (CREATE_OBJECT, CREATE_NIREF, CREATE_SMARTPTR):
        for m in members:
            mm_nm = mm_names[(m.guard_rva, m.mgr_rva, m.ensure_rva, m.alloc_rva)]
            hb_nm = 'HeapAllocBase' if len(mm_names) == 1 else f'HeapAllocBase_{mm_nm}'
            obj_nm = f'Obj_{m.rva:x}'
            if bf == CREATE_OBJECT:
                flines, ilines = _layout_fields(0, m.alloc_size, m.stores)
                base_cls = f' : {hb_nm}' if m.has_spill else ''
                header.append(f'struct {obj_nm}{base_cls} {{')
                header.extend(flines)
                if m.has_spill:
                    header.append(f'    {obj_nm}() {{')
                    header.extend(ilines)
                    header.append('    }')
                header.extend(['};', ''])
            elif bf == CREATE_NIREF:
                nr_nm = nr_names[(m.niref_vft, m.niref_cnt, mm_nm)]
                flines, ilines = _layout_fields(0x10, m.alloc_size, m.stores)
                header.append(f'struct {obj_nm} : {nr_nm} {{')
                header.extend(flines)
                header.append(f'    {obj_nm}() : {nr_nm}() {{')
                header.extend(ilines)
                header.append('    }')
                header.extend(['};', ''])
            elif bf == CREATE_SMARTPTR:
                # Filter out offset 0 (vftable) and offset 8 (refCount/refAndPad) from layout start 0x10
                start_off = 0x10 if m.ref_width == 8 else 0x0c
                flines, _ = _layout_fields(start_off, m.alloc_size, [s for s in m.stores if s.offset >= start_off])
                # Build init lines in exact binary store order
                init_lines = []
                for st in m.stores:
                    if st.offset == 0 and st.kind == 'addr':
                        init_lines.append(f'        vftable = Data_{st.value:x};')
                    elif st.offset == 8 and st.kind == 'zero':
                        init_lines.append('        refCount = 0u;')
                    else:
                        # Handle any expanded unaligned zero stores
                        if st.kind == 'zero' and st.width == 8 and (st.offset % 8) != 0 and (st.offset % 4) == 0:
                            init_lines.append(f'        f_{st.offset:x} = 0u;')
                            init_lines.append(f'        f_{st.offset + 4:x} = 0u;')
                        elif st.kind == 'addr':
                            init_lines.append(f'        f_{st.offset:x} = Data_{st.value:x};')
                        elif st.kind == 'zero':
                            init_lines.append(f'        f_{st.offset:x} = 0u;')
                        else:
                            init_lines.append(f'        f_{st.offset:x} = 0x{st.value:x}u;')
                ref_ty = 'std::uint64_t' if m.ref_width == 8 else 'std::uint32_t'
                header.extend([
                    f'struct {obj_nm} : {hb_nm} {{',
                    '    void* vftable;',
                    f'    {ref_ty} refCount;',
                ])
                header.extend(flines)
                header.append(f'    {obj_nm}() {{')
                header.extend(init_lines)
                header.extend([
                    '    }',
                    '    void Destroy() throw() {',
                    '        using DtorFn = void(__fastcall*)(void*, std::uint32_t);',
                    '        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);',
                    '    }',
                    '    void IncRef() throw() {',
                    '        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment',
                    '    }',
                    '    std::uint32_t DecRef() throw() {',
                    '        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement',
                    '    }',
                    '};',
                    '',
                ])

    header.append(f'struct {family} {{')
    functions = []
    for m in members:
        mm_nm = mm_names[(m.guard_rva, m.mgr_rva, m.ensure_rva, m.alloc_rva)]
        if bf == ALLOC_FIXED:
            header.append(f'    static void* {m.name}();')
            source.extend([
                f'void* {family}::{m.name}()',
                '{',
                f'    return {mm_nm}::Alloc(0x{m.alloc_size:x}u);',
                '}',
                '',
            ])
        elif bf == ALLOC_DYNAMIC:
            header.append(f'    static void* {m.name}(std::size_t size);')
            req_s = 'true' if m.align_req else 'false'
            source.extend([
                f'void* {family}::{m.name}(std::size_t size)',
                '{',
                f'    return {mm_nm}::Alloc(size, 0x{m.align:x}u, {req_s});',
                '}',
                '',
            ])
        elif bf == CREATE_OBJECT:
            obj_nm = f'Obj_{m.rva:x}'
            if m.has_spill:
                header.append(f'    void* {m.name}();')
                source.extend([
                    f'void* {family}::{m.name}()',
                    '{',
                    f'    return new {obj_nm}();',
                    '}',
                    '',
                ])
            else:
                header.append(f'    static void* {m.name}();')
                _, ilines = _layout_fields(0, m.alloc_size, m.stores)
                source.extend([
                    f'void* {family}::{m.name}()',
                    '{',
                    f'    {obj_nm}* p = static_cast<{obj_nm}*>({mm_nm}::Alloc(sizeof({obj_nm})));',
                    '    if (p) {',
                ])
                for ln in ilines:
                    source.append('        p->' + ln.strip())
                source.extend([
                    '        return p;',
                    '    }',
                    '    return nullptr;',
                    '}',
                    '',
                ])
        elif bf == CREATE_NIREF:
            obj_nm = f'Obj_{m.rva:x}'
            header.append(f'    void* {m.name}();')
            source.extend([
                f'void* {family}::{m.name}()',
                '{',
                f'    return new {obj_nm}();',
                '}',
                '',
            ])
        elif bf == CREATE_SMARTPTR:
            obj_nm = f'Obj_{m.rva:x}'
            header.append(f'    void {m.name}(BSTSmartPointer<{obj_nm}>& out);')
            source.extend([
                f'void {family}::{m.name}(BSTSmartPointer<{obj_nm}>& out)',
                '{',
                f'    out = BSTSmartPointer<{obj_nm}>(new {obj_nm}());',
                '}',
                '',
            ])
        functions.append(dict(rva=m.rva, size=m.size, symbol=_mangled(family, m), name=f'{family}::{m.name}'))
    header.append('};')
    return leaf_family_batch.write_unit(root, family, build_id, header, source, symbols, functions)


def main():
    return leaf_family_batch.run(__doc__, discover, emit)


if __name__ == '__main__':
    raise SystemExit(main())
