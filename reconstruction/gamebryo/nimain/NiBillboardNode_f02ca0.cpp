// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf02ca0 NiBillboardNode::CopyMembers
// Adapted bodies: none
#include "NiBillboardNode_f02ca0.h"

void CopyNodeMembers(NiNode& source, NiNode* dest);

void NiBillboardNode::CopyMembers(NiBillboardNode* dest)
{
    CopyNodeMembers(*this, dest);
    dest->mode = mode;
}
