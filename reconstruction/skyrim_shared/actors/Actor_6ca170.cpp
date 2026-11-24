// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6ca170 Actor::GetEquippedWeaponEnchantment
// Adapted bodies: none
#include "Actor_6ca170.h"

EnchantmentItem* Actor::GetEquippedWeaponEnchantment(bool a_leftHand)
{
    EnchantmentItem* result = nullptr;
    InventoryEntryData* entry = GetEquippedWeaponEntry(a_leftHand);
    if (entry) {
        result = entry->object->GetEnchantment(entry->GetFirstExtraList());
    }
    return result;
}
