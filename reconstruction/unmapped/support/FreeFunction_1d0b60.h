// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1d0b60::~MapBase1d0b60 and PointerMap1d0b60::~PointerMap1d0b60, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// MapBase1d0b60, PointerMap1d0b60, FreeHashTable1d0b60, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable1d0b60(void* a_table);

class MapBase1d0b60
{
public:
    virtual ~MapBase1d0b60()
    {
        RemoveAll();
        FreeHashTable1d0b60(hashTable);
    }

    void RemoveAll();

    std::uint32_t hashSize;  // 08
    void** hashTable;        // 10
    std::uint32_t count;     // 18
};
static_assert(sizeof(MapBase1d0b60) == 0x20, "MapBase1d0b60 size");

class PointerMap1d0b60 : public MapBase1d0b60
{
public:
    PointerMap1d0b60();

    ~PointerMap1d0b60() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(PointerMap1d0b60) == 0x20, "PointerMap1d0b60 size");
