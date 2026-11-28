// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x562d30 CombatController::CheckCombatArea
#include "CombatController_562d30.h"

// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool CombatController::CheckCombatArea(Actor* a_actor) const
{
    bool inside = true;
    if (combatArea) {
        if (!combatArea->CheckLocation(a_actor->pos, a_actor->GetBoundRadius())) {
            inside = false;
        }
    }
    return inside;
}
