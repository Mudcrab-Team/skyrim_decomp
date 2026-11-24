// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xce3250 BSReadWriteLock::LockForRead
// Adapted bodies: none
#include "BSReadWriteLock_ce3250.h"

#include <intrin.h>

void BSReadWriteLock::LockForRead()
{
    const std::uint32_t threadId = GetCurrentThreadId();
    if (_writerThread == threadId) {
        // atomic: the writer may re-enter as a reader
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lock));
        return;
    }

    std::uint32_t expected = _lock & kLockCountMask;
    SpinBackoff backoff;
    // atomic: take a read slot only while no writer holds the lock
    std::uint32_t seen = static_cast<std::uint32_t>(_InterlockedCompareExchange(
        reinterpret_cast<volatile long*>(&_lock), static_cast<long>(expected + 1), static_cast<long>(expected)));
    while (seen != expected) {
        if (static_cast<std::int32_t>(seen) < 0) {
            backoff.Pause();
            seen = _lock;
        }
        expected = seen & kLockCountMask;
        // atomic: take a read slot only while no writer holds the lock
        seen = static_cast<std::uint32_t>(_InterlockedCompareExchange(
            reinterpret_cast<volatile long*>(&_lock), static_cast<long>(expected + 1), static_cast<long>(expected)));
    }
}
