// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WORLD_LOCATION; size 0x18
#pragma once

#include "NiPoint3.h"
struct TESForm;
struct WORLD_LOCATION {
    TESForm* locationForm;
    NiPoint3 locPt;
    float zRot;
};
static_assert(sizeof(WORLD_LOCATION) == 24, "WORLD_LOCATION layout differs from the PDB");
