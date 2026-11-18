// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialHairTint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialHairTint::~BSLightingShaderMaterialHairTint, BSLightingShaderMaterialHairTint::Ctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_hairTintDefaultA, g_hairTintDefaultB: GUESS(low)
// fieldA0, fieldA8, unknownAC: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSLightingShaderMaterial.h"

extern double g_hairTintDefaultA;
extern std::uint32_t g_hairTintDefaultB;

class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterial
{
public:
    BSLightingShaderMaterialHairTint();
    virtual ~BSLightingShaderMaterialHairTint();  // compared: 0x1528fb0 (scalar deleting destructor)
    BSLightingShaderMaterialHairTint* Ctor();  // compared: 0x1527050

    double fieldA0;  // A0
    std::uint32_t fieldA8;  // A8
    std::uint8_t unknownAC[0x4];  // AC
};
static_assert(sizeof(BSLightingShaderMaterialHairTint) == 0xB0, "BSLightingShaderMaterialHairTint size");
