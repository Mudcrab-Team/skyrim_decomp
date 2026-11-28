// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Base2d1460::~Base2d1460 and Obj2d1460::~Obj2d1460, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// Base2d1460, Obj2d1460, FreeBuckets2d1460: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

void FreeBuckets2d1460(void* a_buckets);

class Base2d1460
{
public:
    virtual ~Base2d1460()
    {
        Clear();
        FreeBuckets2d1460(buckets);
    }

    void Clear();

    std::uint64_t unk08;  // 0x08
    void* buckets;        // 0x10
};

class Obj2d1460 : public Base2d1460
{
public:
    ~Obj2d1460() override;
};

static_assert(offsetof(Base2d1460, buckets) == 0x10, "buckets offset");
