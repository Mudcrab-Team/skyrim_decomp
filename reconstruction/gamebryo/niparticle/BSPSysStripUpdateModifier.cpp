// Source exposure: mixed (target listing, community headers).
// Code origin: original reconstruction from the pinned image listing and the declarations in NiPSysModifier.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x10029f0 BSPSysStripUpdateModifier::Function10029f0
// 0x1002c80 BSPSysStripUpdateModifier::Initialize
// Adapted bodies: none
#include "BSPSysStripUpdateModifier.h"

// base record, then the 4-byte value at 0x30 through the output stream
void BSPSysStripUpdateModifier::Function10029f0(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);
    a_stream.oStr->write(&unknown30, 1);
}

// forwards the particle index to the strip data
void BSPSysStripUpdateModifier::Initialize(NiPSysData* a_particleData, std::uint16_t a_particle, NiPoint3*)
{
    static_cast<BSStripPSysData*>(a_particleData)->InitializePoint(a_particle);
}
