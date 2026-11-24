// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xce32d0 BSReadWriteLock::LockForWrite
// Adapted bodies: none
#include "BSReadWriteLock_ce32d0.h"

#include <intrin.h>

void BSReadWriteLock::LockForWrite()
{
    const std::uint32_t threadId = GetCurrentThreadId();
    if (_writerThread == threadId) {
        // atomic: the writer re-enters
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lock));
        return;
    }

    SpinBackoff backoff;
    // atomic: claim the lock word only when it is free
    while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lock), static_cast<long>(kLockWrite | 1), 0) != 0) {
        backoff.Pause();
    }
    _writerThread = threadId;
    // fence: publish the owner before the protected data is touched
    _mm_mfence();
}
