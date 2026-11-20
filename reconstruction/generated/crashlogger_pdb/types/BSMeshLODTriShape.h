// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMeshLODTriShape; size 0x170
#pragma once

#include "BSTriShape_d2204fd4.h"
struct BSMeshLODTriShape {
    BSTriShape_d2204fd4 _base;
    unsigned int lodTriangleCounts[3];
    char _pad_16C[4];
};
static_assert(sizeof(BSMeshLODTriShape) == 368, "BSMeshLODTriShape layout differs from the PDB");
