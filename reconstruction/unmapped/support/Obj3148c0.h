// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj3148c0Base::~Obj3148c0Base and Obj3148c0::~Obj3148c0, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// FreeHashTable, Obj3148c0Base, Obj3148c0: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable(void* a_table);

class Obj3148c0Base
{
public:
    virtual ~Obj3148c0Base()
    {
        RemoveAll();
        FreeHashTable(m_hashTable);
    }

    void RemoveAll();

    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
    std::uint32_t m_count;     // 0x18
};
static_assert(sizeof(Obj3148c0Base) == 0x20, "Obj3148c0Base size");

class Obj3148c0 : public Obj3148c0Base
{
public:
    Obj3148c0();

    ~Obj3148c0() override
    {
        RemoveAll();
    }
};
static_assert(sizeof(Obj3148c0) == 0x20, "Obj3148c0 size");
