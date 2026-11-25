// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, ActorProcess::UnlockOwnedData, OwnedData, Lock, Lock::Unlock: GUESS(low) STANDIN
// owner, count, data, GetCurrentThreadId: GUESS(low) OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

struct Lock
{
    std::uint32_t owner;
    std::uint32_t count;

    void Unlock()
    {
        // Order the ownership query after prior protected reads.
        _mm_lfence();
        if (owner == GetCurrentThreadId()) {
            if (count == 1) {
                owner = 0;
                // Publish owner clearance before releasing the recursion count.
                _mm_mfence();
                // Release the final recursive hold atomically.
                _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&count), 0, 1);
            } else {
                // A nested hold releases one recursion level atomically.
                _InterlockedDecrement(reinterpret_cast<volatile long*>(&count));
            }
        }
    }
};

struct OwnedData
{
    std::uint8_t pad00[0x1E8];
    Lock lock;  // 1E8
};

class ActorProcess
{
public:
    void UnlockOwnedData();  // compared: 0x721a30

    void* unk00;
    OwnedData* data;  // 008
};
