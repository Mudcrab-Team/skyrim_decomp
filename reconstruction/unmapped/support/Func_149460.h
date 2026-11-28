// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Base149460::~Base149460, Mid149460::~Mid149460 and Func_149460::~Func_149460, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap and NiTStringTemplateMap::~NiTStringTemplateMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:596
// SPDX-License-Identifier: CC0-1.0
// Node149460: GUESS(low)
// Base149460: GUESS(low)
// Mid149460: GUESS(low)
// Func_149460: GUESS(low)
#pragma once

#include <cstdint>

struct Node149460
{
    Node149460* next;
    void* key;
    std::uint64_t value;
};

extern void FreeMem149460(void* ptr);

struct Base149460
{
    virtual ~Base149460()
    {
        RemoveAll();
        FreeMem149460(buckets);
    }

    void RemoveAll();

    std::uint32_t bucketCount;
    Node149460** buckets;
    std::uint32_t entryCount;
    std::uint32_t unk1C;
};

struct Mid149460 : Base149460
{
    ~Mid149460() override
    {
        RemoveAll();
    }
};

struct Func_149460 : Mid149460
{
    ~Func_149460() override;

    bool copyKeys;
};
