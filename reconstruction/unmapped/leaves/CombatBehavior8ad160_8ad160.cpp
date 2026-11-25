// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8ad160 CombatBehavior8ad160::LoadGame
// Adapted bodies: CombatBehavior8ad160::LoadGame from the sibling source named in the header
#include "CombatBehavior8ad160_8ad160.h"

void CombatBehavior8ad160::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    Assign(CombatObject::Load(a_buffer));
}
