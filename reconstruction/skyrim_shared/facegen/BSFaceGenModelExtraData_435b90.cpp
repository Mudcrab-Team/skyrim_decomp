// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x435b90 BSFaceGenModelExtraData::InitSDM
// Adapted bodies: BSFaceGenModelExtraData::InitSDM from fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenModel.cpp:261 (see the header)
#include "BSFaceGenModelExtraData_435b90.h"

void BSFaceGenModelExtraData::InitSDM()
{
    sTag = BSFixedString("FMD");
}
