// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x317180 Obj317180::GetDerived
// Adapted bodies: none
#include "Obj317180.h"

// Guess: retrieve the holder's polymorphic object and dynamic_cast it to the derived type.
Derived317180* Obj317180::GetDerived() const
{
    if (m_holder)
    {
        return dynamic_cast<Derived317180*>(m_holder->GetObject());
    }
    return nullptr;
}
