// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraDecalGroup, ExtraDecalGroup::~ExtraDecalGroup, BSExtraData, BGSDecalGroup, decalGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// DecalArrayAllocator, DecalArrayBase, DecalArray, FreeData, next, unknown00, listA, listB: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class DecalArrayAllocator
{
public:
    ~DecalArrayAllocator();
    void FreeData();

    void* data;
    std::uint32_t capacity;
    std::uint32_t reserved0C;
};

class DecalArrayBase
{
public:
    ~DecalArrayBase();

    std::uint32_t size;
};

class DecalArray : public DecalArrayAllocator, public DecalArrayBase
{
public:
    void Clear()
    {
        if (data) {
            FreeData();
            size = 0;
        }
    }

    ~DecalArray()
    {
        if (data) {
            FreeData();
            size = 0;
        }
    }
};
static_assert(sizeof(DecalArray) == 0x18, "DecalArray size");

class BGSDecalGroup
{
public:
    ~BGSDecalGroup()
    {
        listA.Clear();
    }

    std::uint64_t unknown00;  // 00
    DecalArray listA;         // 08
    DecalArray listB;         // 20
};
static_assert(sizeof(BGSDecalGroup) == 0x38, "BGSDecalGroup size");

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;  // 08
};

class ExtraDecalGroup : public BSExtraData
{
public:
    ~ExtraDecalGroup() override;  // compared: 0x18c0c0

    BGSDecalGroup* decalGroup;  // 10
};
static_assert(sizeof(ExtraDecalGroup) == 0x18, "ExtraDecalGroup size");
