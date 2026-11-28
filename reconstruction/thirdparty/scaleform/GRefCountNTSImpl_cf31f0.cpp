// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0xcf31f0 GRefCountNTSImpl::GetWeakProxy
#include "GRefCountNTSImpl_cf31f0.h"

// Return the object's weak proxy, allocating it on first access and incrementing its reference count.
GWeakPtrProxy* GRefCountNTSImpl::GetWeakProxy()
{
    if (weakProxy == nullptr) {
        weakProxy = new (this) GWeakPtrProxy(this);
        if (weakProxy == nullptr) {
            return nullptr;
        }
    }
    weakProxy->refCount++;
    return weakProxy;
}
