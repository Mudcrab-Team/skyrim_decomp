// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x40d270 Clouds::dtor_deleting
// CI hash: 0x40d270 ??_GClouds@@UEAAPEAXI@Z
#include "Clouds_40d270.h"

Clouds::Clouds()
{
}

Clouds::~Clouds()
{
    for (std::uint32_t i = 0; i < 32; ++i)
    {
        clouds[i] = nullptr;
    }
    Function40cce0();
}
