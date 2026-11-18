// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiPSysGravityModifier::LinkObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// field30: GUESS(low)
// unknown38: GUESS(low)
#pragma once

#include <cstdint>
#include "NiPSysModifier.h"

class NiPSysGravityModifier : public NiPSysModifier
{
public:
    virtual void LinkObject(NiStream& a_stream);  // compared: 0xf9c400

    NiAVObject* field30;  // 30
    std::uint8_t unknown38[0x28];  // 38
};
static_assert(sizeof(NiPSysGravityModifier) == 0x60, "NiPSysGravityModifier size");
