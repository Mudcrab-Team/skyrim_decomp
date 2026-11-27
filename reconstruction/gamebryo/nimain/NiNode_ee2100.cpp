// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xee2100 NiNode::SetAt2
#include "NiNode_ee2100.h"

void NiNode::SetAt2(std::uint32_t index, NiAVObject* child)
{
    NiPointer<NiAVObject> detached;
    SetAt1(index, child, detached);
}
