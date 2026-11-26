// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1551f10 ImageSpaceEffectDepthOfField::dtor_deleting
// CI hash: 0x1551f10 ??_GImageSpaceEffectDepthOfField@@UEAAPEAXI@Z
#include "ImageSpaceEffectDepthOfField_1551f10.h"

ImageSpaceEffectDepthOfField::ImageSpaceEffectDepthOfField()
{
}

ImageSpaceEffectDepthOfField::~ImageSpaceEffectDepthOfField()
{
    ImageSpaceEffectParam* param = effectParams.data[2];
    if (param)
    {
        delete param;
        effectParams.SetAt(2, nullptr);
    }
    param = effectParams.data[1];
    if (param)
    {
        delete param;
        effectParams.SetAt(1, nullptr);
    }
    param = effectParams.data[0];
    if (param)
    {
        delete param;
        effectParams.SetAt(0, nullptr);
    }
}
