// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xe14600 Functione14600
// Adapted bodies: none
#include "FreeFunction_e14600.h"

// Waits indefinitely on wrapper->mutex->handle and increments lockCount when acquired.
unsigned long Functione14600(LockWrapper_e14600* wrapper)
{
    MutexImpl_e14600* mutex = wrapper->mutex;
    unsigned long result = WaitForSingleObject(mutex->handle, 0xFFFFFFFFu);
    if (result == 0) {
        return ++mutex->lockCount;
    }
    return result;
}
