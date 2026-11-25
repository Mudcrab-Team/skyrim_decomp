// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0x1525ec0 (bsshader/BSLightingShaderMaterialParallax_1525e50): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ComputeMaterialFlagHash_1525a40, Function1525a40, Owner1525a40: GUESS(low) STANDIN
// heightTexture, CopyMembers, ReceiveValuesFromRootMaterial: GUESS(low) STANDIN
#pragma once
#include "BSLightingShaderMaterialParallax_1525e50.h"

class Owner1525a40 : public BSLightingShaderMaterialBase
{
public:
    void CopyMembers(BSShaderMaterial* source) override;
    void ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2);
    std::uint32_t Function1525a40(std::uint32_t flags);

private:
    NiPointer<NiSourceTexture> heightTexture;
};
