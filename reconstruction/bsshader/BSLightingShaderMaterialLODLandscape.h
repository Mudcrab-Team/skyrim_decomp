// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialLODLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLODLandscape::GetFeature: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#pragma once

#include <cstdint>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialLODLandscape : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialLODLandscape();
    virtual ~BSLightingShaderMaterialLODLandscape();  // compared: 0x1528ff0 (scalar deleting destructor)
    virtual Feature GetFeature() const;  // compared: 0x1527fb0

    // unkA0, unkA8, unkB0, unkB8, unkC0, padC4: GUESS(low); storage names invented for the measured offsets
    std::uint64_t unkA0;      // A0
    std::uint64_t unkA8;      // A8
    std::uint64_t unkB0;      // B0
    std::uint64_t unkB8;      // B8
    std::uint32_t unkC0;      // C0
    std::uint32_t padC4;      // C4
};
static_assert(sizeof(BSLightingShaderMaterialLODLandscape) == 0xC8, "BSLightingShaderMaterialLODLandscape size");
