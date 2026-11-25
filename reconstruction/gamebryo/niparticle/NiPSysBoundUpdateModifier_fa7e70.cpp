// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xfa7e70 NiPSysBoundUpdateModifier::SaveBinary
// Adapted bodies: none
#include "NiPSysBoundUpdateModifier_fa7e70.h"

void NiPSysBoundUpdateModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    NiBinaryStream* output = stream.output;
    std::uint32_t componentSize = sizeof(m_sUpdateSkip);
    output->position += output->write(output, &m_sUpdateSkip, sizeof(m_sUpdateSkip), &componentSize, 1);
}
