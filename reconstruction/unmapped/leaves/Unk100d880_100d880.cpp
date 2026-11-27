// CI hash: 0x100d880 ?Function100d880@Unk100d880@@QEAAXPEAUSharedCounter100d880@@@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk100d880: STANDIN GUESS(low)
// Unk100d880::Function100d880: GUESS(low)
// SharedCounter100d880: GUESS(low)
// 0x100d880 Unk100d880::Function100d880
#include "Unk100d880_100d880.h"

// Increment the shared reference count atomically.
void Unk100d880::Function100d880(SharedCounter100d880* value)
{
    // Coordinate the shared counter with concurrent reference owners.
    _InterlockedIncrement(&value->count);
}
