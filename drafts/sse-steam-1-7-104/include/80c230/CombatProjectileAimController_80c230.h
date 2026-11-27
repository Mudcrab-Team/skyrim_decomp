// 0x80c230 CombatProjectileAimController::sub_14075D1B0
// Code origin: original reconstruction from local binary analysis; declarations from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatProjectileAimController, sub_14075D1B0: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// aimX, aimY, aimZ, offsetX, offsetY, offsetZ, flags, timerStart, timerTarget, aimTime: GUESS(low); minimal observed aim-update fields

#pragma once
#include <cstddef>
extern float aimTime;
class CombatProjectileAimController {
public:
    void sub_14075D1B0();
    char unknown00[0x18];
    float aimX;
    float aimY;
    float aimZ;
    char unknown24[0x18];
    unsigned int flags;
    float timerStart;
    float timerTarget;
    char unknown48[0x44];
    float offsetX;
    float offsetY;
    float offsetZ;
};
static_assert(offsetof(CombatProjectileAimController, aimX) == 0x18, "aim offset");
static_assert(offsetof(CombatProjectileAimController, flags) == 0x3c, "flags offset");
static_assert(offsetof(CombatProjectileAimController, timerStart) == 0x40, "timer offset");
static_assert(offsetof(CombatProjectileAimController, offsetX) == 0x8c, "aim displacement offset");
