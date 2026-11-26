// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a4630 ImageSpaceModifierInstanceTemp::ctor
#include "ImageSpaceModifierInstanceTemp_2a4630.h"

ImageSpaceModifierInstanceTemp::ImageSpaceModifierInstanceTemp(float a_age, float a_strength, NiAVObject* a_target, float a_duration)
    : ImageSpaceModifierInstance(a_age, a_strength, a_target), duration(a_duration)
{
}

ImageSpaceModifierInstanceTemp::~ImageSpaceModifierInstanceTemp()
{
}
