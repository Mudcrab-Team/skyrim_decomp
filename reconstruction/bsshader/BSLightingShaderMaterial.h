// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterial::~BSLightingShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterial();
    Feature GetFeature() const override;  // compared: 0x1524940
    virtual ~BSLightingShaderMaterial();  // compared: 0x4b4a00 (scalar deleting destructor)
};
static_assert(sizeof(BSLightingShaderMaterial) == 0xA0, "BSLightingShaderMaterial size");
