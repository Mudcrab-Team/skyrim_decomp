// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialBase, GetTextures, diffuseTexture, normalTexture, rimSoftLightingTexture, specularBackLightingTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// prefix, diffuseGap: GUESS(low); unrepresented members
// 0x1523fd0 BSLightingShaderMaterialBase::GetTextures
#pragma once
#include <cstddef>
class NiSourceTexture;
class BSLightingShaderMaterialBase {
public:
    // The observed operation takes an output array and returns its populated count.
    unsigned int GetTextures(NiSourceTexture** textures);
    unsigned char prefix[0x48];
    NiSourceTexture* diffuseTexture;
    unsigned char diffuseGap[8];
    NiSourceTexture* normalTexture;
    NiSourceTexture* rimSoftLightingTexture;
    NiSourceTexture* specularBackLightingTexture;
};
static_assert(offsetof(BSLightingShaderMaterialBase, diffuseTexture) == 0x48, "diffuse offset");
static_assert(offsetof(BSLightingShaderMaterialBase, normalTexture) == 0x58, "normal offset");
static_assert(offsetof(BSLightingShaderMaterialBase, rimSoftLightingTexture) == 0x60, "rim offset");
static_assert(offsetof(BSLightingShaderMaterialBase, specularBackLightingTexture) == 0x68, "specular offset");
