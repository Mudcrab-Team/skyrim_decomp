// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x152b170 ShaderParam152b170::Function152b170
// Adapted bodies: none
#include "ShaderParam152b170.h"

// Writes four float components into values starting at 4 * index.
void ShaderParam152b170::Function152b170(int index, float x, float y, float z, float w)
{
    int base = index * 4;
    values[base] = x;
    values[base + 1] = y;
    values[base + 2] = z;
    values[base + 3] = w;
}
