// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257ca0 RegionObj257ca0::SetMinimumSlope
// Adapted bodies: none
#include "RegionObj257ca0.h"

// Update the minimum slope angle within valid bounds and refresh child objects.
bool RegionObj257ca0::SetMinimumSlope(std::uint8_t value)
{
    if (parent && parent->minSlope > value)
    {
        value = parent->minSlope;
    }
    if (value > 90 || value > maxSlope || value == minSlope)
    {
        return false;
    }
    minSlope = value;
    RegionObjNode257ca0* node = childrenList ? &childrenList->head : nullptr;
    ClampToParent();
    for (; node && node->item; node = node->next)
    {
        node->item->UpdateChildren();
    }
    return true;
}
