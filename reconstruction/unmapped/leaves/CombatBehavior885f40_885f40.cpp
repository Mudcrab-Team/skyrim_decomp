// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x885f40 CombatBehavior885f40::LoadGame
// Adapted bodies: CombatBehavior885f40::LoadGame from the sibling source named in the header
#include "CombatBehavior885f40_885f40.h"

void CombatBehavior885f40::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    Assign(CombatObject::Load(a_buffer));
}
