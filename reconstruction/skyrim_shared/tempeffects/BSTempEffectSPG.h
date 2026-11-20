// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectSPG: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTempEffectSPG::GetType, BSTempEffectSPG::FinishLoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include "BSTempEffect.h"

class BSTempEffectSPG : public BSTempEffect
{
public:
    virtual TEMP_EFFECT_TYPE GetType() const;  // compared: 0x4b5800
    virtual void FinishLoadGame(BGSLoadGameBuffer* a_buf);  // compared: 0x4b5250

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0x20];  // 30
};
static_assert(sizeof(BSTempEffectSPG) == 0x50, "BSTempEffectSPG size");
