// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BarrierProjectile; size 0x200
#pragma once

#include "BSTArray_RE__BarrierProjectile__CollisionData_847305fb.h"
#include "Projectile.h"
struct BarrierProjectile {
    Projectile _base;
    float width;
    unsigned int pad1DC;
    BSTArray_RE__BarrierProjectile__CollisionData_847305fb collisionData;
};
static_assert(sizeof(BarrierProjectile) == 512, "BarrierProjectile layout differs from the PDB");
