// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xeed910 NiSwitchNode::DetachChildAt2
#include "NiSwitchNode_eed910.h"

void NiSwitchNode::DetachChildAt2(std::uint32_t index)
{
    NiPointer<NiAVObject> detached;
    DetachChildAt1(index, detached);
}
