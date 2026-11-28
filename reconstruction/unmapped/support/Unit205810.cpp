// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit205810::Unlock205810, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x205810 Unit205810::Unlock205810
#include "Unit205810.h"

#include <intrin.h>

extern "C" __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();

// Releases one recursion level of the global reentrant spin lock when held by the current thread.
void Unit205810::Unlock205810()
{
    // Load fence before checking the spin-lock owner thread.
    _mm_lfence();
    if (g_spinLock205810.ownerThread == GetCurrentThreadId()) {
        if (g_spinLock205810.lockCount == 1) {
            g_spinLock205810.ownerThread = 0;
            // Memory fence before releasing the spin lock count.
            _mm_mfence();
            // Atomic compare-exchange to release the final lock count.
            _InterlockedCompareExchange(&g_spinLock205810.lockCount, 0, 1);
        } else {
            // Atomic decrement for a nested spin-lock release.
            _InterlockedDecrement(&g_spinLock205810.lockCount);
        }
    }
}
