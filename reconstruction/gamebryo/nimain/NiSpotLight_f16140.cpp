// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf16140 NiSpotLight::CopyMembers
// Adapted bodies: none
#include "NiSpotLight_f16140.h"
void NiSpotLight::CopyMembers(NiSpotLight* destination)
{
    NiPointLight::CopyMembers(destination);
    destination->m_kWorldDir.x = m_kWorldDir.x;
    destination->m_kWorldDir.y = m_kWorldDir.y;
    destination->m_kWorldDir.z = m_kWorldDir.z;
    destination->m_fOuterSpotAngle = m_fOuterSpotAngle;
    destination->m_fInnerSpotAngle = m_fInnerSpotAngle;
    destination->m_fSpotExponent = m_fSpotExponent;
}
