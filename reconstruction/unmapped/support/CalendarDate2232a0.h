// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// CalendarDate2232a0, dayOfYear, year, gDaysInYear2232a0: GUESS(low)
#pragma once

#include <cstdint>

extern std::uint16_t gDaysInYear2232a0;

class CalendarDate2232a0
{
public:
    CalendarDate2232a0& operator+=(std::uint16_t days);

    std::uint16_t dayOfYear;  // 00
    std::uint16_t year;       // 02
};
