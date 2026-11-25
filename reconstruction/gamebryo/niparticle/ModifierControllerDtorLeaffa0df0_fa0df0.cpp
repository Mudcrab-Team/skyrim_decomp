// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfa0df0 ModifierControllerDtorLeaffa0df0::~ModifierControllerDtorLeaffa0df0
#include "ModifierControllerDtorLeaffa0df0_fa0df0.h"
#include <intrin.h>

ModifierRefPtrfa0df0::~ModifierRefPtrfa0df0()
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
ModifierControllerDtorLeaffa0df0::ModifierControllerDtorLeaffa0df0() = default;
ModifierControllerDtorLeaffa0df0::~ModifierControllerDtorLeaffa0df0() = default;
