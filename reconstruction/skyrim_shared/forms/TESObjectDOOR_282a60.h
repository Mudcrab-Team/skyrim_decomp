// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectDOOR, TESObjectDOOR::randomTeleports, BSTArrayHeapAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectDOOR::ClearData: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectDOOR::ClearRandomTeleportList: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// g_allocationContext, saved, TeleportArray, Release, unk20, unk0C: GUESS(low)
// Adapted bodies: TESObjectDOOR::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectdoor.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311 (AutoMemContext destructor similarity, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (AutoMemContext constructor similarity, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectdoor.cpp:259
#pragma once

#include <cstdint>
#include "declarations/TESForm.h"

extern __declspec(thread) std::uint32_t g_allocationContext;

// AutoMemContext, AutoMemContext::~AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
class AutoMemContext
{
public:
    explicit AutoMemContext(std::uint32_t context) : saved(g_allocationContext)
    {
        g_allocationContext = context;
    }

    ~AutoMemContext();

private:
    std::uint32_t saved;
};

struct BSTArrayHeapAllocator
{
    void Release();
    TESForm** data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
};

struct TeleportArray
{
    void Clear()
    {
        if (allocator.data)
        {
            allocator.Release();
            size = 0;
        }
    }

    BSTArrayHeapAllocator allocator;
    std::uint32_t size;
};

class TESObjectDOOR : public TESForm
{
public:
    void ClearData() override;
    void ClearRandomTeleportList();

    std::uint8_t unk20[0x98];
    TeleportArray randomTeleports;
};
