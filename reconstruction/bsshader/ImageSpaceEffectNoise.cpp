// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: none (written for this reconstruction from the pinned listing)
// SPDX-License-Identifier: CC0-1.0
// 0x1585b60 ImageSpaceEffectNoise::Function1585b60
// Adapted bodies: none
#include "ImageSpaceEffectNoise.h"

// unk330: GUESS(low); the flag at 0x330 gates the call to the helper.
bool ImageSpaceEffectNoise::Function1585b60()
{
    if (unk330 == 0)
        Function1585a20();
    return true;
}
