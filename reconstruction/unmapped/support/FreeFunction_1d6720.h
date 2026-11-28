// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1d6720::~MapBase1d6720 and Map1d6720::~Map1d6720, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// MapBase1d6720, Map1d6720, FreeHashTable1d6720, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable1d6720(void* a_table);

class MapBase1d6720
{
public:
    virtual ~MapBase1d6720()
    {
        RemoveAll();
        FreeHashTable1d6720(hashTable);
    }

    void RemoveAll();

    std::uint32_t hashSize;  // 08
    void** hashTable;        // 10
    std::uint32_t count;     // 18
};
static_assert(sizeof(MapBase1d6720) == 0x20, "MapBase1d6720 size");

class Map1d6720 : public MapBase1d6720
{
public:
    Map1d6720();

    ~Map1d6720() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(Map1d6720) == 0x20, "Map1d6720 size");
