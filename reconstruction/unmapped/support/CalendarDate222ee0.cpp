// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x222ee0 CalendarDate222ee0::GetMonth
// Adapted bodies: none
#include "CalendarDate222ee0.h"

// Return the 0-based month index for the stored day of year.
std::uint32_t CalendarDate222ee0::GetMonth() const
{
    std::uint16_t d = dayOfYear;
    std::uint16_t m = 1;
    if (d > gDaysInYear222ee0)
    {
        d = gDaysInYear222ee0 - 1;
    }
    while (m < 12 && d >= gMonthStartDay222ee0[m])
    {
        ++m;
    }
    --m;
    return m;
}
