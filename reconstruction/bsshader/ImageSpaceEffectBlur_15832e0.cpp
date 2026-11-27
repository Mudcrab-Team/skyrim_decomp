// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x15832e0 ImageSpaceEffectBlur::ctor
#include "ImageSpaceEffectBlur_15832e0.h"

ImageSpaceEffectBlur::ImageSpaceEffectBlur()
    : ImageSpaceEffect()
{
    textures.Function150b8f0(4);
    unk90 = -1;
    unk94 = false;
    unk95 = true;
}

ImageSpaceEffectBlur::~ImageSpaceEffectBlur()
{
}
