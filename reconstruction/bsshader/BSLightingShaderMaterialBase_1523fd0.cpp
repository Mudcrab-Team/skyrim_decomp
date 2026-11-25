// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialBase, GetTextures: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x1523fd0 BSLightingShaderMaterialBase::GetTextures
#include "BSLightingShaderMaterialBase_1523fd0.h"

unsigned int BSLightingShaderMaterialBase::GetTextures(NiSourceTexture** textures)
{
    unsigned int count = 0;
    if (diffuseTexture) {
        textures[count++] = diffuseTexture;
    }
    if (normalTexture) {
        textures[count++] = normalTexture;
    }
    if (rimSoftLightingTexture) {
        textures[count++] = rimSoftLightingTexture;
    }
    if (specularBackLightingTexture) {
        textures[count++] = specularBackLightingTexture;
    }
    return count;
}
