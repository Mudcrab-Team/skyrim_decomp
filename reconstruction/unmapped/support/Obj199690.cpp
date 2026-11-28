// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x199690 Obj199690::ReleaseWorker
// Adapted bodies: none.
#include "Obj199690.h"

// Signals the manager's worker thread and releases its semaphore when called from another thread.
void Obj199690::ReleaseWorker()
{
    Worker199690* worker = gManager199690->worker;
    std::uint32_t tid = worker->threadId;
    if (tid != GetCurrentThreadId()) {
        worker->Signal();
        ReleaseSemaphore(worker->semHandle, 1, 0);
    }
}
