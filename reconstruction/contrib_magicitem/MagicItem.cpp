// Code origin: Bodies for GetChargeTime, IsPoison, IsAutoCalc and HasEffect written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x146680 MagicItem::GetChargeTime
// 0x14e7d0 MagicItem::IsPoison
// 0x146870 MagicItem::IsAutoCalc
// 0x1514d0 MagicItem::HasEffect
#include "MagicItem.h"
float MagicItem::GetChargeTime() const { return 0.0f; }
bool MagicItem::IsPoison() const { return GetType() == 5; }
bool MagicItem::IsAutoCalc() const { return (~GetData()->flags & 1) != 0; }
bool MagicItem::HasEffect(std::int32_t a_value) const
{
    for (std::uint32_t i = 0; i < effects.size; ++i) {
        Effect* effect = effects.data[i];
        if (effect && effect->baseEffect->archetype == a_value) {
            return true;
        }
    }
    return false;
}
