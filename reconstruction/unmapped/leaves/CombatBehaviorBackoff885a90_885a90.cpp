// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x885a90 CombatBehaviorBackoff885a90::LoadGame
// Adapted bodies: CombatBehaviorBackoff885a90::LoadGame from the sibling source named in the header
#include "CombatBehaviorBackoff885a90_885a90.h"

void CombatBehaviorBackoff885a90::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    CheckPathTimer.LoadGame(a_buffer);
    spPath = CombatObject::Load(a_buffer);
}
