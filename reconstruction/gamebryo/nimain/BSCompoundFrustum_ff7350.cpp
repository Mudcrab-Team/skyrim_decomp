// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum, AllocateFromPool, ReleaseToPool: CRASHLOGGER_PDB(59818@2026.10.24)
// PoolGuard, poolLock, poolEnabled, freeSlots and frustumPool: GUESS(low)
// 0xff7350 BSCompoundFrustum::AllocateFromPool
// CI hash: 0xff7350 ?AllocateFromPool@BSCompoundFrustum@@SAPEAU1@XZ
#include "BSCompoundFrustum_ff7350.h"

BSCompoundFrustum* BSCompoundFrustum::AllocateFromPool()
{
    PoolGuard guard(&poolLock);
    if (poolEnabled && freeSlots) {
        unsigned long slot;
        // Reuse the highest available slot first.
        _BitScanReverse(&slot, freeSlots);
        freeSlots &= ~(1u << slot);
        return &frustumPool[slot];
    }
    return new BSCompoundFrustum;
}
