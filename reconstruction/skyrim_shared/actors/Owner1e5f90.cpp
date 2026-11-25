// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1e5f10 (skyrim_shared/actors/Character_1e5f10): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x1e5f90 Owner1e5f90::Function1e5f90
#include "Owner1e5f90.h"

// guess: same compiled code as matched 0x1e5f10 apart from relocated fields; its role here is not established.
void Owner1e5f90::Function1e5f90(bool a_set)
{
    if (TestBit(flags10, 6) != a_set) {
        if (a_set) {
            flags10 |= 0x40;
        } else {
            flags10 &= ~0x40u;
        }
        unk50(1);
    }
}
