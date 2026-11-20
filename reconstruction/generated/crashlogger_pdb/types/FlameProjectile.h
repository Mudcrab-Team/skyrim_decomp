// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FlameProjectile; size 0x1e8
#pragma once

#include "Projectile.h"
struct FlameProjectile {
    Projectile _base;
    float expirationTimer;
    float coneAngle;
};
static_assert(sizeof(FlameProjectile) == 488, "FlameProjectile layout differs from the PDB");
