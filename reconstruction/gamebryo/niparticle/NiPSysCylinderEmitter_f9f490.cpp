// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xf9f490 NiPSysCylinderEmitter::SaveBinary
// Adapted bodies: none
#include "NiPSysCylinderEmitter_f9f490.h"

// WriteValue: GUESS(low); local typed stream-transfer helper
template <class T>
static void WriteValue(NiBinaryStream* binary, const T& value)
{
    std::uint32_t componentSize = sizeof(T);
    binary->position += binary->write(binary, &value, sizeof(T), &componentSize, 1);
}

void NiPSysCylinderEmitter::SaveBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::SaveBinary(stream);
    WriteValue(stream.output, m_fEmitterRadius);
    WriteValue(stream.output, m_fEmitterHeight);
}
