// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSIdleCollection, BGSIdleCollection::~BGSIdleCollection, BGSIdleCollection::idleCount, BGSIdleCollection::idles, BaseFormComponent, MemoryManager, TESIdleForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSIdleCollection::Free: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// MemoryManager::EnsureInit: CRASHLOGGER_PDB(59818@2026.10.24)
// g_allocationContext, AllocationContextScope, saved, g_memoryManager, g_memoryManagerGuard, unk08, unk0A, unk18: GUESS(low)
// Adapted bodies: BGSIdleCollection::~BGSIdleCollection follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp:182
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp:210
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"

class TESIdleForm;

struct MemoryManager
{
    void EnsureInit(std::uint32_t* guard);
    void Deallocate(void* memory, bool aligned);
};

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerGuard;

extern __declspec(thread) std::uint32_t g_allocationContext;

class AllocationContextScope
{
public:
    explicit AllocationContextScope(std::uint32_t context) : saved(g_allocationContext)
    {
        g_allocationContext = context;
    }

    ~AllocationContextScope() { g_allocationContext = saved; }

private:
    std::uint32_t saved;
};

class BGSIdleCollection : public BaseFormComponent
{
public:
    BGSIdleCollection();
    ~BGSIdleCollection() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void Free();

    std::uint8_t unk08;
    std::int8_t idleCount;
    std::uint8_t unk0A[6];
    TESIdleForm** idles;
    std::uint8_t unk18[8];
};
static_assert(sizeof(BGSIdleCollection) == 0x20, "BGSIdleCollection size");
