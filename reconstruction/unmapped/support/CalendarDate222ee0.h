// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// CalendarDate222ee0, GetMonth, dayOfYear, gDaysInYear222ee0, gMonthStartDay222ee0: GUESS(low)
#pragma once

#include <cstdint>

extern std::uint16_t gDaysInYear222ee0;
extern std::uint16_t gMonthStartDay222ee0[12];

class CalendarDate222ee0
{
public:
    std::uint32_t GetMonth() const;

    std::uint16_t dayOfYear;  // 00
};
