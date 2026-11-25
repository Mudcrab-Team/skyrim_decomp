// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xf9f3e0 NiPSysCylinderEmitter::LoadBinary
// Adapted bodies: none
#include "NiPSysCylinderEmitter_f9f3e0.h"

// ReadValue: GUESS(low); local typed stream-transfer helper
template <class T>
static void ReadValue(NiBinaryStream* binary, T& value)
{
    std::uint32_t componentSize = sizeof(T);
    binary->position += binary->read(binary, &value, sizeof(T), &componentSize, 1);
}

void NiPSysCylinderEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    ReadValue(stream.input, m_fEmitterRadius);
    ReadValue(stream.input, m_fEmitterHeight);
}
