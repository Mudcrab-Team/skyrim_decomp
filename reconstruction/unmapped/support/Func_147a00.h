// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MapBase147a00::~MapBase147a00 and Func_147a00::~Func_147a00, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// SPDX-License-Identifier: CC0-1.0
// MapBase147a00: GUESS(low)
// Func_147a00: GUESS(low)
// FreeBuckets147a00: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuckets147a00(void* buckets);

struct MapBase147a00
{
    virtual ~MapBase147a00()
    {
        RemoveAll();
        FreeBuckets147a00(buckets);
    }

    void RemoveAll();

    std::uint64_t unk08;
    void* buckets;
    std::uint64_t unk18;
};

struct Func_147a00 : MapBase147a00
{
    Func_147a00();
    ~Func_147a00() override
    {
        RemoveAll();
    }
};

static_assert(sizeof(Func_147a00) == 0x20, "Func_147a00 size");
