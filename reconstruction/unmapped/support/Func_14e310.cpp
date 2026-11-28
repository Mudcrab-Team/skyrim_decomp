// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x14e310 Func_14e310::ByteSwapFields
// Adapted bodies: none
#include "Func_14e310.h"

#include <intrin.h>

// Byte-swaps the serialized 32-bit and 64-bit payload fields in place.
void Func_14e310::ByteSwapFields()
{
    field90 = _byteswap_ulong(field90);  // Endian swap for serialized field.
    field94 = _byteswap_ulong(field94);  // Endian swap for serialized field.
    fieldA4 = _byteswap_ulong(fieldA4);  // Endian swap for serialized field.
    field98 = _byteswap_ulong(field98);  // Endian swap for serialized field.
    field9C = _byteswap_ulong(field9C);  // Endian swap for serialized field.
    fieldA0 = _byteswap_ulong(fieldA0);  // Endian swap for serialized field.
    fieldA8 = _byteswap_ulong(fieldA8);  // Endian swap for serialized field.
    fieldB0 = _byteswap_uint64(fieldB0);  // Endian swap for serialized field.
    fieldB8 = _byteswap_uint64(fieldB8);  // Endian swap for serialized field.
}
