// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GrenadeProjectile; size 0x1f0
#pragma once

#include "Projectile.h"
struct BGSDecalGroup;
struct GrenadeProjectile {
    Projectile _base;
    BGSDecalGroup* decalGroup;
    bool collisionGroupReset;
    unsigned char pad1E1;
    unsigned short pad1E2;
    unsigned int pad1E4;
};
static_assert(sizeof(GrenadeProjectile) == 496, "GrenadeProjectile layout differs from the PDB");
