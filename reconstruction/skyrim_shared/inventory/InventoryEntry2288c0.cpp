// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2288c0 InventoryEntry2288c0::GetItemMaxCharge
// Adapted bodies: none
#include "InventoryEntry2288c0.h"

// Return the item's maximum charge as a float using the first extra list if present.
float InventoryEntry2288c0::GetItemMaxCharge() const
{
    ExtraDataList2288c0* first = extraLists ? extraLists->item : nullptr;
    return static_cast<float>(GetMaxCharge2288c0(object, first));
}
