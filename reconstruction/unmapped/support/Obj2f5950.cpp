// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2f5950 Obj2f5950::AdjustCount
// Adapted bodies: none
#include "Obj2f5950.h"

// Guess: increment or decrement the extra counter, clamp at zero, and update state.
void Obj2f5950::AdjustCount(bool a_inc)
{
    if (m_extra)
    {
        m_extra->m_count += a_inc ? 1 : -1;
        if (m_extra->m_count < 0)
        {
            m_extra->m_count = 0;
        }
        if (!AsActor() && m_base->m_formType != 0x1D && m_extra->m_count < 2)
        {
            SetFlag(m_extra->m_count != 0);
        }
    }
}
