// Source exposure: mixed (labelled declarations; pinned image observations).
// Code origin: original; handwritten from observed behavior
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xfb8f20 NiPSysRotationModifier::PostLinkObject
#include "NiPSysRotationModifier_fb8f20.h"

void NiPSysRotationModifier::PostLinkObject(NiStream& stream)
{
    NiPSysModifier::PostLinkObject(stream);
    if (stream.nifMaxVersion >= 0x14000002)
        return;
    float* speeds = target->particleData->rotationSpeeds;
    if (!speeds)
        return;
    for (std::uint16_t i = 0; i < target->particleData->numVertices; ++i)
        speeds[i] = m_fInitialRotSpeed;
}
