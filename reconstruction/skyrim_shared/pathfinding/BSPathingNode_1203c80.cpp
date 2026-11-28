// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1203c80 BSPathingNode::BSPathingNode
#include "BSPathingNode_1203c80.h"

// Copy-constructs the pathing location, retains the node action, and copies the tangent vector.
BSPathingNode::BSPathingNode(const BSPathingNode& other) :
    location(other.location),
    actionAtNode(other.actionAtNode),
    tangent(other.tangent)
{
}
