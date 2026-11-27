// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xee43b0 NiStream::Functionee43b0
// Adapted bodies: none
#include "NiStream_ee43b0.h"

int NiStream::Functionee43b0()
{
    if (binaryStream == nullptr) {
        loadFlag = ReadHeader(header);
    } else {
        loadFlag = Load2();
    }
    Notify();
    _InterlockedIncrement(&g_pendingCount);  // counter is shared with the worker thread
    ReleaseSemaphore(g_semaphore, 1, nullptr);
    return g_pendingCount;
}
