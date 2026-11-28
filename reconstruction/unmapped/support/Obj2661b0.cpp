// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2661b0 Obj2661b0::Function2661b0
// Adapted bodies: none
#include "Obj2661b0.h"

// Maps masked flag bits 0x7F0000 to a form-type code.
std::uint32_t Obj2661b0::Function2661b0() const
{
    switch (flags80 & 0x7F0000u) {
    case 0x10000u:
        return 0x3Fu;
    case 0x20000u:
        return 0x41u;
    case 0x40000u:
        return 0x42u;
    case 0x80000u:
        return 0x43u;
    case 0x100000u:
        return 0x44u;
    case 0x200000u:
        return 0x45u;
    case 0x400000u:
        return 0x40u;
    default:
        return 0u;
    }
}
