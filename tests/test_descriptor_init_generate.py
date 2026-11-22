"""Static reflection descriptor initializers in an original synthetic PE image."""
import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import check_code_rules
import contrib_screen
import descriptor_init_generate as generator
import lint_reconstruction
from pecoff import PeImage
from synthetic_pecoff import assemble_pe


# Generic x86-64 instruction encoders for synthetic fixtures (no copied byte runs).
def _rel32(pos, length, target):
    return struct.pack('<i', target - (pos + length))


def _call_rel32(pos, target):
    return bytes([0xe8]) + _rel32(pos, 5, target)


def _lea_rip(pos, modrm, target, *, rex=0x48):
    return bytes([rex, 0x8d, modrm]) + _rel32(pos, 7, target)


def _mov_rip_r64(pos, modrm, target):
    return bytes([0x48, 0x89, modrm]) + _rel32(pos, 7, target)


def _mov_rip_qword_imm32(pos, target, imm):
    return bytes([0x48, 0xc7, 0x05]) + _rel32(pos, 11, target) + struct.pack('<i', imm)


def _mov_rsp_r64(modrm, off):
    return bytes([0x48, 0x89, modrm, 0x24, off])


def _mov_rsp_r32(modrm, off):
    return bytes([0x89, modrm, 0x24, off])


def _mov_rsp_imm32(off, imm):
    return bytes([0xc7, 0x44, 0x24, off]) + struct.pack('<I', imm)


def _mov_rax_disp8_r64(modrm, disp8):
    return bytes([0x48, 0x89, modrm, disp8 & 0xFF])


def _mov_rax_disp8_r32(modrm, disp8):
    return bytes([0x89, modrm, disp8 & 0xFF])


def _mov_rax_disp8_imm32(disp8, imm):
    return bytes([0xc7, 0x40, disp8 & 0xFF]) + struct.pack('<I', imm)


def mk_typeinfo_init(rva, getter, target, f00, f08, f10, f18, obj_size, *, bad_off=False):
    b = bytearray(bytes.fromhex('48 83 ec 28'))
    b += _call_rel32(rva + len(b), getter)
    b += _lea_rip(rva + len(b), 0x0d, f00)
    b += _mov_rip_r64(rva + len(b), 0x05, target + (0x24 if bad_off else 0x20))
    b += _mov_rip_r64(rva + len(b), 0x0d, target)
    b += _lea_rip(rva + len(b), 0x0d, f08)
    b += _mov_rip_r64(rva + len(b), 0x0d, target + 0x08)
    b += _lea_rip(rva + len(b), 0x0d, f10)
    b += _mov_rip_r64(rva + len(b), 0x0d, target + 0x10)
    b += _lea_rip(rva + len(b), 0x0d, f18)
    b += _mov_rip_r64(rva + len(b), 0x0d, target + 0x18)
    b += _mov_rip_qword_imm32(rva + len(b), target + 0x28, obj_size)
    b += bytes.fromhex('48 83 c4 28 c3')
    return bytes(b)


def mk_class_init_std(rva, callee, target, name_ptr, parent_ptr, obj_size,
                      *, members_ptr=None, num_members=0, enums_ptr=None, num_enums=0,
                      defaults_ptr=None, attrs_ptr=None, flags=0, version=0,
                      drop_slot=False, bad_ptr_imm=False):
    b = bytearray(bytes.fromhex('48 83 ec 78'))
    b += bytes.fromhex('33 c9')  # xor ecx, ecx
    if bad_ptr_imm:
        b += bytes([0xb8]) + struct.pack('<I', 7)  # mov eax, 7
        b += _mov_rsp_r64(0x44, 0x20)
    else:
        b += _mov_rsp_r64(0x4c, 0x20)
    if not drop_slot:
        b += _mov_rsp_r32(0x4c, 0x28)
    if enums_ptr is not None:
        b += _lea_rip(rva + len(b), 0x05, enums_ptr)
        b += _mov_rsp_r64(0x44, 0x30)
    else:
        b += _mov_rsp_r64(0x4c, 0x30)
    if num_enums:
        b += _mov_rsp_imm32(0x38, num_enums)
    else:
        b += _mov_rsp_r32(0x4c, 0x38)
    if members_ptr is not None:
        b += _lea_rip(rva + len(b), 0x05, members_ptr)
        b += _mov_rsp_r64(0x44, 0x40)
    else:
        b += _mov_rsp_r64(0x4c, 0x40)
    if num_members:
        b += _mov_rsp_imm32(0x48, num_members)
    else:
        b += _mov_rsp_r32(0x4c, 0x48)
    if defaults_ptr is not None:
        b += _lea_rip(rva + len(b), 0x05, defaults_ptr)
        b += _mov_rsp_r64(0x44, 0x50)
    else:
        b += _mov_rsp_r64(0x4c, 0x50)
    if attrs_ptr is not None:
        b += _lea_rip(rva + len(b), 0x05, attrs_ptr)
        b += _mov_rsp_r64(0x44, 0x58)
    else:
        b += _mov_rsp_r64(0x4c, 0x58)
    if flags:
        b += _mov_rsp_imm32(0x60, flags)
    else:
        b += _mov_rsp_r32(0x4c, 0x60)
    if version:
        b += _mov_rsp_imm32(0x68, version)
    else:
        b += _mov_rsp_r32(0x4c, 0x68)
    if 0 < obj_size < 0x80:
        b += bytes([0x44, 0x8d, 0x49, obj_size])  # lea r9d, [rcx+imm8]
    else:
        b += bytes([0x41, 0xb9]) + struct.pack('<I', obj_size)  # mov r9d, imm32
    if parent_ptr is not None:
        b += _lea_rip(rva + len(b), 0x05, parent_ptr, rex=0x4c)  # lea r8, [rip+...]
    else:
        b += bytes.fromhex('45 33 c0')  # xor r8d, r8d
    b += _lea_rip(rva + len(b), 0x15, name_ptr)  # lea rdx, [rip+...]
    b += _lea_rip(rva + len(b), 0x0d, target)    # lea rcx, [rip+...]
    b += _call_rel32(rva + len(b), callee)
    b += bytes.fromhex('48 83 c4 78 c3')
    return bytes(b)


def mk_class_init_fp(rva, callee, target, name_ptr, obj_size, enums_ptr, num_enums):
    """Frame-pointer variant: mov rax, rsp; sub rsp, 0x78; stores via [rax-disp8]."""
    b = bytearray(bytes.fromhex('48 8b c4 48 83 ec 78 33 c9'))
    b += _mov_rsp_r64(0x4c, 0x20)
    b += _mov_rsp_r32(0x4c, 0x28)
    b += _mov_rax_disp8_imm32(-0x40, num_enums)  # [rsp+0x38] = num_enums
    b += _mov_rax_disp8_r64(0x48, -0x38)         # [rsp+0x40] = 0
    b += _mov_rax_disp8_r32(0x48, -0x30)         # [rsp+0x48] = 0
    b += _mov_rax_disp8_r64(0x48, -0x28)         # [rsp+0x50] = 0
    b += _mov_rax_disp8_r64(0x48, -0x20)         # [rsp+0x58] = 0
    b += _mov_rax_disp8_r32(0x48, -0x18)         # [rsp+0x60] = 0
    b += _mov_rax_disp8_r32(0x48, -0x10)         # [rsp+0x68] = 0
    b += bytes.fromhex('45 33 c0')               # xor r8d, r8d
    b += bytes([0x44, 0x8d, 0x49, obj_size])     # lea r9d, [rcx+obj_size]
    b += _lea_rip(rva + len(b), 0x15, name_ptr)
    b += _lea_rip(rva + len(b), 0x05, enums_ptr)
    b += _mov_rsp_r64(0x44, 0x30)
    b += _lea_rip(rva + len(b), 0x0d, target)
    b += _call_rel32(rva + len(b), callee)
    b += bytes.fromhex('48 83 c4 78 c3')
    return bytes(b)


class DescriptorInitTests(unittest.TestCase):
    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_both_templates_and_rejects_negatives(self):
        # Sections: .rdata at 0x1000, .data at 0x2000, .pdata at 0x3000, .text LAST at 0x4000
        rdata_mut = bytearray(0x200)
        rdata_mut[0x100] = 0x01  # non-EH unwind header
        rdata_mut[0x110] = 0x09  # UNW_FLAG_EHANDLER
        rdata = bytes(rdata_mut)
        data = bytes(0x200)
        text = bytearray(0x1800)
        extents = {}
        pdata = bytearray()

        def place(rva, code, *, add_extent=True):
            if add_extent:
                extents[rva] = len(code)
            off = rva - 0x4000
            text[off:off + len(code)] = code

        f_getter, f_cls_init, f_cb1, f_cb2 = 0x4000, 0x4010, 0x4020, 0x4030
        for h in (f_getter, f_cls_init, f_cb1):
            place(h, bytes([0xc3]))
        # 16B-aligned unindexed leaf callback target
        place(f_cb2, bytes([0xc3]), add_extent=False)

        ro_a, ro_b, ro_name, ro_mem, ro_enum, ro_def, ro_attr = (
            0x1000, 0x1010, 0x1020, 0x1040, 0x1060, 0x1080, 0x10a0
        )
        rw_rec, rw_cls1, rw_cls2, rw_cls3, rw_parent, rw_mem = (
            0x2000, 0x2040, 0x2080, 0x20c0, 0x2100, 0x2140
        )

        pos = []
        cursor = 0x4100

        def add_pos(code, expected_base):
            nonlocal cursor
            rva = cursor
            place(rva, code)
            pdata.extend(struct.pack('<III', rva, rva + len(code), 0x1100))
            pos.append((rva, len(code), expected_base))
            cursor = (cursor + len(code) + 0x1f) & ~0xf

        # 1. TypeInfoDescriptorInitializers (with one indexed and one 16B-aligned leaf callback)
        add_pos(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb1, f_cb2, 0x48),
                generator.TYPEINFO_DESC_INIT)
        # 2. ClassDescriptorInitializers (standard frame, small imm8 size, writable members table, parent)
        add_pos(mk_class_init_std(cursor, f_cls_init, rw_cls1, ro_name, rw_parent, 0x30,
                                  members_ptr=rw_mem, num_members=3, defaults_ptr=ro_def,
                                  attrs_ptr=ro_attr, flags=2, version=1),
                generator.CLASS_DESC_INIT)
        # 3. ClassDescriptorInitializers (large imm32 size, null parent, enums + members)
        add_pos(mk_class_init_std(cursor, f_cls_init, rw_cls2, ro_name, None, 0x140,
                                  members_ptr=ro_mem, num_members=7, enums_ptr=ro_enum, num_enums=2),
                generator.CLASS_DESC_INIT)
        # 4. ClassDescriptorInitializers (mov rax, rsp frame-pointer variant)
        add_pos(mk_class_init_fp(cursor, f_cls_init, rw_cls3, ro_name, 0x18, ro_enum, 1),
                generator.CLASS_DESC_INIT)

        # Negative cases (all must be rejected)
        def add_neg(code, *, eh=False):
            nonlocal cursor
            rva = cursor
            place(rva, code)
            if eh:
                pdata.extend(struct.pack('<III', rva, rva + len(code), 0x1110))
            cursor = (cursor + len(code) + 0x1f) & ~0xf
            return rva

        add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb1, f_cb2, 0x48), eh=True)      # EH handler
        add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb1, f_cb2, 0))                  # zero size
        add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb1, f_cb2, 0x48, bad_off=True)) # bad field offset
        add_neg(mk_typeinfo_init(cursor, f_getter, ro_a, ro_a, ro_b, f_cb1, f_cb2, 0x48))                 # read-only target
        add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, rw_cls1, ro_b, f_cb1, f_cb2, 0x48))            # writable field00
        add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb2 + 1, f_cb2, 0x48))           # unaligned cb
        add_neg(mk_class_init_std(cursor, f_cls_init + 1, rw_cls1, ro_name, None, 0x20))                  # unindexed callee
        add_neg(mk_class_init_std(cursor, f_cls_init, ro_a, ro_name, None, 0x20))                         # read-only target
        add_neg(mk_class_init_std(cursor, f_cls_init, rw_cls1, rw_cls2, None, 0x20))                      # writable name_ptr
        add_neg(mk_class_init_std(cursor, f_cls_init, rw_cls1, ro_name, ro_a, 0x20))                      # read-only parent
        add_neg(mk_class_init_std(cursor, f_cls_init, rw_cls1, ro_name, None, 0x20, drop_slot=True))      # missing stack slot
        add_neg(mk_class_init_std(cursor, f_cls_init, rw_cls1, ro_name, None, 0x20, bad_ptr_imm=True))    # non-zero ptr imm
        matched_rva = add_neg(mk_typeinfo_init(cursor, f_getter, rw_rec, ro_a, ro_b, f_cb1, f_cb2, 0x48))

        image = PeImage(assemble_pe(
            [('.rdata', 0x1000, rdata, 0x40000040),
             ('.data', 0x2000, data, 0xc0000040),
             ('.pdata', 0x3000, bytes(pdata), 0x40000040),
             ('.text', 0x4000, bytes(text), 0x60000020)],
            (0x3000, len(pdata)),
        ))
        inventory = {matched_rva - 1: dict(size=4, status='matched')}
        found = generator.discover(image, extents, inventory)
        self.assertEqual([(m.rva, m.size, m.base_family) for m in found], pos)

    @unittest.skipUnless(importlib.util.find_spec('iced_x86'), 'local generator requires iced-x86==1.21.0')
    def test_discover_shards_large_families(self):
        count = generator.SHARD_SIZE + 2
        text = bytearray(0x70 * (count + 4))
        extents = {0x4000: 1, 0x4010: 1, 0x4020: 1}
        text[0] = text[0x10] = text[0x20] = 0xc3
        for idx in range(count):
            rva = 0x4040 + idx * 0x70
            code = mk_typeinfo_init(rva, 0x4000, 0x2000, 0x1000, 0x1010, 0x4010, 0x4020, 0x30)
            extents[rva] = len(code)
            text[rva - 0x4000:rva - 0x4000 + len(code)] = code
        image = PeImage(assemble_pe(
            [('.rdata', 0x1000, bytes(0x100), 0x40000040),
             ('.data', 0x2000, bytes(0x100), 0xc0000040),
             ('.text', 0x4000, bytes(text), 0x60000020)],
            (0, 0),
        ))
        members = generator.discover(image, extents, {})
        self.assertEqual(len(members), count)
        self.assertEqual([m.family for m in members[:generator.SHARD_SIZE]],
                         [f'{generator.TYPEINFO_DESC_INIT}1'] * generator.SHARD_SIZE)
        self.assertEqual([m.family for m in members[generator.SHARD_SIZE:]],
                         [f'{generator.TYPEINFO_DESC_INIT}2'] * 2)

    def test_emit_produces_clean_units_and_bindings(self):
        members = [
            generator.Member(0x4100, 88, generator.TYPEINFO_DESC_INIT, callee=0x4000, target_global=0x2000,
                             field00=0x1000, field08=0x1010, field10=0x4020, field18=0x4030, object_size=0x48),
            generator.Member(0x4180, 97, generator.CLASS_DESC_INIT, callee=0x4010, target_global=0x2040,
                             name_ptr=0x1020, parent_ptr=0x2100, object_size=0x30,
                             members_ptr=0x1040, num_members=3, defaults_ptr=0x1080, flags=2, described_version=1),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for m in members:
                task, directory = generator.emit(root, m.family, [m], 'synthetic', 'synthetic')
                src = root / task['compiled']
                hdr = src.with_suffix('.h')
                text = src.read_text()
                self.assertIn(f'// 0x{m.rva:x} {m.family}::{m.name}', text)
                symbols = json.loads((directory / 'symbols.json').read_text())['symbols']
                self.assertEqual(symbols[generator._mangled_symbol(m.family, m)], dict(rva=m.rva, size=m.size))
                self.assertEqual(contrib_screen.screen_tree(root, task['compiled']), [])
                for path in (src, hdr):
                    rel = path.relative_to(root).as_posix()
                    self.assertEqual(lint_reconstruction.lint_file(root, rel, 'synthetic', compact=True), [])
                    self.assertEqual(check_code_rules.refusals(rel, path.read_text()), [])
            units = check_code_rules.analyse(root)
            match_findings = [(name, f) for name, unit in units.items()
                              for f in unit.findings if check_code_rules.is_match(f[1], f[2])]
            self.assertEqual(match_findings, [])


if __name__ == '__main__':
    unittest.main()
