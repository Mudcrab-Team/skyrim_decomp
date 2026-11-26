// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfcd900 ImageSpaceModifierInstanceFcd900::~ImageSpaceModifierInstanceFcd900
// CI hash: 0xfcd900 ??1ImageSpaceModifierInstanceFcd900@@UEAA@XZ
#include "ImageSpaceModifierInstanceFcd900_fcd900.h"

// volatile: the counter is changed atomically with interlocked operations
volatile long g_objectCount;

ImageSpaceModifierInstanceFcd900::~ImageSpaceModifierInstanceFcd900()
{
    target = nullptr;
}
