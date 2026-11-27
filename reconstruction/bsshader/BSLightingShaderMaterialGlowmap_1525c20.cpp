// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialGlowmap, ClearTextures, glowTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Cookbook: 29
// 0x1525c20 BSLightingShaderMaterialGlowmap::ClearTextures
#include "BSLightingShaderMaterialGlowmap_1525c20.h"

void BSLightingShaderMaterialGlowmap::ClearTextures()
{
    BSLightingShaderMaterialBase::ClearTextures();
    NiSourceTexture* previous = glowTexture;
    if (previous) {
        glowTexture = nullptr;
        previous->DecRefCount();
    }
}
