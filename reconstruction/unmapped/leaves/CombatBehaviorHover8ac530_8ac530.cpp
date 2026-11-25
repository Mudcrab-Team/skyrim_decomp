// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8ac530 CombatBehaviorHover8ac530::SaveGame
// Adapted bodies: CombatBehaviorHover8ac530::SaveGame from the sibling source named in the header
#include "CombatBehaviorHover8ac530_8ac530.h"

void CombatBehaviorHover8ac530::SaveGame(BGSSaveFormBuffer* a_buffer) const
{
    CombatObject::Save(a_buffer, spPath);
    CombatObject::Save(a_buffer, spAimController);
    HoverTimer.SaveGame(a_buffer);
    StrafeTimer.SaveGame(a_buffer);
}
