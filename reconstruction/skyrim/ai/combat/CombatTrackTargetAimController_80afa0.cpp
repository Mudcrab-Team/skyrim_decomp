// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body adapted from a sibling body, call arguments and offsets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x80afa0 CombatTrackTargetAimController::LoadGame
// CombatTrackTargetAimController::LoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// CombatTrackTargetAimController::fMaxDistance, CombatTrackTargetAimController::bTrackLastSeen: GUESS(medium); spelled as in the permitted sibling body, which does not declare them in a permitted file
// Adapted bodies: CombatTrackTargetAimController::LoadGame
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:294
#include "CombatTrackTargetAimController_80afa0.h"

// Loads the base controller state, then the two settings this controller adds.
void CombatTrackTargetAimController::LoadGame(BGSLoadGameBuffer* a_buf)
{
    CombatAimController::LoadGame(a_buf);
    a_buf->LoadDataEndian(&fMaxDistance, 4, 4);
    a_buf->LoadDataEndian(&bTrackLastSeen, 1, 1);
}
