// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfbf9c0 RefDtorLeaffbf9c0::~RefDtorLeaffbf9c0
#include "RefDtorLeaffbf9c0_fbf9c0.h"
#include <intrin.h>

TimelinePtrfbf9c0::~TimelinePtrfbf9c0()
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
RefDtorLeaffbf9c0::RefDtorLeaffbf9c0() = default;
RefDtorLeaffbf9c0::~RefDtorLeaffbf9c0() = default;
