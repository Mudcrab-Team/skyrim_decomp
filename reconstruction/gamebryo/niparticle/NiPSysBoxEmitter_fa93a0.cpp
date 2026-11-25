// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xfa93a0 NiPSysBoxEmitter::SaveBinary
// Adapted bodies: none
#include "NiPSysBoxEmitter_fa93a0.h"

// WriteValue: GUESS(low); local typed stream-transfer helper
template <class T>
static void WriteValue(NiBinaryStream* binary, const T& value)
{
    std::uint32_t componentSize = sizeof(T);
    binary->position += binary->write(binary, &value, sizeof(T), &componentSize, 1);
}

void NiPSysBoxEmitter::SaveBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::SaveBinary(stream);
    WriteValue(stream.output, m_fEmitterWidth);
    WriteValue(stream.output, m_fEmitterHeight);
    WriteValue(stream.output, m_fEmitterDepth);
}
