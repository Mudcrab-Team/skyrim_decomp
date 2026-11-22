"""Draft non-EH Bethesda BSTArray / BSTSmallArray / BSTScrapArray container helper methods.

    python tools/bst_array_generate.py --exe /path/to/SkyrimSE.exe
    python tools/bst_array_generate.py --exe /path/to/SkyrimSE.exe --out .local/bst-array --compare

Requires iced-x86==1.21.0. --compare uses the pinned contributor compiler and
checks the full code, unwind information, static storage references and direct
call targets for every generated member.
"""
import bisect
from dataclasses import dataclass, replace
from types import SimpleNamespace

import leaf_family_batch
from pecoff import Reject, SCN_MEM_EXECUTE

ERASE_UNORDERED = 'BSTArrayEraseUnordered'
ERASE_ORDERED = 'BSTArrayEraseOrdered'
SMALL_ERASE_ORDERED = 'BSTSmallArrayEraseOrdered'
RESIZE_TRIVIAL = 'BSTArrayResizeTrivial'
RESIZE_CONSTRUCT = 'BSTArrayResizeConstruct'
FIND_ERASE_ORDERED = 'BSTArrayFindEraseOrdered'
FIND_ERASE_UNORDERED = 'BSTArrayFindEraseUnordered'
ARRAY_RELEASE = 'BSTArrayRelease'

BASE_FAMILIES = (
    ERASE_UNORDERED,
    ERASE_ORDERED,
    SMALL_ERASE_ORDERED,
    RESIZE_TRIVIAL,
    RESIZE_CONSTRUCT,
    FIND_ERASE_ORDERED,
    FIND_ERASE_UNORDERED,
    ARRAY_RELEASE,
)

SHARD_SIZE = 30
CANDIDATE_SIZES = frozenset((33, 34, 82, 83, 94, 95, 113, 114, 117, 118, 140, 141, 153, 154, 163, 164))


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    family: str
    elem_size: int
    is_scrap: bool = False
    callee: int = 0
    callee2: int = 0
    callee3: int = 0
    local_bytes: int = 8

    @property
    def name(self):
        return f'Op{self.rva:x}'

    @property
    def base_family(self):
        return self.family.rstrip('0123456789')

    def all_callees(self):
        return tuple(c for c in (self.callee, self.callee2, self.callee3) if c)


def _signed_disp(insn):
    d = insn.memory_displacement
    return d - (1 << 64) if d >= (1 << 63) else d


def _is_imm_to_rsp(insn, disp):
    from iced_x86 import Code, OpKind, Register
    if (insn.code == Code.MOV_RM32_IMM32 and insn.op0_kind == OpKind.MEMORY
            and insn.memory_base == Register.RSP and insn.memory_index == Register.NONE
            and _signed_disp(insn) == disp):
        return insn.immediate32
    return None


def _read_r8d_imm(insn):
    from iced_x86 import Code, OpKind, Register
    if insn.code == Code.MOV_R32_IMM32 and insn.op0_register == Register.R8D:
        return insn.immediate32
    if (insn.code == Code.LEA_R32_M and insn.op0_register == Register.R8D
            and insn.memory_index == Register.NONE and insn.memory_base != Register.NONE):
        return _signed_disp(insn)
    return None


def _classify_release(insns, rva, size):
    """33B/34B (10 insns): if (self->data) { Dealloc(self); self->size = 0; }"""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 10:
        return None
    i0, i1, i2, i3, i4, i5, i6, i7, i8, i9 = insns
    if not (i0.code == Code.PUSH_R64 and i0.op0_register == Register.RBX
            and i1.code == Code.SUB_RM64_IMM8 and i1.op0_register == Register.RSP and i1.immediate8 == 0x20
            and i2.code == Code.CMP_RM64_IMM8 and i2.op0_kind == OpKind.MEMORY
            and i2.memory_base == Register.RCX and i2.memory_index == Register.NONE and i2.immediate8 == 0
            and i3.code == Code.MOV_R64_RM64 and i3.op0_register == Register.RBX and i3.op1_register == Register.RCX
            and i4.code == Code.JE_REL8_64 and i4.near_branch64 == i7.ip
            and i5.code == Code.CALL_REL32_64
            and i6.code == Code.MOV_RM32_IMM32 and i6.op0_kind == OpKind.MEMORY
            and i6.memory_base == Register.RBX and i6.memory_index == Register.NONE and i6.immediate32 == 0
            and i7.code == Code.ADD_RM64_IMM8 and i7.op0_register == Register.RSP and i7.immediate8 == 0x20
            and i8.code == Code.POP_R64 and i8.op0_register == Register.RBX
            and i9.code == Code.RETNQ):
        return None
    data_off = _signed_disp(i2)
    size_off = _signed_disp(i6)
    if (data_off, size_off) == (0, 0x10):
        is_scrap = False
    elif (data_off, size_off) == (8, 0x18):
        is_scrap = True
    else:
        return None
    return Member(rva, size, ARRAY_RELEASE, elem_size=0, is_scrap=is_scrap, callee=i5.near_branch64)


def _classify_erase_unordered(insns, rva, size):
    """82B/83B (24 insns): swap-tail-into-hole unordered erase calling MoveElements."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 24:
        return None
    # Prologue: mov [rsp+8], rbx; push rdi; sub rsp, 0x30
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP
            and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.PUSH_R64 and insns[1].op0_register == Register.RDI
            and insns[2].code == Code.SUB_RM64_IMM8 and insns[2].op0_register == Register.RSP
            and insns[2].immediate8 == 0x30):
        return None
    # Size load & lea rbx, [rcx+size_off]
    i3, i4 = insns[3], insns[4]
    if not (i3.code == Code.MOV_R32_RM32 and i3.op0_register == Register.R9D
            and i3.memory_base == Register.RCX and i3.memory_index == Register.NONE
            and i4.code == Code.LEA_R64_M and i4.op0_register == Register.RBX
            and i4.memory_base == Register.RCX and i4.memory_index == Register.NONE):
        return None
    size_off = _signed_disp(i3)
    if _signed_disp(i4) != size_off:
        return None
    elem_size = _is_imm_to_rsp(insns[6], 0x28)
    if elem_size is None or not (1 <= elem_size <= 0x10000):
        return None
    # Check arithmetic + cmovb + data load + call + sub [rbx], edi + epilogue
    if not (insns[5].code == Code.MOV_R32_RM32 and insns[5].op0_register == Register.EAX and insns[5].op1_register == Register.R9D
            and insns[7].code == Code.SUB_R32_RM32 and insns[7].op0_register == Register.EAX and insns[7].op1_register == Register.EDX
            and insns[8].code == Code.MOV_R32_RM32 and insns[8].op0_register == Register.R10D and insns[8].op1_register == Register.R8D
            and insns[9].code == Code.SUB_R32_RM32 and insns[9].op0_register == Register.EAX and insns[9].op1_register == Register.R8D
            and insns[10].code == Code.MOV_R32_RM32 and insns[10].op0_register == Register.EDI and insns[10].op1_register == Register.R8D
            and insns[11].code == Code.CMP_R32_RM32 and insns[11].op0_register == Register.EAX and insns[11].op1_register == Register.R8D
            and insns[12].code == Code.MOV_R32_RM32 and insns[12].op0_register == Register.R8D and insns[12].op1_register == Register.EDX
            and insns[13].code == Code.MOV_R64_RM64 and insns[13].op0_register == Register.RDX
            and insns[13].memory_base == Register.RCX and insns[13].memory_index == Register.NONE
            and insns[14].code == Code.MOV_R64_RM64 and insns[14].op0_register == Register.RCX and insns[14].op1_register == Register.RBX
            and insns[15].code == Code.CMOVB_R32_RM32 and insns[15].op0_register == Register.R10D and insns[15].op1_register == Register.EAX
            and insns[16].code == Code.SUB_R32_RM32 and insns[16].op0_register == Register.R9D and insns[16].op1_register == Register.R10D
            and insns[17].code == Code.MOV_RM32_R32 and insns[17].memory_base == Register.RSP
            and _signed_disp(insns[17]) == 0x20 and insns[17].op1_register == Register.R10D
            and insns[18].code == Code.CALL_REL32_64
            and insns[19].code == Code.SUB_RM32_R32 and insns[19].memory_base == Register.RBX
            and _signed_disp(insns[19]) == 0 and insns[19].op1_register == Register.EDI
            and insns[20].code == Code.MOV_R64_RM64 and insns[20].op0_register == Register.RBX
            and insns[20].memory_base == Register.RSP and _signed_disp(insns[20]) == 0x40
            and insns[21].code == Code.ADD_RM64_IMM8 and insns[21].op0_register == Register.RSP and insns[21].immediate8 == 0x30
            and insns[22].code == Code.POP_R64 and insns[22].op0_register == Register.RDI
            and insns[23].code == Code.RETNQ):
        return None
    data_off = _signed_disp(insns[13])
    if (data_off, size_off) == (0, 0x10):
        is_scrap = False
    elif (data_off, size_off) == (8, 0x18):
        is_scrap = True
    else:
        return None
    return Member(rva, size, ERASE_UNORDERED, elem_size=elem_size, is_scrap=is_scrap, callee=insns[18].near_branch64)


def _classify_erase_ordered(insns, rva, size):
    """94B/95B (29 insns): ordered shift-tail erase calling MoveElements."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 29:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP
            and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.PUSH_R64 and insns[1].op0_register == Register.RDI
            and insns[2].code == Code.SUB_RM64_IMM8 and insns[2].op0_register == Register.RSP
            and insns[2].immediate8 == 0x30):
        return None
    i3, i4 = insns[3], insns[4]
    if not (i3.code == Code.MOV_R32_RM32 and i3.op0_register == Register.EAX
            and i3.memory_base == Register.RCX and i3.memory_index == Register.NONE
            and i4.code == Code.LEA_R64_M and i4.op0_register == Register.RBX
            and i4.memory_base == Register.RCX and i4.memory_index == Register.NONE):
        return None
    size_off = _signed_disp(i3)
    if _signed_disp(i4) != size_off:
        return None
    elem_size = _is_imm_to_rsp(insns[18], 0x28)
    if elem_size is None or not (1 <= elem_size <= 0x10000):
        return None
    if not (insns[5].code == Code.MOV_R32_RM32 and insns[5].op0_register == Register.EDI and insns[5].op1_register == Register.R8D
            and insns[6].code == Code.MOV_R32_RM32 and insns[6].op0_register == Register.R8D and insns[6].op1_register == Register.EDX
            and insns[7].code == Code.MOV_R64_RM64 and insns[7].op0_register == Register.RDX
            and insns[7].memory_base == Register.RCX and insns[7].memory_index == Register.NONE
            and insns[8].code == Code.CMP_R32_RM32 and insns[8].op0_register == Register.EDI and insns[8].op1_register == Register.EAX
            and insns[9].code == Code.JNE_REL8_64 and insns[9].near_branch64 == insns[17].ip
            and insns[10].code == Code.TEST_RM64_R64 and insns[10].op0_register == Register.RDX and insns[10].op1_register == Register.RDX
            and insns[11].code == Code.JE_REL8_64 and insns[11].near_branch64 == insns[25].ip
            and insns[12].code == Code.MOV_RM32_IMM32 and insns[12].memory_base == Register.RBX
            and _signed_disp(insns[12]) == 0 and insns[12].immediate32 == 0
            and insns[13].code == Code.MOV_R64_RM64 and insns[13].op0_register == Register.RBX
            and insns[13].memory_base == Register.RSP and _signed_disp(insns[13]) == 0x40
            and insns[14].code == Code.ADD_RM64_IMM8 and insns[14].op0_register == Register.RSP and insns[14].immediate8 == 0x30
            and insns[15].code == Code.POP_R64 and insns[15].op0_register == Register.RDI
            and insns[16].code == Code.RETNQ
            and insns[17].code == Code.SUB_R32_RM32 and insns[17].op0_register == Register.EAX and insns[17].op1_register == Register.R8D
            and insns[19].code == Code.SUB_R32_RM32 and insns[19].op0_register == Register.EAX and insns[19].op1_register == Register.EDI
            and insns[20].code == Code.LEA_R32_M and insns[20].op0_register == Register.R9D
            and {insns[20].memory_base, insns[20].memory_index} == {Register.R8, Register.RDI}
            and insns[21].code == Code.MOV_R64_RM64 and insns[21].op0_register == Register.RCX and insns[21].op1_register == Register.RBX
            and insns[22].code == Code.MOV_RM32_R32 and insns[22].memory_base == Register.RSP
            and _signed_disp(insns[22]) == 0x20 and insns[22].op1_register == Register.EAX
            and insns[23].code == Code.CALL_REL32_64
            and insns[24].code == Code.SUB_RM32_R32 and insns[24].memory_base == Register.RBX
            and _signed_disp(insns[24]) == 0 and insns[24].op1_register == Register.EDI
            and insns[25].code == Code.MOV_R64_RM64 and insns[25].op0_register == Register.RBX
            and insns[25].memory_base == Register.RSP and _signed_disp(insns[25]) == 0x40
            and insns[26].code == Code.ADD_RM64_IMM8 and insns[26].op0_register == Register.RSP and insns[26].immediate8 == 0x30
            and insns[27].code == Code.POP_R64 and insns[27].op0_register == Register.RDI
            and insns[28].code == Code.RETNQ):
        return None
    data_off = _signed_disp(insns[7])
    if (data_off, size_off) == (0, 0x10):
        is_scrap = False
    elif (data_off, size_off) == (8, 0x18):
        is_scrap = True
    else:
        return None
    return Member(rva, size, ERASE_ORDERED, elem_size=elem_size, is_scrap=is_scrap, callee=insns[23].near_branch64)


def _classify_small_erase_ordered(insns, rva, size):
    """117B/118B (37 insns): BSTSmallArray ordered erase with inline/heap sign-bit check."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 37:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP
            and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.PUSH_R64 and insns[1].op0_register == Register.RDI
            and insns[2].code == Code.SUB_RM64_IMM8 and insns[2].op0_register == Register.RSP
            and insns[2].immediate8 == 0x30
            and insns[3].code == Code.MOV_R32_RM32 and insns[3].op0_register == Register.EAX
            and insns[3].memory_base == Register.RCX and insns[3].memory_index == Register.NONE
            and insns[4].code == Code.LEA_R64_M and insns[4].op0_register == Register.RBX
            and insns[4].memory_base == Register.RCX and insns[4].memory_index == Register.NONE
            and insns[5].code == Code.MOV_R32_RM32 and insns[5].op0_register == Register.EDI and insns[5].op1_register == Register.R8D
            and insns[6].code == Code.MOV_R32_RM32 and insns[6].op0_register == Register.R10D and insns[6].op1_register == Register.EDX
            and insns[7].code == Code.MOV_R32_RM32 and insns[7].op0_register == Register.R8D
            and insns[7].memory_base == Register.RCX and _signed_disp(insns[7]) == 0
            and insns[8].code == Code.LEA_R64_M and insns[8].op0_register == Register.RDX
            and insns[8].memory_base == Register.RCX and _signed_disp(insns[8]) == 8
            and insns[9].code == Code.CMP_R32_RM32 and insns[9].op0_register == Register.EDI and insns[9].op1_register == Register.EAX
            and insns[10].code == Code.JNE_REL8_64 and insns[10].near_branch64 == insns[21].ip
            and insns[11].code == Code.TEST_RM32_R32 and insns[11].op0_register == Register.R8D and insns[11].op1_register == Register.R8D
            and insns[12].code == Code.JS_REL8_64 and insns[12].near_branch64 == insns[14].ip
            and insns[13].code == Code.MOV_R64_RM64 and insns[13].op0_register == Register.RDX
            and insns[13].memory_base == Register.RDX and _signed_disp(insns[13]) == 0
            and insns[14].code == Code.TEST_RM64_R64 and insns[14].op0_register == Register.RDX and insns[14].op1_register == Register.RDX
            and insns[15].code == Code.JE_REL8_64 and insns[15].near_branch64 == insns[33].ip
            and insns[16].code == Code.MOV_RM32_IMM32 and insns[16].memory_base == Register.RBX and _signed_disp(insns[16]) == 0 and insns[16].immediate32 == 0
            and insns[20].code == Code.RETNQ
            and insns[21].code == Code.SUB_R32_RM32 and insns[21].op0_register == Register.EAX and insns[21].op1_register == Register.R10D
            and insns[22].code == Code.SUB_R32_RM32 and insns[22].op0_register == Register.EAX and insns[22].op1_register == Register.EDI
            and insns[23].code == Code.TEST_RM32_R32 and insns[23].op0_register == Register.R8D and insns[23].op1_register == Register.R8D
            and insns[24].code == Code.JS_REL8_64 and insns[24].near_branch64 == insns[26].ip
            and insns[25].code == Code.MOV_R64_RM64 and insns[25].op0_register == Register.RDX
            and insns[25].memory_base == Register.RDX and _signed_disp(insns[25]) == 0
            and insns[26].code == Code.LEA_R32_M and insns[26].op0_register == Register.R9D
            and {insns[26].memory_base, insns[26].memory_index} == {Register.R10, Register.RDI}
            and insns[28].code == Code.MOV_R32_RM32 and insns[28].op0_register == Register.R8D and insns[28].op1_register == Register.R10D
            and insns[29].code == Code.MOV_RM32_R32 and insns[29].memory_base == Register.RSP and _signed_disp(insns[29]) == 0x20 and insns[29].op1_register == Register.EAX
            and insns[30].code == Code.MOV_R64_RM64 and insns[30].op0_register == Register.RCX and insns[30].op1_register == Register.RBX
            and insns[31].code == Code.CALL_REL32_64
            and insns[32].code == Code.SUB_RM32_R32 and insns[32].memory_base == Register.RBX and _signed_disp(insns[32]) == 0 and insns[32].op1_register == Register.EDI
            and insns[36].code == Code.RETNQ):
        return None
    size_off = _signed_disp(insns[3])
    if _signed_disp(insns[4]) != size_off or size_off < 0x10 or (size_off - 8) % 8 != 0 or size_off > 0x400:
        return None
    elem_size = _is_imm_to_rsp(insns[27], 0x28)
    if elem_size is None or not (1 <= elem_size <= 0x10000):
        return None
    return Member(rva, size, SMALL_ERASE_ORDERED, elem_size=elem_size,
                  callee=insns[31].near_branch64, local_bytes=size_off - 8)


def _classify_resize_trivial(insns, rva, size):
    """113B (36 insns): Resize(newSize) for trivially constructible/destructible elements (Heap or Scrap)."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 36:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP
            and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.PUSH_R64 and insns[1].op0_register == Register.RDI
            and insns[2].code == Code.SUB_RM64_IMM8 and insns[2].op0_register == Register.RSP and insns[2].immediate8 == 0x30
            and insns[3].code == Code.MOV_R32_RM32 and insns[3].op0_register == Register.EBX and insns[3].op1_register == Register.EDX
            and insns[4].code == Code.MOV_R64_RM64 and insns[4].op0_register == Register.RDI and insns[4].op1_register == Register.RCX
            and insns[5].code == Code.MOV_R8_IMM8 and insns[5].op0_register == Register.AL and insns[5].immediate8 == 1
            and insns[6].code == Code.TEST_RM32_R32 and insns[6].op0_register == Register.EDX and insns[6].op1_register == Register.EDX
            and insns[7].code == Code.JE_REL8_64 and insns[7].near_branch64 == insns[31].ip
            and insns[8].code == Code.MOV_R32_RM32 and insns[8].op0_register == Register.R8D and insns[8].memory_base == Register.RCX
            and insns[9].code == Code.CMP_R32_RM32 and insns[9].op0_register == Register.EDX and insns[9].op1_register == Register.R8D
            and insns[10].code == Code.JNE_REL8_64 and insns[10].near_branch64 == insns[16].ip
            and insns[11].code == Code.MOV_RM32_R32 and insns[11].memory_base == Register.RCX and insns[11].op1_register == Register.EDX
            and insns[15].code == Code.RETNQ
            and insns[16].code == Code.MOV_R32_RM32 and insns[16].op0_register == Register.ECX and insns[16].memory_base == Register.RCX
            and insns[17].code == Code.CMP_R32_RM32 and insns[17].op0_register == Register.EBX and insns[17].op1_register == Register.ECX
            and insns[18].code == Code.JBE_REL8_64 and insns[18].near_branch64 == insns[31].ip
            and insns[19].code == Code.TEST_RM32_R32 and insns[19].op0_register == Register.ECX and insns[19].op1_register == Register.ECX
            and insns[20].code == Code.MOV_R64_RM64 and insns[20].op0_register == Register.RCX and insns[20].op1_register == Register.RDI
            and insns[21].code == Code.JNE_REL8_64 and insns[21].near_branch64 == insns[25].ip
            and insns[23].code == Code.CALL_REL32_64
            and insns[24].code == Code.JMP_REL8_64 and insns[24].near_branch64 == insns[29].ip
            and insns[26].code == Code.XOR_R32_RM32 and insns[26].op0_register == Register.R9D and insns[26].op1_register == Register.R9D
            and _is_imm_to_rsp(insns[27], 0x20) == 0
            and insns[28].code == Code.CALL_REL32_64
            and insns[29].code == Code.TEST_RM8_R8 and insns[29].op0_register == Register.AL and insns[29].op1_register == Register.AL
            and insns[30].code == Code.JE_REL8_64 and insns[30].near_branch64 == insns[32].ip
            and insns[31].code == Code.MOV_RM32_R32 and insns[31].memory_base == Register.RDI and insns[31].op1_register == Register.EBX
            and insns[35].code == Code.RETNQ):
        return None
    elem1 = _read_r8d_imm(insns[22])
    elem2 = _is_imm_to_rsp(insns[25], 0x28)
    if elem1 is None or elem1 != elem2 or not (1 <= elem1 <= 0x10000):
        return None
    cap_off = _signed_disp(insns[16])
    size_off = _signed_disp(insns[8])
    if _signed_disp(insns[11]) != size_off or _signed_disp(insns[31]) != size_off:
        return None
    if (cap_off, size_off) == (8, 0x10):
        is_scrap = False
    elif (cap_off, size_off) == (0x10, 0x18):
        is_scrap = True
    else:
        return None
    return Member(rva, size, RESIZE_TRIVIAL, elem_size=elem1, is_scrap=is_scrap,
                  callee=insns[23].near_branch64, callee2=insns[28].near_branch64)


def _classify_resize_construct(insns, rva, size):
    """140B/141B (45 insns): Resize(newSize) calling Alloc/Realloc + ConstructRange."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 45:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.MOV_RM64_R64 and insns[1].memory_base == Register.RSP and _signed_disp(insns[1]) == 0x10 and insns[1].op1_register == Register.RSI
            and insns[2].code == Code.PUSH_R64 and insns[2].op0_register == Register.RDI
            and insns[3].code == Code.SUB_RM64_IMM8 and insns[3].op0_register == Register.RSP and insns[3].immediate8 == 0x30
            and insns[4].code == Code.MOV_R32_RM32 and insns[4].op0_register == Register.EBX and insns[4].op1_register == Register.EDX
            and insns[5].code == Code.MOV_R64_RM64 and insns[5].op0_register == Register.RDI and insns[5].op1_register == Register.RCX
            and insns[6].code == Code.MOV_R8_IMM8 and insns[6].op0_register == Register.SIL and insns[6].immediate8 == 1
            and insns[7].code == Code.TEST_RM32_R32 and insns[7].op0_register == Register.EDX and insns[7].op1_register == Register.EDX
            and insns[8].code == Code.JE_REL8_64 and insns[8].near_branch64 == insns[38].ip
            and insns[9].code == Code.MOV_R32_RM32 and insns[9].op0_register == Register.EDX and insns[9].memory_base == Register.RCX
            and insns[10].code == Code.CMP_R32_RM32 and insns[10].op0_register == Register.EBX and insns[10].op1_register == Register.EDX
            and insns[11].code == Code.JE_REL8_64 and insns[11].near_branch64 == insns[38].ip
            and insns[12].code == Code.MOV_R32_RM32 and insns[12].op0_register == Register.EAX and insns[12].memory_base == Register.RCX
            and insns[13].code == Code.CMP_R32_RM32 and insns[13].op0_register == Register.EBX and insns[13].op1_register == Register.EAX
            and insns[14].code == Code.JBE_REL8_64 and insns[14].near_branch64 == insns[33].ip
            and insns[15].code == Code.TEST_RM32_R32 and insns[15].op0_register == Register.EAX and insns[15].op1_register == Register.EAX
            and insns[16].code == Code.JNE_REL8_64 and insns[16].near_branch64 == insns[21].ip
            and insns[18].code == Code.MOV_R32_RM32 and insns[18].op0_register == Register.EDX and insns[18].op1_register == Register.EBX
            and insns[19].code == Code.CALL_REL32_64
            and insns[20].code == Code.JMP_REL8_64 and insns[20].near_branch64 == insns[27].ip
            and insns[21].code == Code.MOV_R32_RM32 and insns[21].op0_register == Register.R8D and insns[21].op1_register == Register.EDX
            and insns[23].code == Code.MOV_R32_RM32 and insns[23].op0_register == Register.EDX and insns[23].op1_register == Register.EBX
            and _is_imm_to_rsp(insns[24], 0x20) == 0
            and insns[25].code == Code.XOR_R32_RM32 and insns[25].op0_register == Register.R9D and insns[25].op1_register == Register.R9D
            and insns[26].code == Code.CALL_REL32_64
            and insns[27].code == Code.MOVZX_R32_RM8 and insns[27].op0_register == Register.ESI and insns[27].op1_register == Register.AL
            and insns[28].code == Code.TEST_RM8_R8 and insns[28].op0_register == Register.AL and insns[28].op1_register == Register.AL
            and insns[29].code == Code.JE_REL8_64 and insns[29].near_branch64 == insns[39].ip
            and insns[30].code == Code.MOV_R32_RM32 and insns[30].op0_register == Register.EDX and insns[30].memory_base == Register.RDI
            and insns[31].code == Code.MOV_R64_RM64 and insns[31].op0_register == Register.RCX and insns[31].op1_register == Register.RDI
            and insns[32].code == Code.JMP_REL8_64 and insns[32].near_branch64 == insns[35].ip
            and insns[33].code == Code.CMP_R32_RM32 and insns[33].op0_register == Register.EBX and insns[33].op1_register == Register.EDX
            and insns[34].code == Code.JB_REL8_64 and insns[34].near_branch64 == insns[38].ip
            and insns[35].code == Code.MOV_R32_RM32 and insns[35].op0_register == Register.R8D and insns[35].op1_register == Register.EBX
            and insns[36].code == Code.SUB_R32_RM32 and insns[36].op0_register == Register.R8D and insns[36].op1_register == Register.EDX
            and insns[37].code == Code.CALL_REL32_64
            and insns[38].code == Code.MOV_RM32_R32 and insns[38].memory_base == Register.RDI and insns[38].op1_register == Register.EBX
            and insns[44].code == Code.RETNQ):
        return None
    elem1 = _read_r8d_imm(insns[17])
    elem2 = _is_imm_to_rsp(insns[22], 0x28)
    if elem1 is None or elem1 != elem2 or not (1 <= elem1 <= 0x10000):
        return None
    cap_off = _signed_disp(insns[12])
    size_off = _signed_disp(insns[9])
    if _signed_disp(insns[30]) != size_off or _signed_disp(insns[38]) != size_off:
        return None
    if (cap_off, size_off) == (8, 0x10):
        is_scrap = False
    elif (cap_off, size_off) == (0x10, 0x18):
        is_scrap = True
    else:
        return None
    return Member(rva, size, RESIZE_CONSTRUCT, elem_size=elem1, is_scrap=is_scrap,
                  callee=insns[19].near_branch64, callee2=insns[26].near_branch64,
                  callee3=insns[37].near_branch64)


def _classify_find_erase_ordered(insns, rva, size):
    """163B/164B (51 insns): linear find of 4B/8B *key + ordered erase via MoveElements."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 51:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.MOV_RM64_R64 and insns[1].memory_base == Register.RSP and _signed_disp(insns[1]) == 0x10 and insns[1].op1_register == Register.RSI
            and insns[2].code == Code.PUSH_R64 and insns[2].op0_register == Register.RDI
            and insns[3].code == Code.SUB_RM64_IMM8 and insns[3].op0_register == Register.RSP and insns[3].immediate8 == 0x30
            and insns[4].code == Code.MOV_R32_RM32 and insns[4].op0_register == Register.R10D and insns[4].memory_base == Register.RCX and _signed_disp(insns[4]) == 0x10
            and insns[5].code == Code.LEA_R64_M and insns[5].op0_register == Register.RDI and insns[5].memory_base == Register.RCX and _signed_disp(insns[5]) == 0x10
            and insns[6].code == Code.XOR_R32_RM32 and insns[6].op0_register == Register.R8D and insns[6].op1_register == Register.R8D
            and insns[7].code == Code.MOV_R32_IMM32 and insns[7].op0_register == Register.ESI and insns[7].immediate32 == 0xFFFFFFFF
            and insns[8].code == Code.MOV_R64_RM64 and insns[8].op0_register == Register.R11 and insns[8].op1_register == Register.RDX
            and insns[9].code == Code.MOV_R64_RM64 and insns[9].op0_register == Register.R9 and insns[9].op1_register == Register.RCX
            and insns[10].code == Code.MOV_R32_RM32 and insns[10].op0_register == Register.EBX and insns[10].op1_register == Register.ESI
            and insns[11].code == Code.TEST_RM32_R32 and insns[11].op0_register == Register.R10D and insns[11].op1_register == Register.R10D
            and insns[12].code == Code.JE_REL8_64 and insns[12].near_branch64 == insns[44].ip
            and insns[13].code == Code.NOP_RM32
            and insns[14].code == Code.MOV_R32_RM32 and insns[14].op0_register == Register.EAX and insns[14].op1_register == Register.R8D
            and insns[15].code == Code.CMP_R32_RM32 and insns[15].op0_register == Register.EBX and insns[15].op1_register == Register.ESI
            and insns[16].code == Code.JNE_REL8_64 and insns[16].near_branch64 == insns[28].ip
            and insns[17].code == Code.MOV_R64_RM64 and insns[17].op0_register == Register.RCX and insns[17].memory_base == Register.R9 and _signed_disp(insns[17]) == 0
            and insns[18].code == Code.MOV_R32_RM32 and insns[18].op0_register == Register.EBX and insns[18].op1_register == Register.EAX):
        return None
    i19, i20, i21, i22 = insns[19], insns[20], insns[21], insns[22]
    if (i19.code == Code.MOV_R64_RM64 and i19.op0_register == Register.RAX and i19.memory_base == Register.R11
            and i22.code == Code.CMP_RM64_R64 and i22.memory_base == Register.RCX and i22.memory_index == Register.RDX
            and i22.memory_index_scale == 8 and i22.op1_register == Register.RAX):
        elem_size = 8
    elif (i19.code == Code.MOV_R32_RM32 and i19.op0_register == Register.EAX and i19.memory_base == Register.R11
            and i22.code == Code.CMP_RM32_R32 and i22.memory_base == Register.RCX and i22.memory_index == Register.RDX
            and i22.memory_index_scale == 4 and i22.op1_register == Register.EAX):
        elem_size = 4
    else:
        return None
    if not (i20.code == Code.MOV_R32_RM32 and i20.op0_register == Register.EDX and i20.op1_register == Register.R8D
            and i21.code == Code.INC_RM32 and i21.op0_register == Register.R8D
            and insns[23].code == Code.CMOVNE_R32_RM32 and insns[23].op0_register == Register.EBX and insns[23].op1_register == Register.ESI
            and insns[24].code == Code.CMP_R32_RM32 and insns[24].op0_register == Register.R8D and insns[24].op1_register == Register.R10D
            and insns[25].code == Code.JB_REL8_64 and insns[25].near_branch64 == insns[14].ip
            and insns[26].code == Code.CMP_R32_RM32 and insns[26].op0_register == Register.EBX and insns[26].op1_register == Register.ESI
            and insns[27].code == Code.JE_REL8_64 and insns[27].near_branch64 == insns[45].ip
            and insns[28].code == Code.MOV_R64_RM64 and insns[28].op0_register == Register.RDX and insns[28].memory_base == Register.R9 and _signed_disp(insns[28]) == 0
            and insns[29].code == Code.CMP_RM32_IMM8 and insns[29].op0_register == Register.R10D and insns[29].immediate8 == 1
            and insns[30].code == Code.JNE_REL8_64 and insns[30].near_branch64 == insns[35].ip
            and insns[31].code == Code.TEST_RM64_R64 and insns[31].op0_register == Register.RDX and insns[31].op1_register == Register.RDX
            and insns[32].code == Code.JE_REL8_64 and insns[32].near_branch64 == insns[44].ip
            and insns[33].code == Code.MOV_RM32_IMM32 and insns[33].memory_base == Register.RDI and _signed_disp(insns[33]) == 0 and insns[33].immediate32 == 0
            and insns[34].code == Code.JMP_REL8_64 and insns[34].near_branch64 == insns[44].ip
            and insns[35].code == Code.SUB_R32_RM32 and insns[35].op0_register == Register.R10D and insns[35].op1_register == Register.EBX
            and _is_imm_to_rsp(insns[36], 0x28) == elem_size
            and insns[37].code == Code.DEC_RM32 and insns[37].op0_register == Register.R10D
            and insns[38].code == Code.LEA_R32_M and insns[38].op0_register == Register.R9D and insns[38].memory_base == Register.RBX and _signed_disp(insns[38]) == 1
            and insns[39].code == Code.MOV_R32_RM32 and insns[39].op0_register == Register.R8D and insns[39].op1_register == Register.EBX
            and insns[40].code == Code.MOV_RM32_R32 and insns[40].memory_base == Register.RSP and _signed_disp(insns[40]) == 0x20 and insns[40].op1_register == Register.R10D
            and insns[41].code == Code.MOV_R64_RM64 and insns[41].op0_register == Register.RCX and insns[41].op1_register == Register.RDI
            and insns[42].code == Code.CALL_REL32_64
            and insns[43].code == Code.ADD_RM32_R32 and insns[43].memory_base == Register.RDI and _signed_disp(insns[43]) == 0 and insns[43].op1_register == Register.ESI
            and insns[44].code == Code.CMP_R32_RM32 and insns[44].op0_register == Register.EBX and insns[44].op1_register == Register.ESI
            and insns[46].code == Code.SETNE_RM8 and insns[46].op0_register == Register.AL
            and insns[50].code == Code.RETNQ):
        return None
    return Member(rva, size, FIND_ERASE_ORDERED, elem_size=elem_size, callee=insns[42].near_branch64)


def _classify_find_erase_unordered(insns, rva, size):
    """153B/154B (49 insns): linear find of 4B/8B *key + unordered swap-tail erase via MoveElements."""
    from iced_x86 import Code, OpKind, Register
    if len(insns) != 49:
        return None
    if not (insns[0].code == Code.MOV_RM64_R64 and insns[0].memory_base == Register.RSP and _signed_disp(insns[0]) == 8 and insns[0].op1_register == Register.RBX
            and insns[1].code == Code.MOV_RM64_R64 and insns[1].memory_base == Register.RSP and _signed_disp(insns[1]) == 0x10 and insns[1].op1_register == Register.RSI
            and insns[2].code == Code.PUSH_R64 and insns[2].op0_register == Register.RDI
            and insns[3].code == Code.SUB_RM64_IMM8 and insns[3].op0_register == Register.RSP and insns[3].immediate8 == 0x30
            and insns[4].code == Code.MOV_R32_RM32 and insns[4].op0_register == Register.R9D and insns[4].memory_base == Register.RCX and _signed_disp(insns[4]) == 0x10
            and insns[5].code == Code.LEA_R64_M and insns[5].op0_register == Register.RDI and insns[5].memory_base == Register.RCX and _signed_disp(insns[5]) == 0x10
            and insns[6].code == Code.XOR_R32_RM32 and insns[6].op0_register == Register.R8D and insns[6].op1_register == Register.R8D
            and insns[7].code == Code.MOV_R32_IMM32 and insns[7].op0_register == Register.ESI and insns[7].immediate32 == 0xFFFFFFFF
            and insns[8].code == Code.MOV_R64_RM64 and insns[8].op0_register == Register.R11 and insns[8].op1_register == Register.RDX
            and insns[9].code == Code.MOV_R64_RM64 and insns[9].op0_register == Register.R10 and insns[9].op1_register == Register.RCX
            and insns[10].code == Code.MOV_R32_RM32 and insns[10].op0_register == Register.EBX and insns[10].op1_register == Register.ESI
            and insns[11].code == Code.TEST_RM32_R32 and insns[11].op0_register == Register.R9D and insns[11].op1_register == Register.R9D
            and insns[12].code == Code.JE_REL8_64 and insns[12].near_branch64 == insns[42].ip
            and insns[13].code == Code.NOP_RM32
            and insns[14].code == Code.MOV_R32_RM32 and insns[14].op0_register == Register.EAX and insns[14].op1_register == Register.R8D
            and insns[15].code == Code.CMP_R32_RM32 and insns[15].op0_register == Register.EBX and insns[15].op1_register == Register.ESI
            and insns[16].code == Code.JNE_REL8_64 and insns[16].near_branch64 == insns[28].ip
            and insns[17].code == Code.MOV_R64_RM64 and insns[17].op0_register == Register.RCX and insns[17].memory_base == Register.R10 and _signed_disp(insns[17]) == 0
            and insns[18].code == Code.MOV_R32_RM32 and insns[18].op0_register == Register.EBX and insns[18].op1_register == Register.EAX):
        return None
    i19, i20, i21, i22 = insns[19], insns[20], insns[21], insns[22]
    if (i19.code == Code.MOV_R64_RM64 and i19.op0_register == Register.RAX and i19.memory_base == Register.R11
            and i22.code == Code.CMP_RM64_R64 and i22.memory_base == Register.RCX and i22.memory_index == Register.RDX
            and i22.memory_index_scale == 8 and i22.op1_register == Register.RAX):
        elem_size = 8
    elif (i19.code == Code.MOV_R32_RM32 and i19.op0_register == Register.EAX and i19.memory_base == Register.R11
            and i22.code == Code.CMP_RM32_R32 and i22.memory_base == Register.RCX and i22.memory_index == Register.RDX
            and i22.memory_index_scale == 4 and i22.op1_register == Register.EAX):
        elem_size = 4
    else:
        return None
    if not (i20.code == Code.MOV_R32_RM32 and i20.op0_register == Register.EDX and i20.op1_register == Register.R8D
            and i21.code == Code.INC_RM32 and i21.op0_register == Register.R8D
            and insns[23].code == Code.CMOVNE_R32_RM32 and insns[23].op0_register == Register.EBX and insns[23].op1_register == Register.ESI
            and insns[24].code == Code.CMP_R32_RM32 and insns[24].op0_register == Register.R8D and insns[24].op1_register == Register.R9D
            and insns[25].code == Code.JB_REL8_64 and insns[25].near_branch64 == insns[14].ip
            and insns[26].code == Code.CMP_R32_RM32 and insns[26].op0_register == Register.EBX and insns[26].op1_register == Register.ESI
            and insns[27].code == Code.JE_REL8_64 and insns[27].near_branch64 == insns[43].ip
            and insns[28].code == Code.MOV_R64_RM64 and insns[28].op0_register == Register.RDX and insns[28].memory_base == Register.R10 and _signed_disp(insns[28]) == 0
            and insns[29].code == Code.MOV_R32_RM32 and insns[29].op0_register == Register.EAX and insns[29].op1_register == Register.R9D
            and insns[30].code == Code.SUB_R32_RM32 and insns[30].op0_register == Register.EAX and insns[30].op1_register == Register.EBX
            and _is_imm_to_rsp(insns[31], 0x28) == elem_size
            and insns[32].code == Code.DEC_RM32 and insns[32].op0_register == Register.EAX
            and insns[33].code == Code.MOV_R32_IMM32 and insns[33].op0_register == Register.ECX and insns[33].immediate32 == 1
            and insns[34].code == Code.CMP_R32_RM32 and insns[34].op0_register == Register.EAX and insns[34].op1_register == Register.ECX
            and insns[35].code == Code.MOV_R32_RM32 and insns[35].op0_register == Register.R8D and insns[35].op1_register == Register.EBX
            and insns[36].code == Code.CMOVB_R32_RM32 and insns[36].op0_register == Register.ECX and insns[36].op1_register == Register.EAX
            and insns[37].code == Code.SUB_R32_RM32 and insns[37].op0_register == Register.R9D and insns[37].op1_register == Register.ECX
            and insns[38].code == Code.MOV_RM32_R32 and insns[38].memory_base == Register.RSP and _signed_disp(insns[38]) == 0x20 and insns[38].op1_register == Register.ECX
            and insns[39].code == Code.MOV_R64_RM64 and insns[39].op0_register == Register.RCX and insns[39].op1_register == Register.RDI
            and insns[40].code == Code.CALL_REL32_64
            and insns[41].code == Code.ADD_RM32_R32 and insns[41].memory_base == Register.RDI and _signed_disp(insns[41]) == 0 and insns[41].op1_register == Register.ESI
            and insns[42].code == Code.CMP_R32_RM32 and insns[42].op0_register == Register.EBX and insns[42].op1_register == Register.ESI
            and insns[44].code == Code.SETNE_RM8 and insns[44].op0_register == Register.AL
            and insns[48].code == Code.RETNQ):
        return None
    return Member(rva, size, FIND_ERASE_UNORDERED, elem_size=elem_size, callee=insns[40].near_branch64)


def classify(code, rva):
    from iced_x86 import Decoder
    size = len(code)
    if size not in CANDIDATE_SIZES:
        return None
    insns = list(Decoder(64, code, ip=rva))
    if not insns or sum(i.len for i in insns) != size:
        return None
    for fn in (
        _classify_release,
        _classify_erase_unordered,
        _classify_erase_ordered,
        _classify_small_erase_ordered,
        _classify_resize_trivial,
        _classify_resize_construct,
        _classify_find_erase_ordered,
        _classify_find_erase_unordered,
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


def _validate_callees(image, m, starts):
    for c in m.all_callees():
        if not leaf_family_batch.indexed_callee(image, SimpleNamespace(rva=m.rva, size=m.size, callee=c), starts):
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
        and _validate_callees(image, m, starts)
    ]
    sharded = _shard(raw)
    by_fam = {}
    for m in sharded:
        by_fam.setdefault(m.family, set()).add(m.rva)
    return [m for m in sharded if not any(c in by_fam[m.family] for c in m.all_callees())]


def _mangled(family, m):
    bf = m.base_family
    if bf == ERASE_UNORDERED:
        st = 'BSTArrayScrap' if m.is_scrap else 'BSTArrayHeap'
        return f'?{m.name}@{family}@@SAXPEAU{st}@@II@Z'
    if bf == ERASE_ORDERED:
        st = 'BSTArrayScrap' if m.is_scrap else 'BSTArrayHeap'
        return f'?{m.name}@{family}@@SAXPEAU{st}@@II@Z'
    if bf == SMALL_ERASE_ORDERED:
        return f'?{m.name}@{family}@@SAXPEAUBSTSmallArray_{m.local_bytes}@@II@Z'
    if bf in (RESIZE_TRIVIAL, RESIZE_CONSTRUCT):
        st = 'BSTArrayScrap' if m.is_scrap else 'BSTArrayHeap'
        return f'?{m.name}@{family}@@SA_NPEAU{st}@@I@Z'
    if bf in (FIND_ERASE_ORDERED, FIND_ERASE_UNORDERED):
        pt = 'PEB_K' if m.elem_size == 8 else 'PEBI'
        return f'?{m.name}@{family}@@SA_NPEAUBSTArrayHeap@@{pt}@Z'
    if bf == ARRAY_RELEASE:
        st = 'BSTArrayScrap' if m.is_scrap else 'BSTArrayHeap'
        return f'?{m.name}@{family}@@SAXPEAU{st}@@@Z'
    raise ValueError(bf)


def emit(root, family, members, build_id, label):
    bf = members[0].base_family
    prefix = [
        '// Source exposure: mixed (pinned image and community function boundaries).',
        f'// Boundary source: {label}',
        '// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.',
        f'// {family}, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.',
        '// Adapted bodies: none',
    ]
    header = prefix + ['#pragma once', '#include <cstdint>', '']
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"', '']
    symbols = {}

    need_heap = any(not m.is_scrap and bf != SMALL_ERASE_ORDERED for m in members)
    need_scrap = any(m.is_scrap for m in members)
    need_small = (bf == SMALL_ERASE_ORDERED)

    if need_heap:
        header.extend([
            'struct BSTArrayHeap {',
            '    void* data;',
            '    std::uint32_t capacity;',
            '    alignas(8) std::uint32_t size;',
            '};',
            '',
        ])
    if need_scrap:
        header.extend([
            'struct BSTArrayScrap {',
            '    void* allocator;',
            '    void* data;',
            '    std::uint32_t capacity;',
            '    alignas(8) std::uint32_t size;',
            '};',
            '',
        ])
    if need_small:
        for lb in sorted({m.local_bytes for m in members}):
            header.extend([
                f'struct BSTSmallArray_{lb} {{',
                '    std::int32_t capacity;',
                '    union {',
                '        void* heapData;',
                f'        std::uint8_t localData[{lb}];',
                '    };',
                '    std::uint32_t size;',
                '    void* Data() {',
                '        return (capacity < 0) ? static_cast<void*>(localData) : heapData;',
                '    }',
                '};',
                '',
            ])

    # External callee declarations
    if bf in (ERASE_UNORDERED, ERASE_ORDERED, SMALL_ERASE_ORDERED, FIND_ERASE_ORDERED, FIND_ERASE_UNORDERED):
        for c in sorted({m.callee for m in members}):
            nm = f'ArrayMove_{c:x}'
            header.append(f'extern "C" void __cdecl {nm}(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);')
            symbols[nm] = dict(rva=c, size=None)
    elif bf in (RESIZE_TRIVIAL, RESIZE_CONSTRUCT):
        allocs = sorted({(m.callee, m.is_scrap) for m in members})
        reallocs = sorted({(m.callee2, m.is_scrap) for m in members})
        ctors = sorted({(m.callee3, m.is_scrap) for m in members if m.callee3})
        for c, sc in allocs:
            st = 'BSTArrayScrap' if sc else 'BSTArrayHeap'
            nm = f'ArrayAlloc_{c:x}'
            if nm not in symbols:
                header.append(f'extern "C" bool __cdecl {nm}({st}* self, std::uint32_t cap, std::uint32_t elemSize);')
                symbols[nm] = dict(rva=c, size=None)
        for c, sc in reallocs:
            st = 'BSTArrayScrap' if sc else 'BSTArrayHeap'
            nm = f'ArrayRealloc_{c:x}'
            if nm not in symbols:
                header.append(f'extern "C" bool __cdecl {nm}({st}* self, std::uint32_t newCap, std::uint32_t oldSize, std::uint32_t extra1, std::uint32_t extra2, std::uint32_t elemSize);')
                symbols[nm] = dict(rva=c, size=None)
        for c, sc in ctors:
            st = 'BSTArrayScrap' if sc else 'BSTArrayHeap'
            nm = f'ArrayConstruct_{c:x}'
            if nm not in symbols:
                header.append(f'extern "C" void __cdecl {nm}({st}* self, std::uint32_t start, std::uint32_t count);')
                symbols[nm] = dict(rva=c, size=None)
    elif bf == ARRAY_RELEASE:
        for c, sc in sorted({(m.callee, m.is_scrap) for m in members}):
            st = 'BSTArrayScrap' if sc else 'BSTArrayHeap'
            nm = f'ArrayDealloc_{c:x}'
            if nm not in symbols:
                header.append(f'extern "C" void __cdecl {nm}({st}* self);')
                symbols[nm] = dict(rva=c, size=None)

    header.extend(['', f'struct {family} {{'])
    functions = []
    for m in members:
        st = 'BSTArrayScrap' if m.is_scrap else 'BSTArrayHeap'
        if bf == ERASE_UNORDERED:
            header.append(f'    static void {m.name}({st}* self, std::uint32_t pos, std::uint32_t count);')
            source.extend([
                f'void {family}::{m.name}({st}* self, std::uint32_t pos, std::uint32_t count)',
                '{',
                '    std::uint32_t size = self->size;',
                '    std::uint32_t tail = size - pos - count;',
                '    std::uint32_t moveCount = (tail < count) ? tail : count;',
                f'    ArrayMove_{m.callee:x}(&self->size, self->data, pos, size - moveCount, moveCount, {m.elem_size}u);',
                '    self->size -= count;',
                '}',
                '',
            ])
        elif bf == ERASE_ORDERED:
            header.append(f'    static void {m.name}({st}* self, std::uint32_t pos, std::uint32_t count);')
            source.extend([
                f'void {family}::{m.name}({st}* self, std::uint32_t pos, std::uint32_t count)',
                '{',
                '    std::uint32_t size = self->size;',
                '    void* data = self->data;',
                '    if (count == size) {',
                '        if (data) {',
                '            self->size = 0u;',
                '        }',
                '        return;',
                '    }',
                f'    ArrayMove_{m.callee:x}(&self->size, data, pos, pos + count, size - pos - count, {m.elem_size}u);',
                '    self->size -= count;',
                '}',
                '',
            ])
        elif bf == SMALL_ERASE_ORDERED:
            sm = f'BSTSmallArray_{m.local_bytes}'
            header.append(f'    static void {m.name}({sm}* self, std::uint32_t pos, std::uint32_t count);')
            source.extend([
                f'void {family}::{m.name}({sm}* self, std::uint32_t pos, std::uint32_t count)',
                '{',
                '    std::uint32_t size = self->size;',
                '    if (count == size) {',
                '        if (self->Data()) {',
                '            self->size = 0u;',
                '        }',
                '        return;',
                '    }',
                '    std::uint32_t tail = size - pos - count;',
                f'    ArrayMove_{m.callee:x}(&self->size, self->Data(), pos, pos + count, tail, {m.elem_size}u);',
                '    self->size -= count;',
                '}',
                '',
            ])
        elif bf == RESIZE_TRIVIAL:
            header.append(f'    static bool {m.name}({st}* self, std::uint32_t newSize);')
            source.extend([
                f'bool {family}::{m.name}({st}* self, std::uint32_t newSize)',
                '{',
                '    bool ok = true;',
                '    if (newSize != 0u) {',
                '        std::uint32_t oldSize = self->size;',
                '        if (newSize == oldSize) {',
                '            self->size = newSize;',
                '            return true;',
                '        }',
                '        if (newSize > self->capacity) {',
                '            if (self->capacity == 0u) {',
                f'                ok = ArrayAlloc_{m.callee:x}(self, newSize, {m.elem_size}u);',
                '            } else {',
                f'                ok = ArrayRealloc_{m.callee2:x}(self, newSize, oldSize, 0u, 0u, {m.elem_size}u);',
                '            }',
                '        }',
                '    }',
                '    if (ok) {',
                '        self->size = newSize;',
                '    }',
                '    return ok;',
                '}',
                '',
            ])
        elif bf == RESIZE_CONSTRUCT:
            header.append(f'    static bool {m.name}({st}* self, std::uint32_t newSize);')
            source.extend([
                f'bool {family}::{m.name}({st}* self, std::uint32_t newSize)',
                '{',
                '    bool ok = true;',
                '    if (newSize != 0u) {',
                '        std::uint32_t oldSize = self->size;',
                '        if (newSize != oldSize) {',
                '            if (newSize > self->capacity) {',
                '                if (self->capacity == 0u) {',
                f'                    ok = ArrayAlloc_{m.callee:x}(self, newSize, {m.elem_size}u);',
                '                } else {',
                f'                    ok = ArrayRealloc_{m.callee2:x}(self, newSize, oldSize, 0u, 0u, {m.elem_size}u);',
                '                }',
                '                if (ok) {',
                f'                    ArrayConstruct_{m.callee3:x}(self, self->size, newSize - self->size);',
                '                }',
                '            } else if (newSize >= oldSize) {',
                f'                ArrayConstruct_{m.callee3:x}(self, oldSize, newSize - oldSize);',
                '            }',
                '        }',
                '    }',
                '    if (ok) {',
                '        self->size = newSize;',
                '    }',
                '    return ok;',
                '}',
                '',
            ])
        elif bf == FIND_ERASE_ORDERED:
            et = 'std::uint64_t' if m.elem_size == 8 else 'std::uint32_t'
            header.append(f'    static bool {m.name}(BSTArrayHeap* self, const {et}* key);')
            source.extend([
                f'bool {family}::{m.name}(BSTArrayHeap* self, const {et}* key)',
                '{',
                '    std::uint32_t size = self->size;',
                '    std::uint32_t found = 0xFFFFFFFFu;',
                '    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {',
                f'        if (static_cast<const {et}*>(self->data)[i] == *key) {{',
                '            found = i;',
                '        }',
                '    }',
                '    if (found != 0xFFFFFFFFu) {',
                '        void* data = self->data;',
                '        if (size == 1u) {',
                '            if (data) {',
                '                self->size = 0u;',
                '            }',
                '        } else {',
                f'            ArrayMove_{m.callee:x}(&self->size, data, found, found + 1u, size - found - 1u, {m.elem_size}u);',
                '            --self->size;',
                '        }',
                '    }',
                '    return found != 0xFFFFFFFFu;',
                '}',
                '',
            ])
        elif bf == FIND_ERASE_UNORDERED:
            et = 'std::uint64_t' if m.elem_size == 8 else 'std::uint32_t'
            header.append(f'    static bool {m.name}(BSTArrayHeap* self, const {et}* key);')
            source.extend([
                f'bool {family}::{m.name}(BSTArrayHeap* self, const {et}* key)',
                '{',
                '    std::uint32_t size = self->size;',
                '    std::uint32_t found = 0xFFFFFFFFu;',
                '    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {',
                f'        if (static_cast<const {et}*>(self->data)[i] == *key) {{',
                '            found = i;',
                '        }',
                '    }',
                '    if (found != 0xFFFFFFFFu) {',
                '        std::uint32_t tail = size - found - 1u;',
                '        std::uint32_t moveCount = (tail < 1u) ? tail : 1u;',
                f'        ArrayMove_{m.callee:x}(&self->size, self->data, found, size - moveCount, moveCount, {m.elem_size}u);',
                '        --self->size;',
                '    }',
                '    return found != 0xFFFFFFFFu;',
                '}',
                '',
            ])
        elif bf == ARRAY_RELEASE:
            header.append(f'    static void {m.name}({st}* self);')
            source.extend([
                f'void {family}::{m.name}({st}* self)',
                '{',
                '    if (self->data) {',
                f'        ArrayDealloc_{m.callee:x}(self);',
                '        self->size = 0u;',
                '    }',
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
