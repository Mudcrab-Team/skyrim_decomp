// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkContactPoint; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4.h"
struct hkContactPoint {
    hkVector4 position;
    hkVector4 separatingNormal;
};
static_assert(sizeof(hkContactPoint) == 32, "hkContactPoint layout differs from the PDB");
