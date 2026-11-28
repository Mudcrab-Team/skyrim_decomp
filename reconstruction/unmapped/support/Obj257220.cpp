// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj257220::SwapEndian, treated as adapted: shaped like a record byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:12009
// SPDX-License-Identifier: CC0-1.0
// 0x257220 Obj257220::SwapEndian
#include "Obj257220.h"

#include <intrin.h>

// Byte-swap serialized record fields between big-endian and little-endian formats.
void Obj257220::SwapEndian()
{
    unk00 = _byteswap_ulong(unk00);  // Endian byte-swap serialized field.
    unk04 = _byteswap_ushort(unk04);  // Endian byte-swap serialized field.
    unk08 = _byteswap_ulong(unk08);  // Endian byte-swap serialized field.
    unk10 = _byteswap_ushort(unk10);  // Endian byte-swap serialized field.
    unk12 = _byteswap_ushort(unk12);  // Endian byte-swap serialized field.
    unk14 = _byteswap_ulong(unk14);  // Endian byte-swap serialized field.
    unk18 = _byteswap_ulong(unk18);  // Endian byte-swap serialized field.
    unk1C = _byteswap_ulong(unk1C);  // Endian byte-swap serialized field.
    unk20 = _byteswap_ulong(unk20);  // Endian byte-swap serialized field.
    unk24 = _byteswap_ulong(unk24);  // Endian byte-swap serialized field.
    unk30 = _byteswap_ulong(unk30);  // Endian byte-swap serialized field.
    unk28 = _byteswap_ushort(unk28);  // Endian byte-swap serialized field.
    unk2A = _byteswap_ushort(unk2A);  // Endian byte-swap serialized field.
    unk2C = _byteswap_ushort(unk2C);  // Endian byte-swap serialized field.
}
