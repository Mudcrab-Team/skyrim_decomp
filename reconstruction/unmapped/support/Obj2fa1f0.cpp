// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2fa1f0 Obj2fa1f0::GetValue
// Adapted bodies: none
#include "Obj2fa1f0.h"

// Guess: convert the target to its secondary base and return the nested pointer.
void* Obj2fa1f0::GetValue() const
{
    void* result = nullptr;
    const Secondary2fa1f0* base = m_target;
    if (base && base->m_inner)
    {
        result = base->m_inner->m_value;
    }
    return result;
}
