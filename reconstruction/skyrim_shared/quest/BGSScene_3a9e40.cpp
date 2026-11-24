// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a9e40 BGSScene::Function3a9e40
// Adapted bodies: none
#include "BGSScene_3a9e40.h"
std::uint32_t BGSScene::Function3a9e40(BGSSceneAction* action)
{
    if (action && (action->flags & 1)) active = action->Test(parent, package, actor);
    return active == false ? true : false;
}
