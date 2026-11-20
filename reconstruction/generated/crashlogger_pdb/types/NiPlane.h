// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPlane; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPoint3_a7124070.h"
struct NiPlane {
    NiPoint3_a7124070 Normal_0;
    float Constant_C;
};
static_assert(sizeof(NiPlane) == 16, "NiPlane layout differs from the PDB");
