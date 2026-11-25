// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8bb690 CombatBehaviorFaceAngle8bb690::LoadGame
// Adapted bodies: CombatBehaviorFaceAngle8bb690::LoadGame from the sibling source named in the header
#include "CombatBehaviorFaceAngle8bb690_8bb690.h"

void CombatBehaviorFaceAngle8bb690::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    a_buffer->LoadDataEndian(&fAngle, sizeof(fAngle), sizeof(fAngle));
    spAimController = CombatObject::Load(a_buffer);
}
