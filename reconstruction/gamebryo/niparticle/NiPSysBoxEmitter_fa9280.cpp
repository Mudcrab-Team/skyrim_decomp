// Source exposure: mixed (labelled declarations; pinned image observations).
// Code origin: original; handwritten from observed behavior
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xfa9280 NiPSysBoxEmitter::CopyMembers
#include "NiPSysBoxEmitter_fa9280.h"

// Copies the inherited emitter state and the three box dimensions.
void NiPSysBoxEmitter::CopyMembers(NiPSysBoxEmitter* destination, NiCloningProcess& cloning)
{
    NiPSysEmitter::CopyMembers(destination, cloning);
    destination->m_fEmitterWidth = m_fEmitterWidth;
    destination->m_fEmitterHeight = m_fEmitterHeight;
    destination->m_fEmitterDepth = m_fEmitterDepth;
}
