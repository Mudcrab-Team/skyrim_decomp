// Source exposure: mixed (binary-analysis, community-headers).
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// Array storage, indexed search, append and removal reconstructed from the selected build.
// LockedSource_F068_ed3730, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
// Add, Remove, Push, Find, At, Erase, EraseExternal, Reserve, Move, Allocate, Reallocate, Deallocate, Unlock: GUESS(low)
// data, capacity, size, array, owner, count, sinks, pendingRegisters, pendingUnregisters, lock, notifying, ProcessEvent: GUESS(low)
// GetCurrentThreadId: OBSERVED
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "LockedArray_ed3730.h"
#include <intrin.h>
namespace p117_ed3730 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct Lock {
    std::uint32_t owner, count;
    void Unlock() {
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
struct Guard { Lock* lock; Guard(Lock&) noexcept; ~Guard() { if (lock) lock->Unlock(); } };
class LockedSource_F068_ed3730 {
public:
 LockedArray_ed3730<Sink*> sinks,pendingRegisters,pendingUnregisters;
 Lock lock;
 bool notifying;
 void Add(Sink*);
 void Remove(Sink*);
};
static_assert(sizeof(LockedSource_F068_ed3730)==0x58,"source layout");
}
