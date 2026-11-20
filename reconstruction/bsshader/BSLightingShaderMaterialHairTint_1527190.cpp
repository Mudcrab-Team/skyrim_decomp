// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1527190 BSLightingShaderMaterialHairTint::ComputeCRC32
// Adapted bodies: none
#include "BSLightingShaderMaterialHairTint_1527190.h"

std::uint32_t ComputeMaterialFlagHash(BSLightingShaderMaterialBase* material, std::uint32_t flags);

std::uint32_t BSLightingShaderMaterialHairTint::ComputeCRC32(std::uint32_t flags)
{
    struct HairTintChecksum
    {
        NiColor tint;
        std::uint32_t flagHash;
    };
    HairTintChecksum record;
    record.tint = tintColor;
    record.flagHash = ComputeMaterialFlagHash(this, flags);
    std::uint32_t result;
    CRC32Calculator::SizeOfSize(&result, &record, sizeof(record));
    return result;
}
