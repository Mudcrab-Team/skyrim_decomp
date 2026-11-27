// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports MemoryContextScope::~MemoryContextScope as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00c80000_o2.cpp:6643
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c80000_o2.cpp:5505
// TESObjectCELL, TESObjectLAND, cellFlags, cellLand, SetLand: CRASHLOGGER_PDB(59818@2026.10.24)
// gMemoryContext_tls_0x768, MemoryContextScope, previousContext, unknown000, unknown042: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

extern __declspec(thread) std::uint32_t gMemoryContext_tls_0x768;

class TESObjectLAND
{
public:
    virtual ~TESObjectLAND();
};

class TESObjectCELL
{
public:
    void SetLand(TESObjectLAND* land);

    std::uint8_t   unknown000[0x40];  // 000
    std::uint16_t  cellFlags;         // 040
    std::uint8_t   unknown042[0x2E];  // 042
    TESObjectLAND* cellLand;          // 070
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL, cellLand) == 0x70, "cellLand offset");
