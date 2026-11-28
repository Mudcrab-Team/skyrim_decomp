// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// Cookbook: 0x2e4990 16
// SPDX-License-Identifier: CC0-1.0
// 0x2e4990 Obj2e4990::HasFlag15
// Adapted bodies: none
#include "Obj2e4990.h"

// Guess: test bit 15 of the target object's flags field when present.
bool Obj2e4990::HasFlag15() const
{
    bool result = false;
    if (m_target)
    {
        if (TestBit2e4990(m_target->m_flags, 15))
        {
            result = true;
        }
    }
    return result;
}
