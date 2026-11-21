// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConvexShape; size 0x28
#pragma once

#include "hkpSphereRepShape.h"
struct hkpConvexShape {
    hkpSphereRepShape _base;
    float radius;
    unsigned int pad1C;
};
static_assert(sizeof(hkpConvexShape) == 40, "hkpConvexShape layout differs from the PDB");
