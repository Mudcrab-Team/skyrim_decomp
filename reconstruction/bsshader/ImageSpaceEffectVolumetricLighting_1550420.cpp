// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1550420 ImageSpaceEffectVolumetricLighting::dtor_deleting
// CI hash: 0x1550420 ??_GImageSpaceEffectVolumetricLighting@@UEAAPEAXI@Z
#include "ImageSpaceEffectVolumetricLighting_1550420.h"

ImageSpaceEffectVolumetricLighting::ImageSpaceEffectVolumetricLighting()
{
}

ImageSpaceEffectVolumetricLighting::~ImageSpaceEffectVolumetricLighting()
{
    ImageSpaceEffectParam* first = params._data[0];
    if (first)
    {
        delete first;
        params.SetAt(0, nullptr);
    }
}
