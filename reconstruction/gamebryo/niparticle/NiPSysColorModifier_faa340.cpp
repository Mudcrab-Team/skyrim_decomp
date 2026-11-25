// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; pinned-image observations and community virtual interface
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfaa340 NiPSysColorModifier::RegisterStreamables
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "NiPSysColorModifier_faa340.h"

bool NiPSysColorModifier::RegisterStreamables(NiStream& stream)
{
    if (!NiPSysModifier::RegisterStreamables(stream))
        return false;
    if (colorData)
        colorData->RegisterStreamables(stream);
    return true;
}
