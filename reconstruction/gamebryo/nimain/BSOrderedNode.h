// Code origin: hand-written class layouts and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared bodies are written from the local listings.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOrderedNode, BSOrderedNode::RegisterStreamables, BSOrderedNode::OnVisible, BSOrderedNode::~BSOrderedNode, BSOrderedNode::GetRTTI, BSOrderedNode::CreateClone, BSOrderedNode::LoadBinary, BSOrderedNode::LinkObject, BSOrderedNode::SaveBinary, BSOrderedNode::IsEqual, BSOrderedNode::UpdateDownwardPass, BSOrderedNode::UpdateSelectedDownwardPass, BSNiNode::~BSNiNode, BSNiNode::GetRTTI, BSNiNode::CreateClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSNiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBound, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSOrderedNode::orderedBound, BSOrderedNode::useStaticBound, BSOrderedNode::pad13C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiNode.h"

struct NiPoint3
{
    float x;  // 0
    float y;  // 4
    float z;  // 8
};

struct NiBound
{
    NiPoint3 center;  // 00
    float radius;  // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

class BSNiNode : public NiNode
{
public:
    ~BSNiNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
};
static_assert(sizeof(BSNiNode) == 0x128, "BSNiNode size");

class BSOrderedNode : public BSNiNode
{
public:
    ~BSOrderedNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    virtual bool RegisterStreamables(NiStream& a_stream);  // compared: 0x1570370  // slot 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
    void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
    virtual void OnVisible(NiCullingProcess& a_process);  // compared: 0x1570700  // slot 34

    NiBound orderedBound;  // 128
    bool useStaticBound;  // 138
    std::uint32_t pad13C;  // 13C
};
static_assert(sizeof(BSOrderedNode) == 0x140, "BSOrderedNode size");
static_assert(offsetof(BSOrderedNode, orderedBound) == 0x128, "BSOrderedNode members");
