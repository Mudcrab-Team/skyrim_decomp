// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf97360 ControllerLeaff97360::~ControllerLeaff97360
#include "ControllerLeaff97360_f97360.h"
#include <intrin.h>

ControllerRefPtr::~ControllerRefPtr()
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

ControllerLeaff97360::~ControllerLeaff97360() = default;
