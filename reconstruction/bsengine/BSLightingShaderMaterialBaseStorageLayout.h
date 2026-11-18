// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSLightingShaderMaterialBase.h; MIT.
// BSLightingShaderMaterialBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialBaseLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSLightingShaderMaterialBaseLayout.h.
// BSLightingShaderMaterialBaseStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSShaderMaterialStorageLayout.h"
#include "BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class BSTextureSet;
class NiSourceTexture;
class BSLightingShaderMaterialBaseStorageLayout : public BSShaderMaterialStorageLayout {
public:
    virtual ~BSLightingShaderMaterialBaseStorageLayout();
    NiColorStorageLayout specularColor;
    NiPointerStorageLayout<NiSourceTexture> diffuseTexture;
    std::int32_t diffuseRenderTargetSourceIndex;
    NiPointerStorageLayout<NiSourceTexture> normalTexture;
    NiPointerStorageLayout<NiSourceTexture> rimSoftLightingTexture;
    NiPointerStorageLayout<NiSourceTexture> specularBackLightingTexture;
    std::int32_t textureClampMode;
    NiPointerStorageLayout<BSTextureSet> textureSet;
    float materialAlpha;
    float refractionPower;
    float specularPower;
    float specularColorScale;
    float subSurfaceLightRolloff;
    float rimLightPower;
    std::uint64_t unk98;
};
static_assert(sizeof(BSLightingShaderMaterialBaseStorageLayout) == 160, "community represented size");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, specularColor) == 56, "specularColor offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, diffuseTexture) == 72, "diffuseTexture offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, diffuseRenderTargetSourceIndex) == 80, "diffuseRenderTargetSourceIndex offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, normalTexture) == 88, "normalTexture offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, rimSoftLightingTexture) == 96, "rimSoftLightingTexture offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, specularBackLightingTexture) == 104, "specularBackLightingTexture offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, textureClampMode) == 112, "textureClampMode offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, textureSet) == 120, "textureSet offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, materialAlpha) == 128, "materialAlpha offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, refractionPower) == 132, "refractionPower offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, specularPower) == 136, "specularPower offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, specularColorScale) == 140, "specularColorScale offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, subSurfaceLightRolloff) == 144, "subSurfaceLightRolloff offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, rimLightPower) == 148, "rimLightPower offset");
static_assert(offsetof(BSLightingShaderMaterialBaseStorageLayout, unk98) == 152, "unk98 offset");
}
