// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xf9b800 NiPSysEmitterCtlr::GetInterpolator
#include "NiPSysEmitterCtlr_f9b800.h"

void* NiPSysEmitterCtlr::GetInterpolator(std::uint16_t a_index) const
{
    if (a_index == 0)
        return interpolator0;
    if (a_index == 1)
        return interpolator1;
    return nullptr;
}
