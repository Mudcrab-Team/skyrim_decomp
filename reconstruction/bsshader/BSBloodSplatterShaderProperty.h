// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBloodSplatterShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSBloodSplatterShaderProperty::QShader, BSBloodSplatterShaderProperty::GetBaseTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk88: GUESS(low)
#pragma once

#include <cstdint>
#include "BSShaderProperty.h"

class BSBloodSplatterShaderProperty : public BSShaderProperty
{
public:
    virtual std::int32_t QShader();  // compared: 0x152d8a0
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x152db70

    NiSourceTexture* unk88;  // 88
    std::uint8_t     unk90[0x20];  // 90
};
static_assert(sizeof(BSBloodSplatterShaderProperty) == 0xB0, "BSBloodSplatterShaderProperty size");
