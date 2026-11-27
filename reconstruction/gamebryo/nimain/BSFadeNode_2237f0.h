// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiAVObject, NiNode, BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode::FindScabbardNode: CRASHLOGGER_PDB(59818@2026.10.24)
// gScabbardName, gWeaponPrefix, NiAVObject::Unk_00, NiAVObject::Unk_01, NiAVObject::Unk_02, NiAVObject::AsNode, NiAVObject::unk08, NiAVObject::name, NiAVObject::unk18, NiNode::Unk_04, NiNode::Unk_05, NiNode::Unk_06, NiNode::Unk_07, NiNode::Unk_08, NiNode::Unk_09, NiNode::Unk_0A, NiNode::Unk_0B, NiNode::Unk_0C, NiNode::Unk_0D, NiNode::Unk_0E, NiNode::Unk_0F, NiNode::Unk_10, NiNode::Unk_11, NiNode::Unk_12, NiNode::Unk_13, NiNode::Unk_14, NiNode::Unk_15, NiNode::Unk_16, NiNode::Unk_17, NiNode::Unk_18, NiNode::Unk_19, NiNode::Unk_1A, NiNode::Unk_1B, NiNode::Unk_1C, NiNode::Unk_1D, NiNode::Unk_1E, NiNode::Unk_1F, NiNode::Unk_20, NiNode::Unk_21, NiNode::Unk_22, NiNode::Unk_23, NiNode::Unk_24, NiNode::Unk_25, NiNode::Unk_26, NiNode::Unk_27, NiNode::Unk_28, NiNode::Unk_29, NiNode::Unk_2A, NiNode::Unk_2B, NiNode::Unk_2C, NiNode::Unk_2D, NiNode::Unk_2E, NiNode::Unk_2F, NiNode::Unk_30, NiNode::Unk_31, NiNode::Unk_32, NiNode::Unk_33, NiNode::Unk_34, NiNode::Unk_35, NiNode::Unk_36, NiNode::Unk_37, NiNode::Unk_38, NiNode::Unk_39, NiNode::DetachChildAt, NiNode::children, NiNode::unk120, NiNode::childCapacity: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiNode;

extern const char gScabbardName[];
extern const char gWeaponPrefix[];

class NiAVObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* AsNode();

    std::uint64_t unk08;
    const char* name;
    std::uint8_t unk18[0x100];
};
static_assert(offsetof(NiAVObject, name) == 0x10, "name offset");
static_assert(sizeof(NiAVObject) == 0x118, "NiAVObject size");

class NiNode : public NiAVObject
{
public:
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
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void DetachChildAt(std::uint32_t a_index);

    NiAVObject** children;
    std::uint16_t unk120;
    std::uint16_t childCapacity;
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childCapacity) == 0x122, "childCapacity offset");

class BSFadeNode : public NiNode
{
public:
    bool FindScabbardNode();
};
