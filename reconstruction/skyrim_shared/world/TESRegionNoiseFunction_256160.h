// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionNoiseFunction.cpp:184
// TESRegionNoiseFunction, TESRegionNoiseFunction::InterpolatedNoise, TESRegionNoiseFunction::SmoothedNoise, TESRegionNoiseFunction::CosineInterpolate: STANDIN SIBLING(fo4-private@1b765c70, author-permission); reduced to the members the body calls
#pragma once

class TESRegionNoiseFunction
{
public:
    static float InterpolatedNoise(float x, float y, float (*noise)(int, int));
    static float SmoothedNoise(int x, int y, float (*noise)(int, int));
    static float CosineInterpolate(float a, float b, float frac);
};
