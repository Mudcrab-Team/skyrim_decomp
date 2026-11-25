// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x4a0b50 (skyrim/ai/TESEscortPackageData): source copied, names replaced by placeholders.
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:52
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataEscort.cpp:76
// Location::SaveGame, BGSSaveFormBuffer, BGSSaveFormBuffer::SaveData: GUESS(low); inferred from target accesses and sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a0ed0 Owner4a0ed0::Function4a0ed0
#include "Owner4a0ed0.h"

// guess: same compiled code as matched 0x4a0b50 apart from relocated fields; its role here is not established.
void Owner4a0ed0::Function4a0ed0(BGSSaveFormBuffer* b) { b->SaveData(&followRadius, 4, 4, false); bool hasLocation = searchLocation != nullptr; b->SaveData(&hasLocation, 1, 1, false); if (hasLocation) searchLocation->SaveGame(b); }
