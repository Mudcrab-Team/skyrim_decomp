// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1df8d0 Unit1df8d0::GetGenderModel1df8d0
// Adapted bodies: none
#include "Unit1df8d0.h"

// Returns the model entry for the requested sex, falling back from 1 to 0 when its path is empty.
GenderModel1df8d0* Unit1df8d0::GetGenderModel1df8d0(std::int32_t a_sex)
{
    if (models[a_sex].path.Length() == 0 && a_sex == 1) {
        a_sex = 0;
    }
    return &models[a_sex];
}
