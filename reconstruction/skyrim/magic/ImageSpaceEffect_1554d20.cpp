// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1554d20 ImageSpaceEffect::dtor_deleting
// CI hash: 0x1554d20 ??_GImageSpaceEffect@@UEAAPEAXI@Z
#include "ImageSpaceEffect_1554d20.h"

ImageSpaceEffect::ImageSpaceEffect()
{
}

ImageSpaceEffect::~ImageSpaceEffect()
{
    for (std::uint32_t i = 0; i < effectInputs.size; ++i)
    {
        EffectInput* input = effectInputs.data[i];
        if (input)
        {
            delete input;
            effectInputs.SetAt(i, nullptr);
        }
    }
}
