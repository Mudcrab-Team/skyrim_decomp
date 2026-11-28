// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase216240::~NiTMapBase216240, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// NiFree216240, NiTMapBase216240, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void NiFree216240(void* ptr);

class NiTMapBase216240
{
public:
    NiTMapBase216240();
    virtual ~NiTMapBase216240();
    void RemoveAll();

    std::uint32_t hashSize;   // 08
    void** hashTable;         // 10
    std::uint32_t count;      // 18
};

static_assert(sizeof(NiTMapBase216240) == 0x20, "NiTMapBase216240 size");
