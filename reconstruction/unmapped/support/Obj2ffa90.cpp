// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2ffa90 Obj2ffa90::GetValue
// Adapted bodies: none
#include "Obj2ffa90.h"

// Guess: read a float from extra data, falling back to the base form's 16-bit value on sentinel.
float Obj2ffa90::GetValue() const
{
    float value = m_extra.GetFloat();
    if (value == gSentinel2ffa90)
    {
        value = static_cast<float>(m_base->GetDefaultValue(&m_extra));
    }
    return value;
}
