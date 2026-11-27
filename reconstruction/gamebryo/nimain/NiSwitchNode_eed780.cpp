// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xeed780 NiSwitchNode::DetachChild2
#include "NiSwitchNode_eed780.h"

void NiSwitchNode::DetachChild2(NiAVObject* child)
{
    NiPointer<NiAVObject> detached;
    DetachChild1(child, detached);
}
