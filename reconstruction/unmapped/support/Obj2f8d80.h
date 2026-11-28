// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2f8d80::~Obj2f8d80, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// FreeHashTable, Obj2f8d80: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable(void* a_table);

class Obj2f8d80
{
public:
    Obj2f8d80();

    virtual ~Obj2f8d80()
    {
        RemoveAll();
        FreeHashTable(m_hashTable);
    }

    void RemoveAll();

    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
    std::uint32_t m_count;     // 0x18
};
static_assert(sizeof(Obj2f8d80) == 0x20, "Obj2f8d80 size");
