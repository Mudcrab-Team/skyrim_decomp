// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ShaderReferenceEffect, ShaderReferenceEffect::Function5e2440, unk130, a_enable: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ShaderReferenceEffect
{
public:
    void Function5e2440(bool a_enable);

    uint8_t  pad00[0x130];
    uint32_t unk130;
};
