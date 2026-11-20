// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// BSEffectShaderMaterial::GetDefault: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_defaultEffectShaderMaterial: GUESS(low); the global pointer GetDefault reads
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSEffectShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSEffectShaderMaterial::~BSEffectShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown38: GUESS(low)
#pragma once

#include <cstdint>
#include "BSShaderMaterial.h"

class BSEffectShaderMaterial : public BSShaderMaterial
{
public:
    BSEffectShaderMaterial();
    virtual ~BSEffectShaderMaterial();  // compared: 0x1556630 (scalar deleting destructor)
    BSShaderMaterial* GetDefault() override;  // compared: 0x1556500

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown38[0x50];  // 38
};
static_assert(sizeof(BSEffectShaderMaterial) == 0x88, "BSEffectShaderMaterial size");

extern BSShaderMaterial* g_defaultEffectShaderMaterial;
