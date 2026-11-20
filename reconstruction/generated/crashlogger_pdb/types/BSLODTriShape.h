// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLODTriShape; size 0x148
#pragma once

#include "NiTriShape.h"
struct BSLODTriShape {
    NiTriShape _base;
    unsigned int lodTriangleCounts[3];
    char _pad_144[4];
};
static_assert(sizeof(BSLODTriShape) == 328, "BSLODTriShape layout differs from the PDB");
