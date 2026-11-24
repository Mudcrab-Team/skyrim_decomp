// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x8f1bd0 Character::Interpolate
// Adapted bodies: none
#include "Character_8f1bd0.h"

float Character::Interpolate(float a_t, float a_low, float a_mid, float a_high)
{
    float result;
    if (a_t > 0.0f) {
        result = (a_high - a_mid) * a_t + a_mid;
    } else {
        result = (a_mid - a_low) * (a_t + 1.0f) + a_low;
    }
    return result;
}
