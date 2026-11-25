// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum, AllocateFromPool, ReleaseToPool: CRASHLOGGER_PDB(59818@2026.10.24)
// PoolGuard, poolLock, poolEnabled, freeSlots and frustumPool: GUESS(low)
#pragma once

#include "BSCompoundFrustum_ff72a0.h"
#include <cstdint>
#include <intrin.h>
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
void operator delete(void* object, std::size_t size) noexcept;
struct PoolGuard {
    explicit PoolGuard(long& lock) : held(&lock)
    {
        // Yield while another thread owns the pool.
        while (_InterlockedCompareExchange(held, 1, 0) != 0) {
            Sleep(0);
        }
        // Finish acquiring the pool before accessing its entries.
        _mm_mfence();
    }
    ~PoolGuard()
    {
        if (!held) {
            return;
        }
        *held = 0;
        // Publish changes to the free slots before the caller continues.
        _mm_mfence();
    }
    long* held;
};
extern long poolLock;
extern bool poolEnabled;
extern unsigned int freeSlots;

extern struct BSCompoundFrustum frustumPool[32];
