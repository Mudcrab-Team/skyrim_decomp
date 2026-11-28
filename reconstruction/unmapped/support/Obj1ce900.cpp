// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1ce900 Obj1ce900::SetTarget
// Adapted bodies: none.
#include "Obj1ce900.h"

// Stores a_target and caches its identifier and virtual value when non-null.
void Obj1ce900::SetTarget(Target1ce900* a_target)
{
    target38 = a_target;
    if (a_target) {
        std::int32_t val = a_target->val58;
        if (val == -1) {
            val = a_target->val170;
        }
        field2A8 = val;
        field2A4 = a_target->GetVal();
    }
}
