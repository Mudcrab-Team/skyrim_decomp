// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2f6110 Obj2f6110::Apply
// Adapted bodies: none
#include "Obj2f6110.h"

// Guess: update bit 0 of the target info flags based on m_clearFlag and return 1.
std::uint32_t Obj2f6110::Apply(Target2f6110* a_target) const
{
    if (a_target && a_target->GetInfo())
    {
        const bool clear = m_clearFlag;
        Info2f6110* info = a_target->GetInfo();
        if (!clear)
        {
            info->m_flags |= 1u;
        }
        else
        {
            info->m_flags &= ~1u;
        }
    }
    return 1u;
}
