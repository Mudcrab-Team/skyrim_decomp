// Source exposure: mixed (community declarations and pinned image analysis).
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x239820 InventoryChanges::GetEquippedArmorInSlot
// Adapted bodies: none
#include "InventoryChanges_239820.h"

TESObjectARMO* InventoryChanges::GetEquippedArmorInSlot(std::int32_t slot)
{
    if (slot >= 30) {
        GetArmorInSlotFunctor visitor(slot);
        VisitWornItems(visitor);
        return visitor.armor;
    }
    return nullptr;
}
