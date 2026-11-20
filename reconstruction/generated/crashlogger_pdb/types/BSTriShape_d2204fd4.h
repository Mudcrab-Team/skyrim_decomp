// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTriShape; size 0x160
// one of 2 different PDB types sharing this name
#pragma once

#include "BSGeometry_5d16f03d.h"
struct BSTriShape_d2204fd4 {
    BSGeometry_5d16f03d _base;
    unsigned short triangleCount;
    unsigned short vertexCount;
    unsigned int pad15C;
};
static_assert(sizeof(BSTriShape_d2204fd4) == 352, "BSTriShape_d2204fd4 layout differs from the PDB");
