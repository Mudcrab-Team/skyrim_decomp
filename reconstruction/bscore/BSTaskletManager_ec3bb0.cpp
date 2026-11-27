// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::SignalInstanceAvailable: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xec3bb0 BSTaskletManager::SignalInstanceAvailable
#include "BSTaskletManager_ec3bb0.h"

#include <intrin.h>

// Release the instance semaphore, increment the count on success, and notify listeners.
void BSTaskletManager::SignalInstanceAvailable()
{
    if (ReleaseSemaphore(instanceSemaphore, 1, nullptr)) {
        // atomic increment of available tasklet instance counter
        _InterlockedIncrement(&instanceCount);
    }
    started = true;
    Unk_09();
}
