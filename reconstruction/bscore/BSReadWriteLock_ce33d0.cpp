// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xce33d0 BSReadWriteLock::LockForWrite
// Adapted bodies: none
#include "BSReadWriteLock_ce33d0.h"

#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long a_milliseconds);

void BSReadWriteLock::LockForWrite()
{
    std::uint32_t myThreadID = GetCurrentThreadId();
    if (_writerThread != myThreadID) {
        unsigned int spinCount = 0;
        // atomic acquire: spin until the lock word holds the single-reader value
        while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lock), static_cast<long>(0x80000001), 1) != 1) {
            if (spinCount < 10000) {
                ++spinCount;
                Sleep(0);
            } else {
                Sleep(1);
            }
        }

        _writerThread = myThreadID;
        _mm_mfence();  // ordering: publish the owner after taking the lock
    }
}
