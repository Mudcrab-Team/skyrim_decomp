// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xd07fb0 GFxResource::Release
#include "GFxResource_d07fb0.h"

// Decrement the atomic reference count, detach from the resource library, and delete on zero.
void GFxResource::Release()
{
    // Reference count is shared across threads and must decrement atomically.
    if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
        if (lib != nullptr) {
            lib->RemoveResourceOnRelease(this);
            lib = nullptr;
        }
        delete this;
    }
}
