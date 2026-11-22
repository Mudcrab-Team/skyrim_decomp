"""Bethesda BSTArray container helper generator tests on an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import bst_array_generate as generator
import check_code_rules
import contrib_screen
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe

# Short generic x86-64 instruction encoder helpers (strictly original, zero game constants)
def _i8(v):
    return struct.pack('<b', v)


def _u32(v):
    return struct.pack('<I', v)


def _rel32(pos, length, target):
    return struct.pack('<i', target - (pos + length))


def _call(pos, target):
    return bytes([0xe8]) + _rel32(pos, 5, target)


def _jcc8(op, pos, target):
    return bytes([op]) + _i8(target - (pos + 2))


def _mov_rsp_disp8_r64(disp, reg_modrm):
    return bytes([0x48, 0x89, reg_modrm, 0x24, disp])


def _mov_r64_rsp_disp8(disp, reg_modrm):
    return bytes([0x48, 0x8b, reg_modrm, 0x24, disp])


def _mov_rsp_disp8_imm32(disp, imm):
    return bytes([0xc7, 0x44, 0x24, disp]) + _u32(imm)


def _sub_rsp(n):
    return bytes([0x48, 0x83, 0xec, n])


def _add_rsp(n):
    return bytes([0x48, 0x83, 0xc4, n])


def _push_rbx():
    return bytes([0x53])


def _pop_rbx():
    return bytes([0x5b])


def _push_rdi():
    return bytes([0x57])


def _pop_rdi():
    return bytes([0x5f])


def _ret():
    return bytes([0xc3])


def _mk_release(pos, callee, *, is_scrap=False):
    """Build 33B/34B BSTArrayRelease."""
    data_off = 8 if is_scrap else 0
    size_off = 0x18 if is_scrap else 0x10
    b = bytearray()
    b += bytes([0x40, 0x53])  # push rbx (REX-prefixed 2-byte form emitted by MSVC x64)
    b += _sub_rsp(0x20)
    if data_off == 0:
        b += bytes([0x48, 0x83, 0x39, 0x00])  # cmp qword [rcx], 0
    else:
        b += bytes([0x48, 0x83, 0x79, data_off, 0x00])  # cmp qword [rcx+8], 0
    b += bytes([0x48, 0x8b, 0xd9])  # mov rbx, rcx
    je_pos = len(b)
    b += bytes([0x74, 0x00])  # je epilogue
    b += _call(pos + len(b), callee)
    b += bytes([0xc7, 0x43, size_off]) + _u32(0)  # mov dword [rbx+size_off], 0
    ep = len(b)
    b[je_pos + 1] = ep - (je_pos + 2)
    b += _add_rsp(0x20)
    b += _pop_rbx()
    b += _ret()
    return bytes(b)


def _mk_erase_unordered(pos, callee, elem_size, *, is_scrap=False):
    """Build 82B/83B BSTArrayEraseUnordered."""
    data_off = 8 if is_scrap else 0
    size_off = 0x18 if is_scrap else 0x10
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)  # mov [rsp+8], rbx
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x44, 0x8b, 0x49, size_off])  # mov r9d, [rcx+size_off]
    b += bytes([0x48, 0x8d, 0x59, size_off])  # lea rbx, [rcx+size_off]
    b += bytes([0x41, 0x8b, 0xc1])  # mov eax, r9d
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x2b, 0xc2])  # sub eax, edx
    b += bytes([0x45, 0x8b, 0xd0])  # mov r10d, r8d
    b += bytes([0x41, 0x2b, 0xc0])  # sub eax, r8d
    b += bytes([0x41, 0x8b, 0xf8])  # mov edi, r8d
    b += bytes([0x41, 0x3b, 0xc0])  # cmp eax, r8d
    b += bytes([0x44, 0x8b, 0xc2])  # mov r8d, edx
    if data_off == 0:
        b += bytes([0x48, 0x8b, 0x11])  # mov rdx, [rcx]
    else:
        b += bytes([0x48, 0x8b, 0x51, data_off])  # mov rdx, [rcx+8]
    b += bytes([0x48, 0x8b, 0xcb])  # mov rcx, rbx
    b += bytes([0x44, 0x0f, 0x42, 0xd0])  # cmovb r10d, eax
    b += bytes([0x45, 0x2b, 0xca])  # sub r9d, r10d
    b += bytes([0x44, 0x89, 0x54, 0x24, 0x20])  # mov [rsp+20h], r10d
    b += _call(pos + len(b), callee)
    b += bytes([0x29, 0x3b])  # sub [rbx], edi
    b += _mov_r64_rsp_disp8(0x40, 0x5c)  # mov rbx, [rsp+40h]
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_erase_ordered(pos, callee, elem_size, *, is_scrap=False):
    """Build 94B/95B BSTArrayEraseOrdered."""
    data_off = 8 if is_scrap else 0
    size_off = 0x18 if is_scrap else 0x10
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x8b, 0x41, size_off])  # mov eax, [rcx+size_off]
    b += bytes([0x48, 0x8d, 0x59, size_off])  # lea rbx, [rcx+size_off]
    b += bytes([0x41, 0x8b, 0xf8])  # mov edi, r8d
    b += bytes([0x44, 0x8b, 0xc2])  # mov r8d, edx
    if data_off == 0:
        b += bytes([0x48, 0x8b, 0x11])
    else:
        b += bytes([0x48, 0x8b, 0x51, data_off])
    b += bytes([0x3b, 0xf8])  # cmp edi, eax
    jne_pos = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x48, 0x85, 0xd2])  # test rdx, rdx
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0xc7, 0x03]) + _u32(0)  # mov dword [rbx], 0
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    shift_pos = len(b)
    b[jne_pos + 1] = shift_pos - (jne_pos + 2)
    b += bytes([0x41, 0x2b, 0xc0])  # sub eax, r8d
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x2b, 0xc7])  # sub eax, edi
    b += bytes([0x45, 0x8d, 0x0c, 0x38])  # lea r9d, [r8+rdi]
    b += bytes([0x48, 0x8b, 0xcb])  # mov rcx, rbx
    b += bytes([0x89, 0x44, 0x24, 0x20])  # mov [rsp+20h], eax
    b += _call(pos + len(b), callee)
    b += bytes([0x29, 0x3b])  # sub [rbx], edi
    ep = len(b)
    b[je_pos + 1] = ep - (je_pos + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_small_erase_ordered(pos, callee, elem_size, local_bytes=16):
    """Build 117B BSTSmallArrayEraseOrdered."""
    size_off = 8 + local_bytes
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x8b, 0x41, size_off])  # mov eax, [rcx+size_off]
    b += bytes([0x48, 0x8d, 0x59, size_off])  # lea rbx, [rcx+size_off]
    b += bytes([0x41, 0x8b, 0xf8])  # mov edi, r8d
    b += bytes([0x44, 0x8b, 0xd2])  # mov r10d, edx
    b += bytes([0x44, 0x8b, 0x01])  # mov r8d, [rcx]
    b += bytes([0x48, 0x8d, 0x51, 0x08])  # lea rdx, [rcx+8]
    b += bytes([0x3b, 0xf8])  # cmp edi, eax
    jne_pos = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x45, 0x85, 0xc0])  # test r8d, r8d
    b += bytes([0x78, 0x03])  # js +3
    b += bytes([0x48, 0x8b, 0x12])  # mov rdx, [rdx]
    b += bytes([0x48, 0x85, 0xd2])  # test rdx, rdx
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0xc7, 0x03]) + _u32(0)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    shift_pos = len(b)
    b[jne_pos + 1] = shift_pos - (jne_pos + 2)
    b += bytes([0x41, 0x2b, 0xc2])  # sub eax, r10d
    b += bytes([0x2b, 0xc7])  # sub eax, edi
    b += bytes([0x45, 0x85, 0xc0])  # test r8d, r8d
    b += bytes([0x78, 0x03])  # js +3
    b += bytes([0x48, 0x8b, 0x12])  # mov rdx, [rdx]
    b += bytes([0x45, 0x8d, 0x0c, 0x3a])  # lea r9d, [r10+rdi]
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x45, 0x8b, 0xc2])  # mov r8d, r10d
    b += bytes([0x89, 0x44, 0x24, 0x20])
    b += bytes([0x48, 0x8b, 0xcb])
    b += _call(pos + len(b), callee)
    b += bytes([0x29, 0x3b])
    ep = len(b)
    b[je_pos + 1] = ep - (je_pos + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_resize_trivial(pos, alloc_fn, realloc_fn, elem_size, *, is_scrap=False):
    """Build 113B BSTArrayResizeTrivial."""
    cap_off = 0x10 if is_scrap else 8
    size_off = 0x18 if is_scrap else 0x10
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x8b, 0xda])  # mov ebx, edx
    b += bytes([0x48, 0x8b, 0xf9])  # mov rdi, rcx
    b += bytes([0xb0, 0x01])  # mov al, 1
    b += bytes([0x85, 0xd2])  # test edx, edx
    je1 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x44, 0x8b, 0x41, size_off])  # mov r8d, [rcx+size_off]
    b += bytes([0x41, 0x3b, 0xd0])  # cmp edx, r8d
    jne1 = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x89, 0x51, size_off])  # mov [rcx+size_off], edx
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    cap_lbl = len(b)
    b[jne1 + 1] = cap_lbl - (jne1 + 2)
    b += bytes([0x8b, 0x49, cap_off])  # mov ecx, [rcx+cap_off]
    b += bytes([0x3b, 0xd9])  # cmp ebx, ecx
    jbe1 = len(b)
    b += bytes([0x76, 0x00])
    b += bytes([0x85, 0xc9])  # test ecx, ecx
    b += bytes([0x48, 0x8b, 0xcf])  # mov rcx, rdi
    jne2 = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x41, 0xb8]) + _u32(elem_size)  # mov r8d, elem_size
    b += _call(pos + len(b), alloc_fn)
    jmp1 = len(b)
    b += bytes([0xeb, 0x00])
    realloc_lbl = len(b)
    b[jne2 + 1] = realloc_lbl - (jne2 + 2)
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x45, 0x33, 0xc9])  # xor r9d, r9d
    b += _mov_rsp_disp8_imm32(0x20, 0)
    b += _call(pos + len(b), realloc_fn)
    chk_lbl = len(b)
    b[jmp1 + 1] = chk_lbl - (jmp1 + 2)
    b += bytes([0x84, 0xc0])  # test al, al
    je2 = len(b)
    b += bytes([0x74, 0x00])
    set_lbl = len(b)
    b[je1 + 1] = set_lbl - (je1 + 2)
    b[jbe1 + 1] = set_lbl - (jbe1 + 2)
    b += bytes([0x89, 0x5f, size_off])  # mov [rdi+size_off], ebx
    ep = len(b)
    b[je2 + 1] = ep - (je2 + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_resize_construct(pos, alloc_fn, realloc_fn, ctor_fn, elem_size, *, is_scrap=False):
    """Build 140B BSTArrayResizeConstruct."""
    cap_off = 0x10 if is_scrap else 8
    size_off = 0x18 if is_scrap else 0x10
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _mov_rsp_disp8_r64(0x10, 0x74)  # mov [rsp+10h], rsi
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x8b, 0xda])  # mov ebx, edx
    b += bytes([0x48, 0x8b, 0xf9])  # mov rdi, rcx
    b += bytes([0x40, 0xb6, 0x01])  # mov sil, 1
    b += bytes([0x85, 0xd2])  # test edx, edx
    je1 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x8b, 0x51, size_off])  # mov edx, [rcx+size_off]
    b += bytes([0x3b, 0xda])  # cmp ebx, edx
    je2 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x8b, 0x41, cap_off])  # mov eax, [rcx+cap_off]
    b += bytes([0x3b, 0xd8])  # cmp ebx, eax
    jbe1 = len(b)
    b += bytes([0x76, 0x00])
    b += bytes([0x85, 0xc0])  # test eax, eax
    jne1 = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x44, 0x8d, 0x40, elem_size])  # lea r8d, [rax+elem_size]
    b += bytes([0x8b, 0xd3])  # mov edx, ebx
    b += _call(pos + len(b), alloc_fn)
    jmp1 = len(b)
    b += bytes([0xeb, 0x00])
    realloc_lbl = len(b)
    b[jne1 + 1] = realloc_lbl - (jne1 + 2)
    b += bytes([0x44, 0x8b, 0xc2])  # mov r8d, edx
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x8b, 0xd3])  # mov edx, ebx
    b += _mov_rsp_disp8_imm32(0x20, 0)
    b += bytes([0x45, 0x33, 0xc9])  # xor r9d, r9d
    b += _call(pos + len(b), realloc_fn)
    chk_lbl = len(b)
    b[jmp1 + 1] = chk_lbl - (jmp1 + 2)
    b += bytes([0x0f, 0xb6, 0xf0])  # movzx esi, al
    b += bytes([0x84, 0xc0])  # test al, al
    je3 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x8b, 0x57, size_off])  # mov edx, [rdi+size_off]
    b += bytes([0x48, 0x8b, 0xcf])  # mov rcx, rdi
    jmp2 = len(b)
    b += bytes([0xeb, 0x00])
    nocap_lbl = len(b)
    b[jbe1 + 1] = nocap_lbl - (jbe1 + 2)
    b += bytes([0x3b, 0xda])  # cmp ebx, edx
    jb1 = len(b)
    b += bytes([0x72, 0x00])
    ctor_lbl = len(b)
    b[jmp2 + 1] = ctor_lbl - (jmp2 + 2)
    b += bytes([0x44, 0x8b, 0xc3])  # mov r8d, ebx
    b += bytes([0x44, 0x2b, 0xc2])  # sub r8d, edx
    b += _call(pos + len(b), ctor_fn)
    set_lbl = len(b)
    b[je1 + 1] = set_lbl - (je1 + 2)
    b[je2 + 1] = set_lbl - (je2 + 2)
    b[jb1 + 1] = set_lbl - (jb1 + 2)
    b += bytes([0x89, 0x5f, size_off])  # mov [rdi+size_off], ebx
    ep = len(b)
    b[je3 + 1] = ep - (je3 + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += bytes([0x40, 0x0f, 0xb6, 0xc6])  # movzx eax, sil
    b += _mov_r64_rsp_disp8(0x48, 0x74)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_find_erase_ordered(pos, callee, elem_size):
    """Build 163B (4B) or 164B (8B) BSTArrayFindEraseOrdered."""
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _mov_rsp_disp8_r64(0x10, 0x74)
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x44, 0x8b, 0x51, 0x10])  # mov r10d, [rcx+10h]
    b += bytes([0x48, 0x8d, 0x79, 0x10])  # lea rdi, [rcx+10h]
    b += bytes([0x45, 0x33, 0xc0])  # xor r8d, r8d
    b += bytes([0xbe]) + _u32(0xffffffff)  # mov esi, -1
    b += bytes([0x4c, 0x8b, 0xda])  # mov r11, rdx
    b += bytes([0x4c, 0x8b, 0xc9])  # mov r9, rcx
    b += bytes([0x8b, 0xde])  # mov ebx, esi
    b += bytes([0x45, 0x85, 0xd2])  # test r10d, r10d
    je_end = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x0f, 0x1f, 0x40, 0x00])  # nop dword [rax]
    loop_lbl = len(b)
    b += bytes([0x41, 0x8b, 0xc0])  # mov eax, r8d
    b += bytes([0x3b, 0xde])  # cmp ebx, esi
    jne_found = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x49, 0x8b, 0x09])  # mov rcx, [r9]
    b += bytes([0x8b, 0xd8])  # mov ebx, eax
    if elem_size == 8:
        b += bytes([0x49, 0x8b, 0x03])  # mov rax, [r11]
    else:
        b += bytes([0x41, 0x8b, 0x03])  # mov eax, [r11]
    b += bytes([0x41, 0x8b, 0xd0])  # mov edx, r8d
    b += bytes([0x41, 0xff, 0xc0])  # inc r8d
    if elem_size == 8:
        b += bytes([0x48, 0x39, 0x04, 0xd1])  # cmp [rcx+rdx*8], rax
    else:
        b += bytes([0x39, 0x04, 0x91])  # cmp [rcx+rdx*4], eax
    b += bytes([0x0f, 0x45, 0xde])  # cmovne ebx, esi
    b += bytes([0x45, 0x3b, 0xc2])  # cmp r8d, r10d
    b += _jcc8(0x72, len(b), loop_lbl)
    b += bytes([0x3b, 0xde])  # cmp ebx, esi
    je_ep = len(b)
    b += bytes([0x74, 0x00])
    found_lbl = len(b)
    b[jne_found + 1] = found_lbl - (jne_found + 2)
    b += bytes([0x49, 0x8b, 0x11])  # mov rdx, [r9]
    b += bytes([0x41, 0x83, 0xfa, 0x01])  # cmp r10d, 1
    jne_shift = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x48, 0x85, 0xd2])  # test rdx, rdx
    je_end2 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0xc7, 0x07]) + _u32(0)  # mov dword [rdi], 0
    jmp_end = len(b)
    b += bytes([0xeb, 0x00])
    shift_lbl = len(b)
    b[jne_shift + 1] = shift_lbl - (jne_shift + 2)
    b += bytes([0x44, 0x2b, 0xd3])  # sub r10d, ebx
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0x41, 0xff, 0xca])  # dec r10d
    b += bytes([0x44, 0x8d, 0x4b, 0x01])  # lea r9d, [rbx+1]
    b += bytes([0x44, 0x8b, 0xc3])  # mov r8d, ebx
    b += bytes([0x44, 0x89, 0x54, 0x24, 0x20])
    b += bytes([0x48, 0x8b, 0xcf])
    b += _call(pos + len(b), callee)
    b += bytes([0x01, 0x37])  # add [rdi], esi
    cmp_end = len(b)
    b[je_end + 1] = cmp_end - (je_end + 2)
    b[je_end2 + 1] = cmp_end - (je_end2 + 2)
    b[jmp_end + 1] = cmp_end - (jmp_end + 2)
    b += bytes([0x3b, 0xde])  # cmp ebx, esi
    ep = len(b)
    b[je_ep + 1] = ep - (je_ep + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += bytes([0x0f, 0x95, 0xc0])  # setne al
    b += _mov_r64_rsp_disp8(0x48, 0x74)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


def _mk_find_erase_unordered(pos, callee, elem_size):
    """Build 153B (4B) or 154B (8B) BSTArrayFindEraseUnordered."""
    b = bytearray()
    b += _mov_rsp_disp8_r64(8, 0x5c)
    b += _mov_rsp_disp8_r64(0x10, 0x74)
    b += _push_rdi()
    b += _sub_rsp(0x30)
    b += bytes([0x44, 0x8b, 0x49, 0x10])  # mov r9d, [rcx+10h]
    b += bytes([0x48, 0x8d, 0x79, 0x10])  # lea rdi, [rcx+10h]
    b += bytes([0x45, 0x33, 0xc0])
    b += bytes([0xbe]) + _u32(0xffffffff)
    b += bytes([0x4c, 0x8b, 0xda])
    b += bytes([0x4c, 0x8b, 0xd1])  # mov r10, rcx
    b += bytes([0x8b, 0xde])
    b += bytes([0x45, 0x85, 0xc9])  # test r9d, r9d
    je_end = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x0f, 0x1f, 0x40, 0x00])
    loop_lbl = len(b)
    b += bytes([0x41, 0x8b, 0xc0])
    b += bytes([0x3b, 0xde])
    jne_found = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x49, 0x8b, 0x0a])  # mov rcx, [r10]
    b += bytes([0x8b, 0xd8])
    if elem_size == 8:
        b += bytes([0x49, 0x8b, 0x03])
    else:
        b += bytes([0x41, 0x8b, 0x03])
    b += bytes([0x41, 0x8b, 0xd0])
    b += bytes([0x41, 0xff, 0xc0])
    if elem_size == 8:
        b += bytes([0x48, 0x39, 0x04, 0xd1])
    else:
        b += bytes([0x39, 0x04, 0x91])
    b += bytes([0x0f, 0x45, 0xde])
    b += bytes([0x45, 0x3b, 0xc1])  # cmp r8d, r9d
    b += _jcc8(0x72, len(b), loop_lbl)
    b += bytes([0x3b, 0xde])
    je_ep = len(b)
    b += bytes([0x74, 0x00])
    found_lbl = len(b)
    b[jne_found + 1] = found_lbl - (jne_found + 2)
    b += bytes([0x49, 0x8b, 0x12])  # mov rdx, [r10]
    b += bytes([0x41, 0x8b, 0xc1])  # mov eax, r9d
    b += bytes([0x2b, 0xc3])  # sub eax, ebx
    b += _mov_rsp_disp8_imm32(0x28, elem_size)
    b += bytes([0xff, 0xc8])  # dec eax
    b += bytes([0xb9]) + _u32(1)  # mov ecx, 1
    b += bytes([0x3b, 0xc1])  # cmp eax, ecx
    b += bytes([0x44, 0x8b, 0xc3])  # mov r8d, ebx
    b += bytes([0x0f, 0x42, 0xc8])  # cmovb ecx, eax
    b += bytes([0x44, 0x2b, 0xc9])  # sub r9d, ecx
    b += bytes([0x89, 0x4c, 0x24, 0x20])
    b += bytes([0x48, 0x8b, 0xcf])
    b += _call(pos + len(b), callee)
    b += bytes([0x01, 0x37])
    cmp_end = len(b)
    b[je_end + 1] = cmp_end - (je_end + 2)
    b += bytes([0x3b, 0xde])
    ep = len(b)
    b[je_ep + 1] = ep - (je_ep + 2)
    b += _mov_r64_rsp_disp8(0x40, 0x5c)
    b += bytes([0x0f, 0x95, 0xc0])
    b += _mov_r64_rsp_disp8(0x48, 0x74)
    b += _add_rsp(0x30)
    b += _pop_rdi()
    b += _ret()
    return bytes(b)


class BSTArrayTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_all_eight_templates_and_rejects_negatives(self):
        # Synthetic helper RVAs inside .text (at RVA 0x3000)
        text_rva = 0x3000
        rdata_rva = 0x1000
        pdata_rva = 0x2000

        # Helper callees at start of .text
        move_rva = text_rva + 0x00
        alloc_rva = text_rva + 0x10
        realloc_rva = text_rva + 0x20
        salloc_rva = text_rva + 0x30
        srealloc_rva = text_rva + 0x40
        ctor_rva = text_rva + 0x50
        dealloc_rva = text_rva + 0x60

        text = bytearray(b'\xcc' * 0x1800)
        for h in (move_rva, alloc_rva, realloc_rva, salloc_rva, srealloc_rva, ctor_rva, dealloc_rva):
            text[h - text_rva] = 0xc3

        extents = {h: 1 for h in (move_rva, alloc_rva, realloc_rva, salloc_rva, srealloc_rva, ctor_rva, dealloc_rva)}
        cursor = text_rva + 0x100

        def add_fn(blob):
            nonlocal cursor
            rva = cursor
            text[rva - text_rva : rva - text_rva + len(blob)] = blob
            extents[rva] = len(blob)
            cursor = (rva + len(blob) + 15) & ~15
            return rva

        # Positive cases covering all 8 templates (Heap, Scrap, SmallArray, 4B and 8B)
        r_unord = add_fn(_mk_erase_unordered(cursor, move_rva, 8))
        r_ord_h = add_fn(_mk_erase_ordered(cursor, move_rva, 16, is_scrap=False))
        r_ord_s = add_fn(_mk_erase_ordered(cursor, move_rva, 12, is_scrap=True))
        r_small = add_fn(_mk_small_erase_ordered(cursor, move_rva, 8, local_bytes=16))
        r_res_h = add_fn(_mk_resize_trivial(cursor, alloc_rva, realloc_rva, 8, is_scrap=False))
        r_res_s = add_fn(_mk_resize_trivial(cursor, salloc_rva, srealloc_rva, 24, is_scrap=True))
        r_res_c = add_fn(_mk_resize_construct(cursor, alloc_rva, realloc_rva, ctor_rva, 12, is_scrap=False))
        r_find_o4 = add_fn(_mk_find_erase_ordered(cursor, move_rva, 4))
        r_find_o8 = add_fn(_mk_find_erase_ordered(cursor, move_rva, 8))
        r_find_u4 = add_fn(_mk_find_erase_unordered(cursor, move_rva, 4))
        r_find_u8 = add_fn(_mk_find_erase_unordered(cursor, move_rva, 8))
        r_rel = add_fn(_mk_release(cursor, dealloc_rva, is_scrap=False))

        # Negative 1: EH unwind handler in .pdata -> must be rejected
        r_eh = add_fn(_mk_erase_unordered(cursor, move_rva, 8))
        # Negative 2: callee outside indexed starts -> must be rejected
        r_bad_callee = add_fn(_mk_release(cursor, text_rva + 0x70))
        # Negative 3: callee pointing into .rdata -> must be rejected
        r_rdata_callee = add_fn(_mk_release(cursor, rdata_rva))
        # Negative 4: already matched in inventory -> must be skipped
        r_matched = add_fn(_mk_erase_unordered(cursor, move_rva, 4))
        # Negative 5: wrong elem_size == 0 -> must be rejected
        r_zero_elem = add_fn(_mk_erase_unordered(cursor, move_rva, 0))

        # Put an EH unwind info header (flags = UNW_FLAG_EHANDLER = 1 => byte0 = (1<<3)|1 = 0x09) in .rdata
        rdata = bytearray(0x200)
        rdata[0] = 0x09  # version=1, flags=EHANDLER
        pdata = struct.pack('<III', r_eh, r_eh + extents[r_eh], rdata_rva)

        image = PeImage(assemble_pe([
            ('.rdata', rdata_rva, bytes(rdata), 0x40000040),
            ('.pdata', pdata_rva, pdata, 0x40000040),
            ('.text', text_rva, bytes(text), 0x60000020),
        ], (pdata_rva, len(pdata))))

        inventory = {r_matched: {'rva': r_matched, 'size': extents[r_matched], 'status': 'matched'}}
        found = {m.rva: m for m in generator.discover(image, extents, inventory)}

        expected = {
            r_unord: (generator.ERASE_UNORDERED, 8, False),
            r_ord_h: (generator.ERASE_ORDERED, 16, False),
            r_ord_s: (generator.ERASE_ORDERED, 12, True),
            r_small: (generator.SMALL_ERASE_ORDERED, 8, False),
            r_res_h: (generator.RESIZE_TRIVIAL, 8, False),
            r_res_s: (generator.RESIZE_TRIVIAL, 24, True),
            r_res_c: (generator.RESIZE_CONSTRUCT, 12, False),
            r_find_o4: (generator.FIND_ERASE_ORDERED, 4, False),
            r_find_o8: (generator.FIND_ERASE_ORDERED, 8, False),
            r_find_u4: (generator.FIND_ERASE_UNORDERED, 4, False),
            r_find_u8: (generator.FIND_ERASE_UNORDERED, 8, False),
            r_rel: (generator.ARRAY_RELEASE, 0, False),
        }
        self.assertEqual(set(found), set(expected))
        for rva, (fam, esz, scrap) in expected.items():
            self.assertEqual((found[rva].base_family, found[rva].elem_size, found[rva].is_scrap), (fam, esz, scrap))
        self.assertEqual(found[r_small].local_bytes, 16)
        for neg in (r_eh, r_bad_callee, r_rdata_callee, r_matched, r_zero_elem):
            self.assertNotIn(neg, found)

    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_shards_large_families(self):
        text_rva = 0x2000
        move_rva = text_rva
        text = bytearray(b'\xcc' * 0x2000)
        text[0] = 0xc3
        extents = {move_rva: 1}
        cursor = text_rva + 0x40
        count = generator.SHARD_SIZE + 5
        for _ in range(count):
            blob = _mk_erase_unordered(cursor, move_rva, 8)
            text[cursor - text_rva : cursor - text_rva + len(blob)] = blob
            extents[cursor] = len(blob)
            cursor = (cursor + len(blob) + 15) & ~15
        image = PeImage(assemble_pe([('.text', text_rva, bytes(text), 0x60000020)], (0, 0)))
        members = generator.discover(image, extents, {})
        self.assertEqual(len(members), count)
        by_fam = {}
        for m in members:
            by_fam.setdefault(m.family, []).append(m)
        self.assertEqual(sorted(by_fam), [f'{generator.ERASE_UNORDERED}1', f'{generator.ERASE_UNORDERED}2'])
        self.assertEqual(len(by_fam[f'{generator.ERASE_UNORDERED}1']), generator.SHARD_SIZE)
        self.assertEqual(len(by_fam[f'{generator.ERASE_UNORDERED}2']), 5)

    def test_emit_produces_clean_units_and_bindings(self):
        sample_members = [
            generator.Member(0x4100, 82, generator.ERASE_UNORDERED, 8, False, 0x3000),
            generator.Member(0x4200, 95, generator.ERASE_ORDERED, 12, True, 0x3000),
            generator.Member(0x4300, 117, generator.SMALL_ERASE_ORDERED, 8, False, 0x3000, local_bytes=16),
            generator.Member(0x4400, 113, generator.RESIZE_TRIVIAL, 16, False, 0x3010, 0x3020),
            generator.Member(0x4480, 113, generator.RESIZE_TRIVIAL, 8, True, 0x3030, 0x3040),
            generator.Member(0x4500, 140, generator.RESIZE_CONSTRUCT, 12, False, 0x3010, 0x3020, 0x3050),
            generator.Member(0x4600, 164, generator.FIND_ERASE_ORDERED, 8, False, 0x3000),
            generator.Member(0x4700, 153, generator.FIND_ERASE_UNORDERED, 4, False, 0x3000),
            generator.Member(0x4800, 33, generator.ARRAY_RELEASE, 0, False, 0x3060),
        ]
        by_fam = {}
        for m in sample_members:
            by_fam.setdefault(m.family, []).append(m)
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for fam, rows in sorted(by_fam.items()):
                task, tdir = generator.emit(root, fam, rows, 'test-build', 'TEST_LABEL')
                smap = json.loads((tdir / 'symbols.json').read_text())
                self.assertEqual(len(task['functions']), len(rows))
                for m in rows:
                    for c in m.all_callees():
                        self.assertIn(c, {v['rva'] for v in smap['symbols'].values()})
            emitted = sorted((root / 'reconstruction/leaves').glob('*'))
            self.assertEqual(len(emitted), len(by_fam) * 2)
            for path in emitted:
                rel = path.relative_to(root).as_posix()
                self.assertEqual(contrib_screen.screen(path.read_bytes(), rel), [])
                self.assertEqual(lint_reconstruction.lint_file(root, rel, 'test-build', compact=True), [])
                self.assertEqual(check_code_rules.refusals(rel, path.read_text()), [])
            units = check_code_rules.analyse(root)
            cr_match = [(n, f) for n, u in units.items() for f in u.findings if check_code_rules.is_match(f[1], f[2])]
            self.assertEqual(cr_match, [])


if __name__ == '__main__':
    unittest.main()
