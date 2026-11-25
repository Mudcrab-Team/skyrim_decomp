// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8aa4e0 CombatBehaviorFindLateral8aa4e0::LoadGame
// Adapted bodies: CombatBehaviorFindLateral8aa4e0::LoadGame from the sibling source named in the header
#include "CombatBehaviorFindLateral8aa4e0_8aa4e0.h"

void CombatBehaviorFindLateral8aa4e0::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    spPath = CombatObject::Load(a_buffer);
    spAimController = CombatObject::Load(a_buffer);
    CheckLOSTimer.LoadGame(a_buffer);
}
