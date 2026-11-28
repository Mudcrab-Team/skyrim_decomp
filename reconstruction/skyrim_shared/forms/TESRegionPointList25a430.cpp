// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x25a430 TESRegionPointList25a430::Find
// Adapted bodies: none
#include "TESRegionPointList25a430.h"

#include <cmath>

// Find a matching point by identity, exact coordinates, or within tolerance.
RegionPoint25a430* TESRegionPointList25a430::Find(RegionPoint25a430* point, float tolerance)
{
    if (!point || count == 0)
    {
        return nullptr;
    }
    for (RegionPointNode25a430* node = &head; node; node = node->next)
    {
        if (node->item == point)
        {
            return point;
        }
    }
    if (tolerance <= 0.0f)
    {
        for (RegionPointNode25a430* node = &head; node; node = node->next)
        {
            RegionPoint25a430* item = node->item;
            if (item && point->x == item->x && point->y == item->y)
            {
                return item;
            }
        }
    }
    else
    {
        for (RegionPointNode25a430* node = &head; node; node = node->next)
        {
            RegionPoint25a430* item = node->item;
            if (std::fabs(point->x - item->x) <= tolerance && std::fabs(point->y - item->y) <= tolerance)
            {
                return item;
            }
        }
    }
    return nullptr;
}
