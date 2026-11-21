// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MissileProjectile; size 0x1e8
#pragma once

#include "Projectile.h"
struct MissileProjectile {
    Projectile _base;
    unsigned int impactResult;
    bool waitingToInitialize3D;
    unsigned char unk1DD;
    unsigned short unk1DE;
};
static_assert(sizeof(MissileProjectile) == 488, "MissileProjectile layout differs from the PDB");
