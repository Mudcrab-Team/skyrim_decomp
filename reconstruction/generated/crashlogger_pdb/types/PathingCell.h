// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PathingCell; size 0x18
#pragma once

#include "BSPathingCell.h"
#include "PathingCellInfo.h"
struct PathingCell {
    BSPathingCell _base;
    PathingCellInfo pathingCellInfo;
};
static_assert(sizeof(PathingCell) == 24, "PathingCell layout differs from the PDB");
