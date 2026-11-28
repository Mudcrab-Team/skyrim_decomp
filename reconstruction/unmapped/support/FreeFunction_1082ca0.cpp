// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function1082ca0, treated as adapted: shaped like BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp:54, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1082ca0 Function1082ca0
#include "FreeFunction_1082ca0.h"

// Releases one level of the global re-entrant spinlock when owned by the current thread, then notifies.
void Function1082ca0()
{
    // Load fence ensures ownerThread is read after prior critical-section reads before unlock.
    _mm_lfence();
    if (g_spinLock_1082ca0.ownerThread == GetCurrentThreadId()) {
        if (g_spinLock_1082ca0.lockCount == 1) {
            g_spinLock_1082ca0.ownerThread = 0;
            // Full fence orders clearing ownerThread before releasing the lock count to other threads.
            _mm_mfence();
            // Atomically release the final lock count from 1 to 0.
            _InterlockedCompareExchange(&g_spinLock_1082ca0.lockCount, 0, 1);
        } else {
            // Atomically decrement a nested lock count while the current thread retains ownership.
            _InterlockedDecrement(&g_spinLock_1082ca0.lockCount);
        }
    }
    NotifyUnlock_1082ca0();
}
