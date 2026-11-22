// Source exposure: mixed (target listing, anonymous sibling and community headers).
// Code origin: Function10029f0 written from the pinned image listing and the declarations in NiPSysModifier.h; Initialize adapted from the anonymous sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x10029f0 BSPSysStripUpdateModifier::Function10029f0
// 0x1002c80 BSPSysStripUpdateModifier::Initialize
// Adapted bodies: Initialize (fo4-private, see the Sibling source line)
// BSPSysStripUpdateModifier::Initialize: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/BSMain/BSPSysStripUpdateModifier.cpp:12 (BSPSysStripUpdateModifier::Initialize)
// BSPSysStripUpdateModifier, Function10029f0, Initialize: GUESS(low)
// NiPSysData, BSStripPSysData, InitializePoint, NiPoint3: GUESS(low)
// unknown30: GUESS(low); 4 bytes written by Function10029f0, meaning not recovered
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysData {};
class BSStripPSysData : public NiPSysData { public: void InitializePoint(std::uint16_t particle); };

class BSPSysStripUpdateModifier : public NiPSysModifier {
public:
    void Function10029f0(NiStream& a_stream);
    void Initialize(NiPSysData* a_particleData, std::uint16_t a_particle, NiPoint3* a_position) override;

    std::uint32_t unknown30;  // 30
};
static_assert(sizeof(BSPSysStripUpdateModifier) == 0x38, "BSPSysStripUpdateModifier size");
