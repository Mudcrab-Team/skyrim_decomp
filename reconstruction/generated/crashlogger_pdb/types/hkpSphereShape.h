// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSphereShape; size 0x28
#pragma once

#include "hkpConvexShape.h"
struct hkpSphereShape {
    hkpConvexShape _base;
};
static_assert(sizeof(hkpSphereShape) == 40, "hkpSphereShape layout differs from the PDB");
