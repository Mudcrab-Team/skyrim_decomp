// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectNoise::Bias: GUESS(low); the name comes from the inventory
// ImageSpaceEffectNoise: STANDIN GUESS(low); only the member the unit declares
#pragma once

class ImageSpaceEffectNoise
{
public:
    float Bias(float a_value, float a_bias);  // compared: 0x1586480
};
