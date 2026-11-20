// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkAabb; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "hkVector4.h"
struct hkAabb_e8754794 {
    hkVector4 min;
    hkVector4 max;
};
static_assert(sizeof(hkAabb_e8754794) == 32, "hkAabb_e8754794 layout differs from the PDB");
