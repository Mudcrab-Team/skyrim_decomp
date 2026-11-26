// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1582a80 ImageSpaceEffectGetHit::~ImageSpaceEffectGetHit
// CI hash: 0x1582a80 ??1ImageSpaceEffectGetHit@@UEAA@XZ
#include "ImageSpaceEffectGetHit_1582a80.h"

ImageSpaceEffectGetHit::~ImageSpaceEffectGetHit()
{
    ImageSpaceTexture* first = effectTextures.data[2];
    if (first)
    {
        delete first;
        effectTextures.SetAt(2, nullptr);
    }
    ImageSpaceTexture* second = effectTextures.data[3];
    if (second)
    {
        delete second;
        effectTextures.SetAt(3, nullptr);
    }
    ImageSpaceEffectParam* param = effectParams.data[1];
    if (param)
    {
        delete param;
        effectParams.SetAt(1, nullptr);
    }
    param = effectParams.data[3];
    if (param)
    {
        delete param;
        effectParams.SetAt(3, nullptr);
    }
}
