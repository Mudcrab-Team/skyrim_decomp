// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BSEffectShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSEffectShaderMaterial::~BSEffectShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown38: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSShaderMaterial.h"

class BSEffectShaderMaterial : public BSShaderMaterial
{
public:
    BSEffectShaderMaterial();
    virtual ~BSEffectShaderMaterial();  // compared: 0x1556630 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown38[0x50];  // 38
};
static_assert(sizeof(BSEffectShaderMaterial) == 0x88, "BSEffectShaderMaterial size");
