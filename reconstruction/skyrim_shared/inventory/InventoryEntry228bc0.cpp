// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228bc0::GetSoulValue, treated as adapted: shaped like InventoryEntryData::GetSoulLevel (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:154, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228bc0 InventoryEntry228bc0::GetSoulValue
#include "InventoryEntry228bc0.h"

// Return the soul value derived from extra data or the base soul gem form.
std::int32_t InventoryEntry228bc0::GetSoulValue() const
{
    std::int32_t value = -1;
    if (extraLists)
    {
        ExtraDataList228bc0* list = extraLists->item;
        if (list && list->GetSoulLevel())
        {
            value = GetSoulValue228bc0(list->GetSoulLevel());
            if (value != -1)
            {
                return value;
            }
        }
    }
    if (object && object->formType == 0x34)
    {
        std::uint8_t soul = static_cast<const SoulGem228bc0*>(object)->soulLevel;
        if (soul != 0)
        {
            return GetSoulValue228bc0(soul);
        }
    }
    return value;
}
