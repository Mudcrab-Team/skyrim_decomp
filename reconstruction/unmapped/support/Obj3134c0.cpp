// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x3134c0 Obj3134c0::FindIndex
// Adapted bodies: none
#include "Obj3134c0.h"

// Guess: find the index of the first matching pointer element, or 0xFFFFFFFF if absent.
std::uint32_t Obj3134c0::FindIndex(void* const& a_item) const
{
    std::uint32_t result = 0xFFFFFFFFu;
    for (std::uint32_t i = 0; i < m_size && result == 0xFFFFFFFFu; ++i)
    {
        if (m_data[i] == a_item)
        {
            result = i;
        }
    }
    return result;
}
