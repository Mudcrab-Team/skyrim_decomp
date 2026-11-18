// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BSLightingShaderMaterialLODLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLODLandscape::GetFeature: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
#pragma once

#include <cstdint>
#include "../bsengine/BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
{
public:
    virtual Feature GetFeature() const;  // compared: 0x1527fb0

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknownA0[0x28];  // A0
};
static_assert(sizeof(BSLightingShaderMaterialLODLandscape) == 0xC8, "BSLightingShaderMaterialLODLandscape size");
