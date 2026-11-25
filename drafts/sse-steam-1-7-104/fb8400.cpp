// Near miss: 25.54% | inline-set
// Exposure detail: (community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: CC0-1.0
// NiPSysResetOnLoopCtlr, NiPSysResetOnLoopCtlr::Update: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// Adapted bodies: none
// 0xfb8400 NiPSysResetOnLoopCtlr::Update

#include "include/fb8400/NiPSysResetOnLoopCtlr_fb8400.h"
#include <cfloat>
#include <cstddef>

void NiPSysResetOnLoopCtlr::Update(NiUpdateData& data)
{
    if (!(flags & 8) || !target)
        return;
    if (data.time == lastTime && !(flags & 128))
        return;
    flags &= ~6;
    if (flags & 64) {
        float time = vtable->computeScaledTime(this, data.time);
        if (time == scaledTime && !(flags & 128))
            return;
        scaledTime = time;
    }
    flags &= ~128;
    if (m_fLastScaledTime != -FLT_MAX && scaledTime < m_fLastScaledTime)
        target->resetSystem = true;
    m_fLastScaledTime = scaledTime;
}
