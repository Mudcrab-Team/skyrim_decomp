// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xfb9b10 NiPSysSphereEmitter::LoadBinary
// Adapted bodies: none
#include "NiPSysSphereEmitter_fb9b10.h"

void NiPSysSphereEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    NiBinaryStream* input = stream.input;
    std::uint32_t componentSize = sizeof(m_fEmitterRadius);
    input->position += input->read(input, &m_fEmitterRadius, sizeof(m_fEmitterRadius), &componentSize, 1);
}
