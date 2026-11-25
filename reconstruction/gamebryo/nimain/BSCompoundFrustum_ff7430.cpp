// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum and ReleaseToPool: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xff7430 BSCompoundFrustum::ReleaseToPool
// CI hash: 0xff7430 ?ReleaseToPool@BSCompoundFrustum@@SAXPEAU1@@Z
#include "BSCompoundFrustum_ff7430.h"

void BSCompoundFrustum::ReleaseToPool(BSCompoundFrustum* frustum)
{
    PoolGuard guard(poolLock);
    auto offset = reinterpret_cast<std::uintptr_t>(frustum) -
                  reinterpret_cast<std::uintptr_t>(frustumPool);
    if (offset < sizeof(frustumPool)) {
        freeSlots |= 1u << (offset / sizeof(BSCompoundFrustum));
    } else {
        delete frustum;
    }
}
