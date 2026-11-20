// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingStart; size 0x38
#pragma once

#include "BSPathingLocation.h"
struct BSPathingStart {
    BSPathingLocation location;
    float tangent;
    unsigned char undefined_34[4];
};
static_assert(sizeof(BSPathingStart) == 56, "BSPathingStart layout differs from the PDB");
