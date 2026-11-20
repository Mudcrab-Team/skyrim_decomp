// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBloodSplatterShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSBloodSplatterShaderProperty::QShader, BSBloodSplatterShaderProperty::GetBaseTexture, BSBloodSplatterShaderProperty::ForEachTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// textures: GUESS(low); the three texture slots from 0x88 that ForEachTexture visits
#pragma once

#include <cstdint>
#include "BSShaderProperty.h"

class BSBloodSplatterShaderProperty : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();  // compared: 0x152d8a0
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x152db70
    virtual std::int32_t ForEachTexture(ForEachVisitor& a_visitor) override;  // compared: 0x152d950

    NiSourceTexture* textures[3];  // 88
    std::uint8_t     unkA0[0x10];  // A0
};
static_assert(sizeof(BSBloodSplatterShaderProperty) == 0xB0, "BSBloodSplatterShaderProperty size");
