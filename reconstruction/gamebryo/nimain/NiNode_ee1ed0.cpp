// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xee1ed0 NiNode::DetachChildAt2
#include "NiNode_ee1ed0.h"

void NiNode::DetachChildAt2(std::uint32_t index)
{
    NiPointer<NiAVObject> detached;
    DetachChildAt1(index, detached);
}
