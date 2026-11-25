// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x88e550 CombatBehavior88e550::LoadGame
// Adapted bodies: CombatBehavior88e550::LoadGame from the sibling source named in the header
#include "CombatBehavior88e550_88e550.h"

void CombatBehavior88e550::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    Assign(CombatObject::Load(a_buffer));
}
