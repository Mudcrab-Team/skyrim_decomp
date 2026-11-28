// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1df920 Unit1df920::GetGenderIconPath1df920
// Adapted bodies: none
#include "Unit1df920.h"

// Returns the icon path for the requested sex, falling back from 1 to 0 when empty.
const char* Unit1df920::GetGenderIconPath1df920(std::int32_t a_sex) const
{
    if (icons[a_sex].path.Length() == 0 && a_sex == 1) {
        a_sex = 0;
    }
    return icons[a_sex].path.data;
}
