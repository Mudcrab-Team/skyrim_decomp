// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xd33990 HierarchyNoded33990::GetCachedValue
// Adapted bodies: none
#include "HierarchyNoded33990.h"

// Returns a cached 16-bit value, resolving and caching it recursively from the parent node if zero.
std::uint16_t HierarchyNoded33990::GetCachedValue()
{
    if (cachedValue != 0) {
        return cachedValue;
    }
    std::uint16_t result = 0;
    if (parent) {
        result = parent->GetCachedValue();
        cachedValue = result;
    }
    return result;
}
