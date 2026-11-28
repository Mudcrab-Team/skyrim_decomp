// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x3181f0 Obj3181f0::ClearAll
// Adapted bodies: none
#include "Obj3181f0.h"

// Guess: delete dynamic-cast derived entries and sub-objects, then clear both arrays and reset counts.
void Obj3181f0::ClearAll()
{
    const std::uint32_t count = m_count;
    for (std::uint32_t i = 0; i < count; ++i)
    {
        Derived3181f0* obj = dynamic_cast<Derived3181f0*>(GetAt(i));
        delete obj;
    }

    const std::uint16_t subCount = m_subCount;
    for (std::uint16_t i = 0; i < subCount; ++i)
    {
        delete m_subItems[i];
    }

    for (std::uint16_t i = 0; i < m_subCount; ++i)
    {
        m_subItems[i] = nullptr;
    }
    m_subCount = 0;
    m_subUsed = 0;

    gActive3181f0 = nullptr;

    for (std::uint32_t i = 0; i < m_count; ++i)
    {
        m_items[i] = nullptr;
    }
    m_count = 0;
    m_usedCount = 0;
}
