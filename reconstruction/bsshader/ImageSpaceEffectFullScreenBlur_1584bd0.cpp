// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1584bd0 ImageSpaceEffectFullScreenBlur::dtor_deleting
// CI hash: 0x1584bd0 ??_GImageSpaceEffectFullScreenBlur@@UEAAPEAXI@Z
#include "ImageSpaceEffectFullScreenBlur_1584bd0.h"

ImageSpaceEffectFullScreenBlur::ImageSpaceEffectFullScreenBlur()
{
}

ImageSpaceEffectFullScreenBlur::~ImageSpaceEffectFullScreenBlur()
{
    for (int i = 0; i < 11; ++i)
    {
        if (params[i])
        {
            delete params[i];
            params.SetAt(i, nullptr);
        }
    }
}
