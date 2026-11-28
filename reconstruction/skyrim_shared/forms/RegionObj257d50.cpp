// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257d50 RegionObj257d50::SetMaximumSlope
// Adapted bodies: none
#include "RegionObj257d50.h"

// Update the maximum slope angle within valid bounds and refresh child objects.
bool RegionObj257d50::SetMaximumSlope(std::uint8_t value)
{
    if (parent && parent->maxSlope < value)
    {
        value = parent->maxSlope;
    }
    if (value > 90 || value < minSlope || value == maxSlope)
    {
        return false;
    }
    maxSlope = value;
    RegionObjNode257d50* node = childrenList ? &childrenList->head : nullptr;
    ClampToParent();
    for (; node && node->item; node = node->next)
    {
        node->item->UpdateChildren();
    }
    return true;
}
