// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2e4f90 Obj2e4f90::CanProcess
// Adapted bodies: none
#include "Obj2e4f90.h"

namespace
{
// guess: an accessor that keeps its own null test; the caller has already read m_base.
bool IsBasePlayable(const Obj2e4f90* a_ref)
{
    const BaseForm2e4f90* base = a_ref->m_base;
    return base && base->IsPlayable();
}
}

// Guess: test reference flags, optional override, and base form type for processing eligibility.
bool Obj2e4f90::CanProcess(const Obj2e4f90* a_ref, const void* a_override)
{
    if (!a_ref || (a_ref->m_flags & 0x4020u) != 0)
    {
        return false;
    }

    if (a_override)
    {
        return true;
    }

    bool result = true;
    switch (a_ref->m_base->m_formType)
    {
    case 0x22:
        if (!IsBasePlayable(a_ref))
        {
            if (a_ref->GetItemCount() == 0)
            {
                result = false;
            }
        }
        break;
    case 0x26:
    case 0x27:
        result = false;
        break;
    default:
        break;
    }

    return result;
}
