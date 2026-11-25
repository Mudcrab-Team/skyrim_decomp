// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x721a30 ActorProcess::UnlockOwnedData
// Adapted bodies: none
#include "ActorProcess_721a30.h"

void ActorProcess::UnlockOwnedData()
{
    if (data) {
        data->lock.Unlock();
    }
}
