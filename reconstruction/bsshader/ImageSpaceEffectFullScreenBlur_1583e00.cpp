// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1583e00 ImageSpaceEffectFullScreenBlur::ctor
#include "ImageSpaceEffectFullScreenBlur_1583e00.h"

float g_blurA;
float g_blurB;
float g_blurC;

ImageSpaceEffectFullScreenBlur::ImageSpaceEffectFullScreenBlur()
    : ImageSpaceEffect()
{
    textures.Function150b8f0(4);
    g_blurA = kBlurA;
    g_blurB = kBlurB;
    g_blurC = kBlurC;
}

ImageSpaceEffectFullScreenBlur::~ImageSpaceEffectFullScreenBlur()
{
}
