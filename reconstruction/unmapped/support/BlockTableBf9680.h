// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xbf9680
// Adapted bodies: none.
// Float4Bf9680, Block32Bf9680, BlockTableBf9680: GUESS(low) STANDIN
#pragma once

#include <cstdint>

// guess: two four-float halves; the meaning of the values is unknown.
struct Float4Bf9680 {
    float x;
    float y;
    float z;
    float w;
};

struct Block32Bf9680 {
    Float4Bf9680 first;
    Float4Bf9680 second;
};

struct BlockTableBf9680 {
    std::uint64_t reserved00[45];
    Block32Bf9680 entries[16];

    void SetEntry(int a_index, const Block32Bf9680& a_value);
};
