// 0x80ba70 CombatProjectileAimController::IsWithinAimRadius
// Code origin: original reconstruction from local binary analysis; declarations from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatProjectileAimController: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// CombatController, CombatInventory, inventory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// IsWithinAimRadius, pointX, pointY, pointZ, referenceX, referenceY, referenceZ, radius, extraRadius, controller: GUESS(low); roles inferred from scalar arithmetic
#pragma once
#include <cstddef>
class CombatInventory {
public:
    char unknown000[0x1a8];
    float radius;
};
class CombatController {
public:
    char unknown00[0x10];
    CombatInventory* inventory;
};
class CombatProjectileAimController {
public:
    bool IsWithinAimRadius() const;
    char unknown00[0x28];
    CombatController* controller;
    char unknown30[0x2c];
    float pointX;
    float pointY;
    float pointZ;
    char unknown68[0x0c];
    float referenceX;
    float referenceY;
    float referenceZ;
    char unknown80[0x1c];
    float extraRadius;
};
static_assert(offsetof(CombatProjectileAimController, controller) == 0x28, "controller offset");
static_assert(offsetof(CombatProjectileAimController, pointX) == 0x5c, "point offset");
static_assert(offsetof(CombatProjectileAimController, referenceX) == 0x74, "reference offset");
static_assert(offsetof(CombatProjectileAimController, extraRadius) == 0x9c, "radius offset");
static_assert(offsetof(CombatInventory, radius) == 0x1a8, "inventory radius offset");
