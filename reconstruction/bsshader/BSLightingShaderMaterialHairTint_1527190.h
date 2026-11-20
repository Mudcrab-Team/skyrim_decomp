// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialHairTint: EXE_RTTI
// tintColor, ComputeCRC32: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HairTintChecksum, ComputeMaterialFlagHash: GUESS(low)
#pragma once

#include "BSLightingShaderMaterialEnvmap.h"

class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
{
public:
    std::uint32_t ComputeCRC32(std::uint32_t flags);

private:
    NiColor tintColor;
};
