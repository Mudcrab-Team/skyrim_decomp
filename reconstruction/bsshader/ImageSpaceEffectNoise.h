// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: none (written for this reconstruction from the pinned listing)
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectNoise, ImageSpaceEffectNoise::Function1585b60: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectNoise
{
public:
    bool Function1585b60();
    // Function1585a20: STANDIN GUESS(low); callee at 0x1585a20, not compared in this unit
    void Function1585a20();

    // unknown00: GUESS(low); layout padding before the flag byte
    unsigned char unknown00[0x330];
    // unk330: GUESS(low); flag byte at 0x330, tested before the callee
    std::uint8_t unk330;
};
