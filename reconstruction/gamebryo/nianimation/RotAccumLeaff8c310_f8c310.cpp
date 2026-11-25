// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8c310 RotAccumLeaff8c310::~RotAccumLeaff8c310
#include "RotAccumLeaff8c310_f8c310.h"
#include <intrin.h>

RotReferencePtr::~RotReferencePtr()
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

RotAccumLeaff8c310::~RotAccumLeaff8c310() = default;
