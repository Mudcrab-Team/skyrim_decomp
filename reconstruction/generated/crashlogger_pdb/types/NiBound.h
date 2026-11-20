// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBound; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPoint3_a7124070.h"
struct NiBound {
    NiPoint3_a7124070 Center_0;
    float Radius_C;
};
static_assert(sizeof(NiBound) == 16, "NiBound layout differs from the PDB");
