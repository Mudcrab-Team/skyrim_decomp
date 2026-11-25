// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with the class layout from the header beside this file.
// Code origin: reconstructed from local instruction listings of the pinned image; no adapted community bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0xce34c0 BSReadWriteLock::TryLockForWrite
// 0xce3450 BSReadWriteLock::TryLockForRead
// BSReadWriteLock::TryLockForRead: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// BSReadWriteLock::TryLockForWrite: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#include "BSReadWriteLock_ce3450.h"

#include <intrin.h>

// GetCurrentThreadId: OBSERVED; kernel32 import called by the target
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

bool BSReadWriteLock::TryLockForRead()
{
    const std::uint32_t threadId = GetCurrentThreadId();
    if (_writerThread == threadId) {
        // atomic: the writer may re-enter as a reader
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lock));
        return true;
    }

    std::uint32_t expected = _lock & kLockCountMask;
    // atomic: take a read slot only while no writer holds the lock
    std::uint32_t seen = static_cast<std::uint32_t>(_InterlockedCompareExchange(
        reinterpret_cast<volatile long*>(&_lock), static_cast<long>(expected + 1), static_cast<long>(expected)));
    while (static_cast<std::int32_t>(seen) >= 0 && seen != expected) {
        expected = seen & kLockCountMask;
        // atomic: take a read slot only while no writer holds the lock
        seen = static_cast<std::uint32_t>(_InterlockedCompareExchange(
            reinterpret_cast<volatile long*>(&_lock), static_cast<long>(expected + 1), static_cast<long>(expected)));
    }
    return static_cast<bool>(~(seen >> 31) & 1);
}

bool BSReadWriteLock::TryLockForWrite()
{
    const std::uint32_t threadId = GetCurrentThreadId();
    if (_writerThread == threadId) {
        // atomic: the writer re-enters
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lock));
        return true;
    }

    // atomic: claim the lock word only when it is free
    const bool locked = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lock), static_cast<long>(kLockWrite | 1), 0) == 0;
    if (locked) {
        _writerThread = threadId;
        // fence: publish the owner before the protected data is touched
        _mm_mfence();
    }
    return locked;
}
