// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2fa220 Obj2fa220::GetValue
// Adapted bodies: none
#include "Obj2fa220.h"

// Guess: fetch the secondary subobject via virtual slot 4 and read the derived field.
void* Obj2fa220::GetValue() const
{
    if (!m_target)
    {
        return nullptr;
    }
    Derived2fa220* derived = static_cast<Derived2fa220*>(m_target->GetSecondary());
    if (!derived)
    {
        return nullptr;
    }
    return derived->m_value;
}
