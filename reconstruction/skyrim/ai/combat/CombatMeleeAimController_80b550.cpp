// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x80b550 CombatMeleeAimController::SaveGame
// Adapted bodies: none; the sibling lead for this function matched by instruction shape only and holds no comparable body
#include "CombatMeleeAimController_80b550.h"

// Writes the base state, then the minimum distance, a flag byte and one more four-byte value.
void CombatMeleeAimController::SaveGame(BGSSaveGameBuffer* a_buf)
{
    CombatAimController::SaveGame(a_buf);
    a_buf->SaveDataEndian(&fMinDistance, 4, 4, 0);
    a_buf->SaveDataEndian(&unk4C, 1, 1, 0);
    a_buf->SaveDataEndian(&unk50, 4, 4, 0);
}
