// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// 0x675040 Actor::IsBribed_1405D1EB0
#include "Actor_675040.h"

// Check whether the actor is still within its bribery day stamp, clearing expired stamps and flag.
bool Actor::IsBribed_1405D1EB0()
{
    if (intimidateBribeDayStamp != 0x7fffffff && TestBit(boolFlags, 10)) {
        std::uint32_t current = (((g_calendarYear << 4) | g_calendarMonth) << 9) | static_cast<std::int32_t>(g_calendarDay);
        if (current <= intimidateBribeDayStamp) {
            return true;
        }
        boolFlags &= ~(1u << 10);
        intimidateBribeDayStamp = 0x7fffffff;
    }
    return false;
}
