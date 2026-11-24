// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x882a10 CombatBehaviorFlee882a10::LoadGame
// Adapted bodies: CombatBehaviorFlee882a10::LoadGame from the sibling source named in the header
#include "CombatBehaviorFlee882a10_882a10.h"

void CombatBehaviorFlee882a10::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    spPath = CombatObject::Load(a_buffer);
    spAimController = CombatObject::Load(a_buffer);
}
