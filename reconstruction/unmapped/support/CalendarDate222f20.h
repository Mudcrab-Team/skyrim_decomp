// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// CalendarDate222f20, GetDayOfWeek, dayOfYear: GUESS(low)
#pragma once

#include <cstdint>

class CalendarDate222f20
{
public:
    std::uint16_t GetDayOfWeek() const;

    std::uint16_t dayOfYear;  // 00
};
