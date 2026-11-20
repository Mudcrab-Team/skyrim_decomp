// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1525e50 BSLightingShaderMaterialParallax::CopyMembers
// 0x1526080 BSLightingShaderMaterialParallax::ReceiveValuesFromRootMaterial
// 0x1525ec0 BSLightingShaderMaterialParallax::ComputeCRC32
// Adapted bodies: none
#include "BSLightingShaderMaterialParallax_1525e50.h"

void ReceiveRootValues(BSLightingShaderMaterialBase* material, bool skinned, bool rimLighting,
                       bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2);
extern NiPointer<NiSourceTexture> gDefaultHeightTexture;
std::uint32_t ComputeMaterialFlagHash(BSLightingShaderMaterialBase* material, std::uint32_t flags);

void BSLightingShaderMaterialParallax::CopyMembers(BSShaderMaterial* source)
{
    BSLightingShaderMaterialBase::CopyMembers(source);
    heightTexture = static_cast<BSLightingShaderMaterialParallax*>(source)->heightTexture;
}

void BSLightingShaderMaterialParallax::ReceiveValuesFromRootMaterial(bool skinned, bool rimLighting, bool softLighting, bool backLighting, bool msn, void* extra1, void* extra2)
{
    ReceiveRootValues(this, skinned, rimLighting, softLighting, backLighting, msn, extra1, extra2);
    if (!heightTexture) {
        heightTexture = gDefaultHeightTexture;
    }
}

std::uint32_t BSLightingShaderMaterialParallax::ComputeCRC32(std::uint32_t flags)
{
    struct LayerChecksum
    {
        std::uint32_t heightTextureId;
        std::uint32_t flagHash;
    };
    LayerChecksum record;
    if (textureSet) {
        CRC32Calculator::SizeOf32(&record.heightTextureId, textureSet._ptr->Unk_25(3), 0);
    } else {
        record.heightTextureId = 0;
    }
    record.flagHash = ComputeMaterialFlagHash(this, flags);
    std::uint32_t result;
    CRC32Calculator::SizeOfSize(&result, &record, sizeof(record));
    return result;
}
