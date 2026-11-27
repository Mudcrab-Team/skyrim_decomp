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

class PoolGuard {
public:
    explicit PoolGuard(long* lock) : held(lock)
    {
        if (held) {
            // Yield while another thread owns the pool.
            while (_InterlockedCompareExchange(held, 1, 0) != 0) {
                Sleep(0);
            }
            // Finish acquiring the lock before accessing the pool.
            _mm_mfence();
        }
    }

    PoolGuard(const PoolGuard&) = delete;
    PoolGuard& operator=(const PoolGuard&) = delete;

    ~PoolGuard()
    {
        if (held) {
            *held = 0;
            // Order the unlock before subsequent memory accesses.
            _mm_mfence();
        }
    }

private:
    // The unwind cleanup tests this pointer before releasing the lock.
    long* const held;
};

extern long poolLock;
extern bool poolEnabled;
extern unsigned int freeSlots;

extern struct BSCompoundFrustum frustumPool[32];
