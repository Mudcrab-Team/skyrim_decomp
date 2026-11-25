// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x152db70 (bsshader/BSBloodSplatterShaderProperty): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner12af680: GUESS(low) STANDIN
// textures: GUESS(low) STANDIN
#pragma once
#include "BSBloodSplatterShaderProperty.h"

class Owner12af680 : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();
    virtual NiSourceTexture* GetBaseTexture();
    virtual std::int32_t ForEachTexture(ForEachVisitor& a_visitor) override;

    NiSourceTexture* textures[3];  // 88
    std::uint8_t     unkA0[0x10];  // A0
};
static_assert(sizeof(Owner12af680) == 0xB0, "Owner12af680 size");
