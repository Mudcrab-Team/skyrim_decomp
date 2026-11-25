// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf16500 NiSpotLight::UpdateWorldData
// Adapted bodies: none
#include "NiSpotLight_f16500.h"

void NiSpotLight::UpdateWorldData(NiUpdateData* data)
{
    UpdateInheritedWorldData(this, data);
    m_kWorldDir.x = worldRotation.entry[0][0];
    m_kWorldDir.y = worldRotation.entry[1][0];
    m_kWorldDir.z = worldRotation.entry[2][0];
}
