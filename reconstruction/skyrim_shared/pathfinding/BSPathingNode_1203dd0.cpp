// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1203dd0 BSPathingNode::BSPathingNode
#include "BSPathingNode_1203dd0.h"

// Constructs a pathing node from location, action, and tangent, clearing the location flag byte.
BSPathingNode::BSPathingNode(const BSPathingLocation& loc, const BSTSmartPointer<MovementMessage>& action, const NiPoint3& tan) :
    location(loc),
    actionAtNode(action),
    tangent(tan)
{
    location.unk2B = 0;
}
