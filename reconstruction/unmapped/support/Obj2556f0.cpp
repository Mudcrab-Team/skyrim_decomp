// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2556f0 Obj2556f0::HasRegionData
// Adapted bodies: none
#include "Obj2556f0.h"

// Return whether any region in the list contains data of the requested type.
bool Obj2556f0::HasRegionData(ListOwner2556f0* owner, std::uint32_t type, bool requireValid)
{
    for (Node2556f0* node = owner ? &owner->head : nullptr; node && node->item; node = node->next)
    {
        RegionData2556f0* data = node->item->dataList->FindByType(type);
        if (data && (!requireValid || data->IsValid()))
        {
            return true;
        }
    }
    return false;
}
