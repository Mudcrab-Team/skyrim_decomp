// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x153dc30 ImageSpaceEffectHDR::dtor_deleting
// CI hash: 0x153dc30 ??_GImageSpaceEffectHDR@@UEAAPEAXI@Z
#include "ImageSpaceEffectHDR_153dc30.h"

ImageSpaceEffectHDR::ImageSpaceEffectHDR()
{
}

ImageSpaceEffectHDR::~ImageSpaceEffectHDR()
{
    for (std::uint32_t i = 0; i < 9; ++i)
    {
        ImageSpaceEffectParam* param = params._data[i];
        if (param)
        {
            delete param;
            params.SetAt(i, nullptr);
        }
    }
}
