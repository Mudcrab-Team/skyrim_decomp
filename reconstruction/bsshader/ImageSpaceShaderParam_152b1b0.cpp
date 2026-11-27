// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x152b1b0 ImageSpaceShaderParam::Function152b1b0
#include "ImageSpaceShaderParam_152b1b0.h"

#include <cstring>

void ImageSpaceShaderParam::Function152b1b0(int a_index, const float* a_source, int a_count)
{
    int offset = a_index * 4;
    std::memcpy(values + offset, a_source, a_count);
}
