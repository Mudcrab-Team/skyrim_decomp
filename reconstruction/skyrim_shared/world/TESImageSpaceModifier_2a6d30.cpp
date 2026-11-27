// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a6d30 TESImageSpaceModifier::~TESImageSpaceModifier
// CI hash: 0x2a6d30 ??1TESImageSpaceModifier@@UEAA@XZ
#include "TESImageSpaceModifier_2a6d30.h"

TESImageSpaceModifier::~TESImageSpaceModifier()
{
    ClearData();
}
