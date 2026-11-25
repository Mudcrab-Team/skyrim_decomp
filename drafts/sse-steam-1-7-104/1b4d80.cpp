// Near miss: 22.5% | control-flow
// Source exposure: mixed
// Code origin: adapted declarations and locking body from the labelled community source.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSpinLock, BSSpinLock::Lock, BSSpinLock::_owningThread, BSSpinLock::_lockCount, BSSpinLock::kFastSpinThreshold: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: BSSpinLock::Lock from CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT.
// 0x1b4d80 BSSpinLock::Lock

#include "include/1b4d80/BSSpinLock_1b4d80.h"

#include <Windows.h>
#include <intrin.h>

// Acquire the recursive lock, yielding after the configured pause interval.
void BSSpinLock::Lock(std::uint32_t pauseAttempts)
{
    std::uint32_t thread = GetCurrentThreadId();
    // Observe shared ownership before checking for recursive acquisition.
    _mm_lfence();
    if (_owningThread == thread)
    {
        // Recursive acquisition updates the shared count atomically.
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&_lockCount));
    }
    else
    {
        std::uint32_t attempts = 0;
        // Acquire the lock only while its count is zero.
        if (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lockCount), 1, 0))
        {
            do
            {
                ++attempts;
                // Reduce contention while polling the shared lock.
                _mm_pause();
                if (attempts >= pauseAttempts)
                {
                    std::uint32_t spinCount = 0;
                    // Competing threads may acquire between yields.
                    while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lockCount), 1, 0))
                    {
                        Sleep(++spinCount < kFastSpinThreshold ? 0 : 1);
                    }
                    break;
                }
                // Retry acquisition after each processor pause.
            } while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lockCount), 1, 0));
            // Acquire the protected state after winning the lock.
            _mm_lfence();
        }
        _owningThread = thread;
        // Publish the owner after establishing the acquired lock.
        _mm_sfence();
    }
}
