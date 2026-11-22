// Code origin: names, bases, slot order and member layout adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// Source exposure: mixed (community declarations and the contributor-owned pack;
// 0xff3470 compared function
// 0xff3450 compared function
// 0xff3430 compared function
// 0xff3380 compared function
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

// Inner, BSMultiBound and their virtual slots: GUESS(low)
class Inner
{
public:
    virtual void i0();  // slot 0x00
    virtual void i1();  // slot 0x01
    virtual void i2();  // slot 0x02
    virtual void i3();  // slot 0x03
    virtual void i4();  // slot 0x04
    virtual void i5();  // slot 0x05
    virtual void i6();  // slot 0x06
    virtual void i7();  // slot 0x07
    virtual void i8();  // slot 0x08
    virtual void i9();  // slot 0x09
    virtual void i10();  // slot 0x0a
    virtual void i11();  // slot 0x0b
    virtual void i12();  // slot 0x0c
    virtual void i13();  // slot 0x0d
    virtual void i14();  // slot 0x0e
    virtual void i15();  // slot 0x0f
    virtual void i16();  // slot 0x10
    virtual void i17();  // slot 0x11
    virtual void i18();  // slot 0x12
    virtual void i19();  // slot 0x13
    virtual void i20();  // slot 0x14
    virtual void i21();  // slot 0x15
    virtual void i22();  // slot 0x16
    virtual void i23();  // slot 0x17
    virtual void i24();  // slot 0x18
    virtual void i25();  // slot 0x19
    virtual void i26();  // slot 0x1a
    virtual void i27();  // slot 0x1b
    virtual void i28();  // slot 0x1c
    virtual void i29();  // slot 0x1d
    virtual void i30();  // slot 0x1e
    virtual void i31();  // slot 0x1f
    virtual void i32();  // slot 0x20
    virtual void i33();  // slot 0x21
    virtual void i34();  // slot 0x22
    virtual void i35();  // slot 0x23
    virtual void i36();  // slot 0x24
    virtual void i37();  // slot 0x25
    virtual void i38();  // slot 0x26
    virtual void i39();  // slot 0x27
    virtual void i40();  // slot 0x28

    std::uint8_t pad00[0x10];  // 00
};
static_assert(sizeof(Inner) == 0x18, "Inner size");

class BSMultiBound
{
public:
    virtual void b0();  // slot 0x00
    virtual void b1();  // slot 0x01
    virtual void b2();  // slot 0x02
    virtual void b3();  // slot 0x03
    virtual void b4();  // slot 0x04
    virtual void b5();  // slot 0x05
    virtual void b6();  // slot 0x06
    virtual void b7();  // slot 0x07
    virtual void b8();  // slot 0x08
    virtual void b9();  // slot 0x09
    virtual void b10();  // slot 0x0a
    virtual void b11();  // slot 0x0b
    virtual void b12();  // slot 0x0c
    virtual void b13();  // slot 0x0d
    virtual void b14();  // slot 0x0e
    virtual void b15();  // slot 0x0f
    virtual void b16();  // slot 0x10
    virtual void b17();  // slot 0x11
    virtual void b18();  // slot 0x12
    virtual void b19();  // slot 0x13
    virtual void b20();  // slot 0x14
    virtual void b21();  // slot 0x15
    virtual void b22();  // slot 0x16
    virtual void b23();  // slot 0x17
    virtual void b24();  // slot 0x18
    virtual void b25();  // slot 0x19
    virtual void b26();  // slot 0x1a
    virtual void b27();  // slot 0x1b
    virtual void b28();  // slot 0x1c
    virtual void b29();  // slot 0x1d
    virtual void b30();  // slot 0x1e
    virtual void b31();  // slot 0x1f
    virtual void b32();  // slot 0x20
    virtual void b33();  // slot 0x21
    virtual void b34();  // slot 0x22
    virtual void b35();  // slot 0x23
    virtual void b36();  // slot 0x24
    virtual void* b37();  // slot 0x128

    std::uint8_t pad08[0x10];  // 08
    Inner* inner;  // 18
};
static_assert(offsetof(BSMultiBound, inner) == 0x18, "inner offset");

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

    void Functionff3380();  // compared: 0xff3380
    void* Functionff3430();  // compared: 0xff3430
    void Functionff3450();  // compared: 0xff3450
    void Functionff3470();  // compared: 0xff3470

    BSMultiBound* multiBound;  // 128, NG: NiPointer<BSMultiBound>
    std::uint32_t cullingMode;  // 130, NG: BSCullingProcess::BSCPCullingType
    float lastAccumTime;  // 134
};
static_assert(sizeof(BSMultiBoundNode) == 0x138, "BSMultiBoundNode size");
static_assert(offsetof(BSMultiBoundNode, multiBound) == 0x128, "multiBound offset");
