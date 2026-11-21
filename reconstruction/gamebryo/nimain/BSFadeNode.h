// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the bodies are written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFadeNode, BSFadeNode::BSFadeNode (NG's ctor), ::~BSFadeNode, ::GetRTTI, ::AsFadeNode, ::CreateClone, ::LoadBinary, ::LinkObject, ::RegisterStreamables, ::SaveBinary, ::IsEqual, ::UpdateSelectedDownwardPass, ::OnVisible, ::AsTreeNode, ::AsLeafAnimNode, and the members unk128, unk12C, currentFade, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk152, unk153, unk154, unk155, unk156: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode, NiNode::NiNode, NiNode::children and NiNode's virtual overrides: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); defined here because the shared declarations/NiNode.h keeps the children array as opaque storage and has no constructor
// NiTObjectArray, NiTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the 0x18 byte layout for pointer elements, field names are low-confidence guesses
// BSTreeNode, BSLeafAnimNode, NiAVObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations
// BSFadeNode::UpdateCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only, NG declares no such function and its parameter and body are low-confidence guesses
// BSFadeNode::SetCollisionState (address 0x106b870): STANDIN GUESS(low); a non-virtual helper taking the value by reference
// BSFadeNode::Function14e6a10: GUESS(low); placeholder name for the compared setter of the low nibble of unk153
// BSFadeNode::InitRuntimeData (address 0x14e5eb0): STANDIN GUESS(low); a non-virtual helper called at the end of the constructor
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiAVObject.h"

class BSTreeNode;
class BSLeafAnimNode;
template <class T> class NiPointer;

template <class T>
class NiTArray
{
public:
    virtual ~NiTArray();  // 00

    T*            _data;      // 08
    std::uint16_t _capacity;  // 10
    std::uint16_t _freeIdx;   // 12
    std::uint16_t _size;      // 14
    std::uint16_t _growSize;  // 16
};

template <class T>
class NiTObjectArray : public NiTArray<T>
{
};
static_assert(sizeof(NiTObjectArray<NiAVObject*>) == 0x18, "NiTObjectArray size");

class NiNode : public NiAVObject
{
public:
    NiNode(std::uint32_t a_arrBufLen);
    ~NiNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiNode* AsNode() override;  // 03
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
    void UpdateControllers(NiUpdateData& a_data) override;  // 25
    void PerformOp(PerformOpFunc& a_func) override;  // 26
    void AttachProperty(NiAlphaProperty* a_property) override;  // 27
    NiAVObject* GetObjectByName(const BSFixedString& a_name) override;  // 2A
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
    void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
    void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2E
    void UpdateWorldBound() override;  // 2F
    void UpdateTransformAndBounds(NiUpdateData& a_data) override;  // 31
    void OnVisible(NiCullingProcess& a_process) override;  // 34
    virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail = false);  // 35
    virtual void InsertChildAt(std::uint32_t a_idx, NiAVObject* a_child);  // 36
    virtual void DetachChild1(NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);  // 37
    virtual void DetachChild2(NiAVObject* a_child);  // 38
    virtual void DetachChildAt1(std::uint32_t a_idx, NiPointer<NiAVObject>& a_childOut);  // 39
    virtual void DetachChildAt2(std::uint32_t a_idx);  // 3A
    virtual void SetAt1(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);  // 3B
    virtual void SetAt2(std::uint32_t a_idx, NiAVObject* a_child);  // 3C
    virtual void UpdateUpwardPass(NiUpdateData& a_data);  // 3D

    NiTObjectArray<NiAVObject*> children;  // 110
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");
static_assert(offsetof(NiNode, children) == 0x110, "NiNode::children offset");

class BSFadeNode : public NiNode
{
public:
    BSFadeNode();  // compared: 0x14e5a20
    ~BSFadeNode() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    BSFadeNode* AsFadeNode() override;  // 05
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
    void OnVisible(NiCullingProcess& a_process) override;  // 34
    virtual BSTreeNode* AsTreeNode();  // 3E
    virtual BSLeafAnimNode* AsLeafAnimNode();  // 3F
    void UpdateCollisionObject(bool a_arg);  // compared: 0x106b550
    void Function14e6a10(std::uint8_t a_value);  // compared: 0x14e6a10

    void SetCollisionState(const std::uint32_t& a_state);  // address 0x106b870
    void InitRuntimeData() noexcept;                       // address 0x14e5eb0; declared noexcept because the compared constructor emits no exception-unwind state around this call (evidence from the compare, name is a guess)

    float         unk128;       // 128
    float         unk12C;       // 12C
    float         currentFade;  // 130
    std::uint32_t unk134;       // 134
    std::uint32_t unk138;       // 138
    std::uint32_t unk13C;       // 13C
    float         unk140;       // 140
    std::uint32_t unk144;       // 144
    std::uint32_t unk148;       // 148
    float         unk14C;       // 14C
    std::uint16_t unk150;       // 150
    std::uint8_t  unk152;       // 152
    std::uint8_t  unk153;       // 153
    std::uint8_t  unk154;       // 154
    std::uint8_t  unk155;       // 155
    std::uint16_t unk156;       // 156
};
static_assert(sizeof(BSFadeNode) == 0x158, "BSFadeNode size");
static_assert(offsetof(BSFadeNode, unk128) == 0x128, "BSFadeNode::unk128 offset");
