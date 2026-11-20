// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PathingCellInfo; size 0x8
#pragma once

#include "CellFormID.h"
struct PathingCellInfo {
    unsigned int worldSpaceID;
    CellFormID cellID;
};
static_assert(sizeof(PathingCellInfo) == 8, "PathingCellInfo layout differs from the PDB");
