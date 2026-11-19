// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: original; the listing and community declarations only
// NiPSysGravityModifier::~NiPSysGravityModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysGravityModifier::NiPSysGravityModifier: GUESS(low); not compared, defined so the unit emits the vftable and the deleting destructor; NG declares no constructor
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
    NiPSysGravityModifier();
    ~NiPSysGravityModifier() override;  // compared: 0xf9d760 (scalar deleting destructor)
    virtual void LinkObject(NiStream& a_stream);  // compared: 0xf9c400

    NiAVObject* field30;  // 30
    std::uint8_t unknown38[0x28];  // 38
};
static_assert(sizeof(NiPSysGravityModifier) == 0x60, "NiPSysGravityModifier size");
