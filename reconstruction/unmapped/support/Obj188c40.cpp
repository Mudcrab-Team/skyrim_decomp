// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x188c40 Obj188c40::CompareByteDE
// Adapted bodies: none.
#include "Obj188c40.h"

// Compares two indirect holders by their unsigned byte at offset 0xDE (descending order).
std::int32_t Obj188c40::CompareByteDE(const Holder188c40* const* a_lhs, const Holder188c40* const* a_rhs)
{
    std::uint8_t lhs = (*a_lhs)->inner->valueDE;
    std::uint8_t rhs = (*a_rhs)->inner->valueDE;
    if (rhs > lhs) {
        return 1;
    }
    return (rhs < lhs) ? -1 : 0;
}
