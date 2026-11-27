// 0x80ba70 CombatProjectileAimController::IsWithinAimRadius
// Code origin: original reconstruction from local binary analysis; source leads as labelled below.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatProjectileAimController: CRASHLOGGER_PDB(59818@2026.10.24)
// IsWithinAimRadius: GUESS(low); unnamed distance predicate
#include "CombatProjectileAimController_80ba70.h"

bool CombatProjectileAimController::IsWithinAimRadius() const
{
    float limit;
    limit = controller->inventory->radius + extraRadius;
    float x = pointX - referenceX;
    float y = pointY - referenceY;
    float z = pointZ - referenceZ;
    return limit * limit > (y * y + x * x) + z * z;
}
