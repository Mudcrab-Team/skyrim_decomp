// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x222f20 CalendarDate222f20::GetDayOfWeek
// Adapted bodies: none
#include "CalendarDate222f20.h"

// Return the day of the week (0 through 6) for the stored day of year.
std::uint16_t CalendarDate222f20::GetDayOfWeek() const
{
    return dayOfYear % 7;
}
