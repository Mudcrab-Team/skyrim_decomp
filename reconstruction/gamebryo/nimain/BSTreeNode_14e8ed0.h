// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiObject, BSLeafAnimNode, BSTreeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::RegisterStreamables, BSTreeNode::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::Unk_00, NiObject::Unk_01, NiObject::Unk_02, NiObject::Unk_03, NiObject::Unk_04, NiObject::Unk_05, NiObject::Unk_06, NiObject::Unk_07, NiObject::Unk_08, NiObject::Unk_09, NiObject::Unk_0A, NiObject::Unk_0B, NiObject::Unk_0C, NiObject::Unk_0D, NiObject::Unk_0E, NiObject::Unk_0F, NiObject::Unk_10, NiObject::Unk_11, NiObject::Unk_12, NiObject::Unk_13, NiObject::Unk_14, NiObject::Unk_15, NiObject::Unk_16, NiObject::Unk_17, NiObject::Unk_18, NiObject::Unk_19, BSLeafAnimNode::RegisterStreamables, BSLeafAnimNode::unk00, BSTreeNode::unk170, BSTreeNode::array1Data, BSTreeNode::unk190, BSTreeNode::array1Size, BSTreeNode::unk19C, BSTreeNode::array2Data, BSTreeNode::unk1A8, BSTreeNode::array2Size: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiStream;

class NiObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
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
    virtual bool RegisterStreamables(NiStream& a_stream);
};

class BSLeafAnimNode
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    std::uint8_t unk00[0x170];
};
static_assert(sizeof(BSLeafAnimNode) == 0x170, "BSLeafAnimNode size");

class BSTreeNode : public BSLeafAnimNode
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    std::uint8_t unk170[0x18];
    NiObject** array1Data;
    std::uint64_t unk190;
    std::uint32_t array1Size;
    std::uint32_t unk19C;
    NiObject** array2Data;
    std::uint64_t unk1A8;
    std::uint32_t array2Size;
};
static_assert(offsetof(BSTreeNode, array1Data) == 0x188, "array1Data offset");
static_assert(offsetof(BSTreeNode, array1Size) == 0x198, "array1Size offset");
static_assert(offsetof(BSTreeNode, array2Data) == 0x1A0, "array2Data offset");
static_assert(offsetof(BSTreeNode, array2Size) == 0x1B0, "array2Size offset");
