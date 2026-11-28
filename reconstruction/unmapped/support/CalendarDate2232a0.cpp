// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2232a0 CalendarDate2232a0::operator+=
// CI hash: 0x2232a0 ??YCalendarDate2232a0@@QEAAAEAV0@G@Z
// Adapted bodies: none
#include "CalendarDate2232a0.h"

// Advance the date by the given number of days, wrapping into following years.
CalendarDate2232a0& CalendarDate2232a0::operator+=(std::uint16_t days)
{
    dayOfYear += days;
    while (dayOfYear > gDaysInYear2232a0)
    {
        dayOfYear -= gDaysInYear2232a0;
        ++year;
    }
    return *this;
}
