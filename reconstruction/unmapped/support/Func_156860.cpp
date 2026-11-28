// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x156860 Func_156860::InvalidateCache
// Adapted bodies: none
#include "Func_156860.h"

#include <cstring>

// Advances the global and thread-local generation counters and clears the thread cache if owned by owner.
void Func_156860::InvalidateCache(const void* owner)
{
    ++gGeneration156860;
    ++gTlsGen156860_tls_0x10;
    if (owner == gTlsOwner156860_tls_0x18)
    {
        std::memset(gTlsCache156860_tls_0x20, 0, sizeof(gTlsCache156860_tls_0x20));
        gTlsOwner156860_tls_0x18 = nullptr;
    }
}
