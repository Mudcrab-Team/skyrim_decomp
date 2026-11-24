// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x256160 TESRegionNoiseFunction::InterpolatedNoise
// Adapted bodies: TESRegionNoiseFunction::InterpolatedNoise follows fo4-private@1b765c70 src/Shared/Regions/TESRegionNoiseFunction.cpp:184
#include "TESRegionNoiseFunction_256160.h"

float TESRegionNoiseFunction::InterpolatedNoise(float x, float y, float (*noise)(int, int))
{
    int ix = int(x) / 64, iy = int(y) / 64;
    float fx = (x - float(ix << 6)) * 0.015625f;
    float a = SmoothedNoise(ix, iy, noise);
    float b = SmoothedNoise(ix + 64, iy, noise);
    int iy1 = iy + 64;
    float c = SmoothedNoise(ix, iy1, noise);
    float fy = (y - float(iy << 6)) * 0.015625f;
    return CosineInterpolate(CosineInterpolate(a, b, fx), CosineInterpolate(c, SmoothedNoise(ix + 64, iy1, noise), fx), fy);
}
