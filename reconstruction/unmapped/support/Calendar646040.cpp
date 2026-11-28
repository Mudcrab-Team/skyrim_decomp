// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Calendar646040::GetDaysPassed, Calendar646040::GetHoursPassed, treated as adapted: shaped like Calendar::GetDaysPassed and Calendar::GetHoursPassed (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/C/Calendar.cpp:67 and src/RE/C/Calendar.cpp:84, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x646040 Calendar646040::GetHoursPassed
// Cookbook: 0x646040 48
#include "Calendar646040.h"

#include <cmath>

// Returns the integer number of elapsed hours computed from gameDaysPassed * 24.
// The community declaration returns float; this body floors the product to an unsigned integer.
std::uint32_t Calendar646040::GetHoursPassed() const
{
    return static_cast<std::uint32_t>(std::floorf(GetDaysPassed() * 24.0f));
}
