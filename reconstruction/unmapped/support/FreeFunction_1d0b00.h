// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase1d0b00::~MapBase1d0b00, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// MapBase1d0b00, FreeHashTable1d0b00, RemoveAll, hashSize, hashTable, count: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable1d0b00(void* a_table);

class MapBase1d0b00
{
public:
    MapBase1d0b00();

    virtual ~MapBase1d0b00()
    {
        RemoveAll();
        FreeHashTable1d0b00(hashTable);
    }

    void RemoveAll();

    std::uint32_t hashSize;  // 08
    void** hashTable;        // 10
    std::uint32_t count;     // 18
};
static_assert(sizeof(MapBase1d0b00) == 0x20, "MapBase1d0b00 size");
