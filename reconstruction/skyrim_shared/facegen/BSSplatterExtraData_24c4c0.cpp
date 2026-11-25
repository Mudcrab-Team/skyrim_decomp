// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x24c4c0 BSSplatterExtraData::InitSDM
// Adapted bodies: BSSplatterExtraData::InitSDM from fo4-private@1b765c70 src/Shared/Misc/ScreenSplatter.cpp:5 (see the header)
#include "BSSplatterExtraData_24c4c0.h"

void BSSplatterExtraData::InitSDM()
{
    sTag = BSFixedString("SPD");
}
