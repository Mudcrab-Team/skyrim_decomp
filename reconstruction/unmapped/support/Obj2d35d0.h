// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d35d0Base::~Obj2d35d0Base and Obj2d35d0::~Obj2d35d0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// FreeHashTable, Obj2d35d0Base, Obj2d35d0: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable(void* a_table);

class Obj2d35d0Base
{
public:
    virtual ~Obj2d35d0Base()
    {
        RemoveAll();
        FreeHashTable(m_hashTable);
    }

    void RemoveAll();

    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
    std::uint32_t m_count;     // 0x18
};
static_assert(sizeof(Obj2d35d0Base) == 0x20, "Obj2d35d0Base size");

class Obj2d35d0 : public Obj2d35d0Base
{
public:
    Obj2d35d0();

    ~Obj2d35d0() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(Obj2d35d0) == 0x20, "Obj2d35d0 size");
