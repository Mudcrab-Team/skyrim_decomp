// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Base1303f90, Object1303f90, g_instanceCount_1303f90, base, first, second: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>
#include <memory>

extern long long g_instanceCount_1303f90;

struct Base1303f90
{
    virtual ~Base1303f90()
    {
        // Atomically decrement the live instance count on destruction.
        _InterlockedExchangeAdd64(&g_instanceCount_1303f90, -1);
    }
};

struct Object1303f90
{
    Base1303f90 base;              // 0x00
    std::shared_ptr<void> first;   // 0x08
    std::shared_ptr<void> second;  // 0x18

    ~Object1303f90();
};
static_assert(offsetof(Object1303f90, first) == 0x08, "first offset");
static_assert(offsetof(Object1303f90, second) == 0x18, "second offset");
