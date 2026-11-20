// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x15262d0 BSLightingShaderMaterialParallaxOcc::CopyMembers
// 0x1526530 BSLightingShaderMaterialParallaxOcc::ReceiveValuesFromRootMaterial
// Adapted bodies: none
#include "BSLightingShaderMaterialParallaxOcc_15262d0.h"

void ReceiveRootValues(BSLightingShaderMaterialBase* material, bool skinned, bool rimLighting,
                       bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2);
extern NiPointer<NiSourceTexture> gDefaultHeightTexture;

void BSLightingShaderMaterialParallaxOcc::CopyMembers(BSShaderMaterial* source)
{
    BSLightingShaderMaterialBase::CopyMembers(source);
    auto* other = static_cast<BSLightingShaderMaterialParallaxOcc*>(source);
    heightTexture = other->heightTexture;
    parallaxOccMaxPasses = other->parallaxOccMaxPasses;
    parallaxOccScale = other->parallaxOccScale;
}

void BSLightingShaderMaterialParallaxOcc::ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2)
{
    ReceiveRootValues(this, skinned, rimLighting, softLighting, backLighting, msn, extra1, extra2);
    if (!heightTexture) {
        heightTexture = gDefaultHeightTexture;
    }
}
