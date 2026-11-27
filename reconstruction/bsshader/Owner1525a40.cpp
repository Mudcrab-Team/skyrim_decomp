// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0x1525ec0 (bsshader/BSLightingShaderMaterialParallax_1525e50): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1525a40 Owner1525a40::Function1525a40
#include "Owner1525a40.h"

std::uint32_t ComputeMaterialFlagHash_1525a40(BSLightingShaderMaterialBase* material, std::uint32_t flags);

// guess: same compiled code as matched 0x1525ec0 apart from relocated fields; its role here is not established.
std::uint32_t Owner1525a40::Function1525a40(std::uint32_t flags)
{
    struct LayerChecksum
    {
        std::uint32_t heightTextureId;
        std::uint32_t flagHash;
    };
    LayerChecksum record;
    if (textureSet) {
        CRC32Calculator::SizeOf32(&record.heightTextureId, textureSet._ptr->Unk_25(2), 0);
    } else {
        record.heightTextureId = 0;
    }
    record.flagHash = ComputeMaterialFlagHash_1525a40(this, flags);
    std::uint32_t result;
    CRC32Calculator::SizeOfSize(&result, &record, sizeof(record));
    return result;
}
