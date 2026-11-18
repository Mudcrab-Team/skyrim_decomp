// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, members and declarations
// from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); no body is copied from any source.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0x2030b0 BGSDecalNode::CreateClone
// 0x203360 BGSDecalNode::AttachDecal
#include "BGSDecalNode.h"

NiObject* BGSDecalNode::CreateClone(NiCloningProcess& a_cloning)
{
    return CreateNodeInstance(g_nodeInstanceOwner, nullptr, nullptr);
}

void BGSDecalNode::AttachDecal(BSTempEffect* a_decal, bool a_firstAvail)
{
    NiNode::AttachChild(a_decal->Get3D(), a_firstAvail);
}
