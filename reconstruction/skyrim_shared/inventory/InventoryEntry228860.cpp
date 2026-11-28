// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228860::GetItemCharge, treated as adapted: shaped like InventoryEntryData::GetEnchantmentCharge (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:105, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x228860 InventoryEntry228860::GetItemCharge
#include "InventoryEntry228860.h"

// Return the stored charge on the first extra list, or fall back to the base maximum charge.
float InventoryEntry228860::GetItemCharge() const
{
    if (extraLists && extraLists->item)
    {
        float charge = extraLists->item->GetCharge();
        if (charge != -1.0f)
        {
            return charge;
        }
    }
    ExtraDataList228860* first = extraLists ? extraLists->item : nullptr;
    return static_cast<float>(GetMaxCharge228860(object, first));
}
