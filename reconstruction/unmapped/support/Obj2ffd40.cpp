// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2ffd40 Obj2ffd40::GetClampedValue
// Adapted bodies: none
#include "Obj2ffd40.h"

// Guess: read the extra-data float and clamp it below to the global minimum.
float Obj2ffd40::GetClampedValue() const
{
    const float value = m_extra.GetFloat();
    const float minVal = gMin2ffd40;
    if (value > minVal)
    {
        return value;
    }
    return minVal;
}
