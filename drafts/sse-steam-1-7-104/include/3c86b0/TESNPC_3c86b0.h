// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original compact layout from community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESNPC::Layer, TESNPC::Layer::tintColor, TESNPC::Layer::tintIndex, TESNPC::tintLayers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESNPC::Function3c86b0, TESNPC::LayerArray, TESNPC::LayerArray::data, TESNPC::LayerArray::size: GUESS(low) STANDIN; observed array projection
// TESNPC::prefix, TESNPC::LayerArray::capacityAndAllocator: GUESS(low) STANDIN; unaccessed layout regions

#pragma once
#include <cstdint>
#include <cstddef>
class TESNPC {
public:
    struct Layer { uint32_t tintColor; uint16_t tintIndex; };
    struct LayerArray { Layer** data; uint64_t capacityAndAllocator; uint32_t size; };
    Layer* Function3c86b0(uint16_t tintIndex);
    uint8_t prefix[0x260];
    LayerArray* tintLayers;
};
static_assert(offsetof(TESNPC, tintLayers) == 0x260, "tint array offset");
static_assert(offsetof(TESNPC::LayerArray, size) == 0x10, "array size offset");
static_assert(offsetof(TESNPC::Layer, tintIndex) == 4, "tint index offset");
