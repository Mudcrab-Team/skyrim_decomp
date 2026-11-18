// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWindModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSWindModifier::GetRTTI, BSWindModifier::~BSWindModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRTTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../niparticle/NiPSysModifier.h"

class NiRTTI;

class BSWindModifier : public NiPSysModifier
{
public:
    BSWindModifier();
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xfd8f90
    virtual ~BSWindModifier();  // compared: 0xfd8f50 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0x8];  // 30
};
static_assert(sizeof(BSWindModifier) == 0x38, "BSWindModifier size");
