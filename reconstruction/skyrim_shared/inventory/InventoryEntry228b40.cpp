// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228b40::GetSoulLevel, treated as adapted: shaped like InventoryEntryData::GetSoulLevel (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:154, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228b40 InventoryEntry228b40::GetSoulLevel
#include "InventoryEntry228b40.h"

// Return the item's soul level from its extra data or base soul gem form.
std::uint32_t InventoryEntry228b40::GetSoulLevel() const
{
    std::uint32_t level = 0;
    if (extraLists)
    {
        ExtraDataList228b40* list = extraLists->item;
        if (list && list->GetSoulLevel())
        {
            return list->GetSoulLevel();
        }
    }
    if (object && object->formType == 0x34)
    {
        level = static_cast<const SoulGem228b40*>(object)->soulLevel;
    }
    return level;
}
