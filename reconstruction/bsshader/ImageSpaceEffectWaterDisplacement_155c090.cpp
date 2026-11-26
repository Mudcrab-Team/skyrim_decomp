// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x155c090 ImageSpaceEffectWaterDisplacement::dtor_deleting
// CI hash: 0x155c090 ??_GImageSpaceEffectWaterDisplacement@@UEAAPEAXI@Z
#include "ImageSpaceEffectWaterDisplacement_155c090.h"

ImageSpaceEffectWaterDisplacement::ImageSpaceEffectWaterDisplacement()
{
}

ImageSpaceEffectWaterDisplacement::~ImageSpaceEffectWaterDisplacement()
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
