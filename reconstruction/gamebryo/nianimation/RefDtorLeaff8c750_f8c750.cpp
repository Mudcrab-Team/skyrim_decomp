// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8c750 RefDtorLeaff8c750::~RefDtorLeaff8c750
#include "RefDtorLeaff8c750_f8c750.h"
#include <intrin.h>

TimelinePtrf8c750::~TimelinePtrf8c750()
{
    auto* referent = value;
    if (referent) {
        // Decrement the previous reference count atomically.
    // The reference-object counter is updated atomically.
        if (_InterlockedDecrement(&referent->count) == 0) {
            referent->table->destroy(referent);
        }
    }
}
RefDtorLeaff8c750::RefDtorLeaff8c750() = default;
RefDtorLeaff8c750::~RefDtorLeaff8c750() = default;
