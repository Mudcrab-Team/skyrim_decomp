// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1dba60 Unit1dba60::GetName1dba60
// Adapted bodies: none
#include "Unit1dba60.h"

// Casts the object dynamically and queries its inner target's display string, falling back to empty.
const char* Unit1dba60::GetName1dba60(BaseObject1dba60* a_object)
{
    DerivedObject1dba60* derived = dynamic_cast<DerivedObject1dba60*>(a_object);
    if (derived && derived->inner) {
        return derived->inner->GetDisplayString();
    }
    return "";
}
