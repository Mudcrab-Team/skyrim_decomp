// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1df140 Unit1df140::QueryValue1df140
// Adapted bodies: none
#include "Unit1df140.h"

// Dynamically casts the object and returns its slot 4 word value, or 0 if not matching.
std::uint16_t Unit1df140::QueryValue1df140(BaseObject1df140* a_object)
{
    DerivedObject1df140* derived = dynamic_cast<DerivedObject1df140*>(a_object);
    if (derived) {
        return derived->GetWordValue();
    }
    return 0;
}
