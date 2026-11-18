// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialFacegen: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialFacegen::~BSLightingShaderMaterialFacegen, BSLightingShaderMaterialFacegen::Ctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fieldA0, fieldA8, fieldB0: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSLightingShaderMaterial.h"

class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterial
{
public:
    BSLightingShaderMaterialFacegen();
    virtual ~BSLightingShaderMaterialFacegen();  // compared: 0x1528e80 (scalar deleting destructor)
    BSLightingShaderMaterialFacegen* Ctor();  // compared: 0x1526760

    std::uint64_t fieldA0;  // A0
    std::uint64_t fieldA8;  // A8
    std::uint64_t fieldB0;  // B0
};
static_assert(sizeof(BSLightingShaderMaterialFacegen) == 0xB8, "BSLightingShaderMaterialFacegen size");
