// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x155970 Func_155970::ByteSwapFields
// Adapted bodies: none
#include "Func_155970.h"

#include <intrin.h>

// Byte-swaps the serialized 32-bit and 64-bit payload fields in place.
void Func_155970::ByteSwapFields()
{
    fieldC0 = _byteswap_ulong(fieldC0);  // Endian swap for serialized field.
    fieldC4 = _byteswap_ulong(fieldC4);  // Endian swap for serialized field.
    fieldC8 = _byteswap_ulong(fieldC8);  // Endian swap for serialized field.
    fieldD0 = _byteswap_ulong(fieldD0);  // Endian swap for serialized field.
    fieldCC = _byteswap_ulong(fieldCC);  // Endian swap for serialized field.
    fieldD4 = _byteswap_ulong(fieldD4);  // Endian swap for serialized field.
    fieldD8 = _byteswap_ulong(fieldD8);  // Endian swap for serialized field.
    fieldDC = _byteswap_ulong(fieldDC);  // Endian swap for serialized field.
    fieldE0 = _byteswap_uint64(fieldE0);  // Endian swap for serialized field.
}
