// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLandscape::GetFeature, BSLightingShaderMaterialLandscape::~BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
#pragma once

#include <cstdint>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialLandscape();
    virtual Feature GetFeature() const;  // compared: 0x1527a80
    virtual ~BSLightingShaderMaterialLandscape();  // compared: 0x1529030 (scalar deleting destructor)

    std::uint8_t unknownA0[0xB8];  // A0
};
static_assert(sizeof(BSLightingShaderMaterialLandscape) == 0x158, "BSLightingShaderMaterialLandscape size");
