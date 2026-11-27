// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xccb060 BSAudioManager::SignalWorker
// Adapted bodies: none
#include "BSAudioManager_ccb060.h"

void BSAudioManager::SignalWorker()
{
    WorkerState* state = worker;
    if (state && state->count != 0 && state->active != 0) {
        ReleaseSemaphore(state->handle, 1, nullptr);
    }
}
