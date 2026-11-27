// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// kBiasScale: GUESS(low); the value is not read from the listing
// 0x1586480 ImageSpaceEffectNoise::Bias
#include "ImageSpaceEffectNoise_1586480.h"

#include <cmath>

static const float kBiasScale = 1.0f / -0.6931472f;

// Bias: a power curve; the exponent is the log of the bias scaled by a constant.
float ImageSpaceEffectNoise::Bias(float a_value, float a_bias)
{
    return std::pow(a_value, std::log(a_bias) * kBiasScale);
}
