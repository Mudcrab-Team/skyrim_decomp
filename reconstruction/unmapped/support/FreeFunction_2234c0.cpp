// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ComputeDayOfYear2234c0, treated as adapted: shaped like Date::CalculateDate and the same date helper in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_004a0000_od.cpp:2321
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:666
// SPDX-License-Identifier: CC0-1.0
// 0x2234c0 ComputeDayOfYear2234c0
#include "FreeFunction_2234c0.h"

// Convert a 1-based day of month and month index into a 0-based day of year.
std::uint16_t ComputeDayOfYear2234c0(std::uint16_t dayOfMonth, std::uint16_t month)
{
    std::uint16_t day = dayOfMonth - 1;
    if (month > 12)
    {
        month = 11;
    }
    if (day >= gDaysInMonth2234c0[month])
    {
        day = gDaysInMonth2234c0[month] - 1;
    }
    std::uint16_t total = day;
    for (int i = 0; i < month; ++i)
    {
        total += gDaysInMonth2234c0[i];
    }
    return total;
}
