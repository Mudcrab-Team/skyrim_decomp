// Code origin: GetName and GetEquipState bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x951d00 MagicItemData::GetName
// 0x951d10 MagicItemData::GetEquipState
#include "MagicItemData_951d00.h"
const char* MagicItemData::GetName() { return GetFormNameOf(data18); }
std::uint32_t MagicItemData::GetEquipState() { return GetPlayerEquipState(PlayerCharacter::singleton, data18, 0, 0); }

// ReadEnabledFlag: GUESS(low)
bool ReadEnabledFlag(void* a_data);
