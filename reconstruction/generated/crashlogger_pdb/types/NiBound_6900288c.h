// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBound; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint3.h"
struct NiBound_6900288c {
    NiPoint3 center;
    float radius;
};
static_assert(sizeof(NiBound_6900288c) == 16, "NiBound_6900288c layout differs from the PDB");
