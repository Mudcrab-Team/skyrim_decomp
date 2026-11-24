// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess, ActorProcess::SetDamageRootNode: GUESS(low)
// MiddleHighProcessData, damageRootNode, headNode, torsoNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiNode;
struct NiAVObject;

struct MiddleHighProcessData
{
    std::uint8_t pad00[0x118];
    NiNode* damageRootNode[6];  // 118
    NiAVObject* unk148;         // 148
    NiNode* weaponBone;         // 150
    NiAVObject* headNode;       // 158
    NiAVObject* torsoNode;      // 160
};

class ActorProcess
{
public:
    void SetDamageRootNode(std::int32_t a_index, NiNode* a_node);  // compared: 0x7273d0

    void* unk00;
    MiddleHighProcessData* middleHigh;  // 008
};
