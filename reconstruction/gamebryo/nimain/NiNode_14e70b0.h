// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, NiNode, BSFadeNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::~NiAVObject, NiAVObject::AsFadeNode, NiAVObject::parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::GetParent: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// NiNode::AsBSFadeNode: GUESS(low)
// unk08, unk38, unknown110, VSlot01, VSlot02, VSlot03, VSlot04: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSFadeNode;
class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();  // 00
    virtual void VSlot01();  // 01
    virtual void VSlot02();  // 02
    virtual void VSlot03();  // 03
    virtual void VSlot04();  // 04
    virtual BSFadeNode* AsFadeNode();  // 05

    NiNode* GetParent() const
    {
        return parent;
    }

    std::uint8_t unk08[0x28];  // 08
    NiNode* parent;  // 30
    std::uint8_t unk38[0xD8];  // 38
};
static_assert(offsetof(NiAVObject, parent) == 0x30, "parent offset");
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiNode : public NiAVObject
{
public:
    BSFadeNode* AsBSFadeNode();  // compared: 0x14e70b0

    std::uint8_t unknown110[0x18];  // 110
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");
