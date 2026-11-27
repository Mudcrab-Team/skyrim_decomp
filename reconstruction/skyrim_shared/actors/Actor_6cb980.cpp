// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6cb980 Actor::IsFlagged6cb980
// Adapted bodies: TestBit (header), a one-line bit test close to the Fallout 3 sibling body, CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "Actor_6cb980.h"

Holder* gHolder;

bool Actor::IsFlagged6cb980() const
{
    if (statusFlags >= 0x10000000) {
        Holder** slot = process ? process->GetSlot700c60() : &gHolder;
        Holder* holder = *slot;
        if (holder && TestBit(holder->flags28, 2)) {
            return true;
        }
    }
    return false;
}
