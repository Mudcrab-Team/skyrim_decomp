// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2dc8c0Base::~Obj2dc8c0Base and Obj2dc8c0::~Obj2dc8c0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// FreeHashTable, Obj2dc8c0Base, Obj2dc8c0: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable(void* a_table);

class Obj2dc8c0Base
{
public:
    virtual ~Obj2dc8c0Base()
    {
        RemoveAll();
        FreeHashTable(m_hashTable);
    }

    void RemoveAll();

    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
    std::uint32_t m_count;     // 0x18
};
static_assert(sizeof(Obj2dc8c0Base) == 0x20, "Obj2dc8c0Base size");

class Obj2dc8c0 : public Obj2dc8c0Base
{
public:
    Obj2dc8c0();

    ~Obj2dc8c0() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(Obj2dc8c0) == 0x20, "Obj2dc8c0 size");
