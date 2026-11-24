// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfb71b0 ColliderLeaffb71b0::~ColliderLeaffb71b0
#include "ColliderLeaffb71b0_fb71b0.h"
#include <intrin.h>

ColliderBase::~ColliderBase()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColliderObjectCount);
}

ColliderReferencePtr::~ColliderReferencePtr()
{
    auto* referent = value;
    if (referent) {
        // The reference count is decremented atomically.
    // The reference-object counter is updated atomically.
        if (_InterlockedDecrement(&referent->count) == 0) {
            referent->table->destroy(referent);
        }
    }
}

ColliderLeaffb71b0::~ColliderLeaffb71b0() = default;
