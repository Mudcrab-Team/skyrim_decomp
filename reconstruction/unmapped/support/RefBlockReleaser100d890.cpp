// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x100d890 RefBlockReleaser100d890::Release
// Adapted bodies: none
#include <intrin.h>
#include "RefBlockReleaser100d890.h"

// guess: a stateless deleter object; the call does not read this.
void RefBlockReleaser100d890::Release(RefBlock100d890* a_block)
{
    // Atomic reference count decrement on shared control block.
    if (_InterlockedExchangeAdd(&a_block->refCount, -1) == 1) {
        a_block->target->Release();
        delete a_block;
    }
}
