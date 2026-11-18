// Code origin: body written by the contributor from the compared function's behaviour; names and
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0xff2bc0 BSMultiBoundNode::IsEqual
#include "BSMultiBoundNode.h"

bool BSMultiBoundNode::IsEqual(NiObject* a_object)
{
    BSNiNode::IsEqual(a_object);
    return multiBound == static_cast<BSMultiBoundNode*>(a_object)->multiBound;
}
