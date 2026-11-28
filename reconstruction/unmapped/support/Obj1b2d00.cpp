// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1b2d00::Unlock, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1b2d00 Obj1b2d00::Unlock
#include "Obj1b2d00.h"

#include <intrin.h>

// Releases one level of the reentrant global spinlock owned by the current thread.
void Obj1b2d00::Unlock()
{
    // acquire memory barrier before checking spinlock owner
    _mm_lfence();
    if (g_spinLock1b2d00.ownerThread == GetCurrentThreadId()) {
        if (g_spinLock1b2d00.lockCount == 1) {
            g_spinLock1b2d00.ownerThread = 0;
            // full memory barrier before releasing final spinlock count
            _mm_mfence();
            // atomic final lock count release
            _InterlockedCompareExchange(&g_spinLock1b2d00.lockCount, 0, 1);
        } else {
            // atomic reentrant lock count decrement
            _InterlockedDecrement(&g_spinLock1b2d00.lockCount);
        }
    }
}
