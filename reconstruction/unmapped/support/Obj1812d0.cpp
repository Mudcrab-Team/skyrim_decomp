// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1812d0 Obj1812d0::IsNotEqual
// Adapted bodies: none.
#include "Obj1812d0.h"

#include <cstring>

// Compares the location pointer and 24-byte starting transform for inequality.
bool Obj1812d0::IsNotEqual(const Obj1812d0* a_rhs) const
{
    if (a_rhs->location28 != location28) {
        return true;
    }
    if (std::memcmp(&transform10, &a_rhs->transform10, sizeof(transform10)) != 0) {
        return true;
    }
    return false;
}
