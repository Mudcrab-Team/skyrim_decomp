// Code origin: names, bases, slot order and member layout adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundNode, BSMultiBoundNode::IsEqual, BSMultiBoundNode::~BSMultiBoundNode, BSMultiBoundNode::GetRTTI, BSMultiBoundNode::AsMultiBoundNode, BSMultiBoundNode::CreateClone, BSMultiBoundNode::LoadBinary, BSMultiBoundNode::LinkObject, BSMultiBoundNode::RegisterStreamables, BSMultiBoundNode::SaveBinary, BSMultiBoundNode::UpdateDownwardPass, BSMultiBoundNode::UpdateWorldBound, BSMultiBoundNode::OnVisible, BSMultiBoundNode::UpdateUpwardPass, BSMultiBoundNode::GetMultiBoundRoom, BSMultiBoundNode::QPointWithin, BSMultiBoundNode::Unk_40, BSMultiBoundNode::Unk_41, BSNiNode::~BSNiNode, BSNiNode::GetRTTI, BSNiNode::CreateClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSNiNode, BSMultiBoundRoom, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// multiBound, cullingMode, lastAccumTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiNode.h"

class BSMultiBoundRoom;
class NiPoint3;

class BSNiNode : public NiNode
{
public:
    ~BSNiNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
};
static_assert(sizeof(BSNiNode) == 0x128, "BSNiNode size");

class BSMultiBoundNode : public BSNiNode
{
public:
    ~BSMultiBoundNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    BSMultiBoundNode* AsMultiBoundNode() override;  // 06
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xff2bc0  // slot 1C
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
    void UpdateWorldBound() override;  // 2F
    void OnVisible(NiCullingProcess& a_process) override;  // 34
    void UpdateUpwardPass(NiUpdateData& a_data) override;  // 3D
    virtual BSMultiBoundRoom* GetMultiBoundRoom();  // 3E
    virtual bool QPointWithin(const NiPoint3& a_point);  // 3F
    virtual void Unk_40(void);  // 40
    virtual void Unk_41(void);  // 41

    class BSMultiBound* multiBound;  // 128, NG: NiPointer<BSMultiBound>
    std::uint32_t cullingMode;  // 130, NG: BSCullingProcess::BSCPCullingType
    float lastAccumTime;  // 134
};
static_assert(sizeof(BSMultiBoundNode) == 0x138, "BSMultiBoundNode size");
static_assert(offsetof(BSMultiBoundNode, multiBound) == 0x128, "multiBound offset");
