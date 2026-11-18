// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTerrainEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTerrainEffect::GetManagerHandlesSaveLoad: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include "BSTempEffect.h"

class BSTerrainEffect : public BSTempEffect
{
public:
    virtual bool GetManagerHandlesSaveLoad() const;  // compared: 0x4b7c40

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0x88];  // 30
};
static_assert(sizeof(BSTerrainEffect) == 0xB8, "BSTerrainEffect size");
