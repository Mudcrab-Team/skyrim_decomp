// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// Cookbook: 0x2e5620 16
// SPDX-License-Identifier: CC0-1.0
// 0x2e5620 Obj2e5620::MatchesTarget
// Adapted bodies: none
#include "Obj2e5620.h"

// Guess: check object flags, target pointer match, and optional base-form predicate.
bool Obj2e5620::MatchesTarget(const Obj2e5620* a_obj, const void* a_expected)
{
    if (!a_obj || TestBit2e5620(a_obj->m_flags, 5) || a_obj->m_target != a_expected)
    {
        return false;
    }
    if (a_obj->m_base && a_obj->m_base->m_formType == 0x18 && a_obj->m_base->GetSlot3D() != nullptr)
    {
        return false;
    }
    return true;
}
