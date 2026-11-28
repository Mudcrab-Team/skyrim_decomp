// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1de390::~MapBase1de390 and Map1de390::~Map1de390, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// MapBase1de390, Map1de390, FreeHashTable1de390, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable1de390(void* a_table);

class MapBase1de390
{
public:
    virtual ~MapBase1de390()
    {
        RemoveAll();
        FreeHashTable1de390(hashTable);
    }

    void RemoveAll();

    std::uint32_t hashSize;  // 08
    void** hashTable;        // 10
    std::uint32_t count;     // 18
};
static_assert(sizeof(MapBase1de390) == 0x20, "MapBase1de390 size");

class Map1de390 : public MapBase1de390
{
public:
    Map1de390();

    ~Map1de390() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(Map1de390) == 0x20, "Map1de390 size");
