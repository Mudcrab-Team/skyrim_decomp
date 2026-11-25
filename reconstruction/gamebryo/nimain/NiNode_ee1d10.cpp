// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xee1d10 NiNode::DetachChild2
#include "NiNode_ee1d10.h"

void NiNode::DetachChild2(NiAVObject* child)
{
    NiPointer<NiAVObject> detached;
    DetachChild1(child, detached);
}
