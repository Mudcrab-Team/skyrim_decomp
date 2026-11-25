// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf9b820 EmitterControllerLeaff9b820::SetInterpolator
#include "EmitterControllerLeaff9b820_f9b820.h"
#include <intrin.h>

static void Assign(EmitterRefTargetf9b820*& field, EmitterRefTargetf9b820* replacement)
{
    auto* old = field;
    if (old == replacement) {
        return;
    }
    if (replacement) {
        // Increment the new reference count atomically.
        _InterlockedIncrement(&replacement->count);
    }
    field = replacement;
    if (old) {
        // Decrement the previous reference count atomically.
    // The reference-object counter is updated atomically.
        if (_InterlockedDecrement(&old->count) == 0) {
            old->table->destroy(old);
        }
    }
}

void EmitterControllerLeaff9b820::SetInterpolator(EmitterRefTargetf9b820* value, std::uint16_t index)
{
    if (index == 0) {
        Assign(first, value);
    } else if (index == 1) {
        Assign(second, value);
    }
}
