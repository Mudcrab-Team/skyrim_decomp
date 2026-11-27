// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1586580 ImageSpaceEffectNoise::dtor_deleting
// CI hash: 0x1586580 ??_GImageSpaceEffectNoise@@UEAAPEAXI@Z
#include "ImageSpaceEffectNoise_1586580.h"

ImageSpaceEffectNoise::ImageSpaceEffectNoise()
{
}

ImageSpaceEffectNoise::~ImageSpaceEffectNoise()
{
    if (params[0])
    {
        delete params[0];
        params.SetAt(0, nullptr);
    }
    if (params[1])
    {
        delete params[1];
        params.SetAt(1, nullptr);
    }
}
