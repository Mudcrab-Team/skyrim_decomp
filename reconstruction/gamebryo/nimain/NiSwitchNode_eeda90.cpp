// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xeeda90 NiSwitchNode::SetAt2
#include "NiSwitchNode_eeda90.h"

// Replaces a child and releases ownership of the detached child.
void NiSwitchNode::SetAt2(std::uint32_t index, NiAVObject* child)
{
    NiPointer<NiAVObject> detached;
    SetAt1(index, child, detached);
}
