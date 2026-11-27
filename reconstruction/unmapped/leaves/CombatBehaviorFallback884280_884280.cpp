// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x884280 CombatBehaviorFallback884280::SaveGame
// Adapted bodies: CombatBehaviorFallback884280::SaveGame from the sibling source named in the header
#include "CombatBehaviorFallback884280_884280.h"

void CombatBehaviorFallback884280::SaveGame(BGSSaveFormBuffer* a_buffer) const
{
    CheckPathTimer.SaveGame(a_buffer);
    WaitTimer.SaveGame(a_buffer);
    CombatObject::Save(a_buffer, spPath);
}
