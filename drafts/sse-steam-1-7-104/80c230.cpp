// Near miss: 43.33% | inline-set
// 0x80c230 CombatProjectileAimController::sub_14075D1B0
// Code origin: original reconstruction from local binary analysis; source leads as labelled below.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatProjectileAimController, sub_14075D1B0: CRASHLOGGER_PDB(59818@2026.10.24)
#include "include/80c230/CombatProjectileAimController_80c230.h"

void CombatProjectileAimController::sub_14075D1B0()
{
    flags &= ~0x100u;
    flags |= 0x40u;
    aimX += offsetX;
    aimY += offsetY;
    aimZ += offsetZ;
    timerStart = aimTime;
    timerTarget = 0.0f;
    flags |= 1u;
}
