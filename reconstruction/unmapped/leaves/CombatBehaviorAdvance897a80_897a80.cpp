// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x897a80 CombatBehaviorAdvance897a80::LoadGame
// Adapted bodies: CombatBehaviorAdvance897a80::LoadGame from the sibling source named in the header
#include "CombatBehaviorAdvance897a80_897a80.h"

void CombatBehaviorAdvance897a80::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    spPath = CombatObject::Load(a_buffer);
    spAimController = CombatObject::Load(a_buffer);
    spTargetLocationSearch = CombatObject::Load(a_buffer);
    spTargetLocationSearchResult = CombatObject::Load(a_buffer);
}
