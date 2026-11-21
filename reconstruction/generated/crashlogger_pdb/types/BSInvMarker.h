// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSInvMarker; size 0x28
#pragma once

#include "NiExtraData_b2385dce.h"
struct BSInvMarker {
    NiExtraData_b2385dce _base;
    float zoom;
    unsigned short rotationX;
    unsigned short rotationY;
    unsigned short rotationZ;
    unsigned char pad22[6];
};
static_assert(sizeof(BSInvMarker) == 40, "BSInvMarker layout differs from the PDB");
