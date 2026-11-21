// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMaxSizeMotion; size 0x140
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpKeyframedRigidMotion.h"
struct hkpMaxSizeMotion {
    hkpKeyframedRigidMotion _base;
};
static_assert(sizeof(hkpMaxSizeMotion) == 320, "hkpMaxSizeMotion layout differs from the PDB");
