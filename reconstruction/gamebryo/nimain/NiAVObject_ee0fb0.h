// Source exposure: mixed (pinned-image observations; community declarations).
// Code origin: original; compact declarations using labelled names and observed offsets
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, NiAVObject::SavePreviousWorldTransformRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, NiPoint3, NiMatrix3, NiTransform, world, previousWorld, children: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AsNode, data, freeIdx: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk00, Unk01, Unk02, unknown08, unknownE4, flags02, unknown10A, unknown110, capacity, size, growSize: STANDIN GUESS(low); partial declarations at observed offsets
#pragma once
#include <cstdint>
#include <cstddef>
class NiNode;
struct NiPoint3
{
    float x, y, z;
    NiPoint3& operator=(const NiPoint3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};
struct NiMatrix3 { float entry[3][3]; };
struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};
class NiAVObject
{
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual NiNode* AsNode();
    void SavePreviousWorldTransformRecursive();
    std::uint8_t unknown08[0x74];
    NiTransform world;
    NiTransform previousWorld;
    std::uint8_t unknownE4[0x25];
    std::uint8_t flags02;
    std::uint8_t unknown10A[6];
};
class NiNode : public NiAVObject
{
public:
    struct ChildArray
    {
        void* unknown110;
        NiAVObject** data;
        std::uint16_t capacity;
        std::uint16_t freeIdx;
        std::uint16_t size;
        std::uint16_t growSize;
    } children;
};
static_assert(sizeof(NiTransform) == 0x34, "Observed transform extent");
static_assert(sizeof(NiAVObject) == 0x110, "Observed object extent");
