// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiMatrix3, NiUpdateData, NiAVObject, NiNode, BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode::SetFirstChildLocalRotation: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMatrix3::entry, NiUpdateData::time, NiUpdateData::flags, NiAVObject::Unk_00, NiAVObject::Unk_01, NiAVObject::Unk_02, NiAVObject::AsNode, NiAVObject::Unk_04, NiAVObject::Unk_05, NiAVObject::Unk_06, NiAVObject::Unk_07, NiAVObject::Unk_08, NiAVObject::Unk_09, NiAVObject::Unk_0A, NiAVObject::Unk_0B, NiAVObject::Unk_0C, NiAVObject::Unk_0D, NiAVObject::Unk_0E, NiAVObject::Unk_0F, NiAVObject::Unk_10, NiAVObject::Unk_11, NiAVObject::Unk_12, NiAVObject::Unk_13, NiAVObject::Unk_14, NiAVObject::Unk_15, NiAVObject::Unk_16, NiAVObject::Unk_17, NiAVObject::Unk_18, NiAVObject::Unk_19, NiAVObject::Unk_1A, NiAVObject::Unk_1B, NiAVObject::Unk_1C, NiAVObject::Unk_1D, NiAVObject::Unk_1E, NiAVObject::Unk_1F, NiAVObject::Unk_20, NiAVObject::Unk_21, NiAVObject::Unk_22, NiAVObject::Unk_23, NiAVObject::Unk_24, NiAVObject::Unk_25, NiAVObject::Unk_26, NiAVObject::Unk_27, NiAVObject::Unk_28, NiAVObject::Unk_29, NiAVObject::Unk_2A, NiAVObject::Unk_2B, NiAVObject::Unk_2C, NiAVObject::Unk_2D, NiAVObject::Unk_2E, NiAVObject::Unk_2F, NiAVObject::Update, NiAVObject::unk08, NiAVObject::localRotate, NiAVObject::unk6C, NiNode::children, NiNode::unk120, NiNode::childCapacity: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiNode;

struct NiMatrix3
{
    float entry[3][3];
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 size");

struct NiUpdateData
{
    float time;
    std::uint32_t flags;
};
static_assert(sizeof(NiUpdateData) == 0x08, "NiUpdateData size");

class NiAVObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* AsNode();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Update(NiUpdateData& a_data);

    std::uint8_t unk08[0x40];
    NiMatrix3 localRotate;
    std::uint8_t unk6C[0xAC];
};
static_assert(offsetof(NiAVObject, localRotate) == 0x48, "localRotate offset");
static_assert(sizeof(NiAVObject) == 0x118, "NiAVObject size");

class NiNode : public NiAVObject
{
public:
    NiAVObject** children;
    std::uint16_t unk120;
    std::uint16_t childCapacity;
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childCapacity) == 0x122, "childCapacity offset");

class BSFadeNode : public NiNode
{
public:
    void SetFirstChildLocalRotation(const NiMatrix3& a_rot);
};
