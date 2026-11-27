// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8970d0 CombatBehavior8970d0::LoadGame
// Adapted bodies: CombatBehavior8970d0::LoadGame from the sibling source named in the header
#include "CombatBehavior8970d0_8970d0.h"

void CombatBehavior8970d0::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    Assign(CombatObject::Load(a_buffer));
}
