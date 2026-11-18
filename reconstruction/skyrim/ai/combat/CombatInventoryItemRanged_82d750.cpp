// Origin: declaration adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82d750 CombatInventoryItemRanged::sub
#include "CombatInventoryItemRanged_82d750.h"
std::uint32_t CombatInventoryItemRanged::GetEquipType(BGSEquipSlot* a_slot)
{
    return a_slot == GetRangedEquipSlot() ? 0 : 2;
}
