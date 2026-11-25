// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8aa490 CombatBehaviorFindLateral8aa490::SaveGame
// Adapted bodies: CombatBehaviorFindLateral8aa490::SaveGame from the sibling source named in the header
#include "CombatBehaviorFindLateral8aa490_8aa490.h"

void CombatBehaviorFindLateral8aa490::SaveGame(BGSSaveFormBuffer* a_buffer) const
{
    CombatObject::Save(a_buffer, spPath);
    CombatObject::Save(a_buffer, spAimController);
    CheckLOSTimer.SaveGame(a_buffer);
}
