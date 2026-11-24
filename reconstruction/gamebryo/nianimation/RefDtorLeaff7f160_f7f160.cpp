// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf7f160 RefDtorLeaff7f160::~RefDtorLeaff7f160
#include "RefDtorLeaff7f160_f7f160.h"
#include <intrin.h>

TimelinePtrf7f160::~TimelinePtrf7f160()
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
RefDtorLeaff7f160::RefDtorLeaff7f160() = default;
RefDtorLeaff7f160::~RefDtorLeaff7f160() = default;
