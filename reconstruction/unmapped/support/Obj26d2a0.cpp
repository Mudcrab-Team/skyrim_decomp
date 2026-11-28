// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x26d2a0 Obj26d2a0::Function26d2a0
// Adapted bodies: none
#include "Obj26d2a0.h"

// Maps mode values 1, 2, and 4 to bitmask flags 0x8000, 0x10000, and 0x20000.
std::uint32_t Obj26d2a0::Function26d2a0(std::uint32_t a_mode)
{
    switch (a_mode) {
    case 1u:
        return 0x8000u;
    case 2u:
        return 0x10000u;
    case 4u:
        return 0x20000u;
    default:
        return 0x8000u;
    }
}
