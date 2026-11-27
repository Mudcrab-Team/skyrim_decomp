// Near miss: 5.0 alignment distance | control-flow
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target-observed lookup loop
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x3c86b0 TESNPC::Function3c86b0

#include "include/3c86b0/TESNPC_3c86b0.h"

TESNPC::Layer* TESNPC::Function3c86b0(uint16_t tintIndex)
{
    Layer* result = nullptr;
    if (tintLayers) {
        uint64_t index = 0;
        uint32_t count = tintLayers->size;
        while (!result && static_cast<uint32_t>(index) < count) {
            Layer* entry = tintLayers->data[static_cast<uint32_t>(index)];
            result = entry->tintIndex != tintIndex ? nullptr : entry;
            ++index;
        }
    }
    return result;
}
