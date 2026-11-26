// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1565a70 ImageSpaceEffectRefraction::dtor_deleting
// CI hash: 0x1565a70 ??_GImageSpaceEffectRefraction@@UEAAPEAXI@Z
#include "ImageSpaceEffectRefraction_1565a70.h"

ImageSpaceEffectRefraction::ImageSpaceEffectRefraction()
{
}

ImageSpaceEffectRefraction::~ImageSpaceEffectRefraction()
{
    ImageSpaceEffectParam* param = params._data[0];
    if (param)
    {
        delete param;
        params.SetAt(0, nullptr);
    }
    if (buffer.Function15550a0())
    {
        buffer.Function15550d0();
    }
}
