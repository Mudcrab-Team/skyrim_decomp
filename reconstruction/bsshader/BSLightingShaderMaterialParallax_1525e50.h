// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialParallax: EXE_RTTI
// heightTexture, CopyMembers, ComputeCRC32, ReceiveValuesFromRootMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LayerChecksum, ComputeMaterialFlagHash, ReceiveRootValues, gDefaultHeightTexture: GUESS(low)
#pragma once

#include "BSLightingShaderMaterialEnvmap.h"

class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
{
public:
    void CopyMembers(BSShaderMaterial* source) override;
    void ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2);
    std::uint32_t ComputeCRC32(std::uint32_t flags);

private:
    NiPointer<NiSourceTexture> heightTexture;
};
