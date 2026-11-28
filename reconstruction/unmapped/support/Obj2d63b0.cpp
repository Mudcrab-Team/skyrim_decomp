// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d63b0::SetFlagBit, treated as adapted: shaped like a thread local flag setter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00540000_o2.cpp:29502
// SPDX-License-Identifier: CC0-1.0
// 0x2d63b0 Obj2d63b0::SetFlagBit
#include "Obj2d63b0.h"

// Guess: update bit 0 of the thread-local flags word and return whether it was clear.
bool Obj2d63b0::SetFlagBit(bool a_clear)
{
    const bool wasClear = (gFlags_tls_0x670 & 1u) == 0;
    if (!a_clear)
    {
        gFlags_tls_0x670 |= 1u;
    }
    else
    {
        gFlags_tls_0x670 &= ~1u;
    }
    return wasClear;
}
