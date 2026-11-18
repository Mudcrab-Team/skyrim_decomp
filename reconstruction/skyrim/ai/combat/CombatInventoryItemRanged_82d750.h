// Origin: declaration adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemRanged: EXE_RTTI
// GetEquipType: GUESS(low)
// BGSEquipSlot, GetRangedEquipSlot: GUESS(low)
#pragma once
#include <cstdint>
class BGSEquipSlot;
BGSEquipSlot* GetRangedEquipSlot();
class CombatInventoryItemRanged {
public:
    std::uint32_t GetEquipType(BGSEquipSlot* a_slot);
};
