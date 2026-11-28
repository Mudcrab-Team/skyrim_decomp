// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x199640 Obj199640::WaitForWorker
// Adapted bodies: none.
#include "Obj199640.h"

// Signals the manager's worker thread and waits on its semaphore handle when called from another thread.
void Obj199640::WaitForWorker()
{
    Worker199640* worker = gManager199640->worker;
    std::uint32_t tid = worker->threadId;
    if (tid != GetCurrentThreadId()) {
        worker->Signal();
        WaitForSingleObject(worker->semHandle, 0xFFFFFFFFu);
    }
}
