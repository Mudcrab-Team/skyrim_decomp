// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfa0ab0 RotAccumLeaffa0ab0::~RotAccumLeaffa0ab0
#include "RotAccumLeaffa0ab0_fa0ab0.h"
#include <intrin.h>

ModifierRefPtr::~ModifierRefPtr()
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

RotAccumLeaffa0ab0::~RotAccumLeaffa0ab0() = default;
