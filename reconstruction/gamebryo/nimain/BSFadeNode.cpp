// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); bodies written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x106b550 BSFadeNode::UpdateCollisionObject
// 0x14e5a20 BSFadeNode::ctor
// 0x14e6a10 BSFadeNode::Function14e6a10
#include "BSFadeNode.h"

void BSFadeNode::UpdateCollisionObject(bool a_arg)
{
    const std::uint32_t state = a_arg ^ 1;
    SetCollisionState(state);
}

BSFadeNode::BSFadeNode() :
    NiNode(0)
{
    InitRuntimeData();
}

void BSFadeNode::Function14e6a10(std::uint8_t a_value)
{
    unk153 &= 0xf0;
    unk153 |= a_value & 0x0f;
}
