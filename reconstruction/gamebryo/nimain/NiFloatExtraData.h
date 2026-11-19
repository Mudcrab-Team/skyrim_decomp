// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: original; the listing and community declarations only
// NiFloatExtraData::~NiFloatExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiFloatExtraData::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown1C: GUESS(low)
#pragma once

#include <cstdint>
#include "NiExtraData.h"

class NiFloatExtraData : public NiExtraData
{
public:
    ~NiFloatExtraData() override;  // 00, compared: 0xf11120 (scalar deleting destructor)
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xf10f90

    // members
    float value;  // 18
    std::uint8_t unknown1C[0x4];  // 1C
};
static_assert(sizeof(NiFloatExtraData) == 0x20, "NiFloatExtraData size");
