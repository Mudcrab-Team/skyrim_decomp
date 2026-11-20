// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiFloatsExtraData::GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown18: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiExtraData.h"

class NiFloatsExtraData : public NiExtraData
{
public:
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xf119b0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown18[0x10];  // 18
};
static_assert(sizeof(NiFloatsExtraData) == 0x28, "NiFloatsExtraData size");
