// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1df9c0 Unit1df9c0::GetGenderModelName1df9c0
// Adapted bodies: none
#include "Unit1df9c0.h"

// Returns the model name for the requested sex, falling back from 1 to 0 when its path is empty.
const char* Unit1df9c0::GetGenderModelName1df9c0(std::int32_t a_sex) const
{
    if (models[a_sex].path.Length() == 0 && a_sex == 1) {
        a_sex = 0;
    }
    return models[a_sex].GetModelName();
}
