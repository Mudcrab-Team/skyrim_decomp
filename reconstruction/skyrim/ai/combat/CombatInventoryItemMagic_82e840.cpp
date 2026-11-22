// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CombatInventoryItemMagic: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: GetType from the bounded leaf template; GetEquipType reconstructed from the pinned image listing.
// 0x82e840 CombatInventoryItemMagic::GetEquipType
#include "CombatInventoryItemMagic_82e840.h"

std::uint32_t CombatInventoryItemMagic::GetEquipType(BGSEquipSlot* a_slot) const
{
    std::uint32_t type = GetType();
    const BGSEquipSlot* equipSlot = itemSlot.equipSlot;
    if (equipSlot->flags & BGSEquipSlot::kUseAllParents) {
        if (a_slot != equipSlot->parentSlots[0]) {
            type = 0;
        }
    }
    return type;
}
