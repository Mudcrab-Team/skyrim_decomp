// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceShaderParam::Function152b1b0: GUESS(low); the name comes from the inventory
// ImageSpaceShaderParam, values: STANDIN GUESS(low); only the pointer at 0x40 the function reads
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceShaderParam
{
public:
    void Function152b1b0(int a_index, const float* a_source, int a_count);  // compared: 0x152b1b0

    std::uint8_t unk00[0x40];
    float* values;  // 40
};
static_assert(offsetof(ImageSpaceShaderParam, values) == 0x40, "values offset");
