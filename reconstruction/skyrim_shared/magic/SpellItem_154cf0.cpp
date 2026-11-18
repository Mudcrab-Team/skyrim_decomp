// Code origin: GetDelivery, GetFixedCastDuration, IgnoresResistance and GetData2 bodies written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x154d20 SpellItem::GetDelivery
// 0x154cf0 SpellItem::GetData2
// 0x154d30 SpellItem::GetFixedCastDuration
// 0x155360 SpellItem::IgnoresResistance
#include "SpellItem_154cf0.h"
MagicSystem::Delivery SpellItem::GetDelivery() const { return static_cast<MagicSystem::Delivery>(data.delivery); }
float SpellItem::GetFixedCastDuration() const
{
    if (static_cast<int>(GetCastingType()) == 2) {
        return data.castDuration;
    }
    return 0.0f;
}
bool SpellItem::IgnoresResistance() const { return ((GetData1()->flags >> 20) & 1) != 0; }
SpellItemData* SpellItem::GetData2() { return &data; }
