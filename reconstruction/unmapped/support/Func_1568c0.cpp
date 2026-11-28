// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1568c0 Func_1568c0::SyncCache
// Adapted bodies: none
#include "Func_1568c0.h"

#include <cstring>

// Clears the thread-local cache and updates its generation when it lags the global counter.
void Func_1568c0::SyncCache()
{
    if (gTlsGen1568c0_tls_0x10 != gGeneration1568c0)
    {
        gTlsOwner1568c0_tls_0x18 = nullptr;
        std::memset(gTlsCache1568c0_tls_0x20, 0, sizeof(gTlsCache1568c0_tls_0x20));
        gTlsGen1568c0_tls_0x10 = gGeneration1568c0;
    }
}
