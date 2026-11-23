// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xce3360 BSReadWriteLock::LockForRead
// Adapted bodies: none
#include "BSReadWriteLock_ce3360.h"

#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long a_milliseconds);

void BSReadWriteLock::LockForRead()
{
    std::uint32_t myThreadID = GetCurrentThreadId();
    if (_writerThread == myThreadID) {
        // atomic increment: readers on the writer thread nest
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lock));
    } else {
        unsigned int spinCount = 0;
        // atomic acquire: spin until the lock word is free
        long observed = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lock), 1, 0);
        while (observed != 0) {
            if (spinCount < 10000) {
                ++spinCount;
                Sleep(0);
            } else {
                Sleep(1);
            }
            // atomic acquire: retry after yielding
            observed = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lock), 1, 0);
        }
    }
}
