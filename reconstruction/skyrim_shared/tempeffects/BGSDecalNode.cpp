// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x2033b0 BGSDecalNode::Function2033b0
// Adapted bodies: none
// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, members and declarations
// from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); no body is copied from any source.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
#include "BGSDecalNode.h"

void BGSDecalNode::Function2033b0(BSTempEffect* a_decal)
{
    NiPointer<BSTempEffect> local{ a_decal };
    PushDecal(&decals, &local, true);
}

NiObject* BGSDecalNode::CreateClone(NiCloningProcess& a_cloning)
{
    return CreateNodeInstance(g_nodeInstanceOwner, nullptr, nullptr);
}

void BGSDecalNode::AttachDecal(BSTempEffect* a_decal, bool a_firstAvail)
{
    NiNode::AttachChild(a_decal->Get3D(), a_firstAvail);
}
