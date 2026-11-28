// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSSceneActionPackage, BGSSceneAction, packages: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTArrayHeapAllocator, BSTArrayBase, PackageArray, FreeData: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BSTArrayHeapAllocator
{
public:
    ~BSTArrayHeapAllocator();
    void FreeData();

    void* data;
    std::uint64_t capacity;
};

class BSTArrayBase
{
public:
    ~BSTArrayBase();

    std::uint32_t size;
    std::uint32_t unk04;
};

class PackageArray : public BSTArrayHeapAllocator, public BSTArrayBase
{
public:
    ~PackageArray()
    {
        if (data != nullptr)
        {
            FreeData();
            size = 0;
        }
    }
};

class BGSSceneAction
{
public:
    virtual ~BGSSceneAction() {}

    std::uint8_t unk08[0x18];
};

class BGSSceneActionPackage : public BGSSceneAction
{
public:
    BGSSceneActionPackage();

    std::uint64_t unk20;
    PackageArray packages;
};

static_assert(offsetof(BGSSceneActionPackage, packages) == 0x28, "packages offset");
static_assert(sizeof(BGSSceneActionPackage) == 0x40, "BGSSceneActionPackage size");
