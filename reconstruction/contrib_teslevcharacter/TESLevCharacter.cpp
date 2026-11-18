// Code origin: UnClone3D and SaveGame bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x271800 TESLevCharacter::UnClone3D
// 0x271840 TESLevCharacter::SaveGame
#include "TESLevCharacter.h"
unsigned int TESLevCharacter::UnClone3D(TESObjectREFR*) { return 0; }
void TESLevCharacter::SaveGame(BGSSaveFormBuffer* buffer) { TESForm::SaveGame(buffer); TESLeveledList::SaveGame(buffer); }
