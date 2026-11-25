// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa1930 NiPSysMeshUpdateModifier::SaveBinary
// Adapted bodies: none
#include "NiPSysMeshUpdateModifier_fa1930.h"

void NiPSysMeshUpdateModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    std::uint32_t count = meshes.freeIndex;
    std::uint32_t componentSize = sizeof(count);
    auto* output = stream.output;
    output->absoluteCurrentPos += output->writeFn(output, &count, sizeof(count), &componentSize, 1);
    for (std::uint32_t index = 0; index < count; ++index) {
        stream.vtable->SaveLinkID(&stream, meshes.data[index]);
    }
}
