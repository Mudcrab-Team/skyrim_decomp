// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2ef7a0 Obj2ef7a0::GetValue
// Adapted bodies: none
#include "Obj2ef7a0.h"

// Guess: read the integer field from the extra-data entry, or -1 if absent.
std::int32_t Obj2ef7a0::GetValue() const
{
    const Entry2ef7a0* entry = m_extra.FindEntry();
    if (entry)
    {
        return entry->m_value;
    }
    return -1;
}
