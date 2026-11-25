// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8842c0 CombatBehaviorFallback8842c0::LoadGame
// Adapted bodies: CombatBehaviorFallback8842c0::LoadGame from the sibling source named in the header
#include "CombatBehaviorFallback8842c0_8842c0.h"

void CombatBehaviorFallback8842c0::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    CheckPathTimer.LoadGame(a_buffer);
    WaitTimer.LoadGame(a_buffer);
    spPath = CombatObject::Load(a_buffer);
}
