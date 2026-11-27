// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::boolFlags, Actor::IsBribed_1405D1EB0: CRASHLOGGER_PDB(59818@2026.10.24)
// Actor::intimidateBribeDayStamp: CRASHLOGGER_PDB(59818@2026.10.24) OBSERVED; at 0x184 in this build
// g_calendarYear, g_calendarMonth, g_calendarDay, TestBit: GUESS(low)
// Actor::unk00, Actor::unk188: GUESS(low); unresolved bytes before represented members
#pragma once

#include <cstddef>
#include <cstdint>

extern std::uint32_t g_calendarYear;
extern std::uint32_t g_calendarMonth;
extern std::int8_t   g_calendarDay;

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Actor
{
public:
    bool IsBribed_1405D1EB0();

    std::uint8_t  unk00[0x184];
    std::uint32_t intimidateBribeDayStamp;  // 0x184
    std::uint8_t  unk188[0x7c];
    std::uint32_t boolFlags;                // 0x204
};
static_assert(offsetof(Actor, intimidateBribeDayStamp) == 0x184, "Actor::intimidateBribeDayStamp offset");
static_assert(offsetof(Actor, boolFlags) == 0x204, "Actor::boolFlags offset");
