// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ArrowProjectile; size 0x1f8
#pragma once

#include "MissileProjectile.h"
struct ArrowProjectile {
    MissileProjectile _base;
    unsigned char undefined_1e8[16];
};
static_assert(sizeof(ArrowProjectile) == 504, "ArrowProjectile layout differs from the PDB");
