// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase2161d0::~NiTMapBase2161d0 and NiTMap2161d0::~NiTMap2161d0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// NiFree2161d0, NiTMapBase2161d0, NiTMap2161d0, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void NiFree2161d0(void* ptr);

class NiTMapBase2161d0
{
public:
    virtual ~NiTMapBase2161d0();
    void RemoveAll();

    std::uint32_t hashSize;   // 08
    void** hashTable;         // 10
    std::uint32_t count;      // 18
};

class NiTMap2161d0 : public NiTMapBase2161d0
{
public:
    NiTMap2161d0();
    ~NiTMap2161d0() override;
};

static_assert(sizeof(NiTMap2161d0) == 0x20, "NiTMap2161d0 size");
