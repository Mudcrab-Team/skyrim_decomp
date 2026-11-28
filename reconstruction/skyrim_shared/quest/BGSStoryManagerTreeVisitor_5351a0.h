// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSStoryManagerTreeVisitor: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTArrayHeapAllocator, BSTArrayBase, VisitorArray, FreeData, items: GUESS(low) STANDIN
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

class VisitorArray : public BSTArrayHeapAllocator, public BSTArrayBase
{
public:
    ~VisitorArray()
    {
        if (data != nullptr)
        {
            FreeData();
            size = 0;
        }
    }
};

class BGSStoryManagerTreeVisitor
{
public:
    virtual ~BGSStoryManagerTreeVisitor();

    std::uint8_t unk08[0x18];
    VisitorArray items;
};

static_assert(offsetof(BGSStoryManagerTreeVisitor, items) == 0x20, "items offset");
