// Source exposure: mixed (the listing of the pinned image; the name from the sibling declaration used by the adapted body).
// Code origin: body adapted from the sibling function below; constants checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/Misc/Calendar.cpp:295
// 0x646580 Calendar::GetMinutesFromDaysPassed
#include "Calendar_646580.h"

#include <cmath>

// Fraction of a day to hours, fraction of an hour to minutes.
float Calendar::GetMinutesFromDaysPassed(float afDaysPassed)
{
    return fmodf(fmodf(afDaysPassed, 1.0f) * 24.0f, 1.0f) * 60.0f;
}
