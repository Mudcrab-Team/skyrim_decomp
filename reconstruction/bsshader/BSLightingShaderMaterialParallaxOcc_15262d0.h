// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialParallaxOcc: EXE_RTTI
// heightTexture, parallaxOccMaxPasses, parallaxOccScale, CopyMembers, ReceiveValuesFromRootMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReceiveRootValues, gDefaultHeightTexture: GUESS(low)
#pragma once

#include "BSLightingShaderMaterialEnvmap.h"

class BSLightingShaderMaterialParallaxOcc : public BSLightingShaderMaterialBase
{
public:
    void CopyMembers(BSShaderMaterial* source) override;
    void ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2);

private:
    NiPointer<NiSourceTexture> heightTexture;
    float parallaxOccMaxPasses;
    float parallaxOccScale;
};
