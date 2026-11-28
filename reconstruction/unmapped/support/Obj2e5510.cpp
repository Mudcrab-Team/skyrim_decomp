// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2e5510 Obj2e5510::CanProcess
// Adapted bodies: none
#include "Obj2e5510.h"

namespace
{
// guess: an accessor that keeps its own null test; the caller has already read m_base.
bool IsBasePlayable(const Obj2e5510* a_ref)
{
    const BaseForm2e5510* base = a_ref->m_base;
    return base && base->IsPlayable();
}
}

// Guess: check reference flags, base form eligibility, and exclude two sentinel base forms.
bool Obj2e5510::CanProcess(const Obj2e5510* a_ref)
{
    if (!a_ref || (a_ref->m_flags & 0x4020u) != 0)
    {
        return false;
    }

    switch (a_ref->m_base->m_formType)
    {
    case 0x22:
        if (!IsBasePlayable(a_ref))
        {
            if (a_ref->GetItemCount() == 0)
            {
                return false;
            }
        }
        break;
    case 0x26:
    case 0x27:
        return false;
    default:
        break;
    }

    const BaseForm2e5510* base = a_ref->m_base;
    if (base == gExcludedA2e5510 || base == gExcludedB2e5510)
    {
        return false;
    }

    return true;
}
