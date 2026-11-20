// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialFacegenTint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialFacegenTint::GetFeature, BSLightingShaderMaterialFacegenTint::Ctor, BSLightingShaderMaterialFacegenTint::CopyMembers, BSLightingShaderMaterialFacegenTint::~BSLightingShaderMaterialFacegenTint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderPair: GUESS(low); two adjacent tint components copied together
// fieldA0, fieldA8, unknownAC: GUESS(low)
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#pragma once

#include <cstdint>
#include "BSLightingShaderMaterial.h"

struct BSShaderPair
{
    float first;   // 00
    float second;  // 04
};

class BSLightingShaderMaterialFacegenTint : public BSLightingShaderMaterial
{
public:
    BSLightingShaderMaterialFacegenTint();
    virtual Feature GetFeature() const;  // compared: 0x1526fc0
    BSLightingShaderMaterialFacegenTint* Ctor();  // compared: 0x1526e30
    virtual void CopyMembers(BSShaderMaterial* a_other);  // compared: 0x1526f20
    // the plain destructor (0x1526e70) is defined out of line; the deleting destructor (0x1528ec0) is emitted beside the vftable
    virtual ~BSLightingShaderMaterialFacegenTint();

    BSShaderPair fieldA0;  // A0
    std::uint32_t fieldA8;  // A8
    std::uint8_t unknownAC[0x4];  // AC
};
static_assert(sizeof(BSLightingShaderMaterialFacegenTint) == 0xB0, "BSLightingShaderMaterialFacegenTint size");
