// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xfb9b90 NiPSysSphereEmitter::SaveBinary
// Adapted bodies: none
#include "NiPSysSphereEmitter_fb9b90.h"

void NiPSysSphereEmitter::SaveBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::SaveBinary(stream);
    NiBinaryStream* output = stream.output;
    std::uint32_t componentSize = sizeof(m_fEmitterRadius);
    output->position += output->write(output, &m_fEmitterRadius, sizeof(m_fEmitterRadius), &componentSize, 1);
}
