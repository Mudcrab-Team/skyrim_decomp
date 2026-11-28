// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1ef8c0 Unit1ef8c0::GetName1ef8c0
// Adapted bodies: none
#include "Unit1ef8c0.h"

// Dynamically casts the object and returns its inner target's display string, or empty.
const char* Unit1ef8c0::GetName1ef8c0(BaseObject1ef8c0* a_object)
{
    DerivedObject1ef8c0* derived = dynamic_cast<DerivedObject1ef8c0*>(a_object);
    if (derived && derived->inner) {
        return derived->inner->GetDisplayString();
    }
    return "";
}
