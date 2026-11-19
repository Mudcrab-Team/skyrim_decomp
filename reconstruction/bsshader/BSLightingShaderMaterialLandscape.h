// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLandscape::GetFeature, BSLightingShaderMaterialLandscape::~BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialLandscape();
    std::uint32_t GetTextures(NiSourceTexture** a_textures);  // compared: 0x15279b0
    virtual Feature GetFeature() const;  // compared: 0x1527a80
    virtual ~BSLightingShaderMaterialLandscape();  // compared: 0x1529030 (scalar deleting destructor)

    // LandscapeLayers: GUESS(low); layout read by GetTextures: a count, two parallel arrays of five textures, two trailing textures
    std::uint32_t              layerCount;     // A0
    std::uint32_t              padA4;          // A4
    NiSourceTexture*           diffuse[5];     // A8
    NiSourceTexture*           normal[5];      // D0
    NiSourceTexture*           extraF8;        // F8
    NiSourceTexture*           extra100;       // 100
    std::uint8_t               unknown108[0x50];  // 108
};
static_assert(sizeof(BSLightingShaderMaterialLandscape) == 0x158, "BSLightingShaderMaterialLandscape size");
