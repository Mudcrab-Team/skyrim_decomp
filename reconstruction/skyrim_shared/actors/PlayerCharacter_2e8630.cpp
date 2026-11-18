// Inferred names: GUESS(low)
// Origin: declaration adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e8630 PlayerCharacter::GetItemCount
#include "PlayerCharacter_2e8630.h"
std::int32_t PlayerCharacter::GetItemCount(TESBoundObject* object) { Inventory* data = GetInventory(); return data ? data->CountItem(object) : 0; }
