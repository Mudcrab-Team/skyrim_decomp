// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// ShaderParam152b170, Function152b170, unk00, values, index, x, y, z, w: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class ShaderParam152b170
{
public:
    std::uint8_t unk00[0x40];  // 0x00
    float* values;             // 0x40

    void Function152b170(int index, float x, float y, float z, float w);
};
static_assert(offsetof(ShaderParam152b170, values) == 0x40, "values offset");
