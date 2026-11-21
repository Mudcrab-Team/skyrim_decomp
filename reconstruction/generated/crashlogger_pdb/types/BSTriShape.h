// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTriShape; size 0x160
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSGeometry.h"
struct BSTriShape {
    BSGeometry _base;
    unsigned short triangleCount;
    unsigned short vertexCount;
    unsigned int pad15C;
};
static_assert(sizeof(BSTriShape) == 352, "BSTriShape layout differs from the PDB");
