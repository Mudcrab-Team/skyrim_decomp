// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectParticle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTempEffectParticle::GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSTempEffect.h"

class BSTempEffectParticle : public BSTempEffect
{
public:
    virtual TEMP_EFFECT_TYPE GetType() const;  // compared: 0x4b04f0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0xC0];  // 30
};
static_assert(sizeof(BSTempEffectParticle) == 0xF0, "BSTempEffectParticle size");
