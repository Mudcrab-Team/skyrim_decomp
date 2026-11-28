// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d1500Base::~Obj2d1500Base and Obj2d1500::~Obj2d1500, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// FreeHashTable, Obj2d1500Base, Obj2d1500: GUESS(low)
#pragma once

#include <cstdint>

void FreeHashTable(void* a_table);

class Obj2d1500Base
{
public:
    virtual ~Obj2d1500Base()
    {
        RemoveAll();
        FreeHashTable(m_hashTable);
    }

    void RemoveAll();

    std::uint32_t m_hashSize;  // 0x08
    void** m_hashTable;        // 0x10
};

class Obj2d1500 : public Obj2d1500Base
{
public:
    ~Obj2d1500() override;
};
