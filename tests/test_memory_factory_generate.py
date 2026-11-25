"""Bethesda MemoryManager::Allocate factory generator tests on an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_code_rules
import contrib_screen
import lint_reconstruction
import memory_factory_generate as generator
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


# Generic x86-64 instruction encoders for original synthetic PE fixtures (zero game constants)
def _i8(v):
    return struct.pack('<b', v)


def _u16(v):
    return struct.pack('<H', v)


def _u32(v):
    return struct.pack('<I', v)


def _rel32(pos, length, target):
    return struct.pack('<i', target - (pos + length))


def _call(pos, target):
    return bytes([0xe8]) + _rel32(pos, 5, target)


def _jmp32(pos, target):
    return bytes([0xe9]) + _rel32(pos, 5, target)


def _jcc8(op, pos, target):
    return bytes([op]) + _i8(target - (pos + 2))


def _lea_rip(rex, modrm, pos, target):
    return bytes([rex, 0x8d, modrm]) + _rel32(pos, 7, target)


def _cmp_rip_imm8(pos, target, imm):
    # 7-byte RIP-relative 32-bit compare with imm8
    return bytes([0x83, 0x3d]) + _rel32(pos, 7, target) + bytes([imm])


def _emit_ensure(b, base_rva, guard_rva, mgr_rva, ensure_rva, saved_mov=None):
    b += _cmp_rip_imm8(base_rva + len(b), guard_rva, 2)
    if saved_mov is not None:
        b += saved_mov
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += _lea_rip(0x48, 0x15, base_rva + len(b), mgr_rva if False else guard_rva)  # lea rdx, [guard]
    b += _lea_rip(0x48, 0x0d, base_rva + len(b), mgr_rva)  # lea rcx, [mgr]
    b += _call(base_rva + len(b), ensure_rva)
    b[je_pos + 1] = len(b) - (je_pos + 2)


def _emit_alloc_const_args(b, base_rva, mgr_rva, alloc_size):
    b += bytes([0x45, 0x33, 0xc9])  # xor r9d, r9d
    b += _lea_rip(0x48, 0x0d, base_rva + len(b), mgr_rva)  # lea rcx, [mgr]
    b += bytes([0x45, 0x33, 0xc0])  # xor r8d, r8d
    if alloc_size < 0x80:
        b += bytes([0x41, 0x8d, 0x51, alloc_size])  # lea edx, [r9+alloc_size]
    else:
        b += bytes([0xba]) + _u32(alloc_size)  # mov edx, alloc_size


def _mk_alloc_fixed(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva, alloc_size):
    """Build 58B MemoryAllocFixed."""
    b = bytearray()
    b += bytes([0x48, 0x83, 0xec, 0x28])  # sub rsp, 28h
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva)
    _emit_alloc_const_args(b, pos, mgr_rva, alloc_size)
    b += bytes([0x48, 0x83, 0xc4, 0x28])  # add rsp, 28h
    b += _jmp32(pos + len(b), alloc_rva)
    return bytes(b)


def _mk_alloc_dynamic(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva, *, align=0, align_req=False):
    """Build 63B/66B MemoryAllocDynamic."""
    b = bytearray()
    b += bytes([0x40, 0x53])  # push rbx
    b += bytes([0x48, 0x83, 0xec, 0x20])  # sub rsp, 20h
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva, saved_mov=bytes([0x48, 0x8b, 0xd9]))  # mov rbx, rcx
    if align_req:
        b += bytes([0x41, 0xb1, 0x01])  # mov r9b, 1
    else:
        b += bytes([0x45, 0x33, 0xc9])  # xor r9d, r9d
    b += _lea_rip(0x48, 0x0d, pos + len(b), mgr_rva)  # lea rcx, [mgr]
    if align:
        b += bytes([0x41, 0xb8]) + _u32(align)  # mov r8d, align
    else:
        b += bytes([0x45, 0x33, 0xc0])  # xor r8d, r8d
    b += bytes([0x48, 0x8b, 0xd3])  # mov rdx, rbx
    b += bytes([0x48, 0x83, 0xc4, 0x20])  # add rsp, 20h
    b += bytes([0x5b])  # pop rbx
    b += _jmp32(pos + len(b), alloc_rva)
    return bytes(b)


def _mk_create_object_vft(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva, vft_rva, alloc_size=0x10, imm32=0xbf800000):
    """Build 91B MemoryCreateObject (member new Obj with vftable + dword imm)."""
    b = bytearray()
    b += bytes([0x48, 0x83, 0xec, 0x28])  # sub rsp, 28h
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva)
    _emit_alloc_const_args(b, pos, mgr_rva, alloc_size)
    b += _call(pos + len(b), alloc_rva)
    b += bytes([0x48, 0x89, 0x44, 0x24, 0x38])  # mov [rsp+38h], rax
    b += bytes([0x48, 0x85, 0xc0])  # test rax, rax
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += _lea_rip(0x48, 0x0d, pos + len(b), vft_rva)  # lea rcx, [vft]
    b += bytes([0xc7, 0x40, 0x08]) + _u32(imm32)  # mov dword [rax+8], imm32
    b += bytes([0x48, 0x89, 0x08])  # mov [rax], rcx
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])  # add rsp, 28h; ret
    b[je_pos + 1] = len(b) - (je_pos + 2)
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])  # add rsp, 28h; ret
    return bytes(b)


def _mk_create_object_static_zero3q(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva):
    """Build 82B MemoryCreateObject (static Alloc + zero 3 qwords, no [rsp+38h] spill)."""
    b = bytearray()
    b += bytes([0x48, 0x83, 0xec, 0x28])
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva)
    _emit_alloc_const_args(b, pos, mgr_rva, 0x18)
    b += _call(pos + len(b), alloc_rva)
    b += bytes([0x48, 0x85, 0xc0])
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x33, 0xc9])  # xor ecx, ecx
    b += bytes([0x48, 0x89, 0x08])  # mov [rax], rcx
    b += bytes([0x48, 0x89, 0x48, 0x08])  # mov [rax+8], rcx
    b += bytes([0x48, 0x89, 0x48, 0x10])  # mov [rax+10h], rcx
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])
    b[je_pos + 1] = len(b) - (je_pos + 2)
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])
    return bytes(b)


def _mk_create_niref(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva, niref_vft, niref_cnt, derived_vft):
    """Build 117B MemoryCreateNiRefObject."""
    b = bytearray()
    b += bytes([0x48, 0x83, 0xec, 0x28])
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva)
    _emit_alloc_const_args(b, pos, mgr_rva, 0x38)
    b += _call(pos + len(b), alloc_rva)
    b += bytes([0x48, 0x89, 0x44, 0x24, 0x38])  # mov [rsp+38h], rax
    b += bytes([0x48, 0x85, 0xc0])
    je_pos = len(b)
    b += bytes([0x74, 0x00])
    b += _lea_rip(0x48, 0x0d, pos + len(b), niref_vft)  # lea rcx, [niref_vft]
    b += bytes([0x48, 0x89, 0x08])  # mov [rax], rcx
    b += bytes([0x33, 0xc9])  # xor ecx, ecx
    b += bytes([0x89, 0x48, 0x08])  # mov [rax+8], ecx
    b += bytes([0xf0, 0xff, 0x05]) + _rel32(pos + len(b), 7, niref_cnt)  # lock inc dword [niref_cnt]
    b += bytes([0x48, 0x89, 0x48, 0x20])  # mov [rax+20h], rcx
    b += bytes([0x89, 0x48, 0x28])  # mov [rax+28h], ecx
    b += _lea_rip(0x48, 0x0d, pos + len(b), derived_vft)  # lea rcx, [derived_vft]
    b += bytes([0x48, 0x89, 0x08])  # mov [rax], rcx
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])
    b[je_pos + 1] = len(b) - (je_pos + 2)
    b += bytes([0x33, 0xc9, 0x8b, 0xc1])  # zero return value
    b += bytes([0x48, 0x83, 0xc4, 0x28, 0xc3])  # release stack frame and return
    return bytes(b)


def _mk_create_smartptr(pos, guard_rva, mgr_rva, ensure_rva, alloc_rva, vft_rva):
    """Build 206B BSTSmartPointerCreate."""
    b = bytearray()
    b += bytes([0x48, 0x89, 0x5c, 0x24, 0x08])  # mov [rsp+8], rbx
    b += bytes([0x48, 0x89, 0x74, 0x24, 0x18])  # mov [rsp+18h], rsi
    b += bytes([0x57])  # push rdi
    b += bytes([0x48, 0x83, 0xec, 0x20])  # sub rsp, 20h
    _emit_ensure(b, pos, guard_rva, mgr_rva, ensure_rva, saved_mov=bytes([0x48, 0x8b, 0xf2]))  # mov rsi, rdx
    _emit_alloc_const_args(b, pos, mgr_rva, 0x20)
    b += _call(pos + len(b), alloc_rva)
    b += bytes([0x48, 0x89, 0x44, 0x24, 0x38])  # mov [rsp+38h], rax
    b += bytes([0x48, 0x8b, 0xd8])  # mov rbx, rax
    b += bytes([0x48, 0x85, 0xc0])  # test rax, rax
    je_null = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x33, 0xc0])  # xor eax, eax
    b += _lea_rip(0x48, 0x0d, pos + len(b), vft_rva)  # lea rcx, [vft]
    b += bytes([0x48, 0x89, 0x43, 0x08])  # mov [rbx+8], rax
    b += bytes([0x48, 0x89, 0x0b])  # mov [rbx], rcx
    b += bytes([0x89, 0x43, 0x10])  # mov [rbx+10h], eax
    b += bytes([0x48, 0x89, 0x43, 0x18])  # mov [rbx+18h], rax
    b += bytes([0xf0, 0xff, 0x43, 0x08])  # lock inc dword [rbx+8]
    jmp_assign = len(b)
    b += bytes([0xeb, 0x00])
    null_lbl = len(b)
    b[je_null + 1] = null_lbl - (je_null + 2)
    b += bytes([0x48, 0x8b, 0xd8])  # mov rbx, rax
    assign_lbl = len(b)
    b[jmp_assign + 1] = assign_lbl - (jmp_assign + 2)
    b += bytes([0x48, 0x8b, 0x0e])  # mov rcx, [rsi]
    b += bytes([0xbf]) + _u32(0xffffffff)  # mov edi, -1
    b += bytes([0x48, 0x3b, 0xd9])  # cmp rbx, rcx
    je_rel1 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x48, 0x85, 0xdb])  # test rbx, rbx
    je_set = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0xf0, 0xff, 0x43, 0x08])  # lock inc dword [rbx+8]
    set_lbl = len(b)
    b[je_set + 1] = set_lbl - (je_set + 2)
    b += bytes([0x48, 0x89, 0x1e])  # mov [rsi], rbx
    b += bytes([0x48, 0x85, 0xc9])  # test rcx, rcx
    je_rel2 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0x8b, 0xc7])  # mov eax, edi
    b += bytes([0xf0, 0x0f, 0xc1, 0x41, 0x08])  # lock xadd [rcx+8], eax
    b += bytes([0x83, 0xf8, 0x01])  # cmp eax, 1
    jne_rel3 = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x48, 0x8b, 0x01])  # mov rax, [rcx]
    b += bytes([0xba]) + _u32(1)  # mov edx, 1
    b += bytes([0xff, 0x10])  # call [rax]
    rel_lbl = len(b)
    b[je_rel1 + 1] = rel_lbl - (je_rel1 + 2)
    b[je_rel2 + 1] = rel_lbl - (je_rel2 + 2)
    b[jne_rel3 + 1] = rel_lbl - (jne_rel3 + 2)
    b += bytes([0x48, 0x85, 0xdb])  # test rbx, rbx
    je_ep1 = len(b)
    b += bytes([0x74, 0x00])
    b += bytes([0xf0, 0x0f, 0xc1, 0x7b, 0x08])  # lock xadd [rbx+8], edi
    b += bytes([0x83, 0xff, 0x01])  # cmp edi, 1
    jne_ep2 = len(b)
    b += bytes([0x75, 0x00])
    b += bytes([0x48, 0x8b, 0x03])  # mov rax, [rbx]
    b += bytes([0x8b, 0xd7])  # mov edx, edi
    b += bytes([0x48, 0x8b, 0xcb])  # mov rcx, rbx
    b += bytes([0xff, 0x10])  # call [rax]
    ep_lbl = len(b)
    b[je_ep1 + 1] = ep_lbl - (je_ep1 + 2)
    b[jne_ep2 + 1] = ep_lbl - (jne_ep2 + 2)
    b += bytes([0x48, 0x8b, 0x5c, 0x24, 0x30])  # mov rbx, [rsp+30h]
    b += bytes([0x48, 0x8b, 0x74, 0x24, 0x40])  # mov rsi, [rsp+40h]
    b += bytes([0x48, 0x83, 0xc4, 0x20])  # add rsp, 20h
    b += bytes([0x5f, 0xc3])  # pop rdi; ret
    return bytes(b)


class MemoryFactoryTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_all_five_templates_and_rejects_negatives(self):
        rdata_rva = 0x1000
        data_rva = 0x2000
        pdata_rva = 0x3000
        text_rva = 0x4000

        # Synthetic non-executable data addresses (zero game constants)
        guard_rva = data_rva + 0x10
        mgr_rva = data_rva + 0x40
        niref_cnt = data_rva + 0x80
        niref_vft = rdata_rva + 0x40
        vft_obj = rdata_rva + 0x80
        vft_niref = rdata_rva + 0xc0
        vft_sp = rdata_rva + 0x100

        # Helper callees at start of .text
        ensure_rva = text_rva + 0x00
        alloc_rva = text_rva + 0x10

        text = bytearray(b'\xcc' * 0x2000)
        for h in (ensure_rva, alloc_rva):
            text[h - text_rva] = 0xc3
        extents = {ensure_rva: 1, alloc_rva: 1}
        cursor = text_rva + 0x100

        def add_fn(blob):
            nonlocal cursor
            rva = cursor
            text[rva - text_rva:rva - text_rva + len(blob)] = blob
            extents[rva] = len(blob)
            cursor = (rva + len(blob) + 15) & ~15
            return rva

        # Positive cases covering all 5 templates
        r_fix = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, 0x18))
        r_dyn0 = add_fn(_mk_alloc_dynamic(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, align=0, align_req=False))
        r_dyn16 = add_fn(_mk_alloc_dynamic(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, align=0x10, align_req=True))
        r_obj_vft = add_fn(_mk_create_object_vft(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, vft_obj))
        r_obj_z3 = add_fn(_mk_create_object_static_zero3q(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva))
        r_niref = add_fn(_mk_create_niref(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, niref_vft, niref_cnt, vft_niref))
        r_sp = add_fn(_mk_create_smartptr(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, vft_sp))

        # Negative 1: EH unwind handler in .pdata -> must be rejected
        r_eh = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, 0x20))
        # Negative 2: unindexed alloc callee -> must be rejected
        r_unindexed = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, ensure_rva, text_rva + 0x30, 0x18))
        # Negative 3: callee pointing into .rdata -> must be rejected
        r_rdata_callee = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, ensure_rva, rdata_rva + 0x20, 0x18))
        # Negative 4: vftable pointing into executable .text -> must be rejected
        r_exec_vft = add_fn(_mk_create_object_vft(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, text_rva + 0x20))
        # Negative 5: already matched in inventory -> must be skipped
        r_matched = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, 0x18))
        # Negative 6: ensure_rva == alloc_rva -> must be rejected
        r_same_callee = add_fn(_mk_alloc_fixed(cursor, guard_rva, mgr_rva, alloc_rva, alloc_rva, 0x18))

        rdata = bytearray(0x200)
        rdata[0] = 0x09  # UNW_FLAG_EHANDLER
        data = bytearray(0x200)
        pdata = struct.pack('<III', r_eh, r_eh + extents[r_eh], rdata_rva)

        image = PeImage(assemble_pe([
            ('.rdata', rdata_rva, bytes(rdata), 0x40000040),
            ('.data', data_rva, bytes(data), 0xc0000040),
            ('.pdata', pdata_rva, pdata, 0x40000040),
            ('.text', text_rva, bytes(text), 0x60000020),
        ], (pdata_rva, len(pdata))))

        inventory = {r_matched: {'rva': r_matched, 'size': extents[r_matched], 'status': 'matched'}}
        found = {m.rva: m for m in generator.discover(image, extents, inventory)}

        expected = {
            r_fix: (generator.ALLOC_FIXED, 0x18),
            r_dyn0: (generator.ALLOC_DYNAMIC, 0),
            r_dyn16: (generator.ALLOC_DYNAMIC, 0),
            r_obj_vft: (generator.CREATE_OBJECT, 0x10),
            r_obj_z3: (generator.CREATE_OBJECT, 0x18),
            r_niref: (generator.CREATE_NIREF, 0x38),
            r_sp: (generator.CREATE_SMARTPTR, 0x20),
        }
        self.assertEqual(set(found), set(expected))
        for rva, (fam, asz) in expected.items():
            self.assertEqual((found[rva].base_family, found[rva].alloc_size), (fam, asz))
        self.assertEqual((found[r_dyn16].align, found[r_dyn16].align_req), (0x10, True))
        self.assertFalse(found[r_obj_z3].has_spill)
        self.assertTrue(found[r_obj_vft].has_spill)
        for neg in (r_eh, r_unindexed, r_rdata_callee, r_exec_vft, r_matched, r_same_callee):
            self.assertNotIn(neg, found)

    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_shards_large_families(self):
        rdata_rva = 0x1000
        data_rva = 0x2000
        text_rva = 0x3000
        guard_rva = data_rva + 0x10
        mgr_rva = data_rva + 0x40
        vft_rva = rdata_rva + 0x40
        ensure_rva = text_rva
        alloc_rva = text_rva + 0x10

        text = bytearray(b'\xcc' * 0x2000)
        text[0] = 0xc3
        text[0x10] = 0xc3
        extents = {ensure_rva: 1, alloc_rva: 1}
        cursor = text_rva + 0x40
        count = generator.SHARD_SIZE + 5
        for _ in range(count):
            blob = _mk_create_object_vft(cursor, guard_rva, mgr_rva, ensure_rva, alloc_rva, vft_rva)
            text[cursor - text_rva:cursor - text_rva + len(blob)] = blob
            extents[cursor] = len(blob)
            cursor = (cursor + len(blob) + 15) & ~15
        image = PeImage(assemble_pe([
            ('.rdata', rdata_rva, bytes(0x200), 0x40000040),
            ('.data', data_rva, bytes(0x200), 0xc0000040),
            ('.text', text_rva, bytes(text), 0x60000020),
        ], (0, 0)))
        members = generator.discover(image, extents, {})
        self.assertEqual(len(members), count)
        by_fam = {}
        for m in members:
            by_fam.setdefault(m.family, []).append(m)
        self.assertEqual(sorted(by_fam), [f'{generator.CREATE_OBJECT}1', f'{generator.CREATE_OBJECT}2'])
        self.assertEqual(len(by_fam[f'{generator.CREATE_OBJECT}1']), generator.SHARD_SIZE)
        self.assertEqual(len(by_fam[f'{generator.CREATE_OBJECT}2']), 5)

    def test_emit_produces_clean_units_and_bindings(self):
        st_obj = (
            generator.StoreOp('addr', 0, 8, 0x1080),
            generator.StoreOp('imm', 8, 4, 0xbf800000),
        )
        st_z3 = (
            generator.StoreOp('zero', 0, 8, 0),
            generator.StoreOp('zero', 8, 8, 0),
            generator.StoreOp('zero', 16, 8, 0),
        )
        st_nr = (
            generator.StoreOp('zero', 0x20, 8, 0),
            generator.StoreOp('zero', 0x28, 4, 0),
            generator.StoreOp('addr', 0, 8, 0x10c0),
        )
        st_sp = (
            generator.StoreOp('zero', 8, 8, 0),
            generator.StoreOp('addr', 0, 8, 0x1100),
            generator.StoreOp('zero', 0x10, 4, 0),
            generator.StoreOp('zero', 0x18, 8, 0),
        )
        sample_members = [
            generator.Member(0x4100, 58, generator.ALLOC_FIXED, 0x2010, 0x2040, 0x4000, 0x4010, alloc_size=0x18),
            generator.Member(0x4180, 63, generator.ALLOC_DYNAMIC, 0x2010, 0x2040, 0x4000, 0x4010, align=0, align_req=False),
            generator.Member(0x4200, 66, generator.ALLOC_DYNAMIC, 0x2010, 0x2040, 0x4000, 0x4010, align=0x10, align_req=True),
            generator.Member(0x4280, 91, generator.CREATE_OBJECT, 0x2010, 0x2040, 0x4000, 0x4010, alloc_size=0x10, has_spill=True, stores=st_obj),
            generator.Member(0x4300, 82, generator.CREATE_OBJECT, 0x2010, 0x2040, 0x4000, 0x4010, alloc_size=0x18, has_spill=False, stores=st_z3),
            generator.Member(0x4380, 117, generator.CREATE_NIREF, 0x2010, 0x2040, 0x4000, 0x4010, alloc_size=0x38, niref_vft=0x1040, niref_cnt=0x2080, stores=st_nr),
            generator.Member(0x4400, 206, generator.CREATE_SMARTPTR, 0x2010, 0x2040, 0x4000, 0x4010, alloc_size=0x20, ref_width=8, stores=st_sp),
        ]
        by_fam = {}
        for m in sample_members:
            by_fam.setdefault(m.family, []).append(m)
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for fam, rows in sorted(by_fam.items()):
                task, tdir = generator.emit(root, fam, rows, 'test-build', 'TEST_LABEL')
                smap = json.loads((tdir / 'symbols.json').read_text())
                bound = {v['rva'] for v in smap['symbols'].values()}
                self.assertEqual(len(task['functions']), len(rows))
                for m in rows:
                    for c in m.all_callees():
                        self.assertIn(c, bound)
                    for d in m.all_data_refs():
                        self.assertIn(d, bound)
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
