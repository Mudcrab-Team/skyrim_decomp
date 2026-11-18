// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiBooleanExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiBooleanExtraData::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value: GUESS(low)
#pragma once

#include <cstdint>
#include "NiExtraData.h"

class NiBooleanExtraData : public NiExtraData
{
public:
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xf0ff60

    bool value;  // 18
    std::uint8_t unknown19[0x7];  // 19
};
static_assert(sizeof(NiBooleanExtraData) == 0x20, "NiBooleanExtraData size");
