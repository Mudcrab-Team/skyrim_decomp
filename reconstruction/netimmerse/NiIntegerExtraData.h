// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiIntegerExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiIntegerExtraData::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../netimmerse/NiExtraData.h"

class NiIntegerExtraData : public NiExtraData
{
public:
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xf121e0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint32_t value;  // 18
    std::uint8_t unknown1C[0x4];  // 1C
};
static_assert(sizeof(NiIntegerExtraData) == 0x20, "NiIntegerExtraData size");
