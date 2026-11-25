// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x80b5d0 CombatMeleeAimController::LoadGame
// Adapted bodies: none; the sibling lead for this function matched by instruction shape only and holds no comparable body
#include "CombatMeleeAimController_80b5d0.h"

// Reads the base state, then the minimum distance, a flag byte and one more four-byte value.
void CombatMeleeAimController::LoadGame(BGSLoadGameBuffer* a_buf)
{
    CombatAimController::LoadGame(a_buf);
    a_buf->LoadDataEndian(&fMinDistance, 4, 4);
    a_buf->LoadDataEndian(&unk4C, 1, 1);
    a_buf->LoadDataEndian(&unk50, 4, 4);
}
