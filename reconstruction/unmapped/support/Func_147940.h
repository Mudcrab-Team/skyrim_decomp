// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_147940::~Func_147940, treated as adapted: shaped like NiTMapBase::~NiTMapBase in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// SPDX-License-Identifier: CC0-1.0
// Func_147940: GUESS(low)
// FreeBuckets147940: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuckets147940(void* buckets);

struct Func_147940
{
    Func_147940();
    virtual ~Func_147940()
    {
        RemoveAll();
        FreeBuckets147940(buckets);
    }

    void RemoveAll();

    std::uint64_t unk08;
    void* buckets;
    std::uint64_t unk18;
};

static_assert(sizeof(Func_147940) == 0x20, "Func_147940 size");
