// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialGlowmap, ReceiveValuesFromRootMaterial, glowTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Cookbook: 29
// 0x1525bb0 BSLightingShaderMaterialGlowmap::ReceiveValuesFromRootMaterial
#include "BSLightingShaderMaterialGlowmap_1525bb0.h"

void BSLightingShaderMaterialGlowmap::ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool MSN, void* unk38Arg, void* unk40Arg)
{
    BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial(skinned, rimLighting, softLighting, backLighting, MSN, unk38Arg, unk40Arg);
    if (!glowTexture) {
        NiSourceTexture* texture = gDefaultGlowTexture;
        if (texture) {
            texture->IncRefCount();
            glowTexture = texture;
        }
    }
}
