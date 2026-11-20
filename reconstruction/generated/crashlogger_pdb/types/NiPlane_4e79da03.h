// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPlane; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint3.h"
struct NiPlane_4e79da03 {
    NiPoint3 normal;
    float constant;
};
static_assert(sizeof(NiPlane_4e79da03) == 16, "NiPlane_4e79da03 layout differs from the PDB");
