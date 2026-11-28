// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMapBase216160::~NiTMapBase216160 and NiTMap216160::~NiTMap216160, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// NiFree216160, NiTMapBase216160, NiTMap216160, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void NiFree216160(void* ptr);

class NiTMapBase216160
{
public:
    virtual ~NiTMapBase216160();
    void RemoveAll();

    std::uint32_t hashSize;   // 08
    void** hashTable;         // 10
    std::uint32_t count;      // 18
};

class NiTMap216160 : public NiTMapBase216160
{
public:
    NiTMap216160();
    ~NiTMap216160() override;
};

static_assert(sizeof(NiTMap216160) == 0x20, "NiTMap216160 size");
